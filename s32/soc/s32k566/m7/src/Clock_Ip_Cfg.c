/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file       Clock_Ip_Cfg.c
*   @version    0.8.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Clock_Ip_Private.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_VENDOR_ID_C                      43
#define CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_CFG_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_CFG_SW_MINOR_VERSION_C               8
#define CLOCK_IP_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and Std_Types.h are different"
#endif
#endif    /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/* Check if source file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_CFG_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Cfg.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Private.h are different"
#endif

/* Check if source file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_CFG_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_CFG_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Cfg.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"



static const Clock_Ip_XoscConfigType Clock_Ip_XoscConfigurations_0[CLOCK_IP_CONFIGURED_XOSCS_0_NO] = {

    #if CLOCK_IP_XOSCS_COUNT > 0U
    {
        FXOSC_CLK,                      /* Clock name associated to xosc */
        1U,                             /* Enable xosc. */
        40000000U,                      /* External oscillator frequency. */ 
        3U,                             /*  Xosc mode. */ 
        157U,                           /*  Startup stabilization time. */ 
        12U,                            /*  TransConductance. */ 
    },
    #endif

    #if CLOCK_IP_XOSCS_COUNT > 1U
    {
        SXOSC_CLK,                      /* Clock name associated to xosc */
        0U,                             /* Enable xosc. */
        0U,                             /* External oscillator frequency. */ 
        0U,                             /*  Xosc mode. */ 
        0U,                             /* Startup stabilization time. */
        0U,                             /* TransConductance */
    },
    #endif
};


static const Clock_Ip_FracDivConfigType Clock_Ip_DfsConfigurations_0[CLOCK_IP_CONFIGURED_FRACTIONAL_DIVIDERS_0_NO] = 
{

    #if CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT > 0U
    {
        PLL0_DFS0_CLK,                /* Dfs channel name */
        6.4f,                      /* Fractional part of value by witch clock signal is divided. */
    },
    #endif

    #if CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT > 1U
    {
        PLL0_DFS1_CLK,                /* Dfs channel name */
        4.0f,                      /* Fractional part of value by witch clock signal is divided. */
    },
    #endif

    #if CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT > 2U
    {
        PLL0_DFS2_CLK,                /* Dfs channel name */
        4.0f,                      /* Fractional part of value by witch clock signal is divided. */
    },
    #endif

    #if CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT > 3U
    {
        PLL0_DFS3_CLK,                /* Dfs channel name */
        20.0f,                      /* Fractional part of value by witch clock signal is divided. */
    },
    #endif
};


static const Clock_Ip_SelectorConfigType Clock_Ip_SelectorConfigurations_0[CLOCK_IP_CONFIGURED_SELECTORS_0_NO] = 
{

    #if CLOCK_IP_SELECTORS_COUNT > 0U
    {
        RR_RTC_CLK,                /* Clock name associated to selector  */
        SXOSC_CLK,                     /* Name of the selected input source */
    },
    #endif
};


static const Clock_Ip_GateConfigType Clock_Ip_GateConfigurations_0[CLOCK_IP_CONFIGURED_GATES_0_NO] = 
{

    #if CLOCK_IP_GATES_COUNT > 0U
    {
        ACP_DMA3_H_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 1U
    {
        ACP_DMA3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 2U
    {
        ADC0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 3U
    {
        ADC1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 4U
    {
        BCTU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 5U
    {
        BCTU_IPS_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 6U
    {
        CAN_HUB_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 7U
    {
        CLKBIST_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 8U
    {
        CRC0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 9U
    {
        CRC1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 10U
    {
        CSTCU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 11U
    {
        DMA_CH_MUX0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 12U
    {
        DMA_CH_MUX1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 13U
    {
        DMA4_AXI_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 14U
    {
        DMA4_IPG_S_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 15U
    {
        EDMA_TCD_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 16U
    {
        EIM0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 17U
    {
        EIM1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 18U
    {
        EIM2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 19U
    {
        EIM3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 20U
    {
        EMIOS0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 21U
    {
        EMIOS1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 22U
    {
        EMIOS2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 23U
    {
        ERM0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 24U
    {
        ERM1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 25U
    {
        ERM2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 26U
    {
        ERM3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 27U
    {
        FLEXCAN0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 28U
    {
        FLEXCAN1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 29U
    {
        FLEXCAN2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 30U
    {
        FLEXCAN3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 31U
    {
        FLEXCAN4_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 32U
    {
        FLEXCAN5_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 33U
    {
        FLEXCAN6_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 34U
    {
        FLEXCAN7_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 35U
    {
        FLEXCAN8_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 36U
    {
        FLEXCAN9_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 37U
    {
        FLEXCAN10_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 38U
    {
        FLEXCAN11_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 39U
    {
        FLEXCAN12_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 40U
    {
        FLEXCAN13_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 41U
    {
        FLEXCAN14_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 42U
    {
        FLEXCAN15_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 43U
    {
        FLEXCAN16_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 44U
    {
        FLEXIO0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 45U
    {
        FLEXIO1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 46U
    {
        GPR0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 47U
    {
        GPR1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 48U
    {
        INTM_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 49U
    {
        IPSYNC_CSSI_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 50U
    {
        IPSYNC_CSSI_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 51U
    {
        IPSYNC_CVFCCU_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 52U
    {
        IPSYNC_CVFCCU_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 53U
    {
        IPSYNC_DSPI_IPI_0_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 54U
    {
        IPSYNC_DSPI_IPI_1_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 55U
    {
        IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 56U
    {
        IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 57U
    {
        IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 58U
    {
        IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 59U
    {
        IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 60U
    {
        IPSYNC_LPE_LVFCCU_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 61U
    {
        IPSYNC_LPE_LVFCCU_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 62U
    {
        IPSYNC_LPE_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 63U
    {
        IPSYNC_LPE_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 64U
    {
        IPSYNC_LPE_MC_RGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 65U
    {
        IPSYNC_LPE_MC_RGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 66U
    {
        IPSYNC_LPE_STM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 67U
    {
        IPSYNC_LVFCCU0_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 68U
    {
        IPSYNC_LVFCCU0_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 69U
    {
        IPSYNC_LVFCCU1_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 70U
    {
        IPSYNC_LVFCCU1_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 71U
    {
        IPSYNC_LVFCCU2_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 72U
    {
        IPSYNC_LVFCCU2_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 73U
    {
        IPSYNC_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 74U
    {
        IPSYNC_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 75U
    {
        IPSYNC_NETC_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 76U
    {
        IPSYNC_NETC_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 77U
    {
        IPSYNC_PERI_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 78U
    {
        IPSYNC_PERI_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 79U
    {
        IPSYNC_SAI0_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 80U
    {
        IPSYNC_SAI0_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 81U
    {
        IPSYNC_SAI1_MC_CGM_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 82U
    {
        IPSYNC_SAI1_MC_CGM_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 83U
    {
        IPSYNC_STM0_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 84U
    {
        IPSYNC_STM1_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 85U
    {
        IPSYNC_STM2_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 86U
    {
        IPSYNC_STM3_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 87U
    {
        IPSYNC_XSPI_MASTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 88U
    {
        IPSYNC_XSPI_SLAVE_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 89U
    {
        LCU0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 90U
    {
        LCU1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 91U
    {
        LMEM_HCLK_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 92U
    {
        LPE_ADC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 93U
    {
        LPE_BCTU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 94U
    {
        LPE_BCTU_IPG_CLK_S,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 95U
    {
        LPE_CMU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 96U
    {
        LPE_CRC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 97U
    {
        LPE_CXPI0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 98U
    {
        LPE_CXPI1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 99U
    {
        LPE_DMA_CH_MUX_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 100U
    {
        LPE_EIM_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 101U
    {
        LPE_FIRC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 102U
    {
        LPE_FTM_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 103U
    {
        LPE_FXOSC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 104U
    {
        LPE_GPR0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 105U
    {
        LPE_GPR1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 106U
    {
        LPE_LCU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 107U
    {
        LPE_LPCMP0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 108U
    {
        LPE_LPCMP0_RR_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 109U
    {
        LPE_LPCMP0_SAMPLE_GATED_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 110U
    {
        LPE_LPCMP1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 111U
    {
        LPE_LPCMP1_RR_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 112U
    {
        LPE_LPCMP1_SAMPLE_GATED_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 113U
    {
        LPE_LPCMP2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 114U
    {
        LPE_LPCMP2_RR_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 115U
    {
        LPE_LPCMP2_SAMPLE_GATED_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 116U
    {
        LPE_LPI2C_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 117U
    {
        LPE_LPSPI0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 118U
    {
        LPE_LPSPI1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 119U
    {
        LPE_LPUART0_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 120U
    {
        LPE_LPUART1_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 121U
    {
        LPE_LPUART2_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 122U
    {
        LPE_LSTCU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 123U
    {
        LPE_PIT_RTI_IPG_CLK_OSC_RTI,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 124U
    {
        LPE_PIT_RTI_IPG_CLK_SYNC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 125U
    {
        LPE_RTC_API_FIRC_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 126U
    {
        LPE_RTC_API_FXOSC_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 127U
    {
        LPE_RTC_API_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 128U
    {
        LPE_RTC_API_SIRC_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 129U
    {
        LPE_RTC_API_SXOSC_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 130U
    {
        LPE_SEMA42_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 131U
    {
        LPE_SWT_COUNTER_IP_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 132U
    {
        LPE_SWT_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 133U
    {
        LPE_SXOSC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 134U
    {
        LPE_TRGMUX_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 135U
    {
        LPE_TSPC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 136U
    {
        LPE_TSU_NS_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 137U
    {
        LPE_VIRT_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 138U
    {
        LPE_WKPU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 139U
    {
        LPE_WKPU_IPG_CLK_S,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 140U
    {
        LPI2C0_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 141U
    {
        LPI2C1_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 142U
    {
        LPI2C2_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 143U
    {
        LPI2C3_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 144U
    {
        LPSPI0_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 145U
    {
        LPSPI1_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 146U
    {
        LPSPI2_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 147U
    {
        LPSPI3_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 148U
    {
        LPSPI4_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 149U
    {
        LPSPI5_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 150U
    {
        LPSPI6_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 151U
    {
        LPSPI7_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 152U
    {
        LPUART_MSC_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 153U
    {
        LPUART_MSC_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 154U
    {
        LPUART0_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 155U
    {
        LPUART0_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 156U
    {
        LPUART1_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 157U
    {
        LPUART1_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 158U
    {
        LPUART2_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 159U
    {
        LPUART2_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 160U
    {
        LPUART3_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 161U
    {
        LPUART3_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 162U
    {
        LPUART4_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 163U
    {
        LPUART4_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 164U
    {
        LPUART5_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 165U
    {
        LPUART5_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 166U
    {
        LPUART6_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 167U
    {
        LPUART6_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 168U
    {
        LPUART7_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 169U
    {
        LPUART7_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 170U
    {
        LPUART8_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 171U
    {
        LPUART8_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 172U
    {
        LPUART9_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 173U
    {
        LPUART9_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 174U
    {
        LPUART10_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 175U
    {
        LPUART10_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 176U
    {
        LPUART11_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 177U
    {
        LPUART11_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 178U
    {
        LPUART12_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 179U
    {
        LPUART12_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 180U
    {
        LPUART13_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 181U
    {
        LPUART13_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 182U
    {
        LPUART14_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 183U
    {
        LPUART14_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 184U
    {
        LPUART15_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 185U
    {
        LPUART15_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 186U
    {
        LPUART16_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 187U
    {
        LPUART16_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 188U
    {
        LPUART17_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 189U
    {
        LPUART17_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 190U
    {
        LPUART18_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 191U
    {
        LPUART18_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 192U
    {
        LPUART19_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 193U
    {
        LPUART19_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 194U
    {
        LPUART20_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 195U
    {
        LPUART20_pCLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 196U
    {
        LSTCU_ACCEL_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 197U
    {
        LSTCU_CORE0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 198U
    {
        LSTCU_CORE12_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 199U
    {
        LSTCU_CORE3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 200U
    {
        LSTCU_HSPI_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 201U
    {
        LSTCU_NETC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 202U
    {
        LSTCU_PBRIDGE1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 203U
    {
        LSTCU_PBRIDGE3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 204U
    {
        LSTCU_PBRIDGE4_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 205U
    {
        LSTCU_REST_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 206U
    {
        MRAM_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 207U
    {
        MRAMC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 208U
    {
        MRAMC_IPG_CLK_S,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 209U
    {
        MSCM_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 210U
    {
        MSGINTR0_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 211U
    {
        MSGINTR1_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 212U
    {
        MSGINTR2_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 213U
    {
        MSGINTR3_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 214U
    {
        MSGINTR4_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 215U
    {
        MSGINTR5_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 216U
    {
        MSGINTR6_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 217U
    {
        MSGINTR7_APB_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 218U
    {
        PIT0_IPG_CLK_OSC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 219U
    {
        PIT0_IPG_CLK_SYNC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 220U
    {
        PIT1_IPG_CLK_OSC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 221U
    {
        PIT1_IPG_CLK_SYNC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 222U
    {
        PIT2_IPG_CLK_OSC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 223U
    {
        PIT2_IPG_CLK_SYNC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 224U
    {
        PIT3_IPG_CLK_OSC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 225U
    {
        PIT3_IPG_CLK_SYNC,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 226U
    {
        POST_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 227U
    {
        RXLUT_ERM_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 228U
    {
        RXLUT_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 229U
    {
        SAI0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 230U
    {
        SAI1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 231U
    {
        SDHC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 232U
    {
        SEMA42_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 233U
    {
        SINC_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 234U
    {
        SOG_REST_CMU_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 235U
    {
        SRAM0_CONTROLLER_IPS_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 236U
    {
        SRAM1_CONTROLLER_IPS_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 237U
    {
        SRAM2_CONTROLLER_IPS_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 238U
    {
        STAM_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 239U
    {
        SWT_STARTUP_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 240U
    {
        SWT_STARTUP_IPG_COUNTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 241U
    {
        SWT0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 242U
    {
        SWT0_IPG_COUNTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 243U
    {
        SWT1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 244U
    {
        SWT1_IPG_COUNTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 245U
    {
        SWT2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 246U
    {
        SWT2_IPG_COUNTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 247U
    {
        SWT3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 248U
    {
        SWT3_IPG_COUNTER_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 249U
    {
        TRGMUX_IPG_CLK_S,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 250U
    {
        TRGMUX_MSC_IPG_CLK_S,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 251U
    {
        VWRAP0_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 252U
    {
        VWRAP1_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 253U
    {
        VWRAP2_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 254U
    {
        VWRAP3_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif

    #if CLOCK_IP_GATES_COUNT > 255U
    {
        XSPI_IPG_CLK,                /* Clock name associated to gate */
        1U,                     /* Clock is gated for zero values */
    },
    #endif
};


static const Clock_Ip_ExtClkConfigType Clock_Ip_ExtClkConfigurations_0[CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO] = {

    #if CLOCK_IP_EXT_CLKS_COUNT > 0U
    {
        gated_clk,                    /* name */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 1U
    {
        fast_crystal_oscillator,                    /* name */
        40000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 2U
    {
        slow_crystal_oscillator,                    /* name */
        32800U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 3U
    {
        eth0_mii_rx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 4U
    {
        eth0_mii_tx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 5U
    {
        eth0_rgmii_rx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 6U
    {
        eth0_rgmii_tx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 7U
    {
        eth0_rmii_ref_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 8U
    {
        eth1_mii_rx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 9U
    {
        eth1_mii_tx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 10U
    {
        eth1_rgmii_rx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 11U
    {
        eth1_rgmii_tx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 12U
    {
        eth1_rmii_ref_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 13U
    {
        eth2_mii_rx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 14U
    {
        eth2_mii_tx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 15U
    {
        eth2_rgmii_rx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 16U
    {
        eth2_rgmii_tx_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 17U
    {
        eth2_rmii_ref_ext_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_EXT_CLKS_COUNT > 18U
    {
        ts_1588_clk,                    /* name */
        100000000U,                              /* value */
    },
    #endif
};


static const Clock_Ip_ConfiguredFrequencyType Clock_Ip_ConfiguredFrequencyConfigurations_0[CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO] = {

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 0U
    {
        FIRC_CLK,                    /* Clock name associated */
        400000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 1U
    {
        FIRCDIV2_CLK,                    /* Clock name associated */
        200000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 2U
    {
        SAFE_CLK,                    /* Clock name associated */
        50000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 3U
    {
        SIRC_CLK,                    /* Clock name associated */
        32000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 4U
    {
        FXOSC_CLK,                    /* Clock name associated */
        40000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 5U
    {
        SXOSC_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 6U
    {
        gated_clk,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 7U
    {
        fast_crystal_oscillator,                    /* Clock name associated */
        40000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 8U
    {
        slow_crystal_oscillator,                    /* Clock name associated */
        32800U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 9U
    {
        eth0_mii_rx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 10U
    {
        eth0_mii_tx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 11U
    {
        eth0_rgmii_rx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 12U
    {
        eth0_rgmii_tx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 13U
    {
        eth0_rmii_ref_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 14U
    {
        eth1_mii_rx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 15U
    {
        eth1_mii_tx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 16U
    {
        eth1_rgmii_rx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 17U
    {
        eth1_rgmii_tx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 18U
    {
        eth1_rmii_ref_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 19U
    {
        eth2_mii_rx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 20U
    {
        eth2_mii_tx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 21U
    {
        eth2_rgmii_rx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 22U
    {
        eth2_rgmii_tx_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 23U
    {
        eth2_rmii_ref_ext_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 24U
    {
        ts_1588_clk,                    /* Clock name associated */
        100000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 25U
    {
        PLL0_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 26U
    {
        PLL0_DIV_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 27U
    {
        PLL0_DIV0_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 28U
    {
        PLL0_DIV4_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 29U
    {
        PLL0_DFS0_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 30U
    {
        PLL0_DFS1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 31U
    {
        PLL0_DFS2_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 32U
    {
        PLL0_DFS3_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 33U
    {
        PLL1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 34U
    {
        PLL1_DIV_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 35U
    {
        PLL1_DIV0_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 36U
    {
        CPE_PLL_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 37U
    {
        CPE_DIV_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 38U
    {
        CPE_DIV0_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 39U
    {
        LPE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 40U
    {
        LPE_DIV1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 41U
    {
        LPE_DIV2_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 42U
    {
        LPE_DIV4_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 43U
    {
        LPE_DIV8_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 44U
    {
        PLT_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 45U
    {
        PLTCORE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 46U
    {
        PLTDIV1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 47U
    {
        PLTDIV2_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 48U
    {
        PLTDIV4_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 49U
    {
        CAN_PE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 50U
    {
        DFT_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 51U
    {
        DSPI_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 52U
    {
        ETH_TS_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 53U
    {
        ETH0_RX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 54U
    {
        ETH0_TX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 55U
    {
        ETH1_RX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 56U
    {
        ETH1_TX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 57U
    {
        ETH2_RX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 58U
    {
        ETH2_TX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 59U
    {
        ETH3_RX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 60U
    {
        ETH3_TX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 61U
    {
        ETH4_RX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 62U
    {
        ETH4_TX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 63U
    {
        FLEXCAN_0to7_PE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 64U
    {
        FLEXCAN_8to10_PE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 65U
    {
        FLEXCAN_11to16_PE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 66U
    {
        FLEXIO_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 67U
    {
        LPE_CXPI_PE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 68U
    {
        LPE_DIV1_UNGATED_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 69U
    {
        LPE_DIV2_UNGATED_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 70U
    {
        LPE_DIV3_UNGATED_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 71U
    {
        LPE_DIV4_UNGATED_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 72U
    {
        LPE_FLEXCAN_PE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 73U
    {
        LPE_LPI2C_MOD_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 74U
    {
        LPE_LPSPI_MOD_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 75U
    {
        LPE_LPUART_MOD_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 76U
    {
        LPE_STM_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 77U
    {
        LPE_UNGATED_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 78U
    {
        PERI_HIGH_SPEED_REST_USDHC_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 79U
    {
        PERI_HIGH_SPEED_REST_XSPI_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 80U
    {
        PERI_HIGH_SPEED_TRACE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 81U
    {
        PHY_ETH_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 82U
    {
        RR_RTC_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 83U
    {
        SAI0_MCLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 84U
    {
        SAI1_MCLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 85U
    {
        SERDES_AUX_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 86U
    {
        SERDES_REF_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 87U
    {
        SRC_FIRC_CLK,                    /* Clock name associated */
        400000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 88U
    {
        SRC_FIRCDIV2_CLK,                    /* Clock name associated */
        200000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 89U
    {
        SRC_FXOSC_CLK,                    /* Clock name associated */
        40000000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 90U
    {
        SRC_LPE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 91U
    {
        SRC_LPE_DIV1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 92U
    {
        SRC_LPE_DIV2_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 93U
    {
        SRC_LPE_DIV4_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 94U
    {
        SRC_LPE_DIV8_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 95U
    {
        SRC_PLT_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 96U
    {
        SRC_PLTCORE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 97U
    {
        SRC_PLTDIV1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 98U
    {
        SRC_PLTDIV2_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 99U
    {
        SRC_PLTDIV4_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 100U
    {
        SRC_SIRC_CLK,                    /* Clock name associated */
        32000U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 101U
    {
        SRC_SXOSC_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 102U
    {
        STM0_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 103U
    {
        STM1_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 104U
    {
        STM2_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 105U
    {
        STM3_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif

    #if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 106U
    {
        TRACE_CLK,                    /* Clock name associated */
        0U,                              /* value */
    },
    #endif
};



/* *************************************************************************
 * Configuration structure for Clock Configuration 
 * ************************************************************************* */
const Clock_Ip_ClockConfigType Clock_Ip_aClockConfig[1U] = {

    /*! @brief User Configuration structure clock_Cfg_0 */

    {
        0U,                          /* clkConfigId */
        0U,               /* Clock Partition ID */

        2U,                       /* xoscsCount */
        0U,                       /* pllsCount */
        4U,                       /* fracDivsCount */
        0U,                       /* dividersCount */
        1U,                       /* selectorsCount */
        19U,                       /* extClksCount */
        0U,                       /* gatesCount */
        0U,                       /* cmusCount */
        107U,                       /* configureFrequenciesCount */
        7U,                       /* Registers Count */


         (&Clock_Ip_XoscConfigurations_0),                  /* Pll configurations */
         (NULL_PTR),                       /* Pll configurations */
         (&Clock_Ip_DfsConfigurations_0),                  /* Fractional dividers configurations */
         (NULL_PTR),                       /* dividers configurations */
         (&Clock_Ip_SelectorConfigurations_0),                                /* Selectors configurations */
         (&Clock_Ip_ExtClkConfigurations_0),                    /* extClks configurations */
         (&Clock_Ip_GateConfigurations_0),                                 /* Gates configurations */
         (NULL_PTR),                       /* cmus configurations */
         (&Clock_Ip_ConfiguredFrequencyConfigurations_0),       /* configureFrequencies configurations */
         (NULL_PTR),                        /* Register value configurations */
    },
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */


