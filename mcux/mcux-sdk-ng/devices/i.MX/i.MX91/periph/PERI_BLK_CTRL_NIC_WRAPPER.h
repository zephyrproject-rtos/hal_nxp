/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_NIC_WRAPPER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_NIC_WRAPPER.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NIC_WRAPPER
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NIC_WRAPPER
 */

#if !defined(PERI_BLK_CTRL_NIC_WRAPPER_H_)
#define PERI_BLK_CTRL_NIC_WRAPPER_H_             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- BLK_CTRL_NIC_WRAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NIC_WRAPPER_Peripheral_Access_Layer BLK_CTRL_NIC_WRAPPER Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NIC_WRAPPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t DEXSC_ERR;                         /**< DEXSC error response configuration, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t AXI_LIMIT_WAKEUPMIX;               /**< Configuration register for axi_limit_wakeupmix, offset: 0x8 */
  __IO uint32_t CACHE_ATTR;                        /**< Configuration register for AxCACHE[1] override, offset: 0xC */
  __IO uint32_t WAKEUPMIX_QOS;                     /**< Configuration register for QoS value from wakeupmix, offset: 0x10 */
  __IO uint32_t CACHE_QOS;                         /**< Configuration register for QoS value from A55, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t HSIOMIX_QOS;                       /**< Configuration register for QoS value from hsiomix, offset: 0x20 */
  __IO uint32_t TIE_VALUE;                         /**< GPR for uncertain tie0 or tie1, offset: 0x24 */
  __IO uint32_t OCRAM_SGLECC_ERR_INT;              /**< OCRAM single ECC error interrupt flag, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t SSI_MST_DDRMIX;                    /**< low power control for SSI_MST_DDRMIX, offset: 0x30 */
  __IO uint32_t SSI_MST_GIC600;                    /**< low power control for SSI_MST_GIC600, offset: 0x34 */
  __IO uint32_t SSI_MST_WAKEUPMIX;                 /**< low power control for SSI_MST_WAKEUPMIX, offset: 0x38 */
  __IO uint32_t SSI_SLV_CACHE;                     /**< low power control for SSI_SLV_CACHE, offset: 0x3C */
  __IO uint32_t SSI_SLV_GIC600;                    /**< low power control for SSI_SLV_GIC600, offset: 0x40 */
  __IO uint32_t SSI_SLV_HSIOMIX;                   /**< low power control for SSI_SLV_HSIOMIX, offset: 0x44 */
  __IO uint32_t SSI_SLV_MEDIAMIX;                  /**< low power control for SSI_SLV_MEDIAMIX, offset: 0x48 */
  __IO uint32_t SSI_SLV_WAKEUPMIX;                 /**< low power control for SSI_SLV_WAKEUPMIX, offset: 0x4C */
       uint8_t RESERVED_3[16];
  __IO uint32_t REG_RW;                            /**< reserved, offset: 0x60 */
  __I  uint32_t REG_RO;                            /**< reserved, offset: 0x64 */
} BLK_CTRL_NIC_WRAPPER_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NIC_WRAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NIC_WRAPPER_Register_Masks BLK_CTRL_NIC_WRAPPER Register Masks
 * @{
 */

/*! @name DEXSC_ERR - DEXSC error response configuration */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_ERR_RESP_EN_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_ERR_RESP_EN_SHIFT (0U)
/*! OCRAM_ERR_RESP_EN - OCRAM DEXSC error response enable
 *  0b0..DEXSC will not respond error if there is read error on DEXSC
 *  0b1..DEXSC will respond slave error if there is read error on DEXSC
 */
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_ERR_RESP_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_MASK (0x2U)
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_SHIFT (1U)
/*! OCRAM_EXC_ERR_RESP_EN - OCRAM DEXSC exclusive error response enable
 *  0b0..DEXSC will not respond error if there is exclusive error on DEXSC
 *  0b1..DEXSC will respond slave error if there is exclusive error on DEXSC
 */
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_EXC_ERR_RESP_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_SHIFT (2U)
/*! OCRAM_LOCK_ERR_RESP_EN - Lock bit of OCRAM_ERR_RESP_EN and OCRAM_EXC_ERR_RESP_EN */
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_OCRAM_LOCK_ERR_RESP_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_ERR_RESP_EN_MASK (0x10000U)
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_ERR_RESP_EN_SHIFT (16U)
/*! DRAM_ERR_RESP_EN - DRAM DEXSC error response enable
 *  0b0..DEXSC will not respond error if there is read error on DEXSC
 *  0b1..DEXSC will respond slave error if there is read error on DEXSC
 */
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_ERR_RESP_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_MASK (0x20000U)
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_SHIFT (17U)
/*! DRAM_EXC_ERR_RESP_EN - DRAM DEXSC exclusive error response enable
 *  0b0..DEXSC will not respond error if there is exclusive error on DEXSC
 *  0b1..DEXSC will respond slave error if there is exclusive error on DEXSC
 */
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_EXC_ERR_RESP_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_MASK (0x40000U)
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_SHIFT (18U)
/*! DRAM_LOCK_ERR_RESP_EN - Lock bit of DRAM_ERR_RESP_EN and DRAM_EXC_ERR_RESP_EN */
#define BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_DEXSC_ERR_DRAM_LOCK_ERR_RESP_EN_MASK)
/*! @} */

/*! @name AXI_LIMIT_WAKEUPMIX - Configuration register for axi_limit_wakeupmix */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_ENABLE_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_ENABLE_SHIFT (0U)
/*! ENABLE - Enable the beat limit on the access from wakeupmix
 *  0b0..Disable the beat limit
 *  0b1..Enable the beat limit
 */
#define BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_ENABLE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_ENABLE_MASK)

#define BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_MASK (0xFFFF0000U)
#define BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_SHIFT (16U)
/*! BEAT_LIMIT - Beat limit number */
#define BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_SHIFT)) & BLK_CTRL_NIC_WRAPPER_AXI_LIMIT_WAKEUPMIX_BEAT_LIMIT_MASK)
/*! @} */

/*! @name CACHE_ATTR - Configuration register for AxCACHE[1] override */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_SHIFT (0U)
/*! WAKEUPMIX_ARCACHE_EN - Enable ARCACHE[1] override
 *  0b0..Disable override ARCACHE[1] from ssi_slv_wakeupmix
 *  0b1..enable override ARCACHE[1] from ssi_slv_wakeupmix
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_MASK (0x2U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_SHIFT (1U)
/*! WAKEUPMIX_AWCACHE_EN - Enable AWCACHE[1] override
 *  0b0..Disable override AWCACHE[1] from ssi_slv_wakeupmix
 *  0b1..enable override AWCACHE[1] from ssi_slv_wakeupmix
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_EN_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_EN_SHIFT (2U)
/*! CACHE_ARCACHE_EN - Enable ARCACHE[1] override
 *  0b0..Disable override ARCACHE[1] from ssi_slv_cache
 *  0b1..enable override ARCACHE[1] from ssi_slv_cache
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_EN_MASK (0x8U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_EN_SHIFT (3U)
/*! CACHE_AWCACHE_EN - Enable AWCACHE[1] override
 *  0b0..Disable override AWCACHE[1] from ssi_slv_cache
 *  0b1..enable override AWCACHE[1] from ssi_slv_cache
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_EN_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_EN_SHIFT (4U)
/*! HSIOMIX_ARCACHE_EN - Enable ARCACHE[1] override
 *  0b0..Disable override ARCACHE[1] from ssi_slv_hsiomix
 *  0b1..enable override ARCACHE[1] from ssi_slv_hsiomix
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_EN_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_EN_SHIFT (5U)
/*! HSIOMIX_AWCACHE_EN - Enable AWCACHE[1] override
 *  0b0..Disable override AWCACHE[1] from ssi_slv_hsiomix
 *  0b1..enable override AWCACHE[1] from ssi_slv_hsiomix
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_EN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_EN_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_MASK (0x10000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_SHIFT (16U)
/*! WAKEUPMIX_ARCACHE - Override value
 *  0b0..Override ARCACHE[1] from ssi_slv_wakeupmix to 0
 *  0b1..Override ARCACHE[1] from ssi_slv_wakeupmix to 1
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_ARCACHE_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_MASK (0x20000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_SHIFT (17U)
/*! WAKEUPMIX_AWCACHE - Override value
 *  0b0..Override AWCACHE[1] from ssi_slv_wakeupmix to 0
 *  0b1..Override AWCACHE[1] from ssi_slv_wakeupmix to 1
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_WAKEUPMIX_AWCACHE_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_MASK (0x40000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_SHIFT (18U)
/*! CACHE_ARCACHE - Override value
 *  0b0..Override ARCACHE[1] from ssi_slv_cache to 0
 *  0b1..Override ARCACHE[1] from ssi_slv_cache to 1
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_ARCACHE_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_MASK (0x80000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_SHIFT (19U)
/*! CACHE_AWCACHE - Override value
 *  0b0..Override AWCACHE[1] from ssi_slv_cache to 0
 *  0b1..Override AWCACHE[1] from ssi_slv_cache to 1
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_CACHE_AWCACHE_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_MASK (0x100000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_SHIFT (20U)
/*! HSIOMIX_ARCACHE - Override value
 *  0b0..Override ARCACHE[1] from ssi_slv_hsiomix to 0
 *  0b1..Override ARCACHE[1] from ssi_slv_hsiomix to 1
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_ARCACHE_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_MASK (0x200000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_SHIFT (21U)
/*! HSIOMIX_AWCACHE - Override value
 *  0b0..Override AWCACHE[1] from ssi_slv_hsiomix to 0
 *  0b1..Override AWCACHE[1] from ssi_slv_hsiomix to 1
 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_ATTR_HSIOMIX_AWCACHE_MASK)
/*! @} */

/*! @name WAKEUPMIX_QOS - Configuration register for QoS value from wakeupmix */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from wakeupmix */
#define BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from wakeupmix */
#define BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NIC_WRAPPER_WAKEUPMIX_QOS_PANIC_AR_MASK)
/*! @} */

/*! @name CACHE_QOS - Configuration register for QoS value from A55 */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from A55 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from A55 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_QOS_PANIC_AR_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AW_MASK (0xF0000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AW_SHIFT (16U)
/*! DEFAULT_AW - Value of aw_qos_default from A55 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AW_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AW_MASK)

#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AR_MASK (0xF00000U)
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AR_SHIFT (20U)
/*! DEFAULT_AR - Value of ar_qos_default from A55 */
#define BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AR_SHIFT)) & BLK_CTRL_NIC_WRAPPER_CACHE_QOS_DEFAULT_AR_MASK)
/*! @} */

/*! @name HSIOMIX_QOS - Configuration register for QoS value from hsiomix */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AW_MASK (0xFU)
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AW_SHIFT (0U)
/*! PANIC_AW - Value of aw_qos_paNIC from hsiomix */
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AW_SHIFT)) & BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AW_MASK)

#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AR_MASK (0xF0U)
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AR_SHIFT (4U)
/*! PANIC_AR - Value of ar_qos_paNIC from hsiomix */
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AR_SHIFT)) & BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_PANIC_AR_MASK)

#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AW_MASK (0xF0000U)
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AW_SHIFT (16U)
/*! DEFAULT_AW - Value of aw_qos_default from hsiomix */
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AW_SHIFT)) & BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AW_MASK)

#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AR_MASK (0xF00000U)
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AR_SHIFT (20U)
/*! DEFAULT_AR - Value of ar_qos_default from hsiomix */
#define BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AR_SHIFT)) & BLK_CTRL_NIC_WRAPPER_HSIOMIX_QOS_DEFAULT_AR_MASK)
/*! @} */

/*! @name TIE_VALUE - GPR for uncertain tie0 or tie1 */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AIPS4_HBSTRB_MASK (0xFU)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AIPS4_HBSTRB_SHIFT (0U)
/*! AIPS4_HBSTRB - Value of aips4.hbstrb */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AIPS4_HBSTRB(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AIPS4_HBSTRB_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AIPS4_HBSTRB_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_XCPT_RTN_MASK (0x30U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_XCPT_RTN_SHIFT (4U)
/*! XCPT_RTN - Dac_cache_r.xcpt_rtn and dac_cache_w.xcpt_rtn */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_XCPT_RTN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_XCPT_RTN_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_XCPT_RTN_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICT_ALLOW_NS_MASK (0x40U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICT_ALLOW_NS_SHIFT (6U)
/*! GICT_ALLOW_NS - GIC600.gict_allow_ns */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICT_ALLOW_NS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICT_ALLOW_NS_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICT_ALLOW_NS_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICP_ALLOW_NS_MASK (0x80U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICP_ALLOW_NS_SHIFT (7U)
/*! GICP_ALLOW_NS - GIC600.gicp_allow_ns */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICP_ALLOW_NS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICP_ALLOW_NS_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_GICP_ALLOW_NS_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARBAR_S_MASK (0x300U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARBAR_S_SHIFT (8U)
/*! ARBAR_S - GIC600.ARBAR_S */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARBAR_S(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARBAR_S_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARBAR_S_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWBAR_S_MASK (0xC00U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWBAR_S_SHIFT (10U)
/*! AWBAR_S - GIC600.AWBAR_S */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWBAR_S(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWBAR_S_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWBAR_S_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARUSER_S_MASK (0x7000U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARUSER_S_SHIFT (12U)
/*! ARUSER_S - GIC600.ARUSER_S */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARUSER_S(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARUSER_S_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARUSER_S_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWUSER_S_MASK (0x38000U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWUSER_S_SHIFT (15U)
/*! AWUSER_S - GIC600.AWUSER_S */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWUSER_S(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWUSER_S_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWUSER_S_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARSNOOP_S_MASK (0x3C0000U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARSNOOP_S_SHIFT (18U)
/*! ARSNOOP_S - GIC600.arsnoop_s */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARSNOOP_S(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARSNOOP_S_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_ARSNOOP_S_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWSNOOP_S_MASK (0x1C00000U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWSNOOP_S_SHIFT (22U)
/*! AWSNOOP_S - GIC600.awsnoop_s */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWSNOOP_S(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWSNOOP_S_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_AWSNOOP_S_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_HPROT_GPV_CENTRAL_MASK (0x1E000000U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_HPROT_GPV_CENTRAL_SHIFT (25U)
/*! HPROT_GPV_CENTRAL - NIC400_central.HPROT_gpv_central */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_HPROT_GPV_CENTRAL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_HPROT_GPV_CENTRAL_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_HPROT_GPV_CENTRAL_MASK)

#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_DFTRAMHOLD_MASK (0x20000000U)
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_DFTRAMHOLD_SHIFT (29U)
/*! DFTRAMHOLD - GIC600.dftramhold */
#define BLK_CTRL_NIC_WRAPPER_TIE_VALUE_DFTRAMHOLD(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_TIE_VALUE_DFTRAMHOLD_SHIFT)) & BLK_CTRL_NIC_WRAPPER_TIE_VALUE_DFTRAMHOLD_MASK)
/*! @} */

/*! @name OCRAM_SGLECC_ERR_INT - OCRAM single ECC error interrupt flag */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_OCRAM_SGLECC_ERR_INT_SGL_ECC_ERR_IF_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_OCRAM_SGLECC_ERR_INT_SGL_ECC_ERR_IF_SHIFT (0U)
/*! SGL_ECC_ERR_IF - OCRAM single ECC error interrupt flag */
#define BLK_CTRL_NIC_WRAPPER_OCRAM_SGLECC_ERR_INT_SGL_ECC_ERR_IF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_OCRAM_SGLECC_ERR_INT_SGL_ECC_ERR_IF_SHIFT)) & BLK_CTRL_NIC_WRAPPER_OCRAM_SGLECC_ERR_INT_SGL_ECC_ERR_IF_MASK)
/*! @} */

/*! @name SSI_MST_DDRMIX - low power control for SSI_MST_DDRMIX */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_idle_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_pause_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_pause_SHIFT (2U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_pause(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_pause_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_pause_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_black_hole_mode_b_MASK (0x8U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_black_hole_mode_b_SHIFT (3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_black_hole_mode_b(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_black_hole_mode_b_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_black_hole_mode_b_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_DDRMIX_iso_control_MASK)
/*! @} */

/*! @name SSI_MST_GIC600 - low power control for SSI_MST_GIC600 */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_idle_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_pause_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_pause_SHIFT (2U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_pause(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_pause_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_pause_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_GIC600_iso_control_MASK)
/*! @} */

/*! @name SSI_MST_WAKEUPMIX - low power control for SSI_MST_WAKEUPMIX */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_idle_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_pause_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_pause_SHIFT (2U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_pause(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_pause_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_pause_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_black_hole_mode_b_MASK (0x8U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_black_hole_mode_b_SHIFT (3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_black_hole_mode_b(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_black_hole_mode_b_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_black_hole_mode_b_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_MST_WAKEUPMIX_iso_control_MASK)
/*! @} */

/*! @name SSI_SLV_CACHE - low power control for SSI_SLV_CACHE */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_idle_MASK (0x3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_pause_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_pause_SHIFT (2U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_pause(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_pause_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_pause_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_black_hole_mode_b_MASK (0x8U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_black_hole_mode_b_SHIFT (3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_black_hole_mode_b(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_black_hole_mode_b_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_black_hole_mode_b_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_CACHE_iso_control_MASK)
/*! @} */

/*! @name SSI_SLV_GIC600 - low power control for SSI_SLV_GIC600 */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_GIC600_iso_control_MASK)
/*! @} */

/*! @name SSI_SLV_HSIOMIX - low power control for SSI_SLV_HSIOMIX */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_idle_MASK (0x3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_pause_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_pause_SHIFT (2U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_pause(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_pause_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_pause_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_black_hole_mode_b_MASK (0x8U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_black_hole_mode_b_SHIFT (3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_black_hole_mode_b(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_black_hole_mode_b_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_black_hole_mode_b_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_HSIOMIX_iso_control_MASK)
/*! @} */

/*! @name SSI_SLV_MEDIAMIX - low power control for SSI_SLV_MEDIAMIX */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_idle_MASK (0x3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_pause_MASK (0x4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_pause_SHIFT (2U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_pause(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_pause_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_pause_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_black_hole_mode_b_MASK (0x8U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_black_hole_mode_b_SHIFT (3U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_black_hole_mode_b(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_black_hole_mode_b_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_black_hole_mode_b_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_MEDIAMIX_iso_control_MASK)
/*! @} */

/*! @name SSI_SLV_WAKEUPMIX - low power control for SSI_SLV_WAKEUPMIX */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_idle_MASK (0x1U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_idle_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_idle(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_idle_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_idle_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_power_control_MASK (0x10U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_power_control_SHIFT (4U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_power_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_power_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_power_control_MASK)

#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_iso_control_MASK (0x20U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_iso_control_SHIFT (5U)
#define BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_iso_control(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_iso_control_SHIFT)) & BLK_CTRL_NIC_WRAPPER_SSI_SLV_WAKEUPMIX_iso_control_MASK)
/*! @} */

/*! @name REG_RW - reserved */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_REG_RW_z_cell_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_NIC_WRAPPER_REG_RW_z_cell_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_REG_RW_z_cell(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_REG_RW_z_cell_SHIFT)) & BLK_CTRL_NIC_WRAPPER_REG_RW_z_cell_MASK)
/*! @} */

/*! @name REG_RO - reserved */
/*! @{ */

#define BLK_CTRL_NIC_WRAPPER_REG_RO_z_cell_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_NIC_WRAPPER_REG_RO_z_cell_SHIFT (0U)
#define BLK_CTRL_NIC_WRAPPER_REG_RO_z_cell(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NIC_WRAPPER_REG_RO_z_cell_SHIFT)) & BLK_CTRL_NIC_WRAPPER_REG_RO_z_cell_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NIC_WRAPPER_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_NIC_WRAPPER_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_NIC_WRAPPER_H_ */
