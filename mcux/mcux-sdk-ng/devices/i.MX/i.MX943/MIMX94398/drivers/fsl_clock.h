/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"
#ifndef CONFIG_ARM_SCMI
#include "scmi.h"
#include "scmi_clock.h"
#include "scmi_internal.h"
#endif

/*!
 * @brief CCM reg macros to map corresponding registers.
 */
#define CLOCK_OSC32K_HZ                     32768ULL
#define CLOCK_OSC24M_HZ                     24000000ULL
#define CLOCK_FRO_HZ                        256000000ULL
#define CLOCK_PLL_FREF_HZ                   CLOCK_OSC24M_HZ
#define CLOCK_M_HZ                          1000000ULL
#define CLOCK_K_HZ                          1000ULL

#define CLOCK_PLL_CALC_ACCURACY_HZ          1000U
#define CLOCK_PLL_MFD                       (CLOCK_PLL_FREF_HZ/CLOCK_PLL_CALC_ACCURACY_HZ)

#define CLOCK_NUM_PLL                       8U

#define CLOCK_PLL_SYS1                      0U
#define CLOCK_PLL_AUDIO1                    1U
#define CLOCK_PLL_AUDIO2                    2U
#define CLOCK_PLL_ENCODER                   3U
#define CLOCK_PLL_ARM                       4U
#define CLOCK_PLL_DRAM                      5U
#define CLOCK_PLL_HSIO                      6U
#define CLOCK_PLL_LDB                       7U

#define CLOCK_NUM_SRC                       46UL

#define CLOCK_SRC_EXT                       0U
#define CLOCK_SRC_OSC32K                    1U
#define CLOCK_SRC_OSC24M                    2U
#define CLOCK_SRC_FRO                       3U
#define CLOCK_SRC_SYSPLL1_VCO               4U
#define CLOCK_SRC_SYSPLL1_PFD0_UNGATED      5U
#define CLOCK_SRC_SYSPLL1_PFD0              6U
#define CLOCK_SRC_SYSPLL1_PFD0_DIV2         7U
#define CLOCK_SRC_SYSPLL1_PFD1_UNGATED      8U
#define CLOCK_SRC_SYSPLL1_PFD1              9U
#define CLOCK_SRC_SYSPLL1_PFD1_DIV2         10U
#define CLOCK_SRC_SYSPLL1_PFD2_UNGATED      11U
#define CLOCK_SRC_SYSPLL1_PFD2              12U
#define CLOCK_SRC_SYSPLL1_PFD2_DIV2         13U
#define CLOCK_SRC_AUDIOPLL1_VCO             14U
#define CLOCK_SRC_AUDIOPLL1                 15U
#define CLOCK_SRC_AUDIOPLL2_VCO             16U
#define CLOCK_SRC_AUDIOPLL2                 17U
#define CLOCK_SRC_RESERVED18                18U
#define CLOCK_SRC_RESERVED19                19U
#define CLOCK_SRC_RESERVED20                20U
#define CLOCK_SRC_RESERVED21                21U
#define CLOCK_SRC_RESERVED22                22U
#define CLOCK_SRC_RESERVED23                23U
#define CLOCK_SRC_ENCPLL_VCO                24U
#define CLOCK_SRC_ENCPLL_PFD0_UNGATED       25U
#define CLOCK_SRC_ENCPLL_PFD0               26U
#define CLOCK_SRC_ENCPLL_PFD1_UNGATED       27U
#define CLOCK_SRC_ENCPLL_PFD1               28U
#define CLOCK_SRC_ARMPLL_VCO                29U
#define CLOCK_SRC_ARMPLL_PFD0_UNGATED       30U
#define CLOCK_SRC_ARMPLL_PFD0               31U
#define CLOCK_SRC_ARMPLL_PFD1_UNGATED       32U
#define CLOCK_SRC_ARMPLL_PFD1               33U
#define CLOCK_SRC_ARMPLL_PFD2_UNGATED       34U
#define CLOCK_SRC_ARMPLL_PFD2               35U
#define CLOCK_SRC_ARMPLL_PFD3_UNGATED       36U
#define CLOCK_SRC_ARMPLL_PFD3               37U
#define CLOCK_SRC_DRAMPLL_VCO               38U
#define CLOCK_SRC_DRAMPLL                   39U
#define CLOCK_SRC_HSIOPLL_VCO               40U
#define CLOCK_SRC_HSIOPLL                   41U
#define CLOCK_SRC_LDBPLL_VCO                42U
#define CLOCK_SRC_LDBPLL                    43U
#define CLOCK_SRC_EXT1                      44U
#define CLOCK_SRC_EXT2                      45U

#define CLOCK_NUM_ROOT                      128U
#define CLOCK_NUM_ROOT_MUX_SEL              4U

#define CLOCK_ROOT_ADC                      0U
#define CLOCK_ROOT_BUSAON                   1U
#define CLOCK_ROOT_CAN1                     2U
#define CLOCK_ROOT_GLITCHFILTER             3U
#define CLOCK_ROOT_GPT1                     4U
#define CLOCK_ROOT_I3C1SLOW                 5U
#define CLOCK_ROOT_LPI2C1                   6U
#define CLOCK_ROOT_LPI2C2                   7U
#define CLOCK_ROOT_LPSPI1                   8U
#define CLOCK_ROOT_LPSPI2                   9U
#define CLOCK_ROOT_LPTMR1                   10U
#define CLOCK_ROOT_LPUART1                  11U
#define CLOCK_ROOT_LPUART2                  12U
#define CLOCK_ROOT_M33                      13U
#define CLOCK_ROOT_M33SYSTICK               14U
#define CLOCK_ROOT_PDM                      15U
#define CLOCK_ROOT_SAI1                     16U
#define CLOCK_ROOT_TPM2                     17U
#define CLOCK_ROOT_A55                      18U
#define CLOCK_ROOT_A55MTRBUS                19U
#define CLOCK_ROOT_A55PERIPH                20U
#define CLOCK_ROOT_DRAMALT                  21U
#define CLOCK_ROOT_DRAMAPB                  22U
#define CLOCK_ROOT_DISPAPB                  23U
#define CLOCK_ROOT_DISPAXI                  24U
#define CLOCK_ROOT_DISPPIX                  25U
#define CLOCK_ROOT_HSIOACSCAN480M           26U
#define CLOCK_ROOT_HSIOACSCAN80M            27U
#define CLOCK_ROOT_HSIO                     28U
#define CLOCK_ROOT_HSIOPCIEAUX              29U
#define CLOCK_ROOT_HSIOPCIETEST160M         30U
#define CLOCK_ROOT_HSIOPCIETEST400M         31U
#define CLOCK_ROOT_HSIOPCIETEST500M         32U
#define CLOCK_ROOT_HSIOPCIETEST50M          33U
#define CLOCK_ROOT_HSIOUSBTEST60M           34U
#define CLOCK_ROOT_BUSM70                   35U
#define CLOCK_ROOT_M70                      36U
#define CLOCK_ROOT_M70SYSTICK               37U
#define CLOCK_ROOT_BUSM71                   38U
#define CLOCK_ROOT_M71                      39U
#define CLOCK_ROOT_M71SYSTICK               40U
#define CLOCK_ROOT_BUSNETCMIX               41U
#define CLOCK_ROOT_ECAT                     42U
#define CLOCK_ROOT_ENET                     43U
#define CLOCK_ROOT_ENETPHYTEST200M          44U
#define CLOCK_ROOT_ENETPHYTEST500M          45U
#define CLOCK_ROOT_ENETPHYTEST667M          46U
#define CLOCK_ROOT_ENETREF                  47U
#define CLOCK_ROOT_ENETTIMER1               48U
#define CLOCK_ROOT_ENETTIMER2               49U
#define CLOCK_ROOT_ENETTIMER3               50U
#define CLOCK_ROOT_FLEXIO3                  51U
#define CLOCK_ROOT_FLEXIO4                  52U
#define CLOCK_ROOT_M33SYNC                  53U
#define CLOCK_ROOT_M33SYNCSYSTICK           54U
#define CLOCK_ROOT_MAC0                     55U
#define CLOCK_ROOT_MAC1                     56U
#define CLOCK_ROOT_MAC2                     57U
#define CLOCK_ROOT_MAC3                     58U
#define CLOCK_ROOT_MAC4                     59U
#define CLOCK_ROOT_MAC5                     60U
#define CLOCK_ROOT_NOCAPB                   61U
#define CLOCK_ROOT_NOC                      62U
#define CLOCK_ROOT_NPUAPB                   63U
#define CLOCK_ROOT_NPU                      64U
#define CLOCK_ROOT_CCMCKO1                  65U
#define CLOCK_ROOT_CCMCKO2                  66U
#define CLOCK_ROOT_CCMCKO3                  67U
#define CLOCK_ROOT_CCMCKO4                  68U
#define CLOCK_ROOT_BISS                     69U
#define CLOCK_ROOT_BUSWAKEUP                70U
#define CLOCK_ROOT_CAN2                     71U
#define CLOCK_ROOT_CAN3                     72U
#define CLOCK_ROOT_CAN4                     73U
#define CLOCK_ROOT_CAN5                     74U
#define CLOCK_ROOT_ENDAT21                  75U
#define CLOCK_ROOT_ENDAT22                  76U
#define CLOCK_ROOT_ENDAT31FAST              77U
#define CLOCK_ROOT_ENDAT31SLOW              78U
#define CLOCK_ROOT_FLEXIO1                  79U
#define CLOCK_ROOT_FLEXIO2                  80U
#define CLOCK_ROOT_GPT2                     81U
#define CLOCK_ROOT_GPT3                     82U
#define CLOCK_ROOT_GPT4                     83U
#define CLOCK_ROOT_HIPERFACE1               84U
#define CLOCK_ROOT_HIPERFACE1SYNC           85U
#define CLOCK_ROOT_HIPERFACE2               86U
#define CLOCK_ROOT_HIPERFACE2SYNC           87U
#define CLOCK_ROOT_I3C2SLOW                 88U
#define CLOCK_ROOT_LPI2C3                   89U
#define CLOCK_ROOT_LPI2C4                   90U
#define CLOCK_ROOT_LPI2C5                   91U
#define CLOCK_ROOT_LPI2C6                   92U
#define CLOCK_ROOT_LPI2C7                   93U
#define CLOCK_ROOT_LPI2C8                   94U
#define CLOCK_ROOT_LPSPI3                   95U
#define CLOCK_ROOT_LPSPI4                   96U
#define CLOCK_ROOT_LPSPI5                   97U
#define CLOCK_ROOT_LPSPI6                   98U
#define CLOCK_ROOT_LPSPI7                   99U
#define CLOCK_ROOT_LPSPI8                   100U
#define CLOCK_ROOT_LPTMR2                   101U
#define CLOCK_ROOT_LPUART10                 102U
#define CLOCK_ROOT_LPUART11                 103U
#define CLOCK_ROOT_LPUART12                 104U
#define CLOCK_ROOT_LPUART3                  105U
#define CLOCK_ROOT_LPUART4                  106U
#define CLOCK_ROOT_LPUART5                  107U
#define CLOCK_ROOT_LPUART6                  108U
#define CLOCK_ROOT_LPUART7                  109U
#define CLOCK_ROOT_LPUART8                  110U
#define CLOCK_ROOT_LPUART9                  111U
#define CLOCK_ROOT_SAI2                     112U
#define CLOCK_ROOT_SAI3                     113U
#define CLOCK_ROOT_SAI4                     114U
#define CLOCK_ROOT_SWOTRACE                 115U
#define CLOCK_ROOT_TPM4                     116U
#define CLOCK_ROOT_TPM5                     117U
#define CLOCK_ROOT_TPM6                     118U
#define CLOCK_ROOT_USBPHYBURUNIN            119U
#define CLOCK_ROOT_USDHC1                   120U
#define CLOCK_ROOT_USDHC2                   121U
#define CLOCK_ROOT_USDHC3                   122U
#define CLOCK_ROOT_V2XPK                    123U
#define CLOCK_ROOT_WAKEUPAXI                124U
#define CLOCK_ROOT_XSPISLVROOT              125U
#define CLOCK_ROOT_XSPI1                    126U
#define CLOCK_ROOT_XSPI2                    127U

#define CLOCK_NUM_GPR                       3U
#define CLOCK_NUM_GPR_SEL                   8U
#define CLOCK_NUM_GPR_MUX_SEL               2U

#define CLOCK_GPR_SEL_EXT                   0U
#define CLOCK_GPR_SEL_A55C0                 1U
#define CLOCK_GPR_SEL_A55C1                 2U
#define CLOCK_GPR_SEL_A55C2                 3U
#define CLOCK_GPR_SEL_A55C3                 4U
#define CLOCK_GPR_SEL_A55P                  5U
#define CLOCK_GPR_SEL_DRAM                  6U
#define CLOCK_GPR_SEL_TEMPSENSE             7U

#define CLOCK_NUM_CGC                       1U

#define CLOCK_CGC_NPU                       0U

#define CLOCK_ROUND_RULE_CEILING            0U
#define CLOCK_ROUND_RULE_FLOOR              1U
#define CLOCK_ROUND_RULE_CLOSEST            2U

/*******************************************************************************
 * PLL Definitions
 ******************************************************************************/

/* Types */
typedef struct
{
    bool isFrac;
    uint8_t numDFS;
} pll_attr_t;

typedef struct
{
    uint32_t selIdx;
    uint32_t selMask;
    uint32_t selShift;
    uint32_t selMux[CLOCK_NUM_GPR_MUX_SEL];
} ccm_gpr_sel_attr_t;

/*!
 * @brief Clock ID
 */
typedef enum _clock_ip_name
{
    /* unify clock id for clock sources and ips */
    /* clock id for clock sources */
    kCLOCK_Ext = 0, /* clock id for EXT_CLK */
    kCLOCK_Osc32k = 1, /* clock id for OSC_32K_CLK */
    kCLOCK_Osc24m = 2, /* clock id for OSC_24M_CLK */
    kCLOCK_Fro = 3, /* clock id for FRO_CLK */
    kCLOCK_Syspll1ctl = 4, /* clock id for SYS_PLL1_CTL */
    kCLOCK_Syspll1dfs0ctl = 5, /* clock id for SYS_PLL1_DFS0_CTL */
    kCLOCK_Syspll1dfs0 = 6, /* clock id for SYS_PLL1_DFS0_CLK */
    kCLOCK_Syspll1dfs0div2 = 7, /* clock id for SYS_PLL1_DFS0_DIV2_CLK */
    kCLOCK_Syspll1dfs1ctl = 8, /* clock id for SYS_PLL1_DFS1_CTL */
    kCLOCK_Syspll1dfs1 = 9, /* clock id for SYS_PLL1_DFS1_CLK */
    kCLOCK_Syspll1dfs1div2 = 10, /* clock id for SYS_PLL1_DFS1_DIV2_CLK */
    kCLOCK_Syspll1dfs2ctl = 11, /* clock id for SYS_PLL1_DFS2_CTL */
    kCLOCK_Syspll1dfs2 = 12, /* clock id for SYS_PLL1_DFS2_CLK */
    kCLOCK_Syspll1dfs2div2 = 13, /* clock id for SYS_PLL1_DFS2_DIV2_CLK */
    kCLOCK_Audiopll1ctl = 14, /* clock id for AUDIO_PLL1_CTL */
    kCLOCK_Audiopll1 = 15, /* clock id for AUDIO_PLL1_CLK */
    kCLOCK_Audiopll2ctl = 16, /* clock id for AUDIO_PLL2_CTL */
    kCLOCK_Audiopll2 = 17, /* clock id for AUDIO_PLL2_CLK */
    kCLOCK_Videopll1ctl = 18, /* clock id for VIDEO_PLL1_CTL(The clock source dose not exist) */
    kCLOCK_Videopll1 = 19, /* clock id for VIDEO_PLL1_CLK(The clock source dose not exist) */
    kCLOCK_Videopll2ctl = 20, /* clock id for VIDEO_PLL2_CTL(The clock source dose not exist) */
    kCLOCK_Videopll2 = 21, /* clock id for VIDEO_PLL2_CLK(The clock source dose not exist) */
    kCLOCK_Videopll3ctl = 22, /* clock id for VIDEO_PLL3_CTL(The clock source dose not exist) */
    kCLOCK_Videopll3 = 23, /* clock id for VIDEO_PLL3_CLK(The clock source dose not exist) */
    kCLOCK_Encoderpllctl = 24, /* clock id for ENCODER_PLL_CTL */
    kCLOCK_Encoderplldfs0ctl = 25, /* clock id for ENCODER_PLL_DFS0_CTL */
    kCLOCK_Encoderplldfs0 = 26, /* clock id for ENCODER_PLL_DFS0_CLK */
    kCLOCK_Encoderplldfs1ctl = 27, /* clock id for ENCODER_PLL_DFS1_CTL */
    kCLOCK_Encoderplldfs1 = 28, /* clock id for ENCODER_PLL_DFS1_CLK */
    kCLOCK_Armpllctl = 29, /* clock id for ARM_PLL_CTL */
    kCLOCK_Armplldfs0ctl = 30, /* clock id for ARM_PLL_DFS0_CTL */
    kCLOCK_Armplldfs0 = 31, /* clock id for ARM_PLL_DFS0_CLK */
    kCLOCK_Armplldfs1ctl = 32, /* clock id for ARM_PLL_DFS1_CTL */
    kCLOCK_Armplldfs1 = 33, /* clock id for ARM_PLL_DFS1_CLK */
    kCLOCK_Armplldfs2ctl = 34, /* clock id for ARM_PLL_DFS2_CTL */
    kCLOCK_Armplldfs2 = 35, /* clock id for ARM_PLL_DFS2_CLK */
    kCLOCK_Armplldfs3ctl = 36, /* clock id for ARM_PLL_DFS3_CTL */
    kCLOCK_Armplldfs3 = 37, /* clock id for ARM_PLL_DFS3_CLK */
    kCLOCK_Drampllctl = 38, /* clock id for DRAM_PLL_CTL */
    kCLOCK_Drampll = 39, /* clock id for DRAM_PLL_CLK */
    kCLOCK_Hsiopllctl = 40, /* clock id for HSIO_PLL_CTL */
    kCLOCK_Hsiopll = 41, /* clock id for HSIO_PLL_CLK */
    kCLOCK_Ldbpllctl = 42, /* clock id for LDB_PLL_CTL */
    kCLOCK_Ldbpll = 43, /* clock id for LDB_PLL_CLK */
    kCLOCK_Extl   = 44, /* clock id for ext1(from components/imx_sm/devices/MIMX943/drivers/fsl_clock.h) */
    kCLOCK_Ext2   = 45, /* clock id for ext2(from components/imx_sm/devices/MIMX943/drivers/fsl_clock.h) */

    /* clock id for ips */
    kCLOCK_Adc = CLOCK_NUM_SRC + 0, /* clock id for ADC */
    kCLOCK_Busaon = CLOCK_NUM_SRC + 1, /* clock id for BUS AON */
    kCLOCK_Can1 = CLOCK_NUM_SRC + 2, /* clock id for CAN1 */
    kCLOCK_Glitchfilter = CLOCK_NUM_SRC + 3, /* clock id for GLITCHFILTER */
    kCLOCK_Gpt1 = CLOCK_NUM_SRC + 4, /* clock id for GPT1 */
    kCLOCK_I3c1slow = CLOCK_NUM_SRC + 5, /* clock id for I3C1 SLOW */
    kCLOCK_Lpi2c1 = CLOCK_NUM_SRC + 6, /* clock id for LPI2C1 */
    kCLOCK_Lpi2c2 = CLOCK_NUM_SRC + 7, /* clock id for LPI2C2 */
    kCLOCK_Lpspi1 = CLOCK_NUM_SRC + 8, /* clock id for LPSPI1 */
    kCLOCK_Lpspi2 = CLOCK_NUM_SRC + 9, /* clock id for LPSPI2 */
    kCLOCK_Lptmr1 = CLOCK_NUM_SRC + 10, /* clock id for LPTMR1 */
    kCLOCK_Lpuart1 = CLOCK_NUM_SRC + 11, /* clock id for LPUART1 */
    kCLOCK_Lpuart2 = CLOCK_NUM_SRC + 12, /* clock id for LPUART2 */
    kCLOCK_M33 = CLOCK_NUM_SRC + 13, /* clock id for M33 */
    kCLOCK_M33systick = CLOCK_NUM_SRC + 14, /* clock id for M33 SYSTICK */
    kCLOCK_Pdm = CLOCK_NUM_SRC + 15, /* clock id for PDM */
    kCLOCK_Sai1 = CLOCK_NUM_SRC + 16, /* clock id for SAI1 */
    kCLOCK_Tpm2 = CLOCK_NUM_SRC + 17, /* clock id for TPM2 */
    kCLOCK_Arma55 = CLOCK_NUM_SRC + 18, /* clock id for ARM A55 */
    kCLOCK_Arma55mtrbus  = CLOCK_NUM_SRC + 19, /* clock id for ARM A55 MTR BUS  */
    kCLOCK_Arma55periph = CLOCK_NUM_SRC + 20, /* clock id for ARM A55 PERIPH */
    kCLOCK_Dramalt = CLOCK_NUM_SRC + 21, /* clock id for DRAM ALT */
    kCLOCK_Dramapb = CLOCK_NUM_SRC + 22, /* clock id for DRAM APB */
    kCLOCK_Dispapb = CLOCK_NUM_SRC + 23, /* clock id for DISP APB */
    kCLOCK_Dispaxi = CLOCK_NUM_SRC + 24, /* clock id for DISP AXI */
    kCLOCK_Disppix = CLOCK_NUM_SRC + 25, /* clock id for DISP PIX */
    kCLOCK_Hsioacscan480m = CLOCK_NUM_SRC + 26, /* clock id for HSIO ACSCAN 480M */
    kCLOCK_Hsioacscan80m = CLOCK_NUM_SRC + 27, /* clock id for HSIO ACSCAN 80M */
    kCLOCK_Hsio = CLOCK_NUM_SRC + 28, /* clock id for HSIO */
    kCLOCK_Hsiopcieaux = CLOCK_NUM_SRC + 29, /* clock id for HSIO PCIE AUX */
    kCLOCK_Hsiopcietest160m = CLOCK_NUM_SRC + 30, /* clock id for HSIO PCIE TEST 160M */
    kCLOCK_Hsiopcietest400m = CLOCK_NUM_SRC + 31, /* clock id for HSIO PCIE TEST 400M */
    kCLOCK_Hsiopcietest500m = CLOCK_NUM_SRC + 32, /* clock id for HSIO PCIE TEST 500M */
    kCLOCK_Hsiousbtest50m = CLOCK_NUM_SRC + 33, /* clock id for HSIO USB TEST 50M */
    kCLOCK_Hsiousbtest60m = CLOCK_NUM_SRC + 34, /* clock id for HSIO USB TEST 60M */
    kCLOCK_Busm70 = CLOCK_NUM_SRC + 35, /* clock id for BUS M7 0 */
    kCLOCK_M70 = CLOCK_NUM_SRC + 36, /* clock id for M7 0 */
    kCLOCK_M70systick = CLOCK_NUM_SRC + 37, /* clock id for M7 0 SYSTICK */
    kCLOCK_Busm71 = CLOCK_NUM_SRC + 38, /* clock id for BUS M7 1 */
    kCLOCK_M71 = CLOCK_NUM_SRC + 39, /* clock id for M7 1 */
    kCLOCK_M71systick = CLOCK_NUM_SRC + 40, /* clock id for M7 1 SYSTICK */
    kCLOCK_Busnetcmix = CLOCK_NUM_SRC + 41, /* clock id for BUS NETCMIX */
    kCLOCK_Ecat = CLOCK_NUM_SRC + 42, /* clock id for ECAT */
    kCLOCK_Enet = CLOCK_NUM_SRC + 43, /* clock id for ENET */
    kCLOCK_Enetphytest200m = CLOCK_NUM_SRC + 44, /* clock id for ENET PHY TEST 200M */
    kCLOCK_Enetphytest500m = CLOCK_NUM_SRC + 45, /* clock id for ENET PHY TEST 500M */
    kCLOCK_Enetphytest667m = CLOCK_NUM_SRC + 46, /* clock id for ENET PHY TEST 667M */
    kCLOCK_Enetref = CLOCK_NUM_SRC + 47, /* clock id for ENET REF */
    kCLOCK_Enettimer1 = CLOCK_NUM_SRC + 48, /* clock id for ENET TIMER1 */
    kCLOCK_Enettimer2 = CLOCK_NUM_SRC + 49, /* clock id for ENET TIMER2 */
    kCLOCK_Enettimer3 = CLOCK_NUM_SRC + 50, /* clock id for ENET TIMER3 */
    kCLOCK_Flexio3 = CLOCK_NUM_SRC + 51, /* clock id for FLEXIO3 */
    kCLOCK_Flexio4 = CLOCK_NUM_SRC + 52, /* clock id for FLEXIO4 */
    kCLOCK_M33sync = CLOCK_NUM_SRC + 53, /* clock id for M33 SYNC */
    kCLOCK_M33syncsystick = CLOCK_NUM_SRC + 54, /* clock id for M33 SYNC SYSTICK */
    kCLOCK_Mac0 = CLOCK_NUM_SRC + 55, /* clock id for MAC0 */
    kCLOCK_Mac1 = CLOCK_NUM_SRC + 56, /* clock id for MAC1 */
    kCLOCK_Mac2 = CLOCK_NUM_SRC + 57, /* clock id for MAC2 */
    kCLOCK_Mac3 = CLOCK_NUM_SRC + 58, /* clock id for MAC3 */
    kCLOCK_Mac4 = CLOCK_NUM_SRC + 59, /* clock id for MAC4 */
    kCLOCK_Mac5 = CLOCK_NUM_SRC + 60, /* clock id for MAC5 */
    kCLOCK_Nocapb = CLOCK_NUM_SRC + 61, /* clock id for NOC APB */
    kCLOCK_Noc = CLOCK_NUM_SRC + 62, /* clock id for NOC */
    kCLOCK_Npuapb = CLOCK_NUM_SRC + 63, /* clock id for NPU APB */
    kCLOCK_Npu = CLOCK_NUM_SRC + 64, /* clock id for NPU */
    kCLOCK_Ccmcko1 = CLOCK_NUM_SRC + 65, /* clock id for CCM CKO1 */
    kCLOCK_Ccmcko2 = CLOCK_NUM_SRC + 66, /* clock id for CCM CKO2 */
    kCLOCK_Ccmcko3 = CLOCK_NUM_SRC + 67, /* clock id for CCM CKO3 */
    kCLOCK_Ccmcko4 = CLOCK_NUM_SRC + 68, /* clock id for CCM CKO4 */
    kCLOCK_Biss = CLOCK_NUM_SRC + 69, /* clock id for BISS */
    kCLOCK_Buswakeup = CLOCK_NUM_SRC + 70, /* clock id for BUS WAKEUP */
    kCLOCK_Ewm = CLOCK_NUM_SRC + 70, /* clock id for EWM */
    kCLOCK_Ewm0 = CLOCK_NUM_SRC + 70, /* clock id for EWM */
    kCLOCK_Can2 = CLOCK_NUM_SRC + 71, /* clock id for CAN2 */
    kCLOCK_Can3 = CLOCK_NUM_SRC + 72, /* clock id for CAN3 */
    kCLOCK_Can4 = CLOCK_NUM_SRC + 73, /* clock id for CAN4 */
    kCLOCK_Can5 = CLOCK_NUM_SRC + 74, /* clock id for CAN5 */
    kCLOCK_Endat21 = CLOCK_NUM_SRC + 75, /* clock id for ENDAT2 1 */
    kCLOCK_Endat22 = CLOCK_NUM_SRC + 76, /* clock id for ENDAT2 2 */
    kCLOCK_Endat31fast = CLOCK_NUM_SRC + 77, /* clock id for ENDAT3 1 FAST */
    kCLOCK_Endat31slow = CLOCK_NUM_SRC + 78, /* clock id for ENDAT3 1 SLOW */
    kCLOCK_Flexio1 = CLOCK_NUM_SRC + 79, /* clock id for FLEXIO1 */
    kCLOCK_Flexio2 = CLOCK_NUM_SRC + 80, /* clock id for FLEXIO2 */
    kCLOCK_Gpt2 = CLOCK_NUM_SRC + 81, /* clock id for GPT2 */
    kCLOCK_Gpt3 = CLOCK_NUM_SRC + 82, /* clock id for GPT3 */
    kCLOCK_Gpt4 = CLOCK_NUM_SRC + 83, /* clock id for GPT4 */
    kCLOCK_Hiperface1 = CLOCK_NUM_SRC + 84, /* clock id for HIPERFACE1 */
    kCLOCK_Hiperface1sync = CLOCK_NUM_SRC + 85, /* clock id for HIPERFACE1 SYNC */
    kCLOCK_Hiperface2 = CLOCK_NUM_SRC + 86, /* clock id for HIPERFACE2 */
    kCLOCK_Hiperface2sync = CLOCK_NUM_SRC + 87, /* clock id for HIPERFACE2 SYNC */
    kCLOCK_I3c2slow = CLOCK_NUM_SRC + 88, /* clock id for I3C2 SLOW */
    kCLOCK_Lpi2c3 = CLOCK_NUM_SRC + 89, /* clock id for LPI2C3 */
    kCLOCK_Lpi2c4 = CLOCK_NUM_SRC + 90, /* clock id for LPI2C4 */
    kCLOCK_Lpi2c5 = CLOCK_NUM_SRC + 91, /* clock id for LPI2C5 */
    kCLOCK_Lpi2c6 = CLOCK_NUM_SRC + 92, /* clock id for LPI2C6 */
    kCLOCK_Lpi2c7 = CLOCK_NUM_SRC + 93, /* clock id for LPI2C7 */
    kCLOCK_Lpi2c8 = CLOCK_NUM_SRC + 94, /* clock id for LPI2C8 */
    kCLOCK_Lpspi3 = CLOCK_NUM_SRC + 95, /* clock id for LPSPI3 */
    kCLOCK_Lpspi4 = CLOCK_NUM_SRC + 96, /* clock id for LPSPI4 */
    kCLOCK_Lpspi5 = CLOCK_NUM_SRC + 97, /* clock id for LPSPI5 */
    kCLOCK_Lpspi6 = CLOCK_NUM_SRC + 98, /* clock id for LPSPI6 */
    kCLOCK_Lpspi7 = CLOCK_NUM_SRC + 99, /* clock id for LPSPI7 */
    kCLOCK_Lpspi8 = CLOCK_NUM_SRC + 100, /* clock id for LPSPI8 */
    kCLOCK_Lptmr2 = CLOCK_NUM_SRC + 101, /* clock id for LPTMR2 */
    kCLOCK_Lpuart10 = CLOCK_NUM_SRC + 102, /* clock id for LPUART10 */
    kCLOCK_Lpuart11 = CLOCK_NUM_SRC + 103, /* clock id for LPUART11 */
    kCLOCK_Lpuart12 = CLOCK_NUM_SRC + 104, /* clock id for LPUART12 */
    kCLOCK_Lpuart3 = CLOCK_NUM_SRC + 105, /* clock id for LPUART3 */
    kCLOCK_Lpuart4 = CLOCK_NUM_SRC + 106, /* clock id for LPUART4 */
    kCLOCK_Lpuart5 = CLOCK_NUM_SRC + 107, /* clock id for LPUART5 */
    kCLOCK_Lpuart6 = CLOCK_NUM_SRC + 108, /* clock id for LPUART6 */
    kCLOCK_Lpuart7 = CLOCK_NUM_SRC + 109, /* clock id for LPUART7 */
    kCLOCK_Lpuart8 = CLOCK_NUM_SRC + 110, /* clock id for LPUART8 */
    kCLOCK_Lpuart9 = CLOCK_NUM_SRC + 111, /* clock id for LPUART9 */
    kCLOCK_Sai2 = CLOCK_NUM_SRC + 112, /* clock id for SAI2 */
    kCLOCK_Sai3 = CLOCK_NUM_SRC + 113, /* clock id for SAI3 */
    kCLOCK_Sai4 = CLOCK_NUM_SRC + 114, /* clock id for SAI4 */
    kCLOCK_Swotrace = CLOCK_NUM_SRC + 115, /* clock id for SWO TRACE */
    kCLOCK_Tpm4 = CLOCK_NUM_SRC + 116, /* clock id for TPM4 */
    kCLOCK_Tpm5 = CLOCK_NUM_SRC + 117, /* clock id for TPM5 */
    kCLOCK_Tpm6 = CLOCK_NUM_SRC + 118, /* clock id for TPM6 */
    kCLOCK_Usbphyburunin = CLOCK_NUM_SRC + 119, /* clock id for USB PHY BURUNIN */
    kCLOCK_Usdhc1 = CLOCK_NUM_SRC + 120, /* clock id for USDHC1 */
    kCLOCK_Usdhc2 = CLOCK_NUM_SRC + 121, /* clock id for USDHC2 */
    kCLOCK_Usdhc3 = CLOCK_NUM_SRC + 122, /* clock id for USDHC3 */
    kCLOCK_V2xpk = CLOCK_NUM_SRC + 123, /* clock id for V2X PK */
    kCLOCK_Wakeupaxi = CLOCK_NUM_SRC + 124, /* clock id for WAKEUP AXI */
    kCLOCK_Xspislvroot = CLOCK_NUM_SRC + 125, /* clock id for XSPI SLV ROOT */
    kCLOCK_Xspi1 = CLOCK_NUM_SRC + 126, /* clock id for XSPI1 */
    kCLOCK_Xspi2 = CLOCK_NUM_SRC + 127, /* clock id for XSPI2 */
    kCLOCK_IpInvalid          = CLOCK_NUM_SRC + 128
} clock_ip_name_t;

typedef struct _clk
{
    clock_ip_name_t clkId; /* clock device id */
    clock_ip_name_t pclkId; /* parent clock device id */
    uint32_t clkRoundOpt; /* clock round options */
    uint64_t rate; /* clock rate */
} clk_t;

/*!
 * CCM CGC attribute structure
 *
 * Structure for CCM clock-gated clock (CGC) attributes
 */
typedef struct
{
    uint32_t lpcgIdx;                       /*!< LPCG index controlling the CGC */
    uint32_t rootIdx;                       /*!< CCM root sourcing the CGC */
} ccm_cgc_attr_t;

/* Externs */
/*! Board-specific EXT clock */
extern uint64_t g_clockExt1Rate;

/*! PLL attributes */
extern const pll_attr_t g_pllAttrs[];

/*! Clock root mux select (parent clock source for the clock root)*/
extern const uint8_t g_clockRootMux[][CLOCK_NUM_ROOT_MUX_SEL];

/*! GPR-selected clocks (clock source/clock root) */
extern const ccm_gpr_sel_attr_t g_clockGprSel[CLOCK_NUM_GPR_SEL];

/*! CCM CGC attributes */
extern const ccm_cgc_attr_t g_clockCgcAttr[CLOCK_NUM_CGC];

/*******************************************************************************
 * Clock Source Definitions
 ******************************************************************************/

/*******************************************************************************
 * Clock Root Definitions
 ******************************************************************************/

/*! @brief Clock root configuration */
typedef struct _clock_root_config_t
{
    bool clockOff;
    uint8_t mux; /*!< See #clock_root_mux_source_t for details. */
    uint8_t div; /*!< it's the actual divider */
} clock_root_config_t;

/*!
 * @brief Root clock index
 */
typedef enum _clock_root
{
    kCLOCK_Root_Adc,
    kCLOCK_Root_BusAon,
    kCLOCK_Root_Can1,
    kCLOCK_Root_Glitchfilter,
    kCLOCK_Root_Gpt1,
    kCLOCK_Root_I3c1Slow,
    kCLOCK_Root_Lpi2c1,
    kCLOCK_Root_Lpi2c2,
    kCLOCK_Root_Lpspi1,
    kCLOCK_Root_Lpspi2,
    kCLOCK_Root_Lptmr1,
    kCLOCK_Root_Lpuart1,
    kCLOCK_Root_Lpuart2,
    kCLOCK_Root_M33,
    kCLOCK_Root_M33Systick,
    kCLOCK_Root_Pdm,
    kCLOCK_Root_Sai1,
    kCLOCK_Root_Tpm2,
    kCLOCK_Root_ArmA55,
    kCLOCK_Root_ArmA55MtrBus ,
    kCLOCK_Root_ArmA55Periph,
    kCLOCK_Root_DramAlt,
    kCLOCK_Root_DramApb,
    kCLOCK_Root_DispApb,
    kCLOCK_Root_DispAxi,
    kCLOCK_Root_DispPix,
    kCLOCK_Root_HsioAcscan480m,
    kCLOCK_Root_HsioAcscan80m,
    kCLOCK_Root_Hsio,
    kCLOCK_Root_HsioPcieAux,
    kCLOCK_Root_HsioPcieTest160m,
    kCLOCK_Root_HsioPcieTest400m,
    kCLOCK_Root_HsioPcieTest500m,
    kCLOCK_Root_HsioUsbTest50m,
    kCLOCK_Root_HsioUsbTest60m,
    kCLOCK_Root_BusM70,
    kCLOCK_Root_M70,
    kCLOCK_Root_M70Systick,
    kCLOCK_Root_BusM71,
    kCLOCK_Root_M71,
    kCLOCK_Root_M71Systick,
    kCLOCK_Root_BusNetcmix,
    kCLOCK_Root_Ecat,
    kCLOCK_Root_Enet,
    kCLOCK_Root_EnetPhyTest200m,
    kCLOCK_Root_EnetPhyTest500m,
    kCLOCK_Root_EnetPhyTest667m,
    kCLOCK_Root_EnetRef,
    kCLOCK_Root_EnetTimer1,
    kCLOCK_Root_EnetTimer2,
    kCLOCK_Root_EnetTimer3,
    kCLOCK_Root_Flexio3,
    kCLOCK_Root_Flexio4,
    kCLOCK_Root_M33Sync,
    kCLOCK_Root_M33SyncSystick,
    kCLOCK_Root_Mac0,
    kCLOCK_Root_Mac1,
    kCLOCK_Root_Mac2,
    kCLOCK_Root_Mac3,
    kCLOCK_Root_Mac4,
    kCLOCK_Root_Mac5,
    kCLOCK_Root_NocApb,
    kCLOCK_Root_Noc,
    kCLOCK_Root_NpuApb,
    kCLOCK_Root_Npu,
    kCLOCK_Root_CcmCko1,
    kCLOCK_Root_CcmCko2,
    kCLOCK_Root_CcmCko3,
    kCLOCK_Root_CcmCko4,
    kCLOCK_Root_Biss,
    kCLOCK_Root_BusWakeup,
    kCLOCK_Root_Can2,
    kCLOCK_Root_Can3,
    kCLOCK_Root_Can4,
    kCLOCK_Root_Can5,
    kCLOCK_Root_Endat21,
    kCLOCK_Root_Endat22,
    kCLOCK_Root_Endat31Fast,
    kCLOCK_Root_Endat31Slow,
    kCLOCK_Root_Flexio1,
    kCLOCK_Root_Flexio2,
    kCLOCK_Root_Gpt2,
    kCLOCK_Root_Gpt3,
    kCLOCK_Root_Gpt4,
    kCLOCK_Root_Hiperface1,
    kCLOCK_Root_Hiperface1Sync,
    kCLOCK_Root_Hiperface2,
    kCLOCK_Root_Hiperface2Sync,
    kCLOCK_Root_I3c2Slow,
    kCLOCK_Root_Lpi2c3,
    kCLOCK_Root_Lpi2c4,
    kCLOCK_Root_Lpi2c5,
    kCLOCK_Root_Lpi2c6,
    kCLOCK_Root_Lpi2c7,
    kCLOCK_Root_Lpi2c8,
    kCLOCK_Root_Lpspi3,
    kCLOCK_Root_Lpspi4,
    kCLOCK_Root_Lpspi5,
    kCLOCK_Root_Lpspi6,
    kCLOCK_Root_Lpspi7,
    kCLOCK_Root_Lpspi8,
    kCLOCK_Root_Lptmr2,
    kCLOCK_Root_Lpuart10,
    kCLOCK_Root_Lpuart11,
    kCLOCK_Root_Lpuart12,
    kCLOCK_Root_Lpuart3,
    kCLOCK_Root_Lpuart4,
    kCLOCK_Root_Lpuart5,
    kCLOCK_Root_Lpuart6,
    kCLOCK_Root_Lpuart7,
    kCLOCK_Root_Lpuart8,
    kCLOCK_Root_Lpuart9,
    kCLOCK_Root_Sai2,
    kCLOCK_Root_Sai3,
    kCLOCK_Root_Sai4,
    kCLOCK_Root_SwoTrace,
    kCLOCK_Root_Tpm4,
    kCLOCK_Root_Tpm5,
    kCLOCK_Root_Tpm6,
    kCLOCK_Root_UsbPhyBurunin,
    kCLOCK_Root_Usdhc1,
    kCLOCK_Root_Usdhc2,
    kCLOCK_Root_Usdhc3,
    kCLOCK_Root_V2xPk,
    kCLOCK_Root_WakeupAxi,
    kCLOCK_Root_XspiSlvRoot,
    kCLOCK_Root_Xspi1,
    kCLOCK_Root_Xspi2,
} clock_root_t;

/*
 * @brief The enumerator of clock roots' clock source mux value.
 */
typedef enum _clock_root_mux_source
{
    /* adc_clk_root */
    kCLOCK_ADC_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ADC_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ADC_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ADC_ClockRoot_MuxFro = 3U,

    /* bus_aon_clk_root */
    kCLOCK_BUS_AON_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_BUS_AON_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_BUS_AON_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_BUS_AON_ClockRoot_MuxFro = 3U,

    /* can1_clk_root */
    kCLOCK_CAN1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CAN1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_CAN1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_CAN1_ClockRoot_MuxFro = 3U,

    /* glitchfilter_clk_root */
    kCLOCK_GLITCHFILTER_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_GLITCHFILTER_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_GLITCHFILTER_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_GLITCHFILTER_ClockRoot_MuxFro = 3U,

    /* gpt1_clk_root */
    kCLOCK_GPT1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_GPT1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_GPT1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_GPT1_ClockRoot_MuxFro = 3U,

    /* i3c1_slow_clk_root */
    kCLOCK_I3C1_SLOW_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_I3C1_SLOW_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_I3C1_SLOW_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_I3C1_SLOW_ClockRoot_MuxFro = 3U,

    /* lpi2c1_clk_root */
    kCLOCK_LPI2C1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C1_ClockRoot_MuxFro = 3U,

    /* lpi2c2_clk_root */
    kCLOCK_LPI2C2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C2_ClockRoot_MuxFro = 3U,

    /* lpspi1_clk_root */
    kCLOCK_LPSPI1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI1_ClockRoot_MuxFro = 3U,

    /* lpspi2_clk_root */
    kCLOCK_LPSPI2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI2_ClockRoot_MuxFro = 3U,

    /* lptmr1_clk_root */
    kCLOCK_LPTMR1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPTMR1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPTMR1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPTMR1_ClockRoot_MuxFro = 3U,

    /* lpuart1_clk_root */
    kCLOCK_LPUART1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART1_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART1_ClockRoot_MuxFro = 3U,

    /* lpuart2_clk_root */
    kCLOCK_LPUART2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART2_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART2_ClockRoot_MuxFro = 3U,

    /* m33_clk_root */
    kCLOCK_M33_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M33_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_M33_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_M33_ClockRoot_MuxFro = 3U,

    /* m33_systick_clk_root */
    kCLOCK_M33_SYSTICK_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M33_SYSTICK_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_M33_SYSTICK_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_M33_SYSTICK_ClockRoot_MuxFro = 3U,

    /* pdm_clk_root */
    kCLOCK_PDM_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_PDM_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_PDM_ClockRoot_MuxAudioPll2 = 2U,
    kCLOCK_PDM_ClockRoot_MuxExt = 3U,

    /* sai1_clk_root */
    kCLOCK_SAI1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_SAI1_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_SAI1_ClockRoot_MuxAudioPll2 = 2U,
    kCLOCK_SAI1_ClockRoot_MuxExt = 3U,

    /* tpm2_clk_root */
    kCLOCK_TPM2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_TPM2_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_TPM2_ClockRoot_MuxAudioPll1 = 2U,
    kCLOCK_TPM2_ClockRoot_MuxExt = 3U,

    /* arm_a55_clk_root */
    kCLOCK_ARM_A55_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ARM_A55_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ARM_A55_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_ARM_A55_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* arm_a55_mtr_bus_clk_root  */
    kCLOCK_ARM_A55_MTR_BUS_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ARM_A55_MTR_BUS_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ARM_A55_MTR_BUS_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ARM_A55_MTR_BUS_ClockRoot_MuxFro = 3U,

    /* arm_a55_periph_clk_root */
    kCLOCK_ARM_A55_PERIPH_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ARM_A55_PERIPH_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ARM_A55_PERIPH_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_ARM_A55_PERIPH_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* dram_alt_clk_root */
    kCLOCK_DRAM_ALT_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_DRAM_ALT_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_DRAM_ALT_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_DRAM_ALT_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* dram_apb_clk_root */
    kCLOCK_DRAM_APB_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_DRAM_APB_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_DRAM_APB_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_DRAM_APB_ClockRoot_MuxFro = 3U,

    /* disp_apb_clk_root */
    kCLOCK_DISP_APB_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_DISP_APB_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_DISP_APB_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_DISP_APB_ClockRoot_MuxFro = 3U,

    /* disp_axi_clk_root */
    kCLOCK_DISP_AXI_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_DISP_AXI_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_DISP_AXI_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_DISP_AXI_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* disp_pix_clk_root */
    kCLOCK_DISP_PIX_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_DISP_PIX_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_DISP_PIX_ClockRoot_MuxAudioPll2 = 2U,
    kCLOCK_DISP_PIX_ClockRoot_MuxSysPll1Dfs0 = 3U,

    /* hsio_acscan_480m_clk_root */
    kCLOCK_HSIO_ACSCAN_480M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_ACSCAN_480M_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_HSIO_ACSCAN_480M_ClockRoot_MuxEncoderPllDfs1 = 2U,
    kCLOCK_HSIO_ACSCAN_480M_ClockRoot_MuxSysPll1Dfs0Div2 = 3U,

    /* hsio_acscan_80m_clk_root */
    kCLOCK_HSIO_ACSCAN_80M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_ACSCAN_80M_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_HSIO_ACSCAN_80M_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HSIO_ACSCAN_80M_ClockRoot_MuxFro = 3U,

    /* hsio_clk_root */
    kCLOCK_HSIO_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_HSIO_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_HSIO_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* hsio_pcie_aux_clk_root */
    kCLOCK_HSIO_PCIE_AUX_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_PCIE_AUX_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_HSIO_PCIE_AUX_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HSIO_PCIE_AUX_ClockRoot_MuxFro = 3U,

    /* hsio_pcie_test_160m_clk_root */
    kCLOCK_HSIO_PCIE_TEST_160M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_PCIE_TEST_160M_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_HSIO_PCIE_TEST_160M_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_HSIO_PCIE_TEST_160M_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* hsio_pcie_test_400m_clk_root */
    kCLOCK_HSIO_PCIE_TEST_400M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_PCIE_TEST_400M_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_HSIO_PCIE_TEST_400M_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_HSIO_PCIE_TEST_400M_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* hsio_pcie_test_500m_clk_root */
    kCLOCK_HSIO_PCIE_TEST_500M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_PCIE_TEST_500M_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_HSIO_PCIE_TEST_500M_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_HSIO_PCIE_TEST_500M_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* hsio_usb_test_50m_clk_root */
    kCLOCK_HSIO_USB_TEST_50M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_USB_TEST_50M_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_HSIO_USB_TEST_50M_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HSIO_USB_TEST_50M_ClockRoot_MuxFro = 3U,

    /* hsio_usb_test_60m_clk_root */
    kCLOCK_HSIO_USB_TEST_60M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HSIO_USB_TEST_60M_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_HSIO_USB_TEST_60M_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HSIO_USB_TEST_60M_ClockRoot_MuxFro = 3U,

    /* bus_m7_0_clk_root */
    kCLOCK_BUS_M7_0_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_BUS_M7_0_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_BUS_M7_0_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_BUS_M7_0_ClockRoot_MuxFro = 3U,

    /* m7_0_clk_root */
    kCLOCK_M7_0_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M7_0_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_M7_0_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_M7_0_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* m7_0_systick_clk_root */
    kCLOCK_M7_0_SYSTICK_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M7_0_SYSTICK_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_M7_0_SYSTICK_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_M7_0_SYSTICK_ClockRoot_MuxFro = 3U,

    /* bus_m7_1_clk_root */
    kCLOCK_BUS_M7_1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_BUS_M7_1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_BUS_M7_1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_BUS_M7_1_ClockRoot_MuxFro = 3U,

    /* m7_1_clk_root */
    kCLOCK_M7_1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M7_1_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_M7_1_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_M7_1_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* m7_1_systick_clk_root */
    kCLOCK_M7_1_SYSTICK_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M7_1_SYSTICK_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_M7_1_SYSTICK_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_M7_1_SYSTICK_ClockRoot_MuxFro = 3U,

    /* bus_netcmix_clk_root */
    kCLOCK_BUS_NETCMIX_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_BUS_NETCMIX_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_BUS_NETCMIX_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_BUS_NETCMIX_ClockRoot_MuxFro = 3U,

    /* ecat_clk_root */
    kCLOCK_ECAT_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ECAT_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ECAT_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ECAT_ClockRoot_MuxFro = 3U,

    /* enet_clk_root */
    kCLOCK_ENET_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ENET_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_ENET_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* enet_phy_test_200m_clk_root */
    kCLOCK_ENET_PHY_TEST_200M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_PHY_TEST_200M_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ENET_PHY_TEST_200M_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENET_PHY_TEST_200M_ClockRoot_MuxFro = 3U,

    /* enet_phy_test_500m_clk_root */
    kCLOCK_ENET_PHY_TEST_500M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_PHY_TEST_500M_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ENET_PHY_TEST_500M_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_ENET_PHY_TEST_500M_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* enet_phy_test_667m_clk_root */
    kCLOCK_ENET_PHY_TEST_667M_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_PHY_TEST_667M_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ENET_PHY_TEST_667M_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_ENET_PHY_TEST_667M_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* enet_ref_clk_root */
    kCLOCK_ENET_REF_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_REF_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ENET_REF_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENET_REF_ClockRoot_MuxFro = 3U,

    /* enet_timer1_clk_root */
    kCLOCK_ENET_TIMER1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_TIMER1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ENET_TIMER1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENET_TIMER1_ClockRoot_MuxFro = 3U,

    /* enet_timer2_clk_root */
    kCLOCK_ENET_TIMER2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_TIMER2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ENET_TIMER2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENET_TIMER2_ClockRoot_MuxFro = 3U,

    /* enet_timer3_clk_root */
    kCLOCK_ENET_TIMER3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENET_TIMER3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ENET_TIMER3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENET_TIMER3_ClockRoot_MuxFro = 3U,

    /* flexio3_clk_root */
    kCLOCK_FLEXIO3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_FLEXIO3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_FLEXIO3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_FLEXIO3_ClockRoot_MuxFro = 3U,

    /* flexio4_clk_root */
    kCLOCK_FLEXIO4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_FLEXIO4_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_FLEXIO4_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_FLEXIO4_ClockRoot_MuxFro = 3U,

    /* m33_sync_clk_root */
    kCLOCK_M33_SYNC_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M33_SYNC_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_M33_SYNC_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_M33_SYNC_ClockRoot_MuxFro = 3U,

    /* m33_sync_systick_clk_root */
    kCLOCK_M33_SYNC_SYSTICK_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_M33_SYNC_SYSTICK_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_M33_SYNC_SYSTICK_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_M33_SYNC_SYSTICK_ClockRoot_MuxFro = 3U,

    /* mac0_clk_root */
    kCLOCK_MAC0_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_MAC0_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_MAC0_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_MAC0_ClockRoot_MuxFro = 3U,

    /* mac1_clk_root */
    kCLOCK_MAC1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_MAC1_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_MAC1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_MAC1_ClockRoot_MuxFro = 3U,

    /* mac2_clk_root */
    kCLOCK_MAC2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_MAC2_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_MAC2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_MAC2_ClockRoot_MuxFro = 3U,

    /* mac3_clk_root */
    kCLOCK_MAC3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_MAC3_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_MAC3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_MAC3_ClockRoot_MuxFro = 3U,

    /* mac4_clk_root */
    kCLOCK_MAC4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_MAC4_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_MAC4_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_MAC4_ClockRoot_MuxFro = 3U,

    /* mac5_clk_root */
    kCLOCK_MAC5_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_MAC5_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_MAC5_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_MAC5_ClockRoot_MuxFro = 3U,

    /* noc_apb_clk_root */
    kCLOCK_NOC_APB_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_NOC_APB_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_NOC_APB_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_NOC_APB_ClockRoot_MuxFro = 3U,

    /* noc_clk_root */
    kCLOCK_NOC_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_NOC_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_NOC_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_NOC_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* npu_apb_clk_root */
    kCLOCK_NPU_APB_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_NPU_APB_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_NPU_APB_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_NPU_APB_ClockRoot_MuxFro = 3U,

    /* npu_clk_root */
    kCLOCK_NPU_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_NPU_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_NPU_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_NPU_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* ccm_cko1_clk_root */
    kCLOCK_CCM_CKO1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CCM_CKO1_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_CCM_CKO1_ClockRoot_MuxOsc32K = 2U,
    kCLOCK_CCM_CKO1_ClockRoot_MuxAudioPll1 = 3U,

    /* ccm_cko2_clk_root */
    kCLOCK_CCM_CKO2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CCM_CKO2_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_CCM_CKO2_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_CCM_CKO2_ClockRoot_MuxAudioPll2 = 3U,

    /* ccm_cko3_clk_root */
    kCLOCK_CCM_CKO3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CCM_CKO3_ClockRoot_MuxOsc32K = 1U,
    kCLOCK_CCM_CKO3_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_CCM_CKO3_ClockRoot_MuxEncoderPllDfs0 = 3U,

    /* ccm_cko4_clk_root */
    kCLOCK_CCM_CKO4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CCM_CKO4_ClockRoot_MuxEncoderPllDfs1 = 1U,
    kCLOCK_CCM_CKO4_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_CCM_CKO4_ClockRoot_MuxAudioPll2 = 3U,

    /* biss_clk_root */
    kCLOCK_BISS_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_BISS_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_BISS_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_BISS_ClockRoot_MuxFro = 3U,

    /* bus_wakeup_clk_root */
    kCLOCK_BUS_WAKEUP_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_BUS_WAKEUP_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_BUS_WAKEUP_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_BUS_WAKEUP_ClockRoot_MuxFro = 3U,

    /* can2_clk_root */
    kCLOCK_CAN2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CAN2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_CAN2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_CAN2_ClockRoot_MuxFro = 3U,

    /* can3_clk_root */
    kCLOCK_CAN3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CAN3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_CAN3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_CAN3_ClockRoot_MuxFro = 3U,

    /* can4_clk_root */
    kCLOCK_CAN4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CAN4_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_CAN4_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_CAN4_ClockRoot_MuxFro = 3U,

    /* can5_clk_root */
    kCLOCK_CAN5_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_CAN5_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_CAN5_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_CAN5_ClockRoot_MuxFro = 3U,

    /* endat2_1_clk_root */
    kCLOCK_ENDAT2_1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENDAT2_1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ENDAT2_1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENDAT2_1_ClockRoot_MuxEncoderPllDfs1 = 3U,

    /* endat2_2_clk_root */
    kCLOCK_ENDAT2_2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENDAT2_2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ENDAT2_2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENDAT2_2_ClockRoot_MuxEncoderPllDfs1 = 3U,

    /* endat3_1_fast_clk_root */
    kCLOCK_ENDAT3_1_FAST_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENDAT3_1_FAST_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_ENDAT3_1_FAST_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENDAT3_1_FAST_ClockRoot_MuxFro = 3U,

    /* endat3_1_slow_clk_root */
    kCLOCK_ENDAT3_1_SLOW_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_ENDAT3_1_SLOW_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_ENDAT3_1_SLOW_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_ENDAT3_1_SLOW_ClockRoot_MuxFro = 3U,

    /* flexio1_clk_root */
    kCLOCK_FLEXIO1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_FLEXIO1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_FLEXIO1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_FLEXIO1_ClockRoot_MuxFro = 3U,

    /* flexio2_clk_root */
    kCLOCK_FLEXIO2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_FLEXIO2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_FLEXIO2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_FLEXIO2_ClockRoot_MuxFro = 3U,

    /* gpt2_clk_root */
    kCLOCK_GPT2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_GPT2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_GPT2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_GPT2_ClockRoot_MuxFro = 3U,

    /* gpt3_clk_root */
    kCLOCK_GPT3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_GPT3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_GPT3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_GPT3_ClockRoot_MuxFro = 3U,

    /* gpt4_clk_root */
    kCLOCK_GPT4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_GPT4_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_GPT4_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_GPT4_ClockRoot_MuxFro = 3U,

    /* hiperface1_clk_root */
    kCLOCK_HIPERFACE1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HIPERFACE1_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_HIPERFACE1_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HIPERFACE1_ClockRoot_MuxEncoderPllDfs0 = 3U,

    /* hiperface1_sync_clk_root */
    kCLOCK_HIPERFACE1_SYNC_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HIPERFACE1_SYNC_ClockRoot_MuxOsc32K = 1U,
    kCLOCK_HIPERFACE1_SYNC_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HIPERFACE1_SYNC_ClockRoot_MuxEncoderPllDfs0 = 3U,

    /* hiperface2_clk_root */
    kCLOCK_HIPERFACE2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HIPERFACE2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_HIPERFACE2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HIPERFACE2_ClockRoot_MuxEncoderPllDfs0 = 3U,

    /* hiperface2_sync_clk_root */
    kCLOCK_HIPERFACE2_SYNC_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_HIPERFACE2_SYNC_ClockRoot_MuxOsc32K = 1U,
    kCLOCK_HIPERFACE2_SYNC_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_HIPERFACE2_SYNC_ClockRoot_MuxEncoderPllDfs0 = 3U,

    /* i3c2_slow_clk_root */
    kCLOCK_I3C2_SLOW_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_I3C2_SLOW_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_I3C2_SLOW_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_I3C2_SLOW_ClockRoot_MuxFro = 3U,

    /* lpi2c3_clk_root */
    kCLOCK_LPI2C3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C3_ClockRoot_MuxFro = 3U,

    /* lpi2c4_clk_root */
    kCLOCK_LPI2C4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C4_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C4_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C4_ClockRoot_MuxFro = 3U,

    /* lpi2c5_clk_root */
    kCLOCK_LPI2C5_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C5_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C5_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C5_ClockRoot_MuxFro = 3U,

    /* lpi2c6_clk_root */
    kCLOCK_LPI2C6_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C6_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C6_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C6_ClockRoot_MuxFro = 3U,

    /* lpi2c7_clk_root */
    kCLOCK_LPI2C7_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C7_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C7_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C7_ClockRoot_MuxFro = 3U,

    /* lpi2c8_clk_root */
    kCLOCK_LPI2C8_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPI2C8_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPI2C8_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPI2C8_ClockRoot_MuxFro = 3U,

    /* lpspi3_clk_root */
    kCLOCK_LPSPI3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI3_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI3_ClockRoot_MuxFro = 3U,

    /* lpspi4_clk_root */
    kCLOCK_LPSPI4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI4_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI4_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI4_ClockRoot_MuxFro = 3U,

    /* lpspi5_clk_root */
    kCLOCK_LPSPI5_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI5_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI5_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI5_ClockRoot_MuxFro = 3U,

    /* lpspi6_clk_root */
    kCLOCK_LPSPI6_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI6_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI6_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI6_ClockRoot_MuxFro = 3U,

    /* lpspi7_clk_root */
    kCLOCK_LPSPI7_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI7_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI7_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI7_ClockRoot_MuxFro = 3U,

    /* lpspi8_clk_root */
    kCLOCK_LPSPI8_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPSPI8_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPSPI8_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPSPI8_ClockRoot_MuxFro = 3U,

    /* lptmr2_clk_root */
    kCLOCK_LPTMR2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPTMR2_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPTMR2_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_LPTMR2_ClockRoot_MuxFro = 3U,

    /* lpuart10_clk_root */
    kCLOCK_LPUART10_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART10_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART10_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART10_ClockRoot_MuxFro = 3U,

    /* lpuart11_clk_root */
    kCLOCK_LPUART11_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART11_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART11_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART11_ClockRoot_MuxFro = 3U,

    /* lpuart12_clk_root */
    kCLOCK_LPUART12_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART12_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART12_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART12_ClockRoot_MuxFro = 3U,

    /* lpuart3_clk_root */
    kCLOCK_LPUART3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART3_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART3_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART3_ClockRoot_MuxFro = 3U,

    /* lpuart4_clk_root */
    kCLOCK_LPUART4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART4_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART4_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART4_ClockRoot_MuxFro = 3U,

    /* lpuart5_clk_root */
    kCLOCK_LPUART5_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART5_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART5_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART5_ClockRoot_MuxFro = 3U,

    /* lpuart6_clk_root */
    kCLOCK_LPUART6_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART6_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART6_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART6_ClockRoot_MuxFro = 3U,

    /* lpuart7_clk_root */
    kCLOCK_LPUART7_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART7_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART7_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART7_ClockRoot_MuxFro = 3U,

    /* lpuart8_clk_root */
    kCLOCK_LPUART8_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART8_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART8_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART8_ClockRoot_MuxFro = 3U,

    /* lpuart9_clk_root */
    kCLOCK_LPUART9_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_LPUART9_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_LPUART9_ClockRoot_MuxEncoderPllDfs0 = 2U,
    kCLOCK_LPUART9_ClockRoot_MuxFro = 3U,

    /* sai2_clk_root */
    kCLOCK_SAI2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_SAI2_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_SAI2_ClockRoot_MuxAudioPll2 = 2U,
    kCLOCK_SAI2_ClockRoot_MuxExt = 3U,

    /* sai3_clk_root */
    kCLOCK_SAI3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_SAI3_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_SAI3_ClockRoot_MuxAudioPll2 = 2U,
    kCLOCK_SAI3_ClockRoot_MuxExt = 3U,

    /* sai4_clk_root */
    kCLOCK_SAI4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_SAI4_ClockRoot_MuxAudioPll1 = 1U,
    kCLOCK_SAI4_ClockRoot_MuxAudioPll2 = 2U,
    kCLOCK_SAI4_ClockRoot_MuxExt = 3U,

    /* swo_trace_clk_root */
    kCLOCK_SWO_TRACE_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_SWO_TRACE_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_SWO_TRACE_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_SWO_TRACE_ClockRoot_MuxFro = 3U,

    /* tpm4_clk_root */
    kCLOCK_TPM4_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_TPM4_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_TPM4_ClockRoot_MuxAudioPll1 = 2U,
    kCLOCK_TPM4_ClockRoot_MuxExt = 3U,

    /* tpm5_clk_root */
    kCLOCK_TPM5_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_TPM5_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_TPM5_ClockRoot_MuxAudioPll1 = 2U,
    kCLOCK_TPM5_ClockRoot_MuxExt = 3U,

    /* tpm6_clk_root */
    kCLOCK_TPM6_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_TPM6_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_TPM6_ClockRoot_MuxAudioPll1 = 2U,
    kCLOCK_TPM6_ClockRoot_MuxExt = 3U,

    /* usb_phy_burunin_clk_root */
    kCLOCK_USB_PHY_BURUNIN_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_USB_PHY_BURUNIN_ClockRoot_MuxSysPll1Dfs0Div2 = 1U,
    kCLOCK_USB_PHY_BURUNIN_ClockRoot_MuxSysPll1Dfs1Div2 = 2U,
    kCLOCK_USB_PHY_BURUNIN_ClockRoot_MuxFro = 3U,

    /* usdhc1_clk_root */
    kCLOCK_USDHC1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_USDHC1_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_USDHC1_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_USDHC1_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* usdhc2_clk_root */
    kCLOCK_USDHC2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_USDHC2_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_USDHC2_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_USDHC2_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* usdhc3_clk_root */
    kCLOCK_USDHC3_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_USDHC3_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_USDHC3_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_USDHC3_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* v2x_pk_clk_root */
    kCLOCK_V2X_PK_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_V2X_PK_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_V2X_PK_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_V2X_PK_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* wakeup_axi_clk_root */
    kCLOCK_WAKEUP_AXI_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_WAKEUP_AXI_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_WAKEUP_AXI_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_WAKEUP_AXI_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* xspi_slv_root_clk_root */
    kCLOCK_XSPI_SLV_ROOT_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_XSPI_SLV_ROOT_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_XSPI_SLV_ROOT_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_XSPI_SLV_ROOT_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* xspi1_clk_root */
    kCLOCK_XSPI1_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_XSPI1_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_XSPI1_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_XSPI1_ClockRoot_MuxSysPll1Dfs2 = 3U,

    /* xspi2_clk_root */
    kCLOCK_XSPI2_ClockRoot_MuxOsc24M = 0U,
    kCLOCK_XSPI2_ClockRoot_MuxSysPll1Dfs0 = 1U,
    kCLOCK_XSPI2_ClockRoot_MuxSysPll1Dfs1 = 2U,
    kCLOCK_XSPI2_ClockRoot_MuxSysPll1Dfs2 = 3U,

} clock_root_mux_source_t; 

/*******************************************************************************
 * Clock Gate Definitions
 ******************************************************************************/

/*! @brief Clock gate value */
typedef enum _clock_gate_value
{
    kCLOCK_Off = (int)~CCM_LPCG_DIRECT_ON_MASK, /*!< Clock is off. */
    kCLOCK_On  = CCM_LPCG_DIRECT_ON_MASK,       /*!< Clock is on*/
} clock_gate_value_t;

/*! @brief Clock ip name array for EDMA. */
#define EDMA_CLOCKS                \
    {                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
    }

/*! @brief Clock ip name array for ADC. */
#define ADC_CLOCKS                \
    {                              \
        kCLOCK_Adc \
    }

/*
 * ! @brief Clock ip name array for MU.
 * clock of MU1_MUA, MU2_MUA is enabled by same LPCG42(Gate signal is clk_enable_mu_a)
 */
#define MU_CLOCKS                \
    {                            \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid,  \
    }

/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                                                                                                \
    {                                                                                                               \
        kCLOCK_IpInvalid, kCLOCK_Lpi2c1, kCLOCK_Lpi2c2, kCLOCK_Lpi2c3, kCLOCK_Lpi2c4, kCLOCK_Lpi2c5, kCLOCK_Lpi2c6, \
            kCLOCK_Lpi2c7, kCLOCK_Lpi2c8                                                                            \
    }

/*! @brief Clock ip name array for LPIT. */
#define LPIT_CLOCKS                                  \
    {                                                \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, \
    }

/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                                                                                \
    {                                                                                                               \
        kCLOCK_IpInvalid, kCLOCK_Lpspi1, kCLOCK_Lpspi2, kCLOCK_Lpspi3, kCLOCK_Lpspi4, kCLOCK_Lpspi5, kCLOCK_Lpspi6, \
            kCLOCK_Lpspi7, kCLOCK_Lpspi8                                                                            \
    }

/*! @brief Clock ip name array for TPM. */
#define TPM_CLOCKS                                                                    \
    {                                                                                 \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_Tpm2, kCLOCK_IpInvalid, kCLOCK_Tpm4, kCLOCK_Tpm5, kCLOCK_Tpm6, \
    }

/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS                                    \
    {                                                    \
        kCLOCK_IpInvalid, kCLOCK_Flexio1, kCLOCK_Flexio2, kCLOCK_Flexio3, kCLOCK_Flexio4, \
    }

/*! @brief Clock ip name array for XSPI. */
#define XSPI_CLOCKS                    \
    {                                     \
        kCLOCK_IpInvalid, kCLOCK_Xspi1, kCLOCK_Xspi2,  \
    }

/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                              \
    {                                               \
        kCLOCK_IpInvalid, kCLOCK_Can1, kCLOCK_Can2, kCLOCK_Can3, kCLOCK_Can4, kCLOCK_Can5, \
    }

/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                     \
    {                                                                                                     \
        kCLOCK_IpInvalid, kCLOCK_Lpuart1, kCLOCK_Lpuart2, kCLOCK_Lpuart3, kCLOCK_Lpuart4, kCLOCK_Lpuart5, \
        kCLOCK_Lpuart6, kCLOCK_Lpuart7, kCLOCK_Lpuart8, kCLOCK_Lpuart9, kCLOCK_Lpuart10, kCLOCK_Lpuart11, \
	kCLOCK_Lpuart12                                                                                   \
    }

/*! @brief Clock ip name array for SAI. */
#define SAI_CLOCKS                                               \
    {                                                            \
        kCLOCK_IpInvalid, kCLOCK_Sai1, kCLOCK_Sai2, kCLOCK_Sai3, kCLOCK_Sai4, \
    }

/*! @brief Clock ip name array for PDM. */
#define PDM_CLOCKS \
    {              \
        kCLOCK_Pdm \
    }

/*! @brief Clock ip name array for I3C. */
#define I3C_CLOCKS                                 \
    {                                              \
        kCLOCK_IpInvalid, kCLOCK_I3c1, kCLOCK_I3c2 \
    }

/*
 *! @brief Clock ip name array for PWM.
 * PWM clock is from bus_wakeup_clk.
 */
#define PWM_CLOCKS                                                                \
    {                                                                             \
        {kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid}, \
            {kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid},                 \
            {kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid},                 \
            {kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid},                 \
        {                                                                         \
            kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid                    \
        }                                                                         \
    }
/*
 *! @brief Clock ip name array for XBAR.
 * XBAR clock is from bus_wakeup_clk.
 */
#define XBAR_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for GPT.
 */
#define GPT_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for SINC.
 */
#define SINC_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid \
    }
/*
 *! @brief Clock ip name array for EWM.
 */
#define EWM_CLOCKS                                                \
    {                                                              \
        kCLOCK_Ewm \
    }

/*
 *! @brief Clock ip name array for DCIF.
 */
#define DCIF_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for SEMA42.
 */
#define SEMA42_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for EQDC.
 */
#define QDC_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for AOI.
 */
#define AOI_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for PXP.
 */
#define PXP_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid \
    }

/*
 *! @brief Clock ip name array for QTMR.
 */
#define TMR_CLOCKS                                                \
    {                                                              \
        kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid, kCLOCK_IpInvalid \
    }


#ifdef CONFIG_DIRECT
/*******************************************************************************
 * Clock Root APIs
 ******************************************************************************/

/*!
 * @brief Set CCM Root Clock MUX node to certain value.
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 * @param src Clock mux value to set, different mux has different value range. See \ref clock_root_mux_source_t.
 */
static inline void CLOCK_SetRootClockMux(clock_root_t root, uint8_t src)
{
    assert(src < 8U);
    CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW =
        (CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW & ~(CCM_CLOCK_ROOT_MUX_MASK)) | CCM_CLOCK_ROOT_MUX(src);
    __DSB();
    __ISB();
}

/*!
 * @brief Get CCM Root Clock MUX value.
 *
 * @param root Which root clock node to get, see \ref clock_root_t.
 * @return Clock mux value.
 */
static inline uint32_t CLOCK_GetRootClockMux(clock_root_t root)
{
    return (CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW & CCM_CLOCK_ROOT_MUX_MASK) >> CCM_CLOCK_ROOT_MUX_SHIFT;
}

/*!
 * @brief Get CCM Root Clock Source.
 *
 * @param root Which root clock node to get, see \ref clock_root_t.
 * @param src Clock mux value to get, see \ref clock_root_mux_source_t.
 * @return Clock source
 */
static inline clock_name_t CLOCK_GetRootClockSource(clock_root_t root, uint32_t src)
{
    return s_clockSourceName[root][src];
}

/*!
 * @brief Set CCM Root Clock DIV certain value.
 *
 * @param root Which root clock to set, see \ref clock_root_t.
 * @param div Clock div value to set, different divider has different value range.
 */
static inline void CLOCK_SetRootClockDiv(clock_root_t root, uint8_t div)
{
    assert(div);
    CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW =
        (CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW & ~CCM_CLOCK_ROOT_DIV_MASK) |
        CCM_CLOCK_ROOT_DIV((uint32_t)div - 1UL);
    __DSB();
    __ISB();
}

/*!
 * @brief Get CCM DIV node value.
 *
 * @param root Which root clock node to get, see \ref clock_root_t.
 * @return divider set for this root
 */
static inline uint32_t CLOCK_GetRootClockDiv(clock_root_t root)
{
    return ((CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW & CCM_CLOCK_ROOT_DIV_MASK) >> CCM_CLOCK_ROOT_DIV_SHIFT) +
           1UL;
}

/*!
 * @brief Power Off Root Clock
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 */
static inline void CLOCK_PowerOffRootClock(clock_root_t root)
{
    if (0UL == (CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW & CCM_CLOCK_ROOT_OFF_MASK))
    {
        CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.SET = CCM_CLOCK_ROOT_OFF_MASK;
        __DSB();
        __ISB();
    }
}

/*!
 * @brief Power On Root Clock
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 */
static inline void CLOCK_PowerOnRootClock(clock_root_t root)
{
    CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.CLR = CCM_CLOCK_ROOT_OFF_MASK;
    __DSB();
    __ISB();
}

/*!
 * @brief Configure Root Clock
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 * @param config root clock config, see \ref clock_root_config_t
 */
static inline void CLOCK_SetRootClock(clock_root_t root, const clock_root_config_t *config)
{
    assert(config);
    CCM_CTRL->CLOCK_ROOT[root].CLOCK_ROOT_CONTROL.RW = CCM_CLOCK_ROOT_MUX(config->mux) |
                                                       CCM_CLOCK_ROOT_DIV((uint32_t)config->div - 1UL) |
                                                       (config->clockOff ? CCM_CLOCK_ROOT_OFF(config->clockOff) : 0UL);
    __DSB();
    __ISB();
}

/*******************************************************************************
 * Clock Gate APIs
 ******************************************************************************/

/*!
 * @brief Control the clock gate for specific IP.
 *
 * @note This API will not have any effect when this clock is in CPULPM or SetPoint Mode
 *
 * @param name  Which clock to enable, see \ref clock_lpcg_t.
 * @param value Clock gate value to set, see \ref clock_gate_value_t.
 */
static inline void CLOCK_ControlGate(clock_ip_name_t name, clock_gate_value_t value)
{
    if (((uint32_t)value & CCM_LPCG_DIRECT_ON_MASK) != (CCM_CTRL->LPCG[name].DIRECT & CCM_LPCG_DIRECT_ON_MASK))
    {
        CCM_CTRL->LPCG[name].DIRECT = ((uint32_t)value & CCM_LPCG_DIRECT_ON_MASK);
        __DSB();
        __ISB();
    }
}

/*!
 * @brief Enable the clock for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_lpcg_t.
 */
static inline void CLOCK_EnableClock(clock_ip_name_t name)
{
    CLOCK_ControlGate(name, kCLOCK_On);
}

/*!
 * @brief Disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_lpcg_t.
 */
static inline void CLOCK_DisableClock(clock_ip_name_t name)
{
    CLOCK_ControlGate(name, kCLOCK_Off);
}

/*******************************************************************************
 * Other APIs
 ******************************************************************************/

/*
 * Setup a variable for clock source frequencies
 */
extern volatile uint64_t g_clockSourceFreq[CLOCK_NUM_SRC];

/*!
 * @brief Gets the clock frequency for a specific IP module.
 *
 * This function gets the IP module clock frequency.
 *
 * @param name Which root clock to get, see \ref clock_root_t.
 * @return Clock frequency value in hertz
 */
uint64_t CLOCK_GetIpFreq(clock_root_t name);

/*!
 * @brief Gets the clock frequency for a source clock.
 *
 * This function gets the source clock frequency.
 *
 * @param sourceIdx Which source clock to get.
 * @return Clock frequency value in hertz
 */
uint64_t CLOCK_GetSourceFreq(uint32_t sourceIdx);

/*!
 * @brief Gets the clock frequency for a source clock.
 *
 * This function gets the source clock frequency.
 * Compatible with ccm driver
 *
 * @param sourceIdx Which source clock to get.
 * @return Clock frequency value in hertz
 */
uint64_t CLOCK_SourceGetRate(uint32_t sourceIdx);

/*!
 * @brief Set the clock frequency for a source clock.
 *
 * This function sets the source clock frequency.
 *
 * @param sourceIdx Which source clock to get.
 * @param rate Clock frequency will be set.
 * @param roundRule Round rule will be set.
 * @return true: succeed to set clock frequency; false: failed to set clock frequency
 */
bool CLOCK_SourceSetRate(uint32_t sourceIdx, uint64_t rate,
    uint32_t roundRule);

/*!
 * Get clock source enable status
 *
 * @param[in]       sourceIdx       Clock source identifier
 *
 * This function allows caller to get the enable status of given clock source.
 * For the PLL clock sources, it queries the status from Fractional PLL driver
 * API calls.
 *
 * @return Returns true if clock source is enabled and it's enable status is
 * retrieved successfully, otherwise false.
 */
bool CLOCK_SourceGetEnable(uint32_t sourceIdx);

/*!
 * Set clock source enable status
 *
 * @param[in]       sourceIdx       Clock source identifier
 * @param[in]       enable          Enable flag (1=enable, 0=disable)
 *
 * This function allows caller to set the enable status of given clock source.
 * For the PLL clock sources, it calls Fractional PLL driver APIs to set
 * enable flag.
 *
 * @return Returns true if enable flag is set successfully for given clock
 * source, otherwise false.
 */
bool CLOCK_SourceSetEnable(uint32_t sourceIdx, bool enable);
#else
/**
 * @brief Enable the clock for specific IP.
 * @param clk : Clock to be enabled.
 * @return  Nothing
 */
status_t CLOCK_EnableClock(clock_ip_name_t clkId);

/**
 * @brief Disable the clock for specific IP.
 * @param clk : Clock to be disabled.
 * @return  Nothing
 */
status_t CLOCK_DisableClock(clock_ip_name_t clkId);

/**
 * @brief Set rate of the clock for specific IP.
 * @param clk : Clock's rate to be set.
 * @return  status
 */
status_t CLOCK_SetRate(clk_t *clk);

/**
 * @brief Get rate of the clock for specific IP.
 * @param clk : Clock's rate to be Get.
 * @return  clock rate
 */
uint64_t CLOCK_GetRate(clock_ip_name_t clkId);

/**
 * @brief Set parent clock for specific IP.
 * @param clk : Clock's parent to be set.
 * @return  status
 */

status_t CLOCK_SetParent(clk_t *clk);
#endif

#endif
