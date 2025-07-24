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
**         CMSIS Peripheral Access Layer for IOMUXC_AON
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
 * @file PERI_IOMUXC_AON.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC_AON
 *
 * CMSIS Peripheral Access Layer for IOMUXC_AON
 */

#if !defined(PERI_IOMUXC_AON_H_)
#define PERI_IOMUXC_AON_H_                       /**< Symbol preventing repeated inclusion */

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
#if !defined(IOMUXC_AON_SW_MUX_CTL_PAD_T_)
#define IOMUXC_AON_SW_MUX_CTL_PAD_T_
/*!
 * @addtogroup iomuxc_aon_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC_AON SW_MUX_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC_AON SW_MUX_CTL_PAD collections.
 */
typedef enum _iomuxc_aon_sw_mux_ctl_pad
{
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_00 = 0U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_01 = 1U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_02 = 2U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_03 = 3U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_04 = 4U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_05 = 5U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_06 = 6U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_07 = 7U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_08 = 8U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_09 = 9U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_10 = 10U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_11 = 11U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_12 = 12U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_13 = 13U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_14 = 14U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_15 = 15U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_16 = 16U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_17 = 17U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_18 = 18U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_19 = 19U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_20 = 20U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_21 = 21U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_22 = 22U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_23 = 23U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_24 = 24U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_25 = 25U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_26 = 26U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_27 = 27U,  /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC_AON_SW_MUX_CTL_PAD_GPIO_AON_28_DUMMY = 28U, /**< IOMUXC SW_MUX_CTL_PAD index */
} iomuxc_aon_sw_mux_ctl_pad_t;

/* @} */
#endif /* IOMUXC_AON_SW_MUX_CTL_PAD_T_ */

#if !defined(IOMUXC_AON_SW_PAD_CTL_PAD_T_)
#define IOMUXC_AON_SW_PAD_CTL_PAD_T_
/*!
 * @addtogroup iomuxc_aon_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC_AON SW_PAD_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC_AON SW_PAD_CTL_PAD collections.
 */
typedef enum _iomuxc_aon_sw_pad_ctl_pad
{
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_00 = 0U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_01 = 1U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_02 = 2U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_03 = 3U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_04 = 4U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_05 = 5U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_06 = 6U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_07 = 7U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_08 = 8U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_09 = 9U,   /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_10 = 10U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_11 = 11U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_12 = 12U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_13 = 13U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_14 = 14U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_15 = 15U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_16 = 16U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_17 = 17U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_18 = 18U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_19 = 19U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_20 = 20U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_21 = 21U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_22 = 22U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_23 = 23U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_24 = 24U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_25 = 25U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_26 = 26U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_27 = 27U,  /**< IOMUXC SW_PAD_CTL_PAD index */
    kIOMUXC_AON_SW_PAD_CTL_PAD_GPIO_AON_28_DUMMY = 28U, /**< IOMUXC SW_PAD_CTL_PAD index */
} iomuxc_aon_sw_pad_ctl_pad_t;

/* @} */
#endif /* IOMUXC_AON_SW_PAD_CTL_PAD_T_ */

#if !defined(IOMUXC_AON_SELECT_INPUT_T_)
#define IOMUXC_AON_SELECT_INPUT_T_
/*!
 * @brief Enumeration for the IOMUXC_AON select input
 *
 * Defines the enumeration for the IOMUXC_AON select input collections.
 */
typedef enum _iomuxc_aon_select_input
{
    kIOMUXC_AON_I3C1_PIN_SCL_IN_SELECT_INPUT = 0U, /**< IOMUXC select input index */
    kIOMUXC_AON_I3C1_PIN_SDA_IN_SELECT_INPUT = 1U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPI2C1_IPP_IND_LPI2C_SCL_SELECT_INPUT = 2U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPI2C1_IPP_IND_LPI2C_SDA_SELECT_INPUT = 3U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPI2C2_IPP_IND_LPI2C_SCL_SELECT_INPUT = 4U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPI2C2_IPP_IND_LPI2C_SDA_SELECT_INPUT = 5U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI1_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 6U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI1_IPP_IND_LPSPI_PCS_SELECT_INPUT_1 = 7U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI1_IPP_IND_LPSPI_SCK_SELECT_INPUT = 8U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI1_IPP_IND_LPSPI_SDI_SELECT_INPUT = 9U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI1_IPP_IND_LPSPI_SDO_SELECT_INPUT = 10U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI2_IPP_IND_LPSPI_PCS_SELECT_INPUT_0 = 11U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI2_IPP_IND_LPSPI_PCS_SELECT_INPUT_1 = 12U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI2_IPP_IND_LPSPI_PCS_SELECT_INPUT_3 = 13U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI2_IPP_IND_LPSPI_SCK_SELECT_INPUT = 14U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI2_IPP_IND_LPSPI_SDI_SELECT_INPUT = 15U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPSPI2_IPP_IND_LPSPI_SDO_SELECT_INPUT = 16U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPTMR1_IPP_IND_LPTIMER_SELECT_INPUT_1 = 17U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPTMR1_IPP_IND_LPTIMER_SELECT_INPUT_2 = 18U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPTMR1_IPP_IND_LPTIMER_SELECT_INPUT_3 = 19U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART1_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 20U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART1_IPP_IND_LPUART_DCD_N_SELECT_INPUT = 21U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART1_IPP_IND_LPUART_DSR_N_SELECT_INPUT = 22U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART12_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 23U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART12_IPP_IND_LPUART_RXD_SELECT_INPUT = 24U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART12_IPP_IND_LPUART_TXD_SELECT_INPUT = 25U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART2_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 26U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART2_IPP_IND_LPUART_RXD_SELECT_INPUT = 27U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART2_IPP_IND_LPUART_TXD_SELECT_INPUT = 28U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART7_IPP_IND_LPUART_CTS_N_SELECT_INPUT = 29U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART7_IPP_IND_LPUART_RXD_SELECT_INPUT = 30U, /**< IOMUXC select input index */
    kIOMUXC_AON_LPUART7_IPP_IND_LPUART_TXD_SELECT_INPUT = 31U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPG_CLK_SAI_MCLK_SELECT_INPUT = 32U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 33U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPP_IND_SAI_RXDATA_SELECT_INPUT_0 = 34U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPP_IND_SAI_RXDATA_SELECT_INPUT_1 = 35U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 36U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 37U, /**< IOMUXC select input index */
    kIOMUXC_AON_SAI1_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 38U, /**< IOMUXC select input index */
} iomuxc_aon_select_input_t;
#endif /* IOMUXC_AON_SELECT_INPUT_T_ */


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
   -- IOMUXC_AON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_AON_Peripheral_Access_Layer IOMUXC_AON Peripheral Access Layer
 * @{
 */

/** IOMUXC_AON - Size of Registers Arrays */
#define IOMUXC_AON_SW_MUX_CTL_PAD_COUNT           29u
#define IOMUXC_AON_SW_PAD_CTL_PAD_COUNT           29u
#define IOMUXC_AON_SELECT_INPUT_COUNT             39u

/** IOMUXC_AON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC_AON_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD_GPIO_AON_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_AON_28_DUMMY SW MUX Control Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD[IOMUXC_AON_SW_PAD_CTL_PAD_COUNT]; /**< SW_PAD_CTL_PAD_GPIO_AON_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_AON_28_DUMMY SW PAD Control Register, array offset: 0x74, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[IOMUXC_AON_SELECT_INPUT_COUNT]; /**< I3C1_PIN_SCL_IN_SELECT_INPUT DAISY Register..SAI1_IPP_IND_SAI_TXSYNC_SELECT_INPUT DAISY Register, array offset: 0xE8, array step: 0x4 */
} IOMUXC_AON_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_AON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_AON_Register_Masks IOMUXC_AON Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_GPIO_AON_00 SW MUX Control Register..SW_MUX_CTL_PAD_GPIO_AON_28_DUMMY SW MUX Control Register */
/*! @{ */

#define IOMUXC_AON_SW_MUX_CTL_PAD_MUX_MODE_MASK  (0xFU)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */
#define IOMUXC_AON_SW_MUX_CTL_PAD_MUX_MODE_SHIFT (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b0000..Select mux mode: ALT0 mux port: SRC_BOOT_MODE02 of instance: src
 *  0b0001..Select mux mode: ALT1 mux port: CAN3_TX of instance: can3
 *  0b0010..Select mux mode: ALT2 mux port: LPSPI2_PCS3 of instance: lpspi2
 *  0b0011..Select mux mode: ALT3 mux port: LPSPI2_SDO of instance: lpspi2
 *  0b0100..Select mux mode: ALT4 mux port: LPTMR1_ALT3 of instance: lptmr1
 *  0b0101..Select mux mode: ALT5 mux port: GPIO1_IO02 of instance: gpio1
 *  0b0110..Select mux mode: ALT6 mux port: LPUART2_RTS_B of instance: lpuart2
 *  0b1000..Select mux mode: ALT8 mux port: TPM1_CH01 of instance: tpm1
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Select mux mode: ALT12 mux port: ECAT_CLK_ECAT_CLK25 of instance: ecat
 */
#define IOMUXC_AON_SW_MUX_CTL_PAD_MUX_MODE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_AON_SW_MUX_CTL_PAD_MUX_MODE_MASK)  /* Merged from fields with different position or width, of widths (3, 4), largest definition used */

#define IOMUXC_AON_SW_MUX_CTL_PAD_SION_MASK      (0x10U)
#define IOMUXC_AON_SW_MUX_CTL_PAD_SION_SHIFT     (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad GPIO_AON_28_DUMMY
 */
#define IOMUXC_AON_SW_MUX_CTL_PAD_SION(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_AON_SW_MUX_CTL_PAD_SION_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_GPIO_AON_00 SW PAD Control Register..SW_PAD_CTL_PAD_GPIO_AON_28_DUMMY SW PAD Control Register */
/*! @{ */

#define IOMUXC_AON_SW_PAD_CTL_PAD_SRE_MASK       (0x1U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_SRE_SHIFT      (0U)
/*! SRE - Slew Rate Field
 *  0b0..Fast Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC_AON_SW_PAD_CTL_PAD_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_SRE_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_SRE_MASK)

#define IOMUXC_AON_SW_PAD_CTL_PAD_DSE_MASK       (0x2U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_DSE_SHIFT      (1U)
/*! DSE - Drive Strength Field
 *  0b0..normal driver
 *  0b1..high driver
 */
#define IOMUXC_AON_SW_PAD_CTL_PAD_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC_AON_SW_PAD_CTL_PAD_PUE_MASK       (0x4U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_PUE_SHIFT      (2U)
/*! PUE - Pull / Keep Select Field
 *  0b0..Pull Disable, Highz
 *  0b1..Pull Enable
 */
#define IOMUXC_AON_SW_PAD_CTL_PAD_PUE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_PUE_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_PUE_MASK)

#define IOMUXC_AON_SW_PAD_CTL_PAD_PUS_MASK       (0x8U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_PUS_SHIFT      (3U)
/*! PUS - Pull Up / Down Config. Field
 *  0b0..Weak pull down
 *  0b1..Weak pull up
 */
#define IOMUXC_AON_SW_PAD_CTL_PAD_PUS(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_PUS_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_PUS_MASK)

#define IOMUXC_AON_SW_PAD_CTL_PAD_ODE_MASK       (0x10U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_ODE_SHIFT      (4U)
/*! ODE - Open Drain Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC_AON_SW_PAD_CTL_PAD_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_ODE_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_ODE_MASK)

#define IOMUXC_AON_SW_PAD_CTL_PAD_DWP_MASK       (0xF000000U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_DWP_SHIFT      (24U)
/*! DWP - Domain write protection */
#define IOMUXC_AON_SW_PAD_CTL_PAD_DWP(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_DWP_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_DWP_MASK)

#define IOMUXC_AON_SW_PAD_CTL_PAD_DWP_LOCK_MASK  (0xF0000000U)
#define IOMUXC_AON_SW_PAD_CTL_PAD_DWP_LOCK_SHIFT (28U)
/*! DWP_LOCK - Domain write protection lock */
#define IOMUXC_AON_SW_PAD_CTL_PAD_DWP_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SW_PAD_CTL_PAD_DWP_LOCK_SHIFT)) & IOMUXC_AON_SW_PAD_CTL_PAD_DWP_LOCK_MASK)
/*! @} */

/*! @name SELECT_INPUT - I3C1_PIN_SCL_IN_SELECT_INPUT DAISY Register..SAI1_IPP_IND_SAI_TXSYNC_SELECT_INPUT DAISY Register */
/*! @{ */

#define IOMUXC_AON_SELECT_INPUT_DAISY_MASK       (0x3U)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
#define IOMUXC_AON_SELECT_INPUT_DAISY_SHIFT      (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b00..Selecting Pad: GPIO_AON_06 for Mode: ALT3
 *  0b01..Selecting Pad: GPIO_AON_08 for Mode: ALT6
 *  0b10..Selecting Pad: GPIO_AON_20 for Mode: ALT2
 *  0b11..Selecting Pad: GPIO_AON_24 for Mode: ALT1
 */
#define IOMUXC_AON_SELECT_INPUT_DAISY(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_AON_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC_AON_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_AON_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_AON_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC_AON_H_ */

