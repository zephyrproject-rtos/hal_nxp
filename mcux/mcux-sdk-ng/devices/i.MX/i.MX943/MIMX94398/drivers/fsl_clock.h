/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

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
#if 0
/*! @brief PLL initialzation data. */
typedef struct _fracn_pll_init
{
    uint32_t rdiv;
    uint32_t mfi;
    uint32_t mfn;
    uint32_t mfd;
    uint32_t odiv;
} fracn_pll_init_t;

/*! @brief PLL PFD initialzation data. */
typedef struct _fracn_pll_pfd_init
{
    uint32_t mfi;
    uint32_t mfn;
    bool div2_en;
} fracn_pll_pfd_init_t;
#endif

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

#if 0
/*!
 * @brief PLL init.
 *
 * @param pll PLL base addr.
 * @param pll_cfg PLL initailization data.
 */
static inline void CLOCK_PllInit(PLL_Type *pll, const fracn_pll_init_t *pll_cfg)
{
    /* Bypass PLL */
    pll->CTRL.SET = PLL_CTRL_CLKMUX_BYPASS_MASK;
    /* Disable output and PLL */
    pll->CTRL.CLR = PLL_CTRL_CLKMUX_EN_MASK | PLL_CTRL_POWERUP_MASK;
    /* Set rdiv, mfi, and odiv */
    pll->DIV.RW = PLL_DIV_RDIV(pll_cfg->rdiv) | PLL_DIV_MFI(pll_cfg->mfi) | PLL_DIV_ODIV(pll_cfg->odiv);
    /* Disable spread spectrum modulation */
    pll->SPREAD_SPECTRUM.CLR = PLL_SPREAD_SPECTRUM_ENABLE_MASK;
    /* Set mfn and mfd */
    pll->NUMERATOR.RW   = PLL_NUMERATOR_MFN(pll_cfg->mfn);
    pll->DENOMINATOR.RW = PLL_DENOMINATOR_MFD(pll_cfg->mfd);

    /* Power up for locking */
    pll->CTRL.SET = PLL_CTRL_POWERUP_MASK;
    while (!(pll->PLL_STATUS & PLL_PLL_STATUS_PLL_LOCK_MASK))
    {
    }

    /* Enable PLL and clean bypass*/
    pll->CTRL.SET = PLL_CTRL_CLKMUX_EN_MASK;
    pll->CTRL.CLR = PLL_CTRL_CLKMUX_BYPASS_MASK;
    __DSB();
    __ISB();
}

/*!
 * @brief PLL PFD init.
 *
 * @param pll PLL base addr.
 * @param pfd_n The PFD index number.
 * @param pfd_cfg PLL PFD initailization data.
 */
static inline void CLOCK_PllPfdInit(PLL_Type *pll, uint32_t pfd_n, const fracn_pll_pfd_init_t *pfd_cfg)
{
    /* Bypass DFS*/
    pll->DFS[pfd_n].DFS_CTRL.SET = PLL_DFS_BYPASS_EN_MASK;
    /* Disable output and DFS */
    pll->DFS[pfd_n].DFS_CTRL.CLR = PLL_DFS_CLKOUT_EN_MASK | PLL_DFS_ENABLE_MASK;
    /* Set mfi and mfn */
    pll->DFS[pfd_n].DFS_DIV.RW = PLL_DFS_MFI(pfd_cfg->mfi) | PLL_DFS_MFN(pfd_cfg->mfn);
    /* Enable output and DFS*/
    pll->DFS[pfd_n].DFS_CTRL.SET = PLL_DFS_CLKOUT_EN_MASK;
    /* Enable div2 */
    if (pfd_cfg->div2_en)
        pll->DFS[pfd_n].DFS_CTRL.SET = PLL_DFS_CLKOUT_DIVBY2_EN_MASK;
    /* Enable DFS for locking*/
    pll->DFS[pfd_n].DFS_CTRL.SET = PLL_DFS_ENABLE_MASK;
    while (!((pll->DFS_STATUS & PLL_DFS_STATUS_DFS_OK_MASK) & (1 << pfd_n)))
    {
    }
    /* Clean bypass */
    pll->DFS[pfd_n].DFS_CTRL.CLR = PLL_DFS_BYPASS_EN_MASK;
    __DSB();
    __ISB();
}
#endif

/*******************************************************************************
 * Clock Source Definitions
 ******************************************************************************/

/*!
 * @brief Clock name.
 */
typedef enum _clock_name
{
    kCLOCK_Ext = 0,
    kCLOCK_Osc32K = 1,
    kCLOCK_Osc24M = 2,
    kCLOCK_Fro = 3,
    kCLOCK_SysPll1Ctl = 4,
    kCLOCK_SysPll1Dfs0Ctl = 5,
    kCLOCK_SysPll1Dfs0 = 6,
    kCLOCK_SysPll1Dfs0Div2 = 7,
    kCLOCK_SysPll1Dfs1Ctl = 8,
    kCLOCK_SysPll1Dfs1 = 9,
    kCLOCK_SysPll1Dfs1Div2 = 10,
    kCLOCK_SysPll1Dfs2Ctl = 11,
    kCLOCK_SysPll1Dfs2 = 12,
    kCLOCK_SysPll1Dfs2Div2 = 13,
    kCLOCK_AudioPll1Ctl = 14,
    kCLOCK_AudioPll1 = 15,
    kCLOCK_AudioPll2Ctl = 16,
    kCLOCK_AudioPll2 = 17,
    kCLOCK_VideoPll1Ctl_NotExist = 18, /* The clock source does not exist */
    kCLOCK_VideoPll1_NotExist = 19,
    kCLOCK_VideoPll2Ctl_NotExist = 20,
    kCLOCK_VideoPll2_NotExist = 21,
    kCLOCK_VideoPll3Ctl_NotExist = 22,
    kCLOCK_VideoPll3_NotExist = 23,
    kCLOCK_EncoderPllCtl = 24,
    kCLOCK_EncoderPllDfs0Ctl = 25,
    kCLOCK_EncoderPllDfs0 = 26,
    kCLOCK_EncoderPllDfs1Ctl = 27,
    kCLOCK_EncoderPllDfs1 = 28,
    kCLOCK_ArmPllCtl = 29,
    kCLOCK_ArmPllDfs0Ctl = 30,
    kCLOCK_ArmPllDfs0 = 31,
    kCLOCK_ArmPllDfs1Ctl = 32,
    kCLOCK_ArmPllDfs1 = 33,
    kCLOCK_ArmPllDfs2Ctl = 34,
    kCLOCK_ArmPllDfs2 = 35,
    kCLOCK_ArmPllDfs3Ctl = 36,
    kCLOCK_ArmPllDfs3 = 37,
    kCLOCK_DramPllCtl = 38,
    kCLOCK_DramPll = 39,
    kCLOCK_HsioPllCtl = 40,
    kCLOCK_HsioPll = 41,
    kCLOCK_LdbPllCtl = 42,
    kCLOCK_LdbPll = 43,
} clock_name_t;

static const clock_name_t s_clockSourceName[][4] = {
    /*   SRC0,         SRC1,                      SRC2,                                 SRC3,            */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* adc_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* bus_aon_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* can1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* glitchfilter_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* gpt1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* i3c1_slow_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lptmr1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2, kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2, kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart2_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* m33_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* m33_systick_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1,        kCLOCK_AudioPll2,               kCLOCK_Ext},	/* pdm_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1,        kCLOCK_AudioPll2,               kCLOCK_Ext},	/* sai1_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,        kCLOCK_AudioPll1,               kCLOCK_Ext},	/* tpm2_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* arm_a55_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* arm_a55_mtr_bus_clk_root  */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* arm_a55_periph_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* dram_alt_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* dram_apb_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* disp_apb_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* disp_axi_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1,        kCLOCK_AudioPll2,         kCLOCK_SysPll1Dfs0},	/* disp_pix_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1, kCLOCK_EncoderPllDfs1,    kCLOCK_SysPll1Dfs0Div2},	/* hsio_acscan_480m_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* hsio_acscan_80m_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* hsio_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* hsio_pcie_aux_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* hsio_pcie_test_160m_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* hsio_pcie_test_400m_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* hsio_pcie_test_500m_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* hsio_usb_test_50m_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* hsio_usb_test_60m_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* bus_m7_0_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* m7_0_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* m7_0_systick_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* bus_m7_1_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* m7_1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* m7_1_systick_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* bus_netcmix_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* ecat_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* enet_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* enet_phy_test_200m_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* enet_phy_test_500m_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* enet_phy_test_667m_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* enet_ref_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* enet_timer1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* enet_timer2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* enet_timer3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* flexio3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* flexio4_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* m33_sync_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* m33_sync_systick_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* mac0_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* mac1_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* mac2_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* mac3_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* mac4_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* mac5_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* noc_apb_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* noc_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* npu_apb_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* npu_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,           kCLOCK_Osc32K,        kCLOCK_AudioPll1},	/* ccm_cko1_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,        kCLOCK_AudioPll2},	/* ccm_cko2_clk_root */
    {kCLOCK_Osc24M,           kCLOCK_Osc32K,         kCLOCK_SysPll1Dfs1, kCLOCK_EncoderPllDfs0},	/* ccm_cko3_clk_root */
    {kCLOCK_Osc24M, kCLOCK_EncoderPllDfs1,         kCLOCK_SysPll1Dfs1,        kCLOCK_AudioPll2},	/* ccm_cko4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* biss_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* bus_wakeup_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* can2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* can3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* can4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* can5_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2, kCLOCK_EncoderPllDfs1},	/* endat2_1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2, kCLOCK_EncoderPllDfs1},	/* endat2_2_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* endat3_1_fast_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* endat3_1_slow_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* flexio1_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* flexio2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* gpt2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* gpt3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* gpt4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2, kCLOCK_EncoderPllDfs0},	/* hiperface1_clk_root */
    {kCLOCK_Osc24M,           kCLOCK_Osc32K,    kCLOCK_SysPll1Dfs1Div2, kCLOCK_EncoderPllDfs0},	/* hiperface1_sync_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2, kCLOCK_EncoderPllDfs0},	/* hiperface2_clk_root */
    {kCLOCK_Osc24M,           kCLOCK_Osc32K,    kCLOCK_SysPll1Dfs1Div2, kCLOCK_EncoderPllDfs0},	/* hiperface2_sync_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* i3c2_slow_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c5_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c6_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c7_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpi2c8_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi5_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi6_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi7_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lpspi8_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* lptmr2_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart10_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart11_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart12_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart3_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart5_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart6_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart7_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart8_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_EncoderPllDfs0,               kCLOCK_Fro},	/* lpuart9_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1,        kCLOCK_AudioPll2,               kCLOCK_Ext},	/* sai2_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1,        kCLOCK_AudioPll2,               kCLOCK_Ext},	/* sai3_clk_root */
    {kCLOCK_Osc24M,        kCLOCK_AudioPll1,        kCLOCK_AudioPll2,               kCLOCK_Ext},	/* sai4_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* swo_trace_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,        kCLOCK_AudioPll1,               kCLOCK_Ext},	/* tpm4_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,        kCLOCK_AudioPll1,               kCLOCK_Ext},	/* tpm5_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,        kCLOCK_AudioPll1,               kCLOCK_Ext},	/* tpm6_clk_root */
    {kCLOCK_Osc24M,    kCLOCK_SysPll1Dfs0Div2,    kCLOCK_SysPll1Dfs1Div2,               kCLOCK_Fro},	/* usb_phy_burunin_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* usdhc1_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* usdhc2_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* usdhc3_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* v2x_pk_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* wakeup_axi_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* xspi_slv_root_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* xspi1_clk_root */
    {kCLOCK_Osc24M,         kCLOCK_SysPll1Dfs0,         kCLOCK_SysPll1Dfs1,         kCLOCK_SysPll1Dfs2},	/* xspi2_clk_root */
};

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

/*!
 * @brief Clock LPCG index (Clock Gating Channel)
 */
typedef enum _clock_lpcg
{
    kCLOCK_A55            = 0,
    kCLOCK_Cm33           = 1,
    kCLOCK_Arm_Trout      = 2,
    kCLOCK_Sentinel       = 3,
    kCLOCK_Sim_Wakeup     = 4,
    kCLOCK_Sim_Aon        = 5,
    kCLOCK_Sim_Mega       = 6,
    kCLOCK_Anadig         = 7,
    kCLOCK_Src            = 8,
    kCLOCK_Ccm            = 9,
    kCLOCK_Gpc            = 10,
    kCLOCK_Adc1           = 11,
    kCLOCK_Wdog1          = 12,
    kCLOCK_Wdog2          = 13,
    kCLOCK_Wdog3          = 14,
    kCLOCK_Wdog4          = 15,
    kCLOCK_Wdog5          = 16,
    kCLOCK_Sema1          = 17,
    kCLOCK_Sema2          = 18,
    kCLOCK_Mu_A           = 19,
    kCLOCK_Mu_B           = 20,
    kCLOCK_Edma1          = 21,
    kCLOCK_Edma2          = 22,
    kCLOCK_Romcp_A55      = 23,
    kCLOCK_Romcp_M33      = 24,
    kCLOCK_Flexspi1       = 25,
    kCLOCK_Aon_Trdc       = 26,
    kCLOCK_Wkup_Trdc      = 27,
    kCLOCK_Ocotp          = 28,
    kCLOCK_Bbsm_Hp        = 29,
    kCLOCK_Bbsm           = 30,
    kCLOCK_Cstrace        = 31,
    kCLOCK_Csswo          = 32,
    kCLOCK_Iomuxc         = 33,
    kCLOCK_Gpio1          = 34,
    kCLOCK_Gpio2          = 35,
    kCLOCK_Gpio3          = 36,
    kCLOCK_Gpio4          = 37,
    kCLOCK_Flexio1        = 38,
    kCLOCK_Flexio2        = 39,
    kCLOCK_Lpit1          = 40,
    kCLOCK_Lpit2          = 41,
    kCLOCK_Lptmr1         = 42,
    kCLOCK_Lptmr2         = 43,
    kCLOCK_Tpm1           = 44,
    kCLOCK_Tpm2           = 45,
    kCLOCK_Tpm3           = 46,
    kCLOCK_Tpm4           = 47,
    kCLOCK_Tpm5           = 48,
    kCLOCK_Tpm6           = 49,
    kCLOCK_Can1           = 50,
    kCLOCK_Can2           = 51,
    kCLOCK_Lpuart1        = 52,
    kCLOCK_Lpuart2        = 53,
    kCLOCK_Lpuart3        = 54,
    kCLOCK_Lpuart4        = 55,
    kCLOCK_Lpuart5        = 56,
    kCLOCK_Lpuart6        = 57,
    kCLOCK_Lpuart7        = 58,
    kCLOCK_Lpuart8        = 59,
    kCLOCK_Lpi2c1         = 60,
    kCLOCK_Lpi2c2         = 61,
    kCLOCK_Lpi2c3         = 62,
    kCLOCK_Lpi2c4         = 63,
    kCLOCK_Lpi2c5         = 64,
    kCLOCK_Lpi2c6         = 65,
    kCLOCK_Lpi2c7         = 66,
    kCLOCK_Lpi2c8         = 67,
    kCLOCK_Lpspi1         = 68,
    kCLOCK_Lpspi2         = 69,
    kCLOCK_Lpspi3         = 70,
    kCLOCK_Lpspi4         = 71,
    kCLOCK_Lpspi5         = 72,
    kCLOCK_Lpspi6         = 73,
    kCLOCK_Lpspi7         = 74,
    kCLOCK_Lpspi8         = 75,
    kCLOCK_I3c1           = 76,
    kCLOCK_I3c2           = 77,
    kCLOCK_Usdhc1         = 78,
    kCLOCK_Usdhc2         = 79,
    kCLOCK_Usdhc3         = 80,
    kCLOCK_Sai1           = 81,
    kCLOCK_Sai2           = 82,
    kCLOCK_Sai3           = 83,
    kCLOCK_Ssi_W2ao       = 84,
    kCLOCK_Ssi_Ao2w       = 85,
    kCLOCK_Mipi_Csi       = 86,
    kCLOCK_Mipi_Dsi       = 87,
    kCLOCK_Lvds           = 88,
    kCLOCK_Lcdif          = 89,
    kCLOCK_Pxp            = 90,
    kCLOCK_Isi            = 91,
    kCLOCK_Nic_Media      = 92,
    kCLOCK_Ddr_Dfi        = 93,
    kCLOCK_Ddr_Ctl        = 94,
    kCLOCK_Ddr_Dfi_Ctl    = 95,
    kCLOCK_Ddr_Ssi        = 96,
    kCLOCK_Ddr_Bypass     = 97,
    kCLOCK_Ddr_Apb        = 98,
    kCLOCK_Ddr_Drampll    = 99,
    kCLOCK_Ddr_Clk_Ctl    = 100,
    kCLOCK_Nic_Central    = 101,
    kCLOCK_Gic600         = 102,
    kCLOCK_Nic_Apb        = 103,
    kCLOCK_Usb_Controller = 104,
    kCLOCK_Usb_Test_60m   = 105,
    kCLOCK_Hsio_Trout_24m = 106,
    kCLOCK_Pdm            = 107,
    kCLOCK_Mqs1           = 108,
    kCLOCK_Mqs2           = 109,
    kCLOCK_Aud_Xcvr       = 110,
    kCLOCK_Nicmix_Mecc    = 111,
    kCLOCK_Spdif          = 112,
    kCLOCK_Ssi_Ml2nic     = 113,
    kCLOCK_Ssi_Med2nic    = 114,
    kCLOCK_Ssi_Hsio2nic   = 115,
    kCLOCK_Ssi_W2nic      = 116,
    kCLOCK_Ssi_Nic2w      = 117,
    kCLOCK_Ssi_Nic2ddr    = 118,
    kCLOCK_Hsio_32k       = 119,
    kCLOCK_Enet1          = 120,
    kCLOCK_Enet_Qos       = 121,
    kCLOCK_Sys_Cnt        = 122,
    kCLOCK_Tstmr1         = 123,
    kCLOCK_Tstmr2         = 124,
    kCLOCK_Tmc            = 125,
    kCLOCK_Pmro           = 126,
    kCLOCK_IpInvalid,
} clock_lpcg_t;

#define clock_ip_name_t clock_lpcg_t

/*! @brief Clock ip name array for EDMA. */
#define EDMA_CLOCKS                \
    {                              \
        kCLOCK_Edma1, kCLOCK_Edma2 \
    }

/*! @brief Clock ip name array for ADC. */
#define ADC_CLOCKS                \
    {                              \
        kCLOCK_Adc1 \
    }

/*
 * ! @brief Clock ip name array for MU.
 * clock of MU1_MUA, MU2_MUA is enabled by same LPCG42(Gate signal is clk_enable_mu_a)
 */
#define MU_CLOCKS                \
    {                            \
        kCLOCK_Mu_A, kCLOCK_Mu_A \
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
        kCLOCK_IpInvalid, kCLOCK_Lpit1, kCLOCK_Lpit2 \
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
        kCLOCK_Tpm1, kCLOCK_Tpm2, kCLOCK_Tpm3, kCLOCK_Tpm4, kCLOCK_Tpm5, kCLOCK_Tpm6, \
    }

/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS                                    \
    {                                                    \
        kCLOCK_Flexio1, kCLOCK_Flexio2 \
    }

/*! @brief Clock ip name array for FLEXSPI. */
#define FLEXSPI_CLOCKS                    \
    {                                     \
        kCLOCK_IpInvalid, kCLOCK_Flexspi1 \
    }

/*! @brief Clock ip name array for TMU. */
#define TMU_CLOCKS  \
    {               \
        kCLOCK_Tmc, \
    }

/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                              \
    {                                               \
        kCLOCK_IpInvalid, kCLOCK_Can1, kCLOCK_Can2, \
    }

/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                     \
    {                                                                                                     \
        kCLOCK_IpInvalid, kCLOCK_Lpuart1, kCLOCK_Lpuart2, kCLOCK_Lpuart3, kCLOCK_Lpuart4, kCLOCK_Lpuart5, \
            kCLOCK_Lpuart6, kCLOCK_Lpuart7, kCLOCK_Lpuart8                                                \
    }

/*! @brief Clock ip name array for SAI. */
#define SAI_CLOCKS                                               \
    {                                                            \
        kCLOCK_IpInvalid, kCLOCK_Sai1, kCLOCK_Sai2, kCLOCK_Sai3, \
    }

/*! @brief Clock ip name array for PDM. */
#define PDM_CLOCKS \
    {              \
        kCLOCK_Pdm \
    }

/*! @brief Clock ip name array for ENET QOS. */
#define ENETQOS_CLOCKS  \
    {                   \
        kCLOCK_Enet_Qos \
    }

/*! @brief Clock ip name array for ENET. */
#define ENET_CLOCKS  \
    {                \
        kCLOCK_Enet1 \
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

#endif
