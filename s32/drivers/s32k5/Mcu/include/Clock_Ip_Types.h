/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_TYPES_H
#define CLOCK_IP_TYPES_H

/**
*   @file    Clock_Ip_Types.h
*   @version    0.8.0
*
*   @brief   CLOCK IP type header file.
*   @details CLOCK IP type header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Clock_Ip_Cfg_Defines.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_TYPES_VENDOR_ID                       43
#define CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION        9
#define CLOCK_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_TYPES_SW_MAJOR_VERSION                0
#define CLOCK_IP_TYPES_SW_MINOR_VERSION                8
#define CLOCK_IP_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h file are of the same Autosar version */
#if ((CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Types.h  and Std_Types.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if Clock_Ip_Types.h file and Clock_Ip_Cfg_Defines.h file have same versions */
#if (CLOCK_IP_TYPES_VENDOR_ID  != CLOCK_IP_CFG_DEFINES_VENDOR_ID)
    #error "Clock_Ip_Types.h and Clock_Ip_Cfg_Defines.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Types.h file and Clock_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_TYPES_AR_RELEASE_REVISION_VERSION != CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Types.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/* Check if Clock_Ip_Types.h file and Clock_Ip_Cfg_Defines.h file are of the same Software version */
#if ((CLOCK_IP_TYPES_SW_MAJOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_TYPES_SW_MINOR_VERSION != CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CLOCK_IP_TYPES_SW_PATCH_VERSION != CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Types.h and Clock_Ip_Cfg_Defines.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if (defined(CLOCK_IP_POWER_NOTIFICATIONS))
/** @brief Power modes. */
typedef enum {

#if defined(CLOCK_IP_HAS_RUN_MODE)
    RUN_MODE                              = CLOCK_IP_HAS_RUN_MODE,
    VLPR_MODE                             = 1U,
    VLPS_MODE                             = 2U,
    HSRUN_MODE                            = 3U,
#endif
} Clock_Ip_PowerModesType;

/** @brief Power mode notification. */
typedef enum {

    BEFORE_POWER_MODE_CHANGE,                /* Before power mode change command is sent */
    POWER_MODE_CHANGE_IN_PROGRESS,         /* Power mode transition is in progress */
    POWER_MODE_CHANGED,                    /* Power mode transition completed */

} Clock_Ip_PowerNotificationType;
#endif

/** @brief Clock names. */
typedef enum {

#if defined(CLOCK_IP_HAS_gated_clk)
    gated_clk             = CLOCK_IP_HAS_gated_clk,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLK)
    COREPLL_CLK             = CLOCK_IP_HAS_COREPLL_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_VCO_CLK)
    COREPLL_VCO_CLK                 = CLOCK_IP_HAS_COREPLL_VCO_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT0_CLK)
    COREPLL_CLKOUT0_CLK             = CLOCK_IP_HAS_COREPLL_CLKOUT0_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT1_CLK)
    COREPLL_CLKOUT1_CLK             = CLOCK_IP_HAS_COREPLL_CLKOUT1_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT2_CLK)
    COREPLL_CLKOUT2_CLK             = CLOCK_IP_HAS_COREPLL_CLKOUT2_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_CLKOUT3_CLK)
    COREPLL_CLKOUT3_CLK             = CLOCK_IP_HAS_COREPLL_CLKOUT3_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS0_CLK)
    COREPLL_DFS0_CLK                = CLOCK_IP_HAS_COREPLL_DFS0_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS1_CLK)
    COREPLL_DFS1_CLK                = CLOCK_IP_HAS_COREPLL_DFS1_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS2_CLK)
    COREPLL_DFS2_CLK                = CLOCK_IP_HAS_COREPLL_DFS2_CLK,
#endif
#if defined(CLOCK_IP_HAS_COREPLL_DFS3_CLK)
    COREPLL_DFS3_CLK                = CLOCK_IP_HAS_COREPLL_DFS3_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLK)
    PERIPHPLL_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_VCO_CLK)
    PERIPHPLL_VCO_CLK              = CLOCK_IP_HAS_PERIPHPLL_VCO_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT0_CLK)
    PERIPHPLL_CLKOUT0_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLKOUT0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT1_CLK)
    PERIPHPLL_CLKOUT1_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLKOUT1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT2_CLK)
    PERIPHPLL_CLKOUT2_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLKOUT2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT3_CLK)
    PERIPHPLL_CLKOUT3_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLKOUT3_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT4_CLK)
    PERIPHPLL_CLKOUT4_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLKOUT4_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_CLKOUT5_CLK)
    PERIPHPLL_CLKOUT5_CLK             = CLOCK_IP_HAS_PERIPHPLL_CLKOUT5_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS0_CLK)
    PERIPHPLL_DFS0_CLK                = CLOCK_IP_HAS_PERIPHPLL_DFS0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK)
    PERIPHPLL_DFS1_CLK                = CLOCK_IP_HAS_PERIPHPLL_DFS1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK)
    PERIPHPLL_DFS2_CLK                = CLOCK_IP_HAS_PERIPHPLL_DFS2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERIPHPLL_DFS3_CLK)
    PERIPHPLL_DFS3_CLK                = CLOCK_IP_HAS_PERIPHPLL_DFS3_CLK,
#endif
#if defined(CLOCK_IP_HAS_CAN0_CLK)
    CAN0_CLK             = CLOCK_IP_HAS_CAN0_CLK,
#endif
#if defined(CLOCK_IP_HAS_ClockName)
    ClockName             = CLOCK_IP_HAS_ClockName,
#endif
#if defined(CLOCK_IP_HAS_ClockName)
    ClockName             = CLOCK_IP_HAS_ClockName,
#endif
#if defined(CLOCK_IP_HAS_DMACRC0_CLK)
    DMACRC0_CLK             = CLOCK_IP_HAS_DMACRC0_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMACRC4_CLK)
    DMACRC4_CLK             = CLOCK_IP_HAS_DMACRC4_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMAMUX0_CLK)
    DMAMUX0_CLK             = CLOCK_IP_HAS_DMAMUX0_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMAMUX4_CLK)
    DMAMUX4_CLK             = CLOCK_IP_HAS_DMAMUX4_CLK,
#endif
#if defined(CLOCK_IP_HAS_EDMA0_CLK)
    EDMA0_CLK             = CLOCK_IP_HAS_EDMA0_CLK,
#endif
#if defined(CLOCK_IP_HAS_EDMA3_CLK)
    EDMA3_CLK             = CLOCK_IP_HAS_EDMA3_CLK,
#endif
#if defined(CLOCK_IP_HAS_EDMA4_CLK)
    EDMA4_CLK             = CLOCK_IP_HAS_EDMA4_CLK,
#endif
#if defined(CLOCK_IP_HAS_FIRC_CLK)
    FIRC_CLK             = CLOCK_IP_HAS_FIRC_CLK,
#endif
#if defined(CLOCK_IP_HAS_FXOSC_CLK)
    FXOSC_CLK             = CLOCK_IP_HAS_FXOSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_LIN0_CLK)
    LIN0_CLK             = CLOCK_IP_HAS_LIN0_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPI2C2_CLK)
    LPI2C2_CLK             = CLOCK_IP_HAS_LPI2C2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_ATB_CLK)
    P0_ATB_CLK             = CLOCK_IP_HAS_P0_ATB_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_ATB_SEL_CLK)
    P0_ATB_SEL_CLK             = CLOCK_IP_HAS_P0_ATB_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_CAN_PE_CLK)
    P0_CAN_PE_CLK             = CLOCK_IP_HAS_P0_CAN_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_CAN_PE_SEL_CLK)
    P0_CAN_PE_SEL_CLK             = CLOCK_IP_HAS_P0_CAN_PE_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_DBG_APB_CLK)
    P0_DBG_APB_CLK             = CLOCK_IP_HAS_P0_DBG_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_DSPI_CLK)
    P0_DSPI_CLK             = CLOCK_IP_HAS_P0_DSPI_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_DSPI_SEL_CLK)
    P0_DSPI_SEL_CLK             = CLOCK_IP_HAS_P0_DSPI_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_GLB_LBIST_CLK)
    P0_GLB_LBIST_CLK             = CLOCK_IP_HAS_P0_GLB_LBIST_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_GLB_LBIST_SEL_CLK)
    P0_GLB_LBIST_SEL_CLK             = CLOCK_IP_HAS_P0_GLB_LBIST_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_IPS_CLK)
    P0_IPS_CLK             = CLOCK_IP_HAS_P0_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_LIN_BAUD_CLK)
    P0_LIN_BAUD_CLK             = CLOCK_IP_HAS_P0_LIN_BAUD_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_LIN_CLK)
    P0_LIN_CLK             = CLOCK_IP_HAS_P0_LIN_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_LIN_SEL_CLK)
    P0_LIN_SEL_CLK             = CLOCK_IP_HAS_P0_LIN_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_SYS_CLK)
    P0_SYS_CLK             = CLOCK_IP_HAS_P0_SYS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_SYS_DIV2_CLK)
    P0_SYS_DIV2_CLK             = CLOCK_IP_HAS_P0_SYS_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_SYS_DIV4_CLK)
    P0_SYS_DIV4_CLK             = CLOCK_IP_HAS_P0_SYS_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_SYS_SEL_CLK)
    P0_SYS_SEL_CLK             = CLOCK_IP_HAS_P0_SYS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_TS_CLK)
    P0_TS_CLK             = CLOCK_IP_HAS_P0_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_TS_SEL_CLK)
    P0_TS_SEL_CLK             = CLOCK_IP_HAS_P0_TS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_APB_SEL_CLK)
    P1_APB_SEL_CLK             = CLOCK_IP_HAS_P1_APB_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_DBG_APB_CLK)
    P1_DBG_APB_CLK             = CLOCK_IP_HAS_P1_DBG_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_IPS_CLK)
    P1_IPS_CLK             = CLOCK_IP_HAS_P1_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_MII_RX_CLK)
    P1_NETC_ETH0_MII_RX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_MII_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_MII_TX_CLK)
    P1_NETC_ETH0_MII_TX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_MII_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_RGMII_RX_CLK)
    P1_NETC_ETH0_RGMII_RX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_RGMII_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_RGMII_TX_CLK)
    P1_NETC_ETH0_RGMII_TX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_RGMII_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_RMII_REF_CLK)
    P1_NETC_ETH0_RMII_REF_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_RMII_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_RX_SEL_CLK)
    P1_NETC_ETH0_RX_SEL_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_RX_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH0_TX_SEL_CLK)
    P1_NETC_ETH0_TX_SEL_CLK             = CLOCK_IP_HAS_P1_NETC_ETH0_TX_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_MII_RX_CLK)
    P1_NETC_ETH1_MII_RX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_MII_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_MII_TX_CLK)
    P1_NETC_ETH1_MII_TX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_MII_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_RGMII_RX_CLK)
    P1_NETC_ETH1_RGMII_RX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_RGMII_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_RGMII_TX_CLK)
    P1_NETC_ETH1_RGMII_TX_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_RGMII_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_RMII_REF_CLK)
    P1_NETC_ETH1_RMII_REF_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_RMII_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_RX_SEL_CLK)
    P1_NETC_ETH1_RX_SEL_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_RX_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_ETH1_TX_SEL_CLK)
    P1_NETC_ETH1_TX_SEL_CLK             = CLOCK_IP_HAS_P1_NETC_ETH1_TX_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_TS_CLK)
    P1_NETC_TS_CLK             = CLOCK_IP_HAS_P1_NETC_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_NETC_TS_SEL_CLK)
    P1_NETC_TS_SEL_CLK             = CLOCK_IP_HAS_P1_NETC_TS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_SYS_CLK)
    P1_SYS_CLK             = CLOCK_IP_HAS_P1_SYS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_SYS_DIV2_CLK)
    P1_SYS_DIV2_CLK             = CLOCK_IP_HAS_P1_SYS_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_SYS_DIV4_CLK)
    P1_SYS_DIV4_CLK             = CLOCK_IP_HAS_P1_SYS_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_SYS_DIV6_CLK)
    P1_SYS_DIV6_CLK             = CLOCK_IP_HAS_P1_SYS_DIV6_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_XENO_CLK)
    P1_XENO_CLK             = CLOCK_IP_HAS_P1_XENO_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_XENO_DIV4_CLK)
    P1_XENO_DIV4_CLK             = CLOCK_IP_HAS_P1_XENO_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_XENO_SEL_CLK)
    P1_XENO_SEL_CLK             = CLOCK_IP_HAS_P1_XENO_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_APB_SEL_CLK)
    P3_APB_SEL_CLK             = CLOCK_IP_HAS_P3_APB_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_DBG_APB_CLK)
    P3_DBG_APB_CLK             = CLOCK_IP_HAS_P3_DBG_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_DBG_TS_CLK)
    P3_DBG_TS_CLK             = CLOCK_IP_HAS_P3_DBG_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_DBG_TS_SEL_CLK)
    P3_DBG_TS_SEL_CLK             = CLOCK_IP_HAS_P3_DBG_TS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_IPS_CLK)
    P3_IPS_CLK             = CLOCK_IP_HAS_P3_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_SYS_CLK)
    P3_SYS_CLK             = CLOCK_IP_HAS_P3_SYS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_SYS_DIV2_CLK)
    P3_SYS_DIV2_CLK             = CLOCK_IP_HAS_P3_SYS_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_SYS_DIV4_CLK)
    P3_SYS_DIV4_CLK             = CLOCK_IP_HAS_P3_SYS_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_APB_SEL_CLK)
    P4_APB_SEL_CLK             = CLOCK_IP_HAS_P4_APB_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_DBG_APB_CLK)
    P4_DBG_APB_CLK             = CLOCK_IP_HAS_P4_DBG_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_DSPI_CLK)
    P4_DSPI_CLK             = CLOCK_IP_HAS_P4_DSPI_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_DSPI_SEL_CLK)
    P4_DSPI_SEL_CLK             = CLOCK_IP_HAS_P4_DSPI_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_I2C_CLK)
    P4_I2C_CLK             = CLOCK_IP_HAS_P4_I2C_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_I2C_SEL_CLK)
    P4_I2C_SEL_CLK             = CLOCK_IP_HAS_P4_I2C_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_IPS_CLK)
    P4_IPS_CLK             = CLOCK_IP_HAS_P4_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_QSPI0_2X_CLK)
    P4_QSPI0_2X_CLK             = CLOCK_IP_HAS_P4_QSPI0_2X_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_QSPI0_DIV2_CLK)
    P4_QSPI0_DIV2_CLK             = CLOCK_IP_HAS_P4_QSPI0_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_QSPI0_SEL_CLK)
    P4_QSPI0_SEL_CLK             = CLOCK_IP_HAS_P4_QSPI0_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_SYS_CLK)
    P4_SYS_CLK             = CLOCK_IP_HAS_P4_SYS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_SYS_DIV2_CLK)
    P4_SYS_DIV2_CLK             = CLOCK_IP_HAS_P4_SYS_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_SYS_DIV2_HSE_CLK)
    P4_SYS_DIV2_HSE_CLK             = CLOCK_IP_HAS_P4_SYS_DIV2_HSE_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_SYS_DIV4_CLK)
    P4_SYS_DIV4_CLK             = CLOCK_IP_HAS_P4_SYS_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_APB_SEL_CLK)
    P7_APB_SEL_CLK             = CLOCK_IP_HAS_P7_APB_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_CLK)
    P7_CORE_CLK             = CLOCK_IP_HAS_P7_CORE_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_DIV2_CLK)
    P7_CORE_DIV2_CLK             = CLOCK_IP_HAS_P7_CORE_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_IPS_CLK)
    P7_CORE_IPS_CLK             = CLOCK_IP_HAS_P7_CORE_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_SEL_CLK)
    P7_CORE_SEL_CLK             = CLOCK_IP_HAS_P7_CORE_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_APB_SEL_CLK)
    P8_APB_SEL_CLK             = CLOCK_IP_HAS_P8_APB_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_DBG_APB_CLK)
    P8_DBG_APB_CLK             = CLOCK_IP_HAS_P8_DBG_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_IPS_CLK)
    P8_IPS_CLK             = CLOCK_IP_HAS_P8_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_PCI_AUX_CLK)
    P8_PCI_AUX_CLK             = CLOCK_IP_HAS_P8_PCI_AUX_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_PCI_AUX_SEL_CLK)
    P8_PCI_AUX_SEL_CLK             = CLOCK_IP_HAS_P8_PCI_AUX_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_SYS_CLK)
    P8_SYS_CLK             = CLOCK_IP_HAS_P8_SYS_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_SYS_SEL_CLK)
    P8_SYS_SEL_CLK             = CLOCK_IP_HAS_P8_SYS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_PIT0_CLK)
    PIT0_CLK             = CLOCK_IP_HAS_PIT0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PIT4_CLK)
    PIT4_CLK             = CLOCK_IP_HAS_PIT4_CLK,
#endif
#if defined(CLOCK_IP_HAS_QUADSPI0_CLK)
    QUADSPI0_CLK             = CLOCK_IP_HAS_QUADSPI0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SIUL2_0_CLK)
    SIUL2_0_CLK             = CLOCK_IP_HAS_SIUL2_0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SIUL2_1_CLK)
    SIUL2_1_CLK             = CLOCK_IP_HAS_SIUL2_1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SIUL2_4_CLK)
    SIUL2_4_CLK             = CLOCK_IP_HAS_SIUL2_4_CLK,
#endif
#if defined(CLOCK_IP_HAS_SPI0_CLK)
    SPI0_CLK             = CLOCK_IP_HAS_SPI0_CLK,
#endif
#if defined(CLOCK_IP_HAS_fast_crystal_oscillator)
    fast_crystal_oscillator   = CLOCK_IP_HAS_fast_crystal_oscillator,
#endif
#if defined(CLOCK_IP_HAS_slow_crystal_oscillator)
    slow_crystal_oscillator   = CLOCK_IP_HAS_slow_crystal_oscillator,
#endif
#if defined(CLOCK_IP_HAS_serdes_pipe_clk)
    serdes_pipe_clk             = CLOCK_IP_HAS_serdes_pipe_clk,
#endif
#if defined(CLOCK_IP_HAS_dll_eth0_rx_clk)
    dll_eth0_rx_clk             = CLOCK_IP_HAS_dll_eth0_rx_clk,
#endif
#if defined(CLOCK_IP_HAS_eth0_rx_clk)
    eth0_rx_clk             = CLOCK_IP_HAS_eth0_rx_clk,
#endif
#if defined(CLOCK_IP_HAS_eth0_tx_clk)
    eth0_tx_clk             = CLOCK_IP_HAS_eth0_tx_clk,
#endif
#if defined(CLOCK_IP_HAS_tmr_1588_clk)
    tmr_1588_clk             = CLOCK_IP_HAS_tmr_1588_clk,
#endif
#if defined(CLOCK_IP_HAS_xeno0_mii_rx_clk)
    xeno0_mii_rx_clk             = CLOCK_IP_HAS_xeno0_mii_rx_clk,
#endif
#if defined(CLOCK_IP_HAS_xeno0_mii_tx_clk)
    xeno0_mii_tx_clk             = CLOCK_IP_HAS_xeno0_mii_tx_clk,
#endif
#if defined(CLOCK_IP_HAS_xeno1_mii_rx_clk)
    xeno1_mii_rx_clk             = CLOCK_IP_HAS_xeno1_mii_rx_clk,
#endif
#if defined(CLOCK_IP_HAS_xeno1_mii_tx_clk)
    xeno1_mii_tx_clk             = CLOCK_IP_HAS_xeno1_mii_tx_clk,
#endif
#if defined(CLOCK_IP_HAS_FIRCDIV2_CLK)
    FIRCDIV2_CLK              = CLOCK_IP_HAS_FIRCDIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SIRC_CLK)
    SIRC_CLK                  = CLOCK_IP_HAS_SIRC_CLK,
#endif
#if defined(CLOCK_IP_HAS_SAFE_CLK)
    SAFE_CLK                  = CLOCK_IP_HAS_SAFE_CLK,
#endif
#if defined(CLOCK_IP_HAS_SXOSC_CLK)
    SXOSC_CLK                 = CLOCK_IP_HAS_SXOSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_eth0_mii_rx_ext_clk)
    eth0_mii_rx_ext_clk       = CLOCK_IP_HAS_eth0_mii_rx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth0_mii_tx_ext_clk)
    eth0_mii_tx_ext_clk       = CLOCK_IP_HAS_eth0_mii_tx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth0_rgmii_rx_ext_clk)
    eth0_rgmii_rx_ext_clk     = CLOCK_IP_HAS_eth0_rgmii_rx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth0_rgmii_tx_ext_clk)
    eth0_rgmii_tx_ext_clk     = CLOCK_IP_HAS_eth0_rgmii_tx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth0_rmii_ref_ext_clk)
    eth0_rmii_ref_ext_clk     = CLOCK_IP_HAS_eth0_rmii_ref_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth1_mii_rx_ext_clk)
    eth1_mii_rx_ext_clk       = CLOCK_IP_HAS_eth1_mii_rx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth1_mii_tx_ext_clk)
    eth1_mii_tx_ext_clk       = CLOCK_IP_HAS_eth1_mii_tx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth1_rgmii_rx_ext_clk)
    eth1_rgmii_rx_ext_clk     = CLOCK_IP_HAS_eth1_rgmii_rx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth1_rgmii_tx_ext_clk)
    eth1_rgmii_tx_ext_clk     = CLOCK_IP_HAS_eth1_rgmii_tx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth1_rmii_ref_ext_clk)
    eth1_rmii_ref_ext_clk     = CLOCK_IP_HAS_eth1_rmii_ref_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth2_mii_rx_ext_clk)
    eth2_mii_rx_ext_clk       = CLOCK_IP_HAS_eth2_mii_rx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth2_mii_tx_ext_clk)
    eth2_mii_tx_ext_clk       = CLOCK_IP_HAS_eth2_mii_tx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth2_rgmii_rx_ext_clk)
    eth2_rgmii_rx_ext_clk     = CLOCK_IP_HAS_eth2_rgmii_rx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth2_rgmii_tx_ext_clk)
    eth2_rgmii_tx_ext_clk     = CLOCK_IP_HAS_eth2_rgmii_tx_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_eth2_rmii_ref_ext_clk)
    eth2_rmii_ref_ext_clk     = CLOCK_IP_HAS_eth2_rmii_ref_ext_clk,
#endif
#if defined(CLOCK_IP_HAS_ts_1588_clk)
    ts_1588_clk               = CLOCK_IP_HAS_ts_1588_clk,
#endif
#if defined(CLOCK_IP_HAS_PLL0_CLK)
    PLL0_CLK                  = CLOCK_IP_HAS_PLL0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV_CLK)
    PLL0_DIV_CLK              = CLOCK_IP_HAS_PLL0_DIV_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV0_CLK)
    PLL0_DIV0_CLK             = CLOCK_IP_HAS_PLL0_DIV0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV1_CLK)
    PLL0_DIV1_CLK             = CLOCK_IP_HAS_PLL0_DIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV2_CLK)
    PLL0_DIV2_CLK             = CLOCK_IP_HAS_PLL0_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV3_CLK)
    PLL0_DIV3_CLK             = CLOCK_IP_HAS_PLL0_DIV3_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DIV4_CLK)
    PLL0_DIV4_CLK             = CLOCK_IP_HAS_PLL0_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS0_CLK)
    PLL0_DFS0_CLK             = CLOCK_IP_HAS_PLL0_DFS0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
    PLL0_DFS1_CLK             = CLOCK_IP_HAS_PLL0_DFS1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
    PLL0_DFS2_CLK             = CLOCK_IP_HAS_PLL0_DFS2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
    PLL0_DFS3_CLK             = CLOCK_IP_HAS_PLL0_DFS3_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_CLK)
    PLL1_CLK                  = CLOCK_IP_HAS_PLL1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV_CLK)
    PLL1_DIV_CLK              = CLOCK_IP_HAS_PLL1_DIV_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV0_CLK)
    PLL1_DIV0_CLK             = CLOCK_IP_HAS_PLL1_DIV0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV1_CLK)
    PLL1_DIV1_CLK             = CLOCK_IP_HAS_PLL1_DIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV2_CLK)
    PLL1_DIV2_CLK             = CLOCK_IP_HAS_PLL1_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV3_CLK)
    PLL1_DIV3_CLK             = CLOCK_IP_HAS_PLL1_DIV3_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV4_CLK)
    PLL1_DIV4_CLK             = CLOCK_IP_HAS_PLL1_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DIV5_CLK)
    PLL1_DIV5_CLK             = CLOCK_IP_HAS_PLL1_DIV5_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS0_CLK)
    PLL1_DFS0_CLK             = CLOCK_IP_HAS_PLL1_DFS0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS1_CLK)
    PLL1_DFS1_CLK             = CLOCK_IP_HAS_PLL1_DFS1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS2_CLK)
    PLL1_DFS2_CLK             = CLOCK_IP_HAS_PLL1_DFS2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLL1_DFS3_CLK)
    PLL1_DFS3_CLK             = CLOCK_IP_HAS_PLL1_DFS3_CLK,
#endif
#if defined(CLOCK_IP_HAS_CPE_PLL_CLK)
    CPE_PLL_CLK               = CLOCK_IP_HAS_CPE_PLL_CLK,
#endif
#if defined(CLOCK_IP_HAS_CPE_DIV_CLK)
    CPE_DIV_CLK               = CLOCK_IP_HAS_CPE_DIV_CLK,
#endif
#if defined(CLOCK_IP_HAS_CPE_DIV0_CLK)
    CPE_DIV0_CLK              = CLOCK_IP_HAS_CPE_DIV0_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLT_CLK)
    PLT_CLK                   = CLOCK_IP_HAS_PLT_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
    PLTCORE_CLK               = CLOCK_IP_HAS_PLTCORE_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
    PLTDIV1_CLK               = CLOCK_IP_HAS_PLTDIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
    PLTDIV2_CLK               = CLOCK_IP_HAS_PLTDIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
    PLTDIV4_CLK               = CLOCK_IP_HAS_PLTDIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_ACP_DMA3_H_CLK)
    ACP_DMA3_H_CLK            = CLOCK_IP_HAS_ACP_DMA3_H_CLK,
#endif
#if defined(CLOCK_IP_HAS_ACP_DMA3_IPG_CLK)
    ACP_DMA3_IPG_CLK          = CLOCK_IP_HAS_ACP_DMA3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ADC0_IPG_CLK)
    ADC0_IPG_CLK              = CLOCK_IP_HAS_ADC0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ADC1_IPG_CLK)
    ADC1_IPG_CLK              = CLOCK_IP_HAS_ADC1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_BCTU_IPG_CLK)
    BCTU_IPG_CLK              = CLOCK_IP_HAS_BCTU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_BCTU_IPS_CLK)
    BCTU_IPS_CLK              = CLOCK_IP_HAS_BCTU_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_CAN_HUB_IPG_CLK)
    CAN_HUB_IPG_CLK           = CLOCK_IP_HAS_CAN_HUB_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_CAN_PE_CLK)
    CAN_PE_CLK                = CLOCK_IP_HAS_CAN_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_CLKBIST_IPG_CLK)
    CLKBIST_IPG_CLK           = CLOCK_IP_HAS_CLKBIST_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_CRC0_IPG_CLK)
    CRC0_IPG_CLK              = CLOCK_IP_HAS_CRC0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_CRC1_IPG_CLK)
    CRC1_IPG_CLK              = CLOCK_IP_HAS_CRC1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_CSTCU_IPG_CLK)
    CSTCU_IPG_CLK             = CLOCK_IP_HAS_CSTCU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_DIG_PHY0_CLK)
    DIG_PHY0_CLK              = CLOCK_IP_HAS_DIG_PHY0_CLK,
#endif
#if defined(CLOCK_IP_HAS_DIG_PHY1_CLK)
    DIG_PHY1_CLK              = CLOCK_IP_HAS_DIG_PHY1_CLK,
#endif
#if defined(CLOCK_IP_HAS_DIG_PHY2_CLK)
    DIG_PHY2_CLK              = CLOCK_IP_HAS_DIG_PHY2_CLK,
#endif
#if defined(CLOCK_IP_HAS_DIG_PHY3_CLK)
    DIG_PHY3_CLK              = CLOCK_IP_HAS_DIG_PHY3_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMA_CH_MUX0_IPG_CLK)
    DMA_CH_MUX0_IPG_CLK       = CLOCK_IP_HAS_DMA_CH_MUX0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMA_CH_MUX1_IPG_CLK)
    DMA_CH_MUX1_IPG_CLK       = CLOCK_IP_HAS_DMA_CH_MUX1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMA4_AXI_CLK)
    DMA4_AXI_CLK              = CLOCK_IP_HAS_DMA4_AXI_CLK,
#endif
#if defined(CLOCK_IP_HAS_DMA4_IPG_S_CLK)
    DMA4_IPG_S_CLK            = CLOCK_IP_HAS_DMA4_IPG_S_CLK,
#endif
#if defined(CLOCK_IP_HAS_DFT_CLK)
    DFT_CLK                   = CLOCK_IP_HAS_DFT_CLK,
#endif
#if defined(CLOCK_IP_HAS_DSPI_CLK)
    DSPI_CLK                  = CLOCK_IP_HAS_DSPI_CLK,
#endif
#if defined(CLOCK_IP_HAS_DSPI0_IPG_CLK)
    DSPI0_IPG_CLK             = CLOCK_IP_HAS_DSPI0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_DSPI1_IPG_CLK)
    DSPI1_IPG_CLK             = CLOCK_IP_HAS_DSPI1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EDMA_TCD_CLK)
    EDMA_TCD_CLK              = CLOCK_IP_HAS_EDMA_TCD_CLK,
#endif
#if defined(CLOCK_IP_HAS_EIM0_IPG_CLK)
    EIM0_IPG_CLK              = CLOCK_IP_HAS_EIM0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EIM1_IPG_CLK)
    EIM1_IPG_CLK              = CLOCK_IP_HAS_EIM1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EIM2_IPG_CLK)
    EIM2_IPG_CLK              = CLOCK_IP_HAS_EIM2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EIM3_IPG_CLK)
    EIM3_IPG_CLK              = CLOCK_IP_HAS_EIM3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EMIOS0_IPG_CLK)
    EMIOS0_IPG_CLK            = CLOCK_IP_HAS_EMIOS0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EMIOS1_IPG_CLK)
    EMIOS1_IPG_CLK            = CLOCK_IP_HAS_EMIOS1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_EMIOS2_IPG_CLK)
    EMIOS2_IPG_CLK            = CLOCK_IP_HAS_EMIOS2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ERM0_IPG_CLK)
    ERM0_IPG_CLK              = CLOCK_IP_HAS_ERM0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ERM1_IPG_CLK)
    ERM1_IPG_CLK              = CLOCK_IP_HAS_ERM1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ERM2_IPG_CLK)
    ERM2_IPG_CLK              = CLOCK_IP_HAS_ERM2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ERM3_IPG_CLK)
    ERM3_IPG_CLK              = CLOCK_IP_HAS_ERM3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH_TS_CLK)
    ETH_TS_CLK                = CLOCK_IP_HAS_ETH_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH0_RX_CLK)
    ETH0_RX_CLK               = CLOCK_IP_HAS_ETH0_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH0_TX_CLK)
    ETH0_TX_CLK               = CLOCK_IP_HAS_ETH0_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH1_RX_CLK)
    ETH1_RX_CLK               = CLOCK_IP_HAS_ETH1_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH1_TX_CLK)
    ETH1_TX_CLK               = CLOCK_IP_HAS_ETH1_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH2_RX_CLK)
    ETH2_RX_CLK               = CLOCK_IP_HAS_ETH2_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH2_TX_CLK)
    ETH2_TX_CLK               = CLOCK_IP_HAS_ETH2_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH3_RX_CLK)
    ETH3_RX_CLK               = CLOCK_IP_HAS_ETH3_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH3_TX_CLK)
    ETH3_TX_CLK               = CLOCK_IP_HAS_ETH3_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH4_RX_CLK)
    ETH4_RX_CLK               = CLOCK_IP_HAS_ETH4_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_ETH4_TX_CLK)
    ETH4_TX_CLK               = CLOCK_IP_HAS_ETH4_TX_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN_0to7_PE_CLK)
    FLEXCAN_0to7_PE_CLK       = CLOCK_IP_HAS_FLEXCAN_0to7_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN_8to10_PE_CLK)
    FLEXCAN_8to10_PE_CLK      = CLOCK_IP_HAS_FLEXCAN_8to10_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN_11to16_PE_CLK)
    FLEXCAN_11to16_PE_CLK     = CLOCK_IP_HAS_FLEXCAN_11to16_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN0_IPG_CLK)
    FLEXCAN0_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN0_PE_NOGATE_CLK)
    FLEXCAN0_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN0_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN0_TS_CLK)
    FLEXCAN0_TS_CLK           = CLOCK_IP_HAS_FLEXCAN0_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN1_IPG_CLK)
    FLEXCAN1_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN1_PE_NOGATE_CLK)
    FLEXCAN1_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN1_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN1_TS_CLK)
    FLEXCAN1_TS_CLK           = CLOCK_IP_HAS_FLEXCAN1_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN2_IPG_CLK)
    FLEXCAN2_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN2_PE_NOGATE_CLK)
    FLEXCAN2_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN2_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN2_TS_CLK)
    FLEXCAN2_TS_CLK           = CLOCK_IP_HAS_FLEXCAN2_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN3_IPG_CLK)
    FLEXCAN3_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN3_PE_NOGATE_CLK)
    FLEXCAN3_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN3_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN3_TS_CLK)
    FLEXCAN3_TS_CLK           = CLOCK_IP_HAS_FLEXCAN3_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN4_IPG_CLK)
    FLEXCAN4_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN4_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN4_PE_NOGATE_CLK)
    FLEXCAN4_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN4_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN4_TS_CLK)
    FLEXCAN4_TS_CLK           = CLOCK_IP_HAS_FLEXCAN4_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN5_IPG_CLK)
    FLEXCAN5_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN5_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN5_PE_NOGATE_CLK)
    FLEXCAN5_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN5_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN5_TS_CLK)
    FLEXCAN5_TS_CLK           = CLOCK_IP_HAS_FLEXCAN5_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN6_IPG_CLK)
    FLEXCAN6_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN6_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN6_PE_NOGATE_CLK)
    FLEXCAN6_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN6_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN6_TS_CLK)
    FLEXCAN6_TS_CLK           = CLOCK_IP_HAS_FLEXCAN6_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN7_IPG_CLK)
    FLEXCAN7_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN7_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN7_PE_NOGATE_CLK)
    FLEXCAN7_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN7_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN7_TS_CLK)
    FLEXCAN7_TS_CLK           = CLOCK_IP_HAS_FLEXCAN7_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN8_IPG_CLK)
    FLEXCAN8_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN8_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN8_PE_NOGATE_CLK)
    FLEXCAN8_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN8_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN8_TS_CLK)
    FLEXCAN8_TS_CLK           = CLOCK_IP_HAS_FLEXCAN8_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN9_IPG_CLK)
    FLEXCAN9_IPG_CLK          = CLOCK_IP_HAS_FLEXCAN9_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN9_PE_NOGATE_CLK)
    FLEXCAN9_PE_NOGATE_CLK    = CLOCK_IP_HAS_FLEXCAN9_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN9_TS_CLK)
    FLEXCAN9_TS_CLK           = CLOCK_IP_HAS_FLEXCAN9_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN10_IPG_CLK)
    FLEXCAN10_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN10_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN10_PE_NOGATE_CLK)
    FLEXCAN10_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN10_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN10_TS_CLK)
    FLEXCAN10_TS_CLK          = CLOCK_IP_HAS_FLEXCAN10_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN11_IPG_CLK)
    FLEXCAN11_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN11_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN11_PE_NOGATE_CLK)
    FLEXCAN11_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN11_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN11_TS_CLK)
    FLEXCAN11_TS_CLK          = CLOCK_IP_HAS_FLEXCAN11_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN12_IPG_CLK)
    FLEXCAN12_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN12_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN12_PE_NOGATE_CLK)
    FLEXCAN12_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN12_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN12_TS_CLK)
    FLEXCAN12_TS_CLK          = CLOCK_IP_HAS_FLEXCAN12_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN13_IPG_CLK)
    FLEXCAN13_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN13_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN13_PE_NOGATE_CLK)
    FLEXCAN13_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN13_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN13_TS_CLK)
    FLEXCAN13_TS_CLK          = CLOCK_IP_HAS_FLEXCAN13_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN14_IPG_CLK)
    FLEXCAN14_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN14_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN14_PE_NOGATE_CLK)
    FLEXCAN14_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN14_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN14_TS_CLK)
    FLEXCAN14_TS_CLK          = CLOCK_IP_HAS_FLEXCAN14_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN15_IPG_CLK)
    FLEXCAN15_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN15_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN15_PE_NOGATE_CLK)
    FLEXCAN15_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN15_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN15_TS_CLK)
    FLEXCAN15_TS_CLK          = CLOCK_IP_HAS_FLEXCAN15_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN16_IPG_CLK)
    FLEXCAN16_IPG_CLK         = CLOCK_IP_HAS_FLEXCAN16_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN16_PE_NOGATE_CLK)
    FLEXCAN16_PE_NOGATE_CLK   = CLOCK_IP_HAS_FLEXCAN16_PE_NOGATE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXCAN16_TS_CLK)
    FLEXCAN16_TS_CLK          = CLOCK_IP_HAS_FLEXCAN16_TS_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXIO_CLK)
    FLEXIO_CLK                = CLOCK_IP_HAS_FLEXIO_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXIO0_IPG_CLK)
    FLEXIO0_IPG_CLK           = CLOCK_IP_HAS_FLEXIO0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXIO0_PE_CLK)
    FLEXIO0_PE_CLK            = CLOCK_IP_HAS_FLEXIO0_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXIO1_IPG_CLK)
    FLEXIO1_IPG_CLK           = CLOCK_IP_HAS_FLEXIO1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_FLEXIO1_PE_CLK)
    FLEXIO1_PE_CLK            = CLOCK_IP_HAS_FLEXIO1_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_GPR0_IPG_CLK)
    GPR0_IPG_CLK              = CLOCK_IP_HAS_GPR0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_GPR1_IPG_CLK)
    GPR1_IPG_CLK              = CLOCK_IP_HAS_GPR1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_INTM_IPG_CLK)
    INTM_IPG_CLK              = CLOCK_IP_HAS_INTM_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_CSSI_MC_CGM_MASTER_CLK)
    IPSYNC_CSSI_MC_CGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_CSSI_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_CSSI_MC_CGM_SLAVE_CLK)
    IPSYNC_CSSI_MC_CGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_CSSI_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_CVFCCU_MASTER_CLK)
    IPSYNC_CVFCCU_MASTER_CLK  = CLOCK_IP_HAS_IPSYNC_CVFCCU_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_CVFCCU_SLAVE_CLK)
    IPSYNC_CVFCCU_SLAVE_CLK   = CLOCK_IP_HAS_IPSYNC_CVFCCU_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_DSPI_IPI_0_MASTER_CLK)
    IPSYNC_DSPI_IPI_0_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_DSPI_IPI_0_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_DSPI_IPI_1_MASTER_CLK)
    IPSYNC_DSPI_IPI_1_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_DSPI_IPI_1_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK)
    IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK)
    IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK)
    IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK)
    IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK)
    IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK)
    IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_LVFCCU_MASTER_CLK)
    IPSYNC_LPE_LVFCCU_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_LVFCCU_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_LVFCCU_SLAVE_CLK)
    IPSYNC_LPE_LVFCCU_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_LPE_LVFCCU_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_MC_CGM_MASTER_CLK)
    IPSYNC_LPE_MC_CGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_MC_CGM_SLAVE_CLK)
    IPSYNC_LPE_MC_CGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_LPE_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_MC_RGM_MASTER_CLK)
    IPSYNC_LPE_MC_RGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_MC_RGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_MC_RGM_SLAVE_CLK)
    IPSYNC_LPE_MC_RGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_LPE_MC_RGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_STM_MASTER_CLK)
    IPSYNC_LPE_STM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LPE_STM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LPE_STM_SLAVE_CLK)
    IPSYNC_LPE_STM_SLAVE_CLK  = CLOCK_IP_HAS_IPSYNC_LPE_STM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LVFCCU0_MASTER_CLK)
    IPSYNC_LVFCCU0_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LVFCCU0_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LVFCCU0_SLAVE_CLK)
    IPSYNC_LVFCCU0_SLAVE_CLK  = CLOCK_IP_HAS_IPSYNC_LVFCCU0_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LVFCCU1_MASTER_CLK)
    IPSYNC_LVFCCU1_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LVFCCU1_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LVFCCU1_SLAVE_CLK)
    IPSYNC_LVFCCU1_SLAVE_CLK  = CLOCK_IP_HAS_IPSYNC_LVFCCU1_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LVFCCU2_MASTER_CLK)
    IPSYNC_LVFCCU2_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_LVFCCU2_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_LVFCCU2_SLAVE_CLK)
    IPSYNC_LVFCCU2_SLAVE_CLK  = CLOCK_IP_HAS_IPSYNC_LVFCCU2_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_MC_CGM_MASTER_CLK)
    IPSYNC_MC_CGM_MASTER_CLK  = CLOCK_IP_HAS_IPSYNC_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_MC_CGM_SLAVE_CLK)
    IPSYNC_MC_CGM_SLAVE_CLK   = CLOCK_IP_HAS_IPSYNC_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_NETC_MC_CGM_MASTER_CLK)
    IPSYNC_NETC_MC_CGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_NETC_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_NETC_MC_CGM_SLAVE_CLK)
    IPSYNC_NETC_MC_CGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_NETC_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_PERI_MC_CGM_MASTER_CLK)
    IPSYNC_PERI_MC_CGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_PERI_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_PERI_MC_CGM_SLAVE_CLK)
    IPSYNC_PERI_MC_CGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_PERI_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_SAI0_MC_CGM_MASTER_CLK)
    IPSYNC_SAI0_MC_CGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_SAI0_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_SAI0_MC_CGM_SLAVE_CLK)
    IPSYNC_SAI0_MC_CGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_SAI0_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_SAI1_MC_CGM_MASTER_CLK)
    IPSYNC_SAI1_MC_CGM_MASTER_CLK = CLOCK_IP_HAS_IPSYNC_SAI1_MC_CGM_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_SAI1_MC_CGM_SLAVE_CLK)
    IPSYNC_SAI1_MC_CGM_SLAVE_CLK = CLOCK_IP_HAS_IPSYNC_SAI1_MC_CGM_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM0_MASTER_CLK)
    IPSYNC_STM0_MASTER_CLK    = CLOCK_IP_HAS_IPSYNC_STM0_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM0_SLAVE_CLK)
    IPSYNC_STM0_SLAVE_CLK     = CLOCK_IP_HAS_IPSYNC_STM0_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM1_MASTER_CLK)
    IPSYNC_STM1_MASTER_CLK    = CLOCK_IP_HAS_IPSYNC_STM1_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM1_SLAVE_CLK)
    IPSYNC_STM1_SLAVE_CLK     = CLOCK_IP_HAS_IPSYNC_STM1_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM2_MASTER_CLK)
    IPSYNC_STM2_MASTER_CLK    = CLOCK_IP_HAS_IPSYNC_STM2_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM2_SLAVE_CLK)
    IPSYNC_STM2_SLAVE_CLK     = CLOCK_IP_HAS_IPSYNC_STM2_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM3_MASTER_CLK)
    IPSYNC_STM3_MASTER_CLK    = CLOCK_IP_HAS_IPSYNC_STM3_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_STM3_SLAVE_CLK)
    IPSYNC_STM3_SLAVE_CLK     = CLOCK_IP_HAS_IPSYNC_STM3_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_XSPI_MASTER_CLK)
    IPSYNC_XSPI_MASTER_CLK    = CLOCK_IP_HAS_IPSYNC_XSPI_MASTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_IPSYNC_XSPI_SLAVE_CLK)
    IPSYNC_XSPI_SLAVE_CLK     = CLOCK_IP_HAS_IPSYNC_XSPI_SLAVE_CLK,
#endif
#if defined(CLOCK_IP_HAS_LCU0_IPG_CLK)
    LCU0_IPG_CLK              = CLOCK_IP_HAS_LCU0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LCU1_IPG_CLK)
    LCU1_IPG_CLK              = CLOCK_IP_HAS_LCU1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LMEM_HCLK_CLK)
    LMEM_HCLK_CLK             = CLOCK_IP_HAS_LMEM_HCLK_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_ADC_IPG_CLK)
    LPE_ADC_IPG_CLK           = CLOCK_IP_HAS_LPE_ADC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_BCTU_IPG_CLK)
    LPE_BCTU_IPG_CLK          = CLOCK_IP_HAS_LPE_BCTU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_BCTU_IPG_CLK_S)
    LPE_BCTU_IPG_CLK_S        = CLOCK_IP_HAS_LPE_BCTU_IPG_CLK_S,
#endif
#if defined(CLOCK_IP_HAS_LPE_CMU_IPG_CLK)
    LPE_CMU_IPG_CLK           = CLOCK_IP_HAS_LPE_CMU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CRC_IPG_CLK)
    LPE_CRC_IPG_CLK           = CLOCK_IP_HAS_LPE_CRC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CXPI_PE_CLK)
    LPE_CXPI_PE_CLK           = CLOCK_IP_HAS_LPE_CXPI_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CXPI0_IPG_CLK)
    LPE_CXPI0_IPG_CLK         = CLOCK_IP_HAS_LPE_CXPI0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CXPI0_PE_CLK)
    LPE_CXPI0_PE_CLK          = CLOCK_IP_HAS_LPE_CXPI0_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CXPI1_IPG_CLK)
    LPE_CXPI1_IPG_CLK         = CLOCK_IP_HAS_LPE_CXPI1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CXPI1_PE_CLK)
    LPE_CXPI1_PE_CLK          = CLOCK_IP_HAS_LPE_CXPI1_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_CLK)
    LPE_CLK                   = CLOCK_IP_HAS_LPE_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
    LPE_DIV1_CLK              = CLOCK_IP_HAS_LPE_DIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
    LPE_DIV2_CLK              = CLOCK_IP_HAS_LPE_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
    LPE_DIV4_CLK              = CLOCK_IP_HAS_LPE_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
    LPE_DIV8_CLK              = CLOCK_IP_HAS_LPE_DIV8_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV1_UNGATED_CLK)
    LPE_DIV1_UNGATED_CLK      = CLOCK_IP_HAS_LPE_DIV1_UNGATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_UNGATED_CLK)
    LPE_DIV2_UNGATED_CLK      = CLOCK_IP_HAS_LPE_DIV2_UNGATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV3_UNGATED_CLK)
    LPE_DIV3_UNGATED_CLK      = CLOCK_IP_HAS_LPE_DIV3_UNGATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_UNGATED_CLK)
    LPE_DIV4_UNGATED_CLK      = CLOCK_IP_HAS_LPE_DIV4_UNGATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_DMA_CH_MUX_IPG_CLK)
    LPE_DMA_CH_MUX_IPG_CLK    = CLOCK_IP_HAS_LPE_DMA_CH_MUX_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_EIM_IPG_CLK)
    LPE_EIM_IPG_CLK           = CLOCK_IP_HAS_LPE_EIM_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_FIRC_IPG_CLK)
    LPE_FIRC_IPG_CLK          = CLOCK_IP_HAS_LPE_FIRC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_FLEXCAN_MOD_CLK)
    LPE_FLEXCAN_MOD_CLK       = CLOCK_IP_HAS_LPE_FLEXCAN_MOD_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_FLEXCAN_PE_CLK)
    LPE_FLEXCAN_PE_CLK        = CLOCK_IP_HAS_LPE_FLEXCAN_PE_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_FTM_IPG_CLK)
    LPE_FTM_IPG_CLK           = CLOCK_IP_HAS_LPE_FTM_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_FXOSC_IPG_CLK)
    LPE_FXOSC_IPG_CLK         = CLOCK_IP_HAS_LPE_FXOSC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_GPR0_IPG_CLK)
    LPE_GPR0_IPG_CLK          = CLOCK_IP_HAS_LPE_GPR0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_GPR1_IPG_CLK)
    LPE_GPR1_IPG_CLK          = CLOCK_IP_HAS_LPE_GPR1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LCU_IPG_CLK)
    LPE_LCU_IPG_CLK           = CLOCK_IP_HAS_LPE_LCU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP0_IPG_CLK)
    LPE_LPCMP0_IPG_CLK        = CLOCK_IP_HAS_LPE_LPCMP0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP0_RR_CLK)
    LPE_LPCMP0_RR_CLK         = CLOCK_IP_HAS_LPE_LPCMP0_RR_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP0_SAMPLE_GATED_CLK)
    LPE_LPCMP0_SAMPLE_GATED_CLK = CLOCK_IP_HAS_LPE_LPCMP0_SAMPLE_GATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP1_IPG_CLK)
    LPE_LPCMP1_IPG_CLK        = CLOCK_IP_HAS_LPE_LPCMP1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP1_RR_CLK)
    LPE_LPCMP1_RR_CLK         = CLOCK_IP_HAS_LPE_LPCMP1_RR_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP1_SAMPLE_GATED_CLK)
    LPE_LPCMP1_SAMPLE_GATED_CLK = CLOCK_IP_HAS_LPE_LPCMP1_SAMPLE_GATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP2_IPG_CLK)
    LPE_LPCMP2_IPG_CLK        = CLOCK_IP_HAS_LPE_LPCMP2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP2_RR_CLK)
    LPE_LPCMP2_RR_CLK         = CLOCK_IP_HAS_LPE_LPCMP2_RR_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPCMP2_SAMPLE_GATED_CLK)
    LPE_LPCMP2_SAMPLE_GATED_CLK = CLOCK_IP_HAS_LPE_LPCMP2_SAMPLE_GATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPI2C_CLK)
    LPE_LPI2C_CLK             = CLOCK_IP_HAS_LPE_LPI2C_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPI2C_IPG_CLK)
    LPE_LPI2C_IPG_CLK         = CLOCK_IP_HAS_LPE_LPI2C_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPI2C_MOD_CLK)
    LPE_LPI2C_MOD_CLK         = CLOCK_IP_HAS_LPE_LPI2C_MOD_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPSPI_MOD_CLK)
    LPE_LPSPI_MOD_CLK         = CLOCK_IP_HAS_LPE_LPSPI_MOD_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPSPI0_CLK)
    LPE_LPSPI0_CLK            = CLOCK_IP_HAS_LPE_LPSPI0_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPSPI0_IPG_CLK)
    LPE_LPSPI0_IPG_CLK        = CLOCK_IP_HAS_LPE_LPSPI0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPSPI1_CLK)
    LPE_LPSPI1_CLK            = CLOCK_IP_HAS_LPE_LPSPI1_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPSPI1_IPG_CLK)
    LPE_LPSPI1_IPG_CLK        = CLOCK_IP_HAS_LPE_LPSPI1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART_MOD_CLK)
    LPE_LPUART_MOD_CLK        = CLOCK_IP_HAS_LPE_LPUART_MOD_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART0_CLK)
    LPE_LPUART0_CLK           = CLOCK_IP_HAS_LPE_LPUART0_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART0_pCLK)
    LPE_LPUART0_pCLK          = CLOCK_IP_HAS_LPE_LPUART0_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART1_CLK)
    LPE_LPUART1_CLK           = CLOCK_IP_HAS_LPE_LPUART1_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART1_pCLK)
    LPE_LPUART1_pCLK          = CLOCK_IP_HAS_LPE_LPUART1_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART2_CLK)
    LPE_LPUART2_CLK           = CLOCK_IP_HAS_LPE_LPUART2_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LPUART2_pCLK)
    LPE_LPUART2_pCLK          = CLOCK_IP_HAS_LPE_LPUART2_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_LSTCU_IPG_CLK)
    LPE_LSTCU_IPG_CLK         = CLOCK_IP_HAS_LPE_LSTCU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_PIT_RTI_IPG_CLK_OSC_RTI)
    LPE_PIT_RTI_IPG_CLK_OSC_RTI = CLOCK_IP_HAS_LPE_PIT_RTI_IPG_CLK_OSC_RTI,
#endif
#if defined(CLOCK_IP_HAS_LPE_PIT_RTI_IPG_CLK_SYNC)
    LPE_PIT_RTI_IPG_CLK_SYNC  = CLOCK_IP_HAS_LPE_PIT_RTI_IPG_CLK_SYNC,
#endif
#if defined(CLOCK_IP_HAS_LPE_RTC_API_FIRC_CLK)
    LPE_RTC_API_FIRC_CLK      = CLOCK_IP_HAS_LPE_RTC_API_FIRC_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_RTC_API_FXOSC_CLK)
    LPE_RTC_API_FXOSC_CLK     = CLOCK_IP_HAS_LPE_RTC_API_FXOSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_RTC_API_IPG_CLK)
    LPE_RTC_API_IPG_CLK       = CLOCK_IP_HAS_LPE_RTC_API_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_RTC_API_SIRC_CLK)
    LPE_RTC_API_SIRC_CLK      = CLOCK_IP_HAS_LPE_RTC_API_SIRC_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_RTC_API_SXOSC_CLK)
    LPE_RTC_API_SXOSC_CLK     = CLOCK_IP_HAS_LPE_RTC_API_SXOSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_SEMA42_CLK)
    LPE_SEMA42_CLK            = CLOCK_IP_HAS_LPE_SEMA42_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_STM_CLK)
    LPE_STM_CLK               = CLOCK_IP_HAS_LPE_STM_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_STM_IPG_CLK)
    LPE_STM_IPG_CLK           = CLOCK_IP_HAS_LPE_STM_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_SWT_COUNTER_IP_CLK)
    LPE_SWT_COUNTER_IP_CLK    = CLOCK_IP_HAS_LPE_SWT_COUNTER_IP_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_SWT_IPG_CLK)
    LPE_SWT_IPG_CLK           = CLOCK_IP_HAS_LPE_SWT_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_SXOSC_IPG_CLK)
    LPE_SXOSC_IPG_CLK         = CLOCK_IP_HAS_LPE_SXOSC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_TRGMUX_IPG_CLK)
    LPE_TRGMUX_IPG_CLK        = CLOCK_IP_HAS_LPE_TRGMUX_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_TSPC_IPG_CLK)
    LPE_TSPC_IPG_CLK          = CLOCK_IP_HAS_LPE_TSPC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_TSU_NS_IPG_CLK)
    LPE_TSU_NS_IPG_CLK        = CLOCK_IP_HAS_LPE_TSU_NS_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_UNGATED_CLK)
    LPE_UNGATED_CLK           = CLOCK_IP_HAS_LPE_UNGATED_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_VIRT_IPG_CLK)
    LPE_VIRT_IPG_CLK          = CLOCK_IP_HAS_LPE_VIRT_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_WKPU_IPG_CLK)
    LPE_WKPU_IPG_CLK          = CLOCK_IP_HAS_LPE_WKPU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPE_WKPU_IPG_CLK_S)
    LPE_WKPU_IPG_CLK_S        = CLOCK_IP_HAS_LPE_WKPU_IPG_CLK_S,
#endif
#if defined(CLOCK_IP_HAS_LPI2C0_CLK)
    LPI2C0_CLK                = CLOCK_IP_HAS_LPI2C0_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPI2C1_CLK)
    LPI2C1_CLK                = CLOCK_IP_HAS_LPI2C1_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPI2C3_CLK)
    LPI2C3_CLK                = CLOCK_IP_HAS_LPI2C3_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI0_CLK)
    LPSPI0_CLK                = CLOCK_IP_HAS_LPSPI0_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI1_CLK)
    LPSPI1_CLK                = CLOCK_IP_HAS_LPSPI1_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI2_CLK)
    LPSPI2_CLK                = CLOCK_IP_HAS_LPSPI2_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI3_CLK)
    LPSPI3_CLK                = CLOCK_IP_HAS_LPSPI3_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI4_CLK)
    LPSPI4_CLK                = CLOCK_IP_HAS_LPSPI4_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI5_CLK)
    LPSPI5_CLK                = CLOCK_IP_HAS_LPSPI5_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI6_CLK)
    LPSPI6_CLK                = CLOCK_IP_HAS_LPSPI6_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPSPI7_CLK)
    LPSPI7_CLK                = CLOCK_IP_HAS_LPSPI7_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART_MSC_CLK)
    LPUART_MSC_CLK            = CLOCK_IP_HAS_LPUART_MSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART_MSC_pCLK)
    LPUART_MSC_pCLK           = CLOCK_IP_HAS_LPUART_MSC_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART0_CLK)
    LPUART0_CLK               = CLOCK_IP_HAS_LPUART0_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART0_pCLK)
    LPUART0_pCLK              = CLOCK_IP_HAS_LPUART0_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART1_CLK)
    LPUART1_CLK               = CLOCK_IP_HAS_LPUART1_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART1_pCLK)
    LPUART1_pCLK              = CLOCK_IP_HAS_LPUART1_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART2_CLK)
    LPUART2_CLK               = CLOCK_IP_HAS_LPUART2_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART2_pCLK)
    LPUART2_pCLK              = CLOCK_IP_HAS_LPUART2_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART3_CLK)
    LPUART3_CLK               = CLOCK_IP_HAS_LPUART3_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART3_pCLK)
    LPUART3_pCLK              = CLOCK_IP_HAS_LPUART3_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART4_CLK)
    LPUART4_CLK               = CLOCK_IP_HAS_LPUART4_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART4_pCLK)
    LPUART4_pCLK              = CLOCK_IP_HAS_LPUART4_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART5_CLK)
    LPUART5_CLK               = CLOCK_IP_HAS_LPUART5_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART5_pCLK)
    LPUART5_pCLK              = CLOCK_IP_HAS_LPUART5_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART6_CLK)
    LPUART6_CLK               = CLOCK_IP_HAS_LPUART6_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART6_pCLK)
    LPUART6_pCLK              = CLOCK_IP_HAS_LPUART6_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART7_CLK)
    LPUART7_CLK               = CLOCK_IP_HAS_LPUART7_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART7_pCLK)
    LPUART7_pCLK              = CLOCK_IP_HAS_LPUART7_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART8_CLK)
    LPUART8_CLK               = CLOCK_IP_HAS_LPUART8_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART8_pCLK)
    LPUART8_pCLK              = CLOCK_IP_HAS_LPUART8_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART9_CLK)
    LPUART9_CLK               = CLOCK_IP_HAS_LPUART9_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART9_pCLK)
    LPUART9_pCLK              = CLOCK_IP_HAS_LPUART9_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART10_CLK)
    LPUART10_CLK              = CLOCK_IP_HAS_LPUART10_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART10_pCLK)
    LPUART10_pCLK             = CLOCK_IP_HAS_LPUART10_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART11_CLK)
    LPUART11_CLK              = CLOCK_IP_HAS_LPUART11_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART11_pCLK)
    LPUART11_pCLK             = CLOCK_IP_HAS_LPUART11_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART12_CLK)
    LPUART12_CLK              = CLOCK_IP_HAS_LPUART12_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART12_pCLK)
    LPUART12_pCLK             = CLOCK_IP_HAS_LPUART12_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART13_CLK)
    LPUART13_CLK              = CLOCK_IP_HAS_LPUART13_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART13_pCLK)
    LPUART13_pCLK             = CLOCK_IP_HAS_LPUART13_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART14_CLK)
    LPUART14_CLK              = CLOCK_IP_HAS_LPUART14_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART14_pCLK)
    LPUART14_pCLK             = CLOCK_IP_HAS_LPUART14_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART15_CLK)
    LPUART15_CLK              = CLOCK_IP_HAS_LPUART15_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART15_pCLK)
    LPUART15_pCLK             = CLOCK_IP_HAS_LPUART15_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART16_CLK)
    LPUART16_CLK              = CLOCK_IP_HAS_LPUART16_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART16_pCLK)
    LPUART16_pCLK             = CLOCK_IP_HAS_LPUART16_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART17_CLK)
    LPUART17_CLK              = CLOCK_IP_HAS_LPUART17_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART17_pCLK)
    LPUART17_pCLK             = CLOCK_IP_HAS_LPUART17_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART18_CLK)
    LPUART18_CLK              = CLOCK_IP_HAS_LPUART18_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART18_pCLK)
    LPUART18_pCLK             = CLOCK_IP_HAS_LPUART18_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART19_CLK)
    LPUART19_CLK              = CLOCK_IP_HAS_LPUART19_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART19_pCLK)
    LPUART19_pCLK             = CLOCK_IP_HAS_LPUART19_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART20_CLK)
    LPUART20_CLK              = CLOCK_IP_HAS_LPUART20_CLK,
#endif
#if defined(CLOCK_IP_HAS_LPUART20_pCLK)
    LPUART20_pCLK             = CLOCK_IP_HAS_LPUART20_pCLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_ACCEL_IPG_CLK)
    LSTCU_ACCEL_IPG_CLK       = CLOCK_IP_HAS_LSTCU_ACCEL_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_CORE0_IPG_CLK)
    LSTCU_CORE0_IPG_CLK       = CLOCK_IP_HAS_LSTCU_CORE0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_CORE12_IPG_CLK)
    LSTCU_CORE12_IPG_CLK      = CLOCK_IP_HAS_LSTCU_CORE12_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_CORE3_IPG_CLK)
    LSTCU_CORE3_IPG_CLK       = CLOCK_IP_HAS_LSTCU_CORE3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_HSPI_IPG_CLK)
    LSTCU_HSPI_IPG_CLK        = CLOCK_IP_HAS_LSTCU_HSPI_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_NETC_IPG_CLK)
    LSTCU_NETC_IPG_CLK        = CLOCK_IP_HAS_LSTCU_NETC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_PBRIDGE1_IPG_CLK)
    LSTCU_PBRIDGE1_IPG_CLK    = CLOCK_IP_HAS_LSTCU_PBRIDGE1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_PBRIDGE3_IPG_CLK)
    LSTCU_PBRIDGE3_IPG_CLK    = CLOCK_IP_HAS_LSTCU_PBRIDGE3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_PBRIDGE4_IPG_CLK)
    LSTCU_PBRIDGE4_IPG_CLK    = CLOCK_IP_HAS_LSTCU_PBRIDGE4_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_LSTCU_REST_IPG_CLK)
    LSTCU_REST_IPG_CLK        = CLOCK_IP_HAS_LSTCU_REST_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_MC_CGM1_SLICE0_CLK)
    MC_CGM1_SLICE0_CLK        = CLOCK_IP_HAS_MC_CGM1_SLICE0_CLK,
#endif
#if defined(CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV1_CLK)
    MC_CGM1_SLICE0_DIV1_CLK   = CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV2_CLK)
    MC_CGM1_SLICE0_DIV2_CLK   = CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV3_CLK)
    MC_CGM1_SLICE0_DIV3_CLK   = CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV3_CLK,
#endif
#if defined(CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV4_CLK)
    MC_CGM1_SLICE0_DIV4_CLK   = CLOCK_IP_HAS_MC_CGM1_SLICE0_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_MRAM_IPG_CLK)
    MRAM_IPG_CLK              = CLOCK_IP_HAS_MRAM_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_MRAMC_IPG_CLK)
    MRAMC_IPG_CLK             = CLOCK_IP_HAS_MRAMC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_MRAMC_IPG_CLK_S)
    MRAMC_IPG_CLK_S           = CLOCK_IP_HAS_MRAMC_IPG_CLK_S,
#endif
#if defined(CLOCK_IP_HAS_MSCM_IPG_CLK)
    MSCM_IPG_CLK              = CLOCK_IP_HAS_MSCM_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR0_APB_CLK)
    MSGINTR0_APB_CLK          = CLOCK_IP_HAS_MSGINTR0_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR1_APB_CLK)
    MSGINTR1_APB_CLK          = CLOCK_IP_HAS_MSGINTR1_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR2_APB_CLK)
    MSGINTR2_APB_CLK          = CLOCK_IP_HAS_MSGINTR2_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR3_APB_CLK)
    MSGINTR3_APB_CLK          = CLOCK_IP_HAS_MSGINTR3_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR4_APB_CLK)
    MSGINTR4_APB_CLK          = CLOCK_IP_HAS_MSGINTR4_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR5_APB_CLK)
    MSGINTR5_APB_CLK          = CLOCK_IP_HAS_MSGINTR5_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR6_APB_CLK)
    MSGINTR6_APB_CLK          = CLOCK_IP_HAS_MSGINTR6_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_MSGINTR7_APB_CLK)
    MSGINTR7_APB_CLK          = CLOCK_IP_HAS_MSGINTR7_APB_CLK,
#endif
#if defined(CLOCK_IP_HAS_NETC_PLT_CLK)
    NETC_PLT_CLK              = CLOCK_IP_HAS_NETC_PLT_CLK,
#endif
#if defined(CLOCK_IP_HAS_NETC_PLTDIV1_CLK)
    NETC_PLTDIV1_CLK          = CLOCK_IP_HAS_NETC_PLTDIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_NETC_PLTDIV2_CLK)
    NETC_PLTDIV2_CLK          = CLOCK_IP_HAS_NETC_PLTDIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_NETC_PLTDIV3_CLK)
    NETC_PLTDIV3_CLK          = CLOCK_IP_HAS_NETC_PLTDIV3_CLK,
#endif
#if defined(CLOCK_IP_HAS_NETC_PLTDIV4_CLK)
    NETC_PLTDIV4_CLK          = CLOCK_IP_HAS_NETC_PLTDIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK)
    PERI_HIGH_SPEED_REST_USDHC_CLK = CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK)
    PERI_HIGH_SPEED_REST_XSPI_CLK = CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK,
#endif
#if defined(CLOCK_IP_HAS_PERI_HIGH_SPEED_TRACE_CLK)
    PERI_HIGH_SPEED_TRACE_CLK = CLOCK_IP_HAS_PERI_HIGH_SPEED_TRACE_CLK,
#endif
#if defined(CLOCK_IP_HAS_PHY_ETH_CLK)
    PHY_ETH_CLK               = CLOCK_IP_HAS_PHY_ETH_CLK,
#endif
#if defined(CLOCK_IP_HAS_PIT0_IPG_CLK_OSC)
    PIT0_IPG_CLK_OSC          = CLOCK_IP_HAS_PIT0_IPG_CLK_OSC,
#endif
#if defined(CLOCK_IP_HAS_PIT0_IPG_CLK_SYNC)
    PIT0_IPG_CLK_SYNC         = CLOCK_IP_HAS_PIT0_IPG_CLK_SYNC,
#endif
#if defined(CLOCK_IP_HAS_PIT1_IPG_CLK_OSC)
    PIT1_IPG_CLK_OSC          = CLOCK_IP_HAS_PIT1_IPG_CLK_OSC,
#endif
#if defined(CLOCK_IP_HAS_PIT1_IPG_CLK_SYNC)
    PIT1_IPG_CLK_SYNC         = CLOCK_IP_HAS_PIT1_IPG_CLK_SYNC,
#endif
#if defined(CLOCK_IP_HAS_PIT2_IPG_CLK_OSC)
    PIT2_IPG_CLK_OSC          = CLOCK_IP_HAS_PIT2_IPG_CLK_OSC,
#endif
#if defined(CLOCK_IP_HAS_PIT2_IPG_CLK_SYNC)
    PIT2_IPG_CLK_SYNC         = CLOCK_IP_HAS_PIT2_IPG_CLK_SYNC,
#endif
#if defined(CLOCK_IP_HAS_PIT3_IPG_CLK_OSC)
    PIT3_IPG_CLK_OSC          = CLOCK_IP_HAS_PIT3_IPG_CLK_OSC,
#endif
#if defined(CLOCK_IP_HAS_PIT3_IPG_CLK_SYNC)
    PIT3_IPG_CLK_SYNC         = CLOCK_IP_HAS_PIT3_IPG_CLK_SYNC,
#endif
#if defined(CLOCK_IP_HAS_POST_IPG_CLK)
    POST_IPG_CLK              = CLOCK_IP_HAS_POST_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_RR_RTC_CLK)
    RR_RTC_CLK                   = CLOCK_IP_HAS_RR_RTC_CLK,
#endif
#if defined(CLOCK_IP_HAS_RXLUT_ERM_CLK)
    RXLUT_ERM_CLK             = CLOCK_IP_HAS_RXLUT_ERM_CLK,
#endif
#if defined(CLOCK_IP_HAS_RXLUT_IPG_CLK)
    RXLUT_IPG_CLK             = CLOCK_IP_HAS_RXLUT_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SAI0_MCLK)
    SAI0_MCLK                 = CLOCK_IP_HAS_SAI0_MCLK,
#endif
#if defined(CLOCK_IP_HAS_SAI0_IO_MCLK)
    SAI0_IO_MCLK              = CLOCK_IP_HAS_SAI0_IO_MCLK,
#endif
#if defined(CLOCK_IP_HAS_SAI0_IPG_CLK)
    SAI0_IPG_CLK              = CLOCK_IP_HAS_SAI0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SAI1_IO_MCLK)
    SAI1_IO_MCLK              = CLOCK_IP_HAS_SAI1_IO_MCLK,
#endif
#if defined(CLOCK_IP_HAS_SAI1_IPG_CLK)
    SAI1_IPG_CLK              = CLOCK_IP_HAS_SAI1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SAI1_MCLK)
    SAI1_MCLK                 = CLOCK_IP_HAS_SAI1_MCLK,
#endif
#if defined(CLOCK_IP_HAS_SDHC_IPG_CLK)
    SDHC_IPG_CLK              = CLOCK_IP_HAS_SDHC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SDHC_PER_CLK)
    SDHC_PER_CLK              = CLOCK_IP_HAS_SDHC_PER_CLK,
#endif
#if defined(CLOCK_IP_HAS_SEMA42_IPG_CLK)
    SEMA42_IPG_CLK            = CLOCK_IP_HAS_SEMA42_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SERDES_ALT_REF_CLK)
    SERDES_ALT_REF_CLK        = CLOCK_IP_HAS_SERDES_ALT_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_SERDES_AUX_CLK)
    SERDES_AUX_CLK            = CLOCK_IP_HAS_SERDES_AUX_CLK,
#endif
#if defined(CLOCK_IP_HAS_SERDES_REF_CLK)
    SERDES_REF_CLK            = CLOCK_IP_HAS_SERDES_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_SINC_IPG_CLK)
    SINC_IPG_CLK              = CLOCK_IP_HAS_SINC_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SOG_REST_CMU_IPG_CLK)
    SOG_REST_CMU_IPG_CLK      = CLOCK_IP_HAS_SOG_REST_CMU_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_FIRC_CLK)
    SRC_FIRC_CLK              = CLOCK_IP_HAS_SRC_FIRC_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_FIRCDIV2_CLK)
    SRC_FIRCDIV2_CLK          = CLOCK_IP_HAS_SRC_FIRCDIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_FXOSC_CLK)
    SRC_FXOSC_CLK             = CLOCK_IP_HAS_SRC_FXOSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_LPE_CLK)
    SRC_LPE_CLK          = CLOCK_IP_HAS_SRC_LPE_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_LPE_DIV1_CLK)
    SRC_LPE_DIV1_CLK          = CLOCK_IP_HAS_SRC_LPE_DIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_LPE_DIV2_CLK)
    SRC_LPE_DIV2_CLK          = CLOCK_IP_HAS_SRC_LPE_DIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_LPE_DIV4_CLK)
    SRC_LPE_DIV4_CLK          = CLOCK_IP_HAS_SRC_LPE_DIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_LPE_DIV8_CLK)
    SRC_LPE_DIV8_CLK          = CLOCK_IP_HAS_SRC_LPE_DIV8_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PLT_CLK)
    SRC_PLT_CLK               = CLOCK_IP_HAS_SRC_PLT_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PLTCORE_CLK)
    SRC_PLTCORE_CLK           = CLOCK_IP_HAS_SRC_PLTCORE_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PLTDIV1_CLK)
    SRC_PLTDIV1_CLK           = CLOCK_IP_HAS_SRC_PLTDIV1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PLTDIV2_CLK)
    SRC_PLTDIV2_CLK           = CLOCK_IP_HAS_SRC_PLTDIV2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PLTDIV4_CLK)
    SRC_PLTDIV4_CLK           = CLOCK_IP_HAS_SRC_PLTDIV4_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_SIRC_CLK)
    SRC_SIRC_CLK              = CLOCK_IP_HAS_SRC_SIRC_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_SXOSC_CLK)
    SRC_SXOSC_CLK             = CLOCK_IP_HAS_SRC_SXOSC_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRAM0_CONTROLLER_IPS_CLK)
    SRAM0_CONTROLLER_IPS_CLK  = CLOCK_IP_HAS_SRAM0_CONTROLLER_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRAM1_CONTROLLER_IPS_CLK)
    SRAM1_CONTROLLER_IPS_CLK  = CLOCK_IP_HAS_SRAM1_CONTROLLER_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRAM2_CONTROLLER_IPS_CLK)
    SRAM2_CONTROLLER_IPS_CLK  = CLOCK_IP_HAS_SRAM2_CONTROLLER_IPS_CLK,
#endif
#if defined(CLOCK_IP_HAS_STAM_CLK)
    STAM_CLK                  = CLOCK_IP_HAS_STAM_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM0_CLK)
    STM0_CLK                  = CLOCK_IP_HAS_STM0_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM0_IPG_CLK)
    STM0_IPG_CLK              = CLOCK_IP_HAS_STM0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM1_CLK)
    STM1_CLK                  = CLOCK_IP_HAS_STM1_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM1_IPG_CLK)
    STM1_IPG_CLK              = CLOCK_IP_HAS_STM1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM2_CLK)
    STM2_CLK                  = CLOCK_IP_HAS_STM2_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM2_IPG_CLK)
    STM2_IPG_CLK              = CLOCK_IP_HAS_STM2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM3_CLK)
    STM3_CLK                  = CLOCK_IP_HAS_STM3_CLK,
#endif
#if defined(CLOCK_IP_HAS_STM3_IPG_CLK)
    STM3_IPG_CLK              = CLOCK_IP_HAS_STM3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT_STARTUP_IPG_CLK)
    SWT_STARTUP_IPG_CLK       = CLOCK_IP_HAS_SWT_STARTUP_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT_STARTUP_IPG_COUNTER_CLK)
    SWT_STARTUP_IPG_COUNTER_CLK = CLOCK_IP_HAS_SWT_STARTUP_IPG_COUNTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT0_IPG_CLK)
    SWT0_IPG_CLK              = CLOCK_IP_HAS_SWT0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT0_IPG_COUNTER_CLK)
    SWT0_IPG_COUNTER_CLK      = CLOCK_IP_HAS_SWT0_IPG_COUNTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT1_IPG_CLK)
    SWT1_IPG_CLK              = CLOCK_IP_HAS_SWT1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT1_IPG_COUNTER_CLK)
    SWT1_IPG_COUNTER_CLK      = CLOCK_IP_HAS_SWT1_IPG_COUNTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT2_IPG_CLK)
    SWT2_IPG_CLK              = CLOCK_IP_HAS_SWT2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT2_IPG_COUNTER_CLK)
    SWT2_IPG_COUNTER_CLK      = CLOCK_IP_HAS_SWT2_IPG_COUNTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT3_IPG_CLK)
    SWT3_IPG_CLK              = CLOCK_IP_HAS_SWT3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_SWT3_IPG_COUNTER_CLK)
    SWT3_IPG_COUNTER_CLK      = CLOCK_IP_HAS_SWT3_IPG_COUNTER_CLK,
#endif
#if defined(CLOCK_IP_HAS_TRACE_CLK)
    TRACE_CLK                 = CLOCK_IP_HAS_TRACE_CLK,
#endif
#if defined(CLOCK_IP_HAS_TRGMUX_IPG_CLK_S)
    TRGMUX_IPG_CLK_S          = CLOCK_IP_HAS_TRGMUX_IPG_CLK_S,
#endif
#if defined(CLOCK_IP_HAS_TRGMUX_MSC_IPG_CLK_S)
    TRGMUX_MSC_IPG_CLK_S      = CLOCK_IP_HAS_TRGMUX_MSC_IPG_CLK_S,
#endif
#if defined(CLOCK_IP_HAS_VWRAP0_IPG_CLK)
    VWRAP0_IPG_CLK            = CLOCK_IP_HAS_VWRAP0_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_VWRAP1_IPG_CLK)
    VWRAP1_IPG_CLK            = CLOCK_IP_HAS_VWRAP1_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_VWRAP2_IPG_CLK)
    VWRAP2_IPG_CLK            = CLOCK_IP_HAS_VWRAP2_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_VWRAP3_IPG_CLK)
    VWRAP3_IPG_CLK            = CLOCK_IP_HAS_VWRAP3_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_XSPI_IPG_CLK)
    XSPI_IPG_CLK              = CLOCK_IP_HAS_XSPI_IPG_CLK,
#endif
#if defined(CLOCK_IP_HAS_XSPI_UNGATED_2XSFIF_CLK)
    XSPI_UNGATED_2XSFIF_CLK   = CLOCK_IP_HAS_XSPI_UNGATED_2XSFIF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_EXT_REF_CLK)
    P0_EXT_REF_CLK            = CLOCK_IP_HAS_P0_EXT_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_ENET_SCAN_CLK)
    P1_ENET_SCAN_CLK            = CLOCK_IP_HAS_P1_ENET_SCAN_CLK,
#endif
#if defined(CLOCK_IP_HAS_P0_IPS_SEL_CLK)
    P0_IPS_SEL_CLK            = CLOCK_IP_HAS_P0_IPS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_EXT_REF_CLK)
    P1_EXT_REF_CLK            = CLOCK_IP_HAS_P1_EXT_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_EXT_REF_CLK)
    P3_EXT_REF_CLK            = CLOCK_IP_HAS_P3_EXT_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P3_IPS_SEL_CLK)
    P3_IPS_SEL_CLK            = CLOCK_IP_HAS_P3_IPS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_IPS_SEL_CLK)
    P4_IPS_SEL_CLK            = CLOCK_IP_HAS_P4_IPS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_EXT_REF_CLK)
    P7_EXT_REF_CLK            = CLOCK_IP_HAS_P7_EXT_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_SECOND_MONITOR_CLK)
    P7_CORE_SECOND_MONITOR_CLK            = CLOCK_IP_HAS_P7_CORE_SECOND_MONITOR_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_DIV2_SECOND_MONITOR_CLK)
    P7_CORE_DIV2_SECOND_MONITOR_CLK            = CLOCK_IP_HAS_P7_CORE_DIV2_SECOND_MONITOR_CLK,
#endif
#if defined(CLOCK_IP_HAS_P7_CORE_DIV2_THIRD_MONITOR_CLK)
    P7_CORE_DIV2_THIRD_MONITOR_CLK            = CLOCK_IP_HAS_P7_CORE_DIV2_THIRD_MONITOR_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_IPS_SEL_CLK)
    P8_IPS_SEL_CLK            = CLOCK_IP_HAS_P8_IPS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_ENET_SCAN_PHY_TX_RX_CLK)
    P1_ENET_SCAN_PHY_TX_RX_CLK            = CLOCK_IP_HAS_P1_ENET_SCAN_PHY_TX_RX_CLK,
#endif
#if defined(CLOCK_IP_HAS_CAN24_CLK)
    CAN24_CLK            = CLOCK_IP_HAS_CAN24_CLK,
#endif
#if defined(CLOCK_IP_HAS_ENET0_CLK)
    ENET0_CLK            = CLOCK_IP_HAS_ENET0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SPI5_CLK)
    SPI5_CLK            = CLOCK_IP_HAS_SPI5_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_SERDES_PIPE_CLK)
    SRC_SERDES_PIPE_CLK            = CLOCK_IP_HAS_SRC_SERDES_PIPE_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_TMR_1588_CLK)
    SRC_TMR_1588_CLK            = CLOCK_IP_HAS_SRC_TMR_1588_CLK,
#endif
#if defined(CLOCK_IP_HAS_P1_IPS_SEL_CLK)
    P1_IPS_SEL_CLK                = CLOCK_IP_HAS_P1_IPS_SEL_CLK,
#endif
#if defined(CLOCK_IP_HAS_P4_QSPI0_1X_CLK)
    P4_QSPI0_1X_CLK               = CLOCK_IP_HAS_P4_QSPI0_1X_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_EXT_REF_CLK)
    P8_EXT_REF_CLK                = CLOCK_IP_HAS_P8_EXT_REF_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_TestClock_1000Mhz_CLK)
    P8_TestClock_1000Mhz_CLK      = CLOCK_IP_HAS_P8_TestClock_1000Mhz_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_TestClock_500Mhz_CLK)
    P8_TestClock_500Mhz_CLK       = CLOCK_IP_HAS_P8_TestClock_500Mhz_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_TestClock_250Mhz_CLK)
    P8_TestClock_250Mhz_CLK       = CLOCK_IP_HAS_P8_TestClock_250Mhz_CLK,
#endif
#if defined(CLOCK_IP_HAS_P8_TestClock_125Mhz_CLK)
    P8_TestClock_125Mhz_CLK       = CLOCK_IP_HAS_P8_TestClock_125Mhz_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_VCO_CLK)
    SRC_COREPLL_VCO_CLK           = CLOCK_IP_HAS_SRC_COREPLL_VCO_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_CLK)
    SRC_COREPLL_CLK               = CLOCK_IP_HAS_SRC_COREPLL_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_CLKOUT0_CLK)
    SRC_COREPLL_CLKOUT0_CLK       = CLOCK_IP_HAS_SRC_COREPLL_CLKOUT0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_CLKOUT1_CLK)
    SRC_COREPLL_CLKOUT1_CLK       = CLOCK_IP_HAS_SRC_COREPLL_CLKOUT1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_CLKOUT2_CLK)
    SRC_COREPLL_CLKOUT2_CLK       = CLOCK_IP_HAS_SRC_COREPLL_CLKOUT2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_CLKOUT3_CLK)
    SRC_COREPLL_CLKOUT3_CLK       = CLOCK_IP_HAS_SRC_COREPLL_CLKOUT3_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_DFS0_CLK)
    SRC_COREPLL_DFS0_CLK          = CLOCK_IP_HAS_SRC_COREPLL_DFS0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_DFS1_CLK)
    SRC_COREPLL_DFS1_CLK          = CLOCK_IP_HAS_SRC_COREPLL_DFS1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_DFS2_CLK)
    SRC_COREPLL_DFS2_CLK          = CLOCK_IP_HAS_SRC_COREPLL_DFS2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_COREPLL_DFS3_CLK)
    SRC_COREPLL_DFS3_CLK          = CLOCK_IP_HAS_SRC_COREPLL_DFS3_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_VCO_CLK)
    SRC_PERIPHPLL_VCO_CLK         = CLOCK_IP_HAS_SRC_PERIPHPLL_VCO_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLK)
    SRC_PERIPHPLL_CLK             = CLOCK_IP_HAS_SRC_PERIPHPLL_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT0_CLK)
    SRC_PERIPHPLL_CLKOUT0_CLK     = CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT1_CLK)
    SRC_PERIPHPLL_CLKOUT1_CLK     = CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT2_CLK)
    SRC_PERIPHPLL_CLKOUT2_CLK     = CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT3_CLK)
    SRC_PERIPHPLL_CLKOUT3_CLK     = CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT3_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT4_CLK)
    SRC_PERIPHPLL_CLKOUT4_CLK     = CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT4_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT5_CLK)
    SRC_PERIPHPLL_CLKOUT5_CLK     = CLOCK_IP_HAS_SRC_PERIPHPLL_CLKOUT5_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_DFS0_CLK)
    SRC_PERIPHPLL_DFS0_CLK        = CLOCK_IP_HAS_SRC_PERIPHPLL_DFS0_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_DFS1_CLK)
    SRC_PERIPHPLL_DFS1_CLK        = CLOCK_IP_HAS_SRC_PERIPHPLL_DFS1_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_DFS2_CLK)
    SRC_PERIPHPLL_DFS2_CLK        = CLOCK_IP_HAS_SRC_PERIPHPLL_DFS2_CLK,
#endif
#if defined(CLOCK_IP_HAS_SRC_PERIPHPLL_DFS3_CLK)
    SRC_PERIPHPLL_DFS3_CLK        = CLOCK_IP_HAS_SRC_PERIPHPLL_DFS3_CLK,
#endif
#if defined(CLOCK_IP_HAS_ZYX_THE_LAST_MCU_CLK)
    ZYX_THE_LAST_MCU_CLK      = CLOCK_IP_HAS_ZYX_THE_LAST_MCU_CLK,
#endif

    THE_LAST_PRODUCER_CLK         = CLOCK_IP_FEATURE_PRODUCERS_NO,     /* Number of producers clocks */
    RESERVED_CLK                  = CLOCK_IP_FEATURE_NAMES_NO,         /* Invalid clock name */
} Clock_Ip_NameType;

/** @brief Clock ip status return codes. */
typedef enum
{
    CLOCK_IP_SUCCESS                            = 0x00U,    /**< Clock tree was initialized successfully. */
    CLOCK_IP_ERROR                              = 0x01U,    /**< One of the elements timeout, clock tree couldn't be initialized. */

} Clock_Ip_StatusType;

/** @brief Clock ip pll status return codes. */
typedef enum
{
    CLOCK_IP_PLL_LOCKED                         = 0x00U,    /**< PLL is locked */
    CLOCK_IP_PLL_UNLOCKED                       = 0x01U,    /**< PLL is unlocked */
    CLOCK_IP_PLL_STATUS_UNDEFINED               = 0x02U,    /**< PLL Status is unknown */

} Clock_Ip_PllStatusType;

/** @brief Clock ip report error types. */
typedef enum
{
    CLOCK_IP_CMU_ERROR                          = 0U,   /**< @brief Cmu Fccu notification. */
    CLOCK_IP_REPORT_TIMEOUT_ERROR               = 1U,   /**< @brief Report Timeout Error. */
    CLOCK_IP_REPORT_FXOSC_CONFIGURATION_ERROR   = 2U,   /**< @brief Report Fxosc Configuration Error. */
    CLOCK_IP_REPORT_CLOCK_MUX_SWITCH_ERROR      = 3U,   /**< @brief Report Clock Mux Switch Error. */
    CLOCK_IP_RAM_MEMORY_CONFIG_ENTRY            = 4U,   /**< @brief Ram config entry point. */
    CLOCK_IP_RAM_MEMORY_CONFIG_EXIT             = 5U,   /**< @brief Ram config exit point. */
    CLOCK_IP_FLASH_MEMORY_CONFIG_ENTRY          = 6U,   /**< @brief Flash config entry point. */
    CLOCK_IP_FLASH_MEMORY_CONFIG_EXIT           = 7U,   /**< @brief Flash config exit point. */
    CLOCK_IP_ACTIVE                             = 8U,   /**< @brief Report Clock Active. */
    CLOCK_IP_INACTIVE                           = 9U,   /**< @brief Report Clock Inactive. */
    CLOCK_IP_REPORT_WRITE_PROTECTION_ERROR      = 10U,  /**< @brief Report Write Protection Error. */
    CLOCK_IP_SET_RAM_WAIT_STATES_ERROR          = 11U,  /**< @brief Set Ram Wait States Error. */
} Clock_Ip_NotificationType;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Clock notifications callback type.
 * Implements ClockNotificationsCallbackType_Class
 */
typedef void (*Clock_Ip_NotificationsCallbackType)(Clock_Ip_NotificationType Error, Clock_Ip_NameType ClockName);


/*!
 * @brief CGM Clock Source XOSC configuration structure.
 * Implements Clock_Ip_XoscConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType       Name;                   /**< Clock name associated to xosc */

    uint32                  Enable;                 /**< Enable xosc. */

    uint32                  Freq;                   /**< External oscillator frequency. */

    uint8                   Mode;           /**< XOSC operation mode (single ended mode, bypass mode, differention mode, crystal mode) */
    uint16                  StartupDelay;           /**< Startup stabilization time. */
    uint8                   TransConductance;       /**< Crystal overdrive protection */

} Clock_Ip_XoscConfigType;

/*!
 * @brief CGM Clock Source PLLDIG configuration structure.
 * Implements Clock_Ip_PllConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType        Name;                           /**< Clock name associated to pll */

    uint16                   Enable;                         /**< Enable pll. */

    Clock_Ip_NameType        InputReference;                 /**< Input reference. */

    uint16                   Predivider;                     /**< Input clock predivider. */
    float                    Multiplier;                     /**< Clock multiplier.  */
    uint16                   Postdivider;                    /**< Postdivider. */

} Clock_Ip_PllConfigType;

/*!
 * @brief Clock selector configuration structure.
 * Implements Clock_Ip_SelectorConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType               Name;                           /**< Clock name associated to selector */
    Clock_Ip_NameType               Source;                         /**< Name of the selected input source */

} Clock_Ip_SelectorConfigType;

/*!
 * @brief Clock divider configuration structure.
 * Implements Clock_Ip_DividerConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType         Name;                           /**< Clock name associated to divider. */
    uint32                    Value;                          /**< Divider value - if value is zero then divider is disabled. */
    uint8                     Options[1U];                    /**< Option divider value - this value depend hardware information. */
} Clock_Ip_DividerConfigType;


/*!
 * @brief Clock fractional divider configuration structure.
 * Implements Clock_Ip_FracDivConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType         Name;                           /**< Clock name associated to fractional divider. */
    float                     Value;                          /**< Divider value - if value is zero then divider is disabled. */

} Clock_Ip_FracDivConfigType;

/*!
 * @brief Clock external clock configuration structure.
 * Implements Clock_Ip_ExtClkConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType         Name;                           /**< Clock name of the external clock. */
    uint64                    Value;                          /**< Enable value - if value is zero then clock is gated, otherwise is enabled in different modes. */

} Clock_Ip_ExtClkConfigType;


/*!
 * @brief Clock gate clock configuration structure.
 * Implements Clock_Ip_GateConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType         Name;                           /**< Clock name associated to clock gate. */
    uint16                    Enable;                         /**< Enable or disable clock */

} Clock_Ip_GateConfigType;

/*!
 * @brief Clock cmu configuration structure.
 * Implements Clock_Ip_CmuConfigType_Class
 */
typedef struct
{
    Clock_Ip_NameType               Name;                           /**< Clock name associated to clock monitor. */
    uint8                           Enable;                         /**< Enable/disable clock monitor */
    uint32                          MonitoredClockFrequency;        /**< Frequency of the clock source from which ramp-down and to which ramp-up are processed. */
} Clock_Ip_CmuConfigType;

/*!
 * @brief Configured frequency structure.
 * Implements Clock_Ip_ConfiguredFrequencyType_Class
 */
typedef struct
{
    Clock_Ip_NameType               Name;                           /**< Clock name of the configured frequency value */
    uint64                          ConfiguredFrequencyValue;       /**< Configured frequency value */
} Clock_Ip_ConfiguredFrequencyType;

/* Check or update hardware state */
typedef enum
{
	CLOCK_IP_SELECTOR_WRITE_PCFS_STEP_DURATION_VALUE = 0x0000,
	CLOCK_IP_SELECTOR_WRITE_PCFS_CHANGE_RATE_VALUE = 0x0001,
	CLOCK_IP_SELECTOR_WRITE_PCFS_DIVIDER_START_VALUE = 0x0002,
	CLOCK_IP_SELECTOR_WRITE_PCFS_DIVIDER_END_VALUE = 0x0003,
	CLOCK_IP_SELECTOR_WRITE_SDUR_VALUE = 0x0004,
	CLOCK_IP_SELECTOR_CHECK_SELECTOR_VALUE = 0x0005,
	CLOCK_IP_SELECTOR_WRITE_SELECTOR_VALUE = 0x0006,
	CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_IN_PROGRESS = 0x0007,
	CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_IN_PROGRESS = 0x0008,
	CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_IS_NOT_REQUESTED = 0x0009,
	CLOCK_IP_SELECTOR_TIMEOUT_IF_CLOCK_SWITCH_IS_STILL_NOT_REQUESTED = 0x000A,
	CLOCK_IP_SELECTOR_CHECK_CLOCK_SWITCH_STATUS = 0x000B,
    CLOCK_IP_GATE_CLOCK = 0x000C,
    CLOCK_IP_UNGATE_CLOCK = 0x000D,
    CLOCK_IP_CMU_SET_REFERENCE_COUNTER_VALUE = 0x000E,
    CLOCK_IP_CMU_SET_HIGH_LIMIT_THRESHOLD = 0x000F,
    CLOCK_IP_CMU_SET_LOW_LIMIT_THRESHOLD = 0x0010,
    CLOCK_IP_CMU_SET_INTERRUPTS = 0x0011,
	CLOCK_IP_CMU_ENABLE_MONITOR = 0x0012,
	CLOCK_IP_CMU_DISABLE_MONITOR = 0x0013,

} Clock_Ip_HwStateType;


/* Check or update hardware state */
typedef enum
{
	CLOCK_IP_SetCmuFcFceRefCntLfrefHfref_TYPE = 0x0000,
	CLOCK_IP_EnableCmuFcFceRefCntLfrefHfref_TYPE = 0x0001,
	CLOCK_IP_ClockSetGateClockControlEnableGprPctl_TYPE = 0x0002,
	CLOCK_IP_SetCgmXCscCssClkswRampupRampdownSwip_TYPE = 0x0003,
    CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwip_TYPE = 0x0004,
    CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwip_TYPE = 0x0005,
    CLOCK_IP_SetCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE = 0x0005,
    CLOCK_IP_WaitCgmXCscCssClkSwSwtrigSwipRmpSw_TYPE = 0x0006,

} Clock_Ip_FunctionNameType;

/* Operation request type */
typedef enum
{
	CLOCK_IP_SET_TYPE = 0x00,
	CLOCK_IP_WAIT_TYPE = 0x01,
	CLOCK_IP_ENABLE_TYPE = 0x02,

} Clock_Ip_OperationRequestType;


/* Resource type */
typedef enum
{
	CLOCK_IP_SELECTOR_TYPE = 0x00,
	CLOCK_IP_GATE_TYPE = 0x01,
	CLOCK_IP_CMU_TYPE = 0x02,

} Clock_Ip_ResourceType;


/* Register operation type */
typedef enum
{
	REGISTER_ACCESS__CHECK_REGISTER_VALUE = 0x00,
	REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_EVENT = 0x01,
	REGISTER_ACCESS__CHECK_NOT_REGISTER_VALUE__WITH_EVENT = 0x02,
	REGISTER_ACCESS__CHECK_REGISTER_VALUE__WITH_TIMEOUT = 0x03,
	REGISTER_ACCESS__READ_MODIFY_WRITE = 0x04,
	REGISTER_ACCESS__WRITE = 0x05,
	REGISTER_ACCESS__SET_BIT = 0x06,
	REGISTER_ACCESS__CLEAR_BIT = 0x07,
	REGISTER_ACCESS__OPS_NO = 0x08,


} Clock_Ip_RegisterAccessOperationType;



/* Register operation type */
typedef enum
{
	REGISTER_ACCESS__NO_EVENT = 0x00,
	REGISTER_ACCESS__TIMEOUT_EVENT = 0x01,
	REGISTER_ACCESS__MUX_SWITCH_ERROR_EVENT = 0x02,

} Clock_Ip_RegisterAccessEventType;



typedef struct
{
	Clock_Ip_RegisterAccessOperationType RegisterAccessOperation;
    Clock_Ip_RegisterAccessEventType Event;
    uint16 BufferIndex;

    uint16 RegisterIndex;
    uint8 BranchOffset1;
    uint8 BranchOffset2;

	volatile uint32 *Address;
	volatile const uint32 *ConstAddress;
	uint32 Mask;
	uint32 Value;
	Clock_Ip_NameType ClockName;
	Clock_Ip_ResourceType ResourceType;
	Clock_Ip_OperationRequestType OperationType;

    Clock_Ip_FunctionNameType FunctionName;
    Clock_Ip_HwStateType State;

} Clock_Ip_RegisterType;

/*!
 * @brief Clock configuration structure.
 * Implements Clock_Ip_ClockConfigType_Class
 */
typedef struct
{
    uint32                             ClkConfigId;                                     /**< The ID for Clock configuration */
    uint8                              ClkPartitionId;                                  /**< The ID for Partition. */

    uint8   XoscsCount;
    uint8   PllsCount;                                                                  /**< PLLs count */
    uint8   FracDivsCount;                                                              /**< Fractional dividers count */
    uint8   DividersCount;                                                              /**< Dividers count */
    uint8   SelectorsCount;                                                             /**< Selectors count */
    uint8   ExtClksCount;                                                               /**< External clocks count */
    uint16  GatesCount;                                                                 /**< Clock gates count */
    uint8   CmusCount;                                                                  /**< Clock cmus count */
    uint8   ConfigureFrequenciesCount;                                                  /**< Configured frequencies count */
    uint16  ConfiguredRegistersCount;                                                   /**< Configured frequencies count */

    const Clock_Ip_XoscConfigType            (*Xoscs)[];                                /**< XOSCs */
    const Clock_Ip_PllConfigType             (*Plls)[];                                 /**< PLLs */
    const Clock_Ip_FracDivConfigType         (*FracDivs)[];                             /**< Fractional dividers */
    const Clock_Ip_DividerConfigType         (*Dividers)[];                             /**< Dividers */
    const Clock_Ip_SelectorConfigType        (*Selectors)[];                            /**< Selectors */
    const Clock_Ip_ExtClkConfigType          (*ExtClks)[];                              /**< External clocks */
    const Clock_Ip_GateConfigType            (*Gates)[];                                /**< Clock gates */
    const Clock_Ip_CmuConfigType             (*Cmus)[];                                 /**< Clock cmus */
    const Clock_Ip_ConfiguredFrequencyType   (*ConfiguredFrequencies)[];                /**< Configured frequency values */

    const Clock_Ip_RegisterType   (*Registers)[];                /**< Configured frequency values */

} Clock_Ip_ClockConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/



#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TYPES_H */


