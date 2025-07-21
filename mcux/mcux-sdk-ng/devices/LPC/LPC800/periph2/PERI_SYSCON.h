/*
** ###################################################################
**     Processors:          LPC844M201JBD48
**                          LPC844M201JBD64
**                          LPC844M201JHI33
**                          LPC844M201JHI48
**                          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
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
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
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

#if (defined(CPU_LPC844M201JBD48) || defined(CPU_LPC844M201JBD64) || defined(CPU_LPC844M201JHI33) || defined(CPU_LPC844M201JHI48))
#include "LPC844_COMMON.h"
#elif (defined(CPU_LPC845M301JBD48) || defined(CPU_LPC845M301JBD64) || defined(CPU_LPC845M301JHI33) || defined(CPU_LPC845M301JHI48))
#include "LPC845_COMMON.h"
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
#define SYSCON_FCLKSEL_COUNT                      11u
#define SYSCON_FRG_COUNT                          2u
#define SYSCON_PIOPORCAP_COUNT                    2u
#define SYSCON_PINTSEL_COUNT                      8u

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< System Remap register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SYSPLLCTRL;                        /**< PLL control, offset: 0x8 */
  __I  uint32_t SYSPLLSTAT;                        /**< PLL status, offset: 0xC */
       uint8_t RESERVED_1[16];
  __IO uint32_t SYSOSCCTRL;                        /**< system oscillator control, offset: 0x20 */
  __IO uint32_t WDTOSCCTRL;                        /**< Watchdog oscillator control, offset: 0x24 */
  __IO uint32_t FROOSCCTRL;                        /**< FRO oscillator control, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FRODIRECTCLKUEN;                   /**< FRO direct clock source update enable register, offset: 0x30 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register, offset: 0x38 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SYSPLLCLKSEL;                      /**< System PLL clock source select register, offset: 0x40 */
  __IO uint32_t SYSPLLCLKUEN;                      /**< System PLL clock source update enable register, offset: 0x44 */
  __IO uint32_t MAINCLKPLLSEL;                     /**< Main clock source select register, offset: 0x48 */
  __IO uint32_t MAINCLKPLLUEN;                     /**< Main clock source update enable register, offset: 0x4C */
  __IO uint32_t MAINCLKSEL;                        /**< Main clock source select register, offset: 0x50 */
  __IO uint32_t MAINCLKUEN;                        /**< Main clock source update enable register, offset: 0x54 */
  __IO uint32_t SYSAHBCLKDIV;                      /**< System clock divider register, offset: 0x58 */
       uint8_t RESERVED_5[4];
  __IO uint32_t CAPTCLKSEL;                        /**< CAPT clock source select register, offset: 0x60 */
  __IO uint32_t ADCCLKSEL;                         /**< ADC clock source select register, offset: 0x64 */
  __IO uint32_t ADCCLKDIV;                         /**< ADC clock divider register, offset: 0x68 */
  __IO uint32_t SCTCLKSEL;                         /**< SCT clock source select register, offset: 0x6C */
  __IO uint32_t SCTCLKDIV;                         /**< SCT clock divider register, offset: 0x70 */
  __IO uint32_t EXTCLKSEL;                         /**< external clock source select register, offset: 0x74 */
       uint8_t RESERVED_6[8];
  __IO uint32_t SYSAHBCLKCTRL0;                    /**< System clock group 0 control register, offset: 0x80 */
  __IO uint32_t SYSAHBCLKCTRL1;                    /**< System clock group 1 control register, offset: 0x84 */
  __IO uint32_t PRESETCTRL0;                       /**< Peripheral reset group 0 control register, offset: 0x88 */
  __IO uint32_t PRESETCTRL1;                       /**< Peripheral reset group 1 control register, offset: 0x8C */
  __IO uint32_t FCLKSEL[SYSCON_FCLKSEL_COUNT];     /**< peripheral clock source select register. FCLK0SEL~FCLK4SEL are for UART0~UART4 clock source select register. FCLK5SEL~FCLK8SEL are for I2C0~I2C3 clock source select register. FCLK9SEL~FCLK10SEL are for SPI0~SPI1 clock source select register., array offset: 0x90, array step: 0x4 */
       uint8_t RESERVED_7[20];
  struct {                                         /* offset: 0xD0, array step: 0x10 */
    __IO uint32_t FRGDIV;                            /**< fractional generator N divider value register, array offset: 0xD0, array step: 0x10 */
    __IO uint32_t FRGMULT;                           /**< fractional generator N multiplier value register, array offset: 0xD4, array step: 0x10 */
    __IO uint32_t FRGCLKSEL;                         /**< FRG N clock source select register, array offset: 0xD8, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } FRG[SYSCON_FRG_COUNT];
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT clock source select register, offset: 0xF0 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider registers, offset: 0xF4 */
       uint8_t RESERVED_8[4];
  __IO uint32_t EXTTRACECMD;                       /**< External trace buffer command register, offset: 0xFC */
  __I  uint32_t PIOPORCAP[SYSCON_PIOPORCAP_COUNT]; /**< POR captured PIO N status register(PIO0 has 32 PIOs, PIO1 has 22 PIOs), array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_9[44];
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
  __IO uint32_t STARTERP1;                         /**< Start logic 0 pin wake-up enable register 1, offset: 0x214 */
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
/*! BYPASS - oscillator (Xtal) Test Mode input (Active High) */
#define SYSCON_SYSOSCCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSOSCCTRL_BYPASS_SHIFT)) & SYSCON_SYSOSCCTRL_BYPASS_MASK)

#define SYSCON_SYSOSCCTRL_FREQRANGE_MASK         (0x2U)
#define SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT        (1U)
/*! FREQRANGE - oscillator low / high transconductance selection input (Active High) 1-20MHz '0' : 15-50MHz '1' */
#define SYSCON_SYSOSCCTRL_FREQRANGE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT)) & SYSCON_SYSOSCCTRL_FREQRANGE_MASK)
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

/*! @name FROOSCCTRL - FRO oscillator control */
/*! @{ */

#define SYSCON_FROOSCCTRL_FRO_DIRECT_MASK        (0x20000U)
#define SYSCON_FROOSCCTRL_FRO_DIRECT_SHIFT       (17U)
/*! FRO_DIRECT - fro direct clock select
 *  0b0..fro clock is divider by 2 or 16,depend on FAIM slow boot value
 *  0b1..fro clock is direct from FRO oscillator
 */
#define SYSCON_FROOSCCTRL_FRO_DIRECT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FROOSCCTRL_FRO_DIRECT_SHIFT)) & SYSCON_FROOSCCTRL_FRO_DIRECT_MASK)
/*! @} */

/*! @name FRODIRECTCLKUEN - FRO direct clock source update enable register */
/*! @{ */

#define SYSCON_FRODIRECTCLKUEN_ENA_MASK          (0x1U)
#define SYSCON_FRODIRECTCLKUEN_ENA_SHIFT         (0U)
/*! ENA - Enable fro clock source update
 *  0b0..no change
 *  0b1..update clock source
 */
#define SYSCON_FRODIRECTCLKUEN_ENA(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FRODIRECTCLKUEN_ENA_SHIFT)) & SYSCON_FRODIRECTCLKUEN_ENA_MASK)
/*! @} */

/*! @name SYSRSTSTAT - System reset status register */
/*! @{ */

#define SYSCON_SYSRSTSTAT_POR_MASK               (0x1U)
#define SYSCON_SYSRSTSTAT_POR_SHIFT              (0U)
/*! POR - POR reset status
 *  0b0..No POR detected
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
/*! WDT - Status of the Watchdog reset
 *  0b0..No WDT reset detected
 *  0b1..WDT reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_WDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_WDT_SHIFT)) & SYSCON_SYSRSTSTAT_WDT_MASK)

#define SYSCON_SYSRSTSTAT_BOD_MASK               (0x8U)
#define SYSCON_SYSRSTSTAT_BOD_SHIFT              (3U)
/*! BOD - Status of the Brown-out detect reset
 *  0b0..No BOD reset detected
 *  0b1..BOD reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_BOD(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_BOD_SHIFT)) & SYSCON_SYSRSTSTAT_BOD_MASK)

#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x10U)
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (4U)
/*! SYSRST - Status of the software system reset
 *  0b0..No System reset detected
 *  0b1..System reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_SYSRST_SHIFT)) & SYSCON_SYSRSTSTAT_SYSRST_MASK)
/*! @} */

/*! @name SYSPLLCLKSEL - System PLL clock source select register */
/*! @{ */

#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x3U)
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)
/*! SEL - System PLL clock source
 *  0b00..FRO
 *  0b01..External clock
 *  0b10..Watchdog oscillator
 *  0b11..FRO DIV
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

/*! @name MAINCLKPLLSEL - Main clock source select register */
/*! @{ */

#define SYSCON_MAINCLKPLLSEL_SEL_MASK            (0x3U)
#define SYSCON_MAINCLKPLLSEL_SEL_SHIFT           (0U)
/*! SEL - System PLL clock source
 *  0b00..main_clk_pre_pll
 *  0b01..sys pll
 *  0b10..none
 *  0b11..none
 */
#define SYSCON_MAINCLKPLLSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKPLLSEL_SEL_SHIFT)) & SYSCON_MAINCLKPLLSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKPLLUEN - Main clock source update enable register */
/*! @{ */

#define SYSCON_MAINCLKPLLUEN_ENA_MASK            (0x1U)
#define SYSCON_MAINCLKPLLUEN_ENA_SHIFT           (0U)
/*! ENA - Enable main clock source update
 *  0b0..no change
 *  0b1..update clock source
 */
#define SYSCON_MAINCLKPLLUEN_ENA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKPLLUEN_ENA_SHIFT)) & SYSCON_MAINCLKPLLUEN_ENA_MASK)
/*! @} */

/*! @name MAINCLKSEL - Main clock source select register */
/*! @{ */

#define SYSCON_MAINCLKSEL_SEL_MASK               (0x3U)
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)
/*! SEL - System PLL clock source
 *  0b00..FRO
 *  0b01..External clock
 *  0b10..Watchdog oscillator
 *  0b11..FRO_DIV
 */
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSEL_SEL_SHIFT)) & SYSCON_MAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKUEN - Main clock source update enable register */
/*! @{ */

#define SYSCON_MAINCLKUEN_ENA_MASK               (0x1U)
#define SYSCON_MAINCLKUEN_ENA_SHIFT              (0U)
/*! ENA - Enable main clock source update
 *  0b0..no change
 *  0b1..update clock source
 */
#define SYSCON_MAINCLKUEN_ENA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKUEN_ENA_SHIFT)) & SYSCON_MAINCLKUEN_ENA_MASK)
/*! @} */

/*! @name SYSAHBCLKDIV - System clock divider register */
/*! @{ */

#define SYSCON_SYSAHBCLKDIV_DIV_MASK             (0xFFU)
#define SYSCON_SYSAHBCLKDIV_DIV_SHIFT            (0U)
/*! DIV - System AHB clock divider values 0: System clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_SYSAHBCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKDIV_DIV_SHIFT)) & SYSCON_SYSAHBCLKDIV_DIV_MASK)
/*! @} */

/*! @name CAPTCLKSEL - CAPT clock source select register */
/*! @{ */

#define SYSCON_CAPTCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_CAPTCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Clock source for CAPT clock
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..sys pll
 *  0b011..FRO_DIV
 *  0b100..Watchdog oscillator
 *  0b101..None
 *  0b110..None
 *  0b111..None
 */
#define SYSCON_CAPTCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CAPTCLKSEL_SEL_SHIFT)) & SYSCON_CAPTCLKSEL_SEL_MASK)
/*! @} */

/*! @name ADCCLKSEL - ADC clock source select register */
/*! @{ */

#define SYSCON_ADCCLKSEL_SEL_MASK                (0x3U)
#define SYSCON_ADCCLKSEL_SEL_SHIFT               (0U)
/*! SEL - Clock source for ADC clock
 *  0b00..FRO
 *  0b01..sys pll
 *  0b10..none
 *  0b11..none
 */
#define SYSCON_ADCCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKSEL_SEL_SHIFT)) & SYSCON_ADCCLKSEL_SEL_MASK)
/*! @} */

/*! @name ADCCLKDIV - ADC clock divider register */
/*! @{ */

#define SYSCON_ADCCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_ADCCLKDIV_DIV_SHIFT               (0U)
/*! DIV - ADC clock divider values 0: ADC clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_ADCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_DIV_SHIFT)) & SYSCON_ADCCLKDIV_DIV_MASK)
/*! @} */

/*! @name SCTCLKSEL - SCT clock source select register */
/*! @{ */

#define SYSCON_SCTCLKSEL_SEL_MASK                (0x3U)
#define SYSCON_SCTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - Clock source for SCT clock
 *  0b00..FRO
 *  0b01..main clock
 *  0b10..sys pll
 *  0b11..none
 */
#define SYSCON_SCTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKSEL_SEL_SHIFT)) & SYSCON_SCTCLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTCLKDIV - SCT clock divider register */
/*! @{ */

#define SYSCON_SCTCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SCTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - SCT clock divider values 0: SCT clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_SCTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_DIV_SHIFT)) & SYSCON_SCTCLKDIV_DIV_MASK)
/*! @} */

/*! @name EXTCLKSEL - external clock source select register */
/*! @{ */

#define SYSCON_EXTCLKSEL_SEL_MASK                (0x1U)
#define SYSCON_EXTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - Clock source for external clock
 *  0b0..System oscillator
 *  0b1..Clk_in
 */
#define SYSCON_EXTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_EXTCLKSEL_SEL_SHIFT)) & SYSCON_EXTCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL0 - System clock group 0 control register */
/*! @{ */

#define SYSCON_SYSAHBCLKCTRL0_SYS_MASK           (0x1U)
#define SYSCON_SYSAHBCLKCTRL0_SYS_SHIFT          (0U)
/*! SYS - Enables the clock for the AHB, the APB bridge, the Cortex-M0+ core clocks, SYSCON, and the
 *    PMU. This bit is read only and always reads as 1.
 */
#define SYSCON_SYSAHBCLKCTRL0_SYS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SYS_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SYS_MASK)

#define SYSCON_SYSAHBCLKCTRL0_ROM_MASK           (0x2U)
#define SYSCON_SYSAHBCLKCTRL0_ROM_SHIFT          (1U)
/*! ROM - Enables clock for ROM.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_ROM(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_ROM_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_ROM_MASK)

#define SYSCON_SYSAHBCLKCTRL0_RAM0_1_MASK        (0x4U)
#define SYSCON_SYSAHBCLKCTRL0_RAM0_1_SHIFT       (2U)
/*! RAM0_1 - Enables clock for SRAM0 and SRAM1.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_RAM0_1(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_RAM0_1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_RAM0_1_MASK)

#define SYSCON_SYSAHBCLKCTRL0_FLASH_MASK         (0x10U)
#define SYSCON_SYSAHBCLKCTRL0_FLASH_SHIFT        (4U)
/*! FLASH - Enables clock for flash.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_FLASH(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_FLASH_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_FLASH_MASK)

#define SYSCON_SYSAHBCLKCTRL0_I2C0_MASK          (0x20U)
#define SYSCON_SYSAHBCLKCTRL0_I2C0_SHIFT         (5U)
/*! I2C0 - Enables clock for I2C0.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_I2C0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C0_MASK)

#define SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK         (0x40U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT        (6U)
/*! GPIO0 - Enables clock for GPIO0 port registers.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_GPIO0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK)

#define SYSCON_SYSAHBCLKCTRL0_SWM_MASK           (0x80U)
#define SYSCON_SYSAHBCLKCTRL0_SWM_SHIFT          (7U)
/*! SWM - Enables clock for switch matrix.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_SWM(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SWM_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SWM_MASK)

#define SYSCON_SYSAHBCLKCTRL0_SCT_MASK           (0x100U)
#define SYSCON_SYSAHBCLKCTRL0_SCT_SHIFT          (8U)
/*! SCT - Enables clock for state configurable timer SCTimer/PWM.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_SCT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SCT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SCT_MASK)

#define SYSCON_SYSAHBCLKCTRL0_WKT_MASK           (0x200U)
#define SYSCON_SYSAHBCLKCTRL0_WKT_SHIFT          (9U)
/*! WKT - Enables clock for self-wake-up timer.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_WKT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_WKT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_WKT_MASK)

#define SYSCON_SYSAHBCLKCTRL0_MRT_MASK           (0x400U)
#define SYSCON_SYSAHBCLKCTRL0_MRT_SHIFT          (10U)
/*! MRT - Enables clock for multi-rate timer.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_MRT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_MRT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_MRT_MASK)

#define SYSCON_SYSAHBCLKCTRL0_SPI0_MASK          (0x800U)
#define SYSCON_SYSAHBCLKCTRL0_SPI0_SHIFT         (11U)
/*! SPI0 - Enables clock for SPI0.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_SPI0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SPI0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SPI0_MASK)

#define SYSCON_SYSAHBCLKCTRL0_SPI1_MASK          (0x1000U)
#define SYSCON_SYSAHBCLKCTRL0_SPI1_SHIFT         (12U)
/*! SPI1 - Enables clock for SPI1.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_SPI1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_SPI1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_SPI1_MASK)

#define SYSCON_SYSAHBCLKCTRL0_CRC_MASK           (0x2000U)
#define SYSCON_SYSAHBCLKCTRL0_CRC_SHIFT          (13U)
/*! CRC - Enables clock for CRC.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_CRC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_CRC_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_CRC_MASK)

#define SYSCON_SYSAHBCLKCTRL0_UART0_MASK         (0x4000U)
#define SYSCON_SYSAHBCLKCTRL0_UART0_SHIFT        (14U)
/*! UART0 - Enables clock for UART0.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_UART0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART0_MASK)

#define SYSCON_SYSAHBCLKCTRL0_UART1_MASK         (0x8000U)
#define SYSCON_SYSAHBCLKCTRL0_UART1_SHIFT        (15U)
/*! UART1 - Enables clock for UART1.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_UART1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART1_MASK)

#define SYSCON_SYSAHBCLKCTRL0_UART2_MASK         (0x10000U)
#define SYSCON_SYSAHBCLKCTRL0_UART2_SHIFT        (16U)
/*! UART2 - Enables clock for UART2.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_UART2(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART2_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART2_MASK)

#define SYSCON_SYSAHBCLKCTRL0_WWDT_MASK          (0x20000U)
#define SYSCON_SYSAHBCLKCTRL0_WWDT_SHIFT         (17U)
/*! WWDT - Enables clock for WWDT.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_WWDT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_WWDT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_WWDT_MASK)

#define SYSCON_SYSAHBCLKCTRL0_IOCON_MASK         (0x40000U)
#define SYSCON_SYSAHBCLKCTRL0_IOCON_SHIFT        (18U)
/*! IOCON - Enables clock for IOCON.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_IOCON(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_IOCON_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_IOCON_MASK)

#define SYSCON_SYSAHBCLKCTRL0_ACMP_MASK          (0x80000U)
#define SYSCON_SYSAHBCLKCTRL0_ACMP_SHIFT         (19U)
/*! ACMP - Enables clock for analog comparator.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_ACMP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_ACMP_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_ACMP_MASK)

#define SYSCON_SYSAHBCLKCTRL0_GPIO1_MASK         (0x100000U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT        (20U)
/*! GPIO1 - Enables clock for GPIO1 port registers.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_GPIO1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_GPIO1_MASK)

#define SYSCON_SYSAHBCLKCTRL0_I2C1_MASK          (0x200000U)
#define SYSCON_SYSAHBCLKCTRL0_I2C1_SHIFT         (21U)
/*! I2C1 - Enables clock for I2C1.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_I2C1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C1_MASK)

#define SYSCON_SYSAHBCLKCTRL0_I2C2_MASK          (0x400000U)
#define SYSCON_SYSAHBCLKCTRL0_I2C2_SHIFT         (22U)
/*! I2C2 - Enables clock for I2C2.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_I2C2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C2_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C2_MASK)

#define SYSCON_SYSAHBCLKCTRL0_I2C3_MASK          (0x800000U)
#define SYSCON_SYSAHBCLKCTRL0_I2C3_SHIFT         (23U)
/*! I2C3 - Enables clock for I2C3.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_I2C3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C3_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C3_MASK)

#define SYSCON_SYSAHBCLKCTRL0_ADC_MASK           (0x1000000U)
#define SYSCON_SYSAHBCLKCTRL0_ADC_SHIFT          (24U)
/*! ADC - Enables clock for ADC.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_ADC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_ADC_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_ADC_MASK)

#define SYSCON_SYSAHBCLKCTRL0_CTIMER_MASK        (0x2000000U)
#define SYSCON_SYSAHBCLKCTRL0_CTIMER_SHIFT       (25U)
/*! CTIMER - Enables clock for CTIMER.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_CTIMER(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_CTIMER_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_CTIMER_MASK)

#define SYSCON_SYSAHBCLKCTRL0_MTB_MASK           (0x4000000U)
#define SYSCON_SYSAHBCLKCTRL0_MTB_SHIFT          (26U)
/*! MTB - Enables clock to micro-trace buffer control registers. Turn on this clock when using the
 *    micro-trace buffer for debug purposes.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_MTB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_MTB_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_MTB_MASK)

#define SYSCON_SYSAHBCLKCTRL0_DAC0_MASK          (0x8000000U)
#define SYSCON_SYSAHBCLKCTRL0_DAC0_SHIFT         (27U)
/*! DAC0 - Enables clock for DAC0.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_DAC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_DAC0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_DAC0_MASK)

#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK      (0x10000000U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT_SHIFT     (28U)
/*! GPIO_INT - Enable clock for GPIO pin interrupt registers
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_GPIO_INT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK)

#define SYSCON_SYSAHBCLKCTRL0_DMA_MASK           (0x20000000U)
#define SYSCON_SYSAHBCLKCTRL0_DMA_SHIFT          (29U)
/*! DMA - Enables clock for DMA.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_DMA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_DMA_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_DMA_MASK)

#define SYSCON_SYSAHBCLKCTRL0_UART3_MASK         (0x40000000U)
#define SYSCON_SYSAHBCLKCTRL0_UART3_SHIFT        (30U)
/*! UART3 - Enables clock for UART3.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_UART3(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART3_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART3_MASK)

#define SYSCON_SYSAHBCLKCTRL0_UART4_MASK         (0x80000000U)
#define SYSCON_SYSAHBCLKCTRL0_UART4_SHIFT        (31U)
/*! UART4 - Enables clock for UART4.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_UART4(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_UART4_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_UART4_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL1 - System clock group 1 control register */
/*! @{ */

#define SYSCON_SYSAHBCLKCTRL1_CAPT_MASK          (0x1U)
#define SYSCON_SYSAHBCLKCTRL1_CAPT_SHIFT         (0U)
/*! CAPT - Enables clock for CAPT.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL1_CAPT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL1_CAPT_SHIFT)) & SYSCON_SYSAHBCLKCTRL1_CAPT_MASK)

#define SYSCON_SYSAHBCLKCTRL1_DAC1_MASK          (0x2U)
#define SYSCON_SYSAHBCLKCTRL1_DAC1_SHIFT         (1U)
/*! DAC1 - Enables clock for DAC1.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL1_DAC1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL1_DAC1_SHIFT)) & SYSCON_SYSAHBCLKCTRL1_DAC1_MASK)
/*! @} */

/*! @name PRESETCTRL0 - Peripheral reset group 0 control register */
/*! @{ */

#define SYSCON_PRESETCTRL0_FLASH_RST_N_MASK      (0x10U)
#define SYSCON_PRESETCTRL0_FLASH_RST_N_SHIFT     (4U)
/*! FLASH_RST_N - flash controller reset control
 *  0b0..Assert the flash controller reset.
 *  0b1..Clear the flash controller reset.
 */
#define SYSCON_PRESETCTRL0_FLASH_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FLASH_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_FLASH_RST_N_MASK)

#define SYSCON_PRESETCTRL0_I2C0_RST_N_MASK       (0x20U)
#define SYSCON_PRESETCTRL0_I2C0_RST_N_SHIFT      (5U)
/*! I2C0_RST_N - I2C0 reset control
 *  0b0..Assert the I2C0 reset.
 *  0b1..Clear the I2C0 reset.
 */
#define SYSCON_PRESETCTRL0_I2C0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C0_RST_N_MASK)

#define SYSCON_PRESETCTRL0_GPIO0_RST_N_MASK      (0x40U)
#define SYSCON_PRESETCTRL0_GPIO0_RST_N_SHIFT     (6U)
/*! GPIO0_RST_N - GPIO0 reset control
 *  0b0..Assert the GPIO0 reset.
 *  0b1..Clear the GPIO0 reset.
 */
#define SYSCON_PRESETCTRL0_GPIO0_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_GPIO0_RST_N_MASK)

#define SYSCON_PRESETCTRL0_SWM_RST_N_MASK        (0x80U)
#define SYSCON_PRESETCTRL0_SWM_RST_N_SHIFT       (7U)
/*! SWM_RST_N - SWM reset control
 *  0b0..Assert the SWM reset.
 *  0b1..Clear the SWM reset.
 */
#define SYSCON_PRESETCTRL0_SWM_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SWM_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_SWM_RST_N_MASK)

#define SYSCON_PRESETCTRL0_SCT_RST_N_MASK        (0x100U)
#define SYSCON_PRESETCTRL0_SCT_RST_N_SHIFT       (8U)
/*! SCT_RST_N - SCT reset control
 *  0b0..Assert the SCT reset.
 *  0b1..Clear the SCT reset.
 */
#define SYSCON_PRESETCTRL0_SCT_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SCT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_SCT_RST_N_MASK)

#define SYSCON_PRESETCTRL0_WKT_RST_N_MASK        (0x200U)
#define SYSCON_PRESETCTRL0_WKT_RST_N_SHIFT       (9U)
/*! WKT_RST_N - Self-wake-up timer (WKT) reset control
 *  0b0..Assert the WKT reset.
 *  0b1..Clear the WKT reset.
 */
#define SYSCON_PRESETCTRL0_WKT_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_WKT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_WKT_RST_N_MASK)

#define SYSCON_PRESETCTRL0_MRT_RST_N_MASK        (0x400U)
#define SYSCON_PRESETCTRL0_MRT_RST_N_SHIFT       (10U)
/*! MRT_RST_N - Multi-rate timer (MRT) reset control
 *  0b0..Assert the MRT reset.
 *  0b1..Clear the MRT reset.
 */
#define SYSCON_PRESETCTRL0_MRT_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_MRT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_MRT_RST_N_MASK)

#define SYSCON_PRESETCTRL0_SPI0_RST_N_MASK       (0x800U)
#define SYSCON_PRESETCTRL0_SPI0_RST_N_SHIFT      (11U)
/*! SPI0_RST_N - SPI0 reset control
 *  0b0..Assert the SPI0 reset.
 *  0b1..Clear the SPI0 reset.
 */
#define SYSCON_PRESETCTRL0_SPI0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SPI0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_SPI0_RST_N_MASK)

#define SYSCON_PRESETCTRL0_SPI1_RST_N_MASK       (0x1000U)
#define SYSCON_PRESETCTRL0_SPI1_RST_N_SHIFT      (12U)
/*! SPI1_RST_N - SPI1 reset control
 *  0b0..Assert the SPI1 reset.
 *  0b1..Clear the SPI1 reset.
 */
#define SYSCON_PRESETCTRL0_SPI1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SPI1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_SPI1_RST_N_MASK)

#define SYSCON_PRESETCTRL0_CRC_RST_N_MASK        (0x2000U)
#define SYSCON_PRESETCTRL0_CRC_RST_N_SHIFT       (13U)
/*! CRC_RST_N - CRC engine reset control
 *  0b0..Assert the CRC reset.
 *  0b1..Clear the CRC reset.
 */
#define SYSCON_PRESETCTRL0_CRC_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CRC_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_CRC_RST_N_MASK)

#define SYSCON_PRESETCTRL0_UART0_RST_N_MASK      (0x4000U)
#define SYSCON_PRESETCTRL0_UART0_RST_N_SHIFT     (14U)
/*! UART0_RST_N - UART0 reset control
 *  0b0..Assert the UART0 reset.
 *  0b1..Clear the UART0 reset.
 */
#define SYSCON_PRESETCTRL0_UART0_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART0_RST_N_MASK)

#define SYSCON_PRESETCTRL0_UART1_RST_N_MASK      (0x8000U)
#define SYSCON_PRESETCTRL0_UART1_RST_N_SHIFT     (15U)
/*! UART1_RST_N - UART1 reset control
 *  0b0..Assert the UART1 reset.
 *  0b1..Clear the UART1 reset.
 */
#define SYSCON_PRESETCTRL0_UART1_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART1_RST_N_MASK)

#define SYSCON_PRESETCTRL0_UART2_RST_N_MASK      (0x10000U)
#define SYSCON_PRESETCTRL0_UART2_RST_N_SHIFT     (16U)
/*! UART2_RST_N - UART2 reset control
 *  0b0..Assert the UART2 reset.
 *  0b1..Clear the UART2 reset.
 */
#define SYSCON_PRESETCTRL0_UART2_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART2_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART2_RST_N_MASK)

#define SYSCON_PRESETCTRL0_IOCON_RST_N_MASK      (0x40000U)
#define SYSCON_PRESETCTRL0_IOCON_RST_N_SHIFT     (18U)
/*! IOCON_RST_N - IOCON reset control
 *  0b0..Assert the IOCON reset.
 *  0b1..Clear the IOCON reset.
 */
#define SYSCON_PRESETCTRL0_IOCON_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_IOCON_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_IOCON_RST_N_MASK)

#define SYSCON_PRESETCTRL0_ACMP_RST_N_MASK       (0x80000U)
#define SYSCON_PRESETCTRL0_ACMP_RST_N_SHIFT      (19U)
/*! ACMP_RST_N - Analog comparator reset control
 *  0b0..Assert the analog comparator reset.
 *  0b1..Clear the analog comparator reset.
 */
#define SYSCON_PRESETCTRL0_ACMP_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ACMP_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_ACMP_RST_N_MASK)

#define SYSCON_PRESETCTRL0_GPIO1_RST_N_MASK      (0x100000U)
#define SYSCON_PRESETCTRL0_GPIO1_RST_N_SHIFT     (20U)
/*! GPIO1_RST_N - GPIO1 reset control
 *  0b0..Assert the GPIO1 reset.
 *  0b1..Clear the GPIO1 reset.
 */
#define SYSCON_PRESETCTRL0_GPIO1_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_GPIO1_RST_N_MASK)

#define SYSCON_PRESETCTRL0_I2C1_RST_N_MASK       (0x200000U)
#define SYSCON_PRESETCTRL0_I2C1_RST_N_SHIFT      (21U)
/*! I2C1_RST_N - I2C1 reset control
 *  0b0..Assert the I2C1 reset.
 *  0b1..Clear the I2C1 reset.
 */
#define SYSCON_PRESETCTRL0_I2C1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C1_RST_N_MASK)

#define SYSCON_PRESETCTRL0_I2C2_RST_N_MASK       (0x400000U)
#define SYSCON_PRESETCTRL0_I2C2_RST_N_SHIFT      (22U)
/*! I2C2_RST_N - I2C2 reset control
 *  0b0..Assert the I2C2 reset.
 *  0b1..Clear the I2C2 reset.
 */
#define SYSCON_PRESETCTRL0_I2C2_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C2_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C2_RST_N_MASK)

#define SYSCON_PRESETCTRL0_I2C3_RST_N_MASK       (0x800000U)
#define SYSCON_PRESETCTRL0_I2C3_RST_N_SHIFT      (23U)
/*! I2C3_RST_N - I2C3 reset control
 *  0b0..Assert the I2C3 reset.
 *  0b1..Clear the I2C3 reset.
 */
#define SYSCON_PRESETCTRL0_I2C3_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C3_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C3_RST_N_MASK)

#define SYSCON_PRESETCTRL0_ADC_RST_N_MASK        (0x1000000U)
#define SYSCON_PRESETCTRL0_ADC_RST_N_SHIFT       (24U)
/*! ADC_RST_N - ADC reset control
 *  0b0..Assert the ADC reset.
 *  0b1..Clear the ADC reset.
 */
#define SYSCON_PRESETCTRL0_ADC_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ADC_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_ADC_RST_N_MASK)

#define SYSCON_PRESETCTRL0_CTIMER_RST_N_MASK     (0x2000000U)
#define SYSCON_PRESETCTRL0_CTIMER_RST_N_SHIFT    (25U)
/*! CTIMER_RST_N - CTIMER reset control
 *  0b0..Assert the CTIMER reset.
 *  0b1..Clear the CTIMER reset.
 */
#define SYSCON_PRESETCTRL0_CTIMER_RST_N(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CTIMER_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_CTIMER_RST_N_MASK)

#define SYSCON_PRESETCTRL0_DAC0_RST_N_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL0_DAC0_RST_N_SHIFT      (27U)
/*! DAC0_RST_N - DAC0 reset control
 *  0b0..Assert the DAC0 reset.
 *  0b1..Clear the DAC0 reset.
 */
#define SYSCON_PRESETCTRL0_DAC0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DAC0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_DAC0_RST_N_MASK)

#define SYSCON_PRESETCTRL0_GPIOINT_RST_N_MASK    (0x10000000U)
#define SYSCON_PRESETCTRL0_GPIOINT_RST_N_SHIFT   (28U)
/*! GPIOINT_RST_N - GPIOINT reset control
 *  0b0..Assert the GPIOINT reset.
 *  0b1..Clear the GPIOINT reset.
 */
#define SYSCON_PRESETCTRL0_GPIOINT_RST_N(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIOINT_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_GPIOINT_RST_N_MASK)

#define SYSCON_PRESETCTRL0_DMA_RST_N_MASK        (0x20000000U)
#define SYSCON_PRESETCTRL0_DMA_RST_N_SHIFT       (29U)
/*! DMA_RST_N - DMA reset control
 *  0b0..Assert the DMA reset.
 *  0b1..Clear the DMA reset.
 */
#define SYSCON_PRESETCTRL0_DMA_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DMA_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_DMA_RST_N_MASK)

#define SYSCON_PRESETCTRL0_UART3_RST_N_MASK      (0x40000000U)
#define SYSCON_PRESETCTRL0_UART3_RST_N_SHIFT     (30U)
/*! UART3_RST_N - UART3 reset control
 *  0b0..Assert the UART3 reset.
 *  0b1..Clear the UART3 reset.
 */
#define SYSCON_PRESETCTRL0_UART3_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART3_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART3_RST_N_MASK)

#define SYSCON_PRESETCTRL0_UART4_RST_N_MASK      (0x80000000U)
#define SYSCON_PRESETCTRL0_UART4_RST_N_SHIFT     (31U)
/*! UART4_RST_N - UART4 reset control
 *  0b0..Assert the UART4 reset.
 *  0b1..Clear the UART4 reset.
 */
#define SYSCON_PRESETCTRL0_UART4_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_UART4_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_UART4_RST_N_MASK)
/*! @} */

/*! @name PRESETCTRL1 - Peripheral reset group 1 control register */
/*! @{ */

#define SYSCON_PRESETCTRL1_CAPT_RST_N_MASK       (0x1U)
#define SYSCON_PRESETCTRL1_CAPT_RST_N_SHIFT      (0U)
/*! CAPT_RST_N - Capacitive touch reset control
 *  0b0..Assert the capacitive touch reset.
 *  0b1..Clear the capacitive touch reset.
 */
#define SYSCON_PRESETCTRL1_CAPT_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_CAPT_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_CAPT_RST_N_MASK)

#define SYSCON_PRESETCTRL1_DAC1_RST_N_MASK       (0x2U)
#define SYSCON_PRESETCTRL1_DAC1_RST_N_SHIFT      (1U)
/*! DAC1_RST_N - DAC1 reset control
 *  0b0..Assert the DAC1 reset.
 *  0b1..Clear the DAC1 reset.
 */
#define SYSCON_PRESETCTRL1_DAC1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_DAC1_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_DAC1_RST_N_MASK)

#define SYSCON_PRESETCTRL1_FRG0_RST_N_MASK       (0x8U)
#define SYSCON_PRESETCTRL1_FRG0_RST_N_SHIFT      (3U)
/*! FRG0_RST_N - Fractional baud rate generator 0 reset control
 *  0b0..Assert the FRG0 reset.
 *  0b1..Clear the FRG0 reset.
 */
#define SYSCON_PRESETCTRL1_FRG0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FRG0_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_FRG0_RST_N_MASK)

#define SYSCON_PRESETCTRL1_FRG1_RST_N_MASK       (0x10U)
#define SYSCON_PRESETCTRL1_FRG1_RST_N_SHIFT      (4U)
/*! FRG1_RST_N - Fractional baud rate generator 1 reset control
 *  0b0..Assert the FRG1 reset.
 *  0b1..Clear the FRG1 reset.
 */
#define SYSCON_PRESETCTRL1_FRG1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FRG1_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_FRG1_RST_N_MASK)
/*! @} */

/*! @name FCLKSEL - peripheral clock source select register. FCLK0SEL~FCLK4SEL are for UART0~UART4 clock source select register. FCLK5SEL~FCLK8SEL are for I2C0~I2C3 clock source select register. FCLK9SEL~FCLK10SEL are for SPI0~SPI1 clock source select register. */
/*! @{ */

#define SYSCON_FCLKSEL_SEL_MASK                  (0x7U)
#define SYSCON_FCLKSEL_SEL_SHIFT                 (0U)
/*! SEL - Peripheral clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Frg0clk
 *  0b011..Frg1clk
 *  0b100..FRO_DIV
 *  0b101..none
 *  0b110..none
 *  0b111..none
 */
#define SYSCON_FCLKSEL_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FCLKSEL_SEL_SHIFT)) & SYSCON_FCLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG_FRGDIV - fractional generator N divider value register */
/*! @{ */

#define SYSCON_FRG_FRGDIV_DIV_MASK               (0xFFU)
#define SYSCON_FRG_FRGDIV_DIV_SHIFT              (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define SYSCON_FRG_FRGDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGDIV_DIV_SHIFT)) & SYSCON_FRG_FRGDIV_DIV_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGDIV */
#define SYSCON_FRG_FRGDIV_COUNT                  (2U)

/*! @name FRG_FRGMULT - fractional generator N multiplier value register */
/*! @{ */

#define SYSCON_FRG_FRGMULT_MULT_MASK             (0xFFU)
#define SYSCON_FRG_FRGMULT_MULT_SHIFT            (0U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define SYSCON_FRG_FRGMULT_MULT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGMULT_MULT_SHIFT)) & SYSCON_FRG_FRGMULT_MULT_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGMULT */
#define SYSCON_FRG_FRGMULT_COUNT                 (2U)

/*! @name FRG_FRGCLKSEL - FRG N clock source select register */
/*! @{ */

#define SYSCON_FRG_FRGCLKSEL_SEL_MASK            (0x3U)
#define SYSCON_FRG_FRGCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Clock source for frgN_src clock
 *  0b00..FRO
 *  0b01..main clock
 *  0b10..sys pll
 *  0b11..None
 */
#define SYSCON_FRG_FRGCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGCLKSEL_SEL_SHIFT)) & SYSCON_FRG_FRGCLKSEL_SEL_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGCLKSEL */
#define SYSCON_FRG_FRGCLKSEL_COUNT               (2U)

/*! @name CLKOUTSEL - CLKOUT clock source select register */
/*! @{ */

#define SYSCON_CLKOUTSEL_SEL_MASK                (0x7U)
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)
/*! SEL - CLKOUT clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..sys pll
 *  0b011..external clock
 *  0b100..Watchdog oscillator
 *  0b101..None
 *  0b110..None
 *  0b111..None
 */
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSEL_SEL_SHIFT)) & SYSCON_CLKOUTSEL_SEL_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider registers */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - CLKOUT clock divider values 0: Disable CLKOUT clock divider. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)
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

/*! @name PIOPORCAP - POR captured PIO N status register(PIO0 has 32 PIOs, PIO1 has 22 PIOs) */
/*! @{ */

#define SYSCON_PIOPORCAP_PIOSTAT_MASK            (0xFFFFFFFFU)
#define SYSCON_PIOPORCAP_PIOSTAT_SHIFT           (0U)
/*! PIOSTAT - State of PION_31 through PION_0 at power-on reset */
#define SYSCON_PIOPORCAP_PIOSTAT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORCAP_PIOSTAT_SHIFT)) & SYSCON_PIOPORCAP_PIOSTAT_MASK)
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
/*! INTPIN - Pin number select for pin interrupt or pattern match engine input. (PIO0_0 to
 *    PIO0_31correspond to numbers 0 to 31 and PIO1_0 to PIO1_31 correspond to numbers 32 to 63).
 */
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

/*! @name STARTERP1 - Start logic 0 pin wake-up enable register 1 */
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

#define SYSCON_STARTERP1_Cap_Touch_MASK          (0x800U)
#define SYSCON_STARTERP1_Cap_Touch_SHIFT         (11U)
/*! Cap_Touch - Cap Touch interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_Cap_Touch(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_Cap_Touch_SHIFT)) & SYSCON_STARTERP1_Cap_Touch_MASK)

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

#define SYSCON_STARTERP1_UART3_MASK              (0x40000000U)
#define SYSCON_STARTERP1_UART3_SHIFT             (30U)
/*! UART3 - UART3 interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_UART3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_UART3_SHIFT)) & SYSCON_STARTERP1_UART3_MASK)

#define SYSCON_STARTERP1_UART4_MASK              (0x80000000U)
#define SYSCON_STARTERP1_UART4_SHIFT             (31U)
/*! UART4 - UART4 interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_UART4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_UART4_SHIFT)) & SYSCON_STARTERP1_UART4_MASK)
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

#define SYSCON_PDAWAKECFG_FROOUT_PD_MASK         (0x1U)
#define SYSCON_PDAWAKECFG_FROOUT_PD_SHIFT        (0U)
/*! FROOUT_PD - FRO oscillator output wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_FROOUT_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FROOUT_PD_SHIFT)) & SYSCON_PDAWAKECFG_FROOUT_PD_MASK)

#define SYSCON_PDAWAKECFG_FRO_PD_MASK            (0x2U)
#define SYSCON_PDAWAKECFG_FRO_PD_SHIFT           (1U)
/*! FRO_PD - FRO oscillator power-down wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDAWAKECFG_FRO_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_FRO_PD_SHIFT)) & SYSCON_PDAWAKECFG_FRO_PD_MASK)

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

#define SYSCON_PDAWAKECFG_VREF2_PD_MASK          (0x400U)
#define SYSCON_PDAWAKECFG_VREF2_PD_SHIFT         (10U)
/*! VREF2_PD - VREF2 wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_VREF2_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_VREF2_PD_SHIFT)) & SYSCON_PDAWAKECFG_VREF2_PD_MASK)

#define SYSCON_PDAWAKECFG_DAC0_MASK              (0x2000U)
#define SYSCON_PDAWAKECFG_DAC0_SHIFT             (13U)
/*! DAC0 - DAC0 wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_DAC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_DAC0_SHIFT)) & SYSCON_PDAWAKECFG_DAC0_MASK)

#define SYSCON_PDAWAKECFG_DAC1_MASK              (0x4000U)
#define SYSCON_PDAWAKECFG_DAC1_SHIFT             (14U)
/*! DAC1 - DAC1 wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_DAC1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_DAC1_SHIFT)) & SYSCON_PDAWAKECFG_DAC1_MASK)

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

#define SYSCON_PDRUNCFG_FROOUT_PD_MASK           (0x1U)
#define SYSCON_PDRUNCFG_FROOUT_PD_SHIFT          (0U)
/*! FROOUT_PD - FRO oscillator output wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_FROOUT_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FROOUT_PD_SHIFT)) & SYSCON_PDRUNCFG_FROOUT_PD_MASK)

#define SYSCON_PDRUNCFG_FRO_PD_MASK              (0x2U)
#define SYSCON_PDRUNCFG_FRO_PD_SHIFT             (1U)
/*! FRO_PD - FRO oscillator power-down wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */
#define SYSCON_PDRUNCFG_FRO_PD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_FRO_PD_SHIFT)) & SYSCON_PDRUNCFG_FRO_PD_MASK)

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

#define SYSCON_PDRUNCFG_DAC0_MASK                (0x2000U)
#define SYSCON_PDRUNCFG_DAC0_SHIFT               (13U)
/*! DAC0 - DAC0 wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_DAC0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_DAC0_SHIFT)) & SYSCON_PDRUNCFG_DAC0_MASK)

#define SYSCON_PDRUNCFG_DAC1_MASK                (0x4000U)
#define SYSCON_PDRUNCFG_DAC1_SHIFT               (14U)
/*! DAC1 - DAC1 wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_DAC1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_DAC1_SHIFT)) & SYSCON_PDRUNCFG_DAC1_MASK)

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

