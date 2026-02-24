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
**         CMSIS Peripheral Access Layer for BLK_CTRL_NETCMIX
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
 * @file PERI_BLK_CTRL_NETCMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NETCMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NETCMIX
 */

#if !defined(PERI_BLK_CTRL_NETCMIX_H_)
#define PERI_BLK_CTRL_NETCMIX_H_                 /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_NETCMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NETCMIX_Peripheral_Access_Layer BLK_CTRL_NETCMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NETCMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t MQS_SETTING;                       /**< MQS Settings, offset: 0x0 */
  __IO uint32_t NETCMIX_CLK_SEL;                   /**< NETC clock select, offset: 0x4 */
  __IO uint32_t IPG_DEBUG_SAI2;                    /**< Each core's debug mode, offset: 0x8 */
  __IO uint32_t CFG_LINK_IO_VAR;                   /**< NETC cfg_link_io_var, offset: 0xC */
  __IO uint32_t CFG_LINK_MII_PROT;                 /**< NETC cfg_link_mii_prot, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CFG_LINK_PCS_PROT_1;               /**< NETC PCS protocol on link1, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CFG_SRC_ID;                        /**< NETC cfg_src_id, offset: 0x20 */
  __IO uint32_t LPCG;                              /**< force_on_off and force_on_off_sel for LPCGs, offset: 0x24 */
  __IO uint32_t ENETLINK;                          /**< Control register for enetlink, offset: 0x28 */
  __IO uint32_t NETC;                              /**< NETC Control, offset: 0x2C */
} BLK_CTRL_NETCMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NETCMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NETCMIX_Register_Masks BLK_CTRL_NETCMIX Register Masks
 * @{
 */

/*! @name MQS_SETTING - MQS Settings */
/*! @{ */

#define BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN_MASK (0x4U)
#define BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN_SHIFT (2U)
/*! MQS_EN - MQS enable
 *  0b0..Disable MQS
 *  0b1..Enable MQS
 */
#define BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN_SHIFT)) & BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN_MASK)

#define BLK_CTRL_NETCMIX_MQS_SETTING_SOFT_RESET_MASK (0x8U)
#define BLK_CTRL_NETCMIX_MQS_SETTING_SOFT_RESET_SHIFT (3U)
/*! SOFT_RESET - MQS software reset
 *  0b0..Exit software reset for MQS
 *  0b1..Enable software reset for MQS
 */
#define BLK_CTRL_NETCMIX_MQS_SETTING_SOFT_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_MQS_SETTING_SOFT_RESET_SHIFT)) & BLK_CTRL_NETCMIX_MQS_SETTING_SOFT_RESET_MASK)

#define BLK_CTRL_NETCMIX_MQS_SETTING_OVERSAMPLE_MASK (0x10U)
#define BLK_CTRL_NETCMIX_MQS_SETTING_OVERSAMPLE_SHIFT (4U)
/*! OVERSAMPLE - Controls the PWM oversampling rate compared with MCLK.
 *  0b0..32
 *  0b1..64
 */
#define BLK_CTRL_NETCMIX_MQS_SETTING_OVERSAMPLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_MQS_SETTING_OVERSAMPLE_SHIFT)) & BLK_CTRL_NETCMIX_MQS_SETTING_OVERSAMPLE_MASK)

#define BLK_CTRL_NETCMIX_MQS_SETTING_CLK_DIVIDE_MASK (0x1FE00U)
#define BLK_CTRL_NETCMIX_MQS_SETTING_CLK_DIVIDE_SHIFT (9U)
/*! CLK_DIVIDE - Clock divide factor configuration */
#define BLK_CTRL_NETCMIX_MQS_SETTING_CLK_DIVIDE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_MQS_SETTING_CLK_DIVIDE_SHIFT)) & BLK_CTRL_NETCMIX_MQS_SETTING_CLK_DIVIDE_MASK)
/*! @} */

/*! @name NETCMIX_CLK_SEL - NETC clock select */
/*! @{ */

#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK1_MASK (0x1U)
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK1_SHIFT (0U)
/*! SAI2_MCLK1 - SAI2 MCLK1 clock root select
 *  0b0..SAI2_CLK_ROOT
 *  0b1..SAI2_IPP_IND_SAI_MCLK
 */
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK1_SHIFT)) & BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK1_MASK)

#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK2_MASK (0x1EU)
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK2_SHIFT (1U)
/*! SAI2_MCLK2 - SAI2 MCLK2 clock root select
 *  0b0000..SAI1_CLK_ROOT
 *  0b0001..SAI2_CLK_ROOT
 *  0b0010..SAI3_CLK_ROOT
 *  0b0011..SAI4_CLK_ROOT
 *  0b0100..SAI5_CLK_ROOT
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..SAI1_IPP_IND_SAI_MCLK
 *  0b1000..SAI2_IPP_IND_SAI_MCLK
 *  0b1001..SAI3_IPP_IND_SAI_MCLK
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK2_SHIFT)) & BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK2_MASK)

#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET1_TD2_DIR_MASK (0x20U)
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET1_TD2_DIR_SHIFT (5U)
/*! ENET1_TD2_DIR - ENET1_TD2 direction
 *  0b0..ENET1_TD2 set as ETH0_RMII_REF50_CLK input (RMII clock from PHY)
 *  0b1..ENET1_TD2 set as ENET_REF_CLK_ROOT output (RMII clock to PHY)
 */
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET1_TD2_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET1_TD2_DIR_SHIFT)) & BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET1_TD2_DIR_MASK)

#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK3_MASK (0x3C0U)
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK3_SHIFT (6U)
/*! SAI2_MCLK3 - SAI2 MCLK3 clock root select
 *  0b0000..SAI1_CLK_ROOT
 *  0b0001..SAI2_CLK_ROOT
 *  0b0010..SAI3_CLK_ROOT
 *  0b0011..SAI4_CLK_ROOT
 *  0b0100..SAI5_CLK_ROOT
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..SAI1_IPP_IND_SAI_MCLK
 *  0b1000..SAI2_IPP_IND_SAI_MCLK
 *  0b1001..SAI3_IPP_IND_SAI_MCLK
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK3_SHIFT)) & BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_SAI2_MCLK3_MASK)

#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET2_TD2_DIR_MASK (0x400U)
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET2_TD2_DIR_SHIFT (10U)
/*! ENET2_TD2_DIR - ENET2_TD2 direction
 *  0b0..ENET2_TD2 set as ETH1_RMII_REF50_CLK input (RMII clock from PHY)
 *  0b1..ENET2_TD2 set as ENET_REF_CLK_ROOT output (RMII clock to PHY)
 */
#define BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET2_TD2_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET2_TD2_DIR_SHIFT)) & BLK_CTRL_NETCMIX_NETCMIX_CLK_SEL_ENET2_TD2_DIR_MASK)
/*! @} */

/*! @name IPG_DEBUG_SAI2 - Each core's debug mode */
/*! @{ */

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE0_MASK (0x1U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE0_SHIFT (0U)
/*! IPG_DEBUG_CA55_CORE0 - CA55 core0 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE0_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE0_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1_MASK (0x2U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1_SHIFT (1U)
/*! IPG_DEBUG_CA55_CORE1 - CA55 core1 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_MASK (0x4U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_SHIFT (2U)
/*! IPG_DEBUG_CA55_CORE2 - CA55 core2 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_MASK (0x8U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_SHIFT (3U)
/*! IPG_DEBUG_CA55_CORE3 - CA55 core3 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_MASK (0x10U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_SHIFT (4U)
/*! IPG_DEBUG_CA55_CORE4 - CA55 core4 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_MASK (0x20U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_SHIFT (5U)
/*! IPG_DEBUG_CA55_CORE5 - CA55 core5 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_MASK (0x40U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_SHIFT (6U)
/*! IPG_DEBUG_CM33 - CM33 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7_MASK (0x80U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7_SHIFT (7U)
/*! IPG_DEBUG_M7 - M7 in debug mode
 *  0b0..Core does not enter debug mode
 *  0b1..Core enters debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7_MASK)
/*! @} */

/*! @name CFG_LINK_IO_VAR - NETC cfg_link_io_var */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_0_MASK (0xFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_0_SHIFT (0U)
/*! CFG_LINK_IO_VAR_0 - I/O variant supported by SoC on link 0
 *  0b0000..None
 *  0b0001..16FF 16G SerDes
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_0_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_0_MASK)

#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1_MASK (0xF0U)
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1_SHIFT (4U)
/*! CFG_LINK_IO_VAR_1 - I/O variant supported by SoC on link 1
 *  0b0000..None
 *  0b0001..16FF 16G SerDes
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1_MASK)
/*! @} */

/*! @name CFG_LINK_MII_PROT - NETC cfg_link_mii_prot */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0_MASK (0xFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0_SHIFT (0U)
/*! CFG_LINK_MII_PROT_0 - NETC MII protocol on link0
 *  0b0000..MII
 *  0b0001..RMII
 *  0b0010..RGMII
 *  0b0011..Reserved
 *  0b0100..SGMII
 *  0b0101..XGMII
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0_MASK)

#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1_MASK (0xF0U)
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1_SHIFT (4U)
/*! CFG_LINK_MII_PROT_1 - NETC MII protocol on link1
 *  0b0000..MII
 *  0b0001..RMII
 *  0b0010..RGMII
 *  0b0011..Reserved
 *  0b0100..SGMII
 *  0b0101..XGMII
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1_MASK)
/*! @} */

/*! @name CFG_LINK_PCS_PROT_1 - NETC PCS protocol on link1 */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_MASK (0xFFFFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_SHIFT (0U)
/*! CFG_LINK_PCS_PROT_1 - PCS protocol on link1 */
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_MASK)
/*! @} */

/*! @name CFG_SRC_ID - NETC cfg_src_id */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_MASK (0xFFU)
#define BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_SHIFT (0U)
/*! CFG_SRC_ID - NETC cfgsrc_id */
#define BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_SHIFT)) & BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_MASK)
/*! @} */

/*! @name LPCG - force_on_off and force_on_off_sel for LPCGs */
/*! @{ */

#define BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_MASK (0x1U)
#define BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_SHIFT (0U)
/*! NETC_force_on_off - LPCG force_on_off control for NETC group */
#define BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_sel_MASK (0x2U)
#define BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_sel_SHIFT (1U)
/*! NETC_force_on_off_sel - LPCG force_on_off_sel control for NETC group */
#define BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_NETC_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_MASK (0x4U)
#define BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_SHIFT (2U)
/*! SSI_force_on_off - LPCG force_on_off control for SSI group */
#define BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_sel_MASK (0x8U)
#define BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_sel_SHIFT (3U)
/*! SSI_force_on_off_sel - LPCG force_on_off_sel control for SSI group */
#define BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_SSI_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_MASK (0x10U)
#define BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_SHIFT (4U)
/*! INFRA_force_on_off - LPCG force_on_off control for INFRA group */
#define BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_sel_MASK (0x20U)
#define BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_sel_SHIFT (5U)
/*! INFRA_force_on_off_sel - LPCG force_on_off_sel control for INFRA group */
#define BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_INFRA_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_MASK (0x40U)
#define BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_SHIFT (6U)
/*! SECURITY_force_on_off - LPCG force_on_off control for SECURITY group */
#define BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_sel_MASK (0x80U)
#define BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_sel_SHIFT (7U)
/*! SECURITY_force_on_off_sel - LPCG force_on_off_sel control for SECURITY group */
#define BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_SECURITY_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_MASK (0x100U)
#define BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_SHIFT (8U)
/*! PERI_force_on_off - LPCG force_on_off control for PERI group */
#define BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_sel_MASK (0x200U)
#define BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_sel_SHIFT (9U)
/*! PERI_force_on_off_sel - LPCG force_on_off_sel control for PERI group */
#define BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_PERI_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_MASK (0x400U)
#define BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_SHIFT (10U)
/*! ETH0_RGMII_TXC_force_on_off - ETH0_RGMII_TXC LPCG control */
#define BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_sel_MASK (0x800U)
#define BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_sel_SHIFT (11U)
/*! ETH0_RGMII_TXC_force_on_off_sel - ETH0_RGMII_TXC LPCG control */
#define BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_ETH0_RGMII_TXC_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_MASK (0x1000U)
#define BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_SHIFT (12U)
/*! ETH1_RGMII_TXC_force_on_off - ETH1_RGMII_TXC LPCG control */
#define BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_MASK)

#define BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_sel_MASK (0x2000U)
#define BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_sel_SHIFT (13U)
/*! ETH1_RGMII_TXC_force_on_off_sel - ETH1_RGMII_TXC LPCG control */
#define BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_sel(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_sel_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_ETH1_RGMII_TXC_force_on_off_sel_MASK)

#define BLK_CTRL_NETCMIX_LPCG_APB_RC_REG_ERR_GEN_EN_MASK (0x4000U)
#define BLK_CTRL_NETCMIX_LPCG_APB_RC_REG_ERR_GEN_EN_SHIFT (14U)
/*! APB_RC_REG_ERR_GEN_EN - NETC apb_rc_reg error generation enable */
#define BLK_CTRL_NETCMIX_LPCG_APB_RC_REG_ERR_GEN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_APB_RC_REG_ERR_GEN_EN_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_APB_RC_REG_ERR_GEN_EN_MASK)

#define BLK_CTRL_NETCMIX_LPCG_APB_PCFG_ERR_GEN_EN_MASK (0x8000U)
#define BLK_CTRL_NETCMIX_LPCG_APB_PCFG_ERR_GEN_EN_SHIFT (15U)
/*! APB_PCFG_ERR_GEN_EN - NETC apb_pcfg error generation enable */
#define BLK_CTRL_NETCMIX_LPCG_APB_PCFG_ERR_GEN_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_APB_PCFG_ERR_GEN_EN_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_APB_PCFG_ERR_GEN_EN_MASK)

#define BLK_CTRL_NETCMIX_LPCG_SAI2_QCH_BYPASS_EN_MASK (0x10000U)
#define BLK_CTRL_NETCMIX_LPCG_SAI2_QCH_BYPASS_EN_SHIFT (16U)
/*! SAI2_QCH_BYPASS_EN - Bypass enable signal for PERI LPCG group QCH handshake */
#define BLK_CTRL_NETCMIX_LPCG_SAI2_QCH_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_SAI2_QCH_BYPASS_EN_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_SAI2_QCH_BYPASS_EN_MASK)

#define BLK_CTRL_NETCMIX_LPCG_SAI2_PPMR_Q_STOPPED_EN_MASK (0x20000U)
#define BLK_CTRL_NETCMIX_LPCG_SAI2_PPMR_Q_STOPPED_EN_SHIFT (17U)
/*! SAI2_PPMR_Q_STOPPED_EN - Enable for PERI LPCG group ppmr */
#define BLK_CTRL_NETCMIX_LPCG_SAI2_PPMR_Q_STOPPED_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_LPCG_SAI2_PPMR_Q_STOPPED_EN_SHIFT)) & BLK_CTRL_NETCMIX_LPCG_SAI2_PPMR_Q_STOPPED_EN_MASK)
/*! @} */

/*! @name ENETLINK - Control register for enetlink */
/*! @{ */

#define BLK_CTRL_NETCMIX_ENETLINK_safe_state_apb_enable_MASK (0x1U)
#define BLK_CTRL_NETCMIX_ENETLINK_safe_state_apb_enable_SHIFT (0U)
/*! safe_state_apb_enable - Enable signal for safe_state_apb */
#define BLK_CTRL_NETCMIX_ENETLINK_safe_state_apb_enable(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_ENETLINK_safe_state_apb_enable_SHIFT)) & BLK_CTRL_NETCMIX_ENETLINK_safe_state_apb_enable_MASK)

#define BLK_CTRL_NETCMIX_ENETLINK_rx_soft_rst_b_MASK (0x2U)
#define BLK_CTRL_NETCMIX_ENETLINK_rx_soft_rst_b_SHIFT (1U)
/*! rx_soft_rst_b - soft reset for rx adapter */
#define BLK_CTRL_NETCMIX_ENETLINK_rx_soft_rst_b(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_ENETLINK_rx_soft_rst_b_SHIFT)) & BLK_CTRL_NETCMIX_ENETLINK_rx_soft_rst_b_MASK)

#define BLK_CTRL_NETCMIX_ENETLINK_rx_overflow_irq_MASK (0x4U)
#define BLK_CTRL_NETCMIX_ENETLINK_rx_overflow_irq_SHIFT (2U)
/*! rx_overflow_irq - rx adapter fifo overflow */
#define BLK_CTRL_NETCMIX_ENETLINK_rx_overflow_irq(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_ENETLINK_rx_overflow_irq_SHIFT)) & BLK_CTRL_NETCMIX_ENETLINK_rx_overflow_irq_MASK)

#define BLK_CTRL_NETCMIX_ENETLINK_clk_compare_bypass_MASK (0x8U)
#define BLK_CTRL_NETCMIX_ENETLINK_clk_compare_bypass_SHIFT (3U)
/*! clk_compare_bypass - Bypass enable of clk_compare module */
#define BLK_CTRL_NETCMIX_ENETLINK_clk_compare_bypass(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_ENETLINK_clk_compare_bypass_SHIFT)) & BLK_CTRL_NETCMIX_ENETLINK_clk_compare_bypass_MASK)
/*! @} */

/*! @name NETC - NETC Control */
/*! @{ */

#define BLK_CTRL_NETCMIX_NETC_fccu_fault_event_en_MASK (0x1U)
#define BLK_CTRL_NETCMIX_NETC_fccu_fault_event_en_SHIFT (0U)
/*! fccu_fault_event_en - Enable for netc_fccu_fault_event */
#define BLK_CTRL_NETCMIX_NETC_fccu_fault_event_en(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_NETC_fccu_fault_event_en_SHIFT)) & BLK_CTRL_NETCMIX_NETC_fccu_fault_event_en_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NETCMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_NETCMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_NETCMIX_H_ */

