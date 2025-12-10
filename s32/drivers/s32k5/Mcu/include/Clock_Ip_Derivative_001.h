/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_DERIVATIVE_001_H
#define CLOCK_IP_DERIVATIVE_001_H

/**
*   @file       Clock_Ip_Derivative_001.h
*   @version    0.8.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_DERIVATIVE_001_VENDOR_ID                       43
#define CLOCK_IP_DERIVATIVE_001_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_DERIVATIVE_001_AR_RELEASE_MINOR_VERSION        9
#define CLOCK_IP_DERIVATIVE_001_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_DERIVATIVE_001_SW_MAJOR_VERSION                0
#define CLOCK_IP_DERIVATIVE_001_SW_MINOR_VERSION                8
#define CLOCK_IP_DERIVATIVE_001_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/



  /* Implementation index macros */
#define CLOCK_IP_IRCOSC_CALLBACKS_COUNT                                       1U

#define CLOCK_IP_IRCOSC_OUT_CALLBACKS_COUNT                                   1U

#define CLOCK_IP_XOSC_CALLBACKS_COUNT                                         3U
#define CLOCK_IP_FXOSC_CTRL_OSCON_ALC_D_GM_SEL_EOCV_COMP_EN_OSC_BYP_OSC_STAT  1U
#define CLOCK_IP_SXOSC_CTRL_OSCON_GM_SEL_EOCV_CURR_PRG_STAT                   2U

#define CLOCK_IP_PLL_CALLBACKS_COUNT                                          2U
#define CLOCK_IP_PLL_POWERUP_RDIV_MFI_ENABLE_SPREADCTL_STEP_STOP_MFN_REF_CLK_SEL 1U

#define CLOCK_IP_FRACTIONAL_DIVIDER_CALLBACKS_COUNT                           2U
#define CLOCK_IP_DFS_BYPASS_CLKOUT_ENABLE_MFI_MFN                             1U

#define CLOCK_IP_SELECTOR_CALLBACKS_COUNT                                     4U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP                             1U
#define CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP_RMP_SW                      2U
#define CLOCK_IP_RTC_RTCC_CLKSELECT                                           3U

#define CLOCK_IP_DIVIDER_CALLBACKS_COUNT                                      4U
#define CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_POSTDIV                                1U
#define CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_DE_OUTPUT_DIV                          2U
#define CLOCK_IP_CGM_X_SLC_Y_DC_DE_DIV_UPD_STAT                               3U

#define CLOCK_IP_DIVIDER_TRIGGER_CALLBACKS_COUNT                              1U

#define CLOCK_IP_GATE_CALLBACKS_COUNT                                         2U
#define CLOCK_IP_GPR_X_PCTL_MODULE_PCTL_PCTL                                  1U

#define CLOCK_IP_PCFS_CALLBACKS_COUNT                                         1U

#define CLOCK_IP_CMU_CALLBACKS_COUNT                                          2U
#define CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS                            1U


  /* Selector index macros */
#define CLOCK_IP_SEL5_DSPI_CLK_INDEX                                          2U
#define CLOCK_IP_SEL13_ETH_TS_CLK_INDEX                                       4U
#define CLOCK_IP_SEL2_FLEXCAN_0to7_PE_CLK_INDEX                               3U
#define CLOCK_IP_SEL3_FLEXCAN_8to10_PE_CLK_INDEX                              5U
#define CLOCK_IP_SEL4_FLEXCAN_11to16_PE_CLK_INDEX                             6U
#define CLOCK_IP_SEL1_FLEXIO_CLK_INDEX                                        7U
#define CLOCK_IP_SEL6_LPE_CXPI_PE_CLK_INDEX                                   14U
#define CLOCK_IP_SEL4_LPE_FLEXCAN_PE_CLK_INDEX                                8U
#define CLOCK_IP_SEL3_LPE_LPI2C_MOD_CLK_INDEX                                 15U
#define CLOCK_IP_SEL1_LPE_LPSPI_MOD_CLK_INDEX                                 16U
#define CLOCK_IP_SEL2_LPE_LPUART_MOD_CLK_INDEX                                17U
#define CLOCK_IP_SEL5_LPE_STM_CLK_INDEX                                       9U
#define CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX                                   0U
#define CLOCK_IP_SEL1_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX                    20U
#define CLOCK_IP_SEL2_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX                     22U
#define CLOCK_IP_SEL1_PHY_ETH_CLK_INDEX                                       1U
#define CLOCK_IP_SEL0_SAI0_MCLK_INDEX                                         18U
#define CLOCK_IP_SEL0_SAI1_MCLK_INDEX                                         19U
#define CLOCK_IP_SEL10_SERDES_REF_CLK_INDEX                                   21U
#define CLOCK_IP_SEL6_STM0_CLK_INDEX                                          10U
#define CLOCK_IP_SEL7_STM1_CLK_INDEX                                          11U
#define CLOCK_IP_SEL8_STM2_CLK_INDEX                                          12U
#define CLOCK_IP_SEL9_STM3_CLK_INDEX                                          13U

  /* Selector and divider index macros */
#define CLOCK_IP_SEL0_NODIV_LPE_CLK_INDEX                                     0U
#define CLOCK_IP_SEL0_NODIV_PLT_CLK_INDEX                                     1U
#define CLOCK_IP_SEL3_DIV0_CAN_PE_CLK_INDEX                                   2U
#define CLOCK_IP_SEL10_DIV0_DFT_CLK_INDEX                                     3U
#define CLOCK_IP_SEL5_DIV0_DSPI_CLK_INDEX                                     4U
#define CLOCK_IP_SEL13_DIV0_ETH_TS_CLK_INDEX                                  5U
#define CLOCK_IP_SEL3_DIV0_ETH0_RX_CLK_INDEX                                  6U
#define CLOCK_IP_SEL4_DIV0_ETH0_TX_CLK_INDEX                                  7U
#define CLOCK_IP_SEL5_DIV0_ETH1_RX_CLK_INDEX                                  8U
#define CLOCK_IP_SEL6_DIV0_ETH1_TX_CLK_INDEX                                  9U
#define CLOCK_IP_SEL7_DIV0_ETH2_RX_CLK_INDEX                                  10U
#define CLOCK_IP_SEL8_DIV0_ETH2_TX_CLK_INDEX                                  11U
#define CLOCK_IP_SEL11_DIV0_ETH3_RX_CLK_INDEX                                 12U
#define CLOCK_IP_SEL12_DIV0_ETH3_TX_CLK_INDEX                                 13U
#define CLOCK_IP_SEL13_DIV0_ETH4_RX_CLK_INDEX                                 14U
#define CLOCK_IP_SEL14_DIV0_ETH4_TX_CLK_INDEX                                 15U
#define CLOCK_IP_SEL2_DIV0_FLEXCAN_0to7_PE_CLK_INDEX                          16U
#define CLOCK_IP_SEL3_DIV0_FLEXCAN_8to10_PE_CLK_INDEX                         17U
#define CLOCK_IP_SEL4_DIV0_FLEXCAN_11to16_PE_CLK_INDEX                        18U
#define CLOCK_IP_SEL1_DIV0_FLEXIO_CLK_INDEX                                   19U
#define CLOCK_IP_SEL6_DIV0_LPE_CXPI_PE_CLK_INDEX                              20U
#define CLOCK_IP_SEL6_DIV0_LPE_DIV1_UNGATED_CLK_INDEX                         21U
#define CLOCK_IP_SEL6_DIV0_LPE_DIV2_UNGATED_CLK_INDEX                         22U
#define CLOCK_IP_SEL6_DIV0_LPE_DIV3_UNGATED_CLK_INDEX                         23U
#define CLOCK_IP_SEL6_DIV0_LPE_DIV4_UNGATED_CLK_INDEX                         24U
#define CLOCK_IP_SEL4_DIV0_LPE_FLEXCAN_PE_CLK_INDEX                           25U
#define CLOCK_IP_SEL3_DIV0_LPE_LPI2C_MOD_CLK_INDEX                            26U
#define CLOCK_IP_SEL1_DIV0_LPE_LPSPI_MOD_CLK_INDEX                            27U
#define CLOCK_IP_SEL2_DIV0_LPE_LPUART_MOD_CLK_INDEX                           28U
#define CLOCK_IP_SEL5_DIV0_LPE_STM_CLK_INDEX                                  29U
#define CLOCK_IP_SEL6_NODIV_LPE_UNGATED_CLK_INDEX                             30U
#define CLOCK_IP_SEL1_DIV0_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX               31U
#define CLOCK_IP_SEL2_DIV0_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX                32U
#define CLOCK_IP_SEL4_DIV0_PERI_HIGH_SPEED_TRACE_CLK_INDEX                    33U
#define CLOCK_IP_SEL1_DIV0_PHY_ETH_CLK_INDEX                                  34U
#define CLOCK_IP_SEL0_NODIV_RR_RTC_CLK_INDEX                                  35U
#define CLOCK_IP_SEL0_DIV0_SAI0_MCLK_INDEX                                    36U
#define CLOCK_IP_SEL0_DIV0_SAI1_MCLK_INDEX                                    37U
#define CLOCK_IP_SEL9_DIV0_SERDES_AUX_CLK_INDEX                               38U
#define CLOCK_IP_SEL10_DIV0_SERDES_REF_CLK_INDEX                              39U
#define CLOCK_IP_SEL6_DIV0_STM0_CLK_INDEX                                     40U
#define CLOCK_IP_SEL7_DIV0_STM1_CLK_INDEX                                     41U
#define CLOCK_IP_SEL8_DIV0_STM2_CLK_INDEX                                     42U
#define CLOCK_IP_SEL9_DIV0_STM3_CLK_INDEX                                     43U
#define CLOCK_IP_SEL11_DIV0_TRACE_CLK_INDEX                                   44U
#define CLOCK_IP_SELECTOR_DIVIDER_TABLE_SIZE 45U



#define CLOCK_IP_SEL3_CAN_PE_CLK_INDEX                      0U
#define CLOCK_IP_SEL10_DFT_CLK_INDEX                        0U
#define CLOCK_IP_SEL3_ETH0_RX_CLK_INDEX                     0U
#define CLOCK_IP_SEL4_ETH0_TX_CLK_INDEX                     0U
#define CLOCK_IP_SEL5_ETH1_RX_CLK_INDEX                     0U
#define CLOCK_IP_SEL6_ETH1_TX_CLK_INDEX                     0U
#define CLOCK_IP_SEL7_ETH2_RX_CLK_INDEX                     0U
#define CLOCK_IP_SEL8_ETH2_TX_CLK_INDEX                     0U
#define CLOCK_IP_SEL11_ETH3_RX_CLK_INDEX                    0U
#define CLOCK_IP_SEL12_ETH3_TX_CLK_INDEX                    0U
#define CLOCK_IP_SEL13_ETH4_RX_CLK_INDEX                    0U
#define CLOCK_IP_SEL14_ETH4_TX_CLK_INDEX                    0U
#define CLOCK_IP_SEL4_PERI_HIGH_SPEED_TRACE_CLK_INDEX       0U
#define CLOCK_IP_SEL9_SERDES_AUX_CLK_INDEX                  0U
#define CLOCK_IP_SEL11_TRACE_CLK_INDEX                      0U
#define CLOCK_IP_SEL0_RR_RTC_CLK_INDEX                      0U
#define CLOCK_IP_SEL0_LPE_CLK_INDEX                         0U
#define CLOCK_IP_SEL0_PLT_CLK_INDEX                         0U

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef CLOCK_IP_DERIVATIVE_001_H */


