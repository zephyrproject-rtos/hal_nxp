/*
** ###################################################################
**     Processors:          MIMXRT1015CAF4A
**                          MIMXRT1015CAF4B
**                          MIMXRT1015DAF5A
**                          MIMXRT1015DAF5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-11-05)
**         Initial version.
**     - rev. 1.0 (2019-01-18)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-02-20)
**         Update register SRC_SRSR's bitfield LOCKUP_SYSRESETREQ to LOCKUP.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1015RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC
 *
 * CMSIS Peripheral Access Layer for IOMUXC
 */

#if !defined(PERI_IOMUXC_H_)
#define PERI_IOMUXC_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1015CAF4A) || defined(CPU_MIMXRT1015CAF4B) || defined(CPU_MIMXRT1015DAF5A) || defined(CPU_MIMXRT1015DAF5B))
#include "MIMXRT1015_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(IOMUXC_SW_MUX_CTL_PAD_T_)
#define IOMUXC_SW_MUX_CTL_PAD_T_
/*!
 * @addtogroup iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC SW_MUX_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC SW_MUX_CTL_PAD collections.
 */
typedef enum _iomuxc_sw_mux_ctl_pad
{
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_04 = 0U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_05 = 1U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_06 = 2U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_07 = 3U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_08 = 4U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_09 = 5U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_16 = 12U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_17 = 13U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_18 = 14U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_19 = 15U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_20 = 16U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_21 = 17U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_22 = 18U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_23 = 19U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_24 = 20U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_25 = 21U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_26 = 22U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_27 = 23U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_32 = 28U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_33 = 29U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_34 = 30U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_35 = 31U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_00 = 38U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_01 = 39U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_02 = 40U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_03 = 41U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_04 = 42U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05 = 43U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_06 = 44U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_07 = 45U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_08 = 46U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_09 = 47U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_10 = 48U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_11 = 49U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_12 = 50U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_13 = 51U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_14 = 52U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_15 = 53U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_10 = 64U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_11 = 65U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_12 = 66U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_13 = 67U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_14 = 68U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_15 = 69U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_00 = 77U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_01 = 78U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_02 = 79U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_03 = 80U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_04 = 81U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_05 = 82U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_06 = 83U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_07 = 84U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_08 = 85U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_09 = 86U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_10 = 87U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_11 = 88U,    /**< IOMUXC SW_MUX_CTL_PAD index */
} iomuxc_sw_mux_ctl_pad_t;

/* @} */
#endif /* IOMUXC_SW_MUX_CTL_PAD_T_ */

#if !defined(IOMUXC_SW_PAD_CTL_PAD_T_)
#define IOMUXC_SW_PAD_CTL_PAD_T_
/*!
 * @addtogroup iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC SW_PAD_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC SW_PAD_CTL_PAD collections.
 */
typedef enum _iomuxc_sw_pad_ctl_pad
{
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_04 = 0U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_05 = 1U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_06 = 2U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_07 = 3U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08 = 4U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_09 = 5U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_16 = 12U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_17 = 13U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_18 = 14U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_19 = 15U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_20 = 16U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_21 = 17U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_22 = 18U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_23 = 19U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_24 = 20U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_25 = 21U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_26 = 22U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_27 = 23U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_32 = 28U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_33 = 29U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_34 = 30U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_35 = 31U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_00 = 38U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_01 = 39U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_02 = 40U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_03 = 41U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_04 = 42U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_05 = 43U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_06 = 44U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_07 = 45U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_08 = 46U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_09 = 47U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_10 = 48U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_11 = 49U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_12 = 50U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_13 = 51U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_14 = 52U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_15 = 53U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_10 = 64U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_11 = 65U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_12 = 66U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_13 = 67U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_14 = 68U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_15 = 69U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_00 = 77U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_01 = 78U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_02 = 79U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_03 = 80U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_04 = 81U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_05 = 82U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_06 = 83U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_07 = 84U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_08 = 85U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_09 = 86U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_10 = 87U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_11 = 88U,    /**< IOMUXC SW_PAD_CTL_PAD index */
} iomuxc_sw_pad_ctl_pad_t;

/* @} */
#endif /* IOMUXC_SW_PAD_CTL_PAD_T_ */

#if !defined(IOMUXC_SELECT_INPUT_T_)
#define IOMUXC_SELECT_INPUT_T_
/*!
 * @brief Enumeration for the IOMUXC select input
 *
 * Defines the enumeration for the IOMUXC select input collections.
 */
typedef enum _iomuxc_select_input
{
    kIOMUXC_ANATOP_USB_OTG_ID_SELECT_INPUT = 0U,   /**< IOMUXC select input index */
    kIOMUXC_CCM_PMIC_VFUNCIONAL_READY_SELECT_INPUT = 1U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_0 = 11U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_1 = 12U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_2 = 13U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_3 = 14U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_0 = 15U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_1 = 16U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_2 = 17U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_3 = 18U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_IPP_IND_IO_FA_BIT0_SELECT_INPUT = 27U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_IPP_IND_IO_FA_BIT1_SELECT_INPUT = 28U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_IPP_IND_IO_FA_BIT2_SELECT_INPUT = 29U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_IPP_IND_IO_FA_BIT3_SELECT_INPUT = 30U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_IPP_IND_SCK_FA_SELECT_INPUT = 31U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_IPP_IND_LPI2C_SCL_SELECT_INPUT = 32U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_IPP_IND_LPI2C_SDA_SELECT_INPUT = 33U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C2_IPP_IND_LPI2C_SCL_SELECT_INPUT = 34U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C2_IPP_IND_LPI2C_SDA_SELECT_INPUT = 35U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 40U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_IPP_IND_LPSPI_SCK_SELECT_INPUT = 41U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_IPP_IND_LPSPI_SDI_SELECT_INPUT = 42U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_IPP_IND_LPSPI_SDO_SELECT_INPUT = 43U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 44U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_IPP_IND_LPSPI_SCK_SELECT_INPUT = 45U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_IPP_IND_LPSPI_SDI_SELECT_INPUT = 46U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_IPP_IND_LPSPI_SDO_SELECT_INPUT = 47U, /**< IOMUXC select input index */
    kIOMUXC_LPUART2_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 52U, /**< IOMUXC select input index */
    kIOMUXC_LPUART2_IPP_IND_LPUART_RXD_SELECT_INPUT = 53U, /**< IOMUXC select input index */
    kIOMUXC_LPUART2_IPP_IND_LPUART_TXD_SELECT_INPUT = 54U, /**< IOMUXC select input index */
    kIOMUXC_LPUART3_IPP_IND_LPUART_RXD_SELECT_INPUT = 55U, /**< IOMUXC select input index */
    kIOMUXC_LPUART3_IPP_IND_LPUART_TXD_SELECT_INPUT = 56U, /**< IOMUXC select input index */
    kIOMUXC_LPUART4_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 57U, /**< IOMUXC select input index */
    kIOMUXC_LPUART4_IPP_IND_LPUART_RXD_SELECT_INPUT = 58U, /**< IOMUXC select input index */
    kIOMUXC_LPUART4_IPP_IND_LPUART_TXD_SELECT_INPUT = 59U, /**< IOMUXC select input index */
    kIOMUXC_NMI_GLUE_IPP_IND_NMI_SELECT_INPUT = 68U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR0_INPUT_SELECT_INPUT = 69U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR1_INPUT_SELECT_INPUT = 70U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR2_INPUT_SELECT_INPUT = 71U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR3_INPUT_SELECT_INPUT = 72U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPG_CLK_SAI_MCLK_SELECT_INPUT_2 = 77U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 78U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_RXDATA_SELECT_INPUT_0 = 79U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_RXDATA_SELECT_INPUT_1 = 80U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_RXDATA_SELECT_INPUT_2 = 81U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_RXDATA_SELECT_INPUT_3 = 82U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 83U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 84U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 85U, /**< IOMUXC select input index */
    kIOMUXC_SAI2_IPG_CLK_SAI_MCLK_SELECT_INPUT_2 = 86U, /**< IOMUXC select input index */
    kIOMUXC_SAI2_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 87U, /**< IOMUXC select input index */
    kIOMUXC_SAI2_IPP_IND_SAI_RXDATA_SELECT_INPUT_0 = 88U, /**< IOMUXC select input index */
    kIOMUXC_SAI2_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 89U, /**< IOMUXC select input index */
    kIOMUXC_SAI2_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 90U, /**< IOMUXC select input index */
    kIOMUXC_SAI2_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 91U, /**< IOMUXC select input index */
    kIOMUXC_SAI3_IPG_CLK_SAI_MCLK_SELECT_INPUT_2 = 92U, /**< IOMUXC select input index */
    kIOMUXC_SAI3_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 93U, /**< IOMUXC select input index */
    kIOMUXC_SAI3_IPP_IND_SAI_RXDATA_SELECT_INPUT_0 = 94U, /**< IOMUXC select input index */
    kIOMUXC_SAI3_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 95U, /**< IOMUXC select input index */
    kIOMUXC_SAI3_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 96U, /**< IOMUXC select input index */
    kIOMUXC_SAI3_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 97U, /**< IOMUXC select input index */
    kIOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT = 99U,    /**< IOMUXC select input index */
    kIOMUXC_USB_IPP_IND_OTG_OC_SELECT_INPUT = 100U, /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_14 = 105U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_15 = 106U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_16 = 107U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_17 = 108U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_10 = 109U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_12 = 110U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_13 = 111U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_18 = 112U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_19 = 113U,  /**< IOMUXC select input index */
} iomuxc_select_input_t;
#endif /* IOMUXC_SELECT_INPUT_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- IOMUXC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Peripheral_Access_Layer IOMUXC Peripheral Access Layer
 * @{
 */

/** IOMUXC - Size of Registers Arrays */
#define IOMUXC_SW_MUX_CTL_PAD_COUNT               89u
#define IOMUXC_SW_PAD_CTL_PAD_COUNT               89u
#define IOMUXC_SELECT_INPUT_COUNT                 114u

/** IOMUXC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[36];
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD_GPIO_EMC_04 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_SD_B1_11 SW MUX Control Register, array offset: 0x24, array step: 0x4, valid indices: [0-5, 12-23, 28-31, 38-53, 64-69, 77-88] */
       uint8_t RESERVED_1[16];
  __IO uint32_t SW_PAD_CTL_PAD[IOMUXC_SW_PAD_CTL_PAD_COUNT]; /**< SW_PAD_CTL_PAD_GPIO_EMC_04 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_SD_B1_11 SW PAD Control Register, array offset: 0x198, array step: 0x4, valid indices: [0-5, 12-23, 28-31, 38-53, 64-69, 77-88] */
  __IO uint32_t SELECT_INPUT[IOMUXC_SELECT_INPUT_COUNT]; /**< ANATOP_USB_OTG_ID_SELECT_INPUT DAISY Register..XBAR1_XBAR_IN_SELECT_INPUT_19 DAISY Register, array offset: 0x2FC, array step: 0x4, valid indices: [0-1, 11-18, 27-35, 40-47, 52-59, 68-72, 77-97, 99-100, 105-113] */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_GPIO_EMC_04 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_SD_B1_11 SW MUX Control Register */
/*! @{ */

#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK      (0x7U)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT     (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b001..Select mux mode: ALT1 mux port: FLEXPWM1_PWMB03 of instance: flexpwm1
 *  0b010..Select mux mode: ALT2 mux port: LPUART2_RTS_B of instance: lpuart2
 *  0b011..Select mux mode: ALT3 mux port: SAI1_RX_DATA00 of instance: sai1
 *  0b100..Select mux mode: ALT4 mux port: FLEXIO1_FLEXIO25 of instance: flexio1
 *  0b101..Select mux mode: ALT5 mux port: GPIO2_IO21 of instance: gpio2
 *  0b110..Select mux mode: ALT6 mux port: SRC_BT_CFG03 of instance: src
 */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK)

#define IOMUXC_SW_MUX_CTL_PAD_SION_MASK          (0x10U)
#define IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT         (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad GPIO_AD_B0_00
 */
#define IOMUXC_SW_MUX_CTL_PAD_SION(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_SION_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_GPIO_EMC_04 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_SD_B1_11 SW PAD Control Register */
/*! @{ */

#define IOMUXC_SW_PAD_CTL_PAD_SRE_MASK           (0x1U)
#define IOMUXC_SW_PAD_CTL_PAD_SRE_SHIFT          (0U)
/*! SRE - Slew Rate Field
 *  0b0..Slow Slew Rate
 *  0b1..Fast Slew Rate
 */
#define IOMUXC_SW_PAD_CTL_PAD_SRE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SRE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SRE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_DSE_MASK           (0x38U)
#define IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT          (3U)
/*! DSE - Drive Strength Field
 *  0b000..output driver disabled;
 *  0b001..R0(150 Ohm @ 3.3V, 260 Ohm@1.8V)
 *  0b010..R0/2
 *  0b011..R0/3
 *  0b100..R0/4
 *  0b101..R0/5
 *  0b110..R0/6
 *  0b111..R0/7
 */
#define IOMUXC_SW_PAD_CTL_PAD_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_SPEED_MASK         (0xC0U)
#define IOMUXC_SW_PAD_CTL_PAD_SPEED_SHIFT        (6U)
/*! SPEED - Speed Field
 *  0b00..low(50MHz)
 *  0b01..medium(100MHz)
 *  0b10..medium(100MHz)
 *  0b11..max(200MHz)
 */
#define IOMUXC_SW_PAD_CTL_PAD_SPEED(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SPEED_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SPEED_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_ODE_MASK           (0x800U)
#define IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT          (11U)
/*! ODE - Open Drain Enable Field
 *  0b0..Open Drain Disabled
 *  0b1..Open Drain Enabled
 */
#define IOMUXC_SW_PAD_CTL_PAD_ODE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_ODE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PKE_MASK           (0x1000U)
#define IOMUXC_SW_PAD_CTL_PAD_PKE_SHIFT          (12U)
/*! PKE - Pull / Keep Enable Field
 *  0b0..Pull/Keeper Disabled
 *  0b1..Pull/Keeper Enabled
 */
#define IOMUXC_SW_PAD_CTL_PAD_PKE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PKE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PKE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PUE_MASK           (0x2000U)
#define IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT          (13U)
/*! PUE - Pull / Keep Select Field
 *  0b0..Keeper
 *  0b1..Pull
 */
#define IOMUXC_SW_PAD_CTL_PAD_PUE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PUS_MASK           (0xC000U)
#define IOMUXC_SW_PAD_CTL_PAD_PUS_SHIFT          (14U)
/*! PUS - Pull Up / Down Config. Field
 *  0b00..100K Ohm Pull Down
 *  0b01..47K Ohm Pull Up
 *  0b10..100K Ohm Pull Up
 *  0b11..22K Ohm Pull Up
 */
#define IOMUXC_SW_PAD_CTL_PAD_PUS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUS_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_HYS_MASK           (0x10000U)
#define IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT          (16U)
/*! HYS - Hyst. Enable Field
 *  0b0..Hysteresis Disabled
 *  0b1..Hysteresis Enabled
 */
#define IOMUXC_SW_PAD_CTL_PAD_HYS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_HYS_MASK)
/*! @} */

/*! @name SELECT_INPUT - ANATOP_USB_OTG_ID_SELECT_INPUT DAISY Register..XBAR1_XBAR_IN_SELECT_INPUT_19 DAISY Register */
/*! @{ */

#define IOMUXC_SELECT_INPUT_DAISY_MASK           (0x3U)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
#define IOMUXC_SELECT_INPUT_DAISY_SHIFT          (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b00..Reserved00
 *  0b01..Selecting Pad: GPIO_SD_B1_05 for Mode: ALT6
 *  0b10..Selecting Pad: GPIO_AD_B0_03 for Mode: ALT7
 *  0b11..Reserved11
 */
#define IOMUXC_SELECT_INPUT_DAISY(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_IOMUXC_H_ */

