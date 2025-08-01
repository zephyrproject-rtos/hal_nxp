/*
 * Copyright 2017-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.1.2. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 1, 2))
/*@}*/

/* Definition for delay API in clock driver, users can redefine it to the real application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (32000000UL)
#endif

/*! @brief Configure whether driver controls clock
 *
 * When set to 0, peripheral drivers will enable clock in initialize function
 * and disable clock in de-initialize function. When set to 1, peripheral
 * driver will not control the clock, application could control the clock out of
 * the driver.
 *
 * @note All drivers share this feature switcher. If it is set to 1, application
 * should handle clock enable and disable for all drivers.
 */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0
#endif

enum
{
    kFreq_1MHz  = 1000000u,
    kFreq_12MHz = 12u * kFreq_1MHz,
    kFreq_16MHz = 16u * kFreq_1MHz,
    kFreq_24MHz = 24u * kFreq_1MHz,
    kFreq_32MHz = 32u * kFreq_1MHz,
    kFreq_48MHz = 48u * kFreq_1MHz,
    kFreq_64MHz = 64u * kFreq_1MHz,
};

/*! @brief Clock ip name array for ROM. */
#define ROM_CLOCKS \
    {              \
        kCLOCK_Rom \
    }
/*! @brief Clock ip name array for SRAM. */
#define SRAM_CLOCKS                \
    {                              \
        kCLOCK_Sram1, kCLOCK_Sram2 \
    }
/*! @brief Clock ip name array for FLASH. */
#define FLASH_CLOCKS \
    {                \
        kCLOCK_Flash \
    }
/*! @brief Clock ip name array for FMC. */
#define FMC_CLOCKS \
    {              \
        kCLOCK_Fmc \
    }
/*! @brief Clock ip name array for INPUTMUX. */
#define INPUTMUX_CLOCKS \
    {                   \
        kCLOCK_InputMux \
    }
/*! @brief Clock ip name array for IOCON. */
#define IOCON_CLOCKS \
    {                \
        kCLOCK_Iocon \
    }
/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS  \
    {                \
        kCLOCK_Gpio0 \
    }
/*! @brief Clock ip name array for PINT. */
#define PINT_CLOCKS \
    {               \
        kCLOCK_Pint \
    }
/*! @brief Clock ip name array for GINT. */
#define GINT_CLOCKS \
    {               \
        kCLOCK_Gint \
    }
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS               \
    {                            \
        kCLOCK_Dma0, kCLOCK_Dma1 \
    }
/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS \
    {              \
        kCLOCK_Crc \
    }
/*! @brief Clock ip name array for WWDT. */
#define WWDT_CLOCKS \
    {               \
        kCLOCK_Wwdt \
    }
/*! @brief Clock ip name array for RTC. */
#define RTC_CLOCKS \
    {              \
        kCLOCK_Rtc \
    }
/*! @brief Clock ip name array for MRT. */
#define MRT_CLOCKS \
    {              \
        kCLOCK_Mrt \
    }
/*! @brief Clock ip name array for OSTIMER. */
#define OSTIMER_CLOCKS  \
    {                   \
        kCLOCK_OsTimer0 \
    }
/*! @brief Clock ip name array for SCT0. */
#define SCT_CLOCKS  \
    {               \
        kCLOCK_Sct0 \
    }
/*! @brief Clock ip name array for UTICK. */
#define UTICK_CLOCKS  \
    {                 \
        kCLOCK_Utick0 \
    }
/*! @brief Clock ip name array for FLEXCOMM. */
#define FLEXCOMM_CLOCKS                                      \
    {                                                        \
        kCLOCK_FlexComm0, kCLOCK_FlexComm1, kCLOCK_FlexComm2 \
    }
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                     \
    {                                                     \
        kCLOCK_MinUart0, kCLOCK_MinUart1, kCLOCK_MinUart2 \
    }

/*! @brief Clock ip name array for BI2C. */
#define BI2C_CLOCKS                              \
    {                                            \
        kCLOCK_BI2c0, kCLOCK_BI2c1, kCLOCK_BI2c2 \
    }
/*! @brief Clock ip name array for LSPI. */
#define LPSPI_CLOCKS                             \
    {                                            \
        kCLOCK_LSpi0, kCLOCK_LSpi1, kCLOCK_LSpi2 \
    }
/*! @brief Clock ip name array for CTIMER. */
#define CTIMER_CLOCKS                                                             \
    {                                                                             \
        kCLOCK_Timer0, kCLOCK_Timer1, kCLOCK_Timer2, kCLOCK_Timer3, kCLOCK_Timer4 \
    }
/*! @brief Clock ip name array for BLERADIO. */
#define BLERADIO_CLOCKS \
    {                   \
        kCLOCK_BleRadio \
    }
/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS \
    {                 \
        kCLOCK_Freqme \
    }
/*! @brief Clock ip name array for BLERAM. */
#define BLERAM_CLOCKS \
    {                 \
        kCLOCK_BleRam \
    }
/*! @brief Clock ip name array for RNG. */
#define TRNG_CLOCKS \
    {               \
        kCLOCK_Rng  \
    }
/*! @brief Clock ip name array for HashCrypt. */
#define HASHCRYPT_CLOCKS \
    {                    \
        kCLOCK_HashCrypt \
    }
/*! @brief Clock ip name array for PLULUT. */
#define PLULUT_CLOCKS \
    {                 \
        kCLOCK_PluLut \
    }
/*! @brief Clock ip name array for PUF. */
#define PUF_CLOCKS \
    {              \
        kCLOCK_Puf \
    }
/*! @brief Clock ip name array for CASPER. */
#define CASPER_CLOCKS \
    {                 \
        kCLOCK_Casper \
    }
/*! @brief Clock ip name array for ANALOGCTRL. */
#define ANALOGCTRL_CLOCKS \
    {                     \
        kCLOCK_AnalogCtrl \
    }
/*! @brief Clock ip name array for SPIFI. */
#define SPIFI_CLOCKS \
    {                \
        kCLOCK_Spifi \
    }
/*! @brief Clock ip name array for GPIO_SEC. */
#define GPIO_SEC_CLOCKS \
    {                   \
        kCLOCK_Gpio_Sec \
    }
/*! @brief Clock ip name array for GPIO_SEC_INT. */
#define GPIO_SEC_INT_CLOCKS \
    {                       \
        kCLOCK_Gpio_Sec_Int \
    }
#define PLU_CLOCKS    \
    {                 \
        kCLOCK_PluLut \
    }
#define SYSCTL_CLOCKS \
    {                 \
        kCLOCK_Sysctl \
    }
/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
/*------------------------------------------------------------------------------
 clock_ip_name_t definition:
------------------------------------------------------------------------------*/

#define CLK_GATE_REG_OFFSET_SHIFT 8U
#define CLK_GATE_REG_OFFSET_MASK  0xFFFFFF00U
#define CLK_GATE_BIT_SHIFT_SHIFT  0U
#define CLK_GATE_BIT_SHIFT_MASK   0x000000FFU

#define CLK_GATE_DEFINE(reg_offset, bit_shift)                                  \
    ((((reg_offset) << CLK_GATE_REG_OFFSET_SHIFT) & CLK_GATE_REG_OFFSET_MASK) | \
     (((bit_shift) << CLK_GATE_BIT_SHIFT_SHIFT) & CLK_GATE_BIT_SHIFT_MASK))

#define CLK_GATE_ABSTRACT_REG_OFFSET(x) (((uint32_t)(x)&CLK_GATE_REG_OFFSET_MASK) >> CLK_GATE_REG_OFFSET_SHIFT)
#define CLK_GATE_ABSTRACT_BITS_SHIFT(x) (((uint32_t)(x)&CLK_GATE_BIT_SHIFT_MASK) >> CLK_GATE_BIT_SHIFT_SHIFT)

#define AHB_CLK_CTRL0 0
#define AHB_CLK_CTRL1 1
#define AHB_CLK_CTRL2 2

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
    kCLOCK_IpInvalid    = 0U,
    kCLOCK_Rom          = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_ROM_SHIFT),
    kCLOCK_Sram1        = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_SRAM_CTRL1_SHIFT),
    kCLOCK_Sram2        = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_SRAM_CTRL2_SHIFT),
    kCLOCK_Flash        = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_FLASH_SHIFT),
    kCLOCK_Fmc          = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_FMC_SHIFT),
    kCLOCK_InputMux     = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_MUX_SHIFT),
    kCLOCK_Iocon        = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_IOCON_SHIFT),
    kCLOCK_Gpio0        = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_GPIO0_SHIFT),
    kCLOCK_Pint         = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_PINT_SHIFT),
    kCLOCK_Gint         = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_GINT_SHIFT),
    kCLOCK_Dma0         = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_DMA0_SHIFT),
    kCLOCK_Crc          = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_CRCGEN_SHIFT),
    kCLOCK_Wwdt         = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_WWDT_SHIFT),
    kCLOCK_Rtc          = CLK_GATE_DEFINE(AHB_CLK_CTRL0, SYSCON_AHBCLKCTRL0_RTC_SHIFT),
    kCLOCK_Mrt          = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_MRT_SHIFT),
    kCLOCK_OsTimer0     = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_OSTIMER_SHIFT),
    kCLOCK_Sct0         = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_SCT_SHIFT),
    kCLOCK_Utick0       = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_UTICK_SHIFT),
    kCLOCK_FlexComm0    = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC0_SHIFT),
    kCLOCK_FlexComm1    = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC1_SHIFT),
    kCLOCK_FlexComm2    = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC2_SHIFT),
    kCLOCK_MinUart0     = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC0_SHIFT),
    kCLOCK_MinUart1     = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC1_SHIFT),
    kCLOCK_MinUart2     = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC2_SHIFT),
    kCLOCK_LSpi0        = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC0_SHIFT),
    kCLOCK_LSpi1        = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC1_SHIFT),
    kCLOCK_LSpi2        = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC2_SHIFT),
    kCLOCK_BI2c0        = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC0_SHIFT),
    kCLOCK_BI2c1        = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC1_SHIFT),
    kCLOCK_BI2c2        = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_FC2_SHIFT),
    kCLOCK_Timer2       = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_TIMER2_SHIFT),
    kCLOCK_Timer0       = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_TIMER0_SHIFT),
    kCLOCK_Timer1       = CLK_GATE_DEFINE(AHB_CLK_CTRL1, SYSCON_AHBCLKCTRL1_TIMER1_SHIFT),
    kCLOCK_Dma1         = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_DMA1_SHIFT),
    kCLOCK_BleRam       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_BLE_RAM_SHIFT),
    kCLOCK_BleRadio     = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_BLE_RADIO_SHIFT),
    kCLOCK_Freqme       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_FREQME_SHIFT),
    kCLOCK_Rng          = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_RNG_SHIFT),
    kCLOCK_Sysctl       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_SYSCTL_SHIFT),
    kCLOCK_HashCrypt    = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_HASH_AES_SHIFT),
    kCLOCK_PluLut       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_PLULUT_SHIFT),
    kCLOCK_Timer3       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_TIMER3_SHIFT),
    kCLOCK_Timer4       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_TIMER4_SHIFT),
    kCLOCK_Puf          = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_PUF_SHIFT),
    kCLOCK_Casper       = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_CASPER_SHIFT),
    kCLOCK_AnalogCtrl   = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_ANALOG_CTRL_SHIFT),
    kCLOCK_Spifi        = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_SPIFI_SHIFT),
    kCLOCK_Gpio_Sec     = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_GPIO_SEC_SHIFT),
    kCLOCK_Gpio_Sec_Int = CLK_GATE_DEFINE(AHB_CLK_CTRL2, SYSCON_AHBCLKCTRL2_GPIO_SEC_INT_SHIFT)
} clock_ip_name_t;

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_CoreSysClk, /*!< Core/system clock  (aka MAIN_CLK)                       */
    kCLOCK_BusClk,     /*!< Bus clock (AHB clock)                                   */
    kCLOCK_ClockOut,   /*!< CLOCKOUT                                                */
    kCLOCK_FroHf,      /*!< FRO32M                                                  */
    kCLOCK_Sct,        /*!< SCT                                                     */
    kCLOCK_Fro12M,     /*!< FRO12M                                                  */
    kCLOCK_Fro24M,     /*!< FRO24M                                                  */
    kCLOCK_ExtClk,     /*!< External Clock                                          */
    kCLOCK_WdtClk,     /*!< Watchdog clock                                          */
    kCLOCK_Flexcomm0,  /*!< Flexcomm0Clock                                          */
    kCLOCK_Flexcomm1,  /*!< Flexcomm1Clock                                          */
    kCLOCK_Flexcomm2,  /*!< Flexcomm2Clock                                          */
    kCLOCK_CTimer0,    /*!< CTimer0Clock                                            */
    kCLOCK_CTimer1,    /*!< CTimer1Clock                                            */
    kCLOCK_CTimer2,    /*!< CTimer2Clock                                            */
    kCLOCK_CTimer3,    /*!< CTimer3Clock                                            */
    kCLOCK_CTimer4,    /*!< CTimer4Clock                                            */
    kCLOCK_Systick,    /*!< System Tick Clock                                       */
    kCLOCK_SpifiClk,   /*!< Spifi Clock                                             */
} clock_name_t;

/*! @brief Clock Mux Switches
 *  The encoding is as follows each connection identified is 32bits wide while 24bits are valuable
 *  starting from LSB upwards
 *
 *  [4 bits for choice, 0 means invalid choice] [8 bits mux ID]*
 *
 */

#define CLK_ATTACH_ID(mux, sel, pos) (((mux << 0U) | ((sel + 1) & 0xFU) << 8U) << (pos * 12U))
#define MUX_A(mux, sel)              CLK_ATTACH_ID(mux, sel, 0U)
#define MUX_B(mux, sel, selector)    (CLK_ATTACH_ID(mux, sel, 1U) | (selector << 24U))

#define GET_ID_ITEM(connection)      ((connection)&0xFFFU)
#define GET_ID_NEXT_ITEM(connection) ((connection) >> 12U)
#define GET_ID_ITEM_MUX(connection)  ((connection)&0xFFU)
#define GET_ID_ITEM_SEL(connection)  ((((connection)&0xF00U) >> 8U) - 1U)
#define GET_ID_SELECTOR(connection)  ((connection)&0xF000000U)

/*
 * These values are used as an index to find the various CLKSEL registers in SYSCON.
 * Basically, it is the number of registers between the wanted register and SYSTICKCLKSEL0.
 * Gaps in the list indicate reserved registers.
 */
#define CM_SYSTICKCLKSEL (0u)
#define CM_TRACECLKSEL   (2u)
#define CM_CTIMERCLKSEL0 (3u)
#define CM_CTIMERCLKSEL1 (4u)
#define CM_CTIMERCLKSEL2 (5u)
#define CM_CTIMERCLKSEL3 (6u)
#define CM_CTIMERCLKSEL4 (7u)
#define CM_MAINCLKSELA   (8u)
#define CM_MAINCLKSELB   (9u)
#define CM_CLKOUTCLKSEL  (10u)
#define CM_FXCOMCLKSEL0  (20u)
#define CM_FXCOMCLKSEL1  (21u)
#define CM_FXCOMCLKSEL2  (22u)
#define CM_SPIFICLKSEL   (28u)
#define CM_SCTCLKSEL     (36u)

/* RTC is a special case as it is in the PMC. This is treated as a special value in the functions. */
#define CM_RTCOSC32KCLKSEL (63u)

/*
 * These values are the possible selections for each individual CLKSEL register.
 */
/* SEL - System Tick Timer for CPU0 source select. */
#define SYSTICKCLKSEL_SYSTICK_DIV               (0u)
#define SYSTICKCLKSEL_FRO_1MHz                  (1u)
#define SYSTICKCLKSEL_32K_OSC                   (2u)
#define SYSTICKCLKSEL_NO_CLOCK                  (3u)
#define SYSTICKCLKSEL_NO_CLOCK_ALTERNATE_VALUE1 (4u)
#define SYSTICKCLKSEL_NO_CLOCK_ALTERNATE_VALUE2 (5u)
#define SYSTICKCLKSEL_NO_CLOCK_ALTERNATE_VALUE3 (6u)
#define SYSTICKCLKSEL_NO_CLOCK_ALTERNATE_VALUE4 (7u)
/* SEL - Trace clock source select. */
#define TRACECLKSEL_TRACE_DIV                 (0u)
#define TRACECLKSEL_FRO_1MHz                  (1u)
#define TRACECLKSEL_32K_OSC                   (2u)
#define TRACECLKSEL_NO_CLOCK                  (3u)
#define TRACECLKSEL_NO_CLOCK_ALTERNATE_VALUE1 (4u)
#define TRACECLKSEL_NO_CLOCK_ALTERNATE_VALUE2 (5u)
#define TRACECLKSEL_NO_CLOCK_ALTERNATE_VALUE3 (6u)
#define TRACECLKSEL_NO_CLOCK_ALTERNATE_VALUE4 (7u)
/* SEL - CTimer clock source select. */
#define CTIMERCLKSEL_MAINCLK                   (0u)
#define CTIMERCLKSEL_NO_CLOCK                  (1u)
#define CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE1 (2u)
#define CTIMERCLKSEL_FRO_32MHz                 (3u)
#define CTIMERCLKSEL_FRO_1MHz                  (4u)
#define CTIMERCLKSEL_FRO_24MHz                 (5u)
#define CTIMERCLKSEL_32K_OSC                   (6u)
#define CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE2 (7u)
/* SEL - Main clock A source select. */
#define MAINCLKSELA_FRO_12MHz                  (0u)
#define MAINCLKSELA_CLKIN                      (1u)
#define MAINCLKSELA_FRO_1MHz                   (2u)
#define MAINCLKSELA_FRO_32MHz                  (3u)
#define MAINCLKSELA_FRO_12MHz_ALTERNATE_VALUE1 (4u)
#define MAINCLKSELA_CLKIN_ALTERNATE_VALUE1     (5u)
#define MAINCLKSELA_FRO_1MHz_ALTERNATE_VALUE1  (6u)
#define MAINCLKSELA_FRO_32MHz_ALTERNATE_VALUE1 (7u)
/* SEL - Main clock B source select. */
#define MAINCLKSELB_MAINCLKAOUT              (0u)
#define MAINCLKSELB_FRO_24MHz                (1u)
#define MAINCLKSELB_32K_OSC                  (2u)
#define MAINCLKSELB_32K_OSC_ALTERNATE_VALUE1 (3u)
/* SEL - CLKOUT clock source select. */
#define CLKOUTSEL_MAINCLK                   (0u)
#define CLKOUTSEL_NO_CLOCK                  (1u)
#define CLKOUTSEL_CLKIN                     (2u)
#define CLKOUTSEL_FRO_32MHz                 (3u)
#define CLKOUTSEL_FRO_1MHz                  (4u)
#define CLKOUTSEL_FRO_24MHz                 (5u)
#define CLKOUTSEL_32K_OSC                   (6u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE1 (7u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE2 (8u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE3 (9u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE4 (10u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE5 (11u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE6 (12u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE7 (13u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE8 (14u)
#define CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE9 (15u)
/* SEL - Flexcomm Interface clock source select for Fractional Rate Divider. */
#define FCCLKSEL_MAINCLK                   (0u)
#define FCCLKSEL_NO_CLOCK                  (1u)
#define FCCLKSEL_FRO_12MHz                 (2u)
#define FCCLKSEL_FRO_32MHz_DIV             (3u)
#define FCCLKSEL_FRO_1MHz                  (4u)
#define FCCLKSEL_FRO_24MHz                 (5u)
#define FCCLKSEL_32K_OSC                   (6u)
#define FCCLKSEL_NO_CLOCK_ALTERNATE_VALUE1 (7u)
/* SEL - QuadSPI Flash Interface clock source select. */
#define SPIFICLKSEL_MAINCLK                    (0u)
#define SPIFICLKSEL_FRO_64MHz                  (1u)
#define SPIFICLKSEL_FRO_32MHz                  (2u)
#define SPIFICLKSEL_FRO_32MHz_DIV              (3u)
#define SPIFICLKSEL_FRO_48MHz                  (4u)
#define SPIFICLKSEL_FRO_48MHz_ALTERNATE_VALUE1 (5u)
#define SPIFICLKSEL_FRO_48MHz_ALTERNATE_VALUE2 (6u)
#define SPIFICLKSEL_FRO_48MHz_ALTERNATE_VALUE3 (7u)
/* SEL - SCTimer/PWM clock source select. */
#define SCTCLKSEL_MAINCLK                    (0u)
#define SCTCLKSEL_NO_CLOCK                   (1u)
#define SCTCLKSEL_CLKIN                      (2u)
#define SCTCLKSEL_FRO_32MHz                  (3u)
#define SCTCLKSEL_FRO_24MHz                  (4u)
#define SCTCLKSEL_FRO_24MHz_ALTERNATE_VALUE1 (5u)
#define SCTCLKSEL_FRO_24MHz_ALTERNATE_VALUE2 (6u)
#define SCTCLKSEL_FRO_24MHz_ALTERNATE_VALUE3 (7u)

/* SEL - 0: FRO 32 KHz 1: XTAL 32KHz */
#define RTCOSC32K_SEL_FRO  (0u)
#define RTCOSC32K_SEL_XTAL (1u)

/* SEL - OSTimer clock source select. */
#define OSTIMERCLKSEL_32768                    (0u)
#define OSTIMERCLKSEL_FRO_1MHz                 (1u)
#define OSIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE1 (2u)
#define OSTIMERCLKSEL_NO_CLOCK                 (3u)

typedef enum _clock_attach_id
{

    kFRO12M_to_MAIN_CLK =
        MUX_A(CM_MAINCLKSELA, MAINCLKSELA_FRO_12MHz) | MUX_B(CM_MAINCLKSELB, MAINCLKSELB_MAINCLKAOUT, 0),
    kEXT_CLK_to_MAIN_CLK = MUX_A(CM_MAINCLKSELA, MAINCLKSELA_CLKIN) | MUX_B(CM_MAINCLKSELB, MAINCLKSELB_MAINCLKAOUT, 0),
    kFRO1M_to_MAIN_CLK =
        MUX_A(CM_MAINCLKSELA, MAINCLKSELA_FRO_1MHz) | MUX_B(CM_MAINCLKSELB, MAINCLKSELB_MAINCLKAOUT, 0),
    kFRO_HF_to_MAIN_CLK =
        MUX_A(CM_MAINCLKSELA, MAINCLKSELA_FRO_32MHz) | MUX_B(CM_MAINCLKSELB, MAINCLKSELB_MAINCLKAOUT, 0),
    kFRO24M_to_MAIN_CLK =
        MUX_A(CM_MAINCLKSELA, MAINCLKSELA_FRO_12MHz) | MUX_B(CM_MAINCLKSELB, MAINCLKSELB_FRO_24MHz, 0),
    kOSC32K_to_MAIN_CLK = MUX_A(CM_MAINCLKSELA, MAINCLKSELA_FRO_12MHz) | MUX_B(CM_MAINCLKSELB, MAINCLKSELB_32K_OSC, 0),

    kMAIN_CLK_to_CLKOUT = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_MAINCLK),
    kEXT_CLK_to_CLKOUT  = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_CLKIN),
    kFRO_HF_to_CLKOUT   = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_FRO_32MHz),
    kFRO1M_to_CLKOUT    = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_FRO_1MHz),
    kFRO24M_to_CLKOUT   = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_FRO_24MHz),
    kOSC32K_to_CLKOUT   = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_32K_OSC),
    kNONE_to_SYS_CLKOUT = MUX_A(CM_CLKOUTCLKSEL, CLKOUTSEL_NO_CLOCK_ALTERNATE_VALUE1),

    kMAIN_CLK_to_FLEXCOMM0   = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_MAINCLK),
    kFRO12M_to_FLEXCOMM0     = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_FRO_12MHz),
    kFRO_HF_DIV_to_FLEXCOMM0 = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_FRO_32MHz_DIV),
    kFRO1M_to_FLEXCOMM0      = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_FRO_1MHz),
    kFRO24M_to_FLEXCOMM0     = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_FRO_24MHz),
    kOSC32K_to_FLEXCOMM0     = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_32K_OSC),
    kNONE_to_FLEXCOMM0       = MUX_A(CM_FXCOMCLKSEL0, FCCLKSEL_NO_CLOCK_ALTERNATE_VALUE1),

    kMAIN_CLK_to_FLEXCOMM1   = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_MAINCLK),
    kFRO12M_to_FLEXCOMM1     = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_FRO_12MHz),
    kFRO_HF_DIV_to_FLEXCOMM1 = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_FRO_32MHz_DIV),
    kFRO1M_to_FLEXCOMM1      = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_FRO_1MHz),
    kFRO24M_to_FLEXCOMM1     = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_FRO_24MHz),
    kOSC32K_to_FLEXCOMM1     = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_32K_OSC),
    kNONE_to_FLEXCOMM1       = MUX_A(CM_FXCOMCLKSEL1, FCCLKSEL_NO_CLOCK_ALTERNATE_VALUE1),

    kMAIN_CLK_to_FLEXCOMM2   = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_MAINCLK),
    kFRO12M_to_FLEXCOMM2     = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_FRO_12MHz),
    kFRO_HF_DIV_to_FLEXCOMM2 = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_FRO_32MHz_DIV),
    kFRO1M_to_FLEXCOMM2      = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_FRO_1MHz),
    kFRO24M_to_FLEXCOMM2     = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_FRO_24MHz),
    kOSC32K_to_FLEXCOMM2     = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_32K_OSC),
    kNONE_to_FLEXCOMM2       = MUX_A(CM_FXCOMCLKSEL2, FCCLKSEL_NO_CLOCK_ALTERNATE_VALUE1),

    kMAIN_CLK_to_SCT_CLK = MUX_A(CM_SCTCLKSEL, SCTCLKSEL_MAINCLK),
    kEXT_CLK_to_SCT_CLK  = MUX_A(CM_SCTCLKSEL, SCTCLKSEL_CLKIN),
    kFRO_HF_to_SCT_CLK   = MUX_A(CM_SCTCLKSEL, SCTCLKSEL_FRO_32MHz),
    kFRO24M_to_SCT_CLK   = MUX_A(CM_SCTCLKSEL, SCTCLKSEL_FRO_24MHz),

    kFRO32K_to_OSC32K  = MUX_A(CM_RTCOSC32KCLKSEL, RTCOSC32K_SEL_FRO),
    kXTAL32K_to_OSC32K = MUX_A(CM_RTCOSC32KCLKSEL, RTCOSC32K_SEL_XTAL),

    kTRACE_DIV_to_TRACE = MUX_A(CM_TRACECLKSEL, TRACECLKSEL_TRACE_DIV),
    kFRO1M_to_TRACE     = MUX_A(CM_TRACECLKSEL, TRACECLKSEL_FRO_1MHz),
    kOSC32K_to_TRACE    = MUX_A(CM_TRACECLKSEL, TRACECLKSEL_32K_OSC),
    kNONE_to_TRACE      = MUX_A(CM_TRACECLKSEL, TRACECLKSEL_NO_CLOCK_ALTERNATE_VALUE4),

    kSYSTICK_DIV_to_SYSTICK = MUX_A(CM_SYSTICKCLKSEL, SYSTICKCLKSEL_SYSTICK_DIV),
    kFRO1M_to_SYSTICK       = MUX_A(CM_SYSTICKCLKSEL, SYSTICKCLKSEL_FRO_1MHz),
    kOSC32K_to_SYSTICK      = MUX_A(CM_SYSTICKCLKSEL, SYSTICKCLKSEL_32K_OSC),
    kNONE_to_SYSTICK        = MUX_A(CM_SYSTICKCLKSEL, SYSTICKCLKSEL_NO_CLOCK_ALTERNATE_VALUE4),

    kMAIN_CLK_to_CTIMER0 = MUX_A(CM_CTIMERCLKSEL0, CTIMERCLKSEL_MAINCLK),
    kFRO_HF_to_CTIMER0   = MUX_A(CM_CTIMERCLKSEL0, CTIMERCLKSEL_FRO_32MHz),
    kFRO1M_to_CTIMER0    = MUX_A(CM_CTIMERCLKSEL0, CTIMERCLKSEL_FRO_1MHz),
    kFRO24M_to_CTIMER0   = MUX_A(CM_CTIMERCLKSEL0, CTIMERCLKSEL_FRO_24MHz),
    kOSC32K_to_CTIMER0   = MUX_A(CM_CTIMERCLKSEL0, CTIMERCLKSEL_32K_OSC),
    kNONE_to_CTIMER0     = MUX_A(CM_CTIMERCLKSEL0, CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE2),

    kMAIN_CLK_to_CTIMER1 = MUX_A(CM_CTIMERCLKSEL1, CTIMERCLKSEL_MAINCLK),
    kFRO_HF_to_CTIMER1   = MUX_A(CM_CTIMERCLKSEL1, CTIMERCLKSEL_FRO_32MHz),
    kFRO1M_to_CTIMER1    = MUX_A(CM_CTIMERCLKSEL1, CTIMERCLKSEL_FRO_1MHz),
    kFRO24M_to_CTIMER1   = MUX_A(CM_CTIMERCLKSEL1, CTIMERCLKSEL_FRO_24MHz),
    kOSC32K_to_CTIMER1   = MUX_A(CM_CTIMERCLKSEL1, CTIMERCLKSEL_32K_OSC),
    kNONE_to_CTIMER1     = MUX_A(CM_CTIMERCLKSEL1, CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE2),

    kMAIN_CLK_to_CTIMER2 = MUX_A(CM_CTIMERCLKSEL2, CTIMERCLKSEL_MAINCLK),
    kFRO_HF_to_CTIMER2   = MUX_A(CM_CTIMERCLKSEL2, CTIMERCLKSEL_FRO_32MHz),
    kFRO1M_to_CTIMER2    = MUX_A(CM_CTIMERCLKSEL2, CTIMERCLKSEL_FRO_1MHz),
    kFRO24M_to_CTIMER2   = MUX_A(CM_CTIMERCLKSEL2, CTIMERCLKSEL_FRO_24MHz),
    kOSC32K_to_CTIMER2   = MUX_A(CM_CTIMERCLKSEL2, CTIMERCLKSEL_32K_OSC),
    kNONE_to_CTIMER2     = MUX_A(CM_CTIMERCLKSEL2, CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE2),

    kMAIN_CLK_to_CTIMER3 = MUX_A(CM_CTIMERCLKSEL3, CTIMERCLKSEL_MAINCLK),
    kFRO_HF_to_CTIMER3   = MUX_A(CM_CTIMERCLKSEL3, CTIMERCLKSEL_FRO_32MHz),
    kFRO1M_to_CTIMER3    = MUX_A(CM_CTIMERCLKSEL3, CTIMERCLKSEL_FRO_1MHz),
    kFRO24M_to_CTIMER3   = MUX_A(CM_CTIMERCLKSEL3, CTIMERCLKSEL_FRO_24MHz),
    kOSC32K_to_CTIMER3   = MUX_A(CM_CTIMERCLKSEL3, CTIMERCLKSEL_32K_OSC),
    kNONE_to_CTIMER3     = MUX_A(CM_CTIMERCLKSEL3, CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE2),

    kMAIN_CLK_to_CTIMER4 = MUX_A(CM_CTIMERCLKSEL4, CTIMERCLKSEL_MAINCLK),
    kFRO_HF_to_CTIMER4   = MUX_A(CM_CTIMERCLKSEL4, CTIMERCLKSEL_FRO_32MHz),
    kFRO1M_to_CTIMER4    = MUX_A(CM_CTIMERCLKSEL4, CTIMERCLKSEL_FRO_1MHz),
    kFRO24M_to_CTIMER4   = MUX_A(CM_CTIMERCLKSEL4, CTIMERCLKSEL_FRO_24MHz),
    kOSC32K_to_CTIMER4   = MUX_A(CM_CTIMERCLKSEL4, CTIMERCLKSEL_32K_OSC),
    kNONE_to_CTIMER4     = MUX_A(CM_CTIMERCLKSEL4, CTIMERCLKSEL_NO_CLOCK_ALTERNATE_VALUE2),

    kMAIN_CLK_to_SPIFI   = MUX_A(CM_SPIFICLKSEL, SPIFICLKSEL_MAINCLK),
    kFRO64M_to_SPIFI     = MUX_A(CM_SPIFICLKSEL, SPIFICLKSEL_FRO_64MHz),
    kFRO_HF_to_SPIFI     = MUX_A(CM_SPIFICLKSEL, SPIFICLKSEL_FRO_32MHz),
    kFRO_HF_DIV_to_SPIFI = MUX_A(CM_SPIFICLKSEL, SPIFICLKSEL_FRO_32MHz_DIV),
    kFRO48M_to_SPIFI     = MUX_A(CM_SPIFICLKSEL, SPIFICLKSEL_FRO_48MHz),

    kNONE_to_NONE = (int)0x80000000U,
} clock_attach_id_t;

/*
 * These values are used as an index to find the various CLKDIV registers in SYSCON.
 * Basically, it is the number of registers between the wanted register and SYSTICKCLKDIV0.
 * Gaps in the list indicate reserved registers.
 */
typedef enum _clock_div_name
{
    kCLOCK_DivSystickClk  = 0,
    kCLOCK_DivArmTrClkDiv = 2,
    kCLOCK_DivFlexFrg0    = 8,
    kCLOCK_DivFlexFrg1    = 9,
    kCLOCK_DivFlexFrg2    = 10,
    kCLOCK_DivAhbClk      = 32,
    kCLOCK_DivClkOut      = 33,
    kCLOCK_DivFrohfClk    = 34,
    kCLOCK_DivWdtClk      = 35,
    kCLOCK_DivSctClk      = 45,
    kCLOCK_DivSpifiClk    = 52,
    kCLOCK_DivMax         = 52,
} clock_div_name_t;

/*
 * These values are used to select the clock source of the 32kHz OSC in @ref CLOCK_Select32kOscClkSrc.
 */
typedef enum _osc_32k_clock_source
{
    kCLOCK_Osc32kClockSrc_FRO  = 0,
    kCLOCK_Osc32kClockSrc_XTAL = 1
} osc_32k_clock_source_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Enable the clock for specific IP.
 * @param name : Clock to be enabled.
 * @return  Nothing
 */
static inline void CLOCK_EnableClock(clock_ip_name_t clk)
{
    uint32_t index               = CLK_GATE_ABSTRACT_REG_OFFSET(clk);
    SYSCON->AHBCLKCTRLSET[index] = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
}
/**
 * @brief Disable the clock for specific IP.
 * @param name : Clock to be Disabled.
 * @return  Nothing
 */
static inline void CLOCK_DisableClock(clock_ip_name_t clk)
{
    uint32_t index               = CLK_GATE_ABSTRACT_REG_OFFSET(clk);
    SYSCON->AHBCLKCTRLCLR[index] = (1U << CLK_GATE_ABSTRACT_BITS_SHIFT(clk));
}

/**
 * @brief Enable/disable 1MHz FRO.
 * @param enable true to enable the 1MHz FRO, false to disable the 1MHz FRO.
 * @return  Nothing
 */
void CLOCK_Enable1MFRO(bool enable);
/**
 * @brief   Initialize the Core clock to given frequency (12, 24 or 32 MHz).
 * Enables the required divided FRO output.
 * Additionally, the 48 or 64 MHz divided FRO output can be enabled. These cannot be used
 * as Core clock.
 * @param   iFreq   : Desired frequency (must be one of #kFreq_12MHz, #kFreq_24MHz, #kFreq_32MHz, #kFreq_48MHz or
 * #kFreq_64MHz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFROClocking(uint32_t iFreq);
/**
 * @brief   Disable generation of the given frequency (12, 24, 32, 48 or 64 MHz) by turning off
 * the required divided FRO output.
 * @param   iFreq   : Desired frequency (must be one of #kFreq_12MHz, #kFreq_24MHz, #kFreq_32MHz, #kFreq_48MHz or
 * #kFreq_64MHz)
 * @return  returns success or fail status.
 */
status_t CLOCK_DisableFROClock(uint32_t iFreq);
/**
 * @brief	Set the flash wait states for the input freuqency.
 * @param	iFreq	: Input frequency in Hz
 * @return	Nothing
 */
void CLOCK_SetFLASHAccessCyclesForFreq(uint32_t iFreq);
/**
 * brief	Get the actual flash wait states.
 * return	ReadWaitStates
 */
uint32_t CLOCK_GetFLASHAccessCycles(void);
/**
 * brief	Set the flash wait states.
 * param	ReadWaitStates
 */
void CLOCK_SetFLASHAccessCycles(uint32_t ReadWaitStates);
/**
 * @brief   Initialize the external osc clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupExtClocking(uint32_t iFreq);
/**
 * @brief   Configure the clock selection muxes.
 * @param   connection  : Clock to be configured.
 * @return  Nothing
 */
void CLOCK_AttachClk(clock_attach_id_t connection);
/**
 * @brief   Get the actual clock attach id.
 * This fuction uses the offset in input attach id, then it reads the actual source value in
 * the register and combine the offset to obtain an actual attach id.
 * @param   attachId  : Clock attach id to get.
 * @return  Clock source value.
 */
clock_attach_id_t CLOCK_GetClockAttachId(clock_attach_id_t attachId);
/**
 * @brief   Setup peripheral clock dividers.
 * @param   div_name    : Clock divider name
 * @param divided_by_value: Value to be divided.
 *                          Maximum value is 256.
 *                          Value 0 halts the divider counter.
 * @param reset :  Whether to reset the divider counter.
 * @return  Nothing
 */
void CLOCK_SetClkDiv(clock_div_name_t div_name, uint32_t divided_by_value, bool reset);
/**
 * @brief   Setup rtc 1khz clock divider.
 * @param divided_by_value: Value to be divided
 * @return  Nothing
 */
void CLOCK_SetRtc1khzClkDiv(uint32_t divided_by_value);
/**
 * @brief   Setup rtc 1hz clock divider.
 * @param divided_by_value: Value to be divided
 * @return  Nothing
 */
void CLOCK_SetRtc1hzClkDiv(uint32_t divided_by_value);

/**
 * @brief   Set the flexcomm output frequency.
 * @param   id      : flexcomm instance id
 *          freq    : output frequency
 * @return  0   : the frequency range is out of range.
 *          1   : switch successfully.
 */
uint32_t CLOCK_SetFlexCommClock(uint32_t id, uint32_t freq);

/**
 * @brief   Get the flexcomm output frequency.
 * @param   id      : flexcomm instance id
 *          freq    : output frequency
 * @return  the frequency.
 */
uint32_t CLOCK_GetFlexCommClkFreq(uint32_t id);

/*! @brief  Return Frequency of flexcomm input clock
 *  @param  id     : flexcomm instance id
 *  @return Frequency value
 */
uint32_t CLOCK_GetFlexCommInputClock(uint32_t id);

/*! @brief  Return Frequency of selected clock
 *  @return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);
/*! @brief  Return Frequency of FRO 12MHz
 *  @return Frequency of FRO 12MHz
 */
uint32_t CLOCK_GetFro12MFreq(void);
/*! @brief  Return Frequency of FRO 12MHz
 *  @return Frequency of FRO 12MHz
 */
uint32_t CLOCK_GetFro24MFreq(void);
/*! @brief  Return Frequency of FRO 1MHz
 *  @return Frequency of FRO 1MHz
 */
uint32_t CLOCK_GetFro1MFreq(void);
/*! @brief  Return Frequency of ClockOut
 *  @return Frequency of ClockOut
 */
uint32_t CLOCK_GetClockOutClkFreq(void);
/*! @brief  Return Frequency of SCTimer Clock
 *  @return Frequency of SCTimer Clock.
 */
uint32_t CLOCK_GetSctClkFreq(void);
/*! @brief  Return Frequency of SPIFI Clock
 *  @return Frequency of SPIFI Clock.
 */
uint32_t CLOCK_GetSpifiClkFreq(void);
/*! @brief  Return Frequency of External Clock
 *  @return Frequency of External Clock. If no external clock is used returns 0.
 */
uint32_t CLOCK_GetExtClkFreq(void);
/*! @brief  Return Frequency of Watchdog
 *  @return Frequency of Watchdog
 */
uint32_t CLOCK_GetWdtClkFreq(void);
/*! @brief  Return Frequency of High-Freq output of FRO
 *  @return Frequency of High-Freq output of FRO
 */
uint32_t CLOCK_GetFroHfFreq(void);
/*! @brief  Return Frequency of 32kHz osc
 *  @return Frequency of 32kHz osc
 */
uint32_t CLOCK_GetOsc32KFreq(void);
/*! @brief  Return Frequency of Core System
 *  @return Frequency of Core System
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);
/*! @brief  Return Frequency of CTimer functional Clock
 *  @return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id);
/*! @brief  Return Frequency of SystickClock
 *  @return Frequency of Systick Clock
 */
uint32_t CLOCK_GetSystickClkFreq(uint32_t id);
/*! @brief  Return Frequency of OSTimer Clock
 *  @return Frequency of OSTimer Clock.
 */
uint32_t CLOCK_GetOSTimerClkFreq(void);
/*! @brief Enable the OSTIMER 32k clock.
 *  @return  Nothing
 */
void CLOCK_EnableOstimer32kClock(void);

/*! @brief Selects either the XTAL32K or FRO32K as the 32kHz clock source for the system.
 *  @pre   In order to switch from one source to another, both sources have to be enabled.
 *         Note that FRO is always enabled and selected after booting (enabled by bootloader).
 *  @param clockSrc The desired clock source
 *  @return  Nothing
 */
void CLOCK_Select32kOscClkSrc(osc_32k_clock_source_t clockSrc);

/**
 * @brief   Initialize the PLU CLKIN clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupPLUClkInClocking(uint32_t iFreq);

/*! @brief  Return Frequency of PLU CLKIN Clock
 *  @return Frequency of PLU CLKIN Clock
 */
uint32_t CLOCK_GetPLUClkInFreq(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
