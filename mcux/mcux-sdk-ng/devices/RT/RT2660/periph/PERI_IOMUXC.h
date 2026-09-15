/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for IOMUXC
 *
 * CMSIS Peripheral Access Layer for IOMUXC
 */

#if !defined(PERI_IOMUXC_H_)
#define PERI_IOMUXC_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
#if !defined(MAIN_IOMUXC_PIO_T_)
#define MAIN_IOMUXC_PIO_T_
/*!
 * @addtogroup main_iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the MAIN IOMUXC PIO
 *
 * Defines the enumeration for the MAIN IOMUXC PIO collections.
 */
typedef enum _main_iomuxc_pio
{
    kPIO2_0                         = 0U,          /**< IOMUXC PIO index */
    kPIO2_1                         = 1U,          /**< IOMUXC PIO index */
    kPIO2_2                         = 2U,          /**< IOMUXC PIO index */
    kPIO2_3                         = 3U,          /**< IOMUXC PIO index */
    kPIO2_4                         = 4U,          /**< IOMUXC PIO index */
    kPIO2_5                         = 5U,          /**< IOMUXC PIO index */
    kPIO2_6                         = 6U,          /**< IOMUXC PIO index */
    kPIO2_7                         = 7U,          /**< IOMUXC PIO index */
    kPIO2_8                         = 8U,          /**< IOMUXC PIO index */
    kPIO2_9                         = 9U,          /**< IOMUXC PIO index */
    kPIO2_10                        = 10U,         /**< IOMUXC PIO index */
    kPIO2_11                        = 11U,         /**< IOMUXC PIO index */
    kPIO2_12                        = 12U,         /**< IOMUXC PIO index */
    kPIO2_13                        = 13U,         /**< IOMUXC PIO index */
    kPIO2_14                        = 14U,         /**< IOMUXC PIO index */
    kPIO2_15                        = 15U,         /**< IOMUXC PIO index */
    kPIO2_16                        = 16U,         /**< IOMUXC PIO index */
    kPIO2_17                        = 17U,         /**< IOMUXC PIO index */
    kPIO2_18                        = 18U,         /**< IOMUXC PIO index */
    kPIO2_19                        = 19U,         /**< IOMUXC PIO index */
    kPIO2_20                        = 20U,         /**< IOMUXC PIO index */
    kPIO2_21                        = 21U,         /**< IOMUXC PIO index */
    kPIO2_22                        = 22U,         /**< IOMUXC PIO index */
    kPIO2_23                        = 23U,         /**< IOMUXC PIO index */
    kPIO2_24                        = 24U,         /**< IOMUXC PIO index */
    kPIO2_25                        = 25U,         /**< IOMUXC PIO index */
    kPIO2_26                        = 26U,         /**< IOMUXC PIO index */
    kPIO2_27                        = 27U,         /**< IOMUXC PIO index */
    kPIO3_0                         = 32U,         /**< IOMUXC PIO index */
    kPIO3_1                         = 33U,         /**< IOMUXC PIO index */
    kPIO3_2                         = 34U,         /**< IOMUXC PIO index */
    kPIO3_3                         = 35U,         /**< IOMUXC PIO index */
    kPIO3_4                         = 36U,         /**< IOMUXC PIO index */
    kPIO3_5                         = 37U,         /**< IOMUXC PIO index */
    kPIO3_6                         = 38U,         /**< IOMUXC PIO index */
    kPIO3_7                         = 39U,         /**< IOMUXC PIO index */
    kPIO3_8                         = 40U,         /**< IOMUXC PIO index */
    kPIO3_9                         = 41U,         /**< IOMUXC PIO index */
    kPIO3_10                        = 42U,         /**< IOMUXC PIO index */
    kPIO3_11                        = 43U,         /**< IOMUXC PIO index */
    kPIO3_12                        = 44U,         /**< IOMUXC PIO index */
    kPIO3_13                        = 45U,         /**< IOMUXC PIO index */
    kPIO3_14                        = 46U,         /**< IOMUXC PIO index */
    kPIO3_15                        = 47U,         /**< IOMUXC PIO index */
    kPIO3_16                        = 48U,         /**< IOMUXC PIO index */
    kPIO3_17                        = 49U,         /**< IOMUXC PIO index */
    kPIO3_18                        = 50U,         /**< IOMUXC PIO index */
    kPIO3_19                        = 51U,         /**< IOMUXC PIO index */
    kPIO3_20                        = 52U,         /**< IOMUXC PIO index */
    kPIO3_21                        = 53U,         /**< IOMUXC PIO index */
    kPIO3_22                        = 54U,         /**< IOMUXC PIO index */
    kPIO3_23                        = 55U,         /**< IOMUXC PIO index */
    kPIO3_24                        = 56U,         /**< IOMUXC PIO index */
    kPIO3_25                        = 57U,         /**< IOMUXC PIO index */
    kPIO3_26                        = 58U,         /**< IOMUXC PIO index */
    kPIO3_27                        = 59U,         /**< IOMUXC PIO index */
    kPIO3_28                        = 60U,         /**< IOMUXC PIO index */
    kPIO3_29                        = 61U,         /**< IOMUXC PIO index */
    kPIO3_30                        = 62U,         /**< IOMUXC PIO index */
    kPIO3_31                        = 63U,         /**< IOMUXC PIO index */
    kPIO4_0                         = 64U,         /**< IOMUXC PIO index */
    kPIO4_1                         = 65U,         /**< IOMUXC PIO index */
    kPIO4_2                         = 66U,         /**< IOMUXC PIO index */
    kPIO4_3                         = 67U,         /**< IOMUXC PIO index */
    kPIO4_4                         = 68U,         /**< IOMUXC PIO index */
    kPIO4_5                         = 69U,         /**< IOMUXC PIO index */
    kPIO4_6                         = 70U,         /**< IOMUXC PIO index */
    kPIO4_7                         = 71U,         /**< IOMUXC PIO index */
    kPIO4_8                         = 72U,         /**< IOMUXC PIO index */
    kPIO4_9                         = 73U,         /**< IOMUXC PIO index */
    kPIO4_10                        = 74U,         /**< IOMUXC PIO index */
    kPIO4_11                        = 75U,         /**< IOMUXC PIO index */
    kPIO4_12                        = 76U,         /**< IOMUXC PIO index */
    kPIO4_13                        = 77U,         /**< IOMUXC PIO index */
    kPIO4_14                        = 78U,         /**< IOMUXC PIO index */
    kPIO4_15                        = 79U,         /**< IOMUXC PIO index */
    kPIO4_16                        = 80U,         /**< IOMUXC PIO index */
    kPIO4_17                        = 81U,         /**< IOMUXC PIO index */
    kPIO4_18                        = 82U,         /**< IOMUXC PIO index */
    kPIO4_19                        = 83U,         /**< IOMUXC PIO index */
    kPIO4_20                        = 84U,         /**< IOMUXC PIO index */
    kPIO4_21                        = 85U,         /**< IOMUXC PIO index */
    kPIO4_22                        = 86U,         /**< IOMUXC PIO index */
    kPIO4_23                        = 87U,         /**< IOMUXC PIO index */
    kPIO4_24                        = 88U,         /**< IOMUXC PIO index */
    kPIO4_25                        = 89U,         /**< IOMUXC PIO index */
    kPIO4_26                        = 90U,         /**< IOMUXC PIO index */
    kPIO4_27                        = 91U,         /**< IOMUXC PIO index */
    kPIO5_0                         = 96U,         /**< IOMUXC PIO index */
    kPIO5_1                         = 97U,         /**< IOMUXC PIO index */
    kPIO5_2                         = 98U,         /**< IOMUXC PIO index */
    kPIO5_3                         = 99U,         /**< IOMUXC PIO index */
    kPIO5_4                         = 100U,        /**< IOMUXC PIO index */
    kPIO5_5                         = 101U,        /**< IOMUXC PIO index */
    kPIO5_6                         = 102U,        /**< IOMUXC PIO index */
    kPIO5_7                         = 103U,        /**< IOMUXC PIO index */
    kPIO5_8                         = 104U,        /**< IOMUXC PIO index */
    kPIO5_9                         = 105U,        /**< IOMUXC PIO index */
    kPIO5_10                        = 106U,        /**< IOMUXC PIO index */
    kPIO5_11                        = 107U,        /**< IOMUXC PIO index */
    kPIO5_12                        = 108U,        /**< IOMUXC PIO index */
    kPIO5_13                        = 109U,        /**< IOMUXC PIO index */
    kPIO5_14                        = 110U,        /**< IOMUXC PIO index */
    kPIO5_15                        = 111U,        /**< IOMUXC PIO index */
    kPIO5_16                        = 112U,        /**< IOMUXC PIO index */
    kPIO5_17                        = 113U,        /**< IOMUXC PIO index */
    kPIO5_18                        = 114U,        /**< IOMUXC PIO index */
    kPIO5_19                        = 115U,        /**< IOMUXC PIO index */
    kPIO5_20                        = 116U,        /**< IOMUXC PIO index */
    kPIO6_0                         = 128U,        /**< IOMUXC PIO index */
    kPIO6_1                         = 129U,        /**< IOMUXC PIO index */
    kPIO6_2                         = 130U,        /**< IOMUXC PIO index */
    kPIO6_3                         = 131U,        /**< IOMUXC PIO index */
    kPIO6_4                         = 132U,        /**< IOMUXC PIO index */
    kPIO6_5                         = 133U,        /**< IOMUXC PIO index */
    kPIO6_6                         = 134U,        /**< IOMUXC PIO index */
    kPIO6_7                         = 135U,        /**< IOMUXC PIO index */
    kPIO6_8                         = 136U,        /**< IOMUXC PIO index */
    kPIO6_9                         = 137U,        /**< IOMUXC PIO index */
    kPIO6_10                        = 138U,        /**< IOMUXC PIO index */
    kPIO6_11                        = 139U,        /**< IOMUXC PIO index */
    kPIO6_12                        = 140U,        /**< IOMUXC PIO index */
    kPIO7_0                         = 160U,        /**< IOMUXC PIO index */
    kPIO7_1                         = 161U,        /**< IOMUXC PIO index */
    kPIO7_2                         = 162U,        /**< IOMUXC PIO index */
    kPIO7_3                         = 163U,        /**< IOMUXC PIO index */
    kPIO7_4                         = 164U,        /**< IOMUXC PIO index */
    kPIO7_5                         = 165U,        /**< IOMUXC PIO index */
    kPIO7_6                         = 166U,        /**< IOMUXC PIO index */
    kPIO7_7                         = 167U,        /**< IOMUXC PIO index */
    kPIO7_8                         = 168U,        /**< IOMUXC PIO index */
    kPIO7_9                         = 169U,        /**< IOMUXC PIO index */
    kPIO7_10                        = 170U,        /**< IOMUXC PIO index */
    kPIO7_11                        = 171U,        /**< IOMUXC PIO index */
} main_iomuxc_pio_t;

/* @} */
#endif /* MAIN_IOMUXC_PIO_T_ */

#if !defined(MAIN_IOMUXC_SW_DAISY_CONFIG_T_)
#define MAIN_IOMUXC_SW_DAISY_CONFIG_T_
/*!
 * @addtogroup main_iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the MAIN IOMUXC DAISY
 *
 * Defines the enumeration for the MAIN IOMUXC DAISY collections.
 */
typedef enum _main_iomuxc_sw_daisy_config
{
    kAUDIO_MICFIL_PDM_DATA01        = 0U,          /**< IOMUXC DAISY index */
    kAUDIO_MICFIL_PDM_DATA23        = 1U,          /**< IOMUXC DAISY index */
    kAUDIO_MICFIL_PDM_DATA45        = 2U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_MCLK                = 3U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_RX_BCLK             = 4U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_RX_DATA0            = 5U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_RX_DATA1            = 6U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_RX_SYNC             = 7U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_TX_BCLK             = 8U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI1_TX_SYNC             = 9U,          /**< IOMUXC DAISY index */
    kAUDIO_SAI2_MCLK                = 10U,         /**< IOMUXC DAISY index */
    kAUDIO_SAI2_RX_BCLK             = 11U,         /**< IOMUXC DAISY index */
    kAUDIO_SAI2_RX_DATA0            = 12U,         /**< IOMUXC DAISY index */
    kAUDIO_SAI2_RX_DATA1            = 13U,         /**< IOMUXC DAISY index */
    kAUDIO_SAI2_RX_SYNC             = 14U,         /**< IOMUXC DAISY index */
    kAUDIO_SAI2_TX_BCLK             = 15U,         /**< IOMUXC DAISY index */
    kAUDIO_SAI2_TX_SYNC             = 16U,         /**< IOMUXC DAISY index */
    kAUDIO_SPDIF_IN                 = 17U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_REF_CLK1         = 18U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_CLK           = 19U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_TX_CLK_IO        = 20U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_MDIO             = 21U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_COL              = 22U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_CRS              = 23U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_DATA0         = 24U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_DATA1         = 25U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_DATA2         = 26U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_DATA3         = 27U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_EN            = 28U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_QOS_RX_ER            = 29U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_REF_CLK              = 30U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_COL                  = 31U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_CRS                  = 32U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_MDIO                 = 33U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RX_CLK               = 34U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RXD0                 = 35U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RXD1                 = 36U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RXD2                 = 37U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RXD3                 = 38U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RX_EN                = 39U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_RX_ER                = 40U,         /**< IOMUXC DAISY index */
    kCOMM_ENET_TX_CLK_IO            = 41U,         /**< IOMUXC DAISY index */
    kCOMM_USB0_OC                   = 42U,         /**< IOMUXC DAISY index */
    kCOMM_USB0_ID                   = 43U,         /**< IOMUXC DAISY index */
    kCOMM_USB1_VBUS_GPIO            = 44U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC0_CD_B               = 45U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC0_WP                 = 46U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC1_CLK                = 47U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC1_CMD                = 48U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC1_DAT0               = 49U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC1_DAT1               = 50U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC1_DAT2               = 51U,         /**< IOMUXC DAISY index */
    kCOMM_uSDHC1_DAT3               = 52U,         /**< IOMUXC DAISY index */
    kCOMM_10BASET1S0_ED             = 53U,         /**< IOMUXC DAISY index */
    kCOMM_10BASET1S0_RX             = 54U,         /**< IOMUXC DAISY index */
    kCOMM_10BASET1S1_ED             = 55U,         /**< IOMUXC DAISY index */
    kCOMM_10BASET1S1_RX             = 56U,         /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_CS   = 57U,         /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DQS  = 58U,         /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA0 = 59U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA1 = 60U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA2 = 61U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA3 = 62U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA4 = 63U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA5 = 64U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA6 = 65U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_DATA7 = 66U,        /**< IOMUXC DAISY index */
    kCOMM_FlexSPI_FLR_XSPI_FLR_CLK  = 67U,         /**< IOMUXC DAISY index */
    kHSP_CAN1_RX                    = 68U,         /**< IOMUXC DAISY index */
    kHSP_CAN2_RX                    = 69U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO0_FXIO_D28           = 70U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO0_FXIO_D29           = 71U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO0_FXIO_D30           = 72U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO0_FXIO_D31           = 73U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO2_FXIO_D28           = 74U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO2_FXIO_D29           = 75U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO2_FXIO_D30           = 76U,         /**< IOMUXC DAISY index */
    kHSP_FLEXIO2_FXIO_D31           = 77U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM0_A0               = 78U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM0_A1               = 79U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM0_A2               = 80U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM0_B0               = 81U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM0_B1               = 82U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM0_B2               = 83U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_A0               = 84U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_A1               = 85U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_A2               = 86U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_A3               = 87U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_B0               = 88U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_B1               = 89U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_B2               = 90U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_B3               = 91U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM1_X0               = 92U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_A0               = 93U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_A1               = 94U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_A2               = 95U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_A3               = 96U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_B0               = 97U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_B1               = 98U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_B2               = 99U,         /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_B3               = 100U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_X0               = 101U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_X1               = 102U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_X2               = 103U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM2_X3               = 104U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_A0               = 105U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_A1               = 106U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_A2               = 107U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_A3               = 108U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_B0               = 109U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_B1               = 110U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_B2               = 111U,        /**< IOMUXC DAISY index */
    kHSP_eFlexPWM3_B3               = 112U,        /**< IOMUXC DAISY index */
    kHSP_I3C_SCL                    = 113U,        /**< IOMUXC DAISY index */
    kHSP_I3C_SDA                    = 114U,        /**< IOMUXC DAISY index */
    kHSP_LPI2C0_SCL                 = 115U,        /**< IOMUXC DAISY index */
    kHSP_LPI2C0_SDA                 = 116U,        /**< IOMUXC DAISY index */
    kHSP_LPI2C1_SCL                 = 117U,        /**< IOMUXC DAISY index */
    kHSP_LPI2C1_SDA                 = 118U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_PCS0                = 119U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_PCS1                = 120U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_PCS2                = 121U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_PCS3                = 122U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_SCK                 = 123U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_SIN                 = 124U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI0_SOUT                = 125U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_PCS0                = 126U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_PCS1                = 127U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_PCS2                = 128U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_PCS3                = 129U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_SCK                 = 130U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_SIN                 = 131U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI1_SOUT                = 132U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_PCS0                = 133U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_PCS1                = 134U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_PCS2                = 135U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_PCS3                = 136U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_SCK                 = 137U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_SIN                 = 138U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI2_SOUT                = 139U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI3_PCS0                = 140U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI3_PCS2                = 141U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI3_PCS3                = 142U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI3_SCK                 = 143U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI3_SIN                 = 144U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI3_SOUT                = 145U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI4_PCS0                = 146U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI4_PCS2                = 147U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI4_PCS3                = 148U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI4_SCK                 = 149U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI4_SIN                 = 150U,        /**< IOMUXC DAISY index */
    kHSP_LPSPI4_SOUT                = 151U,        /**< IOMUXC DAISY index */
    kHSP_LPUART0_CTS_B              = 152U,        /**< IOMUXC DAISY index */
    kHSP_LPUART0_RXD                = 153U,        /**< IOMUXC DAISY index */
    kHSP_LPUART0_TXD                = 154U,        /**< IOMUXC DAISY index */
    kHSP_LPUART1_CTS_B              = 155U,        /**< IOMUXC DAISY index */
    kHSP_LPUART1_RXD                = 156U,        /**< IOMUXC DAISY index */
    kHSP_LPUART1_TXD                = 157U,        /**< IOMUXC DAISY index */
    kHSP_LPUART2_CTS_B              = 158U,        /**< IOMUXC DAISY index */
    kHSP_LPUART2_RXD                = 159U,        /**< IOMUXC DAISY index */
    kHSP_LPUART2_TXD                = 160U,        /**< IOMUXC DAISY index */
    kHSP_LPUART3_CTS_B              = 161U,        /**< IOMUXC DAISY index */
    kHSP_LPUART3_RXD                = 162U,        /**< IOMUXC DAISY index */
    kHSP_LPUART3_TXD                = 163U,        /**< IOMUXC DAISY index */
    kHSP_LPUART4_CTS_B              = 164U,        /**< IOMUXC DAISY index */
    kHSP_LPUART4_RXD                = 165U,        /**< IOMUXC DAISY index */
    kHSP_LPUART4_TXD                = 166U,        /**< IOMUXC DAISY index */
    kHSP_LPUART5_CTS_B              = 167U,        /**< IOMUXC DAISY index */
    kHSP_LPUART5_RXD                = 168U,        /**< IOMUXC DAISY index */
    kHSP_LPUART5_TXD                = 169U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MBIT0                = 170U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MBIT1                = 171U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MBIT2                = 172U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MBIT3                = 173U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MCLK0                = 174U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MCLK1                = 175U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MCLK2                = 176U,        /**< IOMUXC DAISY index */
    kHSP_SINC0_MCLK3                = 177U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MBIT0                = 178U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MBIT1                = 179U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MBIT2                = 180U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MBIT3                = 181U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MCLK0                = 182U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MCLK1                = 183U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MCLK2                = 184U,        /**< IOMUXC DAISY index */
    kHSP_SINC1_MCLK3                = 185U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT00              = 186U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT01              = 187U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT02              = 188U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT03              = 189U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT04              = 190U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT05              = 191U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT06              = 192U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT07              = 193U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT08              = 194U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT09              = 195U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT10              = 196U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT11              = 197U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT12              = 198U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT13              = 199U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT14              = 200U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT15              = 201U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT16              = 202U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT17              = 203U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT18              = 204U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT19              = 205U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT20              = 206U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT21              = 207U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT22              = 208U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT23              = 209U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT24              = 210U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT25              = 211U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT26              = 212U,        /**< IOMUXC DAISY index */
    kHSP_XBAR0_INOUT27              = 213U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT00              = 214U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT01              = 215U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT02              = 216U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT03              = 217U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT04              = 218U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT05              = 219U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT06              = 220U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT07              = 221U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT08              = 222U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT09              = 223U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT10              = 224U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT11              = 225U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT12              = 226U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT13              = 227U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT14              = 228U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT15              = 229U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT16              = 230U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT17              = 231U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT18              = 232U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT19              = 233U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT20              = 234U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT21              = 235U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT22              = 236U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT23              = 237U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT24              = 238U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT25              = 239U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT26              = 240U,        /**< IOMUXC DAISY index */
    kHSP_XBAR1_INOUT27              = 241U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA00      = 242U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA01      = 243U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA02      = 244U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA03      = 245U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA04      = 246U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA05      = 247U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA06      = 248U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA07      = 249U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA08      = 250U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA09      = 251U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA10      = 252U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA11      = 253U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA12      = 254U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA13      = 255U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA14      = 256U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_DA15      = 257U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_WP0       = 258U,        /**< IOMUXC DAISY index */
    kMAIN_AHB_SRAMC_SRAMC_WP1       = 259U,        /**< IOMUXC DAISY index */
    kMAIN_XSPI0_ECS                 = 260U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA00               = 261U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA01               = 262U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA02               = 263U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA03               = 264U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA04               = 265U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA05               = 266U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA06               = 267U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA07               = 268U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA08               = 269U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA09               = 270U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA10               = 271U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA11               = 272U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA12               = 273U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA13               = 274U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA14               = 275U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_DATA15               = 276U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_HSYNC                = 277U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_PIXCLK               = 278U,        /**< IOMUXC DAISY index */
    kMEDIA_CSI_VSYNC                = 279U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA00       = 280U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA01       = 281U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA02       = 282U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA03       = 283U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA04       = 284U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA05       = 285U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA06       = 286U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA07       = 287U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA08       = 288U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA09       = 289U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA10       = 290U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA11       = 291U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA12       = 292U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA13       = 293U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA14       = 294U,        /**< IOMUXC DAISY index */
    kMEDIA_DCIF_DBI_AB_DATA15       = 295U,        /**< IOMUXC DAISY index */
} main_iomuxc_sw_daisy_config_t;

/* @} */
#endif /* MAIN_IOMUXC_SW_DAISY_CONFIG_T_ */

#if !defined(VABT_IOMUXC_PIO_T_)
#define VABT_IOMUXC_PIO_T_
/*!
 * @addtogroup vabt_iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the VBAT IOMUXC PIO
 *
 * Defines the enumeration for the VBAT IOMUXC PIO collections.
 */
typedef enum _vabt_iomuxc_pio
{
    kPIO0_0                         = 0U,          /**< IOMUXC PIO index */
    kPIO0_1                         = 1U,          /**< IOMUXC PIO index */
    kPIO0_2                         = 2U,          /**< IOMUXC PIO index */
    kPIO0_3                         = 3U,          /**< IOMUXC PIO index */
    kPIO0_4                         = 4U,          /**< IOMUXC PIO index */
    kPIO0_5                         = 5U,          /**< IOMUXC PIO index */
} vabt_iomuxc_pio_t;

/* @} */
#endif /* VABT_IOMUXC_PIO_T_ */

#if !defined(WAKE_IOMUXC_PIO_T_)
#define WAKE_IOMUXC_PIO_T_
/*!
 * @addtogroup wake_iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the WAKE IOMUXC PIO
 *
 * Defines the enumeration for the WAKE IOMUXC PIO collections.
 */
typedef enum _wake_iomuxc_pio
{
    kPIO1_0                         = 0U,          /**< IOMUXC PIO index */
    kPIO1_1                         = 1U,          /**< IOMUXC PIO index */
    kPIO1_2                         = 2U,          /**< IOMUXC PIO index */
    kPIO1_3                         = 3U,          /**< IOMUXC PIO index */
    kPIO1_4                         = 4U,          /**< IOMUXC PIO index */
    kPIO1_5                         = 5U,          /**< IOMUXC PIO index */
    kPIO1_6                         = 6U,          /**< IOMUXC PIO index */
    kPIO1_7                         = 7U,          /**< IOMUXC PIO index */
    kPIO1_8                         = 8U,          /**< IOMUXC PIO index */
    kPIO1_9                         = 9U,          /**< IOMUXC PIO index */
    kPIO1_10                        = 10U,         /**< IOMUXC PIO index */
} wake_iomuxc_pio_t;

/* @} */
#endif /* WAKE_IOMUXC_PIO_T_ */

#if !defined(WAKE_IOMUXC_SW_DAISY_CONFIG_T_)
#define WAKE_IOMUXC_SW_DAISY_CONFIG_T_
/*!
 * @addtogroup wake_iomuxc_pads
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the WAKE IOMUXC DAISY
 *
 * Defines the enumeration for the WAKE IOMUXC DAISY collections.
 */
typedef enum _wake_iomuxc_sw_daisy_config
{
    kWAKE_LPI2C0_SCL                = 0U,          /**< IOMUXC DAISY index */
    kWAKE_LPI2C0_SDA                = 1U,          /**< IOMUXC DAISY index */
    kWAKE_MICFIL_PDM_DATA01         = 2U,          /**< IOMUXC DAISY index */
} wake_iomuxc_sw_daisy_config_t;

/* @} */
#endif /* WAKE_IOMUXC_SW_DAISY_CONFIG_T_ */


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
#define IOMUXC_PIO_COUNT                          172u
#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_COUNT       296u

/** IOMUXC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOMUXC_PIO_COUNT];             /**< IOMUXC Configuration, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
       uint8_t RESERVED_0[32080];
  __IO uint32_t IOMUXC_SW_DAISY_CONFIG[IOMUXC_IOMUXC_SW_DAISY_CONFIG_COUNT]; /**< Daisy Configuration, array offset: 0x8000, array step: 0x4, irregular array, not all indices are valid */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name PIO - IOMUXC Configuration */
/*! @{ */

#define IOMUXC_PIO_MUX_MODE_MASK                 (0xFU)  /* Merged from fields with different position or width, of widths (1, 4), largest definition used */
#define IOMUXC_PIO_MUX_MODE_SHIFT                (0U)
/*! MUX_MODE - MUX Mode Select
 *  0b0000..Function 0
 *  0b0001..Function 1
 *  0b0010..Function 2
 *  0b0011..Function 3
 *  0b0100..Function 4
 *  0b0101..Function 5
 *  0b0110..Function 6
 *  0b0111..Function 7
 *  0b1000..Function 8
 *  0b1001..Function 9
 *  0b1010..Function 10
 *  0b1011..Function 11
 *  0b1100..Function 12
 *  0b1101..Function 13
 *  0b1110..Function 14
 *  0b1111..Function 15
 */
#define IOMUXC_PIO_MUX_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_MUX_MODE_SHIFT)) & IOMUXC_PIO_MUX_MODE_MASK)  /* Merged from fields with different position or width, of widths (1, 4), largest definition used */

#define IOMUXC_PIO_PULLENA_MASK                  (0x30U)
#define IOMUXC_PIO_PULLENA_SHIFT                 (4U)
/*! PULLENA - Pullup/Pulldown Enable
 *  0b00..Disables pullup/pulldown
 *  0b01..Enables pulldown
 *  0b10..Enables pullup
 *  0b11..Retains state (bus keeper)
 */
#define IOMUXC_PIO_PULLENA(x)                    (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_PULLENA_SHIFT)) & IOMUXC_PIO_PULLENA_MASK)

#define IOMUXC_PIO_PRVAL_MASK                    (0x40U)
#define IOMUXC_PIO_PRVAL_SHIFT                   (6U)
/*! PRVAL - Pull Resister Value
 *  0b0..50 kohm
 *  0b1..250 kohm
 */
#define IOMUXC_PIO_PRVAL(x)                      (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_PRVAL_SHIFT)) & IOMUXC_PIO_PRVAL_MASK)

#define IOMUXC_PIO_IBENA_MASK                    (0x80U)
#define IOMUXC_PIO_IBENA_SHIFT                   (7U)
/*! IBENA - Input Buffer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOMUXC_PIO_IBENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_IBENA_SHIFT)) & IOMUXC_PIO_IBENA_MASK)

#define IOMUXC_PIO_SLEWRATE_MASK                 (0x300U)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
#define IOMUXC_PIO_SLEWRATE_SHIFT                (8U)
/*! SLEWRATE - Slew Rate Control
 *  0b00..Low-speed mode
 *  0b01..Medium-speed mode
 *  0b10..Fast-speed mode
 *  0b11..High-speed mode
 */
#define IOMUXC_PIO_SLEWRATE(x)                   (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_SLEWRATE_SHIFT)) & IOMUXC_PIO_SLEWRATE_MASK)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */

#define IOMUXC_PIO_ODENA_MASK                    (0x400U)
#define IOMUXC_PIO_ODENA_SHIFT                   (10U)
/*! ODENA - Open-drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOMUXC_PIO_ODENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_ODENA_SHIFT)) & IOMUXC_PIO_ODENA_MASK)

#define IOMUXC_PIO_IIENA_MASK                    (0x800U)
#define IOMUXC_PIO_IIENA_SHIFT                   (11U)
/*! IIENA - Input Invert Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOMUXC_PIO_IIENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_IIENA_SHIFT)) & IOMUXC_PIO_IIENA_MASK)

#define IOMUXC_PIO_DRIVE_MASK                    (0x3000U)
#define IOMUXC_PIO_DRIVE_SHIFT                   (12U)
/*! DRIVE - Drive Strength
 *  0b00..100 ohm
 *  0b01..66 ohm
 *  0b10..50 ohm
 *  0b11..33 ohm
 */
#define IOMUXC_PIO_DRIVE(x)                      (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_DRIVE_SHIFT)) & IOMUXC_PIO_DRIVE_MASK)

#define IOMUXC_PIO_PFENA_MASK                    (0x4000U)
#define IOMUXC_PIO_PFENA_SHIFT                   (14U)
/*! PFENA - Passive Filter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOMUXC_PIO_PFENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_PFENA_SHIFT)) & IOMUXC_PIO_PFENA_MASK)

#define IOMUXC_PIO_GPIO_MON_ENA_MASK             (0x10000U)
#define IOMUXC_PIO_GPIO_MON_ENA_SHIFT            (16U)
/*! GPIO_MON_ENA - GPIO Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define IOMUXC_PIO_GPIO_MON_ENA(x)               (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_GPIO_MON_ENA_SHIFT)) & IOMUXC_PIO_GPIO_MON_ENA_MASK)

#define IOMUXC_PIO_LOCK_MASK                     (0x80000000U)
#define IOMUXC_PIO_LOCK_SHIFT                    (31U)
/*! LOCK - Lock
 *  0b0..Does not lock
 *  0b1..Locks
 */
#define IOMUXC_PIO_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << IOMUXC_PIO_LOCK_SHIFT)) & IOMUXC_PIO_LOCK_MASK)
/*! @} */

/*! @name IOMUXC_SW_DAISY_CONFIG - Daisy Configuration */
/*! @{ */

#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_DAISY_MASK (0x7U)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */
#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_DAISY_SHIFT (0U)
/*! DAISY - Multiplex Input Path
 *  0b000..PIO2_17---ALT1
 *  0b001..PIO4_9---ALT9
 *  0b010..PIO4_22---ALT9
 *  0b011..PIO6_10---ALT9
 *  0b100..PIO7_11---ALT9
 */
#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_DAISY(x)   (((uint32_t)(((uint32_t)(x)) << IOMUXC_IOMUXC_SW_DAISY_CONFIG_DAISY_SHIFT)) & IOMUXC_IOMUXC_SW_DAISY_CONFIG_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2, 3), largest definition used */

#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_LOCK_MASK  (0x80000000U)
#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_LOCK_SHIFT (31U)
/*! LOCK - Lock
 *  0b0..Does not lock
 *  0b1..Locks
 */
#define IOMUXC_IOMUXC_SW_DAISY_CONFIG_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << IOMUXC_IOMUXC_SW_DAISY_CONFIG_LOCK_SHIFT)) & IOMUXC_IOMUXC_SW_DAISY_CONFIG_LOCK_MASK)
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

