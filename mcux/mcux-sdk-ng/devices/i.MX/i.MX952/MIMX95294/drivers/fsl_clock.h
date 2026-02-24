/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_
#include "fsl_common.h"
#include "scmi.h"
#include "scmi_clock.h"
#include "scmi_internal.h"

/*!
 * @brief CCM reg macros to map corresponding registers.
 */
#define CCM_REG_OFF(root, off) (*((volatile uint32_t *)((uintptr_t)(root) + (off))))
#define CCM_REG(root)          CCM_REG_OFF(root, 0U)

/* Definition for delay API in clock driver, users can redefine it to the real application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY \
    (800000000UL) /* When using Overdrive Voltage, the maximum frequency of cm7 is 800 MHz */
#endif

/*******************************************************************************
 * Clock Source Definitions
 ******************************************************************************/
#define CLOCK_NUM_SRC 41
/* kCLOCK_invalid */
#define CLOCK_PLATFORM_MAX_ID     (CLOCK_NUM_SRC + 130)

/*!
 * @brief Clock ID.
 */
typedef enum _clock_ip_name
{
    /* unify clock id for clock sources and ips */
    /* clock id for clock sources */
    kCLOCK_ext             = 0,  /* clock id for EXT_CLK */
    kCLOCK_osc32k          = 1,  /* clock id for OSC_32K_CLK */
    kCLOCK_osc24m          = 2,  /* clock id for OSC_24M_CLK */
    kCLOCK_fro             = 3,  /* clock id for FRO_CLK */
    kCLOCK_syspll1ctl      = 4,  /* clock id for SYS_PLL1_CTL */
    kCLOCK_syspll1dfs0ctl  = 5,  /* clock id for SYS_PLL1_DFS0_CTL */
    kCLOCK_syspll1dfs0     = 6,  /* clock id for SYS_PLL1_DFS0_CLK */
    kCLOCK_syspll1dfs0div2 = 7,  /* clock id for SYS_PLL1_DFS0_DIV2_CLK */
    kCLOCK_syspll1dfs1ctl  = 8,  /* clock id for SYS_PLL1_DFS1_CTL */
    kCLOCK_syspll1dfs1     = 9,  /* clock id for SYS_PLL1_DFS1_CLK */
    kCLOCK_syspll1dfs1div2 = 10, /* clock id for SYS_PLL1_DFS1_DIV2_CLK */
    kCLOCK_syspll1dfs2ctl  = 11, /* clock id for SYS_PLL1_DFS2_CTL */
    kCLOCK_syspll1dfs2     = 12, /* clock id for SYS_PLL1_DFS2_CLK */
    kCLOCK_syspll1dfs2div2 = 13, /* clock id for SYS_PLL1_DFS2_DIV2_CLK */
    kCLOCK_audiopll1ctl    = 14, /* clock id for AUDIO_PLL1_CTL */
    kCLOCK_audiopll1       = 15, /* clock id for AUDIO_PLL1_CLK */
    kCLOCK_audiopll2ctl    = 16, /* clock id for AUDIO_PLL2_CTL */
    kCLOCK_audiopll2       = 17, /* clock id for AUDIO_PLL2_CLK */
    kCLOCK_videopll1ctl    = 18, /* clock id for VIDEO_PLL1_CTL */
    kCLOCK_videopll1       = 19, /* clock id for VIDEO_PLL1_CLK */
    kCLOCK_reseverd20      = 20, /* clock id for reserved */
    kCLOCK_syspll1dfs3ctl  = 21, /* clock id for SYS_PLL1_DFS3_CTL */
    kCLOCK_syspll1dfs3     = 22, /* clock id for SYS_PLL1_DFS3_CLK */
    kCLOCK_syspll1dfs3div2 = 23, /* clock id for SYS_PLL1_DFS3_DIV2_CLK */
    kCLOCK_armpllctl       = 24, /* clock id for ARM_PLL_CTL */
    kCLOCK_armplldfs0ctl   = 25, /* clock id for ARM_PLL_DFS0_CTL */
    kCLOCK_armplldfs0      = 26, /* clock id for ARM_PLL_DFS0_CLK */
    kCLOCK_armplldfs1ctl   = 27, /* clock id for ARM_PLL_DFS1_CTL */
    kCLOCK_armplldfs1      = 28, /* clock id for ARM_PLL_DFS1_CLK */
    kCLOCK_armplldfs2ctl   = 29, /* clock id for ARM_PLL_DFS2_CTL */
    kCLOCK_armplldfs2      = 30, /* clock id for ARM_PLL_DFS2_CLK */
    kCLOCK_armplldfs3ctl   = 31, /* clock id for ARM_PLL_DFS3_CTL */
    kCLOCK_armplldfs3      = 32, /* clock id for ARM_PLL_DFS3_CLK */
    kCLOCK_drampllctl      = 33, /* clock id for DRAM_PLL_CTL */
    kCLOCK_drampll         = 34, /* clock id for DRAM_PLL_CLK */
    kCLOCK_hsiopllctl      = 35, /* clock id for HSIO_PLL_CTL */
    kCLOCK_hsiopll         = 36, /* clock id for HSIO_PLL_CLK */
    kCLOCK_ldbpllctl       = 37, /* clock id for LDB_PLL_CTL */
    kCLOCK_ldbpll          = 38, /* clock id for LDB_PLL_CLK */
    kCLOCK_extl            = 39, /* clock id for ext1(from components/imx_sm/devices/MIMX95/drivers/fsl_clock.h) */
    kCLOCK_ext2            = 40, /* clock id for ext2(from components/imx_sm/devices/MIMX95/drivers/fsl_clock.h) */

    /* clock id for ips */
    kCLOCK_adc              = CLOCK_NUM_SRC + 0,   /* clock id for Adc */
    kCLOCK_reserved1        = CLOCK_NUM_SRC + 1,   /* clock id for reserved1 */
    kCLOCK_busaon           = CLOCK_NUM_SRC + 2,   /* clock id for Bus Aon */
    kCLOCK_can1             = CLOCK_NUM_SRC + 3,   /* clock id for Can1 */
    kCLOCK_reserved4        = CLOCK_NUM_SRC + 4,   /* clock id for reserved4 */
    kCLOCK_i3c1Slow         = CLOCK_NUM_SRC + 5,   /* clock id for I3C1 Slow */
    kCLOCK_lpi2c1           = CLOCK_NUM_SRC + 6,   /* clock id for Lpi2C1 */
    kCLOCK_lpi2c2           = CLOCK_NUM_SRC + 7,   /* clock id for Lpi2C2 */
    kCLOCK_lpspi1           = CLOCK_NUM_SRC + 8,   /* clock id for Lpspi1 */
    kCLOCK_lpspi2           = CLOCK_NUM_SRC + 9,   /* clock id for Lpspi2 */
    kCLOCK_lptmr1           = CLOCK_NUM_SRC + 10,  /* clock id for Lptmr1 */
    kCLOCK_lpuart1          = CLOCK_NUM_SRC + 11,  /* clock id for Lpuart1 */
    kCLOCK_lpuart2          = CLOCK_NUM_SRC + 12,  /* clock id for Lpuart2 */
    kCLOCK_m33              = CLOCK_NUM_SRC + 13,  /* clock id for M33 */
    kCLOCK_m33systick       = CLOCK_NUM_SRC + 14,  /* clock id for M33 Systick */
    kCLOCK_reserved15       = CLOCK_NUM_SRC + 15,  /* clock id for reserved15 */
    kCLOCK_pdm              = CLOCK_NUM_SRC + 16,  /* clock id for Pdm */
    kCLOCK_sai1             = CLOCK_NUM_SRC + 17,  /* clock id for Sai1 */
    kCLOCK_reserved18       = CLOCK_NUM_SRC + 18,  /* clock id for reserved18 */
    kCLOCK_tpm2             = CLOCK_NUM_SRC + 19,  /* clock id for Tpm2 */
    kCLOCK_reserved20       = CLOCK_NUM_SRC + 20,  /* clock id for reserved20 */
    kCLOCK_camApb           = CLOCK_NUM_SRC + 21,  /* clock id for Cam Apb */
    kCLOCK_camAxi           = CLOCK_NUM_SRC + 22,  /* clock id for Cam Axi */
    kCLOCK_camCm0           = CLOCK_NUM_SRC + 23,  /* clock id for Cam Cm0 */
    kCLOCK_camIsi           = CLOCK_NUM_SRC + 24,  /* clock id for Cam Isi */
    kCLOCK_camPhyCfg        = CLOCK_NUM_SRC + 25,  /* clock id for Cam Phy Cfg */
    kCLOCK_mipiPhyPllBypass = CLOCK_NUM_SRC + 26,  /* clock id for Mipi Phy Pll Bypass */
    kCLOCK_reserved27       = CLOCK_NUM_SRC + 27,  /* clock id for reserved27 */
    kCLOCK_mipiTestByte     = CLOCK_NUM_SRC + 28,  /* clock id for Mipi Test Byte */
    kCLOCK_a55              = CLOCK_NUM_SRC + 29,  /* clock id for Arm A55 */
    kCLOCK_a55mtrbus        = CLOCK_NUM_SRC + 30,  /* clock id for Arm A55 Mtr Bus  */
    kCLOCK_a55periph        = CLOCK_NUM_SRC + 31,  /* clock id for Arm A55 Periph */
    kCLOCK_dramalt          = CLOCK_NUM_SRC + 32,  /* clock id for Dram Alt */
    kCLOCK_dramapb          = CLOCK_NUM_SRC + 33,  /* clock id for Dram Apb */
    kCLOCK_dispapb          = CLOCK_NUM_SRC + 34,  /* clock id for Disp Apb */
    kCLOCK_dispaxi          = CLOCK_NUM_SRC + 35,  /* clock id for Disp Axi */
    kCLOCK_displpspi        = CLOCK_NUM_SRC + 36,  /* clock id for Disp Lpspi */
    kCLOCK_dispocram        = CLOCK_NUM_SRC + 37,  /* clock id for Disp Ocram */
    kCLOCK_disphycfg        = CLOCK_NUM_SRC + 38,  /* clock id for Disp Phy CFG */
    kCLOCK_disp1pix         = CLOCK_NUM_SRC + 39,  /* clock id for Disp1 Pix */
    kCLOCK_dispcdphyapb     = CLOCK_NUM_SRC + 40,  /* clock id for Disp CD Phy Apb */
    kCLOCK_reserved41       = CLOCK_NUM_SRC + 41,  /* clock id for reserved41 */
    kCLOCK_gpuapb           = CLOCK_NUM_SRC + 42,  /* clock id for Gpu Apb */
    kCLOCK_gpu              = CLOCK_NUM_SRC + 43,  /* clock id for Gpu */
    kCLOCK_hsioacscan480m   = CLOCK_NUM_SRC + 44,  /* clock id for Hsio Acscan 480M */
    kCLOCK_hsioacscan80m    = CLOCK_NUM_SRC + 45,  /* clock id for Hsio Acscan 80M */
    kCLOCK_hsio             = CLOCK_NUM_SRC + 46,  /* clock id for Hsio */
    kCLOCK_hsiopcieaux      = CLOCK_NUM_SRC + 47,  /* clock id for Hsio Pcie Aux */
    kCLOCK_hsiopcietest160m = CLOCK_NUM_SRC + 48,  /* clock id for Hsio Pcie Test 160M */
    kCLOCK_hsiopcieTest400m = CLOCK_NUM_SRC + 49,  /* clock id for Hsio Pcie Test 400M */
    kCLOCK_hsiopcieTest500m = CLOCK_NUM_SRC + 50,  /* clock id for Hsio Pcie Test 500M */
    kCLOCK_hsiousbTest50m   = CLOCK_NUM_SRC + 51,  /* clock id for Hsio Usb Test 50M */
    kCLOCK_hsiousbTest60m   = CLOCK_NUM_SRC + 52,  /* clock id for Hsio Usb Test 60M */
    kCLOCK_busm7            = CLOCK_NUM_SRC + 53,  /* clock id for Bus M7 */
    kCLOCK_m7               = CLOCK_NUM_SRC + 54,  /* clock id for M7 */
    kCLOCK_m7systick        = CLOCK_NUM_SRC + 55,  /* clock id for M7 Systick */
    kCLOCK_busnetcmix       = CLOCK_NUM_SRC + 56,  /* clock id for Bus Netcmix */
    kCLOCK_enet             = CLOCK_NUM_SRC + 57,  /* clock id for Enet */
    kCLOCK_enetphytest200m  = CLOCK_NUM_SRC + 58,  /* clock id for Enet Phy Test 200M */
    kCLOCK_enetphytest500m  = CLOCK_NUM_SRC + 59,  /* clock id for Enet Phy Test 500M */
    kCLOCK_enetphytest667m  = CLOCK_NUM_SRC + 60,  /* clock id for Enet Phy Test 667M */
    kCLOCK_enetref          = CLOCK_NUM_SRC + 61,  /* clock id for Enet Ref */
    kCLOCK_enettimer1       = CLOCK_NUM_SRC + 62,  /* clock id for Enet Timer1 */
    kCLOCK_reserved63       = CLOCK_NUM_SRC + 63,  /* clock id for reserved63 */
    kCLOCK_sai2             = CLOCK_NUM_SRC + 64,  /* clock id for Sai2 */
    kCLOCK_nocapb           = CLOCK_NUM_SRC + 65,  /* clock id for Noc Apb */
    kCLOCK_noc              = CLOCK_NUM_SRC + 66,  /* clock id for Noc */
    kCLOCK_npuapb           = CLOCK_NUM_SRC + 67,  /* clock id for Npu Apb */
    kCLOCK_npu              = CLOCK_NUM_SRC + 68,  /* clock id for Npu */
    kCLOCK_ccmcko1          = CLOCK_NUM_SRC + 69,  /* clock id for Ccm Cko1 */
    kCLOCK_ccmcko2          = CLOCK_NUM_SRC + 70,  /* clock id for Ccm Cko2 */
    kCLOCK_ccmcko3          = CLOCK_NUM_SRC + 71,  /* clock id for Ccm Cko3 */
    kCLOCK_ccmcko4          = CLOCK_NUM_SRC + 72,  /* clock id for Ccm Cko4 */
    kCLOCK_vpuapb           = CLOCK_NUM_SRC + 73,  /* clock id for Vpu Apb */
    kCLOCK_vpu              = CLOCK_NUM_SRC + 74,  /* clock id for Vpu */
    kCLOCK_reserved75       = CLOCK_NUM_SRC + 75,  /* clock id for reserved75 */
    kCLOCK_reserved76       = CLOCK_NUM_SRC + 76,  /* clock id for reserved76 */
    kCLOCK_audioxcvr        = CLOCK_NUM_SRC + 77,  /* clock id for Audio Xcvr */
    kCLOCK_buswakeup        = CLOCK_NUM_SRC + 78,  /* clock id for Bus Wakeup */
    kCLOCK_can2             = CLOCK_NUM_SRC + 79,  /* clock id for Can2 */
    kCLOCK_can3             = CLOCK_NUM_SRC + 80,  /* clock id for Can3 */
    kCLOCK_can4             = CLOCK_NUM_SRC + 81,  /* clock id for Can4 */
    kCLOCK_can5             = CLOCK_NUM_SRC + 82,  /* clock id for Can5 */
    kCLOCK_flexio1          = CLOCK_NUM_SRC + 83,  /* clock id for Flexio1 */
    kCLOCK_flexio2          = CLOCK_NUM_SRC + 84,  /* clock id for Flexio2 */
    kCLOCK_xspi1            = CLOCK_NUM_SRC + 85,  /* clock id for xspi1 */
    kCLOCK_reserved86       = CLOCK_NUM_SRC + 86,  /* clock id for reserved86 */
    kCLOCK_i3c2slow         = CLOCK_NUM_SRC + 87,  /* clock id for I3C2 Slow */
    kCLOCK_lpi2c3           = CLOCK_NUM_SRC + 88,  /* clock id for Lpi2C3 */
    kCLOCK_lpi2c4           = CLOCK_NUM_SRC + 89,  /* clock id for Lpi2C4 */
    kCLOCK_lpi2c5           = CLOCK_NUM_SRC + 90,  /* clock id for Lpi2C5 */
    kCLOCK_lpi2c6           = CLOCK_NUM_SRC + 91,  /* clock id for Lpi2C6 */
    kCLOCK_lpi2c7           = CLOCK_NUM_SRC + 92,  /* clock id for Lpi2C7 */
    kCLOCK_lpi2c8           = CLOCK_NUM_SRC + 93,  /* clock id for Lpi2C8 */
    kCLOCK_lpspi3           = CLOCK_NUM_SRC + 94,  /* clock id for Lpspi3 */
    kCLOCK_lpspi4           = CLOCK_NUM_SRC + 95,  /* clock id for Lpspi4 */
    kCLOCK_lpspi5           = CLOCK_NUM_SRC + 96,  /* clock id for Lpspi5 */
    kCLOCK_lpspi6           = CLOCK_NUM_SRC + 97,  /* clock id for Lpspi6 */
    kCLOCK_lpspi7           = CLOCK_NUM_SRC + 98,  /* clock id for Lpspi7 */
    kCLOCK_lpspi8           = CLOCK_NUM_SRC + 99,  /* clock id for Lpspi8 */
    kCLOCK_lptmr2           = CLOCK_NUM_SRC + 100, /* clock id for Lptmr2 */
    kCLOCK_lpuart3          = CLOCK_NUM_SRC + 101, /* clock id for Lpuart3 */
    kCLOCK_lpuart4          = CLOCK_NUM_SRC + 102, /* clock id for Lpuart4 */
    kCLOCK_lpuart5          = CLOCK_NUM_SRC + 103, /* clock id for Lpuart5 */
    kCLOCK_lpuart6          = CLOCK_NUM_SRC + 104, /* clock id for Lpuart6 */
    kCLOCK_lpuart7          = CLOCK_NUM_SRC + 105, /* clock id for Lpuart7 */
    kCLOCK_lpuart8          = CLOCK_NUM_SRC + 106, /* clock id for Lpuart8 */
    kCLOCK_sai3             = CLOCK_NUM_SRC + 107, /* clock id for Sai3 */
    kCLOCK_sai4             = CLOCK_NUM_SRC + 108, /* clock id for Sai4 */
    kCLOCK_sai5             = CLOCK_NUM_SRC + 109, /* clock id for Sai5 */
    kCLOCK_spdif            = CLOCK_NUM_SRC + 110, /* clock id for Spdif */
    kCLOCK_swotrace         = CLOCK_NUM_SRC + 111, /* clock id for Swo Trace */
    kCLOCK_tpm4             = CLOCK_NUM_SRC + 112, /* clock id for Tpm4 */
    kCLOCK_tpm5             = CLOCK_NUM_SRC + 113, /* clock id for Tpm5 */
    kCLOCK_tpm6             = CLOCK_NUM_SRC + 114, /* clock id for Tpm6 */
    kCLOCK_mipiphydft400    = CLOCK_NUM_SRC + 115, /* clock id for MIPI Phy Dft 400*/
    kCLOCK_mipiphydft540    = CLOCK_NUM_SRC + 116, /* clock id for MIPI Phy Dft 540 */
    kCLOCK_usdhc1           = CLOCK_NUM_SRC + 117, /* clock id for Usdhc1 */
    kCLOCK_usdhc2           = CLOCK_NUM_SRC + 118, /* clock id for Usdhc2 */
    kCLOCK_usdhc3           = CLOCK_NUM_SRC + 119, /* clock id for Usdhc3 */
    kCLOCK_v2xpk            = CLOCK_NUM_SRC + 120, /* clock id for V2X Pk */
    kCLOCK_wakeupaxi        = CLOCK_NUM_SRC + 121, /* clock id for Wakeup Axi */
    kCLOCK_xspislvroot      = CLOCK_NUM_SRC + 122, /* clock id for Xspi Slv Root */
    kCLOCK_audmix1          = CLOCK_NUM_SRC + 123, /* clock id for audmix1*/
    kCLOCK_asrc1            = CLOCK_NUM_SRC + 124, /* clock id for asrc1 Root */
    kCLOCK_asrc2            = CLOCK_NUM_SRC + 125, /* clock id for asrc2 Root */
    kCLOCK_gpt2             = CLOCK_NUM_SRC + 126, /* clock id for gpt2 Root */
    kCLOCK_gpt3             = CLOCK_NUM_SRC + 127, /* clock id for gpt3 Root */
    kCLOCK_gpt4             = CLOCK_NUM_SRC + 128, /* clock id for gpt4 Root */
    kCLOCK_gpt5             = CLOCK_NUM_SRC + 129, /* clock id for gpt5 Root */
    kCLOCK_invalid          = CLOCK_NUM_SRC + 130,
} clock_ip_name_t;

typedef struct _clk
{
    clock_ip_name_t clkId; /* clock device id */
    clock_ip_name_t pclkId; /* parent clock device id */
    uint32_t clkRoundOpt; /* clock round options */
    uint64_t rate; /* clock rate */
} clk_t;

/*******************************************************************************
 * Clock Gate Definitions
 ******************************************************************************/

/*! @brief Clock ip name array for ADC. */
#define ADC_CLOCKS                \
    {                              \
        kCLOCK_adc \
    }

/*
 * ! @brief Clock ip name array for MU.
 * clock of MU1_MUA, MU2_MUA is enabled by same LPCG42(Gate signal is clk_enable_mu_a)
 */
/*#define MU_CLOCKS                \
    {                            \
        kCLOCK_Mu_A, kCLOCK_Mu_A \
    }
*/
/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                                                                                                \
    {                                                                                                               \
        kCLOCK_invalid, kCLOCK_lpi2c1, kCLOCK_lpi2c2, kCLOCK_lpi2c3, kCLOCK_lpi2c4, kCLOCK_lpi2c5, kCLOCK_lpi2c6, \
            kCLOCK_lpi2c7, kCLOCK_lpi2c8                                                                          \
    }

/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                                                                                \
    {                                                                                                               \
        kCLOCK_invalid, kCLOCK_lpspi1, kCLOCK_lpspi2, kCLOCK_lpspi3, kCLOCK_lpspi4, kCLOCK_lpspi5, kCLOCK_lpspi6, \
            kCLOCK_lpspi7, kCLOCK_lpspi8                                                                            \
    }

/*! @brief Clock ip name array for TPM. */
#define TPM_CLOCKS                                                                    \
    {                                                                                 \
        kCLOCK_tpm1, kCLOCK_tpm2, kCLOCK_tpm3, kCLOCK_tpm4, kCLOCK_tpm5, kCLOCK_tpm6, \
    }

/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS                                    \
    {                                                    \
        kCLOCK_flexio1, kCLOCK_flexio2 \
    }

/*! @brief Clock ip name array for FLEXSPI. */
#define FLEXSPI_CLOCKS                    \
    {                                     \
        kCLOCK_invalid, kCLOCK_flexspi1 \
    }

/*! @brief Clock ip name array for TMU. */
#define TMU_CLOCKS  \
    {               \
        kCLOCK_tmu, \
    }

/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                              \
    {                                               \
        kCLOCK_invalid, kCLOCK_can1, kCLOCK_can2, kCLOCK_can3, kCLOCK_can4, kCLOCK_can5, \
    }

/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                     \
    {                                                                                                     \
        kCLOCK_invalid, kCLOCK_lpuart1, kCLOCK_lpuart2, kCLOCK_lpuart3, kCLOCK_lpuart4, kCLOCK_lpuart5, \
            kCLOCK_lpuart6, kCLOCK_lpuart7, kCLOCK_lpuart8                                       \
    }

/*! @brief Clock ip name array for SAI. */
#define SAI_CLOCKS                                               \
    {                                                            \
        kCLOCK_invalid, kCLOCK_sai1, kCLOCK_sai2, kCLOCK_sai3, kCLOCK_sai4, kCLOCK_sai5, \
    }

/*! @brief Clock ip name array for PDM. */
#define PDM_CLOCKS \
    {              \
        kCLOCK_pdm \
    }

/*! @brief Clock ip name array for ENET. */
#define ENET_CLOCKS  \
    {                \
        kCLOCK_enet \
    }

/*! @brief Clock ip name array for I3C. */
#define I3C_CLOCKS                                 \
    {                                              \
        kCLOCK_invalid, kCLOCK_i3c1, kCLOCK_i3c2 \
    }

/*******************************************************************************
 * Clock Root APIs
 ******************************************************************************/
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
