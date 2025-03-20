/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_NETCMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file BLK_CTRL_NETCMIX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NETCMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NETCMIX
 */

#if !defined(BLK_CTRL_NETCMIX_H_)
#define BLK_CTRL_NETCMIX_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
  __IO uint32_t CFG_LINK_PCS_PROT_0;               /**< NETC PCS protocol on link0, offset: 0x14 */
  __IO uint32_t CFG_LINK_PCS_PROT_1;               /**< NETC PCS protocol on link1, offset: 0x18 */
  __IO uint32_t CFG_LINK_PCS_PROT_2;               /**< NETC PCS protocol on link2, offset: 0x1C */
  __IO uint32_t CFG_SRC_ID;                        /**< NETC cfg_src_id, offset: 0x20 */
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

#define BLK_CTRL_NETCMIX_MQS_SETTING_SAI_SEL_MASK (0x3U)
#define BLK_CTRL_NETCMIX_MQS_SETTING_SAI_SEL_SHIFT (0U)
/*! SAI_SEL - SAI2 clock source selection
 *  0b01..Reserved
 *  0b00..Select clock source from SAI2
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define BLK_CTRL_NETCMIX_MQS_SETTING_SAI_SEL(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_MQS_SETTING_SAI_SEL_SHIFT)) & BLK_CTRL_NETCMIX_MQS_SETTING_SAI_SEL_MASK)

#define BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN_MASK (0x4U)
#define BLK_CTRL_NETCMIX_MQS_SETTING_MQS_EN_SHIFT (2U)
/*! MQS_EN - MQS enable
 *  0b1..Enable MQS
 *  0b0..Disable MQS
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
 *  0b1100..Reserved
 *  0b0001..SAI2_CLK_ROOT
 *  0b0010..SAI3_CLK_ROOT
 *  0b0000..SAI1_CLK_ROOT
 *  0b0011..SAI4_CLK_ROOT
 *  0b0100..SAI5_CLK_ROOT
 *  0b0110..Reserved
 *  0b0101..Reserved
 *  0b1101..Reserved
 *  0b1111..SPDIF_RX_ROOT
 *  0b0111..SAI1_IPP_IND_SAI_MCLK
 *  0b1000..SAI2_IPP_IND_SAI_MCLK
 *  0b1001..SAI3_IPP_IND_SAI_MCLK
 *  0b1010..Reserved
 *  0b1110..SPDIF_CLK_ROOT
 *  0b1011..Reserved
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
 *  0b1111..SPDIF_RX_ROOT
 *  0b1110..SPDIF_CLK_ROOT
 *  0b1101..Reserved
 *  0b1100..Reserved
 *  0b1011..Reserved
 *  0b1010..Reserved
 *  0b1001..SAI3_IPP_IND_SAI_MCLK
 *  0b1000..SAI2_IPP_IND_SAI_MCLK
 *  0b0111..SAI1_IPP_IND_SAI_MCLK
 *  0b0110..Reserved
 *  0b0101..Reserved
 *  0b0100..SAI5_CLK_ROOT
 *  0b0011..SAI4_CLK_ROOT
 *  0b0010..SAI3_CLK_ROOT
 *  0b0001..SAI2_CLK_ROOT
 *  0b0000..SAI1_CLK_ROOT
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
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE1_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_MASK (0x4U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_SHIFT (2U)
/*! IPG_DEBUG_CA55_CORE2 - CA55 core2 in debug mode
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE2_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_MASK (0x8U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_SHIFT (3U)
/*! IPG_DEBUG_CA55_CORE3 - CA55 core3 in debug mode
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE3_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_MASK (0x10U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_SHIFT (4U)
/*! IPG_DEBUG_CA55_CORE4 - CA55 core4 in debug mode
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE4_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_MASK (0x20U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_SHIFT (5U)
/*! IPG_DEBUG_CA55_CORE5 - CA55 core5 in debug mode
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CA55_CORE5_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_MASK (0x40U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_SHIFT (6U)
/*! IPG_DEBUG_CM33 - CM33 in debug mode
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
 */
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_SHIFT)) & BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_CM33_MASK)

#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7_MASK (0x80U)
#define BLK_CTRL_NETCMIX_IPG_DEBUG_SAI2_IPG_DEBUG_M7_SHIFT (7U)
/*! IPG_DEBUG_M7 - M7 in debug mode
 *  0b1..Core enters debug mode
 *  0b0..Core does not enter debug mode
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
 *  0b0001..16FF 16G SerDes
 *  0b0000..None
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_1_MASK)

#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_2_MASK (0xF00U)
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_2_SHIFT (8U)
/*! CFG_LINK_IO_VAR_2 - I/O variant supported by SoC on link 2
 *  0b0001..16FF 16G SerDes
 *  0b0000..None
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_2_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_IO_VAR_CFG_LINK_IO_VAR_2_MASK)
/*! @} */

/*! @name CFG_LINK_MII_PROT - NETC cfg_link_mii_prot */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0_MASK (0xFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_0_SHIFT (0U)
/*! CFG_LINK_MII_PROT_0 - NETC MII protocol on link0
 *  0b0000..MII
 *  0b0001..RMII
 *  0b0010..RGMII
 *  0b0100..SGMII
 *  0b0101..XGMII
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b0011..Reserved
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
 *  0b1111..Reserved
 *  0b1110..Reserved
 *  0b1101..Reserved
 *  0b1100..Reserved
 *  0b1011..Reserved
 *  0b1010..Reserved
 *  0b1001..Reserved
 *  0b1000..Reserved
 *  0b0111..Reserved
 *  0b0110..Reserved
 *  0b0101..XGMII
 *  0b0100..SGMII
 *  0b0011..Reserved
 *  0b0010..RGMII
 *  0b0001..RMII
 *  0b0000..MII
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_1_MASK)

#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_2_MASK (0xF00U)
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_2_SHIFT (8U)
/*! CFG_LINK_MII_PROT_2 - NETC MII protocol on link2
 *  0b1111..Reserved
 *  0b1110..Reserved
 *  0b1101..Reserved
 *  0b1100..Reserved
 *  0b1011..Reserved
 *  0b1010..Reserved
 *  0b1001..Reserved
 *  0b1000..Reserved
 *  0b0111..Reserved
 *  0b0110..Reserved
 *  0b0101..XGMII
 *  0b0100..SGMII
 *  0b0011..Reserved
 *  0b0010..RGMII
 *  0b0001..RMII
 *  0b0000..MII
 */
#define BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_2_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_MII_PROT_CFG_LINK_MII_PROT_2_MASK)
/*! @} */

/*! @name CFG_LINK_PCS_PROT_0 - NETC PCS protocol on link0 */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_0_CFG_LINK_PCS_PROT_0_MASK (0xFFFFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_0_CFG_LINK_PCS_PROT_0_SHIFT (0U)
/*! CFG_LINK_PCS_PROT_0 - PCS protocol on link0 */
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_0_CFG_LINK_PCS_PROT_0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_0_CFG_LINK_PCS_PROT_0_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_0_CFG_LINK_PCS_PROT_0_MASK)
/*! @} */

/*! @name CFG_LINK_PCS_PROT_1 - NETC PCS protocol on link1 */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_MASK (0xFFFFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_SHIFT (0U)
/*! CFG_LINK_PCS_PROT_1 - PCS protocol on link1 */
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_1_CFG_LINK_PCS_PROT_1_MASK)
/*! @} */

/*! @name CFG_LINK_PCS_PROT_2 - NETC PCS protocol on link2 */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_2_CFG_LINK_PCS_PROT_2_MASK (0xFFFFU)
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_2_CFG_LINK_PCS_PROT_2_SHIFT (0U)
/*! CFG_LINK_PCS_PROT_2 - PCS protocol on link2 */
#define BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_2_CFG_LINK_PCS_PROT_2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_2_CFG_LINK_PCS_PROT_2_SHIFT)) & BLK_CTRL_NETCMIX_CFG_LINK_PCS_PROT_2_CFG_LINK_PCS_PROT_2_MASK)
/*! @} */

/*! @name CFG_SRC_ID - NETC cfg_src_id */
/*! @{ */

#define BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_MASK (0xFFU)
#define BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_SHIFT (0U)
/*! CFG_SRC_ID - NETC cfgsrc_id */
#define BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_SHIFT)) & BLK_CTRL_NETCMIX_CFG_SRC_ID_CFG_SRC_ID_MASK)
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


#endif  /* BLK_CTRL_NETCMIX_H_ */

