/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC0.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC0
 *
 * CMSIS Peripheral Access Layer for IOMUXC0
 */

#if !defined(PERI_IOMUXC0_H_)
#define PERI_IOMUXC0_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
#if !defined(IOMUXC0_SW_MUX_CTL_PAD_T_)
#define IOMUXC0_SW_MUX_CTL_PAD_T_
/*!
 * @addtogroup iomuxc0_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the IOMUXC0 SW_MUX_CTL_PAD
 *
 * Defines the enumeration for the IOMUXC0 SW_MUX_CTL_PAD collections.
 */
typedef enum _iomuxc0_sw_mux_ctl_pad
{
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA0 = 0U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA1 = 1U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA2 = 2U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA3 = 3U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA4 = 4U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA5 = 5U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA6 = 6U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA7 = 7U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA8 = 8U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA9 = 9U,     /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA10 = 10U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA11 = 11U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA12 = 12U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA13 = 13U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA14 = 14U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA15 = 15U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA16 = 16U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA17 = 17U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA18 = 18U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA19 = 19U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA20 = 20U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA21 = 21U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA22 = 22U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA23 = 23U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA24 = 24U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA25 = 25U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA26 = 26U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA27 = 27U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA28 = 28U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA29 = 29U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA30 = 30U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTA31 = 31U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB0 = 32U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB1 = 33U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB2 = 34U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB3 = 35U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB4 = 36U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB5 = 37U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB6 = 38U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB7 = 39U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB8 = 40U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB9 = 41U,    /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB10 = 42U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB11 = 43U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB12 = 44U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB13 = 45U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB14 = 46U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB15 = 47U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB16 = 48U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB17 = 49U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB18 = 50U,   /**< IOMUXC SW_MUX_CTL_PAD index */
    kIOMUXC0_IOMUXC0_SW_MUX_CTL_PAD_PTB19 = 51U,   /**< IOMUXC SW_MUX_CTL_PAD index */
} iomuxc0_sw_mux_ctl_pad_t;

/* @} */
#endif /* IOMUXC0_SW_MUX_CTL_PAD_T_ */

#if !defined(IOMUXC0_SELECT_INPUT_T_)
#define IOMUXC0_SELECT_INPUT_T_
/*!
 * @brief Enumeration for the IOMUXC0 select input
 *
 * Defines the enumeration for the IOMUXC0 select input collections.
 */
typedef enum _iomuxc0_select_input
{
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_PCS0_SELECT_INPUT = 0U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_PCS1_SELECT_INPUT = 1U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_PCS2_SELECT_INPUT = 2U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_PCS3_SELECT_INPUT = 3U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_SCK_SELECT_INPUT = 4U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_SDI_SELECT_INPUT = 5U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI0_IPP_IND_LPSPI_SDO_SELECT_INPUT = 6U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_PCS0_SELECT_INPUT = 7U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_PCS1_SELECT_INPUT = 8U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_PCS2_SELECT_INPUT = 9U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_PCS3_SELECT_INPUT = 10U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_SCK_SELECT_INPUT = 11U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_SDI_SELECT_INPUT = 12U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPSPI1_IPP_IND_LPSPI_SDO_SELECT_INPUT = 13U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CH0_SELECT_INPUT = 14U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CH1_SELECT_INPUT = 15U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CH2_SELECT_INPUT = 16U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CH3_SELECT_INPUT = 17U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CH4_SELECT_INPUT = 18U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CH5_SELECT_INPUT = 19U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM1_IPP_IND_LPTPM_CH0_SELECT_INPUT = 20U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM1_IPP_IND_LPTPM_CH1_SELECT_INPUT = 21U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM2_IPP_IND_LPTPM_CH0_SELECT_INPUT = 22U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM2_IPP_IND_LPTPM_CH1_SELECT_INPUT = 23U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CH0_SELECT_INPUT = 24U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CH1_SELECT_INPUT = 25U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CH2_SELECT_INPUT = 26U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CH3_SELECT_INPUT = 27U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CH4_SELECT_INPUT = 28U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CH5_SELECT_INPUT = 29U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C0_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 30U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C0_IPP_IND_LPI2C_SCL_SELECT_INPUT = 31U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C0_IPP_IND_LPI2C_SDA_SELECT_INPUT = 32U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C1_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 33U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C1_IPP_IND_LPI2C_SCL_SELECT_INPUT = 34U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C1_IPP_IND_LPI2C_SDA_SELECT_INPUT = 35U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C2_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 36U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C2_IPP_IND_LPI2C_SCL_SELECT_INPUT = 37U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C2_IPP_IND_LPI2C_SDA_SELECT_INPUT = 38U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C3_IPP_IND_LPI2C_HREQ_SELECT_INPUT = 39U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C3_IPP_IND_LPI2C_SCL_SELECT_INPUT = 40U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPI2C3_IPP_IND_LPI2C_SDA_SELECT_INPUT = 41U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM0_IPP_IND_LPTPM_CLK_SELECT_INPUT = 42U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM1_IPP_IND_LPTPM_CLK_SELECT_INPUT = 43U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM3_IPP_IND_LPTPM_CLK_SELECT_INPUT = 44U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_PCC_AIPS0_IPP_IND_EXTCLK55_SELECT_INPUT = 45U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI0_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 46U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI0_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 47U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI0_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 48U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI0_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 49U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_PCC_AIPS1_IPP_IND_EXTCLK42_SELECT_INPUT = 50U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_RXBCLK_SELECT_INPUT = 51U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_RXSYNC_SELECT_INPUT = 52U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_TXBCLK_SELECT_INPUT = 53U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_TXSYNC_SELECT_INPUT = 54U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI0_IPP_IND_SAI_RXDATA0_SELECT_INPUT = 55U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI0_IPP_IND_SAI_RXDATA1_SELECT_INPUT = 56U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_RXDATA0_SELECT_INPUT = 57U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_RXDATA1_SELECT_INPUT = 58U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_RXDATA2_SELECT_INPUT = 59U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_SAI1_IPP_IND_SAI_RXDATA3_SELECT_INPUT = 60U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPTPM2_IPP_IND_LPTPM_CLK_SELECT_INPUT = 61U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART0_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 62U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART0_IPP_IND_LPUART_RXD_SELECT_INPUT = 63U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART0_IPP_IND_LPUART_TXD_SELECT_INPUT = 64U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART1_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 65U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART1_IPP_IND_LPUART_RXD_SELECT_INPUT = 66U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART1_IPP_IND_LPUART_TXD_SELECT_INPUT = 67U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART2_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 68U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART2_IPP_IND_LPUART_RXD_SELECT_INPUT = 69U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART2_IPP_IND_LPUART_TXD_SELECT_INPUT = 70U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART3_IPP_IND_LPUART_CTS_B_SELECT_INPUT = 71U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART3_IPP_IND_LPUART_RXD_SELECT_INPUT = 72U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_LPUART3_IPP_IND_LPUART_TXD_SELECT_INPUT = 73U, /**< IOMUXC select input index */
    kIOMUXC0_IOMUXC0_D_IP_EWM_SYN_EWM_IN_SELECT_INPUT = 74U, /**< IOMUXC select input index */
} iomuxc0_select_input_t;
#endif /* IOMUXC0_SELECT_INPUT_T_ */


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
   -- IOMUXC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC0_Peripheral_Access_Layer IOMUXC0 Peripheral Access Layer
 * @{
 */

/** IOMUXC0 - Size of Registers Arrays */
#define IOMUXC0_SW_MUX_CTL_PAD_COUNT              52u
#define IOMUXC0_SELECT_INPUT_COUNT                75u

/** IOMUXC0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC0_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD SW MUX Control Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[48];
  __IO uint32_t SELECT_INPUT[IOMUXC0_SELECT_INPUT_COUNT]; /**< N_SELECT_INPUT_DAISY_Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[104];
  __IO uint32_t SW_MUX_CTL_PAD_RESET0_b;           /**< SW_MUX_CTL_PAD_RESET0_b SW MUX Control Register, offset: 0x294 */
} IOMUXC0_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC0_Register_Masks IOMUXC0 Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD SW MUX Control Register */
/*! @{ */

#define IOMUXC0_SW_MUX_CTL_PAD_PS_MASK           (0x1U)
#define IOMUXC0_SW_MUX_CTL_PAD_PS_SHIFT          (0U)
/*! PS - Pull Select Field
 *  0b0..pull-down
 *  0b1..pull-up
 */
#define IOMUXC0_SW_MUX_CTL_PAD_PS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_PS_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_PS_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_PE_MASK           (0x2U)
#define IOMUXC0_SW_MUX_CTL_PAD_PE_SHIFT          (1U)
/*! PE - Pull Enable field
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_PE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_PE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_PE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_SRE_MASK          (0x4U)
#define IOMUXC0_SW_MUX_CTL_PAD_SRE_SHIFT         (2U)
/*! SRE - Slew Rate Enable Field
 *  0b0..Standard
 *  0b1..Slow
 */
#define IOMUXC0_SW_MUX_CTL_PAD_SRE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_SRE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_SRE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_ODE_MASK          (0x20U)
#define IOMUXC0_SW_MUX_CTL_PAD_ODE_SHIFT         (5U)
/*! ODE - Open-drain Enable Field
 *  0b0..Push-pull
 *  0b1..Open-drain
 */
#define IOMUXC0_SW_MUX_CTL_PAD_ODE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_ODE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_ODE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_DSE_MASK          (0x40U)
#define IOMUXC0_SW_MUX_CTL_PAD_DSE_SHIFT         (6U)
/*! DSE - Drive Strength Enable Field
 *  0b0..Standard
 *  0b1..Hi Drive
 */
#define IOMUXC0_SW_MUX_CTL_PAD_DSE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_DSE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_DSE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_MUX_MODE_MASK     (0xF00U)
#define IOMUXC0_SW_MUX_CTL_PAD_MUX_MODE_SHIFT    (8U)
/*! MUX_MODE - MUX Mode Select Field. */
#define IOMUXC0_SW_MUX_CTL_PAD_MUX_MODE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_MUX_MODE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_LK_MASK           (0x8000U)
#define IOMUXC0_SW_MUX_CTL_PAD_LK_SHIFT          (15U)
/*! LK - Lock Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_LK(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_LK_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_LK_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_IBE_MASK          (0x10000U)
#define IOMUXC0_SW_MUX_CTL_PAD_IBE_SHIFT         (16U)
/*! IBE - Input Buffer Enable Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_IBE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_IBE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_IBE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK          (0x20000U)
#define IOMUXC0_SW_MUX_CTL_PAD_OBE_SHIFT         (17U)
/*! OBE - Output Buffer Enable Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_OBE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_OBE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_OBE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_DFE_MASK          (0x100000U)
#define IOMUXC0_SW_MUX_CTL_PAD_DFE_SHIFT         (20U)
/*! DFE - Digital Filter Enable Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_DFE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_DFE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_DFE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_DFCS_MASK         (0x200000U)
#define IOMUXC0_SW_MUX_CTL_PAD_DFCS_SHIFT        (21U)
/*! DFCS - Digital Filter Clock Select Field
 *  0b0..IPG Clk
 *  0b1..1Khz CLK
 */
#define IOMUXC0_SW_MUX_CTL_PAD_DFCS(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_DFCS_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_DFCS_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_DFD_MASK          (0x7C00000U)
#define IOMUXC0_SW_MUX_CTL_PAD_DFD_SHIFT         (22U)
/*! DFD - Digital Filter Duration Field
 *  0b00000..Disabled
 *  0b00001..Count1
 *  0b00010..Count2
 *  0b00011..Count3
 *  0b00100..Count4
 *  0b00101..Count5
 *  0b00110..Count6
 *  0b00111..Count7
 *  0b01000..Count8
 *  0b01001..Count9
 *  0b01010..Count10
 *  0b01011..Count11
 *  0b01100..Count12
 *  0b01101..Count13
 *  0b01110..Count14
 *  0b01111..Count15
 *  0b10000..Count16
 *  0b10001..Count17
 *  0b10010..Count18
 *  0b10011..Count19
 *  0b10100..Count20
 *  0b10101..Count21
 *  0b10110..Count22
 *  0b10111..Count23
 *  0b11000..Count24
 *  0b11001..Count25
 *  0b11010..Count26
 *  0b11011..Count27
 *  0b11100..Count28
 *  0b11101..Count29
 *  0b11110..Count30
 *  0b11111..Count31
 */
#define IOMUXC0_SW_MUX_CTL_PAD_DFD(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_DFD_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_DFD_MASK)
/*! @} */

/*! @name SELECT_INPUT - N_SELECT_INPUT_DAISY_Register */
/*! @{ */

#define IOMUXC0_SELECT_INPUT_DAISY_MASK          (0x7U)
#define IOMUXC0_SELECT_INPUT_DAISY_SHIFT         (0U)
/*! DAISY - Selects source pad for Module Input Function. Refer to "Input SSS" column from "Input Mux" tab on IOMUX Sheet. */
#define IOMUXC0_SELECT_INPUT_DAISY(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC0_SELECT_INPUT_DAISY_MASK)

#define IOMUXC0_SELECT_INPUT_INVERSION_MASK      (0x8000U)
#define IOMUXC0_SELECT_INPUT_INVERSION_SHIFT     (15U)
/*! INVERSION - Controls the inversion of the pad->module input to instance
 *  0b0..Disable inversion.
 *  0b1..Enable inversion.
 */
#define IOMUXC0_SELECT_INPUT_INVERSION(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SELECT_INPUT_INVERSION_SHIFT)) & IOMUXC0_SELECT_INPUT_INVERSION_MASK)
/*! @} */

/*! @name SW_MUX_CTL_PAD_RESET0_b - SW_MUX_CTL_PAD_RESET0_b SW MUX Control Register */
/*! @{ */

#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PS_MASK  (0x1U)
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PS_SHIFT (0U)
/*! PS - Pull Select Field
 *  0b0..pull-down
 *  0b1..pull-up
 */
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PS(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PS_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PS_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PE_MASK  (0x2U)
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PE_SHIFT (1U)
/*! PE - Pull Enable field
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PE(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_PE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_SRE_MASK (0x4U)
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_SRE_SHIFT (2U)
/*! SRE - Slew Rate Enable Field
 *  0b0..Standard
 *  0b1..Slow
 */
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_SRE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_SRE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_SRE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_ODE_MASK (0x20U)
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_ODE_SHIFT (5U)
/*! ODE - Open-drain Enable Field
 *  0b0..Push-pull
 *  0b1..Open-drain
 */
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_ODE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_ODE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_ODE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_DSE_MASK (0x40U)
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_DSE_SHIFT (6U)
/*! DSE - Drive Strength Enable Field
 *  0b0..Standard
 *  0b1..Hi Drive
 */
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_DSE(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_DSE_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_DSE_MASK)

#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_LK_MASK  (0x8000U)
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_LK_SHIFT (15U)
/*! LK - Lock Field
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_LK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_LK_SHIFT)) & IOMUXC0_SW_MUX_CTL_PAD_RESET0_b_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC0_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC0_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC0_H_ */

