/*
** ###################################################################
**     Processors:          LPC822M101JDH20
**                          LPC822M101JHI33
**                          LPC824M201JDH20
**                          LPC824M201JHI33
**                          LPC832M101FDH20
**                          LPC834M101FHI33
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-02-09)
**         Initial version.
**     - rev. 1.1 (2018-02-25)
**         Update some registers according to UM rev 1.2
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(PERI_SYSCON_H_)
#define PERI_SYSCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC822M101JDH20) || defined(CPU_LPC822M101JHI33))
#include "LPC822_COMMON.h"
#elif (defined(CPU_LPC824M201JDH20) || defined(CPU_LPC824M201JHI33))
#include "LPC824_COMMON.h"
#elif (defined(CPU_LPC832M101FDH20))
#include "LPC832_COMMON.h"
#elif (defined(CPU_LPC834M101FHI33))
#include "LPC834_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SYSCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Peripheral_Access_Layer SYSCON Peripheral Access Layer
 * @{
 */

/** SYSCON - Size of Registers Arrays */
#define SYSCON_PINTSEL_COUNT                      8u

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< System Remap register, offset: 0x0 */
  __IO uint32_t PRESETCTRL;                        /**< Peripheral reset control register, offset: 0x4 */
  __IO uint32_t SYSPLLCTRL;                        /**< PLL control, offset: 0x8 */
  __I  uint32_t SYSPLLSTAT;                        /**< PLL status, offset: 0xC */
       uint8_t RESERVED_0[16];
  __IO uint32_t SYSOSCCTRL;                        /**< system oscillator control, offset: 0x20 */
  __IO uint32_t WDTOSCCTRL;                        /**< Watchdog oscillator control, offset: 0x24 */
  __IO uint32_t IRCCTRL;                           /**< IRC control, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t SYSPLLCLKSEL;                      /**< System PLL clock source select register, offset: 0x40 */
  __IO uint32_t SYSPLLCLKUEN;                      /**< System PLL clock source update enable register, offset: 0x44 */
       uint8_t RESERVED_3[40];
  __IO uint32_t MAINCLKSEL;                        /**< Main clock source select, offset: 0x70 */
  __IO uint32_t MAINCLKUEN;                        /**< Main clock source update enable, offset: 0x74 */
  __IO uint32_t SYSAHBCLKDIV;                      /**< System clock divider, offset: 0x78 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SYSAHBCLKCTRL;                     /**< System clock control, offset: 0x80 */
       uint8_t RESERVED_5[16];
  __IO uint32_t UARTCLKDIV;                        /**< USART clock divider, offset: 0x94 */
       uint8_t RESERVED_6[72];
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT clock source select, offset: 0xE0 */
  __IO uint32_t CLKOUTUEN;                         /**< CLKOUT clock source update enable, offset: 0xE4 */
  __IO uint32_t CLKOUTDIV;                         /**< PLL control, offset: 0xE8 */
       uint8_t RESERVED_7[4];
  __IO uint32_t UARTFRGDIV;                        /**< USART1 to USART4 common fractional generator divider value, offset: 0xF0 */
  __IO uint32_t UARTFRGMULT;                       /**< USART common fractional generator divider value, offset: 0xF4 */
       uint8_t RESERVED_8[4];
  __IO uint32_t EXTTRACECMD;                       /**< External trace buffer command register, offset: 0xFC */
  __I  uint32_t PIOPORCAP0;                        /**< POR captured PIO status 0, offset: 0x100 */
       uint8_t RESERVED_9[48];
  __IO uint32_t IOCONCLKDIV6;                      /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x134 */
  __IO uint32_t IOCONCLKDIV5;                      /**< Peripheral clock 6 to the IOCON block for programmable glitch filter, offset: 0x138 */
  __IO uint32_t IOCONCLKDIV4;                      /**< Peripheral clock 4 to the IOCON block for programmable glitch filter, offset: 0x13C */
  __IO uint32_t IOCONCLKDIV3;                      /**< Peripheral clock 3 to the IOCON block for programmable glitch filter, offset: 0x140 */
  __IO uint32_t IOCONCLKDIV2;                      /**< Peripheral clock 2 to the IOCON block for programmable glitch filter, offset: 0x144 */
  __IO uint32_t IOCONCLKDIV1;                      /**< Peripheral clock 1 to the IOCON block for programmable glitch filter, offset: 0x148 */
  __IO uint32_t IOCONCLKDIV0;                      /**< Peripheral clock 0 to the IOCON block for programmable glitch filter, offset: 0x14C */
  __IO uint32_t BODCTRL;                           /**< BOD control register, offset: 0x150 */
  __IO uint32_t SYSTCKCAL;                         /**< System tick timer calibration register, offset: 0x154 */
       uint8_t RESERVED_10[24];
  __IO uint32_t IRQLATENCY;                        /**< IRQ latency register, offset: 0x170 */
  __IO uint32_t NMISRC;                            /**< NMI source selection register, offset: 0x174 */
  __IO uint32_t PINTSEL[SYSCON_PINTSEL_COUNT];     /**< Pin interrupt select registers N, array offset: 0x178, array step: 0x4 */
       uint8_t RESERVED_11[108];
  __IO uint32_t STARTERP0;                         /**< Start logic 0 pin wake-up enable register 0, offset: 0x204 */
       uint8_t RESERVED_12[12];
  __IO uint32_t STARTERP1;                         /**< Start logic 1 interrupt wake-up enable register, offset: 0x214 */
       uint8_t RESERVED_13[24];
  __IO uint32_t PDSLEEPCFG;                        /**< Deep-sleep configuration register, offset: 0x230 */
  __IO uint32_t PDAWAKECFG;                        /**< Wake-up configuration register, offset: 0x234 */
  __IO uint32_t PDRUNCFG;                          /**< Power configuration register, offset: 0x238 */
       uint8_t RESERVED_14[444];
  __I  uint32_t DEVICE_ID;                         /**< Part ID register, offset: 0x3F8 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name SYSMEMREMAP - System Remap register */
/*! @{ */

#define SYSCON_SYSMEMREMAP_MAP_MASK              (0x3U)
#define SYSCON_SYSMEMREMAP_MAP_SHIFT             (0U)
/*! MAP - System memory remap. Value 0x3 is reserved.
 *  0b00..Boot Loader Mode. Interrupt vectors are re-mapped to Boot ROM.
 *  0b01..User RAM Mode. Interrupt vectors are re-mapped to Static RAM.
 *  0b10..User Flash Mode. Interrupt vectors are not re-mapped and reside in Flash.
 */
#define SYSCON_SYSMEMREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSMEMREMAP_MAP_SHIFT)) & SYSCON_SYSMEMREMAP_MAP_MASK)
/*! @} */

/*! @name PRESETCTRL - Peripheral reset control register */
/*! @{ */

#define SYSCON_PRESETCTRL_SPI0_RST_N_MASK        (0x1U)
#define SYSCON_PRESETCTRL_SPI0_RST_N_SHIFT       (0U)
/*! SPI0_RST_N - SPI0 reset control.
 *  0b0..Assert the SPI0 reset.
 *  0b1..Clear the SPI0 reset.
 */
#define SYSCON_PRESETCTRL_SPI0_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SPI0_RST_N_SHIFT)) & SYSCON_PRESETCTRL_SPI0_RST_N_MASK)

#define SYSCON_PRESETCTRL_SPI1_RST_N_MASK        (0x2U)
#define SYSCON_PRESETCTRL_SPI1_RST_N_SHIFT       (1U)
/*! SPI1_RST_N - SPI1 reset control.
 *  0b0..Assert the SPI1 reset.
 *  0b1..Clear the SPI1 reset.
 */
#define SYSCON_PRESETCTRL_SPI1_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SPI1_RST_N_SHIFT)) & SYSCON_PRESETCTRL_SPI1_RST_N_MASK)

#define SYSCON_PRESETCTRL_UARTFRG_RST_N_MASK     (0x4U)
#define SYSCON_PRESETCTRL_UARTFRG_RST_N_SHIFT    (2U)
/*! UARTFRG_RST_N - USART fractional baud rate generator(UARTFRG) reset control.
 *  0b0..Assert the UARTFRG reset.
 *  0b1..Clear the UARTFRG reset.
 */
#define SYSCON_PRESETCTRL_UARTFRG_RST_N(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UARTFRG_RST_N_SHIFT)) & SYSCON_PRESETCTRL_UARTFRG_RST_N_MASK)

#define SYSCON_PRESETCTRL_UART0_RST_N_MASK       (0x8U)
#define SYSCON_PRESETCTRL_UART0_RST_N_SHIFT      (3U)
/*! UART0_RST_N - USART0 reset control.
 *  0b0..Assert the USART0 reset.
 *  0b1..Clear the USART0 reset.
 */
#define SYSCON_PRESETCTRL_UART0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UART0_RST_N_SHIFT)) & SYSCON_PRESETCTRL_UART0_RST_N_MASK)

#define SYSCON_PRESETCTRL_UART1_RST_N_MASK       (0x10U)
#define SYSCON_PRESETCTRL_UART1_RST_N_SHIFT      (4U)
/*! UART1_RST_N - USART1 reset control.
 *  0b0..Assert the USART1 reset.
 *  0b1..Clear the USART1 reset.
 */
#define SYSCON_PRESETCTRL_UART1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UART1_RST_N_SHIFT)) & SYSCON_PRESETCTRL_UART1_RST_N_MASK)

#define SYSCON_PRESETCTRL_UART2_RST_N_MASK       (0x20U)
#define SYSCON_PRESETCTRL_UART2_RST_N_SHIFT      (5U)
/*! UART2_RST_N - USART2 reset control.
 *  0b0..Assert the USART2 reset.
 *  0b1..Clear the USART2 reset.
 */
#define SYSCON_PRESETCTRL_UART2_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UART2_RST_N_SHIFT)) & SYSCON_PRESETCTRL_UART2_RST_N_MASK)

#define SYSCON_PRESETCTRL_I2C0_RST_N_MASK        (0x40U)
#define SYSCON_PRESETCTRL_I2C0_RST_N_SHIFT       (6U)
/*! I2C0_RST_N - I2C0 reset control.
 *  0b0..Assert the I2C0 reset.
 *  0b1..Clear the I2C0 reset.
 */
#define SYSCON_PRESETCTRL_I2C0_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_I2C0_RST_N_SHIFT)) & SYSCON_PRESETCTRL_I2C0_RST_N_MASK)

#define SYSCON_PRESETCTRL_MRT_RST_N_MASK         (0x80U)
#define SYSCON_PRESETCTRL_MRT_RST_N_SHIFT        (7U)
/*! MRT_RST_N - Multi-rate timer (MRT) reset control.
 *  0b0..Assert the MRT reset.
 *  0b1..Clear the MRT reset.
 */
#define SYSCON_PRESETCTRL_MRT_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MRT_RST_N_SHIFT)) & SYSCON_PRESETCTRL_MRT_RST_N_MASK)

#define SYSCON_PRESETCTRL_SCT_RST_N_MASK         (0x100U)
#define SYSCON_PRESETCTRL_SCT_RST_N_SHIFT        (8U)
/*! SCT_RST_N - SCT reset control.
 *  0b0..Assert the SCT reset.
 *  0b1..Clear the SCT reset.
 */
#define SYSCON_PRESETCTRL_SCT_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SCT_RST_N_SHIFT)) & SYSCON_PRESETCTRL_SCT_RST_N_MASK)

#define SYSCON_PRESETCTRL_WKT_RST_N_MASK         (0x200U)
#define SYSCON_PRESETCTRL_WKT_RST_N_SHIFT        (9U)
/*! WKT_RST_N - Self-wake-up timer (WKT) reset control.
 *  0b0..Assert the WKT reset.
 *  0b1..Clear the WKT reset.
 */
#define SYSCON_PRESETCTRL_WKT_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_WKT_RST_N_SHIFT)) & SYSCON_PRESETCTRL_WKT_RST_N_MASK)

#define SYSCON_PRESETCTRL_GPIO_RST_N_MASK        (0x400U)
#define SYSCON_PRESETCTRL_GPIO_RST_N_SHIFT       (10U)
/*! GPIO_RST_N - GPIO and GPIO pin interrupt reset control.
 *  0b0..Assert the GPIO reset.
 *  0b1..Clear the GPIO reset.
 */
#define SYSCON_PRESETCTRL_GPIO_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO_RST_N_SHIFT)) & SYSCON_PRESETCTRL_GPIO_RST_N_MASK)

#define SYSCON_PRESETCTRL_FLASH_RST_N_MASK       (0x800U)
#define SYSCON_PRESETCTRL_FLASH_RST_N_SHIFT      (11U)
/*! FLASH_RST_N - Flash controller reset control.
 *  0b0..Assert the flash controller reset.
 *  0b1..Clear the flash controller reset.
 */
#define SYSCON_PRESETCTRL_FLASH_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FLASH_RST_N_SHIFT)) & SYSCON_PRESETCTRL_FLASH_RST_N_MASK)

#define SYSCON_PRESETCTRL_ACMP_RST_N_MASK        (0x1000U)
#define SYSCON_PRESETCTRL_ACMP_RST_N_SHIFT       (12U)
/*! ACMP_RST_N - Analog comparator reset control.
 *  0b0..Assert the analog comparator reset.
 *  0b1..Clear the analog comparator controller reset.
 */
#define SYSCON_PRESETCTRL_ACMP_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_ACMP_RST_N_SHIFT)) & SYSCON_PRESETCTRL_ACMP_RST_N_MASK)

#define SYSCON_PRESETCTRL_I2C1_RST_N_MASK        (0x4000U)
#define SYSCON_PRESETCTRL_I2C1_RST_N_SHIFT       (14U)
/*! I2C1_RST_N - I2C1 reset control.
 *  0b0..Assert the I2C1 reset.
 *  0b1..Clear the I2C1 reset.
 */
#define SYSCON_PRESETCTRL_I2C1_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_I2C1_RST_N_SHIFT)) & SYSCON_PRESETCTRL_I2C1_RST_N_MASK)

#define SYSCON_PRESETCTRL_I2C2_RST_N_MASK        (0x8000U)
#define SYSCON_PRESETCTRL_I2C2_RST_N_SHIFT       (15U)
/*! I2C2_RST_N - I2C2 reset control.
 *  0b0..Assert the I2C2 reset.
 *  0b1..Clear the I2C2 reset.
 */
#define SYSCON_PRESETCTRL_I2C2_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_I2C2_RST_N_SHIFT)) & SYSCON_PRESETCTRL_I2C2_RST_N_MASK)

#define SYSCON_PRESETCTRL_I2C3_RST_N_MASK        (0x10000U)
#define SYSCON_PRESETCTRL_I2C3_RST_N_SHIFT       (16U)
/*! I2C3_RST_N - I2C3 reset control.
 *  0b0..Assert the I2C3 reset.
 *  0b1..Clear the I2C3 reset.
 */
#define SYSCON_PRESETCTRL_I2C3_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_I2C3_RST_N_SHIFT)) & SYSCON_PRESETCTRL_I2C3_RST_N_MASK)

#define SYSCON_PRESETCTRL_ADC_RST_N_MASK         (0x1000000U)
#define SYSCON_PRESETCTRL_ADC_RST_N_SHIFT        (24U)
/*! ADC_RST_N - ADC reset control.
 *  0b0..Assert the ADC reset.
 *  0b1..Clear the ADC reset.
 */
#define SYSCON_PRESETCTRL_ADC_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_ADC_RST_N_SHIFT)) & SYSCON_PRESETCTRL_ADC_RST_N_MASK)

#define SYSCON_PRESETCTRL_DMA_RST_N_MASK         (0x20000000U)
#define SYSCON_PRESETCTRL_DMA_RST_N_SHIFT        (29U)
/*! DMA_RST_N - DMA reset control.
 *  0b0..Assert the DMA reset.
 *  0b1..Clear the DMA reset.
 */
#define SYSCON_PRESETCTRL_DMA_RST_N(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_DMA_RST_N_SHIFT)) & SYSCON_PRESETCTRL_DMA_RST_N_MASK)
/*! @} */

/*! @name SYSPLLCTRL - PLL control */
/*! @{ */

#define SYSCON_SYSPLLCTRL_MSEL_MASK              (0x1FU)
#define SYSCON_SYSPLLCTRL_MSEL_SHIFT             (0U)
/*! MSEL - Feedback divider value. The division value M is the programmed MSEL value + 1. 00000:
 *    Division ratio M = 1 to 11111: Division ratio M = 32
 */
#define SYSCON_SYSPLLCTRL_MSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_MSEL_SHIFT)) & SYSCON_SYSPLLCTRL_MSEL_MASK)

#define SYSCON_SYSPLLCTRL_PSEL_MASK              (0x60U)
#define SYSCON_SYSPLLCTRL_PSEL_SHIFT             (5U)
/*! PSEL - Post divider ratio P. The division ratio is 2 x P.
 *  0b00..P = 1
 *  0b01..P = 2
 *  0b10..P = 4
 *  0b11..P = 8
 */
#define SYSCON_SYSPLLCTRL_PSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_PSEL_SHIFT)) & SYSCON_SYSPLLCTRL_PSEL_MASK)
/*! @} */

/*! @name SYSPLLSTAT - PLL status */
/*! @{ */

#define SYSCON_SYSPLLSTAT_LOCK_MASK              (0x1U)
#define SYSCON_SYSPLLSTAT_LOCK_SHIFT             (0U)
/*! LOCK - PLL0 lock indicator */
#define SYSCON_SYSPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSTAT_LOCK_SHIFT)) & SYSCON_SYSPLLSTAT_LOCK_MASK)
/*! @} */

/*! @name SYSOSCCTRL - system oscillator control */
/*! @{ */

#define SYSCON_SYSOSCCTRL_BYPASS_MASK            (0x1U)
#define SYSCON_SYSOSCCTRL_BYPASS_SHIFT           (0U)
/*! BYPASS - Bypass system oscillator */
#define SYSCON_SYSOSCCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSOSCCTRL_BYPASS_SHIFT)) & SYSCON_SYSOSCCTRL_BYPASS_MASK)

#define SYSCON_SYSOSCCTRL_FREQ_RANGE_MASK        (0x2U)
#define SYSCON_SYSOSCCTRL_FREQ_RANGE_SHIFT       (1U)
/*! FREQ_RANGE - oscillator low / high transconductance selection input (Active High) 1-20MHz '0' : 15-50MHz '1' */
#define SYSCON_SYSOSCCTRL_FREQ_RANGE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSOSCCTRL_FREQ_RANGE_SHIFT)) & SYSCON_SYSOSCCTRL_FREQ_RANGE_MASK)
/*! @} */

/*! @name WDTOSCCTRL - Watchdog oscillator control */
/*! @{ */

#define SYSCON_WDTOSCCTRL_DIVSEL_MASK            (0x1FU)
#define SYSCON_WDTOSCCTRL_DIVSEL_SHIFT           (0U)
/*! DIVSEL - Select divider for Fclkana. wdt_osc_clk = Fclkana/ (2 x (1 + DIVSEL)) 00000: 2 x (1 +
 *    DIVSEL) = 2 00001: 2 x (1 + DIVSEL) = 4 to 11111: 2 x (1 + DIVSEL) = 64
 */
#define SYSCON_WDTOSCCTRL_DIVSEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTOSCCTRL_DIVSEL_SHIFT)) & SYSCON_WDTOSCCTRL_DIVSEL_MASK)

#define SYSCON_WDTOSCCTRL_FREQSEL_MASK           (0x1E0U)
#define SYSCON_WDTOSCCTRL_FREQSEL_SHIFT          (5U)
/*! FREQSEL - Frequency select. Selects the frequency of the oscillator. 0x00 = invalid setting when
 *    watchdog oscillator is running 0x1 = 0.6 MHz 0x2 = 1.05 MHz 0x3 = 1.4 MHz 0x4 = 1.75 MHz 0x5
 *    = 2.1 MHz 0x6 = 2.4 MHz 0x7 = 2.7 MHz 0x8 = 3.0 MHz 0x9 = 3.25 MHz 0xA = 3.5 MHz 0xB = 3.75
 *    MHz 0xC = 4.0 MHz 0xD = 4.2 MHz 0xE = 4.4 MHz 0xF = 4.6 MHz
 */
#define SYSCON_WDTOSCCTRL_FREQSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTOSCCTRL_FREQSEL_SHIFT)) & SYSCON_WDTOSCCTRL_FREQSEL_MASK)
/*! @} */

/*! @name IRCCTRL - IRC control */
/*! @{ */

#define SYSCON_IRCCTRL_TRIM_MASK                 (0xFFU)
#define SYSCON_IRCCTRL_TRIM_SHIFT                (0U)
/*! TRIM - Trim value */
#define SYSCON_IRCCTRL_TRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_IRCCTRL_TRIM_SHIFT)) & SYSCON_IRCCTRL_TRIM_MASK)
/*! @} */

/*! @name SYSRSTSTAT - System reset status register */
/*! @{ */

#define SYSCON_SYSRSTSTAT_POR_MASK               (0x1U)
#define SYSCON_SYSRSTSTAT_POR_SHIFT              (0U)
/*! POR - POR reset status.
 *  0b0..No POR detected.
 *  0b1..POR detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_POR(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_POR_SHIFT)) & SYSCON_SYSRSTSTAT_POR_MASK)

#define SYSCON_SYSRSTSTAT_EXTRST_MASK            (0x2U)
#define SYSCON_SYSRSTSTAT_EXTRST_SHIFT           (1U)
/*! EXTRST - Status of the external RESET pin. External reset status.
 *  0b0..No reset event detected.
 *  0b1..Reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_EXTRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_EXTRST_SHIFT)) & SYSCON_SYSRSTSTAT_EXTRST_MASK)

#define SYSCON_SYSRSTSTAT_WDT_MASK               (0x4U)
#define SYSCON_SYSRSTSTAT_WDT_SHIFT              (2U)
/*! WDT - Status of the Watchdog reset.
 *  0b0..No WDT reset detected.
 *  0b1..WDT reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_WDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_WDT_SHIFT)) & SYSCON_SYSRSTSTAT_WDT_MASK)

#define SYSCON_SYSRSTSTAT_BOD_MASK               (0x8U)
#define SYSCON_SYSRSTSTAT_BOD_SHIFT              (3U)
/*! BOD - Status of the Brown-out detect reset.
 *  0b0..No BOD reset detected.
 *  0b1..BOD reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_BOD(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_BOD_SHIFT)) & SYSCON_SYSRSTSTAT_BOD_MASK)

#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x10U)
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (4U)
/*! SYSRST - Status of the software system reset.
 *  0b0..No System reset detected.
 *  0b1..System reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_SYSRST_SHIFT)) & SYSCON_SYSRSTSTAT_SYSRST_MASK)
/*! @} */

/*! @name SYSPLLCLKSEL - System PLL clock source select register */
/*! @{ */

#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x3U)
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)
/*! SEL - System PLL clock source
 *  0b00..IRC
 *  0b01..Crystal Oscillator (SYSOSC)
 *  0b10..Reserved
 *  0b11..CLKIN. External clock input.
 */
#define SYSCON_SYSPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCLKSEL_SEL_SHIFT)) & SYSCON_SYSPLLCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSPLLCLKUEN - System PLL clock source update enable register */
/*! @{ */

#define SYSCON_SYSPLLCLKUEN_ENA_MASK             (0x1U)
#define SYSCON_SYSPLLCLKUEN_ENA_SHIFT            (0U)
/*! ENA - Enable system PLL clock source update
 *  0b0..no change
 *  0b1..update clock source
 */
#define SYSCON_SYSPLLCLKUEN_ENA(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCLKUEN_ENA_SHIFT)) & SYSCON_SYSPLLCLKUEN_ENA_MASK)
/*! @} */

/*! @name MAINCLKSEL - Main clock source select */
/*! @{ */

#define SYSCON_MAINCLKSEL_SEL_MASK               (0x3U)
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Clock source for main clock.
 *  0b00..IRC Oscillator.
 *  0b01..PLL input.
 *  0b10..Watchdog oscillator.
 *  0b11..PLL output.
 */
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSEL_SEL_SHIFT)) & SYSCON_MAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKUEN - Main clock source update enable */
/*! @{ */

#define SYSCON_MAINCLKUEN_ENA_MASK               (0x1U)
#define SYSCON_MAINCLKUEN_ENA_SHIFT              (0U)
/*! ENA - Enable main clock source update.
 *  0b0..No change.
 *  0b1..Update clock source.
 */
#define SYSCON_MAINCLKUEN_ENA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKUEN_ENA_SHIFT)) & SYSCON_MAINCLKUEN_ENA_MASK)
/*! @} */

/*! @name SYSAHBCLKDIV - System clock divider */
/*! @{ */

#define SYSCON_SYSAHBCLKDIV_DIV_MASK             (0xFFU)
#define SYSCON_SYSAHBCLKDIV_DIV_SHIFT            (0U)
/*! DIV - System AHB clock divider values 0: System clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_SYSAHBCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKDIV_DIV_SHIFT)) & SYSCON_SYSAHBCLKDIV_DIV_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL - System clock control */
/*! @{ */

#define SYSCON_SYSAHBCLKCTRL_SYS_MASK            (0x1U)
#define SYSCON_SYSAHBCLKCTRL_SYS_SHIFT           (0U)
/*! SYS - Enables the clock for the AHB, the APB bridge, the Cortex-M0+ core clocks, SYSCON, and the
 *    PMU. This bit is read only and always reads as 1.
 */
#define SYSCON_SYSAHBCLKCTRL_SYS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_SYS_SHIFT)) & SYSCON_SYSAHBCLKCTRL_SYS_MASK)

#define SYSCON_SYSAHBCLKCTRL_ROM_MASK            (0x2U)
#define SYSCON_SYSAHBCLKCTRL_ROM_SHIFT           (1U)
/*! ROM - Enables clock for ROM.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_ROM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_ROM_SHIFT)) & SYSCON_SYSAHBCLKCTRL_ROM_MASK)

#define SYSCON_SYSAHBCLKCTRL_RAM0_1_MASK         (0x4U)
#define SYSCON_SYSAHBCLKCTRL_RAM0_1_SHIFT        (2U)
/*! RAM0_1 - Enables clock for SRAM0 and SRAM1.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_RAM0_1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_RAM0_1_SHIFT)) & SYSCON_SYSAHBCLKCTRL_RAM0_1_MASK)

#define SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK       (0x8U)
#define SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT      (3U)
/*! FLASHREG - Enables clock for flash register interface.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_FLASHREG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_FLASHREG_SHIFT)) & SYSCON_SYSAHBCLKCTRL_FLASHREG_MASK)

#define SYSCON_SYSAHBCLKCTRL_FLASH_MASK          (0x10U)
#define SYSCON_SYSAHBCLKCTRL_FLASH_SHIFT         (4U)
/*! FLASH - Enables clock for flash.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_FLASH(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_FLASH_SHIFT)) & SYSCON_SYSAHBCLKCTRL_FLASH_MASK)

#define SYSCON_SYSAHBCLKCTRL_I2C0_MASK           (0x20U)
#define SYSCON_SYSAHBCLKCTRL_I2C0_SHIFT          (5U)
/*! I2C0 - Enables clock for I2C0.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_I2C0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_I2C0_SHIFT)) & SYSCON_SYSAHBCLKCTRL_I2C0_MASK)

#define SYSCON_SYSAHBCLKCTRL_GPIO_MASK           (0x40U)
#define SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT          (6U)
/*! GPIO - Enables clock for GPIO port registers and GPIO pin interrupt registers.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_GPIO(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_GPIO_SHIFT)) & SYSCON_SYSAHBCLKCTRL_GPIO_MASK)

#define SYSCON_SYSAHBCLKCTRL_SWM_MASK            (0x80U)
#define SYSCON_SYSAHBCLKCTRL_SWM_SHIFT           (7U)
/*! SWM - Enables clock for switch matrix.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_SWM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_SWM_SHIFT)) & SYSCON_SYSAHBCLKCTRL_SWM_MASK)

#define SYSCON_SYSAHBCLKCTRL_SCT_MASK            (0x100U)
#define SYSCON_SYSAHBCLKCTRL_SCT_SHIFT           (8U)
/*! SCT - Enables clock for state configurable timer SCTimer/PWM.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_SCT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_SCT_SHIFT)) & SYSCON_SYSAHBCLKCTRL_SCT_MASK)

#define SYSCON_SYSAHBCLKCTRL_WKT_MASK            (0x200U)
#define SYSCON_SYSAHBCLKCTRL_WKT_SHIFT           (9U)
/*! WKT - Enables clock for self-wake-up timer.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_WKT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_WKT_SHIFT)) & SYSCON_SYSAHBCLKCTRL_WKT_MASK)

#define SYSCON_SYSAHBCLKCTRL_MRT_MASK            (0x400U)
#define SYSCON_SYSAHBCLKCTRL_MRT_SHIFT           (10U)
/*! MRT - Enables clock for multi-rate timer.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_MRT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_MRT_SHIFT)) & SYSCON_SYSAHBCLKCTRL_MRT_MASK)

#define SYSCON_SYSAHBCLKCTRL_SPI0_MASK           (0x800U)
#define SYSCON_SYSAHBCLKCTRL_SPI0_SHIFT          (11U)
/*! SPI0 - Enables clock for SPI0.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_SPI0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_SPI0_SHIFT)) & SYSCON_SYSAHBCLKCTRL_SPI0_MASK)

#define SYSCON_SYSAHBCLKCTRL_SPI1_MASK           (0x1000U)
#define SYSCON_SYSAHBCLKCTRL_SPI1_SHIFT          (12U)
/*! SPI1 - Enables clock for SPI1.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_SPI1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_SPI1_SHIFT)) & SYSCON_SYSAHBCLKCTRL_SPI1_MASK)

#define SYSCON_SYSAHBCLKCTRL_CRC_MASK            (0x2000U)
#define SYSCON_SYSAHBCLKCTRL_CRC_SHIFT           (13U)
/*! CRC - Enables clock for CRC.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_CRC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_CRC_SHIFT)) & SYSCON_SYSAHBCLKCTRL_CRC_MASK)

#define SYSCON_SYSAHBCLKCTRL_UART0_MASK          (0x4000U)
#define SYSCON_SYSAHBCLKCTRL_UART0_SHIFT         (14U)
/*! UART0 - Enables clock for USART0.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_UART0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_UART0_SHIFT)) & SYSCON_SYSAHBCLKCTRL_UART0_MASK)

#define SYSCON_SYSAHBCLKCTRL_UART1_MASK          (0x8000U)
#define SYSCON_SYSAHBCLKCTRL_UART1_SHIFT         (15U)
/*! UART1 - Enables clock for USART1.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_UART1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_UART1_SHIFT)) & SYSCON_SYSAHBCLKCTRL_UART1_MASK)

#define SYSCON_SYSAHBCLKCTRL_UART2_MASK          (0x10000U)
#define SYSCON_SYSAHBCLKCTRL_UART2_SHIFT         (16U)
/*! UART2 - Enables clock for USART2.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_UART2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_UART2_SHIFT)) & SYSCON_SYSAHBCLKCTRL_UART2_MASK)

#define SYSCON_SYSAHBCLKCTRL_WWDT_MASK           (0x20000U)
#define SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT          (17U)
/*! WWDT - Enables clock for WWDT.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_WWDT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_WWDT_SHIFT)) & SYSCON_SYSAHBCLKCTRL_WWDT_MASK)

#define SYSCON_SYSAHBCLKCTRL_IOCON_MASK          (0x40000U)
#define SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT         (18U)
/*! IOCON - Enables clock for IOCON block.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_IOCON(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_IOCON_SHIFT)) & SYSCON_SYSAHBCLKCTRL_IOCON_MASK)

#define SYSCON_SYSAHBCLKCTRL_ACMP_MASK           (0x80000U)
#define SYSCON_SYSAHBCLKCTRL_ACMP_SHIFT          (19U)
/*! ACMP - Enables clock to analog comparator.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_ACMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_ACMP_SHIFT)) & SYSCON_SYSAHBCLKCTRL_ACMP_MASK)

#define SYSCON_SYSAHBCLKCTRL_I2C1_MASK           (0x200000U)
#define SYSCON_SYSAHBCLKCTRL_I2C1_SHIFT          (21U)
/*! I2C1 - Enables clock to I2C1.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_I2C1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_I2C1_SHIFT)) & SYSCON_SYSAHBCLKCTRL_I2C1_MASK)

#define SYSCON_SYSAHBCLKCTRL_I2C2_MASK           (0x400000U)
#define SYSCON_SYSAHBCLKCTRL_I2C2_SHIFT          (22U)
/*! I2C2 - Enables clock to I2C2.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_I2C2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_I2C2_SHIFT)) & SYSCON_SYSAHBCLKCTRL_I2C2_MASK)

#define SYSCON_SYSAHBCLKCTRL_I2C3_MASK           (0x800000U)
#define SYSCON_SYSAHBCLKCTRL_I2C3_SHIFT          (23U)
/*! I2C3 - Enables clock to I2C3.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_I2C3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_I2C3_SHIFT)) & SYSCON_SYSAHBCLKCTRL_I2C3_MASK)

#define SYSCON_SYSAHBCLKCTRL_ADC_MASK            (0x1000000U)
#define SYSCON_SYSAHBCLKCTRL_ADC_SHIFT           (24U)
/*! ADC - Enables clock to ADC.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_ADC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_ADC_SHIFT)) & SYSCON_SYSAHBCLKCTRL_ADC_MASK)

#define SYSCON_SYSAHBCLKCTRL_MTB_MASK            (0x4000000U)
#define SYSCON_SYSAHBCLKCTRL_MTB_SHIFT           (26U)
/*! MTB - Enables clock to micro-trace buffer control registers.Turn on this clock when using the
 *    micro-trace buffer for debug purposes.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_MTB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_MTB_SHIFT)) & SYSCON_SYSAHBCLKCTRL_MTB_MASK)

#define SYSCON_SYSAHBCLKCTRL_DMA_MASK            (0x20000000U)
#define SYSCON_SYSAHBCLKCTRL_DMA_SHIFT           (29U)
/*! DMA - Enables clock to DMA.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_SYSAHBCLKCTRL_DMA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL_DMA_SHIFT)) & SYSCON_SYSAHBCLKCTRL_DMA_MASK)
/*! @} */

/*! @name UARTCLKDIV - USART clock divider */
/*! @{ */

#define SYSCON_UARTCLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_UARTCLKDIV_DIV_SHIFT              (0U)
/*! DIV - USART fractional baud rate generator clock divider values. 0: Clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_UARTCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_UARTCLKDIV_DIV_SHIFT)) & SYSCON_UARTCLKDIV_DIV_MASK)
/*! @} */

/*! @name CLKOUTSEL - CLKOUT clock source select */
/*! @{ */

#define SYSCON_CLKOUTSEL_SEL_MASK                (0x3U)
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)
/*! SEL - CLKOUT clock source.
 *  0b00..IRC oscillator
 *  0b01..Crystal oscillator (SYSOSC)
 *  0b10..Watchdog oscillator
 *  0b11..Main clock
 */
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSEL_SEL_SHIFT)) & SYSCON_CLKOUTSEL_SEL_MASK)
/*! @} */

/*! @name CLKOUTUEN - CLKOUT clock source update enable */
/*! @{ */

#define SYSCON_CLKOUTUEN_ENA_MASK                (0x1U)
#define SYSCON_CLKOUTUEN_ENA_SHIFT               (0U)
/*! ENA - Enable CLKOUT clock source update.
 *  0b0..No change
 *  0b1..Update clock source
 */
#define SYSCON_CLKOUTUEN_ENA(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTUEN_ENA_SHIFT)) & SYSCON_CLKOUTUEN_ENA_MASK)
/*! @} */

/*! @name CLKOUTDIV - PLL control */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - CLKOUT clock divider values. 0: Disable CLKOUT clock divider 1: Divide by 1 to 255: Divide by 255 */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)
/*! @} */

/*! @name UARTFRGDIV - USART1 to USART4 common fractional generator divider value */
/*! @{ */

#define SYSCON_UARTFRGDIV_DIV_MASK               (0xFFU)
#define SYSCON_UARTFRGDIV_DIV_SHIFT              (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define SYSCON_UARTFRGDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_UARTFRGDIV_DIV_SHIFT)) & SYSCON_UARTFRGDIV_DIV_MASK)
/*! @} */

/*! @name UARTFRGMULT - USART common fractional generator divider value */
/*! @{ */

#define SYSCON_UARTFRGMULT_MULT_MASK             (0xFFU)
#define SYSCON_UARTFRGMULT_MULT_SHIFT            (0U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define SYSCON_UARTFRGMULT_MULT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_UARTFRGMULT_MULT_SHIFT)) & SYSCON_UARTFRGMULT_MULT_MASK)
/*! @} */

/*! @name EXTTRACECMD - External trace buffer command register */
/*! @{ */

#define SYSCON_EXTTRACECMD_START_MASK            (0x1U)
#define SYSCON_EXTTRACECMD_START_SHIFT           (0U)
/*! START - Trace start command. Writing a one to this bit sets the TSTART signal to the MTB to HIGH
 *    and starts tracing if the TSTARTEN bit in the MTB master register is set to one as well.
 */
#define SYSCON_EXTTRACECMD_START(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_EXTTRACECMD_START_SHIFT)) & SYSCON_EXTTRACECMD_START_MASK)

#define SYSCON_EXTTRACECMD_STOP_MASK             (0x2U)
#define SYSCON_EXTTRACECMD_STOP_SHIFT            (1U)
/*! STOP - Trace stop command. Writing a one to this bit sets the TSTOP signal in the MTB to HIGH
 *    and stops tracing if the TSTOPEN bit in the MTB master register is set to one as well.
 */
#define SYSCON_EXTTRACECMD_STOP(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_EXTTRACECMD_STOP_SHIFT)) & SYSCON_EXTTRACECMD_STOP_MASK)
/*! @} */

/*! @name PIOPORCAP0 - POR captured PIO status 0 */
/*! @{ */

#define SYSCON_PIOPORCAP0_PIOSTAT_MASK           (0x3FFFFU)
#define SYSCON_PIOPORCAP0_PIOSTAT_SHIFT          (0U)
/*! PIOSTAT - State of PIO0_17 through PIO0_0 at power-on reset */
#define SYSCON_PIOPORCAP0_PIOSTAT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORCAP0_PIOSTAT_SHIFT)) & SYSCON_PIOPORCAP0_PIOSTAT_MASK)
/*! @} */

/*! @name IOCONCLKDIV6 - Peripheral clock 6 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV6_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV6_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV6_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV6_DIV_SHIFT)) & SYSCON_IOCONCLKDIV6_DIV_MASK)
/*! @} */

/*! @name IOCONCLKDIV5 - Peripheral clock 6 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV5_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV5_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV5_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV5_DIV_SHIFT)) & SYSCON_IOCONCLKDIV5_DIV_MASK)
/*! @} */

/*! @name IOCONCLKDIV4 - Peripheral clock 4 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV4_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV4_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV4_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV4_DIV_SHIFT)) & SYSCON_IOCONCLKDIV4_DIV_MASK)
/*! @} */

/*! @name IOCONCLKDIV3 - Peripheral clock 3 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV3_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV3_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV3_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV3_DIV_SHIFT)) & SYSCON_IOCONCLKDIV3_DIV_MASK)
/*! @} */

/*! @name IOCONCLKDIV2 - Peripheral clock 2 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV2_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV2_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV2_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV2_DIV_SHIFT)) & SYSCON_IOCONCLKDIV2_DIV_MASK)
/*! @} */

/*! @name IOCONCLKDIV1 - Peripheral clock 1 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV1_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV1_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV1_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV1_DIV_SHIFT)) & SYSCON_IOCONCLKDIV1_DIV_MASK)
/*! @} */

/*! @name IOCONCLKDIV0 - Peripheral clock 0 to the IOCON block for programmable glitch filter */
/*! @{ */

#define SYSCON_IOCONCLKDIV0_DIV_MASK             (0xFFU)
#define SYSCON_IOCONCLKDIV0_DIV_SHIFT            (0U)
/*! DIV - IOCON glitch filter clock divider values 0: Disable IOCONFILTR_PCLK. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_IOCONCLKDIV0_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_IOCONCLKDIV0_DIV_SHIFT)) & SYSCON_IOCONCLKDIV0_DIV_MASK)
/*! @} */

/*! @name BODCTRL - BOD control register */
/*! @{ */

#define SYSCON_BODCTRL_BODRSTLEV_MASK            (0x3U)
#define SYSCON_BODCTRL_BODRSTLEV_SHIFT           (0U)
/*! BODRSTLEV - BOD reset level
 *  0b00..Reserved
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON_BODCTRL_BODRSTLEV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTLEV_SHIFT)) & SYSCON_BODCTRL_BODRSTLEV_MASK)

#define SYSCON_BODCTRL_BODINTVAL_MASK            (0xCU)
#define SYSCON_BODCTRL_BODINTVAL_SHIFT           (2U)
/*! BODINTVAL - BOD interrupt level
 *  0b00..Reserved
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON_BODCTRL_BODINTVAL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODINTVAL_SHIFT)) & SYSCON_BODCTRL_BODINTVAL_MASK)

#define SYSCON_BODCTRL_BODRSTENA_MASK            (0x10U)
#define SYSCON_BODCTRL_BODRSTENA_SHIFT           (4U)
/*! BODRSTENA - BOD reset enable
 *  0b0..Disable reset function.
 *  0b1..Enable reset function.
 */
#define SYSCON_BODCTRL_BODRSTENA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTENA_SHIFT)) & SYSCON_BODCTRL_BODRSTENA_MASK)
/*! @} */

/*! @name SYSTCKCAL - System tick timer calibration register */
/*! @{ */

#define SYSCON_SYSTCKCAL_CAL_MASK                (0x3FFFFFFU)
#define SYSCON_SYSTCKCAL_CAL_SHIFT               (0U)
/*! CAL - System tick timer calibration value. */
#define SYSCON_SYSTCKCAL_CAL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTCKCAL_CAL_SHIFT)) & SYSCON_SYSTCKCAL_CAL_MASK)
/*! @} */

/*! @name IRQLATENCY - IRQ latency register */
/*! @{ */

#define SYSCON_IRQLATENCY_LATENCY_MASK           (0xFFU)
#define SYSCON_IRQLATENCY_LATENCY_SHIFT          (0U)
/*! LATENCY - 8-bit latency value. */
#define SYSCON_IRQLATENCY_LATENCY(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_IRQLATENCY_LATENCY_SHIFT)) & SYSCON_IRQLATENCY_LATENCY_MASK)
/*! @} */

/*! @name NMISRC - NMI source selection register */
/*! @{ */

#define SYSCON_NMISRC_IRQN_MASK                  (0x1FU)
#define SYSCON_NMISRC_IRQN_SHIFT                 (0U)
/*! IRQN - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) if bit 31 is 1 */
#define SYSCON_NMISRC_IRQN(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQN_SHIFT)) & SYSCON_NMISRC_IRQN_MASK)

#define SYSCON_NMISRC_NMIEN_MASK                 (0x80000000U)
#define SYSCON_NMISRC_NMIEN_SHIFT                (31U)
/*! NMIEN - Write a 1 to this bit to enable the Non-Maskable Interrupt (NMI) source selected by bits 4:0. */
#define SYSCON_NMISRC_NMIEN(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIEN_SHIFT)) & SYSCON_NMISRC_NMIEN_MASK)
/*! @} */

/*! @name PINTSEL - Pin interrupt select registers N */
/*! @{ */

#define SYSCON_PINTSEL_INTPIN_MASK               (0x3FU)
#define SYSCON_PINTSEL_INTPIN_SHIFT              (0U)
/*! INTPIN - Pin number select for pin interrupt or pattern match engine input. (PIO0_0 to PIO0_28 correspond to numbers 0 to 28). */
#define SYSCON_PINTSEL_INTPIN(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PINTSEL_INTPIN_SHIFT)) & SYSCON_PINTSEL_INTPIN_MASK)
/*! @} */

/*! @name STARTERP0 - Start logic 0 pin wake-up enable register 0 */
/*! @{ */

#define SYSCON_STARTERP0_PINT0_MASK              (0x1U)
#define SYSCON_STARTERP0_PINT0_SHIFT             (0U)
/*! PINT0 - GPIO pin interrupt 0 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT0_SHIFT)) & SYSCON_STARTERP0_PINT0_MASK)

#define SYSCON_STARTERP0_PINT1_MASK              (0x2U)
#define SYSCON_STARTERP0_PINT1_SHIFT             (1U)
/*! PINT1 - GPIO pin interrupt 1 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT1_SHIFT)) & SYSCON_STARTERP0_PINT1_MASK)

#define SYSCON_STARTERP0_PINT2_MASK              (0x4U)
#define SYSCON_STARTERP0_PINT2_SHIFT             (2U)
/*! PINT2 - GPIO pin interrupt 2 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT2(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT2_SHIFT)) & SYSCON_STARTERP0_PINT2_MASK)

#define SYSCON_STARTERP0_PINT3_MASK              (0x8U)
#define SYSCON_STARTERP0_PINT3_SHIFT             (3U)
/*! PINT3 - GPIO pin interrupt 3 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT3_SHIFT)) & SYSCON_STARTERP0_PINT3_MASK)

#define SYSCON_STARTERP0_PINT4_MASK              (0x10U)
#define SYSCON_STARTERP0_PINT4_SHIFT             (4U)
/*! PINT4 - GPIO pin interrupt 4 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT4_SHIFT)) & SYSCON_STARTERP0_PINT4_MASK)

#define SYSCON_STARTERP0_PINT5_MASK              (0x20U)
#define SYSCON_STARTERP0_PINT5_SHIFT             (5U)
/*! PINT5 - GPIO pin interrupt 5 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT5(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT5_SHIFT)) & SYSCON_STARTERP0_PINT5_MASK)

#define SYSCON_STARTERP0_PINT6_MASK              (0x40U)
#define SYSCON_STARTERP0_PINT6_SHIFT             (6U)
/*! PINT6 - GPIO pin interrupt 6 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT6(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT6_SHIFT)) & SYSCON_STARTERP0_PINT6_MASK)

#define SYSCON_STARTERP0_PINT7_MASK              (0x80U)
#define SYSCON_STARTERP0_PINT7_SHIFT             (7U)
/*! PINT7 - GPIO pin interrupt 7 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP0_PINT7(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP0_PINT7_SHIFT)) & SYSCON_STARTERP0_PINT7_MASK)
/*! @} */

/*! @name STARTERP1 - Start logic 1 interrupt wake-up enable register */
/*! @{ */

#define SYSCON_STARTERP1_SPI0_MASK               (0x1U)
#define SYSCON_STARTERP1_SPI0_SHIFT              (0U)
/*! SPI0 - SPI0 interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_SPI0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_SPI0_SHIFT)) & SYSCON_STARTERP1_SPI0_MASK)

#define SYSCON_STARTERP1_SPI1_MASK               (0x2U)
#define SYSCON_STARTERP1_SPI1_SHIFT              (1U)
/*! SPI1 - SPI1 interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_SPI1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_SPI1_SHIFT)) & SYSCON_STARTERP1_SPI1_MASK)

#define SYSCON_STARTERP1_USART0_MASK             (0x8U)
#define SYSCON_STARTERP1_USART0_SHIFT            (3U)
/*! USART0 - USART0 interrupt wake-up. Configure USART in synchronous slave mode.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_USART0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_USART0_SHIFT)) & SYSCON_STARTERP1_USART0_MASK)

#define SYSCON_STARTERP1_USART1_MASK             (0x10U)
#define SYSCON_STARTERP1_USART1_SHIFT            (4U)
/*! USART1 - USART1 interrupt wake-up. Configure USART in synchronous slave mode.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_USART1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_USART1_SHIFT)) & SYSCON_STARTERP1_USART1_MASK)

#define SYSCON_STARTERP1_USART2_MASK             (0x20U)
#define SYSCON_STARTERP1_USART2_SHIFT            (5U)
/*! USART2 - USART2 interrupt wake-up. Configure USART in synchronous slave mode.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_USART2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_USART2_SHIFT)) & SYSCON_STARTERP1_USART2_MASK)

#define SYSCON_STARTERP1_I2C1_MASK               (0x80U)
#define SYSCON_STARTERP1_I2C1_SHIFT              (7U)
/*! I2C1 - I2C1 interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_I2C1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_I2C1_SHIFT)) & SYSCON_STARTERP1_I2C1_MASK)

#define SYSCON_STARTERP1_I2C0_MASK               (0x100U)
#define SYSCON_STARTERP1_I2C0_SHIFT              (8U)
/*! I2C0 - I2C0 interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_I2C0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_I2C0_SHIFT)) & SYSCON_STARTERP1_I2C0_MASK)

#define SYSCON_STARTERP1_WWDT_MASK               (0x1000U)
#define SYSCON_STARTERP1_WWDT_SHIFT              (12U)
/*! WWDT - WWDT interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_WWDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_WWDT_SHIFT)) & SYSCON_STARTERP1_WWDT_MASK)

#define SYSCON_STARTERP1_BOD_MASK                (0x2000U)
#define SYSCON_STARTERP1_BOD_SHIFT               (13U)
/*! BOD - BOD interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_BOD(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_BOD_SHIFT)) & SYSCON_STARTERP1_BOD_MASK)

#define SYSCON_STARTERP1_WKT_MASK                (0x8000U)
#define SYSCON_STARTERP1_WKT_SHIFT               (15U)
/*! WKT - Self-wake-up timer interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_WKT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_WKT_SHIFT)) & SYSCON_STARTERP1_WKT_MASK)

#define SYSCON_STARTERP1_I2C2_MASK               (0x200000U)
#define SYSCON_STARTERP1_I2C2_SHIFT              (21U)
/*! I2C2 - I2C2 interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_I2C2(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_I2C2_SHIFT)) & SYSCON_STARTERP1_I2C2_MASK)

#define SYSCON_STARTERP1_I2C3_MASK               (0x400000U)
#define SYSCON_STARTERP1_I2C3_SHIFT              (22U)
/*! I2C3 - I2C3 interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_I2C3(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_I2C3_SHIFT)) & SYSCON_STARTERP1_I2C3_MASK)
/*! @} */

/*! @name PDSLEEPCFG - Deep-sleep configuration register */
/*! @{ */

#define SYSCON_PDSLEEPCFG_BOD_PD_MASK            (0x8U)
#define SYSCON_PDSLEEPCFG_BOD_PD_SHIFT           (3U)
/*! BOD_PD - BOD power-down control for Deep-sleep and Power-down mode
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDSLEEPCFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_BOD_PD_SHIFT)) & SYSCON_PDSLEEPCFG_BOD_PD_MASK)

#define SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK         (0x40U)
#define SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT        (6U)
/*! WDTOSC_PD - Watchdog oscillator power-down control for Deep-sleep and Power-down mode. Changing
 *    this bit to powered-down has no effect when the LOCK bit in the WWDT MOD register is set. In
 *    this case, the watchdog oscillator is always running.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDSLEEPCFG_WDTOSC_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_WDTOSC_PD_SHIFT)) & SYSCON_PDSLEEPCFG_WDTOSC_PD_MASK)
/*! @} */

/*! @name PDAWAKECFG - Wake-up configuration register */
/*! @{ */

#define SYSCON_PDAWAKECFG_IRCOUT_PD_MASK         (0x1U)
#define SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT        (0U)
/*! IRCOUT_PD - IRC oscillator output wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_IRCOUT_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_IRCOUT_PD_SHIFT)) & SYSCON_PDAWAKECFG_IRCOUT_PD_MASK)

#define SYSCON_PDAWAKECFG_IRC_PD_MASK            (0x2U)
#define SYSCON_PDAWAKECFG_IRC_PD_SHIFT           (1U)
/*! IRC_PD - IRC oscillator power-down wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_IRC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_IRC_PD_SHIFT)) & SYSCON_PDAWAKECFG_IRC_PD_MASK)

#define SYSCON_PDAWAKECFG_FLASH_PD_MASK          (0x4U)
#define SYSCON_PDAWAKECFG_FLASH_PD_SHIFT         (2U)
/*! FLASH_PD - Flash wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_FLASH_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FLASH_PD_SHIFT)) & SYSCON_PDAWAKECFG_FLASH_PD_MASK)

#define SYSCON_PDAWAKECFG_BOD_PD_MASK            (0x8U)
#define SYSCON_PDAWAKECFG_BOD_PD_SHIFT           (3U)
/*! BOD_PD - BOD wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_BOD_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_BOD_PD_SHIFT)) & SYSCON_PDAWAKECFG_BOD_PD_MASK)

#define SYSCON_PDAWAKECFG_ADC_PD_MASK            (0x10U)
#define SYSCON_PDAWAKECFG_ADC_PD_SHIFT           (4U)
/*! ADC_PD - ADC wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_ADC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_ADC_PD_SHIFT)) & SYSCON_PDAWAKECFG_ADC_PD_MASK)

#define SYSCON_PDAWAKECFG_SYSOSC_PD_MASK         (0x20U)
#define SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT        (5U)
/*! SYSOSC_PD - Crystal oscillator wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_SYSOSC_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_SYSOSC_PD_SHIFT)) & SYSCON_PDAWAKECFG_SYSOSC_PD_MASK)

#define SYSCON_PDAWAKECFG_WDTOSC_PD_MASK         (0x40U)
#define SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT        (6U)
/*! WDTOSC_PD - Watchdog oscillator wake-up configuration. Changing this bit to powered-down has no
 *    effect when the LOCK bit in the WWDT MOD register is set. In this case, the watchdog
 *    oscillator is always running
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_WDTOSC_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_WDTOSC_PD_SHIFT)) & SYSCON_PDAWAKECFG_WDTOSC_PD_MASK)

#define SYSCON_PDAWAKECFG_SYSPLL_PD_MASK         (0x80U)
#define SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT        (7U)
/*! SYSPLL_PD - System PLL wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_SYSPLL_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_SYSPLL_PD_SHIFT)) & SYSCON_PDAWAKECFG_SYSPLL_PD_MASK)

#define SYSCON_PDAWAKECFG_ACMP_MASK              (0x8000U)
#define SYSCON_PDAWAKECFG_ACMP_SHIFT             (15U)
/*! ACMP - Analog comparator wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_ACMP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_ACMP_SHIFT)) & SYSCON_PDAWAKECFG_ACMP_MASK)
/*! @} */

/*! @name PDRUNCFG - Power configuration register */
/*! @{ */

#define SYSCON_PDRUNCFG_IRCOUT_PD_MASK           (0x1U)
#define SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT          (0U)
/*! IRCOUT_PD - IRC oscillator output wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_IRCOUT_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_IRCOUT_PD_SHIFT)) & SYSCON_PDRUNCFG_IRCOUT_PD_MASK)

#define SYSCON_PDRUNCFG_IRC_PD_MASK              (0x2U)
#define SYSCON_PDRUNCFG_IRC_PD_SHIFT             (1U)
/*! IRC_PD - IRC oscillator power-down wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_IRC_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_IRC_PD_SHIFT)) & SYSCON_PDRUNCFG_IRC_PD_MASK)

#define SYSCON_PDRUNCFG_FLASH_PD_MASK            (0x4U)
#define SYSCON_PDRUNCFG_FLASH_PD_SHIFT           (2U)
/*! FLASH_PD - Flash wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_FLASH_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FLASH_PD_SHIFT)) & SYSCON_PDRUNCFG_FLASH_PD_MASK)

#define SYSCON_PDRUNCFG_BOD_PD_MASK              (0x8U)
#define SYSCON_PDRUNCFG_BOD_PD_SHIFT             (3U)
/*! BOD_PD - BOD wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_BOD_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_BOD_PD_SHIFT)) & SYSCON_PDRUNCFG_BOD_PD_MASK)

#define SYSCON_PDRUNCFG_ADC_PD_MASK              (0x10U)
#define SYSCON_PDRUNCFG_ADC_PD_SHIFT             (4U)
/*! ADC_PD - ADC wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_ADC_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_ADC_PD_SHIFT)) & SYSCON_PDRUNCFG_ADC_PD_MASK)

#define SYSCON_PDRUNCFG_SYSOSC_PD_MASK           (0x20U)
#define SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT          (5U)
/*! SYSOSC_PD - Crystal oscillator wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_SYSOSC_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_SYSOSC_PD_SHIFT)) & SYSCON_PDRUNCFG_SYSOSC_PD_MASK)

#define SYSCON_PDRUNCFG_WDTOSC_PD_MASK           (0x40U)
#define SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT          (6U)
/*! WDTOSC_PD - Watchdog oscillator wake-up configuration. Changing this bit to powered-down has no
 *    effect when the LOCK bit in the WWDT MOD register is set. In this case, the watchdog
 *    oscillator is always running
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_WDTOSC_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_WDTOSC_PD_SHIFT)) & SYSCON_PDRUNCFG_WDTOSC_PD_MASK)

#define SYSCON_PDRUNCFG_SYSPLL_PD_MASK           (0x80U)
#define SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT          (7U)
/*! SYSPLL_PD - System PLL wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_SYSPLL_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_SYSPLL_PD_SHIFT)) & SYSCON_PDRUNCFG_SYSPLL_PD_MASK)

#define SYSCON_PDRUNCFG_ACMP_MASK                (0x8000U)
#define SYSCON_PDRUNCFG_ACMP_SHIFT               (15U)
/*! ACMP - Analog comparator wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_ACMP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_ACMP_SHIFT)) & SYSCON_PDRUNCFG_ACMP_MASK)
/*! @} */

/*! @name DEVICE_ID - Part ID register */
/*! @{ */

#define SYSCON_DEVICE_ID_DEVICEID_MASK           (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_DEVICEID_SHIFT          (0U)
/*! DEVICEID - Part ID */
#define SYSCON_DEVICE_ID_DEVICEID(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID_DEVICEID_SHIFT)) & SYSCON_DEVICE_ID_DEVICEID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SYSCON_H_ */

