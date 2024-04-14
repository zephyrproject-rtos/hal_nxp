/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file       Clock_Ip_Cfg.c
*   @version    2.0.0
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
#include "StandardTypes.h"
#include "Clock_Ip_Private.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_CFG_VENDOR_ID_C                      43
#define CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_CFG_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_CFG_SW_MINOR_VERSION_C               0
#define CLOCK_IP_CFG_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes.h file are of the same Autosar version */
#if ((CLOCK_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Cfg.c and StandardTypes.h are different"
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


/* *************************************************************************
 * Configuration structure for Clock Configuration
 * ************************************************************************* */
const Clock_Ip_ClockConfigType Clock_Ip_aClockConfig[1U] = {

    {
        0U,                          /* clkConfigId */

        (NULL_PTR),               /* Register data if register value optimization is enabled */
        2U,                       /* ircoscsCount */
        1U,                       /* xoscsCount */
        1U,                       /* pllsCount */
        32U,                       /* selectorsCount */
        20U,                       /* dividersCount */
        0U,                       /* dividerTriggersCount */
        0U,                       /* fracDivsCount */
        4U,                       /* extClksCount */
        43U,                       /* gatesCount */
        0U,                       /* pcfsCount */
        0U,                       /* cmusCount */
        1U,                       /* configureFrequenciesCount */


        /* IRCOSC initialization. */
        {

            #if CLOCK_IP_IRCOSCS_NO > 0U
            {
                SIRC_CLK,       /* name */
                1U,                     /* Enabled ircosc */
                0U,                     /* Enabled regulator */
                1U,                     /* Ircosc range */
                1U,                     /* Ircosc enable in VLP mode */
                0U,                     /* Ircosc disable in STOP mode */
            },
            #endif

            #if CLOCK_IP_IRCOSCS_NO > 1U
            {
                FIRC_CLK,       /* name */
                1U,                     /* Enabled ircosc */
                0U,                     /* Enabled regulator */
                0U,                     /* Ircosc range */
                0U,                     /* Ircosc disable in VLP mode */
                0U,                     /* Ircosc disable in STOP mode */
            },
            #endif
        },

        /* XOSC initialization. */

        {

            #if CLOCK_IP_XOSCS_NO > 0U
            {
                SOSC_CLK,              /* Clock name associated to xosc */
                8000000U,              /* External oscillator frequency */
                1U,                     /* Enable xosc */
                0U,                   /* Startup stabilization time */
                0U,                     /* XOSC bypass option */
                0U,                   /* Comparator is not enabled */
                0U,                     /* Crystal overdrive protection */
                0U,                     /* High gain value */
                CLOCK_IP_HAS_MONITOR_DISABLE,                     /* Monitor type */
                0U,                     /* Automatic level controller */
            },
            #endif
        },


        /* PLL initialization. */
        {

            #if CLOCK_IP_PLLS_NO > 0U
            {
                SPLL_CLK,                /* name */
                1U,                     /* enable */
                SOSC_CLK,           /* inputReference */
                0U,                     /* Bypass */
                1U,                      /* predivider */
                0U,                      /* multiplier */
                0U,                      /* postdivider */
                0U,                     /* numeratorFracLoopDiv */
                40U,                   /* mulFactorDiv */
                0U,                     /* ModulationBypass */
                0U,                     /* Modulation type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                1U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                CLOCK_IP_HAS_MONITOR_DISABLE,                     /* Monitor type */
                {                      /* Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
        },



        /* SELECTOR initialization. */
        {

            #if CLOCK_IP_SELECTORS_NO > 0U
            {
                SCS_RUN_CLK,                    /* Clock name associated to selector */
                SPLL_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 1U
            {
                SCS_VLPR_CLK,                    /* Clock name associated to selector */
                SIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 2U
            {
                SCS_HSRUN_CLK,                    /* Clock name associated to selector */
                FIRC_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 3U
            {
                SCG_CLKOUT_CLK,                    /* Clock name associated to selector */
                SPLL_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 4U
            {
                RTC_CLK,                    /* Clock name associated to selector */
                LPO_32K_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 5U
            {
                LPO_CLK,                    /* Clock name associated to selector */
                LPO_128K_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 6U
            {
                TRACE_CLK,                    /* Clock name associated to selector */
                CORE_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 7U
            {
                CLKOUT0_CLK,                    /* Clock name associated to selector */
                HCLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 8U
            {
                FTM0_EXT_CLK,                    /* Clock name associated to selector */
                TCLK0_REF_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 9U
            {
                FTM1_EXT_CLK,                    /* Clock name associated to selector */
                TCLK0_REF_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 10U
            {
                FTM2_EXT_CLK,                    /* Clock name associated to selector */
                TCLK0_REF_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 11U
            {
                FTM3_EXT_CLK,                    /* Clock name associated to selector */
                TCLK0_REF_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 12U
            {
                FTM4_EXT_CLK,                    /* Clock name associated to selector */
                TCLK0_REF_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 13U
            {
                FTM5_EXT_CLK,                    /* Clock name associated to selector */
                TCLK0_REF_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 14U
            {
                FTM0_CLK,                    /* Clock name associated to selector */
                SPLLDIV1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 15U
            {
                FTM1_CLK,                    /* Clock name associated to selector */
                SPLLDIV1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 16U
            {
                FTM2_CLK,                    /* Clock name associated to selector */
                SPLLDIV1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 17U
            {
                FTM3_CLK,                    /* Clock name associated to selector */
                SPLLDIV1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 18U
            {
                FTM4_CLK,                    /* Clock name associated to selector */
                SPLLDIV1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 19U
            {
                FTM5_CLK,                    /* Clock name associated to selector */
                SPLLDIV1_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 20U
            {
                ADC1_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 21U
            {
                LPSPI0_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 22U
            {
                LPSPI1_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 23U
            {
                LPSPI2_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 24U
            {
                LPIT0_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 25U
            {
                ADC0_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 26U
            {
                FlexIO_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 27U
            {
                LPI2C0_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 28U
            {
                LPUART0_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 29U
            {
                LPUART1_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 30U
            {
                LPUART2_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif

            #if CLOCK_IP_SELECTORS_NO > 31U
            {
                LPTMR0_CLK,                    /* Clock name associated to selector */
                SPLLDIV2_CLK,                    /* Name of the selected input source */
            },
            #endif
        },


        /* DIVIDER initialization. */

        {

            #if CLOCK_IP_DIVIDERS_NO > 0U
            {
                SIRCDIV1_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 1U
            {
                SIRCDIV2_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 2U
            {
                FIRCDIV1_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 3U
            {
                FIRCDIV2_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 4U
            {
                SOSCDIV1_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 5U
            {
                SOSCDIV2_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 6U
            {
                SPLLDIV1_CLK,                    /* name */
                2U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 7U
            {
                SPLLDIV2_CLK,                    /* name */
                4U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 8U
            {
                CORE_RUN_CLK,                    /* name */
                2U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 9U
            {
                CORE_VLPR_CLK,                    /* name */
                8U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 10U
            {
                CORE_HSRUN_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 11U
            {
                BUS_RUN_CLK,                    /* name */
                2U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 12U
            {
                BUS_VLPR_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 13U
            {
                BUS_HSRUN_CLK,                    /* name */
                1U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 14U
            {
                SLOW_RUN_CLK,                    /* name */
                3U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 15U
            {
                SLOW_VLPR_CLK,                    /* name */
                4U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 16U
            {
                SLOW_HSRUN_CLK,                    /* name */
                2U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 17U
            {
                CLKOUT0_CLK,                    /* name */
                5U,                              /* value */
                {
                    0U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 18U
            {
                LPTMR0_CLK,                    /* name */
                1U,                              /* value */
                {
                    1U,
                }
            },
            #endif

            #if CLOCK_IP_DIVIDERS_NO > 19U
            {
                TRACE_CLK,                    /* name */
                1U,                              /* value */
                {
                    1U,
                }
            },
            #endif
        },

        /* TRIGGER DIVIDER Initialization. */
        {
            {
                RESERVED_CLK,             /* divider name */
                IMMEDIATE_DIVIDER_UPDATE, /* trigger value */
                RESERVED_CLK,             /* input source name */
            },
        },



        /* FRACTIONAL DIVIDER initialization. */
        {
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
        },



        /* EXTERNAL CLOCKS initialization. */
        {

            #if CLOCK_IP_EXT_CLKS_NO > 0U
            {
                TCLK0_REF_CLK,                    /* name */
                0U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 1U
            {
                TCLK1_REF_CLK,                    /* name */
                0U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 2U
            {
                TCLK2_REF_CLK,                    /* name */
                0U,                              /* value */
            },
            #endif

            #if CLOCK_IP_EXT_CLKS_NO > 3U
            {
                RTC_CLKIN,                    /* name */
                32768U,                              /* value */
            },
            #endif
        },



        /* CLOCK GATES initialization. */
        {

            #if CLOCK_IP_GATES_NO > 0U
            {
                LPO_32K_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 1U
            {
                LPO_1K_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 2U
            {
                ADC0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 3U
            {
                ADC1_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 4U
            {
                CLKOUT0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 5U
            {
                CMP0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 6U
            {
                CRC0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 7U
            {
                DMA0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 8U
            {
                DMAMUX0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 9U
            {
                EIM0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 10U
            {
                ERM0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 11U
            {
                EWM0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 12U
            {
                FLEXCAN0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 13U
            {
                FLEXCAN1_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 14U
            {
                FLEXCAN2_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 15U
            {
                FlexIO_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 16U
            {
                FTFC_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 17U
            {
                FTM0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 18U
            {
                FTM1_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 19U
            {
                FTM2_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 20U
            {
                FTM3_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 21U
            {
                FTM4_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 22U
            {
                FTM5_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 23U
            {
                LPI2C0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 24U
            {
                LPIT0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 25U
            {
                LPSPI0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 26U
            {
                LPSPI1_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 27U
            {
                LPSPI2_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 28U
            {
                LPTMR0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 29U
            {
                LPUART0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 30U
            {
                LPUART1_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 31U
            {
                LPUART2_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 32U
            {
                MPU0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 33U
            {
                MSCM0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 34U
            {
                PDB0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 35U
            {
                PDB1_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 36U
            {
                PORTA_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 37U
            {
                PORTB_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 38U
            {
                PORTC_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 39U
            {
                PORTD_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 40U
            {
                PORTE_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 41U
            {
                RTC0_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif

            #if CLOCK_IP_GATES_NO > 42U
            {
                TRACE_CLK,                    /* name */
                1U,                           /* enable */
            },
            #endif
        },


        /* PCFS initialization. */
        {
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
        },


        /* Clock monitor */
        {
            {
                RESERVED_CLK,
                0U,
                0U,
                0U,
                {
                        0U,          /* Start index in register values array */
                        0U,          /* End index in register values array */
                },
            },
        },


        /* Specific peripheral initialization. */
        {
            0U,
            {
                {
                    RESERVED_VALUE,
                    0U,
                },
            },
        },
        /* Configured frequency values. */
        {
            {
                CLOCK_IS_OFF,
                0U,
            },
        },
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
