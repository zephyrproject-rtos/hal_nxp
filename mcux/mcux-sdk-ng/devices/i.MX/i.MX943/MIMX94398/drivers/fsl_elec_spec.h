/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================*/
/*!
 * @file
 * @brief
 *
 * Header file containing definitions for the SoC electrical specification.
 *
 * @{
 */
/*==========================================================================*/

#ifndef FSL_ELEC_SPEC_H
#define FSL_ELEC_SPEC_H

/* Defines */

/* Base definitions for clock rates */
#define ES_133KHZ                   133333U
#define ES_167KHZ                   166667U
#define ES_200KHZ                   200000U
#define ES_250KHZ                   250000U
#define ES_333KHZ                   333333U
#define ES_400KHZ                   400000U
#define ES_500KHZ                   500000U
#define ES_533KHZ                   533333U
#define ES_667KHZ                   666667U
#define ES_750KHZ                   750000U
#define ES_800KHZ                   800000U
#define ES_900KHZ                   900000U
#define ES_1000KHZ                  1000000U
#define ES_1067KHZ                  1066667U
#define ES_1170KHZ                  1170000U
#define ES_1404KHZ                  1404000U
#define ES_1500KHZ                  1500000U
#define ES_1670KHZ                  1670000U
#define ES_1800KHZ                  1800000U
#define ES_2004KHZ                  2004000U

#define ES_10MHZ                    10000000ULL
#define ES_24MHZ                    24000000ULL
#define ES_50MHZ                    50000000ULL
#define ES_64MHZ                    64000000ULL
#define ES_67MHZ                    66666667ULL
#define ES_80MHZ                    80000000ULL
#define ES_83MHZ                    83333333ULL
#define ES_100MHZ                   100000000ULL
#define ES_133MHZ                   133333333ULL
#define ES_160MHZ                   160000000ULL
#define ES_200MHZ                   200000000ULL
#define ES_250MHZ                   250000000ULL
#define ES_333MHZ                   333333333ULL
#define ES_350MHZ                   350000000ULL
#define ES_400MHZ                   400000000ULL
#define ES_480MHZ                   480000000ULL
#define ES_500MHZ                   500000000ULL
#define ES_667MHZ                   666666667ULL
#define ES_700MHZ                   700000000ULL
#define ES_800MHZ                   800000000ULL
#define ES_1000MHZ                  1000000000ULL

/* Supply voltage setpoints */
#define ES_SUSPEND_UV_VDD_SOC       650000U
#define ES_LOW_UV_VDD_SOC           750000U
#define ES_NOM_UV_VDD_SOC           800000U
#define ES_ODV_UV_VDD_SOC           900000U

#define ES_LOW_UV_VDD_ARM           750000U
#define ES_NOM_UV_VDD_ARM           800000U
#define ES_ODV_UV_VDD_ARM           900000U
#define ES_SOD_UV_VDD_ARM           1000000U

/* Clock frequency setpoints */
#define ES_LOW_KHZ_ELE              ES_133KHZ
#define ES_NOM_KHZ_ELE              ES_200KHZ
#define ES_ODV_KHZ_ELE              ES_250KHZ

#define ES_LOW_KHZ_M33              ES_167KHZ
#define ES_NOM_KHZ_M33              ES_250KHZ
#define ES_ODV_KHZ_M33              ES_333KHZ

#define ES_LOW_KHZ_M7               ES_400KHZ
#define ES_NOM_KHZ_M7               ES_667KHZ
#define ES_ODV_KHZ_M7               ES_800KHZ

#define ES_LOW_KHZ_WAKEUP           ES_200KHZ
#define ES_NOM_KHZ_WAKEUP           ES_333KHZ /* <= 312.5MHz with 2.5MHz MDC/MDIO */
#define ES_ODV_KHZ_WAKEUP           ES_400KHZ

#define ES_LOW_KHZ_A55              ES_900KHZ
#define ES_NOM_KHZ_A55              ES_1404KHZ
#define ES_ODV_KHZ_A55              ES_1800KHZ
#define ES_SOD_KHZ_A55              ES_2004KHZ

#define ES_LOW_KHZ_A55DSU           ES_750KHZ
#define ES_NOM_KHZ_A55DSU           ES_1170KHZ
#define ES_ODV_KHZ_A55DSU           ES_1500KHZ
#define ES_SOD_KHZ_A55DSU           ES_1670KHZ

#define ES_LOW_KHZ_A55PER           ES_200KHZ
#define ES_NOM_KHZ_A55PER           ES_333KHZ
#define ES_ODV_KHZ_A55PER           ES_400KHZ
#define ES_SOD_KHZ_A55PER           ES_500KHZ

#define ES_LOW_KHZ_DRAM             ES_533KHZ
#define ES_NOM_KHZ_DRAM             ES_800KHZ
#define ES_ODV_KHZ_DRAM             ES_1067KHZ

#define ES_LOW_KHZ_HSIO             ES_250KHZ
#define ES_NOM_KHZ_HSIO             ES_400KHZ
#define ES_ODV_KHZ_HSIO             ES_500KHZ

#define ES_LOW_KHZ_NPU              ES_500KHZ
#define ES_NOM_KHZ_NPU              ES_800KHZ
#define ES_ODV_KHZ_NPU              ES_1000KHZ

#define ES_LOW_KHZ_NOC              ES_400KHZ
#define ES_NOM_KHZ_NOC              ES_667KHZ
#define ES_ODV_KHZ_NOC              ES_800KHZ

#define ES_LOW_KHZ_GPU              ES_500KHZ
#define ES_NOM_KHZ_GPU              ES_800KHZ
#define ES_ODV_KHZ_GPU              ES_1000KHZ

#define ES_LOW_KHZ_VPU              ES_333KHZ
#define ES_NOM_KHZ_VPU              ES_500KHZ
#define ES_ODV_KHZ_VPU              ES_667KHZ

#define ES_LOW_KHZ_CAM              ES_400KHZ
#define ES_NOM_KHZ_CAM              ES_667KHZ
#define ES_ODV_KHZ_CAM              ES_800KHZ

#define ES_LOW_KHZ_DISP             ES_400KHZ
#define ES_NOM_KHZ_DISP             ES_667KHZ
#define ES_ODV_KHZ_DISP             ES_800KHZ

/* PLL frequency limits */
#define ES_MIN_HZ_PLLVCO            2520000000ULL   /* 2.5GHz rounded to 24M */
#define ES_MAX_HZ_PLLVCO            4992000000ULL   /* 5.0GHz rounded to 24M */

/* PLL output = VCO_MIN / ODIV
 * where ODIV = {2 - 255}
 *
 * MIN = (VCO_MIN) / 255
 *
 * MAX = (VCO_MAX) / 2
 */
#define ES_MIN_HZ_PLLOUT            ((ES_MIN_HZ_PLLVCO+254ULL)/255ULL)
#define ES_MAX_HZ_PLLOUT            ((ES_MAX_HZ_PLLVCO)/2ULL)

#define ES_MIN_HZ_ARMPLL            ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_ARMPLL            ES_MAX_HZ_PLLOUT

#define ES_MIN_HZ_SYSPLL            ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_SYSPLL            ES_MAX_HZ_PLLOUT

/* PFD output = VCO / (MFI + (MFN / 5))
 * where MFI = {2 - 255}
 *       MFN = {0 - 4}
 *
 * MIN = (VCO_MIN) / (255 + (4 / 5))
 *     = (VCO_MIN * 5) / (255*5 + 4)
 *     = (VCO_MIN * 5) / 1279
 *
 * MAX = (VCO_MAX) / (2 + (0 / 5))
 *     = (VCO_MAX) / 2
 */
#define ES_MIN_HZ_PFD              (((ES_MIN_HZ_PLLVCO*5ULL)+1278ULL)/(1279ULL))
#define ES_MAX_HZ_PFD              (ES_MAX_HZ_PLLVCO/2ULL)

#define ES_MIN_HZ_DRAMPLL          ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_DRAMPLL          ES_MAX_HZ_PLLOUT

#define ES_MIN_HZ_AUDIOPLL         ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_AUDIOPLL         ES_MAX_HZ_PLLOUT

#define ES_MIN_HZ_VIDEOPLL         ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_VIDEOPLL         ES_MAX_HZ_PLLOUT

#define ES_MIN_HZ_HSIOPLL          ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_HSIOPLL          ES_MAX_HZ_PLLOUT

#define ES_MIN_HZ_LDBPLL           ES_MIN_HZ_PLLOUT
#define ES_MAX_HZ_LDBPLL           ES_MAX_HZ_PLLOUT

/* CCM clock source frequency limits */
#define ES_MIN_HZ_GND              0ULL
#define ES_MAX_HZ_GND              0ULL

#define ES_MIN_HZ_OSC32K           32768ULL
#define ES_MAX_HZ_OSC32K           32768ULL

#define ES_MIN_HZ_OSC24M           ES_24MHZ
#define ES_MAX_HZ_OSC24M           ES_24MHZ

#define ES_MIN_HZ_FRO              ES_200MHZ
#define ES_MAX_HZ_FRO              ES_400MHZ

#define ES_MIN_HZ_EXT1             0ULL
#define ES_MAX_HZ_EXT1             ES_133MHZ

/* CCM clock root frequency limits */

/* Specify root minimum as
 * ROOT = OSC24M / MAX_DIV
 *      = 24000000Hz / 256
 *      = 93750Hz
 *      = 94KHz
 */
#define ES_MIN_HZ_ROOT              93750ULL
#define ES_MAX_HZ_ROOT_UNSPEC       ES_133MHZ

#define ES_MIN_HZ_ADC               ES_MIN_HZ_ROOT
#define ES_MIN_HZ_BUSAON            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CAN1              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_GLITCHFILTER      ES_MIN_HZ_ROOT
#define ES_MIN_HZ_GPT1              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_I3C1SLOW          ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C1            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C2            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI1            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI2            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPTMR1            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART1           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART2           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_M33               ES_MIN_HZ_ROOT
#define ES_MIN_HZ_M33SYSTICK        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_PDM               ES_MIN_HZ_ROOT
#define ES_MIN_HZ_SAI1              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_TPM2              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_A55               ES_MIN_HZ_ROOT
#define ES_MIN_HZ_A55MTRBUS         ES_MIN_HZ_ROOT
#define ES_MIN_HZ_A55PERIPH         ES_MIN_HZ_ROOT
#define ES_MIN_HZ_DRAMALT           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_DRAMAPB           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_DISPAPB           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_DISPAXI           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_DISPPIX           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOACSCAN480M    ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOACSCAN80M     ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIO              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOPCIEAUX       ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOPCIETEST160M  ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOPCIETEST400M  ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOPCIETEST500M  ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOPCIETEST50M   ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HSIOUSBTEST60M    ES_MIN_HZ_ROOT
#define ES_MIN_HZ_BUSM7             ES_MIN_HZ_ROOT
#define ES_MIN_HZ_M7                ES_MIN_HZ_ROOT
#define ES_MIN_HZ_M7SYSTICK         ES_MIN_HZ_ROOT
#define ES_MIN_HZ_BUSNETCMIX        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ECAT              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENET              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETPHYTEST200M   ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETPHYTEST500M   ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETPHYTEST667M   ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETREF           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETTIMER1        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETTIMER2        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENETTIMER3        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_FLEXIO3           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_FLEXIO4           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_M33SYNC           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_M33SYNCSYSTICK    ES_MIN_HZ_ROOT
#define ES_MIN_HZ_MAC0              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_MAC1              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_MAC2              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_MAC3              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_MAC4              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_MAC5              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_NOCAPB            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_NOC               ES_MIN_HZ_ROOT
#define ES_MIN_HZ_NPUAPB            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_NPU               ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CCMCKO1           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CCMCKO2           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CCMCKO3           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CCMCKO4           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CCMWAKEUPMIXBISS  ES_MIN_HZ_ROOT
#define ES_MIN_HZ_BUSWAKEUP         ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CAN2              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CAN3              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CAN4              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_CAN5              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENDAT21           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENDAT22           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENDAT31FAST       ES_MIN_HZ_ROOT
#define ES_MIN_HZ_ENDAT31SLOW       ES_MIN_HZ_ROOT
#define ES_MIN_HZ_FLEXIO1           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_FLEXIO2           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_GPT2              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_GPT3              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_GPT4              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HIPERFACE1        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HIPERFACE1SYNC    ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HIPERFACE2        ES_MIN_HZ_ROOT
#define ES_MIN_HZ_HIPERFACE2SYNC    ES_MIN_HZ_ROOT
#define ES_MIN_HZ_I3C2SLOW          ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C3            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C4            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C5            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C6            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C7            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPI2C8            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI3            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI4            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI5            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI6            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI7            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPSPI8            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPTMR2            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART10          ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART11          ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART12          ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART3           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART4           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART5           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART6           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART7           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART8           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_LPUART9           ES_MIN_HZ_ROOT
#define ES_MIN_HZ_SAI2              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_SAI3              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_SAI4              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_SWOTRACE          ES_MIN_HZ_ROOT
#define ES_MIN_HZ_TPM4              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_TPM5              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_TPM6              ES_MIN_HZ_ROOT
#define ES_MIN_HZ_USBPHYBURUNIN     ES_MIN_HZ_ROOT
#define ES_MIN_HZ_USDHC1            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_USDHC2            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_USDHC3            ES_MIN_HZ_ROOT
#define ES_MIN_HZ_V2XPK             ES_MIN_HZ_ROOT
#define ES_MIN_HZ_WAKEUPAXI         ES_MIN_HZ_ROOT
#define ES_MIN_HZ_XSPISLVROOT       ES_MIN_HZ_ROOT
#define ES_MIN_HZ_XSPI1             ES_MIN_HZ_ROOT
#define ES_MIN_HZ_XSPI2             ES_MIN_HZ_ROOT

#define ES_MAX_HZ_ADC               ES_80MHZ
#define ES_MAX_HZ_BUSAON            ES_133MHZ
#define ES_MAX_HZ_CAN1              ES_80MHZ
#define ES_MAX_HZ_GLITCHFILTER      ES_80MHZ
#define ES_MAX_HZ_GPT1              ES_24MHZ
#define ES_MAX_HZ_I3C1SLOW          ES_24MHZ
#define ES_MAX_HZ_LPI2C1            ES_133MHZ
#define ES_MAX_HZ_LPI2C2            ES_133MHZ
#define ES_MAX_HZ_LPSPI1            ES_133MHZ
#define ES_MAX_HZ_LPSPI2            ES_133MHZ
#define ES_MAX_HZ_LPTMR1            ES_80MHZ
#define ES_MAX_HZ_LPUART1           ES_133MHZ
#define ES_MAX_HZ_LPUART2           ES_133MHZ
#define ES_MAX_HZ_M33               ES_333MHZ
#define ES_MAX_HZ_M33SYSTICK        ES_24MHZ
#define ES_MAX_HZ_PDM               ES_200MHZ
#define ES_MAX_HZ_SAI1              ES_67MHZ
#define ES_MAX_HZ_TPM2              ES_83MHZ
#define ES_MAX_HZ_A55               ES_1000MHZ
#define ES_MAX_HZ_A55MTRBUS         ES_133MHZ
#define ES_MAX_HZ_A55PERIPH         ES_400MHZ
#define ES_MAX_HZ_DRAMALT           ES_667MHZ
#define ES_MAX_HZ_DRAMAPB           ES_133MHZ
#define ES_MAX_HZ_DISPAPB           ES_133MHZ
#define ES_MAX_HZ_DISPAXI           ES_800MHZ
#define ES_MAX_HZ_DISPPIX           ES_667MHZ
#define ES_MAX_HZ_HSIOACSCAN480M    ES_480MHZ
#define ES_MAX_HZ_HSIOACSCAN80M     ES_80MHZ
#define ES_MAX_HZ_HSIO              ES_500MHZ
#define ES_MAX_HZ_HSIOPCIEAUX       ES_10MHZ
#define ES_MAX_HZ_HSIOPCIETEST160M  ES_160MHZ
#define ES_MAX_HZ_HSIOPCIETEST400M  ES_400MHZ
#define ES_MAX_HZ_HSIOPCIETEST500M  ES_500MHZ
#define ES_MAX_HZ_HSIOUSBTEST50M    ES_50MHZ
#define ES_MAX_HZ_HSIOUSBTEST60M    62500000ULL
#define ES_MAX_HZ_BUSM7             ES_133MHZ
#define ES_MAX_HZ_M7                ES_800MHZ
#define ES_MAX_HZ_M7SYSTICK         ES_24MHZ
#define ES_MAX_HZ_BUSNETCMIX        ES_133MHZ
#define ES_MAX_HZ_ECAT              ES_667MHZ
#define ES_MAX_HZ_ENET              ES_667MHZ
#define ES_MAX_HZ_ENETPHYTEST200M   ES_200MHZ
#define ES_MAX_HZ_ENETPHYTEST500M   ES_500MHZ
#define ES_MAX_HZ_ENETPHYTEST667M   ES_667MHZ
#define ES_MAX_HZ_ENETREF           ES_250MHZ
#define ES_MAX_HZ_ENETTIMER1        ES_100MHZ
#define ES_MAX_HZ_ENETTIMER2        ES_100MHZ
#define ES_MAX_HZ_ENETTIMER3        ES_100MHZ
#define ES_MAX_HZ_FLEXIO3           ES_80MHZ
#define ES_MAX_HZ_FLEXIO4           ES_80MHZ
#define ES_MAX_HZ_M33SYNC           ES_333MHZ
#define ES_MAX_HZ_M33SYNCSYSTICK    ES_24MHZ
#define ES_MAX_HZ_MAC0              ES_24MHZ
#define ES_MAX_HZ_MAC1              ES_24MHZ
#define ES_MAX_HZ_MAC2              ES_24MHZ
#define ES_MAX_HZ_MAC3              ES_24MHZ
#define ES_MAX_HZ_MAC4              ES_24MHZ
#define ES_MAX_HZ_MAC5              ES_24MHZ
#define ES_MAX_HZ_NOCAPB            ES_133MHZ
#define ES_MAX_HZ_NOC               ES_800MHZ
#define ES_MAX_HZ_NPUAPB            ES_133MHZ
#define ES_MAX_HZ_NPU               ES_1000MHZ
#define ES_MAX_HZ_CCMCKO1           ES_250MHZ
#define ES_MAX_HZ_CCMCKO2           ES_250MHZ
#define ES_MAX_HZ_CCMCKO3           ES_250MHZ
#define ES_MAX_HZ_CCMCKO4           ES_250MHZ
#define ES_MAX_HZ_CCMWAKEUPMIXBISS  ES_24MHZ
#define ES_MAX_HZ_BUSWAKEUP         ES_133MHZ
#define ES_MAX_HZ_CAN2              ES_80MHZ
#define ES_MAX_HZ_CAN3              ES_80MHZ
#define ES_MAX_HZ_CAN4              ES_80MHZ
#define ES_MAX_HZ_CAN5              ES_80MHZ
#define ES_MAX_HZ_ENDAT21           ES_80MHZ
#define ES_MAX_HZ_ENDAT22           ES_80MHZ
#define ES_MAX_HZ_ENDAT31FAST       ES_80MHZ
#define ES_MAX_HZ_ENDAT31SLOW       ES_80MHZ
#define ES_MAX_HZ_FLEXIO1           ES_80MHZ
#define ES_MAX_HZ_FLEXIO2           ES_80MHZ
#define ES_MAX_HZ_GPT2              ES_24MHZ
#define ES_MAX_HZ_GPT3              ES_24MHZ
#define ES_MAX_HZ_GPT4              ES_24MHZ
#define ES_MAX_HZ_HIPERFACE1        ES_24MHZ
#define ES_MAX_HZ_HIPERFACE1SYNC    ES_24MHZ
#define ES_MAX_HZ_HIPERFACE2        ES_24MHZ
#define ES_MAX_HZ_HIPERFACE2SYNC    ES_24MHZ
#define ES_MAX_HZ_I3C2SLOW          ES_24MHZ
#define ES_MAX_HZ_LPI2C3            ES_133MHZ
#define ES_MAX_HZ_LPI2C4            ES_133MHZ
#define ES_MAX_HZ_LPI2C5            ES_133MHZ
#define ES_MAX_HZ_LPI2C6            ES_133MHZ
#define ES_MAX_HZ_LPI2C7            ES_133MHZ
#define ES_MAX_HZ_LPI2C8            ES_133MHZ
#define ES_MAX_HZ_LPSPI3            ES_133MHZ
#define ES_MAX_HZ_LPSPI4            ES_133MHZ
#define ES_MAX_HZ_LPSPI5            ES_133MHZ
#define ES_MAX_HZ_LPSPI6            ES_133MHZ
#define ES_MAX_HZ_LPSPI7            ES_133MHZ
#define ES_MAX_HZ_LPSPI8            ES_133MHZ
#define ES_MAX_HZ_LPTMR2            ES_80MHZ
#define ES_MAX_HZ_LPUART10          ES_133MHZ
#define ES_MAX_HZ_LPUART11          ES_133MHZ
#define ES_MAX_HZ_LPUART12          ES_133MHZ
#define ES_MAX_HZ_LPUART3           ES_133MHZ
#define ES_MAX_HZ_LPUART4           ES_133MHZ
#define ES_MAX_HZ_LPUART5           ES_133MHZ
#define ES_MAX_HZ_LPUART6           ES_133MHZ
#define ES_MAX_HZ_LPUART7           ES_133MHZ
#define ES_MAX_HZ_LPUART8           ES_133MHZ
#define ES_MAX_HZ_LPUART9           ES_133MHZ
#define ES_MAX_HZ_SAI3              ES_67MHZ
#define ES_MAX_HZ_SAI4              ES_67MHZ
#define ES_MAX_HZ_SAI5              ES_67MHZ
#define ES_MAX_HZ_SWOTRACE          ES_133MHZ
#define ES_MAX_HZ_TPM4              ES_83MHZ
#define ES_MAX_HZ_TPM5              ES_83MHZ
#define ES_MAX_HZ_TPM6              ES_83MHZ
#define ES_MAX_HZ_USBPHYBURUNIN     ES_50MHZ
#define ES_MAX_HZ_USDHC1            ES_400MHZ
#define ES_MAX_HZ_USDHC2            ES_400MHZ
#define ES_MAX_HZ_USDHC3            ES_400MHZ
#define ES_MAX_HZ_V2XPK             ES_800MHZ
#define ES_MAX_HZ_WAKEUPAXI         ES_400MHZ
#define ES_MAX_HZ_XSPISLVROOT       ES_400MHZ
#define ES_MAX_HZ_XSPI1             ES_400MHZ
#define ES_MAX_HZ_XSPI2             ES_400MHZ

#endif /* FSL_ELEC_SPEC_H */

/** @} */

