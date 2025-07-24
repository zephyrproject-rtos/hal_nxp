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
 * @file PERI_IOMUXC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC
 *
 * CMSIS Peripheral Access Layer for IOMUXC
 */

#if !defined(PERI_IOMUXC_H_)
#define PERI_IOMUXC_H_                           /**< Symbol preventing repeated inclusion */

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
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_00 = 0U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_01 = 1U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_02 = 2U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_03 = 3U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_04 = 4U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_05 = 5U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_06 = 6U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_07 = 7U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_08 = 8U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_09 = 9U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_10 = 10U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_11 = 11U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_12 = 12U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_13 = 13U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_14 = 14U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_15 = 15U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_16 = 16U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_17 = 17U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_18 = 18U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_19 = 19U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_20 = 20U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_21 = 21U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_22 = 22U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_23 = 23U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_24 = 24U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_25 = 25U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_26 = 26U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_27 = 27U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_28 = 28U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_29 = 29U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_30 = 30U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_31 = 31U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_32 = 32U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_33 = 33U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_34 = 34U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_35 = 35U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_36 = 36U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_37 = 37U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_38 = 38U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_39 = 39U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_40 = 40U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B1_41 = 41U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_00 = 42U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_01 = 43U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_02 = 44U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_03 = 45U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_04 = 46U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_05 = 47U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_06 = 48U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_07 = 49U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_08 = 50U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_09 = 51U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_10 = 52U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_11 = 53U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_12 = 54U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_13 = 55U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_14 = 56U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_15 = 57U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_16 = 58U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_17 = 59U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_18 = 60U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_19 = 61U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_B2_20 = 62U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_00 = 63U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_01 = 64U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_02 = 65U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_03 = 66U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_04 = 67U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_05 = 68U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_06 = 69U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_07 = 70U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_08 = 71U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_09 = 72U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_10 = 73U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_11 = 74U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_12 = 75U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_13 = 76U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_14 = 77U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_15 = 78U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_16 = 79U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_17 = 80U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_18 = 81U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_19 = 82U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_20 = 83U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_21 = 84U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_22 = 85U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_23 = 86U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_24 = 87U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_25 = 88U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_26 = 89U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_27 = 90U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_28 = 91U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_29 = 92U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_30 = 93U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_31 = 94U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_32 = 95U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_33 = 96U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_34 = 97U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_AD_35 = 98U,       /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_00 = 99U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_01 = 100U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_02 = 101U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_03 = 102U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_04 = 103U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B1_05 = 104U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_00 = 105U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_01 = 106U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_02 = 107U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_03 = 108U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_04 = 109U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_05 = 110U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_06 = 111U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_07 = 112U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_08 = 113U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_09 = 114U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_10 = 115U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_11 = 116U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B2_12_DUMMY = 117U, /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_00 = 118U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_01 = 119U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_02 = 120U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_03 = 121U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_04 = 122U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_05 = 123U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_06 = 124U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_07 = 125U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_08 = 126U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_09 = 127U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_10 = 128U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_11 = 129U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_12 = 130U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B1_13 = 131U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_00 = 132U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_01 = 133U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_02 = 134U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_03 = 135U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_04 = 136U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_05 = 137U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_06 = 138U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_07 = 139U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_08 = 140U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_09 = 141U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_10 = 142U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_11 = 143U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_12 = 144U,      /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_SW_MUX_CTL_PAD_GPIO_B2_13 = 145U,      /**< IOMUXC SW_MUX_CTL_PAD index */
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
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_00 = 0U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_01 = 1U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_02 = 2U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_03 = 3U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_04 = 4U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_05 = 5U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_06 = 6U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_07 = 7U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_08 = 8U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_09 = 9U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_10 = 10U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_11 = 11U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_12 = 12U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_13 = 13U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_14 = 14U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_15 = 15U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_16 = 16U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_17 = 17U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_18 = 18U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_19 = 19U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_20 = 20U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_21 = 21U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_22 = 22U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_23 = 23U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_24 = 24U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_25 = 25U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_26 = 26U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_27 = 27U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_28 = 28U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_29 = 29U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_30 = 30U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_31 = 31U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_32 = 32U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_33 = 33U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_34 = 34U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_35 = 35U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_36 = 36U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_37 = 37U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_38 = 38U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_39 = 39U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_40 = 40U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B1_41 = 41U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_00 = 42U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_01 = 43U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_02 = 44U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_03 = 45U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_04 = 46U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_05 = 47U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_06 = 48U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_07 = 49U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_08 = 50U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_09 = 51U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_10 = 52U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_11 = 53U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_12 = 54U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_13 = 55U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_14 = 56U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_15 = 57U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_16 = 58U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_17 = 59U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_18 = 60U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_19 = 61U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_B2_20 = 62U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_00 = 63U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_01 = 64U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_02 = 65U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_03 = 66U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_04 = 67U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_05 = 68U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_06 = 69U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_07 = 70U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_08 = 71U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_09 = 72U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_10 = 73U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_11 = 74U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_12 = 75U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_13 = 76U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_14 = 77U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_15 = 78U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_16 = 79U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_17 = 80U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_18 = 81U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_19 = 82U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_20 = 83U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_21 = 84U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_22 = 85U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_23 = 86U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_24 = 87U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_25 = 88U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_26 = 89U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_27 = 90U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_28 = 91U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_29 = 92U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_30 = 93U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_31 = 94U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_32 = 95U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_33 = 96U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_34 = 97U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_AD_35 = 98U,       /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_00 = 99U,    /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_01 = 100U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_02 = 101U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_03 = 102U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_04 = 103U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B1_05 = 104U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_00 = 105U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_01 = 106U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_02 = 107U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_03 = 108U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_04 = 109U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_05 = 110U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_06 = 111U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_07 = 112U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_08 = 113U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_09 = 114U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_10 = 115U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_11 = 116U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B2_12_DUMMY = 117U, /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_00 = 118U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_01 = 119U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_02 = 120U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_03 = 121U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_04 = 122U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_05 = 123U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_06 = 124U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_07 = 125U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_08 = 126U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_09 = 127U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_10 = 128U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_11 = 129U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_12 = 130U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B1_13 = 131U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_00 = 132U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_01 = 133U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_02 = 134U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_03 = 135U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_04 = 136U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_05 = 137U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_06 = 138U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_07 = 139U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_08 = 140U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_09 = 141U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_10 = 142U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_11 = 143U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_12 = 144U,      /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_SW_PAD_CTL_PAD_GPIO_B2_13 = 145U,      /**< IOMUXC SW_PAD_CTL_PAD index */
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
    kIOMUXC_CAN1_IPP_IND_CANRX_SELECT_INPUT = 0U,  /**< IOMUXC select input index */
    kIOMUXC_CAN2_IPP_IND_CANRX_SELECT_INPUT = 1U,  /**< IOMUXC select input index */
    kIOMUXC_CAN3_IPP_IND_CANRX_SELECT_INPUT = 2U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_CLK_0_SELECT_INPUT = 3U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_CLK_1_SELECT_INPUT = 4U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA0_0_SELECT_INPUT = 5U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA0_1_SELECT_INPUT = 6U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA1_0_SELECT_INPUT = 7U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA1_1_SELECT_INPUT = 8U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA2_0_SELECT_INPUT = 9U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA2_1_SELECT_INPUT = 10U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA3_0_SELECT_INPUT = 11U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DATA3_1_SELECT_INPUT = 12U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DV_0_SELECT_INPUT = 13U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_DV_1_SELECT_INPUT = 14U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_ER_0_SELECT_INPUT = 15U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_RX_ER_1_SELECT_INPUT = 16U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_TX_CLK_0_SELECT_INPUT = 17U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_ECAT_TX_CLK_1_SELECT_INPUT = 18U, /**< IOMUXC select input index */
    kIOMUXC_ECAT_MDIO_DATA_IN_SELECT_INPUT = 19U,  /**< IOMUXC select input index */
    kIOMUXC_ECAT_PROM_DATA_IN_SELECT_INPUT = 20U,  /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_0 = 21U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_1 = 22U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMA_SELECT_INPUT_2 = 23U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_0 = 24U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_1 = 25U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM1_IPP_IND_PWMB_SELECT_INPUT_2 = 26U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_IPP_IND_PWMA_SELECT_INPUT_0 = 27U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_IPP_IND_PWMA_SELECT_INPUT_1 = 28U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_IPP_IND_PWMA_SELECT_INPUT_2 = 29U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_IPP_IND_PWMB_SELECT_INPUT_0 = 30U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_IPP_IND_PWMB_SELECT_INPUT_1 = 31U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM2_IPP_IND_PWMB_SELECT_INPUT_2 = 32U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMA_SELECT_INPUT_0 = 33U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMA_SELECT_INPUT_1 = 34U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMA_SELECT_INPUT_2 = 35U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMA_SELECT_INPUT_3 = 36U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMB_SELECT_INPUT_0 = 37U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMB_SELECT_INPUT_1 = 38U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMB_SELECT_INPUT_2 = 39U, /**< IOMUXC select input index */
    kIOMUXC_FLEXPWM3_IPP_IND_PWMB_SELECT_INPUT_3 = 40U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_DQS_FA_SELECT_INPUT = 41U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_DQS_FB_SELECT_INPUT = 42U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT0_SELECT_INPUT = 43U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT1_SELECT_INPUT = 44U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT2_SELECT_INPUT = 45U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT3_SELECT_INPUT = 46U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT4_SELECT_INPUT = 47U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT5_SELECT_INPUT = 48U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT6_SELECT_INPUT = 49U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_IO_FB_BIT7_SELECT_INPUT = 50U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI1_BUS2BIT_IPP_IND_SCK_FB_SELECT_INPUT = 51U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_DQS_FA_SELECT_INPUT = 52U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_DQS_FB_SELECT_INPUT = 53U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FA_BIT0_SELECT_INPUT = 54U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FA_BIT1_SELECT_INPUT = 55U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FA_BIT2_SELECT_INPUT = 56U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FA_BIT3_SELECT_INPUT = 57U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FB_BIT0_SELECT_INPUT = 58U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FB_BIT1_SELECT_INPUT = 59U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FB_BIT2_SELECT_INPUT = 60U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_IO_FB_BIT3_SELECT_INPUT = 61U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_SCK_FA_SELECT_INPUT = 62U, /**< IOMUXC select input index */
    kIOMUXC_FLEXSPI2_BUS2BIT_IPP_IND_SCK_FB_SELECT_INPUT = 63U, /**< IOMUXC select input index */
    kIOMUXC_I3C2_PIN_SCL_IN_SELECT_INPUT = 64U,    /**< IOMUXC select input index */
    kIOMUXC_I3C2_PIN_SDA_IN_SELECT_INPUT = 65U,    /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_0 = 66U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_1 = 67U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_2 = 68U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_3 = 69U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_4 = 70U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_5 = 71U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_6 = 72U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_COL_SELECT_INPUT_7 = 73U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_0 = 74U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_1 = 75U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_2 = 76U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_3 = 77U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_4 = 78U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_5 = 79U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_6 = 80U,  /**< IOMUXC select input index */
    kIOMUXC_KPP_IPP_IND_ROW_SELECT_INPUT_7 = 81U,  /**< IOMUXC select input index */
    kIOMUXC_LPI2C3_IPP_IND_LPI2C_SCL_SELECT_INPUT = 82U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C3_IPP_IND_LPI2C_SDA_SELECT_INPUT = 83U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C4_IPP_IND_LPI2C_SCL_SELECT_INPUT = 84U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C4_IPP_IND_LPI2C_SDA_SELECT_INPUT = 85U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C5_IPP_IND_LPI2C_SCL_SELECT_INPUT = 86U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C5_IPP_IND_LPI2C_SDA_SELECT_INPUT = 87U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C6_IPP_IND_LPI2C_SCL_SELECT_INPUT = 88U, /**< IOMUXC select input index */
    kIOMUXC_LPI2C6_IPP_IND_LPI2C_SDA_SELECT_INPUT = 89U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 90U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_PCS_SELECT_INPUT_1 = 91U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_PCS_SELECT_INPUT_2 = 92U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_PCS_SELECT_INPUT_3 = 93U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_SCK_SELECT_INPUT = 94U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_SDI_SELECT_INPUT = 95U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI3_IPP_IND_LPSPI_SDO_SELECT_INPUT = 96U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 97U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_IPP_IND_LPSPI_SCK_SELECT_INPUT = 98U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_IPP_IND_LPSPI_SDI_SELECT_INPUT = 99U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI4_IPP_IND_LPSPI_SDO_SELECT_INPUT = 100U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 101U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_PCS_SELECT_INPUT_1 = 102U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_PCS_SELECT_INPUT_2 = 103U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_PCS_SELECT_INPUT_3 = 104U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_SCK_SELECT_INPUT = 105U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_SDI_SELECT_INPUT = 106U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI5_IPP_IND_LPSPI_SDO_SELECT_INPUT = 107U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 108U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_PCS_SELECT_INPUT_1 = 109U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_PCS_SELECT_INPUT_2 = 110U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_PCS_SELECT_INPUT_3 = 111U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_SCK_SELECT_INPUT = 112U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_SDI_SELECT_INPUT = 113U, /**< IOMUXC select input index */
    kIOMUXC_LPSPI6_IPP_IND_LPSPI_SDO_SELECT_INPUT = 114U, /**< IOMUXC select input index */
    kIOMUXC_LPUART10_IPP_IND_LPUART_RXD_SELECT_INPUT = 115U, /**< IOMUXC select input index */
    kIOMUXC_LPUART10_IPP_IND_LPUART_TXD_SELECT_INPUT = 116U, /**< IOMUXC select input index */
    kIOMUXC_LPUART11_IPP_IND_LPUART_RXD_SELECT_INPUT = 117U, /**< IOMUXC select input index */
    kIOMUXC_LPUART11_IPP_IND_LPUART_TXD_SELECT_INPUT = 118U, /**< IOMUXC select input index */
    kIOMUXC_LPUART3_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 119U, /**< IOMUXC select input index */
    kIOMUXC_LPUART3_IPP_IND_LPUART_RXD_SELECT_INPUT = 120U, /**< IOMUXC select input index */
    kIOMUXC_LPUART3_IPP_IND_LPUART_TXD_SELECT_INPUT = 121U, /**< IOMUXC select input index */
    kIOMUXC_LPUART4_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 122U, /**< IOMUXC select input index */
    kIOMUXC_LPUART5_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 123U, /**< IOMUXC select input index */
    kIOMUXC_LPUART5_IPP_IND_LPUART_DCD_N_SELECT_INPUT = 124U, /**< IOMUXC select input index */
    kIOMUXC_LPUART5_IPP_IND_LPUART_DSR_N_SELECT_INPUT = 125U, /**< IOMUXC select input index */
    kIOMUXC_LPUART5_IPP_IND_LPUART_RI_N_SELECT_INPUT = 126U, /**< IOMUXC select input index */
    kIOMUXC_LPUART5_IPP_IND_LPUART_RXD_SELECT_INPUT = 127U, /**< IOMUXC select input index */
    kIOMUXC_LPUART5_IPP_IND_LPUART_TXD_SELECT_INPUT = 128U, /**< IOMUXC select input index */
    kIOMUXC_LPUART6_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 129U, /**< IOMUXC select input index */
    kIOMUXC_LPUART6_IPP_IND_LPUART_DCD_N_SELECT_INPUT = 130U, /**< IOMUXC select input index */
    kIOMUXC_LPUART6_IPP_IND_LPUART_DSR_N_SELECT_INPUT = 131U, /**< IOMUXC select input index */
    kIOMUXC_LPUART6_IPP_IND_LPUART_RI_N_SELECT_INPUT = 132U, /**< IOMUXC select input index */
    kIOMUXC_LPUART6_IPP_IND_LPUART_RXD_SELECT_INPUT = 133U, /**< IOMUXC select input index */
    kIOMUXC_LPUART6_IPP_IND_LPUART_TXD_SELECT_INPUT = 134U, /**< IOMUXC select input index */
    kIOMUXC_LPUART8_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 135U, /**< IOMUXC select input index */
    kIOMUXC_LPUART8_IPP_IND_LPUART_RXD_SELECT_INPUT = 136U, /**< IOMUXC select input index */
    kIOMUXC_LPUART8_IPP_IND_LPUART_TXD_SELECT_INPUT = 137U, /**< IOMUXC select input index */
    kIOMUXC_LPUART9_IPP_IND_LPUART_RXD_SELECT_INPUT = 138U, /**< IOMUXC select input index */
    kIOMUXC_LPUART9_IPP_IND_LPUART_TXD_SELECT_INPUT = 139U, /**< IOMUXC select input index */
    kIOMUXC_MIC_IPP_IND_MIC_PDM_BITSTREAM_SELECT_INPUT_0 = 140U, /**< IOMUXC select input index */
    kIOMUXC_MIC_IPP_IND_MIC_PDM_BITSTREAM_SELECT_INPUT_1 = 141U, /**< IOMUXC select input index */
    kIOMUXC_MIC_IPP_IND_MIC_PDM_BITSTREAM_SELECT_INPUT_2 = 142U, /**< IOMUXC select input index */
    kIOMUXC_MIC_IPP_IND_MIC_PDM_BITSTREAM_SELECT_INPUT_3 = 143U, /**< IOMUXC select input index */
    kIOMUXC_NETC_EMDIO_IN_SELECT_INPUT = 190U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH2_COL_SELECT_INPUT = 191U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH2_CRS_SELECT_INPUT = 192U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH2_SLV_MDC_IN_SELECT_INPUT = 193U, /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH2_SLV_MDIO_IN_SELECT_INPUT = 194U, /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH3_COL_SELECT_INPUT = 195U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH3_CRS_SELECT_INPUT = 196U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH3_SLV_MDC_IN_SELECT_INPUT = 197U, /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH3_SLV_MDIO_IN_SELECT_INPUT = 198U, /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH4_COL_SELECT_INPUT = 199U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH4_CRS_SELECT_INPUT = 200U,     /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH4_SLV_MDC_IN_SELECT_INPUT = 201U, /**< IOMUXC select input index */
    kIOMUXC_NETC_ETH4_SLV_MDIO_IN_SELECT_INPUT = 202U, /**< IOMUXC select input index */
    kIOMUXC_NETC_TMR_TRIG1_SELECT_INPUT = 203U,    /**< IOMUXC select input index */
    kIOMUXC_NETC_TMR_TRIG2_SELECT_INPUT = 204U,    /**< IOMUXC select input index */
    kIOMUXC_NETC_CLKGEN_IPP_TMR_CLK_SELECT_INPUT = 205U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RX_CLK_SELECT_INPUT = 206U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RX_DV_SELECT_INPUT = 207U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RX_ER_SELECT_INPUT = 208U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RXD_SELECT_INPUT_0 = 209U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RXD_SELECT_INPUT_1 = 210U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RXD_SELECT_INPUT_2 = 211U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_RXD_SELECT_INPUT_3 = 212U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH0_TX_CLK_SELECT_INPUT = 213U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RX_CLK_SELECT_INPUT = 214U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RX_DV_SELECT_INPUT = 215U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RX_ER_SELECT_INPUT = 216U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RXD_SELECT_INPUT_0 = 217U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RXD_SELECT_INPUT_1 = 218U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RXD_SELECT_INPUT_2 = 219U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_RXD_SELECT_INPUT_3 = 220U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH2_TX_CLK_SELECT_INPUT = 221U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RX_CLK_SELECT_INPUT = 222U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RX_DV_SELECT_INPUT = 223U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RX_ER_SELECT_INPUT = 224U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RXD_SELECT_INPUT_0 = 225U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RXD_SELECT_INPUT_1 = 226U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RXD_SELECT_INPUT_2 = 227U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_RXD_SELECT_INPUT_3 = 228U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH3_TX_CLK_SELECT_INPUT = 229U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RX_CLK_SELECT_INPUT = 230U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RX_DV_SELECT_INPUT = 231U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RX_ER_SELECT_INPUT = 232U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RXD_SELECT_INPUT_0 = 233U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RXD_SELECT_INPUT_1 = 234U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RXD_SELECT_INPUT_2 = 235U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_RXD_SELECT_INPUT_3 = 236U, /**< IOMUXC select input index */
    kIOMUXC_NETC_PINMUX_IPP_IND_ETH4_TX_CLK_SELECT_INPUT = 237U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR0_INPUT_SELECT_INPUT = 238U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR1_INPUT_SELECT_INPUT = 239U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER1_TMR2_INPUT_SELECT_INPUT = 240U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TMR0_INPUT_SELECT_INPUT = 241U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TMR1_INPUT_SELECT_INPUT = 242U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER2_TMR2_INPUT_SELECT_INPUT = 243U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER3_TMR0_INPUT_SELECT_INPUT = 244U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER3_TMR1_INPUT_SELECT_INPUT = 245U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER3_TMR2_INPUT_SELECT_INPUT = 246U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER4_TMR0_INPUT_SELECT_INPUT = 247U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER4_TMR1_INPUT_SELECT_INPUT = 248U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER4_TMR2_INPUT_SELECT_INPUT = 249U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER5_TMR0_INPUT_SELECT_INPUT = 250U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER5_TMR1_INPUT_SELECT_INPUT = 251U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER5_TMR2_INPUT_SELECT_INPUT = 252U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER6_TMR0_INPUT_SELECT_INPUT = 253U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER6_TMR1_INPUT_SELECT_INPUT = 254U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER6_TMR2_INPUT_SELECT_INPUT = 255U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER7_TMR0_INPUT_SELECT_INPUT = 256U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER7_TMR1_INPUT_SELECT_INPUT = 257U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER8_TMR0_INPUT_SELECT_INPUT = 258U, /**< IOMUXC select input index */
    kIOMUXC_QTIMER8_TMR1_INPUT_SELECT_INPUT = 259U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPG_CLK_SAI_MCLK_SELECT_INPUT = 260U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 261U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPP_IND_SAI_RXDATA_SELECT_INPUT_0 = 262U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPP_IND_SAI_RXDATA_SELECT_INPUT_1 = 263U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 264U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 265U, /**< IOMUXC select input index */
    kIOMUXC_SAI4_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 266U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMBIT_SELECT_INPUT_0 = 269U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMBIT_SELECT_INPUT_1 = 270U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMBIT_SELECT_INPUT_2 = 271U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMBIT_SELECT_INPUT_3 = 272U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMCLK_SELECT_INPUT_0 = 273U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMCLK_SELECT_INPUT_1 = 274U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMCLK_SELECT_INPUT_2 = 275U, /**< IOMUXC select input index */
    kIOMUXC_SINC1_IPP_IND_EMCLK_SELECT_INPUT_3 = 276U, /**< IOMUXC select input index */
    kIOMUXC_SINC2_IPP_IND_EMBIT_SELECT_INPUT_2 = 277U, /**< IOMUXC select input index */
    kIOMUXC_SINC2_IPP_IND_EMBIT_SELECT_INPUT_3 = 278U, /**< IOMUXC select input index */
    kIOMUXC_SINC2_IPP_IND_EMCLK_SELECT_INPUT_0 = 279U, /**< IOMUXC select input index */
    kIOMUXC_SINC2_IPP_IND_EMCLK_SELECT_INPUT_2 = 280U, /**< IOMUXC select input index */
    kIOMUXC_SINC2_IPP_IND_EMCLK_SELECT_INPUT_3 = 281U, /**< IOMUXC select input index */
    kIOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT = 282U,   /**< IOMUXC select input index */
    kIOMUXC_USB_IPP_IND_OTG2_OC_SELECT_INPUT = 285U, /**< IOMUXC select input index */
    kIOMUXC_USB_IPP_IND_OTG_OC_SELECT_INPUT = 286U, /**< IOMUXC select input index */
    kIOMUXC_USBPHY1_USB_ID_SELECT_INPUT = 287U,    /**< IOMUXC select input index */
    kIOMUXC_USBPHY2_USB_ID_SELECT_INPUT = 288U,    /**< IOMUXC select input index */
    kIOMUXC_USDHC1_IPP_CARD_DET_SELECT_INPUT = 289U, /**< IOMUXC select input index */
    kIOMUXC_USDHC1_IPP_WP_ON_SELECT_INPUT = 290U,  /**< IOMUXC select input index */
    kIOMUXC_USDHC2_IPP_CARD_DET_SELECT_INPUT = 291U, /**< IOMUXC select input index */
    kIOMUXC_USDHC2_IPP_WP_ON_SELECT_INPUT = 292U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_14 = 293U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_15 = 294U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_17 = 295U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_18 = 296U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_19 = 297U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_20 = 298U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_21 = 299U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_22 = 300U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_23 = 301U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_24 = 302U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_25 = 303U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_26 = 304U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_27 = 305U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_28 = 306U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_29 = 307U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_30 = 308U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_31 = 309U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_32 = 310U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_33 = 311U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_34 = 312U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_35 = 313U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_36 = 314U,  /**< IOMUXC select input index */
    kIOMUXC_XBAR1_XBAR_IN_SELECT_INPUT_37 = 315U,  /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_CS_SELECT_INPUT = 344U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_DQS_SELECT_INPUT = 345U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_0 = 346U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_1 = 347U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_2 = 348U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_3 = 349U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_4 = 350U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_5 = 351U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_6 = 352U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_7 = 353U, /**< IOMUXC select input index */
    kIOMUXC_XSPI_SLV_IPP_IND_SCK_SELECT_INPUT = 354U, /**< IOMUXC select input index */
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
#define IOMUXC_SW_MUX_CTL_PAD_COUNT               146u
#define IOMUXC_SW_PAD_CTL_PAD_COUNT               146u
#define IOMUXC_SELECT_INPUT_COUNT                 355u

/** IOMUXC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD_GPIO_EMC_B1_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_B2_13 SW MUX Control Register, array offset: 0x10, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD[IOMUXC_SW_PAD_CTL_PAD_COUNT]; /**< SW_PAD_CTL_PAD_GPIO_EMC_B1_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_B2_13 SW PAD Control Register, array offset: 0x258, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[IOMUXC_SELECT_INPUT_COUNT]; /**< CAN1_IPP_IND_CANRX_SELECT_INPUT DAISY Register..XSPI_SLV_IPP_IND_SCK_SELECT_INPUT DAISY Register, array offset: 0x4A0, array step: 0x4, valid indices: [0-143, 190-266, 269-282, 285-315, 344-354] */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_GPIO_EMC_B1_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_B2_13 SW MUX Control Register */
/*! @{ */

#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK      (0xFU)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT     (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b0000..Select mux mode: ALT0 mux port: MIC_BITSTREAM00 of instance: mic
 *  0b0001..Select mux mode: ALT1 mux port: SINC2_EMCLK03 of instance: sinc2
 *  0b0010..Select mux mode: ALT2 mux port: CAN3_TX of instance: can3
 *  0b0011..Select mux mode: ALT3 mux port: LPUART8_CTS_B of instance: lpuart8
 *  0b0100..Select mux mode: ALT4 mux port: LPUART6_TX of instance: lpuart6
 *  0b0101..Select mux mode: ALT5 mux port: GPIO6_IO24 of instance: gpio6
 *  0b0110..Select mux mode: ALT6 mux port: LPI2C4_SCL of instance: lpi2c4
 *  0b0111..Select mux mode: ALT7 mux port: FLEXSPI1_BUS2BIT_A_DATA00 of instance: flexspi1_bus2bit
 *  0b1000..Select mux mode: ALT8 mux port: TPM4_CH00 of instance: tpm4
 *  0b1001..Select mux mode: ALT9 mux port: LPSPI4_SCK of instance: lpspi4
 *  0b1010..Select mux mode: ALT10 mux port: XSPI_SLV_DATA00 of instance: xspi_slv
 *  0b1011..Select mux mode: ALT11 mux port: NETC_PINMUX_ETH2_RXD00 of instance: netc_pinmux
 *  0b1100..Select mux mode: ALT12 mux port: ECAT_RX_DATA0_1 of instance: ecat
 */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define IOMUXC_SW_MUX_CTL_PAD_SION_MASK          (0x10U)
#define IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT         (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad GPIO_SD_B2_12_DUMMY
 */
#define IOMUXC_SW_MUX_CTL_PAD_SION(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_SION_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_GPIO_EMC_B1_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_B2_13 SW PAD Control Register */
/*! @{ */

#define IOMUXC_SW_PAD_CTL_PAD_SRE_MASK           (0x1U)
#define IOMUXC_SW_PAD_CTL_PAD_SRE_SHIFT          (0U)
/*! SRE - Slew Rate Field
 *  0b0..Fast Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC_SW_PAD_CTL_PAD_SRE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SRE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SRE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_DSE_MASK           (0x2U)
#define IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT          (1U)
/*! DSE - Drive Strength Field
 *  0b0..normal driver
 *  0b1..high driver
 */
#define IOMUXC_SW_PAD_CTL_PAD_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PDRV_MASK          (0x2U)
#define IOMUXC_SW_PAD_CTL_PAD_PDRV_SHIFT         (1U)
/*! PDRV - PDRV Field
 *  0b0..high driver
 *  0b1..normal driver
 */
#define IOMUXC_SW_PAD_CTL_PAD_PDRV(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PDRV_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PDRV_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PUE_MASK           (0x4U)
#define IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT          (2U)
/*! PUE - Pull / Keep Select Field
 *  0b0..Pull Disable, Highz
 *  0b1..Pull Enable
 */
#define IOMUXC_SW_PAD_CTL_PAD_PUE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PULL_MASK          (0xCU)
#define IOMUXC_SW_PAD_CTL_PAD_PULL_SHIFT         (2U)
/*! PULL - Pull Down Pull Up Field
 *  0b00..Forbidden
 *  0b01..PU
 *  0b10..PD
 *  0b11..No Pull
 */
#define IOMUXC_SW_PAD_CTL_PAD_PULL(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PULL_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PULL_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PUS_MASK           (0x8U)
#define IOMUXC_SW_PAD_CTL_PAD_PUS_SHIFT          (3U)
/*! PUS - Pull Up / Down Config. Field
 *  0b0..Weak pull down
 *  0b1..Weak pull up
 */
#define IOMUXC_SW_PAD_CTL_PAD_PUS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PUS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PUS_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_ODE_MASK           (0x10U)
#define IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT          (4U)
/*! ODE - Open Drain Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC_SW_PAD_CTL_PAD_ODE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_ODE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_ODE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_IBE_OFF_MASK       (0x80U)
#define IOMUXC_SW_PAD_CTL_PAD_IBE_OFF_SHIFT      (7U)
/*! IBE_OFF - Force Input Buffer Enable (IBE) off Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC_SW_PAD_CTL_PAD_IBE_OFF(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_IBE_OFF_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_IBE_OFF_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_DWP_MASK           (0xF000000U)
#define IOMUXC_SW_PAD_CTL_PAD_DWP_SHIFT          (24U)
/*! DWP - Domain write protection */
#define IOMUXC_SW_PAD_CTL_PAD_DWP(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DWP_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DWP_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK_MASK      (0xF0000000U)
#define IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK_SHIFT     (28U)
/*! DWP_LOCK - Domain write protection lock */
#define IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DWP_LOCK_MASK)
/*! @} */

/*! @name SELECT_INPUT - CAN1_IPP_IND_CANRX_SELECT_INPUT DAISY Register..XSPI_SLV_IPP_IND_SCK_SELECT_INPUT DAISY Register */
/*! @{ */

#define IOMUXC_SELECT_INPUT_DAISY_MASK           (0x7U)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */
#define IOMUXC_SELECT_INPUT_DAISY_SHIFT          (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b000..Selecting Pad: GPIO_EMC_B1_19 for Mode: ALT10
 *  0b001..Selecting Pad: GPIO_EMC_B1_41 for Mode: ALT1
 *  0b010..Selecting Pad: GPIO_EMC_B2_01 for Mode: ALT3
 *  0b011..Selecting Pad: GPIO_EMC_B2_20 for Mode: ALT4
 *  0b100..Selecting Pad: GPIO_AD_31 for Mode: ALT7
 *  0b101..Selecting Pad: GPIO_SD_B2_10 for Mode: ALT10
 *  0b110..Selecting Pad: GPIO_B1_12 for Mode: ALT1
 *  0b111..Selecting Pad: GPIO_B2_02 for Mode: ALT3
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

