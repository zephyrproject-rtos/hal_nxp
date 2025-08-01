/*
** ###################################################################
**     Processors:          LPC804M101JDH20
**                          LPC804M101JDH24
**                          LPC804M101JHI33
**                          LPC804M111JDH24
**                          LPC804UK
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
**     - rev. 1.0 (2018-01-09)
**         Initial version.
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

#if (defined(CPU_LPC804M101JDH20) || defined(CPU_LPC804M101JDH24) || defined(CPU_LPC804M101JHI33) || defined(CPU_LPC804M111JDH24) || defined(CPU_LPC804UK))
#include "LPC804_COMMON.h"
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
#define SYSCON_FRG_COUNT                          1u
#define SYSCON_PINTSEL_COUNT                      8u

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< System Remap register, offset: 0x0 */
       uint8_t RESERVED_0[52];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register., offset: 0x38 */
       uint8_t RESERVED_1[20];
  __IO uint32_t MAINCLKSEL;                        /**< Main clock source select register, offset: 0x50 */
  __IO uint32_t MAINCLKUEN;                        /**< Main clock source update enable register., offset: 0x54 */
  __IO uint32_t SYSAHBCLKDIV;                      /**< System clock divider register, offset: 0x58 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CAPTCLKSEL;                        /**< Capacitive Touch clock source select., offset: 0x60 */
  __IO uint32_t ADCCLKSEL;                         /**< ADC clock source select register, offset: 0x64 */
  __IO uint32_t ADCCLKDIV;                         /**< ADC clock divider register, offset: 0x68 */
       uint8_t RESERVED_3[16];
  __IO uint32_t LPOSCCLKEN;                        /**< WDT and Wake Timer clock enable control., offset: 0x7C */
  __IO uint32_t SYSAHBCLKCTRL0;                    /**< System clock group 0 control register, offset: 0x80 */
  __IO uint32_t SYSAHBCLKCTRL1;                    /**< System clock group 1 control register, offset: 0x84 */
  __IO uint32_t PRESETCTRL0;                       /**< Peripheral reset group 0 control register, offset: 0x88 */
  __IO uint32_t PRESETCTRL1;                       /**< Peripheral reset group 1 control register, offset: 0x8C */
  __IO uint32_t UART0CLKSEL;                       /**< Function clock source select for UART0., offset: 0x90 */
  __IO uint32_t UART1CLKSEL;                       /**< Function clock source select for UART1., offset: 0x94 */
       uint8_t RESERVED_4[12];
  __IO uint32_t I2C0CLKSEL;                        /**< Function clock source select for I2C0., offset: 0xA4 */
  __IO uint32_t I2C1CLKSEL;                        /**< Function clock source select for I2C1., offset: 0xA8 */
       uint8_t RESERVED_5[8];
  __IO uint32_t SPI0CLKSEL;                        /**< Function clock source select for SPI0., offset: 0xB4 */
       uint8_t RESERVED_6[24];
  struct {                                         /* offset: 0xD0, array step: 0xC */
    __IO uint32_t FRGDIV;                            /**< fractional generator divider value register, array offset: 0xD0, array step: 0xC */
    __IO uint32_t FRGMULT;                           /**< fractional generator multiplier value register, array offset: 0xD4, array step: 0xC */
    __IO uint32_t FRGCLKSEL;                         /**< FRG clock source select register, array offset: 0xD8, array step: 0xC */
  } FRG[SYSCON_FRG_COUNT];
       uint8_t RESERVED_7[20];
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT clock source select register, offset: 0xF0 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider registers, offset: 0xF4 */
       uint8_t RESERVED_8[8];
  __IO uint32_t PIOPORACP;                         /**< POR captured PIO0 status 0, offset: 0x100 */
       uint8_t RESERVED_9[76];
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
  __I  uint32_t DEVICE_ID;                         /**< Device ID register, offset: 0x3F8 */
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
/*! MAP - System memory remap. Value 0x2 is reserved.
 *  0b00..Boot Loader Mode. Interrupt vectors are re-mapped to Boot ROM.
 *  0b01..User RAM Mode. Interrupt vectors are re-mapped to Static RAM.
 *  0b10..User Flash Mode. Interrupt vectors are not re-mapped and reside in Flash.
 */
#define SYSCON_SYSMEMREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSMEMREMAP_MAP_SHIFT)) & SYSCON_SYSMEMREMAP_MAP_MASK)
/*! @} */

/*! @name SYSRSTSTAT - System reset status register. */
/*! @{ */

#define SYSCON_SYSRSTSTAT_POR_BOD_MASK           (0x1U)
#define SYSCON_SYSRSTSTAT_POR_BOD_SHIFT          (0U)
/*! POR_BOD - POR and BOD reset status
 *  0b0..No POR detected
 *  0b1..POR and BOD detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_POR_BOD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_POR_BOD_SHIFT)) & SYSCON_SYSRSTSTAT_POR_BOD_MASK)

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

#define SYSCON_SYSRSTSTAT_SYSRST_MASK            (0x10U)
#define SYSCON_SYSRSTSTAT_SYSRST_SHIFT           (4U)
/*! SYSRST - Status of the software system reset
 *  0b0..No System reset detected
 *  0b1..System reset detected. Writing a one clears this reset.
 */
#define SYSCON_SYSRSTSTAT_SYSRST(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSRSTSTAT_SYSRST_SHIFT)) & SYSCON_SYSRSTSTAT_SYSRST_MASK)
/*! @} */

/*! @name MAINCLKSEL - Main clock source select register */
/*! @{ */

#define SYSCON_MAINCLKSEL_SEL_MASK               (0x3U)
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Clock source for main clock.
 *  0b00..FRO.
 *  0b01..External clock.
 *  0b10..Low power oscillator.
 *  0b11..FRO_DIV.
 */
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSEL_SEL_SHIFT)) & SYSCON_MAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKUEN - Main clock source update enable register. */
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

/*! @name CAPTCLKSEL - Capacitive Touch clock source select. */
/*! @{ */

#define SYSCON_CAPTCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_CAPTCLKSEL_SEL_SHIFT              (0U)
/*! SEL - Peripheral clock source.
 *  0b000..FRO
 *  0b001..Main clock
 *  0b010..Reserved
 *  0b011..FRO_DIV = FRO/2
 *  0b100..Low power oscillator
 *  0b101..Reserved
 *  0b110..Reserved
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
 *  0b01..External clock
 *  0b10..Reserved
 *  0b11..None
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

/*! @name LPOSCCLKEN - WDT and Wake Timer clock enable control. */
/*! @{ */

#define SYSCON_LPOSCCLKEN_WDT_MASK               (0x1U)
#define SYSCON_LPOSCCLKEN_WDT_SHIFT              (0U)
/*! WDT - Enables clock for WDT
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_LPOSCCLKEN_WDT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_LPOSCCLKEN_WDT_SHIFT)) & SYSCON_LPOSCCLKEN_WDT_MASK)

#define SYSCON_LPOSCCLKEN_WKT_MASK               (0x2U)
#define SYSCON_LPOSCCLKEN_WKT_SHIFT              (1U)
/*! WKT - Enables clock for Wake Timer
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_LPOSCCLKEN_WKT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_LPOSCCLKEN_WKT_SHIFT)) & SYSCON_LPOSCCLKEN_WKT_MASK)
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

#define SYSCON_SYSAHBCLKCTRL0_RAM0_MASK          (0x4U)
#define SYSCON_SYSAHBCLKCTRL0_RAM0_SHIFT         (2U)
/*! RAM0 - Enables clock for SRAM0
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_RAM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_RAM0_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_RAM0_MASK)

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

#define SYSCON_SYSAHBCLKCTRL0_I2C1_MASK          (0x200000U)
#define SYSCON_SYSAHBCLKCTRL0_I2C1_SHIFT         (21U)
/*! I2C1 - Enables clock for I2C1.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_I2C1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_I2C1_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_I2C1_MASK)

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

#define SYSCON_SYSAHBCLKCTRL0_DAC_MASK           (0x8000000U)
#define SYSCON_SYSAHBCLKCTRL0_DAC_SHIFT          (27U)
/*! DAC - Enables clock for DAC.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_DAC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_DAC_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_DAC_MASK)

#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK      (0x10000000U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT_SHIFT     (28U)
/*! GPIO_INT - Enable clock for GPIO pin interrupt registers
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL0_GPIO_INT(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL0_GPIO_INT_SHIFT)) & SYSCON_SYSAHBCLKCTRL0_GPIO_INT_MASK)
/*! @} */

/*! @name SYSAHBCLKCTRL1 - System clock group 1 control register */
/*! @{ */

#define SYSCON_SYSAHBCLKCTRL1_CAPT_MASK          (0x1U)
#define SYSCON_SYSAHBCLKCTRL1_CAPT_SHIFT         (0U)
/*! CAPT - Enables the clock for Capacitive Touch. */
#define SYSCON_SYSAHBCLKCTRL1_CAPT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL1_CAPT_SHIFT)) & SYSCON_SYSAHBCLKCTRL1_CAPT_MASK)

#define SYSCON_SYSAHBCLKCTRL1_PLU_MASK           (0x20U)
#define SYSCON_SYSAHBCLKCTRL1_PLU_SHIFT          (5U)
/*! PLU - Enables clock for PLU.
 *  0b0..disable
 *  0b1..enable
 */
#define SYSCON_SYSAHBCLKCTRL1_PLU(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKCTRL1_PLU_SHIFT)) & SYSCON_SYSAHBCLKCTRL1_PLU_MASK)
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

#define SYSCON_PRESETCTRL0_I2C1_RST_N_MASK       (0x200000U)
#define SYSCON_PRESETCTRL0_I2C1_RST_N_SHIFT      (21U)
/*! I2C1_RST_N - I2C1 reset control.
 *  0b0..Assert the I2C1 reset.
 *  0b1..Clear the I2C1 reset.
 */
#define SYSCON_PRESETCTRL0_I2C1_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_I2C1_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_I2C1_RST_N_MASK)

#define SYSCON_PRESETCTRL0_ADC_RST_N_MASK        (0x1000000U)
#define SYSCON_PRESETCTRL0_ADC_RST_N_SHIFT       (24U)
/*! ADC_RST_N - ADC reset control
 *  0b0..Assert the ADC reset.
 *  0b1..Clear the ADC reset.
 */
#define SYSCON_PRESETCTRL0_ADC_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ADC_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_ADC_RST_N_MASK)

#define SYSCON_PRESETCTRL0_CTIMER0_RST_N_MASK    (0x2000000U)
#define SYSCON_PRESETCTRL0_CTIMER0_RST_N_SHIFT   (25U)
/*! CTIMER0_RST_N - CTIMER reset control
 *  0b0..Assert the CTIMER reset.
 *  0b1..Clear the CTIMER reset.
 */
#define SYSCON_PRESETCTRL0_CTIMER0_RST_N(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CTIMER0_RST_N_SHIFT)) & SYSCON_PRESETCTRL0_CTIMER0_RST_N_MASK)

#define SYSCON_PRESETCTRL0_DAC0_RST_N_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL0_DAC0_RST_N_SHIFT      (27U)
/*! DAC0_RST_N - DAC0 reset control.
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
/*! @} */

/*! @name PRESETCTRL1 - Peripheral reset group 1 control register */
/*! @{ */

#define SYSCON_PRESETCTRL1_CAPT_RST_N_MASK       (0x1U)
#define SYSCON_PRESETCTRL1_CAPT_RST_N_SHIFT      (0U)
/*! CAPT_RST_N - Capacitive Touch reset control.
 *  0b0..Assert Capacitive Touch reset.
 *  0b1..Clear Capacitive Touch reset.
 */
#define SYSCON_PRESETCTRL1_CAPT_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_CAPT_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_CAPT_RST_N_MASK)

#define SYSCON_PRESETCTRL1_FRG0_RST_N_MASK       (0x8U)
#define SYSCON_PRESETCTRL1_FRG0_RST_N_SHIFT      (3U)
/*! FRG0_RST_N - Fractional baud rate generator 0 reset control
 *  0b0..Assert the FRG0 reset.
 *  0b1..Clear the FRG0 reset.
 */
#define SYSCON_PRESETCTRL1_FRG0_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FRG0_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_FRG0_RST_N_MASK)

#define SYSCON_PRESETCTRL1_PLU_RST_N_MASK        (0x20U)
#define SYSCON_PRESETCTRL1_PLU_RST_N_SHIFT       (5U)
/*! PLU_RST_N - PLU reset control.
 *  0b0..Assert PLU reset.
 *  0b1..Clear PLU reset.
 */
#define SYSCON_PRESETCTRL1_PLU_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_PLU_RST_N_SHIFT)) & SYSCON_PRESETCTRL1_PLU_RST_N_MASK)
/*! @} */

/*! @name UART0CLKSEL - Function clock source select for UART0. */
/*! @{ */

#define SYSCON_UART0CLKSEL_SEL_MASK              (0x7U)
#define SYSCON_UART0CLKSEL_SEL_SHIFT             (0U)
/*! SEL - Peripheral clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Frg0clk
 *  0b011..none
 *  0b100..FRO_DIV
 *  0b101..none
 *  0b110..none
 *  0b111..none
 */
#define SYSCON_UART0CLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_UART0CLKSEL_SEL_SHIFT)) & SYSCON_UART0CLKSEL_SEL_MASK)
/*! @} */

/*! @name UART1CLKSEL - Function clock source select for UART1. */
/*! @{ */

#define SYSCON_UART1CLKSEL_SEL_MASK              (0x7U)
#define SYSCON_UART1CLKSEL_SEL_SHIFT             (0U)
/*! SEL - Peripheral clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Frg0clk
 *  0b011..none
 *  0b100..FRO_DIV
 *  0b101..none
 *  0b110..none
 *  0b111..none
 */
#define SYSCON_UART1CLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_UART1CLKSEL_SEL_SHIFT)) & SYSCON_UART1CLKSEL_SEL_MASK)
/*! @} */

/*! @name I2C0CLKSEL - Function clock source select for I2C0. */
/*! @{ */

#define SYSCON_I2C0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_I2C0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Peripheral clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Frg0clk
 *  0b011..none
 *  0b100..FRO_DIV
 *  0b101..none
 *  0b110..none
 *  0b111..none
 */
#define SYSCON_I2C0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_I2C0CLKSEL_SEL_SHIFT)) & SYSCON_I2C0CLKSEL_SEL_MASK)
/*! @} */

/*! @name I2C1CLKSEL - Function clock source select for I2C1. */
/*! @{ */

#define SYSCON_I2C1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_I2C1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Peripheral clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Frg0clk
 *  0b011..none
 *  0b100..FRO_DIV
 *  0b101..none
 *  0b110..none
 *  0b111..none
 */
#define SYSCON_I2C1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_I2C1CLKSEL_SEL_SHIFT)) & SYSCON_I2C1CLKSEL_SEL_MASK)
/*! @} */

/*! @name SPI0CLKSEL - Function clock source select for SPI0. */
/*! @{ */

#define SYSCON_SPI0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_SPI0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - Peripheral clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Frg0clk
 *  0b011..none
 *  0b100..FRO_DIV
 *  0b101..none
 *  0b110..none
 *  0b111..none
 */
#define SYSCON_SPI0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SPI0CLKSEL_SEL_SHIFT)) & SYSCON_SPI0CLKSEL_SEL_MASK)
/*! @} */

/*! @name FRG_FRGDIV - fractional generator divider value register */
/*! @{ */

#define SYSCON_FRG_FRGDIV_DIV_MASK               (0xFFU)
#define SYSCON_FRG_FRGDIV_DIV_SHIFT              (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define SYSCON_FRG_FRGDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGDIV_DIV_SHIFT)) & SYSCON_FRG_FRGDIV_DIV_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGDIV */
#define SYSCON_FRG_FRGDIV_COUNT                  (1U)

/*! @name FRG_FRGMULT - fractional generator multiplier value register */
/*! @{ */

#define SYSCON_FRG_FRGMULT_MULT_MASK             (0xFFU)
#define SYSCON_FRG_FRGMULT_MULT_SHIFT            (0U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define SYSCON_FRG_FRGMULT_MULT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGMULT_MULT_SHIFT)) & SYSCON_FRG_FRGMULT_MULT_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGMULT */
#define SYSCON_FRG_FRGMULT_COUNT                 (1U)

/*! @name FRG_FRGCLKSEL - FRG clock source select register */
/*! @{ */

#define SYSCON_FRG_FRGCLKSEL_SEL_MASK            (0x3U)
#define SYSCON_FRG_FRGCLKSEL_SEL_SHIFT           (0U)
/*! SEL - Clock source for frgN_src clock
 *  0b00..FRO
 *  0b01..main clock
 *  0b10..Reserved
 *  0b11..None
 */
#define SYSCON_FRG_FRGCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FRG_FRGCLKSEL_SEL_SHIFT)) & SYSCON_FRG_FRGCLKSEL_SEL_MASK)
/*! @} */

/* The count of SYSCON_FRG_FRGCLKSEL */
#define SYSCON_FRG_FRGCLKSEL_COUNT               (1U)

/*! @name CLKOUTSEL - CLKOUT clock source select register */
/*! @{ */

#define SYSCON_CLKOUTSEL_SEL_MASK                (0x7U)
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)
/*! SEL - CLKOUT clock source
 *  0b000..FRO
 *  0b001..main clock
 *  0b010..Reserved
 *  0b011..external clock
 *  0b100..Low power oscillator
 *  0b101..Reserved
 *  0b110..Reserved
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

/*! @name PIOPORACP - POR captured PIO0 status 0 */
/*! @{ */

#define SYSCON_PIOPORACP_PIOSTAT_MASK            (0xFFFFFFFFU)
#define SYSCON_PIOPORACP_PIOSTAT_SHIFT           (0U)
/*! PIOSTAT - State of PIO0_0 to PIO0_5 and PIO0_7 to PIO0_17 at power-on reset */
#define SYSCON_PIOPORACP_PIOSTAT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORACP_PIOSTAT_SHIFT)) & SYSCON_PIOPORACP_PIOSTAT_MASK)
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
/*! INTPIN - Pin number select for pin interrupt or pattern match engine input. (PIO0_0 to PIO0_5
 *    correspond to numbers 0 to 5. PIO0_7 to PIO0_30 correspond to numbers 7 to 30.)
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

#define SYSCON_STARTERP1_PLU_MASK                (0x40U)
#define SYSCON_STARTERP1_PLU_SHIFT               (6U)
/*! PLU - PLU interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_PLU(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_PLU_SHIFT)) & SYSCON_STARTERP1_PLU_MASK)

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

#define SYSCON_STARTERP1_CAPT_MASK               (0x800U)
#define SYSCON_STARTERP1_CAPT_SHIFT              (11U)
/*! CAPT - CAPT interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_STARTERP1_CAPT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERP1_CAPT_SHIFT)) & SYSCON_STARTERP1_CAPT_MASK)

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

#define SYSCON_PDSLEEPCFG_LPOSC_PD_MASK          (0x40U)
#define SYSCON_PDSLEEPCFG_LPOSC_PD_SHIFT         (6U)
/*! LPOSC_PD - Low power oscillator power-down control for deep-sleep and power-down mode. Changing
 *    this bit to powered-down has no effect when the LOCK bit in the WWDT MOD register is set. In
 *    this case, the low power oscillator is always running.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDSLEEPCFG_LPOSC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_LPOSC_PD_SHIFT)) & SYSCON_PDSLEEPCFG_LPOSC_PD_MASK)
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

#define SYSCON_PDAWAKECFG_LPOSC_PD_MASK          (0x40U)
#define SYSCON_PDAWAKECFG_LPOSC_PD_SHIFT         (6U)
/*! LPOSC_PD - Low power oscillator wake-up configuration. Changing this bit to powered-down has no
 *    effect when the LOCK bit in the WWDT MOD register is set. In this case, the low power
 *    oscillator is always running.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_LPOSC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_LPOSC_PD_SHIFT)) & SYSCON_PDAWAKECFG_LPOSC_PD_MASK)

#define SYSCON_PDAWAKECFG_DAC_MASK               (0x2000U)
#define SYSCON_PDAWAKECFG_DAC_SHIFT              (13U)
/*! DAC - DAC0 wake-up configuration.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDAWAKECFG_DAC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PDAWAKECFG_DAC_SHIFT)) & SYSCON_PDAWAKECFG_DAC_MASK)

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

#define SYSCON_PDRUNCFG_LPOSC_PD_MASK            (0x40U)
#define SYSCON_PDRUNCFG_LPOSC_PD_SHIFT           (6U)
/*! LPOSC_PD - Low power oscillator power down. Changing this bit to powered-down has no effect when
 *    the LOCK bit in the WWDT MOD register is set. In this case, the low power oscillator is
 *    always running.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_LPOSC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_LPOSC_PD_SHIFT)) & SYSCON_PDRUNCFG_LPOSC_PD_MASK)

#define SYSCON_PDRUNCFG_DAC0_MASK                (0x2000U)
#define SYSCON_PDRUNCFG_DAC0_SHIFT               (13U)
/*! DAC0 - DAC0 wake-up configuration.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_DAC0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_DAC0_SHIFT)) & SYSCON_PDRUNCFG_DAC0_MASK)

#define SYSCON_PDRUNCFG_ACMP_MASK                (0x8000U)
#define SYSCON_PDRUNCFG_ACMP_SHIFT               (15U)
/*! ACMP - Analog comparator wake-up configuration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_PDRUNCFG_ACMP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_ACMP_SHIFT)) & SYSCON_PDRUNCFG_ACMP_MASK)
/*! @} */

/*! @name DEVICE_ID - Device ID register */
/*! @{ */

#define SYSCON_DEVICE_ID_DEVICEID_MASK           (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_DEVICEID_SHIFT          (0U)
/*! DEVICEID - Used to read the part identification number. */
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

