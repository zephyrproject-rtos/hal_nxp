/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Clock_Ip_Frequency.c
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



#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))


/*==================================================================================================
                                     SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_FREQUENCY_VENDOR_ID_C                      43
#define CLOCK_IP_FREQUENCY_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_FREQUENCY_AR_RELEASE_MINOR_VERSION_C       9
#define CLOCK_IP_FREQUENCY_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_FREQUENCY_SW_MAJOR_VERSION_C               0
#define CLOCK_IP_FREQUENCY_SW_MINOR_VERSION_C               8
#define CLOCK_IP_FREQUENCY_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_FREQUENCY_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Frequency.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_FREQUENCY_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Frequency.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Frequency.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_FREQUENCY_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_FREQUENCY_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Frequency.c and Clock_Ip_Private.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef struct{

    Clock_Ip_NameType Name;
    uint64 Frequency;

}extSignalFreq;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


#define CLOCK_IP_SELECTOR_SOURCE_NO                        64U
#define CLOCK_IP_DFS_MASK_0_CHANNEL                        1U
#define CLOCK_IP_DFS_MASK_1_CHANNEL                        2U
#define CLOCK_IP_DFS_MASK_2_CHANNEL                        4U
#define CLOCK_IP_DFS_MASK_3_CHANNEL                        8U
#define CLOCK_IP_DFS_MASK_4_CHANNEL                        16U
#define CLOCK_IP_DFS_MASK_5_CHANNEL                        32U
#define CLOCK_IP_MUL_BY_16384                              14U
#define CLOCK_IP_MUL_BY_2048                               11U
#define CLOCK_IP_MUL_BY_32                                 5U
#define CLOCK_IP_MUL_BY_16                                 4U
#define CLOCK_IP_MUL_BY_4                                  2U
#define CLOCK_IP_MUL_BY_2                                  1U
#define CLOCK_IP_DISABLED                                  0U
#define CLOCK_IP_ENABLED                                   0xFFFFFFFFFFFFFFFFU
#define CLOCK_IP_gated_clk_INDEX_ENTRY                     0U
#define CLOCK_IP_fast_crystal_oscillator_INDEX_ENTRY       1U
#define CLOCK_IP_slow_crystal_oscillator_INDEX_ENTRY       2U
#define CLOCK_IP_eth0_mii_rx_ext_clk_INDEX_ENTRY           3U
#define CLOCK_IP_eth0_mii_tx_ext_clk_INDEX_ENTRY           4U
#define CLOCK_IP_eth0_rgmii_rx_ext_clk_INDEX_ENTRY         5U
#define CLOCK_IP_eth0_rgmii_tx_ext_clk_INDEX_ENTRY         6U
#define CLOCK_IP_eth0_rmii_ref_ext_clk_INDEX_ENTRY         7U
#define CLOCK_IP_eth1_mii_rx_ext_clk_INDEX_ENTRY           8U
#define CLOCK_IP_eth1_mii_tx_ext_clk_INDEX_ENTRY           9U
#define CLOCK_IP_eth1_rgmii_rx_ext_clk_INDEX_ENTRY         10U
#define CLOCK_IP_eth1_rgmii_tx_ext_clk_INDEX_ENTRY         11U
#define CLOCK_IP_eth1_rmii_ref_ext_clk_INDEX_ENTRY         12U
#define CLOCK_IP_eth2_mii_rx_ext_clk_INDEX_ENTRY           13U
#define CLOCK_IP_eth2_mii_tx_ext_clk_INDEX_ENTRY           14U
#define CLOCK_IP_eth2_rgmii_rx_ext_clk_INDEX_ENTRY         15U
#define CLOCK_IP_eth2_rgmii_tx_ext_clk_INDEX_ENTRY         16U
#define CLOCK_IP_eth2_rmii_ref_ext_clk_INDEX_ENTRY         17U
#define CLOCK_IP_ts_1588_clk_INDEX_ENTRY                   18U
#define CLOCK_IP_EXT_SIGNALS_NO                            19U

/*==================================================================================================
                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static uint64 Clock_Ip_PLL_VCO(const PLL_Type *Base);
static uint64 DFS_OUTPUT(const PLL_Type *Base, uint32 Channel, uint64 Fin);
static uint64 Clock_Ip_Get_Zero_Frequency(void);
static uint64 Clock_Ip_Get_FIRC_CLK_Frequency(void);
static uint64 Clock_Ip_Get_FIRCDIV2_CLK_Frequency(void);
static uint64 Clock_Ip_Get_SAFE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_SIRC_CLK_Frequency(void);
static uint64 Clock_Ip_Get_FXOSC_CLK_Frequency(void);
static uint64 Clock_Ip_Get_SXOSC_CLK_Frequency(void);
static uint64 Clock_Ip_Get_gated_clk_Frequency(void);
static uint64 Clock_Ip_Get_fast_crystal_oscillator_Frequency(void);
static uint64 Clock_Ip_Get_slow_crystal_oscillator_Frequency(void);
static uint64 Clock_Ip_Get_eth0_mii_rx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth0_mii_tx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth0_rgmii_rx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth0_rgmii_tx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth0_rmii_ref_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth1_mii_rx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth1_mii_tx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth1_rgmii_tx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth1_rmii_ref_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth2_mii_rx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth2_mii_tx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth2_rgmii_rx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth2_rgmii_tx_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_eth2_rmii_ref_ext_clk_Frequency(void);
static uint64 Clock_Ip_Get_ts_1588_clk_Frequency(void);
static uint64 Clock_Ip_Get_PLL0_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PLL0_DIV_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PLL0_DIV0_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PLL0_DIV4_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PLL0_DFS0_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
static uint64 Clock_Ip_Get_PLL0_DFS1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
static uint64 Clock_Ip_Get_PLL0_DFS2_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
static uint64 Clock_Ip_Get_PLL0_DFS3_CLK_Frequency(void);
#endif
static uint64 Clock_Ip_Get_PLL1_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PLL1_DIV_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PLL1_DIV0_CLK_Frequency(void);
static uint64 Clock_Ip_Get_CPE_PLL_CLK_Frequency(void);
static uint64 Clock_Ip_Get_CPE_DIV_CLK_Frequency(void);
static uint64 Clock_Ip_Get_CPE_DIV0_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
static uint64 Clock_Ip_Get_LPE_DIV1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
static uint64 Clock_Ip_Get_LPE_DIV2_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
static uint64 Clock_Ip_Get_LPE_DIV4_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
static uint64 Clock_Ip_Get_LPE_DIV8_CLK_Frequency(void);
#endif
static uint64 Clock_Ip_Get_PLT_CLK_Frequency(void);
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
static uint64 Clock_Ip_Get_PLTCORE_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
static uint64 Clock_Ip_Get_PLTDIV1_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
static uint64 Clock_Ip_Get_PLTDIV2_CLK_Frequency(void);
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
static uint64 Clock_Ip_Get_PLTDIV4_CLK_Frequency(void);
#endif
static uint64 Clock_Ip_Get_CAN_PE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_DFT_CLK_Frequency(void);
static uint64 Clock_Ip_Get_DSPI_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH_TS_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH0_RX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH0_TX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH1_RX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH1_TX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH2_RX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH2_TX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH3_RX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH3_TX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH4_RX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_ETH4_TX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_FLEXCAN_8to10_PE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_FLEXIO_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_CXPI_PE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_DIV1_UNGATED_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_DIV2_UNGATED_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_DIV3_UNGATED_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_DIV4_UNGATED_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_FLEXCAN_PE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_LPI2C_MOD_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_LPSPI_MOD_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_LPUART_MOD_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_STM_CLK_Frequency(void);
static uint64 Clock_Ip_Get_LPE_UNGATED_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PERI_HIGH_SPEED_REST_USDHC_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PERI_HIGH_SPEED_REST_XSPI_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PERI_HIGH_SPEED_TRACE_CLK_Frequency(void);
static uint64 Clock_Ip_Get_PHY_ETH_CLK_Frequency(void);
static uint64 Clock_Ip_Get_RR_RTC_CLK_Frequency(void);
uint64 Clock_Ip_Get_RR_RTC_CLK_Frequency_TrustedCall(void);
static uint64 Clock_Ip_Get_SAI0_MCLK_Frequency(void);
static uint64 Clock_Ip_Get_SAI1_MCLK_Frequency(void);
static uint64 Clock_Ip_Get_SERDES_AUX_CLK_Frequency(void);
static uint64 Clock_Ip_Get_SERDES_REF_CLK_Frequency(void);
static uint64 Clock_Ip_Get_STM0_CLK_Frequency(void);
static uint64 Clock_Ip_Get_STM1_CLK_Frequency(void);
static uint64 Clock_Ip_Get_STM2_CLK_Frequency(void);
static uint64 Clock_Ip_Get_STM3_CLK_Frequency(void);
static uint64 Clock_Ip_Get_TRACE_CLK_Frequency(void);

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"



/* static const uint64 Clock_Ip_au32EnableClock[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED}; */
static const uint64 Clock_Ip_au32EnableDivider[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED};
/* static const uint64 Clock_Ip_u32EnableGate[2U] = {CLOCK_IP_DISABLED,CLOCK_IP_ENABLED}; */

typedef uint64 (*getFreqType)(void);




static const getFreqType Clock_Ip_apfFreqSrcTable[3U][64U] =
{
   /* ALL    */
   {
    Clock_Ip_Get_SAFE_CLK_Frequency,                      /* clock name for 0  hardware value */
    Clock_Ip_Get_FIRCDIV2_CLK_Frequency,                  /* clock name for 1  hardware value */
    Clock_Ip_Get_SIRC_CLK_Frequency,                      /* clock name for 2  hardware value */
    Clock_Ip_Get_FXOSC_CLK_Frequency,                     /* clock name for 3  hardware value */
    Clock_Ip_Get_SXOSC_CLK_Frequency,                     /* clock name for 4  hardware value */
    Clock_Ip_Get_FIRC_CLK_Frequency,                      /* clock name for 5  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 6  hardware value */
    Clock_Ip_Get_PLL1_CLK_Frequency,                      /* clock name for 7  hardware value */
    Clock_Ip_Get_PLL0_DIV4_CLK_Frequency,                 /* clock name for 8  hardware value */
    Clock_Ip_Get_PLL0_CLK_Frequency,                      /* clock name for 9  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 10 hardware value */
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
    Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                  /* clock name for 11 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 12 hardware value */
    Clock_Ip_Get_PLL0_DFS0_CLK_Frequency,                 /* clock name for 13 hardware value */
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
    Clock_Ip_Get_PLL0_DFS1_CLK_Frequency,                 /* clock name for 14 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
    Clock_Ip_Get_PLL0_DFS2_CLK_Frequency,                 /* clock name for 15 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
    Clock_Ip_Get_PLL0_DFS3_CLK_Frequency,                 /* clock name for 16 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
    Clock_Ip_Get_PLTDIV1_CLK_Frequency,                   /* clock name for 17 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
    Clock_Ip_Get_PLTDIV2_CLK_Frequency,                   /* clock name for 18 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 19 hardware value */
    Clock_Ip_Get_ts_1588_clk_Frequency,                   /* clock name for 20 hardware value */
    Clock_Ip_Get_eth0_rmii_ref_ext_clk_Frequency,         /* clock name for 21 hardware value */
    Clock_Ip_Get_eth0_mii_rx_ext_clk_Frequency,           /* clock name for 22 hardware value */
    Clock_Ip_Get_eth0_mii_tx_ext_clk_Frequency,           /* clock name for 23 hardware value */
    Clock_Ip_Get_eth0_rgmii_rx_ext_clk_Frequency,         /* clock name for 24 hardware value */
    Clock_Ip_Get_eth0_rgmii_tx_ext_clk_Frequency,         /* clock name for 25 hardware value */
    Clock_Ip_Get_eth1_rmii_ref_ext_clk_Frequency,         /* clock name for 26 hardware value */
    Clock_Ip_Get_eth1_mii_rx_ext_clk_Frequency,           /* clock name for 27 hardware value */
    Clock_Ip_Get_eth1_mii_tx_ext_clk_Frequency,           /* clock name for 28 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 29 hardware value */
    Clock_Ip_Get_eth1_rgmii_tx_ext_clk_Frequency,         /* clock name for 30 hardware value */
    Clock_Ip_Get_eth2_rmii_ref_ext_clk_Frequency,         /* clock name for 31 hardware value */
    Clock_Ip_Get_eth2_mii_rx_ext_clk_Frequency,           /* clock name for 32 hardware value */
    Clock_Ip_Get_eth2_mii_tx_ext_clk_Frequency,           /* clock name for 33 hardware value */
    Clock_Ip_Get_eth2_rgmii_rx_ext_clk_Frequency,         /* clock name for 34 hardware value */
    Clock_Ip_Get_eth2_rgmii_tx_ext_clk_Frequency,         /* clock name for 35 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 36 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 37 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 38 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 39 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 40 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 41 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 42 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 43 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 44 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 45 hardware value */
    Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,         /* clock name for 46 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 47 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 48 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 49 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 50 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 51 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 52 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 53 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 54 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 55 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 56 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 57 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 58 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 59 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 60 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 61 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 62 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 63 hardware value */
    },
   /* LPE    */
   {
    Clock_Ip_Get_SAFE_CLK_Frequency,                      /* clock name for 0  hardware value */
    Clock_Ip_Get_FIRCDIV2_CLK_Frequency,                  /* clock name for 1  hardware value */
    Clock_Ip_Get_SIRC_CLK_Frequency,                      /* clock name for 2  hardware value */
    Clock_Ip_Get_FXOSC_CLK_Frequency,                     /* clock name for 3  hardware value */
    Clock_Ip_Get_SXOSC_CLK_Frequency,                     /* clock name for 4  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 5  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 6  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 7  hardware value */
    Clock_Ip_Get_PLL0_DIV4_CLK_Frequency,                 /* clock name for 8  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 9  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 10 hardware value */
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
    Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                  /* clock name for 11 hardware value */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 12 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 13 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 14 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 15 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 16 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 17 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 18 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 19 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 20 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 21 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 22 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 23 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 24 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 25 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 26 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 27 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 28 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 29 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 30 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 31 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 32 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 33 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 34 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 35 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 36 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 37 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 38 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 39 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 40 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 41 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 42 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 43 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 44 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 45 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 46 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 47 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 48 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 49 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 50 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 51 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 52 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 53 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 54 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 55 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 56 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 57 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 58 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 59 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 60 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 61 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 62 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 63 hardware value */
    },
   /* CPE    */
   {
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 0  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 1  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 2  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 3  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 4  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 5  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 6  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 7  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 8  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 9  hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 10 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 11 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 12 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 13 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 14 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 15 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 16 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 17 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 18 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 19 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 20 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 21 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 22 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 23 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 24 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 25 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 26 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 27 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 28 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 29 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 30 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 31 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 32 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 33 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 34 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 35 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 36 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 37 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 38 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 39 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 40 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 41 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 42 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 43 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 44 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 45 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 46 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 47 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 48 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 49 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 50 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 51 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 52 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 53 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 54 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 55 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 56 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 57 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 58 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 59 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 60 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 61 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 62 hardware value */
    Clock_Ip_Get_Zero_Frequency,                          /* clock name for 63 hardware value */
    },
};

static const getFreqType Clock_Ip_apfFreqSrcRtcTable[4U] =
{
    Clock_Ip_Get_SXOSC_CLK_Frequency,                     /* clock name for 0  hardware value */
    Clock_Ip_Get_SIRC_CLK_Frequency,                      /* clock name for 1  hardware value */
    Clock_Ip_Get_SAFE_CLK_Frequency,                      /* clock name for 2  hardware value */
    Clock_Ip_Get_FXOSC_CLK_Frequency,                     /* clock name for 3  hardware value */
};

static const getFreqType Clock_Ip_apfFreqTable[CLOCK_IP_NAMES_NO] =
{
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* FIRC_CLK                                         */
    &Clock_Ip_Get_FIRCDIV2_CLK_Frequency,                                                /* FIRCDIV2_CLK                                     */
    &Clock_Ip_Get_SAFE_CLK_Frequency,                                                    /* SAFE_CLK                                         */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* SIRC_CLK                                         */
    &Clock_Ip_Get_FXOSC_CLK_Frequency,                                                   /* FXOSC_CLK                                        */
    &Clock_Ip_Get_SXOSC_CLK_Frequency,                                                   /* SXOSC_CLK                                        */
    &Clock_Ip_Get_gated_clk_Frequency,                                                   /* gated_clk                                        */
    &Clock_Ip_Get_fast_crystal_oscillator_Frequency,                                     /* fast_crystal_oscillator                          */
    &Clock_Ip_Get_slow_crystal_oscillator_Frequency,                                     /* slow_crystal_oscillator                          */
    &Clock_Ip_Get_eth0_mii_rx_ext_clk_Frequency,                                         /* eth0_mii_rx_ext_clk                              */
    &Clock_Ip_Get_eth0_mii_tx_ext_clk_Frequency,                                         /* eth0_mii_tx_ext_clk                              */
    &Clock_Ip_Get_eth0_rgmii_rx_ext_clk_Frequency,                                       /* eth0_rgmii_rx_ext_clk                            */
    &Clock_Ip_Get_eth0_rgmii_tx_ext_clk_Frequency,                                       /* eth0_rgmii_tx_ext_clk                            */
    &Clock_Ip_Get_eth0_rmii_ref_ext_clk_Frequency,                                       /* eth0_rmii_ref_ext_clk                            */
    &Clock_Ip_Get_eth1_mii_rx_ext_clk_Frequency,                                         /* eth1_mii_rx_ext_clk                              */
    &Clock_Ip_Get_eth1_mii_tx_ext_clk_Frequency,                                         /* eth1_mii_tx_ext_clk                              */
    &Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency,                                       /* eth1_rgmii_rx_ext_clk                            */
    &Clock_Ip_Get_eth1_rgmii_tx_ext_clk_Frequency,                                       /* eth1_rgmii_tx_ext_clk                            */
    &Clock_Ip_Get_eth1_rmii_ref_ext_clk_Frequency,                                       /* eth1_rmii_ref_ext_clk                            */
    &Clock_Ip_Get_eth2_mii_rx_ext_clk_Frequency,                                         /* eth2_mii_rx_ext_clk                              */
    &Clock_Ip_Get_eth2_mii_tx_ext_clk_Frequency,                                         /* eth2_mii_tx_ext_clk                              */
    &Clock_Ip_Get_eth2_rgmii_rx_ext_clk_Frequency,                                       /* eth2_rgmii_rx_ext_clk                            */
    &Clock_Ip_Get_eth2_rgmii_tx_ext_clk_Frequency,                                       /* eth2_rgmii_tx_ext_clk                            */
    &Clock_Ip_Get_eth2_rmii_ref_ext_clk_Frequency,                                       /* eth2_rmii_ref_ext_clk                            */
    &Clock_Ip_Get_ts_1588_clk_Frequency,                                                 /* ts_1588_clk                                      */
    &Clock_Ip_Get_PLL0_CLK_Frequency,                                                    /* PLL0_CLK                                         */
    &Clock_Ip_Get_PLL0_DIV_CLK_Frequency,                                                /* PLL0_DIV_CLK                                     */
    &Clock_Ip_Get_PLL0_DIV0_CLK_Frequency,                                               /* PLL0_DIV0_CLK                                    */
    &Clock_Ip_Get_PLL0_DIV4_CLK_Frequency,                                               /* PLL0_DIV4_CLK                                    */
    &Clock_Ip_Get_PLL0_DFS0_CLK_Frequency,                                               /* PLL0_DFS0_CLK                                    */
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
    &Clock_Ip_Get_PLL0_DFS1_CLK_Frequency,                                               /* PLL0_DFS1_CLK                                    */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
    &Clock_Ip_Get_PLL0_DFS2_CLK_Frequency,                                               /* PLL0_DFS2_CLK                                    */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
    &Clock_Ip_Get_PLL0_DFS3_CLK_Frequency,                                               /* PLL0_DFS3_CLK                                    */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
    &Clock_Ip_Get_PLL1_CLK_Frequency,                                                    /* PLL1_CLK                                         */
    &Clock_Ip_Get_PLL1_DIV_CLK_Frequency,                                                /* PLL1_DIV_CLK                                     */
    &Clock_Ip_Get_PLL1_DIV0_CLK_Frequency,                                               /* PLL1_DIV0_CLK                                    */
    &Clock_Ip_Get_CPE_PLL_CLK_Frequency,                                                 /* CPE_PLL_CLK                                      */
    &Clock_Ip_Get_CPE_DIV_CLK_Frequency,                                                 /* CPE_DIV_CLK                                      */
    &Clock_Ip_Get_CPE_DIV0_CLK_Frequency,                                                /* CPE_DIV0_CLK                                     */
    &Clock_Ip_Get_LPE_CLK_Frequency,                                                     /* LPE_CLK                                          */
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* LPE_DIV1_CLK                                     */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_DIV2_CLK                                     */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_DIV4_CLK                                     */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
    &Clock_Ip_Get_LPE_DIV8_CLK_Frequency,                                                /* LPE_DIV8_CLK                                     */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
    &Clock_Ip_Get_PLT_CLK_Frequency,                                                     /* PLT_CLK                                          */
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
    &Clock_Ip_Get_PLTCORE_CLK_Frequency,                                                 /* PLTCORE_CLK                                      */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* PLTDIV1_CLK                                      */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* PLTDIV2_CLK                                      */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* PLTDIV4_CLK                                      */
#else
    Clock_Ip_Get_Zero_Frequency,
#endif
                       &Clock_Ip_Get_Zero_Frequency,                                     /* THE_LAST_PRODUCER_CLK                            */
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* ACP_DMA3_H_CLK                                   */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* ACP_DMA3_IPG_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* ADC0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* ADC1_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* BCTU_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* BCTU_IPS_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* CAN_HUB_IPG_CLK                                  */
    &Clock_Ip_Get_CAN_PE_CLK_Frequency,                                                  /* CAN_PE_CLK                                       */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* CLKBIST_IPG_CLK                                  */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* CRC0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* CRC1_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* CSTCU_IPG_CLK                                    */
    &Clock_Ip_Get_PHY_ETH_CLK_Frequency,                                                 /* DIG_PHY0_CLK                                     */
    &Clock_Ip_Get_PHY_ETH_CLK_Frequency,                                                 /* DIG_PHY1_CLK                                     */
    &Clock_Ip_Get_PHY_ETH_CLK_Frequency,                                                 /* DIG_PHY2_CLK                                     */
    &Clock_Ip_Get_PHY_ETH_CLK_Frequency,                                                 /* DIG_PHY3_CLK                                     */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* DMA_CH_MUX0_IPG_CLK                              */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* DMA_CH_MUX1_IPG_CLK                              */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* DMA4_AXI_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* DMA4_IPG_S_CLK                                   */
    &Clock_Ip_Get_DFT_CLK_Frequency,                                                     /* DFT_CLK                                          */
    &Clock_Ip_Get_DSPI_CLK_Frequency,                                                    /* DSPI_CLK                                         */
    &Clock_Ip_Get_DSPI_CLK_Frequency,                                                    /* DSPI0_IPG_CLK                                    */
    &Clock_Ip_Get_DSPI_CLK_Frequency,                                                    /* DSPI1_IPG_CLK                                    */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* EDMA_TCD_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* EIM0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* EIM1_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* EIM2_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* EIM3_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* EMIOS0_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* EMIOS1_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* EMIOS2_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* ERM0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* ERM1_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* ERM2_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* ERM3_IPG_CLK                                     */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* ETH_TS_CLK                                       */
    &Clock_Ip_Get_ETH0_RX_CLK_Frequency,                                                 /* ETH0_RX_CLK                                      */
    &Clock_Ip_Get_ETH0_TX_CLK_Frequency,                                                 /* ETH0_TX_CLK                                      */
    &Clock_Ip_Get_ETH1_RX_CLK_Frequency,                                                 /* ETH1_RX_CLK                                      */
    &Clock_Ip_Get_ETH1_TX_CLK_Frequency,                                                 /* ETH1_TX_CLK                                      */
    &Clock_Ip_Get_ETH2_RX_CLK_Frequency,                                                 /* ETH2_RX_CLK                                      */
    &Clock_Ip_Get_ETH2_TX_CLK_Frequency,                                                 /* ETH2_TX_CLK                                      */
    &Clock_Ip_Get_ETH3_RX_CLK_Frequency,                                                 /* ETH3_RX_CLK                                      */
    &Clock_Ip_Get_ETH3_TX_CLK_Frequency,                                                 /* ETH3_TX_CLK                                      */
    &Clock_Ip_Get_ETH4_RX_CLK_Frequency,                                                 /* ETH4_RX_CLK                                      */
    &Clock_Ip_Get_ETH4_TX_CLK_Frequency,                                                 /* ETH4_TX_CLK                                      */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN_0to7_PE_CLK                              */
    &Clock_Ip_Get_FLEXCAN_8to10_PE_CLK_Frequency,                                        /* FLEXCAN_8to10_PE_CLK                             */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN_11to16_PE_CLK                            */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN0_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN0_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN0_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN1_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN1_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN1_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN2_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN2_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN2_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN3_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN3_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN3_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN4_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN4_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN4_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN5_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN5_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN5_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN6_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN6_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN6_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN7_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency,                                         /* FLEXCAN7_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN7_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN8_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_8to10_PE_CLK_Frequency,                                        /* FLEXCAN8_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN8_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN9_IPG_CLK                                 */
    &Clock_Ip_Get_FLEXCAN_8to10_PE_CLK_Frequency,                                        /* FLEXCAN9_PE_NOGATE_CLK                           */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN9_TS_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN10_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_8to10_PE_CLK_Frequency,                                        /* FLEXCAN10_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN10_TS_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN11_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN11_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN11_TS_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN12_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN12_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN12_TS_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN13_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN13_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN13_TS_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN14_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN14_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN14_TS_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN15_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN15_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN15_TS_CLK                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXCAN16_IPG_CLK                                */
    &Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency,                                       /* FLEXCAN16_PE_NOGATE_CLK                          */
    &Clock_Ip_Get_ETH_TS_CLK_Frequency,                                                  /* FLEXCAN16_TS_CLK                                 */
    &Clock_Ip_Get_FLEXIO_CLK_Frequency,                                                  /* FLEXIO_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXIO0_IPG_CLK                                  */
    &Clock_Ip_Get_FLEXIO_CLK_Frequency,                                                  /* FLEXIO0_PE_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* FLEXIO1_IPG_CLK                                  */
    &Clock_Ip_Get_FLEXIO_CLK_Frequency,                                                  /* FLEXIO1_PE_CLK                                   */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* GPR0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* GPR1_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* INTM_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_CSSI_MC_CGM_MASTER_CLK                    */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_CSSI_MC_CGM_SLAVE_CLK                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_CVFCCU_MASTER_CLK                         */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_CVFCCU_SLAVE_CLK                          */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_DSPI_IPI_0_MASTER_CLK                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_DSPI_IPI_1_MASTER_CLK                     */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* IPSYNC_LPE_D_IP_FLEXCAN3_SYN_MASTER_CLK          */
    &Clock_Ip_Get_LPE_FLEXCAN_PE_CLK_Frequency,                                          /* IPSYNC_LPE_D_IP_FLEXCAN3_SYN_SLAVE_CLK           */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_MASTER_CLK         */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LPE_D_IP_LOGIC_UNIT_SYN_SLAVE_CLK         */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_MASTER_CLK         */
    &Clock_Ip_Get_FIRCDIV2_CLK_Frequency,                                                /* IPSYNC_LPE_DA_IP_TEMPSENSE_C16FFC_SLAVE_CLK         */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* IPSYNC_LPE_LVFCCU_MASTER_CLK                     */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LPE_LVFCCU_SLAVE_CLK                      */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* IPSYNC_LPE_MC_CGM_MASTER_CLK                     */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LPE_MC_CGM_SLAVE_CLK                      */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* IPSYNC_LPE_MC_RGM_MASTER_CLK                     */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LPE_MC_RGM_SLAVE_CLK                      */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* IPSYNC_LPE_STM_MASTER_CLK                        */
    &Clock_Ip_Get_LPE_STM_CLK_Frequency,                                                 /* IPSYNC_LPE_STM_SLAVE_CLK                         */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_LVFCCU0_MASTER_CLK                        */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LVFCCU0_SLAVE_CLK                         */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_LVFCCU1_MASTER_CLK                        */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LVFCCU1_SLAVE_CLK                         */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_LVFCCU2_MASTER_CLK                        */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_LVFCCU2_SLAVE_CLK                         */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_MC_CGM_MASTER_CLK                         */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_MC_CGM_SLAVE_CLK                          */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_NETC_MC_CGM_MASTER_CLK                    */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_NETC_MC_CGM_SLAVE_CLK                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_PERI_MC_CGM_MASTER_CLK                    */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_PERI_MC_CGM_SLAVE_CLK                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_SAI0_MC_CGM_MASTER_CLK                    */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_SAI0_MC_CGM_SLAVE_CLK                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* IPSYNC_SAI1_MC_CGM_MASTER_CLK                    */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* IPSYNC_SAI1_MC_CGM_SLAVE_CLK                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_STM0_MASTER_CLK                           */
    &Clock_Ip_Get_STM0_CLK_Frequency,                                                    /* IPSYNC_STM0_SLAVE_CLK                            */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_STM1_MASTER_CLK                           */
    &Clock_Ip_Get_STM1_CLK_Frequency,                                                    /* IPSYNC_STM1_SLAVE_CLK                            */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_STM2_MASTER_CLK                           */
    &Clock_Ip_Get_STM2_CLK_Frequency,                                                    /* IPSYNC_STM2_SLAVE_CLK                            */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_STM3_MASTER_CLK                           */
    &Clock_Ip_Get_STM3_CLK_Frequency,                                                    /* IPSYNC_STM3_SLAVE_CLK                            */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_XSPI_MASTER_CLK                           */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* IPSYNC_XSPI_SLAVE_CLK                            */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LCU0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LCU1_IPG_CLK                                     */
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* LMEM_HCLK_CLK                                    */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_ADC_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_BCTU_IPG_CLK                                 */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_BCTU_IPG_CLK_S                               */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_CMU_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* LPE_CRC_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_CXPI_PE_CLK_Frequency,                                             /* LPE_CXPI_PE_CLK                                  */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_CXPI0_IPG_CLK                                */
    &Clock_Ip_Get_LPE_CXPI_PE_CLK_Frequency,                                             /* LPE_CXPI0_PE_CLK                                 */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_CXPI1_IPG_CLK                                */
    &Clock_Ip_Get_LPE_CXPI_PE_CLK_Frequency,                                             /* LPE_CXPI1_PE_CLK                                 */
    &Clock_Ip_Get_LPE_DIV1_UNGATED_CLK_Frequency,                                        /* LPE_DIV1_UNGATED_CLK                             */
    &Clock_Ip_Get_LPE_DIV2_UNGATED_CLK_Frequency,                                        /* LPE_DIV2_UNGATED_CLK                             */
    &Clock_Ip_Get_LPE_DIV3_UNGATED_CLK_Frequency,                                        /* LPE_DIV3_UNGATED_CLK                             */
    &Clock_Ip_Get_LPE_DIV4_UNGATED_CLK_Frequency,                                        /* LPE_DIV4_UNGATED_CLK                             */
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* LPE_DMA_CH_MUX_IPG_CLK                           */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_EIM_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_FIRC_IPG_CLK                                 */
    &Clock_Ip_Get_LPE_FLEXCAN_PE_CLK_Frequency,                                          /* LPE_FLEXCAN_MOD_CLK                              */
    &Clock_Ip_Get_LPE_FLEXCAN_PE_CLK_Frequency,                                          /* LPE_FLEXCAN_PE_CLK                               */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_FTM_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_FXOSC_IPG_CLK                                */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_GPR0_IPG_CLK                                 */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_GPR1_IPG_CLK                                 */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LCU_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_LPCMP0_IPG_CLK                               */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LPCMP0_RR_CLK                                */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LPCMP0_SAMPLE_GATED_CLK                      */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_LPCMP1_IPG_CLK                               */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LPCMP1_RR_CLK                                */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LPCMP1_SAMPLE_GATED_CLK                      */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_LPCMP2_IPG_CLK                               */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LPCMP2_RR_CLK                                */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_LPCMP2_SAMPLE_GATED_CLK                      */
    &Clock_Ip_Get_LPE_LPI2C_MOD_CLK_Frequency,                                           /* LPE_LPI2C_CLK                                    */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_LPI2C_IPG_CLK                                */
    &Clock_Ip_Get_LPE_LPI2C_MOD_CLK_Frequency,                                           /* LPE_LPI2C_MOD_CLK                                */
    &Clock_Ip_Get_LPE_LPSPI_MOD_CLK_Frequency,                                           /* LPE_LPSPI_MOD_CLK                                */
    &Clock_Ip_Get_LPE_LPSPI_MOD_CLK_Frequency,                                           /* LPE_LPSPI0_CLK                                   */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_LPSPI0_IPG_CLK                               */
    &Clock_Ip_Get_LPE_LPSPI_MOD_CLK_Frequency,                                           /* LPE_LPSPI1_CLK                                   */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_LPSPI1_IPG_CLK                               */
    &Clock_Ip_Get_LPE_LPUART_MOD_CLK_Frequency,                                          /* LPE_LPUART_MOD_CLK                               */
    &Clock_Ip_Get_LPE_LPUART_MOD_CLK_Frequency,                                          /* LPE_LPUART0_CLK                                  */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_LPUART0_pCLK                                 */
    &Clock_Ip_Get_LPE_LPUART_MOD_CLK_Frequency,                                          /* LPE_LPUART1_CLK                                  */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_LPUART1_pCLK                                 */
    &Clock_Ip_Get_LPE_LPUART_MOD_CLK_Frequency,                                          /* LPE_LPUART2_CLK                                  */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_LPUART2_pCLK                                 */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_LSTCU_IPG_CLK                                */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* LPE_PIT_RTI_IPG_CLK_OSC_RTI                      */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_PIT_RTI_IPG_CLK_SYNC                         */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_RTC_API_FIRC_CLK                             */
    &Clock_Ip_Get_FXOSC_CLK_Frequency,                                                   /* LPE_RTC_API_FXOSC_CLK                            */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_RTC_API_IPG_CLK                              */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* LPE_RTC_API_SIRC_CLK                             */
    &Clock_Ip_Get_SXOSC_CLK_Frequency,                                                   /* LPE_RTC_API_SXOSC_CLK                            */
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* LPE_SEMA42_CLK                                   */
    &Clock_Ip_Get_LPE_STM_CLK_Frequency,                                                 /* LPE_STM_CLK                                      */
    &Clock_Ip_Get_LPE_STM_CLK_Frequency,                                                 /* LPE_STM_IPG_CLK                                  */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* LPE_SWT_COUNTER_IP_CLK                           */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_SWT_IPG_CLK                                  */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_SXOSC_IPG_CLK                                */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_TRGMUX_IPG_CLK                               */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_TSPC_IPG_CLK                                 */
    &Clock_Ip_Get_FIRCDIV2_CLK_Frequency,                                                /* LPE_TSU_NS_IPG_CLK                               */
    &Clock_Ip_Get_LPE_UNGATED_CLK_Frequency,                                             /* LPE_UNGATED_CLK                                  */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* LPE_VIRT_IPG_CLK                                 */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_WKPU_IPG_CLK                                 */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* LPE_WKPU_IPG_CLK_S                               */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPI2C0_CLK                                       */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPI2C1_CLK                                       */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPI2C2_CLK                                       */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPI2C3_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI0_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI1_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI2_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI3_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI4_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI5_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI6_CLK                                       */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPSPI7_CLK                                       */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART_MSC_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART_MSC_pCLK                                  */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART0_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART0_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART1_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART1_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART2_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART2_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART3_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART3_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART4_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART4_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART5_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART5_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART6_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART6_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART7_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART7_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART8_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART8_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART9_CLK                                      */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART9_pCLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART10_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART10_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART11_CLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* LPUART11_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART12_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART12_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART13_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART13_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART14_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART14_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART15_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART15_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART16_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART16_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART17_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART17_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART18_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART18_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART19_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART19_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART20_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LPUART20_pCLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_ACCEL_IPG_CLK                              */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_CORE0_IPG_CLK                              */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_CORE12_IPG_CLK                             */
    &Clock_Ip_Get_PLTCORE_CLK_Frequency,                                                 /* LSTCU_CORE3_IPG_CLK                              */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_HSPI_IPG_CLK                               */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_NETC_IPG_CLK                               */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_PBRIDGE1_IPG_CLK                           */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_PBRIDGE3_IPG_CLK                           */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_PBRIDGE4_IPG_CLK                           */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* LSTCU_REST_IPG_CLK                               */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* MRAM_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MRAMC_IPG_CLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* MRAMC_IPG_CLK_S                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* MSCM_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR0_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR1_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR2_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR3_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR4_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR5_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR6_APB_CLK                                 */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* MSGINTR7_APB_CLK                                 */
    &Clock_Ip_Get_PERI_HIGH_SPEED_REST_USDHC_CLK_Frequency,                              /* PERI_HIGH_SPEED_REST_USDHC_CLK                   */
    &Clock_Ip_Get_PERI_HIGH_SPEED_REST_XSPI_CLK_Frequency,                               /* PERI_HIGH_SPEED_REST_XSPI_CLK                    */
    &Clock_Ip_Get_PERI_HIGH_SPEED_TRACE_CLK_Frequency,                                   /* PERI_HIGH_SPEED_TRACE_CLK                        */
    &Clock_Ip_Get_PHY_ETH_CLK_Frequency,                                                 /* PHY_ETH_CLK                                      */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* PIT0_IPG_CLK_OSC                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* PIT0_IPG_CLK_SYNC                                */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* PIT1_IPG_CLK_OSC                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* PIT1_IPG_CLK_SYNC                                */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* PIT2_IPG_CLK_OSC                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* PIT2_IPG_CLK_SYNC                                */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* PIT3_IPG_CLK_OSC                                 */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* PIT3_IPG_CLK_SYNC                                */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* POST_IPG_CLK                                     */
    &Clock_Ip_Get_RR_RTC_CLK_Frequency,                                                  /* RR_RTC_CLK                                       */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* RXLUT_ERM_CLK                                    */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* RXLUT_IPG_CLK                                    */
    &Clock_Ip_Get_SAI0_MCLK_Frequency,                                                   /* SAI0_MCLK                                        */
    &Clock_Ip_Get_SAI0_MCLK_Frequency,                                                   /* SAI0_IO_MCLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* SAI0_IPG_CLK                                     */
    &Clock_Ip_Get_SAI1_MCLK_Frequency,                                                   /* SAI1_IO_MCLK                                     */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* SAI1_IPG_CLK                                     */
    &Clock_Ip_Get_SAI1_MCLK_Frequency,                                                   /* SAI1_MCLK                                        */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* SDHC_IPG_CLK                                     */
    &Clock_Ip_Get_PERI_HIGH_SPEED_REST_USDHC_CLK_Frequency,                              /* SDHC_PER_CLK                                     */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* SEMA42_IPG_CLK                                   */
    &Clock_Ip_Get_SERDES_REF_CLK_Frequency,                                              /* SERDES_ALT_REF_CLK                               */
    &Clock_Ip_Get_SERDES_AUX_CLK_Frequency,                                              /* SERDES_AUX_CLK                                   */
    &Clock_Ip_Get_SERDES_REF_CLK_Frequency,                                              /* SERDES_REF_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* SINC_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SOG_REST_CMU_IPG_CLK                             */
    &Clock_Ip_Get_FIRC_CLK_Frequency,                                                    /* SRC_FIRC_CLK                                     */
    &Clock_Ip_Get_FIRCDIV2_CLK_Frequency,                                                /* SRC_FIRCDIV2_CLK                                 */
    &Clock_Ip_Get_FXOSC_CLK_Frequency,                                                   /* SRC_FXOSC_CLK                                    */
    &Clock_Ip_Get_LPE_CLK_Frequency,                                                     /* SRC_LPE_CLK                                      */
    &Clock_Ip_Get_LPE_DIV1_CLK_Frequency,                                                /* SRC_LPE_DIV1_CLK                                 */
    &Clock_Ip_Get_LPE_DIV2_CLK_Frequency,                                                /* SRC_LPE_DIV2_CLK                                 */
    &Clock_Ip_Get_LPE_DIV4_CLK_Frequency,                                                /* SRC_LPE_DIV4_CLK                                 */
    &Clock_Ip_Get_LPE_DIV8_CLK_Frequency,                                                /* SRC_LPE_DIV8_CLK                                 */
    &Clock_Ip_Get_PLT_CLK_Frequency,                                                     /* SRC_PLT_CLK                                      */
    &Clock_Ip_Get_PLTCORE_CLK_Frequency,                                                 /* SRC_PLTCORE_CLK                                  */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* SRC_PLTDIV1_CLK                                  */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* SRC_PLTDIV2_CLK                                  */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SRC_PLTDIV4_CLK                                  */
    &Clock_Ip_Get_SIRC_CLK_Frequency,                                                    /* SRC_SIRC_CLK                                     */
    &Clock_Ip_Get_SXOSC_CLK_Frequency,                                                   /* SRC_SXOSC_CLK                                    */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SRAM0_CONTROLLER_IPS_CLK                         */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SRAM1_CONTROLLER_IPS_CLK                         */
    &Clock_Ip_Get_PLTDIV1_CLK_Frequency,                                                 /* SRAM2_CONTROLLER_IPS_CLK                         */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* STAM_CLK                                         */
    &Clock_Ip_Get_STM0_CLK_Frequency,                                                    /* STM0_CLK                                         */
    &Clock_Ip_Get_STM0_CLK_Frequency,                                                    /* STM0_IPG_CLK                                     */
    &Clock_Ip_Get_STM1_CLK_Frequency,                                                    /* STM1_CLK                                         */
    &Clock_Ip_Get_STM1_CLK_Frequency,                                                    /* STM1_IPG_CLK                                     */
    &Clock_Ip_Get_STM2_CLK_Frequency,                                                    /* STM2_CLK                                         */
    &Clock_Ip_Get_STM2_CLK_Frequency,                                                    /* STM2_IPG_CLK                                     */
    &Clock_Ip_Get_STM3_CLK_Frequency,                                                    /* STM3_CLK                                         */
    &Clock_Ip_Get_STM3_CLK_Frequency,                                                    /* STM3_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT_STARTUP_IPG_CLK                              */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT_STARTUP_IPG_COUNTER_CLK                      */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT0_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT0_IPG_COUNTER_CLK                             */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT1_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT1_IPG_COUNTER_CLK                             */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT2_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT2_IPG_COUNTER_CLK                             */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT3_IPG_CLK                                     */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* SWT3_IPG_COUNTER_CLK                             */
    &Clock_Ip_Get_TRACE_CLK_Frequency,                                                   /* TRACE_CLK                                        */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* TRGMUX_IPG_CLK_S                                 */
    &Clock_Ip_Get_PLTDIV4_CLK_Frequency,                                                 /* TRGMUX_MSC_IPG_CLK_S                             */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* VWRAP0_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* VWRAP1_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* VWRAP2_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* VWRAP3_IPG_CLK                                   */
    &Clock_Ip_Get_PLTDIV2_CLK_Frequency,                                                 /* XSPI_IPG_CLK                                     */
    &Clock_Ip_Get_PERI_HIGH_SPEED_REST_XSPI_CLK_Frequency,                               /* XSPI_UNGATED_2XSFIF_CLK                          */
};



/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#endif

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

/* External oscillators */
static uint64 Clock_Ip_u32fxosc = CLOCK_IP_DEFAULT_FXOSC_FREQUENCY;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))


/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static extSignalFreq Clock_Ip_axExtSignalFreqEntries[CLOCK_IP_EXT_SIGNALS_NO] =  {
{gated_clk,0U},
{fast_crystal_oscillator,0U},
{slow_crystal_oscillator,0U},
{eth0_mii_rx_ext_clk,0U},
{eth0_mii_tx_ext_clk,0U},
{eth0_rgmii_rx_ext_clk,0U},
{eth0_rgmii_tx_ext_clk,0U},
{eth0_rmii_ref_ext_clk,0U},
{eth1_mii_rx_ext_clk,0U},
{eth1_mii_tx_ext_clk,0U},
{eth1_rgmii_rx_ext_clk,0U},
{eth1_rgmii_tx_ext_clk,0U},
{eth1_rmii_ref_ext_clk,0U},
{eth2_mii_rx_ext_clk,0U},
{eth2_mii_tx_ext_clk,0U},
{eth2_rgmii_rx_ext_clk,0U},
{eth2_rgmii_tx_ext_clk,0U},
{eth2_rmii_ref_ext_clk,0U},
{ts_1588_clk,0U},
};

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"

uint32 Clock_Ip_u32PLL0_CLKChecksum = 0U;
uint32 Clock_Ip_u32PLL1_CLKChecksum = 0U;
uint32 Clock_Ip_u32CPE_PLL_CLKChecksum = 0U;
uint32 Clock_Ip_u32PLL0_DFS0_CLKChecksum = 0U;
uint32 Clock_Ip_u32PLL0_DFS1_CLKChecksum = 0U;
uint32 Clock_Ip_u32PLL0_DFS2_CLKChecksum = 0U;
uint32 Clock_Ip_u32PLL0_DFS3_CLKChecksum = 0U;

uint32 Clock_Ip_u32PLL0_DFS0_CLKFreq = 0U;
uint32 Clock_Ip_u32PLL0_DFS1_CLKFreq = 0U;
uint32 Clock_Ip_u32PLL0_DFS2_CLKFreq = 0U;
uint32 Clock_Ip_u32PLL0_DFS3_CLKFreq = 0U;
uint32 Clock_Ip_u32PLL0_CLKFreq = 0U;
uint32 Clock_Ip_u32PLL1_CLKFreq = 0U;
uint32 Clock_Ip_u32CPE_PLL_CLKFreq = 0U;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_32
#include "Mcu_MemMap.h"




/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"



/* Return zero frequency */
static uint64 Clock_Ip_Get_Zero_Frequency(void)
{
    return 0U;
}

/* Return FIRC_CLK frequency */
static uint64 Clock_Ip_Get_FIRC_CLK_Frequency(void) {
    return CLOCK_IP_FIRC_FREQUENCY;
}
/* Return FIRCDIV2_CLK frequency */
static uint64 Clock_Ip_Get_FIRCDIV2_CLK_Frequency(void) {
    return CLOCK_IP_FIRC_FREQUENCY / 2;
}
static uint64 Clock_Ip_Get_SAFE_CLK_Frequency(void) {
    return CLOCK_IP_SAFE_FREQUENCY;
}
/* Return SIRC_CLK frequency */
static uint64 Clock_Ip_Get_SIRC_CLK_Frequency(void) {
    return CLOCK_IP_FIRC_FREQUENCY;
}
/* Return FXOSC_CLK frequency */
static uint64 Clock_Ip_Get_FXOSC_CLK_Frequency(void) {
    return CLOCK_IP_DEFAULT_FXOSC_FREQUENCY;
}
/* Return SXOSC_CLK frequency */
static uint64 Clock_Ip_Get_SXOSC_CLK_Frequency(void) {
    return 0U;
}
/* Return gated_clk frequency */
static uint64 Clock_Ip_Get_gated_clk_Frequency(void) {
    return 0U;
}
/* Return fast_crystal_oscillator frequency */
static uint64 Clock_Ip_Get_fast_crystal_oscillator_Frequency(void) {
    return 0U;
}
/* Return slow_crystal_oscillator frequency */
static uint64 Clock_Ip_Get_slow_crystal_oscillator_Frequency(void) {
    return 0U;
}
/* Return eth0_mii_rx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth0_mii_rx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth0_mii_tx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth0_mii_tx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth0_rgmii_rx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth0_rgmii_rx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth0_rgmii_tx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth0_rgmii_tx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth0_rmii_ref_ext_clk frequency */
static uint64 Clock_Ip_Get_eth0_rmii_ref_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth1_mii_rx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth1_mii_rx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth1_mii_tx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth1_mii_tx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth1_rgmii_rx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth1_rgmii_rx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth1_rgmii_tx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth1_rgmii_tx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth1_rmii_ref_ext_clk frequency */
static uint64 Clock_Ip_Get_eth1_rmii_ref_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth2_mii_rx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth2_mii_rx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth2_mii_tx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth2_mii_tx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth2_rgmii_rx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth2_rgmii_rx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth2_rgmii_tx_ext_clk frequency */
static uint64 Clock_Ip_Get_eth2_rgmii_tx_ext_clk_Frequency(void) {
    return 0U;
}
/* Return eth2_rmii_ref_ext_clk frequency */
static uint64 Clock_Ip_Get_eth2_rmii_ref_ext_clk_Frequency(void) {
    return 0U;
}
/* Return ts_1588_clk frequency */
static uint64 Clock_Ip_Get_ts_1588_clk_Frequency(void) {
    return 0U;
}
/* Return PLL0_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_CLK_Frequency(void) {
    if (Clock_Ip_u32PLL0_CLKChecksum != (IP_PLL_0->CTRL.RW ^ IP_PLL_0->SPREAD_SPECTRUM.RW ^ IP_PLL_0->DIV.RW ^ IP_PLL_0->DENOMINATOR.RW ^IP_PLL_0->NUMERATOR.RW))
    {
        Clock_Ip_u32PLL0_CLKChecksum = (IP_PLL_0->CTRL.RW ^ IP_PLL_0->SPREAD_SPECTRUM.RW ^ IP_PLL_0->DIV.RW ^ IP_PLL_0->DENOMINATOR.RW ^ IP_PLL_0->NUMERATOR.RW);
        Clock_Ip_u32PLL0_CLKFreq = Clock_Ip_PLL_VCO(IP_PLL_0);
    }
    return (((IP_PLL_0->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) >> PLL_PLL_STATUS_PLL_LOCK_SHIFT) != 0U) ? Clock_Ip_u32PLL0_CLKFreq : 0U;
}
/* Return PLL0_DIV_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DIV_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLL0_CLK_Frequency();
    Frequency >>= 2U;                                                                                                                                 /*  Apply divider value */
    return Frequency;
}
/* Return PLL0_DIV0_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DIV0_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLL0_DIV_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PLL_0->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_DE_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_DE_SHIFT)];/*  Divider enable/disable */
    Frequency /= (((IP_PLL_0->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_SHIFT) + 1U);   /*  Apply divider value */
    return Frequency;
}
/* Return PLL0_DIV4_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DIV4_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLL0_DIV_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PLL_0->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_DE_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_DE_SHIFT)];/*  Divider enable/disable */
    Frequency /= (((IP_PLL_0->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_SHIFT) + 1U);   /*  Apply divider value */
    return Frequency;
}
/* Return PLL0_DFS0_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DFS0_CLK_Frequency(void) {
    if (Clock_Ip_u32PLL0_DFS0_CLKChecksum != (IP_PLL_0->DFS_CTRL_0.RW ^ IP_PLL_0->DFS_DIV_0.RW ^ IP_PLL_0->DFS_STATUS))
    {
        Clock_Ip_u32PLL0_DFS0_CLKChecksum = (IP_PLL_0->DFS_CTRL_0.RW ^ IP_PLL_0->DFS_DIV_0.RW ^ IP_PLL_0->DFS_STATUS);
        Clock_Ip_u32PLL0_DFS0_CLKFreq = DFS_OUTPUT(IP_PLL_0,0U,Clock_Ip_Get_PLL0_CLK_Frequency());
    }
    return ((((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK) >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 0U)) != 0U) ? Clock_Ip_u32PLL0_DFS0_CLKFreq : 0U;
}
#if defined(CLOCK_IP_HAS_PLL0_DFS1_CLK)
/* Return PLL0_DFS1_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DFS1_CLK_Frequency(void) {
    if (Clock_Ip_u32PLL0_DFS1_CLKChecksum != (IP_PLL_0->DFS_CTRL_1.RW ^ IP_PLL_0->DFS_DIV_1.RW ^ IP_PLL_0->DFS_STATUS))
    {
        Clock_Ip_u32PLL0_DFS1_CLKChecksum = (IP_PLL_0->DFS_CTRL_1.RW ^ IP_PLL_0->DFS_DIV_1.RW ^ IP_PLL_0->DFS_STATUS);
        Clock_Ip_u32PLL0_DFS1_CLKFreq = DFS_OUTPUT(IP_PLL_0,1U,Clock_Ip_Get_PLL0_CLK_Frequency());
    }
    return ((((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK) >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 1U)) != 0U) ? Clock_Ip_u32PLL0_DFS1_CLKFreq : 0U;
}
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS2_CLK)
/* Return PLL0_DFS2_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DFS2_CLK_Frequency(void) {
    if (Clock_Ip_u32PLL0_DFS2_CLKChecksum != (IP_PLL_0->DFS_CTRL_2.RW ^ IP_PLL_0->DFS_DIV_2.RW ^ IP_PLL_0->DFS_STATUS))
    {
        Clock_Ip_u32PLL0_DFS2_CLKChecksum = (IP_PLL_0->DFS_CTRL_2.RW ^ IP_PLL_0->DFS_DIV_2.RW ^ IP_PLL_0->DFS_STATUS);
        Clock_Ip_u32PLL0_DFS2_CLKFreq = DFS_OUTPUT(IP_PLL_0,2U,Clock_Ip_Get_PLL0_CLK_Frequency());
    }
    return ((((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK) >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 2U)) != 0U) ? Clock_Ip_u32PLL0_DFS2_CLKFreq : 0U;
}
#endif
#if defined(CLOCK_IP_HAS_PLL0_DFS3_CLK)
/* Return PLL0_DFS3_CLK frequency */
static uint64 Clock_Ip_Get_PLL0_DFS3_CLK_Frequency(void) {
    if (Clock_Ip_u32PLL0_DFS3_CLKChecksum != (IP_PLL_0->DFS_CTRL_3.RW ^ IP_PLL_0->DFS_DIV_3.RW ^ IP_PLL_0->DFS_STATUS))
    {
        Clock_Ip_u32PLL0_DFS3_CLKChecksum = (IP_PLL_0->DFS_CTRL_3.RW ^ IP_PLL_0->DFS_DIV_3.RW ^ IP_PLL_0->DFS_STATUS);
        Clock_Ip_u32PLL0_DFS3_CLKFreq = DFS_OUTPUT(IP_PLL_0,3U,Clock_Ip_Get_PLL0_CLK_Frequency());
    }
    return ((((IP_PLL_0->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK) >> PLL_DFS_STATUS_DFS_OK_SHIFT) & (1UL << 3U)) != 0U) ? Clock_Ip_u32PLL0_DFS3_CLKFreq : 0U;
}
#endif
/* Return PLL1_CLK frequency */
static uint64 Clock_Ip_Get_PLL1_CLK_Frequency(void) {
    if (Clock_Ip_u32PLL1_CLKChecksum != (IP_PLL_1->CTRL.RW ^ IP_PLL_1->SPREAD_SPECTRUM.RW ^ IP_PLL_1->DIV.RW ^ IP_PLL_1->DENOMINATOR.RW ^IP_PLL_1->NUMERATOR.RW))
    {
        Clock_Ip_u32PLL1_CLKChecksum = (IP_PLL_1->CTRL.RW ^ IP_PLL_1->SPREAD_SPECTRUM.RW ^ IP_PLL_1->DIV.RW ^ IP_PLL_1->DENOMINATOR.RW ^ IP_PLL_1->NUMERATOR.RW);
        Clock_Ip_u32PLL1_CLKFreq = Clock_Ip_PLL_VCO(IP_PLL_1);
    }
    return (((IP_PLL_1->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) >> PLL_PLL_STATUS_PLL_LOCK_SHIFT) != 0U) ? Clock_Ip_u32PLL1_CLKFreq : 0U;
}
/* Return PLL1_DIV_CLK frequency */
static uint64 Clock_Ip_Get_PLL1_DIV_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLL1_CLK_Frequency();
    Frequency >>= 2U;                                                                                                                                 /*  Apply divider value */
    return Frequency;
}
/* Return PLL1_DIV0_CLK frequency */
static uint64 Clock_Ip_Get_PLL1_DIV0_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLL1_DIV_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_PLL_1->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_DE_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_DE_SHIFT)];/*  Divider enable/disable */
    Frequency /= (((IP_PLL_1->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_SHIFT) + 1U);   /*  Apply divider value */
    return Frequency;
}
/* Return CPE_PLL_CLK frequency */
static uint64 Clock_Ip_Get_CPE_PLL_CLK_Frequency(void) {
    if (Clock_Ip_u32CPE_PLL_CLKChecksum != (IP_CPE_PLL->CTRL.RW ^ IP_CPE_PLL->SPREAD_SPECTRUM.RW ^ IP_CPE_PLL->DIV.RW ^ IP_CPE_PLL->DENOMINATOR.RW ^IP_CPE_PLL->NUMERATOR.RW))
    {
        Clock_Ip_u32CPE_PLL_CLKChecksum = (IP_CPE_PLL->CTRL.RW ^ IP_CPE_PLL->SPREAD_SPECTRUM.RW ^ IP_CPE_PLL->DIV.RW ^ IP_CPE_PLL->DENOMINATOR.RW ^ IP_CPE_PLL->NUMERATOR.RW);
        Clock_Ip_u32CPE_PLL_CLKFreq = Clock_Ip_PLL_VCO(IP_CPE_PLL);
    }
    return (((IP_CPE_PLL->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK) >> PLL_PLL_STATUS_PLL_LOCK_SHIFT) != 0U) ? Clock_Ip_u32CPE_PLL_CLKFreq : 0U;
}
/* Return CPE_DIV_CLK frequency */
static uint64 Clock_Ip_Get_CPE_DIV_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_CPE_PLL_CLK_Frequency();
    Frequency >>= 2U;                                                                                                                                 /*  Apply divider value */
    return Frequency;
}
/* Return CPE_DIV0_CLK frequency */
static uint64 Clock_Ip_Get_CPE_DIV0_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_CPE_DIV_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_CPE_PLL->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_DE_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_DE_SHIFT)];/*  Divider enable/disable */
    Frequency /= (((IP_CPE_PLL->PLL_OUTPUT_DIVIDER_0 & PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_MASK) >> PLL_PLL_OUTPUT_DIVIDER_0_OUTPUT_DIV_SHIFT) + 1U); /*  Apply divider value */
    return Frequency;
}
/* Return LPE_CLK frequency */
static uint64 Clock_Ip_Get_LPE_CLK_Frequency(void) {
    return Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_0_CSS & MC_CGM_SLC_0_CSS_SELSTAT_MASK) >> MC_CGM_SLC_0_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
}
#if defined(CLOCK_IP_HAS_LPE_DIV1_CLK)
/* Return LPE_DIV1_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV1_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV2_CLK)
/* Return LPE_DIV2_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV2_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV4_CLK)
/* Return LPE_DIV4_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV4_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
#if defined(CLOCK_IP_HAS_LPE_DIV8_CLK)
/* Return LPE_DIV8_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV8_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
/* Return PLT_CLK frequency */
static uint64 Clock_Ip_Get_PLT_CLK_Frequency(void) {
    return Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_0_CSS & MC_CGM_SLC_0_CSS_SELSTAT_MASK) >> MC_CGM_SLC_0_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
}
#if defined(CLOCK_IP_HAS_PLTCORE_CLK)
/* Return PLTCORE_CLK frequency */
static uint64 Clock_Ip_Get_PLTCORE_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLT_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
#if defined(CLOCK_IP_HAS_PLTDIV1_CLK)
/* Return PLTDIV1_CLK frequency */
static uint64 Clock_Ip_Get_PLTDIV1_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLT_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_0_DC_1 & MC_CGM_SLC_0_DC_1_DE_MASK) >> MC_CGM_SLC_0_DC_1_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_0_DC_1 & MC_CGM_SLC_0_DC_1_DIV_MASK) >> MC_CGM_SLC_0_DC_1_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
#if defined(CLOCK_IP_HAS_PLTDIV2_CLK)
/* Return PLTDIV2_CLK frequency */
static uint64 Clock_Ip_Get_PLTDIV2_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLT_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_0_DC_2 & MC_CGM_SLC_0_DC_2_DE_MASK) >> MC_CGM_SLC_0_DC_2_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_0_DC_2 & MC_CGM_SLC_0_DC_2_DIV_MASK) >> MC_CGM_SLC_0_DC_2_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
#if defined(CLOCK_IP_HAS_PLTDIV4_CLK)
/* Return PLTDIV4_CLK frequency */
static uint64 Clock_Ip_Get_PLTDIV4_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_PLT_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_0_DC_3 & MC_CGM_SLC_0_DC_3_DE_MASK) >> MC_CGM_SLC_0_DC_3_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_0_DC_3 & MC_CGM_SLC_0_DC_3_DIV_MASK) >> MC_CGM_SLC_0_DC_3_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
#endif
/* Return CAN_PE_CLK frequency */
static uint64 Clock_Ip_Get_CAN_PE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_1->SLC_3_CSS & MC_CGM_SLC_3_CSS_SELSTAT_MASK) >> MC_CGM_SLC_3_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_1->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DE_MASK) >> MC_CGM_SLC_3_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DIV_MASK) >> MC_CGM_SLC_3_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return DFT_CLK frequency */
static uint64 Clock_Ip_Get_DFT_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_10_CSS & MC_CGM_SLC_10_CSS_SELSTAT_MASK) >> MC_CGM_SLC_10_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_10_DC_0 & MC_CGM_SLC_10_DC_0_DE_MASK) >> MC_CGM_SLC_10_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_10_DC_0 & MC_CGM_SLC_10_DC_0_DIV_MASK) >> MC_CGM_SLC_10_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return DSPI_CLK frequency */
static uint64 Clock_Ip_Get_DSPI_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_5_CSS & MC_CGM_SLC_5_CSS_SELSTAT_MASK) >> MC_CGM_SLC_5_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_5_DC_0 & MC_CGM_SLC_5_DC_0_DE_MASK) >> MC_CGM_SLC_5_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_5_DC_0 & MC_CGM_SLC_5_DC_0_DIV_MASK) >> MC_CGM_SLC_5_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH_TS_CLK frequency */
static uint64 Clock_Ip_Get_ETH_TS_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_13_CSS & MC_CGM_SLC_13_CSS_SELSTAT_MASK) >> MC_CGM_SLC_13_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_13_DC_0 & MC_CGM_SLC_13_DC_0_DE_MASK) >> MC_CGM_SLC_13_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_13_DC_0 & MC_CGM_SLC_13_DC_0_DIV_MASK) >> MC_CGM_SLC_13_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH0_RX_CLK frequency */
static uint64 Clock_Ip_Get_ETH0_RX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_3_CSS & MC_CGM_SLC_3_CSS_SELSTAT_MASK) >> MC_CGM_SLC_3_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DE_MASK) >> MC_CGM_SLC_3_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DIV_MASK) >> MC_CGM_SLC_3_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH0_TX_CLK frequency */
static uint64 Clock_Ip_Get_ETH0_TX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_4_CSS & MC_CGM_SLC_4_CSS_SELSTAT_MASK) >> MC_CGM_SLC_4_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH1_RX_CLK frequency */
static uint64 Clock_Ip_Get_ETH1_RX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_5_CSS & MC_CGM_SLC_5_CSS_SELSTAT_MASK) >> MC_CGM_SLC_5_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_5_DC_0 & MC_CGM_SLC_5_DC_0_DE_MASK) >> MC_CGM_SLC_5_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_5_DC_0 & MC_CGM_SLC_5_DC_0_DIV_MASK) >> MC_CGM_SLC_5_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH1_TX_CLK frequency */
static uint64 Clock_Ip_Get_ETH1_TX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_6_CSS & MC_CGM_SLC_6_CSS_SELSTAT_MASK) >> MC_CGM_SLC_6_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_6_DC_0 & MC_CGM_SLC_6_DC_0_DE_MASK) >> MC_CGM_SLC_6_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_6_DC_0 & MC_CGM_SLC_6_DC_0_DIV_MASK) >> MC_CGM_SLC_6_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH2_RX_CLK frequency */
static uint64 Clock_Ip_Get_ETH2_RX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_7_CSS & MC_CGM_SLC_7_CSS_SELSTAT_MASK) >> MC_CGM_SLC_7_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_7_DC_0 & MC_CGM_SLC_7_DC_0_DE_MASK) >> MC_CGM_SLC_7_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_7_DC_0 & MC_CGM_SLC_7_DC_0_DIV_MASK) >> MC_CGM_SLC_7_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH2_TX_CLK frequency */
static uint64 Clock_Ip_Get_ETH2_TX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_8_CSS & MC_CGM_SLC_8_CSS_SELSTAT_MASK) >> MC_CGM_SLC_8_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_8_DC_0 & MC_CGM_SLC_8_DC_0_DE_MASK) >> MC_CGM_SLC_8_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_8_DC_0 & MC_CGM_SLC_8_DC_0_DIV_MASK) >> MC_CGM_SLC_8_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH3_RX_CLK frequency */
static uint64 Clock_Ip_Get_ETH3_RX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_11_CSS & MC_CGM_SLC_11_CSS_SELSTAT_MASK) >> MC_CGM_SLC_11_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_11_DC_0 & MC_CGM_SLC_11_DC_0_DE_MASK) >> MC_CGM_SLC_11_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_11_DC_0 & MC_CGM_SLC_11_DC_0_DIV_MASK) >> MC_CGM_SLC_11_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH3_TX_CLK frequency */
static uint64 Clock_Ip_Get_ETH3_TX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_12_CSS & MC_CGM_SLC_12_CSS_SELSTAT_MASK) >> MC_CGM_SLC_12_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_12_DC_0 & MC_CGM_SLC_12_DC_0_DE_MASK) >> MC_CGM_SLC_12_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_12_DC_0 & MC_CGM_SLC_12_DC_0_DIV_MASK) >> MC_CGM_SLC_12_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH4_RX_CLK frequency */
static uint64 Clock_Ip_Get_ETH4_RX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_13_CSS & MC_CGM_SLC_13_CSS_SELSTAT_MASK) >> MC_CGM_SLC_13_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_13_DC_0 & MC_CGM_SLC_13_DC_0_DE_MASK) >> MC_CGM_SLC_13_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_13_DC_0 & MC_CGM_SLC_13_DC_0_DIV_MASK) >> MC_CGM_SLC_13_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return ETH4_TX_CLK frequency */
static uint64 Clock_Ip_Get_ETH4_TX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_14_CSS & MC_CGM_SLC_14_CSS_SELSTAT_MASK) >> MC_CGM_SLC_14_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_14_DC_0 & MC_CGM_SLC_14_DC_0_DE_MASK) >> MC_CGM_SLC_14_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_14_DC_0 & MC_CGM_SLC_14_DC_0_DIV_MASK) >> MC_CGM_SLC_14_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return FLEXCAN_0to7_PE_CLK frequency */
static uint64 Clock_Ip_Get_FLEXCAN_0to7_PE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_2_CSS & MC_CGM_SLC_2_CSS_SELSTAT_MASK) >> MC_CGM_SLC_2_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_2_DC_0 & MC_CGM_SLC_2_DC_0_DE_MASK) >> MC_CGM_SLC_2_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_2_DC_0 & MC_CGM_SLC_2_DC_0_DIV_MASK) >> MC_CGM_SLC_2_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return FLEXCAN_8to10_PE_CLK frequency */
static uint64 Clock_Ip_Get_FLEXCAN_8to10_PE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_3_CSS & MC_CGM_SLC_3_CSS_SELSTAT_MASK) >> MC_CGM_SLC_3_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DE_MASK) >> MC_CGM_SLC_3_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DIV_MASK) >> MC_CGM_SLC_3_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return FLEXCAN_11to16_PE_CLK frequency */
static uint64 Clock_Ip_Get_FLEXCAN_11to16_PE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_4_CSS & MC_CGM_SLC_4_CSS_SELSTAT_MASK) >> MC_CGM_SLC_4_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return FLEXIO_CLK frequency */
static uint64 Clock_Ip_Get_FLEXIO_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_1_CSS & MC_CGM_SLC_1_CSS_SELSTAT_MASK) >> MC_CGM_SLC_1_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DE_MASK) >> MC_CGM_SLC_1_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DIV_MASK) >> MC_CGM_SLC_1_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_CXPI_PE_CLK frequency */
static uint64 Clock_Ip_Get_LPE_CXPI_PE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_6_CSS & MC_CGM_SLC_6_CSS_SELSTAT_MASK) >> MC_CGM_SLC_6_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_6_DC_0 & MC_CGM_SLC_6_DC_0_DE_MASK) >> MC_CGM_SLC_6_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_6_DC_0 & MC_CGM_SLC_6_DC_0_DIV_MASK) >> MC_CGM_SLC_6_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_DIV1_UNGATED_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV1_UNGATED_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_UNGATED_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_DIV2_UNGATED_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV2_UNGATED_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_UNGATED_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_DIV3_UNGATED_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV3_UNGATED_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_UNGATED_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_DIV4_UNGATED_CLK frequency */
static uint64 Clock_Ip_Get_LPE_DIV4_UNGATED_CLK_Frequency(void) {
    uint64 Frequency = Clock_Ip_Get_LPE_UNGATED_CLK_Frequency();
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_FLEXCAN_PE_CLK frequency */
static uint64 Clock_Ip_Get_LPE_FLEXCAN_PE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_4_CSS & MC_CGM_SLC_4_CSS_SELSTAT_MASK) >> MC_CGM_SLC_4_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_LPI2C_MOD_CLK frequency */
static uint64 Clock_Ip_Get_LPE_LPI2C_MOD_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_3_CSS & MC_CGM_SLC_3_CSS_SELSTAT_MASK) >> MC_CGM_SLC_3_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DE_MASK) >> MC_CGM_SLC_3_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_3_DC_0 & MC_CGM_SLC_3_DC_0_DIV_MASK) >> MC_CGM_SLC_3_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_LPSPI_MOD_CLK frequency */
static uint64 Clock_Ip_Get_LPE_LPSPI_MOD_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_1_CSS & MC_CGM_SLC_1_CSS_SELSTAT_MASK) >> MC_CGM_SLC_1_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DE_MASK) >> MC_CGM_SLC_1_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DIV_MASK) >> MC_CGM_SLC_1_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_LPUART_MOD_CLK frequency */
static uint64 Clock_Ip_Get_LPE_LPUART_MOD_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_2_CSS & MC_CGM_SLC_2_CSS_SELSTAT_MASK) >> MC_CGM_SLC_2_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_2_DC_0 & MC_CGM_SLC_2_DC_0_DE_MASK) >> MC_CGM_SLC_2_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_2_DC_0 & MC_CGM_SLC_2_DC_0_DIV_MASK) >> MC_CGM_SLC_2_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_STM_CLK frequency */
static uint64 Clock_Ip_Get_LPE_STM_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_5_CSS & MC_CGM_SLC_5_CSS_SELSTAT_MASK) >> MC_CGM_SLC_5_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_LPE_MC_CGM->SLC_5_DC_0 & MC_CGM_SLC_5_DC_0_DE_MASK) >> MC_CGM_SLC_5_DC_0_DE_SHIFT)];                 /*  Divider enable/disable */
    Frequency /= (((IP_LPE_MC_CGM->SLC_5_DC_0 & MC_CGM_SLC_5_DC_0_DIV_MASK) >> MC_CGM_SLC_5_DC_0_DIV_SHIFT) + 1U);                                    /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return LPE_UNGATED_CLK frequency */
static uint64 Clock_Ip_Get_LPE_UNGATED_CLK_Frequency(void) {
    return Clock_Ip_apfFreqSrcTable[0U][((IP_LPE_MC_CGM->SLC_6_CSS & MC_CGM_SLC_6_CSS_SELSTAT_MASK) >> MC_CGM_SLC_6_CSS_SELSTAT_SHIFT)]();       /*  Selector value */
}
/* Return PERI_HIGH_SPEED_REST_USDHC_CLK frequency */
static uint64 Clock_Ip_Get_PERI_HIGH_SPEED_REST_USDHC_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_1->SLC_1_CSS & MC_CGM_SLC_1_CSS_SELSTAT_MASK) >> MC_CGM_SLC_1_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_1->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DE_MASK) >> MC_CGM_SLC_1_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DIV_MASK) >> MC_CGM_SLC_1_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return PERI_HIGH_SPEED_REST_XSPI_CLK frequency */
static uint64 Clock_Ip_Get_PERI_HIGH_SPEED_REST_XSPI_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_1->SLC_2_CSS & MC_CGM_SLC_2_CSS_SELSTAT_MASK) >> MC_CGM_SLC_2_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_1->SLC_2_DC_0 & MC_CGM_SLC_2_DC_0_DE_MASK) >> MC_CGM_SLC_2_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->SLC_2_DC_0 & MC_CGM_SLC_2_DC_0_DIV_MASK) >> MC_CGM_SLC_2_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return PERI_HIGH_SPEED_TRACE_CLK frequency */
static uint64 Clock_Ip_Get_PERI_HIGH_SPEED_TRACE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_1->SLC_4_CSS & MC_CGM_SLC_4_CSS_SELSTAT_MASK) >> MC_CGM_SLC_4_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_1->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DE_MASK) >> MC_CGM_SLC_4_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_1->SLC_4_DC_0 & MC_CGM_SLC_4_DC_0_DIV_MASK) >> MC_CGM_SLC_4_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return PHY_ETH_CLK frequency */
static uint64 Clock_Ip_Get_PHY_ETH_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_1_CSS & MC_CGM_SLC_1_CSS_SELSTAT_MASK) >> MC_CGM_SLC_1_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DE_MASK) >> MC_CGM_SLC_1_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_1_DC_0 & MC_CGM_SLC_1_DC_0_DIV_MASK) >> MC_CGM_SLC_1_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return RR_RTC_CLK frequency */
static uint64 Clock_Ip_Get_RR_RTC_CLK_Frequency(void) {
    uint64 Frequency;

#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    Frequency = OsIf_Trusted_Call_Return(Clock_Ip_Get_RR_RTC_CLK_Frequency_TrustedCall);
  #else
    Frequency = Clock_Ip_Get_RR_RTC_CLK_Frequency_TrustedCall();
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    return Frequency;
}
/* Return RR_RTC_CLK frequency */
uint64 Clock_Ip_Get_RR_RTC_CLK_Frequency_TrustedCall(void)
{
    uint64 Frequency;

    Frequency = Clock_Ip_apfFreqSrcRtcTable[((IP_LPE_RTC->RTCC & RTC_RTCC_CLKSEL_MASK) >> RTC_RTCC_CLKSEL_SHIFT)]();                                  /*  Selector value */

    return Frequency;
}
/* Return SAI0_MCLK frequency */
static uint64 Clock_Ip_Get_SAI0_MCLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_2->SLC_0_CSS & MC_CGM_SLC_0_CSS_SELSTAT_MASK) >> MC_CGM_SLC_0_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_2->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_2->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return SAI1_MCLK frequency */
static uint64 Clock_Ip_Get_SAI1_MCLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_5->SLC_0_CSS & MC_CGM_SLC_0_CSS_SELSTAT_MASK) >> MC_CGM_SLC_0_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_5->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DE_MASK) >> MC_CGM_SLC_0_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_5->SLC_0_DC_0 & MC_CGM_SLC_0_DC_0_DIV_MASK) >> MC_CGM_SLC_0_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return SERDES_AUX_CLK frequency */
static uint64 Clock_Ip_Get_SERDES_AUX_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_9_CSS & MC_CGM_SLC_9_CSS_SELSTAT_MASK) >> MC_CGM_SLC_9_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_9_DC_0 & MC_CGM_SLC_9_DC_0_DE_MASK) >> MC_CGM_SLC_9_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_9_DC_0 & MC_CGM_SLC_9_DC_0_DIV_MASK) >> MC_CGM_SLC_9_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return SERDES_REF_CLK frequency */
static uint64 Clock_Ip_Get_SERDES_REF_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_0->SLC_10_CSS & MC_CGM_SLC_10_CSS_SELSTAT_MASK) >> MC_CGM_SLC_10_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_0->SLC_10_DC_0 & MC_CGM_SLC_10_DC_0_DE_MASK) >> MC_CGM_SLC_10_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_0->SLC_10_DC_0 & MC_CGM_SLC_10_DC_0_DIV_MASK) >> MC_CGM_SLC_10_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return STM0_CLK frequency */
static uint64 Clock_Ip_Get_STM0_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_6_CSS & MC_CGM_SLC_6_CSS_SELSTAT_MASK) >> MC_CGM_SLC_6_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_6_DC_0 & MC_CGM_SLC_6_DC_0_DE_MASK) >> MC_CGM_SLC_6_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_6_DC_0 & MC_CGM_SLC_6_DC_0_DIV_MASK) >> MC_CGM_SLC_6_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return STM1_CLK frequency */
static uint64 Clock_Ip_Get_STM1_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_7_CSS & MC_CGM_SLC_7_CSS_SELSTAT_MASK) >> MC_CGM_SLC_7_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_7_DC_0 & MC_CGM_SLC_7_DC_0_DE_MASK) >> MC_CGM_SLC_7_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_7_DC_0 & MC_CGM_SLC_7_DC_0_DIV_MASK) >> MC_CGM_SLC_7_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return STM2_CLK frequency */
static uint64 Clock_Ip_Get_STM2_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_8_CSS & MC_CGM_SLC_8_CSS_SELSTAT_MASK) >> MC_CGM_SLC_8_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_8_DC_0 & MC_CGM_SLC_8_DC_0_DE_MASK) >> MC_CGM_SLC_8_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_8_DC_0 & MC_CGM_SLC_8_DC_0_DIV_MASK) >> MC_CGM_SLC_8_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return STM3_CLK frequency */
static uint64 Clock_Ip_Get_STM3_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_9_CSS & MC_CGM_SLC_9_CSS_SELSTAT_MASK) >> MC_CGM_SLC_9_CSS_SELSTAT_SHIFT)]();         /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_9_DC_0 & MC_CGM_SLC_9_DC_0_DE_MASK) >> MC_CGM_SLC_9_DC_0_DE_SHIFT)];                   /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_9_DC_0 & MC_CGM_SLC_9_DC_0_DIV_MASK) >> MC_CGM_SLC_9_DC_0_DIV_SHIFT) + 1U);                                      /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}
/* Return TRACE_CLK frequency */
static uint64 Clock_Ip_Get_TRACE_CLK_Frequency(void) {
    uint64 Frequency = 0U;
    Frequency = Clock_Ip_apfFreqSrcTable[0U][((IP_MC_CGM_3->SLC_11_CSS & MC_CGM_SLC_11_CSS_SELSTAT_MASK) >> MC_CGM_SLC_11_CSS_SELSTAT_SHIFT)]();      /*  Selector value */
    Frequency &= Clock_Ip_au32EnableDivider[((IP_MC_CGM_3->SLC_11_DC_0 & MC_CGM_SLC_11_DC_0_DE_MASK) >> MC_CGM_SLC_11_DC_0_DE_SHIFT)];                /*  Divider enable/disable */
    Frequency /= (((IP_MC_CGM_3->SLC_11_DC_0 & MC_CGM_SLC_11_DC_0_DIV_MASK) >> MC_CGM_SLC_11_DC_0_DIV_SHIFT) + 1U);                                   /*  Apply divider value */
    return Frequency;                                                                                                                                 /*  Return frequency value */
}

/* Return Clock_Ip_PLL_VCO frequency */
static uint64 Clock_Ip_PLL_VCO(const PLL_Type *Base)
{
    uint64 Fin;
    uint64 Rdiv;
    uint64 Mfi;
    //uint64 Mfn;
    // uint64 Multiplier;
    Fin  = (((Base->CTRL.RW & PLL_CTRL_REF_CLK_SEL_MASK) >> PLL_CTRL_REF_CLK_SEL_SHIFT) == 0U) ? Clock_Ip_Get_FIRC_CLK_Frequency() : Clock_Ip_Get_FXOSC_CLK_Frequency();   /* input freq */
    Rdiv = ((Base->DIV.RW & PLL_DIV_RDIV_MASK) >> PLL_DIV_RDIV_SHIFT);              /* Rdiv */
    Mfi  = ((Base->DIV.RW & PLL_DIV_MFI_MASK) >> PLL_DIV_MFI_SHIFT);                /* Mfi */
    // Mfn  = ((Base->NUMERATOR.RW & PLL_NUMERATOR_MFN_MASK) >> PLL_NUMERATOR_MFN_SHIFT);                /* Mfn */

    // Multiplier = ((Mfi << CLOCK_IP_MUL_BY_16384) + (Mfi << CLOCK_IP_MUL_BY_2048) + Mfn);

    return ((Fin / Rdiv) * Mfi);                 /* Fin divided by predivider and multiplied. */
}

/* Return DFS_OUTPUT frequency */
static uint64 DFS_OUTPUT(const PLL_Type *Base, uint32 Channel, uint64 Fin)
{
    uint32 Mfi;
    uint32 Mfn;
    uint32 Divider;

    switch (Channel)
    {
        case 0U:
        {
            Mfi = ((Base->DFS_DIV_0.RW & PLL_DFS_DIV_0_MFI_MASK) >> PLL_DFS_DIV_0_MFI_SHIFT);              /* Mfi */
            Mfn = ((Base->DFS_DIV_0.RW & PLL_DFS_DIV_0_MFN_MASK) >> PLL_DFS_DIV_0_MFN_SHIFT);              /* Mfn */
        }
        break;
        case 1U:
        {
            Mfi = ((Base->DFS_DIV_1.RW & PLL_DFS_DIV_0_MFI_MASK) >> PLL_DFS_DIV_0_MFI_SHIFT);              /* Mfi */
            Mfn = ((Base->DFS_DIV_1.RW & PLL_DFS_DIV_0_MFN_MASK) >> PLL_DFS_DIV_0_MFN_SHIFT);              /* Mfn */
        }
        break;
        case 2U:
        {
            Mfi = ((Base->DFS_DIV_2.RW & PLL_DFS_DIV_0_MFI_MASK) >> PLL_DFS_DIV_0_MFI_SHIFT);              /* Mfi */
            Mfn = ((Base->DFS_DIV_2.RW & PLL_DFS_DIV_0_MFN_MASK) >> PLL_DFS_DIV_0_MFN_SHIFT);              /* Mfn */
        }
        break;
        case 3U:
        {
            Mfi = ((Base->DFS_DIV_3.RW & PLL_DFS_DIV_0_MFI_MASK) >> PLL_DFS_DIV_0_MFI_SHIFT);              /* Mfi */
            Mfn = ((Base->DFS_DIV_3.RW & PLL_DFS_DIV_0_MFN_MASK) >> PLL_DFS_DIV_0_MFN_SHIFT);              /* Mfn */
        }
        break;
        default:
        {
            /* Invalid index */
        }
    }

    Divider = (Mfi + Mfn / 5);

    return (Divider != 0U) ? (Fin / Divider) : 0U;                 /* Fin divide by Divider */
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/* Return frequency value */
uint64 Clock_Ip_GetFreq(Clock_Ip_NameType ClockName)
{
    return Clock_Ip_apfFreqTable[ClockName]();
}


#if CLOCK_IP_XOSC_CALLBACKS_COUNT > 1
/* Get external frequency */
void Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_NameType ExtOscName, uint64 Frequency)
{
    switch (ExtOscName)
    {
        case FXOSC_CLK:
            Clock_Ip_u32fxosc = Frequency;
            break;
        default:
            /* Do nothing */
            break;
    }
}
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#endif  /* #if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON)) */

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/* Set frequency value for External Signal */
void Clock_Ip_SetExternalSignalFrequency(Clock_Ip_NameType SignalName, uint64 Frequency)
{
#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))
    uint32 Index;
    for (Index = 0U; Index < CLOCK_IP_EXT_SIGNALS_NO; Index++)
    {
        if (SignalName == Clock_Ip_axExtSignalFreqEntries[Index].Name)
        {
            Clock_Ip_axExtSignalFreqEntries[Index].Frequency = Frequency;
            break;
        }
    }
#else
    (void)SignalName;
    (void)Frequency;
#endif
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"



#ifdef __cplusplus
}
#endif

/** @} */
