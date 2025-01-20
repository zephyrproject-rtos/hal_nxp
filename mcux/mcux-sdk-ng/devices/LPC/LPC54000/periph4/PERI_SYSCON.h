/*
** ###################################################################
**     Processors:          LPC54101J256BD64
**                          LPC54101J256UK49
**                          LPC54101J512BD64
**                          LPC54101J512UK49
**                          LPC54102J256BD64_cm0plus
**                          LPC54102J256BD64_cm4
**                          LPC54102J256UK49_cm0plus
**                          LPC54102J256UK49_cm4
**                          LPC54102J512BD64_cm0plus
**                          LPC54102J512BD64_cm4
**                          LPC54102J512UK49_cm0plus
**                          LPC54102J512UK49_cm4
**
**     Version:             rev. 1.0, 2016-04-29
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-29)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file SYSCON.h
 * @version 1.0
 * @date 2016-04-29
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(SYSCON_H_)
#define SYSCON_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54101J256BD64) || defined(CPU_LPC54101J256UK49) || defined(CPU_LPC54101J512BD64) || defined(CPU_LPC54101J512UK49))
#include "LPC54101_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm0plus) || defined(CPU_LPC54102J256UK49_cm0plus) || defined(CPU_LPC54102J512BD64_cm0plus) || defined(CPU_LPC54102J512UK49_cm0plus))
#include "LPC54102_cm0plus_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm4) || defined(CPU_LPC54102J256UK49_cm4) || defined(CPU_LPC54102J512BD64_cm4) || defined(CPU_LPC54102J512UK49_cm4))
#include "LPC54102_cm4_COMMON.h"
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
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
#define SYSCON_PRESETCTRL_COUNT                   2u
#define SYSCON_PRESETCTRLSET_COUNT                2u
#define SYSCON_PRESETCTRLCLR_COUNT                2u
#define SYSCON_AHBCLKCTRL_COUNT                   2u
#define SYSCON_AHBCLKCTRLSET_COUNT                2u
#define SYSCON_AHBCLKCTRLCLR_COUNT                2u
#define SYSCON_STARTER_COUNT                      2u
#define SYSCON_STARTERSET_COUNT                   2u
#define SYSCON_STARTERCLR_COUNT                   2u
#define SYSCON_DEVICE_ID_COUNT                    2u

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< System memory remap, offset: 0x0 */
  __IO uint32_t AHBMATPRIO;                        /**< AHB multilayer matrix priority control, offset: 0x4 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SYSTCKCAL;                         /**< System tick counter calibration, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x1C */
  __IO uint32_t ASYNCAPBCTRL;                      /**< Asynchronous APB Control, offset: 0x20 */
       uint8_t RESERVED_2[28];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register, offset: 0x40 */
  __IO uint32_t PRESETCTRL[SYSCON_PRESETCTRL_COUNT]; /**< Peripheral reset control n, array offset: 0x44, array step: 0x4 */
  __IO uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Set bits in PRESETCTRL n, array offset: 0x4C, array step: 0x4 */
  __IO uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Clear bits in PRESETCTRL n, array offset: 0x54, array step: 0x4 */
  __IO uint32_t PIOPORCAP0;                        /**< POR captured PIO status 0, offset: 0x5C */
  __IO uint32_t PIOPORCAP1;                        /**< POR captured PIO status 1, offset: 0x60 */
       uint8_t RESERVED_3[4];
  __IO uint32_t PIORESCAP0;                        /**< Reset captured PIO status 0, offset: 0x68 */
  __IO uint32_t PIORESCAP1;                        /**< Reset captured PIO status 1, offset: 0x6C */
       uint8_t RESERVED_4[16];
  __IO uint32_t MAINCLKSELA;                       /**< Main clock source select A, offset: 0x80 */
  __IO uint32_t MAINCLKSELB;                       /**< Main clock source select B, offset: 0x84 */
       uint8_t RESERVED_5[4];
  __IO uint32_t ADCCLKSEL;                         /**< ADC clock source select, offset: 0x8C */
       uint8_t RESERVED_6[4];
  __IO uint32_t CLKOUTSELA;                        /**< CLKOUT clock source select A, offset: 0x94 */
  __IO uint32_t CLKOUTSELB;                        /**< CLKOUT clock source select B, offset: 0x98 */
       uint8_t RESERVED_7[4];
  __IO uint32_t SYSPLLCLKSEL;                      /**< PLL clock source select, offset: 0xA0 */
       uint8_t RESERVED_8[28];
  __IO uint32_t AHBCLKCTRL[SYSCON_AHBCLKCTRL_COUNT]; /**< AHB Clock control n, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< Set bits in AHBCLKCTRL n, array offset: 0xC8, array step: 0x4 */
  __IO uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< Clear bits in AHBCLKCTRL n, array offset: 0xD0, array step: 0x4 */
       uint8_t RESERVED_9[8];
  __IO uint32_t SYSTICKCLKDIV;                     /**< SYSTICK clock divider, offset: 0xE0 */
  __IO uint32_t TRACECLKDIV;                       /**< TRACE clock divider, offset: 0xE4 */
       uint8_t RESERVED_10[24];
  __IO uint32_t AHBCLKDIV;                         /**< System clock divider, offset: 0x100 */
       uint8_t RESERVED_11[4];
  __IO uint32_t ADCCLKDIV;                         /**< ADC clock divider, offset: 0x108 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider, offset: 0x10C */
       uint8_t RESERVED_12[16];
  __IO uint32_t FREQMECTRL;                        /**< Frequency measure register, offset: 0x120 */
  __IO uint32_t FLASHCFG;                          /**< Flash wait states configuration, offset: 0x124 */
       uint8_t RESERVED_13[32];
  __IO uint32_t FIFOCTRL;                          /**< Serial interface FIFO enables, offset: 0x148 */
       uint8_t RESERVED_14[56];
  __IO uint32_t IRCCTRL;                           /**< IRC oscillator control, offset: 0x184 */
       uint8_t RESERVED_15[8];
  __IO uint32_t RTCOSCCTRL;                        /**< RTC oscillator 32 kHz output control, offset: 0x190 */
       uint8_t RESERVED_16[28];
  __IO uint32_t SYSPLLCTRL;                        /**< PLL control, offset: 0x1B0 */
  __IO uint32_t SYSPLLSTAT;                        /**< PLL status, offset: 0x1B4 */
  __IO uint32_t SYSPLLNDEC;                        /**< PLL N decoder, offset: 0x1B8 */
  __IO uint32_t SYSPLLPDEC;                        /**< PLL P decoder, offset: 0x1BC */
  __IO uint32_t SYSPLLSSCTRL0;                     /**< PLL spread spectrum control 0, offset: 0x1C0 */
  __IO uint32_t SYSPLLSSCTRL1;                     /**< PLL spread spectrum control 1, offset: 0x1C4 */
       uint8_t RESERVED_17[72];
  __IO uint32_t PDRUNCFG;                          /**< Power configuration register, offset: 0x210 */
  __IO uint32_t PDRUNCFGSET;                       /**< Set bits in PDRUNCFG, offset: 0x214 */
  __IO uint32_t PDRUNCFGCLR;                       /**< Clear bits in PDRUNCFG, offset: 0x218 */
       uint8_t RESERVED_18[36];
  __IO uint32_t STARTER[SYSCON_STARTER_COUNT];     /**< Start logic n wake-up enable register, array offset: 0x240, array step: 0x4 */
  __IO uint32_t STARTERSET[SYSCON_STARTERSET_COUNT]; /**< Set bits in STARTERP n, array offset: 0x248, array step: 0x4 */
  __IO uint32_t STARTERCLR[SYSCON_STARTERCLR_COUNT]; /**< Clear bits in STARTER n, array offset: 0x250, array step: 0x4 */
       uint8_t RESERVED_19[168];
  __IO uint32_t CPUCTRL;                           /**< CPU Control for multiple processors, offset: 0x300 */
  __IO uint32_t CPBOOT;                            /**< Coprocessor Boot Address, offset: 0x304 */
  __IO uint32_t CPSTACK;                           /**< Coprocessor Stack Address, offset: 0x308 */
  __IO uint32_t CPSTAT;                            /**< Coprocessor Status, offset: 0x30C */
       uint8_t RESERVED_20[228];
  __IO uint32_t JTAGIDCODE;                        /**< JTAG ID code register, offset: 0x3F4 */
  __IO uint32_t DEVICE_ID[SYSCON_DEVICE_ID_COUNT]; /**< Part ID register, array offset: 0x3F8, array step: 0x4 */
       uint8_t RESERVED_21[179268];
  __IO uint32_t BODCTRL;                           /**< Brown-Out Detect control, offset: 0x2C044 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name SYSMEMREMAP - System memory remap */
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

/*! @name AHBMATPRIO - AHB multilayer matrix priority control */
/*! @{ */

#define SYSCON_AHBMATPRIO_PRI_ICODE_MASK         (0x3U)
#define SYSCON_AHBMATPRIO_PRI_ICODE_SHIFT        (0U)
/*! PRI_ICODE - I-Code bus priority. Should be lower than PRI_DCODE for proper operation. */
#define SYSCON_AHBMATPRIO_PRI_ICODE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_ICODE_SHIFT)) & SYSCON_AHBMATPRIO_PRI_ICODE_MASK)

#define SYSCON_AHBMATPRIO_PRI_DCODE_MASK         (0xCU)
#define SYSCON_AHBMATPRIO_PRI_DCODE_SHIFT        (2U)
/*! PRI_DCODE - D-Code bus priority. */
#define SYSCON_AHBMATPRIO_PRI_DCODE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_DCODE_SHIFT)) & SYSCON_AHBMATPRIO_PRI_DCODE_MASK)

#define SYSCON_AHBMATPRIO_PRI_SYS_MASK           (0x30U)
#define SYSCON_AHBMATPRIO_PRI_SYS_SHIFT          (4U)
/*! PRI_SYS - System bus priority. */
#define SYSCON_AHBMATPRIO_PRI_SYS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SYS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SYS_MASK)

#define SYSCON_AHBMATPRIO_PRI_DMA_MASK           (0x300U)
#define SYSCON_AHBMATPRIO_PRI_DMA_SHIFT          (8U)
/*! PRI_DMA - DMA controller priority. */
#define SYSCON_AHBMATPRIO_PRI_DMA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_DMA_SHIFT)) & SYSCON_AHBMATPRIO_PRI_DMA_MASK)

#define SYSCON_AHBMATPRIO_PRI_FIFO_MASK          (0xC000U)
#define SYSCON_AHBMATPRIO_PRI_FIFO_SHIFT         (14U)
/*! PRI_FIFO - System FIFO bus priority */
#define SYSCON_AHBMATPRIO_PRI_FIFO(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_FIFO_SHIFT)) & SYSCON_AHBMATPRIO_PRI_FIFO_MASK)

#define SYSCON_AHBMATPRIO_PRI_M0_MASK            (0x30000U)
#define SYSCON_AHBMATPRIO_PRI_M0_SHIFT           (16U)
/*! PRI_M0 - Cortex-M0+ bus priority. */
#define SYSCON_AHBMATPRIO_PRI_M0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_M0_SHIFT)) & SYSCON_AHBMATPRIO_PRI_M0_MASK)
/*! @} */

/*! @name SYSTCKCAL - System tick counter calibration */
/*! @{ */

#define SYSCON_SYSTCKCAL_CAL_MASK                (0xFFFFFFU)
#define SYSCON_SYSTCKCAL_CAL_SHIFT               (0U)
/*! CAL - System tick timer calibration value. */
#define SYSCON_SYSTCKCAL_CAL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTCKCAL_CAL_SHIFT)) & SYSCON_SYSTCKCAL_CAL_MASK)

#define SYSCON_SYSTCKCAL_SKEW_MASK               (0x1000000U)
#define SYSCON_SYSTCKCAL_SKEW_SHIFT              (24U)
/*! SKEW - Initial value for the Systick timer. */
#define SYSCON_SYSTCKCAL_SKEW(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTCKCAL_SKEW_SHIFT)) & SYSCON_SYSTCKCAL_SKEW_MASK)

#define SYSCON_SYSTCKCAL_NOREF_MASK              (0x2000000U)
#define SYSCON_SYSTCKCAL_NOREF_SHIFT             (25U)
/*! NOREF - Initial value for the Systick timer. */
#define SYSCON_SYSTCKCAL_NOREF(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTCKCAL_NOREF_SHIFT)) & SYSCON_SYSTCKCAL_NOREF_MASK)
/*! @} */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON_NMISRC_IRQM4_MASK                 (0x3FU)
#define SYSCON_NMISRC_IRQM4_SHIFT                (0U)
/*! IRQM4 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for the Cortex-M4, if enabled by NMIENM4. */
#define SYSCON_NMISRC_IRQM4(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQM4_SHIFT)) & SYSCON_NMISRC_IRQM4_MASK)

#define SYSCON_NMISRC_IRQM0_MASK                 (0x3F00U)
#define SYSCON_NMISRC_IRQM0_SHIFT                (8U)
/*! IRQM0 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for the Cortex-M0+, if enabled by NMIENM0. */
#define SYSCON_NMISRC_IRQM0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQM0_SHIFT)) & SYSCON_NMISRC_IRQM0_MASK)

#define SYSCON_NMISRC_NMIENM0_MASK               (0x40000000U)
#define SYSCON_NMISRC_NMIENM0_SHIFT              (30U)
/*! NMIENM0 - Write a 1 to this bit to enable the Non-Maskable Interrupt (NMI) source selected by IRQM0. */
#define SYSCON_NMISRC_NMIENM0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENM0_SHIFT)) & SYSCON_NMISRC_NMIENM0_MASK)

#define SYSCON_NMISRC_NMIENM4_MASK               (0x80000000U)
#define SYSCON_NMISRC_NMIENM4_SHIFT              (31U)
/*! NMIENM4 - Write a 1 to this bit to enable the Non-Maskable Interrupt (NMI) source selected by IRQM4. */
#define SYSCON_NMISRC_NMIENM4(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENM4_SHIFT)) & SYSCON_NMISRC_NMIENM4_MASK)
/*! @} */

/*! @name ASYNCAPBCTRL - Asynchronous APB Control */
/*! @{ */

#define SYSCON_ASYNCAPBCTRL_ENABLE_MASK          (0x1U)
#define SYSCON_ASYNCAPBCTRL_ENABLE_SHIFT         (0U)
/*! ENABLE - Enables the asynchronous APB bridge and subsystem.
 *  0b0..Disabled. Asynchronous APB bridge is disabled.
 *  0b1..Enabled. Asynchronous APB bridge is enabled.
 */
#define SYSCON_ASYNCAPBCTRL_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ASYNCAPBCTRL_ENABLE_SHIFT)) & SYSCON_ASYNCAPBCTRL_ENABLE_MASK)
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

/*! @name PRESETCTRL - Peripheral reset control n */
/*! @{ */

#define SYSCON_PRESETCTRL_MRT_RST_MASK           (0x1U)
#define SYSCON_PRESETCTRL_MRT_RST_SHIFT          (0U)
/*! MRT_RST - Multi-rate timer (MRT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_MRT_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MRT_RST_SHIFT)) & SYSCON_PRESETCTRL_MRT_RST_MASK)

#define SYSCON_PRESETCTRL_RIT_RST_MASK           (0x2U)
#define SYSCON_PRESETCTRL_RIT_RST_SHIFT          (1U)
/*! RIT_RST - Repetitive interrupt timer (RIT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_RIT_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_RIT_RST_SHIFT)) & SYSCON_PRESETCTRL_RIT_RST_MASK)

#define SYSCON_PRESETCTRL_SCT0_RST_MASK          (0x4U)
#define SYSCON_PRESETCTRL_SCT0_RST_SHIFT         (2U)
/*! SCT0_RST - State configurable timer 0 (SCT0) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_SCT0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SCT0_RST_SHIFT)) & SYSCON_PRESETCTRL_SCT0_RST_MASK)

#define SYSCON_PRESETCTRL_FLASH_RST_MASK         (0x80U)
#define SYSCON_PRESETCTRL_FLASH_RST_SHIFT        (7U)
/*! FLASH_RST - Flash controller reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FLASH_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FLASH_RST_SHIFT)) & SYSCON_PRESETCTRL_FLASH_RST_MASK)

#define SYSCON_PRESETCTRL_FMC_RST_MASK           (0x100U)
#define SYSCON_PRESETCTRL_FMC_RST_SHIFT          (8U)
/*! FMC_RST - Flash accelerator reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FMC_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FMC_RST_SHIFT)) & SYSCON_PRESETCTRL_FMC_RST_MASK)

#define SYSCON_PRESETCTRL_FIFO_RST_MASK          (0x200U)
#define SYSCON_PRESETCTRL_FIFO_RST_SHIFT         (9U)
/*! FIFO_RST - System FIFO reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FIFO_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FIFO_RST_SHIFT)) & SYSCON_PRESETCTRL_FIFO_RST_MASK)

#define SYSCON_PRESETCTRL_UTICK_RST_MASK         (0x400U)
#define SYSCON_PRESETCTRL_UTICK_RST_SHIFT        (10U)
/*! UTICK_RST - Micro-tick Timer reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_UTICK_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UTICK_RST_SHIFT)) & SYSCON_PRESETCTRL_UTICK_RST_MASK)

#define SYSCON_PRESETCTRL_MUX_RST_MASK           (0x800U)
#define SYSCON_PRESETCTRL_MUX_RST_SHIFT          (11U)
/*! MUX_RST - Input mux reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_MUX_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MUX_RST_SHIFT)) & SYSCON_PRESETCTRL_MUX_RST_MASK)

#define SYSCON_PRESETCTRL_IOCON_RST_MASK         (0x2000U)
#define SYSCON_PRESETCTRL_IOCON_RST_SHIFT        (13U)
/*! IOCON_RST - IOCON reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_IOCON_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_IOCON_RST_SHIFT)) & SYSCON_PRESETCTRL_IOCON_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO0_RST_MASK         (0x4000U)
#define SYSCON_PRESETCTRL_GPIO0_RST_SHIFT        (14U)
/*! GPIO0_RST - GPIO0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GPIO0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO0_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO0_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO1_RST_MASK         (0x8000U)
#define SYSCON_PRESETCTRL_GPIO1_RST_SHIFT        (15U)
/*! GPIO1_RST - GPIO1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GPIO1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO1_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO1_RST_MASK)

#define SYSCON_PRESETCTRL_PINT_RST_MASK          (0x40000U)
#define SYSCON_PRESETCTRL_PINT_RST_SHIFT         (18U)
/*! PINT_RST - Pin interrupt (PINT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_PINT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_PINT_RST_SHIFT)) & SYSCON_PRESETCTRL_PINT_RST_MASK)

#define SYSCON_PRESETCTRL_GINT_RST_MASK          (0x80000U)
#define SYSCON_PRESETCTRL_GINT_RST_SHIFT         (19U)
/*! GINT_RST - Grouped interrupt (GINT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GINT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GINT_RST_SHIFT)) & SYSCON_PRESETCTRL_GINT_RST_MASK)

#define SYSCON_PRESETCTRL_DMA_RST_MASK           (0x100000U)
#define SYSCON_PRESETCTRL_DMA_RST_SHIFT          (20U)
/*! DMA_RST - DMA reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_DMA_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_DMA_RST_SHIFT)) & SYSCON_PRESETCTRL_DMA_RST_MASK)

#define SYSCON_PRESETCTRL_CRC_RST_MASK           (0x200000U)
#define SYSCON_PRESETCTRL_CRC_RST_SHIFT          (21U)
/*! CRC_RST - CRC generator reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CRC_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CRC_RST_SHIFT)) & SYSCON_PRESETCTRL_CRC_RST_MASK)

#define SYSCON_PRESETCTRL_CT32B2_RST_MASK        (0x400000U)
#define SYSCON_PRESETCTRL_CT32B2_RST_SHIFT       (22U)
/*! CT32B2_RST - CT32B 2 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CT32B2_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CT32B2_RST_SHIFT)) & SYSCON_PRESETCTRL_CT32B2_RST_MASK)

#define SYSCON_PRESETCTRL_WWDT_RST_MASK          (0x400000U)
#define SYSCON_PRESETCTRL_WWDT_RST_SHIFT         (22U)
/*! WWDT_RST - Watchdog timer reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_WWDT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_WWDT_RST_SHIFT)) & SYSCON_PRESETCTRL_WWDT_RST_MASK)

#define SYSCON_PRESETCTRL_CT32B3_RST_MASK        (0x4000000U)
#define SYSCON_PRESETCTRL_CT32B3_RST_SHIFT       (26U)
/*! CT32B3_RST - CT32B 3 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CT32B3_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CT32B3_RST_SHIFT)) & SYSCON_PRESETCTRL_CT32B3_RST_MASK)

#define SYSCON_PRESETCTRL_ADC0_RST_MASK          (0x8000000U)
#define SYSCON_PRESETCTRL_ADC0_RST_SHIFT         (27U)
/*! ADC0_RST - ADC0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_ADC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_ADC0_RST_SHIFT)) & SYSCON_PRESETCTRL_ADC0_RST_MASK)

#define SYSCON_PRESETCTRL_CT32B4_RST_MASK        (0x8000000U)
#define SYSCON_PRESETCTRL_CT32B4_RST_SHIFT       (27U)
/*! CT32B4_RST - CT32B 4 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CT32B4_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CT32B4_RST_SHIFT)) & SYSCON_PRESETCTRL_CT32B4_RST_MASK)
/*! @} */

/*! @name PRESETCTRLSET - Set bits in PRESETCTRL n */
/*! @{ */

#define SYSCON_PRESETCTRLSET_RST_SET_MASK        (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLSET_RST_SET_SHIFT       (0U)
/*! RST_SET - Writing ones to this register sets the corresponding bit or bits in the PRESETCTRL n
 *    register, if they are implemented. Bits that do not correspond to defined bits in PRESETCTRL0
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_PRESETCTRLSET_RST_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_RST_SET_SHIFT)) & SYSCON_PRESETCTRLSET_RST_SET_MASK)
/*! @} */

/*! @name PRESETCTRLCLR - Clear bits in PRESETCTRL n */
/*! @{ */

#define SYSCON_PRESETCTRLCLR_RST_CLR_MASK        (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLCLR_RST_CLR_SHIFT       (0U)
/*! RST_CLR - Writing ones to this register clears the corresponding bit or bits in the PRESETCTRL n
 *    register, if they are implemented. Bits that do not correspond to defined bits in PRESETCTRL0
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_PRESETCTRLCLR_RST_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_RST_CLR_SHIFT)) & SYSCON_PRESETCTRLCLR_RST_CLR_MASK)
/*! @} */

/*! @name PIOPORCAP0 - POR captured PIO status 0 */
/*! @{ */

#define SYSCON_PIOPORCAP0_PIOPORSTAT_MASK        (0xFFFFFFFFU)
#define SYSCON_PIOPORCAP0_PIOPORSTAT_SHIFT       (0U)
/*! PIOPORSTAT - State of PIO0_31 through PIO0_0 at power-on reset */
#define SYSCON_PIOPORCAP0_PIOPORSTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORCAP0_PIOPORSTAT_SHIFT)) & SYSCON_PIOPORCAP0_PIOPORSTAT_MASK)
/*! @} */

/*! @name PIOPORCAP1 - POR captured PIO status 1 */
/*! @{ */

#define SYSCON_PIOPORCAP1_PIOPORSTAT_MASK        (0xFFFFFFFFU)
#define SYSCON_PIOPORCAP1_PIOPORSTAT_SHIFT       (0U)
/*! PIOPORSTAT - State of PIO1_31 through PIO1_0 at power-on reset */
#define SYSCON_PIOPORCAP1_PIOPORSTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORCAP1_PIOPORSTAT_SHIFT)) & SYSCON_PIOPORCAP1_PIOPORSTAT_MASK)
/*! @} */

/*! @name PIORESCAP0 - Reset captured PIO status 0 */
/*! @{ */

#define SYSCON_PIORESCAP0_PIORESSTAT_MASK        (0xFFFFFFFFU)
#define SYSCON_PIORESCAP0_PIORESSTAT_SHIFT       (0U)
/*! PIORESSTAT - State of PIO0_31 through PIO0_0 for resets other than power-on reset. */
#define SYSCON_PIORESCAP0_PIORESSTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PIORESCAP0_PIORESSTAT_SHIFT)) & SYSCON_PIORESCAP0_PIORESSTAT_MASK)
/*! @} */

/*! @name PIORESCAP1 - Reset captured PIO status 1 */
/*! @{ */

#define SYSCON_PIORESCAP1_PIORESSTAT_MASK        (0xFFFFFFFFU)
#define SYSCON_PIORESCAP1_PIORESSTAT_SHIFT       (0U)
/*! PIORESSTAT - State of PIO1_31 through PIO1_0 for resets other than power-on reset. */
#define SYSCON_PIORESCAP1_PIORESSTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PIORESCAP1_PIORESSTAT_SHIFT)) & SYSCON_PIORESCAP1_PIORESSTAT_MASK)
/*! @} */

/*! @name MAINCLKSELA - Main clock source select A */
/*! @{ */

#define SYSCON_MAINCLKSELA_SEL_MASK              (0x3U)
#define SYSCON_MAINCLKSELA_SEL_SHIFT             (0U)
/*! SEL - Clock source for main clock source selector A
 *  0b00..IRC Oscillator
 *  0b01..CLKIN
 *  0b10..Watchdog oscillator
 *  0b11..Reserved
 */
#define SYSCON_MAINCLKSELA_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELA_SEL_SHIFT)) & SYSCON_MAINCLKSELA_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELB - Main clock source select B */
/*! @{ */

#define SYSCON_MAINCLKSELB_SEL_MASK              (0x3U)
#define SYSCON_MAINCLKSELB_SEL_SHIFT             (0U)
/*! SEL - Clock source for main clock source selector B. Selects the clock source for the main clock.
 *  0b00..MAINCLKSELA. Use the clock source selected in MAINCLKSELA register.
 *  0b01..System PLL input.
 *  0b10..System PLL output.
 *  0b11..RTC osc output. RTC oscillator 32 kHz output.
 */
#define SYSCON_MAINCLKSELB_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELB_SEL_SHIFT)) & SYSCON_MAINCLKSELB_SEL_MASK)
/*! @} */

/*! @name ADCCLKSEL - ADC clock source select */
/*! @{ */

#define SYSCON_ADCCLKSEL_SEL_MASK                (0x3U)
#define SYSCON_ADCCLKSEL_SEL_SHIFT               (0U)
/*! SEL - ADC clock source.
 *  0b00..Main clock
 *  0b01..System PLL output
 *  0b10..IRC Oscillator
 *  0b11..reserved
 */
#define SYSCON_ADCCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKSEL_SEL_SHIFT)) & SYSCON_ADCCLKSEL_SEL_MASK)
/*! @} */

/*! @name CLKOUTSELA - CLKOUT clock source select A */
/*! @{ */

#define SYSCON_CLKOUTSELA_SEL_MASK               (0x3U)
#define SYSCON_CLKOUTSELA_SEL_SHIFT              (0U)
/*! SEL - CLKOUT clock source
 *  0b00..Main clock
 *  0b01..CLKIN
 *  0b10..Watchdog oscillator
 *  0b11..IRC oscillator
 */
#define SYSCON_CLKOUTSELA_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSELA_SEL_SHIFT)) & SYSCON_CLKOUTSELA_SEL_MASK)
/*! @} */

/*! @name CLKOUTSELB - CLKOUT clock source select B */
/*! @{ */

#define SYSCON_CLKOUTSELB_SEL_MASK               (0x3U)
#define SYSCON_CLKOUTSELB_SEL_SHIFT              (0U)
/*! SEL - CLKOUT clock source
 *  0b00..CLKOUTSELA. Clock source selected in the CLKOUTSELA register.
 *  0b01..reserved
 *  0b10..reserved
 *  0b11..RTC 32 kHz clock
 */
#define SYSCON_CLKOUTSELB_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSELB_SEL_SHIFT)) & SYSCON_CLKOUTSELB_SEL_MASK)
/*! @} */

/*! @name SYSPLLCLKSEL - PLL clock source select */
/*! @{ */

#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x3U)
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)
/*! SEL - System PLL clock source
 *  0b00..IRC Oscillator
 *  0b01..CLKIN
 *  0b10..Watchdog oscillator
 *  0b11..RTC 32 kHz clock
 */
#define SYSCON_SYSPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCLKSEL_SEL_SHIFT)) & SYSCON_SYSPLLCLKSEL_SEL_MASK)
/*! @} */

/*! @name AHBCLKCTRL - AHB Clock control n */
/*! @{ */

#define SYSCON_AHBCLKCTRL_MRT_MASK               (0x1U)
#define SYSCON_AHBCLKCTRL_MRT_SHIFT              (0U)
/*! MRT - Enables the clock for the Multi-Rate Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_MRT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_MRT_SHIFT)) & SYSCON_AHBCLKCTRL_MRT_MASK)

#define SYSCON_AHBCLKCTRL_RIT_MASK               (0x2U)
#define SYSCON_AHBCLKCTRL_RIT_SHIFT              (1U)
/*! RIT - Enables the clock for the repetitive interrupt timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_RIT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_RIT_SHIFT)) & SYSCON_AHBCLKCTRL_RIT_MASK)

#define SYSCON_AHBCLKCTRL_ROM_MASK               (0x2U)
#define SYSCON_AHBCLKCTRL_ROM_SHIFT              (1U)
/*! ROM - Enables the clock for the Boot ROM. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_ROM(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_ROM_SHIFT)) & SYSCON_AHBCLKCTRL_ROM_MASK)

#define SYSCON_AHBCLKCTRL_SCT0_MASK              (0x4U)
#define SYSCON_AHBCLKCTRL_SCT0_SHIFT             (2U)
/*! SCT0 - Enables the clock for SCT0. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SCT0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SCT0_SHIFT)) & SYSCON_AHBCLKCTRL_SCT0_MASK)

#define SYSCON_AHBCLKCTRL_SRAM1_MASK             (0x8U)
#define SYSCON_AHBCLKCTRL_SRAM1_SHIFT            (3U)
/*! SRAM1 - Enables the clock for SRAM1. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SRAM1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SRAM1_SHIFT)) & SYSCON_AHBCLKCTRL_SRAM1_MASK)

#define SYSCON_AHBCLKCTRL_SRAM2_MASK             (0x10U)
#define SYSCON_AHBCLKCTRL_SRAM2_SHIFT            (4U)
/*! SRAM2 - Enables the clock for SRAM2. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SRAM2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SRAM2_SHIFT)) & SYSCON_AHBCLKCTRL_SRAM2_MASK)

#define SYSCON_AHBCLKCTRL_FLASH_MASK             (0x80U)
#define SYSCON_AHBCLKCTRL_FLASH_SHIFT            (7U)
/*! FLASH - Enables the clock for the flash controller. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLASH(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLASH_SHIFT)) & SYSCON_AHBCLKCTRL_FLASH_MASK)

#define SYSCON_AHBCLKCTRL_FMC_MASK               (0x100U)
#define SYSCON_AHBCLKCTRL_FMC_SHIFT              (8U)
/*! FMC - Enables the clock for the Flash accelerator. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FMC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FMC_SHIFT)) & SYSCON_AHBCLKCTRL_FMC_MASK)

#define SYSCON_AHBCLKCTRL_FIFO_MASK              (0x200U)
#define SYSCON_AHBCLKCTRL_FIFO_SHIFT             (9U)
/*! FIFO - Enables the clock for system FIFOs. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FIFO(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FIFO_SHIFT)) & SYSCON_AHBCLKCTRL_FIFO_MASK)

#define SYSCON_AHBCLKCTRL_UTICK_MASK             (0x400U)
#define SYSCON_AHBCLKCTRL_UTICK_SHIFT            (10U)
/*! UTICK - Enables the clock for the Micro-tick Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_UTICK(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_UTICK_SHIFT)) & SYSCON_AHBCLKCTRL_UTICK_MASK)

#define SYSCON_AHBCLKCTRL_INPUTMUX_MASK          (0x800U)
#define SYSCON_AHBCLKCTRL_INPUTMUX_SHIFT         (11U)
/*! INPUTMUX - Enables the clock for the input muxes. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_INPUTMUX(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_INPUTMUX_SHIFT)) & SYSCON_AHBCLKCTRL_INPUTMUX_MASK)

#define SYSCON_AHBCLKCTRL_IOCON_MASK             (0x2000U)
#define SYSCON_AHBCLKCTRL_IOCON_SHIFT            (13U)
/*! IOCON - Enables the clock for the IOCON block. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_IOCON(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_IOCON_SHIFT)) & SYSCON_AHBCLKCTRL_IOCON_MASK)

#define SYSCON_AHBCLKCTRL_GPIO0_MASK             (0x4000U)
#define SYSCON_AHBCLKCTRL_GPIO0_SHIFT            (14U)
/*! GPIO0 - Enables the clock for the GPIO0 port registers. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GPIO0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO0_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO0_MASK)

#define SYSCON_AHBCLKCTRL_GPIO1_MASK             (0x8000U)
#define SYSCON_AHBCLKCTRL_GPIO1_SHIFT            (15U)
/*! GPIO1 - Enables the clock for the GPIO1 port registers. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GPIO1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO1_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO1_MASK)

#define SYSCON_AHBCLKCTRL_PINT_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL_PINT_SHIFT             (18U)
/*! PINT - Enables the clock for the pin interrupt block.0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_PINT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_PINT_SHIFT)) & SYSCON_AHBCLKCTRL_PINT_MASK)

#define SYSCON_AHBCLKCTRL_GINT_MASK              (0x80000U)
#define SYSCON_AHBCLKCTRL_GINT_SHIFT             (19U)
/*! GINT - Enables the clock for the grouped pin interrupt block. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GINT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GINT_SHIFT)) & SYSCON_AHBCLKCTRL_GINT_MASK)

#define SYSCON_AHBCLKCTRL_DMA_MASK               (0x100000U)
#define SYSCON_AHBCLKCTRL_DMA_SHIFT              (20U)
/*! DMA - Enables the clock for the DMA controller. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_DMA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_DMA_SHIFT)) & SYSCON_AHBCLKCTRL_DMA_MASK)

#define SYSCON_AHBCLKCTRL_CRC_MASK               (0x200000U)
#define SYSCON_AHBCLKCTRL_CRC_SHIFT              (21U)
/*! CRC - Enables the clock for the CRC engine. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CRC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CRC_SHIFT)) & SYSCON_AHBCLKCTRL_CRC_MASK)

#define SYSCON_AHBCLKCTRL_CT32B2_MASK            (0x400000U)
#define SYSCON_AHBCLKCTRL_CT32B2_SHIFT           (22U)
/*! CT32B2 - Enables the clock for CT32B 2. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CT32B2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CT32B2_SHIFT)) & SYSCON_AHBCLKCTRL_CT32B2_MASK)

#define SYSCON_AHBCLKCTRL_WWDT_MASK              (0x400000U)
#define SYSCON_AHBCLKCTRL_WWDT_SHIFT             (22U)
/*! WWDT - Enables the clock for the Watchdog Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_WWDT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_WWDT_SHIFT)) & SYSCON_AHBCLKCTRL_WWDT_MASK)

#define SYSCON_AHBCLKCTRL_RTC_MASK               (0x800000U)
#define SYSCON_AHBCLKCTRL_RTC_SHIFT              (23U)
/*! RTC - Enables the clock for the RTC. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_RTC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_RTC_SHIFT)) & SYSCON_AHBCLKCTRL_RTC_MASK)

#define SYSCON_AHBCLKCTRL_CT32B3_MASK            (0x4000000U)
#define SYSCON_AHBCLKCTRL_CT32B3_SHIFT           (26U)
/*! CT32B3 - Enables the clock for CT32B 3. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CT32B3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CT32B3_SHIFT)) & SYSCON_AHBCLKCTRL_CT32B3_MASK)

#define SYSCON_AHBCLKCTRL_MAILBOX_MASK           (0x4000000U)
#define SYSCON_AHBCLKCTRL_MAILBOX_SHIFT          (26U)
/*! MAILBOX - Enables the clock for the Mailbox. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_MAILBOX(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_MAILBOX_SHIFT)) & SYSCON_AHBCLKCTRL_MAILBOX_MASK)

#define SYSCON_AHBCLKCTRL_ADC0_MASK              (0x8000000U)
#define SYSCON_AHBCLKCTRL_ADC0_SHIFT             (27U)
/*! ADC0 - Enables the clock for the ADC0 register interface. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_ADC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_ADC0_SHIFT)) & SYSCON_AHBCLKCTRL_ADC0_MASK)

#define SYSCON_AHBCLKCTRL_CT32B4_MASK            (0x8000000U)
#define SYSCON_AHBCLKCTRL_CT32B4_SHIFT           (27U)
/*! CT32B4 - Enables the clock for CT32B 4. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CT32B4(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CT32B4_SHIFT)) & SYSCON_AHBCLKCTRL_CT32B4_MASK)
/*! @} */

/*! @name AHBCLKCTRLSET - Set bits in AHBCLKCTRL n */
/*! @{ */

#define SYSCON_AHBCLKCTRLSET_CLK_SET_MASK        (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLSET_CLK_SET_SHIFT       (0U)
/*! CLK_SET - Writing ones to this register sets the corresponding bit or bits in the AHBCLKCTRL0
 *    register, if they are implemented. Bits that do not correspond to defined bits in AHBCLKCTRL0
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_AHBCLKCTRLSET_CLK_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLSET_CLK_SET_SHIFT)) & SYSCON_AHBCLKCTRLSET_CLK_SET_MASK)
/*! @} */

/*! @name AHBCLKCTRLCLR - Clear bits in AHBCLKCTRL n */
/*! @{ */

#define SYSCON_AHBCLKCTRLCLR_CLK_CLR_MASK        (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLCLR_CLK_CLR_SHIFT       (0U)
/*! CLK_CLR - Writing ones to this register clears the corresponding bit or bits in the AHBCLKCTRL0
 *    register, if they are implemented. Bits that do not correspond to defined bits in AHBCLKCTRL0
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_AHBCLKCTRLCLR_CLK_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLCLR_CLK_CLR_SHIFT)) & SYSCON_AHBCLKCTRLCLR_CLK_CLR_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV - SYSTICK clock divider */
/*! @{ */

#define SYSCON_SYSTICKCLKDIV_DIV_MASK            (0xFFU)
#define SYSCON_SYSTICKCLKDIV_DIV_SHIFT           (0U)
/*! DIV - SYSTICK clock divider value. 0: Disable SYSTICK timer clock. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_SYSTICKCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_DIV_SHIFT)) & SYSCON_SYSTICKCLKDIV_DIV_MASK)
/*! @} */

/*! @name TRACECLKDIV - TRACE clock divider */
/*! @{ */

#define SYSCON_TRACECLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_TRACECLKDIV_DIV_SHIFT             (0U)
/*! DIV - TRACE clock divider value. 0: Disable TRACE clock. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_TRACECLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_DIV_SHIFT)) & SYSCON_TRACECLKDIV_DIV_MASK)
/*! @} */

/*! @name AHBCLKDIV - System clock divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - System AHB clock divider value. 0: System clock disabled. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)
/*! @} */

/*! @name ADCCLKDIV - ADC clock divider */
/*! @{ */

#define SYSCON_ADCCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_ADCCLKDIV_DIV_SHIFT               (0U)
/*! DIV - ADC clock divider value. 0: Disable ADC clock. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_ADCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_DIV_SHIFT)) & SYSCON_ADCCLKDIV_DIV_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - CLKOUT clock divider value. 0: Disable CLKOUT clock divider. 1: Divide by 1. to 255: Divide by 255. */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)
/*! @} */

/*! @name FREQMECTRL - Frequency measure register */
/*! @{ */

#define SYSCON_FREQMECTRL_CAPVAL_MASK            (0x3FFFU)
#define SYSCON_FREQMECTRL_CAPVAL_SHIFT           (0U)
/*! CAPVAL - Stores the capture result which is used to calculate the frequency of the target clock. This field is read-only. */
#define SYSCON_FREQMECTRL_CAPVAL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FREQMECTRL_CAPVAL_SHIFT)) & SYSCON_FREQMECTRL_CAPVAL_MASK)

#define SYSCON_FREQMECTRL_PROG_MASK              (0x80000000U)
#define SYSCON_FREQMECTRL_PROG_SHIFT             (31U)
/*! PROG - Set this bit to one to initiate a frequency measurement cycle. Hardware clears this bit
 *    when the measurement cycle has completed and there is valid capture data in the CAPVAL field
 *    (bits 13:0).
 */
#define SYSCON_FREQMECTRL_PROG(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FREQMECTRL_PROG_SHIFT)) & SYSCON_FREQMECTRL_PROG_MASK)
/*! @} */

/*! @name FLASHCFG - Flash wait states configuration */
/*! @{ */

#define SYSCON_FLASHCFG_FETCHCFG_MASK            (0x3U)
#define SYSCON_FLASHCFG_FETCHCFG_SHIFT           (0U)
/*! FETCHCFG - Instruction fetch configuration. This field determines how flash accelerator buffers are used for instruction fetches. */
#define SYSCON_FLASHCFG_FETCHCFG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_FETCHCFG_SHIFT)) & SYSCON_FLASHCFG_FETCHCFG_MASK)

#define SYSCON_FLASHCFG_DATACFG_MASK             (0xCU)
#define SYSCON_FLASHCFG_DATACFG_SHIFT            (2U)
/*! DATACFG - Data read configuration. This field determines how flash accelerator buffers are used for data accesses. */
#define SYSCON_FLASHCFG_DATACFG(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_DATACFG_SHIFT)) & SYSCON_FLASHCFG_DATACFG_MASK)

#define SYSCON_FLASHCFG_ACCEL_MASK               (0x10U)
#define SYSCON_FLASHCFG_ACCEL_SHIFT              (4U)
/*! ACCEL - Acceleration enable. */
#define SYSCON_FLASHCFG_ACCEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_ACCEL_SHIFT)) & SYSCON_FLASHCFG_ACCEL_MASK)

#define SYSCON_FLASHCFG_PREFEN_MASK              (0x20U)
#define SYSCON_FLASHCFG_PREFEN_SHIFT             (5U)
/*! PREFEN - Prefetch enable. */
#define SYSCON_FLASHCFG_PREFEN(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_PREFEN_SHIFT)) & SYSCON_FLASHCFG_PREFEN_MASK)

#define SYSCON_FLASHCFG_PREFOVR_MASK             (0x40U)
#define SYSCON_FLASHCFG_PREFOVR_SHIFT            (6U)
/*! PREFOVR - Prefetch override. */
#define SYSCON_FLASHCFG_PREFOVR(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_PREFOVR_SHIFT)) & SYSCON_FLASHCFG_PREFOVR_MASK)

#define SYSCON_FLASHCFG_FLASHTIM_MASK            (0xF000U)
#define SYSCON_FLASHCFG_FLASHTIM_SHIFT           (12U)
/*! FLASHTIM - Flash memory access time. FLASHTIM +1 is equal to the number of system clocks used for flash access.
 *  0b0000..1 clock cycle. 1 system clock flash access time (for system clock frequencies of up to MHz).
 *  0b0001..2 clock cycles. 2 system clocks flash access time (for system clock frequencies of up to MHz).
 *  0b0010..3 clock cycles. 3 system clocks flash access time (for system clock frequencies of up to MHz).
 *  0b0011..4 clock cycles. 4 system clocks flash access time.
 *  0b0100..5 clock cycles. 5 system clocks flash access time.
 *  0b0101..6 clock cycles. 6 system clocks flash access time.
 *  0b0110..7 clock cycles. 7 system clocks flash access time.
 *  0b0111..8 clock cycles. 8 system clocks flash access time.
 */
#define SYSCON_FLASHCFG_FLASHTIM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_FLASHTIM_SHIFT)) & SYSCON_FLASHCFG_FLASHTIM_MASK)
/*! @} */

/*! @name FIFOCTRL - Serial interface FIFO enables */
/*! @{ */

#define SYSCON_FIFOCTRL_U0TXFIFOEN_MASK          (0x1U)
#define SYSCON_FIFOCTRL_U0TXFIFOEN_SHIFT         (0U)
/*! U0TXFIFOEN - USART0 transmitter FIFO enable */
#define SYSCON_FIFOCTRL_U0TXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U0TXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U0TXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U1TXFIFOEN_MASK          (0x2U)
#define SYSCON_FIFOCTRL_U1TXFIFOEN_SHIFT         (1U)
/*! U1TXFIFOEN - USART1 transmitter FIFO enable */
#define SYSCON_FIFOCTRL_U1TXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U1TXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U1TXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U2TXFIFOEN_MASK          (0x4U)
#define SYSCON_FIFOCTRL_U2TXFIFOEN_SHIFT         (2U)
/*! U2TXFIFOEN - USART2 transmitter FIFO enable */
#define SYSCON_FIFOCTRL_U2TXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U2TXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U2TXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U3TXFIFOEN_MASK          (0x8U)
#define SYSCON_FIFOCTRL_U3TXFIFOEN_SHIFT         (3U)
/*! U3TXFIFOEN - USART3 transmitter FIFO enable */
#define SYSCON_FIFOCTRL_U3TXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U3TXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U3TXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_SPI0TXFIFOEN_MASK        (0x10U)
#define SYSCON_FIFOCTRL_SPI0TXFIFOEN_SHIFT       (4U)
/*! SPI0TXFIFOEN - SPI0 transmitter FIFO enable */
#define SYSCON_FIFOCTRL_SPI0TXFIFOEN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_SPI0TXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_SPI0TXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_SPI1TXFIFOEN_MASK        (0x20U)
#define SYSCON_FIFOCTRL_SPI1TXFIFOEN_SHIFT       (5U)
/*! SPI1TXFIFOEN - SPI1 transmitter FIFO enable */
#define SYSCON_FIFOCTRL_SPI1TXFIFOEN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_SPI1TXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_SPI1TXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U0RXFIFOEN_MASK          (0x100U)
#define SYSCON_FIFOCTRL_U0RXFIFOEN_SHIFT         (8U)
/*! U0RXFIFOEN - USART0 receiver FIFO enable */
#define SYSCON_FIFOCTRL_U0RXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U0RXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U0RXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U1RXFIFOEN_MASK          (0x200U)
#define SYSCON_FIFOCTRL_U1RXFIFOEN_SHIFT         (9U)
/*! U1RXFIFOEN - USART1 receiver FIFO enable */
#define SYSCON_FIFOCTRL_U1RXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U1RXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U1RXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U2RXFIFOEN_MASK          (0x400U)
#define SYSCON_FIFOCTRL_U2RXFIFOEN_SHIFT         (10U)
/*! U2RXFIFOEN - USART2 receiver FIFO enable */
#define SYSCON_FIFOCTRL_U2RXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U2RXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U2RXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_U3RXFIFOEN_MASK          (0x800U)
#define SYSCON_FIFOCTRL_U3RXFIFOEN_SHIFT         (11U)
/*! U3RXFIFOEN - USART3 receiver FIFO enable */
#define SYSCON_FIFOCTRL_U3RXFIFOEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_U3RXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_U3RXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_SPI0RXFIFOEN_MASK        (0x1000U)
#define SYSCON_FIFOCTRL_SPI0RXFIFOEN_SHIFT       (12U)
/*! SPI0RXFIFOEN - SPI0 receiver FIFO enable */
#define SYSCON_FIFOCTRL_SPI0RXFIFOEN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_SPI0RXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_SPI0RXFIFOEN_MASK)

#define SYSCON_FIFOCTRL_SPI1RXFIFOEN_MASK        (0x2000U)
#define SYSCON_FIFOCTRL_SPI1RXFIFOEN_SHIFT       (13U)
/*! SPI1RXFIFOEN - SPI1 receiver FIFO enable */
#define SYSCON_FIFOCTRL_SPI1RXFIFOEN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FIFOCTRL_SPI1RXFIFOEN_SHIFT)) & SYSCON_FIFOCTRL_SPI1RXFIFOEN_MASK)
/*! @} */

/*! @name IRCCTRL - IRC oscillator control */
/*! @{ */

#define SYSCON_IRCCTRL_TRIM_MASK                 (0xFFU)
#define SYSCON_IRCCTRL_TRIM_SHIFT                (0U)
/*! TRIM - Trim value */
#define SYSCON_IRCCTRL_TRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_IRCCTRL_TRIM_SHIFT)) & SYSCON_IRCCTRL_TRIM_MASK)
/*! @} */

/*! @name RTCOSCCTRL - RTC oscillator 32 kHz output control */
/*! @{ */

#define SYSCON_RTCOSCCTRL_EN_MASK                (0x1U)
#define SYSCON_RTCOSCCTRL_EN_SHIFT               (0U)
/*! EN - RTC 32 kHz clock enable.
 *  0b0..Disabled. RTC clock off.
 *  0b1..Enabled. RTC clock on.
 */
#define SYSCON_RTCOSCCTRL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_RTCOSCCTRL_EN_SHIFT)) & SYSCON_RTCOSCCTRL_EN_MASK)
/*! @} */

/*! @name SYSPLLCTRL - PLL control */
/*! @{ */

#define SYSCON_SYSPLLCTRL_SELR_MASK              (0xFU)
#define SYSCON_SYSPLLCTRL_SELR_SHIFT             (0U)
/*! SELR - Bandwidth select R value */
#define SYSCON_SYSPLLCTRL_SELR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELR_SHIFT)) & SYSCON_SYSPLLCTRL_SELR_MASK)

#define SYSCON_SYSPLLCTRL_SELI_MASK              (0x3F0U)
#define SYSCON_SYSPLLCTRL_SELI_SHIFT             (4U)
/*! SELI - Bandwidth select I value */
#define SYSCON_SYSPLLCTRL_SELI(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELI_SHIFT)) & SYSCON_SYSPLLCTRL_SELI_MASK)

#define SYSCON_SYSPLLCTRL_SELP_MASK              (0x7C00U)
#define SYSCON_SYSPLLCTRL_SELP_SHIFT             (10U)
/*! SELP - Bandwidth select P value */
#define SYSCON_SYSPLLCTRL_SELP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELP_SHIFT)) & SYSCON_SYSPLLCTRL_SELP_MASK)

#define SYSCON_SYSPLLCTRL_BYPASS_MASK            (0x8000U)
#define SYSCON_SYSPLLCTRL_BYPASS_SHIFT           (15U)
/*! BYPASS - PLL bypass control
 *  0b0..Disabled. PLL CCO is used to create the PLL output.
 *  0b1..Enabled. PLL is bypassed, the PLL input clock is routed directly to the PLL output (default).
 */
#define SYSCON_SYSPLLCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_BYPASS_SHIFT)) & SYSCON_SYSPLLCTRL_BYPASS_MASK)

#define SYSCON_SYSPLLCTRL_BYPASSCCODIV2_MASK     (0x10000U)
#define SYSCON_SYSPLLCTRL_BYPASSCCODIV2_SHIFT    (16U)
/*! BYPASSCCODIV2 - Bypass feedback clock divide by 2.
 *  0b0..Divide by 2. The CCO feedback clock is divided by 2 in addition to the programmed M divide.
 *  0b1..Bypass. The CCO feedback clock is divided only by the programmed M divide.
 */
#define SYSCON_SYSPLLCTRL_BYPASSCCODIV2(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_BYPASSCCODIV2_SHIFT)) & SYSCON_SYSPLLCTRL_BYPASSCCODIV2_MASK)

#define SYSCON_SYSPLLCTRL_UPLIMOFF_MASK          (0x20000U)
#define SYSCON_SYSPLLCTRL_UPLIMOFF_SHIFT         (17U)
/*! UPLIMOFF - Enable spread spectrum/fractional mode
 *  0b0..Normal mode.
 *  0b1..SSGC mode. Spread spectrum/fractional mode.
 */
#define SYSCON_SYSPLLCTRL_UPLIMOFF(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_UPLIMOFF_SHIFT)) & SYSCON_SYSPLLCTRL_UPLIMOFF_MASK)

#define SYSCON_SYSPLLCTRL_BANDSEL_MASK           (0x40000U)
#define SYSCON_SYSPLLCTRL_BANDSEL_SHIFT          (18U)
/*! BANDSEL - PLL filter control. Set this bit to one when the SSGC is disabled or at low frequencies.
 *  0b0..SSCG control. The PLL filter uses the parameters derived from the SSCG decoder.
 *  0b1..MDEC control. The PLL filter uses the programmable fields SELP, SELR, and SELI in this register to control the filter constants.
 */
#define SYSCON_SYSPLLCTRL_BANDSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_BANDSEL_SHIFT)) & SYSCON_SYSPLLCTRL_BANDSEL_MASK)

#define SYSCON_SYSPLLCTRL_DIRECTI_MASK           (0x80000U)
#define SYSCON_SYSPLLCTRL_DIRECTI_SHIFT          (19U)
/*! DIRECTI - PLL0 direct input enable
 *  0b0..Disabled. The PLL input divider (N divider) output is used to drive the PLL CCO.
 *  0b1..Enabled. The PLL input divider (N divider) is bypassed. the PLL input clock is used directly to drive the PLL CCO.
 */
#define SYSCON_SYSPLLCTRL_DIRECTI(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_DIRECTI_SHIFT)) & SYSCON_SYSPLLCTRL_DIRECTI_MASK)

#define SYSCON_SYSPLLCTRL_DIRECTO_MASK           (0x100000U)
#define SYSCON_SYSPLLCTRL_DIRECTO_SHIFT          (20U)
/*! DIRECTO - PLL0 direct output enable
 *  0b0..Disabled. The PLL output divider (P divider) is used to create the PLL output.
 *  0b1..Enabled. The PLL output divider (P divider) is bypassed, the PLL CCO output is used as the PLL output.
 */
#define SYSCON_SYSPLLCTRL_DIRECTO(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_DIRECTO_SHIFT)) & SYSCON_SYSPLLCTRL_DIRECTO_MASK)
/*! @} */

/*! @name SYSPLLSTAT - PLL status */
/*! @{ */

#define SYSCON_SYSPLLSTAT_LOCK_MASK              (0x1U)
#define SYSCON_SYSPLLSTAT_LOCK_SHIFT             (0U)
/*! LOCK - PLL0 lock indicator */
#define SYSCON_SYSPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSTAT_LOCK_SHIFT)) & SYSCON_SYSPLLSTAT_LOCK_MASK)
/*! @} */

/*! @name SYSPLLNDEC - PLL N decoder */
/*! @{ */

#define SYSCON_SYSPLLNDEC_NDEC_MASK              (0x3FFU)
#define SYSCON_SYSPLLNDEC_NDEC_SHIFT             (0U)
/*! NDEC - Decoded N-divider coefficient value */
#define SYSCON_SYSPLLNDEC_NDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLNDEC_NDEC_SHIFT)) & SYSCON_SYSPLLNDEC_NDEC_MASK)

#define SYSCON_SYSPLLNDEC_NREQ_MASK              (0x400U)
#define SYSCON_SYSPLLNDEC_NREQ_SHIFT             (10U)
/*! NREQ - NDEC reload request. When a 1 is written to this bit, the NDEC value is loaded into the
 *    PLL. Must be cleared by software for any subsequent load, or the PLL can be powered down and
 *    back up via the PDEN_SYS_PLL bit in the PDRUNCFG register if the NDEC value is changed.
 */
#define SYSCON_SYSPLLNDEC_NREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLNDEC_NREQ_SHIFT)) & SYSCON_SYSPLLNDEC_NREQ_MASK)
/*! @} */

/*! @name SYSPLLPDEC - PLL P decoder */
/*! @{ */

#define SYSCON_SYSPLLPDEC_PDEC_MASK              (0x7FU)
#define SYSCON_SYSPLLPDEC_PDEC_SHIFT             (0U)
/*! PDEC - Decoded P-divider coefficient value */
#define SYSCON_SYSPLLPDEC_PDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLPDEC_PDEC_SHIFT)) & SYSCON_SYSPLLPDEC_PDEC_MASK)

#define SYSCON_SYSPLLPDEC_PREQ_MASK              (0x80U)
#define SYSCON_SYSPLLPDEC_PREQ_SHIFT             (7U)
/*! PREQ - PDEC reload request. When a 1 is written to this bit, the PDEC value is loaded into the
 *    PLL. Must be cleared by software for any subsequent load, or the PLL can be powered down and
 *    back up via the PDEN_SYS_PLL bit in the PDRUNCFG register if the PDEC value is changed.
 */
#define SYSCON_SYSPLLPDEC_PREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLPDEC_PREQ_SHIFT)) & SYSCON_SYSPLLPDEC_PREQ_MASK)
/*! @} */

/*! @name SYSPLLSSCTRL0 - PLL spread spectrum control 0 */
/*! @{ */

#define SYSCON_SYSPLLSSCTRL0_MDEC_MASK           (0x1FFFFU)
#define SYSCON_SYSPLLSSCTRL0_MDEC_SHIFT          (0U)
/*! MDEC - Decoded M-divider coefficient value */
#define SYSCON_SYSPLLSSCTRL0_MDEC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL0_MDEC_SHIFT)) & SYSCON_SYSPLLSSCTRL0_MDEC_MASK)

#define SYSCON_SYSPLLSSCTRL0_MREQ_MASK           (0x20000U)
#define SYSCON_SYSPLLSSCTRL0_MREQ_SHIFT          (17U)
/*! MREQ - MDEC reload request. When a 1 is written to this bit, the MDEC value is loaded into the
 *    PLL. Must be cleared by software for any subsequent load, or the PLL can be powered down and
 *    back up via the PDEN_SYS_PLL bit in the PDRUNCFG register if the MDEC value is changed.
 */
#define SYSCON_SYSPLLSSCTRL0_MREQ(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL0_MREQ_SHIFT)) & SYSCON_SYSPLLSSCTRL0_MREQ_MASK)

#define SYSCON_SYSPLLSSCTRL0_SEL_EXT_MASK        (0x40000U)
#define SYSCON_SYSPLLSSCTRL0_SEL_EXT_SHIFT       (18U)
/*! SEL_EXT - Select spread spectrum mode.
 *  0b0..Spread spectrum mode. Spread spectrum mode enabled.
 *  0b1..MDEC enabled. Spread spectrum clock generator not used.
 */
#define SYSCON_SYSPLLSSCTRL0_SEL_EXT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL0_SEL_EXT_SHIFT)) & SYSCON_SYSPLLSSCTRL0_SEL_EXT_MASK)
/*! @} */

/*! @name SYSPLLSSCTRL1 - PLL spread spectrum control 1 */
/*! @{ */

#define SYSCON_SYSPLLSSCTRL1_MD_MASK             (0x7FFFFU)
#define SYSCON_SYSPLLSSCTRL1_MD_SHIFT            (0U)
/*! MD - M- divider value with fraction. MD[18:11] : integer portion of the feedback divider value.
 *    MD[10:0] : fractional portion of the feedback divider value.
 */
#define SYSCON_SYSPLLSSCTRL1_MD(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MD_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MD_MASK)

#define SYSCON_SYSPLLSSCTRL1_MDREQ_MASK          (0x80000U)
#define SYSCON_SYSPLLSSCTRL1_MDREQ_SHIFT         (19U)
/*! MDREQ - MD reload request. When a 1 is written to this bit, the MD value is loaded into the PLL.
 *    This bit is cleared when the load is complete.
 */
#define SYSCON_SYSPLLSSCTRL1_MDREQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MDREQ_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MDREQ_MASK)

#define SYSCON_SYSPLLSSCTRL1_MF_MASK             (0x700000U)
#define SYSCON_SYSPLLSSCTRL1_MF_SHIFT            (20U)
/*! MF - Programmable modulation frequency fm = Fref/Nss with Fref = Fin/N 0b000 => Nss = 512 (fm =
 *    3.9 - 7.8 kHz) 0b001 => Nss = 384 (fm = 5.2 - 10.4 kHz) 0b010 => Nss = 256 (fm = 7.8 - 15.6
 *    kHz) 0b011 => Nss = 128 (fm = 15.6 - 31.3 kHz) 0b100 => Nss = 64 (fm = 32.3 - 64.5 kHz) 0b101 =>
 *    Nss = 32 (fm = 62.5- 125 kHz) 0b110 => Nss = 24 (fm = 83.3- 166.6 kHz) 0b111 => Nss = 16 (fm
 *    = 125- 250 kHz)
 */
#define SYSCON_SYSPLLSSCTRL1_MF(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MF_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MF_MASK)

#define SYSCON_SYSPLLSSCTRL1_MR_MASK             (0x3800000U)
#define SYSCON_SYSPLLSSCTRL1_MR_SHIFT            (23U)
/*! MR - Programmable frequency modulation depth deltafmodpk-pk = Fref x k/Fcco = k/MDdec 0 = no
 *    spread 0b000 => k = 0 (no spread spectrum) 0b001 => k = 1 0b010 => k = 1.5 0b011 => k = 2 0b100
 *    => k = 3 0b101 => k = 4 0b110 => k = 6 0b111 => k = 8
 */
#define SYSCON_SYSPLLSSCTRL1_MR(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MR_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MR_MASK)

#define SYSCON_SYSPLLSSCTRL1_MC_MASK             (0xC000000U)
#define SYSCON_SYSPLLSSCTRL1_MC_SHIFT            (26U)
/*! MC - Modulation waveform control 0 = no compensation Compensation for low pass filtering of the
 *    PLL to get a triangular modulation at the output of the PLL, giving a flat frequency spectrum.
 *    0b00 => no compensation 0b10 => recommended setting 0b11 => max. compensation
 */
#define SYSCON_SYSPLLSSCTRL1_MC(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MC_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MC_MASK)

#define SYSCON_SYSPLLSSCTRL1_PD_MASK             (0x10000000U)
#define SYSCON_SYSPLLSSCTRL1_PD_SHIFT            (28U)
/*! PD - Power down.
 *  0b0..Enabled. Spread spectrum controller is enabled
 *  0b1..Disabled. Spread spectrum controller is disabled
 */
#define SYSCON_SYSPLLSSCTRL1_PD(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_PD_SHIFT)) & SYSCON_SYSPLLSSCTRL1_PD_MASK)

#define SYSCON_SYSPLLSSCTRL1_DITHER_MASK         (0x20000000U)
#define SYSCON_SYSPLLSSCTRL1_DITHER_SHIFT        (29U)
/*! DITHER - Select modulation frequency.
 *  0b0..Fixed. Fixed modulation frequency.
 *  0b1..Dither. Randomly dither between two modulation frequencies.
 */
#define SYSCON_SYSPLLSSCTRL1_DITHER(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_DITHER_SHIFT)) & SYSCON_SYSPLLSSCTRL1_DITHER_MASK)
/*! @} */

/*! @name PDRUNCFG - Power configuration register */
/*! @{ */

#define SYSCON_PDRUNCFG_PDEN_IRC_OSC_MASK        (0x8U)
#define SYSCON_PDRUNCFG_PDEN_IRC_OSC_SHIFT       (3U)
/*! PDEN_IRC_OSC - IRC oscillator output. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_IRC_OSC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_IRC_OSC_SHIFT)) & SYSCON_PDRUNCFG_PDEN_IRC_OSC_MASK)

#define SYSCON_PDRUNCFG_PDEN_IRC_MASK            (0x10U)
#define SYSCON_PDRUNCFG_PDEN_IRC_SHIFT           (4U)
/*! PDEN_IRC - IRC oscillator. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_IRC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_IRC_SHIFT)) & SYSCON_PDRUNCFG_PDEN_IRC_MASK)

#define SYSCON_PDRUNCFG_PDEN_FLASH_MASK          (0x20U)
#define SYSCON_PDRUNCFG_PDEN_FLASH_SHIFT         (5U)
/*! PDEN_FLASH - Flash memory. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_FLASH(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_FLASH_SHIFT)) & SYSCON_PDRUNCFG_PDEN_FLASH_MASK)

#define SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK        (0x80U)
#define SYSCON_PDRUNCFG_PDEN_BOD_RST_SHIFT       (7U)
/*! PDEN_BOD_RST - Brown-out Detect reset. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_BOD_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_BOD_RST_SHIFT)) & SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK)

#define SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK       (0x100U)
#define SYSCON_PDRUNCFG_PDEN_BOD_INTR_SHIFT      (8U)
/*! PDEN_BOD_INTR - Brown-out Detect interrupt. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_BOD_INTR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_BOD_INTR_SHIFT)) & SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK)

#define SYSCON_PDRUNCFG_PDEN_ADC0_MASK           (0x400U)
#define SYSCON_PDRUNCFG_PDEN_ADC0_SHIFT          (10U)
/*! PDEN_ADC0 - ADC0. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_ADC0_SHIFT)) & SYSCON_PDRUNCFG_PDEN_ADC0_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAM0A_MASK         (0x2000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM0A_SHIFT        (13U)
/*! PDEN_SRAM0A - First 8 kB of SRAM0). 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SRAM0A(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM0A_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM0A_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAM0B_MASK         (0x4000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM0B_SHIFT        (14U)
/*! PDEN_SRAM0B - Remaining portion of SRAM0). 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SRAM0B(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM0B_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM0B_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAM1_MASK          (0x8000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM1_SHIFT         (15U)
/*! PDEN_SRAM1 - SRAM1. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SRAM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM1_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM1_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAM2_MASK          (0x10000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM2_SHIFT         (16U)
/*! PDEN_SRAM2 - SRAM2 (undedicated 8 kB RAM). 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SRAM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM2_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM2_MASK)

#define SYSCON_PDRUNCFG_PDEN_ROM_MASK            (0x20000U)
#define SYSCON_PDRUNCFG_PDEN_ROM_SHIFT           (17U)
/*! PDEN_ROM - ROM. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_ROM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_ROM_SHIFT)) & SYSCON_PDRUNCFG_PDEN_ROM_MASK)

#define SYSCON_PDRUNCFG_PDEN_VDDA_MASK           (0x80000U)
#define SYSCON_PDRUNCFG_PDEN_VDDA_SHIFT          (19U)
/*! PDEN_VDDA - Vdda to the ADC, must be enabled for the ADC to work. Also see bit 23. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_VDDA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VDDA_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VDDA_MASK)

#define SYSCON_PDRUNCFG_PDEN_WDT_OSC_MASK        (0x100000U)
#define SYSCON_PDRUNCFG_PDEN_WDT_OSC_SHIFT       (20U)
/*! PDEN_WDT_OSC - Watchdog oscillator. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_WDT_OSC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_WDT_OSC_SHIFT)) & SYSCON_PDRUNCFG_PDEN_WDT_OSC_MASK)

#define SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK        (0x400000U)
#define SYSCON_PDRUNCFG_PDEN_SYS_PLL_SHIFT       (22U)
/*! PDEN_SYS_PLL - PLL0. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SYS_PLL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SYS_PLL_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK)

#define SYSCON_PDRUNCFG_PDEN_VREFP_MASK          (0x800000U)
#define SYSCON_PDRUNCFG_PDEN_VREFP_SHIFT         (23U)
/*! PDEN_VREFP - Vrefp to the ADC, must be enabled for the ADC to work. Also see bit 19. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_VREFP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VREFP_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VREFP_MASK)

#define SYSCON_PDRUNCFG_PDEN_32K_OSC_MASK        (0x1000000U)
#define SYSCON_PDRUNCFG_PDEN_32K_OSC_SHIFT       (24U)
/*! PDEN_32K_OSC - 32 kHz RTC oscillator. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_32K_OSC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_32K_OSC_SHIFT)) & SYSCON_PDRUNCFG_PDEN_32K_OSC_MASK)
/*! @} */

/*! @name PDRUNCFGSET - Set bits in PDRUNCFG */
/*! @{ */

#define SYSCON_PDRUNCFGSET_PD_SET_MASK           (0xFFFFFFFFU)
#define SYSCON_PDRUNCFGSET_PD_SET_SHIFT          (0U)
/*! PD_SET - Writing ones to this register sets the corresponding bit or bits in the PDRUNCFG
 *    register, if they are implemented. Bits that do not correspond to defined bits in PDRUNCFG are
 *    reserved and only zeroes should be written to them.
 */
#define SYSCON_PDRUNCFGSET_PD_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PD_SET_SHIFT)) & SYSCON_PDRUNCFGSET_PD_SET_MASK)
/*! @} */

/*! @name PDRUNCFGCLR - Clear bits in PDRUNCFG */
/*! @{ */

#define SYSCON_PDRUNCFGCLR_PD_CLR_MASK           (0xFFFFFFFFU)
#define SYSCON_PDRUNCFGCLR_PD_CLR_SHIFT          (0U)
/*! PD_CLR - Writing ones to this register clears the corresponding bit or bits in the PDRUNCFG
 *    register, if they are implemented. Bits that do not correspond to defined bits in PDRUNCFG are
 *    reserved and only zeroes should be written to them.
 */
#define SYSCON_PDRUNCFGCLR_PD_CLR(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PD_CLR_SHIFT)) & SYSCON_PDRUNCFGCLR_PD_CLR_MASK)
/*! @} */

/*! @name STARTER - Start logic n wake-up enable register */
/*! @{ */

#define SYSCON_STARTER_GINT1_MASK                (0x1U)
#define SYSCON_STARTER_GINT1_SHIFT               (0U)
/*! GINT1 - Group interrupt 0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_GINT1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT1_SHIFT)) & SYSCON_STARTER_GINT1_MASK)

#define SYSCON_STARTER_WWDT_MASK                 (0x1U)
#define SYSCON_STARTER_WWDT_SHIFT                (0U)
/*! WWDT - WWDT interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_WWDT(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_WWDT_SHIFT)) & SYSCON_STARTER_WWDT_MASK)

#define SYSCON_STARTER_BOD_MASK                  (0x2U)
#define SYSCON_STARTER_BOD_SHIFT                 (1U)
/*! BOD - BOD interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_BOD(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_BOD_SHIFT)) & SYSCON_STARTER_BOD_MASK)

#define SYSCON_STARTER_PINT4_MASK                (0x2U)
#define SYSCON_STARTER_PINT4_SHIFT               (1U)
/*! PINT4 - GPIO pin interrupt 4 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT4(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT4_SHIFT)) & SYSCON_STARTER_PINT4_MASK)

#define SYSCON_STARTER_PINT5_MASK                (0x4U)
#define SYSCON_STARTER_PINT5_SHIFT               (2U)
/*! PINT5 - GPIO pin interrupt 5 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT5(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT5_SHIFT)) & SYSCON_STARTER_PINT5_MASK)

#define SYSCON_STARTER_DMA_MASK                  (0x8U)
#define SYSCON_STARTER_DMA_SHIFT                 (3U)
/*! DMA - DMA wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Typically used in sleep mode only. */
#define SYSCON_STARTER_DMA(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DMA_SHIFT)) & SYSCON_STARTER_DMA_MASK)

#define SYSCON_STARTER_PINT6_MASK                (0x8U)
#define SYSCON_STARTER_PINT6_SHIFT               (3U)
/*! PINT6 - GPIO pin interrupt 6 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT6(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT6_SHIFT)) & SYSCON_STARTER_PINT6_MASK)

#define SYSCON_STARTER_GINT0_MASK                (0x10U)
#define SYSCON_STARTER_GINT0_SHIFT               (4U)
/*! GINT0 - Group interrupt 0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_GINT0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT0_SHIFT)) & SYSCON_STARTER_GINT0_MASK)

#define SYSCON_STARTER_PINT7_MASK                (0x10U)
#define SYSCON_STARTER_PINT7_SHIFT               (4U)
/*! PINT7 - GPIO pin interrupt 7 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT7(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT7_SHIFT)) & SYSCON_STARTER_PINT7_MASK)

#define SYSCON_STARTER_PINT0_MASK                (0x20U)
#define SYSCON_STARTER_PINT0_SHIFT               (5U)
/*! PINT0 - GPIO pin interrupt 0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT0_SHIFT)) & SYSCON_STARTER_PINT0_MASK)

#define SYSCON_STARTER_PINT1_MASK                (0x40U)
#define SYSCON_STARTER_PINT1_SHIFT               (6U)
/*! PINT1 - GPIO pin interrupt 1 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT1_SHIFT)) & SYSCON_STARTER_PINT1_MASK)

#define SYSCON_STARTER_PINT2_MASK                (0x80U)
#define SYSCON_STARTER_PINT2_SHIFT               (7U)
/*! PINT2 - GPIO pin interrupt 2 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT2(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT2_SHIFT)) & SYSCON_STARTER_PINT2_MASK)

#define SYSCON_STARTER_PINT3_MASK                (0x100U)
#define SYSCON_STARTER_PINT3_SHIFT               (8U)
/*! PINT3 - GPIO pin interrupt 3 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PINT3(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT3_SHIFT)) & SYSCON_STARTER_PINT3_MASK)

#define SYSCON_STARTER_RIT_MASK                  (0x100U)
#define SYSCON_STARTER_RIT_SHIFT                 (8U)
/*! RIT - Repetitive Interrupt Timer interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.
 *    Typically used in sleep mode only.
 */
#define SYSCON_STARTER_RIT(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_RIT_SHIFT)) & SYSCON_STARTER_RIT_MASK)

#define SYSCON_STARTER_UTICK_MASK                (0x200U)
#define SYSCON_STARTER_UTICK_SHIFT               (9U)
/*! UTICK - Micro-tick Timer wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_UTICK(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_UTICK_SHIFT)) & SYSCON_STARTER_UTICK_MASK)

#define SYSCON_STARTER_MRT_MASK                  (0x400U)
#define SYSCON_STARTER_MRT_SHIFT                 (10U)
/*! MRT - Multi-Rate Timer wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Typically used in sleep mode only. */
#define SYSCON_STARTER_MRT(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_MRT_SHIFT)) & SYSCON_STARTER_MRT_MASK)

#define SYSCON_STARTER_CT32B0_MASK               (0x800U)
#define SYSCON_STARTER_CT32B0_SHIFT              (11U)
/*! CT32B0 - CT32B 0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_CT32B0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CT32B0_SHIFT)) & SYSCON_STARTER_CT32B0_MASK)

#define SYSCON_STARTER_CT32B1_MASK               (0x1000U)
#define SYSCON_STARTER_CT32B1_SHIFT              (12U)
/*! CT32B1 - CT32B 1 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_CT32B1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CT32B1_SHIFT)) & SYSCON_STARTER_CT32B1_MASK)

#define SYSCON_STARTER_CT32B2_MASK               (0x2000U)
#define SYSCON_STARTER_CT32B2_SHIFT              (13U)
/*! CT32B2 - CT32B 2 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_CT32B2(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CT32B2_SHIFT)) & SYSCON_STARTER_CT32B2_MASK)

#define SYSCON_STARTER_CT32B3_MASK               (0x4000U)
#define SYSCON_STARTER_CT32B3_SHIFT              (14U)
/*! CT32B3 - CT32B 3 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_CT32B3(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CT32B3_SHIFT)) & SYSCON_STARTER_CT32B3_MASK)

#define SYSCON_STARTER_CT32B4_MASK               (0x8000U)
#define SYSCON_STARTER_CT32B4_SHIFT              (15U)
/*! CT32B4 - CT32B 4 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_CT32B4(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CT32B4_SHIFT)) & SYSCON_STARTER_CT32B4_MASK)

#define SYSCON_STARTER_SCT0_MASK                 (0x10000U)
#define SYSCON_STARTER_SCT0_SHIFT                (16U)
/*! SCT0 - SCT0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_SCT0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SCT0_SHIFT)) & SYSCON_STARTER_SCT0_MASK)

#define SYSCON_STARTER_USART0_MASK               (0x20000U)
#define SYSCON_STARTER_USART0_SHIFT              (17U)
/*! USART0 - USART0 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_USART0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USART0_SHIFT)) & SYSCON_STARTER_USART0_MASK)

#define SYSCON_STARTER_USART1_MASK               (0x40000U)
#define SYSCON_STARTER_USART1_SHIFT              (18U)
/*! USART1 - USART1 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_USART1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USART1_SHIFT)) & SYSCON_STARTER_USART1_MASK)

#define SYSCON_STARTER_USART2_MASK               (0x80000U)
#define SYSCON_STARTER_USART2_SHIFT              (19U)
/*! USART2 - USART2 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_USART2(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USART2_SHIFT)) & SYSCON_STARTER_USART2_MASK)

#define SYSCON_STARTER_USART3_MASK               (0x100000U)
#define SYSCON_STARTER_USART3_SHIFT              (20U)
/*! USART3 - USART2 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_USART3(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USART3_SHIFT)) & SYSCON_STARTER_USART3_MASK)

#define SYSCON_STARTER_I2C0_MASK                 (0x200000U)
#define SYSCON_STARTER_I2C0_SHIFT                (21U)
/*! I2C0 - I2C0 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_I2C0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_I2C0_SHIFT)) & SYSCON_STARTER_I2C0_MASK)

#define SYSCON_STARTER_I2C1_MASK                 (0x400000U)
#define SYSCON_STARTER_I2C1_SHIFT                (22U)
/*! I2C1 - I2C1 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_I2C1(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_I2C1_SHIFT)) & SYSCON_STARTER_I2C1_MASK)

#define SYSCON_STARTER_I2C2_MASK                 (0x800000U)
#define SYSCON_STARTER_I2C2_SHIFT                (23U)
/*! I2C2 - I2C2 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_I2C2(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_I2C2_SHIFT)) & SYSCON_STARTER_I2C2_MASK)

#define SYSCON_STARTER_SPI0_MASK                 (0x1000000U)
#define SYSCON_STARTER_SPI0_SHIFT                (24U)
/*! SPI0 - SPI0 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_SPI0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SPI0_SHIFT)) & SYSCON_STARTER_SPI0_MASK)

#define SYSCON_STARTER_SPI1_MASK                 (0x2000000U)
#define SYSCON_STARTER_SPI1_SHIFT                (25U)
/*! SPI1 - SPI1 interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Peripheral interrupt. */
#define SYSCON_STARTER_SPI1(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SPI1_SHIFT)) & SYSCON_STARTER_SPI1_MASK)

#define SYSCON_STARTER_ADC0_SEQA_MASK            (0x4000000U)
#define SYSCON_STARTER_ADC0_SEQA_SHIFT           (26U)
/*! ADC0_SEQA - ADC0 sequence A interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_ADC0_SEQA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_SEQA_SHIFT)) & SYSCON_STARTER_ADC0_SEQA_MASK)

#define SYSCON_STARTER_ADC0_SEQB_MASK            (0x8000000U)
#define SYSCON_STARTER_ADC0_SEQB_SHIFT           (27U)
/*! ADC0_SEQB - ADC0 sequence B interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_ADC0_SEQB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_SEQB_SHIFT)) & SYSCON_STARTER_ADC0_SEQB_MASK)

#define SYSCON_STARTER_ADC0_THCMP_MASK           (0x10000000U)
#define SYSCON_STARTER_ADC0_THCMP_SHIFT          (28U)
/*! ADC0_THCMP - ADC0 threshold and error interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_ADC0_THCMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_THCMP_SHIFT)) & SYSCON_STARTER_ADC0_THCMP_MASK)

#define SYSCON_STARTER_RTC_MASK                  (0x20000000U)
#define SYSCON_STARTER_RTC_SHIFT                 (29U)
/*! RTC - RTC interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_RTC(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_RTC_SHIFT)) & SYSCON_STARTER_RTC_MASK)

#define SYSCON_STARTER_MAILBOX_MASK              (0x80000000U)
#define SYSCON_STARTER_MAILBOX_SHIFT             (31U)
/*! MAILBOX - Mailbox interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only. */
#define SYSCON_STARTER_MAILBOX(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_MAILBOX_SHIFT)) & SYSCON_STARTER_MAILBOX_MASK)
/*! @} */

/*! @name STARTERSET - Set bits in STARTERP n */
/*! @{ */

#define SYSCON_STARTERSET_START_SET_MASK         (0xFFFFFFFFU)
#define SYSCON_STARTERSET_START_SET_SHIFT        (0U)
/*! START_SET - Writing ones to this register sets the corresponding bit or bits in the STARTERP n
 *    register, if they are implemented. Bits that do not correspond to defined bits in STARTERP0 are
 *    reserved and only zeroes should be written to them.
 */
#define SYSCON_STARTERSET_START_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_START_SET_SHIFT)) & SYSCON_STARTERSET_START_SET_MASK)
/*! @} */

/*! @name STARTERCLR - Clear bits in STARTER n */
/*! @{ */

#define SYSCON_STARTERCLR_START_CLR_MASK         (0xFFFFFFFFU)
#define SYSCON_STARTERCLR_START_CLR_SHIFT        (0U)
/*! START_CLR - Writing ones to this register clears the corresponding bit or bits in the STARTERP n
 *    register, if they are implemented. Bits that do not correspond to defined bits in STARTERP0
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_STARTERCLR_START_CLR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_START_CLR_SHIFT)) & SYSCON_STARTERCLR_START_CLR_MASK)
/*! @} */

/*! @name CPUCTRL - CPU Control for multiple processors */
/*! @{ */

#define SYSCON_CPUCTRL_MASTERCPU_MASK            (0x1U)
#define SYSCON_CPUCTRL_MASTERCPU_SHIFT           (0U)
/*! MASTERCPU - Determines which CPU is considered the master. The master CPU cannot have its clock
 *    turned off via the related CMnCLKEN bit or be reset via the related CMxRSTEN in this register.
 *    The slave CPU wakes up briefly following device reset, then goes back to sleep until
 *    activated by the master CPU.
 *  0b0..M0+. Cortex-M0+ is the master CPU.
 *  0b1..M4. Cortex-M4 is the master CPU.
 */
#define SYSCON_CPUCTRL_MASTERCPU(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_MASTERCPU_SHIFT)) & SYSCON_CPUCTRL_MASTERCPU_MASK)

#define SYSCON_CPUCTRL_CM4CLKEN_MASK             (0x4U)
#define SYSCON_CPUCTRL_CM4CLKEN_SHIFT            (2U)
/*! CM4CLKEN - Cortex-M4 clock enable.
 *  0b0..Disabled. The Cortex-M4 clock is not enabled.
 *  0b1..Enabled. The Cortex-M4 clock is enabled.
 */
#define SYSCON_CPUCTRL_CM4CLKEN(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_CM4CLKEN_SHIFT)) & SYSCON_CPUCTRL_CM4CLKEN_MASK)

#define SYSCON_CPUCTRL_CM0CLKEN_MASK             (0x8U)
#define SYSCON_CPUCTRL_CM0CLKEN_SHIFT            (3U)
/*! CM0CLKEN - Cortex-M0+ clock enable.
 *  0b0..Disabled. The Cortex-M0+ clock is not enabled.
 *  0b1..Enabled. The Cortex-M0+ clock is enabled.
 */
#define SYSCON_CPUCTRL_CM0CLKEN(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_CM0CLKEN_SHIFT)) & SYSCON_CPUCTRL_CM0CLKEN_MASK)

#define SYSCON_CPUCTRL_CM4RSTEN_MASK             (0x10U)
#define SYSCON_CPUCTRL_CM4RSTEN_SHIFT            (4U)
/*! CM4RSTEN - Cortex-M4 reset.
 *  0b0..Disabled. The Cortex-M4 is not being reset.
 *  0b1..Enabled. The Cortex-M4 is being reset.
 */
#define SYSCON_CPUCTRL_CM4RSTEN(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_CM4RSTEN_SHIFT)) & SYSCON_CPUCTRL_CM4RSTEN_MASK)

#define SYSCON_CPUCTRL_CM0RSTEN_MASK             (0x20U)
#define SYSCON_CPUCTRL_CM0RSTEN_SHIFT            (5U)
/*! CM0RSTEN - Cortex-M0+ reset.
 *  0b0..Disabled. The Cortex-M0+ is not being reset.
 *  0b1..Enabled. The Cortex-M0+ is being reset.
 */
#define SYSCON_CPUCTRL_CM0RSTEN(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_CM0RSTEN_SHIFT)) & SYSCON_CPUCTRL_CM0RSTEN_MASK)

#define SYSCON_CPUCTRL_POWERCPU_MASK             (0x40U)
#define SYSCON_CPUCTRL_POWERCPU_SHIFT            (6U)
/*! POWERCPU - Identifies the owner of reduced power mode control: which CPU can cause the device to
 *    enter Sleep, Deep Sleep, Power-down, and Deep Power-down modes.
 *  0b0..M0+. Cortex-M0+ is the owner of reduced power mode control.
 *  0b1..M4. Cortex-M4 is the owner of reduced power mode control.
 */
#define SYSCON_CPUCTRL_POWERCPU(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUCTRL_POWERCPU_SHIFT)) & SYSCON_CPUCTRL_POWERCPU_MASK)
/*! @} */

/*! @name CPBOOT - Coprocessor Boot Address */
/*! @{ */

#define SYSCON_CPBOOT_BOOTADDR_MASK              (0xFFFFFFFFU)
#define SYSCON_CPBOOT_BOOTADDR_SHIFT             (0U)
/*! BOOTADDR - Slave processor boot address. */
#define SYSCON_CPBOOT_BOOTADDR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CPBOOT_BOOTADDR_SHIFT)) & SYSCON_CPBOOT_BOOTADDR_MASK)
/*! @} */

/*! @name CPSTACK - Coprocessor Stack Address */
/*! @{ */

#define SYSCON_CPSTACK_STACKADDR_MASK            (0xFFFFFFFFU)
#define SYSCON_CPSTACK_STACKADDR_SHIFT           (0U)
/*! STACKADDR - Slave processor stack address. */
#define SYSCON_CPSTACK_STACKADDR(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTACK_STACKADDR_SHIFT)) & SYSCON_CPSTACK_STACKADDR_MASK)
/*! @} */

/*! @name CPSTAT - Coprocessor Status */
/*! @{ */

#define SYSCON_CPSTAT_CM4SLEEPING_MASK           (0x1U)
#define SYSCON_CPSTAT_CM4SLEEPING_SHIFT          (0U)
/*! CM4SLEEPING - When 1, the Cortex-M4 CPU is sleeping. */
#define SYSCON_CPSTAT_CM4SLEEPING(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTAT_CM4SLEEPING_SHIFT)) & SYSCON_CPSTAT_CM4SLEEPING_MASK)

#define SYSCON_CPSTAT_CM0SLEEPING_MASK           (0x2U)
#define SYSCON_CPSTAT_CM0SLEEPING_SHIFT          (1U)
/*! CM0SLEEPING - When 1, the Cortex-M0+ CPU is sleeping. */
#define SYSCON_CPSTAT_CM0SLEEPING(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTAT_CM0SLEEPING_SHIFT)) & SYSCON_CPSTAT_CM0SLEEPING_MASK)

#define SYSCON_CPSTAT_CM4LOCKUP_MASK             (0x4U)
#define SYSCON_CPSTAT_CM4LOCKUP_SHIFT            (2U)
/*! CM4LOCKUP - When 1, the Cortex-M4 CPU is in lockup. */
#define SYSCON_CPSTAT_CM4LOCKUP(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTAT_CM4LOCKUP_SHIFT)) & SYSCON_CPSTAT_CM4LOCKUP_MASK)

#define SYSCON_CPSTAT_CM0LOCKUP_MASK             (0x8U)
#define SYSCON_CPSTAT_CM0LOCKUP_SHIFT            (3U)
/*! CM0LOCKUP - When 1, the Cortex-M0+ CPU is in lockup. */
#define SYSCON_CPSTAT_CM0LOCKUP(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTAT_CM0LOCKUP_SHIFT)) & SYSCON_CPSTAT_CM0LOCKUP_MASK)
/*! @} */

/*! @name JTAGIDCODE - JTAG ID code register */
/*! @{ */

#define SYSCON_JTAGIDCODE_JTAGID_MASK            (0xFFFFFFFFU)
#define SYSCON_JTAGIDCODE_JTAGID_SHIFT           (0U)
/*! JTAGID - JTAG ID code. */
#define SYSCON_JTAGIDCODE_JTAGID(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAGIDCODE_JTAGID_SHIFT)) & SYSCON_JTAGIDCODE_JTAGID_MASK)
/*! @} */

/*! @name DEVICE_ID - Part ID register */
/*! @{ */

#define SYSCON_DEVICE_ID_PARTID_MASK             (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_PARTID_SHIFT            (0U)
/*! PARTID - Part ID */
#define SYSCON_DEVICE_ID_PARTID(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID_PARTID_SHIFT)) & SYSCON_DEVICE_ID_PARTID_MASK)

#define SYSCON_DEVICE_ID_REVID_MASK              (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID_REVID_SHIFT             (0U)
/*! REVID - Revision. */
#define SYSCON_DEVICE_ID_REVID(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID_REVID_SHIFT)) & SYSCON_DEVICE_ID_REVID_MASK)
/*! @} */

/*! @name BODCTRL - Brown-Out Detect control */
/*! @{ */

#define SYSCON_BODCTRL_BODRSTLEV_MASK            (0x3U)
#define SYSCON_BODCTRL_BODRSTLEV_SHIFT           (0U)
/*! BODRSTLEV - BOD reset level
 *  0b00..Level 0: 1.5 V
 *  0b01..Level 1: 1.85 V
 *  0b10..Level 2: 2.0 V
 *  0b11..Level 3: 2.3 V
 */
#define SYSCON_BODCTRL_BODRSTLEV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTLEV_SHIFT)) & SYSCON_BODCTRL_BODRSTLEV_MASK)

#define SYSCON_BODCTRL_BODRSTENA_MASK            (0x4U)
#define SYSCON_BODCTRL_BODRSTENA_SHIFT           (2U)
/*! BODRSTENA - BOD reset enable
 *  0b0..Disable reset function.
 *  0b1..Enable reset function.
 */
#define SYSCON_BODCTRL_BODRSTENA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTENA_SHIFT)) & SYSCON_BODCTRL_BODRSTENA_MASK)

#define SYSCON_BODCTRL_BODINTLEV_MASK            (0x18U)
#define SYSCON_BODCTRL_BODINTLEV_SHIFT           (3U)
/*! BODINTLEV - BOD interrupt level
 *  0b00..Level 0: 2.05 V
 *  0b01..Level 1: 2.45 V
 *  0b10..Level 2: 2.75 V
 *  0b11..Level 3: 3.05 V
 */
#define SYSCON_BODCTRL_BODINTLEV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODINTLEV_SHIFT)) & SYSCON_BODCTRL_BODINTLEV_MASK)

#define SYSCON_BODCTRL_BODINTENA_MASK            (0x20U)
#define SYSCON_BODCTRL_BODINTENA_SHIFT           (5U)
/*! BODINTENA - BOD interrupt enable
 *  0b0..Disable interrupt function.
 *  0b1..Enable reset function.
 */
#define SYSCON_BODCTRL_BODINTENA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODINTENA_SHIFT)) & SYSCON_BODCTRL_BODINTENA_MASK)

#define SYSCON_BODCTRL_BODRSTSTAT_MASK           (0x40U)
#define SYSCON_BODCTRL_BODRSTSTAT_SHIFT          (6U)
/*! BODRSTSTAT - BOD reset status */
#define SYSCON_BODCTRL_BODRSTSTAT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTSTAT_SHIFT)) & SYSCON_BODCTRL_BODRSTSTAT_MASK)

#define SYSCON_BODCTRL_BODINTSTAT_MASK           (0x80U)
#define SYSCON_BODCTRL_BODINTSTAT_SHIFT          (7U)
/*! BODINTSTAT - BOD interrupt status */
#define SYSCON_BODCTRL_BODINTSTAT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODINTSTAT_SHIFT)) & SYSCON_BODCTRL_BODINTSTAT_MASK)
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* SYSCON_H_ */

