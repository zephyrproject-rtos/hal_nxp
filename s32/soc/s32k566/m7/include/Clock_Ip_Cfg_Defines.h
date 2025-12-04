/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file       Clock_Ip_Cfg_Defines.h
*   @version    0.8.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Driver
*   @{
*/

#ifndef CLOCK_IP_CFG_DEFINES_H
#define CLOCK_IP_CFG_DEFINES_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
 #include "S32K566_COMMON.h" 
 #include "S32K566_MC_CGM.h" 
 #include "S32K566_FXOSC.h" 
 #include "S32K566_SXOSC.h" 
 #include "S32K566_PLL.h" 
 #include "S32K566_MC_ME.h" 
 #include "S32K566_CMU_FC.h" 
 #include "S32K566_RTC.h" 
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_DEFINES_VENDOR_ID                       43
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        9
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION                0
#define CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION                8
#define CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define CLOCK_IP_DERIVATIVE_001
/**
* @brief            Platform used.
*/
#define CLOCK_IP_PLATFORM_001

/**
* @brief            Max number of internal oscillators
*/
#define CLOCK_IP_IRCOSCS_COUNT       (0U)

/**
* @brief            Max number of external oscillators
*/
#define CLOCK_IP_XOSCS_COUNT       (2U)

/**
* @brief            Max number of pll devices
*/
#define CLOCK_IP_PLLS_COUNT       (3U)

/**
* @brief            Max number of selectors
*/
#define CLOCK_IP_SELECTORS_COUNT       (41U)

/**
* @brief            Max number of dividers
*/
#define CLOCK_IP_DIVIDERS_COUNT       (53U)

/**
* @brief            Max number of fractional dividers
*/
#define CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT       (4U)

/**
* @brief            Max number of external clocks
*/
#define CLOCK_IP_EXT_CLKS_COUNT       (19U)

/**
* @brief            Max number of clock gates
*/
#define CLOCK_IP_GATES_COUNT       (323U)

/**
* @brief            Max number of clock monitoring units
*/
#define CLOCK_IP_CMUS_COUNT       (1U)

/**
* @brief            Max number of configured frequencies values
*/
#define CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT       (108U)

/**
* @brief            Number of clock configurations 0
*/
#define CLOCK_IP_CONFIGURED_XOSCS_0_NO       (2U)
#define CLOCK_IP_CONFIGURED_SELECTORS_0_NO       (1U)
#define CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_0_NO       (4U)
#define CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO       (19U)
#define CLOCK_IP_CONFIGURED_GATES_0_NO       (256U)
#define CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO       (107U)
#define CLOCK_IP_CONFIGURED_REGISTERS_0_NO       (7U)
#ifndef CLOCK_IP_CONFIGURED_REGISTERS_0_VS_0_NO
#define CLOCK_IP_CONFIGURED_REGISTERS_0_VS_0_NO    CLOCK_IP_CONFIGURED_REGISTERS_0_NO
#endif

/**
* @brief            Supported power mode.
*/
#define CLOCK_IP_HAS_RUN_MODE                0U

/**
* @brief            Firc frequency.
*/
#define CLOCK_IP_FIRC_FREQUENCY                400000000U

/**
* @brief            Sirc frequency.
*/
#define CLOCK_IP_SIRC_FREQUENCY                32000U

/**
* @brief            Clock ip supports clock frequency.
*/
#define CLOCK_IP_GET_FREQUENCY_API                (STD_ON)

/**
* @brief            Supports wait states configuration
*/
#define CLOCK_IP_SUPPORTS_WAIT_STATES                (STD_ON)


/**
* @brief            Default fxosc frequency.
*/
#define CLOCK_IP_DEFAULT_FXOSC_FREQUENCY                40000000U

/**
* @brief            Supported clocks.
*/
#define CLOCK_IP_HAS_FIRC_CLK         0U
#define CLOCK_IP_HAS_FIRCDIV2_CLK         1U
#define CLOCK_IP_HAS_SAFE_CLK         2U
#define CLOCK_IP_HAS_SIRC_CLK         3U
#define CLOCK_IP_HAS_FXOSC_CLK         4U
#define CLOCK_IP_HAS_SXOSC_CLK         5U
#define CLOCK_IP_HAS_gated_clk         6U
#define CLOCK_IP_HAS_fast_crystal_oscillator         7U
#define CLOCK_IP_HAS_slow_crystal_oscillator         8U
#define CLOCK_IP_HAS_eth0_mii_rx_ext_clk         9U
#define CLOCK_IP_HAS_eth0_mii_tx_ext_clk         10U
#define CLOCK_IP_HAS_eth0_rgmii_rx_ext_clk         11U
#define CLOCK_IP_HAS_eth0_rgmii_tx_ext_clk         12U
#define CLOCK_IP_HAS_eth0_rmii_ref_ext_clk         13U
#define CLOCK_IP_HAS_eth1_mii_rx_ext_clk         14U
#define CLOCK_IP_HAS_eth1_mii_tx_ext_clk         15U
#define CLOCK_IP_HAS_eth1_rgmii_rx_ext_clk         16U
#define CLOCK_IP_HAS_eth1_rgmii_tx_ext_clk         17U
#define CLOCK_IP_HAS_eth1_rmii_ref_ext_clk         18U
#define CLOCK_IP_HAS_eth2_mii_rx_ext_clk         19U
#define CLOCK_IP_HAS_eth2_mii_tx_ext_clk         20U
#define CLOCK_IP_HAS_eth2_rgmii_rx_ext_clk         21U
#define CLOCK_IP_HAS_eth2_rgmii_tx_ext_clk         22U
#define CLOCK_IP_HAS_eth2_rmii_ref_ext_clk         23U
#define CLOCK_IP_HAS_ts_1588_clk         24U
#define CLOCK_IP_HAS_PLL0_CLK         25U
#define CLOCK_IP_HAS_PLL0_DIV_CLK         26U
#define CLOCK_IP_HAS_PLL0_DIV0_CLK         27U
#define CLOCK_IP_HAS_PLL0_DIV4_CLK         28U
#define CLOCK_IP_HAS_PLL0_DFS0_CLK         29U
#define CLOCK_IP_HAS_PLL0_DFS1_CLK         30U
#define CLOCK_IP_HAS_PLL0_DFS2_CLK         31U
#define CLOCK_IP_HAS_PLL0_DFS3_CLK         32U
#define CLOCK_IP_HAS_PLL1_CLK         33U
#define CLOCK_IP_HAS_PLL1_DIV_CLK         34U
#define CLOCK_IP_HAS_PLL1_DIV0_CLK         35U
#define CLOCK_IP_HAS_CPE_PLL_CLK         36U
#define CLOCK_IP_HAS_CPE_DIV_CLK         37U
#define CLOCK_IP_HAS_CPE_DIV0_CLK         38U
#define CLOCK_IP_HAS_LPE_CLK         39U
#define CLOCK_IP_HAS_LPE_DIV1_CLK         40U
#define CLOCK_IP_HAS_LPE_DIV2_CLK         41U
#define CLOCK_IP_HAS_LPE_DIV4_CLK         42U
#define CLOCK_IP_HAS_LPE_DIV8_CLK         43U
#define CLOCK_IP_HAS_PLT_CLK         44U
#define CLOCK_IP_HAS_PLTCORE_CLK         45U
#define CLOCK_IP_HAS_PLTDIV1_CLK         46U
#define CLOCK_IP_HAS_PLTDIV2_CLK         47U
#define CLOCK_IP_HAS_PLTDIV4_CLK         48U
#define CLOCK_IP_FEATURE_PRODUCERS_NO         49U
#define CLOCK_IP_HAS_ACP_DMA3_H_CLK         50U
#define CLOCK_IP_HAS_ACP_DMA3_IPG_CLK         51U
#define CLOCK_IP_HAS_ADC0_IPG_CLK         52U
#define CLOCK_IP_HAS_ADC1_IPG_CLK         53U
#define CLOCK_IP_HAS_BCTU_IPG_CLK         54U
#define CLOCK_IP_HAS_BCTU_IPS_CLK         55U
#define CLOCK_IP_HAS_CAN_HUB_IPG_CLK         56U
#define CLOCK_IP_HAS_CAN_PE_CLK         57U
#define CLOCK_IP_HAS_CLKBIST_IPG_CLK         58U
#define CLOCK_IP_HAS_CRC0_IPG_CLK         59U
#define CLOCK_IP_HAS_CRC1_IPG_CLK         60U
#define CLOCK_IP_HAS_CSTCU_IPG_CLK         61U
#define CLOCK_IP_HAS_DIG_PHY0_CLK         62U
#define CLOCK_IP_HAS_DIG_PHY1_CLK         63U
#define CLOCK_IP_HAS_DIG_PHY2_CLK         64U
#define CLOCK_IP_HAS_DIG_PHY3_CLK         65U
#define CLOCK_IP_HAS_DMA_CH_MUX0_IPG_CLK         66U
#define CLOCK_IP_HAS_DMA_CH_MUX1_IPG_CLK         67U
#define CLOCK_IP_HAS_DMA4_AXI_CLK         68U
#define CLOCK_IP_HAS_DMA4_IPG_S_CLK         69U
#define CLOCK_IP_HAS_DFT_CLK         70U
#define CLOCK_IP_HAS_DSPI_CLK         71U
#define CLOCK_IP_HAS_DSPI0_IPG_CLK         72U
#define CLOCK_IP_HAS_DSPI1_IPG_CLK         73U
#define CLOCK_IP_HAS_EDMA_TCD_CLK         74U
#define CLOCK_IP_HAS_EIM0_IPG_CLK         75U
#define CLOCK_IP_HAS_EIM1_IPG_CLK         76U
#define CLOCK_IP_HAS_EIM2_IPG_CLK         77U
#define CLOCK_IP_HAS_EIM3_IPG_CLK         78U
#define CLOCK_IP_HAS_EMIOS0_IPG_CLK         79U
#define CLOCK_IP_HAS_EMIOS1_IPG_CLK         80U
#define CLOCK_IP_HAS_EMIOS2_IPG_CLK         81U
#define CLOCK_IP_HAS_ERM0_IPG_CLK         82U
#define CLOCK_IP_HAS_ERM1_IPG_CLK         83U
#define CLOCK_IP_HAS_ERM2_IPG_CLK         84U
#define CLOCK_IP_HAS_ERM3_IPG_CLK         85U
#define CLOCK_IP_HAS_ETH_TS_CLK         86U
#define CLOCK_IP_HAS_ETH0_RX_CLK         87U
#define CLOCK_IP_HAS_ETH0_TX_CLK         88U
#define CLOCK_IP_HAS_ETH1_RX_CLK         89U
#define CLOCK_IP_HAS_ETH1_TX_CLK         90U
#define CLOCK_IP_HAS_ETH2_RX_CLK         91U
#define CLOCK_IP_HAS_ETH2_TX_CLK         92U
#define CLOCK_IP_HAS_ETH3_RX_CLK         93U
#define CLOCK_IP_HAS_ETH3_TX_CLK         94U
#define CLOCK_IP_HAS_ETH4_RX_CLK         95U
#define CLOCK_IP_HAS_ETH4_TX_CLK         96U
#define CLOCK_IP_HAS_FLEXCAN_0to7_PE_CLK         97U
#define CLOCK_IP_HAS_FLEXCAN_8to10_PE_CLK         98U
#define CLOCK_IP_HAS_FLEXCAN_11to16_PE_CLK         99U
#define CLOCK_IP_HAS_FLEXCAN0_IPG_CLK         100U
#define CLOCK_IP_HAS_FLEXCAN0_PE_NOGATE_CLK         101U
#define CLOCK_IP_HAS_FLEXCAN0_TS_CLK         102U
#define CLOCK_IP_HAS_FLEXCAN1_IPG_CLK         103U
#define CLOCK_IP_HAS_FLEXCAN1_PE_NOGATE_CLK         104U
#define CLOCK_IP_HAS_FLEXCAN1_TS_CLK         105U
#define CLOCK_IP_HAS_FLEXCAN2_IPG_CLK         106U
#define CLOCK_IP_HAS_FLEXCAN2_PE_NOGATE_CLK         107U
#define CLOCK_IP_HAS_FLEXCAN2_TS_CLK         108U
#define CLOCK_IP_HAS_FLEXCAN3_IPG_CLK         109U
#define CLOCK_IP_HAS_FLEXCAN3_PE_NOGATE_CLK         110U
#define CLOCK_IP_HAS_FLEXCAN3_TS_CLK         111U
#define CLOCK_IP_HAS_FLEXCAN4_IPG_CLK         112U
#define CLOCK_IP_HAS_FLEXCAN4_PE_NOGATE_CLK         113U
#define CLOCK_IP_HAS_FLEXCAN4_TS_CLK         114U
#define CLOCK_IP_HAS_FLEXCAN5_IPG_CLK         115U
#define CLOCK_IP_HAS_FLEXCAN5_PE_NOGATE_CLK         116U
#define CLOCK_IP_HAS_FLEXCAN5_TS_CLK         117U
#define CLOCK_IP_HAS_FLEXCAN6_IPG_CLK         118U
#define CLOCK_IP_HAS_FLEXCAN6_PE_NOGATE_CLK         119U
#define CLOCK_IP_HAS_FLEXCAN6_TS_CLK         120U
#define CLOCK_IP_HAS_FLEXCAN7_IPG_CLK         121U
#define CLOCK_IP_HAS_FLEXCAN7_PE_NOGATE_CLK         122U
#define CLOCK_IP_HAS_FLEXCAN7_TS_CLK         123U
#define CLOCK_IP_HAS_FLEXCAN8_IPG_CLK         124U
#define CLOCK_IP_HAS_FLEXCAN8_PE_NOGATE_CLK         125U
#define CLOCK_IP_HAS_FLEXCAN8_TS_CLK         126U
#define CLOCK_IP_HAS_FLEXCAN9_IPG_CLK         127U
#define CLOCK_IP_HAS_FLEXCAN9_PE_NOGATE_CLK         128U
#define CLOCK_IP_HAS_FLEXCAN9_TS_CLK         129U
#define CLOCK_IP_HAS_FLEXCAN10_IPG_CLK         130U
#define CLOCK_IP_HAS_FLEXCAN10_PE_NOGATE_CLK         131U
#define CLOCK_IP_HAS_FLEXCAN10_TS_CLK         132U
#define CLOCK_IP_HAS_FLEXCAN11_IPG_CLK         133U
#define CLOCK_IP_HAS_FLEXCAN11_PE_NOGATE_CLK         134U
#define CLOCK_IP_HAS_FLEXCAN11_TS_CLK         135U
#define CLOCK_IP_HAS_FLEXCAN12_IPG_CLK         136U
#define CLOCK_IP_HAS_FLEXCAN12_PE_NOGATE_CLK         137U
#define CLOCK_IP_HAS_FLEXCAN12_TS_CLK         138U
#define CLOCK_IP_HAS_FLEXCAN13_IPG_CLK         139U
#define CLOCK_IP_HAS_FLEXCAN13_PE_NOGATE_CLK         140U
#define CLOCK_IP_HAS_FLEXCAN13_TS_CLK         141U
#define CLOCK_IP_HAS_FLEXCAN14_IPG_CLK         142U
#define CLOCK_IP_HAS_FLEXCAN14_PE_NOGATE_CLK         143U
#define CLOCK_IP_HAS_FLEXCAN14_TS_CLK         144U
#define CLOCK_IP_HAS_FLEXCAN15_IPG_CLK         145U
#define CLOCK_IP_HAS_FLEXCAN15_PE_NOGATE_CLK         146U
#define CLOCK_IP_HAS_FLEXCAN15_TS_CLK         147U
#define CLOCK_IP_HAS_FLEXCAN16_IPG_CLK         148U
#define CLOCK_IP_HAS_FLEXCAN16_PE_NOGATE_CLK         149U
#define CLOCK_IP_HAS_FLEXCAN16_TS_CLK         150U
#define CLOCK_IP_HAS_FLEXIO_CLK         151U
#define CLOCK_IP_HAS_FLEXIO0_IPG_CLK         152U
#define CLOCK_IP_HAS_FLEXIO0_PE_CLK         153U
#define CLOCK_IP_HAS_FLEXIO1_IPG_CLK         154U
#define CLOCK_IP_HAS_FLEXIO1_PE_CLK         155U
#define CLOCK_IP_HAS_GPR0_IPG_CLK         156U
#define CLOCK_IP_HAS_GPR1_IPG_CLK         157U
#define CLOCK_IP_HAS_INTM_IPG_CLK         158U
#define CLOCK_IP_HAS_IPSYNC_CSSI_MC_CGM_MASTER_CLK         159U
#define CLOCK_IP_HAS_IPSYNC_CSSI_MC_CGM_SLAVE_CLK         160U
#define CLOCK_IP_HAS_IPSYNC_CVFCCU_MASTER_CLK         161U
#define CLOCK_IP_HAS_IPSYNC_CVFCCU_SLAVE_CLK         162U
#define CLOCK_IP_HAS_IPSYNC_DSPI_IPI_0_MASTER_CLK         163U
#define CLOCK_IP_HAS_IPSYNC_DSPI_IPI_1_MASTER_CLK         164U
#define CLOCK_IP_HAS_IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK         165U
#define CLOCK_IP_HAS_IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK         166U
#define CLOCK_IP_HAS_IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK         167U
#define CLOCK_IP_HAS_IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK         168U
#define CLOCK_IP_HAS_IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK         169U
#define CLOCK_IP_HAS_IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK         170U
#define CLOCK_IP_HAS_IPSYNC_LPE_LVFCCU_MASTER_CLK         171U
#define CLOCK_IP_HAS_IPSYNC_LPE_LVFCCU_SLAVE_CLK         172U
#define CLOCK_IP_HAS_IPSYNC_LPE_MC_CGM_MASTER_CLK         173U
#define CLOCK_IP_HAS_IPSYNC_LPE_MC_CGM_SLAVE_CLK         174U
#define CLOCK_IP_HAS_IPSYNC_LPE_MC_RGM_MASTER_CLK         175U
#define CLOCK_IP_HAS_IPSYNC_LPE_MC_RGM_SLAVE_CLK         176U
#define CLOCK_IP_HAS_IPSYNC_LPE_STM_MASTER_CLK         177U
#define CLOCK_IP_HAS_IPSYNC_LPE_STM_SLAVE_CLK         178U
#define CLOCK_IP_HAS_IPSYNC_LVFCCU0_MASTER_CLK         179U
#define CLOCK_IP_HAS_IPSYNC_LVFCCU0_SLAVE_CLK         180U
#define CLOCK_IP_HAS_IPSYNC_LVFCCU1_MASTER_CLK         181U
#define CLOCK_IP_HAS_IPSYNC_LVFCCU1_SLAVE_CLK         182U
#define CLOCK_IP_HAS_IPSYNC_LVFCCU2_MASTER_CLK         183U
#define CLOCK_IP_HAS_IPSYNC_LVFCCU2_SLAVE_CLK         184U
#define CLOCK_IP_HAS_IPSYNC_MC_CGM_MASTER_CLK         185U
#define CLOCK_IP_HAS_IPSYNC_MC_CGM_SLAVE_CLK         186U
#define CLOCK_IP_HAS_IPSYNC_NETC_MC_CGM_MASTER_CLK         187U
#define CLOCK_IP_HAS_IPSYNC_NETC_MC_CGM_SLAVE_CLK         188U
#define CLOCK_IP_HAS_IPSYNC_PERI_MC_CGM_MASTER_CLK         189U
#define CLOCK_IP_HAS_IPSYNC_PERI_MC_CGM_SLAVE_CLK         190U
#define CLOCK_IP_HAS_IPSYNC_SAI0_MC_CGM_MASTER_CLK         191U
#define CLOCK_IP_HAS_IPSYNC_SAI0_MC_CGM_SLAVE_CLK         192U
#define CLOCK_IP_HAS_IPSYNC_SAI1_MC_CGM_MASTER_CLK         193U
#define CLOCK_IP_HAS_IPSYNC_SAI1_MC_CGM_SLAVE_CLK         194U
#define CLOCK_IP_HAS_IPSYNC_STM0_MASTER_CLK         195U
#define CLOCK_IP_HAS_IPSYNC_STM0_SLAVE_CLK         196U
#define CLOCK_IP_HAS_IPSYNC_STM1_MASTER_CLK         197U
#define CLOCK_IP_HAS_IPSYNC_STM1_SLAVE_CLK         198U
#define CLOCK_IP_HAS_IPSYNC_STM2_MASTER_CLK         199U
#define CLOCK_IP_HAS_IPSYNC_STM2_SLAVE_CLK         200U
#define CLOCK_IP_HAS_IPSYNC_STM3_MASTER_CLK         201U
#define CLOCK_IP_HAS_IPSYNC_STM3_SLAVE_CLK         202U
#define CLOCK_IP_HAS_IPSYNC_XSPI_MASTER_CLK         203U
#define CLOCK_IP_HAS_IPSYNC_XSPI_SLAVE_CLK         204U
#define CLOCK_IP_HAS_LCU0_IPG_CLK         205U
#define CLOCK_IP_HAS_LCU1_IPG_CLK         206U
#define CLOCK_IP_HAS_LMEM_HCLK_CLK         207U
#define CLOCK_IP_HAS_LPE_ADC_IPG_CLK         208U
#define CLOCK_IP_HAS_LPE_BCTU_IPG_CLK         209U
#define CLOCK_IP_HAS_LPE_BCTU_IPG_CLK_S         210U
#define CLOCK_IP_HAS_LPE_CMU_IPG_CLK         211U
#define CLOCK_IP_HAS_LPE_CRC_IPG_CLK         212U
#define CLOCK_IP_HAS_LPE_CXPI_PE_CLK         213U
#define CLOCK_IP_HAS_LPE_CXPI0_IPG_CLK         214U
#define CLOCK_IP_HAS_LPE_CXPI0_PE_CLK         215U
#define CLOCK_IP_HAS_LPE_CXPI1_IPG_CLK         216U
#define CLOCK_IP_HAS_LPE_CXPI1_PE_CLK         217U
#define CLOCK_IP_HAS_LPE_DIV1_UNGATED_CLK         218U
#define CLOCK_IP_HAS_LPE_DIV2_UNGATED_CLK         219U
#define CLOCK_IP_HAS_LPE_DIV3_UNGATED_CLK         220U
#define CLOCK_IP_HAS_LPE_DIV4_UNGATED_CLK         221U
#define CLOCK_IP_HAS_LPE_DMA_CH_MUX_IPG_CLK         222U
#define CLOCK_IP_HAS_LPE_EIM_IPG_CLK         223U
#define CLOCK_IP_HAS_LPE_FIRC_IPG_CLK         224U
#define CLOCK_IP_HAS_LPE_FLEXCAN_MOD_CLK         225U
#define CLOCK_IP_HAS_LPE_FLEXCAN_PE_CLK         226U
#define CLOCK_IP_HAS_LPE_FTM_IPG_CLK         227U
#define CLOCK_IP_HAS_LPE_FXOSC_IPG_CLK         228U
#define CLOCK_IP_HAS_LPE_GPR0_IPG_CLK         229U
#define CLOCK_IP_HAS_LPE_GPR1_IPG_CLK         230U
#define CLOCK_IP_HAS_LPE_LCU_IPG_CLK         231U
#define CLOCK_IP_HAS_LPE_LPCMP0_IPG_CLK         232U
#define CLOCK_IP_HAS_LPE_LPCMP0_RR_CLK         233U
#define CLOCK_IP_HAS_LPE_LPCMP0_SAMPLE_GATED_CLK         234U
#define CLOCK_IP_HAS_LPE_LPCMP1_IPG_CLK         235U
#define CLOCK_IP_HAS_LPE_LPCMP1_RR_CLK         236U
#define CLOCK_IP_HAS_LPE_LPCMP1_SAMPLE_GATED_CLK         237U
#define CLOCK_IP_HAS_LPE_LPCMP2_IPG_CLK         238U
#define CLOCK_IP_HAS_LPE_LPCMP2_RR_CLK         239U
#define CLOCK_IP_HAS_LPE_LPCMP2_SAMPLE_GATED_CLK         240U
#define CLOCK_IP_HAS_LPE_LPI2C_CLK         241U
#define CLOCK_IP_HAS_LPE_LPI2C_IPG_CLK         242U
#define CLOCK_IP_HAS_LPE_LPI2C_MOD_CLK         243U
#define CLOCK_IP_HAS_LPE_LPSPI_MOD_CLK         244U
#define CLOCK_IP_HAS_LPE_LPSPI0_CLK         245U
#define CLOCK_IP_HAS_LPE_LPSPI0_IPG_CLK         246U
#define CLOCK_IP_HAS_LPE_LPSPI1_CLK         247U
#define CLOCK_IP_HAS_LPE_LPSPI1_IPG_CLK         248U
#define CLOCK_IP_HAS_LPE_LPUART_MOD_CLK         249U
#define CLOCK_IP_HAS_LPE_LPUART0_CLK         250U
#define CLOCK_IP_HAS_LPE_LPUART0_pCLK         251U
#define CLOCK_IP_HAS_LPE_LPUART1_CLK         252U
#define CLOCK_IP_HAS_LPE_LPUART1_pCLK         253U
#define CLOCK_IP_HAS_LPE_LPUART2_CLK         254U
#define CLOCK_IP_HAS_LPE_LPUART2_pCLK         255U
#define CLOCK_IP_HAS_LPE_LSTCU_IPG_CLK         256U
#define CLOCK_IP_HAS_LPE_PIT_RTI_IPG_CLK_OSC_RTI         257U
#define CLOCK_IP_HAS_LPE_PIT_RTI_IPG_CLK_SYNC         258U
#define CLOCK_IP_HAS_LPE_RTC_API_FIRC_CLK         259U
#define CLOCK_IP_HAS_LPE_RTC_API_FXOSC_CLK         260U
#define CLOCK_IP_HAS_LPE_RTC_API_IPG_CLK         261U
#define CLOCK_IP_HAS_LPE_RTC_API_SIRC_CLK         262U
#define CLOCK_IP_HAS_LPE_RTC_API_SXOSC_CLK         263U
#define CLOCK_IP_HAS_LPE_SEMA42_CLK         264U
#define CLOCK_IP_HAS_LPE_STM_CLK         265U
#define CLOCK_IP_HAS_LPE_STM_IPG_CLK         266U
#define CLOCK_IP_HAS_LPE_SWT_COUNTER_IP_CLK         267U
#define CLOCK_IP_HAS_LPE_SWT_IPG_CLK         268U
#define CLOCK_IP_HAS_LPE_SXOSC_IPG_CLK         269U
#define CLOCK_IP_HAS_LPE_TRGMUX_IPG_CLK         270U
#define CLOCK_IP_HAS_LPE_TSPC_IPG_CLK         271U
#define CLOCK_IP_HAS_LPE_TSU_NS_IPG_CLK         272U
#define CLOCK_IP_HAS_LPE_UNGATED_CLK         273U
#define CLOCK_IP_HAS_LPE_VIRT_IPG_CLK         274U
#define CLOCK_IP_HAS_LPE_WKPU_IPG_CLK         275U
#define CLOCK_IP_HAS_LPE_WKPU_IPG_CLK_S         276U
#define CLOCK_IP_HAS_LPI2C0_CLK         277U
#define CLOCK_IP_HAS_LPI2C1_CLK         278U
#define CLOCK_IP_HAS_LPI2C2_CLK         279U
#define CLOCK_IP_HAS_LPI2C3_CLK         280U
#define CLOCK_IP_HAS_LPSPI0_CLK         281U
#define CLOCK_IP_HAS_LPSPI1_CLK         282U
#define CLOCK_IP_HAS_LPSPI2_CLK         283U
#define CLOCK_IP_HAS_LPSPI3_CLK         284U
#define CLOCK_IP_HAS_LPSPI4_CLK         285U
#define CLOCK_IP_HAS_LPSPI5_CLK         286U
#define CLOCK_IP_HAS_LPSPI6_CLK         287U
#define CLOCK_IP_HAS_LPSPI7_CLK         288U
#define CLOCK_IP_HAS_LPUART_MSC_CLK         289U
#define CLOCK_IP_HAS_LPUART_MSC_pCLK         290U
#define CLOCK_IP_HAS_LPUART0_CLK         291U
#define CLOCK_IP_HAS_LPUART0_pCLK         292U
#define CLOCK_IP_HAS_LPUART1_CLK         293U
#define CLOCK_IP_HAS_LPUART1_pCLK         294U
#define CLOCK_IP_HAS_LPUART2_CLK         295U
#define CLOCK_IP_HAS_LPUART2_pCLK         296U
#define CLOCK_IP_HAS_LPUART3_CLK         297U
#define CLOCK_IP_HAS_LPUART3_pCLK         298U
#define CLOCK_IP_HAS_LPUART4_CLK         299U
#define CLOCK_IP_HAS_LPUART4_pCLK         300U
#define CLOCK_IP_HAS_LPUART5_CLK         301U
#define CLOCK_IP_HAS_LPUART5_pCLK         302U
#define CLOCK_IP_HAS_LPUART6_CLK         303U
#define CLOCK_IP_HAS_LPUART6_pCLK         304U
#define CLOCK_IP_HAS_LPUART7_CLK         305U
#define CLOCK_IP_HAS_LPUART7_pCLK         306U
#define CLOCK_IP_HAS_LPUART8_CLK         307U
#define CLOCK_IP_HAS_LPUART8_pCLK         308U
#define CLOCK_IP_HAS_LPUART9_CLK         309U
#define CLOCK_IP_HAS_LPUART9_pCLK         310U
#define CLOCK_IP_HAS_LPUART10_CLK         311U
#define CLOCK_IP_HAS_LPUART10_pCLK         312U
#define CLOCK_IP_HAS_LPUART11_CLK         313U
#define CLOCK_IP_HAS_LPUART11_pCLK         314U
#define CLOCK_IP_HAS_LPUART12_CLK         315U
#define CLOCK_IP_HAS_LPUART12_pCLK         316U
#define CLOCK_IP_HAS_LPUART13_CLK         317U
#define CLOCK_IP_HAS_LPUART13_pCLK         318U
#define CLOCK_IP_HAS_LPUART14_CLK         319U
#define CLOCK_IP_HAS_LPUART14_pCLK         320U
#define CLOCK_IP_HAS_LPUART15_CLK         321U
#define CLOCK_IP_HAS_LPUART15_pCLK         322U
#define CLOCK_IP_HAS_LPUART16_CLK         323U
#define CLOCK_IP_HAS_LPUART16_pCLK         324U
#define CLOCK_IP_HAS_LPUART17_CLK         325U
#define CLOCK_IP_HAS_LPUART17_pCLK         326U
#define CLOCK_IP_HAS_LPUART18_CLK         327U
#define CLOCK_IP_HAS_LPUART18_pCLK         328U
#define CLOCK_IP_HAS_LPUART19_CLK         329U
#define CLOCK_IP_HAS_LPUART19_pCLK         330U
#define CLOCK_IP_HAS_LPUART20_CLK         331U
#define CLOCK_IP_HAS_LPUART20_pCLK         332U
#define CLOCK_IP_HAS_LSTCU_ACCEL_IPG_CLK         333U
#define CLOCK_IP_HAS_LSTCU_CORE0_IPG_CLK         334U
#define CLOCK_IP_HAS_LSTCU_CORE12_IPG_CLK         335U
#define CLOCK_IP_HAS_LSTCU_CORE3_IPG_CLK         336U
#define CLOCK_IP_HAS_LSTCU_HSPI_IPG_CLK         337U
#define CLOCK_IP_HAS_LSTCU_NETC_IPG_CLK         338U
#define CLOCK_IP_HAS_LSTCU_PBRIDGE1_IPG_CLK         339U
#define CLOCK_IP_HAS_LSTCU_PBRIDGE3_IPG_CLK         340U
#define CLOCK_IP_HAS_LSTCU_PBRIDGE4_IPG_CLK         341U
#define CLOCK_IP_HAS_LSTCU_REST_IPG_CLK         342U
#define CLOCK_IP_HAS_MRAM_IPG_CLK         343U
#define CLOCK_IP_HAS_MRAMC_IPG_CLK         344U
#define CLOCK_IP_HAS_MRAMC_IPG_CLK_S         345U
#define CLOCK_IP_HAS_MSCM_IPG_CLK         346U
#define CLOCK_IP_HAS_MSGINTR0_APB_CLK         347U
#define CLOCK_IP_HAS_MSGINTR1_APB_CLK         348U
#define CLOCK_IP_HAS_MSGINTR2_APB_CLK         349U
#define CLOCK_IP_HAS_MSGINTR3_APB_CLK         350U
#define CLOCK_IP_HAS_MSGINTR4_APB_CLK         351U
#define CLOCK_IP_HAS_MSGINTR5_APB_CLK         352U
#define CLOCK_IP_HAS_MSGINTR6_APB_CLK         353U
#define CLOCK_IP_HAS_MSGINTR7_APB_CLK         354U
#define CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK         355U
#define CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK         356U
#define CLOCK_IP_HAS_PERI_HIGH_SPEED_TRACE_CLK         357U
#define CLOCK_IP_HAS_PHY_ETH_CLK         358U
#define CLOCK_IP_HAS_PIT0_IPG_CLK_OSC         359U
#define CLOCK_IP_HAS_PIT0_IPG_CLK_SYNC         360U
#define CLOCK_IP_HAS_PIT1_IPG_CLK_OSC         361U
#define CLOCK_IP_HAS_PIT1_IPG_CLK_SYNC         362U
#define CLOCK_IP_HAS_PIT2_IPG_CLK_OSC         363U
#define CLOCK_IP_HAS_PIT2_IPG_CLK_SYNC         364U
#define CLOCK_IP_HAS_PIT3_IPG_CLK_OSC         365U
#define CLOCK_IP_HAS_PIT3_IPG_CLK_SYNC         366U
#define CLOCK_IP_HAS_POST_IPG_CLK         367U
#define CLOCK_IP_HAS_RR_RTC_CLK         368U
#define CLOCK_IP_HAS_RXLUT_ERM_CLK         369U
#define CLOCK_IP_HAS_RXLUT_IPG_CLK         370U
#define CLOCK_IP_HAS_SAI0_MCLK         371U
#define CLOCK_IP_HAS_SAI0_IO_MCLK         372U
#define CLOCK_IP_HAS_SAI0_IPG_CLK         373U
#define CLOCK_IP_HAS_SAI1_IO_MCLK         374U
#define CLOCK_IP_HAS_SAI1_IPG_CLK         375U
#define CLOCK_IP_HAS_SAI1_MCLK         376U
#define CLOCK_IP_HAS_SDHC_IPG_CLK         377U
#define CLOCK_IP_HAS_SDHC_PER_CLK         378U
#define CLOCK_IP_HAS_SEMA42_IPG_CLK         379U
#define CLOCK_IP_HAS_SERDES_ALT_REF_CLK         380U
#define CLOCK_IP_HAS_SERDES_AUX_CLK         381U
#define CLOCK_IP_HAS_SERDES_REF_CLK         382U
#define CLOCK_IP_HAS_SINC_IPG_CLK         383U
#define CLOCK_IP_HAS_SOG_REST_CMU_IPG_CLK         384U
#define CLOCK_IP_HAS_SRC_FIRC_CLK         385U
#define CLOCK_IP_HAS_SRC_FIRCDIV2_CLK         386U
#define CLOCK_IP_HAS_SRC_FXOSC_CLK         387U
#define CLOCK_IP_HAS_SRC_LPE_CLK         388U
#define CLOCK_IP_HAS_SRC_LPE_DIV1_CLK         389U
#define CLOCK_IP_HAS_SRC_LPE_DIV2_CLK         390U
#define CLOCK_IP_HAS_SRC_LPE_DIV4_CLK         391U
#define CLOCK_IP_HAS_SRC_LPE_DIV8_CLK         392U
#define CLOCK_IP_HAS_SRC_PLT_CLK         393U
#define CLOCK_IP_HAS_SRC_PLTCORE_CLK         394U
#define CLOCK_IP_HAS_SRC_PLTDIV1_CLK         395U
#define CLOCK_IP_HAS_SRC_PLTDIV2_CLK         396U
#define CLOCK_IP_HAS_SRC_PLTDIV4_CLK         397U
#define CLOCK_IP_HAS_SRC_SIRC_CLK         398U
#define CLOCK_IP_HAS_SRC_SXOSC_CLK         399U
#define CLOCK_IP_HAS_SRAM0_CONTROLLER_IPS_CLK         400U
#define CLOCK_IP_HAS_SRAM1_CONTROLLER_IPS_CLK         401U
#define CLOCK_IP_HAS_SRAM2_CONTROLLER_IPS_CLK         402U
#define CLOCK_IP_HAS_STAM_CLK         403U
#define CLOCK_IP_HAS_STM0_CLK         404U
#define CLOCK_IP_HAS_STM0_IPG_CLK         405U
#define CLOCK_IP_HAS_STM1_CLK         406U
#define CLOCK_IP_HAS_STM1_IPG_CLK         407U
#define CLOCK_IP_HAS_STM2_CLK         408U
#define CLOCK_IP_HAS_STM2_IPG_CLK         409U
#define CLOCK_IP_HAS_STM3_CLK         410U
#define CLOCK_IP_HAS_STM3_IPG_CLK         411U
#define CLOCK_IP_HAS_SWT_STARTUP_IPG_CLK         412U
#define CLOCK_IP_HAS_SWT_STARTUP_IPG_COUNTER_CLK         413U
#define CLOCK_IP_HAS_SWT0_IPG_CLK         414U
#define CLOCK_IP_HAS_SWT0_IPG_COUNTER_CLK         415U
#define CLOCK_IP_HAS_SWT1_IPG_CLK         416U
#define CLOCK_IP_HAS_SWT1_IPG_COUNTER_CLK         417U
#define CLOCK_IP_HAS_SWT2_IPG_CLK         418U
#define CLOCK_IP_HAS_SWT2_IPG_COUNTER_CLK         419U
#define CLOCK_IP_HAS_SWT3_IPG_CLK         420U
#define CLOCK_IP_HAS_SWT3_IPG_COUNTER_CLK         421U
#define CLOCK_IP_HAS_TRACE_CLK         422U
#define CLOCK_IP_HAS_TRGMUX_IPG_CLK_S         423U
#define CLOCK_IP_HAS_TRGMUX_MSC_IPG_CLK_S         424U
#define CLOCK_IP_HAS_VWRAP0_IPG_CLK         425U
#define CLOCK_IP_HAS_VWRAP1_IPG_CLK         426U
#define CLOCK_IP_HAS_VWRAP2_IPG_CLK         427U
#define CLOCK_IP_HAS_VWRAP3_IPG_CLK         428U
#define CLOCK_IP_HAS_XSPI_IPG_CLK         429U
#define CLOCK_IP_HAS_XSPI_UNGATED_2XSFIF_CLK         430U
#define CLOCK_IP_FEATURE_NAMES_NO         431U
/**
* @brief        Support for MultiPartition.
*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* #ifndef CLOCK_IP_CFG_DEFINES_H */

/** @} */


