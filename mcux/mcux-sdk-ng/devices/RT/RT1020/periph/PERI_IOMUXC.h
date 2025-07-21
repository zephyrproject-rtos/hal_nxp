/*
** ###################################################################
**     Processors:          MIMXRT1021CAF4A
**                          MIMXRT1021CAF4B
**                          MIMXRT1021CAG4A
**                          MIMXRT1021CAG4B
**                          MIMXRT1021DAF5A
**                          MIMXRT1021DAF5B
**                          MIMXRT1021DAG5A
**                          MIMXRT1021DAG5B
**                          MIMXRT1024CAG4A
**                          MIMXRT1024CAG4B
**                          MIMXRT1024DAG5A
**                          MIMXRT1024DAG5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 0.1 (2017-11-06)
**         Initial version.
**     - rev. 1.0 (2018-11-27)
**         Update header files to align with IMXRT1020RM Rev.1.
**     - rev. 1.1 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1020RM Rev.2.
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

#if (defined(CPU_MIMXRT1021CAF4A) || defined(CPU_MIMXRT1021CAF4B) || defined(CPU_MIMXRT1021CAG4A) || defined(CPU_MIMXRT1021CAG4B) || defined(CPU_MIMXRT1021DAF5A) || defined(CPU_MIMXRT1021DAF5B) || defined(CPU_MIMXRT1021DAG5A) || defined(CPU_MIMXRT1021DAG5B))
#include "MIMXRT1021_COMMON.h"
#elif (defined(CPU_MIMXRT1024CAG4A) || defined(CPU_MIMXRT1024CAG4B) || defined(CPU_MIMXRT1024DAG5A) || defined(CPU_MIMXRT1024DAG5B))
#include "MIMXRT1024_COMMON.h"
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
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_00 = 0U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_01 = 1U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_02 = 2U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_03 = 3U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_04 = 4U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_05 = 5U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_06 = 6U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_07 = 7U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_08 = 8U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_09 = 9U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_10 = 10U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_11 = 11U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_12 = 12U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_13 = 13U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_14 = 14U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_15 = 15U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_16 = 16U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_17 = 17U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_18 = 18U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_19 = 19U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_20 = 20U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_21 = 21U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_22 = 22U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_23 = 23U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_24 = 24U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_25 = 25U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_26 = 26U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_27 = 27U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_28 = 28U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_29 = 29U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_30 = 30U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_31 = 31U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_32 = 32U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_33 = 33U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_34 = 34U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_35 = 35U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_36 = 36U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_37 = 37U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_38 = 38U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_39 = 39U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_40 = 40U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_41 = 41U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_00 = 42U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_01 = 43U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_02 = 44U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_03 = 45U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_04 = 46U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_05 = 47U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_06 = 48U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_07 = 49U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_08 = 50U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_09 = 51U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_10 = 52U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_11 = 53U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_12 = 54U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_13 = 55U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_14 = 56U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_15 = 57U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_00 = 58U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_01 = 59U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_02 = 60U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_03 = 61U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_04 = 62U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_05 = 63U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_06 = 64U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_07 = 65U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_08 = 66U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_09 = 67U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_10 = 68U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_11 = 69U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_12 = 70U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_13 = 71U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_14 = 72U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_15 = 73U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_00 = 74U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_01 = 75U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_02 = 76U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_03 = 77U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_04 = 78U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_05 = 79U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_06 = 80U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_00 = 81U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_01 = 82U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_02 = 83U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_03 = 84U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_04 = 85U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_05 = 86U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_06 = 87U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_07 = 88U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_08 = 89U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_09 = 90U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_10 = 91U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_11 = 92U,    /**< IOMUXC SW_MUX_CTL_PAD index */
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
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_00 = 0U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_01 = 1U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_02 = 2U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_03 = 3U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_04 = 4U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_05 = 5U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_06 = 6U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_07 = 7U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08 = 8U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_09 = 9U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_10 = 10U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_11 = 11U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_12 = 12U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_13 = 13U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_14 = 14U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_15 = 15U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_16 = 16U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_17 = 17U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_18 = 18U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_19 = 19U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_20 = 20U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_21 = 21U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_22 = 22U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_23 = 23U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_24 = 24U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_25 = 25U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_26 = 26U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_27 = 27U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_28 = 28U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_29 = 29U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_30 = 30U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_31 = 31U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_32 = 32U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_33 = 33U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_34 = 34U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_35 = 35U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36 = 36U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_37 = 37U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_38 = 38U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_39 = 39U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_40 = 40U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_41 = 41U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_00 = 42U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_01 = 43U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_02 = 44U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_03 = 45U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_04 = 46U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_05 = 47U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_06 = 48U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_07 = 49U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_08 = 50U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_09 = 51U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_10 = 52U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_11 = 53U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_12 = 54U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_13 = 55U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_14 = 56U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_15 = 57U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00 = 58U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01 = 59U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_02 = 60U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_03 = 61U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_04 = 62U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_05 = 63U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_06 = 64U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_07 = 65U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_08 = 66U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_09 = 67U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_10 = 68U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_11 = 69U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_12 = 70U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_13 = 71U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_14 = 72U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_15 = 73U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_00 = 74U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_01 = 75U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_02 = 76U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_03 = 77U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_04 = 78U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_05 = 79U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_06 = 80U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_00 = 81U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_01 = 82U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_02 = 83U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_03 = 84U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_04 = 85U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_05 = 86U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_06 = 87U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_07 = 88U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_08 = 89U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_09 = 90U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_10 = 91U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_11 = 92U,    /**< IOMUXC SW_PAD_CTL_PAD index */
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
    kIOMUXC_CCM_PMIC_READY_SELECT_INPUT = 1U,      /**< IOMUXC select input index */
    kIOMUXC_ENET_RMII_SELECT_INPUT  = 2U,          /**< IOMUXC select input index */
    kIOMUXC_ENET_MDIO_SELECT_INPUT  = 3U,          /**< IOMUXC select input index */
    kIOMUXC_ENET_RX_DATA0_SELECT_INPUT = 4U,       /**< IOMUXC select input index */
    kIOMUXC_ENET_RX_DATA1_SELECT_INPUT = 5U,       /**< IOMUXC select input index */
    kIOMUXC_ENET_RX_EN_SELECT_INPUT = 6U,          /**< IOMUXC select input index */
    kIOMUXC_ENET_RX_ERR_SELECT_INPUT = 7U,         /**< IOMUXC select input index */
    kIOMUXC_ENET_TX_CLK_SELECT_INPUT = 8U,         /**< IOMUXC select input index */
    kIOMUXC_FLEXCAN1_RX_SELECT_INPUT = 9U,         /**< IOMUXC select input index */
    kIOMUXC_FLEXCAN2_RX_SELECT_INPUT = 10U,        /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA0_SELECT_INPUT = 11U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA1_SELECT_INPUT = 12U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA2_SELECT_INPUT = 13U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMA3_SELECT_INPUT = 14U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB0_SELECT_INPUT = 15U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB1_SELECT_INPUT = 16U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB2_SELECT_INPUT = 17U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_PWMB3_SELECT_INPUT = 18U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMA0_SELECT_INPUT = 19U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMA1_SELECT_INPUT = 20U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMA2_SELECT_INPUT = 21U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMA3_SELECT_INPUT = 22U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMB0_SELECT_INPUT = 23U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMB1_SELECT_INPUT = 24U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMB2_SELECT_INPUT = 25U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_PWMB3_SELECT_INPUT = 26U,     /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_A_DATA0_SELECT_INPUT = 27U,    /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_A_DATA1_SELECT_INPUT = 28U,    /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_A_DATA2_SELECT_INPUT = 29U,    /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_A_DATA3_SELECT_INPUT = 30U,    /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI_A_SCLK_SELECT_INPUT = 31U,     /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_SCL_SELECT_INPUT = 32U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C1_SDA_SELECT_INPUT = 33U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C2_SCL_SELECT_INPUT = 34U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C2_SDA_SELECT_INPUT = 35U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C3_SCL_SELECT_INPUT = 36U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C3_SDA_SELECT_INPUT = 37U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C4_SCL_SELECT_INPUT = 38U,         /**< IOMUXC select input index */
    kIOMUXC_LPI2C4_SDA_SELECT_INPUT = 39U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_PCS0_SELECT_INPUT = 40U,        /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_SCK_SELECT_INPUT = 41U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_SDI_SELECT_INPUT = 42U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI1_SDO_SELECT_INPUT = 43U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_PCS0_SELECT_INPUT = 44U,        /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_SCK_SELECT_INPUT = 45U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_SDI_SELECT_INPUT = 46U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI2_SDO_SELECT_INPUT = 47U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_PCS0_SELECT_INPUT = 48U,        /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_SCK_SELECT_INPUT = 49U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_SDI_SELECT_INPUT = 50U,         /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_SDO_SELECT_INPUT = 51U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART2_CTS_B_SELECT_INPUT = 52U,      /**< IOMUXC select input index */
    kIOMUXC_LPUART2_RX_SELECT_INPUT = 53U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART2_TX_SELECT_INPUT = 54U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART3_RX_SELECT_INPUT = 55U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART3_TX_SELECT_INPUT = 56U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART4_CTS_B_SELECT_INPUT = 57U,      /**< IOMUXC select input index */
    kIOMUXC_LPUART4_RX_SELECT_INPUT = 58U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART4_TX_SELECT_INPUT = 59U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART5_RX_SELECT_INPUT = 60U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART5_TX_SELECT_INPUT = 61U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART6_RX_SELECT_INPUT = 62U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART6_TX_SELECT_INPUT = 63U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART7_RX_SELECT_INPUT = 64U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART7_TX_SELECT_INPUT = 65U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART8_RX_SELECT_INPUT = 66U,         /**< IOMUXC select input index */
    kIOMUXC_LPUART8_TX_SELECT_INPUT = 67U,         /**< IOMUXC select input index */
    kIOMUXC_NMI_SELECT_INPUT        = 68U,         /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TIMER0_INPUT_SELECT_INPUT = 69U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TIMER1_INPUT_SELECT_INPUT = 70U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TIMER2_INPUT_SELECT_INPUT = 71U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TIMER3_INPUT_SELECT_INPUT = 72U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TIMER0_INPUT_SELECT_INPUT = 73U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TIMER1_INPUT_SELECT_INPUT = 74U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TIMER2_INPUT_SELECT_INPUT = 75U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TIMER3_INPUT_SELECT_INPUT = 76U, /**< IOMUXC select input index */
    kIOMUXC_SAI1_MCLK_SELECT_INPUT  = 77U,         /**< IOMUXC select input index */
    kIOMUXC_SAI1_RX_BCLK_SELECT_INPUT = 78U,       /**< IOMUXC select input index */
    kIOMUXC_SAI1_RX_DATA0_SELECT_INPUT = 79U,      /**< IOMUXC select input index */
    kIOMUXC_SAI1_RX_DATA1_SELECT_INPUT = 80U,      /**< IOMUXC select input index */
    kIOMUXC_SAI1_RX_DATA2_SELECT_INPUT = 81U,      /**< IOMUXC select input index */
    kIOMUXC_SAI1_RX_DATA3_SELECT_INPUT = 82U,      /**< IOMUXC select input index */
    kIOMUXC_SAI1_RX_SYNC_SELECT_INPUT = 83U,       /**< IOMUXC select input index */
    kIOMUXC_SAI1_TX_BCLK_SELECT_INPUT = 84U,       /**< IOMUXC select input index */
    kIOMUXC_SAI1_TX_SYNC_SELECT_INPUT = 85U,       /**< IOMUXC select input index */
    kIOMUXC_SAI2_MCLK_SELECT_INPUT  = 86U,         /**< IOMUXC select input index */
    kIOMUXC_SAI2_RX_BCLK_SELECT_INPUT = 87U,       /**< IOMUXC select input index */
    kIOMUXC_SAI2_RX_DATA0_SELECT_INPUT = 88U,      /**< IOMUXC select input index */
    kIOMUXC_SAI2_RX_SYNC_SELECT_INPUT = 89U,       /**< IOMUXC select input index */
    kIOMUXC_SAI2_TX_BCLK_SELECT_INPUT = 90U,       /**< IOMUXC select input index */
    kIOMUXC_SAI2_TX_SYNC_SELECT_INPUT = 91U,       /**< IOMUXC select input index */
    kIOMUXC_SAI3_MCLK_SELECT_INPUT  = 92U,         /**< IOMUXC select input index */
    kIOMUXC_SAI3_RX_BCLK_SELECT_INPUT = 93U,       /**< IOMUXC select input index */
    kIOMUXC_SAI3_RX_DATA0_SELECT_INPUT = 94U,      /**< IOMUXC select input index */
    kIOMUXC_SAI3_RX_SYNC_SELECT_INPUT = 95U,       /**< IOMUXC select input index */
    kIOMUXC_SAI3_TX_BCLK_SELECT_INPUT = 96U,       /**< IOMUXC select input index */
    kIOMUXC_SAI3_TX_SYNC_SELECT_INPUT = 97U,       /**< IOMUXC select input index */
    kIOMUXC_SEMC_READY_SELECT_INPUT = 98U,         /**< IOMUXC select input index */
    kIOMUXC_SPDIF_IN_SELECT_INPUT   = 99U,         /**< IOMUXC select input index */
    kIOMUXC_USB_OTG_OC_SELECT_INPUT = 100U,        /**< IOMUXC select input index */
    kIOMUXC_USDHC1_CD_B_SELECT_INPUT = 101U,       /**< IOMUXC select input index */
    kIOMUXC_USDHC1_WP_SELECT_INPUT  = 102U,        /**< IOMUXC select input index */
    kIOMUXC_USDHC2_CD_B_SELECT_INPUT = 103U,       /**< IOMUXC select input index */
    kIOMUXC_USDHC2_WP_SELECT_INPUT  = 104U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN14_SELECT_INPUT = 105U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN15_SELECT_INPUT = 106U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN16_SELECT_INPUT = 107U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN17_SELECT_INPUT = 108U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN10_SELECT_INPUT = 109U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN12_SELECT_INPUT = 110U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN13_SELECT_INPUT = 111U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN18_SELECT_INPUT = 112U,        /**< IOMUXC select input index */
    kIOMUXC_XBAR1_IN19_SELECT_INPUT = 113U,        /**< IOMUXC select input index */
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
#define IOMUXC_SW_MUX_CTL_PAD_COUNT               93u
#define IOMUXC_SW_PAD_CTL_PAD_COUNT               93u
#define IOMUXC_SELECT_INPUT_COUNT                 114u

/** IOMUXC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[20];
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD_GPIO_EMC_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_SD_B1_11 SW MUX Control Register, array offset: 0x14, array step: 0x4, irregular array, not all indices are valid */
  __IO uint32_t SW_PAD_CTL_PAD[IOMUXC_SW_PAD_CTL_PAD_COUNT]; /**< SW_PAD_CTL_PAD_GPIO_EMC_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_SD_B1_11 SW PAD Control Register, array offset: 0x188, array step: 0x4, irregular array, not all indices are valid */
  __IO uint32_t SELECT_INPUT[IOMUXC_SELECT_INPUT_COUNT]; /**< ANATOP_USB_OTG_ID_SELECT_INPUT DAISY Register..XBAR1_IN19_SELECT_INPUT DAISY Register, array offset: 0x2FC, array step: 0x4 */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_GPIO_EMC_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_SD_B1_11 SW MUX Control Register */
/*! @{ */

#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK      (0x7U)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT     (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: SEMC_CSX02 of instance: semc
 *  0b001..Select mux mode: ALT1 mux port: FLEXSPI_A_DATA02 of instance: flexspi_bus2bit
 *  0b010..Select mux mode: ALT2 mux port: LPSPI4_PCS0 of instance: lpspi4
 *  0b011..Select mux mode: ALT3 mux port: SAI1_TX_DATA00 of instance: sai1
 *  0b100..Select mux mode: ALT4 mux port: FLEXIO1_FLEXIO12 of instance: flexio1
 *  0b101..Select mux mode: ALT5 mux port: GPIO1_IO19 of instance: gpio1
 *  0b110..Select mux mode: ALT6 mux port: ENET_1588_EVENT3_IN of instance: enet
 *  0b111..Select mux mode: ALT7 mux port: KPP_ROW05 of instance: kpp
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

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_GPIO_EMC_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_SD_B1_11 SW PAD Control Register */
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
 *  0b00..50MHz
 *  0b01..100MHz - 150MHz
 *  0b10..100MHz - 150MHz
 *  0b11..150MHz - 200MHz
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

/*! @name SELECT_INPUT - ANATOP_USB_OTG_ID_SELECT_INPUT DAISY Register..XBAR1_IN19_SELECT_INPUT DAISY Register */
/*! @{ */

#define IOMUXC_SELECT_INPUT_DAISY_MASK           (0x7U)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */
#define IOMUXC_SELECT_INPUT_DAISY_SHIFT          (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b000..Selecting Pad: GPIO_AD_B0_03 for Mode: ALT4
 *  0b001..Selecting Pad: GPIO_AD_B0_04 for Mode: ALT2
 *  0b010..Selecting Pad: GPIO_AD_B1_05 for Mode: ALT0
 *  0b011..Selecting Pad: GPIO_AD_B1_11 for Mode: ALT3
 *  0b100..Selecting Pad: GPIO_EMC_36 for Mode: ALT7
 */
#define IOMUXC_SELECT_INPUT_DAISY(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */
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

