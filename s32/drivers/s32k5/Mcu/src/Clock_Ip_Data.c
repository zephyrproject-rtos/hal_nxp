/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Data.c
*   @version    0.8.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
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


#include "Clock_Ip_Private.h"


#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_DATA_VENDOR_ID_C                      43
#define CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_DATA_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_DATA_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_DATA_SW_MINOR_VERSION_C               8
#define CLOCK_IP_DATA_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_DATA_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Data.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_DATA_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Data.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Data.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_DATA_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_DATA_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_DATA_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Data.c and Clock_Ip_Private.h are different"
#endif

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Clock_Ip_Data.c file and RegLockMacros.h file are of the same Autosar version */
    #if ((CLOCK_IP_DATA_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CLOCK_IP_DATA_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Data.c and RegLockMacros.h are different"
    #endif
    #endif
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CLOCK_IP_ALL_INDEX                     0U
#define CLOCK_IP_LPE_INDEX                     1U
#define CLOCK_IP_CPE_INDEX                     2U

#define CLOCK_IP_NO_CALLBACK                   0U
#define CLOCK_IP_MUX_DIV                       1U
#define CLOCK_IP_FXOSC                         1U
#define CLOCK_IP_GATE                          1U
#define CLOCK_IP_PLL_DFS_OUT                   1U
#define CLOCK_IP_PLL_MOD                       1U
#define CLOCK_IP_IRCOSC                        1U
#define CLOCK_IP_IRCOSC_OUT                    1U
#define CLOCK_IP_DIV                           2U
#define CLOCK_IP_MUX_PCFS                      2U
#define CLOCK_IP_SXOSC                         2U
#define CLOCK_IP_PLL_DIV_OUT                   3U
#define CLOCK_IP_MUX_PCFS_CMU                  3U
#define CLOCK_IP_PLL_OUT                       4U
#define CLOCK_IP_MUX_RTC                       4U

#define CLOCK_IP_0_INSTANCE                    0U
#define CLOCK_IP_1_INSTANCE                    1U
#define CLOCK_IP_2_INSTANCE                    2U
#define CLOCK_IP_3_INSTANCE                    3U
#define CLOCK_IP_5_INSTANCE                    5U
#define CLOCK_IP_6_INSTANCE                    6U


#define CLOCK_IP_SEL0_INDEX                    0U
#define CLOCK_IP_SEL1_INDEX                    1U
#define CLOCK_IP_SEL2_INDEX                    2U
#define CLOCK_IP_SEL3_INDEX                    3U
#define CLOCK_IP_SEL4_INDEX                    4U
#define CLOCK_IP_SEL5_INDEX                    5U
#define CLOCK_IP_SEL6_INDEX                    6U
#define CLOCK_IP_SEL7_INDEX                    7U
#define CLOCK_IP_SEL8_INDEX                    8U
#define CLOCK_IP_SEL9_INDEX                    9U
#define CLOCK_IP_SEL10_INDEX                   10U
#define CLOCK_IP_SEL11_INDEX                   11U
#define CLOCK_IP_SEL12_INDEX                   12U
#define CLOCK_IP_SEL13_INDEX                   13U
#define CLOCK_IP_SEL14_INDEX                   14U


#define CLOCK_IP_DIV0_INDEX                    0U
#define CLOCK_IP_DIV1_INDEX                    1U
#define CLOCK_IP_DIV2_INDEX                    2U
#define CLOCK_IP_DIV3_INDEX                    3U
#define CLOCK_IP_DIV4_INDEX                    4U


#define CLOCK_IP_000_DIV_IDS_BITS              0U
#define CLOCK_IP_001_DIV_IDS_BITS              1U


#define CLOCK_IP_NOPLL_TYPE                    1U
#define CLOCK_IP_PLL_TYPE                      2U
#define CLOCK_IP_SEL_TYPE                      4U
#define CLOCK_IP_DIV_TYPE                      8U
#define CLOCK_IP_SEL_DIV_TYPE                  12U
#define CLOCK_IP_GATE_TYPE                     16U
#define CLOCK_IP_SEL_CMU_TYPE                  36U


#ifdef CLOCK_IP_HAS_LPE_UNGATED_CLK
    #ifndef CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_UNGATED_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_UNGATED_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PHY_ETH_CLK
    #ifndef CLOCK_IP_SEL1_PHY_ETH_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PHY_ETH_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_PHY_ETH_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PHY_ETH_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_DSPI_CLK
    #ifndef CLOCK_IP_SEL5_DSPI_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name DSPI_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL5_DSPI_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name DSPI_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXCAN_0to7_PE_CLK
    #ifndef CLOCK_IP_SEL2_FLEXCAN_0to7_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXCAN_0to7_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL2_FLEXCAN_0to7_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXCAN_0to7_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH_TS_CLK
    #ifndef CLOCK_IP_SEL13_ETH_TS_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH_TS_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL13_ETH_TS_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH_TS_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXCAN_8to10_PE_CLK
    #ifndef CLOCK_IP_SEL3_FLEXCAN_8to10_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXCAN_8to10_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL3_FLEXCAN_8to10_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXCAN_8to10_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXCAN_11to16_PE_CLK
    #ifndef CLOCK_IP_SEL4_FLEXCAN_11to16_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXCAN_11to16_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL4_FLEXCAN_11to16_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXCAN_11to16_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXIO_CLK
    #ifndef CLOCK_IP_SEL1_FLEXIO_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXIO_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_FLEXIO_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXIO_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_FLEXCAN_PE_CLK
    #ifndef CLOCK_IP_SEL4_LPE_FLEXCAN_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_FLEXCAN_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL4_LPE_FLEXCAN_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_FLEXCAN_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_STM_CLK
    #ifndef CLOCK_IP_SEL5_LPE_STM_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_STM_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL5_LPE_STM_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_STM_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM0_CLK
    #ifndef CLOCK_IP_SEL6_STM0_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM0_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_STM0_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM0_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM1_CLK
    #ifndef CLOCK_IP_SEL7_STM1_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM1_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL7_STM1_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM1_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM2_CLK
    #ifndef CLOCK_IP_SEL8_STM2_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM2_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL8_STM2_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM2_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM3_CLK
    #ifndef CLOCK_IP_SEL9_STM3_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM3_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL9_STM3_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM3_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_CXPI_PE_CLK
    #ifndef CLOCK_IP_SEL6_LPE_CXPI_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_CXPI_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_LPE_CXPI_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_CXPI_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_LPI2C_MOD_CLK
    #ifndef CLOCK_IP_SEL3_LPE_LPI2C_MOD_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_LPI2C_MOD_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL3_LPE_LPI2C_MOD_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_LPI2C_MOD_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_LPSPI_MOD_CLK
    #ifndef CLOCK_IP_SEL1_LPE_LPSPI_MOD_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_LPSPI_MOD_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_LPE_LPSPI_MOD_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_LPSPI_MOD_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_LPUART_MOD_CLK
    #ifndef CLOCK_IP_SEL2_LPE_LPUART_MOD_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_LPUART_MOD_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL2_LPE_LPUART_MOD_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_LPUART_MOD_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SAI0_MCLK
    #ifndef CLOCK_IP_SEL0_SAI0_MCLK_INDEX
        #error "Selector macro index is not defined although associated clock name SAI0_MCLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_SAI0_MCLK_INDEX
        #error "Selector macro index is  defined although associated clock name SAI0_MCLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SAI1_MCLK
    #ifndef CLOCK_IP_SEL0_SAI1_MCLK_INDEX
        #error "Selector macro index is not defined although associated clock name SAI1_MCLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_SAI1_MCLK_INDEX
        #error "Selector macro index is  defined although associated clock name SAI1_MCLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK
    #ifndef CLOCK_IP_SEL1_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PERI_HIGH_SPEED_REST_USDHC_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PERI_HIGH_SPEED_REST_USDHC_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SERDES_REF_CLK
    #ifndef CLOCK_IP_SEL10_SERDES_REF_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name SERDES_REF_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL10_SERDES_REF_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name SERDES_REF_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK
    #ifndef CLOCK_IP_SEL2_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PERI_HIGH_SPEED_REST_XSPI_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL2_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PERI_HIGH_SPEED_REST_XSPI_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_CLK
    #ifndef CLOCK_IP_SEL0_NODIV_LPE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_NODIV_LPE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PLT_CLK
    #ifndef CLOCK_IP_SEL0_NODIV_PLT_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PLT_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_NODIV_PLT_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PLT_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_CAN_PE_CLK
    #ifndef CLOCK_IP_SEL3_DIV0_CAN_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name CAN_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL3_DIV0_CAN_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name CAN_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_DFT_CLK
    #ifndef CLOCK_IP_SEL10_DIV0_DFT_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name DFT_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL10_DIV0_DFT_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name DFT_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_DSPI_CLK
    #ifndef CLOCK_IP_SEL5_DIV0_DSPI_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name DSPI_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL5_DIV0_DSPI_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name DSPI_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH_TS_CLK
    #ifndef CLOCK_IP_SEL13_DIV0_ETH_TS_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH_TS_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL13_DIV0_ETH_TS_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH_TS_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH0_RX_CLK
    #ifndef CLOCK_IP_SEL3_DIV0_ETH0_RX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH0_RX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL3_DIV0_ETH0_RX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH0_RX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH0_TX_CLK
    #ifndef CLOCK_IP_SEL4_DIV0_ETH0_TX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH0_TX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL4_DIV0_ETH0_TX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH0_TX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH1_RX_CLK
    #ifndef CLOCK_IP_SEL5_DIV0_ETH1_RX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH1_RX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL5_DIV0_ETH1_RX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH1_RX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH1_TX_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_ETH1_TX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH1_TX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_ETH1_TX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH1_TX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH2_RX_CLK
    #ifndef CLOCK_IP_SEL7_DIV0_ETH2_RX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH2_RX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL7_DIV0_ETH2_RX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH2_RX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH2_TX_CLK
    #ifndef CLOCK_IP_SEL8_DIV0_ETH2_TX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH2_TX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL8_DIV0_ETH2_TX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH2_TX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH3_RX_CLK
    #ifndef CLOCK_IP_SEL11_DIV0_ETH3_RX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH3_RX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL11_DIV0_ETH3_RX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH3_RX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH3_TX_CLK
    #ifndef CLOCK_IP_SEL12_DIV0_ETH3_TX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH3_TX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL12_DIV0_ETH3_TX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH3_TX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH4_RX_CLK
    #ifndef CLOCK_IP_SEL13_DIV0_ETH4_RX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH4_RX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL13_DIV0_ETH4_RX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH4_RX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_ETH4_TX_CLK
    #ifndef CLOCK_IP_SEL14_DIV0_ETH4_TX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name ETH4_TX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL14_DIV0_ETH4_TX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name ETH4_TX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXCAN_0to7_PE_CLK
    #ifndef CLOCK_IP_SEL2_DIV0_FLEXCAN_0to7_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXCAN_0to7_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL2_DIV0_FLEXCAN_0to7_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXCAN_0to7_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXCAN_8to10_PE_CLK
    #ifndef CLOCK_IP_SEL3_DIV0_FLEXCAN_8to10_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXCAN_8to10_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL3_DIV0_FLEXCAN_8to10_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXCAN_8to10_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXCAN_11to16_PE_CLK
    #ifndef CLOCK_IP_SEL4_DIV0_FLEXCAN_11to16_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXCAN_11to16_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL4_DIV0_FLEXCAN_11to16_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXCAN_11to16_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_FLEXIO_CLK
    #ifndef CLOCK_IP_SEL1_DIV0_FLEXIO_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name FLEXIO_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_DIV0_FLEXIO_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name FLEXIO_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_CXPI_PE_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_LPE_CXPI_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_CXPI_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_LPE_CXPI_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_CXPI_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_DIV1_UNGATED_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_LPE_DIV1_UNGATED_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_DIV1_UNGATED_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_LPE_DIV1_UNGATED_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_DIV1_UNGATED_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_DIV2_UNGATED_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_LPE_DIV2_UNGATED_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_DIV2_UNGATED_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_LPE_DIV2_UNGATED_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_DIV2_UNGATED_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_DIV3_UNGATED_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_LPE_DIV3_UNGATED_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_DIV3_UNGATED_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_LPE_DIV3_UNGATED_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_DIV3_UNGATED_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_DIV4_UNGATED_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_LPE_DIV4_UNGATED_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_DIV4_UNGATED_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_LPE_DIV4_UNGATED_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_DIV4_UNGATED_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_FLEXCAN_PE_CLK
    #ifndef CLOCK_IP_SEL4_DIV0_LPE_FLEXCAN_PE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_FLEXCAN_PE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL4_DIV0_LPE_FLEXCAN_PE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_FLEXCAN_PE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_LPI2C_MOD_CLK
    #ifndef CLOCK_IP_SEL3_DIV0_LPE_LPI2C_MOD_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_LPI2C_MOD_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL3_DIV0_LPE_LPI2C_MOD_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_LPI2C_MOD_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_LPSPI_MOD_CLK
    #ifndef CLOCK_IP_SEL1_DIV0_LPE_LPSPI_MOD_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_LPSPI_MOD_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_DIV0_LPE_LPSPI_MOD_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_LPSPI_MOD_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_LPUART_MOD_CLK
    #ifndef CLOCK_IP_SEL2_DIV0_LPE_LPUART_MOD_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_LPUART_MOD_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL2_DIV0_LPE_LPUART_MOD_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_LPUART_MOD_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_STM_CLK
    #ifndef CLOCK_IP_SEL5_DIV0_LPE_STM_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_STM_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL5_DIV0_LPE_STM_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_STM_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_LPE_UNGATED_CLK
    #ifndef CLOCK_IP_SEL6_NODIV_LPE_UNGATED_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name LPE_UNGATED_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_NODIV_LPE_UNGATED_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name LPE_UNGATED_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_USDHC_CLK
    #ifndef CLOCK_IP_SEL1_DIV0_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PERI_HIGH_SPEED_REST_USDHC_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_DIV0_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PERI_HIGH_SPEED_REST_USDHC_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PERI_HIGH_SPEED_REST_XSPI_CLK
    #ifndef CLOCK_IP_SEL2_DIV0_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PERI_HIGH_SPEED_REST_XSPI_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL2_DIV0_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PERI_HIGH_SPEED_REST_XSPI_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PERI_HIGH_SPEED_TRACE_CLK
    #ifndef CLOCK_IP_SEL4_DIV0_PERI_HIGH_SPEED_TRACE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PERI_HIGH_SPEED_TRACE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL4_DIV0_PERI_HIGH_SPEED_TRACE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PERI_HIGH_SPEED_TRACE_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_PHY_ETH_CLK
    #ifndef CLOCK_IP_SEL1_DIV0_PHY_ETH_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name PHY_ETH_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL1_DIV0_PHY_ETH_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name PHY_ETH_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_RR_RTC_CLK
    #ifndef CLOCK_IP_SEL0_NODIV_RR_RTC_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name RR_RTC_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_NODIV_RR_RTC_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name RR_RTC_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SAI0_MCLK
    #ifndef CLOCK_IP_SEL0_DIV0_SAI0_MCLK_INDEX
        #error "Selector macro index is not defined although associated clock name SAI0_MCLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_DIV0_SAI0_MCLK_INDEX
        #error "Selector macro index is  defined although associated clock name SAI0_MCLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SAI1_MCLK
    #ifndef CLOCK_IP_SEL0_DIV0_SAI1_MCLK_INDEX
        #error "Selector macro index is not defined although associated clock name SAI1_MCLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL0_DIV0_SAI1_MCLK_INDEX
        #error "Selector macro index is  defined although associated clock name SAI1_MCLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SERDES_AUX_CLK
    #ifndef CLOCK_IP_SEL9_DIV0_SERDES_AUX_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name SERDES_AUX_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL9_DIV0_SERDES_AUX_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name SERDES_AUX_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_SERDES_REF_CLK
    #ifndef CLOCK_IP_SEL10_DIV0_SERDES_REF_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name SERDES_REF_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL10_DIV0_SERDES_REF_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name SERDES_REF_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM0_CLK
    #ifndef CLOCK_IP_SEL6_DIV0_STM0_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM0_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL6_DIV0_STM0_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM0_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM1_CLK
    #ifndef CLOCK_IP_SEL7_DIV0_STM1_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM1_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL7_DIV0_STM1_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM1_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM2_CLK
    #ifndef CLOCK_IP_SEL8_DIV0_STM2_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM2_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL8_DIV0_STM2_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM2_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_STM3_CLK
    #ifndef CLOCK_IP_SEL9_DIV0_STM3_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name STM3_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL9_DIV0_STM3_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name STM3_CLK is not defined"
    #endif
#endif

#ifdef CLOCK_IP_HAS_TRACE_CLK
    #ifndef CLOCK_IP_SEL11_DIV0_TRACE_CLK_INDEX
        #error "Selector macro index is not defined although associated clock name TRACE_CLK is defined"
    #endif
#else
    #ifdef CLOCK_IP_SEL11_DIV0_TRACE_CLK_INDEX
        #error "Selector macro index is  defined although associated clock name TRACE_CLK is not defined"
    #endif
#endif





/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/



/* Clock start constant section data */
#define MCU_START_SEC_CONST_8
#include "Mcu_MemMap.h"

const uint8 Clock_Ip_au8IrcoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8IrcoscOutCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8XoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_FXOSC_CTRL_OSCON_ALC_D_GM_SEL_EOCV_COMP_EN_OSC_BYP_OSC_STAT,/* CLOCK_IP_FXOSC */
    CLOCK_IP_SXOSC_CTRL_OSCON_GM_SEL_EOCV_CURR_PRG_STAT,        /* CLOCK_IP_SXOSC */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8PllCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_PLL_POWERUP_RDIV_MFI_ENABLE_SPREADCTL_STEP_STOP_MFN_REF_CLK_SEL,/* CLOCK_IP_PLL_MOD */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8FractionalDividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_DFS_BYPASS_CLKOUT_ENABLE_MFI_MFN,                  /* CLOCK_IP_PLL_DFS_OUT */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8SelectorCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP,                  /* CLOCK_IP_MUX_DIV */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP_RMP_SW,           /* CLOCK_IP_MUX_PCFS */
    CLOCK_IP_CGM_X_CSC_CSS_CLK_SW_SWTRIG_SWIP_RMP_SW,           /* CLOCK_IP_MUX_PCFS_CMU */
    CLOCK_IP_RTC_RTCC_CLKSELECT,                                /* CLOCK_IP_MUX_RTC */
};
const uint8 Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CGM_X_SLC_Y_DC_DE_DIV_UPD_STAT,                    /* CLOCK_IP_MUX_DIV */
    CLOCK_IP_CGM_X_SLC_Y_DC_DE_DIV_UPD_STAT,                    /* CLOCK_IP_DIV */
    CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_DE_OUTPUT_DIV,               /* CLOCK_IP_PLL_DIV_OUT */
    CLOCK_IP_PLLDIV_OUTPUT_DIVIDER_POSTDIV,                     /* CLOCK_IP_PLL_OUT */
};
const uint8 Clock_Ip_au8DividerTriggerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8GateCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_GPR_X_PCTL_MODULE_PCTL_PCTL,                       /* CLOCK_IP_GATE */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8PcfsCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};
const uint8 Clock_Ip_au8CmuCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT] = {
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
    CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF_RS,                 /* CLOCK_IP_MUX_PCFS_CMU */
    CLOCK_IP_NO_CALLBACK,                                       /* No callback */
};




/* Clock features mapping */
const uint16 Clock_Ip_au16ClockFeatures[CLOCK_IP_NAMES_NO][CLOCK_IP_FEATURES_NO] =
/*
****************************************************************************************************************************************************************************************************************************************************************
**********************************************     ************************   I   ***********************       *       *****************************************       *****************************************       ********************       *************
**********************************************  I  ************************   M   ***********************       *   S   *****************************************   D   *****************************************       ********************       *************
**********************************************  N  ************************   P   ***********************   P   *   E   *****************************************   I   *****************************************   G   ********************       *************
**********************************************  S  ************************   L   ***********************   O   *   L   *****************************************   V   *****************************************   A   ********************   C   *************
**********************************************  T  ************************   E   ***********************   W   *   E   *****************************************   I   *****************************************   T   ********************   M   *************
**********************************************  A  ************************   M   ***********************   E   *   C   *****************************************   D   *****************************************   E   ********************   U   *************
**********************************************  N  ************************   E   ***********************   R   *   T   *****************************************   E   *****************************************       ********************       *************
**********************************************  C  ************************   N   ***********************       *   O   *****************************************   R   *****************************************       ********************       *************
**********************************************  E  ************************   T   ***********************       *   R   *****************************************       *****************************************       ********************       *************
**********************************************     ************************   A   ***********************       *       *****************************************       *****************************************       ********************       *************
**********************************************     ************************   T   ***********************       *       *****************************************       *****************************************       ********************       *************
**********************************************     ************************   I   ***********************       *       *****************************************       *****************************************       ********************       *************
**********************************************     ************************   O   ***********************       *       *****************************************       *****************************************       ********************       *************
**********************************************     ************************   N   ***********************       *       *****************************************       *****************************************       ********************       *************
****************************************************************************************************************************************************************************************************************************************************************/
{
/*   FIRC_CLK clock                      */ {CLOCK_IP_IRCOSC,                CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   FIRC_CLK clock                  */
/*   FIRCDIV2_CLK clock                  */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   FIRCDIV2_CLK clock              */
/*   SAFE_CLK clock                      */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SAFE_CLK clock                  */
/*   SIRC_CLK clock                      */ {CLOCK_IP_IRCOSC,                CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   SIRC_CLK clock                  */
/*   FXOSC_CLK clock                     */ {CLOCK_IP_FXOSC,                 CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   FXOSC_CLK clock                 */
/*   SXOSC_CLK clock                     */ {CLOCK_IP_SXOSC,                 CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   SXOSC_CLK clock                 */
/*   gated_clk clock                     */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   gated_clk clock                 */
/*   fast_crystal_oscillator clock       */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   fast_crystal_oscillator clock   */
/*   slow_crystal_oscillator clock       */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   slow_crystal_oscillator clock   */
/*   eth0_mii_rx_ext_clk clock           */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth0_mii_rx_ext_clk clock       */
/*   eth0_mii_tx_ext_clk clock           */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth0_mii_tx_ext_clk clock       */
/*   eth0_rgmii_rx_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth0_rgmii_rx_ext_clk clock     */
/*   eth0_rgmii_tx_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth0_rgmii_tx_ext_clk clock     */
/*   eth0_rmii_ref_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth0_rmii_ref_ext_clk clock     */
/*   eth1_mii_rx_ext_clk clock           */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth1_mii_rx_ext_clk clock       */
/*   eth1_mii_tx_ext_clk clock           */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth1_mii_tx_ext_clk clock       */
/*   eth1_rgmii_rx_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth1_rgmii_rx_ext_clk clock     */
/*   eth1_rgmii_tx_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth1_rgmii_tx_ext_clk clock     */
/*   eth1_rmii_ref_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth1_rmii_ref_ext_clk clock     */
/*   eth2_mii_rx_ext_clk clock           */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth2_mii_rx_ext_clk clock       */
/*   eth2_mii_tx_ext_clk clock           */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth2_mii_tx_ext_clk clock       */
/*   eth2_rgmii_rx_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth2_rgmii_rx_ext_clk clock     */
/*   eth2_rgmii_tx_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth2_rgmii_tx_ext_clk clock     */
/*   eth2_rmii_ref_ext_clk clock         */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   eth2_rmii_ref_ext_clk clock     */
/*   ts_1588_clk clock                   */ {CLOCK_IP_NO_CALLBACK,           CLOCK_IP_NOPLL_TYPE,            0U,                                                 0U,                                                 0U},         /*   ts_1588_clk clock               */
/*   PLL0_CLK clock                      */ {CLOCK_IP_PLL_MOD,               CLOCK_IP_PLL_TYPE,              0U,                                                 0U,                                                 0U},         /*   PLL0_CLK clock                  */
/*   PLL0_DIV_CLK clock                  */ {CLOCK_IP_PLL_OUT,               0U,                             0U,                                                 0U,                                                 0U},         /*   PLL0_DIV_CLK clock              */
/*   PLL0_DIV0_CLK clock                 */ {CLOCK_IP_PLL_DIV_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV0_INDEX,                                0U,                                                 0U},         /*   PLL0_DIV0_CLK clock             */
/*   PLL0_DIV4_CLK clock                 */ {CLOCK_IP_PLL_DIV_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV4_INDEX,                                0U,                                                 0U},         /*   PLL0_DIV4_CLK clock             */
/*   PLL0_DFS0_CLK clock                 */ {CLOCK_IP_PLL_DFS_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV0_INDEX,                                0U,                                                 0U},         /*   PLL0_DFS0_CLK clock             */
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
/*   PLL0_DFS1_CLK clock                 */ {CLOCK_IP_PLL_DFS_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV1_INDEX,                                0U,                                                 0U},         /*   PLL0_DFS1_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
/*   PLL0_DFS2_CLK clock                 */ {CLOCK_IP_PLL_DFS_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV2_INDEX,                                0U,                                                 0U},         /*   PLL0_DFS2_CLK clock             */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
/*   PLL0_DFS3_CLK clock                 */ {CLOCK_IP_PLL_DFS_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV3_INDEX,                                0U,                                                 0U},         /*   PLL0_DFS3_CLK clock             */
#endif
/*   PLL1_CLK clock                      */ {CLOCK_IP_PLL_MOD,               CLOCK_IP_PLL_TYPE,              0U,                                                 0U,                                                 0U},         /*   PLL1_CLK clock                  */
/*   PLL1_DIV_CLK clock                  */ {CLOCK_IP_PLL_OUT,               0U,                             0U,                                                 0U,                                                 0U},         /*   PLL1_DIV_CLK clock              */
/*   PLL1_DIV0_CLK clock                 */ {CLOCK_IP_PLL_DIV_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV0_INDEX,                                0U,                                                 0U},         /*   PLL1_DIV0_CLK clock             */
/*   CPE_PLL_CLK clock                   */ {CLOCK_IP_PLL_MOD,               CLOCK_IP_PLL_TYPE,              0U,                                                 0U,                                                 0U},         /*   CPE_PLL_CLK clock               */
/*   CPE_DIV_CLK clock                   */ {CLOCK_IP_PLL_OUT,               0U,                             0U,                                                 0U,                                                 0U},         /*   CPE_DIV_CLK clock               */
/*   CPE_DIV0_CLK clock                  */ {CLOCK_IP_PLL_DIV_OUT,           CLOCK_IP_DIV_TYPE,              CLOCK_IP_DIV0_INDEX,                                0U,                                                 0U},         /*   CPE_DIV0_CLK clock              */
/*   LPE_CLK clock                       */ {CLOCK_IP_MUX_PCFS,              CLOCK_IP_SEL_TYPE,                             CLOCK_IP_SEL0_NODIV_LPE_CLK_INDEX,                                                 0U,                                                 0U},         /*   LPE_CLK clock                   */
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
/*   LPE_DIV1_CLK clock                  */ {CLOCK_IP_DIV,                   CLOCK_IP_DIV_TYPE,                             CLOCK_IP_SEL0_NODIV_LPE_CLK_INDEX,                                                 0U,                                                 0U},         /*   LPE_DIV1_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
/*   LPE_DIV2_CLK clock                  */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   LPE_DIV2_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
/*   LPE_DIV4_CLK clock                  */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   LPE_DIV4_CLK clock              */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
/*   LPE_DIV8_CLK clock                  */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   LPE_DIV8_CLK clock              */
#endif
/*   PLT_CLK clock                       */ {CLOCK_IP_MUX_PCFS,              CLOCK_IP_SEL_TYPE,                             CLOCK_IP_SEL0_NODIV_PLT_CLK_INDEX,                                                 0U,                                                 0U},         /*   PLT_CLK clock                   */
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
/*   PLTCORE_CLK clock                   */ {CLOCK_IP_DIV,                   CLOCK_IP_DIV_TYPE,                             CLOCK_IP_SEL0_NODIV_PLT_CLK_INDEX,                                                 0U,                                                 0U},         /*   PLTCORE_CLK clock               */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
/*   PLTDIV1_CLK clock                   */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   PLTDIV1_CLK clock               */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
/*   PLTDIV2_CLK clock                   */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   PLTDIV2_CLK clock               */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
/*   PLTDIV4_CLK clock                   */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   PLTDIV4_CLK clock               */
#endif
/*   THE_LAST_PRODUCER_CLK clock          */ {0U,                          CLOCK_IP_NO_CALLBACK,         0U,    0U,                                             0U,                                             0U,                           0U},                                           /*   THE_LAST_PRODUCER_CLK clock          */
/*   ACP_DMA3_H_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ACP_DMA3_H_CLK clock            */
/*   ACP_DMA3_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ACP_DMA3_IPG_CLK clock          */
/*   ADC0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ADC0_IPG_CLK clock              */
/*   ADC1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ADC1_IPG_CLK clock              */
/*   BCTU_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   BCTU_IPG_CLK clock              */
/*   BCTU_IPS_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   BCTU_IPS_CLK clock              */
/*   CAN_HUB_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   CAN_HUB_IPG_CLK clock           */
/*   CAN_PE_CLK clock                    */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL3_DIV0_CAN_PE_CLK_INDEX,                0U,                                                 0U},         /*   CAN_PE_CLK clock                */
/*   CLKBIST_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   CLKBIST_IPG_CLK clock           */
/*   CRC0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   CRC0_IPG_CLK clock              */
/*   CRC1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   CRC1_IPG_CLK clock              */
/*   CSTCU_IPG_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   CSTCU_IPG_CLK clock             */
/*   DIG_PHY0_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DIG_PHY0_CLK clock              */
/*   DIG_PHY1_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DIG_PHY1_CLK clock              */
/*   DIG_PHY2_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DIG_PHY2_CLK clock              */
/*   DIG_PHY3_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DIG_PHY3_CLK clock              */
/*   DMA_CH_MUX0_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DMA_CH_MUX0_IPG_CLK clock       */
/*   DMA_CH_MUX1_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DMA_CH_MUX1_IPG_CLK clock       */
/*   DMA4_AXI_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DMA4_AXI_CLK clock              */
/*   DMA4_IPG_S_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DMA4_IPG_S_CLK clock            */
/*   DFT_CLK clock                       */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL10_DIV0_DFT_CLK_INDEX,                  0U,                                                 0U},         /*   DFT_CLK clock                   */
/*   DSPI_CLK clock                      */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL5_DIV0_DSPI_CLK_INDEX,                  0U,                                                 0U},         /*   DSPI_CLK clock                  */
/*   DSPI0_IPG_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DSPI0_IPG_CLK clock             */
/*   DSPI1_IPG_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   DSPI1_IPG_CLK clock             */
/*   EDMA_TCD_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EDMA_TCD_CLK clock              */
/*   EIM0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EIM0_IPG_CLK clock              */
/*   EIM1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EIM1_IPG_CLK clock              */
/*   EIM2_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EIM2_IPG_CLK clock              */
/*   EIM3_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EIM3_IPG_CLK clock              */
/*   EMIOS0_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EMIOS0_IPG_CLK clock            */
/*   EMIOS1_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EMIOS1_IPG_CLK clock            */
/*   EMIOS2_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   EMIOS2_IPG_CLK clock            */
/*   ERM0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ERM0_IPG_CLK clock              */
/*   ERM1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ERM1_IPG_CLK clock              */
/*   ERM2_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ERM2_IPG_CLK clock              */
/*   ERM3_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   ERM3_IPG_CLK clock              */
/*   ETH_TS_CLK clock                    */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL13_DIV0_ETH_TS_CLK_INDEX,               0U,                                                 0U},         /*   ETH_TS_CLK clock                */
/*   ETH0_RX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL3_DIV0_ETH0_RX_CLK_INDEX,               0U,                                                 0U},         /*   ETH0_RX_CLK clock               */
/*   ETH0_TX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL4_DIV0_ETH0_TX_CLK_INDEX,               0U,                                                 0U},         /*   ETH0_TX_CLK clock               */
/*   ETH1_RX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL5_DIV0_ETH1_RX_CLK_INDEX,               0U,                                                 0U},         /*   ETH1_RX_CLK clock               */
/*   ETH1_TX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL6_DIV0_ETH1_TX_CLK_INDEX,               0U,                                                 0U},         /*   ETH1_TX_CLK clock               */
/*   ETH2_RX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL7_DIV0_ETH2_RX_CLK_INDEX,               0U,                                                 0U},         /*   ETH2_RX_CLK clock               */
/*   ETH2_TX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL8_DIV0_ETH2_TX_CLK_INDEX,               0U,                                                 0U},         /*   ETH2_TX_CLK clock               */
/*   ETH3_RX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL11_DIV0_ETH3_RX_CLK_INDEX,              0U,                                                 0U},         /*   ETH3_RX_CLK clock               */
/*   ETH3_TX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL12_DIV0_ETH3_TX_CLK_INDEX,              0U,                                                 0U},         /*   ETH3_TX_CLK clock               */
/*   ETH4_RX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL13_DIV0_ETH4_RX_CLK_INDEX,              0U,                                                 0U},         /*   ETH4_RX_CLK clock               */
/*   ETH4_TX_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL14_DIV0_ETH4_TX_CLK_INDEX,              0U,                                                 0U},         /*   ETH4_TX_CLK clock               */
/*   FLEXCAN_0to7_PE_CLK clock           */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL2_DIV0_FLEXCAN_0to7_PE_CLK_INDEX,       0U,                                                 0U},         /*   FLEXCAN_0to7_PE_CLK clock       */
/*   FLEXCAN_8to10_PE_CLK clock          */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL3_DIV0_FLEXCAN_8to10_PE_CLK_INDEX,      0U,                                                 0U},         /*   FLEXCAN_8to10_PE_CLK clock      */
/*   FLEXCAN_11to16_PE_CLK clock         */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL4_DIV0_FLEXCAN_11to16_PE_CLK_INDEX,     0U,                                                 0U},         /*   FLEXCAN_11to16_PE_CLK clock     */
/*   FLEXCAN0_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN0_IPG_CLK clock          */
/*   FLEXCAN0_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN0_PE_NOGATE_CLK clock    */
/*   FLEXCAN0_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN0_TS_CLK clock           */
/*   FLEXCAN1_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN1_IPG_CLK clock          */
/*   FLEXCAN1_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN1_PE_NOGATE_CLK clock    */
/*   FLEXCAN1_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN1_TS_CLK clock           */
/*   FLEXCAN2_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN2_IPG_CLK clock          */
/*   FLEXCAN2_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN2_PE_NOGATE_CLK clock    */
/*   FLEXCAN2_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN2_TS_CLK clock           */
/*   FLEXCAN3_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN3_IPG_CLK clock          */
/*   FLEXCAN3_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN3_PE_NOGATE_CLK clock    */
/*   FLEXCAN3_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN3_TS_CLK clock           */
/*   FLEXCAN4_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN4_IPG_CLK clock          */
/*   FLEXCAN4_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN4_PE_NOGATE_CLK clock    */
/*   FLEXCAN4_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN4_TS_CLK clock           */
/*   FLEXCAN5_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN5_IPG_CLK clock          */
/*   FLEXCAN5_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN5_PE_NOGATE_CLK clock    */
/*   FLEXCAN5_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN5_TS_CLK clock           */
/*   FLEXCAN6_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN6_IPG_CLK clock          */
/*   FLEXCAN6_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN6_PE_NOGATE_CLK clock    */
/*   FLEXCAN6_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN6_TS_CLK clock           */
/*   FLEXCAN7_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN7_IPG_CLK clock          */
/*   FLEXCAN7_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN7_PE_NOGATE_CLK clock    */
/*   FLEXCAN7_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN7_TS_CLK clock           */
/*   FLEXCAN8_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN8_IPG_CLK clock          */
/*   FLEXCAN8_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN8_PE_NOGATE_CLK clock    */
/*   FLEXCAN8_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN8_TS_CLK clock           */
/*   FLEXCAN9_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN9_IPG_CLK clock          */
/*   FLEXCAN9_PE_NOGATE_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN9_PE_NOGATE_CLK clock    */
/*   FLEXCAN9_TS_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN9_TS_CLK clock           */
/*   FLEXCAN10_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN10_IPG_CLK clock         */
/*   FLEXCAN10_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN10_PE_NOGATE_CLK clock   */
/*   FLEXCAN10_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN10_TS_CLK clock          */
/*   FLEXCAN11_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN11_IPG_CLK clock         */
/*   FLEXCAN11_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN11_PE_NOGATE_CLK clock   */
/*   FLEXCAN11_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN11_TS_CLK clock          */
/*   FLEXCAN12_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN12_IPG_CLK clock         */
/*   FLEXCAN12_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN12_PE_NOGATE_CLK clock   */
/*   FLEXCAN12_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN12_TS_CLK clock          */
/*   FLEXCAN13_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN13_IPG_CLK clock         */
/*   FLEXCAN13_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN13_PE_NOGATE_CLK clock   */
/*   FLEXCAN13_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN13_TS_CLK clock          */
/*   FLEXCAN14_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN14_IPG_CLK clock         */
/*   FLEXCAN14_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN14_PE_NOGATE_CLK clock   */
/*   FLEXCAN14_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN14_TS_CLK clock          */
/*   FLEXCAN15_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN15_IPG_CLK clock         */
/*   FLEXCAN15_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN15_PE_NOGATE_CLK clock   */
/*   FLEXCAN15_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN15_TS_CLK clock          */
/*   FLEXCAN16_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN16_IPG_CLK clock         */
/*   FLEXCAN16_PE_NOGATE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN16_PE_NOGATE_CLK clock   */
/*   FLEXCAN16_TS_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXCAN16_TS_CLK clock          */
/*   FLEXIO_CLK clock                    */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL1_DIV0_FLEXIO_CLK_INDEX,                0U,                                                 0U},         /*   FLEXIO_CLK clock                */
/*   FLEXIO0_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXIO0_IPG_CLK clock           */
/*   FLEXIO0_PE_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXIO0_PE_CLK clock            */
/*   FLEXIO1_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXIO1_IPG_CLK clock           */
/*   FLEXIO1_PE_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   FLEXIO1_PE_CLK clock            */
/*   GPR0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   GPR0_IPG_CLK clock              */
/*   GPR1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   GPR1_IPG_CLK clock              */
/*   INTM_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   INTM_IPG_CLK clock              */
/*   IPSYNC_CSSI_MC_CGM_MASTER_CLK       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_CSSI_MC_CGM_MASTER_CLK   */
/*   IPSYNC_CSSI_MC_CGM_SLAVE_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_CSSI_MC_CGM_SLAVE_CLK    */
/*   IPSYNC_CVFCCU_MASTER_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_CVFCCU_MASTER_CLK clock  */
/*   IPSYNC_CVFCCU_SLAVE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_CVFCCU_SLAVE_CLK clock   */
/*   IPSYNC_DSPI_IPI_0_MASTER_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_DSPI_IPI_0_MASTER_CLK    */
/*   IPSYNC_DSPI_IPI_1_MASTER_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_DSPI_IPI_1_MASTER_CLK    */
/*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK */ {CLOCK_IP_GATE,              CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK */
/*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK */ {CLOCK_IP_GATE,               CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK */
/*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK */ {CLOCK_IP_GATE,            CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK */
/*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK */ {CLOCK_IP_GATE,             CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK */
/*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK */ {CLOCK_IP_GATE,         CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK */
/*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK */ {CLOCK_IP_GATE,          CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK */
/*   IPSYNC_LPE_LVFCCU_MASTER_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_LVFCCU_MASTER_CLK    */
/*   IPSYNC_LPE_LVFCCU_SLAVE_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_LVFCCU_SLAVE_CLK     */
/*   IPSYNC_LPE_MC_CGM_MASTER_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_MC_CGM_MASTER_CLK    */
/*   IPSYNC_LPE_MC_CGM_SLAVE_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_MC_CGM_SLAVE_CLK     */
/*   IPSYNC_LPE_MC_RGM_MASTER_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_MC_RGM_MASTER_CLK    */
/*   IPSYNC_LPE_MC_RGM_SLAVE_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_MC_RGM_SLAVE_CLK     */
/*   IPSYNC_LPE_STM_MASTER_CLK clock     */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_STM_MASTER_CLK       */
/*   IPSYNC_LPE_STM_SLAVE_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LPE_STM_SLAVE_CLK clock  */
/*   IPSYNC_LVFCCU0_MASTER_CLK clock     */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LVFCCU0_MASTER_CLK       */
/*   IPSYNC_LVFCCU0_SLAVE_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LVFCCU0_SLAVE_CLK clock  */
/*   IPSYNC_LVFCCU1_MASTER_CLK clock     */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LVFCCU1_MASTER_CLK       */
/*   IPSYNC_LVFCCU1_SLAVE_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LVFCCU1_SLAVE_CLK clock  */
/*   IPSYNC_LVFCCU2_MASTER_CLK clock     */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LVFCCU2_MASTER_CLK       */
/*   IPSYNC_LVFCCU2_SLAVE_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_LVFCCU2_SLAVE_CLK clock  */
/*   IPSYNC_MC_CGM_MASTER_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_MC_CGM_MASTER_CLK clock  */
/*   IPSYNC_MC_CGM_SLAVE_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_MC_CGM_SLAVE_CLK clock   */
/*   IPSYNC_NETC_MC_CGM_MASTER_CLK       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_NETC_MC_CGM_MASTER_CLK   */
/*   IPSYNC_NETC_MC_CGM_SLAVE_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_NETC_MC_CGM_SLAVE_CLK    */
/*   IPSYNC_PERI_MC_CGM_MASTER_CLK       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_PERI_MC_CGM_MASTER_CLK   */
/*   IPSYNC_PERI_MC_CGM_SLAVE_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_PERI_MC_CGM_SLAVE_CLK    */
/*   IPSYNC_SAI0_MC_CGM_MASTER_CLK       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_SAI0_MC_CGM_MASTER_CLK   */
/*   IPSYNC_SAI0_MC_CGM_SLAVE_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_SAI0_MC_CGM_SLAVE_CLK    */
/*   IPSYNC_SAI1_MC_CGM_MASTER_CLK       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_SAI1_MC_CGM_MASTER_CLK   */
/*   IPSYNC_SAI1_MC_CGM_SLAVE_CLK clock  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_SAI1_MC_CGM_SLAVE_CLK    */
/*   IPSYNC_STM0_MASTER_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM0_MASTER_CLK clock    */
/*   IPSYNC_STM0_SLAVE_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM0_SLAVE_CLK clock     */
/*   IPSYNC_STM1_MASTER_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM1_MASTER_CLK clock    */
/*   IPSYNC_STM1_SLAVE_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM1_SLAVE_CLK clock     */
/*   IPSYNC_STM2_MASTER_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM2_MASTER_CLK clock    */
/*   IPSYNC_STM2_SLAVE_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM2_SLAVE_CLK clock     */
/*   IPSYNC_STM3_MASTER_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM3_MASTER_CLK clock    */
/*   IPSYNC_STM3_SLAVE_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_STM3_SLAVE_CLK clock     */
/*   IPSYNC_XSPI_MASTER_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_XSPI_MASTER_CLK clock    */
/*   IPSYNC_XSPI_SLAVE_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   IPSYNC_XSPI_SLAVE_CLK clock     */
/*   LCU0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LCU0_IPG_CLK clock              */
/*   LCU1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LCU1_IPG_CLK clock              */
/*   LMEM_HCLK_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LMEM_HCLK_CLK clock             */
/*   LPE_ADC_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_ADC_IPG_CLK clock           */
/*   LPE_BCTU_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_BCTU_IPG_CLK clock          */
/*   LPE_BCTU_IPG_CLK_S clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_BCTU_IPG_CLK_S clock        */
/*   LPE_CMU_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_CMU_IPG_CLK clock           */
/*   LPE_CRC_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_CRC_IPG_CLK clock           */
/*   LPE_CXPI_PE_CLK clock               */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL6_DIV0_LPE_CXPI_PE_CLK_INDEX,           0U,                                                 0U},         /*   LPE_CXPI_PE_CLK clock           */
/*   LPE_CXPI0_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_CXPI0_IPG_CLK clock         */
/*   LPE_CXPI0_PE_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_CXPI0_PE_CLK clock          */
/*   LPE_CXPI1_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_CXPI1_IPG_CLK clock         */
/*   LPE_CXPI1_PE_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_CXPI1_PE_CLK clock          */
/*   LPE_DIV1_UNGATED_CLK clock          */ {CLOCK_IP_DIV,                   CLOCK_IP_DIV_TYPE,              CLOCK_IP_SEL6_DIV0_LPE_DIV1_UNGATED_CLK_INDEX,      0U,                                                 0U},         /*   LPE_DIV1_UNGATED_CLK clock      */
/*   LPE_DIV2_UNGATED_CLK clock          */ {CLOCK_IP_DIV,                   CLOCK_IP_DIV_TYPE,              CLOCK_IP_SEL6_DIV0_LPE_DIV2_UNGATED_CLK_INDEX,      0U,                                                 0U},         /*   LPE_DIV2_UNGATED_CLK clock      */
/*   LPE_DIV3_UNGATED_CLK clock          */ {CLOCK_IP_DIV,                   CLOCK_IP_DIV_TYPE,              CLOCK_IP_SEL6_DIV0_LPE_DIV3_UNGATED_CLK_INDEX,      0U,                                                 0U},         /*   LPE_DIV3_UNGATED_CLK clock      */
/*   LPE_DIV4_UNGATED_CLK clock          */ {CLOCK_IP_DIV,                   CLOCK_IP_DIV_TYPE,              CLOCK_IP_SEL6_DIV0_LPE_DIV4_UNGATED_CLK_INDEX,      0U,                                                 0U},         /*   LPE_DIV4_UNGATED_CLK clock      */
/*   LPE_DMA_CH_MUX_IPG_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_DMA_CH_MUX_IPG_CLK clock    */
/*   LPE_EIM_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_EIM_IPG_CLK clock           */
/*   LPE_FIRC_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_FIRC_IPG_CLK clock          */
/*   LPE_FLEXCAN_MOD_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_FLEXCAN_MOD_CLK clock       */
/*   LPE_FLEXCAN_PE_CLK clock            */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL4_DIV0_LPE_FLEXCAN_PE_CLK_INDEX,        0U,                                                 0U},         /*   LPE_FLEXCAN_PE_CLK clock        */
/*   LPE_FTM_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_FTM_IPG_CLK clock           */
/*   LPE_FXOSC_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_FXOSC_IPG_CLK clock         */
/*   LPE_GPR0_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_GPR0_IPG_CLK clock          */
/*   LPE_GPR1_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_GPR1_IPG_CLK clock          */
/*   LPE_LCU_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LCU_IPG_CLK clock           */
/*   LPE_LPCMP0_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP0_IPG_CLK clock        */
/*   LPE_LPCMP0_RR_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP0_RR_CLK clock         */
/*   LPE_LPCMP0_SAMPLE_GATED_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP0_SAMPLE_GATED_CLK     */
/*   LPE_LPCMP1_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP1_IPG_CLK clock        */
/*   LPE_LPCMP1_RR_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP1_RR_CLK clock         */
/*   LPE_LPCMP1_SAMPLE_GATED_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP1_SAMPLE_GATED_CLK     */
/*   LPE_LPCMP2_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP2_IPG_CLK clock        */
/*   LPE_LPCMP2_RR_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP2_RR_CLK clock         */
/*   LPE_LPCMP2_SAMPLE_GATED_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPCMP2_SAMPLE_GATED_CLK     */
/*   LPE_LPI2C_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPI2C_CLK clock             */
/*   LPE_LPI2C_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPI2C_IPG_CLK clock         */
/*   LPE_LPI2C_MOD_CLK clock             */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL3_DIV0_LPE_LPI2C_MOD_CLK_INDEX,         0U,                                                 0U},         /*   LPE_LPI2C_MOD_CLK clock         */
/*   LPE_LPSPI_MOD_CLK clock             */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL1_DIV0_LPE_LPSPI_MOD_CLK_INDEX,         0U,                                                 0U},         /*   LPE_LPSPI_MOD_CLK clock         */
/*   LPE_LPSPI0_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPSPI0_CLK clock            */
/*   LPE_LPSPI0_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPSPI0_IPG_CLK clock        */
/*   LPE_LPSPI1_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPSPI1_CLK clock            */
/*   LPE_LPSPI1_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPSPI1_IPG_CLK clock        */
/*   LPE_LPUART_MOD_CLK clock            */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL2_DIV0_LPE_LPUART_MOD_CLK_INDEX,        0U,                                                 0U},         /*   LPE_LPUART_MOD_CLK clock        */
/*   LPE_LPUART0_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPUART0_CLK clock           */
/*   LPE_LPUART0_pCLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPUART0_pCLK clock          */
/*   LPE_LPUART1_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPUART1_CLK clock           */
/*   LPE_LPUART1_pCLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPUART1_pCLK clock          */
/*   LPE_LPUART2_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPUART2_CLK clock           */
/*   LPE_LPUART2_pCLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LPUART2_pCLK clock          */
/*   LPE_LSTCU_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_LSTCU_IPG_CLK clock         */
/*   LPE_PIT_RTI_IPG_CLK_OSC_RTI clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_PIT_RTI_IPG_CLK_OSC_RTI     */
/*   LPE_PIT_RTI_IPG_CLK_SYNC clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_PIT_RTI_IPG_CLK_SYNC clock  */
/*   LPE_RTC_API_FIRC_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_RTC_API_FIRC_CLK clock      */
/*   LPE_RTC_API_FXOSC_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_RTC_API_FXOSC_CLK clock     */
/*   LPE_RTC_API_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_RTC_API_IPG_CLK clock       */
/*   LPE_RTC_API_SIRC_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_RTC_API_SIRC_CLK clock      */
/*   LPE_RTC_API_SXOSC_CLK clock         */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_RTC_API_SXOSC_CLK clock     */
/*   LPE_SEMA42_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_SEMA42_CLK clock            */
/*   LPE_STM_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL5_DIV0_LPE_STM_CLK_INDEX,               0U,                                                 0U},         /*   LPE_STM_CLK clock               */
/*   LPE_STM_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_STM_IPG_CLK clock           */
/*   LPE_SWT_COUNTER_IP_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_SWT_COUNTER_IP_CLK clock    */
/*   LPE_SWT_IPG_CLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_SWT_IPG_CLK clock           */
/*   LPE_SXOSC_IPG_CLK clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_SXOSC_IPG_CLK clock         */
/*   LPE_TRGMUX_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_TRGMUX_IPG_CLK clock        */
/*   LPE_TSPC_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_TSPC_IPG_CLK clock          */
/*   LPE_TSU_NS_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_TSU_NS_IPG_CLK clock        */
/*   LPE_UNGATED_CLK clock               */ {CLOCK_IP_MUX_PCFS_CMU,          CLOCK_IP_SEL_CMU_TYPE,          CLOCK_IP_SEL6_NODIV_LPE_UNGATED_CLK_INDEX,          0U,                                                 0U},         /*   LPE_UNGATED_CLK clock           */
/*   LPE_VIRT_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_VIRT_IPG_CLK clock          */
/*   LPE_WKPU_IPG_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_WKPU_IPG_CLK clock          */
/*   LPE_WKPU_IPG_CLK_S clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPE_WKPU_IPG_CLK_S clock        */
/*   LPI2C0_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPI2C0_CLK clock                */
/*   LPI2C1_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPI2C1_CLK clock                */
/*   LPI2C2_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPI2C2_CLK clock                */
/*   LPI2C3_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPI2C3_CLK clock                */
/*   LPSPI0_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI0_CLK clock                */
/*   LPSPI1_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI1_CLK clock                */
/*   LPSPI2_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI2_CLK clock                */
/*   LPSPI3_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI3_CLK clock                */
/*   LPSPI4_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI4_CLK clock                */
/*   LPSPI5_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI5_CLK clock                */
/*   LPSPI6_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI6_CLK clock                */
/*   LPSPI7_CLK clock                    */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPSPI7_CLK clock                */
/*   LPUART_MSC_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART_MSC_CLK clock            */
/*   LPUART_MSC_pCLK clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART_MSC_pCLK clock           */
/*   LPUART0_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART0_CLK clock               */
/*   LPUART0_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART0_pCLK clock              */
/*   LPUART1_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART1_CLK clock               */
/*   LPUART1_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART1_pCLK clock              */
/*   LPUART2_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART2_CLK clock               */
/*   LPUART2_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART2_pCLK clock              */
/*   LPUART3_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART3_CLK clock               */
/*   LPUART3_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART3_pCLK clock              */
/*   LPUART4_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART4_CLK clock               */
/*   LPUART4_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART4_pCLK clock              */
/*   LPUART5_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART5_CLK clock               */
/*   LPUART5_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART5_pCLK clock              */
/*   LPUART6_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART6_CLK clock               */
/*   LPUART6_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART6_pCLK clock              */
/*   LPUART7_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART7_CLK clock               */
/*   LPUART7_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART7_pCLK clock              */
/*   LPUART8_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART8_CLK clock               */
/*   LPUART8_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART8_pCLK clock              */
/*   LPUART9_CLK clock                   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART9_CLK clock               */
/*   LPUART9_pCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART9_pCLK clock              */
/*   LPUART10_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART10_CLK clock              */
/*   LPUART10_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART10_pCLK clock             */
/*   LPUART11_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART11_CLK clock              */
/*   LPUART11_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART11_pCLK clock             */
/*   LPUART12_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART12_CLK clock              */
/*   LPUART12_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART12_pCLK clock             */
/*   LPUART13_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART13_CLK clock              */
/*   LPUART13_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART13_pCLK clock             */
/*   LPUART14_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART14_CLK clock              */
/*   LPUART14_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART14_pCLK clock             */
/*   LPUART15_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART15_CLK clock              */
/*   LPUART15_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART15_pCLK clock             */
/*   LPUART16_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART16_CLK clock              */
/*   LPUART16_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART16_pCLK clock             */
/*   LPUART17_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART17_CLK clock              */
/*   LPUART17_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART17_pCLK clock             */
/*   LPUART18_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART18_CLK clock              */
/*   LPUART18_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART18_pCLK clock             */
/*   LPUART19_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART19_CLK clock              */
/*   LPUART19_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART19_pCLK clock             */
/*   LPUART20_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART20_CLK clock              */
/*   LPUART20_pCLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LPUART20_pCLK clock             */
/*   LSTCU_ACCEL_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_ACCEL_IPG_CLK clock       */
/*   LSTCU_CORE0_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_CORE0_IPG_CLK clock       */
/*   LSTCU_CORE12_IPG_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_CORE12_IPG_CLK clock      */
/*   LSTCU_CORE3_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_CORE3_IPG_CLK clock       */
/*   LSTCU_HSPI_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_HSPI_IPG_CLK clock        */
/*   LSTCU_NETC_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_NETC_IPG_CLK clock        */
/*   LSTCU_PBRIDGE1_IPG_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_PBRIDGE1_IPG_CLK clock    */
/*   LSTCU_PBRIDGE3_IPG_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_PBRIDGE3_IPG_CLK clock    */
/*   LSTCU_PBRIDGE4_IPG_CLK clock        */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_PBRIDGE4_IPG_CLK clock    */
/*   LSTCU_REST_IPG_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   LSTCU_REST_IPG_CLK clock        */
/*   MRAM_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MRAM_IPG_CLK clock              */
/*   MRAMC_IPG_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MRAMC_IPG_CLK clock             */
/*   MRAMC_IPG_CLK_S clock               */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MRAMC_IPG_CLK_S clock           */
/*   MSCM_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSCM_IPG_CLK clock              */
/*   MSGINTR0_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR0_APB_CLK clock          */
/*   MSGINTR1_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR1_APB_CLK clock          */
/*   MSGINTR2_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR2_APB_CLK clock          */
/*   MSGINTR3_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR3_APB_CLK clock          */
/*   MSGINTR4_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR4_APB_CLK clock          */
/*   MSGINTR5_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR5_APB_CLK clock          */
/*   MSGINTR6_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR6_APB_CLK clock          */
/*   MSGINTR7_APB_CLK clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   MSGINTR7_APB_CLK clock          */
/*   PERI_HIGH_SPEED_REST_USDHC_CLK      */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL1_DIV0_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX, 0U,                                            0U},         /*   PERI_HIGH_SPEED_REST_USDHC_CLK  */
/*   PERI_HIGH_SPEED_REST_XSPI_CLK       */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL2_DIV0_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX, 0U,                                             0U},         /*   PERI_HIGH_SPEED_REST_XSPI_CLK   */
/*   PERI_HIGH_SPEED_TRACE_CLK clock     */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL4_DIV0_PERI_HIGH_SPEED_TRACE_CLK_INDEX, 0U,                                                 0U},         /*   PERI_HIGH_SPEED_TRACE_CLK       */
/*   PHY_ETH_CLK clock                   */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL1_DIV0_PHY_ETH_CLK_INDEX,               0U,                                                 0U},         /*   PHY_ETH_CLK clock               */
/*   PIT0_IPG_CLK_OSC clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT0_IPG_CLK_OSC clock          */
/*   PIT0_IPG_CLK_SYNC clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT0_IPG_CLK_SYNC clock         */
/*   PIT1_IPG_CLK_OSC clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT1_IPG_CLK_OSC clock          */
/*   PIT1_IPG_CLK_SYNC clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT1_IPG_CLK_SYNC clock         */
/*   PIT2_IPG_CLK_OSC clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT2_IPG_CLK_OSC clock          */
/*   PIT2_IPG_CLK_SYNC clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT2_IPG_CLK_SYNC clock         */
/*   PIT3_IPG_CLK_OSC clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT3_IPG_CLK_OSC clock          */
/*   PIT3_IPG_CLK_SYNC clock             */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   PIT3_IPG_CLK_SYNC clock         */
/*   POST_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   POST_IPG_CLK clock              */
/*   RR_RTC_CLK clock                    */ {CLOCK_IP_MUX_RTC,               CLOCK_IP_SEL_TYPE,              CLOCK_IP_SEL0_NODIV_RR_RTC_CLK_INDEX,               0U,                                                 0U},         /*   RR_RTC_CLK clock                */
/*   RXLUT_ERM_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   RXLUT_ERM_CLK clock             */
/*   RXLUT_IPG_CLK clock                 */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   RXLUT_IPG_CLK clock             */
/*   SAI0_MCLK clock                     */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL0_DIV0_SAI0_MCLK_INDEX,                 0U,                                                 0U},         /*   SAI0_MCLK clock                 */
/*   SAI0_IO_MCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SAI0_IO_MCLK clock              */
/*   SAI0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SAI0_IPG_CLK clock              */
/*   SAI1_IO_MCLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SAI1_IO_MCLK clock              */
/*   SAI1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SAI1_IPG_CLK clock              */
/*   SAI1_MCLK clock                     */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL0_DIV0_SAI1_MCLK_INDEX,                 0U,                                                 0U},         /*   SAI1_MCLK clock                 */
/*   SDHC_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SDHC_IPG_CLK clock              */
/*   SDHC_PER_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SDHC_PER_CLK clock              */
/*   SEMA42_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SEMA42_IPG_CLK clock            */
/*   SERDES_ALT_REF_CLK clock            */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SERDES_ALT_REF_CLK clock        */
/*   SERDES_AUX_CLK clock                */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL9_DIV0_SERDES_AUX_CLK_INDEX,            0U,                                                 0U},         /*   SERDES_AUX_CLK clock            */
/*   SERDES_REF_CLK clock                */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL10_DIV0_SERDES_REF_CLK_INDEX,           0U,                                                 0U},         /*   SERDES_REF_CLK clock            */
/*   SINC_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SINC_IPG_CLK clock              */
/*   SOG_REST_CMU_IPG_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SOG_REST_CMU_IPG_CLK clock      */
/*   SRC_FIRC_CLK clock                  */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_FIRC_CLK clock              */
/*   SRC_FIRCDIV2_CLK clock              */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_FIRCDIV2_CLK clock          */
/*   SRC_FXOSC_CLK clock                 */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_FXOSC_CLK clock             */
/*   SRC_LPE_CLK clock                   */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_LPE_CLK clock               */
/*   SRC_LPE_DIV1_CLK clock              */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_LPE_DIV1_CLK clock          */
/*   SRC_LPE_DIV2_CLK clock              */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_LPE_DIV2_CLK clock          */
/*   SRC_LPE_DIV4_CLK clock              */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_LPE_DIV4_CLK clock          */
/*   SRC_LPE_DIV8_CLK clock              */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_LPE_DIV8_CLK clock          */
/*   SRC_PLT_CLK clock                   */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_PLT_CLK clock               */
/*   SRC_PLTCORE_CLK clock               */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_PLTCORE_CLK clock           */
/*   SRC_PLTDIV1_CLK clock               */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_PLTDIV1_CLK clock           */
/*   SRC_PLTDIV2_CLK clock               */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_PLTDIV2_CLK clock           */
/*   SRC_PLTDIV4_CLK clock               */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_PLTDIV4_CLK clock           */
/*   SRC_SIRC_CLK clock                  */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_SIRC_CLK clock              */
/*   SRC_SXOSC_CLK clock                 */ {CLOCK_IP_NO_CALLBACK,           0U,                             0U,                                                 0U,                                                 0U},         /*   SRC_SXOSC_CLK clock             */
/*   SRAM0_CONTROLLER_IPS_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SRAM0_CONTROLLER_IPS_CLK clock  */
/*   SRAM1_CONTROLLER_IPS_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SRAM1_CONTROLLER_IPS_CLK clock  */
/*   SRAM2_CONTROLLER_IPS_CLK clock      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SRAM2_CONTROLLER_IPS_CLK clock  */
/*   STAM_CLK clock                      */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   STAM_CLK clock                  */
/*   STM0_CLK clock                      */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL6_DIV0_STM0_CLK_INDEX,                  0U,                                                 0U},         /*   STM0_CLK clock                  */
/*   STM0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   STM0_IPG_CLK clock              */
/*   STM1_CLK clock                      */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL7_DIV0_STM1_CLK_INDEX,                  0U,                                                 0U},         /*   STM1_CLK clock                  */
/*   STM1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   STM1_IPG_CLK clock              */
/*   STM2_CLK clock                      */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL8_DIV0_STM2_CLK_INDEX,                  0U,                                                 0U},         /*   STM2_CLK clock                  */
/*   STM2_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   STM2_IPG_CLK clock              */
/*   STM3_CLK clock                      */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL9_DIV0_STM3_CLK_INDEX,                  0U,                                                 0U},         /*   STM3_CLK clock                  */
/*   STM3_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   STM3_IPG_CLK clock              */
/*   SWT_STARTUP_IPG_CLK clock           */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT_STARTUP_IPG_CLK clock       */
/*   SWT_STARTUP_IPG_COUNTER_CLK clock   */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT_STARTUP_IPG_COUNTER_CLK     */
/*   SWT0_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT0_IPG_CLK clock              */
/*   SWT0_IPG_COUNTER_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT0_IPG_COUNTER_CLK clock      */
/*   SWT1_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT1_IPG_CLK clock              */
/*   SWT1_IPG_COUNTER_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT1_IPG_COUNTER_CLK clock      */
/*   SWT2_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT2_IPG_CLK clock              */
/*   SWT2_IPG_COUNTER_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT2_IPG_COUNTER_CLK clock      */
/*   SWT3_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT3_IPG_CLK clock              */
/*   SWT3_IPG_COUNTER_CLK clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   SWT3_IPG_COUNTER_CLK clock      */
/*   TRACE_CLK clock                     */ {CLOCK_IP_MUX_DIV,               CLOCK_IP_SEL_DIV_TYPE,          CLOCK_IP_SEL11_DIV0_TRACE_CLK_INDEX,                0U,                                                 0U},         /*   TRACE_CLK clock                 */
/*   TRGMUX_IPG_CLK_S clock              */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   TRGMUX_IPG_CLK_S clock          */
/*   TRGMUX_MSC_IPG_CLK_S clock          */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   TRGMUX_MSC_IPG_CLK_S clock      */
/*   VWRAP0_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   VWRAP0_IPG_CLK clock            */
/*   VWRAP1_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   VWRAP1_IPG_CLK clock            */
/*   VWRAP2_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   VWRAP2_IPG_CLK clock            */
/*   VWRAP3_IPG_CLK clock                */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   VWRAP3_IPG_CLK clock            */
/*   XSPI_IPG_CLK clock                  */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   XSPI_IPG_CLK clock              */
/*   XSPI_UNGATED_2XSFIF_CLK clock       */ {CLOCK_IP_GATE,                  CLOCK_IP_GATE_TYPE,             0U,                                                 0U,                                                 0U},         /*   XSPI_UNGATED_2XSFIF_CLK clock   */
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_8
#include "Mcu_MemMap.h"





/* Clock start constant section data */
#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
    #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
/* Clock name types */
const uint32 Clock_Ip_au8ClockNameTypes[CLOCK_IP_NAMES_NO] =
{
/*   FIRC_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FIRC_CLK clock             */
/*   FIRCDIV2_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FIRCDIV2_CLK clock         */
/*   SAFE_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAFE_CLK clock             */
/*   SIRC_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SIRC_CLK clock             */
/*   FXOSC_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FXOSC_CLK clock            */
/*   SXOSC_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SXOSC_CLK clock            */
/*   gated_clk clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   gated_clk clock            */
/*   fast_crystal_oscillator    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   fast_crystal_oscillator    */
/*   slow_crystal_oscillator    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   slow_crystal_oscillator    */
/*   eth0_mii_rx_ext_clk clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth0_mii_rx_ext_clk clock  */
/*   eth0_mii_tx_ext_clk clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth0_mii_tx_ext_clk clock  */
/*   eth0_rgmii_rx_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth0_rgmii_rx_ext_clk      */
/*   eth0_rgmii_tx_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth0_rgmii_tx_ext_clk      */
/*   eth0_rmii_ref_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth0_rmii_ref_ext_clk      */
/*   eth1_mii_rx_ext_clk clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth1_mii_rx_ext_clk clock  */
/*   eth1_mii_tx_ext_clk clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth1_mii_tx_ext_clk clock  */
/*   eth1_rgmii_rx_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth1_rgmii_rx_ext_clk      */
/*   eth1_rgmii_tx_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth1_rgmii_tx_ext_clk      */
/*   eth1_rmii_ref_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth1_rmii_ref_ext_clk      */
/*   eth2_mii_rx_ext_clk clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth2_mii_rx_ext_clk clock  */
/*   eth2_mii_tx_ext_clk clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth2_mii_tx_ext_clk clock  */
/*   eth2_rgmii_rx_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth2_rgmii_rx_ext_clk      */
/*   eth2_rgmii_tx_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth2_rgmii_tx_ext_clk      */
/*   eth2_rmii_ref_ext_clk      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   eth2_rmii_ref_ext_clk      */
/*   ts_1588_clk clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ts_1588_clk clock          */
/*   PLL0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_CLK clock             */
/*   PLL0_DIV_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DIV_CLK clock         */
/*   PLL0_DIV0_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DIV0_CLK clock        */
/*   PLL0_DIV4_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DIV4_CLK clock        */
/*   PLL0_DFS0_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DFS0_CLK clock        */
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
/*   PLL0_DFS1_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DFS1_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
/*   PLL0_DFS2_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DFS2_CLK clock        */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
/*   PLL0_DFS3_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL0_DFS3_CLK clock        */
#endif
/*   PLL1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL1_CLK clock             */
/*   PLL1_DIV_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL1_DIV_CLK clock         */
/*   PLL1_DIV0_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLL1_DIV0_CLK clock        */
/*   CPE_PLL_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CPE_PLL_CLK clock          */
/*   CPE_DIV_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CPE_DIV_CLK clock          */
/*   CPE_DIV0_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CPE_DIV0_CLK clock         */
/*   LPE_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CLK clock              */
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
/*   LPE_DIV1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV1_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
/*   LPE_DIV2_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV2_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
/*   LPE_DIV4_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV4_CLK clock         */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
/*   LPE_DIV8_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV8_CLK clock         */
#endif
/*   PLT_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLT_CLK clock              */
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
/*   PLTCORE_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLTCORE_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
/*   PLTDIV1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLTDIV1_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
/*   PLTDIV2_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLTDIV2_CLK clock          */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
/*   PLTDIV4_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PLTDIV4_CLK clock          */
#endif
/*   THE_LAST_PRODUCER_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   THE_LAST_PRODUCER_CLK      */
/*   ACP_DMA3_H_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ACP_DMA3_H_CLK clock       */
/*   ACP_DMA3_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ACP_DMA3_IPG_CLK clock     */
/*   ADC0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ADC0_IPG_CLK clock         */
/*   ADC1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ADC1_IPG_CLK clock         */
/*   BCTU_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   BCTU_IPG_CLK clock         */
/*   BCTU_IPS_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   BCTU_IPS_CLK clock         */
/*   CAN_HUB_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CAN_HUB_IPG_CLK clock      */
/*   CAN_PE_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CAN_PE_CLK clock           */
/*   CLKBIST_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CLKBIST_IPG_CLK clock      */
/*   CRC0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CRC0_IPG_CLK clock         */
/*   CRC1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CRC1_IPG_CLK clock         */
/*   CSTCU_IPG_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   CSTCU_IPG_CLK clock        */
/*   DIG_PHY0_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DIG_PHY0_CLK clock         */
/*   DIG_PHY1_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DIG_PHY1_CLK clock         */
/*   DIG_PHY2_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DIG_PHY2_CLK clock         */
/*   DIG_PHY3_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DIG_PHY3_CLK clock         */
/*   DMA_CH_MUX0_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DMA_CH_MUX0_IPG_CLK clock  */
/*   DMA_CH_MUX1_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DMA_CH_MUX1_IPG_CLK clock  */
/*   DMA4_AXI_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DMA4_AXI_CLK clock         */
/*   DMA4_IPG_S_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DMA4_IPG_S_CLK clock       */
/*   DFT_CLK clock              */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DFT_CLK clock              */
/*   DSPI_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DSPI_CLK clock             */
/*   DSPI0_IPG_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DSPI0_IPG_CLK clock        */
/*   DSPI1_IPG_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   DSPI1_IPG_CLK clock        */
/*   EDMA_TCD_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EDMA_TCD_CLK clock         */
/*   EIM0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EIM0_IPG_CLK clock         */
/*   EIM1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EIM1_IPG_CLK clock         */
/*   EIM2_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EIM2_IPG_CLK clock         */
/*   EIM3_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EIM3_IPG_CLK clock         */
/*   EMIOS0_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EMIOS0_IPG_CLK clock       */
/*   EMIOS1_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EMIOS1_IPG_CLK clock       */
/*   EMIOS2_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   EMIOS2_IPG_CLK clock       */
/*   ERM0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ERM0_IPG_CLK clock         */
/*   ERM1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ERM1_IPG_CLK clock         */
/*   ERM2_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ERM2_IPG_CLK clock         */
/*   ERM3_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ERM3_IPG_CLK clock         */
/*   ETH_TS_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH_TS_CLK clock           */
/*   ETH0_RX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH0_RX_CLK clock          */
/*   ETH0_TX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH0_TX_CLK clock          */
/*   ETH1_RX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH1_RX_CLK clock          */
/*   ETH1_TX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH1_TX_CLK clock          */
/*   ETH2_RX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH2_RX_CLK clock          */
/*   ETH2_TX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH2_TX_CLK clock          */
/*   ETH3_RX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH3_RX_CLK clock          */
/*   ETH3_TX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH3_TX_CLK clock          */
/*   ETH4_RX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH4_RX_CLK clock          */
/*   ETH4_TX_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   ETH4_TX_CLK clock          */
/*   FLEXCAN_0to7_PE_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN_0to7_PE_CLK clock  */
/*   FLEXCAN_8to10_PE_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN_8to10_PE_CLK       */
/*   FLEXCAN_11to16_PE_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN_11to16_PE_CLK      */
/*   FLEXCAN0_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN0_IPG_CLK clock     */
/*   FLEXCAN0_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN0_PE_NOGATE_CLK     */
/*   FLEXCAN0_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN0_TS_CLK clock      */
/*   FLEXCAN1_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN1_IPG_CLK clock     */
/*   FLEXCAN1_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN1_PE_NOGATE_CLK     */
/*   FLEXCAN1_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN1_TS_CLK clock      */
/*   FLEXCAN2_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN2_IPG_CLK clock     */
/*   FLEXCAN2_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN2_PE_NOGATE_CLK     */
/*   FLEXCAN2_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN2_TS_CLK clock      */
/*   FLEXCAN3_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN3_IPG_CLK clock     */
/*   FLEXCAN3_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN3_PE_NOGATE_CLK     */
/*   FLEXCAN3_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN3_TS_CLK clock      */
/*   FLEXCAN4_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN4_IPG_CLK clock     */
/*   FLEXCAN4_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN4_PE_NOGATE_CLK     */
/*   FLEXCAN4_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN4_TS_CLK clock      */
/*   FLEXCAN5_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN5_IPG_CLK clock     */
/*   FLEXCAN5_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN5_PE_NOGATE_CLK     */
/*   FLEXCAN5_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN5_TS_CLK clock      */
/*   FLEXCAN6_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN6_IPG_CLK clock     */
/*   FLEXCAN6_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN6_PE_NOGATE_CLK     */
/*   FLEXCAN6_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN6_TS_CLK clock      */
/*   FLEXCAN7_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN7_IPG_CLK clock     */
/*   FLEXCAN7_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN7_PE_NOGATE_CLK     */
/*   FLEXCAN7_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN7_TS_CLK clock      */
/*   FLEXCAN8_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN8_IPG_CLK clock     */
/*   FLEXCAN8_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN8_PE_NOGATE_CLK     */
/*   FLEXCAN8_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN8_TS_CLK clock      */
/*   FLEXCAN9_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN9_IPG_CLK clock     */
/*   FLEXCAN9_PE_NOGATE_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN9_PE_NOGATE_CLK     */
/*   FLEXCAN9_TS_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN9_TS_CLK clock      */
/*   FLEXCAN10_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN10_IPG_CLK clock    */
/*   FLEXCAN10_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN10_PE_NOGATE_CLK    */
/*   FLEXCAN10_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN10_TS_CLK clock     */
/*   FLEXCAN11_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN11_IPG_CLK clock    */
/*   FLEXCAN11_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN11_PE_NOGATE_CLK    */
/*   FLEXCAN11_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN11_TS_CLK clock     */
/*   FLEXCAN12_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN12_IPG_CLK clock    */
/*   FLEXCAN12_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN12_PE_NOGATE_CLK    */
/*   FLEXCAN12_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN12_TS_CLK clock     */
/*   FLEXCAN13_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN13_IPG_CLK clock    */
/*   FLEXCAN13_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN13_PE_NOGATE_CLK    */
/*   FLEXCAN13_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN13_TS_CLK clock     */
/*   FLEXCAN14_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN14_IPG_CLK clock    */
/*   FLEXCAN14_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN14_PE_NOGATE_CLK    */
/*   FLEXCAN14_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN14_TS_CLK clock     */
/*   FLEXCAN15_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN15_IPG_CLK clock    */
/*   FLEXCAN15_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN15_PE_NOGATE_CLK    */
/*   FLEXCAN15_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN15_TS_CLK clock     */
/*   FLEXCAN16_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN16_IPG_CLK clock    */
/*   FLEXCAN16_PE_NOGATE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN16_PE_NOGATE_CLK    */
/*   FLEXCAN16_TS_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXCAN16_TS_CLK clock     */
/*   FLEXIO_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXIO_CLK clock           */
/*   FLEXIO0_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXIO0_IPG_CLK clock      */
/*   FLEXIO0_PE_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXIO0_PE_CLK clock       */
/*   FLEXIO1_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXIO1_IPG_CLK clock      */
/*   FLEXIO1_PE_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   FLEXIO1_PE_CLK clock       */
/*   GPR0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   GPR0_IPG_CLK clock         */
/*   GPR1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   GPR1_IPG_CLK clock         */
/*   INTM_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   INTM_IPG_CLK clock         */
/*   IPSYNC_CSSI_MC_CGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_CSSI_MC_CGM_MASTER_CLK */
/*   IPSYNC_CSSI_MC_CGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_CSSI_MC_CGM_SLAVE_CLK */
/*   IPSYNC_CVFCCU_MASTER_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_CVFCCU_MASTER_CLK   */
/*   IPSYNC_CVFCCU_SLAVE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_CVFCCU_SLAVE_CLK    */
/*   IPSYNC_DSPI_IPI_0_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_DSPI_IPI_0_MASTER_CLK */
/*   IPSYNC_DSPI_IPI_1_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_DSPI_IPI_1_MASTER_CLK */
/*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK */
/*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK */
/*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK */
/*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK */
/*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK */
/*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK */
/*   IPSYNC_LPE_LVFCCU_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_LVFCCU_MASTER_CLK */
/*   IPSYNC_LPE_LVFCCU_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_LVFCCU_SLAVE_CLK */
/*   IPSYNC_LPE_MC_CGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_MC_CGM_MASTER_CLK */
/*   IPSYNC_LPE_MC_CGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_MC_CGM_SLAVE_CLK */
/*   IPSYNC_LPE_MC_RGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_MC_RGM_MASTER_CLK */
/*   IPSYNC_LPE_MC_RGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_MC_RGM_SLAVE_CLK */
/*   IPSYNC_LPE_STM_MASTER_CLK  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_STM_MASTER_CLK  */
/*   IPSYNC_LPE_STM_SLAVE_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LPE_STM_SLAVE_CLK   */
/*   IPSYNC_LVFCCU0_MASTER_CLK  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LVFCCU0_MASTER_CLK  */
/*   IPSYNC_LVFCCU0_SLAVE_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LVFCCU0_SLAVE_CLK   */
/*   IPSYNC_LVFCCU1_MASTER_CLK  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LVFCCU1_MASTER_CLK  */
/*   IPSYNC_LVFCCU1_SLAVE_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LVFCCU1_SLAVE_CLK   */
/*   IPSYNC_LVFCCU2_MASTER_CLK  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LVFCCU2_MASTER_CLK  */
/*   IPSYNC_LVFCCU2_SLAVE_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_LVFCCU2_SLAVE_CLK   */
/*   IPSYNC_MC_CGM_MASTER_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_MC_CGM_MASTER_CLK   */
/*   IPSYNC_MC_CGM_SLAVE_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_MC_CGM_SLAVE_CLK    */
/*   IPSYNC_NETC_MC_CGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_NETC_MC_CGM_MASTER_CLK */
/*   IPSYNC_NETC_MC_CGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_NETC_MC_CGM_SLAVE_CLK */
/*   IPSYNC_PERI_MC_CGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_PERI_MC_CGM_MASTER_CLK */
/*   IPSYNC_PERI_MC_CGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_PERI_MC_CGM_SLAVE_CLK */
/*   IPSYNC_SAI0_MC_CGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_SAI0_MC_CGM_MASTER_CLK */
/*   IPSYNC_SAI0_MC_CGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_SAI0_MC_CGM_SLAVE_CLK */
/*   IPSYNC_SAI1_MC_CGM_MASTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_SAI1_MC_CGM_MASTER_CLK */
/*   IPSYNC_SAI1_MC_CGM_SLAVE_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_SAI1_MC_CGM_SLAVE_CLK */
/*   IPSYNC_STM0_MASTER_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM0_MASTER_CLK     */
/*   IPSYNC_STM0_SLAVE_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM0_SLAVE_CLK      */
/*   IPSYNC_STM1_MASTER_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM1_MASTER_CLK     */
/*   IPSYNC_STM1_SLAVE_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM1_SLAVE_CLK      */
/*   IPSYNC_STM2_MASTER_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM2_MASTER_CLK     */
/*   IPSYNC_STM2_SLAVE_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM2_SLAVE_CLK      */
/*   IPSYNC_STM3_MASTER_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM3_MASTER_CLK     */
/*   IPSYNC_STM3_SLAVE_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_STM3_SLAVE_CLK      */
/*   IPSYNC_XSPI_MASTER_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_XSPI_MASTER_CLK     */
/*   IPSYNC_XSPI_SLAVE_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   IPSYNC_XSPI_SLAVE_CLK      */
/*   LCU0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LCU0_IPG_CLK clock         */
/*   LCU1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LCU1_IPG_CLK clock         */
/*   LMEM_HCLK_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LMEM_HCLK_CLK clock        */
/*   LPE_ADC_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_ADC_IPG_CLK clock      */
/*   LPE_BCTU_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_BCTU_IPG_CLK clock     */
/*   LPE_BCTU_IPG_CLK_S clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_BCTU_IPG_CLK_S clock   */
/*   LPE_CMU_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CMU_IPG_CLK clock      */
/*   LPE_CRC_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CRC_IPG_CLK clock      */
/*   LPE_CXPI_PE_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CXPI_PE_CLK clock      */
/*   LPE_CXPI0_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CXPI0_IPG_CLK clock    */
/*   LPE_CXPI0_PE_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CXPI0_PE_CLK clock     */
/*   LPE_CXPI1_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CXPI1_IPG_CLK clock    */
/*   LPE_CXPI1_PE_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_CXPI1_PE_CLK clock     */
/*   LPE_DIV1_UNGATED_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV1_UNGATED_CLK       */
/*   LPE_DIV2_UNGATED_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV2_UNGATED_CLK       */
/*   LPE_DIV3_UNGATED_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV3_UNGATED_CLK       */
/*   LPE_DIV4_UNGATED_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DIV4_UNGATED_CLK       */
/*   LPE_DMA_CH_MUX_IPG_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_DMA_CH_MUX_IPG_CLK     */
/*   LPE_EIM_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_EIM_IPG_CLK clock      */
/*   LPE_FIRC_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_FIRC_IPG_CLK clock     */
/*   LPE_FLEXCAN_MOD_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_FLEXCAN_MOD_CLK clock  */
/*   LPE_FLEXCAN_PE_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_FLEXCAN_PE_CLK clock   */
/*   LPE_FTM_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_FTM_IPG_CLK clock      */
/*   LPE_FXOSC_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_FXOSC_IPG_CLK clock    */
/*   LPE_GPR0_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_GPR0_IPG_CLK clock     */
/*   LPE_GPR1_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_GPR1_IPG_CLK clock     */
/*   LPE_LCU_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LCU_IPG_CLK clock      */
/*   LPE_LPCMP0_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP0_IPG_CLK clock   */
/*   LPE_LPCMP0_RR_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP0_RR_CLK clock    */
/*   LPE_LPCMP0_SAMPLE_GATED_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP0_SAMPLE_GATED_CLK */
/*   LPE_LPCMP1_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP1_IPG_CLK clock   */
/*   LPE_LPCMP1_RR_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP1_RR_CLK clock    */
/*   LPE_LPCMP1_SAMPLE_GATED_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP1_SAMPLE_GATED_CLK */
/*   LPE_LPCMP2_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP2_IPG_CLK clock   */
/*   LPE_LPCMP2_RR_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP2_RR_CLK clock    */
/*   LPE_LPCMP2_SAMPLE_GATED_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPCMP2_SAMPLE_GATED_CLK */
/*   LPE_LPI2C_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPI2C_CLK clock        */
/*   LPE_LPI2C_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPI2C_IPG_CLK clock    */
/*   LPE_LPI2C_MOD_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPI2C_MOD_CLK clock    */
/*   LPE_LPSPI_MOD_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPSPI_MOD_CLK clock    */
/*   LPE_LPSPI0_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPSPI0_CLK clock       */
/*   LPE_LPSPI0_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPSPI0_IPG_CLK clock   */
/*   LPE_LPSPI1_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPSPI1_CLK clock       */
/*   LPE_LPSPI1_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPSPI1_IPG_CLK clock   */
/*   LPE_LPUART_MOD_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART_MOD_CLK clock   */
/*   LPE_LPUART0_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART0_CLK clock      */
/*   LPE_LPUART0_pCLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART0_pCLK clock     */
/*   LPE_LPUART1_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART1_CLK clock      */
/*   LPE_LPUART1_pCLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART1_pCLK clock     */
/*   LPE_LPUART2_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART2_CLK clock      */
/*   LPE_LPUART2_pCLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LPUART2_pCLK clock     */
/*   LPE_LSTCU_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_LSTCU_IPG_CLK clock    */
/*   LPE_PIT_RTI_IPG_CLK_OSC_RTI */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_PIT_RTI_IPG_CLK_OSC_RTI */
/*   LPE_PIT_RTI_IPG_CLK_SYNC   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_PIT_RTI_IPG_CLK_SYNC   */
/*   LPE_RTC_API_FIRC_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_RTC_API_FIRC_CLK       */
/*   LPE_RTC_API_FXOSC_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_RTC_API_FXOSC_CLK      */
/*   LPE_RTC_API_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_RTC_API_IPG_CLK clock  */
/*   LPE_RTC_API_SIRC_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_RTC_API_SIRC_CLK       */
/*   LPE_RTC_API_SXOSC_CLK      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_RTC_API_SXOSC_CLK      */
/*   LPE_SEMA42_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_SEMA42_CLK clock       */
/*   LPE_STM_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_STM_CLK clock          */
/*   LPE_STM_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_STM_IPG_CLK clock      */
/*   LPE_SWT_COUNTER_IP_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_SWT_COUNTER_IP_CLK     */
/*   LPE_SWT_IPG_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_SWT_IPG_CLK clock      */
/*   LPE_SXOSC_IPG_CLK clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_SXOSC_IPG_CLK clock    */
/*   LPE_TRGMUX_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_TRGMUX_IPG_CLK clock   */
/*   LPE_TSPC_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_TSPC_IPG_CLK clock     */
/*   LPE_TSU_NS_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_TSU_NS_IPG_CLK clock   */
/*   LPE_UNGATED_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_UNGATED_CLK clock      */
/*   LPE_VIRT_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_VIRT_IPG_CLK clock     */
/*   LPE_WKPU_IPG_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_WKPU_IPG_CLK clock     */
/*   LPE_WKPU_IPG_CLK_S clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPE_WKPU_IPG_CLK_S clock   */
/*   LPI2C0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPI2C0_CLK clock           */
/*   LPI2C1_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPI2C1_CLK clock           */
/*   LPI2C2_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPI2C2_CLK clock           */
/*   LPI2C3_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPI2C3_CLK clock           */
/*   LPSPI0_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI0_CLK clock           */
/*   LPSPI1_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI1_CLK clock           */
/*   LPSPI2_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI2_CLK clock           */
/*   LPSPI3_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI3_CLK clock           */
/*   LPSPI4_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI4_CLK clock           */
/*   LPSPI5_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI5_CLK clock           */
/*   LPSPI6_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI6_CLK clock           */
/*   LPSPI7_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPSPI7_CLK clock           */
/*   LPUART_MSC_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART_MSC_CLK clock       */
/*   LPUART_MSC_pCLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART_MSC_pCLK clock      */
/*   LPUART0_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART0_CLK clock          */
/*   LPUART0_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART0_pCLK clock         */
/*   LPUART1_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART1_CLK clock          */
/*   LPUART1_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART1_pCLK clock         */
/*   LPUART2_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART2_CLK clock          */
/*   LPUART2_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART2_pCLK clock         */
/*   LPUART3_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART3_CLK clock          */
/*   LPUART3_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART3_pCLK clock         */
/*   LPUART4_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART4_CLK clock          */
/*   LPUART4_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART4_pCLK clock         */
/*   LPUART5_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART5_CLK clock          */
/*   LPUART5_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART5_pCLK clock         */
/*   LPUART6_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART6_CLK clock          */
/*   LPUART6_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART6_pCLK clock         */
/*   LPUART7_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART7_CLK clock          */
/*   LPUART7_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART7_pCLK clock         */
/*   LPUART8_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART8_CLK clock          */
/*   LPUART8_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART8_pCLK clock         */
/*   LPUART9_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART9_CLK clock          */
/*   LPUART9_pCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART9_pCLK clock         */
/*   LPUART10_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART10_CLK clock         */
/*   LPUART10_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART10_pCLK clock        */
/*   LPUART11_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART11_CLK clock         */
/*   LPUART11_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART11_pCLK clock        */
/*   LPUART12_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART12_CLK clock         */
/*   LPUART12_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART12_pCLK clock        */
/*   LPUART13_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART13_CLK clock         */
/*   LPUART13_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART13_pCLK clock        */
/*   LPUART14_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART14_CLK clock         */
/*   LPUART14_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART14_pCLK clock        */
/*   LPUART15_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART15_CLK clock         */
/*   LPUART15_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART15_pCLK clock        */
/*   LPUART16_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART16_CLK clock         */
/*   LPUART16_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART16_pCLK clock        */
/*   LPUART17_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART17_CLK clock         */
/*   LPUART17_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART17_pCLK clock        */
/*   LPUART18_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART18_CLK clock         */
/*   LPUART18_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART18_pCLK clock        */
/*   LPUART19_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART19_CLK clock         */
/*   LPUART19_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART19_pCLK clock        */
/*   LPUART20_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART20_CLK clock         */
/*   LPUART20_pCLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LPUART20_pCLK clock        */
/*   LSTCU_ACCEL_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_ACCEL_IPG_CLK clock  */
/*   LSTCU_CORE0_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_CORE0_IPG_CLK clock  */
/*   LSTCU_CORE12_IPG_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_CORE12_IPG_CLK       */
/*   LSTCU_CORE3_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_CORE3_IPG_CLK clock  */
/*   LSTCU_HSPI_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_HSPI_IPG_CLK clock   */
/*   LSTCU_NETC_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_NETC_IPG_CLK clock   */
/*   LSTCU_PBRIDGE1_IPG_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_PBRIDGE1_IPG_CLK     */
/*   LSTCU_PBRIDGE3_IPG_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_PBRIDGE3_IPG_CLK     */
/*   LSTCU_PBRIDGE4_IPG_CLK     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_PBRIDGE4_IPG_CLK     */
/*   LSTCU_REST_IPG_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   LSTCU_REST_IPG_CLK clock   */
/*   MRAM_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MRAM_IPG_CLK clock         */
/*   MRAMC_IPG_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MRAMC_IPG_CLK clock        */
/*   MRAMC_IPG_CLK_S clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MRAMC_IPG_CLK_S clock      */
/*   MSCM_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSCM_IPG_CLK clock         */
/*   MSGINTR0_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR0_APB_CLK clock     */
/*   MSGINTR1_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR1_APB_CLK clock     */
/*   MSGINTR2_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR2_APB_CLK clock     */
/*   MSGINTR3_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR3_APB_CLK clock     */
/*   MSGINTR4_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR4_APB_CLK clock     */
/*   MSGINTR5_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR5_APB_CLK clock     */
/*   MSGINTR6_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR6_APB_CLK clock     */
/*   MSGINTR7_APB_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   MSGINTR7_APB_CLK clock     */
/*   PERI_HIGH_SPEED_REST_USDHC_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PERI_HIGH_SPEED_REST_USDHC_CLK */
/*   PERI_HIGH_SPEED_REST_XSPI_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PERI_HIGH_SPEED_REST_XSPI_CLK */
/*   PERI_HIGH_SPEED_TRACE_CLK  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PERI_HIGH_SPEED_TRACE_CLK  */
/*   PHY_ETH_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PHY_ETH_CLK clock          */
/*   PIT0_IPG_CLK_OSC clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT0_IPG_CLK_OSC clock     */
/*   PIT0_IPG_CLK_SYNC clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT0_IPG_CLK_SYNC clock    */
/*   PIT1_IPG_CLK_OSC clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT1_IPG_CLK_OSC clock     */
/*   PIT1_IPG_CLK_SYNC clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT1_IPG_CLK_SYNC clock    */
/*   PIT2_IPG_CLK_OSC clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT2_IPG_CLK_OSC clock     */
/*   PIT2_IPG_CLK_SYNC clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT2_IPG_CLK_SYNC clock    */
/*   PIT3_IPG_CLK_OSC clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT3_IPG_CLK_OSC clock     */
/*   PIT3_IPG_CLK_SYNC clock    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   PIT3_IPG_CLK_SYNC clock    */
/*   POST_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   POST_IPG_CLK clock         */
/*   RR_RTC_CLK clock           */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   RR_RTC_CLK clock           */
/*   RXLUT_ERM_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   RXLUT_ERM_CLK clock        */
/*   RXLUT_IPG_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   RXLUT_IPG_CLK clock        */
/*   SAI0_MCLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAI0_MCLK clock            */
/*   SAI0_IO_MCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAI0_IO_MCLK clock         */
/*   SAI0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAI0_IPG_CLK clock         */
/*   SAI1_IO_MCLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAI1_IO_MCLK clock         */
/*   SAI1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAI1_IPG_CLK clock         */
/*   SAI1_MCLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SAI1_MCLK clock            */
/*   SDHC_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SDHC_IPG_CLK clock         */
/*   SDHC_PER_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SDHC_PER_CLK clock         */
/*   SEMA42_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SEMA42_IPG_CLK clock       */
/*   SERDES_ALT_REF_CLK clock   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SERDES_ALT_REF_CLK clock   */
/*   SERDES_AUX_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SERDES_AUX_CLK clock       */
/*   SERDES_REF_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SERDES_REF_CLK clock       */
/*   SINC_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SINC_IPG_CLK clock         */
/*   SOG_REST_CMU_IPG_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SOG_REST_CMU_IPG_CLK       */
/*   SRC_FIRC_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_FIRC_CLK clock         */
/*   SRC_FIRCDIV2_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_FIRCDIV2_CLK clock     */
/*   SRC_FXOSC_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_FXOSC_CLK clock        */
/*   SRC_LPE_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_LPE_CLK clock          */
/*   SRC_LPE_DIV1_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_LPE_DIV1_CLK clock     */
/*   SRC_LPE_DIV2_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_LPE_DIV2_CLK clock     */
/*   SRC_LPE_DIV4_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_LPE_DIV4_CLK clock     */
/*   SRC_LPE_DIV8_CLK clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_LPE_DIV8_CLK clock     */
/*   SRC_PLT_CLK clock          */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_PLT_CLK clock          */
/*   SRC_PLTCORE_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_PLTCORE_CLK clock      */
/*   SRC_PLTDIV1_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_PLTDIV1_CLK clock      */
/*   SRC_PLTDIV2_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_PLTDIV2_CLK clock      */
/*   SRC_PLTDIV4_CLK clock      */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_PLTDIV4_CLK clock      */
/*   SRC_SIRC_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_SIRC_CLK clock         */
/*   SRC_SXOSC_CLK clock        */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRC_SXOSC_CLK clock        */
/*   SRAM0_CONTROLLER_IPS_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRAM0_CONTROLLER_IPS_CLK   */
/*   SRAM1_CONTROLLER_IPS_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRAM1_CONTROLLER_IPS_CLK   */
/*   SRAM2_CONTROLLER_IPS_CLK   */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SRAM2_CONTROLLER_IPS_CLK   */
/*   STAM_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STAM_CLK clock             */
/*   STM0_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM0_CLK clock             */
/*   STM0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM0_IPG_CLK clock         */
/*   STM1_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM1_CLK clock             */
/*   STM1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM1_IPG_CLK clock         */
/*   STM2_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM2_CLK clock             */
/*   STM2_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM2_IPG_CLK clock         */
/*   STM3_CLK clock             */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM3_CLK clock             */
/*   STM3_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   STM3_IPG_CLK clock         */
/*   SWT_STARTUP_IPG_CLK clock  */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT_STARTUP_IPG_CLK clock  */
/*   SWT_STARTUP_IPG_COUNTER_CLK */(CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT_STARTUP_IPG_COUNTER_CLK */
/*   SWT0_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT0_IPG_CLK clock         */
/*   SWT0_IPG_COUNTER_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT0_IPG_COUNTER_CLK       */
/*   SWT1_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT1_IPG_CLK clock         */
/*   SWT1_IPG_COUNTER_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT1_IPG_COUNTER_CLK       */
/*   SWT2_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT2_IPG_CLK clock         */
/*   SWT2_IPG_COUNTER_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT2_IPG_COUNTER_CLK       */
/*   SWT3_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT3_IPG_CLK clock         */
/*   SWT3_IPG_COUNTER_CLK       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   SWT3_IPG_COUNTER_CLK       */
/*   TRACE_CLK clock            */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   TRACE_CLK clock            */
/*   TRGMUX_IPG_CLK_S clock     */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   TRGMUX_IPG_CLK_S clock     */
/*   TRGMUX_MSC_IPG_CLK_S       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   TRGMUX_MSC_IPG_CLK_S       */
/*   VWRAP0_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   VWRAP0_IPG_CLK clock       */
/*   VWRAP1_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   VWRAP1_IPG_CLK clock       */
/*   VWRAP2_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   VWRAP2_IPG_CLK clock       */
/*   VWRAP3_IPG_CLK clock       */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   VWRAP3_IPG_CLK clock       */
/*   XSPI_IPG_CLK clock         */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   XSPI_IPG_CLK clock         */
/*   XSPI_UNGATED_2XSFIF_CLK    */ (CLOCK_IP_IRCOSC_OBJECT | CLOCK_IP_XOSC_OBJECT | CLOCK_IP_PLL_OBJECT | CLOCK_IP_SELECTOR_OBJECT | CLOCK_IP_DIVIDER_OBJECT | CLOCK_IP_DIVIDER_TRIGGER_OBJECT | CLOCK_IP_FRAC_DIV_OBJECT | CLOCK_IP_EXT_SIG_OBJECT | CLOCK_IP_GATE_OBJECT | CLOCK_IP_PCFS_OBJECT | CLOCK_IP_CMU_OBJECT) ,/*   XSPI_UNGATED_2XSFIF_CLK    */
};
    #endif /* CLOCK_IP_DEV_ERROR_DETECT == STD_ON */
#endif /* CLOCK_IP_DEV_ERROR_DETECT */


/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"




/* Clock start constant section data */
#define MCU_START_SEC_CONST_16
#include "Mcu_MemMap.h"



/*!
 * @brief Converts a clock name to a selector entry hardware value
 */
const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_PRODUCERS_NO] = {

   5U,                                         /*!< FIRC_CLK                                */
   1U,                                         /*!< FIRCDIV2_CLK                            */
   0U,                                         /*!< SAFE_CLK                                */
   2U,                                         /*!< SIRC_CLK                                */
   3U,                                         /*!< FXOSC_CLK                               */
   4U,                                         /*!< SXOSC_CLK                               */
   0U,                                         /*!< gated_clk                               */
   0U,                                         /*!< fast_crystal_oscillator                 */
   0U,                                         /*!< slow_crystal_oscillator                 */
   22U,                                        /*!< eth0_mii_rx_ext_clk                     */
   23U,                                        /*!< eth0_mii_tx_ext_clk                     */
   24U,                                        /*!< eth0_rgmii_rx_ext_clk                   */
   25U,                                        /*!< eth0_rgmii_tx_ext_clk                   */
   21U,                                        /*!< eth0_rmii_ref_ext_clk                   */
   27U,                                        /*!< eth1_mii_rx_ext_clk                     */
   28U,                                        /*!< eth1_mii_tx_ext_clk                     */
   29U,                                        /*!< eth1_rgmii_rx_ext_clk                   */
   30U,                                        /*!< eth1_rgmii_tx_ext_clk                   */
   26U,                                        /*!< eth1_rmii_ref_ext_clk                   */
   32U,                                        /*!< eth2_mii_rx_ext_clk                     */
   33U,                                        /*!< eth2_mii_tx_ext_clk                     */
   34U,                                        /*!< eth2_rgmii_rx_ext_clk                   */
   35U,                                        /*!< eth2_rgmii_tx_ext_clk                   */
   31U,                                        /*!< eth2_rmii_ref_ext_clk                   */
   20U,                                        /*!< ts_1588_clk                             */
   9U,                                         /*!< PLL0_CLK                                */
   0U,                                         /*!< PLL0_DIV_CLK                            */
   0U,                                         /*!< PLL0_DIV0_CLK                           */
   8U,                                         /*!< PLL0_DIV4_CLK                           */
   13U,                                        /*!< PLL0_DFS0_CLK                           */
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
   14U,                                        /*!< PLL0_DFS1_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
   15U,                                        /*!< PLL0_DFS2_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
   16U,                                        /*!< PLL0_DFS3_CLK                           */
#endif
   7U,                                         /*!< PLL1_CLK                                */
   0U,                                         /*!< PLL1_DIV_CLK                            */
   0U,                                         /*!< PLL1_DIV0_CLK                           */
   0U,                                         /*!< CPE_PLL_CLK                             */
   0U,                                         /*!< CPE_DIV_CLK                             */
   0U,                                         /*!< CPE_DIV0_CLK                            */
   0U,                                         /*!< LPE_CLK                                 */
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
   0U,                                         /*!< LPE_DIV1_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
   11U,                                        /*!< LPE_DIV2_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
   0U,                                         /*!< LPE_DIV4_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
   0U,                                         /*!< LPE_DIV8_CLK                            */
#endif
   0U,                                         /*!< PLT_CLK                                 */
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
   0U,                                         /*!< PLTCORE_CLK                             */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
   17U,                                        /*!< PLTDIV1_CLK                             */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
   18U,                                        /*!< PLTDIV2_CLK                             */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
   0U,                                         /*!< PLTDIV4_CLK                             */
#endif
};

const uint16 Clock_Ip_au16SelectorEntryRtcHardwareValue[7U] = {

   0U,                                         /*!< FIRC_CLK                                */
   0U,                                         /*!< FIRCDIV2_CLK                            */
   2U,                                         /*!< SAFE_CLK                                */
   1U,                                         /*!< SIRC_CLK                                */
   3U,                                         /*!< FXOSC_CLK                               */
   0U,                                         /*!< SXOSC_CLK                               */
   0U,                                         /*!< gated_clk                               */
};
/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16
#include "Mcu_MemMap.h"





/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

Clock_Ip_ExtOSCType* const Clock_Ip_apxXosc[CLOCK_IP_XOSC_INSTANCES_ARRAY_SIZE] =
{
    (Clock_Ip_ExtOSCType*)IP_LPE_FXOSC,
    (Clock_Ip_ExtOSCType*)IP_LPE_SXOSC,
};
Clock_Ip_PllType const Clock_Ip_apxPll[CLOCK_IP_PLL_INSTANCES_ARRAY_SIZE] = {
    {
        (PLL_Type *)IP_PLL_0,
        0U,
    },
    {
        (PLL_Type *)IP_PLL_1,
        0U,
    },
    {
        (PLL_Type *)IP_CPE_PLL,
        0U,
    },
};

volatile uint32* const Clock_Ip_SwitchDuration[8U] = {
    (volatile uint32* const)IP_MC_CGM_0_BASE,
    (volatile uint32* const)IP_MC_CGM_1_BASE,
    (volatile uint32* const)IP_MC_CGM_2_BASE,
    (volatile uint32* const)IP_MC_CGM_3_BASE,
    (volatile uint32* const)IP_MC_CGM_4_BASE,
    (volatile uint32* const)IP_MC_CGM_5_BASE,
    (volatile uint32* const)IP_LPE_MC_CGM_BASE,
    (volatile uint32* const)IP_CPE_MC_CGM_BASE,
};
Clock_Ip_CmuInfoType const Clock_Ip_axCmuInfo[CLOCK_IP_CMU_INFO_SIZE] =  {

    {
        RESERVED_CLK,       /* Name of the clock that can be monitored/supports cmu (clock monitor) */
        RESERVED_CLK,       /* Name of the reference clock */
        RESERVED_CLK,       /* Name of the bus clock */
        NULL_PTR
    },

};


const Clock_Ip_ClockNameSourceType Clock_Ip_aeSourceTypeClockName[CLOCK_IP_PRODUCERS_NO] = {
    IRCOSC_TYPE,                               /*!< FIRC_CLK                                */
    UKNOWN_TYPE,                               /*!< FIRCDIV2_CLK                            */
    UKNOWN_TYPE,                               /*!< SAFE_CLK                                */
    IRCOSC_TYPE,                               /*!< SIRC_CLK                                */
    XOSC_TYPE,                                 /*!< FXOSC_CLK                               */
    XOSC_TYPE,                                 /*!< SXOSC_CLK                               */
    EXT_CLK_TYPE,                              /*!< gated_clk                               */
    EXT_CLK_TYPE,                              /*!< fast_crystal_oscillator                 */
    EXT_CLK_TYPE,                              /*!< slow_crystal_oscillator                 */
    EXT_CLK_TYPE,                              /*!< eth0_mii_rx_ext_clk                     */
    EXT_CLK_TYPE,                              /*!< eth0_mii_tx_ext_clk                     */
    EXT_CLK_TYPE,                              /*!< eth0_rgmii_rx_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth0_rgmii_tx_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth0_rmii_ref_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth1_mii_rx_ext_clk                     */
    EXT_CLK_TYPE,                              /*!< eth1_mii_tx_ext_clk                     */
    EXT_CLK_TYPE,                              /*!< eth1_rgmii_rx_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth1_rgmii_tx_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth1_rmii_ref_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth2_mii_rx_ext_clk                     */
    EXT_CLK_TYPE,                              /*!< eth2_mii_tx_ext_clk                     */
    EXT_CLK_TYPE,                              /*!< eth2_rgmii_rx_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth2_rgmii_tx_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< eth2_rmii_ref_ext_clk                   */
    EXT_CLK_TYPE,                              /*!< ts_1588_clk                             */
    PLL_TYPE,                                  /*!< PLL0_CLK                                */
    UKNOWN_TYPE,                               /*!< PLL0_DIV_CLK                            */
    PLL_TYPE,                                  /*!< PLL0_DIV0_CLK                           */
    PLL_TYPE,                                  /*!< PLL0_DIV4_CLK                           */
    PLL_TYPE,                                  /*!< PLL0_DFS0_CLK                           */
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
    PLL_TYPE,                                  /*!< PLL0_DFS1_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
    PLL_TYPE,                                  /*!< PLL0_DFS2_CLK                           */
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
    PLL_TYPE,                                  /*!< PLL0_DFS3_CLK                           */
#endif
    PLL_TYPE,                                  /*!< PLL1_CLK                                */
    UKNOWN_TYPE,                               /*!< PLL1_DIV_CLK                            */
    PLL_TYPE,                                  /*!< PLL1_DIV0_CLK                           */
    PLL_TYPE,                                  /*!< CPE_PLL_CLK                             */
    UKNOWN_TYPE,                               /*!< CPE_DIV_CLK                             */
    PLL_TYPE,                                  /*!< CPE_DIV0_CLK                            */
    UKNOWN_TYPE,                               /*!< LPE_CLK                                 */
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
    UKNOWN_TYPE,                               /*!< LPE_DIV1_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
    UKNOWN_TYPE,                               /*!< LPE_DIV2_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
    UKNOWN_TYPE,                               /*!< LPE_DIV4_CLK                            */
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
    UKNOWN_TYPE,                               /*!< LPE_DIV8_CLK                            */
#endif
    UKNOWN_TYPE,                               /*!< PLT_CLK                                 */
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
    UKNOWN_TYPE,                               /*!< PLTCORE_CLK                             */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
    UKNOWN_TYPE,                               /*!< PLTDIV1_CLK                             */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
    UKNOWN_TYPE,                               /*!< PLTDIV2_CLK                             */
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
    UKNOWN_TYPE,                               /*!< PLTDIV4_CLK                             */
#endif
};

const Clock_Ip_NameType Clock_Ip_aeHwPllName[CLOCK_IP_NUMBER_OF_HARDWARE_PLL] =
{
    PLL0_CLK,                       /* PLL0_CLK Clock */
    PLL1_CLK,                       /* PLL1_CLK Clock */
    CPE_PLL_CLK,                    /* CPE_PLL_CLK Clock */
};

const Clock_Ip_NameType Clock_Ip_aeHwDfsName[CLOCK_IP_NUMBER_OF_HARDWARE_DFS] =
{
    PLL0_DFS0_CLK,                 /* PLL0_DFS0_CLK Clock */
    PLL0_DFS1_CLK,                 /* PLL0_DFS1_CLK Clock */
    PLL0_DFS2_CLK,                 /* PLL0_DFS2_CLK Clock */
    PLL0_DFS3_CLK,                 /* PLL0_DFS3_CLK Clock */
};

const Clock_Ip_SelectorDividerType Clock_Ip_axSelectorsDividersTable[CLOCK_IP_SELECTOR_DIVIDER_TABLE_SIZE] = {
/*   CLOCK_IP_SEL0_NODIV_LPE_CLK_INDEX                       */ {CLOCK_IP_SEL0_LPE_CLK_INDEX,                        CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL0_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_0_CSC_SELCTL_SHIFT,       MC_CGM_SLC_0_DC_0_DIV_SHIFT,         MC_CGM_SLC_0_CSC_SELCTL_MASK,        MC_CGM_SLC_0_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120300U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_CLK clock                   */
/*   CLOCK_IP_SEL0_NODIV_PLT_CLK_INDEX                       */ {CLOCK_IP_SEL0_PLT_CLK_INDEX,                        CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL0_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_0_CSC_SELCTL_SHIFT,       MC_CGM_SLC_0_DC_0_DIV_SHIFT,         MC_CGM_SLC_0_CSC_SELCTL_MASK,        MC_CGM_SLC_0_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8300U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   PLT_CLK clock                   */
/*   CLOCK_IP_SEL3_DIV0_CAN_PE_CLK_INDEX                     */ {CLOCK_IP_SEL3_CAN_PE_CLK_INDEX,                     CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_1_INSTANCE,  CLOCK_IP_SEL3_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_3_CSC_SELCTL_SHIFT,       MC_CGM_SLC_3_DC_0_DIV_SHIFT,         MC_CGM_SLC_3_CSC_SELCTL_MASK,        MC_CGM_SLC_3_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x400983c0U),  ((Clock_Ip_HwPcfsType (*)[])0x40098004U)}, /*   CAN_PE_CLK clock                */
/*   CLOCK_IP_SEL10_DIV0_DFT_CLK_INDEX                       */ {CLOCK_IP_SEL10_DFT_CLK_INDEX,                       CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL10_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_10_CSC_SELCTL_SHIFT,      MC_CGM_SLC_10_DC_0_DIV_SHIFT,        MC_CGM_SLC_10_CSC_SELCTL_MASK,       MC_CGM_SLC_10_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x404b8580U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   DFT_CLK clock                   */
/*   CLOCK_IP_SEL5_DIV0_DSPI_CLK_INDEX                       */ {CLOCK_IP_SEL5_DSPI_CLK_INDEX,                       CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL5_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_5_CSC_SELCTL_SHIFT,       MC_CGM_SLC_5_DC_0_DIV_SHIFT,         MC_CGM_SLC_5_CSC_SELCTL_MASK,        MC_CGM_SLC_5_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8440U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   DSPI_CLK clock                  */
/*   CLOCK_IP_SEL13_DIV0_ETH_TS_CLK_INDEX                    */ {CLOCK_IP_SEL13_ETH_TS_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL13_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_13_CSC_SELCTL_SHIFT,      MC_CGM_SLC_13_DC_0_DIV_SHIFT,        MC_CGM_SLC_13_CSC_SELCTL_MASK,       MC_CGM_SLC_13_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x404b8640U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   ETH_TS_CLK clock                */
/*   CLOCK_IP_SEL3_DIV0_ETH0_RX_CLK_INDEX                    */ {CLOCK_IP_SEL3_ETH0_RX_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL3_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_3_CSC_SELCTL_SHIFT,       MC_CGM_SLC_3_DC_0_DIV_SHIFT,         MC_CGM_SLC_3_CSC_SELCTL_MASK,        MC_CGM_SLC_3_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x400943c0U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH0_RX_CLK clock               */
/*   CLOCK_IP_SEL4_DIV0_ETH0_TX_CLK_INDEX                    */ {CLOCK_IP_SEL4_ETH0_TX_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL4_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_4_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_4_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40094400U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH0_TX_CLK clock               */
/*   CLOCK_IP_SEL5_DIV0_ETH1_RX_CLK_INDEX                    */ {CLOCK_IP_SEL5_ETH1_RX_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL5_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_5_CSC_SELCTL_SHIFT,       MC_CGM_SLC_5_DC_0_DIV_SHIFT,         MC_CGM_SLC_5_CSC_SELCTL_MASK,        MC_CGM_SLC_5_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40094440U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH1_RX_CLK clock               */
/*   CLOCK_IP_SEL6_DIV0_ETH1_TX_CLK_INDEX                    */ {CLOCK_IP_SEL6_ETH1_TX_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_6_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_6_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40094480U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH1_TX_CLK clock               */
/*   CLOCK_IP_SEL7_DIV0_ETH2_RX_CLK_INDEX                    */ {CLOCK_IP_SEL7_ETH2_RX_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL7_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_7_CSC_SELCTL_SHIFT,       MC_CGM_SLC_7_DC_0_DIV_SHIFT,         MC_CGM_SLC_7_CSC_SELCTL_MASK,        MC_CGM_SLC_7_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x400944c0U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH2_RX_CLK clock               */
/*   CLOCK_IP_SEL8_DIV0_ETH2_TX_CLK_INDEX                    */ {CLOCK_IP_SEL8_ETH2_TX_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL8_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_8_CSC_SELCTL_SHIFT,       MC_CGM_SLC_8_DC_0_DIV_SHIFT,         MC_CGM_SLC_8_CSC_SELCTL_MASK,        MC_CGM_SLC_8_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40094500U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH2_TX_CLK clock               */
/*   CLOCK_IP_SEL11_DIV0_ETH3_RX_CLK_INDEX                   */ {CLOCK_IP_SEL11_ETH3_RX_CLK_INDEX,                   CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL11_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_11_CSC_SELCTL_SHIFT,      MC_CGM_SLC_11_DC_0_DIV_SHIFT,        MC_CGM_SLC_11_CSC_SELCTL_MASK,       MC_CGM_SLC_11_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x400945c0U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH3_RX_CLK clock               */
/*   CLOCK_IP_SEL12_DIV0_ETH3_TX_CLK_INDEX                   */ {CLOCK_IP_SEL12_ETH3_TX_CLK_INDEX,                   CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL12_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_12_CSC_SELCTL_SHIFT,      MC_CGM_SLC_12_DC_0_DIV_SHIFT,        MC_CGM_SLC_12_CSC_SELCTL_MASK,       MC_CGM_SLC_12_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x40094600U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH3_TX_CLK clock               */
/*   CLOCK_IP_SEL13_DIV0_ETH4_RX_CLK_INDEX                   */ {CLOCK_IP_SEL13_ETH4_RX_CLK_INDEX,                   CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL13_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_13_CSC_SELCTL_SHIFT,      MC_CGM_SLC_13_DC_0_DIV_SHIFT,        MC_CGM_SLC_13_CSC_SELCTL_MASK,       MC_CGM_SLC_13_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x40094640U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH4_RX_CLK clock               */
/*   CLOCK_IP_SEL14_DIV0_ETH4_TX_CLK_INDEX                   */ {CLOCK_IP_SEL14_ETH4_TX_CLK_INDEX,                   CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL14_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_14_CSC_SELCTL_SHIFT,      MC_CGM_SLC_14_DC_0_DIV_SHIFT,        MC_CGM_SLC_14_CSC_SELCTL_MASK,       MC_CGM_SLC_14_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x40094680U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   ETH4_TX_CLK clock               */
/*   CLOCK_IP_SEL2_DIV0_FLEXCAN_0to7_PE_CLK_INDEX            */ {CLOCK_IP_SEL2_FLEXCAN_0to7_PE_CLK_INDEX,            CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL2_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_2_CSC_SELCTL_SHIFT,       MC_CGM_SLC_2_DC_0_DIV_SHIFT,         MC_CGM_SLC_2_CSC_SELCTL_MASK,        MC_CGM_SLC_2_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8380U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   FLEXCAN_0to7_PE_CLK clock       */
/*   CLOCK_IP_SEL3_DIV0_FLEXCAN_8to10_PE_CLK_INDEX           */ {CLOCK_IP_SEL3_FLEXCAN_8to10_PE_CLK_INDEX,           CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL3_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_3_CSC_SELCTL_SHIFT,       MC_CGM_SLC_3_DC_0_DIV_SHIFT,         MC_CGM_SLC_3_CSC_SELCTL_MASK,        MC_CGM_SLC_3_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b83c0U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   FLEXCAN_8to10_PE_CLK clock      */
/*   CLOCK_IP_SEL4_DIV0_FLEXCAN_11to16_PE_CLK_INDEX          */ {CLOCK_IP_SEL4_FLEXCAN_11to16_PE_CLK_INDEX,          CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL4_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_4_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_4_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8400U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   FLEXCAN_11to16_PE_CLK clock     */
/*   CLOCK_IP_SEL1_DIV0_FLEXIO_CLK_INDEX                     */ {CLOCK_IP_SEL1_FLEXIO_CLK_INDEX,                     CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL1_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_1_CSC_SELCTL_SHIFT,       MC_CGM_SLC_1_DC_0_DIV_SHIFT,         MC_CGM_SLC_1_CSC_SELCTL_MASK,        MC_CGM_SLC_1_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8340U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   FLEXIO_CLK clock                */
/*   CLOCK_IP_SEL6_DIV0_LPE_CXPI_PE_CLK_INDEX                */ {CLOCK_IP_SEL6_LPE_CXPI_PE_CLK_INDEX,                CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_6_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_6_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120480U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_CXPI_PE_CLK clock           */
/*   CLOCK_IP_SEL6_DIV0_LPE_DIV1_UNGATED_CLK_INDEX           */ {CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX,                0U,                             CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120480U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_DIV1_UNGATED_CLK clock      */
/*   CLOCK_IP_SEL6_DIV0_LPE_DIV2_UNGATED_CLK_INDEX           */ {CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX,                0U,                             CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120480U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_DIV2_UNGATED_CLK clock      */
/*   CLOCK_IP_SEL6_DIV0_LPE_DIV3_UNGATED_CLK_INDEX           */ {CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX,                0U,                             CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120480U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_DIV3_UNGATED_CLK clock      */
/*   CLOCK_IP_SEL6_DIV0_LPE_DIV4_UNGATED_CLK_INDEX           */ {CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX,                0U,                             CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120480U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_DIV4_UNGATED_CLK clock      */
/*   CLOCK_IP_SEL4_DIV0_LPE_FLEXCAN_PE_CLK_INDEX             */ {CLOCK_IP_SEL4_LPE_FLEXCAN_PE_CLK_INDEX,             CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL4_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_4_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_4_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120400U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_FLEXCAN_PE_CLK clock        */
/*   CLOCK_IP_SEL3_DIV0_LPE_LPI2C_MOD_CLK_INDEX              */ {CLOCK_IP_SEL3_LPE_LPI2C_MOD_CLK_INDEX,              CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL3_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_3_CSC_SELCTL_SHIFT,       MC_CGM_SLC_3_DC_0_DIV_SHIFT,         MC_CGM_SLC_3_CSC_SELCTL_MASK,        MC_CGM_SLC_3_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x421203c0U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_LPI2C_MOD_CLK clock         */
/*   CLOCK_IP_SEL1_DIV0_LPE_LPSPI_MOD_CLK_INDEX              */ {CLOCK_IP_SEL1_LPE_LPSPI_MOD_CLK_INDEX,              CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL1_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_1_CSC_SELCTL_SHIFT,       MC_CGM_SLC_1_DC_0_DIV_SHIFT,         MC_CGM_SLC_1_CSC_SELCTL_MASK,        MC_CGM_SLC_1_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120340U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_LPSPI_MOD_CLK clock         */
/*   CLOCK_IP_SEL2_DIV0_LPE_LPUART_MOD_CLK_INDEX             */ {CLOCK_IP_SEL2_LPE_LPUART_MOD_CLK_INDEX,             CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL2_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_2_CSC_SELCTL_SHIFT,       MC_CGM_SLC_2_DC_0_DIV_SHIFT,         MC_CGM_SLC_2_CSC_SELCTL_MASK,        MC_CGM_SLC_2_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120380U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_LPUART_MOD_CLK clock        */
/*   CLOCK_IP_SEL5_DIV0_LPE_STM_CLK_INDEX                    */ {CLOCK_IP_SEL5_LPE_STM_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL5_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_5_CSC_SELCTL_SHIFT,       MC_CGM_SLC_5_DC_0_DIV_SHIFT,         MC_CGM_SLC_5_CSC_SELCTL_MASK,        MC_CGM_SLC_5_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x42120440U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_STM_CLK clock               */
/*   CLOCK_IP_SEL6_NODIV_LPE_UNGATED_CLK_INDEX               */ {CLOCK_IP_SEL6_LPE_UNGATED_CLK_INDEX,                CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_6_INSTANCE,  CLOCK_IP_SEL6_INDEX,  0U,                   MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       0U,                                  MC_CGM_SLC_6_CSC_SELCTL_MASK,        0U,                                  ((Clock_Ip_HwSelectorType*)0x42120480U),  ((Clock_Ip_HwPcfsType (*)[])0x42120004U)}, /*   LPE_UNGATED_CLK clock           */
/*   CLOCK_IP_SEL1_DIV0_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX */ {CLOCK_IP_SEL1_PERI_HIGH_SPEED_REST_USDHC_CLK_INDEX, CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_1_INSTANCE,  CLOCK_IP_SEL1_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_1_CSC_SELCTL_SHIFT,       MC_CGM_SLC_1_DC_0_DIV_SHIFT,         MC_CGM_SLC_1_CSC_SELCTL_MASK,        MC_CGM_SLC_1_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40098340U),  ((Clock_Ip_HwPcfsType (*)[])0x40098004U)}, /*   PERI_HIGH_SPEED_REST_USDHC_CLK  */
/*   CLOCK_IP_SEL2_DIV0_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX  */ {CLOCK_IP_SEL2_PERI_HIGH_SPEED_REST_XSPI_CLK_INDEX,  CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_1_INSTANCE,  CLOCK_IP_SEL2_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_2_CSC_SELCTL_SHIFT,       MC_CGM_SLC_2_DC_0_DIV_SHIFT,         MC_CGM_SLC_2_CSC_SELCTL_MASK,        MC_CGM_SLC_2_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40098380U),  ((Clock_Ip_HwPcfsType (*)[])0x40098004U)}, /*   PERI_HIGH_SPEED_REST_XSPI_CLK   */
/*   CLOCK_IP_SEL4_DIV0_PERI_HIGH_SPEED_TRACE_CLK_INDEX      */ {CLOCK_IP_SEL4_PERI_HIGH_SPEED_TRACE_CLK_INDEX,      CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_1_INSTANCE,  CLOCK_IP_SEL4_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_4_CSC_SELCTL_SHIFT,       MC_CGM_SLC_4_DC_0_DIV_SHIFT,         MC_CGM_SLC_4_CSC_SELCTL_MASK,        MC_CGM_SLC_4_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40098400U),  ((Clock_Ip_HwPcfsType (*)[])0x40098004U)}, /*   PERI_HIGH_SPEED_TRACE_CLK       */
/*   CLOCK_IP_SEL1_DIV0_PHY_ETH_CLK_INDEX                    */ {CLOCK_IP_SEL1_PHY_ETH_CLK_INDEX,                    CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL1_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_1_CSC_SELCTL_SHIFT,       MC_CGM_SLC_1_DC_0_DIV_SHIFT,         MC_CGM_SLC_1_CSC_SELCTL_MASK,        MC_CGM_SLC_1_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40094340U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   PHY_ETH_CLK clock               */
/*   CLOCK_IP_SEL0_NODIV_RR_RTC_CLK_INDEX                    */ {CLOCK_IP_SEL0_RR_RTC_CLK_INDEX,               CLOCK_IP_000_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL0_INDEX,  0U,                   RTC_RTCC_CLKSEL_SHIFT,               0U,                                  RTC_RTCC_CLKSEL_MASK,                0U,                                  ((Clock_Ip_HwSelectorType*)0x42164004U),  ((Clock_Ip_HwPcfsType (*)[])0x42164004U)}, /*   RR_RTC_CLK clock                */
/*   CLOCK_IP_SEL0_DIV0_SAI0_MCLK_INDEX                      */ {CLOCK_IP_SEL0_SAI0_MCLK_INDEX,                      CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_2_INSTANCE,  CLOCK_IP_SEL0_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_0_CSC_SELCTL_SHIFT,       MC_CGM_SLC_0_DC_0_DIV_SHIFT,         MC_CGM_SLC_0_CSC_SELCTL_MASK,        MC_CGM_SLC_0_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x402fc300U),  ((Clock_Ip_HwPcfsType (*)[])0x402fc004U)}, /*   SAI0_MCLK clock                 */
/*   CLOCK_IP_SEL0_DIV0_SAI1_MCLK_INDEX                      */ {CLOCK_IP_SEL0_SAI1_MCLK_INDEX,                      CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_5_INSTANCE,  CLOCK_IP_SEL0_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_0_CSC_SELCTL_SHIFT,       MC_CGM_SLC_0_DC_0_DIV_SHIFT,         MC_CGM_SLC_0_CSC_SELCTL_MASK,        MC_CGM_SLC_0_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40b3c300U),  ((Clock_Ip_HwPcfsType (*)[])0x40b3c004U)}, /*   SAI1_MCLK clock                 */
/*   CLOCK_IP_SEL9_DIV0_SERDES_AUX_CLK_INDEX                 */ {CLOCK_IP_SEL9_SERDES_AUX_CLK_INDEX,                 CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL9_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_9_CSC_SELCTL_SHIFT,       MC_CGM_SLC_9_DC_0_DIV_SHIFT,         MC_CGM_SLC_9_CSC_SELCTL_MASK,        MC_CGM_SLC_9_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x40094540U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   SERDES_AUX_CLK clock            */
/*   CLOCK_IP_SEL10_DIV0_SERDES_REF_CLK_INDEX                */ {CLOCK_IP_SEL10_SERDES_REF_CLK_INDEX,                CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_0_INSTANCE,  CLOCK_IP_SEL10_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_10_CSC_SELCTL_SHIFT,      MC_CGM_SLC_10_DC_0_DIV_SHIFT,        MC_CGM_SLC_10_CSC_SELCTL_MASK,       MC_CGM_SLC_10_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x40094580U),  ((Clock_Ip_HwPcfsType (*)[])0x40094004U)}, /*   SERDES_REF_CLK clock            */
/*   CLOCK_IP_SEL6_DIV0_STM0_CLK_INDEX                       */ {CLOCK_IP_SEL6_STM0_CLK_INDEX,                       CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL6_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_6_CSC_SELCTL_SHIFT,       MC_CGM_SLC_6_DC_0_DIV_SHIFT,         MC_CGM_SLC_6_CSC_SELCTL_MASK,        MC_CGM_SLC_6_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8480U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   STM0_CLK clock                  */
/*   CLOCK_IP_SEL7_DIV0_STM1_CLK_INDEX                       */ {CLOCK_IP_SEL7_STM1_CLK_INDEX,                       CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL7_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_7_CSC_SELCTL_SHIFT,       MC_CGM_SLC_7_DC_0_DIV_SHIFT,         MC_CGM_SLC_7_CSC_SELCTL_MASK,        MC_CGM_SLC_7_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b84c0U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   STM1_CLK clock                  */
/*   CLOCK_IP_SEL8_DIV0_STM2_CLK_INDEX                       */ {CLOCK_IP_SEL8_STM2_CLK_INDEX,                       CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL8_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_8_CSC_SELCTL_SHIFT,       MC_CGM_SLC_8_DC_0_DIV_SHIFT,         MC_CGM_SLC_8_CSC_SELCTL_MASK,        MC_CGM_SLC_8_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8500U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   STM2_CLK clock                  */
/*   CLOCK_IP_SEL9_DIV0_STM3_CLK_INDEX                       */ {CLOCK_IP_SEL9_STM3_CLK_INDEX,                       CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL9_INDEX,  CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_9_CSC_SELCTL_SHIFT,       MC_CGM_SLC_9_DC_0_DIV_SHIFT,         MC_CGM_SLC_9_CSC_SELCTL_MASK,        MC_CGM_SLC_9_DC_0_DIV_MASK,          ((Clock_Ip_HwSelectorType*)0x404b8540U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   STM3_CLK clock                  */
/*   CLOCK_IP_SEL11_DIV0_TRACE_CLK_INDEX                     */ {CLOCK_IP_SEL11_TRACE_CLK_INDEX,                     CLOCK_IP_001_DIV_IDS_BITS,      CLOCK_IP_3_INSTANCE,  CLOCK_IP_SEL11_INDEX, CLOCK_IP_DIV0_INDEX,  MC_CGM_SLC_11_CSC_SELCTL_SHIFT,      MC_CGM_SLC_11_DC_0_DIV_SHIFT,        MC_CGM_SLC_11_CSC_SELCTL_MASK,       MC_CGM_SLC_11_DC_0_DIV_MASK,         ((Clock_Ip_HwSelectorType*)0x404b85c0U),  ((Clock_Ip_HwPcfsType (*)[])0x404b8004U)}, /*   TRACE_CLK clock                 */
};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/




#ifdef __cplusplus
}
#endif

/** @} */
