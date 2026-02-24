/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_NS_AONMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
 */

#if !defined(PERI_BLK_CTRL_NS_AONMIX_H_)
#define PERI_BLK_CTRL_NS_AONMIX_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- BLK_CTRL_NS_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer BLK_CTRL_NS_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NS_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPC_CFG;                           /**< GPC CORE SLEEP Request Select, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t IPG_DEBUG_CM33;                    /**< IPG Debug Mask Bit for CM33, offset: 0x8 */
  __IO uint32_t IPG_DEBUG_CA55C0;                  /**< IPG Debug Mask Bit CA55 Core0, offset: 0xC */
  __IO uint32_t IPG_DEBUG_CA55C1;                  /**< IPG Debug Mask Bit CA55 Core1, offset: 0x10 */
  __IO uint32_t IPG_DEBUG_CA55C2;                  /**< IPG Debug Mask Bit CA55 Core2, offset: 0x14 */
  __IO uint32_t IPG_DEBUG_CA55C3;                  /**< IPG Debug Mask Bit CA55 Core3, offset: 0x18 */
       uint8_t RESERVED_1[8];
  __IO uint32_t IPG_DEBUG_CM7;                     /**< IPG Debug Mask Bit for CM7, offset: 0x24 */
  __I  uint32_t FUSE_ACC_DIS;                      /**< Read-only Version of OCOTP Fuse-access-disable Bit, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __I  uint32_t OCOTP_FUSE_DATA0;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_0, offset: 0x30 */
  __I  uint32_t OCOTP_FUSE_DATA1;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_1, offset: 0x34 */
  __I  uint32_t OCOTP_FUSE_DATA2;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_2, offset: 0x38 */
  __I  uint32_t OCOTP_FUSE_DATA3;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_3, offset: 0x3C */
  __I  uint32_t OCOTP_FUSE_DATA4;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_4, offset: 0x40 */
  __I  uint32_t OCOTP_FUSE_DATA5;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_5, offset: 0x44 */
  __I  uint32_t OCOTP_FUSE_DATA6;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_6, offset: 0x48 */
  __I  uint32_t OCOTP_FUSE_DATA7;                  /**< Read-only Version of OCOTP fusedata_mtr_cfg_7, offset: 0x4C */
  __I  uint32_t OCOTP_FUSE_DATA8;                  /**< Read-only Version of OCOTP fusedata_mem_trim_cfg0, offset: 0x50 */
  __I  uint32_t OCOTP_FUSE_DATA9;                  /**< Read-only Version of OCOTP fusedata_mem_trim_cfg1, offset: 0x54 */
  __I  uint32_t OCOTP_FUSE_DATA10;                 /**< Read-only Version of OCOTP fusedata_mem_trim_cfg2, offset: 0x58 */
  __I  uint32_t OCOTP_FUSE_DATA11;                 /**< Read-only Version of OCOTP fusedata_mem_trim_cfg3, offset: 0x5C */
  __I  uint32_t OCOTP_FUSE_DATA12;                 /**< Read-only Version of OCOTP fusedata_mem_trim_cfg4, offset: 0x60 */
  __I  uint32_t OCOTP_FUSE_DATA13;                 /**< Read-only Version of OCOTP fusedata_mem_trim_cfg5, offset: 0x64 */
  __I  uint32_t OCOTP_FUSE_DATA14;                 /**< Read-only Version of OCOTP fusedata_mem_trim_cfg6, offset: 0x68 */
  __I  uint32_t OCOTP_FUSE_DATA15;                 /**< Read-only Version of OCOTP fusedata_mem_trim_cfg7, offset: 0x6C */
  __IO uint32_t I3C1_WAKEUP;                       /**< I3C1 WAKEUPX CLR, offset: 0x70 */
       uint8_t RESERVED_3[4];
  __IO uint32_t PDM_CLK_SEL;                       /**< PDM Clock Selection, offset: 0x78 */
  __IO uint32_t I3C1_SDA_IRQ;                      /**< I3C1 SDA IRQ, offset: 0x7C */
  __I  uint32_t SSI;                               /**< SSI Initiator Low Power Mode Control, offset: 0x80 */
  __I  uint32_t FASTBOOT_ENABLE;                   /**< Fastboot Enable, offset: 0x84 */
  __IO uint32_t MQS_SETTINGS;                      /**< MQS Settings, offset: 0x88 */
  __I  uint32_t ELE_FW_PRESENT;                    /**< Read-only Bit for Fuse ELE_FW_PRESENT, offset: 0x8C */
  __I  uint32_t AOMIX_SPARE_FUSE;                  /**< Spare Fuse, offset: 0x90 */
  __IO uint32_t PCIE_ENET_COMBO_PHY;               /**< PCIe/ENET COMBO PHY Configuration, offset: 0x94 */
  __IO uint32_t CA55_CLUSTER;                      /**< Cortex-A55 CLUSTER Configuration, offset: 0x98 */
} BLK_CTRL_NS_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NS_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Register_Masks BLK_CTRL_NS_AONMIX Register Masks
 * @{
 */

/*! @name GPC_CFG - GPC CORE SLEEP Request Select */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_SHIFT (0U)
/*! M33_SLEEP_SEL - M33 SLEEP Request Select
 *  0b0..Select SLEEPING as request source
 *  0b1..Select SLEEPDEEP as request source
 */
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK)

#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_SHIFT (1U)
/*! M7_SLEEP_SEL - M7 SLEEP Request Select
 *  0b0..Select SLEEPING as request source
 *  0b1..Select SLEEPDEEP as request source
 */
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM33 - IPG Debug Mask Bit for CM33 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_can1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_can1_SHIFT (0U)
/*! can1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_can1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_can1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_can1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_edma1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_edma1_SHIFT (1U)
/*! edma1 - eDMA3_1 Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_edma1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_edma1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_edma1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpi2c2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpit1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpit1_SHIFT (4U)
/*! lpit1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpit1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpit1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpit1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lpspi2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lptmr1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lptmr1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lptmr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lptmr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_lptmr1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sai1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sai1_SHIFT (8U)
/*! sai1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sai1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sai1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sai1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm1_SHIFT (9U)
/*! tpm1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm2_SHIFT (10U)
/*! tpm2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_tpm2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog1_SHIFT (11U)
/*! wdog1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog2_SHIFT (12U)
/*! wdog2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_wdog2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_i3c1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_i3c1_SHIFT (13U)
/*! i3c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_i3c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_i3c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_i3c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_pdm_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_pdm_SHIFT (14U)
/*! pdm - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_pdm(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_pdm_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_pdm_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sys_ctr1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sys_ctr1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM33
 *  0b1..Block enters debug Halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sys_ctr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sys_ctr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM33_sys_ctr1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C0 - IPG Debug Mask Bit CA55 Core0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_can1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_can1_SHIFT (0U)
/*! can1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_can1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_can1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_can1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_edma1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_edma1_SHIFT (1U)
/*! edma1 - eDMA3_1 Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_edma1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_edma1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_edma1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpi2c2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpit1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpit1_SHIFT (4U)
/*! lpit1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpit1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpit1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpit1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lpspi2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lptmr1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lptmr1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lptmr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lptmr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_lptmr1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sai1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sai1_SHIFT (8U)
/*! sai1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sai1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sai1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sai1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm1_SHIFT (9U)
/*! tpm1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm2_SHIFT (10U)
/*! tpm2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_tpm2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog1_SHIFT (11U)
/*! wdog1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog2_SHIFT (12U)
/*! wdog2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_wdog2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_i3c1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_i3c1_SHIFT (13U)
/*! i3c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_i3c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_i3c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_i3c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_pdm_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_pdm_SHIFT (14U)
/*! pdm - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_pdm(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_pdm_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_pdm_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sys_ctr1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sys_ctr1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sys_ctr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sys_ctr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C0_sys_ctr1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C1 - IPG Debug Mask Bit CA55 Core1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_can1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_can1_SHIFT (0U)
/*! can1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_can1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_can1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_can1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_edma1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_edma1_SHIFT (1U)
/*! edma1 - eDMA3_1 Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_edma1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_edma1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_edma1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpi2c2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpit1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpit1_SHIFT (4U)
/*! lpit1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpit1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpit1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpit1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lpspi2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lptmr1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lptmr1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lptmr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lptmr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_lptmr1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sai1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sai1_SHIFT (8U)
/*! sai1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sai1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sai1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sai1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm1_SHIFT (9U)
/*! tpm1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm2_SHIFT (10U)
/*! tpm2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_tpm2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog1_SHIFT (11U)
/*! wdog1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog2_SHIFT (12U)
/*! wdog2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_wdog2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_i3c1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_i3c1_SHIFT (13U)
/*! i3c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_i3c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_i3c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_i3c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_pdm_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_pdm_SHIFT (14U)
/*! pdm - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_pdm(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_pdm_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_pdm_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sys_ctr1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sys_ctr1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sys_ctr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sys_ctr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C1_sys_ctr1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C2 - IPG Debug Mask Bit CA55 Core2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_can1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_can1_SHIFT (0U)
/*! can1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_can1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_can1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_can1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_edma1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_edma1_SHIFT (1U)
/*! edma1 - eDMA3_1 Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_edma1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_edma1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_edma1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpi2c2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpit1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpit1_SHIFT (4U)
/*! lpit1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpit1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpit1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpit1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lpspi2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lptmr1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lptmr1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lptmr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lptmr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_lptmr1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sai1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sai1_SHIFT (8U)
/*! sai1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sai1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sai1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sai1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm1_SHIFT (9U)
/*! tpm1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm2_SHIFT (10U)
/*! tpm2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_tpm2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog1_SHIFT (11U)
/*! wdog1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog2_SHIFT (12U)
/*! wdog2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_wdog2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_i3c1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_i3c1_SHIFT (13U)
/*! i3c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_i3c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_i3c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_i3c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_pdm_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_pdm_SHIFT (14U)
/*! pdm - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_pdm(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_pdm_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_pdm_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sys_ctr1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sys_ctr1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sys_ctr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sys_ctr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C2_sys_ctr1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CA55C3 - IPG Debug Mask Bit CA55 Core3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_can1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_can1_SHIFT (0U)
/*! can1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_can1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_can1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_can1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_edma1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_edma1_SHIFT (1U)
/*! edma1 - eDMA3_1 Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_edma1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_edma1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_edma1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpi2c2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpit1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpit1_SHIFT (4U)
/*! lpit1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpit1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpit1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpit1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lpspi2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lptmr1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lptmr1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lptmr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lptmr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_lptmr1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sai1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sai1_SHIFT (8U)
/*! sai1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sai1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sai1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sai1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm1_SHIFT (9U)
/*! tpm1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm2_SHIFT (10U)
/*! tpm2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_tpm2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog1_SHIFT (11U)
/*! wdog1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog2_SHIFT (12U)
/*! wdog2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_wdog2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_i3c1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_i3c1_SHIFT (13U)
/*! i3c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_i3c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_i3c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_i3c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_pdm_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_pdm_SHIFT (14U)
/*! pdm - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_pdm(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_pdm_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_pdm_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sys_ctr1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sys_ctr1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CA55
 *  0b1..Block enters debug Halted mode when CA55 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sys_ctr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sys_ctr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CA55C3_sys_ctr1_MASK)
/*! @} */

/*! @name IPG_DEBUG_CM7 - IPG Debug Mask Bit for CM7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_can1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_can1_SHIFT (0U)
/*! can1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_can1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_can1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_can1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_edma1_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_edma1_SHIFT (1U)
/*! edma1 - eDMA3_1 Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_edma1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_edma1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_edma1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c1_SHIFT (2U)
/*! lpi2c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c2_SHIFT (3U)
/*! lpi2c2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpi2c2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpit1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpit1_SHIFT (4U)
/*! lpit1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpit1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpit1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpit1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi1_SHIFT (5U)
/*! lpspi1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi2_SHIFT (6U)
/*! lpspi2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lpspi2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lptmr1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lptmr1_SHIFT (7U)
/*! lptmr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lptmr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lptmr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_lptmr1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sai1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sai1_SHIFT (8U)
/*! sai1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sai1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sai1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sai1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm1_SHIFT (9U)
/*! tpm1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm2_SHIFT (10U)
/*! tpm2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_tpm2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog1_SHIFT (11U)
/*! wdog1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog2_SHIFT (12U)
/*! wdog2 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_wdog2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_i3c1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_i3c1_SHIFT (13U)
/*! i3c1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_i3c1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_i3c1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_i3c1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_pdm_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_pdm_SHIFT (14U)
/*! pdm - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_pdm(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_pdm_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_pdm_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sys_ctr1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sys_ctr1_SHIFT (15U)
/*! sys_ctr1 - Mask bit for debug Halted mode
 *  0b0..Block does not enter debug Halted mode with CM7
 *  0b1..Block enters debug Halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sys_ctr1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sys_ctr1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_CM7_sys_ctr1_MASK)
/*! @} */

/*! @name FUSE_ACC_DIS - Read-only Version of OCOTP Fuse-access-disable Bit */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT (0U)
/*! OSCCA_FUSE_READ_DIS - Fuse read disable bit
 *  0b0..SoC is allowed to access the OCOTP registers
 *  0b1..SoC is not allowed to access the OCOTP
 */
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT)) & BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA0 - Read-only Version of OCOTP fusedata_mtr_cfg_0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_SHIFT (0U)
/*! OCOTP_FUSE_DATA0 - OCOTP_FUSE_DATA0 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA0_OCOTP_FUSE_DATA0_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA1 - Read-only Version of OCOTP fusedata_mtr_cfg_1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_SHIFT (0U)
/*! OCOTP_FUSE_DATA1 - OCOTP_FUSE_DATA1 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA1_OCOTP_FUSE_DATA1_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA2 - Read-only Version of OCOTP fusedata_mtr_cfg_2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_SHIFT (0U)
/*! OCOTP_FUSE_DATA2 - OCOTP_FUSE_DATA2 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA2_OCOTP_FUSE_DATA2_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA3 - Read-only Version of OCOTP fusedata_mtr_cfg_3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_SHIFT (0U)
/*! OCOTP_FUSE_DATA3 - OCOTP_FUSE_DATA3 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA3_OCOTP_FUSE_DATA3_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA4 - Read-only Version of OCOTP fusedata_mtr_cfg_4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_SHIFT (0U)
/*! OCOTP_FUSE_DATA4 - OCOTP_FUSE_DATA4 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA4_OCOTP_FUSE_DATA4_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA5 - Read-only Version of OCOTP fusedata_mtr_cfg_5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_SHIFT (0U)
/*! OCOTP_FUSE_DATA5 - OCOTP_FUSE_DATA5 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA5_OCOTP_FUSE_DATA5_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA6 - Read-only Version of OCOTP fusedata_mtr_cfg_6 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_SHIFT (0U)
/*! OCOTP_FUSE_DATA6 - OCOTP_FUSE_DATA6 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA6_OCOTP_FUSE_DATA6_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA7 - Read-only Version of OCOTP fusedata_mtr_cfg_7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_SHIFT (0U)
/*! OCOTP_FUSE_DATA7 - OCOTP_FUSE_DATA7 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA7_OCOTP_FUSE_DATA7_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA8 - Read-only Version of OCOTP fusedata_mem_trim_cfg0 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_SHIFT (0U)
/*! OCOTP_FUSE_DATA8 - OCOTP_FUSE_DATA8 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA8_OCOTP_FUSE_DATA8_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA9 - Read-only Version of OCOTP fusedata_mem_trim_cfg1 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_SHIFT (0U)
/*! OCOTP_FUSE_DATA9 - OCOTP_FUSE_DATA9 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA9_OCOTP_FUSE_DATA9_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA10 - Read-only Version of OCOTP fusedata_mem_trim_cfg2 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_SHIFT (0U)
/*! OCOTP_FUSE_DATA10 - OCOTP_FUSE_DATA10 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA10_OCOTP_FUSE_DATA10_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA11 - Read-only Version of OCOTP fusedata_mem_trim_cfg3 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_SHIFT (0U)
/*! OCOTP_FUSE_DATA11 - OCOTP_FUSE_DATA12 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA11_OCOTP_FUSE_DATA11_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA12 - Read-only Version of OCOTP fusedata_mem_trim_cfg4 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_SHIFT (0U)
/*! OCOTP_FUSE_DATA12 - OCOTP_FUSE_DATA13 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA12_OCOTP_FUSE_DATA12_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA13 - Read-only Version of OCOTP fusedata_mem_trim_cfg5 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_SHIFT (0U)
/*! OCOTP_FUSE_DATA13 - OCOTP_FUSE_DATA13 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA13_OCOTP_FUSE_DATA13_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA14 - Read-only Version of OCOTP fusedata_mem_trim_cfg6 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_SHIFT (0U)
/*! OCOTP_FUSE_DATA14 - OCOTP_FUSE_DATA14 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA14_OCOTP_FUSE_DATA14_MASK)
/*! @} */

/*! @name OCOTP_FUSE_DATA15 - Read-only Version of OCOTP fusedata_mem_trim_cfg7 */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_MASK (0xFFFFFFFFU)
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_SHIFT (0U)
/*! OCOTP_FUSE_DATA15 - OCOTP_FUSE_DATA15 */
#define BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_SHIFT)) & BLK_CTRL_NS_AONMIX_OCOTP_FUSE_DATA15_OCOTP_FUSE_DATA15_MASK)
/*! @} */

/*! @name I3C1_WAKEUP - I3C1 WAKEUPX CLR */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_irq_clr_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_irq_clr_SHIFT (0U)
/*! irq_clr - I3C1 interrupt request clear */
#define BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_irq_clr(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_irq_clr_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_WAKEUP_irq_clr_MASK)
/*! @} */

/*! @name PDM_CLK_SEL - PDM Clock Selection */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_sel_MASK  (0x1U)
#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_sel_SHIFT (0U)
/*! sel - select source for pdm clock
 *  0b0..PDM root clock
 *  0b1..SAI1_MCLK
 */
#define BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_sel(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_sel_SHIFT)) & BLK_CTRL_NS_AONMIX_PDM_CLK_SEL_sel_MASK)
/*! @} */

/*! @name I3C1_SDA_IRQ - I3C1 SDA IRQ */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_enable_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_enable_SHIFT (0U)
/*! enable - IRQ enable bit
 *  0b0..I3C1 SDA IRQ disable
 *  0b1..I3C1 SDA IRQ enable
 */
#define BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_enable_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_SDA_IRQ_enable_MASK)
/*! @} */

/*! @name SSI - SSI Initiator Low Power Mode Control */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_MASK   (0x1U)
#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_SHIFT  (0U)
/*! PAUSE_MODE - AONMIX SSI Initiator Pause Mode
 *  0b0..AONMIX SSI initiator is not in pause mode
 *  0b1..AONMIX SSI initiator is in pause mode
 */
#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_SHIFT)) & BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_MASK)
/*! @} */

/*! @name FASTBOOT_ENABLE - Fastboot Enable */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_MASK (0x3U)
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_SHIFT (0U)
/*! FASTBOOT_ENABLE - FASTBOOT_ENABLE bits */
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_FASTBOOT_ENABLE_MASK)

#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_MASK (0xCU)
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_SHIFT (2U)
/*! BP_FASTBOOT_ENABLE - BP_FASTBOOT_ENABLE bits */
#define BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_SHIFT)) & BLK_CTRL_NS_AONMIX_FASTBOOT_ENABLE_BP_FASTBOOT_ENABLE_MASK)
/*! @} */

/*! @name MQS_SETTINGS - MQS Settings */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_SHIFT (1U)
/*! MQS_EN - MQS Enable
 *  0b0..Disable MQS
 *  0b1..Enable MQS
 */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_MQS_EN_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_SHIFT (2U)
/*! SOFT_RESET - Software Reset
 *  0b0..Exit software reset for MQS
 *  0b1..Enable software reset for MQS
 */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_SOFT_RESET_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_SHIFT (3U)
/*! OVERSAMPLE - Oversample rate
 *  0b0..64
 *  0b1..32
 */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_OVERSAMPLE_MASK)

#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_MASK (0xFF00U)
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_SHIFT (8U)
/*! CLK_DIVIDE - Clock divide factor configuration */
#define BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_SHIFT)) & BLK_CTRL_NS_AONMIX_MQS_SETTINGS_CLK_DIVIDE_MASK)
/*! @} */

/*! @name ELE_FW_PRESENT - Read-only Bit for Fuse ELE_FW_PRESENT */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_ELE_FW_PRESENT_ELE_fw_present_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_ELE_FW_PRESENT_ELE_fw_present_SHIFT (0U)
/*! ELE_fw_present - Read-only bit for ELE FW present */
#define BLK_CTRL_NS_AONMIX_ELE_FW_PRESENT_ELE_fw_present(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_ELE_FW_PRESENT_ELE_fw_present_SHIFT)) & BLK_CTRL_NS_AONMIX_ELE_FW_PRESENT_ELE_fw_present_MASK)
/*! @} */

/*! @name AOMIX_SPARE_FUSE - Spare Fuse */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_Spare_fuse_MASK (0x3U)
#define BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_Spare_fuse_SHIFT (0U)
/*! Spare_fuse - Read-only bit for Spare fuse */
#define BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_Spare_fuse(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_Spare_fuse_SHIFT)) & BLK_CTRL_NS_AONMIX_AOMIX_SPARE_FUSE_Spare_fuse_MASK)
/*! @} */

/*! @name PCIE_ENET_COMBO_PHY - PCIe/ENET COMBO PHY Configuration */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_PCIE_ENET_COMBO_PHY_combophy_mode_MASK (0x7U)
#define BLK_CTRL_NS_AONMIX_PCIE_ENET_COMBO_PHY_combophy_mode_SHIFT (0U)
/*! combophy_mode - COMBO PHY Mode Select
 *  0b000..PCIe
 *  0b001..PCIe
 *  0b010..PCIe
 *  0b011..Ethernet
 *  0b100..Ethernet
 */
#define BLK_CTRL_NS_AONMIX_PCIE_ENET_COMBO_PHY_combophy_mode(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_PCIE_ENET_COMBO_PHY_combophy_mode_SHIFT)) & BLK_CTRL_NS_AONMIX_PCIE_ENET_COMBO_PHY_combophy_mode_MASK)
/*! @} */

/*! @name CA55_CLUSTER - Cortex-A55 CLUSTER Configuration */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_CA55_CLUSTER_AWAKEUPS_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_CA55_CLUSTER_AWAKEUPS_SHIFT (0U)
/*! AWAKEUPS - ACP Activity Indicator
 *  0b0..Not active
 *  0b1..Active
 */
#define BLK_CTRL_NS_AONMIX_CA55_CLUSTER_AWAKEUPS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_CA55_CLUSTER_AWAKEUPS_SHIFT)) & BLK_CTRL_NS_AONMIX_CA55_CLUSTER_AWAKEUPS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_NS_AONMIX_H_ */

