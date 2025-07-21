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
**         CMSIS Peripheral Access Layer for IEE_APC
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
 * @file PERI_IEE_APC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IEE_APC
 *
 * CMSIS Peripheral Access Layer for IEE_APC
 */

#if !defined(PERI_IEE_APC_H_)
#define PERI_IEE_APC_H_                          /**< Symbol preventing repeated inclusion */

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
   -- IEE_APC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IEE_APC_Peripheral_Access_Layer IEE_APC Peripheral Access Layer
 * @{
 */

/** IEE_APC - Register Layout Typedef */
typedef struct {
  __IO uint32_t REGION0_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x0 */
  __IO uint32_t REGION0_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x4 */
  __IO uint32_t REGION0_ENA;                       /**< Region enable for region (n), offset: 0x8 */
  __IO uint32_t REGION0_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0xC */
  __IO uint32_t REGION1_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x10 */
  __IO uint32_t REGION1_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x14 */
  __IO uint32_t REGION1_ENA;                       /**< Region enable for region (n), offset: 0x18 */
  __IO uint32_t REGION1_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x1C */
  __IO uint32_t REGION2_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x20 */
  __IO uint32_t REGION2_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x24 */
  __IO uint32_t REGION2_ENA;                       /**< Region enable for region (n), offset: 0x28 */
  __IO uint32_t REGION2_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x2C */
  __IO uint32_t REGION3_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x30 */
  __IO uint32_t REGION3_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x34 */
  __IO uint32_t REGION3_ENA;                       /**< Region enable for region (n), offset: 0x38 */
  __IO uint32_t REGION3_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x3C */
  __IO uint32_t REGION4_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x40 */
  __IO uint32_t REGION4_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x44 */
  __IO uint32_t REGION4_ENA;                       /**< Region enable for region (n), offset: 0x48 */
  __IO uint32_t REGION4_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x4C */
  __IO uint32_t REGION5_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x50 */
  __IO uint32_t REGION5_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x54 */
  __IO uint32_t REGION5_ENA;                       /**< Region enable for region (n), offset: 0x58 */
  __IO uint32_t REGION5_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x5C */
  __IO uint32_t REGION6_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x60 */
  __IO uint32_t REGION6_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x64 */
  __IO uint32_t REGION6_ENA;                       /**< Region enable for region (n), offset: 0x68 */
  __IO uint32_t REGION6_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x6C */
  __IO uint32_t REGION7_TOP_ADDR;                  /**< End address of IEE region (n), offset: 0x70 */
  __IO uint32_t REGION7_BOT_ADDR;                  /**< Start address of IEE region (n), offset: 0x74 */
  __IO uint32_t REGION7_ENA;                       /**< Region enable for region (n), offset: 0x78 */
  __IO uint32_t REGION7_ACC_CTL;                   /**< Access control for IEE APC registers of region (n), offset: 0x7C */
} IEE_APC_Type;

/* ----------------------------------------------------------------------------
   -- IEE_APC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IEE_APC_Register_Masks IEE_APC Register Masks
 * @{
 */

/*! @name REGION0_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION0_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION0_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION0_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION0_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION0_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION0_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION0_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION0_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION0_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION0_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION0_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION0_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION0_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION0_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION0_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION0_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION0_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION0_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION0_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION0_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION0_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION0_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION0_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION0_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION0_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION0_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION0_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION0_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION0_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION0_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION0_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION0_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION0_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION0_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION0_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION0_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION1_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION1_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION1_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION1_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION1_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION1_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION1_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION1_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION1_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION1_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION1_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION1_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION1_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION1_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION1_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION1_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION1_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION1_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION1_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION1_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION1_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION1_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION1_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION1_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION1_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION1_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION1_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION1_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION1_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION1_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION1_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION1_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION1_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION1_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION1_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION1_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION1_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION2_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION2_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION2_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION2_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION2_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION2_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION2_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION2_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION2_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION2_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION2_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION2_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION2_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION2_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION2_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION2_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION2_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION2_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION2_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION2_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION2_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION2_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION2_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION2_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION2_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION2_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION2_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION2_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION2_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION2_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION2_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION2_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION2_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION2_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION2_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION2_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION2_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION3_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION3_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION3_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION3_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION3_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION3_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION3_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION3_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION3_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION3_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION3_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION3_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION3_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION3_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION3_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION3_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION3_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION3_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION3_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION3_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION3_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION3_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION3_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION3_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION3_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION3_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION3_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION3_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION3_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION3_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION3_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION3_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION3_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION3_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION3_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION3_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION3_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION4_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION4_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION4_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION4_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION4_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION4_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION4_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION4_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION4_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION4_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION4_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION4_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION4_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION4_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION4_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION4_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION4_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION4_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION4_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION4_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION4_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION4_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION4_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION4_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION4_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION4_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION4_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION4_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION4_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION4_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION4_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION4_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION4_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION4_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION4_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION4_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION4_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION5_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION5_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION5_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION5_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION5_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION5_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION5_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION5_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION5_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION5_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION5_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION5_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION5_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION5_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION5_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION5_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION5_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION5_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION5_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION5_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION5_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION5_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION5_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION5_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION5_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION5_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION5_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION5_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION5_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION5_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION5_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION5_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION5_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION5_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION5_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION5_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION5_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION6_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION6_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION6_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION6_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION6_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION6_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION6_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION6_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION6_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION6_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION6_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION6_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION6_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION6_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION6_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION6_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION6_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION6_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION6_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION6_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION6_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION6_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION6_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION6_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION6_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION6_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION6_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION6_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION6_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION6_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION6_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION6_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION6_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION6_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION6_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION6_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION6_ACC_CTL_LOCK_H_MASK)
/*! @} */

/*! @name REGION7_TOP_ADDR - End address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION7_TOP_ADDR_TOP_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION7_TOP_ADDR_TOP_ADDR_SHIFT  (6U)
/*! TOP_ADDR - End address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION7_TOP_ADDR_TOP_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_TOP_ADDR_TOP_ADDR_SHIFT)) & IEE_APC_REGION7_TOP_ADDR_TOP_ADDR_MASK)
/*! @} */

/*! @name REGION7_BOT_ADDR - Start address of IEE region (n) */
/*! @{ */

#define IEE_APC_REGION7_BOT_ADDR_BOT_ADDR_MASK   (0xFFFFFFC0U)
#define IEE_APC_REGION7_BOT_ADDR_BOT_ADDR_SHIFT  (6U)
/*! BOT_ADDR - Start address[31:6] of IEE region. The lower 6 address bits of IEE region is always 0. */
#define IEE_APC_REGION7_BOT_ADDR_BOT_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_BOT_ADDR_BOT_ADDR_SHIFT)) & IEE_APC_REGION7_BOT_ADDR_BOT_ADDR_MASK)
/*! @} */

/*! @name REGION7_ENA - Region enable for region (n) */
/*! @{ */

#define IEE_APC_REGION7_ENA_ENCRYPT_ENABLE_MASK  (0x1U)
#define IEE_APC_REGION7_ENA_ENCRYPT_ENABLE_SHIFT (0U)
/*! ENCRYPT_ENABLE - Enable this region
 *  0b0..This region is not enabled for IEE routing even hit
 *  0b1..This region is enabled for IEE routing once hit
 */
#define IEE_APC_REGION7_ENA_ENCRYPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_ENA_ENCRYPT_ENABLE_SHIFT)) & IEE_APC_REGION7_ENA_ENCRYPT_ENABLE_MASK)
/*! @} */

/*! @name REGION7_ACC_CTL - Access control for IEE APC registers of region (n) */
/*! @{ */

#define IEE_APC_REGION7_ACC_CTL_ALLOW_DID_MASK   (0xFU)
#define IEE_APC_REGION7_ACC_CTL_ALLOW_DID_SHIFT  (0U)
/*! ALLOW_DID - Allowed domain ID */
#define IEE_APC_REGION7_ACC_CTL_ALLOW_DID(x)     (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_ACC_CTL_ALLOW_DID_SHIFT)) & IEE_APC_REGION7_ACC_CTL_ALLOW_DID_MASK)

#define IEE_APC_REGION7_ACC_CTL_LOCK_L_MASK      (0x8000U)
#define IEE_APC_REGION7_ACC_CTL_LOCK_L_SHIFT     (15U)
/*! LOCK_L - Lock bit for the lower half word
 *  0b0..Lower half word is not locked
 *  0b1..Lower half word is locked
 */
#define IEE_APC_REGION7_ACC_CTL_LOCK_L(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_ACC_CTL_LOCK_L_SHIFT)) & IEE_APC_REGION7_ACC_CTL_LOCK_L_MASK)

#define IEE_APC_REGION7_ACC_CTL_ALLOW_NS_MASK    (0x10000U)
#define IEE_APC_REGION7_ACC_CTL_ALLOW_NS_SHIFT   (16U)
/*! ALLOW_NS - Allow nonsecure mode access
 *  0b0..Only secure access to this region's registers is allowed
 *  0b1..Secure and nonsecure access to this region's registers is allowed
 */
#define IEE_APC_REGION7_ACC_CTL_ALLOW_NS(x)      (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_ACC_CTL_ALLOW_NS_SHIFT)) & IEE_APC_REGION7_ACC_CTL_ALLOW_NS_MASK)

#define IEE_APC_REGION7_ACC_CTL_ALLOW_USER_MASK  (0x20000U)
#define IEE_APC_REGION7_ACC_CTL_ALLOW_USER_SHIFT (17U)
/*! ALLOW_USER - Allow user mode access
 *  0b0..Only privilege access to this region's registers is allowed
 *  0b1..User and privilege access to this region's registers is allowed
 */
#define IEE_APC_REGION7_ACC_CTL_ALLOW_USER(x)    (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_ACC_CTL_ALLOW_USER_SHIFT)) & IEE_APC_REGION7_ACC_CTL_ALLOW_USER_MASK)

#define IEE_APC_REGION7_ACC_CTL_LOCK_H_MASK      (0x80000000U)
#define IEE_APC_REGION7_ACC_CTL_LOCK_H_SHIFT     (31U)
/*! LOCK_H - Lock bit for the higher half word
 *  0b0..Higher half word is not locked
 *  0b1..Higher half word is locked
 */
#define IEE_APC_REGION7_ACC_CTL_LOCK_H(x)        (((uint32_t)(((uint32_t)(x)) << IEE_APC_REGION7_ACC_CTL_LOCK_H_SHIFT)) & IEE_APC_REGION7_ACC_CTL_LOCK_H_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IEE_APC_Register_Masks */


/*!
 * @}
 */ /* end of group IEE_APC_Peripheral_Access_Layer */


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


#endif  /* PERI_IEE_APC_H_ */

