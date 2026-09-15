/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_clock.h"
#include "PERI_CCM.h"
#include "PERI_CGUANA.h"
#include "fsl_modcon.h"
#include "PERI_MODCON.h"
#include "fsl_reset.h"
#if defined(CLOCK_ENABLE_INFO_DUMP) && CLOCK_ENABLE_INFO_DUMP
#include "fsl_debug_console.h"
#endif
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.clock"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* To make full use of CM7 hardware FPU, use double instead of uint64_t in clock driver to
achieve better performance, it is depend on the IDE Floating point settings, if double precision is selected
in IDE, clock_64b_t will switch to double type automatically. only support IAR and MDK here */
#if __FPU_USED

#if (defined(__ICCARM__))

#if (__ARMVFP__ >= __ARMFPV5__) && \
    (__ARM_FP == 0xE) /*0xe implies support for half, single and double precision operations*/
typedef double clock_64b_t;
#else
typedef uint64_t clock_64b_t;
#endif

#elif (defined(__GNUC__))

#if (__ARM_FP == 0xE) /*0xe implies support for half, single and double precision operations*/
typedef double clock_64b_t;
#else
typedef uint64_t clock_64b_t;
#endif

#elif defined(__CC_ARM) || defined(__ARMCC_VERSION)

#if defined __TARGET_FPU_FPV5_D16
typedef double clock_64b_t;
#else
typedef uint64_t clock_64b_t;
#endif

#else
typedef uint64_t clock_64b_t;
#endif

#else
typedef uint64_t clock_64b_t;
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
const clock_name_t s_clockSourceNameCGU[][4] = {
    /*SRC0,                        SRC1,                        SRC2,                       SRC3,                           index      name   */ \
    { kCLOCK_SRC_OSC_24M,          kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 0 SXOSC */ \
    { kCLOCK_SRC_FRO_192M,         kCLOCK_SRC_OSC_24M,          kCLOCK_SRC_LPOSC_12M_CORE,  kCLOCK_SRC_LPOSC_1M_CORE },  /* CGU ROOT 1 BASE */ \
    { kCLOCK_SRC_FRO_24M,          kCLOCK_SRC_OSC_24M,          kCLOCK_SRC_LPOSC_12M_CORE,  kCLOCK_SRC_LPOSC_1M_CORE },  /* CGU ROOT 2 LOW */ \
    { kCLOCK_SRC_MAINPLL_DIV4,     kCLOCK_SRC_MAINPLL_DIV5,     kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 3 MAINPLL_DIVX */ \
    { kCLOCK_SRC_SYSPLL_DIV4,      kCLOCK_SRC_SYSPLL_DIV5,      kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 4 SYSPLL_DIVX */ \
    { kCLOCK_SRC_MAINPLL_DIVOUT1,  kCLOCK_SRC_MAINPLL_DIVOUT2,  kCLOCK_SRC_SYSPLL_DIVOUT1,  kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 5 PLL_PFDX */ \
    { kCLOCK_SRC_MAINPLL_DIVOUT1,  kCLOCK_SRC_MAINPLL_DIVOUT2,  kCLOCK_SRC_SYSPLL_DIVOUT1,  kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 6 MEDIA_PFDX */ \
    { kCLOCK_SRC_COREPLL_OUT,      kCLOCK_SRC_MAINPLL_DIVOUT2,  kCLOCK_SRC_SYSPLL_DIVOUT1,  kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 7 MAINPFDX */ \
    { kCLOCK_SRC_COREPLL_OUT,      kCLOCK_SRC_MAINPLL_DIVOUT2,  kCLOCK_SRC_SYSPLL_DIVOUT1,  kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 8 COMMPFDX */ \
    { kCLOCK_SRC_MAINPLL_DIV4,     kCLOCK_SRC_MAINPLL_DIV5,     kCLOCK_SRC_SYSPLL_DIV4,     kCLOCK_SRC_SYSPLL_DIV5 },    /* CGU ROOT 9 MAINDIVX */ \
    { kCLOCK_SRC_SAI0_MCLK,        kCLOCK_SRC_SAI1_MCLK,        kCLOCK_SRC_SAI2_MCLK,       kCLOCK_SRC_LPOSC_12M_CORE }, /* CGU ROOT 10 SAIMCLK */ \
    { kCLOCK_SRC_SAI0_MCLK,        kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 11 SAIMCLK0 */ \
    { kCLOCK_SRC_SAI1_MCLK,        kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 12 SAIMCLK1 */ \
    { kCLOCK_SRC_SAI2_MCLK,        kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 13 SAIMCLK2 */ \
    { kCLOCK_SRC_LPOSC_12M_CORE,   kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 14 LP12M_CORE */ \
    { kCLOCK_SRC_LPOSC_1M_CORE,    kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 15 LP1M_CORE */ \
    { kCLOCK_SRC_LPOSC32K,         kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 16 ULP32K */ \
    { kCLOCK_SRC_FRO_192M,         kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 17 FRO192M */ \
    { kCLOCK_SRC_FRO_96M,          kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 18 FRO96M */ \
    { kCLOCK_SRC_FRO_48M,          kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 19 FRO48M */ \
    { kCLOCK_SRC_FRO_24M,          kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 20 FRO24M */ \
    { kCLOCK_SRC_SYSPLL_DIV4,      kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 21 SYSPLLDIV4 */ \
    { kCLOCK_SRC_SYSPLL_DIV5,      kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 22 SYSPLLDIV5 */ \
    { kCLOCK_SRC_SYSPLL_DIV4,      kCLOCK_SRC_SYSPLL_DIV5,      kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 23 SYSPLLDIVX */ \
    { kCLOCK_SRC_MAINPLL_DIV4,     kCLOCK_SRC_MAINPLL_DIV5,     kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 24 MAINPLLDIVX */ \
    { kCLOCK_SRC_MAINPLL_DIV8,     kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 25 MAINPLLDIV8 */ \
    { kCLOCK_SRC_MAINPLL_DIV10,    kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 26 MAINPLLDIV10 */ \
    { kCLOCK_SRC_MAINPLL_DIV20,    kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 27 MAINPLLDIV20 */ \
    { kCLOCK_SRC_AUDIOPLL_DIVOUT,  kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 28 AUDIOPLL */ \
    { kCLOCK_SRC_VIDEOPLL_DIVOUT,  kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 29 VIDEOPLL */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_COREPLL_OUT,      kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_PLL_PFDX },       /* CGU ROOT 30 MAIN (renamed from CPU) */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_COREPLL_OUT,      kCLOCK_SRC_MAINPLL_DIVOUT1, kCLOCK_SRC_PLL_PFDX },       /* CGU ROOT 31 NPU */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_COREPLL_OUT,      kCLOCK_SRC_SYSPLL_DIVOUT2,  kCLOCK_SRC_PLL_PFDX },       /* CGU ROOT 32 MEDIABUS */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_SYSPLL_DIVOUT2,   kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVX },    /* CGU ROOT 33 AUDIOBUS */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_SYSPLL_DIVOUT2,   kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVX },    /* CGU ROOT 34 COMMBUS */ \
    { kCLOCK_SRC_LOW,              kCLOCK_SRC_FRO_192M,         kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 35 WAKEBUS */ \
    { kCLOCK_SRC_LOW,              kCLOCK_SRC_FRO_48M,          kCLOCK_SRC_MAINPLL_DIV10,   kCLOCK_SRC_SYSPLL_DIV10 },   /* CGU ROOT 36 SYSCON_PDMAIN */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT0,  kCLOCK_SRC_SYSPLL_DIVOUT0,  kCLOCK_SRC_SYSPLL_DIVOUT1 }, /* CGU ROOT 37 PERI0 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT1,  kCLOCK_SRC_SYSPLL_DIVOUT0,  kCLOCK_SRC_SYSPLL_DIVOUT1 }, /* CGU ROOT 38 PERI1 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT2,  kCLOCK_SRC_SYSPLL_DIVOUT0,  kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 39 PERI2 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT2,  kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 40 PERI3 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT0,  kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 41 PERI4 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT0,  kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 42 PERI5 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIVOUT1,  kCLOCK_SRC_MAINPLL_DIVX,    kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 43 PERI6 */ \
    { kCLOCK_SRC_LOW,              kCLOCK_SRC_FRO_192M,         kCLOCK_SRC_MAINPLL_DIVOUT2, kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 44 PERI7 */ \
    { kCLOCK_SRC_LOW,              kCLOCK_SRC_AUDIOPLL_DIVOUT,  kCLOCK_SRC_VIDEOPLL_DIVOUT, kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 45 AUDIO */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_AUDIOPLL_DIVOUT,  kCLOCK_SRC_VIDEOPLL_DIVOUT, kCLOCK_SRC_MEDIA_PFDX },     /* CGU ROOT 46 VIDEO */ \
    { kCLOCK_SRC_FRO_48M,          kCLOCK_SRC_MAINPLL_DIVOUT1,  kCLOCK_SRC_MAINPLL_DIVOUT2, kCLOCK_SRC_SYSPLL_DIVOUT2 }, /* CGU ROOT 47 USB1 */ \
    { kCLOCK_SRC_BASE,             kCLOCK_SRC_MAINPLL_DIV8,     kCLOCK_SRC_MAINPLL_DIV20,   kCLOCK_SRC_SYSPLL_DIV20 },   /* CGU ROOT 48 ETH */ \
    { kCLOCK_SRC_TIE_LOW,          kCLOCK_SRC_COREPLL_OUT,      kCLOCK_SRC_MAINPLL_DIVOUT0, kCLOCK_SRC_SYSPLL_DIVOUT0 }, /* CGU ROOT 49 TEST */
#if 0
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,            kCLOCK_SRC_FRO192M,         kCLOCK_SRC_MAINPLLDIV10 },   /* CGU ROOT 50 CLKOUT */
    { kCLOCK_SRC_FRO192M,          kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 51 MAIN_FRO192M */
    { kCLOCK_SRC_ULP32K,           kCLOCK_SRC_Invalid,          kCLOCK_SRC_Invalid,         kCLOCK_SRC_Invalid },        /* CGU ROOT 52 MAIN_ULP32K */
#endif
};

const clock_name_t s_clockSourceNameCMPT[][4] = {
    /*SRC0,                  SRC1,                SRC2,               SRC3,                         index      name   */ \
    { kCLOCK_SRC_MAIN,       kCLOCK_SRC_Invalid,  kCLOCK_SRC_Invalid, kCLOCK_SRC_Invalid },      /* CMPT ROOT 0 CMPT */ \
    { kCLOCK_SRC_CPU,        kCLOCK_SRC_Invalid,  kCLOCK_SRC_Invalid, kCLOCK_SRC_Invalid },      /* CMPT ROOT 1 CPU */ \
    { kCLOCK_SRC_NPU,        kCLOCK_SRC_Invalid,  kCLOCK_SRC_Invalid, kCLOCK_SRC_Invalid },      /* CMPT ROOT 2 NPU */ \
    { kCLOCK_SRC_LP1M_CORE,  kCLOCK_SRC_SXOSC,    kCLOCK_SRC_PERI4,   kCLOCK_SRC_MAINPLLDIV10 }, /* CMPT ROOT 3 SYSTICK0 */ \
    { kCLOCK_SRC_LP1M_CORE,  kCLOCK_SRC_SXOSC,    kCLOCK_SRC_PERI4,   kCLOCK_SRC_MAINPLLDIV10 }, /* CMPT ROOT 4 SYSTICK1 */ \
};

const clock_name_t s_clockSourceNameMAIN[][4] = {
    /*SRC0,                        SRC1,                      SRC2,                  SRC3,                         index      name   */ \
    { kCLOCK_SRC_MAIN,             kCLOCK_SRC_TIE_LOW,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },      /* MAIN ROOT 0 MAIN */ \
    { kCLOCK_SRC_MAIN_PERI0_DIV2,  kCLOCK_SRC_MAINPFDX_DIV2,  kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },   /* MAIN ROOT 1 XSPI0 */ \
    { kCLOCK_SRC_MAIN_PERI1_DIV2,  kCLOCK_SRC_MAINPFDX_DIV2,  kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },   /* MAIN ROOT 2 XSPI1 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 3 I3C0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 4 LPI2C0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 5 LPI2C1 */ \
    { kCLOCK_SRC_PERI2,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 6 LPSPI0 */ \
    { kCLOCK_SRC_PERI2,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 7 LPSPI1 */ \
    { kCLOCK_SRC_PERI2,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 8 LPSPI2 */ \
    { kCLOCK_SRC_PERI2,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 9 LPSPI3 */ \
    { kCLOCK_SRC_PERI2,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 10 LPSPI4 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 11 LPUART0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 12 LPUART1 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 13 LPUART2 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 14 LPUART3 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 15 LPUART4 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 16 LPUART5 */ \
    { kCLOCK_SRC_PERI1,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 17 FLEXCAN0 */ \
    { kCLOCK_SRC_PERI1,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 18 FLEXCAN1 */ \
    { kCLOCK_SRC_PERI1,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 19 FLEXCAN2 */ \
    { kCLOCK_SRC_PERI1,            kCLOCK_SRC_PERI4,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 20 FLEXCAN_GFCLK */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_SXOSC },        /* MAIN ROOT 21 QTPM0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 22 LPIT0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 23 LPIT1 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 24 ADC0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 25 ADC1 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 26 SINC0 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 27 SINC1 */ \
    { kCLOCK_SRC_PERI0,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 28 FLEXIO0 */ \
    { kCLOCK_SRC_PERI0,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 29 FLEXIO1 */ \
    { kCLOCK_SRC_PERI0,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 30 FLEXIO2 */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_SYSPLLDIV4,     kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINDIVX },     /* MAIN ROOT 31 TPIU */ \
    { kCLOCK_SRC_FRO96M,           kCLOCK_SRC_MAINPLLDIV10,   kCLOCK_SRC_TIE_LOW,    kCLOCK_SRC_Invalid },      /* MAIN ROOT 32 CSSI_REFCLK */ \
    { kCLOCK_SRC_SXOSC,            kCLOCK_SRC_MAINPLLDIV10,   kCLOCK_SRC_FRO192M,    kCLOCK_SRC_FRO24M },       /* MAIN ROOT 33 OTP */ \
    { kCLOCK_SRC_PERI3,            kCLOCK_SRC_PERI5,          kCLOCK_SRC_FRO192M,    kCLOCK_SRC_MAINPLLDIV10 }, /* MAIN ROOT 34 CLKOUT */ \
    { kCLOCK_SRC_FRO192M,          kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },      /* MAIN ROOT 35 MAIN_FRO192M */ \
    { kCLOCK_SRC_ULP32K,           kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },      /* MAIN ROOT 36 MAIN_ULP32K */ \
};

const clock_name_t s_clockSourceNameWAKE[][4] = {
    /*SRC0,                   SRC1,                   SRC2,                  SRC3,                      index      name   */ \
    { kCLOCK_SRC_WAKEBUS,     kCLOCK_SRC_LP12M_WAKE,  kCLOCK_SRC_LP2M_WAKE,  kCLOCK_SRC_Invalid },   /* WAKE ROOT 0 WAKE */ \
    { kCLOCK_SRC_SXOSC,       kCLOCK_SRC_Invalid,     kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 1 WAKE_SXOSC */ \
    { kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_Invalid,     kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 2 WAKE_LP1M */ \
    { kCLOCK_SRC_LP12M_WAKE,  kCLOCK_SRC_Invalid,     kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 3 WAKE_LP12M */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_Invalid,     kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 4 WAKE_ULP32K */ \
    { kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_LP12M_WAKE,  kCLOCK_SRC_LP2M_WAKE,  kCLOCK_SRC_Invalid },   /* WAKE ROOT 5 WAKE_LPCLK */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 6 I3C1 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 7 LPI2C2 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 8 LPI2C3 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 9 LPSPI0 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_ULP32K },    /* WAKE ROOT 10 LPUART0 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_ULP32K },    /* WAKE ROOT 11 LPUART1 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_AUDIO,       kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SAIMCLK },   /* WAKE ROOT 12 DMIC1_APPCLK */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_AUDIO,       kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_ULP32K },    /* WAKE ROOT 13 QTPM0 */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 14 LPTMR0 */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 15 LPTMR1 */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_TIE_LOW,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 16 SWT0 */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_TIE_LOW,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 17 SWT1 */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_LP1M_WAKE,   kCLOCK_SRC_TIE_LOW,    kCLOCK_SRC_Invalid },   /* WAKE ROOT 18 EWM */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 19 ACMP0 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 20 ACMP1 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 21 ACMP2 */ \
    { kCLOCK_SRC_PERI7,       kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_SXOSC },     /* WAKE ROOT 22 ACMP3 */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_LP1M_WAKE }, /* WAKE ROOT 23 ACMP0_RRCLK */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_LP1M_WAKE }, /* WAKE ROOT 24 ACMP1_RRCLK */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_LP1M_WAKE }, /* WAKE ROOT 25 ACMP2_RRCLK */ \
    { kCLOCK_SRC_ULP32K,      kCLOCK_SRC_FRO24M,      kCLOCK_SRC_WAKE_LPCLK, kCLOCK_SRC_LP1M_WAKE }, /* WAKE ROOT 26 ACMP3_RRCLK */ \
};

const clock_name_t s_clockSourceNameCOMM[][4] = {
    /*SRC0,                        SRC1,                      SRC2,                  SRC3,                        index      name   */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },     /* COMM ROOT 0 COMM */ \
    { kCLOCK_SRC_ULP32K,           kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },     /* COMM ROOT 1 COMM_ULP32K */ \
    { kCLOCK_SRC_COMM_PERI1_DIV2,  kCLOCK_SRC_COMMPFDX_DIV2,  kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },  /* COMM ROOT 2 USDHC0 */ \
    { kCLOCK_SRC_COMM_PERI2_DIV2,  kCLOCK_SRC_COMMPFDX_DIV2,  kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },  /* COMM ROOT 3 USDHC1 */ \
    { kCLOCK_SRC_PERI1,            kCLOCK_SRC_PERI2,          kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },  /* COMM ROOT 4 XSPIR */ \
    { kCLOCK_SRC_SXOSC,            kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },     /* COMM ROOT 5 USB0_PHYCLK */ \
    { kCLOCK_SRC_FRO48M,           kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },     /* COMM ROOT 6 USB0_FRO48M */ \
    { kCLOCK_SRC_USB1,             kCLOCK_SRC_USBPLL_OUT,     kCLOCK_SRC_USBPLL_48M, kCLOCK_SRC_FRO48M },      /* COMM ROOT 7 USB1 */ \
    { kCLOCK_SRC_ULP32K,           kCLOCK_SRC_LP1M_CORE,      kCLOCK_SRC_SXOSC,      kCLOCK_SRC_TIE_LOW },     /* COMM ROOT 8 USB0_WAKECLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_ETH,            kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_MAINPLLDIV8 }, /* COMM ROOT 9 ETH0_TRXCLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_ETH,            kCLOCK_SRC_SXOSC,      kCLOCK_SRC_MAINPLLDIV8 }, /* COMM ROOT 10 ETH0_TIMERCLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_ETH,            kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_MAINPLLDIV8 }, /* COMM ROOT 11 ETH1_TRXCLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_ETH,            kCLOCK_SRC_SXOSC,      kCLOCK_SRC_MAINPLLDIV8 }, /* COMM ROOT 12 ETH1_TIMERCLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_ETH,            kCLOCK_SRC_SXOSC,      kCLOCK_SRC_MAINPLLDIV8 }, /* COMM ROOT 13 ETH_REFCLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_MAINPLLDIV10,   kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },  /* COMM ROOT 14 XENO0_LIWCLK */ \
    { kCLOCK_SRC_COMMBUS,          kCLOCK_SRC_MAINPLLDIV10,   kCLOCK_SRC_SYSPLLDIV4, kCLOCK_SRC_SYSPLLDIV5 },  /* COMM ROOT 15 XENO1_LIWCLK */ \
    { kCLOCK_SRC_MAINPLLDIV10,     kCLOCK_SRC_Invalid,        kCLOCK_SRC_Invalid,    kCLOCK_SRC_Invalid },     /* COMM ROOT 16 DLL_REFCLK */ \
};

const clock_name_t s_clockSourceNameAUDIO[][4] = {
    /*SRC0,                 SRC1,                 SRC2,                    SRC3,                     index      name   */ \
    { kCLOCK_SRC_AUDIOBUS,  kCLOCK_SRC_Invalid,   kCLOCK_SRC_Invalid,      kCLOCK_SRC_Invalid },  /* AUDIO ROOT 0 AUDIO */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK },  /* AUDIO ROOT 1 DMIC0_APPCLK */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK0 }, /* AUDIO ROOT 2 SAI0_MCLK0 */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK },  /* AUDIO ROOT 3 SAI0_MCLK1 */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK1 }, /* AUDIO ROOT 4 SAI1_MCLK0 */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK },  /* AUDIO ROOT 5 SAI1_MCLK1 */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK2 }, /* AUDIO ROOT 6 SAI2_MCLK0 */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK },  /* AUDIO ROOT 7 SAI2_MCLK1 */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_AUDIO,        kCLOCK_SRC_SAIMCLK },  /* AUDIO ROOT 8 SPDIF_TXCLK */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_MAINPLLDIV10, kCLOCK_SRC_AUDIOBUS }, /* AUDIO ROOT 9 SPDIF_CDRCLK */ \
    { kCLOCK_SRC_PERI6,     kCLOCK_SRC_AUDIOPLL,  kCLOCK_SRC_MAINPLLDIV10, kCLOCK_SRC_AUDIOBUS }, /* AUDIO ROOT 10 ASRC */ \
};

const clock_name_t s_clockSourceNameMEDIA[][4] = {
    /*SRC0,                     SRC1,                     SRC2,               SRC3,                     index      name   */ \
    { kCLOCK_SRC_MEDIABUS,      kCLOCK_SRC_Invalid,       kCLOCK_SRC_Invalid, kCLOCK_SRC_Invalid },  /* MEDIA ROOT 0 MEDIA */ \
    { kCLOCK_SRC_MAINPLLDIV10,  kCLOCK_SRC_MIPIPLL_DIV8,  kCLOCK_SRC_Invalid, kCLOCK_SRC_Invalid },  /* MEDIA ROOT 1 MEDIAPLL */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_VIDEOPLL,      kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 2 MIPICSI_ESCCLK */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_VIDEOPLL,      kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 3 MIPICSI */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_VIDEOPLL,      kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 4 MIPIDSI_ESCCLK */ \
    { kCLOCK_SRC_SXOSC,         kCLOCK_SRC_Invalid,       kCLOCK_SRC_Invalid, kCLOCK_SRC_Invalid },  /* MEDIA ROOT 5 MIPIDSI_REFCLK */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_VIDEOPLL,      kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 6 MIPIDSI */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_VIDEOPLL,      kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 7 REFORMAT */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_VIDEOPLL,      kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 8 DCPIXEL */ \
    { kCLOCK_SRC_PERI5,         kCLOCK_SRC_SXOSC,         kCLOCK_SRC_VIDEO,   kCLOCK_SRC_MEDIAPLL }, /* MEDIA ROOT 9 CSI_MCLKOUT */ \
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
static CCM_Type* locateClkRoot(clock_root_t target, uint32_t* index)
{
    CCM_Type* targetCCM = (CCM_Type*)NULL;
    *index = 0;

    // Determine which SS the clock node belongs to and its inner index
    if (target <= kCLOCK_Root_CGU_END) {
        // CGU
        targetCCM = SYSCON__CCM;
        *index = target - kCLOCK_Root_CGU_START;
    }
    else if (target >= kCLOCK_Root_CMPT_START && target <= kCLOCK_Root_CMPT_END) {
        // CMPT
        targetCCM = CMPT__CCM;
        *index = target - kCLOCK_Root_CMPT_START;
    }
    else if (target >= kCLOCK_Root_MAIN_START && target <= kCLOCK_Root_MAIN_END) {
        // MAIN
        targetCCM = MAIN__CCM;
        *index = target - kCLOCK_Root_MAIN_START;
    }
    else if (target >= kCLOCK_Root_WAKE_START && target <= kCLOCK_Root_WAKE_END) {
        // WAKE
        targetCCM = WAKE__CCM;
        *index = target - kCLOCK_Root_WAKE_START;
    }
    else if (target >= kCLOCK_Root_COMM_START && target <= kCLOCK_Root_COMM_END) {
        // COMM
        targetCCM = COMM__CCM;
        *index = target - kCLOCK_Root_COMM_START;
    }
    else if (target >= kCLOCK_Root_AUDIO_START && target <= kCLOCK_Root_AUDIO_END) {
        // AUDIO
        targetCCM = AUDIO__CCM;
        *index = target - kCLOCK_Root_AUDIO_START;
    }
    else if (target >= kCLOCK_Root_MEDIA_START && target <= kCLOCK_Root_MEDIA_END) {
        // MEDIA
        targetCCM = MEDIA__CCM;
        *index = target - kCLOCK_Root_MEDIA_START;
    }

    return targetCCM;
}

/*!
 * @brief Set CCM Root Clock MUX node to certain value.
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 * @param src Clock mux value to set, different mux has different value range. See \ref clock_root_mux_source_t.
 */
void CLOCK_SetRootClockMux(clock_root_t root, clock_root_mux_source_t src)
{
    CCM_Type* targetCCM;
    uint32_t index;
    assert(src < 4U);
    targetCCM = locateClkRoot(root, &index);
    if (targetCCM != NULL)
    {
        targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
            (targetCCM->CLOCK_ROOT[index].SLICE_CONTROL & ~(CCM_SLICE_CONTROL_MUX_MASK)) | CCM_SLICE_CONTROL_MUX(src);
        __DSB();
        __ISB();
#if __CORTEX_M == 85
        (void)targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
#endif
    }
}

/*!
 * @brief Get CCM Root Clock MUX value.
 *
 * @param root Which root clock node to get, see \ref clock_root_t.
 * @return Clock mux value.
 */
uint32_t CLOCK_GetRootClockMux(clock_root_t root)
{
    CCM_Type* targetCCM;
    uint32_t index;
    targetCCM = locateClkRoot(root, &index);
    if (NULL == targetCCM) { return 0U; }
    return (targetCCM->CLOCK_ROOT[index].STATUS0 & CCM_STATUS0_MUX_MASK) >> CCM_STATUS0_MUX_SHIFT;
}

/*!
 * @brief Get CCM Root Clock Source.
 *
 * @param root Which root clock node to get, see \ref clock_root_t.
 * @param src Clock mux value to get, see \ref clock_root_mux_source_t.
 * @return Clock source
 */
clock_name_t CLOCK_GetRootClockSource(clock_root_t root, uint32_t src)
{
    CCM_Type* targetCCM;
    uint32_t index;
    targetCCM = locateClkRoot(root, &index);
    if (targetCCM == SYSCON__CCM)
        return s_clockSourceNameCGU[index][src];
    else if (targetCCM == CMPT__CCM)
        return s_clockSourceNameCMPT[index][src];
    else if (targetCCM == MAIN__CCM)
        return s_clockSourceNameMAIN[index][src];
    else if (targetCCM == WAKE__CCM)
        return s_clockSourceNameWAKE[index][src];
    else if (targetCCM == COMM__CCM)
        return s_clockSourceNameCOMM[index][src];
    else if (targetCCM == AUDIO__CCM)
        return s_clockSourceNameAUDIO[index][src];
    else if (targetCCM == MEDIA__CCM)
        return s_clockSourceNameMEDIA[index][src];
    else
        return kCLOCK_SRC_Invalid;
}

/*!
 * @brief Set CCM Root Clock DIV certain value.
 *
 * @param root Which root clock to set, see \ref clock_root_t.
 * @param div Clock div value to set, different divider has different value range.
 */
void CLOCK_SetRootClockDiv(clock_root_t root, uint32_t div)
{
    CCM_Type* targetCCM;
    uint32_t index;

    assert(div);
    targetCCM = locateClkRoot(root, &index);
    if (targetCCM != NULL)
    {
        targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
            (targetCCM->CLOCK_ROOT[index].SLICE_CONTROL & ~CCM_SLICE_CONTROL_DIV_MASK) |
            CCM_SLICE_CONTROL_DIV((uint32_t)div - 1UL);
        __DSB();
        __ISB();
#if __CORTEX_M == 85
        (void)targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
#endif
    }
}

/*!
 * @brief Get CCM DIV node value.
 *
 * @param root Which root clock node to get, see \ref clock_root_t.
 * @return divider set for this root
 */
uint32_t CLOCK_GetRootClockDiv(clock_root_t root)
{
    CCM_Type* targetCCM;
    uint32_t index;
    targetCCM = locateClkRoot(root, &index);
    if (NULL == targetCCM) { return 0U; }
    return ((targetCCM->CLOCK_ROOT[index].STATUS0 & CCM_STATUS0_DIV_MASK) >> CCM_STATUS0_DIV_SHIFT) + 1UL;
}

/*!
 * @brief Power Off Root Clock
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 */
void CLOCK_PowerOffRootClock(clock_root_t root)
{
    CCM_Type* targetCCM;
    uint32_t index;
    targetCCM = locateClkRoot(root, &index);
    if (targetCCM != NULL)
    {
        if (0UL == (targetCCM->CLOCK_ROOT[index].STATUS0 & CCM_STATUS0_OFF_MASK))
        {
            targetCCM->CLOCK_ROOT[index].SLICE_CONTROL |= CCM_SLICE_CONTROL_SHUTDOWN_MASK;
            __DSB();
            __ISB();
#if __CORTEX_M == 85
            (void)targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
#endif
        }
    }
}

/*!
 * @brief Power On Root Clock
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 */
void CLOCK_PowerOnRootClock(clock_root_t root)
{
    CCM_Type* targetCCM;
    uint32_t index;
    targetCCM = locateClkRoot(root, &index);
    if (targetCCM != NULL)
    {
        targetCCM->CLOCK_ROOT[index].SLICE_CONTROL &= ~CCM_SLICE_CONTROL_SHUTDOWN_MASK;
        __DSB();
        __ISB();
#if __CORTEX_M == 85
        (void)targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
#endif
    }
}

/*!
 * @brief Configure Root Clock
 *
 * @param root Which root clock node to set, see \ref clock_root_t.
 * @param config root clock config, see \ref clock_root_config_t
 */
void CLOCK_SetRootClock(clock_root_t root, const clock_root_config_t *config)
{
    CCM_Type* targetCCM;
    uint32_t index;

    bool secondDivPresent;
    bool glitchFree;
    bool curPowerState;
    uint32_t status0, status1, curDiv, curSndDiv, newDiv, newSndDiv;
    uint32_t sliceCtrl;

    assert(config);
    targetCCM = locateClkRoot(root, &index);
    if (targetCCM != NULL)
    {
        /* Divider fields in SLICE_CONTROL and STATUS0 are (actual - 1); compare raw
         * register values so the sequencing below is straightforward. */
        status0          = targetCCM->CLOCK_ROOT[index].STATUS0;
        status1          = targetCCM->CLOCK_ROOT[index].STATUS1;
        curDiv           = (status0 & CCM_STATUS0_DIV_MASK)     >> CCM_STATUS0_DIV_SHIFT;
        curSndDiv        = (status0 & CCM_STATUS0_SND_DIV_MASK) >> CCM_STATUS0_SND_DIV_SHIFT;
        secondDivPresent = (status1 & CCM_STATUS1_SECOND_DIVIDER_PRESENT_MASK) != 0UL;
        glitchFree       = (status1 & CCM_STATUS1_GLITCH_FREE_MASK) != 0UL;
        curPowerState    = (status0 & CCM_STATUS0_OFF_MASK) == 0UL;
        newDiv           = (uint32_t)config->div    - 1UL;
        newSndDiv        = (config->sndDiv == 0) ? 0 : (uint32_t)config->sndDiv - 1UL;

        /* For non-glitch-free roots that are currently running, gate the clock before
         * touching MUX/DIV to avoid glitches on the output.  Skip this when the root
         * is already shut down (curPowerState == 0) since gating an already-off clock
         * achieves nothing.  Update curPowerState to reflect the gated state so the
         * final SHUTDOWN step can use it to decide whether to open or keep closed. */
        if (!glitchFree && curPowerState)
        {
            sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
            targetCCM->CLOCK_ROOT[index].SLICE_CONTROL = sliceCtrl | CCM_SLICE_CONTROL_SHUTDOWN_MASK;
            curPowerState = false;
        }

        /* Grow dividers BEFORE the mux change; shrink AFTER. This keeps the output
         * frequency at or below the target across the mux transition and prevents
         * the surge that a single-write mux+div update can cause. */
        if (secondDivPresent && (newSndDiv > curSndDiv))
        {
            sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
            targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
                (sliceCtrl & ~CCM_SLICE_CONTROL_SND_DIV_MASK) | CCM_SLICE_CONTROL_SND_DIV(newSndDiv);
        }

        if (newDiv > curDiv)
        {
            sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
            targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
                (sliceCtrl & ~CCM_SLICE_CONTROL_DIV_MASK) | CCM_SLICE_CONTROL_DIV(newDiv);
        }

        sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
        targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
            (sliceCtrl & ~CCM_SLICE_CONTROL_MUX_MASK) | CCM_SLICE_CONTROL_MUX(config->mux);

        if (newDiv < curDiv)
        {
            sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
            targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
                (sliceCtrl & ~CCM_SLICE_CONTROL_DIV_MASK) | CCM_SLICE_CONTROL_DIV(newDiv);
        }

        if (secondDivPresent && (newSndDiv < curSndDiv))
        {
            sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
            targetCCM->CLOCK_ROOT[index].SLICE_CONTROL =
                (sliceCtrl & ~CCM_SLICE_CONTROL_SND_DIV_MASK) | CCM_SLICE_CONTROL_SND_DIV(newSndDiv);
        }

        sliceCtrl = targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
        /* Use config->clockShutdown and curPowerState (which reflects the gated
         * state after the pre-MUX/DIV step above) to decide the final SHUTDOWN:
         *   - clockShutdown=1, curPowerState=1: want off, currently on  -> assert SHUTDOWN.
         *   - clockShutdown=0, curPowerState=0: want on,  currently off -> clear SHUTDOWN.
         *   - clockShutdown=1, curPowerState=0: already off, stay off   -> no action.
         *   - clockShutdown=0, curPowerState=1: already on, stay on     -> no action. */
        if (config->clockShutdown == curPowerState)
        {
            if (config->clockShutdown)
            {
                sliceCtrl |= CCM_SLICE_CONTROL_SHUTDOWN_MASK;
            }
            else
            {
                sliceCtrl &= ~CCM_SLICE_CONTROL_SHUTDOWN_MASK;
            }
        }
        targetCCM->CLOCK_ROOT[index].SLICE_CONTROL = sliceCtrl;

        __DSB();
        __ISB();
#if __CORTEX_M == 85
        (void)targetCCM->CLOCK_ROOT[index].SLICE_CONTROL;
#endif
    }
}

/*******************************************************************************
 * MODCON-controlled clock-tree muxes (MCUX-88602)
 *
 * Set-side counterpart to the Case-3 / OSC_24M branches of
 * CLOCK_GetClockSrcFreq. The canonical MODCON instance for each Mx must match
 * what the Get path reads so all readers see the same /2 selection -- see the
 * shared-Mx note above s_clockSrcRootMap.
 ******************************************************************************/

void CLOCK_SetOsc24mSource(clock_osc_24m_src_t src)
{
    uint32_t cfg = MODCON_GetCFG((uint32_t)kModCon_MAIN_CLK24M_SEL, 0U);
    cfg = (cfg & ~MODCON_CFG_SEL_MASK) | MODCON_CFG_SEL((uint32_t)src);
    MODCON_SetCFG((uint32_t)kModCon_MAIN_CLK24M_SEL, 0U, cfg);
}

clock_osc_24m_src_t CLOCK_GetOsc24mSource(void)
{
    uint32_t cfg = MODCON_GetCFG((uint32_t)kModCon_MAIN_CLK24M_SEL, 0U);
    return ((cfg & MODCON_CFG_SEL_MASK) == 0U) ? kCLOCK_Osc24mSrc_FRO_24M : kCLOCK_Osc24mSrc_SXOSC;
}

static bool clockSrcDiv2Lookup(clock_name_t src, uint32_t *modcon, uint32_t *mask)
{
    switch (src)
    {
        case kCLOCK_SRC_MAIN_PERI0_DIV2:
            *modcon = (uint32_t)kModCon_MAIN_XSPI0;
            *mask   = MODCON_CFG_PERI_ROOTCLK0_MASK;
            return true;
        case kCLOCK_SRC_MAIN_PERI1_DIV2:
            *modcon = (uint32_t)kModCon_MAIN_XSPI1;
            *mask   = MODCON_CFG_PERI_ROOTCLK1_MASK;
            return true;
        case kCLOCK_SRC_MAINPFDX_DIV2:
            /* Shared XSPI0/XSPI1 source -- XSPI0 is the canonical instance. */
            *modcon = (uint32_t)kModCon_MAIN_XSPI0;
            *mask   = MODCON_CFG_MAINPFDX_ROOTCLK_MASK;
            return true;
        case kCLOCK_SRC_COMM_PERI1_DIV2:
            *modcon = (uint32_t)kModCon_COMM_USDHC0;
            *mask   = MODCON_CFG_PERI_ROOTCLK1_SEL_DIV2_MASK;
            return true;
        case kCLOCK_SRC_COMM_PERI2_DIV2:
            *modcon = (uint32_t)kModCon_COMM_USDHC1;
            *mask   = MODCON_CFG_PERI_ROOTCLK2_SEL_DIV2_MASK;
            return true;
        case kCLOCK_SRC_COMMPFDX_DIV2:
            /* Shared USDHC0/USDHC1 source -- USDHC0 is the canonical instance. */
            *modcon = (uint32_t)kModCon_COMM_USDHC0;
            *mask   = MODCON_CFG_COMMPFDX_ROOTCLK_SEL_DIV2_MASK;
            return true;
        default:
            return false;
    }
}

void CLOCK_SetClockSrcDiv2(clock_name_t src, bool useDiv2)
{
    uint32_t modcon = 0U, mask = 0U, cfg;

    if (!clockSrcDiv2Lookup(src, &modcon, &mask))
    {
        return;
    }
    cfg = MODCON_GetCFG(modcon, 0U);
    if (useDiv2)
    {
        cfg |= mask;
    }
    else
    {
        cfg &= ~mask;
    }
    MODCON_SetCFG(modcon, 0U, cfg);
}

bool CLOCK_GetClockSrcDiv2(clock_name_t src)
{
    uint32_t modcon = 0U, mask = 0U;

    if (!clockSrcDiv2Lookup(src, &modcon, &mask))
    {
        return false;
    }
    return (MODCON_GetCFG(modcon, 0U) & mask) != 0U;
}

static CCM_Type* locateClkGate(clock_ip_name_t target, uint32_t* index)
{
    CCM_Type* targetCCM = (CCM_Type*)NULL;
    /* Safe default: 0 sits inside every CCM's CGC_ROOT[] array. All valid
     * subsystem branches below reassign *index; for out-of-range targets
     * (e.g. kCLOCK_IpInvalid) the value stays bounded. Setting an
     * unconditional default of (target - kCLOCK_MAIN_START) at entry
     * confuses -Werror=array-bounds analysis, which then reports 172 as a
     * reachable subscript when no branch matches. */
    *index = 0U;

    // Determine which SS the clock node belongs to and its inner index
    if (target <= kCLOCK_SYSCON_END) {
        // SYSCON
        targetCCM = SYSCON__CCM;
        *index = target - kCLOCK_SYSCON_START;
    }
    else if (target >= kCLOCK_CMPT_START && target <= kCLOCK_CMPT_END) {
        // CMPT
        targetCCM = CMPT__CCM;
        *index = target - kCLOCK_CMPT_START;
    }
    else if (target >= kCLOCK_MAIN_START && target <= kCLOCK_MAIN_END) {
        // MAIN
        targetCCM = MAIN__CCM;
        *index = target - kCLOCK_MAIN_START;
    }
    else if (target >= kCLOCK_WAKE_START && target <= kCLOCK_WAKE_END) {
        // WAKE
        targetCCM = WAKE__CCM;
        *index = target - kCLOCK_WAKE_START;
    }
    else if (target >= kCLOCK_COMM_START && target <= kCLOCK_COMM_END) {
        // COMM
        targetCCM = COMM__CCM;
        *index = target - kCLOCK_COMM_START;
    }
    else if (target >= kCLOCK_AUDIO_START && target <= kCLOCK_AUDIO_END) {
        // AUDIO
        targetCCM = AUDIO__CCM;
        *index = target - kCLOCK_AUDIO_START;
    }
    else if (target >= kCLOCK_MEDIA_START && target <= kCLOCK_MEDIA_END) {
        // MEDIA
        targetCCM = MEDIA__CCM;
        *index = target - kCLOCK_MEDIA_START;
    }
    return targetCCM;
}

/*!
 * @brief Enable the clock for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_lpcg_t.
 */
void CLOCK_EnableClock(clock_ip_name_t name)
{
    CCM_Type* targetCCM;
    uint32_t index;
    /* Instances without an LPCG (e.g. VBAT__GPIO, VBAT__LPTMR) use
     * kCLOCK_IpInvalid in the per-IP clock arrays; locateClkGate() has no
     * mapping for it and would produce a stray register write. */
    if (name == kCLOCK_IpInvalid)
    {
        return;
    }
    targetCCM = locateClkGate(name, &index);
    if (targetCCM != NULL)
    {
        targetCCM->CGC_ROOT[index].SLICE_CONTROL |= CCM_SLICE_CONTROL_LPCG_CFG_MASK;
    }
}

/*!
 * @brief Disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_lpcg_t.
 */
void CLOCK_DisableClock(clock_ip_name_t name)
{
    CCM_Type* targetCCM;
    uint32_t index;
    if (name == kCLOCK_IpInvalid)
    {
        return;
    }
    targetCCM = locateClkGate(name, &index);
    if (targetCCM != NULL)
    {
        targetCCM->CGC_ROOT[index].SLICE_CONTROL &= ~CCM_SLICE_CONTROL_LPCG_CFG_MASK;
    }
}

/*!
 * @brief Program LPCG_CFG, HSK_SEL, and HSK_BYPASS of a peripheral clock gate.
 */
void CLOCK_SetClockGateMode(clock_ip_name_t name, clock_gate_value_t mode, uint8_t hskSel,
                            bool bypassHandshake)
{
    CCM_Type* targetCCM;
    uint32_t  index;
    uint32_t  clearMask;
    uint32_t  setMask;

    if (name == kCLOCK_IpInvalid)
    {
        return;
    }
    targetCCM = locateClkGate(name, &index);
    if (targetCCM != NULL)
    {
        clearMask = CCM_SLICE_CONTROL_LPCG_CFG_MASK |
                    CCM_SLICE_CONTROL_HSK_SEL_MASK  |
                    CCM_SLICE_CONTROL_HSK_BYPASS_MASK;
        setMask   = CCM_SLICE_CONTROL_LPCG_CFG((uint32_t)mode) |
                    CCM_SLICE_CONTROL_HSK_SEL((uint32_t)hskSel) |
                    (bypassHandshake ? CCM_SLICE_CONTROL_HSK_BYPASS(1U) : 0U);

        targetCCM->CGC_ROOT[index].SLICE_CONTROL =
            (targetCCM->CGC_ROOT[index].SLICE_CONTROL & ~clearMask) | setMask;
    }
}

/*******************************************************************************
 * CGUANA driver
 ******************************************************************************/

static const uint32_t s_cguanaRefFreq[4] = {19200000U, 24000000U, 32000000U, 40000000U};

/* 
 * Turn on one or more FSM-controlled resources and wait until they are ready.
 * fsmBits: one or more CLOCK_CGUANA_FSM_xxx bits (must NOT include FRO12M_WAKE). 
 *      0    LDOA 0.8 V
 *      1    FRO192M
 *      2    FRO12M
 *      3    MAINPLL
 *      4    COREPLL
 *      5    SYSPLL
 *      6    LDOQ 0.8 V
 *      7    SXOSC
 *      8    FRO12M_LP
 */
static void CGUANA_FsmOn(uint32_t fsmBits)
{
#if 1
    /* Original path: drive the CGUANA FSM directly via CGUAD_CTRL_REG. */
    uint32_t reg = SYSCON__CGUANA->CGUAD_CTRL_REG;
    reg &= ~CGUANA_CGUAD_CTRL_REG_CGUAD_FSM_SW_OFF_REQ(fsmBits);
    reg |= CGUANA_CGUAD_CTRL_REG_CGUAD_FSM_SW_ON_REQ(fsmBits);
    SYSCON__CGUANA->CGUAD_CTRL_REG = reg;
    /* Wait for all requested RDY bits (FRO12M_WAKE bit8 has no RDY) */
    uint32_t rdyMask = fsmBits & CGUANA_CGUAD_CTRL_STS_CGUAD_FSM_RDY_MASK;
    while ((SYSCON__CGUANA->CGUAD_CTRL_STS & rdyMask) != rdyMask) {}
#else
    /* Alternative path: use POWERCON P_TRIG */
    uint32_t csrc = SYSCON__POWERCON_SOC_CTRL->CSRCCFG_ACTIVE;
    csrc |= (fsmBits & POWERCON_SOC_CTRL_CSRCCFG_ACTIVE_CFG_ACTIVE_MASK);
    SYSCON__POWERCON_SOC_CTRL->CSRCCFG_ACTIVE = csrc;
    /* Fire the P-Channel handshake to PMU/CGUANA. */
    SYSCON__POWERCON_SOC_CTRL->SOC_CTRL_STATUS |= POWERCON_SOC_CTRL_SOC_CTRL_STATUS_P_TRG_MASK;
    /* Wait for the P-Channel update to complete (P_OVER). */
    while ((SYSCON__POWERCON_SOC_CTRL->SOC_CTRL_STATUS &
            POWERCON_SOC_CTRL_SOC_CTRL_STATUS_P_OVER_MASK) == 0U) {}
    /* Wait for all requested RDY bits (FRO12M_WAKE bit8 has no RDY). */
    uint32_t rdyMask = fsmBits & CGUANA_CGUAD_CTRL_STS_CGUAD_FSM_RDY_MASK;
    while ((SYSCON__CGUANA->CGUAD_CTRL_STS & rdyMask) != rdyMask) {}
#endif
}

/* Turn off one or more FSM-controlled resources. */
static void CGUANA_FsmOff(uint32_t fsmBits)
{
    uint32_t reg = SYSCON__CGUANA->CGUAD_CTRL_REG;
    reg &= ~CGUANA_CGUAD_CTRL_REG_CGUAD_FSM_SW_ON_REQ(fsmBits);
    reg |= CGUANA_CGUAD_CTRL_REG_CGUAD_FSM_SW_OFF_REQ(fsmBits);
    SYSCON__CGUANA->CGUAD_CTRL_REG = reg;
}

void CLOCK_SetCmsPllRefSource(clock_pll_ref_src_t src)
{
    uint32_t reg = SYSCON__CGUANA->CGUA_CTRL_REG;
    reg &= ~CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CMS_PLL_CKIN_SEL_MASK;
    reg |= CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CMS_PLL_CKIN_SEL((uint32_t)src);
    SYSCON__CGUANA->CGUA_CTRL_REG = reg;
}

clock_pll_ref_src_t CLOCK_GetCmsPllRefSource(void)
{
    return ((SYSCON__CGUANA->CGUA_CTRL_REG & CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CMS_PLL_CKIN_SEL_MASK) != 0U)
               ? kCLOCK_PllRefSrc_SXOSC
               : kCLOCK_PllRefSrc_FRO192M_24M;
}

void CLOCK_SetAvPllRefSource(clock_pll_ref_src_t src)
{
    uint32_t reg = SYSCON__CGUANA->CGUA_CTRL_REG;
    reg &= ~CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_AV_PLL_CKIN_SEL_MASK;
    reg |= CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_AV_PLL_CKIN_SEL((uint32_t)src);
    SYSCON__CGUANA->CGUA_CTRL_REG = reg;
}

clock_pll_ref_src_t CLOCK_GetAvPllRefSource(void)
{
    return ((SYSCON__CGUANA->CGUA_CTRL_REG & CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_AV_PLL_CKIN_SEL_MASK) != 0U)
               ? kCLOCK_PllRefSrc_SXOSC
               : kCLOCK_PllRefSrc_FRO192M_24M;
}

/* Shared helper: program Main/Sys PLL control registers (identical layouts).
 * Uses MAINPLL macro names -- bit patterns are identical for SYSPLL. */
static void CGUANA_ConfigFracPllRegs(
    volatile uint32_t *pll1Reg, volatile uint32_t *pll2Reg,
    volatile uint32_t *pll3Reg, volatile uint32_t *pll4Reg,
    const clock_cguana_frac_pll_config_t *config)
{
    *pll1Reg =
        (config->div5En  ? CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV5_EN_MASK  : 0U) |
        (config->div8En  ? CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV8_EN_MASK  : 0U) |
        (config->div10En ? CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV10_EN_MASK : 0U) |
        (config->div20En ? CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV20_EN_MASK : 0U);

    *pll2Reg =
        (config->fracDiv[0].en    ? CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_EN_MASK    : 0U) |
        (config->fracDiv[0].range ? CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_RANGE_MASK : 0U) |
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_SEL(config->fracDiv[0].sel) |
        (config->fracDiv[1].en    ? CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_EN_MASK    : 0U) |
        (config->fracDiv[1].range ? CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_RANGE_MASK : 0U) |
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_SEL(config->fracDiv[1].sel) |
        (config->fracDiv[2].en    ? CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_EN_MASK    : 0U) |
        (config->fracDiv[2].range ? CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_RANGE_MASK : 0U) |
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_SEL(config->fracDiv[2].sel);

    *pll3Reg =
        CGUANA_CGUA_MAINPLL_PLL3_REG_MAINPLL_FREF_SET((uint32_t)config->refFreq) |
        CGUANA_CGUA_MAINPLL_PLL3_REG_MAINPLL_LOWFREQ(config->lowFreq);

    uint32_t pll4 = 0U;
    if (config->sscgEn)
    {
        pll4 |= CGUANA_CGUA_MAINPLL_PLL4_REG_MAINPLL_SSCG_EN_MASK;
        if (config->sscg != NULL)
        {
            pll4 |= CGUANA_CGUA_MAINPLL_PLL4_REG_MAINPLL_SSCG_STOP(config->sscg->stop) |
                    CGUANA_CGUA_MAINPLL_PLL4_REG_MAINPLL_SSCG_STEP(config->sscg->step) |
                    (config->sscg->centerSpread ?
                        CGUANA_CGUA_MAINPLL_PLL4_REG_MAINPLL_SSCG_SPREAD_MODE_MASK : 0U);
        }
    }
    *pll4Reg = pll4;
}

/* Per-fractional-output (DIVOUT0..2) DIVFRAC SEL/RANGE field descriptors,
 * indexed by fracIdx (0..2). MainPLL and SysPLL share the same PLL2 layout,
 * so a single descriptor table covers both. */
typedef struct
{
    uint32_t selMask;
    uint32_t selShift;
    uint32_t rangeMask;
} cguana_main_sys_pll_divfrac_desc_t;

static const cguana_main_sys_pll_divfrac_desc_t s_mainSysPllDivFracDesc[3] = {
    {
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_SEL_MASK,
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_SEL_SHIFT,
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_RANGE_MASK,
    },
    {
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_SEL_MASK,
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_SEL_SHIFT,
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_RANGE_MASK,
    },
    {
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_SEL_MASK,
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_SEL_SHIFT,
        CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_RANGE_MASK,
    },
};

/* Base VCO frequency for the four LOWFREQ band-select values, indexed by the
 * MAINPLL_LOWFREQ field value (0..3). */
static const uint32_t s_mainSysPllVcoFreq[4] = {
    2000000000U, 1950000000U, 1900000000U, 1850000000U
};

/* Read the VCO frequency from a frac PLL's PLL3 register (LOWFREQ band select). */
static uint32_t CGUANA_GetFracPllVcoFreq(volatile const uint32_t *pll3Reg)
{
    return s_mainSysPllVcoFreq[
        (*pll3Reg & CGUANA_CGUA_MAINPLL_PLL3_REG_MAINPLL_LOWFREQ_MASK) >>
        CGUANA_CGUA_MAINPLL_PLL3_REG_MAINPLL_LOWFREQ_SHIFT];
}

/* Compute one of the fractional outputs (DIVOUT0..2) of a frac PLL, given the
 * already-computed VCO frequency and the consuming output index (0..2). */
static uint32_t CGUANA_GetFracPllDivOutFreq(
    uint32_t vco, volatile const uint32_t *pll2Reg, uint8_t fracIdx)
{
    const cguana_main_sys_pll_divfrac_desc_t *desc = &s_mainSysPllDivFracDesc[fracIdx];
    uint32_t pll2  = *pll2Reg;
    uint32_t sel   = (pll2 & desc->selMask) >> desc->selShift;
    uint32_t range = ((pll2 & desc->rangeMask) != 0U) ? 1U : 0U;

    if (range != 0U)
    {
        sel += 32U;
    }
    if (sel == 0U)
    {
        return 0U;
    }
    return (uint32_t)((uint64_t)vco * 4U / sel);
}


void CLOCK_InitSxosc(const clock_cguana_sxosc_config_t *config)
{
    assert(config != NULL);
    SYSCON__CGUANA->CGUA_SXOSC_CTRL_REG =
        CGUANA_CGUA_SXOSC_CTRL_REG_SXOSC_MODE_SEL(config->modeSel)              |
        CGUANA_CGUA_SXOSC_CTRL_REG_SXOSC_GM_SEL(config->gmSel)                  |
        CGUANA_CGUA_SXOSC_CTRL_REG_SXOSC_XTAL1_CAP_TRIM(config->xtal1CapTrim)   |
        CGUANA_CGUA_SXOSC_CTRL_REG_SXOSC_XTAL2_CAP_TRIM(config->xtal2CapTrim)   |
        CGUANA_CGUA_SXOSC_CTRL_REG_SXOSC_DET_TRIM(config->detTrim)              |
        (config->clkDiv2En ? CGUANA_CGUA_SXOSC_CTRL_REG_SXOSC_CLK_DIV2_EN_MASK : 0U);
    CGUANA_FsmOn(CLOCK_CGUANA_FSM_SXOSC);
}

void CLOCK_DeinitSxosc(void)
{
    CGUANA_FsmOff(CLOCK_CGUANA_FSM_SXOSC);
}

void CLOCK_InitFro192M(const clock_cguana_fro192m_config_t *config)
{
    assert(config != NULL);
    uint32_t reg = SYSCON__CGUANA->CGUA_FRO192M_CTRL_REG;
    reg &= ~CGUANA_CGUA_FRO192M_CTRL_REG_FRO192M_OTWB_MASK;
    reg |= CGUANA_CGUA_FRO192M_CTRL_REG_FRO192M_OTWB(config->otwb);
    SYSCON__CGUANA->CGUA_FRO192M_CTRL_REG = reg;
    CGUANA_FsmOn(CLOCK_CGUANA_FSM_FRO192M);
}

void CLOCK_DeinitFro192M(void)
{
    CGUANA_FsmOff(CLOCK_CGUANA_FSM_FRO192M);
}

void CLOCK_InitFro12M(const clock_cguana_fro12m_config_t *config)
{
    assert(config != NULL);
    uint32_t reg = SYSCON__CGUANA->CGUA_FRO12M_CTRL_REG;
    reg &= ~CGUANA_CGUA_FRO12M_CTRL_REG_FRO12M_OTWB_MASK;
    reg |= CGUANA_CGUA_FRO12M_CTRL_REG_FRO12M_OTWB(config->otwb);
    SYSCON__CGUANA->CGUA_FRO12M_CTRL_REG = reg;
    CGUANA_FsmOn(CLOCK_CGUANA_FSM_FRO12M);
}

void CLOCK_DeinitFro12M(void)
{
    CGUANA_FsmOff(CLOCK_CGUANA_FSM_FRO12M);
}

void CLOCK_InitCorePll(const clock_cguana_core_pll_config_t *config)
{
    assert(config != NULL);

    SYSCON__CGUANA->CGUA_COREPLL_PLL2_REG =
        (config->vcoSelHf ? CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_VCO_SEL_MASK : 0U) |
        CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_FREF_SET((uint32_t)config->refFreq)    |
        CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_LOOPDIV_NINT(config->loopDivNint)      |
        (config->postDivBy2 ? CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_POSTDIV_DIVRATIO_MASK : 0U);

    CGUANA_FsmOn(CLOCK_CGUANA_FSM_COREPLL);
}

void CLOCK_DeinitCorePll(void)
{
    CGUANA_FsmOff(CLOCK_CGUANA_FSM_COREPLL);
}

uint32_t CLOCK_GetCorePllFreq(void)
{
    uint32_t pll2   = SYSCON__CGUANA->CGUA_COREPLL_PLL2_REG;
    uint32_t fref   = s_cguanaRefFreq[
        (pll2 & CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_FREF_SET_MASK) >>
        CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_FREF_SET_SHIFT];
    uint32_t nint   = (pll2 & CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_LOOPDIV_NINT_MASK) >>
                      CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_LOOPDIV_NINT_SHIFT;
    uint32_t vco    = fref * nint;
    return ((pll2 & CGUANA_CGUA_COREPLL_PLL2_REG_COREPLL_POSTDIV_DIVRATIO_MASK) != 0U) ?
           (vco / 2U) : vco;
}

void CLOCK_InitMainPll(const clock_cguana_frac_pll_config_t *config)
{
    assert(config != NULL);
    CGUANA_ConfigFracPllRegs(
        &SYSCON__CGUANA->CGUA_MAINPLL_PLL1_REG,
        &SYSCON__CGUANA->CGUA_MAINPLL_PLL2_REG,
        &SYSCON__CGUANA->CGUA_MAINPLL_PLL3_REG,
        &SYSCON__CGUANA->CGUA_MAINPLL_PLL4_REG,
        config);
    CGUANA_FsmOn(CLOCK_CGUANA_FSM_MAINPLL);
}

void CLOCK_DeinitMainPll(void)
{
    CGUANA_FsmOff(CLOCK_CGUANA_FSM_MAINPLL);
}

uint32_t CLOCK_GetMainPllVcoFreq(void)
{
    return CGUANA_GetFracPllVcoFreq(&SYSCON__CGUANA->CGUA_MAINPLL_PLL3_REG);
}

uint32_t CLOCK_GetMainPllFreq(uint8_t fracIdx)
{
    return CGUANA_GetFracPllDivOutFreq(
        CLOCK_GetMainPllVcoFreq(),
        &SYSCON__CGUANA->CGUA_MAINPLL_PLL2_REG,
        fracIdx);
}

void CLOCK_InitSysPll(const clock_cguana_frac_pll_config_t *config)
{
    assert(config != NULL);
    CGUANA_ConfigFracPllRegs(
        &SYSCON__CGUANA->CGUA_SYSPLL_PLL1_REG,
        &SYSCON__CGUANA->CGUA_SYSPLL_PLL2_REG,
        &SYSCON__CGUANA->CGUA_SYSPLL_PLL3_REG,
        &SYSCON__CGUANA->CGUA_SYSPLL_PLL4_REG,
        config);
    CGUANA_FsmOn(CLOCK_CGUANA_FSM_SYSPLL);
}

void CLOCK_DeinitSysPll(void)
{
    CGUANA_FsmOff(CLOCK_CGUANA_FSM_SYSPLL);
}

uint32_t CLOCK_GetSysPllVcoFreq(void)
{
    return CGUANA_GetFracPllVcoFreq(&SYSCON__CGUANA->CGUA_SYSPLL_PLL3_REG);
}

uint32_t CLOCK_GetSysPllFreq(uint8_t fracIdx)
{
    return CGUANA_GetFracPllDivOutFreq(
        CLOCK_GetSysPllVcoFreq(),
        &SYSCON__CGUANA->CGUA_SYSPLL_PLL2_REG,
        fracIdx);
}

/* Shared internal init for Audio/Video PLLs (not FSM-controlled). */
static void CGUANA_InitAvPll(
    volatile uint32_t *pll1Reg, volatile uint32_t *pll3Reg,
    volatile uint32_t *pll4Reg, volatile uint32_t *dnumReg,
    volatile const uint32_t *stsReg,
    const clock_cguana_avpll_config_t *config)
{
    /* Clear PWREN/PLL_EN/RSTN/CLKOUT_EN before reconfiguring */
    *pll1Reg &= ~(CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CLKOUT_EN_MASK |
                  CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_PLL_EN_MASK    |
                  CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_RSTN_MASK      |
                  CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_PWREN_MASK);

    /* Configure PLL parameters */
    *pll1Reg |=
        CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_FREF_SET((uint32_t)config->refFreq)             |
        CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CCO_FREQ_BAND_SEL(config->ccoBandSel);

    /* SSCG configuration */
    uint32_t pll3 = 0U;
    uint32_t pll4 = CGUANA_CGUA_AUDIOPLL_PLL4_REG_AUDIOPLL_POSTDIV_DIVRATIO_SEL(config->postDivRatio);
    if (config->sscgEn && config->sscg != NULL)
    {
        pll3 = CGUANA_CGUA_AUDIOPLL_PLL3_REG_AUDIOPLL_SSCG_STOP(config->sscg->stop) |
               CGUANA_CGUA_AUDIOPLL_PLL3_REG_AUDIOPLL_SSCG_STEP(config->sscg->step) |
               (config->sscg->centerSpread ?
                   CGUANA_CGUA_AUDIOPLL_PLL3_REG_AUDIOPLL_SSCG_SPREAD_MODE_MASK : 0U);
        pll4 |= CGUANA_CGUA_AUDIOPLL_PLL4_REG_AUDIOPLL_SSCG_EN_MASK;
    }
    *pll3Reg = pll3;
    *pll4Reg = pll4;

    /* Write DNUM (no update-req needed at startup; PLL hasn't started yet) */
    *dnumReg = CGUANA_CGUA_AUDIOPLL_DNUM_REG_AUDIOPLL_DNUM(config->dnum);

    /* Power on sequence: PWREN -> wait PWRACK -> RSTN=1 -> PLL_EN=1 -> wait READY */
    *pll1Reg |= CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_PWREN_MASK;
    while ((*stsReg & CGUANA_CGUA_AUDIOPLL_STS_AUDIOPLL_PWRACK_MASK) == 0U) {}

    *pll1Reg |= CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_RSTN_MASK;
    *pll1Reg |= CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_PLL_EN_MASK;
    while ((*stsReg & CGUANA_CGUA_AUDIOPLL_STS_AUDIOPLL_READY_MASK) == 0U) {}

    *pll1Reg |= CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CLKOUT_EN_MASK;
}

/* Shared internal deinit for Audio/Video PLLs. */
static void CGUANA_DeinitAvPll(volatile uint32_t *pll1Reg)
{
    *pll1Reg &= ~(CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CLKOUT_EN_MASK |
                  CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_PLL_EN_MASK    |
                  CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_RSTN_MASK      |
                  CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_PWREN_MASK);
}

/* Shared internal GetFreq for Audio/Video PLLs.
 *
 * The band selects a nominal target VCO frequency F_cal around which DNUM
 * provides fine adjustment referenced to Fref:
 *   1. F_cal = F_BASE + band * D_BAND     (F_BASE = 722.5344 MHz, D_BAND = 10.6496 MHz)
 *   2. Loop  = F_cal / Fref                (conceptual, fractional)
 *   3. F_VCO = Fref * (Loop + DNUM/2^30)   = F_cal + Fref * DNUM / 2^30
 *   4. F_OUT = F_VCO / postDiv
 *
 * Audio PLL only supports bands 0 and 6; Video PLL supports bands 0-7.
 */
#define CGUANA_AVPLL_FBASE_HZ (722534400U) /* 722.5344 MHz */
#define CGUANA_AVPLL_DBAND_HZ (10649600U)  /* 10.6496  MHz */

static uint32_t CGUANA_GetAvPllFreq(
    volatile const uint32_t *pll1Reg, volatile const uint32_t *pll4Reg,
    volatile const uint32_t *dnumReg, bool isAudio)
{
    uint32_t pll1 = *pll1Reg;
    uint32_t band = (pll1 & CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CCO_FREQ_BAND_SEL_MASK) >>
                    CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CCO_FREQ_BAND_SEL_SHIFT;
    if (band > 7U || (isAudio && band != 0U && band != 6U))
    {
        return 0U;
    }

    uint32_t fref = s_cguanaRefFreq[
        (pll1 & CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_FREF_SET_MASK) >>
        CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_FREF_SET_SHIFT];
    uint32_t dnum = *dnumReg & CGUANA_CGUA_AUDIOPLL_DNUM_REG_AUDIOPLL_DNUM_MASK;
    uint32_t postdiv = (*pll4Reg & CGUANA_CGUA_AUDIOPLL_PLL4_REG_AUDIOPLL_POSTDIV_DIVRATIO_SEL_MASK) >>
                       CGUANA_CGUA_AUDIOPLL_PLL4_REG_AUDIOPLL_POSTDIV_DIVRATIO_SEL_SHIFT;
    if (postdiv < 8U)
    {
        return 0U;
    }

    uint32_t fcal = CGUANA_AVPLL_FBASE_HZ + band * CGUANA_AVPLL_DBAND_HZ;
    uint64_t fvco = (uint64_t)fcal + ((uint64_t)fref * dnum) / (1ULL << 30);
    return (uint32_t)(fvco / postdiv);
}

void CLOCK_InitAudioPll(const clock_cguana_avpll_config_t *config)
{
    assert(config != NULL);
    /* Enable reference clock output to Audio PLL */
    SYSCON__CGUANA->CGUA_CTRL_REG |= CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CKREF_AUDIOPLL_EN_MASK;
    CGUANA_InitAvPll(
        &SYSCON__CGUANA->CGUA_AUDIOPLL_PLL1_REG,
        &SYSCON__CGUANA->CGUA_AUDIOPLL_PLL3_REG,
        &SYSCON__CGUANA->CGUA_AUDIOPLL_PLL4_REG,
        &SYSCON__CGUANA->CGUA_AUDIOPLL_DNUM_REG,
        &SYSCON__CGUANA->CGUA_AUDIOPLL_STS,
        config);
}

void CLOCK_DeinitAudioPll(void)
{
    CGUANA_DeinitAvPll(&SYSCON__CGUANA->CGUA_AUDIOPLL_PLL1_REG);
    SYSCON__CGUANA->CGUA_CTRL_REG &= ~CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CKREF_AUDIOPLL_EN_MASK;
}

uint32_t CLOCK_GetAudioPllFreq(void)
{
    return CGUANA_GetAvPllFreq(
        &SYSCON__CGUANA->CGUA_AUDIOPLL_PLL1_REG,
        &SYSCON__CGUANA->CGUA_AUDIOPLL_PLL4_REG,
        &SYSCON__CGUANA->CGUA_AUDIOPLL_DNUM_REG,
        true);
}

void CLOCK_UpdateAudioPllDnum(uint32_t dnum)
{
    /* Write new DNUM value and assert UPDATE_REQ in the same write */
    SYSCON__CGUANA->CGUA_AUDIOPLL_DNUM_REG =
        CGUANA_CGUA_AUDIOPLL_DNUM_REG_AUDIOPLL_DNUM(dnum) |
        CGUANA_CGUA_AUDIOPLL_DNUM_REG_AUDIOPLL_DNUM_UPDATE_REQ_MASK;
    /* Wait for ACK (resynchronised) */
    while ((SYSCON__CGUANA->CGUAD_CTRL_STS &
            CGUANA_CGUAD_CTRL_STS_CGUAD_AUDIOPLL_DNUM_UPDATE_ACK_RESYNC_MASK) == 0U) {}
    /* Clear the UPDATE_REQ bit */
    SYSCON__CGUANA->CGUA_AUDIOPLL_DNUM_REG =
        CGUANA_CGUA_AUDIOPLL_DNUM_REG_AUDIOPLL_DNUM(dnum);
}

void CLOCK_InitVideoPll(const clock_cguana_avpll_config_t *config)
{
    assert(config != NULL);
    /* Enable reference clock output to Video PLL */
    SYSCON__CGUANA->CGUA_CTRL_REG |= CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CKREF_VIDEOPLL_EN_MASK;
    /* Video PLL registers are identical in layout to Audio PLL -- cast to Audio-PLL volatile ptrs */
    CGUANA_InitAvPll(
        (volatile uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_PLL1_REG,
        (volatile uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_PLL3_REG,
        (volatile uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_PLL4_REG,
        (volatile uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_DNUM_REG,
        (volatile const uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_STS,
        config);
}

void CLOCK_DeinitVideoPll(void)
{
    CGUANA_DeinitAvPll((volatile uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_PLL1_REG);
    SYSCON__CGUANA->CGUA_CTRL_REG &= ~CGUANA_CGUA_CTRL_REG_CGUA_CLKGEN_CKREF_VIDEOPLL_EN_MASK;
}

uint32_t CLOCK_GetVideoPllFreq(void)
{
    return CGUANA_GetAvPllFreq(
        (volatile const uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_PLL1_REG,
        (volatile const uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_PLL4_REG,
        (volatile const uint32_t *)&SYSCON__CGUANA->CGUA_VIDEOPLL_DNUM_REG,
        false);
}

void CLOCK_UpdateVideoPllDnum(uint32_t dnum)
{
    SYSCON__CGUANA->CGUA_VIDEOPLL_DNUM_REG =
        CGUANA_CGUA_VIDEOPLL_DNUM_REG_VIDEOPLL_DNUM(dnum) |
        CGUANA_CGUA_VIDEOPLL_DNUM_REG_VIDEOPLL_DNUM_UPDATE_REQ_MASK;
    while ((SYSCON__CGUANA->CGUAD_CTRL_STS &
            CGUANA_CGUAD_CTRL_STS_CGUAD_VIDEOPLL_DNUM_UPDATE_ACK_RESYNC_MASK) == 0U) {}
    SYSCON__CGUANA->CGUA_VIDEOPLL_DNUM_REG =
        CGUANA_CGUA_VIDEOPLL_DNUM_REG_VIDEOPLL_DNUM(dnum);
}

bool CLOCK_EnableUsbFsClock(clock_usb_fs_src_t src)
{
    clock_root_config_t config = {0};
    const uint32_t targetFreq  = 48000000U;
    bool useUsbPhyPllClk       = false;
    uint32_t srcFreq;

    switch (src)
    {
        case kCLOCK_UsbFsSrcUsb1Root:
            srcFreq = CLOCK_GetRootClockFreq(kCLOCK_Root_CGU_USB1_ROOTCLK);
            break;
        case kCLOCK_UsbFsSrcUsbPllOut:
            srcFreq         = CLOCK_GetClockSrcFreq(kCLOCK_SRC_USBPLL_OUT);
            useUsbPhyPllClk = true;
            break;
        case kCLOCK_UsbFsSrcUsbPll48M:
            srcFreq         = CLOCK_GetClockSrcFreq(kCLOCK_SRC_USBPLL_48M);
            useUsbPhyPllClk = true;
            break;
        case kCLOCK_UsbFsSrcFro48M:
            srcFreq = CLOCK_GetClockSrcFreq(kCLOCK_SRC_FRO_48M);
            break;
        default:
            return false;
    }

    if ((srcFreq == 0U) || (srcFreq % targetFreq != 0U))
    {
        return false;
    }

    /* USBPLL_OUT/USBPLL_48M come from the shared USB PHY PLL. This also
     * ungates kCLOCK_COMM_usb0 internally. */
    if (useUsbPhyPllClk)
    {
        if (!CLOCK_EnableUsbPhyPllClock())
        {
            return false;
        }
    }

    config.clockShutdown = false;
    config.mux           = (uint8_t)src;
    config.div           = srcFreq / targetFreq;
    CLOCK_SetRootClock(kCLOCK_Root_COMM_usb1_fclk, &config);

    CLOCK_EnableClock(kCLOCK_COMM_usb1);

    RESET_PeripheralReset(kModCon_COMM_USB1);

    return true;
}

void CLOCK_DisableUsbFsClock(void)
{
    uint32_t mux = CLOCK_GetRootClockMux(kCLOCK_Root_COMM_usb1_fclk);

    if ((mux == kCLOCK_USB1_ClockRoot_USBPLL_OUT) || (mux == kCLOCK_USB1_ClockRoot_USBPLL_48M))
    {
        /* Also gates kCLOCK_COMM_usb0 internally. */
        CLOCK_DisableUsbPhyPllClock();
    }

    CLOCK_DisableClock(kCLOCK_COMM_usb1);

    CLOCK_PowerOffRootClock(kCLOCK_Root_COMM_usb1_fclk);
}

bool CLOCK_EnableUsbHsClock(void)
{
    clock_root_config_t config = {0};

    /* USB HS (EHCI) 48 MHz reference: usb0_fro48m root <- FRO48M, /1. */
    config.clockShutdown = false;
    config.mux           = (uint8_t)kCLOCK_USB0_FRO48M_ClockRoot_FRO48M;
    config.div           = 1U;
    CLOCK_SetRootClock(kCLOCK_Root_COMM_usb0_fro48m, &config);

    /* Power up the shared USB PHY PLL (480 MHz). NOTE: this also ungates
     * kCLOCK_COMM_usb0 internally. Propagate failure so the controller is not
     * released from reset on an unlocked PLL. */
    if (!CLOCK_EnableUsbPhyPllClock())
    {
        return false;
    }

    RESET_PeripheralReset(kModCon_COMM_USB0);

    /* Issue the controller-level soft reset (USBCMD.RST). */
    COMM__USBC->USBCMD |= USBHS_USBCMD_RST(1U);

    /* Wait out the mandatory reset-recovery time before the controller is used. */
    SDK_DelayAtLeastUs(15U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    return true;
}

void CLOCK_DisableUsbHsClock(void)
{
    CLOCK_DisableUsbPhyPllClock();

    CLOCK_PowerOffRootClock(kCLOCK_Root_COMM_usb0_fro48m);
}

bool CLOCK_EnableUsbPhyPllClock(void)
{
    const uint32_t targetFreq = 480000000UL;
    uint32_t srcFreq;
    uint32_t phyPllDiv;

    /* PHY reference from usb0_phyclk root (SRC0 = SXOSC = 24 MHz). */
    srcFreq = CLOCK_GetRootClockFreq(kCLOCK_Root_COMM_usb0_phyclk);

    if ((srcFreq == 0U) || ((targetFreq % srcFreq) != 0UL))
    {
        return false;
    }

    switch (targetFreq / srcFreq)
    {
        case 15U:
            phyPllDiv = 0U;
            break;
        case 16U:
            phyPllDiv = 1U;
            break;
        case 20U:
            phyPllDiv = 2U;
            break;
        case 22U:
            phyPllDiv = 3U;
            break;
        case 24U:
            phyPllDiv = 4U;
            break;
        case 25U:
            phyPllDiv = 5U;
            break;
        case 30U:
            phyPllDiv = 6U;
            break;
        case 40U:
            phyPllDiv = 7U;
            break;
        default:
            return false;
    }

    /* Ungate the USB PHY (COMM usb0) so the PLL_SIC/CTRL registers are accessible. */
    CLOCK_EnableClock(kCLOCK_COMM_usb0);

    RESET_PeripheralReset(kModCon_COMM_USBPHY0);

    /* Release the PHY soft reset and enable the PLL regulator, then power the PLL. */
    COMM__USBPHY->CTRL_CLR    = USBPHY_CTRL_SFTRST(1U);
    COMM__USBPHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_REG_ENABLE(1U);
    SDK_DelayAtLeastUs(15U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    COMM__USBPHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_POWER(1U);

    /* Program the multiplier (PLL_DIV_SEL). */
    COMM__USBPHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_DIV_SEL_MASK;
    COMM__USBPHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_DIV_SEL(phyPllDiv);

    /* Program the PLL post-divider that generates usbpll_out.
     * PLL_POSTDIV is a 3-bit field: a value of 0b0xx disables the post-divider
     * output (usbpll_out stays gated / has no clock), while 0b1xx enables it
     * and selects the divide ratio (0b100 = /1 ... 0b111 = /4). Writing 4U
     * (0b100) enables the post-divider at divide-by-1 so usbpll_out actually
     * produces a clock. Clear the field first, then set the new value. */
    COMM__USBPHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_POSTDIV_MASK;
    COMM__USBPHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_POSTDIV(4U);

    /* Leave bypass, enable the USB clock taps (480 MHz / 48 MHz), ungate PHY clocks. */
    COMM__USBPHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_BYPASS(1U);
    COMM__USBPHY->PLL_SIC_SET = USBPHY_PLL_SIC_PLL_EN_USB_CLKS(1U);
    COMM__USBPHY->CTRL_CLR    = USBPHY_CTRL_CLR_CLKGATE(1U);

    /* Wait for the PLL to lock before it is used as a clock source. */
    while (USBPHY_PLL_SIC_PLL_LOCK(1U) != (COMM__USBPHY->PLL_SIC & USBPHY_PLL_SIC_PLL_LOCK_MASK))
    {
    }

    return true;
}

void CLOCK_DisableUsbPhyPllClock(void)
{
    /* Reverse of CLOCK_EnableUsbPhyPllClock: gate the PHY clocks, stop the USB
     * clock taps (480 MHz / 48 MHz), then power down the PLL and its regulator. */
    COMM__USBPHY->CTRL_SET    = USBPHY_CTRL_CLKGATE(1U);
    COMM__USBPHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_EN_USB_CLKS(1U);
    COMM__USBPHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_POWER(1U);
    COMM__USBPHY->PLL_SIC_CLR = USBPHY_PLL_SIC_PLL_REG_ENABLE(1U);

    CLOCK_DisableClock(kCLOCK_COMM_usb0);
}

/*! @brief One row of tuner (FLL) reference parameters for a given reference source.
 *
 * The values are transcribed literally from the reference manual FRO_TUNER settings
 * tables. ckrefSrcSel and sxoscFrefSel select the reference (CKREF_SOURCE_SEL and
 * SXOSC_FREF_SEL in CTRL_REG); frefWinLgth and cycleTarget are the reference window
 * length and expected FRO cycle count for that window (COUNT_REG); kiGain is the loop
 * integration gain (KI_GAIN in CTRL_REG). The cycle target is NOT derived at runtime
 * because it does not follow a single clean formula across all references. */
typedef struct _clock_fro_tuner_param
{
    uint16_t ckrefSrcSel;
    uint16_t sxoscFrefSel;
    uint16_t frefWinLgth;
    uint32_t cycleTarget;
    uint16_t kiGain;
} clock_fro_tuner_param_t;

/* FRO192M tuner settings (reference manual Table 814 FRO_192M FRO_TUNER settings).
 * Indexed by clock_fro_tuner_src_t. */
static const clock_fro_tuner_param_t s_froTuner192mParam[] = {
    /* {ckrefSrcSel, sxoscFrefSel, frefWinLgth, cycleTarget, kiGain} */
    [kCLOCK_FroTunerRefSxosc19M2]   = {0U, 0U, 480U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc24M]    = {0U, 1U, 600U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc32M]    = {0U, 2U, 800U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc40M]    = {0U, 3U, 1000U, 4800U, 3U},
    /* SXOSC_FREF_SEL is not applicable for the non-SXOSC references (blank in the
     * datasheet); it only matters when CKREF_SOURCE_SEL is 0, so leave it 0. */
    [kCLOCK_FroTunerRefSxosc32768Hz] = {1U, 0U, 1U, 5859U, 4U},
    [kCLOCK_FroTunerRefUsbFsSof1kHz] = {2U, 0U, 1U, 192000U, 9U},
    [kCLOCK_FroTunerRefUsbHsSof8kHz] = {3U, 0U, 1U, 24000U, 6U},
};

/* FRO12M tuner settings (reference manual Table 815 FRO_12M FRO_TUNER settings).
 * Indexed by clock_fro_tuner_src_t. */
static const clock_fro_tuner_param_t s_froTuner12mParam[] = {
    /* {ckrefSrcSel, sxoscFrefSel, frefWinLgth, cycleTarget, kiGain} */
    [kCLOCK_FroTunerRefSxosc19M2]     = {0U, 0U, 7680U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc24M]      = {0U, 1U, 9600U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc32M]      = {0U, 2U, 12800U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc40M]      = {0U, 3U, 16000U, 4800U, 3U},
    [kCLOCK_FroTunerRefSxosc32768Hz]  = {1U, 0U, 14U, 5126U, 4U},
    [kCLOCK_FroTunerRefUsbFsSof1kHz]  = {2U, 0U, 1U, 12000U, 5U},
    [kCLOCK_FroTunerRefUsbHsSof8kHz]  = {3U, 0U, 4U, 600U, 4U},
};

void CLOCK_EnableFroTuner(clock_fro_tuner_target_t target, clock_fro_tuner_src_t src, uint16_t lockCriteria)
{
    const clock_fro_tuner_param_t *param;
    uint32_t clearMask;
    uint32_t setBits;

    if ((uint32_t)src >= ARRAY_SIZE(s_froTuner192mParam))
    {
        return;
    }

    /* Note: CKREF_SOURCE_SEL and SXOSC_FREF_SEL are shared by both tuners, so the
     * FRO12M and FRO192M tuners can only lock to the same reference source at once.
     * Enabling one tuner reprograms the reference-source selection for both.
     * SXOSC_FREF_SEL only applies when CKREF_SOURCE_SEL == 0 (SXOSC reference); for
     * any other reference it is left untouched so a concurrent SXOSC tuner setting
     * is not disturbed. */
    if (target == kCLOCK_FroTuner12M)
    {
        param = &s_froTuner12mParam[src];

        /* Program the control fields in one read-modify-write, keeping TUNE_EN cleared
         * until the count register is set. */
        clearMask = CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_LOCK_CRITERIA_MASK |
                    CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_KI_GAIN_MASK |
                    CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_CKREF_SOURCE_SEL_MASK |
                    CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_TUNE_EN_MASK;
        setBits = CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_LOCK_CRITERIA(lockCriteria) |
                  CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_KI_GAIN(param->kiGain) |
                  CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_CKREF_SOURCE_SEL(param->ckrefSrcSel);

        /* Only configure SXOSC_FREF_SEL when the reference is SXOSC. */
        if (param->ckrefSrcSel == 0U)
        {
            clearMask |= CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_SXOSC_FREF_SEL_MASK;
            setBits |= CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_SXOSC_FREF_SEL(param->sxoscFrefSel);
        }

        SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG =
            (SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG & ~clearMask) | setBits;

        /* Program the cycle target and reference window length in one read-modify-write. */
        SYSCON__CGUANA->CGUAD_FROTUNER_FRO12M_COUNT_REG =
            (SYSCON__CGUANA->CGUAD_FROTUNER_FRO12M_COUNT_REG &
             ~(CGUANA_CGUAD_FROTUNER_FRO12M_COUNT_REG_CGUAD_FROTUNER_FRO12M_CYCLE_TARGET_MASK |
               CGUANA_CGUAD_FROTUNER_FRO12M_COUNT_REG_CGUAD_FROTUNER_FRO12M_FREF_WIN_LGTH_MASK)) |
            CGUANA_CGUAD_FROTUNER_FRO12M_COUNT_REG_CGUAD_FROTUNER_FRO12M_CYCLE_TARGET(param->cycleTarget) |
            CGUANA_CGUAD_FROTUNER_FRO12M_COUNT_REG_CGUAD_FROTUNER_FRO12M_FREF_WIN_LGTH(param->frefWinLgth);

        /* Enable the FRO12M tuner last, once its configuration is in place. */
        SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG |= CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_TUNE_EN(1U);
    }
    else
    {
        param = &s_froTuner192mParam[src];

        /* Program the control fields in one read-modify-write, keeping TUNE_EN cleared
         * until the count register is set. */
        clearMask = CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_LOCK_CRITERIA_MASK |
                    CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_KI_GAIN_MASK |
                    CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_CKREF_SOURCE_SEL_MASK |
                    CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_TUNE_EN_MASK;
        setBits = CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_LOCK_CRITERIA(lockCriteria) |
                  CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_KI_GAIN(param->kiGain) |
                  CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_CKREF_SOURCE_SEL(param->ckrefSrcSel);

        /* Only configure SXOSC_FREF_SEL when the reference is SXOSC. */
        if (param->ckrefSrcSel == 0U)
        {
            clearMask |= CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_SXOSC_FREF_SEL_MASK;
            setBits |= CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_SXOSC_FREF_SEL(param->sxoscFrefSel);
        }

        SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG =
            (SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG & ~clearMask) | setBits;

        /* Program the cycle target and reference window length in one read-modify-write. */
        SYSCON__CGUANA->CGUAD_FROTUNER_FRO192M_COUNT_REG =
            (SYSCON__CGUANA->CGUAD_FROTUNER_FRO192M_COUNT_REG &
             ~(CGUANA_CGUAD_FROTUNER_FRO192M_COUNT_REG_CGUAD_FROTUNER_FRO192M_CYCLE_TARGET_MASK |
               CGUANA_CGUAD_FROTUNER_FRO192M_COUNT_REG_CGUAD_FROTUNER_FRO192M_FREF_WIN_LGTH_MASK)) |
            CGUANA_CGUAD_FROTUNER_FRO192M_COUNT_REG_CGUAD_FROTUNER_FRO192M_CYCLE_TARGET(param->cycleTarget) |
            CGUANA_CGUAD_FROTUNER_FRO192M_COUNT_REG_CGUAD_FROTUNER_FRO192M_FREF_WIN_LGTH(param->frefWinLgth);

        /* Enable the FRO192M tuner last, once its configuration is in place. */
        SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG |= CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_TUNE_EN(1U);
    }
}

void CLOCK_DisableFroTuner(clock_fro_tuner_target_t target)
{
    /* Clear TUNE_EN only; leave the other tuner configuration fields intact so the
     * FRO keeps its last tuned value and can be re-enabled as-is. */
    if (target == kCLOCK_FroTuner12M)
    {
        SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG &= ~CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO12M_TUNE_EN_MASK;
    }
    else
    {
        SYSCON__CGUANA->CGUAD_FROTUNER_CTRL_REG &= ~CGUANA_CGUAD_FROTUNER_CTRL_REG_CGUAD_FROTUNER_FRO192M_TUNE_EN_MASK;
    }
}

/*******************************************************************************
 * Frequency resolver (MCUX-88602)
 *
 * Mental model:
 *   For any clock root we read mux + div + sndDiv from CCM SLICE_CONTROL/STATUS0,
 *   resolve the mux to a clock_name_t via CLOCK_GetRootClockSource(), then ask
 *   CLOCK_GetClockSrcFreq() for the source frequency. A clock_name_t source
 *   has four shapes:
 *     1. It aliases another clock root (L1 Ox / L2 Ox / Lx WAKE feedback)
 *        - look it up in s_clockSrcRootMap and recurse via CLOCK_GetRootClockFreq.
 *     2. It is a relatively fixed analog source (Sx / Ax / Dx)
 *        - simple: return a constant or #ifndef-guarded macro
 *        - complex: call a PLL helper (Core/Main/Sys/Audio/Video).
 *     3. It is a MODCON-controlled Mx (parent root /1 or /2)
 *        - look up the parent root in s_clockSrcRootMap, recurse, then divide
 *          by the MODCON-driven /2 bit.
 *     4. Special: both kCLOCK_SRC_MAIN and kCLOCK_SRC_CPU -> kCLOCK_Root_CGU_MAIN_ROOTCLK.
 *        CGU ROOT 30 feeds CMPT ROOT 0 MAIN after div + sndDiv, and CMPT ROOT 1 CPU after
 *        div only. CLOCK_GetRootClockFreq applies both dividers, so kCLOCK_SRC_CPU needs to
 *        multiply the resolved frequency by sndDiv to recover the post-div-only value
 *        (see MCUX-88628).
 *
 * Final frequency: srcFreq / div / sndDiv. ISR-safe and reentrant.
 *
 * Termination: CLOCK_GetRootClockFreq and CLOCK_GetClockSrcFreq are mutually
 * recursive. The recursion graph is the hardware mux DAG (rooted at L0 analog
 * sources) plus a few well-defined fixed-frequency Sx sources that short the
 * back-edges in the source-name tables (SXOSC, LP12M_WAKE, LP1M_WAKE are
 * resolved as constants, not via their nominal CGU/WAKE roots, which would
 * cycle back through OSC_24M MODCON SEL / their own root mux SRC). Max chain
 * is ~4 hops (L2 root -> L1 root -> L0 source -> Case 2 constant).
 ******************************************************************************/

/*
 * Weak default board hook for external (Dx) sources (REQ-005).
 * Board ports override by linking a non-weak symbol of the same name.
 */
__attribute__((weak)) uint32_t CLOCK_GetExternalSrcFreq(clock_name_t name)
{
    (void)name;
    return 0U;
}

/*
 * src -> root flat lookup table. Indexed directly by clock_name_t for any
 * value in the [0, kCLOCK_SRC_BOUNDARY) range. Slots [48, 64) are reserved
 * future-in-map slots and hold kCLOCK_Root_Invalid; the resolver short-
 * circuits to 0 if any of those values shows up at runtime. Adding a new
 * in-map src means picking the next free value in the reserved segment and
 * adding its [slot] = root line below -- no other entries move.
 *
 * The six Mx MODCON-controlled /2 entries (kCLOCK_SRC_*_DIV2 / *PFDX_DIV2)
 * recurse normally; the /2 selection is read in CLOCK_GetClockSrcFreq via a
 * canonical MODCON instance for each Mx. The SW invariant is that all
 * consumers of the same Mx source program identical /2 selections system-wide.
 *
 * Cycle breakers intentionally absent from the table -- their CGU/WAKE roots'
 * mux SRCs name those same sources back, forming cycles. Treated as Case 2
 * fixed-frequency constants:
 *   kCLOCK_SRC_SXOSC       (O0 -- OSC_24M MODCON SEL=1 routes back to SXOSC)
 *   kCLOCK_SRC_LP12M_WAKE  (WAKE root 3 wake_lp12m SRC0 == LP12M_WAKE)
 *   kCLOCK_SRC_LP1M_WAKE   (WAKE root 2 wake_lp1m  SRC0 == LP1M_WAKE)
 *
 * Case 4 special: both kCLOCK_SRC_MAIN and kCLOCK_SRC_CPU alias
 * kCLOCK_Root_CGU_MAIN_ROOTCLK (CGU root 30, renamed for MCUX-88628). The two
 * differ by where they tap on the slice: MAIN is post-div+sndDiv, CPU is post-div
 * only. The /sndDiv backout for CPU lives in CLOCK_GetClockSrcFreq below.
 */
static const clock_root_t s_clockSrcRootMap[kCLOCK_SRC_BOUNDARY] = {
    /* --- A.1: L1 Ox CGU passthrough/mux outputs (38) --- */
    [kCLOCK_SRC_BASE]              = kCLOCK_Root_CGU_BASE_CLK,
    [kCLOCK_SRC_LOW]               = kCLOCK_Root_CGU_LOW_CLK,
    [kCLOCK_SRC_MAINPLL_DIVX]      = kCLOCK_Root_CGU_MAINPLL_DIVX,
    [kCLOCK_SRC_SYSPLL_DIVX]       = kCLOCK_Root_CGU_SYSPLL_DIVX,
    [kCLOCK_SRC_PLL_PFDX]          = kCLOCK_Root_CGU_PLL_PFDX,
    [kCLOCK_SRC_MEDIA_PFDX]        = kCLOCK_Root_CGU_MEDIA_PFDX,
    [kCLOCK_SRC_MAINDIVX]          = kCLOCK_Root_CGU_MAINDIVX_ROOTCLK,
    [kCLOCK_SRC_SAIMCLK]           = kCLOCK_Root_CGU_SAIMCLK_ROOTCLK,
    [kCLOCK_SRC_SAIMCLK0]          = kCLOCK_Root_CGU_SAIMCLK0_ROOTCLK,
    [kCLOCK_SRC_SAIMCLK1]          = kCLOCK_Root_CGU_SAIMCLK1_ROOTCLK,
    [kCLOCK_SRC_SAIMCLK2]          = kCLOCK_Root_CGU_SAIMCLK2_ROOTCLK,
    [kCLOCK_SRC_ULP32K]            = kCLOCK_Root_CGU_ULP32K_ROOTCLK,
    [kCLOCK_SRC_FRO192M]           = kCLOCK_Root_CGU_FRO192M_ROOTCLK,
    [kCLOCK_SRC_FRO96M]            = kCLOCK_Root_CGU_FRO96M_ROOTCLK,
    [kCLOCK_SRC_FRO48M]            = kCLOCK_Root_CGU_FRO48M_ROOTCLK,
    [kCLOCK_SRC_FRO24M]            = kCLOCK_Root_CGU_FRO24M_ROOTCLK,
    [kCLOCK_SRC_SYSPLLDIV4]        = kCLOCK_Root_CGU_SYSPLLDIV4_ROOTCLK,
    [kCLOCK_SRC_SYSPLLDIV5]        = kCLOCK_Root_CGU_SYSPLLDIV5_ROOTCLK,
    [kCLOCK_SRC_MAINPLLDIV8]       = kCLOCK_Root_CGU_MAINPLLDIV8_ROOTCLK,
    [kCLOCK_SRC_MAINPLLDIV10]      = kCLOCK_Root_CGU_MAINPLLDIV10_ROOTCLK,
    [kCLOCK_SRC_AUDIOPLL]          = kCLOCK_Root_CGU_AUDIOPLL_ROOTCLK,
    [kCLOCK_SRC_VIDEOPLL]          = kCLOCK_Root_CGU_VIDEOPLL_ROOTCLK,
    [kCLOCK_SRC_CPU]               = kCLOCK_Root_CGU_MAIN_ROOTCLK,
    [kCLOCK_SRC_NPU]               = kCLOCK_Root_CGU_NPU_ROOTCLK,
    [kCLOCK_SRC_MEDIABUS]          = kCLOCK_Root_CGU_MEDIABUS_ROOTCLK,
    [kCLOCK_SRC_AUDIOBUS]          = kCLOCK_Root_CGU_AUDIOBUS_ROOTCLK,
    [kCLOCK_SRC_COMMBUS]           = kCLOCK_Root_CGU_COMMBUS_ROOTCLK,
    [kCLOCK_SRC_WAKEBUS]           = kCLOCK_Root_CGU_WAKEBUS_ROOTCLK,
    [kCLOCK_SRC_PERI0]             = kCLOCK_Root_CGU_PERI_ROOTCLK0,
    [kCLOCK_SRC_PERI1]             = kCLOCK_Root_CGU_PERI_ROOTCLK1,
    [kCLOCK_SRC_PERI2]             = kCLOCK_Root_CGU_PERI_ROOTCLK2,
    [kCLOCK_SRC_PERI3]             = kCLOCK_Root_CGU_PERI_ROOTCLK3,
    [kCLOCK_SRC_PERI4]             = kCLOCK_Root_CGU_PERI_ROOTCLK4,
    [kCLOCK_SRC_PERI5]             = kCLOCK_Root_CGU_PERI_ROOTCLK5,
    [kCLOCK_SRC_PERI6]             = kCLOCK_Root_CGU_PERI_ROOTCLK6,
    [kCLOCK_SRC_PERI7]             = kCLOCK_Root_CGU_PERI_ROOTCLK7,
    [kCLOCK_SRC_AUDIO]             = kCLOCK_Root_CGU_AUDIO_ROOTCLK,
    [kCLOCK_SRC_VIDEO]             = kCLOCK_Root_CGU_VIDEO_ROOTCLK,
    [kCLOCK_SRC_USB1]              = kCLOCK_Root_CGU_USB1_ROOTCLK,
    [kCLOCK_SRC_ETH]               = kCLOCK_Root_CGU_ETH_ROOTCLK,

    /* --- A.2: Case 4 special alias (1) --- */
    [kCLOCK_SRC_MAIN]              = kCLOCK_Root_CGU_MAIN_ROOTCLK,

    /* --- A.3: L2 Lx WAKE-domain feedback (1) --- */
    [kCLOCK_SRC_WAKE_LPCLK]        = kCLOCK_Root_WAKE_wake_lpclk,

    /* --- A.4: Mx MODCON-controlled /2 (6) ---
     * Parent root only; the /2 is applied in CLOCK_GetClockSrcFreq. */
    [kCLOCK_SRC_MAIN_PERI0_DIV2]   = kCLOCK_Root_CGU_PERI_ROOTCLK0,
    [kCLOCK_SRC_MAIN_PERI1_DIV2]   = kCLOCK_Root_CGU_PERI_ROOTCLK1,
    [kCLOCK_SRC_MAINPFDX_DIV2]     = kCLOCK_Root_CGU_MAINPFDX_ROOTCLK,
    [kCLOCK_SRC_COMM_PERI1_DIV2]   = kCLOCK_Root_CGU_PERI_ROOTCLK1,
    [kCLOCK_SRC_COMM_PERI2_DIV2]   = kCLOCK_Root_CGU_PERI_ROOTCLK2,
    [kCLOCK_SRC_COMMPFDX_DIV2]     = kCLOCK_Root_CGU_COMMPFDX_ROOTCLK,

    /* --- Section B: reserved future-in-map slots [48, 64) ---
     * Explicitly marked kCLOCK_Root_Invalid so the resolver can short-circuit
     * to 0. (Designated-init zero-fill would default to root 0 = SXOSC, which
     * is a valid root, not what we want.) */
    [48] = kCLOCK_Root_Invalid, [49] = kCLOCK_Root_Invalid,
    [50] = kCLOCK_Root_Invalid, [51] = kCLOCK_Root_Invalid,
    [52] = kCLOCK_Root_Invalid, [53] = kCLOCK_Root_Invalid,
    [54] = kCLOCK_Root_Invalid, [55] = kCLOCK_Root_Invalid,
    [56] = kCLOCK_Root_Invalid, [57] = kCLOCK_Root_Invalid,
    [58] = kCLOCK_Root_Invalid, [59] = kCLOCK_Root_Invalid,
    [60] = kCLOCK_Root_Invalid, [61] = kCLOCK_Root_Invalid,
    [62] = kCLOCK_Root_Invalid, [63] = kCLOCK_Root_Invalid,
};

/*
 * Read the configured second divider for a root (CCM STATUS0.SND_DIV + 1).
 * Mirrors the convention of CLOCK_GetRootClockDiv: returns the 1-based value.
 */
static uint32_t CLOCK_GetRootClockSndDiv(clock_root_t root)
{
    CCM_Type *targetCCM;
    uint32_t  index;
    targetCCM = locateClkRoot(root, &index);
    if (NULL == targetCCM) { return 0U; }
    return ((targetCCM->CLOCK_ROOT[index].STATUS0 & CCM_STATUS0_SND_DIV_MASK) >> CCM_STATUS0_SND_DIV_SHIFT) + 1UL;
}

/*
 * CLOCK_GetClockSrcFreq -- resolve a clock_name_t source to its frequency.
 *
 * Cases 1/3/4: name < kCLOCK_SRC_BOUNDARY -> O(1) direct-index into
 *              s_clockSrcRootMap, recurse into the root via
 *              CLOCK_GetRootClockFreq. Six Mx sources (case 3) then apply
 *              an additional MODCON-controlled /2 -- handled as a special
 *              case below the table lookup so the table itself stays simple.
 * Case 2:      name >= kCLOCK_SRC_BOUNDARY -> terminal: a fixed analog
 *              (Sx/Ax/Dx), PLL helper, macro, or external hook.
 */
uint32_t CLOCK_GetClockSrcFreq(clock_name_t name)
{
    uint32_t freq;

    /* Cases 1, 3, 4 -- direct index into the src->root table. */
    if ((uint32_t)name < (uint32_t)kCLOCK_SRC_BOUNDARY)
    {
        clock_root_t root = s_clockSrcRootMap[name];
        if (root == kCLOCK_Root_Invalid)
        {
            /* Hit a reserved (Section B) slot. */
            return 0U;
        }
        freq = CLOCK_GetRootClockFreq(root);

        /* Case 3 -- the six Mx sources additionally /2 per MODCON. Skip
         * the MODCON read entirely for Cases 1/4 via the contiguous-block
         * range check (the six Mx entries are contiguous in clock_name_t). */
        if (((uint32_t)name >= (uint32_t)kCLOCK_SRC_MAIN_PERI0_DIV2) &&
            ((uint32_t)name <= (uint32_t)kCLOCK_SRC_COMMPFDX_DIV2) &&
            CLOCK_GetClockSrcDiv2(name))
        {
            freq /= 2U;
        }

        /* Case 4 -- kCLOCK_SRC_CPU taps CGU ROOT 30 after the first divider
         * only, while CLOCK_GetRootClockFreq applied both div and sndDiv.
         * Multiply by sndDiv to recover the post-div-only frequency. MAIN
         * keeps the post-both-dividers value the table lookup produced. */
        if (name == kCLOCK_SRC_CPU)
        {
            freq *= CLOCK_GetRootClockSndDiv(kCLOCK_Root_CGU_MAIN_ROOTCLK);
        }
        return freq;
    }

    /* Case 2 -- analog (Sx/Ax) or external (Dx). Only L0 fundamentals appear
     * here; no-underscore FRO aliases are routed through the table above. */
    switch (name)
    {
        /* OSC_24M (Sx) -- MODCON-controlled between FRO_24M and SXOSC. */
        case kCLOCK_SRC_OSC_24M:
            return CLOCK_GetClockSrcFreq(
                (CLOCK_GetOsc24mSource() == kCLOCK_Osc24mSrc_FRO_24M) ? kCLOCK_SRC_FRO_24M
                                                                     : kCLOCK_SRC_SXOSC);

        /* Sx -- L0 fixed analog constants.
         * SXOSC, LP12M_WAKE, LP1M_WAKE are here (not in the table) to break
         * back-edges in the source-name graph -- see the table's NOTE comments. */
        case kCLOCK_SRC_SXOSC:
            return 24000000U;
        case kCLOCK_SRC_FRO_192M:
            return 192000000U;
        case kCLOCK_SRC_FRO_96M:
            return 96000000U;
        case kCLOCK_SRC_FRO_48M:
            return 48000000U;
        case kCLOCK_SRC_FRO_24M:
            return 24000000U;
        case kCLOCK_SRC_LP12M_WAKE:
        case kCLOCK_SRC_LPOSC_12M_CORE:
            return 12000000U;
        case kCLOCK_SRC_LP1M_WAKE:
        case kCLOCK_SRC_LPOSC_1M_CORE:
        case kCLOCK_SRC_LP1M_CORE:
            return 1000000U;
        case kCLOCK_SRC_LP2M_WAKE:
            return 2000000U;
        case kCLOCK_SRC_LPOSC32K:
            return 32768U;

        /* Sx -- PLL-derived: dedicated helpers.
         * Integer dividers (DIV4/5/8/10/20) are simply VCO/N at the call site;
         * fractional outputs (DIVOUT0..2) are the public PLL accessor. */
        case kCLOCK_SRC_COREPLL_OUT:
            return CLOCK_GetCorePllFreq();
        case kCLOCK_SRC_AUDIOPLL_DIVOUT:
            return CLOCK_GetAudioPllFreq();
        case kCLOCK_SRC_VIDEOPLL_DIVOUT:
            return CLOCK_GetVideoPllFreq();
        case kCLOCK_SRC_MAINPLL_DIV4:
            return CLOCK_GetMainPllVcoFreq() / 4U;
        case kCLOCK_SRC_MAINPLL_DIV5:
            return CLOCK_GetMainPllVcoFreq() / 5U;
        case kCLOCK_SRC_MAINPLL_DIV8:
            return CLOCK_GetMainPllVcoFreq() / 8U;
        case kCLOCK_SRC_MAINPLL_DIV10:
            return CLOCK_GetMainPllVcoFreq() / 10U;
        case kCLOCK_SRC_MAINPLL_DIV20:
            return CLOCK_GetMainPllVcoFreq() / 20U;
        case kCLOCK_SRC_MAINPLL_DIVOUT0:
            return CLOCK_GetMainPllFreq(0U);
        case kCLOCK_SRC_MAINPLL_DIVOUT1:
            return CLOCK_GetMainPllFreq(1U);
        case kCLOCK_SRC_MAINPLL_DIVOUT2:
            return CLOCK_GetMainPllFreq(2U);
        case kCLOCK_SRC_SYSPLL_DIV4:
            return CLOCK_GetSysPllVcoFreq() / 4U;
        case kCLOCK_SRC_SYSPLL_DIV5:
            return CLOCK_GetSysPllVcoFreq() / 5U;
        case kCLOCK_SRC_SYSPLL_DIV10:
            return CLOCK_GetSysPllVcoFreq() / 10U;
        case kCLOCK_SRC_SYSPLL_DIV20:
            return CLOCK_GetSysPllVcoFreq() / 20U;
        case kCLOCK_SRC_SYSPLL_DIVOUT0:
            return CLOCK_GetSysPllFreq(0U);
        case kCLOCK_SRC_SYSPLL_DIVOUT1:
            return CLOCK_GetSysPllFreq(1U);
        case kCLOCK_SRC_SYSPLL_DIVOUT2:
            return CLOCK_GetSysPllFreq(2U);

        /* Macro-backed PLL defaults (REQ-010); board/app overrides via #ifndef. */
        case kCLOCK_SRC_USBPLL_OUT:
            return FSL_CLOCK_USBPLL_OUT_FREQ_HZ;
        case kCLOCK_SRC_USBPLL_48M:
            return FSL_CLOCK_USBPLL_48M_FREQ_HZ;
        case kCLOCK_SRC_MIPIPLL_DIV8:
            return FSL_CLOCK_MIPIPLL_DIV8_FREQ_HZ;
        case kCLOCK_SRC_MEDIAPLL:
            return FSL_CLOCK_MEDIAPLL_FREQ_HZ;

        /* Dx -- external sources via board hook (REQ-005). */
        case kCLOCK_SRC_SAI0_MCLK:
        case kCLOCK_SRC_SAI1_MCLK:
        case kCLOCK_SRC_SAI2_MCLK:
            return CLOCK_GetExternalSrcFreq(name);

        case kCLOCK_SRC_TIE_LOW:
        case kCLOCK_SRC_Invalid:
        default:
            return 0U;
    }
}

uint32_t CLOCK_GetRootClockFreq(clock_root_t root)
{
    uint32_t      mux;
    uint32_t      div;
    uint32_t      sndDiv;
    uint32_t      srcFreq;
    clock_name_t  src;

    mux    = CLOCK_GetRootClockMux(root);
    src    = CLOCK_GetRootClockSource(root, mux);
    div    = CLOCK_GetRootClockDiv(root);
    sndDiv = CLOCK_GetRootClockSndDiv(root);

    if ((div == 0U) || (sndDiv == 0U) || (src == kCLOCK_SRC_Invalid))
    {
        return 0U;
    }

    srcFreq = CLOCK_GetClockSrcFreq(src);
    return (srcFreq / div) / sndDiv;
}

/*******************************************************************************
 * FREQME-based actual frequency measurement
 *
 * CLOCK_MeasureRootClockFreq / CLOCK_MeasureClockSrcFreq return the real,
 * hardware-measured frequency instead of the theoretical value the Get APIs
 * compute -- needed while the internal FROs are untrimmed. Register-level
 * FREQME/INPUTMUX access on purpose: the fsl_freqme/fsl_inputmux drivers call
 * back into this driver for clock gating, so using them here would create a
 * circular dependency and force every project to link both drivers.
 *
 * Measurement chain: every subsystem's FREQME measures its own targets, with
 * a per-domain reference whose frequency is trusted or itself measured:
 *   SYSCON, WAKE : reference = SXOSC crystal (the only trusted clock).
 *   others       : reference = a domain input that is node-identical to a
 *                  SYSCON target tap, pre-measured against SXOSC by the
 *                  SYSCON FREQME. Accuracy therefore always derives from the
 *                  crystal; no divider arithmetic is involved anywhere.
 ******************************************************************************/

/* Chip-wide measurement bounds: reference clocks are >= 24 MHz and no clock
 * exceeds 2 GHz, so the count ratio is bounded by 2 GHz / 24 MHz < 84. At
 * scale 24 the worst-case RESULT is 84 * 2^24 ~= 1.41e9 < 2^31 - 1: the
 * 31-bit result counter cannot overflow for any valid scale. */
#define CLOCK_FREQME_SCALE_MAX    (24U)
#define CLOCK_FREQME_MAX_RATIO    (84UL)
#define CLOCK_FREQME_MIN_EXPECTED (0xFUL)

#if (FSL_CLOCK_FREQME_REF_SCALE > 24U)
#error "FSL_CLOCK_FREQME_REF_SCALE must be in range 0..24 (the 31-bit result counter overflows above 24)."
#endif

/* Marker values for the descriptor/mapping tables below. */
#define CLOCK_FREQME_REF_IS_SXOSC (0xFFU) /* reference is the crystal; no pre-measurement */
#define CLOCK_FREQME_TAR_NONE     (0xFFU) /* root has no FREQME target tap */

/* Per-domain FREQME resources (the domain table itself lives in
 * CLOCK_FreqmeMeasure, its only user). refMux selects the domain reference on
 * the FREQMEAS REF mux; sysconTarRef is the SYSCON FREQMEAS TAR value tapping
 * the node-identical signal used to pre-measure that reference (mux values
 * match fsl_inputmux_connections.h). refRoot names the reference's root for
 * the crystal-referenced domains. */
typedef struct
{
    FREQME_Type   *freqme;
    INPUTMUX_Type *inputmux;
    clock_lpcg_t   gate;         /* one LPCG covers the domain FREQME + INPUTMUX */
    uint8_t        refMux;
    uint8_t        sysconTarRef;
    clock_root_t   refRoot;      /* used only when sysconTarRef == CLOCK_FREQME_REF_IS_SXOSC */
} clock_freqme_domain_t;

enum
{
    kCLOCK_FreqmeDomainSyscon = 0,
    kCLOCK_FreqmeDomainCmpt,
    kCLOCK_FreqmeDomainMain,
    kCLOCK_FreqmeDomainWake,
    kCLOCK_FreqmeDomainComm,
    kCLOCK_FreqmeDomainAudio,
    kCLOCK_FreqmeDomainMedia,
};

/* root -> domain FREQMEAS TAR mux value, one table per subsystem range,
 * indexed by (root - kCLOCK_Root_<SS>_START). Values transcribed from
 * fsl_inputmux_connections.h; CLOCK_FREQME_TAR_NONE marks roots without a
 * target tap. The CGU range is formulaic and handled in code (see
 * CLOCK_LocateFreqmeTar).
 *
 * Note: each domain's FREQMEAS mux also has inputs (typically below 16) that
 * are NOT clock-tree roots and therefore have no entry in these tables: XBAR
 * event outputs (hsp_ss_xbar0_out*) and silicon test/monitor signals such as
 * the pm_104* process-monitor ring oscillators (LVT/SLVT speed-grade and
 * HTOL aging monitors), the WAKE buck/lposc test buses, and the COMM usbphy
 * test clocks. Those signals have no clock_root_t identity and no
 * theoretical frequency to compare against; when silicon characterization
 * needs them, measure them with the fsl_freqme + fsl_inputmux drivers using
 * the kINPUTMUX_<SS>_*_ref/_tar connection enums directly. */
static const uint8_t s_cmptRootTar[] = {
    16U, /* cmpt_clk     */ 17U, /* cpu_clk      */ 18U, /* npu_clk      */
    19U, /* systick_clk0 */ 20U, /* systick_clk1 */
};
static const uint8_t s_mainRootTar[] = {
    17U, /* main_clk_divided  */ 21U, /* xspi0_fclk_divided */ 25U, /* xspi1_fclk_divided */
    28U, /* i3c0_fclk         */ 29U, /* lpi2c0_fclk        */ 30U, /* lpi2c1_fclk        */
    31U, /* lpspi0_fclk       */ 32U, /* lpspi1_fclk        */ 33U, /* lpspi2_fclk        */
    34U, /* lpspi3_fclk       */ 35U, /* lpspi4_fclk        */ 36U, /* lpuart0_fclk       */
    37U, /* lpuart1_fclk      */ 38U, /* lpuart2_fclk       */ 39U, /* lpuart3_fclk       */
    40U, /* lpuart4_fclk      */ 41U, /* lpuart5_fclk       */ 42U, /* flexcan0_fclk      */
    43U, /* flexcan1_fclk     */ 44U, /* flexcan2_fclk      */ 45U, /* flexcan_gfclk      */
    46U, /* qtpm0_fclk        */ 47U, /* lpit0_fclk         */ 48U, /* lpit1_fclk         */
    49U, /* adc0_fclk         */ 50U, /* adc1_fclk          */ 51U, /* sinc0_fclk         */
    52U, /* sinc1_fclk        */ 53U, /* flexio0_fclk       */ 54U, /* flexio1_fclk       */
    55U, /* flexio2_fclk      */ 56U, /* tpiu_clk           */ 57U, /* cssi_refclk        */
    58U, /* otp_clk           */ 59U, /* clkout             */ 60U, /* main_fro192m       */
    61U, /* main_ulp32k       */
};
static const uint8_t s_wakeRootTar[] = {
    16U, /* wake_clk     */ 17U, /* wake_sxosc  */ 18U, /* wake_lp1m   */ 19U, /* wake_lp12m  */
    20U, /* wake_ulp32k  */ 21U, /* wake_lpclk  */ 22U, /* i3c0_fclk   */ 23U, /* lpi2c0_fclk */
    24U, /* lpi2c1_fclk  */ 25U, /* lpspi0_fclk */ 26U, /* lpuart0_fclk*/ 27U, /* lpuart1_fclk*/
    28U, /* dmic1_appclk */ 29U, /* qtpm0_fclk  */ 30U, /* lptmr0_fclk */ 31U, /* lptmr1_fclk */
    32U, /* swt0_fclk    */ 33U, /* swt1_fclk   */ 34U, /* ewm_fclk    */ 35U, /* acmp0_fclk  */
    36U, /* acmp1_fclk   */ 37U, /* acmp2_fclk  */ 38U, /* acmp3_fclk  */ 39U, /* acmp0_rrclk */
    40U, /* acmp1_rrclk  */ 41U, /* acmp2_rrclk */ 42U, /* acmp3_rrclk */
};
static const uint8_t s_commRootTar[] = {
    16U,                   /* comm_clk      */
    17U,                   /* comm_ulp32k   */
    18U,                   /* usdhc0_fclk   */
    19U,                   /* usdhc1_fclk   */
    20U,                   /* xspir_rootclk */
    21U,                   /* usb0_phyclk   */
    22U,                   /* usb0_fro48m   */
    23U,                   /* usb1_fclk     */
    24U,                   /* usb0_wakeclk  */
    25U,                   /* eth0_trxclk   */
    26U,                   /* eth0_timerclk */
    27U,                   /* eth1_trxclk   */
    31U,                   /* eth1_timerclk */
    32U,                   /* eth_refclk (eth_tarclk_tar) */
    33U,                   /* xeno0_liwclk  */
    34U,                   /* xeno1_liwclk  */
    35U,                   /* dll_refclk (dll_tarclk_tar) */
};
static const uint8_t s_audioRootTar[] = {
    16U, /* audio_clk  */ 17U, /* dmic0_appclk */ 18U, /* sai0_mclk0   */ 19U, /* sai0_mclk1 */
    20U, /* sai1_mclk0 */ 21U, /* sai1_mclk1   */ 22U, /* sai2_mclk0   */ 23U, /* sai2_mclk1 */
    24U, /* spdif_txclk*/ 25U, /* spdif_cdrclk */ 26U, /* asrc_clk     */
};
static const uint8_t s_mediaRootTar[] = {
    16U, /* media_clk      */ 17U, /* mediapll_clk (mediapll_rootclk_tar)   */
    18U, /* mipicsi_escclk */ 19U, /* mipicsi_clk                           */
    21U, /* mipidsi_escclk_divided                                          */
    24U, /* mipidsi_refclk (mipidsi_tarclk_tar)                             */
    25U, /* mipidsi_clk    */ 26U, /* reformat_fclk (tarormat_fclk_tar)     */
    27U, /* dcpixel_fclk   */ 28U, /* csi_mclkout                           */
};

/*
 * Resolve a root to (measuring domain, FREQMEAS TAR mux value). Returns false
 * for out-of-range roots and roots without a target tap.
 */
static bool CLOCK_LocateFreqmeTar(clock_root_t root, uint32_t *domainIdx, uint8_t *tarMux)
{
    /* Unsigned compare so a stray negative enum cast falls through to the
     * final return false instead of matching the CGU range. */
    if ((uint32_t)root <= (uint32_t)kCLOCK_Root_CGU_END)
    {
        /* CGU roots are tapped by the SYSCON FREQMEAS TAR mux with a formulaic
         * layout (fsl_inputmux_connections.h): roots 0..29 sit at 16..45;
         * root 30 (MAIN_ROOTCLK) is tapped post div+sndDiv at 47
         * (cpu_rootclk_divided -- matching what CLOCK_GetRootClockFreq
         * reports; the post-div-only CPU tap at 46 backs kCLOCK_SRC_CPU);
         * roots 31..48 sit at 50..67. */
        *domainIdx = kCLOCK_FreqmeDomainSyscon;
        if (root <= kCLOCK_Root_CGU_VIDEOPLL_ROOTCLK)
        {
            *tarMux = (uint8_t)((uint32_t)root + 16U);
        }
        else if (root == kCLOCK_Root_CGU_MAIN_ROOTCLK)
        {
            *tarMux = 47U;
        }
        else
        {
            *tarMux = (uint8_t)((uint32_t)root + 19U);
        }
        return true;
    }
    else if ((root >= kCLOCK_Root_CMPT_START) && (root <= kCLOCK_Root_CMPT_END))
    {
        *domainIdx = kCLOCK_FreqmeDomainCmpt;
        *tarMux    = s_cmptRootTar[root - kCLOCK_Root_CMPT_START];
    }
    else if ((root >= kCLOCK_Root_MAIN_START) && (root <= kCLOCK_Root_MAIN_END))
    {
        *domainIdx = kCLOCK_FreqmeDomainMain;
        *tarMux    = s_mainRootTar[root - kCLOCK_Root_MAIN_START];
    }
    else if ((root >= kCLOCK_Root_WAKE_START) && (root <= kCLOCK_Root_WAKE_END))
    {
        *domainIdx = kCLOCK_FreqmeDomainWake;
        *tarMux    = s_wakeRootTar[root - kCLOCK_Root_WAKE_START];
    }
    else if ((root >= kCLOCK_Root_COMM_START) && (root <= kCLOCK_Root_COMM_END))
    {
        *domainIdx = kCLOCK_FreqmeDomainComm;
        *tarMux    = s_commRootTar[root - kCLOCK_Root_COMM_START];
    }
    else if ((root >= kCLOCK_Root_AUDIO_START) && (root <= kCLOCK_Root_AUDIO_END))
    {
        *domainIdx = kCLOCK_FreqmeDomainAudio;
        *tarMux    = s_audioRootTar[root - kCLOCK_Root_AUDIO_START];
    }
    else if ((root >= kCLOCK_Root_MEDIA_START) && (root <= kCLOCK_Root_MEDIA_END))
    {
        *domainIdx = kCLOCK_FreqmeDomainMedia;
        *tarMux    = s_mediaRootTar[root - kCLOCK_Root_MEDIA_START];
    }
    else
    {
        return false;
    }
    return *tarMux != CLOCK_FREQME_TAR_NONE;
}

/*
 * Run one polled FREQME measurement cycle on a domain and convert the result.
 * The domain's FREQME/INPUTMUX access clock is enabled around the cycle and
 * its LPCG_CFG restored afterwards; the measured clock itself is never
 * touched (caller's responsibility -- a gated target shows up as LT_MIN).
 * Returns the frequency in Hz, or 0 with *stat holding the raw CTRLSTAT
 * flags so the caller can tell a too-slow target (LT_MIN) from other errors.
 */
static uint32_t CLOCK_FreqmeMeasureOnce(const clock_freqme_domain_t *dom, uint8_t tarMux,
                                        uint32_t refFreq, uint32_t refScale, uint32_t *stat)
{
    CCM_Type *gateCCM;
    uint32_t  gateIdx;
    uint32_t  savedLpcg;
    uint32_t  timeout;
    uint32_t  result;
    uint32_t  freq = 0U;

    *stat = 0U;

    /* The measurement window is 2^refScale reference cycles; widen the
     * polling bound for scales above 16 (the sizing baseline of
     * FSL_CLOCK_FREQME_TIMEOUT_LOOPS) so long windows (up to ~0.7 s at
     * scale 24 / 24 MHz) are not misreported as timeouts. Saturate rather
     * than wrap if a large user override leaves no headroom for the
     * shift (max shift is 8, scale cap 24). */
    timeout = FSL_CLOCK_FREQME_TIMEOUT_LOOPS;
    if (refScale > 16U)
    {
        if (timeout > (UINT32_MAX >> (refScale - 16U)))
        {
            timeout = UINT32_MAX;
        }
        else
        {
            timeout <<= (refScale - 16U);
        }
    }

    gateCCM   = locateClkGate(dom->gate, &gateIdx);
    if (NULL == gateCCM) { return 0U; }
    savedLpcg = gateCCM->CGC_ROOT[gateIdx].SLICE_CONTROL & CCM_SLICE_CONTROL_LPCG_CFG_MASK;
    CLOCK_EnableClock(dom->gate);

    dom->inputmux->FREQME_REF = INPUTMUX_FREQME_REF_INP(dom->refMux);
    dom->inputmux->FREQME_TAR = INPUTMUX_FREQME_TAR_INP(tarMux);

    /* MIN flags a dead or too-slow target; MAX encodes the 2 GHz device
     * ceiling as a count: (2 GHz / 24 MHz rounded up) << scale. */
    dom->freqme->MIN = CLOCK_FREQME_MIN_EXPECTED;
    dom->freqme->MAX = CLOCK_FREQME_MAX_RATIO << refScale;

    /* Clear stale W1C status flags (CTRLSTAT mirrors the control fields, so
     * plain |= only sets the write-1-to-clear bits). */
    dom->freqme->CTRLSTAT = dom->freqme->CTRLSTAT | FREQME_CTRLSTAT_LT_MIN_STAT_MASK |
                            FREQME_CTRLSTAT_GT_MAX_STAT_MASK | FREQME_CTRLSTAT_RESULT_READY_STAT_MASK;

    /* Configure and start in a single write. CTRL_W is write-only (reading
     * offset 0 returns CTRL_R) -- never read-modify-write it. Frequency
     * measurement mode: PULSE_MODE = 0, continuous mode and interrupts off. */
    dom->freqme->CTRL_W = FREQME_CTRL_W_REF_SCALE(refScale) | FREQME_CTRL_W_MEASURE_IN_PROGRESS_MASK;

    while (((dom->freqme->CTRL_R & FREQME_CTRL_R_MEASURE_IN_PROGRESS_MASK) != 0U) && (timeout > 0U))
    {
        timeout--;
    }

    if ((dom->freqme->CTRL_R & FREQME_CTRL_R_MEASURE_IN_PROGRESS_MASK) != 0U)
    {
        /* Timed out -- reference clock dead; terminate the cycle. */
        dom->freqme->CTRL_W = 0U;
    }
    else
    {
        *stat = dom->freqme->CTRLSTAT;
        if (((*stat & FREQME_CTRLSTAT_RESULT_READY_STAT_MASK) != 0U) &&
            ((*stat & (FREQME_CTRLSTAT_LT_MIN_STAT_MASK | FREQME_CTRLSTAT_GT_MAX_STAT_MASK)) == 0U))
        {
            result = dom->freqme->CTRL_R & FREQME_CTRL_R_RESULT_MASK;
            /* Ftar = (RESULT + 1) * Fref / 2^REF_SCALE
             * (FSL_FEATURE_FREQME_RESULT_CALCULATION_MODE == 1 on RT2660). */
            freq = (uint32_t)((((uint64_t)result + 1ULL) * (uint64_t)refFreq) >> refScale);
        }
    }

    gateCCM->CGC_ROOT[gateIdx].SLICE_CONTROL =
        (gateCCM->CGC_ROOT[gateIdx].SLICE_CONTROL & ~CCM_SLICE_CONTROL_LPCG_CFG_MASK) | savedLpcg;

    return freq;
}

/*
 * Measure one target of a domain: resolve the domain reference frequency
 * (crystal-known, or pre-measured against SXOSC via the SYSCON FREQME), then
 * measure the target, escalating the reference scale on underflow so slow
 * targets against fast references still resolve.
 */
static uint32_t CLOCK_FreqmeMeasure(uint32_t domainIdx, uint8_t tarMux)
{
    static const clock_freqme_domain_t s_freqmeDomains[] = {
        [kCLOCK_FreqmeDomainSyscon] = {SYSCON__FREQME, SYSCON__INPUTMUX, kCLOCK_SYSCON_freqme,
                                       16U /* sxosc_rootclk_ref */, CLOCK_FREQME_REF_IS_SXOSC,
                                       kCLOCK_Root_CGU_SXOSC_ROOTCLK},
        [kCLOCK_FreqmeDomainCmpt]   = {CMPT__FREQME, CMPT__INPUTMUX, kCLOCK_CMPT_freqme,
                                       17U /* cpu_clk_ref */, 46U /* cpu_rootclk_tar */,
                                       kCLOCK_Root_Invalid},
        [kCLOCK_FreqmeDomainMain]   = {MAIN__FREQME, MAIN__INPUTMUX, kCLOCK_MAIN_freqme,
                                       60U /* main_fro192m_ref */,
                                       33U /* fro192m_rootclk_tar */, kCLOCK_Root_Invalid},
        [kCLOCK_FreqmeDomainWake]   = {WAKE__FREQME, WAKE__INPUTMUX, kCLOCK_WAKE_freqme,
                                       17U /* wake_sxosc_ref */, CLOCK_FREQME_REF_IS_SXOSC,
                                       kCLOCK_Root_WAKE_wake_sxosc},
        [kCLOCK_FreqmeDomainComm]   = {COMM__FREQME, COMM__INPUTMUX, kCLOCK_COMM_freqme,
                                       16U /* comm_clk_ref */, 53U /* commbus_rootclk_tar */,
                                       kCLOCK_Root_Invalid},
        [kCLOCK_FreqmeDomainAudio]  = {AUDIO__FREQME, AUDIO__INPUTMUX, kCLOCK_AUDIO_freqme,
                                       16U /* audio_clk_ref */, 52U /* audiobus_rootclk_tar */,
                                       kCLOCK_Root_Invalid},
        [kCLOCK_FreqmeDomainMedia]  = {MEDIA__FREQME, MEDIA__INPUTMUX, kCLOCK_MEDIA_freqme,
                                       16U /* media_clk_ref */, 51U /* mediabus_rootclk_tar */,
                                       kCLOCK_Root_Invalid},
    };
    const clock_freqme_domain_t *dom = &s_freqmeDomains[domainIdx];
    uint32_t refFreq;
    uint32_t scale = FSL_CLOCK_FREQME_REF_SCALE;
    uint32_t stat;
    uint32_t freq;

    if (scale > CLOCK_FREQME_SCALE_MAX)
    {
        scale = CLOCK_FREQME_SCALE_MAX;
    }

    if (dom->sysconTarRef == CLOCK_FREQME_REF_IS_SXOSC)
    {
        /* Crystal-derived reference: the theoretical value is the actual one. */
        refFreq = CLOCK_GetRootClockFreq(dom->refRoot);
    }
    else
    {
        /* Two-level chain: measure this domain's reference against SXOSC
         * first (single-level recursion -- SYSCON is crystal-referenced). */
        refFreq = CLOCK_FreqmeMeasure(kCLOCK_FreqmeDomainSyscon, dom->sysconTarRef);
    }
    if (refFreq == 0U)
    {
        return 0U;
    }

    for (;;)
    {
        freq = CLOCK_FreqmeMeasureOnce(dom, tarMux, refFreq, scale, &stat);
        if ((freq != 0U) || ((stat & FREQME_CTRLSTAT_LT_MIN_STAT_MASK) == 0U) ||
            (scale >= CLOCK_FREQME_SCALE_MAX))
        {
            break;
        }
        /* Underflow: target too slow for this scale -- lengthen the window. */
        scale += 4U;
        if (scale > CLOCK_FREQME_SCALE_MAX)
        {
            scale = CLOCK_FREQME_SCALE_MAX;
        }
    }
    return freq;
}

uint32_t CLOCK_MeasureRootClockFreq(clock_root_t root)
{
    uint32_t domainIdx;
    uint8_t  tarMux;

    if (!CLOCK_LocateFreqmeTar(root, &domainIdx, &tarMux))
    {
        return 0U;
    }
    return CLOCK_FreqmeMeasure(domainIdx, tarMux);
}

uint32_t CLOCK_MeasureClockSrcFreq(clock_name_t name)
{
    uint32_t freq;

    /* kCLOCK_SRC_CPU taps CGU ROOT 30 after the first divider only; SYSCON
     * TAR 46 (cpu_rootclk) taps that same hardware point directly, so no
     * sndDiv backout is needed (contrast CLOCK_GetClockSrcFreq). */
    if (name == kCLOCK_SRC_CPU)
    {
        return CLOCK_FreqmeMeasure(kCLOCK_FreqmeDomainSyscon, 46U);
    }

    if ((uint32_t)name < (uint32_t)kCLOCK_SRC_BOUNDARY)
    {
        clock_root_t root = s_clockSrcRootMap[name];
        if (root == kCLOCK_Root_Invalid)
        {
            return 0U;
        }
        freq = CLOCK_MeasureRootClockFreq(root);

        /* The six Mx sources add a MODCON-controlled /2 after the parent
         * root; the divider is deterministic, so halving the measured parent
         * is exact (same range check as CLOCK_GetClockSrcFreq). */
        if (((uint32_t)name >= (uint32_t)kCLOCK_SRC_MAIN_PERI0_DIV2) &&
            ((uint32_t)name <= (uint32_t)kCLOCK_SRC_COMMPFDX_DIV2) &&
            CLOCK_GetClockSrcDiv2(name))
        {
            freq /= 2U;
        }
        return freq;
    }

    /* Terminal analog/external sources have no FREQMEAS tap; measure the
     * corresponding root alias instead (e.g. kCLOCK_SRC_FRO192M). */
    return 0U;
}

/*******************************************************************************
 * Main/System PLL output enable APIs
 *
 * MainPLL and SysPLL share an identical register layout in PERI_CGUANA.h:
 * PLL1_REG holds Div5/8/10/20 EN at bits 3/5/7/9, PLL2_REG holds
 * Divfrac0/1/2 EN at bits 0/8/16. The mapping table below uses the
 * MAINPLL_* mask constants; SYSPLL_* masks resolve to identical values.
 * The target PLL is selected by a small (pll -> {PLL1_REG offset,
 * PLL2_REG offset}) lookup at runtime.
 *
 * The kCLOCK_MainSysPllOutput_All value toggles all 7 EN bits in one call.
 *
 * Each per-output call does one 32-bit read-modify-write; the _All call
 * does one RMW per involved register (PLL1_REG and PLL2_REG). No PLL
 * bring-up sequencing; no _STS / _LOCK / _READY bit is polled.
 ******************************************************************************/

/* Aggregate masks for the _All variant. MAINPLL_* used; SYSPLL_* are bit-identical. */
#define CLOCK_MAIN_SYS_PLL_PLL1_ALL_MASK                                    \
    (CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV5_EN_MASK  |                   \
     CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV8_EN_MASK  |                   \
     CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV10_EN_MASK |                   \
     CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV20_EN_MASK)

#define CLOCK_MAIN_SYS_PLL_PLL2_ALL_MASK                                    \
    (CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_EN_MASK |                \
     CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_EN_MASK |                \
     CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_EN_MASK)

typedef struct _clock_main_sys_pll_regs
{
    uint16_t pll1_offset; /* offsetof(CGUANA_Type, CGUA_<PLL>_PLL1_REG) */
    uint16_t pll2_offset; /* offsetof(CGUANA_Type, CGUA_<PLL>_PLL2_REG) */
} clock_main_sys_pll_regs_t;

static const clock_main_sys_pll_regs_t s_mainSysPllRegs[kCLOCK_MainSysPll_Count] = {
    [kCLOCK_MainSysPll_Main] = { (uint16_t)offsetof(CGUANA_Type, CGUA_MAINPLL_PLL1_REG),
                                 (uint16_t)offsetof(CGUANA_Type, CGUA_MAINPLL_PLL2_REG) },
    [kCLOCK_MainSysPll_Sys]  = { (uint16_t)offsetof(CGUANA_Type, CGUA_SYSPLL_PLL1_REG),
                                 (uint16_t)offsetof(CGUANA_Type, CGUA_SYSPLL_PLL2_REG) },
};

typedef struct _clock_main_sys_pll_output_map
{
    uint8_t  regIndex; /* 0 = PLL1_REG (Div5/8/10/20), 1 = PLL2_REG (Divfrac0/1/2) */
    uint32_t mask;
} clock_main_sys_pll_output_map_t;

/* Indexed by kCLOCK_MainSysPllOutput_Div5..Divfrac2 (0..6). _All is handled inline. */
static const clock_main_sys_pll_output_map_t s_mainSysPllOutputMap[kCLOCK_MainSysPllOutput_All] = {
    [kCLOCK_MainSysPllOutput_Div5]     = { 0U, CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV5_EN_MASK },
    [kCLOCK_MainSysPllOutput_Div8]     = { 0U, CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV8_EN_MASK },
    [kCLOCK_MainSysPllOutput_Div10]    = { 0U, CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV10_EN_MASK },
    [kCLOCK_MainSysPllOutput_Div20]    = { 0U, CGUANA_CGUA_MAINPLL_PLL1_REG_MAINPLL_DIV20_EN_MASK },
    [kCLOCK_MainSysPllOutput_Divfrac0] = { 1U, CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC0_EN_MASK },
    [kCLOCK_MainSysPllOutput_Divfrac1] = { 1U, CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC1_EN_MASK },
    [kCLOCK_MainSysPllOutput_Divfrac2] = { 1U, CGUANA_CGUA_MAINPLL_PLL2_REG_MAINPLL_DIVFRAC2_EN_MASK },
};

static volatile uint32_t *main_sys_pll_pll1_reg(clock_main_sys_pll_t pll)
{
    return (volatile uint32_t *)((uintptr_t)SYSCON__CGUANA + s_mainSysPllRegs[pll].pll1_offset);
}

static volatile uint32_t *main_sys_pll_pll2_reg(clock_main_sys_pll_t pll)
{
    return (volatile uint32_t *)((uintptr_t)SYSCON__CGUANA + s_mainSysPllRegs[pll].pll2_offset);
}

static volatile uint32_t *main_sys_pll_output_reg(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out)
{
    return (s_mainSysPllOutputMap[out].regIndex == 0U) ? main_sys_pll_pll1_reg(pll)
                                                       : main_sys_pll_pll2_reg(pll);
}

void CLOCK_EnableMainSysPllOutput(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out)
{
    if (((uint32_t)pll >= (uint32_t)kCLOCK_MainSysPll_Count) ||
        ((uint32_t)out >= (uint32_t)kCLOCK_MainSysPllOutput_Count))
    {
        return;
    }
    if (out == kCLOCK_MainSysPllOutput_All)
    {
        *main_sys_pll_pll1_reg(pll) |= CLOCK_MAIN_SYS_PLL_PLL1_ALL_MASK;
        *main_sys_pll_pll2_reg(pll) |= CLOCK_MAIN_SYS_PLL_PLL2_ALL_MASK;
    }
    else
    {
        *main_sys_pll_output_reg(pll, out) |= s_mainSysPllOutputMap[out].mask;
    }
}

void CLOCK_DisableMainSysPllOutput(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out)
{
    if (((uint32_t)pll >= (uint32_t)kCLOCK_MainSysPll_Count) ||
        ((uint32_t)out >= (uint32_t)kCLOCK_MainSysPllOutput_Count))
    {
        return;
    }
    if (out == kCLOCK_MainSysPllOutput_All)
    {
        *main_sys_pll_pll1_reg(pll) &= ~CLOCK_MAIN_SYS_PLL_PLL1_ALL_MASK;
        *main_sys_pll_pll2_reg(pll) &= ~CLOCK_MAIN_SYS_PLL_PLL2_ALL_MASK;
    }
    else
    {
        *main_sys_pll_output_reg(pll, out) &= ~s_mainSysPllOutputMap[out].mask;
    }
}

bool CLOCK_IsMainSysPllOutputEnabled(clock_main_sys_pll_t pll, clock_main_sys_pll_output_t out)
{
    if (((uint32_t)pll >= (uint32_t)kCLOCK_MainSysPll_Count) ||
        ((uint32_t)out >= (uint32_t)kCLOCK_MainSysPllOutput_Count))
    {
        return false;
    }
    if (out == kCLOCK_MainSysPllOutput_All)
    {
        return ((*main_sys_pll_pll1_reg(pll) & CLOCK_MAIN_SYS_PLL_PLL1_ALL_MASK) == CLOCK_MAIN_SYS_PLL_PLL1_ALL_MASK) &&
               ((*main_sys_pll_pll2_reg(pll) & CLOCK_MAIN_SYS_PLL_PLL2_ALL_MASK) == CLOCK_MAIN_SYS_PLL_PLL2_ALL_MASK);
    }
    return (*main_sys_pll_output_reg(pll, out) & s_mainSysPllOutputMap[out].mask) != 0U;
}

/*******************************************************************************
 * Audio/Video PLL CLKOUT enable APIs
 *
 * AUDIOPLL_CLKOUT_EN and VIDEOPLL_CLKOUT_EN share the same bit (bit 3 of the
 * respective PLL1_REG); the CLOCK_AV_PLL_CLKOUT_EN_MASK below aliases the
 * AUDIOPLL_* mask constant.
 ******************************************************************************/

static const uint16_t s_avPllPll1RegOffset[kCLOCK_AvPll_Count] = {
    [kCLOCK_AvPll_Audio] = (uint16_t)offsetof(CGUANA_Type, CGUA_AUDIOPLL_PLL1_REG),
    [kCLOCK_AvPll_Video] = (uint16_t)offsetof(CGUANA_Type, CGUA_VIDEOPLL_PLL1_REG),
};

#define CLOCK_AV_PLL_CLKOUT_EN_MASK CGUANA_CGUA_AUDIOPLL_PLL1_REG_AUDIOPLL_CLKOUT_EN_MASK

static volatile uint32_t *av_pll_pll1_reg(clock_av_pll_t pll)
{
    return (volatile uint32_t *)((uintptr_t)SYSCON__CGUANA + s_avPllPll1RegOffset[pll]);
}

void CLOCK_EnableAvPllClkout(clock_av_pll_t pll)
{
    if ((uint32_t)pll >= (uint32_t)kCLOCK_AvPll_Count)
    {
        return;
    }
    *av_pll_pll1_reg(pll) |= CLOCK_AV_PLL_CLKOUT_EN_MASK;
}

void CLOCK_DisableAvPllClkout(clock_av_pll_t pll)
{
    if ((uint32_t)pll >= (uint32_t)kCLOCK_AvPll_Count)
    {
        return;
    }
    *av_pll_pll1_reg(pll) &= ~CLOCK_AV_PLL_CLKOUT_EN_MASK;
}

bool CLOCK_IsAvPllClkoutEnabled(clock_av_pll_t pll)
{
    if ((uint32_t)pll >= (uint32_t)kCLOCK_AvPll_Count)
    {
        return false;
    }
    return (*av_pll_pll1_reg(pll) & CLOCK_AV_PLL_CLKOUT_EN_MASK) != 0U;
}

#if defined(CLOCK_ENABLE_INFO_DUMP) && CLOCK_ENABLE_INFO_DUMP
/*!
 * @brief Dump a clock-root capability table to the debug console.
 *
 * See fsl_clock.h for the full API contract.
 */
void CLOCK_InfoDump(void)
{
    /* Flat lookup table: index == clock_root_t enum value, NULL for gaps.
     * Max enum value is kCLOCK_Root_MEDIA_csi_mclkout = 217. */
    static const char * const s_rootNames[218] = {
        /* CGU  0-52 */
        [0]   = "CGU_SXOSC_ROOTCLK",
        [1]   = "CGU_BASE_CLK",
        [2]   = "CGU_LOW_CLK",
        [3]   = "CGU_MAINPLL_DIVX",
        [4]   = "CGU_SYSPLL_DIVX",
        [5]   = "CGU_PLL_PFDX",
        [6]   = "CGU_MEDIA_PFDX",
        [7]   = "CGU_MAINPFDX_ROOTCLK",
        [8]   = "CGU_COMMPFDX_ROOTCLK",
        [9]   = "CGU_MAINDIVX_ROOTCLK",
        [10]  = "CGU_SAIMCLK_ROOTCLK",
        [11]  = "CGU_SAIMCLK0_ROOTCLK",
        [12]  = "CGU_SAIMCLK1_ROOTCLK",
        [13]  = "CGU_SAIMCLK2_ROOTCLK",
        [14]  = "CGU_LP12M_CORE_ROOTCLK",
        [15]  = "CGU_LP1M_CORE_ROOTCLK",
        [16]  = "CGU_ULP32K_ROOTCLK",
        [17]  = "CGU_FRO192M_ROOTCLK",
        [18]  = "CGU_FRO96M_ROOTCLK",
        [19]  = "CGU_FRO48M_ROOTCLK",
        [20]  = "CGU_FRO24M_ROOTCLK",
        [21]  = "CGU_SYSPLLDIV4_ROOTCLK",
        [22]  = "CGU_SYSPLLDIV5_ROOTCLK",
        [23]  = "CGU_SYSPLLDIVX_ROOTCLK",
        [24]  = "CGU_MAINPLLDIVX_ROOTCLK",
        [25]  = "CGU_MAINPLLDIV8_ROOTCLK",
        [26]  = "CGU_MAINPLLDIV10_ROOTCLK",
        [27]  = "CGU_MAINPLLDIV20_ROOTCLK",
        [28]  = "CGU_AUDIOPLL_ROOTCLK",
        [29]  = "CGU_VIDEOPLL_ROOTCLK",
        [30]  = "CGU_MAIN_ROOTCLK",
        [31]  = "CGU_NPU_ROOTCLK",
        [32]  = "CGU_MEDIABUS_ROOTCLK",
        [33]  = "CGU_AUDIOBUS_ROOTCLK",
        [34]  = "CGU_COMMBUS_ROOTCLK",
        [35]  = "CGU_WAKEBUS_ROOTCLK",
        [36]  = "CGU_SYSCON_PDMAIN_CLK",
        [37]  = "CGU_PERI_ROOTCLK0",
        [38]  = "CGU_PERI_ROOTCLK1",
        [39]  = "CGU_PERI_ROOTCLK2",
        [40]  = "CGU_PERI_ROOTCLK3",
        [41]  = "CGU_PERI_ROOTCLK4",
        [42]  = "CGU_PERI_ROOTCLK5",
        [43]  = "CGU_PERI_ROOTCLK6",
        [44]  = "CGU_PERI_ROOTCLK7",
        [45]  = "CGU_AUDIO_ROOTCLK",
        [46]  = "CGU_VIDEO_ROOTCLK",
        [47]  = "CGU_USB1_ROOTCLK",
        [48]  = "CGU_ETH_ROOTCLK",
        [49]  = "CGU_TEST_ROOTCLK",
        [50]  = "CGU_CLKOUT",
        [51]  = "CGU_MAIN_FRO192M",
        [52]  = "CGU_MAIN_ULP32K",
        /* 53-63 gap */
        /* CMPT 64-68 */
        [64]  = "CMPT_cmpt_clk",
        [65]  = "CMPT_cpu_clk",
        [66]  = "CMPT_npu_clk",
        [67]  = "CMPT_systick_clk0",
        [68]  = "CMPT_systick_clk1",
        /* 69-79 gap */
        /* MAIN 80-116 */
        [80]  = "MAIN_main_clk_divided",
        [81]  = "MAIN_xspi0_fclk_divided",
        [82]  = "MAIN_xspi1_fclk_divided",
        [83]  = "MAIN_i3c0_fclk",
        [84]  = "MAIN_lpi2c0_fclk",
        [85]  = "MAIN_lpi2c1_fclk",
        [86]  = "MAIN_lpspi0_fclk",
        [87]  = "MAIN_lpspi1_fclk",
        [88]  = "MAIN_lpspi2_fclk",
        [89]  = "MAIN_lpspi3_fclk",
        [90]  = "MAIN_lpspi4_fclk",
        [91]  = "MAIN_lpuart0_fclk",
        [92]  = "MAIN_lpuart1_fclk",
        [93]  = "MAIN_lpuart2_fclk",
        [94]  = "MAIN_lpuart3_fclk",
        [95]  = "MAIN_lpuart4_fclk",
        [96]  = "MAIN_lpuart5_fclk",
        [97]  = "MAIN_flexcan0_fclk",
        [98]  = "MAIN_flexcan1_fclk",
        [99]  = "MAIN_flexcan2_fclk",
        [100] = "MAIN_flexcan_gfclk",
        [101] = "MAIN_qtpm0_fclk",
        [102] = "MAIN_lpit0_fclk",
        [103] = "MAIN_lpit1_fclk",
        [104] = "MAIN_adc0_fclk",
        [105] = "MAIN_adc1_fclk",
        [106] = "MAIN_sinc0_fclk",
        [107] = "MAIN_sinc1_fclk",
        [108] = "MAIN_flexio0_fclk",
        [109] = "MAIN_flexio1_fclk",
        [110] = "MAIN_flexio2_fclk",
        [111] = "MAIN_tpiu_clk",
        [112] = "MAIN_cssi_refclk",
        [113] = "MAIN_otp_clk",
        [114] = "MAIN_clkout",
        [115] = "MAIN_fro192m",
        [116] = "MAIN_ulp32k",
        /* 117-127 gap */
        /* WAKE 128-154 */
        [128] = "WAKE_wake_clk",
        [129] = "WAKE_wake_sxosc",
        [130] = "WAKE_wake_lp1m",
        [131] = "WAKE_wake_lp12m",
        [132] = "WAKE_wake_ulp32k",
        [133] = "WAKE_wake_lpclk",
        [134] = "WAKE_i3c0_fclk",
        [135] = "WAKE_lpi2c0_fclk",
        [136] = "WAKE_lpi2c1_fclk",
        [137] = "WAKE_lpspi0_fclk",
        [138] = "WAKE_lpuart0_fclk",
        [139] = "WAKE_lpuart1_fclk",
        [140] = "WAKE_dmic1_appclk",
        [141] = "WAKE_qtpm0_fclk",
        [142] = "WAKE_lptmr0_fclk",
        [143] = "WAKE_lptmr1_fclk",
        [144] = "WAKE_swt0_fclk",
        [145] = "WAKE_swt1_fclk",
        [146] = "WAKE_ewm_fclk",
        [147] = "WAKE_acmp0_fclk",
        [148] = "WAKE_acmp1_fclk",
        [149] = "WAKE_acmp2_fclk",
        [150] = "WAKE_acmp3_fclk",
        [151] = "WAKE_acmp0_rrclk",
        [152] = "WAKE_acmp1_rrclk",
        [153] = "WAKE_acmp2_rrclk",
        [154] = "WAKE_acmp3_rrclk",
        /* 155-159 gap */
        /* COMM 160-176 */
        [160] = "COMM_comm_clk",
        [161] = "COMM_comm_ulp32k",
        [162] = "COMM_usdhc0_fclk",
        [163] = "COMM_usdhc1_fclk",
        [164] = "COMM_xspir_rootclk",
        [165] = "COMM_usb0_phyclk",
        [166] = "COMM_usb0_fro48m",
        [167] = "COMM_usb1_fclk",
        [168] = "COMM_usb0_wakeclk",
        [169] = "COMM_eth0_trxclk",
        [170] = "COMM_eth0_timerclk",
        [171] = "COMM_eth1_trxclk",
        [172] = "COMM_eth1_timerclk",
        [173] = "COMM_eth_refclk",
        [174] = "COMM_xeno0_liwclk",
        [175] = "COMM_xeno1_liwclk",
        [176] = "COMM_dll_refclk",
        /* 177-191 gap */
        /* AUDIO 192-202 */
        [192] = "AUDIO_audio_clk",
        [193] = "AUDIO_dmic0_appclk",
        [194] = "AUDIO_sai0_mclk0",
        [195] = "AUDIO_sai0_mclk1",
        [196] = "AUDIO_sai1_mclk0",
        [197] = "AUDIO_sai1_mclk1",
        [198] = "AUDIO_sai2_mclk0",
        [199] = "AUDIO_sai2_mclk1",
        [200] = "AUDIO_spdif_txclk",
        [201] = "AUDIO_spdif_cdrclk",
        [202] = "AUDIO_asrc_clk",
        /* 203-207 gap */
        /* MEDIA 208-217 */
        [208] = "MEDIA_media_clk",
        [209] = "MEDIA_mediapll_clk",
        [210] = "MEDIA_mipicsi_escclk",
        [211] = "MEDIA_mipicsi_clk",
        [212] = "MEDIA_mipidsi_escclk_divided",
        [213] = "MEDIA_mipidsi_refclk",
        [214] = "MEDIA_mipidsi_clk",
        [215] = "MEDIA_reformat_fclk",
        [216] = "MEDIA_dcpixel_fclk",
        [217] = "MEDIA_csi_mclkout",
    };

    clock_root_t root;
    uint32_t     index;
    CCM_Type    *targetCCM;
    uint32_t     status1;

    /* Table header */
    PRINTF("%-4s  %-32s  %-11s  %-10s  %-8s  %-13s  %-11s\r\n",
           "id", "name", "glitch_free", "divPresent", "divWidth",
           "sndDivPresent", "sndDivWidth");
    PRINTF("----  --------------------------------  -----------  ----------  --------  -------------  -----------\r\n");

    for (root = kCLOCK_Root_CGU_START; root <= kCLOCK_Root_MEDIA_END; root++)
    {
        targetCCM = locateClkRoot(root, &index);
        if (targetCCM == NULL)
        {
            continue;
        }
        status1 = targetCCM->CLOCK_ROOT[index].STATUS1;

        bool     glitchFree = (status1 & CCM_STATUS1_GLITCH_FREE_MASK)            != 0UL;
        bool     divPresent = (status1 & CCM_STATUS1_DIVIDER_PRESENT_MASK)        != 0UL;
        uint32_t divWidth   = (status1 & CCM_STATUS1_DIV_WIDTH_MASK)
                              >> CCM_STATUS1_DIV_WIDTH_SHIFT;
        bool     sndPresent = (status1 & CCM_STATUS1_SECOND_DIVIDER_PRESENT_MASK) != 0UL;
        uint32_t sndWidth   = (status1 & CCM_STATUS1_SECOND_DIV_WIDTH_MASK)
                              >> CCM_STATUS1_SECOND_DIV_WIDTH_SHIFT;

        const char *name = ((uint32_t)root < 218U && s_rootNames[(uint32_t)root] != NULL)
                           ? s_rootNames[(uint32_t)root] : "?";

        PRINTF("%-4u  %-4u  %-32s  %-11s  %-10s  %-8u  %-13s  %-11u\r\n",
               (unsigned)root, index, name,
               glitchFree ? "yes" : "no",
               divPresent ? "yes" : "no",
               (unsigned)divWidth,
               sndPresent ? "yes" : "no",
               (unsigned)sndWidth);
    }
}
#endif
