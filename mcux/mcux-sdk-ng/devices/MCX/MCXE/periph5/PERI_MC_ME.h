/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MC_ME
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_MC_ME.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MC_ME
 *
 * CMSIS Peripheral Access Layer for MC_ME
 */

#if !defined(PERI_MC_ME_H_)
#define PERI_MC_ME_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- MC_ME Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_ME_Peripheral_Access_Layer MC_ME Peripheral Access Layer
 * @{
 */

/** MC_ME - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTL_KEY;                           /**< Control Key Register, offset: 0x0 */
  __IO uint32_t MODE_CONF;                         /**< Mode Configuration Register, offset: 0x4 */
  __IO uint32_t MODE_UPD;                          /**< Mode Update Register, offset: 0x8 */
  __I  uint32_t MODE_STAT;                         /**< Mode Status Register, offset: 0xC */
  __IO uint32_t MAIN_COREID;                       /**< Main Core ID Register, offset: 0x10 */
       uint8_t RESERVED_0[236];
  __IO uint32_t PRTN0_PCONF;                       /**< Partition 0 Process Configuration Register, offset: 0x100 */
  __IO uint32_t PRTN0_PUPD;                        /**< Partition 0 Process Update Register, offset: 0x104 */
  __I  uint32_t PRTN0_STAT;                        /**< Partition 0 Status Register, offset: 0x108 */
       uint8_t RESERVED_1[8];
  __I  uint32_t PRTN0_COFB1_STAT;                  /**< Partition 0 COFB Set 1 Clock Status Register, offset: 0x114 */
       uint8_t RESERVED_2[28];
  __IO uint32_t PRTN0_COFB1_CLKEN;                 /**< Partition 0 COFB Set 1 Clock Enable Register, offset: 0x134 */
       uint8_t RESERVED_3[8];
  __IO uint32_t PRTN0_CORE0_PCONF;                 /**< Partition 0 Core 0 Process Configuration Register, offset: 0x140 */
  __IO uint32_t PRTN0_CORE0_PUPD;                  /**< Partition 0 Core 0 Process Update Register, offset: 0x144 */
  __I  uint32_t PRTN0_CORE0_STAT;                  /**< Partition 0 Core 0 Status Register, offset: 0x148 */
  __IO uint32_t PRTN0_CORE0_ADDR;                  /**< Partition 0 Core 0 Address Register, offset: 0x14C */
       uint8_t RESERVED_4[56];
  __I  uint32_t PRTN0_CORE2_STAT;                  /**< Partition 0 Core 2 Status Register, offset: 0x188 */
  __I  uint32_t PRTN0_CORE2_ADDR;                  /**< Partition 0 Core 2 Address Register, offset: 0x18C */
       uint8_t RESERVED_5[368];
  __IO uint32_t PRTN1_PCONF;                       /**< Partition 1 Process Configuration Register, offset: 0x300 */
  __IO uint32_t PRTN1_PUPD;                        /**< Partition 1 Process Update Register, offset: 0x304 */
  __I  uint32_t PRTN1_STAT;                        /**< Partition 1 Status Register, offset: 0x308 */
       uint8_t RESERVED_6[4];
  __I  uint32_t PRTN1_COFB0_STAT;                  /**< Partition 1 COFB Set 0 Clock Status Register, offset: 0x310 */
  __I  uint32_t PRTN1_COFB1_STAT;                  /**< Partition 1 COFB Set 1 Clock Status Register, offset: 0x314 */
  __I  uint32_t PRTN1_COFB2_STAT;                  /**< Partition 1 COFB Set 2 Clock Status Register, offset: 0x318 */
  __I  uint32_t PRTN1_COFB3_STAT;                  /**< Partition 1 COFB Set 3 Clock Status Register, offset: 0x31C */
       uint8_t RESERVED_7[16];
  __IO uint32_t PRTN1_COFB0_CLKEN;                 /**< Partition 1 COFB Set 0 Clock Enable Register, offset: 0x330 */
  __IO uint32_t PRTN1_COFB1_CLKEN;                 /**< Partition 1 COFB Set 1 Clock Enable Register, offset: 0x334 */
  __IO uint32_t PRTN1_COFB2_CLKEN;                 /**< Partition 1 COFB Set 2 Clock Enable Register, offset: 0x338 */
  __IO uint32_t PRTN1_COFB3_CLKEN;                 /**< Partition 1 COFB Set 3 Clock Enable Register, offset: 0x33C */
} MC_ME_Type;

/* ----------------------------------------------------------------------------
   -- MC_ME Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_ME_Register_Masks MC_ME Register Masks
 * @{
 */

/*! @name CTL_KEY - Control Key Register */
/*! @{ */

#define MC_ME_CTL_KEY_KEY_MASK                   (0xFFFFU)
#define MC_ME_CTL_KEY_KEY_SHIFT                  (0U)
/*! KEY - Control key */
#define MC_ME_CTL_KEY_KEY(x)                     (((uint32_t)(((uint32_t)(x)) << MC_ME_CTL_KEY_KEY_SHIFT)) & MC_ME_CTL_KEY_KEY_MASK)
/*! @} */

/*! @name MODE_CONF - Mode Configuration Register */
/*! @{ */

#define MC_ME_MODE_CONF_DEST_RST_MASK            (0x1U)
#define MC_ME_MODE_CONF_DEST_RST_SHIFT           (0U)
/*! DEST_RST - Destructive reset request */
#define MC_ME_MODE_CONF_DEST_RST(x)              (((uint32_t)(((uint32_t)(x)) << MC_ME_MODE_CONF_DEST_RST_SHIFT)) & MC_ME_MODE_CONF_DEST_RST_MASK)

#define MC_ME_MODE_CONF_FUNC_RST_MASK            (0x2U)
#define MC_ME_MODE_CONF_FUNC_RST_SHIFT           (1U)
/*! FUNC_RST - Functional reset request */
#define MC_ME_MODE_CONF_FUNC_RST(x)              (((uint32_t)(((uint32_t)(x)) << MC_ME_MODE_CONF_FUNC_RST_SHIFT)) & MC_ME_MODE_CONF_FUNC_RST_MASK)

#define MC_ME_MODE_CONF_STANDBY_MASK             (0x8000U)
#define MC_ME_MODE_CONF_STANDBY_SHIFT            (15U)
/*! STANDBY - Standby request */
#define MC_ME_MODE_CONF_STANDBY(x)               (((uint32_t)(((uint32_t)(x)) << MC_ME_MODE_CONF_STANDBY_SHIFT)) & MC_ME_MODE_CONF_STANDBY_MASK)
/*! @} */

/*! @name MODE_UPD - Mode Update Register */
/*! @{ */

#define MC_ME_MODE_UPD_MODE_UPD_MASK             (0x1U)
#define MC_ME_MODE_UPD_MODE_UPD_SHIFT            (0U)
/*! MODE_UPD - Mode update */
#define MC_ME_MODE_UPD_MODE_UPD(x)               (((uint32_t)(((uint32_t)(x)) << MC_ME_MODE_UPD_MODE_UPD_SHIFT)) & MC_ME_MODE_UPD_MODE_UPD_MASK)
/*! @} */

/*! @name MODE_STAT - Mode Status Register */
/*! @{ */

#define MC_ME_MODE_STAT_PREV_MODE_MASK           (0x1U)
#define MC_ME_MODE_STAT_PREV_MODE_SHIFT          (0U)
/*! PREV_MODE - Previous mode
 *  0b0..The previous mode was reset (any reset).
 *  0b1..The previous mode was standby.
 */
#define MC_ME_MODE_STAT_PREV_MODE(x)             (((uint32_t)(((uint32_t)(x)) << MC_ME_MODE_STAT_PREV_MODE_SHIFT)) & MC_ME_MODE_STAT_PREV_MODE_MASK)
/*! @} */

/*! @name MAIN_COREID - Main Core ID Register */
/*! @{ */

#define MC_ME_MAIN_COREID_CIDX_MASK              (0x7U)
#define MC_ME_MAIN_COREID_CIDX_SHIFT             (0U)
/*! CIDX - Core index */
#define MC_ME_MAIN_COREID_CIDX(x)                (((uint32_t)(((uint32_t)(x)) << MC_ME_MAIN_COREID_CIDX_SHIFT)) & MC_ME_MAIN_COREID_CIDX_MASK)

#define MC_ME_MAIN_COREID_PIDX_MASK              (0x1F00U)
#define MC_ME_MAIN_COREID_PIDX_SHIFT             (8U)
/*! PIDX - Partition index */
#define MC_ME_MAIN_COREID_PIDX(x)                (((uint32_t)(((uint32_t)(x)) << MC_ME_MAIN_COREID_PIDX_SHIFT)) & MC_ME_MAIN_COREID_PIDX_MASK)
/*! @} */

/*! @name PRTN0_PCONF - Partition 0 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN0_PCONF_PCE_SHIFT              (0U)
/*! PCE - Partition clock enable
 *  0b0..Disable the clock to IPs
 *  0b1..Enable the clock to IPs
 */
#define MC_ME_PRTN0_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_PCONF_PCE_SHIFT)) & MC_ME_PRTN0_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN0_PUPD - Partition 0 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN0_PUPD_PCUD_SHIFT              (0U)
/*! PCUD - Partition clock update
 *  0b0..Do not trigger the hardware process
 *  0b1..Trigger the hardware process
 */
#define MC_ME_PRTN0_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_PUPD_PCUD_SHIFT)) & MC_ME_PRTN0_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN0_STAT - Partition 0 Status Register */
/*! @{ */

#define MC_ME_PRTN0_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN0_STAT_PCS_SHIFT               (0U)
/*! PCS - Partition clock status
 *  0b0..Clock is inactive
 *  0b1..Clock is active
 */
#define MC_ME_PRTN0_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_STAT_PCS_SHIFT)) & MC_ME_PRTN0_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN0_COFB1_STAT - Partition 0 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN0_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK32_SHIFT     (0U)
/*! BLOCK32 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK33_MASK      (0x2U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK33_SHIFT     (1U)
/*! BLOCK33 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK33(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK33_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK33_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK34_MASK      (0x4U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK34_SHIFT     (2U)
/*! BLOCK34 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK34(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK34_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK34_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK35_SHIFT     (3U)
/*! BLOCK35 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK38_SHIFT     (6U)
/*! BLOCK38 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK39_SHIFT     (7U)
/*! BLOCK39 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK40_MASK      (0x100U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK40_SHIFT     (8U)
/*! BLOCK40 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK40(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK40_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK40_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK41_MASK      (0x200U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK41_SHIFT     (9U)
/*! BLOCK41 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK41(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK41_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK41_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK44_MASK      (0x1000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK44_SHIFT     (12U)
/*! BLOCK44 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK44(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK44_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK44_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK45_SHIFT     (13U)
/*! BLOCK45 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK48_MASK      (0x10000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK48_SHIFT     (16U)
/*! BLOCK48 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK48(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK48_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK48_MASK)

#define MC_ME_PRTN0_COFB1_STAT_BLOCK62_MASK      (0x40000000U)
#define MC_ME_PRTN0_COFB1_STAT_BLOCK62_SHIFT     (30U)
/*! BLOCK62 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN0_COFB1_STAT_BLOCK62(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_STAT_BLOCK62_SHIFT)) & MC_ME_PRTN0_COFB1_STAT_BLOCK62_MASK)
/*! @} */

/*! @name PRTN0_COFB1_CLKEN - Partition 0 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN0_COFB1_CLKEN_REQ32_MASK       (0x1U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ32_SHIFT      (0U)
/*! REQ32 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ32(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ32_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ32_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ33_MASK       (0x2U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ33_SHIFT      (1U)
/*! REQ33 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ33(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ33_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ33_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ34_MASK       (0x4U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ34_SHIFT      (2U)
/*! REQ34 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ34(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ34_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ34_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ35_MASK       (0x8U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ35_SHIFT      (3U)
/*! REQ35 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ35(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ35_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ35_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ38_MASK       (0x40U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ38_SHIFT      (6U)
/*! REQ38 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ38(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ38_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ38_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ39_MASK       (0x80U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ39_SHIFT      (7U)
/*! REQ39 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ39(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ39_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ39_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ40_MASK       (0x100U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ40_SHIFT      (8U)
/*! REQ40 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ40(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ40_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ40_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ41_MASK       (0x200U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ41_SHIFT      (9U)
/*! REQ41 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ41(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ41_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ41_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ44_MASK       (0x1000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ44_SHIFT      (12U)
/*! REQ44 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ44(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ44_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ44_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ45_MASK       (0x2000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ45_SHIFT      (13U)
/*! REQ45 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ45(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ45_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ45_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ48_MASK       (0x10000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ48_SHIFT      (16U)
/*! REQ48 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ48(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ48_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ48_MASK)

#define MC_ME_PRTN0_COFB1_CLKEN_REQ62_MASK       (0x40000000U)
#define MC_ME_PRTN0_COFB1_CLKEN_REQ62_SHIFT      (30U)
/*! REQ62 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN0_COFB1_CLKEN_REQ62(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_COFB1_CLKEN_REQ62_SHIFT)) & MC_ME_PRTN0_COFB1_CLKEN_REQ62_MASK)
/*! @} */

/*! @name PRTN0_CORE0_PCONF - Partition 0 Core 0 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_PCONF_CCE_MASK         (0x1U)
#define MC_ME_PRTN0_CORE0_PCONF_CCE_SHIFT        (0U)
/*! CCE - Core 0 clock enable
 *  0b0..Disable the core clock
 *  0b1..Enable the core clock
 */
#define MC_ME_PRTN0_CORE0_PCONF_CCE(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_PCONF_CCE_SHIFT)) & MC_ME_PRTN0_CORE0_PCONF_CCE_MASK)
/*! @} */

/*! @name PRTN0_CORE0_PUPD - Partition 0 Core 0 Process Update Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_PUPD_CCUPD_MASK        (0x1U)
#define MC_ME_PRTN0_CORE0_PUPD_CCUPD_SHIFT       (0U)
/*! CCUPD - Core 0 clock update
 *  0b0..Do not trigger the hardware process
 *  0b1..Trigger the hardware process
 */
#define MC_ME_PRTN0_CORE0_PUPD_CCUPD(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_PUPD_CCUPD_SHIFT)) & MC_ME_PRTN0_CORE0_PUPD_CCUPD_MASK)
/*! @} */

/*! @name PRTN0_CORE0_STAT - Partition 0 Core 0 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE0_STAT_CCS_SHIFT         (0U)
/*! CCS - Core 0 clock process status
 *  0b0..Clock is inactive.
 *  0b1..Clock is active.
 */
#define MC_ME_PRTN0_CORE0_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE0_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE0_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE0_STAT_WFI_SHIFT         (31U)
/*! WFI - Wait for interrupt status
 *  0b0..No WFI executed
 *  0b1..WFI executed
 */
#define MC_ME_PRTN0_CORE0_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE0_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE0_ADDR - Partition 0 Core 0 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE0_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE0_ADDR_ADDR_SHIFT        (2U)
/*! ADDR - Address */
#define MC_ME_PRTN0_CORE0_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE0_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE0_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN0_CORE2_STAT - Partition 0 Core 2 Status Register */
/*! @{ */

#define MC_ME_PRTN0_CORE2_STAT_CCS_MASK          (0x1U)
#define MC_ME_PRTN0_CORE2_STAT_CCS_SHIFT         (0U)
/*! CCS - Core 2 clock process status
 *  0b1..Clock is active.
 */
#define MC_ME_PRTN0_CORE2_STAT_CCS(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_STAT_CCS_SHIFT)) & MC_ME_PRTN0_CORE2_STAT_CCS_MASK)

#define MC_ME_PRTN0_CORE2_STAT_WFI_MASK          (0x80000000U)
#define MC_ME_PRTN0_CORE2_STAT_WFI_SHIFT         (31U)
/*! WFI - Wait for interrupt status
 *  0b0..No WFI executed
 *  0b1..WFI executed
 */
#define MC_ME_PRTN0_CORE2_STAT_WFI(x)            (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_STAT_WFI_SHIFT)) & MC_ME_PRTN0_CORE2_STAT_WFI_MASK)
/*! @} */

/*! @name PRTN0_CORE2_ADDR - Partition 0 Core 2 Address Register */
/*! @{ */

#define MC_ME_PRTN0_CORE2_ADDR_ADDR_MASK         (0xFFFFFFFCU)
#define MC_ME_PRTN0_CORE2_ADDR_ADDR_SHIFT        (2U)
/*! ADDR - Address */
#define MC_ME_PRTN0_CORE2_ADDR_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN0_CORE2_ADDR_ADDR_SHIFT)) & MC_ME_PRTN0_CORE2_ADDR_ADDR_MASK)
/*! @} */

/*! @name PRTN1_PCONF - Partition 1 Process Configuration Register */
/*! @{ */

#define MC_ME_PRTN1_PCONF_PCE_MASK               (0x1U)
#define MC_ME_PRTN1_PCONF_PCE_SHIFT              (0U)
/*! PCE - Partition clock enable
 *  0b0..Disable the clock to IPs
 *  0b1..Enable the clock to IPs
 */
#define MC_ME_PRTN1_PCONF_PCE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_PCONF_PCE_SHIFT)) & MC_ME_PRTN1_PCONF_PCE_MASK)
/*! @} */

/*! @name PRTN1_PUPD - Partition 1 Process Update Register */
/*! @{ */

#define MC_ME_PRTN1_PUPD_PCUD_MASK               (0x1U)
#define MC_ME_PRTN1_PUPD_PCUD_SHIFT              (0U)
/*! PCUD - Partition clock update
 *  0b0..Do not trigger the hardware process
 *  0b1..Trigger the hardware process
 */
#define MC_ME_PRTN1_PUPD_PCUD(x)                 (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_PUPD_PCUD_SHIFT)) & MC_ME_PRTN1_PUPD_PCUD_MASK)
/*! @} */

/*! @name PRTN1_STAT - Partition 1 Status Register */
/*! @{ */

#define MC_ME_PRTN1_STAT_PCS_MASK                (0x1U)
#define MC_ME_PRTN1_STAT_PCS_SHIFT               (0U)
/*! PCS - Partition clock status
 *  0b0..Clock is inactive
 *  0b1..Clock is active
 */
#define MC_ME_PRTN1_STAT_PCS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_STAT_PCS_SHIFT)) & MC_ME_PRTN1_STAT_PCS_MASK)
/*! @} */

/*! @name PRTN1_COFB0_STAT - Partition 1 COFB Set 0 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN1_COFB0_STAT_BLOCK1_MASK       (0x2U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK1_SHIFT      (1U)
/*! BLOCK1 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK1(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK1_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK1_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK3_MASK       (0x8U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK3_SHIFT      (3U)
/*! BLOCK3 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK3(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK3_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK3_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK4_MASK       (0x10U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK4_SHIFT      (4U)
/*! BLOCK4 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK4(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK4_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK4_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK5_MASK       (0x20U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK5_SHIFT      (5U)
/*! BLOCK5 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK5(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK5_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK5_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK6_MASK       (0x40U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK6_SHIFT      (6U)
/*! BLOCK6 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK6(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK6_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK6_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK7_MASK       (0x80U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK7_SHIFT      (7U)
/*! BLOCK7 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK7(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK7_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK7_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK8_MASK       (0x100U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK8_SHIFT      (8U)
/*! BLOCK8 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK8(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK8_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK8_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK9_MASK       (0x200U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK9_SHIFT      (9U)
/*! BLOCK9 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK9(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK9_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK9_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK10_MASK      (0x400U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK10_SHIFT     (10U)
/*! BLOCK10 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK10(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK10_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK10_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK11_MASK      (0x800U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK11_SHIFT     (11U)
/*! BLOCK11 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK11(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK11_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK11_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK12_MASK      (0x1000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK12_SHIFT     (12U)
/*! BLOCK12 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK12(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK12_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK12_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK13_MASK      (0x2000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK13_SHIFT     (13U)
/*! BLOCK13 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK13(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK13_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK13_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK14_MASK      (0x4000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK14_SHIFT     (14U)
/*! BLOCK14 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK14(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK14_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK14_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK15_MASK      (0x8000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK15_SHIFT     (15U)
/*! BLOCK15 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK15(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK15_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK15_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK16_MASK      (0x10000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK16_SHIFT     (16U)
/*! BLOCK16 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK16(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK16_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK16_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK17_MASK      (0x20000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK17_SHIFT     (17U)
/*! BLOCK17 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK17(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK17_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK17_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK18_MASK      (0x40000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK18_SHIFT     (18U)
/*! BLOCK18 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK18(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK18_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK18_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK19_MASK      (0x80000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK19_SHIFT     (19U)
/*! BLOCK19 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK19(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK19_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK19_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK20_MASK      (0x100000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK20_SHIFT     (20U)
/*! BLOCK20 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK20(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK20_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK20_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK21_MASK      (0x200000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK21_SHIFT     (21U)
/*! BLOCK21 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK21(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK21_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK21_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK22_MASK      (0x400000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK22_SHIFT     (22U)
/*! BLOCK22 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK22(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK22_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK22_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK23_MASK      (0x800000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK23_SHIFT     (23U)
/*! BLOCK23 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK23(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK23_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK23_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK24_MASK      (0x1000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK24_SHIFT     (24U)
/*! BLOCK24 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK24(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK24_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK24_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK25_MASK      (0x2000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK25_SHIFT     (25U)
/*! BLOCK25 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK25(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK25_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK25_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK26_MASK      (0x4000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK26_SHIFT     (26U)
/*! BLOCK26 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK26(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK26_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK26_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK27_MASK      (0x8000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK27_SHIFT     (27U)
/*! BLOCK27 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK27(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK27_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK27_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK28_MASK      (0x10000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK28_SHIFT     (28U)
/*! BLOCK28 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK28(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK28_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK28_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK29_MASK      (0x20000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK29_SHIFT     (29U)
/*! BLOCK29 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK29(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK29_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK29_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK30_MASK      (0x40000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK30_SHIFT     (30U)
/*! BLOCK30 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK30(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK30_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK30_MASK)

#define MC_ME_PRTN1_COFB0_STAT_BLOCK31_MASK      (0x80000000U)
#define MC_ME_PRTN1_COFB0_STAT_BLOCK31_SHIFT     (31U)
/*! BLOCK31 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB0_STAT_BLOCK31(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_STAT_BLOCK31_SHIFT)) & MC_ME_PRTN1_COFB0_STAT_BLOCK31_MASK)
/*! @} */

/*! @name PRTN1_COFB1_STAT - Partition 1 COFB Set 1 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN1_COFB1_STAT_BLOCK32_MASK      (0x1U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK32_SHIFT     (0U)
/*! BLOCK32 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK32(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK32_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK32_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK33_MASK      (0x2U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK33_SHIFT     (1U)
/*! BLOCK33 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK33(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK33_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK33_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK34_MASK      (0x4U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK34_SHIFT     (2U)
/*! BLOCK34 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK34(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK34_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK34_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK35_MASK      (0x8U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK35_SHIFT     (3U)
/*! BLOCK35 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK35(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK35_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK35_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK36_MASK      (0x10U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK36_SHIFT     (4U)
/*! BLOCK36 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK36(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK36_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK36_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK37_MASK      (0x20U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK37_SHIFT     (5U)
/*! BLOCK37 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK37(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK37_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK37_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK38_MASK      (0x40U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK38_SHIFT     (6U)
/*! BLOCK38 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK38(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK38_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK38_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK39_MASK      (0x80U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK39_SHIFT     (7U)
/*! BLOCK39 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK39(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK39_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK39_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK42_MASK      (0x400U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK42_SHIFT     (10U)
/*! BLOCK42 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK42(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK42_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK42_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK43_MASK      (0x800U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK43_SHIFT     (11U)
/*! BLOCK43 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK43(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK43_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK43_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK45_MASK      (0x2000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK45_SHIFT     (13U)
/*! BLOCK45 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK45(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK45_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK45_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK47_MASK      (0x8000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK47_SHIFT     (15U)
/*! BLOCK47 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK47(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK47_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK47_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK49_MASK      (0x20000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK49_SHIFT     (17U)
/*! BLOCK49 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK49(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK49_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK49_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK50_MASK      (0x40000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK50_SHIFT     (18U)
/*! BLOCK50 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK50(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK50_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK50_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK52_MASK      (0x100000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK52_SHIFT     (20U)
/*! BLOCK52 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK52(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK52_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK52_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK53_MASK      (0x200000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK53_SHIFT     (21U)
/*! BLOCK53 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK53(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK53_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK53_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK54_MASK      (0x400000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK54_SHIFT     (22U)
/*! BLOCK54 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK54(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK54_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK54_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK55_MASK      (0x800000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK55_SHIFT     (23U)
/*! BLOCK55 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK55(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK55_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK55_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK56_MASK      (0x1000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK56_SHIFT     (24U)
/*! BLOCK56 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK56(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK56_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK56_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK58_MASK      (0x4000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK58_SHIFT     (26U)
/*! BLOCK58 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK58(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK58_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK58_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK59_MASK      (0x8000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK59_SHIFT     (27U)
/*! BLOCK59 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK59(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK59_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK59_MASK)

#define MC_ME_PRTN1_COFB1_STAT_BLOCK60_MASK      (0x10000000U)
#define MC_ME_PRTN1_COFB1_STAT_BLOCK60_SHIFT     (28U)
/*! BLOCK60 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB1_STAT_BLOCK60(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_STAT_BLOCK60_SHIFT)) & MC_ME_PRTN1_COFB1_STAT_BLOCK60_MASK)
/*! @} */

/*! @name PRTN1_COFB2_STAT - Partition 1 COFB Set 2 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN1_COFB2_STAT_BLOCK65_MASK      (0x2U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK65_SHIFT     (1U)
/*! BLOCK65 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK65(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK65_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK65_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK66_MASK      (0x4U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK66_SHIFT     (2U)
/*! BLOCK66 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK66(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK66_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK66_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK67_MASK      (0x8U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK67_SHIFT     (3U)
/*! BLOCK67 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK67(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK67_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK67_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK73_MASK      (0x200U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK73_SHIFT     (9U)
/*! BLOCK73 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK73(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK73_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK73_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK74_MASK      (0x400U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK74_SHIFT     (10U)
/*! BLOCK74 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK74(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK74_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK74_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK75_MASK      (0x800U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK75_SHIFT     (11U)
/*! BLOCK75 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK75(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK75_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK75_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK76_MASK      (0x1000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK76_SHIFT     (12U)
/*! BLOCK76 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK76(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK76_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK76_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK77_MASK      (0x2000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK77_SHIFT     (13U)
/*! BLOCK77 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK77(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK77_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK77_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK84_MASK      (0x100000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK84_SHIFT     (20U)
/*! BLOCK84 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK84(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK84_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK84_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK85_MASK      (0x200000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK85_SHIFT     (21U)
/*! BLOCK85 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK85(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK85_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK85_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK86_MASK      (0x400000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK86_SHIFT     (22U)
/*! BLOCK86 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK86(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK86_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK86_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK87_MASK      (0x800000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK87_SHIFT     (23U)
/*! BLOCK87 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK87(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK87_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK87_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK88_MASK      (0x1000000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK88_SHIFT     (24U)
/*! BLOCK88 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK88(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK88_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK88_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK89_MASK      (0x2000000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK89_SHIFT     (25U)
/*! BLOCK89 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK89(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK89_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK89_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK92_MASK      (0x10000000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK92_SHIFT     (28U)
/*! BLOCK92 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK92(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK92_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK92_MASK)

#define MC_ME_PRTN1_COFB2_STAT_BLOCK95_MASK      (0x80000000U)
#define MC_ME_PRTN1_COFB2_STAT_BLOCK95_SHIFT     (31U)
/*! BLOCK95 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB2_STAT_BLOCK95(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_STAT_BLOCK95_SHIFT)) & MC_ME_PRTN1_COFB2_STAT_BLOCK95_MASK)
/*! @} */

/*! @name PRTN1_COFB3_STAT - Partition 1 COFB Set 3 Clock Status Register */
/*! @{ */

#define MC_ME_PRTN1_COFB3_STAT_BLOCK96_MASK      (0x1U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK96_SHIFT     (0U)
/*! BLOCK96 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK96(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK96_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK96_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK97_MASK      (0x2U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK97_SHIFT     (1U)
/*! BLOCK97 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK97(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK97_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK97_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK98_MASK      (0x4U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK98_SHIFT     (2U)
/*! BLOCK98 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK98(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK98_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK98_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK99_MASK      (0x8U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK99_SHIFT     (3U)
/*! BLOCK99 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK99(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK99_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK99_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK100_MASK     (0x10U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK100_SHIFT    (4U)
/*! BLOCK100 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK100(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK100_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK100_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK101_MASK     (0x20U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK101_SHIFT    (5U)
/*! BLOCK101 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK101(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK101_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK101_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK102_MASK     (0x40U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK102_SHIFT    (6U)
/*! BLOCK102 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK102(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK102_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK102_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK103_MASK     (0x80U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK103_SHIFT    (7U)
/*! BLOCK103 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK103(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK103_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK103_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK104_MASK     (0x100U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK104_SHIFT    (8U)
/*! BLOCK104 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK104(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK104_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK104_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK105_MASK     (0x200U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK105_SHIFT    (9U)
/*! BLOCK105 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK105(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK105_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK105_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK106_MASK     (0x400U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK106_SHIFT    (10U)
/*! BLOCK106 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK106(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK106_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK106_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK107_MASK     (0x800U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK107_SHIFT    (11U)
/*! BLOCK107 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK107(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK107_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK107_MASK)

#define MC_ME_PRTN1_COFB3_STAT_BLOCK109_MASK     (0x2000U)
#define MC_ME_PRTN1_COFB3_STAT_BLOCK109_SHIFT    (13U)
/*! BLOCK109 - IP block status
 *  0b0..Clock is not running.
 *  0b1..Clock is running.
 */
#define MC_ME_PRTN1_COFB3_STAT_BLOCK109(x)       (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_STAT_BLOCK109_SHIFT)) & MC_ME_PRTN1_COFB3_STAT_BLOCK109_MASK)
/*! @} */

/*! @name PRTN1_COFB0_CLKEN - Partition 1 COFB Set 0 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN1_COFB0_CLKEN_REQ3_MASK        (0x8U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ3_SHIFT       (3U)
/*! REQ3 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ3(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ3_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ3_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ4_MASK        (0x10U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ4_SHIFT       (4U)
/*! REQ4 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ4(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ4_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ4_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ5_MASK        (0x20U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ5_SHIFT       (5U)
/*! REQ5 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ5(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ5_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ5_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ6_MASK        (0x40U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ6_SHIFT       (6U)
/*! REQ6 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ6(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ6_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ6_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ7_MASK        (0x80U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ7_SHIFT       (7U)
/*! REQ7 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ7(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ7_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ7_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ8_MASK        (0x100U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ8_SHIFT       (8U)
/*! REQ8 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ8(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ8_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ8_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ9_MASK        (0x200U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ9_SHIFT       (9U)
/*! REQ9 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ9(x)          (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ9_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ9_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ10_MASK       (0x400U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ10_SHIFT      (10U)
/*! REQ10 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ10(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ10_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ10_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ11_MASK       (0x800U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ11_SHIFT      (11U)
/*! REQ11 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ11(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ11_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ11_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ12_MASK       (0x1000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ12_SHIFT      (12U)
/*! REQ12 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ12(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ12_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ12_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ13_MASK       (0x2000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ13_SHIFT      (13U)
/*! REQ13 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ13(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ13_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ13_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ14_MASK       (0x4000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ14_SHIFT      (14U)
/*! REQ14 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ14(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ14_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ14_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ15_MASK       (0x8000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ15_SHIFT      (15U)
/*! REQ15 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ15(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ15_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ15_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ21_MASK       (0x200000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ21_SHIFT      (21U)
/*! REQ21 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ21(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ21_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ21_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ22_MASK       (0x400000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ22_SHIFT      (22U)
/*! REQ22 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ22(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ22_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ22_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ23_MASK       (0x800000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ23_SHIFT      (23U)
/*! REQ23 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ23(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ23_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ23_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ24_MASK       (0x1000000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ24_SHIFT      (24U)
/*! REQ24 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ24(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ24_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ24_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ28_MASK       (0x10000000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ28_SHIFT      (28U)
/*! REQ28 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ28(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ28_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ28_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ29_MASK       (0x20000000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ29_SHIFT      (29U)
/*! REQ29 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ29(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ29_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ29_MASK)

#define MC_ME_PRTN1_COFB0_CLKEN_REQ31_MASK       (0x80000000U)
#define MC_ME_PRTN1_COFB0_CLKEN_REQ31_SHIFT      (31U)
/*! REQ31 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB0_CLKEN_REQ31(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB0_CLKEN_REQ31_SHIFT)) & MC_ME_PRTN1_COFB0_CLKEN_REQ31_MASK)
/*! @} */

/*! @name PRTN1_COFB1_CLKEN - Partition 1 COFB Set 1 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN1_COFB1_CLKEN_REQ32_MASK       (0x1U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ32_SHIFT      (0U)
/*! REQ32 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ32(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ32_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ32_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ33_MASK       (0x2U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ33_SHIFT      (1U)
/*! REQ33 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ33(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ33_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ33_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ34_MASK       (0x4U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ34_SHIFT      (2U)
/*! REQ34 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ34(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ34_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ34_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ42_MASK       (0x400U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ42_SHIFT      (10U)
/*! REQ42 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ42(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ42_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ42_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ45_MASK       (0x2000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ45_SHIFT      (13U)
/*! REQ45 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ45(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ45_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ45_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ47_MASK       (0x8000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ47_SHIFT      (15U)
/*! REQ47 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ47(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ47_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ47_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ49_MASK       (0x20000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ49_SHIFT      (17U)
/*! REQ49 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ49(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ49_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ49_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ53_MASK       (0x200000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ53_SHIFT      (21U)
/*! REQ53 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ53(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ53_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ53_MASK)

#define MC_ME_PRTN1_COFB1_CLKEN_REQ56_MASK       (0x1000000U)
#define MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT      (24U)
/*! REQ56 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB1_CLKEN_REQ56(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB1_CLKEN_REQ56_SHIFT)) & MC_ME_PRTN1_COFB1_CLKEN_REQ56_MASK)
/*! @} */

/*! @name PRTN1_COFB2_CLKEN - Partition 1 COFB Set 2 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN1_COFB2_CLKEN_REQ65_MASK       (0x2U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ65_SHIFT      (1U)
/*! REQ65 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ65(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ65_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ65_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ66_MASK       (0x4U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ66_SHIFT      (2U)
/*! REQ66 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ66(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ66_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ66_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ67_MASK       (0x8U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ67_SHIFT      (3U)
/*! REQ67 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ67(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ67_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ67_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ73_MASK       (0x200U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ73_SHIFT      (9U)
/*! REQ73 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ73(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ73_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ73_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ74_MASK       (0x400U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ74_SHIFT      (10U)
/*! REQ74 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ74(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ74_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ74_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ75_MASK       (0x800U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ75_SHIFT      (11U)
/*! REQ75 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ75(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ75_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ75_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ76_MASK       (0x1000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ76_SHIFT      (12U)
/*! REQ76 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ76(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ76_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ76_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ77_MASK       (0x2000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ77_SHIFT      (13U)
/*! REQ77 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ77(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ77_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ77_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ84_MASK       (0x100000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ84_SHIFT      (20U)
/*! REQ84 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ84(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ84_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ84_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ85_MASK       (0x200000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ85_SHIFT      (21U)
/*! REQ85 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ85(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ85_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ85_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ86_MASK       (0x400000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ86_SHIFT      (22U)
/*! REQ86 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ86(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ86_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ86_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ87_MASK       (0x800000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ87_SHIFT      (23U)
/*! REQ87 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ87(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ87_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ87_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ88_MASK       (0x1000000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ88_SHIFT      (24U)
/*! REQ88 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ88(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ88_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ88_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ89_MASK       (0x2000000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ89_SHIFT      (25U)
/*! REQ89 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ89(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ89_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ89_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ92_MASK       (0x10000000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ92_SHIFT      (28U)
/*! REQ92 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ92(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ92_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ92_MASK)

#define MC_ME_PRTN1_COFB2_CLKEN_REQ95_MASK       (0x80000000U)
#define MC_ME_PRTN1_COFB2_CLKEN_REQ95_SHIFT      (31U)
/*! REQ95 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB2_CLKEN_REQ95(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB2_CLKEN_REQ95_SHIFT)) & MC_ME_PRTN1_COFB2_CLKEN_REQ95_MASK)
/*! @} */

/*! @name PRTN1_COFB3_CLKEN - Partition 1 COFB Set 3 Clock Enable Register */
/*! @{ */

#define MC_ME_PRTN1_COFB3_CLKEN_REQ96_MASK       (0x1U)
#define MC_ME_PRTN1_COFB3_CLKEN_REQ96_SHIFT      (0U)
/*! REQ96 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB3_CLKEN_REQ96(x)         (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_CLKEN_REQ96_SHIFT)) & MC_ME_PRTN1_COFB3_CLKEN_REQ96_MASK)

#define MC_ME_PRTN1_COFB3_CLKEN_REQ102_MASK      (0x40U)
#define MC_ME_PRTN1_COFB3_CLKEN_REQ102_SHIFT     (6U)
/*! REQ102 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB3_CLKEN_REQ102(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_CLKEN_REQ102_SHIFT)) & MC_ME_PRTN1_COFB3_CLKEN_REQ102_MASK)

#define MC_ME_PRTN1_COFB3_CLKEN_REQ104_MASK      (0x100U)
#define MC_ME_PRTN1_COFB3_CLKEN_REQ104_SHIFT     (8U)
/*! REQ104 - Clock enable
 *  0b0..Clock is turned off.
 *  0b1..Clock is turned on.
 */
#define MC_ME_PRTN1_COFB3_CLKEN_REQ104(x)        (((uint32_t)(((uint32_t)(x)) << MC_ME_PRTN1_COFB3_CLKEN_REQ104_SHIFT)) & MC_ME_PRTN1_COFB3_CLKEN_REQ104_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MC_ME_Register_Masks */


/*!
 * @}
 */ /* end of group MC_ME_Peripheral_Access_Layer */


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


#endif  /* PERI_MC_ME_H_ */

