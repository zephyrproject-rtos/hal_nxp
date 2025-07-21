/*
** ###################################################################
**     Processors:          LPC51U68JBD48
**                          LPC51U68JBD64
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2017-12-15)
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

#if (defined(CPU_LPC51U68JBD48) || defined(CPU_LPC51U68JBD64))
#include "LPC51U68_COMMON.h"
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
#define SYSCON_PIOPORCAP_COUNT                    2u
#define SYSCON_PIORESCAP_COUNT                    2u
#define SYSCON_PRESETCTRL_COUNT                   2u
#define SYSCON_PRESETCTRLSET_COUNT                2u
#define SYSCON_PRESETCTRLCLR_COUNT                2u
#define SYSCON_AHBCLKCTRL_COUNT                   2u
#define SYSCON_AHBCLKCTRLSET_COUNT                2u
#define SYSCON_AHBCLKCTRLCLR_COUNT                2u
#define SYSCON_FXCOMCLKSEL_COUNT                  8u
#define SYSCON_PDSLEEPCFG_COUNT                   2u
#define SYSCON_PDRUNCFG_COUNT                     1u
#define SYSCON_PDRUNCFGSET_COUNT                  1u
#define SYSCON_PDRUNCFGCLR_COUNT                  1u
#define SYSCON_STARTER_COUNT                      1u
#define SYSCON_STARTERSET_COUNT                   1u
#define SYSCON_STARTERCLR_COUNT                   1u

/** SYSCON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t AHBMATPRIO;                        /**< AHB multilayer matrix priority control, offset: 0x10 */
       uint8_t RESERVED_1[44];
  __IO uint32_t SYSTCKCAL;                         /**< System tick counter calibration, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
  __IO uint32_t ASYNCAPBCTRL;                      /**< Asynchronous APB Control, offset: 0x4C */
       uint8_t RESERVED_3[112];
  __I  uint32_t PIOPORCAP[SYSCON_PIOPORCAP_COUNT]; /**< POR captured value of port n, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[8];
  __I  uint32_t PIORESCAP[SYSCON_PIORESCAP_COUNT]; /**< Reset captured value of port n, array offset: 0xD0, array step: 0x4 */
       uint8_t RESERVED_5[40];
  __IO uint32_t PRESETCTRL[SYSCON_PRESETCTRL_COUNT]; /**< Peripheral reset control n, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_6[24];
  __O  uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Set bits in PRESETCTRLn, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_7[24];
  __O  uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Clear bits in PRESETCTRLn, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_8[168];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register, offset: 0x1F0 */
       uint8_t RESERVED_9[12];
  __IO uint32_t AHBCLKCTRL[SYSCON_AHBCLKCTRL_COUNT]; /**< AHB Clock control n, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_10[24];
  __O  uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< Set bits in AHBCLKCTRLn, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_11[24];
  __O  uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< Clear bits in AHBCLKCTRLn, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_12[56];
  __IO uint32_t MAINCLKSELA;                       /**< Main clock source select A, offset: 0x280 */
  __IO uint32_t MAINCLKSELB;                       /**< Main clock source select B, offset: 0x284 */
  __IO uint32_t CLKOUTSELA;                        /**< CLKOUT clock source select A, offset: 0x288 */
       uint8_t RESERVED_13[4];
  __IO uint32_t SYSPLLCLKSEL;                      /**< PLL clock source select, offset: 0x290 */
       uint8_t RESERVED_14[16];
  __IO uint32_t ADCCLKSEL;                         /**< ADC clock source select, offset: 0x2A4 */
  __IO uint32_t USBCLKSEL;                         /**< USB clock source select, offset: 0x2A8 */
       uint8_t RESERVED_15[4];
  __IO uint32_t FXCOMCLKSEL[SYSCON_FXCOMCLKSEL_COUNT]; /**< Flexcomm0 clock source select..Flexcomm7 clock source select, array offset: 0x2B0, array step: 0x4 */
       uint8_t RESERVED_16[16];
  __IO uint32_t MCLKCLKSEL;                        /**< MCLK clock source select, offset: 0x2E0 */
       uint8_t RESERVED_17[4];
  __IO uint32_t FRGCLKSEL;                         /**< Fractional Rate Generator clock source select, offset: 0x2E8 */
       uint8_t RESERVED_18[20];
  __IO uint32_t SYSTICKCLKDIV;                     /**< SYSTICK clock divider, offset: 0x300 */
       uint8_t RESERVED_19[124];
  __IO uint32_t AHBCLKDIV;                         /**< AHB clock divider, offset: 0x380 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider, offset: 0x384 */
       uint8_t RESERVED_20[12];
  __IO uint32_t ADCCLKDIV;                         /**< ADC clock divider, offset: 0x394 */
  __IO uint32_t USBCLKDIV;                         /**< USB clock divider, offset: 0x398 */
       uint8_t RESERVED_21[4];
  __IO uint32_t FRGCTRL;                           /**< Fractional rate divider, offset: 0x3A0 */
       uint8_t RESERVED_22[8];
  __IO uint32_t MCLKDIV;                           /**< I2S MCLK clock divider, offset: 0x3AC */
       uint8_t RESERVED_23[80];
  __IO uint32_t FLASHCFG;                          /**< Flash wait states configuration, offset: 0x400 */
       uint8_t RESERVED_24[8];
  __IO uint32_t USBCLKCTRL;                        /**< USB clock control, offset: 0x40C */
  __IO uint32_t USBCLKSTAT;                        /**< USB clock status, offset: 0x410 */
       uint8_t RESERVED_25[4];
  __IO uint32_t FREQMECTRL;                        /**< Frequency measure register, offset: 0x418 */
       uint8_t RESERVED_26[4];
  __IO uint32_t MCLKIO;                            /**< MCLK input/output control, offset: 0x420 */
       uint8_t RESERVED_27[220];
  __IO uint32_t FROCTRL;                           /**< FRO oscillator control, offset: 0x500 */
       uint8_t RESERVED_28[4];
  __IO uint32_t WDTOSCCTRL;                        /**< Watchdog oscillator control, offset: 0x508 */
  __IO uint32_t RTCOSCCTRL;                        /**< RTC oscillator 32 kHz output control, offset: 0x50C */
       uint8_t RESERVED_29[112];
  __IO uint32_t SYSPLLCTRL;                        /**< PLL control, offset: 0x580 */
  __I  uint32_t SYSPLLSTAT;                        /**< PLL status, offset: 0x584 */
  __IO uint32_t SYSPLLNDEC;                        /**< PLL N decoder, offset: 0x588 */
  __IO uint32_t SYSPLLPDEC;                        /**< PLL P decoder, offset: 0x58C */
  __IO uint32_t SYSPLLSSCTRL0;                     /**< PLL spread spectrum control 0, offset: 0x590 */
  __IO uint32_t SYSPLLSSCTRL1;                     /**< PLL spread spectrum control 1, offset: 0x594 */
       uint8_t RESERVED_30[104];
  __IO uint32_t PDSLEEPCFG[SYSCON_PDSLEEPCFG_COUNT]; /**< Sleep configuration register n, array offset: 0x600, array step: 0x4 */
       uint8_t RESERVED_31[8];
  __IO uint32_t PDRUNCFG[SYSCON_PDRUNCFG_COUNT];   /**< Power configuration register 0, array offset: 0x610, array step: 0x4 */
       uint8_t RESERVED_32[12];
  __O  uint32_t PDRUNCFGSET[SYSCON_PDRUNCFGSET_COUNT]; /**< Set bits in PDRUNCFGn, array offset: 0x620, array step: 0x4 */
       uint8_t RESERVED_33[12];
  __O  uint32_t PDRUNCFGCLR[SYSCON_PDRUNCFGCLR_COUNT]; /**< Clear bits in PDRUNCFGn, array offset: 0x630, array step: 0x4 */
       uint8_t RESERVED_34[76];
  __IO uint32_t STARTER[SYSCON_STARTER_COUNT];     /**< Start logic n wake-up enable register, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_35[28];
  __O  uint32_t STARTERSET[SYSCON_STARTERSET_COUNT]; /**< Set bits in STARTERn, array offset: 0x6A0, array step: 0x4 */
       uint8_t RESERVED_36[28];
  __O  uint32_t STARTERCLR[SYSCON_STARTERCLR_COUNT]; /**< Clear bits in STARTERn, array offset: 0x6C0, array step: 0x4 */
       uint8_t RESERVED_37[188];
  __IO uint32_t HWWAKE;                            /**< Configures special cases of hardware wake-up, offset: 0x780 */
       uint8_t RESERVED_38[2160];
  __I  uint32_t JTAGIDCODE;                        /**< JTAG ID code register, offset: 0xFF4 */
  __I  uint32_t DEVICE_ID0;                        /**< Part ID register, offset: 0xFF8 */
  __I  uint32_t DEVICE_ID1;                        /**< Boot ROM and die revision register, offset: 0xFFC */
       uint8_t RESERVED_39[127044];
  __IO uint32_t BODCTRL;                           /**< Brown-Out Detect control, offset: 0x20044 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name AHBMATPRIO - AHB multilayer matrix priority control */
/*! @{ */

#define SYSCON_AHBMATPRIO_PRI_ICODE_MASK         (0x3U)
#define SYSCON_AHBMATPRIO_PRI_ICODE_SHIFT        (0U)
/*! PRI_ICODE - Cortex-M4 I-Code bus priority. Should typically be lower than PRI_DCODE for best operation. */
#define SYSCON_AHBMATPRIO_PRI_ICODE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_ICODE_SHIFT)) & SYSCON_AHBMATPRIO_PRI_ICODE_MASK)

#define SYSCON_AHBMATPRIO_PRI_DCODE_MASK         (0xCU)
#define SYSCON_AHBMATPRIO_PRI_DCODE_SHIFT        (2U)
/*! PRI_DCODE - Cortex M4 D-Code bus priority. */
#define SYSCON_AHBMATPRIO_PRI_DCODE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_DCODE_SHIFT)) & SYSCON_AHBMATPRIO_PRI_DCODE_MASK)

#define SYSCON_AHBMATPRIO_PRI_SYS_MASK           (0x30U)
#define SYSCON_AHBMATPRIO_PRI_SYS_SHIFT          (4U)
/*! PRI_SYS - Cortex M4 System bus priority. */
#define SYSCON_AHBMATPRIO_PRI_SYS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SYS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SYS_MASK)

#define SYSCON_AHBMATPRIO_PRI_M0_MASK            (0xC0U)
#define SYSCON_AHBMATPRIO_PRI_M0_SHIFT           (6U)
/*! PRI_M0 - Cortex-M0+ bus priority. Present on selected devices. */
#define SYSCON_AHBMATPRIO_PRI_M0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_M0_SHIFT)) & SYSCON_AHBMATPRIO_PRI_M0_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB_MASK           (0x300U)
#define SYSCON_AHBMATPRIO_PRI_USB_SHIFT          (8U)
/*! PRI_USB - USB interface priority. */
#define SYSCON_AHBMATPRIO_PRI_USB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB_MASK)

#define SYSCON_AHBMATPRIO_PRI_DMA_MASK           (0xC00U)
#define SYSCON_AHBMATPRIO_PRI_DMA_SHIFT          (10U)
/*! PRI_DMA - DMA controller priority. */
#define SYSCON_AHBMATPRIO_PRI_DMA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_DMA_SHIFT)) & SYSCON_AHBMATPRIO_PRI_DMA_MASK)
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
/*! IRQM0 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for the
 *    Cortex-M0+, if enabled by NMIENM0. Present on selected devices.
 */
#define SYSCON_NMISRC_IRQM0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQM0_SHIFT)) & SYSCON_NMISRC_IRQM0_MASK)

#define SYSCON_NMISRC_NMIENM0_MASK               (0x40000000U)
#define SYSCON_NMISRC_NMIENM0_SHIFT              (30U)
/*! NMIENM0 - Write a 1 to this bit to enable the Non-Maskable Interrupt (NMI) source selected by IRQM0. Present on selected devices. */
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

/*! @name PIOPORCAP - POR captured value of port n */
/*! @{ */

#define SYSCON_PIOPORCAP_PIOPORCAP_MASK          (0xFFFFFFFFU)
#define SYSCON_PIOPORCAP_PIOPORCAP_SHIFT         (0U)
/*! PIOPORCAP - State of PIOn_31 through PIOn_0 at power-on reset */
#define SYSCON_PIOPORCAP_PIOPORCAP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PIOPORCAP_PIOPORCAP_SHIFT)) & SYSCON_PIOPORCAP_PIOPORCAP_MASK)
/*! @} */

/*! @name PIORESCAP - Reset captured value of port n */
/*! @{ */

#define SYSCON_PIORESCAP_PIORESCAP_MASK          (0xFFFFFFFFU)
#define SYSCON_PIORESCAP_PIORESCAP_SHIFT         (0U)
/*! PIORESCAP - State of PIOn_31 through PIOn_0 for resets other than POR. */
#define SYSCON_PIORESCAP_PIORESCAP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PIORESCAP_PIORESCAP_SHIFT)) & SYSCON_PIORESCAP_PIORESCAP_MASK)
/*! @} */

/*! @name PRESETCTRL - Peripheral reset control n */
/*! @{ */

#define SYSCON_PRESETCTRL_MRT0_RST_MASK          (0x1U)
#define SYSCON_PRESETCTRL_MRT0_RST_SHIFT         (0U)
/*! MRT0_RST - Multi-rate timer (MRT0) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_MRT0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MRT0_RST_SHIFT)) & SYSCON_PRESETCTRL_MRT0_RST_MASK)

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
/*! FMC_RST - Flash accelerator reset control. Note that the FMC must not be reset while executing
 *    from flash, and must be reconfigured after reset. 0 = Clear reset to this function. 1 = Assert
 *    reset to this function.
 */
#define SYSCON_PRESETCTRL_FMC_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FMC_RST_SHIFT)) & SYSCON_PRESETCTRL_FMC_RST_MASK)

#define SYSCON_PRESETCTRL_UTICK0_RST_MASK        (0x400U)
#define SYSCON_PRESETCTRL_UTICK0_RST_SHIFT       (10U)
/*! UTICK0_RST - Micro-tick Timer reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_UTICK0_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UTICK0_RST_SHIFT)) & SYSCON_PRESETCTRL_UTICK0_RST_MASK)

#define SYSCON_PRESETCTRL_FC0_RST_MASK           (0x800U)
#define SYSCON_PRESETCTRL_FC0_RST_SHIFT          (11U)
/*! FC0_RST - Flexcomm 0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC0_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC0_RST_SHIFT)) & SYSCON_PRESETCTRL_FC0_RST_MASK)

#define SYSCON_PRESETCTRL_MUX_RST_MASK           (0x800U)
#define SYSCON_PRESETCTRL_MUX_RST_SHIFT          (11U)
/*! MUX_RST - Input mux reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_MUX_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MUX_RST_SHIFT)) & SYSCON_PRESETCTRL_MUX_RST_MASK)

#define SYSCON_PRESETCTRL_FC1_RST_MASK           (0x1000U)
#define SYSCON_PRESETCTRL_FC1_RST_SHIFT          (12U)
/*! FC1_RST - Flexcomm 1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC1_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC1_RST_SHIFT)) & SYSCON_PRESETCTRL_FC1_RST_MASK)

#define SYSCON_PRESETCTRL_FC2_RST_MASK           (0x2000U)
#define SYSCON_PRESETCTRL_FC2_RST_SHIFT          (13U)
/*! FC2_RST - Flexcomm 2 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC2_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC2_RST_SHIFT)) & SYSCON_PRESETCTRL_FC2_RST_MASK)

#define SYSCON_PRESETCTRL_IOCON_RST_MASK         (0x2000U)
#define SYSCON_PRESETCTRL_IOCON_RST_SHIFT        (13U)
/*! IOCON_RST - IOCON reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_IOCON_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_IOCON_RST_SHIFT)) & SYSCON_PRESETCTRL_IOCON_RST_MASK)

#define SYSCON_PRESETCTRL_FC3_RST_MASK           (0x4000U)
#define SYSCON_PRESETCTRL_FC3_RST_SHIFT          (14U)
/*! FC3_RST - Flexcomm 3 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC3_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC3_RST_SHIFT)) & SYSCON_PRESETCTRL_FC3_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO0_RST_MASK         (0x4000U)
#define SYSCON_PRESETCTRL_GPIO0_RST_SHIFT        (14U)
/*! GPIO0_RST - GPIO0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GPIO0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO0_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO0_RST_MASK)

#define SYSCON_PRESETCTRL_FC4_RST_MASK           (0x8000U)
#define SYSCON_PRESETCTRL_FC4_RST_SHIFT          (15U)
/*! FC4_RST - Flexcomm 4 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC4_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC4_RST_SHIFT)) & SYSCON_PRESETCTRL_FC4_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO1_RST_MASK         (0x8000U)
#define SYSCON_PRESETCTRL_GPIO1_RST_SHIFT        (15U)
/*! GPIO1_RST - GPIO1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GPIO1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO1_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO1_RST_MASK)

#define SYSCON_PRESETCTRL_FC5_RST_MASK           (0x10000U)
#define SYSCON_PRESETCTRL_FC5_RST_SHIFT          (16U)
/*! FC5_RST - Flexcomm 5 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC5_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC5_RST_SHIFT)) & SYSCON_PRESETCTRL_FC5_RST_MASK)

#define SYSCON_PRESETCTRL_FC6_RST_MASK           (0x20000U)
#define SYSCON_PRESETCTRL_FC6_RST_SHIFT          (17U)
/*! FC6_RST - Flexcomm 6 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC6_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC6_RST_SHIFT)) & SYSCON_PRESETCTRL_FC6_RST_MASK)

#define SYSCON_PRESETCTRL_FC7_RST_MASK           (0x40000U)
#define SYSCON_PRESETCTRL_FC7_RST_SHIFT          (18U)
/*! FC7_RST - Flexcomm 7 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC7_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC7_RST_SHIFT)) & SYSCON_PRESETCTRL_FC7_RST_MASK)

#define SYSCON_PRESETCTRL_PINT_RST_MASK          (0x40000U)
#define SYSCON_PRESETCTRL_PINT_RST_SHIFT         (18U)
/*! PINT_RST - Pin interrupt (PINT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_PINT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_PINT_RST_SHIFT)) & SYSCON_PRESETCTRL_PINT_RST_MASK)

#define SYSCON_PRESETCTRL_GINT_RST_MASK          (0x80000U)
#define SYSCON_PRESETCTRL_GINT_RST_SHIFT         (19U)
/*! GINT_RST - Grouped interrupt (GINT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GINT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GINT_RST_SHIFT)) & SYSCON_PRESETCTRL_GINT_RST_MASK)

#define SYSCON_PRESETCTRL_DMA0_RST_MASK          (0x100000U)
#define SYSCON_PRESETCTRL_DMA0_RST_SHIFT         (20U)
/*! DMA0_RST - DMA0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_DMA0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_DMA0_RST_SHIFT)) & SYSCON_PRESETCTRL_DMA0_RST_MASK)

#define SYSCON_PRESETCTRL_CRC_RST_MASK           (0x200000U)
#define SYSCON_PRESETCTRL_CRC_RST_SHIFT          (21U)
/*! CRC_RST - CRC generator reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CRC_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CRC_RST_SHIFT)) & SYSCON_PRESETCTRL_CRC_RST_MASK)

#define SYSCON_PRESETCTRL_WWDT_RST_MASK          (0x400000U)
#define SYSCON_PRESETCTRL_WWDT_RST_SHIFT         (22U)
/*! WWDT_RST - Watchdog timer reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_WWDT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_WWDT_RST_SHIFT)) & SYSCON_PRESETCTRL_WWDT_RST_MASK)

#define SYSCON_PRESETCTRL_USB0_RST_MASK          (0x2000000U)
#define SYSCON_PRESETCTRL_USB0_RST_SHIFT         (25U)
/*! USB0_RST - USB0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_USB0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB0_RST_SHIFT)) & SYSCON_PRESETCTRL_USB0_RST_MASK)

#define SYSCON_PRESETCTRL_CTIMER0_RST_MASK       (0x4000000U)
#define SYSCON_PRESETCTRL_CTIMER0_RST_SHIFT      (26U)
/*! CTIMER0_RST - CTIMER0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CTIMER0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CTIMER0_RST_SHIFT)) & SYSCON_PRESETCTRL_CTIMER0_RST_MASK)

#define SYSCON_PRESETCTRL_ADC0_RST_MASK          (0x8000000U)
#define SYSCON_PRESETCTRL_ADC0_RST_SHIFT         (27U)
/*! ADC0_RST - ADC0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_ADC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_ADC0_RST_SHIFT)) & SYSCON_PRESETCTRL_ADC0_RST_MASK)

#define SYSCON_PRESETCTRL_CTIMER1_RST_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL_CTIMER1_RST_SHIFT      (27U)
/*! CTIMER1_RST - CTIMER1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CTIMER1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CTIMER1_RST_SHIFT)) & SYSCON_PRESETCTRL_CTIMER1_RST_MASK)
/*! @} */

/*! @name PRESETCTRLSET - Set bits in PRESETCTRLn */
/*! @{ */

#define SYSCON_PRESETCTRLSET_RST_SET_MASK        (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLSET_RST_SET_SHIFT       (0U)
/*! RST_SET - Writing ones to this register sets the corresponding bit or bits in the PRESETCTRLn
 *    register, if they are implemented. Bits that do not correspond to defined bits in PRESETCTRLn
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_PRESETCTRLSET_RST_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_RST_SET_SHIFT)) & SYSCON_PRESETCTRLSET_RST_SET_MASK)
/*! @} */

/*! @name PRESETCTRLCLR - Clear bits in PRESETCTRLn */
/*! @{ */

#define SYSCON_PRESETCTRLCLR_RST_CLR_MASK        (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLCLR_RST_CLR_SHIFT       (0U)
/*! RST_CLR - Writing ones to this register clears the corresponding bit or bits in the PRESETCTRLn
 *    register, if they are implemented. Bits that do not correspond to defined bits in PRESETCTRLn
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_PRESETCTRLCLR_RST_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_RST_CLR_SHIFT)) & SYSCON_PRESETCTRLCLR_RST_CLR_MASK)
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
/*! EXTRST - Status of the external RESET pin. External reset status
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

/*! @name AHBCLKCTRL - AHB Clock control n */
/*! @{ */

#define SYSCON_AHBCLKCTRL_MRT0_MASK              (0x1U)
#define SYSCON_AHBCLKCTRL_MRT0_SHIFT             (0U)
/*! MRT0 - Enables the clock for the Multi-Rate Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_MRT0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_MRT0_SHIFT)) & SYSCON_AHBCLKCTRL_MRT0_MASK)

#define SYSCON_AHBCLKCTRL_ROM_MASK               (0x2U)
#define SYSCON_AHBCLKCTRL_ROM_SHIFT              (1U)
/*! ROM - Enables the clock for the Boot ROM. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_ROM(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_ROM_SHIFT)) & SYSCON_AHBCLKCTRL_ROM_MASK)

#define SYSCON_AHBCLKCTRL_SCT0_MASK              (0x4U)
#define SYSCON_AHBCLKCTRL_SCT0_SHIFT             (2U)
/*! SCT0 - Enables the clock for SCT0. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SCT0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SCT0_SHIFT)) & SYSCON_AHBCLKCTRL_SCT0_MASK)

#define SYSCON_AHBCLKCTRL_FLASH_MASK             (0x80U)
#define SYSCON_AHBCLKCTRL_FLASH_SHIFT            (7U)
/*! FLASH - Enables the clock for the flash controller. 0 = Disable; 1 = Enable. This clock is
 *    needed for flash programming, not for flash read.
 */
#define SYSCON_AHBCLKCTRL_FLASH(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLASH_SHIFT)) & SYSCON_AHBCLKCTRL_FLASH_MASK)

#define SYSCON_AHBCLKCTRL_FMC_MASK               (0x100U)
#define SYSCON_AHBCLKCTRL_FMC_SHIFT              (8U)
/*! FMC - Enables the clock for the Flash accelerator. 0 = Disable; 1 = Enable. This clock is needed if the flash is being read. */
#define SYSCON_AHBCLKCTRL_FMC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FMC_SHIFT)) & SYSCON_AHBCLKCTRL_FMC_MASK)

#define SYSCON_AHBCLKCTRL_UTICK0_MASK            (0x400U)
#define SYSCON_AHBCLKCTRL_UTICK0_SHIFT           (10U)
/*! UTICK0 - Enables the clock for the Micro-tick Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_UTICK0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_UTICK0_SHIFT)) & SYSCON_AHBCLKCTRL_UTICK0_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM0_MASK         (0x800U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM0_SHIFT        (11U)
/*! FLEXCOMM0 - Enables the clock for Flexcomm 0. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM0_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM0_MASK)

#define SYSCON_AHBCLKCTRL_INPUTMUX_MASK          (0x800U)
#define SYSCON_AHBCLKCTRL_INPUTMUX_SHIFT         (11U)
/*! INPUTMUX - Enables the clock for the input muxes. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_INPUTMUX(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_INPUTMUX_SHIFT)) & SYSCON_AHBCLKCTRL_INPUTMUX_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM1_MASK         (0x1000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM1_SHIFT        (12U)
/*! FLEXCOMM1 - Enables the clock for Flexcomm 1. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM1_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM1_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM2_MASK         (0x2000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM2_SHIFT        (13U)
/*! FLEXCOMM2 - Enables the clock for Flexcomm 2. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM2(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM2_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM2_MASK)

#define SYSCON_AHBCLKCTRL_IOCON_MASK             (0x2000U)
#define SYSCON_AHBCLKCTRL_IOCON_SHIFT            (13U)
/*! IOCON - Enables the clock for the IOCON block. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_IOCON(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_IOCON_SHIFT)) & SYSCON_AHBCLKCTRL_IOCON_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM3_MASK         (0x4000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM3_SHIFT        (14U)
/*! FLEXCOMM3 - Enables the clock for Flexcomm 3. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM3(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM3_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM3_MASK)

#define SYSCON_AHBCLKCTRL_GPIO0_MASK             (0x4000U)
#define SYSCON_AHBCLKCTRL_GPIO0_SHIFT            (14U)
/*! GPIO0 - Enables the clock for the GPIO0 port registers. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GPIO0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO0_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO0_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM4_MASK         (0x8000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM4_SHIFT        (15U)
/*! FLEXCOMM4 - Enables the clock for Flexcomm 4. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM4(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM4_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM4_MASK)

#define SYSCON_AHBCLKCTRL_GPIO1_MASK             (0x8000U)
#define SYSCON_AHBCLKCTRL_GPIO1_SHIFT            (15U)
/*! GPIO1 - Enables the clock for the GPIO1 port registers. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GPIO1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO1_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO1_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM5_MASK         (0x10000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM5_SHIFT        (16U)
/*! FLEXCOMM5 - Enables the clock for Flexcomm 5. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM5(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM5_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM5_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM6_MASK         (0x20000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM6_SHIFT        (17U)
/*! FLEXCOMM6 - Enables the clock for Flexcomm 6. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM6(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM6_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM6_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM7_MASK         (0x40000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM7_SHIFT        (18U)
/*! FLEXCOMM7 - Enables the clock for Flexcomm 7. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM7(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM7_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM7_MASK)

#define SYSCON_AHBCLKCTRL_PINT_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL_PINT_SHIFT             (18U)
/*! PINT - Enables the clock for the pin interrupt block.0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_PINT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_PINT_SHIFT)) & SYSCON_AHBCLKCTRL_PINT_MASK)

#define SYSCON_AHBCLKCTRL_GINT_MASK              (0x80000U)
#define SYSCON_AHBCLKCTRL_GINT_SHIFT             (19U)
/*! GINT - Enables the clock for the grouped pin interrupt block. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GINT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GINT_SHIFT)) & SYSCON_AHBCLKCTRL_GINT_MASK)

#define SYSCON_AHBCLKCTRL_DMA0_MASK              (0x100000U)
#define SYSCON_AHBCLKCTRL_DMA0_SHIFT             (20U)
/*! DMA0 - Enables the clock for the DMA0 controller. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_DMA0_SHIFT)) & SYSCON_AHBCLKCTRL_DMA0_MASK)

#define SYSCON_AHBCLKCTRL_CRC_MASK               (0x200000U)
#define SYSCON_AHBCLKCTRL_CRC_SHIFT              (21U)
/*! CRC - Enables the clock for the CRC engine. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CRC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CRC_SHIFT)) & SYSCON_AHBCLKCTRL_CRC_MASK)

#define SYSCON_AHBCLKCTRL_WWDT_MASK              (0x400000U)
#define SYSCON_AHBCLKCTRL_WWDT_SHIFT             (22U)
/*! WWDT - Enables the clock for the Watchdog Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_WWDT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_WWDT_SHIFT)) & SYSCON_AHBCLKCTRL_WWDT_MASK)

#define SYSCON_AHBCLKCTRL_RTC_MASK               (0x800000U)
#define SYSCON_AHBCLKCTRL_RTC_SHIFT              (23U)
/*! RTC - Enables the bus clock for the RTC. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_RTC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_RTC_SHIFT)) & SYSCON_AHBCLKCTRL_RTC_MASK)

#define SYSCON_AHBCLKCTRL_USB0_MASK              (0x2000000U)
#define SYSCON_AHBCLKCTRL_USB0_SHIFT             (25U)
/*! USB0 - Enables the clock for the USB0 interface. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_USB0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB0_SHIFT)) & SYSCON_AHBCLKCTRL_USB0_MASK)

#define SYSCON_AHBCLKCTRL_CTIMER0_MASK           (0x4000000U)
#define SYSCON_AHBCLKCTRL_CTIMER0_SHIFT          (26U)
/*! CTIMER0 - Enables the clock for timer CTIMER0. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CTIMER0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CTIMER0_SHIFT)) & SYSCON_AHBCLKCTRL_CTIMER0_MASK)

#define SYSCON_AHBCLKCTRL_ADC0_MASK              (0x8000000U)
#define SYSCON_AHBCLKCTRL_ADC0_SHIFT             (27U)
/*! ADC0 - Enables the clock for the ADC0 register interface. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_ADC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_ADC0_SHIFT)) & SYSCON_AHBCLKCTRL_ADC0_MASK)

#define SYSCON_AHBCLKCTRL_CTIMER1_MASK           (0x8000000U)
#define SYSCON_AHBCLKCTRL_CTIMER1_SHIFT          (27U)
/*! CTIMER1 - Enables the clock for timer CTIMER1. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CTIMER1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CTIMER1_SHIFT)) & SYSCON_AHBCLKCTRL_CTIMER1_MASK)
/*! @} */

/*! @name AHBCLKCTRLSET - Set bits in AHBCLKCTRLn */
/*! @{ */

#define SYSCON_AHBCLKCTRLSET_CLK_SET_MASK        (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLSET_CLK_SET_SHIFT       (0U)
/*! CLK_SET - Writing ones to this register sets the corresponding bit or bits in the AHBCLKCTRLn
 *    register, if they are implemented. Bits that do not correspond to defined bits in AHBCLKCTRLn
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_AHBCLKCTRLSET_CLK_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLSET_CLK_SET_SHIFT)) & SYSCON_AHBCLKCTRLSET_CLK_SET_MASK)
/*! @} */

/*! @name AHBCLKCTRLCLR - Clear bits in AHBCLKCTRLn */
/*! @{ */

#define SYSCON_AHBCLKCTRLCLR_CLK_CLR_MASK        (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLCLR_CLK_CLR_SHIFT       (0U)
/*! CLK_CLR - Writing ones to this register clears the corresponding bit or bits in the AHBCLKCTRLn
 *    register, if they are implemented. Bits that do not correspond to defined bits in AHBCLKCTRLn
 *    are reserved and only zeroes should be written to them.
 */
#define SYSCON_AHBCLKCTRLCLR_CLK_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLCLR_CLK_CLR_SHIFT)) & SYSCON_AHBCLKCTRLCLR_CLK_CLR_MASK)
/*! @} */

/*! @name MAINCLKSELA - Main clock source select A */
/*! @{ */

#define SYSCON_MAINCLKSELA_SEL_MASK              (0x3U)
#define SYSCON_MAINCLKSELA_SEL_SHIFT             (0U)
/*! SEL - Clock source for main clock source selector A
 *  0b00..FRO 12 MHz (fro_12m)
 *  0b01..CLKIN (clk_in)
 *  0b10..Watchdog oscillator (wdt_clk)
 *  0b11..FRO 96 or 48 MHz (fro_hf)
 */
#define SYSCON_MAINCLKSELA_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELA_SEL_SHIFT)) & SYSCON_MAINCLKSELA_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELB - Main clock source select B */
/*! @{ */

#define SYSCON_MAINCLKSELB_SEL_MASK              (0x3U)
#define SYSCON_MAINCLKSELB_SEL_SHIFT             (0U)
/*! SEL - Clock source for main clock source selector B. Selects the clock source for the main clock.
 *  0b00..MAINCLKSELA. Use the clock source selected in MAINCLKSELA register.
 *  0b01..Reserved setting
 *  0b10..System PLL output (pll_clk)
 *  0b11..RTC oscillator 32 kHz output (32k_clk)
 */
#define SYSCON_MAINCLKSELB_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELB_SEL_SHIFT)) & SYSCON_MAINCLKSELB_SEL_MASK)
/*! @} */

/*! @name CLKOUTSELA - CLKOUT clock source select A */
/*! @{ */

#define SYSCON_CLKOUTSELA_SEL_MASK               (0x7U)
#define SYSCON_CLKOUTSELA_SEL_SHIFT              (0U)
/*! SEL - CLKOUT clock source selection
 *  0b000..Main clock (main_clk)
 *  0b001..CLKIN (clk_in)
 *  0b010..Watchdog oscillator (wdt_clk)
 *  0b011..FRO 96 or 48 MHz (fro_hf)
 *  0b100..PLL output (pll_clk)
 *  0b101..FRO 12 MHz (fro_12m)
 *  0b110..RTC oscillator 32 kHz output (32k_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_CLKOUTSELA_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSELA_SEL_SHIFT)) & SYSCON_CLKOUTSELA_SEL_MASK)
/*! @} */

/*! @name SYSPLLCLKSEL - PLL clock source select */
/*! @{ */

#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)
/*! SEL - System PLL clock source selection
 *  0b000..FRO 12 MHz (fro_12m)
 *  0b001..CLKIN (clk_in)
 *  0b011..RTC 32 kHz clock (32k_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_SYSPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCLKSEL_SEL_SHIFT)) & SYSCON_SYSPLLCLKSEL_SEL_MASK)
/*! @} */

/*! @name ADCCLKSEL - ADC clock source select */
/*! @{ */

#define SYSCON_ADCCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_ADCCLKSEL_SEL_SHIFT               (0U)
/*! SEL - ADC clock source selection
 *  0b000..Main clock (main_clk)
 *  0b001..System PLL output (pll_clk)
 *  0b010..FRO 96 or 48 MHz (fro_hf)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_ADCCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKSEL_SEL_SHIFT)) & SYSCON_ADCCLKSEL_SEL_MASK)
/*! @} */

/*! @name USBCLKSEL - USB clock source select */
/*! @{ */

#define SYSCON_USBCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_USBCLKSEL_SEL_SHIFT               (0U)
/*! SEL - USB device clock source selection
 *  0b000..FRO 96 or 48 MHz (fro_hf)
 *  0b001..System PLL output (pll_clk)
 *  0b010..Main clock (main_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_USBCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_USBCLKSEL_SEL_SHIFT)) & SYSCON_USBCLKSEL_SEL_MASK)
/*! @} */

/*! @name FXCOMCLKSEL - Flexcomm0 clock source select..Flexcomm7 clock source select */
/*! @{ */

#define SYSCON_FXCOMCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_FXCOMCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Flexcomm clock source selection. One per Flexcomm.
 *  0b000..FRO 12 MHz (fro_12m)
 *  0b001..FRO 96 or 48 MHz (fro_hf)
 *  0b010..System PLL output (pll_clk)
 *  0b011..MCLK pin input, when selected in IOCON (mclk_in)
 *  0b100..FRG clock, the output of the fractional rate generator (frg_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_FXCOMCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FXCOMCLKSEL_SEL_SHIFT)) & SYSCON_FXCOMCLKSEL_SEL_MASK)
/*! @} */

/*! @name MCLKCLKSEL - MCLK clock source select */
/*! @{ */

#define SYSCON_MCLKCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_MCLKCLKSEL_SEL_SHIFT              (0U)
/*! SEL - MCLK source select. This may be used by Flexcomms that support I2S, and/or by the digital microphone subsystem.
 *  0b000..FRO 96 or 48 MHz (fro_hf)
 *  0b001..System PLL output (pll_clk)
 *  0b010..Main clock (main_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_MCLKCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKCLKSEL_SEL_SHIFT)) & SYSCON_MCLKCLKSEL_SEL_MASK)
/*! @} */

/*! @name FRGCLKSEL - Fractional Rate Generator clock source select */
/*! @{ */

#define SYSCON_FRGCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_FRGCLKSEL_SEL_SHIFT               (0U)
/*! SEL - Fractional Rate Generator clock source select.
 *  0b000..Main clock (main_clk)
 *  0b001..System PLL output (pll_clk)
 *  0b010..FRO 12 MHz (fro_12m)
 *  0b011..FRO 96 or 48 MHz (fro_hf)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_FRGCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FRGCLKSEL_SEL_SHIFT)) & SYSCON_FRGCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV - SYSTICK clock divider */
/*! @{ */

#define SYSCON_SYSTICKCLKDIV_DIV_MASK            (0xFFU)
#define SYSCON_SYSTICKCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_SYSTICKCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_DIV_SHIFT)) & SYSCON_SYSTICKCLKDIV_DIV_MASK)
/*! @} */

/*! @name AHBCLKDIV - AHB clock divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)
/*! @} */

/*! @name ADCCLKDIV - ADC clock divider */
/*! @{ */

#define SYSCON_ADCCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_ADCCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_ADCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_DIV_SHIFT)) & SYSCON_ADCCLKDIV_DIV_MASK)
/*! @} */

/*! @name USBCLKDIV - USB clock divider */
/*! @{ */

#define SYSCON_USBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_USBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_USBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_USBCLKDIV_DIV_SHIFT)) & SYSCON_USBCLKDIV_DIV_MASK)
/*! @} */

/*! @name FRGCTRL - Fractional rate divider */
/*! @{ */

#define SYSCON_FRGCTRL_DIV_MASK                  (0xFFU)
#define SYSCON_FRGCTRL_DIV_SHIFT                 (0U)
/*! DIV - Denominator of the fractional divider. DIV is equal to the programmed value +1. Always set
 *    to 0xFF to use with the fractional baud rate generator.
 */
#define SYSCON_FRGCTRL_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FRGCTRL_DIV_SHIFT)) & SYSCON_FRGCTRL_DIV_MASK)

#define SYSCON_FRGCTRL_MULT_MASK                 (0xFF00U)
#define SYSCON_FRGCTRL_MULT_SHIFT                (8U)
/*! MULT - Numerator of the fractional divider. MULT is equal to the programmed value. */
#define SYSCON_FRGCTRL_MULT(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FRGCTRL_MULT_SHIFT)) & SYSCON_FRGCTRL_MULT_MASK)
/*! @} */

/*! @name MCLKDIV - I2S MCLK clock divider */
/*! @{ */

#define SYSCON_MCLKDIV_DIV_MASK                  (0xFFU)
#define SYSCON_MCLKDIV_DIV_SHIFT                 (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_MCLKDIV_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_DIV_SHIFT)) & SYSCON_MCLKDIV_DIV_MASK)
/*! @} */

/*! @name FLASHCFG - Flash wait states configuration */
/*! @{ */

#define SYSCON_FLASHCFG_FETCHCFG_MASK            (0x3U)
#define SYSCON_FLASHCFG_FETCHCFG_SHIFT           (0U)
/*! FETCHCFG - Instruction fetch configuration. This field determines how flash accelerator buffers are used for instruction fetches.
 *  0b00..Instruction fetches from flash are not buffered. Every fetch request from the CPU results in a read of
 *        the flash memory. This setting may use significantly more power than when buffering is enabled.
 *  0b01..One buffer is used for all instruction fetches.
 *  0b10..All buffers may be used for instruction fetches.
 *  0b11..Reserved setting, do not use.
 */
#define SYSCON_FLASHCFG_FETCHCFG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_FETCHCFG_SHIFT)) & SYSCON_FLASHCFG_FETCHCFG_MASK)

#define SYSCON_FLASHCFG_DATACFG_MASK             (0xCU)
#define SYSCON_FLASHCFG_DATACFG_SHIFT            (2U)
/*! DATACFG - Data read configuration. This field determines how flash accelerator buffers are used for data accesses.
 *  0b00..Data accesses from flash are not buffered. Every data access from the CPU results in a read of the flash memory.
 *  0b01..One buffer is used for all data accesses.
 *  0b10..All buffers may be used for data accesses.
 *  0b11..Reserved setting, do not use.
 */
#define SYSCON_FLASHCFG_DATACFG(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_DATACFG_SHIFT)) & SYSCON_FLASHCFG_DATACFG_MASK)

#define SYSCON_FLASHCFG_ACCEL_MASK               (0x10U)
#define SYSCON_FLASHCFG_ACCEL_SHIFT              (4U)
/*! ACCEL - Acceleration enable.
 *  0b0..Flash acceleration is disabled. Every flash read (including those fulfilled from a buffer) takes FLASHTIM
 *       + 1 system clocks. This allows more determinism at a cost of performance.
 *  0b1..Flash acceleration is enabled. Performance is enhanced, dependent on other FLASHCFG settings.
 */
#define SYSCON_FLASHCFG_ACCEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_ACCEL_SHIFT)) & SYSCON_FLASHCFG_ACCEL_MASK)

#define SYSCON_FLASHCFG_PREFEN_MASK              (0x20U)
#define SYSCON_FLASHCFG_PREFEN_SHIFT             (5U)
/*! PREFEN - Prefetch enable.
 *  0b0..No instruction prefetch is performed.
 *  0b1..If the FETCHCFG field is not 0, the next flash line following the current execution address is
 *       automatically prefetched if it is not already buffered.
 */
#define SYSCON_FLASHCFG_PREFEN(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_PREFEN_SHIFT)) & SYSCON_FLASHCFG_PREFEN_MASK)

#define SYSCON_FLASHCFG_PREFOVR_MASK             (0x40U)
#define SYSCON_FLASHCFG_PREFOVR_SHIFT            (6U)
/*! PREFOVR - Prefetch override. This bit only applies when PREFEN = 1 and a buffered instruction is
 *    completing for which the next flash line is not already buffered or being prefetched.
 *  0b0..Any previously initiated prefetch will be completed.
 *  0b1..Any previously initiated prefetch will be aborted, and the next flash line following the current
 *       execution address will be prefetched if not already buffered.
 */
#define SYSCON_FLASHCFG_PREFOVR(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_PREFOVR_SHIFT)) & SYSCON_FLASHCFG_PREFOVR_MASK)

#define SYSCON_FLASHCFG_FLASHTIM_MASK            (0xF000U)
#define SYSCON_FLASHCFG_FLASHTIM_SHIFT           (12U)
/*! FLASHTIM - Flash memory access time. The number of system clocks used for flash accesses is equal to FLASHTIM +1.
 *  0b0000..1 system clock flash access time (for system clock rates up to 12 MHz).
 *  0b0001..2 system clocks flash access time (for system clock rates up to 30 MHz).
 *  0b0010..3 system clocks flash access time (for system clock rates up to 60 MHz).
 *  0b0011..4 system clocks flash access time (for system clock rates up to 85 MHz).
 *  0b0100..5 system clocks flash access time (for system clock rates up to 100 MHz).
 */
#define SYSCON_FLASHCFG_FLASHTIM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHCFG_FLASHTIM_SHIFT)) & SYSCON_FLASHCFG_FLASHTIM_MASK)
/*! @} */

/*! @name USBCLKCTRL - USB clock control */
/*! @{ */

#define SYSCON_USBCLKCTRL_POL_CLK_MASK           (0x2U)
#define SYSCON_USBCLKCTRL_POL_CLK_SHIFT          (1U)
/*! POL_CLK - USB_NEED_CLK polarity for triggering the USB wake-up interrupt
 *  0b0..Falling edge of the USB_NEED_CLK triggers the USB wake-up (default).
 *  0b1..Rising edge of the USB_NEED_CLK triggers the USB wake-up.
 */
#define SYSCON_USBCLKCTRL_POL_CLK(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_USBCLKCTRL_POL_CLK_SHIFT)) & SYSCON_USBCLKCTRL_POL_CLK_MASK)
/*! @} */

/*! @name USBCLKSTAT - USB clock status */
/*! @{ */

#define SYSCON_USBCLKSTAT_NEED_CLKST_MASK        (0x1U)
#define SYSCON_USBCLKSTAT_NEED_CLKST_SHIFT       (0U)
/*! NEED_CLKST - USB_NEED_CLK signal status
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON_USBCLKSTAT_NEED_CLKST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_USBCLKSTAT_NEED_CLKST_SHIFT)) & SYSCON_USBCLKSTAT_NEED_CLKST_MASK)
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

/*! @name MCLKIO - MCLK input/output control */
/*! @{ */

#define SYSCON_MCLKIO_DIR_MASK                   (0x1U)
#define SYSCON_MCLKIO_DIR_SHIFT                  (0U)
/*! DIR - MCLK direction control.
 *  0b0..The MCLK function is an input.
 *  0b1..The MCLK function is an output.
 */
#define SYSCON_MCLKIO_DIR(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKIO_DIR_SHIFT)) & SYSCON_MCLKIO_DIR_MASK)
/*! @} */

/*! @name FROCTRL - FRO oscillator control */
/*! @{ */

#define SYSCON_FROCTRL_TRIM_MASK                 (0x3FFFU)
#define SYSCON_FROCTRL_TRIM_SHIFT                (0U)
/*! TRIM - This value is factory trimmed to account for bias and temperature compensation. The value
 *    should not be changed by software. Also see the WRTRIM bit description.
 */
#define SYSCON_FROCTRL_TRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_TRIM_SHIFT)) & SYSCON_FROCTRL_TRIM_MASK)

#define SYSCON_FROCTRL_SEL_MASK                  (0x4000U)
#define SYSCON_FROCTRL_SEL_SHIFT                 (14U)
/*! SEL - Select the fro_hf output frequency. This bit can only be changed by software when the
 *    WRTRIM bit = 1. Note that the factory trim values are for the 96 MHz FRO only.
 *  0b0..48 MHz
 *  0b1..96 MHz
 */
#define SYSCON_FROCTRL_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_SEL_SHIFT)) & SYSCON_FROCTRL_SEL_MASK)

#define SYSCON_FROCTRL_FREQTRIM_MASK             (0xFF0000U)
#define SYSCON_FROCTRL_FREQTRIM_SHIFT            (16U)
/*! FREQTRIM - Frequency trim. Boot code configures this to a device-specific factory trim value for
 *    the 48 MHz FRO. If USBCLKADJ = 1, this field is read-only and provides the value resulting
 *    from USB rate adjustment. See the USBMODCFG flag regarding reading this field. Application code
 *    may adjust this field when USBCLKADJ = 0. A single step of FREQTRIM is roughly equivalent to
 *    0.1% of the selected FRO frequency.
 */
#define SYSCON_FROCTRL_FREQTRIM(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_FREQTRIM_SHIFT)) & SYSCON_FROCTRL_FREQTRIM_MASK)

#define SYSCON_FROCTRL_USBCLKADJ_MASK            (0x1000000U)
#define SYSCON_FROCTRL_USBCLKADJ_SHIFT           (24U)
/*! USBCLKADJ - USB clock adjust mode.
 *  0b0..Normal operation.
 *  0b1..Automatic USB rate adjustment mode. If the USB FS device peripheral is enabled and connected to a USB
 *       host, it provides clock adjustment information to the FRO based on SOF packets. USB rate adjustment requires
 *       a number of cycles to take place. the USBMODCHG bit (see below) indicates when initial adjustment is
 *       complete, and when later adjustments are in progress. software must not alter TRIM and FREQTRIM while USBCLKADJ
 *       = 1. see USBCLKADJ usage notes below this table.
 */
#define SYSCON_FROCTRL_USBCLKADJ(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_USBCLKADJ_SHIFT)) & SYSCON_FROCTRL_USBCLKADJ_MASK)

#define SYSCON_FROCTRL_USBMODCHG_MASK            (0x2000000U)
#define SYSCON_FROCTRL_USBMODCHG_SHIFT           (25U)
/*! USBMODCHG - USB Mode value Change flag. When 1, indicates that the USB trim is currently being
 *    updated (or is still starting up) and software should wait to read FREQTRIM. Update occurs at
 *    most once per millisecond.
 */
#define SYSCON_FROCTRL_USBMODCHG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_USBMODCHG_SHIFT)) & SYSCON_FROCTRL_USBMODCHG_MASK)

#define SYSCON_FROCTRL_HSPDCLK_MASK              (0x40000000U)
#define SYSCON_FROCTRL_HSPDCLK_SHIFT             (30U)
/*! HSPDCLK - High speed clock enable. Allows disabling the highs-speed FRO output if it is not needed.
 *  0b0..The high-speed FRO output is disabled.
 *  0b1..The selected high-speed FRO output (48 MHz or 96 MHz) is enabled.
 */
#define SYSCON_FROCTRL_HSPDCLK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_HSPDCLK_SHIFT)) & SYSCON_FROCTRL_HSPDCLK_MASK)

#define SYSCON_FROCTRL_WRTRIM_MASK               (0x80000000U)
#define SYSCON_FROCTRL_WRTRIM_SHIFT              (31U)
/*! WRTRIM - Write Trim value. Must be written to 1 to modify the SEL or TRIM fields, during the
 *    same write. This bit always reads as 0.
 */
#define SYSCON_FROCTRL_WRTRIM(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_WRTRIM_SHIFT)) & SYSCON_FROCTRL_WRTRIM_MASK)
/*! @} */

/*! @name WDTOSCCTRL - Watchdog oscillator control */
/*! @{ */

#define SYSCON_WDTOSCCTRL_DIVSEL_MASK            (0x1FU)
#define SYSCON_WDTOSCCTRL_DIVSEL_SHIFT           (0U)
/*! DIVSEL - Divider select. Selects the value of the divider that adjusts the output of the
 *    oscillator. 0x00 = divide by 2 0x01 = divide by 4 0x02 = divide by 6 up to 0x1E = divide by 62 0x1F =
 *    divide by 64
 */
#define SYSCON_WDTOSCCTRL_DIVSEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTOSCCTRL_DIVSEL_SHIFT)) & SYSCON_WDTOSCCTRL_DIVSEL_MASK)

#define SYSCON_WDTOSCCTRL_FREQSEL_MASK           (0x3E0U)
#define SYSCON_WDTOSCCTRL_FREQSEL_SHIFT          (5U)
/*! FREQSEL - Frequency select. Selects the frequency of the oscillator. 0x00 = invalid setting when
 *    watchdog oscillator is running 0x01 = 0.4 MHz 0x02 = 0.6 MHz 0x03 = 0.75 MHz 0x04 = 0.9 MHz
 *    0x05 = 1.0 MHz 0x06 = 1.2 MHz 0x07 = 1.3 MHz 0x08 = 1.4 MHz 0x09 = 1.5 MHz 0x0A = 1.6 MHz 0x0B
 *    = 1.7 MHz 0x0C = 1.8 MHz 0x0D = 1.9 MHz 0x0E = 2.0 MHz 0x0F = 2.05 MHz 0x10 = 2.1 MHz 0x11 =
 *    2.2 MHz 0x12 = 2.25 MHz 0x13 = 2.3 MHz 0x14 = 2.4 MHz 0x15 = 2.45 MHz 0x16 = 2.5 MHz 0x17 = 2.6
 *    MHz 0x18 = 2.65 MHz 0x19 = 2.7 MHz 0x1A = 2.8 MHz 0x1B = 2.85 MHz 0x1C = 2.9 MHz 0x1D = 2.95
 *    MHz 0x1E = 3.0 MHz 0x1F = 3.05 MHz
 */
#define SYSCON_WDTOSCCTRL_FREQSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTOSCCTRL_FREQSEL_SHIFT)) & SYSCON_WDTOSCCTRL_FREQSEL_MASK)
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
/*! SELI - Bandwidth select I value. */
#define SYSCON_SYSPLLCTRL_SELI(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELI_SHIFT)) & SYSCON_SYSPLLCTRL_SELI_MASK)

#define SYSCON_SYSPLLCTRL_SELP_MASK              (0x7C00U)
#define SYSCON_SYSPLLCTRL_SELP_SHIFT             (10U)
/*! SELP - Bandwidth select P value */
#define SYSCON_SYSPLLCTRL_SELP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELP_SHIFT)) & SYSCON_SYSPLLCTRL_SELP_MASK)

#define SYSCON_SYSPLLCTRL_BYPASS_MASK            (0x8000U)
#define SYSCON_SYSPLLCTRL_BYPASS_SHIFT           (15U)
/*! BYPASS - PLL bypass control.
 *  0b0..Bypass disabled. PLL CCO is sent to the PLL post-dividers.
 *  0b1..Bypass enabled. PLL input clock is sent directly to the PLL output (default).
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
/*! UPLIMOFF - Disable upper frequency limiter.
 *  0b0..Normal mode.
 *  0b1..Upper frequency limiter disabled.
 */
#define SYSCON_SYSPLLCTRL_UPLIMOFF(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_UPLIMOFF_SHIFT)) & SYSCON_SYSPLLCTRL_UPLIMOFF_MASK)

#define SYSCON_SYSPLLCTRL_BANDSEL_MASK           (0x40000U)
#define SYSCON_SYSPLLCTRL_BANDSEL_SHIFT          (18U)
/*! BANDSEL - PLL filter control. Set this bit to one when the spread spectrum controller is
 *    disabled or at low frequencies. For spread spectrum mode: SEL_EXT = 0, BANDSEL = 0, and UPLIMOFF = 1.
 *  0b0..SSCG control. The PLL filter uses the parameters derived from the spread spectrum controller.
 *  0b1..MDEC control. The PLL filter uses the programmable fields SELP, SELR, and SELI in this register to control the filter constants.
 */
#define SYSCON_SYSPLLCTRL_BANDSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_BANDSEL_SHIFT)) & SYSCON_SYSPLLCTRL_BANDSEL_MASK)

#define SYSCON_SYSPLLCTRL_DIRECTI_MASK           (0x80000U)
#define SYSCON_SYSPLLCTRL_DIRECTI_SHIFT          (19U)
/*! DIRECTI - PLL0 direct input enable
 *  0b0..Disabled. The PLL input divider (N divider) output is used to drive the PLL CCO.
 *  0b1..Enabled. The PLL input divider (N divider) is bypassed. the PLL input clock is used directly to drive the PLL CCO input.
 */
#define SYSCON_SYSPLLCTRL_DIRECTI(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_DIRECTI_SHIFT)) & SYSCON_SYSPLLCTRL_DIRECTI_MASK)

#define SYSCON_SYSPLLCTRL_DIRECTO_MASK           (0x100000U)
#define SYSCON_SYSPLLCTRL_DIRECTO_SHIFT          (20U)
/*! DIRECTO - PLL0 direct output enable.
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
/*! NDEC - Decoded N-divider coefficient value. */
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
/*! PDEC - Decoded P-divider coefficient value. */
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
/*! MDEC - Decoded M-divider coefficient value. */
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
/*! SEL_EXT - Select spread spectrum mode. Selects the source of the feedback divider value. For
 *    normal mode, this must be the value from the MDEC field in this register. For spread spectrum
 *    mode: SEL_EXT = 0, BANDSEL = 0, and UPLIMOFF = 1.
 */
#define SYSCON_SYSPLLSSCTRL0_SEL_EXT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL0_SEL_EXT_SHIFT)) & SYSCON_SYSPLLSSCTRL0_SEL_EXT_MASK)
/*! @} */

/*! @name SYSPLLSSCTRL1 - PLL spread spectrum control 1 */
/*! @{ */

#define SYSCON_SYSPLLSSCTRL1_MD_MASK             (0x7FFFFU)
#define SYSCON_SYSPLLSSCTRL1_MD_SHIFT            (0U)
/*! MD - M- divider value with fraction. MD[18:11]: integer portion of the feedback divider value.
 *    MD[10:0]: fractional portion of the feedback divider value. In fractional mode, fcco = (2 -
 *    BYPASSCCODIV2) x (MD x 2^-11) x Fref
 */
#define SYSCON_SYSPLLSSCTRL1_MD(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MD_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MD_MASK)

#define SYSCON_SYSPLLSSCTRL1_MDREQ_MASK          (0x80000U)
#define SYSCON_SYSPLLSSCTRL1_MDREQ_SHIFT         (19U)
/*! MDREQ - MD reload request. When a 1 is written to this bit, the MD value is loaded into the PLL.
 *    This bit is cleared when the load is complete
 */
#define SYSCON_SYSPLLSSCTRL1_MDREQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MDREQ_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MDREQ_MASK)

#define SYSCON_SYSPLLSSCTRL1_MF_MASK             (0x700000U)
#define SYSCON_SYSPLLSSCTRL1_MF_SHIFT            (20U)
/*! MF - Programmable modulation frequency fm = Fref/Nss with Fref = Fin/N 0b000 => Nss = 512 (fm _
 *    3.9 - 7.8 kHz) 0b001 => Nss _ 384 (fm _ 5.2 - 10.4 kHz) 0b010 => Nss = 256 (fm _ 7.8 - 15.6
 *    kHz) 0b011 => Nss = 128 (fm _ 15.6 - 31.3 kHz) 0b100 => Nss = 64 (fm _ 32.3 - 64.5 kHz) 0b101 =>
 *    Nss = 32 (fm _ 62.5- 125 kHz) 0b110 => Nss _ 24 (fm _ 83.3- 166.6 kHz) 0b111 => Nss = 16 (fm
 *    _ 125- 250 kHz)
 */
#define SYSCON_SYSPLLSSCTRL1_MF(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MF_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MF_MASK)

#define SYSCON_SYSPLLSSCTRL1_MR_MASK             (0x3800000U)
#define SYSCON_SYSPLLSSCTRL1_MR_SHIFT            (23U)
/*! MR - Programmable frequency modulation depth. 0 = no spread. _fmodpk-pk = Fref x k/Fcco =
 *    k/MDdec 0b000 -> k = 0 (no spread spectrum) 0b001 => k _ 1 0b010 => k _ 1.5 0b011 => k _ 2 0b100 =>
 *    k _ 3 0b101 => k _ 4 0b110 => k _ 6 0b111 => k _ 8
 */
#define SYSCON_SYSPLLSSCTRL1_MR(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MR_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MR_MASK)

#define SYSCON_SYSPLLSSCTRL1_MC_MASK             (0xC000000U)
#define SYSCON_SYSPLLSSCTRL1_MC_SHIFT            (26U)
/*! MC - Modulation waveform control. 0 = no compensation. Compensation for low pass filtering of
 *    the PLL to get a triangular modulation at the output of the PLL, giving a flat frequency
 *    spectrum. 0b00 => no compensation 0b10 => recommended setting 0b11 => max. compensation
 */
#define SYSCON_SYSPLLSSCTRL1_MC(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSSCTRL1_MC_SHIFT)) & SYSCON_SYSPLLSSCTRL1_MC_MASK)

#define SYSCON_SYSPLLSSCTRL1_PD_MASK             (0x10000000U)
#define SYSCON_SYSPLLSSCTRL1_PD_SHIFT            (28U)
/*! PD - Spread spectrum power-down.
 *  0b0..Enabled. Spread spectrum controller is enabled
 *  0b1..Disabled. Spread spectrum controller is disabled.
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

/*! @name PDSLEEPCFG - Sleep configuration register n */
/*! @{ */

#define SYSCON_PDSLEEPCFG_PD_SLEEP_MASK          (0xFFFFFFFFU)
#define SYSCON_PDSLEEPCFG_PD_SLEEP_SHIFT         (0U)
/*! PD_SLEEP - See bit descriptions in the PDRUNCFGn register. */
#define SYSCON_PDSLEEPCFG_PD_SLEEP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PD_SLEEP_SHIFT)) & SYSCON_PDSLEEPCFG_PD_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG - Power configuration register 0 */
/*! @{ */

#define SYSCON_PDRUNCFG_PDEN_FRO_MASK            (0x10U)
#define SYSCON_PDRUNCFG_PDEN_FRO_SHIFT           (4U)
/*! PDEN_FRO - FRO oscillator. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_FRO(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_FRO_SHIFT)) & SYSCON_PDRUNCFG_PDEN_FRO_MASK)

#define SYSCON_PDRUNCFG_PDEN_TS_MASK             (0x40U)
#define SYSCON_PDRUNCFG_PDEN_TS_SHIFT            (6U)
/*! PDEN_TS - Temp sensor. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_TS(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_TS_SHIFT)) & SYSCON_PDRUNCFG_PDEN_TS_MASK)

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

#define SYSCON_PDRUNCFG_PDEN_SRAM0_MASK          (0x2000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM0_SHIFT         (13U)
/*! PDEN_SRAM0 - SRAM0. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SRAM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM0_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM0_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAMX_MASK          (0x10000U)
#define SYSCON_PDRUNCFG_PDEN_SRAMX_SHIFT         (16U)
/*! PDEN_SRAMX - SRAMX. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SRAMX(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAMX_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAMX_MASK)

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

#define SYSCON_PDRUNCFG_PDEN_USB_PHY_MASK        (0x200000U)
#define SYSCON_PDRUNCFG_PDEN_USB_PHY_SHIFT       (21U)
/*! PDEN_USB_PHY - USB pin interface. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_USB_PHY(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_USB_PHY_SHIFT)) & SYSCON_PDRUNCFG_PDEN_USB_PHY_MASK)

#define SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK        (0x400000U)
#define SYSCON_PDRUNCFG_PDEN_SYS_PLL_SHIFT       (22U)
/*! PDEN_SYS_PLL - PLL0. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_SYS_PLL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SYS_PLL_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK)

#define SYSCON_PDRUNCFG_PDEN_VREFP_MASK          (0x800000U)
#define SYSCON_PDRUNCFG_PDEN_VREFP_SHIFT         (23U)
/*! PDEN_VREFP - Vrefp to the ADC, must be enabled for the ADC to work. Also see bit 19. 0 = Powered; 1 = Powered down. */
#define SYSCON_PDRUNCFG_PDEN_VREFP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VREFP_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VREFP_MASK)
/*! @} */

/*! @name PDRUNCFGSET - Set bits in PDRUNCFGn */
/*! @{ */

#define SYSCON_PDRUNCFGSET_PD_SET_MASK           (0xFFFFFFFFU)
#define SYSCON_PDRUNCFGSET_PD_SET_SHIFT          (0U)
/*! PD_SET - Writing ones to this register sets the corresponding bit or bits in the PDRUNCFG
 *    register, if they are implemented. Bits that do not correspond to defined bits in PDRUNCFG are
 *    reserved and only zeroes should be written to them.
 */
#define SYSCON_PDRUNCFGSET_PD_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PD_SET_SHIFT)) & SYSCON_PDRUNCFGSET_PD_SET_MASK)
/*! @} */

/*! @name PDRUNCFGCLR - Clear bits in PDRUNCFGn */
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

#define SYSCON_STARTER_WDT_BOD_MASK              (0x1U)
#define SYSCON_STARTER_WDT_BOD_SHIFT             (0U)
/*! WDT_BOD - WWDT and BOD interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_WDT_BOD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_WDT_BOD_SHIFT)) & SYSCON_STARTER_WDT_BOD_MASK)

#define SYSCON_STARTER_DMA0_MASK                 (0x2U)
#define SYSCON_STARTER_DMA0_SHIFT                (1U)
/*! DMA0 - DMA0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Typically used in sleep mode
 *    only since the peripheral clock must be running for it to function.
 */
#define SYSCON_STARTER_DMA0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DMA0_SHIFT)) & SYSCON_STARTER_DMA0_MASK)

#define SYSCON_STARTER_GINT0_MASK                (0x4U)
#define SYSCON_STARTER_GINT0_SHIFT               (2U)
/*! GINT0 - Group interrupt 0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_GINT0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT0_SHIFT)) & SYSCON_STARTER_GINT0_MASK)

#define SYSCON_STARTER_GINT1_MASK                (0x8U)
#define SYSCON_STARTER_GINT1_SHIFT               (3U)
/*! GINT1 - Group interrupt 1 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_GINT1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT1_SHIFT)) & SYSCON_STARTER_GINT1_MASK)

#define SYSCON_STARTER_PIN_INT0_MASK             (0x10U)
#define SYSCON_STARTER_PIN_INT0_SHIFT            (4U)
/*! PIN_INT0 - GPIO pin interrupt 0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PIN_INT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT0_SHIFT)) & SYSCON_STARTER_PIN_INT0_MASK)

#define SYSCON_STARTER_PIN_INT1_MASK             (0x20U)
#define SYSCON_STARTER_PIN_INT1_SHIFT            (5U)
/*! PIN_INT1 - GPIO pin interrupt 1 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PIN_INT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT1_SHIFT)) & SYSCON_STARTER_PIN_INT1_MASK)

#define SYSCON_STARTER_PIN_INT2_MASK             (0x40U)
#define SYSCON_STARTER_PIN_INT2_SHIFT            (6U)
/*! PIN_INT2 - GPIO pin interrupt 2 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PIN_INT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT2_SHIFT)) & SYSCON_STARTER_PIN_INT2_MASK)

#define SYSCON_STARTER_PIN_INT3_MASK             (0x80U)
#define SYSCON_STARTER_PIN_INT3_SHIFT            (7U)
/*! PIN_INT3 - GPIO pin interrupt 3 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Not for pattern match. */
#define SYSCON_STARTER_PIN_INT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT3_SHIFT)) & SYSCON_STARTER_PIN_INT3_MASK)

#define SYSCON_STARTER_UTICK0_MASK               (0x100U)
#define SYSCON_STARTER_UTICK0_SHIFT              (8U)
/*! UTICK0 - Micro-tick Timer wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_UTICK0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_UTICK0_SHIFT)) & SYSCON_STARTER_UTICK0_MASK)

#define SYSCON_STARTER_MRT0_MASK                 (0x200U)
#define SYSCON_STARTER_MRT0_SHIFT                (9U)
/*! MRT0 - Multi-Rate Timer wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. Typically used in
 *    sleep mode only since the peripheral clock must be running for it to function.
 */
#define SYSCON_STARTER_MRT0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_MRT0_SHIFT)) & SYSCON_STARTER_MRT0_MASK)

#define SYSCON_STARTER_CTIMER0_MASK              (0x400U)
#define SYSCON_STARTER_CTIMER0_SHIFT             (10U)
/*! CTIMER0 - Standard counter/timer CTIMER0 wake-up. 0 = Wake-up disabled. 1 = Wake-up
 *    enabled.Typically used in sleep mode only since the peripheral clock must be running for it to function.
 */
#define SYSCON_STARTER_CTIMER0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER0_SHIFT)) & SYSCON_STARTER_CTIMER0_MASK)

#define SYSCON_STARTER_CTIMER1_MASK              (0x800U)
#define SYSCON_STARTER_CTIMER1_SHIFT             (11U)
/*! CTIMER1 - Standard counter/timer CTIMER1 wake-up. 0 = Wake-up disabled. 1 = Wake-up
 *    enabled.Typically used in sleep mode only since the peripheral clock must be running for it to function.
 */
#define SYSCON_STARTER_CTIMER1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER1_SHIFT)) & SYSCON_STARTER_CTIMER1_MASK)

#define SYSCON_STARTER_SCT0_MASK                 (0x1000U)
#define SYSCON_STARTER_SCT0_SHIFT                (12U)
/*! SCT0 - SCT0 wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled.Typically used in sleep mode only
 *    since the peripheral clock must be running for it to function.
 */
#define SYSCON_STARTER_SCT0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SCT0_SHIFT)) & SYSCON_STARTER_SCT0_MASK)

#define SYSCON_STARTER_CTIMER3_MASK              (0x2000U)
#define SYSCON_STARTER_CTIMER3_SHIFT             (13U)
/*! CTIMER3 - Standard counter/timer CTIMER3 wake-up. 0 = Wake-up disabled. 1 = Wake-up
 *    enabled.Typically used in sleep mode only since the peripheral clock must be running for it to function.
 */
#define SYSCON_STARTER_CTIMER3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER3_SHIFT)) & SYSCON_STARTER_CTIMER3_MASK)

#define SYSCON_STARTER_FLEXCOMM0_MASK            (0x4000U)
#define SYSCON_STARTER_FLEXCOMM0_SHIFT           (14U)
/*! FLEXCOMM0 - Flexcomm0 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM0_SHIFT)) & SYSCON_STARTER_FLEXCOMM0_MASK)

#define SYSCON_STARTER_FLEXCOMM1_MASK            (0x8000U)
#define SYSCON_STARTER_FLEXCOMM1_SHIFT           (15U)
/*! FLEXCOMM1 - Flexcomm1 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM1_SHIFT)) & SYSCON_STARTER_FLEXCOMM1_MASK)

#define SYSCON_STARTER_FLEXCOMM2_MASK            (0x10000U)
#define SYSCON_STARTER_FLEXCOMM2_SHIFT           (16U)
/*! FLEXCOMM2 - Flexcomm2 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM2_SHIFT)) & SYSCON_STARTER_FLEXCOMM2_MASK)

#define SYSCON_STARTER_FLEXCOMM3_MASK            (0x20000U)
#define SYSCON_STARTER_FLEXCOMM3_SHIFT           (17U)
/*! FLEXCOMM3 - Flexcomm3 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM3_SHIFT)) & SYSCON_STARTER_FLEXCOMM3_MASK)

#define SYSCON_STARTER_FLEXCOMM4_MASK            (0x40000U)
#define SYSCON_STARTER_FLEXCOMM4_SHIFT           (18U)
/*! FLEXCOMM4 - Flexcomm4 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM4(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM4_SHIFT)) & SYSCON_STARTER_FLEXCOMM4_MASK)

#define SYSCON_STARTER_FLEXCOMM5_MASK            (0x80000U)
#define SYSCON_STARTER_FLEXCOMM5_SHIFT           (19U)
/*! FLEXCOMM5 - Flexcomm5 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM5(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM5_SHIFT)) & SYSCON_STARTER_FLEXCOMM5_MASK)

#define SYSCON_STARTER_FLEXCOMM6_MASK            (0x100000U)
#define SYSCON_STARTER_FLEXCOMM6_SHIFT           (20U)
/*! FLEXCOMM6 - Flexcomm6 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM6(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM6_SHIFT)) & SYSCON_STARTER_FLEXCOMM6_MASK)

#define SYSCON_STARTER_FLEXCOMM7_MASK            (0x200000U)
#define SYSCON_STARTER_FLEXCOMM7_SHIFT           (21U)
/*! FLEXCOMM7 - Flexcomm7 peripheral interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_FLEXCOMM7(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM7_SHIFT)) & SYSCON_STARTER_FLEXCOMM7_MASK)

#define SYSCON_STARTER_USB0_NEEDCLK_MASK         (0x8000000U)
#define SYSCON_STARTER_USB0_NEEDCLK_SHIFT        (27U)
/*! USB0_NEEDCLK - USB0 activity interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_USB0_NEEDCLK(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB0_NEEDCLK_SHIFT)) & SYSCON_STARTER_USB0_NEEDCLK_MASK)

#define SYSCON_STARTER_USB0_MASK                 (0x10000000U)
#define SYSCON_STARTER_USB0_SHIFT                (28U)
/*! USB0 - USB0 function interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_USB0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB0_SHIFT)) & SYSCON_STARTER_USB0_MASK)

#define SYSCON_STARTER_RTC_MASK                  (0x20000000U)
#define SYSCON_STARTER_RTC_SHIFT                 (29U)
/*! RTC - RTC interrupt alarm and wake-up timer. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_RTC(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_RTC_SHIFT)) & SYSCON_STARTER_RTC_MASK)
/*! @} */

/*! @name STARTERSET - Set bits in STARTERn */
/*! @{ */

#define SYSCON_STARTERSET_START_SET_MASK         (0xFFFFFFFFU)
#define SYSCON_STARTERSET_START_SET_SHIFT        (0U)
/*! START_SET - Writing ones to this register sets the corresponding bit or bits in the STARTERn
 *    register, if they are implemented. Bits that do not correspond to defined bits in STARTERn are
 *    reserved and only zeroes should be written to them.
 */
#define SYSCON_STARTERSET_START_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_START_SET_SHIFT)) & SYSCON_STARTERSET_START_SET_MASK)
/*! @} */

/*! @name STARTERCLR - Clear bits in STARTERn */
/*! @{ */

#define SYSCON_STARTERCLR_START_CLR_MASK         (0xFFFFFFFFU)
#define SYSCON_STARTERCLR_START_CLR_SHIFT        (0U)
/*! START_CLR - Writing ones to this register clears the corresponding bit or bits in the STARTERn
 *    register, if they are implemented. Bits that do not correspond to defined bits in STARTERn are
 *    reserved and only zeroes should be written to them.
 */
#define SYSCON_STARTERCLR_START_CLR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_START_CLR_SHIFT)) & SYSCON_STARTERCLR_START_CLR_MASK)
/*! @} */

/*! @name HWWAKE - Configures special cases of hardware wake-up */
/*! @{ */

#define SYSCON_HWWAKE_FORCEWAKE_MASK             (0x1U)
#define SYSCON_HWWAKE_FORCEWAKE_SHIFT            (0U)
/*! FORCEWAKE - Force peripheral clocking to stay on during Deep Sleep and Power-down modes. When 1,
 *    clocking to peripherals is prevented from being shut down when the CPU enters Deep Sleep and
 *    Power-down modes. This is intended to allow a coprocessor to continue operating while the main
 *    CPU(s) are shut down.
 */
#define SYSCON_HWWAKE_FORCEWAKE(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_HWWAKE_FORCEWAKE_SHIFT)) & SYSCON_HWWAKE_FORCEWAKE_MASK)

#define SYSCON_HWWAKE_FCWAKE_MASK                (0x2U)
#define SYSCON_HWWAKE_FCWAKE_SHIFT               (1U)
/*! FCWAKE - Wake for Flexcomms. When 1, any Flexcomm FIFO reaching the level specified by its own
 *    TXLVL will cause peripheral clocking to wake up temporarily while the related status is
 *    asserted.
 */
#define SYSCON_HWWAKE_FCWAKE(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_HWWAKE_FCWAKE_SHIFT)) & SYSCON_HWWAKE_FCWAKE_MASK)

#define SYSCON_HWWAKE_WAKEDMA_MASK               (0x8U)
#define SYSCON_HWWAKE_WAKEDMA_SHIFT              (3U)
/*! WAKEDMA - Wake for DMA. When 1, DMA being busy will cause peripheral clocking to remain running
 *    until DMA completes. This is generally used in conjunction with bit 1 and/or 2 in order to
 *    prevent peripheral clocking from being shut down as soon as the cause of wake-up is cleared, but
 *    before DMA has completed its related activity.
 */
#define SYSCON_HWWAKE_WAKEDMA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_HWWAKE_WAKEDMA_SHIFT)) & SYSCON_HWWAKE_WAKEDMA_MASK)
/*! @} */

/*! @name JTAGIDCODE - JTAG ID code register */
/*! @{ */

#define SYSCON_JTAGIDCODE_JTAGID_MASK            (0xFFFFFFFFU)
#define SYSCON_JTAGIDCODE_JTAGID_SHIFT           (0U)
/*! JTAGID - JTAG ID code. */
#define SYSCON_JTAGIDCODE_JTAGID(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAGIDCODE_JTAGID_SHIFT)) & SYSCON_JTAGIDCODE_JTAGID_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Part ID register */
/*! @{ */

#define SYSCON_DEVICE_ID0_PARTID_MASK            (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID0_PARTID_SHIFT           (0U)
/*! PARTID - Part ID */
#define SYSCON_DEVICE_ID0_PARTID(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_PARTID_SHIFT)) & SYSCON_DEVICE_ID0_PARTID_MASK)
/*! @} */

/*! @name DEVICE_ID1 - Boot ROM and die revision register */
/*! @{ */

#define SYSCON_DEVICE_ID1_REVID_MASK             (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID1_REVID_SHIFT            (0U)
/*! REVID - Revision. */
#define SYSCON_DEVICE_ID1_REVID(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID1_REVID_SHIFT)) & SYSCON_DEVICE_ID1_REVID_MASK)
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
 *  0b1..Enable interrupt function.
 */
#define SYSCON_BODCTRL_BODINTENA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODINTENA_SHIFT)) & SYSCON_BODCTRL_BODINTENA_MASK)

#define SYSCON_BODCTRL_BODRSTSTAT_MASK           (0x40U)
#define SYSCON_BODCTRL_BODRSTSTAT_SHIFT          (6U)
/*! BODRSTSTAT - BOD reset status. When 1, a BOD reset has occurred. Cleared by writing 1 to this bit. */
#define SYSCON_BODCTRL_BODRSTSTAT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_BODCTRL_BODRSTSTAT_SHIFT)) & SYSCON_BODCTRL_BODRSTSTAT_MASK)

#define SYSCON_BODCTRL_BODINTSTAT_MASK           (0x80U)
#define SYSCON_BODCTRL_BODINTSTAT_SHIFT          (7U)
/*! BODINTSTAT - BOD interrupt status. When 1, a BOD interrupt has occurred. Cleared by writing 1 to this bit. */
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

