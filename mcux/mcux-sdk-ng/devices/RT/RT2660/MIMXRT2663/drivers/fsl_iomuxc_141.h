/*
 * Copyright 2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_IOMUXC_H_
#define _FSL_IOMUXC_H_

#include "fsl_common.h"

/*!
 * @addtogroup iomuxc_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.iomuxc"
#endif

/*! @name Driver version */
/*@{*/
/*! @brief IOMUXC driver version 2.0.0. */
#define FSL_IOMUXC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @name Pin function ID
 * The pin function ID is a tuple of \<muxRegister muxMode inputRegister inputDaisy configRegister\>
 *
 * @{
 */
#define IOMUXC_PIO2_0_HSP_GPIO0_GPIO0                                                           0x421C0000U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_0_HSP_LPUART0_CTS_B                                                         0x421C0000U, 0x1U, 0X421C823CU, 0x0U
#define IOMUXC_PIO2_0_HSP_FLEXIO0_FXIO_D00                                                      0x421C0000U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_0_AUDIO_SAI0_TX_DATA0                                                       0x421C0000U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_0_HSP_eFlexPWM0_PWM_A0                                                      0x421C0000U, 0x4U, 0X421C810CU, 0x0U
#define IOMUXC_PIO2_0_MAIN_AHB_SRAMC_SRAMC_DA00                                                 0x421C0000U, 0x5U, 0X421C83A4U, 0x0U
#define IOMUXC_PIO2_0_HSP_QTPM0_CH0                                                             0x421C0000U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_0_MEDIA_DCIF_DATA00                                                         0x421C0000U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_0_HSP_LPI2C0_SDA                                                            0x421C0000U, 0x8U, 0X421C81A4U, 0x0U
#define IOMUXC_PIO2_0_HSP_XBAR0_INOUT00                                                         0x421C0000U, 0xAU, 0X421C82C4U, 0x0U
#define IOMUXC_PIO2_0_HSP_XBAR1_INOUT00                                                         0x421C0000U, 0xBU, 0X421C8334U, 0x0U

#define IOMUXC_PIO2_1_HSP_GPIO0_GPIO1                                                           0x421C0004U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_1_HSP_LPUART0_RTS_B                                                         0x421C0004U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_1_HSP_FLEXIO0_FXIO_D01                                                      0x421C0004U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_1_AUDIO_SAI0_RX_DATA0                                                       0x421C0004U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_1_HSP_eFlexPWM0_PWM_B0                                                      0x421C0004U, 0x4U, 0X421C8118U, 0x0U
#define IOMUXC_PIO2_1_MAIN_AHB_SRAMC_SRAMC_DA01                                                 0x421C0004U, 0x5U, 0X421C83A8U, 0x0U
#define IOMUXC_PIO2_1_HSP_QTPM0_CH1                                                             0x421C0004U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_1_MEDIA_DCIF_DATA01                                                         0x421C0004U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_1_HSP_LPI2C0_SCL                                                            0x421C0004U, 0x8U, 0X421C81A0U, 0x0U
#define IOMUXC_PIO2_1_HSP_XBAR0_INOUT01                                                         0x421C0004U, 0xAU, 0X421C82C8U, 0x0U
#define IOMUXC_PIO2_1_HSP_XBAR1_INOUT01                                                         0x421C0004U, 0xBU, 0X421C8338U, 0x0U

#define IOMUXC_PIO2_2_HSP_GPIO0_GPIO2                                                           0x421C0008U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_2_HSP_LPUART0_TXD                                                           0x421C0008U, 0x1U, 0X421C8244U, 0x0U
#define IOMUXC_PIO2_2_HSP_FLEXIO0_FXIO_D02                                                      0x421C0008U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_2_AUDIO_SAI0_TX_BCLK                                                        0x421C0008U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_2_HSP_eFlexPWM0_PWM_A1                                                      0x421C0008U, 0x4U, 0X421C8110U, 0x0U
#define IOMUXC_PIO2_2_MAIN_AHB_SRAMC_SRAMC_DA02                                                 0x421C0008U, 0x5U, 0X421C83ACU, 0x0U
#define IOMUXC_PIO2_2_HSP_QTPM0_CH2                                                             0x421C0008U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_2_MEDIA_DCIF_DATA02                                                         0x421C0008U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_2_HSP_LPI2C1_SDA                                                            0x421C0008U, 0x8U, 0X421C81ACU, 0x0U
#define IOMUXC_PIO2_2_HSP_XBAR0_INOUT02                                                         0x421C0008U, 0xAU, 0X421C82CCU, 0x0U
#define IOMUXC_PIO2_2_HSP_XBAR1_INOUT02                                                         0x421C0008U, 0xBU, 0X421C833CU, 0x0U

#define IOMUXC_PIO2_3_HSP_GPIO0_GPIO3                                                           0x421C000CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_3_HSP_LPUART0_RXD                                                           0x421C000CU, 0x1U, 0X421C8240U, 0x0U
#define IOMUXC_PIO2_3_HSP_FLEXIO0_FXIO_D03                                                      0x421C000CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_3_AUDIO_SAI0_TX_SYNC                                                        0x421C000CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_3_HSP_eFlexPWM0_PWM_B1                                                      0x421C000CU, 0x4U, 0X421C811CU, 0x0U
#define IOMUXC_PIO2_3_MAIN_AHB_SRAMC_SRAMC_DA03                                                 0x421C000CU, 0x5U, 0X421C83B0U, 0x0U
#define IOMUXC_PIO2_3_HSP_QTPM0_CH3                                                             0x421C000CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_3_MEDIA_DCIF_DATA03                                                         0x421C000CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_3_HSP_LPI2C1_SCL                                                            0x421C000CU, 0x8U, 0X421C81A8U, 0x0U
#define IOMUXC_PIO2_3_HSP_XBAR0_INOUT03                                                         0x421C000CU, 0xAU, 0X421C82D0U, 0x0U
#define IOMUXC_PIO2_3_HSP_XBAR1_INOUT03                                                         0x421C000CU, 0xBU, 0X421C8340U, 0x0U

#define IOMUXC_PIO2_4_HSP_GPIO0_GPIO4                                                           0x421C0010U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_4_HSP_LPUART1_CTS_B                                                         0x421C0010U, 0x1U, 0X421C8248U, 0x0U
#define IOMUXC_PIO2_4_HSP_FLEXIO0_FXIO_D04                                                      0x421C0010U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_4_AUDIO_SAI0_MCLK                                                           0x421C0010U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_4_HSP_eFlexPWM0_PWM_A2                                                      0x421C0010U, 0x4U, 0X421C8114U, 0x0U
#define IOMUXC_PIO2_4_MAIN_AHB_SRAMC_SRAMC_DA04                                                 0x421C0010U, 0x5U, 0X421C83B4U, 0x0U
#define IOMUXC_PIO2_4_HSP_QTPM0_CH4                                                             0x421C0010U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_4_MEDIA_DCIF_DATA04                                                         0x421C0010U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_4_HSP_LPSPI0_PCS0                                                           0x421C0010U, 0x8U, 0X421C81B0U, 0x0U
#define IOMUXC_PIO2_4_MAIN_TRACE3                                                               0x421C0010U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_4_HSP_XBAR0_INOUT04                                                         0x421C0010U, 0xAU, 0X421C82D4U, 0x0U
#define IOMUXC_PIO2_4_HSP_XBAR1_INOUT04                                                         0x421C0010U, 0xBU, 0X421C8344U, 0x0U

#define IOMUXC_PIO2_5_HSP_GPIO0_GPIO5                                                           0x421C0014U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_HSP_LPUART1_RTS_B                                                         0x421C0014U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_HSP_FLEXIO0_FXIO_D05                                                      0x421C0014U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_AUDIO_SAI0_RX_BCLK                                                        0x421C0014U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_HSP_eFlexPWM0_PWM_B2                                                      0x421C0014U, 0x4U, 0X421C8120U, 0x0U
#define IOMUXC_PIO2_5_MAIN_AHB_SRAMC_SRAMC_DA05                                                 0x421C0014U, 0x5U, 0X421C83B8U, 0x0U
#define IOMUXC_PIO2_5_HSP_QTPM0_CH5                                                             0x421C0014U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_MEDIA_DCIF_DATA05                                                         0x421C0014U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_HSP_LPSPI0_SOUT                                                           0x421C0014U, 0x8U, 0X421C81C8U, 0x0U
#define IOMUXC_PIO2_5_MAIN_TRACE2                                                               0x421C0014U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_5_HSP_XBAR0_INOUT05                                                         0x421C0014U, 0xAU, 0X421C82D8U, 0x0U
#define IOMUXC_PIO2_5_HSP_XBAR1_INOUT05                                                         0x421C0014U, 0xBU, 0X421C8348U, 0x0U

#define IOMUXC_PIO2_6_HSP_GPIO0_GPIO6                                                           0x421C0018U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_HSP_LPUART1_TXD                                                           0x421C0018U, 0x1U, 0X421C8250U, 0x0U
#define IOMUXC_PIO2_6_HSP_FLEXIO0_FXIO_D06                                                      0x421C0018U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_AUDIO_SAI0_RX_SYNC                                                        0x421C0018U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_HSP_eFlexPWM0_PWM_A3                                                      0x421C0018U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_MAIN_AHB_SRAMC_SRAMC_DA06                                                 0x421C0018U, 0x5U, 0X421C83BCU, 0x0U
#define IOMUXC_PIO2_6_HSP_QTPM0_CH6                                                             0x421C0018U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_MEDIA_DCIF_DATA06                                                         0x421C0018U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_HSP_LPSPI0_SIN                                                            0x421C0018U, 0x8U, 0X421C81C4U, 0x0U
#define IOMUXC_PIO2_6_MAIN_TRACE1                                                               0x421C0018U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_6_HSP_XBAR0_INOUT06                                                         0x421C0018U, 0xAU, 0X421C82DCU, 0x0U
#define IOMUXC_PIO2_6_HSP_XBAR1_INOUT06                                                         0x421C0018U, 0xBU, 0X421C834CU, 0x0U
#define IOMUXC_PIO2_6_COMM_uSDHC0_TST_TRG                                                       0x421C0018U, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO2_7_HSP_GPIO0_GPIO7                                                           0x421C001CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_HSP_LPUART1_RXD                                                           0x421C001CU, 0x1U, 0X421C824CU, 0x0U
#define IOMUXC_PIO2_7_HSP_FLEXIO0_FXIO_D07                                                      0x421C001CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_AUDIO_SAI0_TX_DATA1                                                       0x421C001CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_HSP_eFlexPWM0_PWM_B3                                                      0x421C001CU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_MAIN_AHB_SRAMC_SRAMC_DA07                                                 0x421C001CU, 0x5U, 0X421C83C0U, 0x0U
#define IOMUXC_PIO2_7_HSP_QTPM0_CH7                                                             0x421C001CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_MEDIA_DCIF_DATA07                                                         0x421C001CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_HSP_LPSPI0_SCK                                                            0x421C001CU, 0x8U, 0X421C81C0U, 0x0U
#define IOMUXC_PIO2_7_MAIN_TRACE0                                                               0x421C001CU, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_7_HSP_XBAR0_INOUT07                                                         0x421C001CU, 0xAU, 0X421C82E0U, 0x0U
#define IOMUXC_PIO2_7_HSP_XBAR1_INOUT07                                                         0x421C001CU, 0xBU, 0X421C8350U, 0x0U
#define IOMUXC_PIO2_7_COMM_uSDHC1_TST_TRG                                                       0x421C001CU, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO2_8_HSP_GPIO0_GPIO8                                                           0x421C0020U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_HSP_LPUART2_TXD                                                           0x421C0020U, 0x1U, 0X421C825CU, 0x0U
#define IOMUXC_PIO2_8_HSP_FLEXIO0_FXIO_D08                                                      0x421C0020U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_AUDIO_SAI0_RX_DATA1                                                       0x421C0020U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_HSP_SINC0_MCLK0                                                           0x421C0020U, 0x4U, 0X421C8294U, 0x0U
#define IOMUXC_PIO2_8_MAIN_AHB_SRAMC_SRAMC_LBB                                                  0x421C0020U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_HSP_SINC0_MCLK_OUT0                                                       0x421C0020U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_MEDIA_DCIF_DATA08                                                         0x421C0020U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_HSP_LPSPI0_PCS1                                                           0x421C0020U, 0x8U, 0X421C81B4U, 0x0U
#define IOMUXC_PIO2_8_MAIN_TRACE_CLK                                                            0x421C0020U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_8_HSP_XBAR0_INOUT08                                                         0x421C0020U, 0xAU, 0X421C82E4U, 0x0U
#define IOMUXC_PIO2_8_HSP_XBAR1_INOUT08                                                         0x421C0020U, 0xBU, 0X421C8354U, 0x0U

#define IOMUXC_PIO2_9_HSP_GPIO0_GPIO9                                                           0x421C0024U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_9_HSP_LPUART2_RXD                                                           0x421C0024U, 0x1U, 0X421C8258U, 0x0U
#define IOMUXC_PIO2_9_HSP_FLEXIO0_FXIO_D09                                                      0x421C0024U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_9_AUDIO_SAI0_TX_DATA2                                                       0x421C0024U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_9_HSP_SINC0_MCLK1                                                           0x421C0024U, 0x4U, 0X421C8298U, 0x0U
#define IOMUXC_PIO2_9_MAIN_AHB_SRAMC_SRAMC_DA08                                                 0x421C0024U, 0x5U, 0X421C83C4U, 0x0U
#define IOMUXC_PIO2_9_HSP_SINC0_MCLK_OUT1                                                       0x421C0024U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_9_MEDIA_DCIF_DATA09                                                         0x421C0024U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_9_HSP_LPSPI0_PCS2                                                           0x421C0024U, 0x8U, 0X421C81B8U, 0x0U
#define IOMUXC_PIO2_9_HSP_XBAR0_INOUT09                                                         0x421C0024U, 0xAU, 0X421C82E8U, 0x0U
#define IOMUXC_PIO2_9_HSP_XBAR1_INOUT09                                                         0x421C0024U, 0xBU, 0X421C8358U, 0x0U

#define IOMUXC_PIO2_10_HSP_GPIO0_GPIO10                                                         0x421C0028U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_10_HSP_LPUART2_CTS_B                                                        0x421C0028U, 0x1U, 0X421C8254U, 0x0U
#define IOMUXC_PIO2_10_HSP_FLEXIO0_FXIO_D10                                                     0x421C0028U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_10_AUDIO_SAI0_RX_DATA2                                                      0x421C0028U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_10_HSP_SINC0_MCLK2                                                          0x421C0028U, 0x4U, 0X421C829CU, 0x0U
#define IOMUXC_PIO2_10_MAIN_AHB_SRAMC_SRAMC_DA09                                                0x421C0028U, 0x5U, 0X421C83C8U, 0x0U
#define IOMUXC_PIO2_10_HSP_SINC0_MCLK_OUT2                                                      0x421C0028U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_10_MEDIA_DCIF_DATA10                                                        0x421C0028U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_10_HSP_LPSPI0_PCS3                                                          0x421C0028U, 0x8U, 0X421C81BCU, 0x0U
#define IOMUXC_PIO2_10_HSP_XBAR0_INOUT10                                                        0x421C0028U, 0xAU, 0X421C82ECU, 0x0U
#define IOMUXC_PIO2_10_HSP_XBAR1_INOUT10                                                        0x421C0028U, 0xBU, 0X421C835CU, 0x0U

#define IOMUXC_PIO2_11_HSP_GPIO0_GPIO11                                                         0x421C002CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_11_HSP_LPUART2_RTS_B                                                        0x421C002CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_11_HSP_FLEXIO0_FXIO_D11                                                     0x421C002CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_11_AUDIO_SAI0_TX_DATA3                                                      0x421C002CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_11_HSP_SINC0_MCLK3                                                          0x421C002CU, 0x4U, 0X421C82A0U, 0x0U
#define IOMUXC_PIO2_11_MAIN_AHB_SRAMC_SRAMC_DA10                                                0x421C002CU, 0x5U, 0X421C83CCU, 0x0U
#define IOMUXC_PIO2_11_MEDIA_DCIF_DATA11                                                        0x421C002CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_11_HSP_XBAR0_INOUT11                                                        0x421C002CU, 0xAU, 0X421C82F0U, 0x0U
#define IOMUXC_PIO2_11_HSP_XBAR1_INOUT11                                                        0x421C002CU, 0xBU, 0X421C8360U, 0x0U

#define IOMUXC_PIO2_12_HSP_GPIO0_GPIO12                                                         0x421C0030U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_12_HSP_LPUART3_TXD                                                          0x421C0030U, 0x1U, 0X421C8268U, 0x0U
#define IOMUXC_PIO2_12_HSP_FLEXIO0_FXIO_D12                                                     0x421C0030U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_12_AUDIO_SAI0_RX_DATA3                                                      0x421C0030U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_12_HSP_SINC0_MBIT0                                                          0x421C0030U, 0x4U, 0X421C8284U, 0x0U
#define IOMUXC_PIO2_12_MAIN_AHB_SRAMC_SRAMC_DA11                                                0x421C0030U, 0x5U, 0X421C83D0U, 0x0U
#define IOMUXC_PIO2_12_MEDIA_DCIF_DATA12                                                        0x421C0030U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_12_HSP_LPI2C0_SDA                                                           0x421C0030U, 0x8U, 0X421C81A4U, 0x1U
#define IOMUXC_PIO2_12_HSP_XBAR0_INOUT12                                                        0x421C0030U, 0xAU, 0X421C82F4U, 0x0U
#define IOMUXC_PIO2_12_HSP_XBAR1_INOUT12                                                        0x421C0030U, 0xBU, 0X421C8364U, 0x0U

#define IOMUXC_PIO2_13_HSP_GPIO0_GPIO13                                                         0x421C0034U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_13_HSP_LPUART3_RXD                                                          0x421C0034U, 0x1U, 0X421C8264U, 0x0U
#define IOMUXC_PIO2_13_HSP_FLEXIO0_FXIO_D13                                                     0x421C0034U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_13_WAKE_EWM_OUT_B                                                           0x421C0034U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_13_HSP_SINC0_MBIT1                                                          0x421C0034U, 0x4U, 0X421C8288U, 0x0U
#define IOMUXC_PIO2_13_MAIN_AHB_SRAMC_SRAMC_DA12                                                0x421C0034U, 0x5U, 0X421C83D4U, 0x0U
#define IOMUXC_PIO2_13_HSP_eFlexPWM0_PWM_X0                                                     0x421C0034U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_13_MEDIA_DCIF_DATA13                                                        0x421C0034U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_13_HSP_LPI2C0_SCL                                                           0x421C0034U, 0x8U, 0X421C81A0U, 0x1U
#define IOMUXC_PIO2_13_HSP_XBAR0_INOUT13                                                        0x421C0034U, 0xAU, 0X421C82F8U, 0x0U
#define IOMUXC_PIO2_13_HSP_XBAR1_INOUT13                                                        0x421C0034U, 0xBU, 0X421C8368U, 0x0U

#define IOMUXC_PIO2_14_HSP_GPIO0_GPIO14                                                         0x421C0038U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_14_HSP_LPUART3_CTS_B                                                        0x421C0038U, 0x1U, 0X421C8260U, 0x0U
#define IOMUXC_PIO2_14_HSP_FLEXIO0_FXIO_D14                                                     0x421C0038U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_14_AUDIO_MICFIL_PDM_CLK                                                     0x421C0038U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_14_HSP_SINC0_MBIT2                                                          0x421C0038U, 0x4U, 0X421C828CU, 0x0U
#define IOMUXC_PIO2_14_MAIN_AHB_SRAMC_SRAMC_DA13                                                0x421C0038U, 0x5U, 0X421C83D8U, 0x0U
#define IOMUXC_PIO2_14_HSP_eFlexPWM0_PWM_X1                                                     0x421C0038U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_14_MEDIA_DCIF_DATA14                                                        0x421C0038U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_14_HSP_FlexCAN0_CAN_TX                                                      0x421C0038U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_14_HSP_XBAR0_INOUT14                                                        0x421C0038U, 0xAU, 0X421C82FCU, 0x0U
#define IOMUXC_PIO2_14_HSP_XBAR1_INOUT14                                                        0x421C0038U, 0xBU, 0X421C836CU, 0x0U

#define IOMUXC_PIO2_15_HSP_GPIO0_GPIO15                                                         0x421C003CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_15_HSP_LPUART3_RTS_B                                                        0x421C003CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_15_HSP_FLEXIO0_FXIO_D15                                                     0x421C003CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_15_AUDIO_MICFIL_PDM_DATA45                                                  0x421C003CU, 0x3U, 0X421C8008U, 0x0U
#define IOMUXC_PIO2_15_HSP_SINC0_MBIT3                                                          0x421C003CU, 0x4U, 0X421C8290U, 0x0U
#define IOMUXC_PIO2_15_MAIN_AHB_SRAMC_SRAMC_DA14                                                0x421C003CU, 0x5U, 0X421C83DCU, 0x0U
#define IOMUXC_PIO2_15_HSP_eFlexPWM0_PWM_X2                                                     0x421C003CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_15_MEDIA_DCIF_DATA15                                                        0x421C003CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_15_HSP_FlexCAN0_CAN_RX                                                      0x421C003CU, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_15_HSP_XBAR0_INOUT15                                                        0x421C003CU, 0xAU, 0X421C8300U, 0x0U
#define IOMUXC_PIO2_15_HSP_XBAR1_INOUT15                                                        0x421C003CU, 0xBU, 0X421C8370U, 0x0U

#define IOMUXC_PIO2_16_HSP_GPIO0_GPIO16                                                         0x421C0040U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_16_HSP_LPUART4_TXD                                                          0x421C0040U, 0x1U, 0X421C8274U, 0x0U
#define IOMUXC_PIO2_16_HSP_FLEXIO0_FXIO_D16                                                     0x421C0040U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_16_AUDIO_MICFIL_PDM_DATA23                                                  0x421C0040U, 0x3U, 0X421C8004U, 0x0U
#define IOMUXC_PIO2_16_HSP_SINC0_BREAK                                                          0x421C0040U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_16_MAIN_AHB_SRAMC_SRAMC_DA15                                                0x421C0040U, 0x5U, 0X421C83E0U, 0x0U
#define IOMUXC_PIO2_16_HSP_eFlexPWM0_PWM_X3                                                     0x421C0040U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_16_MEDIA_DCIF_DATA16                                                        0x421C0040U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_16_HSP_FlexCAN1_CAN_TX                                                      0x421C0040U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_16_HSP_XBAR0_INOUT16                                                        0x421C0040U, 0xAU, 0X421C8304U, 0x0U
#define IOMUXC_PIO2_16_HSP_XBAR1_INOUT16                                                        0x421C0040U, 0xBU, 0X421C8374U, 0x0U

#define IOMUXC_PIO2_17_HSP_GPIO0_GPIO17                                                         0x421C0044U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_17_HSP_LPUART4_RXD                                                          0x421C0044U, 0x1U, 0X421C8270U, 0x0U
#define IOMUXC_PIO2_17_HSP_FLEXIO0_FXIO_D17                                                     0x421C0044U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_17_AUDIO_MICFIL_PDM_DATA01                                                  0x421C0044U, 0x3U, 0X421C8000U, 0x0U
#define IOMUXC_PIO2_17_AUDIO_MQS_MQS_LEFT                                                       0x421C0044U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_17_MAIN_AHB_SRAMC_SRAMC_UBB                                                 0x421C0044U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_17_AUDIO_SAI1_MCLK                                                          0x421C0044U, 0x6U, 0X421C800CU, 0x0U
#define IOMUXC_PIO2_17_MEDIA_DCIF_DATA17                                                        0x421C0044U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_17_HSP_FlexCAN1_CAN_RX                                                      0x421C0044U, 0x8U, 0X421C8104U, 0x0U
#define IOMUXC_PIO2_17_HSP_XBAR0_INOUT17                                                        0x421C0044U, 0xAU, 0X421C8308U, 0x0U
#define IOMUXC_PIO2_17_HSP_XBAR1_INOUT17                                                        0x421C0044U, 0xBU, 0X421C8378U, 0x0U

#define IOMUXC_PIO2_18_HSP_GPIO0_GPIO18                                                         0x421C0048U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_18_HSP_LPUART4_CTS_B                                                        0x421C0048U, 0x1U, 0X421C826CU, 0x0U
#define IOMUXC_PIO2_18_HSP_FLEXIO0_FXIO_D18                                                     0x421C0048U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_18_AUDIO_MQS_MQS_RIGHT                                                      0x421C0048U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_18_MAIN_AHB_SRAMC_SRAMC_WEB                                                 0x421C0048U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_18_AUDIO_SAI1_TX_BCLK                                                       0x421C0048U, 0x6U, 0X421C8020U, 0x0U
#define IOMUXC_PIO2_18_MEDIA_DCIF_DATA18                                                        0x421C0048U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_18_HSP_XBAR0_INOUT18                                                        0x421C0048U, 0xAU, 0X421C830CU, 0x0U
#define IOMUXC_PIO2_18_HSP_XBAR1_INOUT18                                                        0x421C0048U, 0xBU, 0X421C837CU, 0x0U

#define IOMUXC_PIO2_19_HSP_GPIO0_GPIO19                                                         0x421C004CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_19_HSP_LPUART4_RTS_B                                                        0x421C004CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_19_HSP_FLEXIO0_FXIO_D19                                                     0x421C004CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_19_HSP_eFlexPWM1_PWM_X0                                                     0x421C004CU, 0x4U, 0X421C8144U, 0x0U
#define IOMUXC_PIO2_19_MAIN_AHB_SRAMC_SRAMC_OEB                                                 0x421C004CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_19_AUDIO_SAI1_TX_SYNC                                                       0x421C004CU, 0x6U, 0X421C8024U, 0x0U
#define IOMUXC_PIO2_19_MEDIA_DCIF_DATA19                                                        0x421C004CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_19_HSP_XBAR0_INOUT19                                                        0x421C004CU, 0xAU, 0X421C8310U, 0x0U
#define IOMUXC_PIO2_19_HSP_XBAR1_INOUT19                                                        0x421C004CU, 0xBU, 0X421C8380U, 0x0U

#define IOMUXC_PIO2_20_HSP_GPIO0_GPIO20                                                         0x421C0050U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_20_HSP_LPUART5_TXD                                                          0x421C0050U, 0x1U, 0X421C8280U, 0x0U
#define IOMUXC_PIO2_20_HSP_FLEXIO0_FXIO_D20                                                     0x421C0050U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_20_COMM_USB0_PWR                                                            0x421C0050U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_20_HSP_eFlexPWM1_PWM_A3                                                     0x421C0050U, 0x4U, 0X421C8130U, 0x0U
#define IOMUXC_PIO2_20_MAIN_AHB_SRAMC_SRAMC_WP0                                                 0x421C0050U, 0x5U, 0X421C83E4U, 0x0U
#define IOMUXC_PIO2_20_AUDIO_SAI1_TX_DATA0                                                      0x421C0050U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_20_MEDIA_DCIF_DATA20                                                        0x421C0050U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_20_HSP_XBAR0_INOUT20                                                        0x421C0050U, 0xAU, 0X421C8314U, 0x0U
#define IOMUXC_PIO2_20_HSP_XBAR1_INOUT20                                                        0x421C0050U, 0xBU, 0X421C8384U, 0x0U

#define IOMUXC_PIO2_21_HSP_GPIO0_GPIO21                                                         0x421C0054U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_21_HSP_LPUART5_RXD                                                          0x421C0054U, 0x1U, 0X421C827CU, 0x0U
#define IOMUXC_PIO2_21_HSP_FLEXIO0_FXIO_D21                                                     0x421C0054U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_21_COMM_USB0_OC                                                             0x421C0054U, 0x3U, 0X421C80A4U, 0x0U
#define IOMUXC_PIO2_21_HSP_eFlexPWM1_PWM_B3                                                     0x421C0054U, 0x4U, 0X421C8140U, 0x0U
#define IOMUXC_PIO2_21_MAIN_AHB_SRAMC_SRAMC_WP1                                                 0x421C0054U, 0x5U, 0X421C83E8U, 0x0U
#define IOMUXC_PIO2_21_AUDIO_SAI1_RX_DATA0                                                      0x421C0054U, 0x6U, 0X421C8014U, 0x0U
#define IOMUXC_PIO2_21_MEDIA_DCIF_DATA21                                                        0x421C0054U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_21_HSP_LPSPI1_PCS3                                                          0x421C0054U, 0x9U, 0X421C81D8U, 0x0U
#define IOMUXC_PIO2_21_HSP_XBAR0_INOUT21                                                        0x421C0054U, 0xAU, 0X421C8318U, 0x0U
#define IOMUXC_PIO2_21_HSP_XBAR1_INOUT21                                                        0x421C0054U, 0xBU, 0X421C8388U, 0x0U

#define IOMUXC_PIO2_22_HSP_GPIO0_GPIO22                                                         0x421C0058U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_22_HSP_LPUART5_CTS_B                                                        0x421C0058U, 0x1U, 0X421C8278U, 0x0U
#define IOMUXC_PIO2_22_HSP_FLEXIO0_FXIO_D22                                                     0x421C0058U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_22_COMM_USB0_ID                                                             0x421C0058U, 0x3U, 0X421C80A8U, 0x0U
#define IOMUXC_PIO2_22_HSP_eFlexPWM1_PWM_A2                                                     0x421C0058U, 0x4U, 0X421C812CU, 0x0U
#define IOMUXC_PIO2_22_MAIN_XSPI0_ECS                                                           0x421C0058U, 0x5U, 0X421C83ECU, 0x0U
#define IOMUXC_PIO2_22_AUDIO_SAI1_MCLK                                                          0x421C0058U, 0x6U, 0X421C800CU, 0x1U
#define IOMUXC_PIO2_22_MEDIA_DCIF_DATA22                                                        0x421C0058U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_22_HSP_LPSPI1_PCS2                                                          0x421C0058U, 0x9U, 0X421C81D4U, 0x0U
#define IOMUXC_PIO2_22_HSP_XBAR0_INOUT22                                                        0x421C0058U, 0xAU, 0X421C831CU, 0x0U
#define IOMUXC_PIO2_22_HSP_XBAR1_INOUT22                                                        0x421C0058U, 0xBU, 0X421C838CU, 0x0U

#define IOMUXC_PIO2_23_HSP_GPIO0_GPIO23                                                         0x421C005CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_23_HSP_LPUART5_RTS_B                                                        0x421C005CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_23_HSP_FLEXIO0_FXIO_D23                                                     0x421C005CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_23_HSP_eFlexPWM1_PWM_B2                                                     0x421C005CU, 0x4U, 0X421C813CU, 0x0U
#define IOMUXC_PIO2_23_HSP_eFlexPWM1_PWM_X0                                                     0x421C005CU, 0x5U, 0X421C8144U, 0x1U
#define IOMUXC_PIO2_23_AUDIO_SAI1_RX_BCLK                                                       0x421C005CU, 0x6U, 0X421C8010U, 0x0U
#define IOMUXC_PIO2_23_MEDIA_DCIF_DATA23                                                        0x421C005CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_23_HSP_LPSPI1_PCS1                                                          0x421C005CU, 0x9U, 0X421C81D0U, 0x0U
#define IOMUXC_PIO2_23_HSP_XBAR0_INOUT23                                                        0x421C005CU, 0xAU, 0X421C8320U, 0x0U
#define IOMUXC_PIO2_23_HSP_XBAR1_INOUT23                                                        0x421C005CU, 0xBU, 0X421C8390U, 0x0U

#define IOMUXC_PIO2_24_HSP_GPIO0_GPIO24                                                         0x421C0060U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_24_HSP_LPI2C1_SDA                                                           0x421C0060U, 0x1U, 0X421C81ACU, 0x1U
#define IOMUXC_PIO2_24_HSP_FLEXIO0_FXIO_D24                                                     0x421C0060U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_24_HSP_I3C_SDA                                                              0x421C0060U, 0x3U, 0X421C819CU, 0x0U
#define IOMUXC_PIO2_24_HSP_eFlexPWM1_PWM_A1                                                     0x421C0060U, 0x4U, 0X421C8128U, 0x0U
#define IOMUXC_PIO2_24_AUDIO_SPDIF_IN                                                           0x421C0060U, 0x5U, 0X421C8044U, 0x0U
#define IOMUXC_PIO2_24_AUDIO_SAI1_RX_SYNC                                                       0x421C0060U, 0x6U, 0X421C801CU, 0x0U
#define IOMUXC_PIO2_24_MEDIA_DCIF_HSYNC                                                         0x421C0060U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_24_HSP_LPSPI1_PCS0                                                          0x421C0060U, 0x9U, 0X421C81CCU, 0x0U
#define IOMUXC_PIO2_24_HSP_XBAR0_INOUT24                                                        0x421C0060U, 0xAU, 0X421C8324U, 0x0U
#define IOMUXC_PIO2_24_HSP_XBAR1_INOUT24                                                        0x421C0060U, 0xBU, 0X421C8394U, 0x0U

#define IOMUXC_PIO2_25_HSP_GPIO0_GPIO25                                                         0x421C0064U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_25_HSP_LPI2C1_SCL                                                           0x421C0064U, 0x1U, 0X421C81A8U, 0x1U
#define IOMUXC_PIO2_25_HSP_FLEXIO0_FXIO_D25                                                     0x421C0064U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_25_HSP_I3C_SCL                                                              0x421C0064U, 0x3U, 0X421C8198U, 0x0U
#define IOMUXC_PIO2_25_HSP_eFlexPWM1_PWM_B1                                                     0x421C0064U, 0x4U, 0X421C8138U, 0x0U
#define IOMUXC_PIO2_25_AUDIO_SPDIF_OUT                                                          0x421C0064U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_25_AUDIO_SAI1_TX_DATA1                                                      0x421C0064U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_25_MEDIA_DCIF_VSYNC                                                         0x421C0064U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_25_HSP_FlexCAN1_CAN_TX                                                      0x421C0064U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_25_HSP_LPSPI1_SCK                                                           0x421C0064U, 0x9U, 0X421C81DCU, 0x0U
#define IOMUXC_PIO2_25_HSP_XBAR0_INOUT25                                                        0x421C0064U, 0xAU, 0X421C8328U, 0x0U
#define IOMUXC_PIO2_25_HSP_XBAR1_INOUT25                                                        0x421C0064U, 0xBU, 0X421C8398U, 0x0U

#define IOMUXC_PIO2_26_HSP_GPIO0_GPIO26                                                         0x421C0068U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_26_HSP_FLEXIO0_FXIO_D26                                                     0x421C0068U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_26_HSP_I3C_PUR                                                              0x421C0068U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_26_HSP_eFlexPWM1_PWM_A0                                                     0x421C0068U, 0x4U, 0X421C8124U, 0x0U
#define IOMUXC_PIO2_26_AUDIO_MQS_MQS_LEFT                                                       0x421C0068U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_26_AUDIO_SAI1_RX_DATA1                                                      0x421C0068U, 0x6U, 0X421C8018U, 0x0U
#define IOMUXC_PIO2_26_MEDIA_DCIF_DE                                                            0x421C0068U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_26_HSP_FlexCAN1_CAN_RX                                                      0x421C0068U, 0x8U, 0X421C8104U, 0x1U
#define IOMUXC_PIO2_26_HSP_LPSPI1_SIN                                                           0x421C0068U, 0x9U, 0X421C81E0U, 0x0U
#define IOMUXC_PIO2_26_HSP_XBAR0_INOUT26                                                        0x421C0068U, 0xAU, 0X421C832CU, 0x0U
#define IOMUXC_PIO2_26_HSP_XBAR1_INOUT26                                                        0x421C0068U, 0xBU, 0X421C839CU, 0x0U

#define IOMUXC_PIO2_27_HSP_GPIO0_GPIO27                                                         0x421C006CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_27_HSP_FLEXIO0_FXIO_D27                                                     0x421C006CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_27_COMM_CCM_CLKREF_25M                                                      0x421C006CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_27_HSP_eFlexPWM1_PWM_B0                                                     0x421C006CU, 0x4U, 0X421C8134U, 0x0U
#define IOMUXC_PIO2_27_AUDIO_MQS_MQS_RIGHT                                                      0x421C006CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_27_MEDIA_DCIF_PIXEL_CLK                                                     0x421C006CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO2_27_HSP_LPSPI1_SOUT                                                          0x421C006CU, 0x9U, 0X421C81E4U, 0x0U
#define IOMUXC_PIO2_27_HSP_XBAR0_INOUT27                                                        0x421C006CU, 0xAU, 0X421C8330U, 0x0U
#define IOMUXC_PIO2_27_HSP_XBAR1_INOUT27                                                        0x421C006CU, 0xBU, 0X421C83A0U, 0x0U

#define IOMUXC_PIO3_0_HSP_GPIO1_GPIO0                                                           0x421C0080U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_0_COMM_ENET_QOS_TX_CLK_IO                                                   0x421C0080U, 0x1U, 0X421C8050U, 0x0U
#define IOMUXC_PIO3_0_HSP_FLEXIO1_FXIO_D00                                                      0x421C0080U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_0_MEDIA_CSI_DATA00                                                          0x421C0080U, 0x4U, 0X421C83F0U, 0x0U
#define IOMUXC_PIO3_0_MAIN_AHB_SRAMC_SRAMC_ADDR00                                               0x421C0080U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_0_MEDIA_DCIF_DATA00                                                         0x421C0080U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_0_MEDIA_DCIF_DBI_AB_DATA00                                                  0x421C0080U, 0x7U, 0X421C843CU, 0x0U
#define IOMUXC_PIO3_0_HSP_eFlexPWM1_PWM_A0                                                      0x421C0080U, 0x8U, 0X421C8124U, 0x1U
#define IOMUXC_PIO3_0_COMM_ENET_QOS_REF_CLK1                                                    0x421C0080U, 0x9U, 0X421C8048U, 0x0U
#define IOMUXC_PIO3_0_HSP_XBAR0_INOUT00                                                         0x421C0080U, 0xAU, 0X421C82C4U, 0x1U
#define IOMUXC_PIO3_0_HSP_XBAR1_INOUT00                                                         0x421C0080U, 0xBU, 0X421C8334U, 0x1U

#define IOMUXC_PIO3_1_HSP_GPIO1_GPIO1                                                           0x421C0084U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_1_COMM_ENET_QOS_TX_DATA0                                                    0x421C0084U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_1_HSP_FLEXIO1_FXIO_D01                                                      0x421C0084U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_1_MEDIA_CSI_DATA01                                                          0x421C0084U, 0x4U, 0X421C83F4U, 0x0U
#define IOMUXC_PIO3_1_MAIN_AHB_SRAMC_SRAMC_ADDR01                                               0x421C0084U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_1_MEDIA_DCIF_DATA01                                                         0x421C0084U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_1_MEDIA_DCIF_DBI_AB_DATA01                                                  0x421C0084U, 0x7U, 0X421C8440U, 0x0U
#define IOMUXC_PIO3_1_HSP_eFlexPWM1_PWM_B0                                                      0x421C0084U, 0x8U, 0X421C8134U, 0x1U
#define IOMUXC_PIO3_1_HSP_XBAR0_INOUT01                                                         0x421C0084U, 0xAU, 0X421C82C8U, 0x1U
#define IOMUXC_PIO3_1_HSP_XBAR1_INOUT01                                                         0x421C0084U, 0xBU, 0X421C8338U, 0x1U

#define IOMUXC_PIO3_2_HSP_GPIO1_GPIO2                                                           0x421C0088U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_2_COMM_ENET_QOS_TX_DATA1                                                    0x421C0088U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_2_HSP_FLEXIO1_FXIO_D02                                                      0x421C0088U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_2_COMM_TENBASET_PHY0_TX                                                     0x421C0088U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_2_MEDIA_CSI_DATA02                                                          0x421C0088U, 0x4U, 0X421C83F8U, 0x0U
#define IOMUXC_PIO3_2_MAIN_AHB_SRAMC_SRAMC_ADDR02                                               0x421C0088U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_2_MEDIA_DCIF_DATA02                                                         0x421C0088U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_2_MEDIA_DCIF_DBI_AB_DATA02                                                  0x421C0088U, 0x7U, 0X421C8444U, 0x0U
#define IOMUXC_PIO3_2_HSP_eFlexPWM1_PWM_A1                                                      0x421C0088U, 0x8U, 0X421C8128U, 0x1U
#define IOMUXC_PIO3_2_HSP_LPUART0_TXD                                                           0x421C0088U, 0x9U, 0X421C8244U, 0x1U
#define IOMUXC_PIO3_2_HSP_XBAR0_INOUT02                                                         0x421C0088U, 0xAU, 0X421C82CCU, 0x1U
#define IOMUXC_PIO3_2_HSP_XBAR1_INOUT02                                                         0x421C0088U, 0xBU, 0X421C833CU, 0x1U

#define IOMUXC_PIO3_3_HSP_GPIO1_GPIO3                                                           0x421C008CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_3_COMM_ENET_QOS_TX_EN                                                       0x421C008CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_3_HSP_FLEXIO1_FXIO_D03                                                      0x421C008CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_3_MAIN_XSPI0_ECS                                                            0x421C008CU, 0x3U, 0X421C83ECU, 0x1U
#define IOMUXC_PIO3_3_MEDIA_CSI_DATA03                                                          0x421C008CU, 0x4U, 0X421C83FCU, 0x0U
#define IOMUXC_PIO3_3_MAIN_AHB_SRAMC_SRAMC_ADDR03                                               0x421C008CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_3_MEDIA_DCIF_DATA03                                                         0x421C008CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_3_MEDIA_DCIF_DBI_AB_DATA03                                                  0x421C008CU, 0x7U, 0X421C8448U, 0x0U
#define IOMUXC_PIO3_3_HSP_eFlexPWM1_PWM_B1                                                      0x421C008CU, 0x8U, 0X421C8138U, 0x1U
#define IOMUXC_PIO3_3_HSP_LPUART0_RXD                                                           0x421C008CU, 0x9U, 0X421C8240U, 0x1U
#define IOMUXC_PIO3_3_HSP_XBAR0_INOUT03                                                         0x421C008CU, 0xAU, 0X421C82D0U, 0x1U
#define IOMUXC_PIO3_3_HSP_XBAR1_INOUT03                                                         0x421C008CU, 0xBU, 0X421C8340U, 0x1U

#define IOMUXC_PIO3_4_HSP_GPIO1_GPIO4                                                           0x421C0090U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_4_COMM_ENET_QOS_RX_DATA0                                                    0x421C0090U, 0x1U, 0X421C8060U, 0x0U
#define IOMUXC_PIO3_4_HSP_FLEXIO1_FXIO_D04                                                      0x421C0090U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_4_AUDIO_MICFIL_PDM_CLK                                                      0x421C0090U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_4_MEDIA_CSI_DATA04                                                          0x421C0090U, 0x4U, 0X421C8400U, 0x0U
#define IOMUXC_PIO3_4_MAIN_AHB_SRAMC_SRAMC_ADDR04                                               0x421C0090U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_4_MEDIA_DCIF_DATA04                                                         0x421C0090U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_4_MEDIA_DCIF_DBI_AB_DATA04                                                  0x421C0090U, 0x7U, 0X421C844CU, 0x0U
#define IOMUXC_PIO3_4_HSP_eFlexPWM1_PWM_A2                                                      0x421C0090U, 0x8U, 0X421C812CU, 0x1U
#define IOMUXC_PIO3_4_HSP_LPUART0_CTS_B                                                         0x421C0090U, 0x9U, 0X421C823CU, 0x1U
#define IOMUXC_PIO3_4_HSP_XBAR0_INOUT04                                                         0x421C0090U, 0xAU, 0X421C82D4U, 0x1U
#define IOMUXC_PIO3_4_HSP_XBAR1_INOUT04                                                         0x421C0090U, 0xBU, 0X421C8344U, 0x1U

#define IOMUXC_PIO3_5_HSP_GPIO1_GPIO5                                                           0x421C0094U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_5_COMM_ENET_QOS_RX_DATA1                                                    0x421C0094U, 0x1U, 0X421C8064U, 0x0U
#define IOMUXC_PIO3_5_HSP_FLEXIO1_FXIO_D05                                                      0x421C0094U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_5_AUDIO_MICFIL_PDM_DATA45                                                   0x421C0094U, 0x3U, 0X421C8008U, 0x1U
#define IOMUXC_PIO3_5_MEDIA_CSI_DATA05                                                          0x421C0094U, 0x4U, 0X421C8404U, 0x0U
#define IOMUXC_PIO3_5_MAIN_AHB_SRAMC_SRAMC_ADDR05                                               0x421C0094U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_5_MEDIA_DCIF_DATA05                                                         0x421C0094U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_5_MEDIA_DCIF_DBI_AB_DATA05                                                  0x421C0094U, 0x7U, 0X421C8450U, 0x0U
#define IOMUXC_PIO3_5_HSP_eFlexPWM1_PWM_B2                                                      0x421C0094U, 0x8U, 0X421C813CU, 0x1U
#define IOMUXC_PIO3_5_HSP_LPUART0_RTS_B                                                         0x421C0094U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_5_HSP_XBAR0_INOUT05                                                         0x421C0094U, 0xAU, 0X421C82D8U, 0x1U
#define IOMUXC_PIO3_5_HSP_XBAR1_INOUT05                                                         0x421C0094U, 0xBU, 0X421C8348U, 0x1U

#define IOMUXC_PIO3_6_HSP_GPIO1_GPIO6                                                           0x421C0098U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_6_COMM_ENET_QOS_CRS                                                         0x421C0098U, 0x1U, 0X421C805CU, 0x0U
#define IOMUXC_PIO3_6_HSP_FLEXIO1_FXIO_D06                                                      0x421C0098U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_6_AUDIO_MICFIL_PDM_DATA23                                                   0x421C0098U, 0x3U, 0X421C8004U, 0x1U
#define IOMUXC_PIO3_6_MEDIA_CSI_DATA06                                                          0x421C0098U, 0x4U, 0X421C8408U, 0x0U
#define IOMUXC_PIO3_6_MAIN_AHB_SRAMC_SRAMC_ADDR06                                               0x421C0098U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_6_MEDIA_DCIF_DATA06                                                         0x421C0098U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_6_MEDIA_DCIF_DBI_AB_DATA06                                                  0x421C0098U, 0x7U, 0X421C8454U, 0x0U
#define IOMUXC_PIO3_6_HSP_eFlexPWM1_PWM_A3                                                      0x421C0098U, 0x8U, 0X421C8130U, 0x1U
#define IOMUXC_PIO3_6_HSP_LPUART1_CTS_B                                                         0x421C0098U, 0x9U, 0X421C8248U, 0x1U
#define IOMUXC_PIO3_6_HSP_XBAR0_INOUT06                                                         0x421C0098U, 0xAU, 0X421C82DCU, 0x1U
#define IOMUXC_PIO3_6_HSP_XBAR1_INOUT06                                                         0x421C0098U, 0xBU, 0X421C834CU, 0x1U

#define IOMUXC_PIO3_7_HSP_GPIO1_GPIO7                                                           0x421C009CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_7_COMM_ENET_QOS_RX_ER                                                       0x421C009CU, 0x1U, 0X421C8074U, 0x0U
#define IOMUXC_PIO3_7_HSP_FLEXIO1_FXIO_D07                                                      0x421C009CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_7_AUDIO_MICFIL_PDM_DATA01                                                   0x421C009CU, 0x3U, 0X421C8000U, 0x1U
#define IOMUXC_PIO3_7_MEDIA_CSI_DATA07                                                          0x421C009CU, 0x4U, 0X421C840CU, 0x0U
#define IOMUXC_PIO3_7_MAIN_AHB_SRAMC_SRAMC_ADDR07                                               0x421C009CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_7_MEDIA_DCIF_DATA07                                                         0x421C009CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_7_MEDIA_DCIF_DBI_AB_DATA07                                                  0x421C009CU, 0x7U, 0X421C8458U, 0x0U
#define IOMUXC_PIO3_7_HSP_eFlexPWM1_PWM_B3                                                      0x421C009CU, 0x8U, 0X421C8140U, 0x1U
#define IOMUXC_PIO3_7_HSP_LPUART1_RTS_B                                                         0x421C009CU, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_7_HSP_XBAR0_INOUT07                                                         0x421C009CU, 0xAU, 0X421C82E0U, 0x1U
#define IOMUXC_PIO3_7_HSP_XBAR1_INOUT07                                                         0x421C009CU, 0xBU, 0X421C8350U, 0x1U

#define IOMUXC_PIO3_8_HSP_GPIO1_GPIO8                                                           0x421C00A0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_8_COMM_ENET_QOS_MDIO                                                        0x421C00A0U, 0x1U, 0X421C8054U, 0x0U
#define IOMUXC_PIO3_8_HSP_FLEXIO1_FXIO_D08                                                      0x421C00A0U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_8_COMM_TENBASET_PHY0_ED                                                     0x421C00A0U, 0x3U, 0X421C80D0U, 0x0U
#define IOMUXC_PIO3_8_MEDIA_CSI_DATA08                                                          0x421C00A0U, 0x4U, 0X421C8410U, 0x0U
#define IOMUXC_PIO3_8_MAIN_AHB_SRAMC_SRAMC_ADDR08                                               0x421C00A0U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_8_MEDIA_DCIF_DATA08                                                         0x421C00A0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_8_MEDIA_DCIF_DBI_AB_DATA08                                                  0x421C00A0U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_8_HSP_LPI2C1_SDA                                                            0x421C00A0U, 0x8U, 0X421C81ACU, 0x2U
#define IOMUXC_PIO3_8_HSP_LPUART1_TXD                                                           0x421C00A0U, 0x9U, 0X421C8250U, 0x1U
#define IOMUXC_PIO3_8_HSP_XBAR0_INOUT08                                                         0x421C00A0U, 0xAU, 0X421C82E4U, 0x1U
#define IOMUXC_PIO3_8_HSP_XBAR1_INOUT08                                                         0x421C00A0U, 0xBU, 0X421C8354U, 0x1U
#define IOMUXC_PIO3_8_HSP_eFlexPWM2_PWM_A0                                                      0x421C00A0U, 0xCU, 0X421C8148U, 0x0U

#define IOMUXC_PIO3_9_HSP_GPIO1_GPIO9                                                           0x421C00A4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_9_COMM_ENET_QOS_MDC                                                         0x421C00A4U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_9_HSP_FLEXIO1_FXIO_D09                                                      0x421C00A4U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_9_COMM_TENBASET_PHY0_RX                                                     0x421C00A4U, 0x3U, 0X421C80D4U, 0x0U
#define IOMUXC_PIO3_9_MEDIA_CSI_DATA09                                                          0x421C00A4U, 0x4U, 0X421C8414U, 0x0U
#define IOMUXC_PIO3_9_MAIN_AHB_SRAMC_SRAMC_ADDR09                                               0x421C00A4U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_9_MEDIA_DCIF_DATA09                                                         0x421C00A4U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_9_MEDIA_DCIF_DBI_AB_DATA09                                                  0x421C00A4U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_9_HSP_LPI2C1_SCL                                                            0x421C00A4U, 0x8U, 0X421C81A8U, 0x2U
#define IOMUXC_PIO3_9_HSP_LPUART1_RXD                                                           0x421C00A4U, 0x9U, 0X421C824CU, 0x1U
#define IOMUXC_PIO3_9_HSP_XBAR0_INOUT09                                                         0x421C00A4U, 0xAU, 0X421C82E8U, 0x1U
#define IOMUXC_PIO3_9_HSP_XBAR1_INOUT09                                                         0x421C00A4U, 0xBU, 0X421C8358U, 0x1U
#define IOMUXC_PIO3_9_HSP_eFlexPWM2_PWM_B0                                                      0x421C00A4U, 0xCU, 0X421C8158U, 0x0U

#define IOMUXC_PIO3_10_HSP_GPIO1_GPIO10                                                         0x421C00A8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_10_COMM_ENET_QOS_TX_DATA2                                                   0x421C00A8U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_10_HSP_FLEXIO1_FXIO_D10                                                     0x421C00A8U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_10_AUDIO_SAI1_MCLK                                                          0x421C00A8U, 0x3U, 0X421C800CU, 0x2U
#define IOMUXC_PIO3_10_MEDIA_CSI_DATA10                                                         0x421C00A8U, 0x4U, 0X421C8418U, 0x0U
#define IOMUXC_PIO3_10_MAIN_AHB_SRAMC_SRAMC_ADDR10                                              0x421C00A8U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_10_MEDIA_DCIF_DATA10                                                        0x421C00A8U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_10_MEDIA_DCIF_DBI_AB_DATA10                                                 0x421C00A8U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_10_HSP_LPSPI1_PCS3                                                          0x421C00A8U, 0x8U, 0X421C81D8U, 0x1U
#define IOMUXC_PIO3_10_HSP_LPUART2_CTS_B                                                        0x421C00A8U, 0x9U, 0X421C8254U, 0x1U
#define IOMUXC_PIO3_10_HSP_XBAR0_INOUT10                                                        0x421C00A8U, 0xAU, 0X421C82ECU, 0x1U
#define IOMUXC_PIO3_10_HSP_XBAR1_INOUT10                                                        0x421C00A8U, 0xBU, 0X421C835CU, 0x1U
#define IOMUXC_PIO3_10_HSP_eFlexPWM2_PWM_A1                                                     0x421C00A8U, 0xCU, 0X421C814CU, 0x0U

#define IOMUXC_PIO3_11_HSP_GPIO1_GPIO11                                                         0x421C00ACU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_COMM_ENET_QOS_TX_DATA3                                                   0x421C00ACU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_HSP_FLEXIO1_FXIO_D11                                                     0x421C00ACU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_AUDIO_SAI1_TX_BCLK                                                       0x421C00ACU, 0x3U, 0X421C8020U, 0x1U
#define IOMUXC_PIO3_11_MEDIA_CSI_DATA11                                                         0x421C00ACU, 0x4U, 0X421C841CU, 0x0U
#define IOMUXC_PIO3_11_MAIN_AHB_SRAMC_SRAMC_ADDR11                                              0x421C00ACU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_MEDIA_DCIF_DATA11                                                        0x421C00ACU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_MEDIA_DCIF_DBI_AB_DATA11                                                 0x421C00ACU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_HSP_LPSPI1_PCS2                                                          0x421C00ACU, 0x8U, 0X421C81D4U, 0x1U
#define IOMUXC_PIO3_11_HSP_LPUART2_RTS_B                                                        0x421C00ACU, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_11_HSP_XBAR0_INOUT11                                                        0x421C00ACU, 0xAU, 0X421C82F0U, 0x1U
#define IOMUXC_PIO3_11_HSP_XBAR1_INOUT11                                                        0x421C00ACU, 0xBU, 0X421C8360U, 0x1U
#define IOMUXC_PIO3_11_HSP_eFlexPWM2_PWM_B1                                                     0x421C00ACU, 0xCU, 0X421C815CU, 0x0U

#define IOMUXC_PIO3_12_HSP_GPIO1_GPIO12                                                         0x421C00B0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_12_COMM_ENET_QOS_TX_ER                                                      0x421C00B0U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_12_HSP_FLEXIO1_FXIO_D12                                                     0x421C00B0U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_12_AUDIO_SAI1_TX_SYNC                                                       0x421C00B0U, 0x3U, 0X421C8024U, 0x1U
#define IOMUXC_PIO3_12_MEDIA_CSI_DATA12                                                         0x421C00B0U, 0x4U, 0X421C8420U, 0x0U
#define IOMUXC_PIO3_12_MAIN_AHB_SRAMC_SRAMC_ADDR12                                              0x421C00B0U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_12_MEDIA_DCIF_DATA12                                                        0x421C00B0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_12_MEDIA_DCIF_DBI_AB_DATA12                                                 0x421C00B0U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_12_HSP_LPSPI1_PCS1                                                          0x421C00B0U, 0x8U, 0X421C81D0U, 0x1U
#define IOMUXC_PIO3_12_HSP_LPUART2_TXD                                                          0x421C00B0U, 0x9U, 0X421C825CU, 0x1U
#define IOMUXC_PIO3_12_HSP_XBAR0_INOUT12                                                        0x421C00B0U, 0xAU, 0X421C82F4U, 0x1U
#define IOMUXC_PIO3_12_HSP_XBAR1_INOUT12                                                        0x421C00B0U, 0xBU, 0X421C8364U, 0x1U
#define IOMUXC_PIO3_12_HSP_eFlexPWM2_PWM_A3                                                     0x421C00B0U, 0xCU, 0X421C8154U, 0x0U

#define IOMUXC_PIO3_13_HSP_GPIO1_GPIO13                                                         0x421C00B4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_13_COMM_ENET_QOS_RX_CLK                                                     0x421C00B4U, 0x1U, 0X421C804CU, 0x0U
#define IOMUXC_PIO3_13_HSP_FLEXIO1_FXIO_D13                                                     0x421C00B4U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_13_AUDIO_SAI1_TX_DATA0                                                      0x421C00B4U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_13_MEDIA_CSI_DATA13                                                         0x421C00B4U, 0x4U, 0X421C8424U, 0x0U
#define IOMUXC_PIO3_13_MAIN_AHB_SRAMC_SRAMC_ADDR13                                              0x421C00B4U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_13_MEDIA_DCIF_DATA13                                                        0x421C00B4U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_13_MEDIA_DCIF_DBI_AB_DATA13                                                 0x421C00B4U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_13_HSP_LPSPI1_PCS0                                                          0x421C00B4U, 0x8U, 0X421C81CCU, 0x1U
#define IOMUXC_PIO3_13_HSP_LPUART2_RXD                                                          0x421C00B4U, 0x9U, 0X421C8258U, 0x1U
#define IOMUXC_PIO3_13_HSP_XBAR0_INOUT13                                                        0x421C00B4U, 0xAU, 0X421C82F8U, 0x1U
#define IOMUXC_PIO3_13_HSP_XBAR1_INOUT13                                                        0x421C00B4U, 0xBU, 0X421C8368U, 0x1U
#define IOMUXC_PIO3_13_HSP_eFlexPWM2_PWM_B3                                                     0x421C00B4U, 0xCU, 0X421C8164U, 0x0U

#define IOMUXC_PIO3_14_HSP_GPIO1_GPIO14                                                         0x421C00B8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_14_COMM_ENET_QOS_RX_DATA2                                                   0x421C00B8U, 0x1U, 0X421C8068U, 0x0U
#define IOMUXC_PIO3_14_HSP_FLEXIO1_FXIO_D14                                                     0x421C00B8U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_14_AUDIO_SAI1_RX_DATA0                                                      0x421C00B8U, 0x3U, 0X421C8014U, 0x1U
#define IOMUXC_PIO3_14_MEDIA_CSI_DATA14                                                         0x421C00B8U, 0x4U, 0X421C8428U, 0x0U
#define IOMUXC_PIO3_14_MAIN_AHB_SRAMC_SRAMC_ADDR14                                              0x421C00B8U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_14_MEDIA_DCIF_DATA14                                                        0x421C00B8U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_14_MEDIA_DCIF_DBI_AB_DATA14                                                 0x421C00B8U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_14_HSP_LPSPI1_SCK                                                           0x421C00B8U, 0x8U, 0X421C81DCU, 0x1U
#define IOMUXC_PIO3_14_HSP_LPUART3_CTS_B                                                        0x421C00B8U, 0x9U, 0X421C8260U, 0x1U
#define IOMUXC_PIO3_14_HSP_XBAR0_INOUT14                                                        0x421C00B8U, 0xAU, 0X421C82FCU, 0x1U
#define IOMUXC_PIO3_14_HSP_XBAR1_INOUT14                                                        0x421C00B8U, 0xBU, 0X421C836CU, 0x1U

#define IOMUXC_PIO3_15_HSP_GPIO1_GPIO15                                                         0x421C00BCU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_15_COMM_ENET_QOS_RX_DATA3                                                   0x421C00BCU, 0x1U, 0X421C806CU, 0x0U
#define IOMUXC_PIO3_15_HSP_FLEXIO1_FXIO_D15                                                     0x421C00BCU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_15_AUDIO_SAI1_RX_BCLK                                                       0x421C00BCU, 0x3U, 0X421C8010U, 0x1U
#define IOMUXC_PIO3_15_MEDIA_CSI_DATA15                                                         0x421C00BCU, 0x4U, 0X421C842CU, 0x0U
#define IOMUXC_PIO3_15_MAIN_AHB_SRAMC_SRAMC_ADDR15                                              0x421C00BCU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_15_MEDIA_DCIF_DATA15                                                        0x421C00BCU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_15_MEDIA_DCIF_DBI_AB_DATA15                                                 0x421C00BCU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_15_HSP_LPSPI1_SOUT                                                          0x421C00BCU, 0x8U, 0X421C81E4U, 0x1U
#define IOMUXC_PIO3_15_HSP_LPUART3_RTS_B                                                        0x421C00BCU, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_15_HSP_XBAR0_INOUT15                                                        0x421C00BCU, 0xAU, 0X421C8300U, 0x1U
#define IOMUXC_PIO3_15_HSP_XBAR1_INOUT15                                                        0x421C00BCU, 0xBU, 0X421C8370U, 0x1U

#define IOMUXC_PIO3_16_HSP_GPIO1_GPIO16                                                         0x421C00C0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_16_COMM_ENET_QOS_RX_EN                                                      0x421C00C0U, 0x1U, 0X421C8070U, 0x0U
#define IOMUXC_PIO3_16_HSP_FLEXIO1_FXIO_D16                                                     0x421C00C0U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_16_AUDIO_SAI1_RX_SYNC                                                       0x421C00C0U, 0x3U, 0X421C801CU, 0x1U
#define IOMUXC_PIO3_16_MEDIA_CSI_MCLK                                                           0x421C00C0U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_16_MAIN_AHB_SRAMC_SRAMC_ADDR16                                              0x421C00C0U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_16_MEDIA_DCIF_DATA16                                                        0x421C00C0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_16_MEDIA_DCIF_DBI_AB_CSX                                                    0x421C00C0U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_16_HSP_LPSPI1_SIN                                                           0x421C00C0U, 0x8U, 0X421C81E0U, 0x1U
#define IOMUXC_PIO3_16_HSP_LPUART3_TXD                                                          0x421C00C0U, 0x9U, 0X421C8268U, 0x1U
#define IOMUXC_PIO3_16_HSP_XBAR0_INOUT16                                                        0x421C00C0U, 0xAU, 0X421C8304U, 0x1U
#define IOMUXC_PIO3_16_HSP_XBAR1_INOUT16                                                        0x421C00C0U, 0xBU, 0X421C8374U, 0x1U

#define IOMUXC_PIO3_17_HSP_GPIO1_GPIO17                                                         0x421C00C4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_17_COMM_ENET_QOS_COL                                                        0x421C00C4U, 0x1U, 0X421C8058U, 0x0U
#define IOMUXC_PIO3_17_HSP_FLEXIO1_FXIO_D17                                                     0x421C00C4U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_17_AUDIO_SAI1_TX_DATA1                                                      0x421C00C4U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_17_MEDIA_CSI_HSYNC                                                          0x421C00C4U, 0x4U, 0X421C8430U, 0x0U
#define IOMUXC_PIO3_17_MAIN_AHB_SRAMC_SRAMC_ADVB                                                0x421C00C4U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_17_MEDIA_DCIF_DATA17                                                        0x421C00C4U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_17_MEDIA_DCIF_DBI_AB_DCS                                                    0x421C00C4U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_17_HSP_LPSPI0_PCS3                                                          0x421C00C4U, 0x8U, 0X421C81BCU, 0x1U
#define IOMUXC_PIO3_17_HSP_LPUART3_RXD                                                          0x421C00C4U, 0x9U, 0X421C8264U, 0x1U
#define IOMUXC_PIO3_17_HSP_XBAR0_INOUT17                                                        0x421C00C4U, 0xAU, 0X421C8308U, 0x1U
#define IOMUXC_PIO3_17_HSP_XBAR1_INOUT17                                                        0x421C00C4U, 0xBU, 0X421C8378U, 0x1U
#define IOMUXC_PIO3_17_AUDIO_MQS_MQS_LEFT                                                       0x421C00C4U, 0xCU, 0x00000000U, 0x0U

#define IOMUXC_PIO3_18_HSP_GPIO1_GPIO18                                                         0x421C00C8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_WAKE_EWM_OUT_B                                                           0x421C00C8U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_HSP_FLEXIO1_FXIO_D18                                                     0x421C00C8U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_AUDIO_SAI1_RX_DATA1                                                      0x421C00C8U, 0x3U, 0X421C8018U, 0x1U
#define IOMUXC_PIO3_18_MEDIA_CSI_VSYNC                                                          0x421C00C8U, 0x4U, 0X421C8438U, 0x0U
#define IOMUXC_PIO3_18_MAIN_AHB_SRAMC_SRAMC_CS0                                                 0x421C00C8U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_MEDIA_DCIF_DATA18                                                        0x421C00C8U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_MEDIA_DCIF_DBI_B_RDX                                                     0x421C00C8U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_HSP_LPSPI0_PCS2                                                          0x421C00C8U, 0x8U, 0X421C81B8U, 0x1U
#define IOMUXC_PIO3_18_MEDIA_DCIF_DBI_A_E                                                       0x421C00C8U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_18_HSP_XBAR0_INOUT18                                                        0x421C00C8U, 0xAU, 0X421C830CU, 0x1U
#define IOMUXC_PIO3_18_HSP_XBAR1_INOUT18                                                        0x421C00C8U, 0xBU, 0X421C837CU, 0x1U
#define IOMUXC_PIO3_18_AUDIO_MQS_MQS_RIGHT                                                      0x421C00C8U, 0xCU, 0x00000000U, 0x0U

#define IOMUXC_PIO3_19_HSP_GPIO1_GPIO19                                                         0x421C00CCU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_19_HSP_FLEXIO1_FXIO_D19                                                     0x421C00CCU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_19_COMM_CCM_CLKREF_25M                                                      0x421C00CCU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_19_MEDIA_CSI_PIXCLK                                                         0x421C00CCU, 0x4U, 0X421C8434U, 0x0U
#define IOMUXC_PIO3_19_MAIN_AHB_SRAMC_SRAMC_CS1                                                 0x421C00CCU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_19_MEDIA_DCIF_DATA19                                                        0x421C00CCU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_19_MEDIA_DCIF_DBI_A_RWX_OR_B_WRX                                              0x421C00CCU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_19_HSP_LPSPI0_PCS1                                                          0x421C00CCU, 0x8U, 0X421C81B4U, 0x1U
#define IOMUXC_PIO3_19_AUDIO_MICFIL_PDM_DATA45                                                  0x421C00CCU, 0x9U, 0X421C8008U, 0x2U
#define IOMUXC_PIO3_19_HSP_XBAR0_INOUT19                                                        0x421C00CCU, 0xAU, 0X421C8310U, 0x1U
#define IOMUXC_PIO3_19_HSP_XBAR1_INOUT19                                                        0x421C00CCU, 0xBU, 0X421C8380U, 0x1U

#define IOMUXC_PIO3_20_HSP_GPIO1_GPIO20                                                         0x421C00D0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_20_HSP_FLEXIO1_FXIO_D20                                                     0x421C00D0U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_20_SYSCON_FREQME_CLK_OUT                                                    0x421C00D0U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_20_MEDIA_CSI_FIELD                                                          0x421C00D0U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_20_MAIN_AHB_SRAMC_SRAMC_WP0                                                 0x421C00D0U, 0x5U, 0X421C83E4U, 0x1U
#define IOMUXC_PIO3_20_MEDIA_DCIF_DATA20                                                        0x421C00D0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_20_HSP_LPI2C0_SCL                                                           0x421C00D0U, 0x7U, 0X421C81A0U, 0x2U
#define IOMUXC_PIO3_20_HSP_LPSPI0_SCK                                                           0x421C00D0U, 0x8U, 0X421C81C0U, 0x1U
#define IOMUXC_PIO3_20_AUDIO_MICFIL_PDM_DATA23                                                  0x421C00D0U, 0x9U, 0X421C8004U, 0x2U
#define IOMUXC_PIO3_20_HSP_XBAR0_INOUT20                                                        0x421C00D0U, 0xAU, 0X421C8314U, 0x1U
#define IOMUXC_PIO3_20_HSP_XBAR1_INOUT20                                                        0x421C00D0U, 0xBU, 0X421C8384U, 0x1U

#define IOMUXC_PIO3_21_HSP_GPIO1_GPIO21                                                         0x421C00D4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_21_HSP_FLEXIO1_FXIO_D21                                                     0x421C00D4U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_21_MEDIA_FREQME_CLK_OUT                                                     0x421C00D4U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_21_COMM_USB0_ID                                                             0x421C00D4U, 0x4U, 0X421C80A8U, 0x1U
#define IOMUXC_PIO3_21_MAIN_AHB_SRAMC_SRAMC_WP1                                                 0x421C00D4U, 0x5U, 0X421C83E8U, 0x1U
#define IOMUXC_PIO3_21_MEDIA_DCIF_DATA21                                                        0x421C00D4U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_21_HSP_LPI2C0_SDA                                                           0x421C00D4U, 0x7U, 0X421C81A4U, 0x2U
#define IOMUXC_PIO3_21_HSP_LPSPI0_SOUT                                                          0x421C00D4U, 0x8U, 0X421C81C8U, 0x1U
#define IOMUXC_PIO3_21_AUDIO_MICFIL_PDM_DATA01                                                  0x421C00D4U, 0x9U, 0X421C8000U, 0x2U
#define IOMUXC_PIO3_21_HSP_XBAR0_INOUT21                                                        0x421C00D4U, 0xAU, 0X421C8318U, 0x1U
#define IOMUXC_PIO3_21_HSP_XBAR1_INOUT21                                                        0x421C00D4U, 0xBU, 0X421C8388U, 0x1U
#define IOMUXC_PIO3_21_HSP_eFlexPWM2_PWM_X0                                                     0x421C00D4U, 0xCU, 0X421C8168U, 0x0U

#define IOMUXC_PIO3_22_HSP_GPIO1_GPIO22                                                         0x421C00D8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_HSP_FLEXIO1_FXIO_D22                                                     0x421C00D8U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_COMM_FREQME_CLK_OUT                                                      0x421C00D8U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_COMM_uSDHC1_CD_B                                                         0x421C00D8U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_MEDIA_DCIF_DATA22                                                        0x421C00D8U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_HSP_FlexCAN2_CAN_TX                                                      0x421C00D8U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_HSP_LPSPI0_SIN                                                           0x421C00D8U, 0x8U, 0X421C81C4U, 0x1U
#define IOMUXC_PIO3_22_AUDIO_MICFIL_PDM_CLK                                                     0x421C00D8U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_22_HSP_XBAR0_INOUT22                                                        0x421C00D8U, 0xAU, 0X421C831CU, 0x1U
#define IOMUXC_PIO3_22_HSP_XBAR1_INOUT22                                                        0x421C00D8U, 0xBU, 0X421C838CU, 0x1U
#define IOMUXC_PIO3_22_HSP_eFlexPWM2_PWM_X1                                                     0x421C00D8U, 0xCU, 0X421C816CU, 0x0U

#define IOMUXC_PIO3_23_HSP_GPIO1_GPIO23                                                         0x421C00DCU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_23_HSP_FLEXIO1_FXIO_D23                                                     0x421C00DCU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_23_MAIN_TRACE_SWO                                                           0x421C00DCU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_23_COMM_USB0_PWR                                                            0x421C00DCU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_23_COMM_uSDHC1_RESET_B                                                      0x421C00DCU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_23_MEDIA_DCIF_DATA23                                                        0x421C00DCU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_23_HSP_FlexCAN2_CAN_RX                                                      0x421C00DCU, 0x7U, 0X421C8108U, 0x0U
#define IOMUXC_PIO3_23_HSP_LPSPI0_PCS0                                                          0x421C00DCU, 0x8U, 0X421C81B0U, 0x1U
#define IOMUXC_PIO3_23_HSP_XBAR0_INOUT23                                                        0x421C00DCU, 0xAU, 0X421C8320U, 0x1U
#define IOMUXC_PIO3_23_HSP_XBAR1_INOUT23                                                        0x421C00DCU, 0xBU, 0X421C8390U, 0x1U
#define IOMUXC_PIO3_23_HSP_eFlexPWM2_PWM_X2                                                     0x421C00DCU, 0xCU, 0X421C8170U, 0x0U

#define IOMUXC_PIO3_24_HSP_GPIO1_GPIO24                                                         0x421C00E0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_24_HSP_FLEXIO1_FXIO_D24                                                     0x421C00E0U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_24_MAIN_CCM_CLKOUT                                                          0x421C00E0U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_24_COMM_USB0_OC                                                             0x421C00E0U, 0x4U, 0X421C80A4U, 0x1U
#define IOMUXC_PIO3_24_COMM_uSDHC1_WP                                                           0x421C00E0U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_24_MEDIA_DCIF_DE                                                            0x421C00E0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_24_HSP_LPI2C0_SDA                                                           0x421C00E0U, 0x8U, 0X421C81A4U, 0x3U
#define IOMUXC_PIO3_24_HSP_XBAR0_INOUT24                                                        0x421C00E0U, 0xAU, 0X421C8324U, 0x1U
#define IOMUXC_PIO3_24_HSP_XBAR1_INOUT24                                                        0x421C00E0U, 0xBU, 0X421C8394U, 0x1U
#define IOMUXC_PIO3_24_HSP_eFlexPWM2_PWM_X3                                                     0x421C00E0U, 0xCU, 0X421C8174U, 0x0U

#define IOMUXC_PIO3_25_HSP_GPIO1_GPIO25                                                         0x421C00E4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_25_HSP_FLEXIO1_FXIO_D25                                                     0x421C00E4U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_25_HSP_I3C_SDA                                                              0x421C00E4U, 0x3U, 0X421C819CU, 0x1U
#define IOMUXC_PIO3_25_MEDIA_DCIF_PIXEL_CLK                                                     0x421C00E4U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_25_HSP_LPI2C0_SCL                                                           0x421C00E4U, 0x8U, 0X421C81A0U, 0x3U
#define IOMUXC_PIO3_25_HSP_XBAR0_INOUT25                                                        0x421C00E4U, 0xAU, 0X421C8328U, 0x1U
#define IOMUXC_PIO3_25_HSP_XBAR1_INOUT25                                                        0x421C00E4U, 0xBU, 0X421C8398U, 0x1U

#define IOMUXC_PIO3_26_HSP_GPIO1_GPIO26                                                         0x421C00E8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_26_HSP_FLEXIO1_FXIO_D26                                                     0x421C00E8U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_26_HSP_I3C_SCL                                                              0x421C00E8U, 0x3U, 0X421C8198U, 0x1U
#define IOMUXC_PIO3_26_MEDIA_DCIF_HSYNC                                                         0x421C00E8U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_26_AUDIO_MQS_MQS_LEFT                                                       0x421C00E8U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_26_HSP_XBAR0_INOUT26                                                        0x421C00E8U, 0xAU, 0X421C832CU, 0x1U
#define IOMUXC_PIO3_26_HSP_XBAR1_INOUT26                                                        0x421C00E8U, 0xBU, 0X421C839CU, 0x1U

#define IOMUXC_PIO3_27_HSP_GPIO1_GPIO27                                                         0x421C00ECU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_27_HSP_FLEXIO1_FXIO_D27                                                     0x421C00ECU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_27_HSP_I3C_PUR                                                              0x421C00ECU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_27_MEDIA_DCIF_VSYNC                                                         0x421C00ECU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_27_AUDIO_MQS_MQS_RIGHT                                                      0x421C00ECU, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_27_HSP_XBAR0_INOUT27                                                        0x421C00ECU, 0xAU, 0X421C8330U, 0x1U
#define IOMUXC_PIO3_27_HSP_XBAR1_INOUT27                                                        0x421C00ECU, 0xBU, 0X421C83A0U, 0x1U

#define IOMUXC_PIO3_28_HSP_GPIO1_GPIO28                                                         0x421C00F0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_HSP_LPUART0_CTS_B                                                        0x421C00F0U, 0x1U, 0X421C823CU, 0x2U
#define IOMUXC_PIO3_28_HSP_FLEXIO1_FXIO_D28                                                     0x421C00F0U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_MAIN_CCM_CLKOUT                                                          0x421C00F0U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_HSP_eFlexPWM1_PWM_X1                                                     0x421C00F0U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_COMM_ENET_TX_ER                                                          0x421C00F0U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_COMM_uSDHC0_RESET_B                                                      0x421C00F0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_HSP_XBAR0_INOUT28                                                        0x421C00F0U, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO3_28_HSP_XBAR1_INOUT28                                                        0x421C00F0U, 0xBU, 0x00000000U, 0x0U

#define IOMUXC_PIO3_29_HSP_GPIO1_GPIO29                                                         0x421C00F4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_29_HSP_LPUART0_RTS_B                                                        0x421C00F4U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_29_HSP_FLEXIO1_FXIO_D29                                                     0x421C00F4U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_29_CMPT_FREQME_CLK_OUT                                                      0x421C00F4U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_29_HSP_eFlexPWM1_PWM_X2                                                     0x421C00F4U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_29_COMM_ENET_RX_ER                                                          0x421C00F4U, 0x5U, 0X421C80A0U, 0x0U
#define IOMUXC_PIO3_29_COMM_uSDHC0_CD_B                                                         0x421C00F4U, 0x6U, 0X421C80B0U, 0x0U
#define IOMUXC_PIO3_29_HSP_XBAR0_INOUT29                                                        0x421C00F4U, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO3_29_HSP_XBAR1_INOUT29                                                        0x421C00F4U, 0xBU, 0x00000000U, 0x0U

#define IOMUXC_PIO3_30_HSP_GPIO1_GPIO30                                                         0x421C00F8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_30_HSP_LPUART0_TXD                                                          0x421C00F8U, 0x1U, 0X421C8244U, 0x2U
#define IOMUXC_PIO3_30_HSP_FLEXIO1_FXIO_D30                                                     0x421C00F8U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_30_HSP_eFlexPWM1_PWM_X3                                                     0x421C00F8U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_30_COMM_ENET_CRS                                                            0x421C00F8U, 0x5U, 0X421C8080U, 0x0U
#define IOMUXC_PIO3_30_COMM_uSDHC0_WP                                                           0x421C00F8U, 0x6U, 0X421C80B4U, 0x0U
#define IOMUXC_PIO3_30_HSP_XBAR0_INOUT30                                                        0x421C00F8U, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO3_30_HSP_XBAR1_INOUT30                                                        0x421C00F8U, 0xBU, 0x00000000U, 0x0U
#define IOMUXC_PIO3_30_MAIN_XSPI0_TST_TRG                                                       0x421C00F8U, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO3_31_HSP_GPIO1_GPIO31                                                         0x421C00FCU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_HSP_LPUART0_RXD                                                          0x421C00FCU, 0x1U, 0X421C8240U, 0x2U
#define IOMUXC_PIO3_31_HSP_FLEXIO1_FXIO_D31                                                     0x421C00FCU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_MAIN_FREQME_CLK_OUT                                                      0x421C00FCU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_COMM_CCM_CLKREF_25M                                                      0x421C00FCU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_COMM_ENET_COL                                                            0x421C00FCU, 0x5U, 0X421C807CU, 0x0U
#define IOMUXC_PIO3_31_COMM_uSDHC0_VSELECT                                                      0x421C00FCU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_HSP_XBAR0_INOUT31                                                        0x421C00FCU, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_HSP_XBAR1_INOUT31                                                        0x421C00FCU, 0xBU, 0x00000000U, 0x0U
#define IOMUXC_PIO3_31_MAIN_XSPI1_TST_TRG                                                       0x421C00FCU, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO4_0_HSP_GPIO2_GPIO0                                                           0x421C0100U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_0_COMM_ENET_TX_CLK_IO                                                       0x421C0100U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_0_HSP_FLEXIO2_FXIO_D00                                                      0x421C0100U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_0_AUDIO_SAI2_MCLK                                                           0x421C0100U, 0x3U, 0X421C8028U, 0x0U
#define IOMUXC_PIO4_0_MEDIA_CSI_DATA23                                                          0x421C0100U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_0_HSP_SINC1_MBIT0                                                           0x421C0100U, 0x5U, 0X421C82A4U, 0x0U
#define IOMUXC_PIO4_0_MEDIA_DCIF_DATA00                                                         0x421C0100U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_0_MEDIA_DCIF_DBI_AB_DATA00                                                  0x421C0100U, 0x7U, 0X421C843CU, 0x1U
#define IOMUXC_PIO4_0_HSP_eFlexPWM2_PWM_A0                                                      0x421C0100U, 0x8U, 0X421C8148U, 0x1U
#define IOMUXC_PIO4_0_COMM_ENET_REF_CLK                                                         0x421C0100U, 0x9U, 0X421C8078U, 0x0U
#define IOMUXC_PIO4_0_HSP_XBAR0_INOUT00                                                         0x421C0100U, 0xAU, 0X421C82C4U, 0x2U
#define IOMUXC_PIO4_0_HSP_XBAR1_INOUT00                                                         0x421C0100U, 0xBU, 0X421C8334U, 0x2U

#define IOMUXC_PIO4_1_HSP_GPIO2_GPIO1                                                           0x421C0104U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_1_COMM_ENET_TXD0                                                            0x421C0104U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_1_HSP_FLEXIO2_FXIO_D01                                                      0x421C0104U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_1_AUDIO_SAI2_TX_BCLK                                                        0x421C0104U, 0x3U, 0X421C803CU, 0x0U
#define IOMUXC_PIO4_1_MEDIA_CSI_DATA22                                                          0x421C0104U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_1_HSP_SINC1_MCLK0                                                           0x421C0104U, 0x5U, 0X421C82B4U, 0x0U
#define IOMUXC_PIO4_1_MEDIA_DCIF_DATA01                                                         0x421C0104U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_1_MEDIA_DCIF_DBI_AB_DATA01                                                  0x421C0104U, 0x7U, 0X421C8440U, 0x1U
#define IOMUXC_PIO4_1_HSP_eFlexPWM2_PWM_B0                                                      0x421C0104U, 0x8U, 0X421C8158U, 0x1U
#define IOMUXC_PIO4_1_HSP_SINC1_MCLK_OUT0                                                       0x421C0104U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_1_HSP_XBAR0_INOUT01                                                         0x421C0104U, 0xAU, 0X421C82C8U, 0x2U
#define IOMUXC_PIO4_1_HSP_XBAR1_INOUT01                                                         0x421C0104U, 0xBU, 0X421C8338U, 0x2U

#define IOMUXC_PIO4_2_HSP_GPIO2_GPIO2                                                           0x421C0108U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_2_COMM_ENET_TXD1                                                            0x421C0108U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_2_HSP_FLEXIO2_FXIO_D02                                                      0x421C0108U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_2_AUDIO_SAI2_TX_SYNC                                                        0x421C0108U, 0x3U, 0X421C8040U, 0x0U
#define IOMUXC_PIO4_2_MEDIA_CSI_DATA21                                                          0x421C0108U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_2_HSP_SINC1_MCLK1                                                           0x421C0108U, 0x5U, 0X421C82B8U, 0x0U
#define IOMUXC_PIO4_2_MEDIA_DCIF_DATA02                                                         0x421C0108U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_2_MEDIA_DCIF_DBI_AB_DATA02                                                  0x421C0108U, 0x7U, 0X421C8444U, 0x1U
#define IOMUXC_PIO4_2_HSP_eFlexPWM2_PWM_A1                                                      0x421C0108U, 0x8U, 0X421C814CU, 0x1U
#define IOMUXC_PIO4_2_HSP_SINC1_MCLK_OUT1                                                       0x421C0108U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_2_HSP_XBAR0_INOUT02                                                         0x421C0108U, 0xAU, 0X421C82CCU, 0x2U
#define IOMUXC_PIO4_2_HSP_XBAR1_INOUT02                                                         0x421C0108U, 0xBU, 0X421C833CU, 0x2U

#define IOMUXC_PIO4_3_HSP_GPIO2_GPIO3                                                           0x421C010CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_3_COMM_ENET_TX_EN                                                           0x421C010CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_3_HSP_FLEXIO2_FXIO_D03                                                      0x421C010CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_3_AUDIO_SAI2_RX_DATA0                                                       0x421C010CU, 0x3U, 0X421C8030U, 0x0U
#define IOMUXC_PIO4_3_MEDIA_CSI_DATA20                                                          0x421C010CU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_3_HSP_SINC1_MBIT1                                                           0x421C010CU, 0x5U, 0X421C82A8U, 0x0U
#define IOMUXC_PIO4_3_MEDIA_DCIF_DATA03                                                         0x421C010CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_3_MEDIA_DCIF_DBI_AB_DATA03                                                  0x421C010CU, 0x7U, 0X421C8448U, 0x1U
#define IOMUXC_PIO4_3_HSP_eFlexPWM2_PWM_B1                                                      0x421C010CU, 0x8U, 0X421C815CU, 0x1U
#define IOMUXC_PIO4_3_HSP_XBAR0_INOUT03                                                         0x421C010CU, 0xAU, 0X421C82D0U, 0x2U
#define IOMUXC_PIO4_3_HSP_XBAR1_INOUT03                                                         0x421C010CU, 0xBU, 0X421C8340U, 0x2U

#define IOMUXC_PIO4_4_HSP_GPIO2_GPIO4                                                           0x421C0110U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_4_COMM_ENET_RXD0                                                            0x421C0110U, 0x1U, 0X421C808CU, 0x0U
#define IOMUXC_PIO4_4_HSP_FLEXIO2_FXIO_D04                                                      0x421C0110U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_4_AUDIO_SAI2_TX_DATA0                                                       0x421C0110U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_4_MEDIA_CSI_DATA19                                                          0x421C0110U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_4_HSP_SINC1_MCLK2                                                           0x421C0110U, 0x5U, 0X421C82BCU, 0x0U
#define IOMUXC_PIO4_4_MEDIA_DCIF_DATA04                                                         0x421C0110U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_4_MEDIA_DCIF_DBI_AB_DATA04                                                  0x421C0110U, 0x7U, 0X421C844CU, 0x1U
#define IOMUXC_PIO4_4_HSP_eFlexPWM2_PWM_A2                                                      0x421C0110U, 0x8U, 0X421C8150U, 0x0U
#define IOMUXC_PIO4_4_HSP_SINC1_MCLK_OUT2                                                       0x421C0110U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_4_HSP_XBAR0_INOUT04                                                         0x421C0110U, 0xAU, 0X421C82D4U, 0x2U
#define IOMUXC_PIO4_4_HSP_XBAR1_INOUT04                                                         0x421C0110U, 0xBU, 0X421C8344U, 0x2U

#define IOMUXC_PIO4_5_HSP_GPIO2_GPIO5                                                           0x421C0114U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_5_COMM_ENET_RXD1                                                            0x421C0114U, 0x1U, 0X421C8090U, 0x0U
#define IOMUXC_PIO4_5_HSP_FLEXIO2_FXIO_D05                                                      0x421C0114U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_5_AUDIO_SAI2_RX_BCLK                                                        0x421C0114U, 0x3U, 0X421C802CU, 0x0U
#define IOMUXC_PIO4_5_MEDIA_CSI_DATA18                                                          0x421C0114U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_5_HSP_SINC1_MBIT2                                                           0x421C0114U, 0x5U, 0X421C82ACU, 0x0U
#define IOMUXC_PIO4_5_MEDIA_DCIF_DATA05                                                         0x421C0114U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_5_MEDIA_DCIF_DBI_AB_DATA05                                                  0x421C0114U, 0x7U, 0X421C8450U, 0x1U
#define IOMUXC_PIO4_5_HSP_eFlexPWM2_PWM_B2                                                      0x421C0114U, 0x8U, 0X421C8160U, 0x0U
#define IOMUXC_PIO4_5_HSP_XBAR0_INOUT05                                                         0x421C0114U, 0xAU, 0X421C82D8U, 0x2U
#define IOMUXC_PIO4_5_HSP_XBAR1_INOUT05                                                         0x421C0114U, 0xBU, 0X421C8348U, 0x2U

#define IOMUXC_PIO4_6_HSP_GPIO2_GPIO6                                                           0x421C0118U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_6_COMM_ENET_MDIO                                                            0x421C0118U, 0x1U, 0X421C8084U, 0x0U
#define IOMUXC_PIO4_6_HSP_FLEXIO2_FXIO_D06                                                      0x421C0118U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_6_AUDIO_SAI2_RX_SYNC                                                        0x421C0118U, 0x3U, 0X421C8038U, 0x0U
#define IOMUXC_PIO4_6_MEDIA_CSI_DATA17                                                          0x421C0118U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_6_HSP_SINC1_MCLK3                                                           0x421C0118U, 0x5U, 0X421C82C0U, 0x0U
#define IOMUXC_PIO4_6_MEDIA_DCIF_DATA06                                                         0x421C0118U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_6_MEDIA_DCIF_DBI_AB_DATA06                                                  0x421C0118U, 0x7U, 0X421C8454U, 0x1U
#define IOMUXC_PIO4_6_HSP_eFlexPWM2_PWM_A3                                                      0x421C0118U, 0x8U, 0X421C8154U, 0x1U
#define IOMUXC_PIO4_6_HSP_LPUART4_RTS_B                                                         0x421C0118U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_6_HSP_XBAR0_INOUT06                                                         0x421C0118U, 0xAU, 0X421C82DCU, 0x2U
#define IOMUXC_PIO4_6_HSP_XBAR1_INOUT06                                                         0x421C0118U, 0xBU, 0X421C834CU, 0x2U

#define IOMUXC_PIO4_7_HSP_GPIO2_GPIO7                                                           0x421C011CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_7_COMM_ENET_MDC                                                             0x421C011CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_7_HSP_FLEXIO2_FXIO_D07                                                      0x421C011CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_7_AUDIO_SAI2_TX_DATA1                                                       0x421C011CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_7_MEDIA_CSI_DATA16                                                          0x421C011CU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_7_HSP_SINC1_MBIT3                                                           0x421C011CU, 0x5U, 0X421C82B0U, 0x0U
#define IOMUXC_PIO4_7_MEDIA_DCIF_DATA07                                                         0x421C011CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_7_MEDIA_DCIF_DBI_AB_DATA07                                                  0x421C011CU, 0x7U, 0X421C8458U, 0x1U
#define IOMUXC_PIO4_7_HSP_eFlexPWM2_PWM_B3                                                      0x421C011CU, 0x8U, 0X421C8164U, 0x1U
#define IOMUXC_PIO4_7_HSP_LPUART4_CTS_B                                                         0x421C011CU, 0x9U, 0X421C826CU, 0x1U
#define IOMUXC_PIO4_7_HSP_XBAR0_INOUT07                                                         0x421C011CU, 0xAU, 0X421C82E0U, 0x2U
#define IOMUXC_PIO4_7_HSP_XBAR1_INOUT07                                                         0x421C011CU, 0xBU, 0X421C8350U, 0x2U

#define IOMUXC_PIO4_8_HSP_GPIO2_GPIO8                                                           0x421C0120U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_COMM_ENET_TXD2                                                            0x421C0120U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_HSP_FLEXIO2_FXIO_D08                                                      0x421C0120U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_AUDIO_SAI2_RX_DATA1                                                       0x421C0120U, 0x3U, 0X421C8034U, 0x0U
#define IOMUXC_PIO4_8_MEDIA_CSI_DATA15                                                          0x421C0120U, 0x4U, 0X421C842CU, 0x1U
#define IOMUXC_PIO4_8_HSP_SINC1_BREAK                                                           0x421C0120U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_MEDIA_DCIF_DATA08                                                         0x421C0120U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_MEDIA_DCIF_DBI_AB_CSX                                                     0x421C0120U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_COMM_TENBASET_PHY1_TX                                                     0x421C0120U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_8_HSP_LPUART4_TXD                                                           0x421C0120U, 0x9U, 0X421C8274U, 0x1U
#define IOMUXC_PIO4_8_HSP_XBAR0_INOUT08                                                         0x421C0120U, 0xAU, 0X421C82E4U, 0x2U
#define IOMUXC_PIO4_8_HSP_XBAR1_INOUT08                                                         0x421C0120U, 0xBU, 0X421C8354U, 0x2U

#define IOMUXC_PIO4_9_HSP_GPIO2_GPIO9                                                           0x421C0124U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_9_COMM_ENET_TXD3                                                            0x421C0124U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_9_HSP_FLEXIO2_FXIO_D09                                                      0x421C0124U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_9_MEDIA_CSI_DATA14                                                          0x421C0124U, 0x4U, 0X421C8428U, 0x1U
#define IOMUXC_PIO4_9_MEDIA_DCIF_DATA09                                                         0x421C0124U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_9_MEDIA_DCIF_DBI_AB_DCS                                                     0x421C0124U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_9_HSP_eFlexPWM3_PWM_A0                                                      0x421C0124U, 0x8U, 0X421C8178U, 0x0U
#define IOMUXC_PIO4_9_HSP_LPUART4_RXD                                                           0x421C0124U, 0x9U, 0X421C8270U, 0x1U
#define IOMUXC_PIO4_9_HSP_XBAR0_INOUT09                                                         0x421C0124U, 0xAU, 0X421C82E8U, 0x2U
#define IOMUXC_PIO4_9_HSP_XBAR1_INOUT09                                                         0x421C0124U, 0xBU, 0X421C8358U, 0x2U

#define IOMUXC_PIO4_10_HSP_GPIO2_GPIO10                                                         0x421C0128U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_10_COMM_ENET_RX_CLK                                                         0x421C0128U, 0x1U, 0X421C8088U, 0x0U
#define IOMUXC_PIO4_10_HSP_FLEXIO2_FXIO_D10                                                     0x421C0128U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_10_AUDIO_MICFIL_PDM_CLK                                                     0x421C0128U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_10_MEDIA_CSI_DATA13                                                         0x421C0128U, 0x4U, 0X421C8424U, 0x1U
#define IOMUXC_PIO4_10_MEDIA_DCIF_DBI_A_E                                                       0x421C0128U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_10_MEDIA_DCIF_DATA10                                                        0x421C0128U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_10_MEDIA_DCIF_DBI_B_RDX                                                     0x421C0128U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_10_HSP_eFlexPWM3_PWM_B0                                                     0x421C0128U, 0x8U, 0X421C8188U, 0x0U
#define IOMUXC_PIO4_10_HSP_LPUART5_TXD                                                          0x421C0128U, 0x9U, 0X421C8280U, 0x1U
#define IOMUXC_PIO4_10_COMM_ENET_QOS_COL                                                        0x421C0128U, 0xAU, 0X421C8058U, 0x1U
#define IOMUXC_PIO4_10_HSP_XBAR1_INOUT10                                                        0x421C0128U, 0xBU, 0X421C835CU, 0x2U

#define IOMUXC_PIO4_11_HSP_GPIO2_GPIO11                                                         0x421C012CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_11_COMM_ENET_RXD2                                                           0x421C012CU, 0x1U, 0X421C8094U, 0x0U
#define IOMUXC_PIO4_11_HSP_FLEXIO2_FXIO_D11                                                     0x421C012CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_11_AUDIO_MICFIL_PDM_DATA45                                                  0x421C012CU, 0x3U, 0X421C8008U, 0x3U
#define IOMUXC_PIO4_11_MEDIA_CSI_DATA12                                                         0x421C012CU, 0x4U, 0X421C8420U, 0x1U
#define IOMUXC_PIO4_11_MEDIA_DCIF_DBI_A_RWX_OR_B_WRX                                              0x421C012CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_11_MEDIA_DCIF_DATA11                                                        0x421C012CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_11_COMM_TENBASET_PHY1_TX                                                    0x421C012CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_11_HSP_eFlexPWM3_PWM_A1                                                     0x421C012CU, 0x8U, 0X421C817CU, 0x0U
#define IOMUXC_PIO4_11_HSP_LPUART5_RXD                                                          0x421C012CU, 0x9U, 0X421C827CU, 0x1U
#define IOMUXC_PIO4_11_COMM_ENET_QOS_CRS                                                        0x421C012CU, 0xAU, 0X421C805CU, 0x1U
#define IOMUXC_PIO4_11_HSP_XBAR1_INOUT11                                                        0x421C012CU, 0xBU, 0X421C8360U, 0x2U

#define IOMUXC_PIO4_12_HSP_GPIO2_GPIO12                                                         0x421C0130U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_12_COMM_ENET_RXD3                                                           0x421C0130U, 0x1U, 0X421C8098U, 0x0U
#define IOMUXC_PIO4_12_HSP_FLEXIO2_FXIO_D12                                                     0x421C0130U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_12_AUDIO_MICFIL_PDM_DATA23                                                  0x421C0130U, 0x3U, 0X421C8004U, 0x3U
#define IOMUXC_PIO4_12_MEDIA_CSI_DATA11                                                         0x421C0130U, 0x4U, 0X421C841CU, 0x1U
#define IOMUXC_PIO4_12_HSP_LPSPI2_PCS2                                                          0x421C0130U, 0x5U, 0X421C81F0U, 0x0U
#define IOMUXC_PIO4_12_MEDIA_DCIF_DATA12                                                        0x421C0130U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_12_COMM_TENBASET_PHY1_ED                                                    0x421C0130U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_12_HSP_eFlexPWM3_PWM_B1                                                     0x421C0130U, 0x8U, 0X421C818CU, 0x0U
#define IOMUXC_PIO4_12_HSP_LPUART5_CTS_B                                                        0x421C0130U, 0x9U, 0X421C8278U, 0x1U
#define IOMUXC_PIO4_12_COMM_ENET_QOS_TX_ER                                                      0x421C0130U, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO4_12_HSP_XBAR1_INOUT12                                                        0x421C0130U, 0xBU, 0X421C8364U, 0x2U

#define IOMUXC_PIO4_13_HSP_GPIO2_GPIO13                                                         0x421C0134U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_13_COMM_ENET_RX_EN                                                          0x421C0134U, 0x1U, 0X421C809CU, 0x0U
#define IOMUXC_PIO4_13_HSP_FLEXIO2_FXIO_D13                                                     0x421C0134U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_13_AUDIO_MICFIL_PDM_DATA01                                                  0x421C0134U, 0x3U, 0X421C8000U, 0x3U
#define IOMUXC_PIO4_13_MEDIA_CSI_DATA10                                                         0x421C0134U, 0x4U, 0X421C8418U, 0x1U
#define IOMUXC_PIO4_13_HSP_LPSPI2_PCS3                                                          0x421C0134U, 0x5U, 0X421C81F4U, 0x0U
#define IOMUXC_PIO4_13_MEDIA_DCIF_DATA13                                                        0x421C0134U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_13_COMM_TENBASET_PHY1_RX                                                    0x421C0134U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_13_HSP_eFlexPWM3_PWM_A2                                                     0x421C0134U, 0x8U, 0X421C8180U, 0x0U
#define IOMUXC_PIO4_13_HSP_LPUART5_RTS_B                                                        0x421C0134U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_13_COMM_ENET_QOS_RX_ER                                                      0x421C0134U, 0xAU, 0X421C8074U, 0x1U
#define IOMUXC_PIO4_13_HSP_XBAR1_INOUT13                                                        0x421C0134U, 0xBU, 0X421C8368U, 0x2U

#define IOMUXC_PIO4_14_HSP_GPIO2_GPIO14                                                         0x421C0138U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_14_COMM_ENET_QOS_TX_CLK_IO                                                  0x421C0138U, 0x1U, 0X421C8050U, 0x1U
#define IOMUXC_PIO4_14_HSP_FLEXIO2_FXIO_D14                                                     0x421C0138U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_14_COMM_ENET_QOS_REF_CLK1                                                   0x421C0138U, 0x3U, 0X421C8048U, 0x1U
#define IOMUXC_PIO4_14_MEDIA_CSI_DATA09                                                         0x421C0138U, 0x4U, 0X421C8414U, 0x1U
#define IOMUXC_PIO4_14_HSP_LPSPI2_PCS0                                                          0x421C0138U, 0x5U, 0X421C81E8U, 0x0U
#define IOMUXC_PIO4_14_MEDIA_DCIF_DATA14                                                        0x421C0138U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_14_HSP_eFlexPWM3_PWM_B2                                                     0x421C0138U, 0x8U, 0X421C8190U, 0x0U
#define IOMUXC_PIO4_14_COMM_ENET_RX_ER                                                          0x421C0138U, 0xAU, 0X421C80A0U, 0x1U
#define IOMUXC_PIO4_14_HSP_XBAR1_INOUT14                                                        0x421C0138U, 0xBU, 0X421C836CU, 0x2U

#define IOMUXC_PIO4_15_HSP_GPIO2_GPIO15                                                         0x421C013CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_15_COMM_ENET_QOS_TX_DATA0                                                   0x421C013CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_15_HSP_FLEXIO2_FXIO_D15                                                     0x421C013CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_15_MEDIA_CSI_DATA08                                                         0x421C013CU, 0x4U, 0X421C8410U, 0x1U
#define IOMUXC_PIO4_15_HSP_LPSPI2_SCK                                                           0x421C013CU, 0x5U, 0X421C81F8U, 0x0U
#define IOMUXC_PIO4_15_MEDIA_DCIF_DATA15                                                        0x421C013CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_15_HSP_eFlexPWM3_PWM_A3                                                     0x421C013CU, 0x8U, 0X421C8184U, 0x0U
#define IOMUXC_PIO4_15_COMM_ENET_TX_ER                                                          0x421C013CU, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO4_15_HSP_XBAR1_INOUT15                                                        0x421C013CU, 0xBU, 0X421C8370U, 0x2U

#define IOMUXC_PIO4_16_HSP_GPIO2_GPIO16                                                         0x421C0140U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_16_COMM_ENET_QOS_TX_DATA1                                                   0x421C0140U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_16_HSP_FLEXIO2_FXIO_D16                                                     0x421C0140U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_16_MEDIA_CSI_DATA07                                                         0x421C0140U, 0x4U, 0X421C840CU, 0x1U
#define IOMUXC_PIO4_16_HSP_LPSPI2_SOUT                                                          0x421C0140U, 0x5U, 0X421C8200U, 0x0U
#define IOMUXC_PIO4_16_MEDIA_DCIF_DATA16                                                        0x421C0140U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_16_HSP_eFlexPWM3_PWM_B3                                                     0x421C0140U, 0x8U, 0X421C8194U, 0x0U
#define IOMUXC_PIO4_16_COMM_ENET_CRS                                                            0x421C0140U, 0xAU, 0X421C8080U, 0x1U
#define IOMUXC_PIO4_16_HSP_XBAR1_INOUT16                                                        0x421C0140U, 0xBU, 0X421C8374U, 0x2U

#define IOMUXC_PIO4_17_HSP_GPIO2_GPIO17                                                         0x421C0144U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_17_COMM_ENET_QOS_TX_EN                                                      0x421C0144U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_17_HSP_FLEXIO2_FXIO_D17                                                     0x421C0144U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_17_AUDIO_SAI2_RX_DATA1                                                      0x421C0144U, 0x3U, 0X421C8034U, 0x1U
#define IOMUXC_PIO4_17_MEDIA_CSI_DATA06                                                         0x421C0144U, 0x4U, 0X421C8408U, 0x1U
#define IOMUXC_PIO4_17_HSP_LPSPI2_SIN                                                           0x421C0144U, 0x5U, 0X421C81FCU, 0x0U
#define IOMUXC_PIO4_17_MEDIA_DCIF_DATA17                                                        0x421C0144U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_17_HSP_eFlexPWM3_PWM_X0                                                     0x421C0144U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_17_HSP_FlexCAN2_CAN_TX                                                      0x421C0144U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_17_COMM_ENET_COL                                                            0x421C0144U, 0xAU, 0X421C807CU, 0x1U
#define IOMUXC_PIO4_17_HSP_XBAR1_INOUT17                                                        0x421C0144U, 0xBU, 0X421C8378U, 0x2U

#define IOMUXC_PIO4_18_HSP_GPIO2_GPIO18                                                         0x421C0148U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_18_COMM_ENET_QOS_RX_DATA0                                                   0x421C0148U, 0x1U, 0X421C8060U, 0x1U
#define IOMUXC_PIO4_18_HSP_FLEXIO2_FXIO_D18                                                     0x421C0148U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_18_AUDIO_SAI2_TX_DATA1                                                      0x421C0148U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_18_MEDIA_CSI_DATA05                                                         0x421C0148U, 0x4U, 0X421C8404U, 0x1U
#define IOMUXC_PIO4_18_HSP_LPSPI2_PCS1                                                          0x421C0148U, 0x5U, 0X421C81ECU, 0x0U
#define IOMUXC_PIO4_18_MEDIA_DCIF_DATA18                                                        0x421C0148U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_18_HSP_eFlexPWM3_PWM_X1                                                     0x421C0148U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_18_HSP_FlexCAN2_CAN_RX                                                      0x421C0148U, 0x9U, 0X421C8108U, 0x1U
#define IOMUXC_PIO4_18_WAKE_EWM_OUT_B                                                           0x421C0148U, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO4_18_HSP_XBAR1_INOUT18                                                        0x421C0148U, 0xBU, 0X421C837CU, 0x2U

#define IOMUXC_PIO4_19_HSP_GPIO2_GPIO19                                                         0x421C014CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_19_COMM_ENET_QOS_RX_DATA1                                                   0x421C014CU, 0x1U, 0X421C8064U, 0x1U
#define IOMUXC_PIO4_19_HSP_FLEXIO2_FXIO_D19                                                     0x421C014CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_19_AUDIO_SAI2_MCLK                                                          0x421C014CU, 0x3U, 0X421C8028U, 0x1U
#define IOMUXC_PIO4_19_MEDIA_CSI_DATA04                                                         0x421C014CU, 0x4U, 0X421C8400U, 0x1U
#define IOMUXC_PIO4_19_MEDIA_DCIF_DATA19                                                        0x421C014CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_19_HSP_eFlexPWM3_PWM_X2                                                     0x421C014CU, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_19_HSP_SINC1_MBIT0                                                          0x421C014CU, 0xAU, 0X421C82A4U, 0x1U
#define IOMUXC_PIO4_19_HSP_XBAR1_INOUT19                                                        0x421C014CU, 0xBU, 0X421C8380U, 0x2U

#define IOMUXC_PIO4_20_HSP_GPIO2_GPIO20                                                         0x421C0150U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_20_COMM_ENET_QOS_MDIO                                                       0x421C0150U, 0x1U, 0X421C8054U, 0x1U
#define IOMUXC_PIO4_20_HSP_FLEXIO2_FXIO_D20                                                     0x421C0150U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_20_AUDIO_SAI2_RX_DATA0                                                      0x421C0150U, 0x3U, 0X421C8030U, 0x1U
#define IOMUXC_PIO4_20_MEDIA_CSI_DATA03                                                         0x421C0150U, 0x4U, 0X421C83FCU, 0x1U
#define IOMUXC_PIO4_20_MEDIA_DCIF_DATA20                                                        0x421C0150U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_20_HSP_eFlexPWM3_PWM_X3                                                     0x421C0150U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_20_HSP_LPUART4_RTS_B                                                        0x421C0150U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_20_HSP_SINC1_MBIT1                                                          0x421C0150U, 0xAU, 0X421C82A8U, 0x1U
#define IOMUXC_PIO4_20_HSP_XBAR1_INOUT20                                                        0x421C0150U, 0xBU, 0X421C8384U, 0x2U

#define IOMUXC_PIO4_21_HSP_GPIO2_GPIO21                                                         0x421C0154U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_21_COMM_ENET_QOS_MDC                                                        0x421C0154U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_21_HSP_FLEXIO2_FXIO_D21                                                     0x421C0154U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_21_AUDIO_SAI2_TX_DATA0                                                      0x421C0154U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_21_MEDIA_CSI_DATA02                                                         0x421C0154U, 0x4U, 0X421C83F8U, 0x1U
#define IOMUXC_PIO4_21_AUDIO_SPDIF_IN                                                           0x421C0154U, 0x5U, 0X421C8044U, 0x1U
#define IOMUXC_PIO4_21_MEDIA_DCIF_DATA21                                                        0x421C0154U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_21_HSP_eFlexPWM2_PWM_X0                                                     0x421C0154U, 0x8U, 0X421C8168U, 0x1U
#define IOMUXC_PIO4_21_HSP_LPUART4_CTS_B                                                        0x421C0154U, 0x9U, 0X421C826CU, 0x2U
#define IOMUXC_PIO4_21_HSP_SINC1_MBIT2                                                          0x421C0154U, 0xAU, 0X421C82ACU, 0x1U
#define IOMUXC_PIO4_21_HSP_XBAR1_INOUT21                                                        0x421C0154U, 0xBU, 0X421C8388U, 0x2U

#define IOMUXC_PIO4_22_HSP_GPIO2_GPIO22                                                         0x421C0158U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_22_COMM_ENET_QOS_TX_DATA2                                                   0x421C0158U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_22_HSP_FLEXIO2_FXIO_D22                                                     0x421C0158U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_22_AUDIO_SAI2_TX_BCLK                                                       0x421C0158U, 0x3U, 0X421C803CU, 0x1U
#define IOMUXC_PIO4_22_MEDIA_CSI_DATA01                                                         0x421C0158U, 0x4U, 0X421C83F4U, 0x1U
#define IOMUXC_PIO4_22_AUDIO_SPDIF_OUT                                                          0x421C0158U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_22_MEDIA_DCIF_DATA22                                                        0x421C0158U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_22_HSP_eFlexPWM2_PWM_X1                                                     0x421C0158U, 0x8U, 0X421C816CU, 0x1U
#define IOMUXC_PIO4_22_HSP_LPUART4_RXD                                                          0x421C0158U, 0x9U, 0X421C8270U, 0x2U
#define IOMUXC_PIO4_22_HSP_SINC1_MBIT3                                                          0x421C0158U, 0xAU, 0X421C82B0U, 0x1U
#define IOMUXC_PIO4_22_HSP_XBAR1_INOUT22                                                        0x421C0158U, 0xBU, 0X421C838CU, 0x2U

#define IOMUXC_PIO4_23_HSP_GPIO2_GPIO23                                                         0x421C015CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_23_COMM_ENET_QOS_TX_DATA3                                                   0x421C015CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_23_HSP_FLEXIO2_FXIO_D23                                                     0x421C015CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_23_AUDIO_SAI2_TX_SYNC                                                       0x421C015CU, 0x3U, 0X421C8040U, 0x1U
#define IOMUXC_PIO4_23_MEDIA_CSI_DATA00                                                         0x421C015CU, 0x4U, 0X421C83F0U, 0x1U
#define IOMUXC_PIO4_23_HSP_SINC1_MCLK_OUT0                                                      0x421C015CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_23_MEDIA_DCIF_DATA23                                                        0x421C015CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_23_HSP_eFlexPWM2_PWM_X2                                                     0x421C015CU, 0x8U, 0X421C8170U, 0x1U
#define IOMUXC_PIO4_23_HSP_LPUART4_TXD                                                          0x421C015CU, 0x9U, 0X421C8274U, 0x2U
#define IOMUXC_PIO4_23_HSP_SINC1_MCLK0                                                          0x421C015CU, 0xAU, 0X421C82B4U, 0x1U
#define IOMUXC_PIO4_23_HSP_XBAR1_INOUT23                                                        0x421C015CU, 0xBU, 0X421C8390U, 0x2U

#define IOMUXC_PIO4_24_HSP_GPIO2_GPIO24                                                         0x421C0160U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_24_COMM_ENET_QOS_RX_CLK                                                     0x421C0160U, 0x1U, 0X421C804CU, 0x1U
#define IOMUXC_PIO4_24_HSP_FLEXIO2_FXIO_D24                                                     0x421C0160U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_24_AUDIO_SAI2_RX_SYNC                                                       0x421C0160U, 0x3U, 0X421C8038U, 0x1U
#define IOMUXC_PIO4_24_MEDIA_CSI_MCLK                                                           0x421C0160U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_24_HSP_SINC1_MCLK_OUT1                                                      0x421C0160U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_24_MEDIA_DCIF_PIXEL_CLK                                                     0x421C0160U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_24_HSP_eFlexPWM2_PWM_X3                                                     0x421C0160U, 0x8U, 0X421C8174U, 0x1U
#define IOMUXC_PIO4_24_HSP_LPUART5_CTS_B                                                        0x421C0160U, 0x9U, 0X421C8278U, 0x2U
#define IOMUXC_PIO4_24_HSP_SINC1_MCLK1                                                          0x421C0160U, 0xAU, 0X421C82B8U, 0x1U
#define IOMUXC_PIO4_24_HSP_XBAR1_INOUT24                                                        0x421C0160U, 0xBU, 0X421C8394U, 0x2U

#define IOMUXC_PIO4_25_HSP_GPIO2_GPIO25                                                         0x421C0164U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_25_COMM_ENET_QOS_RX_DATA2                                                   0x421C0164U, 0x1U, 0X421C8068U, 0x1U
#define IOMUXC_PIO4_25_HSP_FLEXIO2_FXIO_D25                                                     0x421C0164U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_25_AUDIO_SAI2_RX_BCLK                                                       0x421C0164U, 0x3U, 0X421C802CU, 0x1U
#define IOMUXC_PIO4_25_MEDIA_CSI_HSYNC                                                          0x421C0164U, 0x4U, 0X421C8430U, 0x1U
#define IOMUXC_PIO4_25_HSP_SINC1_MCLK_OUT2                                                      0x421C0164U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_25_MEDIA_DCIF_HSYNC                                                         0x421C0164U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_25_COMM_TENBASET_PHY0_TX                                                    0x421C0164U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_25_HSP_LPUART5_RTS_B                                                        0x421C0164U, 0x9U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_25_HSP_SINC1_MCLK2                                                          0x421C0164U, 0xAU, 0X421C82BCU, 0x1U
#define IOMUXC_PIO4_25_HSP_XBAR1_INOUT25                                                        0x421C0164U, 0xBU, 0X421C8398U, 0x2U

#define IOMUXC_PIO4_26_HSP_GPIO2_GPIO26                                                         0x421C0168U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_26_COMM_ENET_QOS_RX_DATA3                                                   0x421C0168U, 0x1U, 0X421C806CU, 0x1U
#define IOMUXC_PIO4_26_HSP_FLEXIO2_FXIO_D26                                                     0x421C0168U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_26_MAIN_XSPI0_ECS                                                           0x421C0168U, 0x3U, 0X421C83ECU, 0x2U
#define IOMUXC_PIO4_26_MEDIA_CSI_VSYNC                                                          0x421C0168U, 0x4U, 0X421C8438U, 0x1U
#define IOMUXC_PIO4_26_AUDIO_MQS_MQS_LEFT                                                       0x421C0168U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_26_MEDIA_DCIF_VSYNC                                                         0x421C0168U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_26_COMM_TENBASET_PHY0_ED                                                    0x421C0168U, 0x7U, 0X421C80D0U, 0x1U
#define IOMUXC_PIO4_26_HSP_LPUART5_TXD                                                          0x421C0168U, 0x9U, 0X421C8280U, 0x2U
#define IOMUXC_PIO4_26_HSP_SINC1_MCLK3                                                          0x421C0168U, 0xAU, 0X421C82C0U, 0x1U
#define IOMUXC_PIO4_26_HSP_XBAR1_INOUT26                                                        0x421C0168U, 0xBU, 0X421C839CU, 0x2U

#define IOMUXC_PIO4_27_HSP_GPIO2_GPIO27                                                         0x421C016CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_27_COMM_ENET_QOS_RX_EN                                                      0x421C016CU, 0x1U, 0X421C8070U, 0x1U
#define IOMUXC_PIO4_27_HSP_FLEXIO2_FXIO_D27                                                     0x421C016CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_27_MAIN_TRACE_SWO                                                           0x421C016CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_27_MEDIA_CSI_PIXCLK                                                         0x421C016CU, 0x4U, 0X421C8434U, 0x1U
#define IOMUXC_PIO4_27_AUDIO_MQS_MQS_RIGHT                                                      0x421C016CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_27_MEDIA_DCIF_DE                                                            0x421C016CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO4_27_COMM_TENBASET_PHY0_RX                                                    0x421C016CU, 0x7U, 0X421C80D4U, 0x1U
#define IOMUXC_PIO4_27_HSP_LPUART5_RXD                                                          0x421C016CU, 0x9U, 0X421C827CU, 0x2U
#define IOMUXC_PIO4_27_HSP_SINC1_BREAK                                                          0x421C016CU, 0xAU, 0x00000000U, 0x0U
#define IOMUXC_PIO4_27_HSP_XBAR1_INOUT27                                                        0x421C016CU, 0xBU, 0X421C83A0U, 0x2U

#define IOMUXC_PIO5_0_HSP_GPIO3_GPIO0                                                           0x421C0180U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_0_MAIN_XSPI1_SS0_N                                                          0x421C0180U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_0_COMM_ENET_REF_CLK                                                         0x421C0180U, 0x4U, 0X421C8078U, 0x1U
#define IOMUXC_PIO5_0_MAIN_AHB_SRAMC_SRAMC_CS0                                                  0x421C0180U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_0_HSP_eFlexPWM3_PWM_A0                                                      0x421C0180U, 0x6U, 0X421C8178U, 0x1U
#define IOMUXC_PIO5_0_HSP_LPSPI2_PCS0                                                           0x421C0180U, 0x8U, 0X421C81E8U, 0x1U

#define IOMUXC_PIO5_1_HSP_GPIO3_GPIO1                                                           0x421C0184U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_1_MAIN_XSPI1_DATA0                                                          0x421C0184U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_1_COMM_ENET_TXD0                                                            0x421C0184U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_1_MAIN_AHB_SRAMC_SRAMC_DA00                                                 0x421C0184U, 0x5U, 0X421C83A4U, 0x1U
#define IOMUXC_PIO5_1_HSP_eFlexPWM3_PWM_B0                                                      0x421C0184U, 0x6U, 0X421C8188U, 0x1U
#define IOMUXC_PIO5_1_HSP_LPSPI2_SOUT                                                           0x421C0184U, 0x8U, 0X421C8200U, 0x1U

#define IOMUXC_PIO5_2_HSP_GPIO3_GPIO2                                                           0x421C0188U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_2_MAIN_XSPI1_DATA1                                                          0x421C0188U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_2_COMM_ENET_TXD1                                                            0x421C0188U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_2_MAIN_AHB_SRAMC_SRAMC_DA01                                                 0x421C0188U, 0x5U, 0X421C83A8U, 0x1U
#define IOMUXC_PIO5_2_HSP_eFlexPWM3_PWM_A1                                                      0x421C0188U, 0x6U, 0X421C817CU, 0x1U
#define IOMUXC_PIO5_2_HSP_LPSPI2_SIN                                                            0x421C0188U, 0x8U, 0X421C81FCU, 0x1U

#define IOMUXC_PIO5_3_HSP_GPIO3_GPIO3                                                           0x421C018CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_3_MAIN_XSPI1_DATA2                                                          0x421C018CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_3_COMM_ENET_TX_EN                                                           0x421C018CU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_3_MAIN_AHB_SRAMC_SRAMC_DA02                                                 0x421C018CU, 0x5U, 0X421C83ACU, 0x1U
#define IOMUXC_PIO5_3_HSP_eFlexPWM3_PWM_B1                                                      0x421C018CU, 0x6U, 0X421C818CU, 0x1U
#define IOMUXC_PIO5_3_HSP_LPSPI2_PCS2                                                           0x421C018CU, 0x8U, 0X421C81F0U, 0x1U

#define IOMUXC_PIO5_4_HSP_GPIO3_GPIO4                                                           0x421C0190U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_4_MAIN_XSPI1_DATA3                                                          0x421C0190U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_4_COMM_ENET_RXD0                                                            0x421C0190U, 0x4U, 0X421C808CU, 0x1U
#define IOMUXC_PIO5_4_MAIN_AHB_SRAMC_SRAMC_DA03                                                 0x421C0190U, 0x5U, 0X421C83B0U, 0x1U
#define IOMUXC_PIO5_4_HSP_eFlexPWM3_PWM_A2                                                      0x421C0190U, 0x6U, 0X421C8180U, 0x1U
#define IOMUXC_PIO5_4_HSP_LPSPI2_PCS3                                                           0x421C0190U, 0x8U, 0X421C81F4U, 0x1U

#define IOMUXC_PIO5_5_HSP_GPIO3_GPIO5                                                           0x421C0194U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_5_MAIN_XSPI1_SCLK0                                                          0x421C0194U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_5_COMM_ENET_RXD1                                                            0x421C0194U, 0x4U, 0X421C8090U, 0x1U
#define IOMUXC_PIO5_5_MAIN_AHB_SRAMC_SRAMC_DA04                                                 0x421C0194U, 0x5U, 0X421C83B4U, 0x1U
#define IOMUXC_PIO5_5_HSP_eFlexPWM3_PWM_B2                                                      0x421C0194U, 0x6U, 0X421C8190U, 0x1U
#define IOMUXC_PIO5_5_HSP_LPSPI2_SCK                                                            0x421C0194U, 0x8U, 0X421C81F8U, 0x1U

#define IOMUXC_PIO5_6_HSP_GPIO3_GPIO6                                                           0x421C0198U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_6_MAIN_XSPI1_DATA4                                                          0x421C0198U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_6_COMM_ENET_CRS                                                             0x421C0198U, 0x4U, 0X421C8080U, 0x2U
#define IOMUXC_PIO5_6_MAIN_AHB_SRAMC_SRAMC_DA05                                                 0x421C0198U, 0x5U, 0X421C83B8U, 0x1U
#define IOMUXC_PIO5_6_HSP_eFlexPWM3_PWM_A3                                                      0x421C0198U, 0x6U, 0X421C8184U, 0x1U
#define IOMUXC_PIO5_6_HSP_LPSPI2_PCS1                                                           0x421C0198U, 0x8U, 0X421C81ECU, 0x1U

#define IOMUXC_PIO5_7_HSP_GPIO3_GPIO7                                                           0x421C019CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_7_MAIN_XSPI1_DATA5                                                          0x421C019CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_7_COMM_ENET_RX_ER                                                           0x421C019CU, 0x4U, 0X421C80A0U, 0x2U
#define IOMUXC_PIO5_7_MAIN_AHB_SRAMC_SRAMC_DA06                                                 0x421C019CU, 0x5U, 0X421C83BCU, 0x1U
#define IOMUXC_PIO5_7_HSP_eFlexPWM3_PWM_B3                                                      0x421C019CU, 0x6U, 0X421C8194U, 0x1U
#define IOMUXC_PIO5_7_HSP_LPSPI3_SIN                                                            0x421C019CU, 0x8U, 0X421C8218U, 0x0U

#define IOMUXC_PIO5_8_HSP_GPIO3_GPIO8                                                           0x421C01A0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_8_MAIN_XSPI1_DATA6                                                          0x421C01A0U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_8_COMM_ENET_MDIO                                                            0x421C01A0U, 0x4U, 0X421C8084U, 0x1U
#define IOMUXC_PIO5_8_MAIN_AHB_SRAMC_SRAMC_DA07                                                 0x421C01A0U, 0x5U, 0X421C83C0U, 0x1U
#define IOMUXC_PIO5_8_HSP_LPSPI3_SOUT                                                           0x421C01A0U, 0x8U, 0X421C821CU, 0x0U

#define IOMUXC_PIO5_9_HSP_GPIO3_GPIO9                                                           0x421C01A4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_9_MAIN_XSPI1_DATA7                                                          0x421C01A4U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_9_COMM_ENET_MDC                                                             0x421C01A4U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_9_MAIN_AHB_SRAMC_SRAMC_DA08                                                 0x421C01A4U, 0x5U, 0X421C83C4U, 0x1U
#define IOMUXC_PIO5_9_HSP_LPSPI3_SCK                                                            0x421C01A4U, 0x8U, 0X421C8214U, 0x0U

#define IOMUXC_PIO5_10_HSP_GPIO3_GPIO10                                                         0x421C01A8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_10_MAIN_XSPI1_DQS0                                                          0x421C01A8U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_10_COMM_FlexSPI_FLR_XSPI_FLR_CS                                              0x421C01A8U, 0x3U, 0X421C80D8U, 0x0U
#define IOMUXC_PIO5_10_MAIN_AHB_SRAMC_SRAMC_DA09                                                0x421C01A8U, 0x5U, 0X421C83C8U, 0x1U
#define IOMUXC_PIO5_10_HSP_LPSPI3_PCS0                                                          0x421C01A8U, 0x8U, 0X421C8204U, 0x0U

#define IOMUXC_PIO5_11_HSP_GPIO3_GPIO11                                                         0x421C01ACU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_11_MAIN_XSPI1_SCLK0_N                                                       0x421C01ACU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_11_MAIN_XSPI1_SS1_N                                                         0x421C01ACU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_11_COMM_FlexSPI_FLR_XSPI_FLR_CLK                                              0x421C01ACU, 0x3U, 0X421C8100U, 0x0U
#define IOMUXC_PIO5_11_COMM_ENET_TXD2                                                           0x421C01ACU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_11_MAIN_AHB_SRAMC_SRAMC_DA10                                                0x421C01ACU, 0x5U, 0X421C83CCU, 0x1U
#define IOMUXC_PIO5_11_HSP_LPSPI3_PCS1                                                          0x421C01ACU, 0x8U, 0X421C8208U, 0x0U

#define IOMUXC_PIO5_12_HSP_GPIO3_GPIO12                                                         0x421C01B0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_12_MAIN_XSPI1_DATA8                                                         0x421C01B0U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_12_COMM_FlexSPI_FLR_XSPI_FLR_DATA0                                              0x421C01B0U, 0x3U, 0X421C80E0U, 0x0U
#define IOMUXC_PIO5_12_COMM_ENET_TXD3                                                           0x421C01B0U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_12_MAIN_AHB_SRAMC_SRAMC_DA11                                                0x421C01B0U, 0x5U, 0X421C83D0U, 0x1U
#define IOMUXC_PIO5_12_HSP_SINC0_MCLK_OUT0                                                      0x421C01B0U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_12_HSP_SINC0_MCLK0                                                          0x421C01B0U, 0x7U, 0X421C8294U, 0x1U
#define IOMUXC_PIO5_12_HSP_LPSPI3_PCS2                                                          0x421C01B0U, 0x8U, 0X421C820CU, 0x0U
#define IOMUXC_PIO5_12_HSP_FLEXIO0_FXIO_D28                                                     0x421C01B0U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_13_HSP_GPIO3_GPIO13                                                         0x421C01B4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_13_MAIN_XSPI1_DATA9                                                         0x421C01B4U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_13_COMM_FlexSPI_FLR_XSPI_FLR_DATA1                                              0x421C01B4U, 0x3U, 0X421C80E4U, 0x0U
#define IOMUXC_PIO5_13_MAIN_AHB_SRAMC_SRAMC_DA12                                                0x421C01B4U, 0x5U, 0X421C83D4U, 0x1U
#define IOMUXC_PIO5_13_HSP_SINC0_MCLK_OUT1                                                      0x421C01B4U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_13_HSP_SINC0_MCLK1                                                          0x421C01B4U, 0x7U, 0X421C8298U, 0x1U
#define IOMUXC_PIO5_13_HSP_LPSPI3_PCS3                                                          0x421C01B4U, 0x8U, 0X421C8210U, 0x0U
#define IOMUXC_PIO5_13_HSP_FLEXIO0_FXIO_D29                                                     0x421C01B4U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_14_HSP_GPIO3_GPIO14                                                         0x421C01B8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_14_MAIN_XSPI1_DATA10                                                        0x421C01B8U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_14_COMM_FlexSPI_FLR_XSPI_FLR_DATA2                                              0x421C01B8U, 0x3U, 0X421C80E8U, 0x0U
#define IOMUXC_PIO5_14_COMM_ENET_RX_CLK                                                         0x421C01B8U, 0x4U, 0X421C8088U, 0x1U
#define IOMUXC_PIO5_14_MAIN_AHB_SRAMC_SRAMC_DA13                                                0x421C01B8U, 0x5U, 0X421C83D8U, 0x1U
#define IOMUXC_PIO5_14_HSP_SINC0_MCLK_OUT2                                                      0x421C01B8U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_14_HSP_SINC0_MCLK2                                                          0x421C01B8U, 0x7U, 0X421C829CU, 0x1U
#define IOMUXC_PIO5_14_HSP_LPSPI4_SIN                                                           0x421C01B8U, 0x8U, 0X421C8234U, 0x0U
#define IOMUXC_PIO5_14_HSP_FLEXIO0_FXIO_D30                                                     0x421C01B8U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_15_HSP_GPIO3_GPIO15                                                         0x421C01BCU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_15_MAIN_XSPI1_DATA11                                                        0x421C01BCU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_15_COMM_uSDHC1_CLK                                                          0x421C01BCU, 0x2U, 0X421C80B8U, 0x0U
#define IOMUXC_PIO5_15_COMM_FlexSPI_FLR_XSPI_FLR_DATA3                                              0x421C01BCU, 0x3U, 0X421C80ECU, 0x0U
#define IOMUXC_PIO5_15_COMM_ENET_RXD2                                                           0x421C01BCU, 0x4U, 0X421C8094U, 0x1U
#define IOMUXC_PIO5_15_MAIN_AHB_SRAMC_SRAMC_DA14                                                0x421C01BCU, 0x5U, 0X421C83DCU, 0x1U
#define IOMUXC_PIO5_15_HSP_SINC0_MCLK3                                                          0x421C01BCU, 0x7U, 0X421C82A0U, 0x1U
#define IOMUXC_PIO5_15_HSP_LPSPI4_SOUT                                                          0x421C01BCU, 0x8U, 0X421C8238U, 0x0U
#define IOMUXC_PIO5_15_HSP_FLEXIO0_FXIO_D31                                                     0x421C01BCU, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_16_HSP_GPIO3_GPIO16                                                         0x421C01C0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_16_MAIN_XSPI1_DQS1                                                          0x421C01C0U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_16_COMM_uSDHC1_CMD                                                          0x421C01C0U, 0x2U, 0X421C80BCU, 0x0U
#define IOMUXC_PIO5_16_COMM_FlexSPI_FLR_XSPI_FLR_DQS                                              0x421C01C0U, 0x3U, 0X421C80DCU, 0x0U
#define IOMUXC_PIO5_16_COMM_ENET_RXD3                                                           0x421C01C0U, 0x4U, 0X421C8098U, 0x1U
#define IOMUXC_PIO5_16_MAIN_AHB_SRAMC_SRAMC_DA15                                                0x421C01C0U, 0x5U, 0X421C83E0U, 0x1U
#define IOMUXC_PIO5_16_HSP_SINC0_MBIT0                                                          0x421C01C0U, 0x7U, 0X421C8284U, 0x1U
#define IOMUXC_PIO5_16_HSP_LPSPI4_SCK                                                           0x421C01C0U, 0x8U, 0X421C8230U, 0x0U

#define IOMUXC_PIO5_17_HSP_GPIO3_GPIO17                                                         0x421C01C4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_17_MAIN_XSPI1_DATA12                                                        0x421C01C4U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_17_COMM_uSDHC1_DAT0                                                         0x421C01C4U, 0x2U, 0X421C80C0U, 0x0U
#define IOMUXC_PIO5_17_COMM_FlexSPI_FLR_XSPI_FLR_DATA4                                              0x421C01C4U, 0x3U, 0X421C80F0U, 0x0U
#define IOMUXC_PIO5_17_COMM_ENET_RX_EN                                                          0x421C01C4U, 0x4U, 0X421C809CU, 0x1U
#define IOMUXC_PIO5_17_MAIN_AHB_SRAMC_SRAMC_WEB                                                 0x421C01C4U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_17_HSP_SINC0_MBIT1                                                          0x421C01C4U, 0x7U, 0X421C8288U, 0x1U
#define IOMUXC_PIO5_17_HSP_LPSPI4_PCS0                                                          0x421C01C4U, 0x8U, 0X421C8220U, 0x0U
#define IOMUXC_PIO5_17_HSP_FLEXIO2_FXIO_D28                                                     0x421C01C4U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_18_HSP_GPIO3_GPIO18                                                         0x421C01C8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_18_MAIN_XSPI1_DATA13                                                        0x421C01C8U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_18_COMM_uSDHC1_DAT1                                                         0x421C01C8U, 0x2U, 0X421C80C4U, 0x0U
#define IOMUXC_PIO5_18_COMM_FlexSPI_FLR_XSPI_FLR_DATA5                                              0x421C01C8U, 0x3U, 0X421C80F4U, 0x0U
#define IOMUXC_PIO5_18_MAIN_AHB_SRAMC_SRAMC_OEB                                                 0x421C01C8U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_18_HSP_SINC0_MBIT2                                                          0x421C01C8U, 0x7U, 0X421C828CU, 0x1U
#define IOMUXC_PIO5_18_HSP_LPSPI4_PCS1                                                          0x421C01C8U, 0x8U, 0X421C8224U, 0x0U
#define IOMUXC_PIO5_18_HSP_FLEXIO2_FXIO_D29                                                     0x421C01C8U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_19_HSP_GPIO3_GPIO19                                                         0x421C01CCU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_19_MAIN_XSPI1_DATA14                                                        0x421C01CCU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_19_COMM_uSDHC1_DAT2                                                         0x421C01CCU, 0x2U, 0X421C80C8U, 0x0U
#define IOMUXC_PIO5_19_COMM_FlexSPI_FLR_XSPI_FLR_DATA6                                              0x421C01CCU, 0x3U, 0X421C80F8U, 0x0U
#define IOMUXC_PIO5_19_MAIN_AHB_SRAMC_SRAMC_ADVB                                                0x421C01CCU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_19_HSP_SINC0_MBIT3                                                          0x421C01CCU, 0x7U, 0X421C8290U, 0x1U
#define IOMUXC_PIO5_19_HSP_LPSPI4_PCS2                                                          0x421C01CCU, 0x8U, 0X421C8228U, 0x0U
#define IOMUXC_PIO5_19_HSP_FLEXIO2_FXIO_D30                                                     0x421C01CCU, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO5_20_HSP_GPIO3_GPIO20                                                         0x421C01D0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_20_MAIN_XSPI1_DATA15                                                        0x421C01D0U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_20_COMM_uSDHC1_DAT3                                                         0x421C01D0U, 0x2U, 0X421C80CCU, 0x0U
#define IOMUXC_PIO5_20_COMM_FlexSPI_FLR_XSPI_FLR_DATA7                                              0x421C01D0U, 0x3U, 0X421C80FCU, 0x0U
#define IOMUXC_PIO5_20_MAIN_AHB_SRAMC_SRAMC_WP0                                                 0x421C01D0U, 0x5U, 0X421C83E4U, 0x2U
#define IOMUXC_PIO5_20_HSP_SINC0_BREAK                                                          0x421C01D0U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO5_20_HSP_LPSPI4_PCS3                                                          0x421C01D0U, 0x8U, 0X421C822CU, 0x0U
#define IOMUXC_PIO5_20_HSP_FLEXIO2_FXIO_D31                                                     0x421C01D0U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO6_0_HSP_GPIO4_GPIO0                                                           0x421C0200U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_0_MAIN_XSPI0_SCLK0                                                          0x421C0200U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_0_HSP_LPSPI3_SCK                                                            0x421C0200U, 0x8U, 0X421C8214U, 0x1U

#define IOMUXC_PIO6_1_HSP_GPIO4_GPIO1                                                           0x421C0204U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_1_MAIN_XSPI0_SS0_N                                                          0x421C0204U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_1_HSP_LPSPI3_PCS0                                                           0x421C0204U, 0x8U, 0X421C8204U, 0x1U

#define IOMUXC_PIO6_2_HSP_GPIO4_GPIO2                                                           0x421C0208U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_2_MAIN_XSPI0_DATA0                                                          0x421C0208U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_2_HSP_LPSPI3_SOUT                                                           0x421C0208U, 0x8U, 0X421C821CU, 0x1U

#define IOMUXC_PIO6_3_HSP_GPIO4_GPIO3                                                           0x421C020CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_3_MAIN_XSPI0_DATA1                                                          0x421C020CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_3_HSP_LPSPI3_SIN                                                            0x421C020CU, 0x8U, 0X421C8218U, 0x1U

#define IOMUXC_PIO6_4_HSP_GPIO4_GPIO4                                                           0x421C0210U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_4_MAIN_XSPI0_DATA2                                                          0x421C0210U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_4_HSP_LPSPI3_PCS2                                                           0x421C0210U, 0x8U, 0X421C820CU, 0x1U

#define IOMUXC_PIO6_5_HSP_GPIO4_GPIO5                                                           0x421C0214U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_5_MAIN_XSPI0_DATA3                                                          0x421C0214U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_5_HSP_LPSPI3_PCS3                                                           0x421C0214U, 0x8U, 0X421C8210U, 0x1U

#define IOMUXC_PIO6_6_HSP_GPIO4_GPIO6                                                           0x421C0218U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_6_MAIN_XSPI0_DQS0                                                           0x421C0218U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_6_HSP_LPSPI4_PCS3                                                           0x421C0218U, 0x8U, 0X421C822CU, 0x1U

#define IOMUXC_PIO6_7_HSP_GPIO4_GPIO7                                                           0x421C021CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_7_MAIN_XSPI0_DATA4                                                          0x421C021CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_7_COMM_uSDHC0_RESET_B                                                       0x421C021CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_7_HSP_eFlexPWM2_PWM_A0                                                      0x421C021CU, 0x5U, 0X421C8148U, 0x2U
#define IOMUXC_PIO6_7_HSP_LPSPI4_SOUT                                                           0x421C021CU, 0x8U, 0X421C8238U, 0x1U
#define IOMUXC_PIO6_7_HSP_LPUART3_TXD                                                           0x421C021CU, 0x9U, 0X421C8268U, 0x2U

#define IOMUXC_PIO6_8_HSP_GPIO4_GPIO8                                                           0x421C0220U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_8_MAIN_XSPI0_DATA5                                                          0x421C0220U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_8_COMM_uSDHC0_CD_B                                                          0x421C0220U, 0x3U, 0X421C80B0U, 0x1U
#define IOMUXC_PIO6_8_HSP_eFlexPWM2_PWM_B0                                                      0x421C0220U, 0x5U, 0X421C8158U, 0x2U
#define IOMUXC_PIO6_8_HSP_LPSPI4_SIN                                                            0x421C0220U, 0x8U, 0X421C8234U, 0x1U
#define IOMUXC_PIO6_8_HSP_LPUART3_RXD                                                           0x421C0220U, 0x9U, 0X421C8264U, 0x2U

#define IOMUXC_PIO6_9_HSP_GPIO4_GPIO9                                                           0x421C0224U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_9_MAIN_XSPI0_DATA6                                                          0x421C0224U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_9_COMM_uSDHC0_WP                                                            0x421C0224U, 0x3U, 0X421C80B4U, 0x1U
#define IOMUXC_PIO6_9_HSP_eFlexPWM2_PWM_A1                                                      0x421C0224U, 0x5U, 0X421C814CU, 0x2U
#define IOMUXC_PIO6_9_HSP_LPSPI4_PCS2                                                           0x421C0224U, 0x8U, 0X421C8228U, 0x1U
#define IOMUXC_PIO6_9_HSP_LPUART4_TXD                                                           0x421C0224U, 0x9U, 0X421C8274U, 0x3U

#define IOMUXC_PIO6_10_HSP_GPIO4_GPIO10                                                         0x421C0228U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_10_MAIN_XSPI0_DATA7                                                         0x421C0228U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_10_COMM_uSDHC0_VSELECT                                                      0x421C0228U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_10_HSP_eFlexPWM2_PWM_B1                                                     0x421C0228U, 0x5U, 0X421C815CU, 0x2U
#define IOMUXC_PIO6_10_HSP_LPSPI4_PCS3                                                          0x421C0228U, 0x8U, 0X421C822CU, 0x2U
#define IOMUXC_PIO6_10_HSP_LPUART4_RXD                                                          0x421C0228U, 0x9U, 0X421C8270U, 0x3U

#define IOMUXC_PIO6_11_HSP_GPIO4_GPIO11                                                         0x421C022CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_11_MAIN_XSPI0_SS1_N                                                         0x421C022CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_11_HSP_eFlexPWM2_PWM_A2                                                     0x421C022CU, 0x5U, 0X421C8150U, 0x1U
#define IOMUXC_PIO6_11_HSP_LPSPI4_PCS0                                                          0x421C022CU, 0x8U, 0X421C8220U, 0x1U
#define IOMUXC_PIO6_11_HSP_LPUART5_TXD                                                          0x421C022CU, 0x9U, 0X421C8280U, 0x3U

#define IOMUXC_PIO6_12_HSP_GPIO4_GPIO12                                                         0x421C0230U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_12_MAIN_XSPI0_SCLK0_N                                                       0x421C0230U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO6_12_HSP_eFlexPWM2_PWM_B2                                                     0x421C0230U, 0x5U, 0X421C8160U, 0x1U
#define IOMUXC_PIO6_12_HSP_LPSPI4_SCK                                                           0x421C0230U, 0x8U, 0X421C8230U, 0x1U
#define IOMUXC_PIO6_12_HSP_LPUART5_RXD                                                          0x421C0230U, 0x9U, 0X421C827CU, 0x3U

#define IOMUXC_PIO7_0_HSP_GPIO4_GPIO13                                                          0x421C0280U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_0_COMM_uSDHC0_DAT4                                                          0x421C0280U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_0_COMM_FlexSPI_FLR_XSPI_FLR_DATA0                                              0x421C0280U, 0x2U, 0X421C80E0U, 0x1U
#define IOMUXC_PIO7_0_COMM_uSDHC1_DAT0                                                          0x421C0280U, 0x3U, 0X421C80C0U, 0x1U
#define IOMUXC_PIO7_0_HSP_eFlexPWM3_PWM_A0                                                      0x421C0280U, 0x5U, 0X421C8178U, 0x2U
#define IOMUXC_PIO7_0_HSP_LPSPI3_SIN                                                            0x421C0280U, 0x8U, 0X421C8218U, 0x2U

#define IOMUXC_PIO7_1_HSP_GPIO4_GPIO14                                                          0x421C0284U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_1_COMM_uSDHC0_DAT5                                                          0x421C0284U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_1_COMM_FlexSPI_FLR_XSPI_FLR_DATA1                                              0x421C0284U, 0x2U, 0X421C80E4U, 0x1U
#define IOMUXC_PIO7_1_COMM_uSDHC1_DAT1                                                          0x421C0284U, 0x3U, 0X421C80C4U, 0x1U
#define IOMUXC_PIO7_1_HSP_eFlexPWM3_PWM_B0                                                      0x421C0284U, 0x5U, 0X421C8188U, 0x2U
#define IOMUXC_PIO7_1_HSP_LPSPI3_PCS2                                                           0x421C0284U, 0x8U, 0X421C820CU, 0x2U
#define IOMUXC_PIO7_1_HSP_LPUART3_TXD                                                           0x421C0284U, 0x9U, 0X421C8268U, 0x3U

#define IOMUXC_PIO7_2_HSP_GPIO4_GPIO15                                                          0x421C0288U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_2_COMM_uSDHC0_DAT6                                                          0x421C0288U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_2_COMM_FlexSPI_FLR_XSPI_FLR_DATA2                                              0x421C0288U, 0x2U, 0X421C80E8U, 0x1U
#define IOMUXC_PIO7_2_COMM_uSDHC1_DAT2                                                          0x421C0288U, 0x3U, 0X421C80C8U, 0x1U
#define IOMUXC_PIO7_2_HSP_eFlexPWM3_PWM_A1                                                      0x421C0288U, 0x5U, 0X421C817CU, 0x2U
#define IOMUXC_PIO7_2_HSP_LPSPI3_PCS1                                                           0x421C0288U, 0x8U, 0X421C8208U, 0x1U
#define IOMUXC_PIO7_2_HSP_LPUART3_RXD                                                           0x421C0288U, 0x9U, 0X421C8264U, 0x3U

#define IOMUXC_PIO7_3_HSP_GPIO4_GPIO16                                                          0x421C028CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_3_COMM_uSDHC0_DAT7                                                          0x421C028CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_3_COMM_FlexSPI_FLR_XSPI_FLR_DATA3                                              0x421C028CU, 0x2U, 0X421C80ECU, 0x1U
#define IOMUXC_PIO7_3_COMM_uSDHC1_DAT3                                                          0x421C028CU, 0x3U, 0X421C80CCU, 0x1U
#define IOMUXC_PIO7_3_HSP_eFlexPWM3_PWM_B1                                                      0x421C028CU, 0x5U, 0X421C818CU, 0x2U
#define IOMUXC_PIO7_3_HSP_LPSPI3_PCS0                                                           0x421C028CU, 0x8U, 0X421C8204U, 0x2U
#define IOMUXC_PIO7_3_HSP_LPUART3_CTS_B                                                         0x421C028CU, 0x9U, 0X421C8260U, 0x2U

#define IOMUXC_PIO7_4_HSP_GPIO4_GPIO17                                                          0x421C0290U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_4_COMM_uSDHC0_DS                                                            0x421C0290U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_4_COMM_FlexSPI_FLR_XSPI_FLR_DQS                                              0x421C0290U, 0x2U, 0X421C80DCU, 0x1U
#define IOMUXC_PIO7_4_COMM_uSDHC1_CMD                                                           0x421C0290U, 0x3U, 0X421C80BCU, 0x1U
#define IOMUXC_PIO7_4_HSP_eFlexPWM3_PWM_A2                                                      0x421C0290U, 0x5U, 0X421C8180U, 0x2U
#define IOMUXC_PIO7_4_HSP_LPSPI3_SOUT                                                           0x421C0290U, 0x8U, 0X421C821CU, 0x2U
#define IOMUXC_PIO7_4_HSP_LPUART3_RTS_B                                                         0x421C0290U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO7_5_HSP_GPIO4_GPIO18                                                          0x421C0294U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_5_COMM_FlexSPI_FLR_XSPI_FLR_CLK                                              0x421C0294U, 0x2U, 0X421C8100U, 0x1U
#define IOMUXC_PIO7_5_COMM_uSDHC1_CLK                                                           0x421C0294U, 0x3U, 0X421C80B8U, 0x1U
#define IOMUXC_PIO7_5_HSP_eFlexPWM3_PWM_B2                                                      0x421C0294U, 0x5U, 0X421C8190U, 0x2U
#define IOMUXC_PIO7_5_HSP_LPSPI3_SCK                                                            0x421C0294U, 0x8U, 0X421C8214U, 0x2U

#define IOMUXC_PIO7_6_HSP_GPIO4_GPIO19                                                          0x421C0298U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_6_COMM_uSDHC0_CMD                                                           0x421C0298U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_6_COMM_FlexSPI_FLR_XSPI_FLR_CS                                              0x421C0298U, 0x2U, 0X421C80D8U, 0x1U
#define IOMUXC_PIO7_6_HSP_eFlexPWM0_PWM_A0                                                      0x421C0298U, 0x5U, 0X421C810CU, 0x1U
#define IOMUXC_PIO7_6_HSP_LPSPI4_SOUT                                                           0x421C0298U, 0x8U, 0X421C8238U, 0x2U

#define IOMUXC_PIO7_7_HSP_GPIO4_GPIO20                                                          0x421C029CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_7_COMM_uSDHC0_CLK                                                           0x421C029CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_7_HSP_eFlexPWM0_PWM_B0                                                      0x421C029CU, 0x5U, 0X421C8118U, 0x1U
#define IOMUXC_PIO7_7_HSP_LPSPI4_SCK                                                            0x421C029CU, 0x8U, 0X421C8230U, 0x2U

#define IOMUXC_PIO7_8_HSP_GPIO4_GPIO21                                                          0x421C02A0U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_8_COMM_uSDHC0_DAT0                                                          0x421C02A0U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_8_COMM_FlexSPI_FLR_XSPI_FLR_DATA4                                              0x421C02A0U, 0x2U, 0X421C80F0U, 0x1U
#define IOMUXC_PIO7_8_HSP_eFlexPWM0_PWM_A1                                                      0x421C02A0U, 0x5U, 0X421C8110U, 0x1U
#define IOMUXC_PIO7_8_HSP_LPSPI4_SIN                                                            0x421C02A0U, 0x8U, 0X421C8234U, 0x2U
#define IOMUXC_PIO7_8_HSP_LPUART4_RTS_B                                                         0x421C02A0U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO7_9_HSP_GPIO4_GPIO22                                                          0x421C02A4U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_9_COMM_uSDHC0_DAT1                                                          0x421C02A4U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_9_COMM_FlexSPI_FLR_XSPI_FLR_DATA5                                              0x421C02A4U, 0x2U, 0X421C80F4U, 0x1U
#define IOMUXC_PIO7_9_HSP_eFlexPWM0_PWM_B1                                                      0x421C02A4U, 0x5U, 0X421C811CU, 0x1U
#define IOMUXC_PIO7_9_HSP_LPSPI4_PCS0                                                           0x421C02A4U, 0x8U, 0X421C8220U, 0x2U
#define IOMUXC_PIO7_9_HSP_LPUART4_CTS_B                                                         0x421C02A4U, 0x9U, 0X421C826CU, 0x3U

#define IOMUXC_PIO7_10_HSP_GPIO4_GPIO23                                                         0x421C02A8U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_10_COMM_uSDHC0_DAT2                                                         0x421C02A8U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_10_COMM_FlexSPI_FLR_XSPI_FLR_DATA6                                              0x421C02A8U, 0x2U, 0X421C80F8U, 0x1U
#define IOMUXC_PIO7_10_HSP_eFlexPWM0_PWM_A2                                                     0x421C02A8U, 0x5U, 0X421C8114U, 0x1U
#define IOMUXC_PIO7_10_HSP_LPSPI4_PCS1                                                          0x421C02A8U, 0x8U, 0X421C8224U, 0x1U
#define IOMUXC_PIO7_10_HSP_LPUART4_TXD                                                          0x421C02A8U, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO7_11_HSP_GPIO4_GPIO24                                                         0x421C02ACU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_11_COMM_uSDHC0_DAT3                                                         0x421C02ACU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO7_11_COMM_FlexSPI_FLR_XSPI_FLR_DATA7                                              0x421C02ACU, 0x2U, 0X421C80FCU, 0x1U
#define IOMUXC_PIO7_11_HSP_eFlexPWM0_PWM_B2                                                     0x421C02ACU, 0x5U, 0X421C8120U, 0x1U
#define IOMUXC_PIO7_11_HSP_LPSPI4_PCS2                                                          0x421C02ACU, 0x8U, 0X421C8228U, 0x2U
#define IOMUXC_PIO7_11_HSP_LPUART4_RXD                                                          0x421C02ACU, 0x9U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_0_WAKE_GPIO0_GPIO0                                                          0x46220000U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_0_WAKE_CMP3_OUT                                                             0x46220000U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_0_WAKE_LPI2C0_SDA                                                           0x46220000U, 0x2U, 0X4622800CU, 0x0U
#define IOMUXC_PIO1_0_WAKE_LPSPI0_SIN                                                           0x46220000U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_0_WAKE_I3C_SDA                                                              0x46220000U, 0x4U, 0X46228004U, 0x0U
#define IOMUXC_PIO1_0_WAKE_LPUART1_CTS_B                                                        0x46220000U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_0_WAKE_MICFIL_PDM_DATA01                                                    0x46220000U, 0x6U, 0X46228010U, 0x0U
#define IOMUXC_PIO1_0_WAKE_LPTMR0_ALT0                                                          0x46220000U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_0_WAKE_QTPM0_CH0                                                            0x46220000U, 0x8U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_1_WAKE_GPIO0_GPIO1                                                          0x46220004U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_CMP2_OUT                                                             0x46220004U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_LPI2C0_SCL                                                           0x46220004U, 0x2U, 0X46228008U, 0x0U
#define IOMUXC_PIO1_1_WAKE_LPSPI0_PCS0                                                          0x46220004U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_I3C_SCL                                                              0x46220004U, 0x4U, 0X46228000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_LPUART1_RTS_B                                                        0x46220004U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_MICFIL_PDM_CLK                                                       0x46220004U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_LPTMR0_ALT1                                                          0x46220004U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_1_WAKE_QTPM0_CH1                                                            0x46220004U, 0x8U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_2_WAKE_GPIO0_GPIO2                                                          0x46220008U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_2_WAKE_CMP1_OUT                                                             0x46220008U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_2_WAKE_LPSPI0_SCK                                                           0x46220008U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_2_WAKE_I3C_PUR                                                              0x46220008U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_2_WAKE_LPUART1_TXD                                                          0x46220008U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_2_WAKE_MICFIL_PDM_DATA01                                                    0x46220008U, 0x6U, 0X46228010U, 0x1U
#define IOMUXC_PIO1_2_WAKE_LPTMR0_ALT2                                                          0x46220008U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_2_WAKE_QTPM0_CH2                                                            0x46220008U, 0x8U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_3_WAKE_GPIO0_GPIO3                                                          0x4622000CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_CMP0_OUT                                                             0x4622000CU, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_EWM_OUT_B                                                            0x4622000CU, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_LPSPI0_SOUT                                                          0x4622000CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_XBAR_INOUT0                                                          0x4622000CU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_LPUART1_RXD                                                          0x4622000CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_MICFIL_PDM_CLK                                                       0x4622000CU, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_LPTMR0_ALT3                                                          0x4622000CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_3_WAKE_QTPM0_CH3                                                            0x4622000CU, 0x8U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_4_WAKE_GPIO0_GPIO4                                                          0x46220010U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_4_BOOT_MODE0                                                                0x46220010U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_4_WAKE_XBAR_INOUT1                                                          0x46220010U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_4_WAKE_LPUART0_TXD                                                          0x46220010U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_4_WAKE_FREQME_CLK_OUT                                                       0x46220010U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_4_WAKE_LPTMR1_ALT0                                                          0x46220010U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_4_WAKE_QTPM0_CH4                                                            0x46220010U, 0x8U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_5_WAKE_GPIO0_GPIO5                                                          0x46220014U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_5_BOOT_MODE1                                                                0x46220014U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_5_WAKE_XBAR_INOUT2                                                          0x46220014U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_5_WAKE_LPUART0_RXD                                                          0x46220014U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_5_VBAT_RTC_CLKOUT                                                           0x46220014U, 0x6U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_5_WAKE_LPTMR1_ALT1                                                          0x46220014U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_5_WAKE_QTPM0_CH5                                                            0x46220014U, 0x8U, 0x00000000U, 0x0U

#define IOMUXC_PIO1_6_WAKE_GPIO0_GPIO6                                                          0x46220018U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_6_WAKE_LPI2C0_SDA                                                           0x46220018U, 0x2U, 0X4622800CU, 0x1U
#define IOMUXC_PIO1_6_WAKE_XBAR_INOUT3                                                          0x46220018U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_6_WAKE_LPUART0_CTS_B                                                        0x46220018U, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_6_WAKE_LPTMR1_ALT2                                                          0x46220018U, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_6_WAKE_QTPM0_CH6                                                            0x46220018U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_6_JTAGC_TCK                                                                 0x46220018U, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO1_7_WAKE_GPIO0_GPIO7                                                          0x4622001CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_7_WAKE_LPI2C0_SCL                                                           0x4622001CU, 0x2U, 0X46228008U, 0x1U
#define IOMUXC_PIO1_7_WAKE_LPSPI0_PCS1                                                          0x4622001CU, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_7_WAKE_XBAR_INOUT4                                                          0x4622001CU, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_7_WAKE_LPUART0_RTS_B                                                        0x4622001CU, 0x5U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_7_WAKE_LPTMR1_ALT3                                                          0x4622001CU, 0x7U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_7_WAKE_QTPM0_CH7                                                            0x4622001CU, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_7_JTAGC_TMS                                                                 0x4622001CU, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO1_8_WAKE_GPIO0_GPIO8                                                          0x46220020U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_8_WAKE_I3C_SDA                                                              0x46220020U, 0x1U, 0X46228004U, 0x1U
#define IOMUXC_PIO1_8_WAKE_LPI2C1_SDA                                                           0x46220020U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_8_WAKE_LPSPI0_PCS2                                                          0x46220020U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_8_WAKE_XBAR_INOUT5                                                          0x46220020U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_8_JTAGC_TDI                                                                 0x46220020U, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO1_9_WAKE_GPIO0_GPIO9                                                          0x46220024U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_9_WAKE_I3C_SCL                                                              0x46220024U, 0x1U, 0X46228000U, 0x1U
#define IOMUXC_PIO1_9_WAKE_LPI2C1_SCL                                                           0x46220024U, 0x2U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_9_WAKE_LPSPI0_PCS3                                                          0x46220024U, 0x3U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_9_WAKE_XBAR_INOUT6                                                          0x46220024U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_9_MAIN_TRACE_SWO                                                            0x46220024U, 0x8U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_9_JTAGC_TDO                                                                 0x46220024U, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO1_10_WAKE_GPIO0_GPIO10                                                        0x46220028U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_10_WAKE_I3C_PUR                                                             0x46220028U, 0x1U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_10_WAKE_XBAR_INOUT7                                                         0x46220028U, 0x4U, 0x00000000U, 0x0U
#define IOMUXC_PIO1_10_JTAGC_TRSTN                                                              0x46220028U, 0xFU, 0x00000000U, 0x0U

#define IOMUXC_PIO0_0_VBAT_GPIO0_GPIO0                                                          0x46360000U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO0_0_PMIC_MODE0                                                                0x46360000U, 0x1U, 0x00000000U, 0x0U

#define IOMUXC_PIO0_1_VBAT_GPIO0_GPIO1                                                          0x46360004U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO0_1_PMIC_MODE1                                                                0x46360004U, 0x1U, 0x00000000U, 0x0U

#define IOMUXC_PIO0_2_VBAT_GPIO0_GPIO2                                                          0x46360008U, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO0_2_RTC_TAMPER0                                                               0x46360008U, 0x1U, 0x00000000U, 0x0U

#define IOMUXC_PIO0_3_VBAT_GPIO0_GPIO3                                                          0x4636000CU, 0x0U, 0x00000000U, 0x0U
#define IOMUXC_PIO0_3_RTC_TAMPER1                                                               0x4636000CU, 0x1U, 0x00000000U, 0x0U

#define IOMUXC_PIO0_4_VBAT_GPIO0_GPIO4                                                          0x46360010U, 0x0U, 0x00000000U, 0x0U

/*@}*/

#define IOMUXC_GPR_SAIMCLK_LOWBITMASK (0x7U)
#define IOMUXC_GPR_SAIMCLK_HIGHBITMASK (0x3U)

typedef enum _iomuxc_mqs_pwm_oversample_rate
{
    kIOMUXC_MqsPwmOverSampleRate32 = 0, /* MQS PWM over sampling rate 32. */
    kIOMUXC_MqsPwmOverSampleRate64 = 1  /* MQS PWM over sampling rate 64. */
} iomuxc_mqs_pwm_oversample_rate_t;

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus */

/*! @name Configuration */
/*@{*/

/*!
 * @brief Sets the IOMUXC pin mux mode.
 * @note The first five parameters can be filled with the pin function ID macros.
 *
 * This is an example to set the PTA6 as the lpuart0_tx:
 * @code
 * IOMUXC_SetPinMux(IOMUXC_PTA6_LPUART0_TX, 0);
 * @endcode
 *
 * This is an example to set the PTA0 as GPIOA0:
 * @code
 * IOMUXC_SetPinMux(IOMUXC_PTA0_GPIOA0, 0);
 * @endcode
 *
 * @param muxRegister  The pin mux register.
 * @param muxMode      The pin mux mode.
 * @param inputRegister The select input register.
 * @param inputDaisy   The input daisy.
 * @param configRegister  The config register.
 * @param inputOnfield   Software input on field.
 */
static inline void IOMUXC_SetPin_Mux_Config(uint32_t muxRegister,
                                    uint32_t muxMode,
                                    uint32_t inputRegister,
                                    uint32_t inputDaisy,
                                    uint32_t configValue)
{
    /*mux and config are now in the same register*/
    if (muxRegister != 0UL)
    {
        *((volatile uint32_t *)muxRegister) = IOMUXC_PIO_MUX_MODE(muxMode) | configValue;
    }

    if (inputRegister != 0UL)
    {
        *((volatile uint32_t *)inputRegister) = inputDaisy;
    }
}

/*@}*/

#if defined(__cplusplus)
}
#endif /*_cplusplus */

/*! @}*/

#endif /* _FSL_IOMUXC_H_ */
