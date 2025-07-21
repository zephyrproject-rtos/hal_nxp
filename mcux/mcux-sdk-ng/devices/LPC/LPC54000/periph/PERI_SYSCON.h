/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
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

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
#define SYSCON_PRESETCTRL_COUNT                   3u
#define SYSCON_PRESETCTRLSET_COUNT                3u
#define SYSCON_PRESETCTRLCLR_COUNT                3u
#define SYSCON_AHBCLKCTRL_COUNT                   3u
#define SYSCON_AHBCLKCTRLSET_COUNT                3u
#define SYSCON_AHBCLKCTRLCLR_COUNT                3u
#define SYSCON_FCLKSEL_COUNT                      10u
#define SYSCON_PDSLEEPCFG_COUNT                   2u
#define SYSCON_PDRUNCFG_COUNT                     2u
#define SYSCON_PDRUNCFGSET_COUNT                  2u
#define SYSCON_PDRUNCFGCLR_COUNT                  2u
#define SYSCON_STARTER_COUNT                      2u
#define SYSCON_STARTERSET_COUNT                   2u
#define SYSCON_STARTERCLR_COUNT                   2u

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
       uint8_t RESERVED_6[20];
  __O  uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Set bits in PRESETCTRLn, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_7[20];
  __O  uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Clear bits in PRESETCTRLn, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_8[164];
  __IO uint32_t SYSRSTSTAT;                        /**< System reset status register, offset: 0x1F0 */
       uint8_t RESERVED_9[12];
  __IO uint32_t AHBCLKCTRL[SYSCON_AHBCLKCTRL_COUNT]; /**< AHB Clock control n, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_10[20];
  __O  uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< Set bits in AHBCLKCTRLn, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_11[20];
  __O  uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< Clear bits in AHBCLKCTRLn, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_12[52];
  __IO uint32_t MAINCLKSELA;                       /**< Main clock source select A, offset: 0x280 */
  __IO uint32_t MAINCLKSELB;                       /**< Main clock source select B, offset: 0x284 */
  __IO uint32_t CLKOUTSELA;                        /**< CLKOUT clock source select A, offset: 0x288 */
       uint8_t RESERVED_13[4];
  __IO uint32_t SYSPLLCLKSEL;                      /**< PLL clock source select, offset: 0x290 */
       uint8_t RESERVED_14[4];
  __IO uint32_t AUDPLLCLKSEL;                      /**< Audio PLL clock source select, offset: 0x298 */
       uint8_t RESERVED_15[4];
  __IO uint32_t SPIFICLKSEL;                       /**< SPIFI clock source select, offset: 0x2A0 */
  __IO uint32_t ADCCLKSEL;                         /**< ADC clock source select, offset: 0x2A4 */
  __IO uint32_t USB0CLKSEL;                        /**< USB0 clock source select, offset: 0x2A8 */
  __IO uint32_t USB1CLKSEL;                        /**< USB1 clock source select, offset: 0x2AC */
  __IO uint32_t FCLKSEL[SYSCON_FCLKSEL_COUNT];     /**< Flexcomm 0 clock source select, array offset: 0x2B0, array step: 0x4 */
       uint8_t RESERVED_16[8];
  __IO uint32_t MCLKCLKSEL;                        /**< MCLK clock source select, offset: 0x2E0 */
       uint8_t RESERVED_17[4];
  __IO uint32_t FRGCLKSEL;                         /**< Fractional Rate Generator clock source select, offset: 0x2E8 */
  __IO uint32_t DMICCLKSEL;                        /**< Digital microphone (DMIC) subsystem clock select, offset: 0x2EC */
  __IO uint32_t SCTCLKSEL;                         /**< SCTimer/PWM clock source select, offset: 0x2F0 */
  __IO uint32_t LCDCLKSEL;                         /**< LCD clock source select, offset: 0x2F4 */
  __IO uint32_t SDIOCLKSEL;                        /**< SDIO clock source select, offset: 0x2F8 */
       uint8_t RESERVED_18[4];
  __IO uint32_t SYSTICKCLKDIV;                     /**< SYSTICK clock divider, offset: 0x300 */
  __IO uint32_t ARMTRACECLKDIV;                    /**< ARM Trace clock divider, offset: 0x304 */
  __IO uint32_t CAN0CLKDIV;                        /**< MCAN0 clock divider, offset: 0x308 */
  __IO uint32_t CAN1CLKDIV;                        /**< MCAN1 clock divider, offset: 0x30C */
  __IO uint32_t SC0CLKDIV;                         /**< Smartcard0 clock divider, offset: 0x310 */
  __IO uint32_t SC1CLKDIV;                         /**< Smartcard1 clock divider, offset: 0x314 */
       uint8_t RESERVED_19[104];
  __IO uint32_t AHBCLKDIV;                         /**< AHB clock divider, offset: 0x380 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider, offset: 0x384 */
  __IO uint32_t FROHFCLKDIV;                       /**< FROHF clock divider, offset: 0x388 */
       uint8_t RESERVED_20[4];
  __IO uint32_t SPIFICLKDIV;                       /**< SPIFI clock divider, offset: 0x390 */
  __IO uint32_t ADCCLKDIV;                         /**< ADC clock divider, offset: 0x394 */
  __IO uint32_t USB0CLKDIV;                        /**< USB0 clock divider, offset: 0x398 */
  __IO uint32_t USB1CLKDIV;                        /**< USB1 clock divider, offset: 0x39C */
  __IO uint32_t FRGCTRL;                           /**< Fractional rate divider, offset: 0x3A0 */
       uint8_t RESERVED_21[4];
  __IO uint32_t DMICCLKDIV;                        /**< DMIC clock divider, offset: 0x3A8 */
  __IO uint32_t MCLKDIV;                           /**< I2S MCLK clock divider, offset: 0x3AC */
  __IO uint32_t LCDCLKDIV;                         /**< LCD clock divider, offset: 0x3B0 */
  __IO uint32_t SCTCLKDIV;                         /**< SCT/PWM clock divider, offset: 0x3B4 */
  __IO uint32_t EMCCLKDIV;                         /**< EMC clock divider, offset: 0x3B8 */
  __IO uint32_t SDIOCLKDIV;                        /**< SDIO clock divider, offset: 0x3BC */
       uint8_t RESERVED_22[64];
  __IO uint32_t FLASHCFG;                          /**< Flash wait states configuration, offset: 0x400 */
       uint8_t RESERVED_23[8];
  __IO uint32_t USB0CLKCTRL;                       /**< USB0 clock control, offset: 0x40C */
  __IO uint32_t USB0CLKSTAT;                       /**< USB0 clock status, offset: 0x410 */
       uint8_t RESERVED_24[4];
  __IO uint32_t FREQMECTRL;                        /**< Frequency measure register, offset: 0x418 */
       uint8_t RESERVED_25[4];
  __IO uint32_t MCLKIO;                            /**< MCLK input/output control, offset: 0x420 */
  __IO uint32_t USB1CLKCTRL;                       /**< USB1 clock control, offset: 0x424 */
  __IO uint32_t USB1CLKSTAT;                       /**< USB1 clock status, offset: 0x428 */
       uint8_t RESERVED_26[24];
  __IO uint32_t EMCSYSCTRL;                        /**< EMC system control, offset: 0x444 */
  __IO uint32_t EMCDLYCTRL;                        /**< EMC clock delay control, offset: 0x448 */
  __IO uint32_t EMCDLYCAL;                         /**< EMC delay chain calibration control, offset: 0x44C */
  __IO uint32_t ETHPHYSEL;                         /**< Ethernet PHY Selection, offset: 0x450 */
  __IO uint32_t ETHSBDCTRL;                        /**< Ethernet SBD flow control, offset: 0x454 */
       uint8_t RESERVED_27[8];
  __IO uint32_t SDIOCLKCTRL;                       /**< SDIO CCLKIN phase and delay control, offset: 0x460 */
       uint8_t RESERVED_28[156];
  __IO uint32_t FROCTRL;                           /**< FRO oscillator control, offset: 0x500 */
  __IO uint32_t SYSOSCCTRL;                        /**< System oscillator control, offset: 0x504 */
  __IO uint32_t WDTOSCCTRL;                        /**< Watchdog oscillator control, offset: 0x508 */
  __IO uint32_t RTCOSCCTRL;                        /**< RTC oscillator 32 kHz output control, offset: 0x50C */
       uint8_t RESERVED_29[12];
  __IO uint32_t USBPLLCTRL;                        /**< USB PLL control, offset: 0x51C */
  __IO uint32_t USBPLLSTAT;                        /**< USB PLL status, offset: 0x520 */
       uint8_t RESERVED_30[92];
  __IO uint32_t SYSPLLCTRL;                        /**< System PLL control, offset: 0x580 */
  __IO uint32_t SYSPLLSTAT;                        /**< PLL status, offset: 0x584 */
  __IO uint32_t SYSPLLNDEC;                        /**< PLL N divider, offset: 0x588 */
  __IO uint32_t SYSPLLPDEC;                        /**< PLL P divider, offset: 0x58C */
  __IO uint32_t SYSPLLMDEC;                        /**< System PLL M divider, offset: 0x590 */
       uint8_t RESERVED_31[12];
  __IO uint32_t AUDPLLCTRL;                        /**< Audio PLL control, offset: 0x5A0 */
  __IO uint32_t AUDPLLSTAT;                        /**< Audio PLL status, offset: 0x5A4 */
  __IO uint32_t AUDPLLNDEC;                        /**< Audio PLL N divider, offset: 0x5A8 */
  __IO uint32_t AUDPLLPDEC;                        /**< Audio PLL P divider, offset: 0x5AC */
  __IO uint32_t AUDPLLMDEC;                        /**< Audio PLL M divider, offset: 0x5B0 */
  __IO uint32_t AUDPLLFRAC;                        /**< Audio PLL fractional divider control, offset: 0x5B4 */
       uint8_t RESERVED_32[72];
  __IO uint32_t PDSLEEPCFG[SYSCON_PDSLEEPCFG_COUNT]; /**< Sleep configuration register, array offset: 0x600, array step: 0x4 */
       uint8_t RESERVED_33[8];
  __IO uint32_t PDRUNCFG[SYSCON_PDRUNCFG_COUNT];   /**< Power configuration register, array offset: 0x610, array step: 0x4 */
       uint8_t RESERVED_34[8];
  __IO uint32_t PDRUNCFGSET[SYSCON_PDRUNCFGSET_COUNT]; /**< Power configuration set register, array offset: 0x620, array step: 0x4 */
       uint8_t RESERVED_35[8];
  __IO uint32_t PDRUNCFGCLR[SYSCON_PDRUNCFGCLR_COUNT]; /**< Power configuration clear register, array offset: 0x630, array step: 0x4 */
       uint8_t RESERVED_36[72];
  __IO uint32_t STARTER[SYSCON_STARTER_COUNT];     /**< Start logic 0 wake-up enable register, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_37[24];
  __O  uint32_t STARTERSET[SYSCON_STARTERSET_COUNT]; /**< Set bits in STARTER, array offset: 0x6A0, array step: 0x4 */
       uint8_t RESERVED_38[24];
  __O  uint32_t STARTERCLR[SYSCON_STARTERCLR_COUNT]; /**< Clear bits in STARTER0, array offset: 0x6C0, array step: 0x4 */
       uint8_t RESERVED_39[184];
  __IO uint32_t HWWAKE;                            /**< Configures special cases of hardware wake-up, offset: 0x780 */
       uint8_t RESERVED_40[1664];
  __IO uint32_t AUTOCGOR;                          /**< Auto Clock-Gate Override Register, offset: 0xE04 */
       uint8_t RESERVED_41[492];
  __I  uint32_t JTAGIDCODE;                        /**< JTAG ID code register, offset: 0xFF4 */
  __I  uint32_t DEVICE_ID0;                        /**< Part ID register, offset: 0xFF8 */
  __I  uint32_t DEVICE_ID1;                        /**< Boot ROM and die revision register, offset: 0xFFC */
       uint8_t RESERVED_42[127044];
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
/*! PRI_ICODE - I-Code bus priority. */
#define SYSCON_AHBMATPRIO_PRI_ICODE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_ICODE_SHIFT)) & SYSCON_AHBMATPRIO_PRI_ICODE_MASK)

#define SYSCON_AHBMATPRIO_PRI_DCODE_MASK         (0xCU)
#define SYSCON_AHBMATPRIO_PRI_DCODE_SHIFT        (2U)
/*! PRI_DCODE - D-Code bus priority. */
#define SYSCON_AHBMATPRIO_PRI_DCODE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_DCODE_SHIFT)) & SYSCON_AHBMATPRIO_PRI_DCODE_MASK)

#define SYSCON_AHBMATPRIO_PRI_SYS_MASK           (0x30U)
#define SYSCON_AHBMATPRIO_PRI_SYS_SHIFT          (4U)
/*! PRI_SYS - System bus priority. */
#define SYSCON_AHBMATPRIO_PRI_SYS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SYS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SYS_MASK)

#define SYSCON_AHBMATPRIO_PRI_DMA_MASK           (0x3C0U)
#define SYSCON_AHBMATPRIO_PRI_DMA_SHIFT          (6U)
/*! PRI_DMA - DMA controller priority. */
#define SYSCON_AHBMATPRIO_PRI_DMA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_DMA_SHIFT)) & SYSCON_AHBMATPRIO_PRI_DMA_MASK)

#define SYSCON_AHBMATPRIO_PRI_ETH_MASK           (0xC00U)
#define SYSCON_AHBMATPRIO_PRI_ETH_SHIFT          (10U)
/*! PRI_ETH - Ethernet DMA priority. */
#define SYSCON_AHBMATPRIO_PRI_ETH(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_ETH_SHIFT)) & SYSCON_AHBMATPRIO_PRI_ETH_MASK)

#define SYSCON_AHBMATPRIO_PRI_LCD_MASK           (0x3000U)
#define SYSCON_AHBMATPRIO_PRI_LCD_SHIFT          (12U)
/*! PRI_LCD - LCD DMA priority. */
#define SYSCON_AHBMATPRIO_PRI_LCD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_LCD_SHIFT)) & SYSCON_AHBMATPRIO_PRI_LCD_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB0_MASK          (0xC000U)
#define SYSCON_AHBMATPRIO_PRI_USB0_SHIFT         (14U)
/*! PRI_USB0 - USB0 DMA priority. */
#define SYSCON_AHBMATPRIO_PRI_USB0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB0_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB0_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB1_MASK          (0x30000U)
#define SYSCON_AHBMATPRIO_PRI_USB1_SHIFT         (16U)
/*! PRI_USB1 - USB1 DMA priority. */
#define SYSCON_AHBMATPRIO_PRI_USB1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB1_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB1_MASK)

#define SYSCON_AHBMATPRIO_PRI_SDIO_MASK          (0xC0000U)
#define SYSCON_AHBMATPRIO_PRI_SDIO_SHIFT         (18U)
/*! PRI_SDIO - SDIO priority. */
#define SYSCON_AHBMATPRIO_PRI_SDIO(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SDIO_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SDIO_MASK)

#define SYSCON_AHBMATPRIO_PRI_MCAN1_MASK         (0x300000U)
#define SYSCON_AHBMATPRIO_PRI_MCAN1_SHIFT        (20U)
/*! PRI_MCAN1 - MCAN1 priority. */
#define SYSCON_AHBMATPRIO_PRI_MCAN1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_MCAN1_SHIFT)) & SYSCON_AHBMATPRIO_PRI_MCAN1_MASK)

#define SYSCON_AHBMATPRIO_PRI_MCAN2_MASK         (0xC00000U)
#define SYSCON_AHBMATPRIO_PRI_MCAN2_SHIFT        (22U)
/*! PRI_MCAN2 - MCAN2 priority. */
#define SYSCON_AHBMATPRIO_PRI_MCAN2(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_MCAN2_SHIFT)) & SYSCON_AHBMATPRIO_PRI_MCAN2_MASK)

#define SYSCON_AHBMATPRIO_PRI_SHA_MASK           (0x3000000U)
#define SYSCON_AHBMATPRIO_PRI_SHA_SHIFT          (24U)
/*! PRI_SHA - SHA priority. */
#define SYSCON_AHBMATPRIO_PRI_SHA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SHA_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SHA_MASK)
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

#define SYSCON_PRESETCTRL_MRT_RST_MASK           (0x1U)
#define SYSCON_PRESETCTRL_MRT_RST_SHIFT          (0U)
/*! MRT_RST - Multi-rate timer (MRT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_MRT_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MRT_RST_SHIFT)) & SYSCON_PRESETCTRL_MRT_RST_MASK)

#define SYSCON_PRESETCTRL_LCD_RST_MASK           (0x4U)
#define SYSCON_PRESETCTRL_LCD_RST_SHIFT          (2U)
/*! LCD_RST - LCD reset control. */
#define SYSCON_PRESETCTRL_LCD_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_LCD_RST_SHIFT)) & SYSCON_PRESETCTRL_LCD_RST_MASK)

#define SYSCON_PRESETCTRL_SCT0_RST_MASK          (0x4U)
#define SYSCON_PRESETCTRL_SCT0_RST_SHIFT         (2U)
/*! SCT0_RST - State configurable timer 0 (SCT0) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_SCT0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SCT0_RST_SHIFT)) & SYSCON_PRESETCTRL_SCT0_RST_MASK)

#define SYSCON_PRESETCTRL_SDIO_RST_MASK          (0x8U)
#define SYSCON_PRESETCTRL_SDIO_RST_SHIFT         (3U)
/*! SDIO_RST - SDIO reset control. */
#define SYSCON_PRESETCTRL_SDIO_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SDIO_RST_SHIFT)) & SYSCON_PRESETCTRL_SDIO_RST_MASK)

#define SYSCON_PRESETCTRL_USB1H_RST_MASK         (0x10U)
#define SYSCON_PRESETCTRL_USB1H_RST_SHIFT        (4U)
/*! USB1H_RST - USB1 Host reset control. */
#define SYSCON_PRESETCTRL_USB1H_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB1H_RST_SHIFT)) & SYSCON_PRESETCTRL_USB1H_RST_MASK)

#define SYSCON_PRESETCTRL_USB1D_RST_MASK         (0x20U)
#define SYSCON_PRESETCTRL_USB1D_RST_SHIFT        (5U)
/*! USB1D_RST - USB1 Device reset control. */
#define SYSCON_PRESETCTRL_USB1D_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB1D_RST_SHIFT)) & SYSCON_PRESETCTRL_USB1D_RST_MASK)

#define SYSCON_PRESETCTRL_USB1RAM_RST_MASK       (0x40U)
#define SYSCON_PRESETCTRL_USB1RAM_RST_SHIFT      (6U)
/*! USB1RAM_RST - USB1 RAM reset control. */
#define SYSCON_PRESETCTRL_USB1RAM_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB1RAM_RST_SHIFT)) & SYSCON_PRESETCTRL_USB1RAM_RST_MASK)

#define SYSCON_PRESETCTRL_EMC_RESET_MASK         (0x80U)
#define SYSCON_PRESETCTRL_EMC_RESET_SHIFT        (7U)
/*! EMC_RESET - EMC reset control. */
#define SYSCON_PRESETCTRL_EMC_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_EMC_RESET_SHIFT)) & SYSCON_PRESETCTRL_EMC_RESET_MASK)

#define SYSCON_PRESETCTRL_FLASH_RST_MASK         (0x80U)
#define SYSCON_PRESETCTRL_FLASH_RST_SHIFT        (7U)
/*! FLASH_RST - Flash controller reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FLASH_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FLASH_RST_SHIFT)) & SYSCON_PRESETCTRL_FLASH_RST_MASK)

#define SYSCON_PRESETCTRL_MCAN0_RST_MASK         (0x80U)
#define SYSCON_PRESETCTRL_MCAN0_RST_SHIFT        (7U)
/*! MCAN0_RST - 0 = Clear reset to this function. */
#define SYSCON_PRESETCTRL_MCAN0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MCAN0_RST_SHIFT)) & SYSCON_PRESETCTRL_MCAN0_RST_MASK)

#define SYSCON_PRESETCTRL_ETH_RST_MASK           (0x100U)
#define SYSCON_PRESETCTRL_ETH_RST_SHIFT          (8U)
/*! ETH_RST - Ethernet reset control. */
#define SYSCON_PRESETCTRL_ETH_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_ETH_RST_SHIFT)) & SYSCON_PRESETCTRL_ETH_RST_MASK)

#define SYSCON_PRESETCTRL_FMC_RST_MASK           (0x100U)
#define SYSCON_PRESETCTRL_FMC_RST_SHIFT          (8U)
/*! FMC_RST - Flash accelerator reset control. Note that the FMC must not be reset while executing
 *    from flash, and must be reconfigured after reset. 0 = Clear reset to this function. 1 = Assert
 *    reset to this function.
 */
#define SYSCON_PRESETCTRL_FMC_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FMC_RST_SHIFT)) & SYSCON_PRESETCTRL_FMC_RST_MASK)

#define SYSCON_PRESETCTRL_MCAN1_RST_MASK         (0x100U)
#define SYSCON_PRESETCTRL_MCAN1_RST_SHIFT        (8U)
/*! MCAN1_RST - 0 = Clear reset to this function. */
#define SYSCON_PRESETCTRL_MCAN1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_MCAN1_RST_SHIFT)) & SYSCON_PRESETCTRL_MCAN1_RST_MASK)

#define SYSCON_PRESETCTRL_EEPROM_RST_MASK        (0x200U)
#define SYSCON_PRESETCTRL_EEPROM_RST_SHIFT       (9U)
/*! EEPROM_RST - EEPROM reset control. */
#define SYSCON_PRESETCTRL_EEPROM_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_EEPROM_RST_SHIFT)) & SYSCON_PRESETCTRL_EEPROM_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO4_RST_MASK         (0x200U)
#define SYSCON_PRESETCTRL_GPIO4_RST_SHIFT        (9U)
/*! GPIO4_RST - GPIO4 reset control. */
#define SYSCON_PRESETCTRL_GPIO4_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO4_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO4_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO5_RST_MASK         (0x400U)
#define SYSCON_PRESETCTRL_GPIO5_RST_SHIFT        (10U)
/*! GPIO5_RST - GPIO5 reset control. */
#define SYSCON_PRESETCTRL_GPIO5_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO5_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO5_RST_MASK)

#define SYSCON_PRESETCTRL_SPIFI_RST_MASK         (0x400U)
#define SYSCON_PRESETCTRL_SPIFI_RST_SHIFT        (10U)
/*! SPIFI_RST - SPIFI reset control. */
#define SYSCON_PRESETCTRL_SPIFI_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SPIFI_RST_SHIFT)) & SYSCON_PRESETCTRL_SPIFI_RST_MASK)

#define SYSCON_PRESETCTRL_UTICK_RST_MASK         (0x400U)
#define SYSCON_PRESETCTRL_UTICK_RST_SHIFT        (10U)
/*! UTICK_RST - Micro-tick Timer reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_UTICK_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_UTICK_RST_SHIFT)) & SYSCON_PRESETCTRL_UTICK_RST_MASK)

#define SYSCON_PRESETCTRL_AES_RST_MASK           (0x800U)
#define SYSCON_PRESETCTRL_AES_RST_SHIFT          (11U)
/*! AES_RST - AES reset control. */
#define SYSCON_PRESETCTRL_AES_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_AES_RST_SHIFT)) & SYSCON_PRESETCTRL_AES_RST_MASK)

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

#define SYSCON_PRESETCTRL_OTP_RST_MASK           (0x1000U)
#define SYSCON_PRESETCTRL_OTP_RST_SHIFT          (12U)
/*! OTP_RST - OTP reset control. */
#define SYSCON_PRESETCTRL_OTP_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_OTP_RST_SHIFT)) & SYSCON_PRESETCTRL_OTP_RST_MASK)

#define SYSCON_PRESETCTRL_FC2_RST_MASK           (0x2000U)
#define SYSCON_PRESETCTRL_FC2_RST_SHIFT          (13U)
/*! FC2_RST - Flexcomm 2 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC2_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC2_RST_SHIFT)) & SYSCON_PRESETCTRL_FC2_RST_MASK)

#define SYSCON_PRESETCTRL_IOCON_RST_MASK         (0x2000U)
#define SYSCON_PRESETCTRL_IOCON_RST_SHIFT        (13U)
/*! IOCON_RST - IOCON reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_IOCON_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_IOCON_RST_SHIFT)) & SYSCON_PRESETCTRL_IOCON_RST_MASK)

#define SYSCON_PRESETCTRL_RNG_RST_MASK           (0x2000U)
#define SYSCON_PRESETCTRL_RNG_RST_SHIFT          (13U)
/*! RNG_RST - RNG reset control. */
#define SYSCON_PRESETCTRL_RNG_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_RNG_RST_SHIFT)) & SYSCON_PRESETCTRL_RNG_RST_MASK)

#define SYSCON_PRESETCTRL_FC3_RST_MASK           (0x4000U)
#define SYSCON_PRESETCTRL_FC3_RST_SHIFT          (14U)
/*! FC3_RST - Flexcomm 3 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC3_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC3_RST_SHIFT)) & SYSCON_PRESETCTRL_FC3_RST_MASK)

#define SYSCON_PRESETCTRL_FC8_RST_MASK           (0x4000U)
#define SYSCON_PRESETCTRL_FC8_RST_SHIFT          (14U)
/*! FC8_RST - Flexcomm 8 reset control. */
#define SYSCON_PRESETCTRL_FC8_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC8_RST_SHIFT)) & SYSCON_PRESETCTRL_FC8_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO0_RST_MASK         (0x4000U)
#define SYSCON_PRESETCTRL_GPIO0_RST_SHIFT        (14U)
/*! GPIO0_RST - GPIO0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GPIO0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO0_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO0_RST_MASK)

#define SYSCON_PRESETCTRL_FC4_RST_MASK           (0x8000U)
#define SYSCON_PRESETCTRL_FC4_RST_SHIFT          (15U)
/*! FC4_RST - Flexcomm 4 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC4_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC4_RST_SHIFT)) & SYSCON_PRESETCTRL_FC4_RST_MASK)

#define SYSCON_PRESETCTRL_FC9_RST_MASK           (0x8000U)
#define SYSCON_PRESETCTRL_FC9_RST_SHIFT          (15U)
/*! FC9_RST - Flexcomm 9 reset control. */
#define SYSCON_PRESETCTRL_FC9_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC9_RST_SHIFT)) & SYSCON_PRESETCTRL_FC9_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO1_RST_MASK         (0x8000U)
#define SYSCON_PRESETCTRL_GPIO1_RST_SHIFT        (15U)
/*! GPIO1_RST - GPIO1 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GPIO1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO1_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO1_RST_MASK)

#define SYSCON_PRESETCTRL_FC5_RST_MASK           (0x10000U)
#define SYSCON_PRESETCTRL_FC5_RST_SHIFT          (16U)
/*! FC5_RST - Flexcomm 5 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC5_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC5_RST_SHIFT)) & SYSCON_PRESETCTRL_FC5_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO2_RST_MASK         (0x10000U)
#define SYSCON_PRESETCTRL_GPIO2_RST_SHIFT        (16U)
/*! GPIO2_RST - GPIO2 reset control. */
#define SYSCON_PRESETCTRL_GPIO2_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO2_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO2_RST_MASK)

#define SYSCON_PRESETCTRL_USB0HMR_RST_MASK       (0x10000U)
#define SYSCON_PRESETCTRL_USB0HMR_RST_SHIFT      (16U)
/*! USB0HMR_RST - USB0 HOST master reset control. */
#define SYSCON_PRESETCTRL_USB0HMR_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB0HMR_RST_SHIFT)) & SYSCON_PRESETCTRL_USB0HMR_RST_MASK)

#define SYSCON_PRESETCTRL_FC6_RST_MASK           (0x20000U)
#define SYSCON_PRESETCTRL_FC6_RST_SHIFT          (17U)
/*! FC6_RST - Flexcomm 6 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC6_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC6_RST_SHIFT)) & SYSCON_PRESETCTRL_FC6_RST_MASK)

#define SYSCON_PRESETCTRL_GPIO3_RST_MASK         (0x20000U)
#define SYSCON_PRESETCTRL_GPIO3_RST_SHIFT        (17U)
/*! GPIO3_RST - GPIO3 reset control. */
#define SYSCON_PRESETCTRL_GPIO3_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GPIO3_RST_SHIFT)) & SYSCON_PRESETCTRL_GPIO3_RST_MASK)

#define SYSCON_PRESETCTRL_USB0HSL_RST_MASK       (0x20000U)
#define SYSCON_PRESETCTRL_USB0HSL_RST_SHIFT      (17U)
/*! USB0HSL_RST - USB0 HOST slave reset control. */
#define SYSCON_PRESETCTRL_USB0HSL_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB0HSL_RST_SHIFT)) & SYSCON_PRESETCTRL_USB0HSL_RST_MASK)

#define SYSCON_PRESETCTRL_FC7_RST_MASK           (0x40000U)
#define SYSCON_PRESETCTRL_FC7_RST_SHIFT          (18U)
/*! FC7_RST - Flexcomm 7 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_FC7_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_FC7_RST_SHIFT)) & SYSCON_PRESETCTRL_FC7_RST_MASK)

#define SYSCON_PRESETCTRL_PINT_RST_MASK          (0x40000U)
#define SYSCON_PRESETCTRL_PINT_RST_SHIFT         (18U)
/*! PINT_RST - Pin interrupt (PINT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_PINT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_PINT_RST_SHIFT)) & SYSCON_PRESETCTRL_PINT_RST_MASK)

#define SYSCON_PRESETCTRL_SHA_RST_MASK           (0x40000U)
#define SYSCON_PRESETCTRL_SHA_RST_SHIFT          (18U)
/*! SHA_RST - SHA reset control. */
#define SYSCON_PRESETCTRL_SHA_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SHA_RST_SHIFT)) & SYSCON_PRESETCTRL_SHA_RST_MASK)

#define SYSCON_PRESETCTRL_DMIC_RST_MASK          (0x80000U)
#define SYSCON_PRESETCTRL_DMIC_RST_SHIFT         (19U)
/*! DMIC_RST - Digital microphone interface reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_DMIC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_DMIC_RST_SHIFT)) & SYSCON_PRESETCTRL_DMIC_RST_MASK)

#define SYSCON_PRESETCTRL_GINT_RST_MASK          (0x80000U)
#define SYSCON_PRESETCTRL_GINT_RST_SHIFT         (19U)
/*! GINT_RST - Grouped interrupt (GINT) reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_GINT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_GINT_RST_SHIFT)) & SYSCON_PRESETCTRL_GINT_RST_MASK)

#define SYSCON_PRESETCTRL_SC0_RST_MASK           (0x80000U)
#define SYSCON_PRESETCTRL_SC0_RST_SHIFT          (19U)
/*! SC0_RST - Smart card 0 reset control. */
#define SYSCON_PRESETCTRL_SC0_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SC0_RST_SHIFT)) & SYSCON_PRESETCTRL_SC0_RST_MASK)

#define SYSCON_PRESETCTRL_DMA0_RST_MASK          (0x100000U)
#define SYSCON_PRESETCTRL_DMA0_RST_SHIFT         (20U)
/*! DMA0_RST - DMA0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_DMA0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_DMA0_RST_SHIFT)) & SYSCON_PRESETCTRL_DMA0_RST_MASK)

#define SYSCON_PRESETCTRL_SC1_RST_MASK           (0x100000U)
#define SYSCON_PRESETCTRL_SC1_RST_SHIFT          (20U)
/*! SC1_RST - Smart card 1 reset control. */
#define SYSCON_PRESETCTRL_SC1_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_SC1_RST_SHIFT)) & SYSCON_PRESETCTRL_SC1_RST_MASK)

#define SYSCON_PRESETCTRL_CRC_RST_MASK           (0x200000U)
#define SYSCON_PRESETCTRL_CRC_RST_SHIFT          (21U)
/*! CRC_RST - CRC generator reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_CRC_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CRC_RST_SHIFT)) & SYSCON_PRESETCTRL_CRC_RST_MASK)

#define SYSCON_PRESETCTRL_CTIMER2_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL_CTIMER2_RST_SHIFT      (22U)
/*! CTIMER2_RST - CTIMER2 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function */
#define SYSCON_PRESETCTRL_CTIMER2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_CTIMER2_RST_SHIFT)) & SYSCON_PRESETCTRL_CTIMER2_RST_MASK)

#define SYSCON_PRESETCTRL_WWDT_RST_MASK          (0x400000U)
#define SYSCON_PRESETCTRL_WWDT_RST_SHIFT         (22U)
/*! WWDT_RST - Watchdog timer reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_WWDT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_WWDT_RST_SHIFT)) & SYSCON_PRESETCTRL_WWDT_RST_MASK)

#define SYSCON_PRESETCTRL_USB0D_RST_MASK         (0x2000000U)
#define SYSCON_PRESETCTRL_USB0D_RST_SHIFT        (25U)
/*! USB0D_RST - USB0 reset control. 0 = Clear reset to this function. 1 = Assert reset to this function. */
#define SYSCON_PRESETCTRL_USB0D_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL_USB0D_RST_SHIFT)) & SYSCON_PRESETCTRL_USB0D_RST_MASK)

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

#define SYSCON_AHBCLKCTRL_MRT_MASK               (0x1U)
#define SYSCON_AHBCLKCTRL_MRT_SHIFT              (0U)
/*! MRT - Enables the clock for the Multi-Rate Timer. */
#define SYSCON_AHBCLKCTRL_MRT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_MRT_SHIFT)) & SYSCON_AHBCLKCTRL_MRT_MASK)

#define SYSCON_AHBCLKCTRL_RIT_MASK               (0x2U)
#define SYSCON_AHBCLKCTRL_RIT_SHIFT              (1U)
/*! RIT - Enables the clock for the Repetitive Interrupt Timer. */
#define SYSCON_AHBCLKCTRL_RIT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_RIT_SHIFT)) & SYSCON_AHBCLKCTRL_RIT_MASK)

#define SYSCON_AHBCLKCTRL_ROM_MASK               (0x2U)
#define SYSCON_AHBCLKCTRL_ROM_SHIFT              (1U)
/*! ROM - Enables the clock for the Boot ROM. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_ROM(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_ROM_SHIFT)) & SYSCON_AHBCLKCTRL_ROM_MASK)

#define SYSCON_AHBCLKCTRL_LCD_MASK               (0x4U)
#define SYSCON_AHBCLKCTRL_LCD_SHIFT              (2U)
/*! LCD - Enables the clock for the LCD interface. */
#define SYSCON_AHBCLKCTRL_LCD(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_LCD_SHIFT)) & SYSCON_AHBCLKCTRL_LCD_MASK)

#define SYSCON_AHBCLKCTRL_SCT0_MASK              (0x4U)
#define SYSCON_AHBCLKCTRL_SCT0_SHIFT             (2U)
/*! SCT0 - Enables the clock for SCT0. */
#define SYSCON_AHBCLKCTRL_SCT0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SCT0_SHIFT)) & SYSCON_AHBCLKCTRL_SCT0_MASK)

#define SYSCON_AHBCLKCTRL_SDIO_MASK              (0x8U)
#define SYSCON_AHBCLKCTRL_SDIO_SHIFT             (3U)
/*! SDIO - Enables the clock for the SDIO interface. */
#define SYSCON_AHBCLKCTRL_SDIO(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SDIO_SHIFT)) & SYSCON_AHBCLKCTRL_SDIO_MASK)

#define SYSCON_AHBCLKCTRL_SRAM1_MASK             (0x8U)
#define SYSCON_AHBCLKCTRL_SRAM1_SHIFT            (3U)
/*! SRAM1 - Enables the clock for SRAM1. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SRAM1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SRAM1_SHIFT)) & SYSCON_AHBCLKCTRL_SRAM1_MASK)

#define SYSCON_AHBCLKCTRL_SRAM2_MASK             (0x10U)
#define SYSCON_AHBCLKCTRL_SRAM2_SHIFT            (4U)
/*! SRAM2 - Enables the clock for SRAM2. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SRAM2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SRAM2_SHIFT)) & SYSCON_AHBCLKCTRL_SRAM2_MASK)

#define SYSCON_AHBCLKCTRL_USB1H_MASK             (0x10U)
#define SYSCON_AHBCLKCTRL_USB1H_SHIFT            (4U)
/*! USB1H - Enables the clock for the USB1 host interface. */
#define SYSCON_AHBCLKCTRL_USB1H(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB1H_SHIFT)) & SYSCON_AHBCLKCTRL_USB1H_MASK)

#define SYSCON_AHBCLKCTRL_SRAM3_MASK             (0x20U)
#define SYSCON_AHBCLKCTRL_SRAM3_SHIFT            (5U)
/*! SRAM3 - Enables the clock for SRAM3. */
#define SYSCON_AHBCLKCTRL_SRAM3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SRAM3_SHIFT)) & SYSCON_AHBCLKCTRL_SRAM3_MASK)

#define SYSCON_AHBCLKCTRL_USB1D_MASK             (0x20U)
#define SYSCON_AHBCLKCTRL_USB1D_SHIFT            (5U)
/*! USB1D - Enables the clock for the USB1 device interface. */
#define SYSCON_AHBCLKCTRL_USB1D(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB1D_SHIFT)) & SYSCON_AHBCLKCTRL_USB1D_MASK)

#define SYSCON_AHBCLKCTRL_USB1RAM_MASK           (0x40U)
#define SYSCON_AHBCLKCTRL_USB1RAM_SHIFT          (6U)
/*! USB1RAM - Enables the clock for the USB1 RAM interface. */
#define SYSCON_AHBCLKCTRL_USB1RAM(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB1RAM_SHIFT)) & SYSCON_AHBCLKCTRL_USB1RAM_MASK)

#define SYSCON_AHBCLKCTRL_EMC_MASK               (0x80U)
#define SYSCON_AHBCLKCTRL_EMC_SHIFT              (7U)
/*! EMC - Enables the clock for the EMC interface. */
#define SYSCON_AHBCLKCTRL_EMC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_EMC_SHIFT)) & SYSCON_AHBCLKCTRL_EMC_MASK)

#define SYSCON_AHBCLKCTRL_FLASH_MASK             (0x80U)
#define SYSCON_AHBCLKCTRL_FLASH_SHIFT            (7U)
/*! FLASH - Enables the clock for the flash controller. 0 = Disable; 1 = Enable. This clock is
 *    needed for flash programming, not for flash read.
 */
#define SYSCON_AHBCLKCTRL_FLASH(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLASH_SHIFT)) & SYSCON_AHBCLKCTRL_FLASH_MASK)

#define SYSCON_AHBCLKCTRL_MCAN0_MASK             (0x80U)
#define SYSCON_AHBCLKCTRL_MCAN0_SHIFT            (7U)
/*! MCAN0 - Enables the clock for MCAN0. */
#define SYSCON_AHBCLKCTRL_MCAN0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_MCAN0_SHIFT)) & SYSCON_AHBCLKCTRL_MCAN0_MASK)

#define SYSCON_AHBCLKCTRL_ETH_MASK               (0x100U)
#define SYSCON_AHBCLKCTRL_ETH_SHIFT              (8U)
/*! ETH - Enables the clock for the ethernet interface. */
#define SYSCON_AHBCLKCTRL_ETH(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_ETH_SHIFT)) & SYSCON_AHBCLKCTRL_ETH_MASK)

#define SYSCON_AHBCLKCTRL_FMC_MASK               (0x100U)
#define SYSCON_AHBCLKCTRL_FMC_SHIFT              (8U)
/*! FMC - Enables the clock for the Flash accelerator. 0 = Disable; 1 = Enable. This clock is needed if the flash is being read. */
#define SYSCON_AHBCLKCTRL_FMC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FMC_SHIFT)) & SYSCON_AHBCLKCTRL_FMC_MASK)

#define SYSCON_AHBCLKCTRL_MCAN1_MASK             (0x100U)
#define SYSCON_AHBCLKCTRL_MCAN1_SHIFT            (8U)
/*! MCAN1 - Enables the clock for MCAN1. */
#define SYSCON_AHBCLKCTRL_MCAN1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_MCAN1_SHIFT)) & SYSCON_AHBCLKCTRL_MCAN1_MASK)

#define SYSCON_AHBCLKCTRL_EEPROM_MASK            (0x200U)
#define SYSCON_AHBCLKCTRL_EEPROM_SHIFT           (9U)
/*! EEPROM - Enables the clock for EEPROM. */
#define SYSCON_AHBCLKCTRL_EEPROM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_EEPROM_SHIFT)) & SYSCON_AHBCLKCTRL_EEPROM_MASK)

#define SYSCON_AHBCLKCTRL_GPIO4_MASK             (0x200U)
#define SYSCON_AHBCLKCTRL_GPIO4_SHIFT            (9U)
/*! GPIO4 - Enables the clock for the GPIO4 interface. */
#define SYSCON_AHBCLKCTRL_GPIO4(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO4_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO4_MASK)

#define SYSCON_AHBCLKCTRL_GPIO5_MASK             (0x400U)
#define SYSCON_AHBCLKCTRL_GPIO5_SHIFT            (10U)
/*! GPIO5 - Enables the clock for the GPIO5 interface. */
#define SYSCON_AHBCLKCTRL_GPIO5(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO5_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO5_MASK)

#define SYSCON_AHBCLKCTRL_SPIFI_MASK             (0x400U)
#define SYSCON_AHBCLKCTRL_SPIFI_SHIFT            (10U)
/*! SPIFI - Enables the clock for the SPIFI. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_SPIFI(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SPIFI_SHIFT)) & SYSCON_AHBCLKCTRL_SPIFI_MASK)

#define SYSCON_AHBCLKCTRL_UTICK_MASK             (0x400U)
#define SYSCON_AHBCLKCTRL_UTICK_SHIFT            (10U)
/*! UTICK - Enables the clock for the Micro-tick Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_UTICK(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_UTICK_SHIFT)) & SYSCON_AHBCLKCTRL_UTICK_MASK)

#define SYSCON_AHBCLKCTRL_AES_MASK               (0x800U)
#define SYSCON_AHBCLKCTRL_AES_SHIFT              (11U)
/*! AES - Enables the clock for the AES interface. */
#define SYSCON_AHBCLKCTRL_AES(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_AES_SHIFT)) & SYSCON_AHBCLKCTRL_AES_MASK)

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

#define SYSCON_AHBCLKCTRL_OTP_MASK               (0x1000U)
#define SYSCON_AHBCLKCTRL_OTP_SHIFT              (12U)
/*! OTP - Enables the clock for the OTP interface. */
#define SYSCON_AHBCLKCTRL_OTP(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_OTP_SHIFT)) & SYSCON_AHBCLKCTRL_OTP_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM2_MASK         (0x2000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM2_SHIFT        (13U)
/*! FLEXCOMM2 - Enables the clock for Flexcomm 2. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM2(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM2_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM2_MASK)

#define SYSCON_AHBCLKCTRL_IOCON_MASK             (0x2000U)
#define SYSCON_AHBCLKCTRL_IOCON_SHIFT            (13U)
/*! IOCON - Enables the clock for the IOCON block. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_IOCON(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_IOCON_SHIFT)) & SYSCON_AHBCLKCTRL_IOCON_MASK)

#define SYSCON_AHBCLKCTRL_RNG_MASK               (0x2000U)
#define SYSCON_AHBCLKCTRL_RNG_SHIFT              (13U)
/*! RNG - Enables the clock for the RNG interface. */
#define SYSCON_AHBCLKCTRL_RNG(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_RNG_SHIFT)) & SYSCON_AHBCLKCTRL_RNG_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM3_MASK         (0x4000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM3_SHIFT        (14U)
/*! FLEXCOMM3 - Enables the clock for Flexcomm 3. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM3(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM3_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM3_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM8_MASK         (0x4000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM8_SHIFT        (14U)
/*! FLEXCOMM8 - Enables the clock for the Flexcomm8 interface. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM8(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM8_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM8_MASK)

#define SYSCON_AHBCLKCTRL_GPIO0_MASK             (0x4000U)
#define SYSCON_AHBCLKCTRL_GPIO0_SHIFT            (14U)
/*! GPIO0 - Enables the clock for the GPIO0 port registers. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GPIO0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO0_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO0_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM4_MASK         (0x8000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM4_SHIFT        (15U)
/*! FLEXCOMM4 - Enables the clock for Flexcomm 4. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM4(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM4_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM4_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM9_MASK         (0x8000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM9_SHIFT        (15U)
/*! FLEXCOMM9 - Enables the clock for the Flexcomm9 interface. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM9(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM9_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM9_MASK)

#define SYSCON_AHBCLKCTRL_GPIO1_MASK             (0x8000U)
#define SYSCON_AHBCLKCTRL_GPIO1_SHIFT            (15U)
/*! GPIO1 - Enables the clock for the GPIO1 port registers. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GPIO1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO1_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO1_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM5_MASK         (0x10000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM5_SHIFT        (16U)
/*! FLEXCOMM5 - Enables the clock for Flexcomm 5. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM5(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM5_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM5_MASK)

#define SYSCON_AHBCLKCTRL_GPIO2_MASK             (0x10000U)
#define SYSCON_AHBCLKCTRL_GPIO2_SHIFT            (16U)
/*! GPIO2 - Enables the clock for the GPIO2 port registers. */
#define SYSCON_AHBCLKCTRL_GPIO2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO2_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO2_MASK)

#define SYSCON_AHBCLKCTRL_USB0HMR_MASK           (0x10000U)
#define SYSCON_AHBCLKCTRL_USB0HMR_SHIFT          (16U)
/*! USB0HMR - Enables the clock for the USB host master interface. */
#define SYSCON_AHBCLKCTRL_USB0HMR(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB0HMR_SHIFT)) & SYSCON_AHBCLKCTRL_USB0HMR_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM6_MASK         (0x20000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM6_SHIFT        (17U)
/*! FLEXCOMM6 - Enables the clock for Flexcomm 6. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM6(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM6_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM6_MASK)

#define SYSCON_AHBCLKCTRL_GPIO3_MASK             (0x20000U)
#define SYSCON_AHBCLKCTRL_GPIO3_SHIFT            (17U)
/*! GPIO3 - Enables the clock for the GPIO3 port registers. */
#define SYSCON_AHBCLKCTRL_GPIO3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GPIO3_SHIFT)) & SYSCON_AHBCLKCTRL_GPIO3_MASK)

#define SYSCON_AHBCLKCTRL_USB0HSL_MASK           (0x20000U)
#define SYSCON_AHBCLKCTRL_USB0HSL_SHIFT          (17U)
/*! USB0HSL - Enables the clock for the USB host slave interface. */
#define SYSCON_AHBCLKCTRL_USB0HSL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB0HSL_SHIFT)) & SYSCON_AHBCLKCTRL_USB0HSL_MASK)

#define SYSCON_AHBCLKCTRL_FLEXCOMM7_MASK         (0x40000U)
#define SYSCON_AHBCLKCTRL_FLEXCOMM7_SHIFT        (18U)
/*! FLEXCOMM7 - Enables the clock for Flexcomm 7. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_FLEXCOMM7(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_FLEXCOMM7_SHIFT)) & SYSCON_AHBCLKCTRL_FLEXCOMM7_MASK)

#define SYSCON_AHBCLKCTRL_PINT_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL_PINT_SHIFT             (18U)
/*! PINT - Enables the clock for the pin interrupt block.0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_PINT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_PINT_SHIFT)) & SYSCON_AHBCLKCTRL_PINT_MASK)

#define SYSCON_AHBCLKCTRL_SHA0_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL_SHA0_SHIFT             (18U)
/*! SHA0 - Enables the clock for the SHA interface. */
#define SYSCON_AHBCLKCTRL_SHA0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SHA0_SHIFT)) & SYSCON_AHBCLKCTRL_SHA0_MASK)

#define SYSCON_AHBCLKCTRL_DMIC_MASK              (0x80000U)
#define SYSCON_AHBCLKCTRL_DMIC_SHIFT             (19U)
/*! DMIC - Enables the clock for the digital microphone interface. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_DMIC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_DMIC_SHIFT)) & SYSCON_AHBCLKCTRL_DMIC_MASK)

#define SYSCON_AHBCLKCTRL_GINT_MASK              (0x80000U)
#define SYSCON_AHBCLKCTRL_GINT_SHIFT             (19U)
/*! GINT - Enables the clock for the grouped pin interrupt block. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_GINT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_GINT_SHIFT)) & SYSCON_AHBCLKCTRL_GINT_MASK)

#define SYSCON_AHBCLKCTRL_SC0_MASK               (0x80000U)
#define SYSCON_AHBCLKCTRL_SC0_SHIFT              (19U)
/*! SC0 - Enables the clock for the Smart card0 interface. */
#define SYSCON_AHBCLKCTRL_SC0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SC0_SHIFT)) & SYSCON_AHBCLKCTRL_SC0_MASK)

#define SYSCON_AHBCLKCTRL_DMA_MASK               (0x100000U)
#define SYSCON_AHBCLKCTRL_DMA_SHIFT              (20U)
/*! DMA - Enables the clock for the DMA controller. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_DMA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_DMA_SHIFT)) & SYSCON_AHBCLKCTRL_DMA_MASK)

#define SYSCON_AHBCLKCTRL_SC1_MASK               (0x100000U)
#define SYSCON_AHBCLKCTRL_SC1_SHIFT              (20U)
/*! SC1 - Enables the clock for the Smart card1 interface. */
#define SYSCON_AHBCLKCTRL_SC1(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_SC1_SHIFT)) & SYSCON_AHBCLKCTRL_SC1_MASK)

#define SYSCON_AHBCLKCTRL_CRC_MASK               (0x200000U)
#define SYSCON_AHBCLKCTRL_CRC_SHIFT              (21U)
/*! CRC - Enables the clock for the CRC engine. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CRC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CRC_SHIFT)) & SYSCON_AHBCLKCTRL_CRC_MASK)

#define SYSCON_AHBCLKCTRL_CTIMER2_MASK           (0x400000U)
#define SYSCON_AHBCLKCTRL_CTIMER2_SHIFT          (22U)
/*! CTIMER2 - Enables the clock for CTIMER 2. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CTIMER2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CTIMER2_SHIFT)) & SYSCON_AHBCLKCTRL_CTIMER2_MASK)

#define SYSCON_AHBCLKCTRL_WWDT_MASK              (0x400000U)
#define SYSCON_AHBCLKCTRL_WWDT_SHIFT             (22U)
/*! WWDT - Enables the clock for the Watchdog Timer. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_WWDT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_WWDT_SHIFT)) & SYSCON_AHBCLKCTRL_WWDT_MASK)

#define SYSCON_AHBCLKCTRL_RTC_MASK               (0x800000U)
#define SYSCON_AHBCLKCTRL_RTC_SHIFT              (23U)
/*! RTC - Enables the bus clock for the RTC. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_RTC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_RTC_SHIFT)) & SYSCON_AHBCLKCTRL_RTC_MASK)

#define SYSCON_AHBCLKCTRL_USB0D_MASK             (0x2000000U)
#define SYSCON_AHBCLKCTRL_USB0D_SHIFT            (25U)
/*! USB0D - Enables the clock for the USB0 device interface. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_USB0D(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_USB0D_SHIFT)) & SYSCON_AHBCLKCTRL_USB0D_MASK)

#define SYSCON_AHBCLKCTRL_CTIMER0_MASK           (0x4000000U)
#define SYSCON_AHBCLKCTRL_CTIMER0_SHIFT          (26U)
/*! CTIMER0 - Enables the clock for timer CTIMER0. 0 = Disable; 1 = Enable. */
#define SYSCON_AHBCLKCTRL_CTIMER0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL_CTIMER0_SHIFT)) & SYSCON_AHBCLKCTRL_CTIMER0_MASK)

#define SYSCON_AHBCLKCTRL_ADC0_MASK              (0x8000000U)
#define SYSCON_AHBCLKCTRL_ADC0_SHIFT             (27U)
/*! ADC0 - Enables the clock for the ADC0 register interface. */
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
 *  0b101..USB PLL clock (usb_pll_clk)
 *  0b110..Audio PLL clock (audio_pll_clk)
 *  0b111..RTC oscillator 32 kHz output (32k_clk)
 */
#define SYSCON_CLKOUTSELA_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSELA_SEL_SHIFT)) & SYSCON_CLKOUTSELA_SEL_MASK)
/*! @} */

/*! @name SYSPLLCLKSEL - PLL clock source select */
/*! @{ */

#define SYSCON_SYSPLLCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_SYSPLLCLKSEL_SEL_SHIFT            (0U)
/*! SEL - System PLL clock source selection.
 *  0b000..FRO 12 MHz (fro_12m)
 *  0b001..CLKIN (clk_in)
 *  0b010..Watchdog oscillator (wdt_clk)
 *  0b011..RTC oscillator 32 kHz output (32k_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_SYSPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCLKSEL_SEL_SHIFT)) & SYSCON_SYSPLLCLKSEL_SEL_MASK)
/*! @} */

/*! @name AUDPLLCLKSEL - Audio PLL clock source select */
/*! @{ */

#define SYSCON_AUDPLLCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_AUDPLLCLKSEL_SEL_SHIFT            (0U)
/*! SEL - Audio PLL clock source selection.
 *  0b000..FRO 12 MHz (fro_12m)
 *  0b001..CLKIN (clk_in)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_AUDPLLCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCLKSEL_SEL_SHIFT)) & SYSCON_AUDPLLCLKSEL_SEL_MASK)
/*! @} */

/*! @name SPIFICLKSEL - SPIFI clock source select */
/*! @{ */

#define SYSCON_SPIFICLKSEL_SEL_MASK              (0x7U)
#define SYSCON_SPIFICLKSEL_SEL_SHIFT             (0U)
/*! SEL - System PLL clock source selection
 *  0b000..Main clock (main_clk)
 *  0b001..System PLL output (pll_clk)
 *  0b010..USB PLL clock (usb_pll_clk)
 *  0b011..FRO 96 or 48 MHz (fro_hf)
 *  0b100..Audio PLL clock (audio_pll_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_SPIFICLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKSEL_SEL_SHIFT)) & SYSCON_SPIFICLKSEL_SEL_MASK)
/*! @} */

/*! @name ADCCLKSEL - ADC clock source select */
/*! @{ */

#define SYSCON_ADCCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_ADCCLKSEL_SEL_SHIFT               (0U)
/*! SEL - ADC clock source selection
 *  0b000..FRO 96 or 48 MHz (fro_hf)
 *  0b001..System PLL output (pll_clk)
 *  0b010..USB PLL clock (usb_pll_clk)
 *  0b011..Audio PLL clock (audio_pll_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_ADCCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKSEL_SEL_SHIFT)) & SYSCON_ADCCLKSEL_SEL_MASK)
/*! @} */

/*! @name USB0CLKSEL - USB0 clock source select */
/*! @{ */

#define SYSCON_USB0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_USB0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - USB0 device clock source selection.
 *  0b000..FRO 96 or 48 MHz (fro_hf)
 *  0b001..System PLL output (pll_clk)
 *  0b010..USB PLL clock (usb_pll_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_USB0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKSEL_SEL_SHIFT)) & SYSCON_USB0CLKSEL_SEL_MASK)
/*! @} */

/*! @name USB1CLKSEL - USB1 clock source select */
/*! @{ */

#define SYSCON_USB1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_USB1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - USB1 PHY clock source selection.
 *  0b000..Main clock (main_clk)
 *  0b001..System PLL output (pll_clk)
 *  0b010..USB PLL clock (usb_pll_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_USB1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKSEL_SEL_SHIFT)) & SYSCON_USB1CLKSEL_SEL_MASK)
/*! @} */

/*! @name FCLKSEL - Flexcomm 0 clock source select */
/*! @{ */

#define SYSCON_FCLKSEL_SEL_MASK                  (0x7U)
#define SYSCON_FCLKSEL_SEL_SHIFT                 (0U)
/*! SEL - Flexcomm clock source selection. One per Flexcomm.
 *  0b000..FRO 12 MHz (fro_12m)
 *  0b001..FRO HF DIV (fro_hf_div)
 *  0b010..Audio PLL clock (audio_pll_clk)
 *  0b011..MCLK pin input, when selected in IOCON (mclk_in)
 *  0b100..FRG clock, the output of the fractional rate generator (frg_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_FCLKSEL_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FCLKSEL_SEL_SHIFT)) & SYSCON_FCLKSEL_SEL_MASK)
/*! @} */

/*! @name MCLKCLKSEL - MCLK clock source select */
/*! @{ */

#define SYSCON_MCLKCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_MCLKCLKSEL_SEL_SHIFT              (0U)
/*! SEL - MCLK source select. This may be used by Flexcomms that support I2S, and/or by the digital microphone subsystem.
 *  0b000..FRO HF DIV (fro_hf_div)
 *  0b001..Audio PLL clock (audio_pll_clk)
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

/*! @name DMICCLKSEL - Digital microphone (DMIC) subsystem clock select */
/*! @{ */

#define SYSCON_DMICCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_DMICCLKSEL_SEL_SHIFT              (0U)
/*! SEL - DMIC (audio subsystem) clock source select.
 *  0b000..FRO 12 MHz (fro_12m)
 *  0b001..FRO HF DIV (fro_hf_div)
 *  0b010..Audio PLL clock (audio_pll_clk)
 *  0b011..MCLK pin input, when selected in IOCON (mclk_in)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_DMICCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICCLKSEL_SEL_SHIFT)) & SYSCON_DMICCLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTCLKSEL - SCTimer/PWM clock source select */
/*! @{ */

#define SYSCON_SCTCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_SCTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - SCT clock source select.
 *  0b000..Main clock (main_clk)
 *  0b001..System PLL output (pll_clk)
 *  0b010..FRO 96 or 48 MHz (fro_hf)
 *  0b011..Audio PLL clock (audio_pll_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_SCTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKSEL_SEL_SHIFT)) & SYSCON_SCTCLKSEL_SEL_MASK)
/*! @} */

/*! @name LCDCLKSEL - LCD clock source select */
/*! @{ */

#define SYSCON_LCDCLKSEL_SEL_MASK                (0x3U)
#define SYSCON_LCDCLKSEL_SEL_SHIFT               (0U)
/*! SEL - LCD clock source select.
 *  0b00..Main clock (main_clk)
 *  0b01..LCDCLKIN (LCDCLK_EXT)
 *  0b10..FRO 96 or 48 MHz (fro_hf)
 *  0b11..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_LCDCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_LCDCLKSEL_SEL_SHIFT)) & SYSCON_LCDCLKSEL_SEL_MASK)
/*! @} */

/*! @name SDIOCLKSEL - SDIO clock source select */
/*! @{ */

#define SYSCON_SDIOCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_SDIOCLKSEL_SEL_SHIFT              (0U)
/*! SEL - SDIO clock source select.
 *  0b000..Main clock (main_clk)
 *  0b001..System PLL output (pll_clk)
 *  0b010..USB PLL clock (usb_pll_clk)
 *  0b011..FRO 96 or 48 MHz (fro_hf)
 *  0b100..Audio PLL clock (audio_pll_clk)
 *  0b111..None, this may be selected in order to reduce power when no output is needed.
 */
#define SYSCON_SDIOCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKSEL_SEL_SHIFT)) & SYSCON_SDIOCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV - SYSTICK clock divider */
/*! @{ */

#define SYSCON_SYSTICKCLKDIV_DIV_MASK            (0xFFU)
#define SYSCON_SYSTICKCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_SYSTICKCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_DIV_SHIFT)) & SYSCON_SYSTICKCLKDIV_DIV_MASK)

#define SYSCON_SYSTICKCLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_SYSTICKCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define SYSCON_SYSTICKCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_RESET_SHIFT)) & SYSCON_SYSTICKCLKDIV_RESET_MASK)

#define SYSCON_SYSTICKCLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_SYSTICKCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_SYSTICKCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_HALT_SHIFT)) & SYSCON_SYSTICKCLKDIV_HALT_MASK)

#define SYSCON_SYSTICKCLKDIV_REQFLAG_MASK        (0x80000000U)
#define SYSCON_SYSTICKCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_SYSTICKCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_REQFLAG_SHIFT)) & SYSCON_SYSTICKCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name ARMTRACECLKDIV - ARM Trace clock divider */
/*! @{ */

#define SYSCON_ARMTRACECLKDIV_DIV_MASK           (0xFFU)
#define SYSCON_ARMTRACECLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock divider value. */
#define SYSCON_ARMTRACECLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_ARMTRACECLKDIV_DIV_SHIFT)) & SYSCON_ARMTRACECLKDIV_DIV_MASK)

#define SYSCON_ARMTRACECLKDIV_RESET_MASK         (0x20000000U)
#define SYSCON_ARMTRACECLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_ARMTRACECLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ARMTRACECLKDIV_RESET_SHIFT)) & SYSCON_ARMTRACECLKDIV_RESET_MASK)

#define SYSCON_ARMTRACECLKDIV_HALT_MASK          (0x40000000U)
#define SYSCON_ARMTRACECLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_ARMTRACECLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ARMTRACECLKDIV_HALT_SHIFT)) & SYSCON_ARMTRACECLKDIV_HALT_MASK)

#define SYSCON_ARMTRACECLKDIV_REQFLAG_MASK       (0x80000000U)
#define SYSCON_ARMTRACECLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_ARMTRACECLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ARMTRACECLKDIV_REQFLAG_SHIFT)) & SYSCON_ARMTRACECLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CAN0CLKDIV - MCAN0 clock divider */
/*! @{ */

#define SYSCON_CAN0CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_CAN0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_CAN0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN0CLKDIV_DIV_SHIFT)) & SYSCON_CAN0CLKDIV_DIV_MASK)

#define SYSCON_CAN0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_CAN0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_CAN0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN0CLKDIV_RESET_SHIFT)) & SYSCON_CAN0CLKDIV_RESET_MASK)

#define SYSCON_CAN0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_CAN0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_CAN0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN0CLKDIV_HALT_SHIFT)) & SYSCON_CAN0CLKDIV_HALT_MASK)

#define SYSCON_CAN0CLKDIV_REQFLAG_MASK           (0x80000000U)
#define SYSCON_CAN0CLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_CAN0CLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN0CLKDIV_REQFLAG_SHIFT)) & SYSCON_CAN0CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CAN1CLKDIV - MCAN1 clock divider */
/*! @{ */

#define SYSCON_CAN1CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_CAN1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_CAN1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN1CLKDIV_DIV_SHIFT)) & SYSCON_CAN1CLKDIV_DIV_MASK)

#define SYSCON_CAN1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_CAN1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define SYSCON_CAN1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN1CLKDIV_RESET_SHIFT)) & SYSCON_CAN1CLKDIV_RESET_MASK)

#define SYSCON_CAN1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_CAN1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_CAN1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN1CLKDIV_HALT_SHIFT)) & SYSCON_CAN1CLKDIV_HALT_MASK)

#define SYSCON_CAN1CLKDIV_REQFLAG_MASK           (0x80000000U)
#define SYSCON_CAN1CLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_CAN1CLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CAN1CLKDIV_REQFLAG_SHIFT)) & SYSCON_CAN1CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SC0CLKDIV - Smartcard0 clock divider */
/*! @{ */

#define SYSCON_SC0CLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SC0CLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SC0CLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SC0CLKDIV_DIV_SHIFT)) & SYSCON_SC0CLKDIV_DIV_MASK)

#define SYSCON_SC0CLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_SC0CLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_SC0CLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SC0CLKDIV_RESET_SHIFT)) & SYSCON_SC0CLKDIV_RESET_MASK)

#define SYSCON_SC0CLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_SC0CLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_SC0CLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SC0CLKDIV_HALT_SHIFT)) & SYSCON_SC0CLKDIV_HALT_MASK)

#define SYSCON_SC0CLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_SC0CLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_SC0CLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SC0CLKDIV_REQFLAG_SHIFT)) & SYSCON_SC0CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SC1CLKDIV - Smartcard1 clock divider */
/*! @{ */

#define SYSCON_SC1CLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SC1CLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SC1CLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SC1CLKDIV_DIV_SHIFT)) & SYSCON_SC1CLKDIV_DIV_MASK)

#define SYSCON_SC1CLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_SC1CLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_SC1CLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SC1CLKDIV_RESET_SHIFT)) & SYSCON_SC1CLKDIV_RESET_MASK)

#define SYSCON_SC1CLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_SC1CLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_SC1CLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SC1CLKDIV_HALT_SHIFT)) & SYSCON_SC1CLKDIV_HALT_MASK)

#define SYSCON_SC1CLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_SC1CLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_SC1CLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SC1CLKDIV_REQFLAG_SHIFT)) & SYSCON_SC1CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name AHBCLKDIV - AHB clock divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)

#define SYSCON_AHBCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_AHBCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_AHBCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_REQFLAG_SHIFT)) & SYSCON_AHBCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)

#define SYSCON_CLKOUTDIV_RESET_MASK              (0x20000000U)
#define SYSCON_CLKOUTDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define SYSCON_CLKOUTDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_RESET_SHIFT)) & SYSCON_CLKOUTDIV_RESET_MASK)

#define SYSCON_CLKOUTDIV_HALT_MASK               (0x40000000U)
#define SYSCON_CLKOUTDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define SYSCON_CLKOUTDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_HALT_SHIFT)) & SYSCON_CLKOUTDIV_HALT_MASK)

#define SYSCON_CLKOUTDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_CLKOUTDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_CLKOUTDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_REQFLAG_SHIFT)) & SYSCON_CLKOUTDIV_REQFLAG_MASK)
/*! @} */

/*! @name FROHFCLKDIV - FROHF clock divider */
/*! @{ */

#define SYSCON_FROHFCLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_FROHFCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value. */
#define SYSCON_FROHFCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFCLKDIV_DIV_SHIFT)) & SYSCON_FROHFCLKDIV_DIV_MASK)

#define SYSCON_FROHFCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_FROHFCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_FROHFCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFCLKDIV_RESET_SHIFT)) & SYSCON_FROHFCLKDIV_RESET_MASK)

#define SYSCON_FROHFCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_FROHFCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_FROHFCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFCLKDIV_HALT_SHIFT)) & SYSCON_FROHFCLKDIV_HALT_MASK)

#define SYSCON_FROHFCLKDIV_REQFLAG_MASK          (0x80000000U)
#define SYSCON_FROHFCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_FROHFCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFCLKDIV_REQFLAG_SHIFT)) & SYSCON_FROHFCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SPIFICLKDIV - SPIFI clock divider */
/*! @{ */

#define SYSCON_SPIFICLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_SPIFICLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SPIFICLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_DIV_SHIFT)) & SYSCON_SPIFICLKDIV_DIV_MASK)

#define SYSCON_SPIFICLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_SPIFICLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define SYSCON_SPIFICLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_RESET_SHIFT)) & SYSCON_SPIFICLKDIV_RESET_MASK)

#define SYSCON_SPIFICLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_SPIFICLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define SYSCON_SPIFICLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_HALT_SHIFT)) & SYSCON_SPIFICLKDIV_HALT_MASK)

#define SYSCON_SPIFICLKDIV_REQFLAG_MASK          (0x80000000U)
#define SYSCON_SPIFICLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_SPIFICLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_REQFLAG_SHIFT)) & SYSCON_SPIFICLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name ADCCLKDIV - ADC clock divider */
/*! @{ */

#define SYSCON_ADCCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_ADCCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_ADCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_DIV_SHIFT)) & SYSCON_ADCCLKDIV_DIV_MASK)

#define SYSCON_ADCCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_ADCCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_ADCCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_RESET_SHIFT)) & SYSCON_ADCCLKDIV_RESET_MASK)

#define SYSCON_ADCCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_ADCCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_ADCCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_HALT_SHIFT)) & SYSCON_ADCCLKDIV_HALT_MASK)

#define SYSCON_ADCCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_ADCCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_ADCCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ADCCLKDIV_REQFLAG_SHIFT)) & SYSCON_ADCCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name USB0CLKDIV - USB0 clock divider */
/*! @{ */

#define SYSCON_USB0CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_USB0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_USB0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_DIV_SHIFT)) & SYSCON_USB0CLKDIV_DIV_MASK)

#define SYSCON_USB0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_USB0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_USB0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_RESET_SHIFT)) & SYSCON_USB0CLKDIV_RESET_MASK)

#define SYSCON_USB0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_USB0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_USB0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_HALT_SHIFT)) & SYSCON_USB0CLKDIV_HALT_MASK)

#define SYSCON_USB0CLKDIV_REQFLAG_MASK           (0x80000000U)
#define SYSCON_USB0CLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_USB0CLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_REQFLAG_SHIFT)) & SYSCON_USB0CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name USB1CLKDIV - USB1 clock divider */
/*! @{ */

#define SYSCON_USB1CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_USB1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_USB1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKDIV_DIV_SHIFT)) & SYSCON_USB1CLKDIV_DIV_MASK)

#define SYSCON_USB1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_USB1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_USB1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKDIV_RESET_SHIFT)) & SYSCON_USB1CLKDIV_RESET_MASK)

#define SYSCON_USB1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_USB1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_USB1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKDIV_HALT_SHIFT)) & SYSCON_USB1CLKDIV_HALT_MASK)

#define SYSCON_USB1CLKDIV_REQFLAG_MASK           (0x80000000U)
#define SYSCON_USB1CLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_USB1CLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKDIV_REQFLAG_SHIFT)) & SYSCON_USB1CLKDIV_REQFLAG_MASK)
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

/*! @name DMICCLKDIV - DMIC clock divider */
/*! @{ */

#define SYSCON_DMICCLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_DMICCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_DMICCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICCLKDIV_DIV_SHIFT)) & SYSCON_DMICCLKDIV_DIV_MASK)

#define SYSCON_DMICCLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_DMICCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define SYSCON_DMICCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICCLKDIV_RESET_SHIFT)) & SYSCON_DMICCLKDIV_RESET_MASK)

#define SYSCON_DMICCLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_DMICCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. The intent is to allow the divider clock source to be changed
 *    without the risk of a glitch at the output.
 */
#define SYSCON_DMICCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICCLKDIV_HALT_SHIFT)) & SYSCON_DMICCLKDIV_HALT_MASK)

#define SYSCON_DMICCLKDIV_REQFLAG_MASK           (0x80000000U)
#define SYSCON_DMICCLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_DMICCLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICCLKDIV_REQFLAG_SHIFT)) & SYSCON_DMICCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MCLKDIV - I2S MCLK clock divider */
/*! @{ */

#define SYSCON_MCLKDIV_DIV_MASK                  (0xFFU)
#define SYSCON_MCLKDIV_DIV_SHIFT                 (0U)
/*! DIV - Clock divider value. 0: Divide by 1 up to 255: Divide by 256. */
#define SYSCON_MCLKDIV_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_DIV_SHIFT)) & SYSCON_MCLKDIV_DIV_MASK)

#define SYSCON_MCLKDIV_RESET_MASK                (0x20000000U)
#define SYSCON_MCLKDIV_RESET_SHIFT               (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_MCLKDIV_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_RESET_SHIFT)) & SYSCON_MCLKDIV_RESET_MASK)

#define SYSCON_MCLKDIV_HALT_MASK                 (0x40000000U)
#define SYSCON_MCLKDIV_HALT_SHIFT                (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_MCLKDIV_HALT(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_HALT_SHIFT)) & SYSCON_MCLKDIV_HALT_MASK)

#define SYSCON_MCLKDIV_REQFLAG_MASK              (0x80000000U)
#define SYSCON_MCLKDIV_REQFLAG_SHIFT             (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_MCLKDIV_REQFLAG(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_REQFLAG_SHIFT)) & SYSCON_MCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name LCDCLKDIV - LCD clock divider */
/*! @{ */

#define SYSCON_LCDCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_LCDCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_LCDCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_LCDCLKDIV_DIV_SHIFT)) & SYSCON_LCDCLKDIV_DIV_MASK)

#define SYSCON_LCDCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_LCDCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_LCDCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_LCDCLKDIV_RESET_SHIFT)) & SYSCON_LCDCLKDIV_RESET_MASK)

#define SYSCON_LCDCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_LCDCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_LCDCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_LCDCLKDIV_HALT_SHIFT)) & SYSCON_LCDCLKDIV_HALT_MASK)

#define SYSCON_LCDCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_LCDCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_LCDCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_LCDCLKDIV_REQFLAG_SHIFT)) & SYSCON_LCDCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SCTCLKDIV - SCT/PWM clock divider */
/*! @{ */

#define SYSCON_SCTCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SCTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SCTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_DIV_SHIFT)) & SYSCON_SCTCLKDIV_DIV_MASK)

#define SYSCON_SCTCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_SCTCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_SCTCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_RESET_SHIFT)) & SYSCON_SCTCLKDIV_RESET_MASK)

#define SYSCON_SCTCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_SCTCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_SCTCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_HALT_SHIFT)) & SYSCON_SCTCLKDIV_HALT_MASK)

#define SYSCON_SCTCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_SCTCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_SCTCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_REQFLAG_SHIFT)) & SYSCON_SCTCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name EMCCLKDIV - EMC clock divider */
/*! @{ */

#define SYSCON_EMCCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_EMCCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_EMCCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCCLKDIV_DIV_SHIFT)) & SYSCON_EMCCLKDIV_DIV_MASK)

#define SYSCON_EMCCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_EMCCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_EMCCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCCLKDIV_RESET_SHIFT)) & SYSCON_EMCCLKDIV_RESET_MASK)

#define SYSCON_EMCCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_EMCCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_EMCCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCCLKDIV_HALT_SHIFT)) & SYSCON_EMCCLKDIV_HALT_MASK)

#define SYSCON_EMCCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_EMCCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_EMCCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCCLKDIV_REQFLAG_SHIFT)) & SYSCON_EMCCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDIOCLKDIV - SDIO clock divider */
/*! @{ */

#define SYSCON_SDIOCLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_SDIOCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SDIOCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKDIV_DIV_SHIFT)) & SYSCON_SDIOCLKDIV_DIV_MASK)

#define SYSCON_SDIOCLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_SDIOCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. */
#define SYSCON_SDIOCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKDIV_RESET_SHIFT)) & SYSCON_SDIOCLKDIV_RESET_MASK)

#define SYSCON_SDIOCLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_SDIOCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter. */
#define SYSCON_SDIOCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKDIV_HALT_SHIFT)) & SYSCON_SDIOCLKDIV_HALT_MASK)

#define SYSCON_SDIOCLKDIV_REQFLAG_MASK           (0x80000000U)
#define SYSCON_SDIOCLKDIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag. */
#define SYSCON_SDIOCLKDIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKDIV_REQFLAG_SHIFT)) & SYSCON_SDIOCLKDIV_REQFLAG_MASK)
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

/*! @name USB0CLKCTRL - USB0 clock control */
/*! @{ */

#define SYSCON_USB0CLKCTRL_AP_FS_DEV_CLK_MASK    (0x1U)
#define SYSCON_USB0CLKCTRL_AP_FS_DEV_CLK_SHIFT   (0U)
/*! AP_FS_DEV_CLK - USB0 Device USB0_NEEDCLK signal control. */
#define SYSCON_USB0CLKCTRL_AP_FS_DEV_CLK(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKCTRL_AP_FS_DEV_CLK_SHIFT)) & SYSCON_USB0CLKCTRL_AP_FS_DEV_CLK_MASK)

#define SYSCON_USB0CLKCTRL_POL_FS_DEV_CLK_MASK   (0x2U)
#define SYSCON_USB0CLKCTRL_POL_FS_DEV_CLK_SHIFT  (1U)
/*! POL_FS_DEV_CLK - USB0 Device USB0_NEEDCLK polarity for triggering the USB0 wake-up interrupt. */
#define SYSCON_USB0CLKCTRL_POL_FS_DEV_CLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKCTRL_POL_FS_DEV_CLK_SHIFT)) & SYSCON_USB0CLKCTRL_POL_FS_DEV_CLK_MASK)

#define SYSCON_USB0CLKCTRL_AP_FS_HOST_CLK_MASK   (0x4U)
#define SYSCON_USB0CLKCTRL_AP_FS_HOST_CLK_SHIFT  (2U)
/*! AP_FS_HOST_CLK - USB0 Host USB0_NEEDCLK signal control. */
#define SYSCON_USB0CLKCTRL_AP_FS_HOST_CLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKCTRL_AP_FS_HOST_CLK_SHIFT)) & SYSCON_USB0CLKCTRL_AP_FS_HOST_CLK_MASK)

#define SYSCON_USB0CLKCTRL_POL_FS_HOST_CLK_MASK  (0x8U)
#define SYSCON_USB0CLKCTRL_POL_FS_HOST_CLK_SHIFT (3U)
/*! POL_FS_HOST_CLK - USB0 Host USB0_NEEDCLK polarity for triggering the USB0 wake-up interrupt. */
#define SYSCON_USB0CLKCTRL_POL_FS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKCTRL_POL_FS_HOST_CLK_SHIFT)) & SYSCON_USB0CLKCTRL_POL_FS_HOST_CLK_MASK)

#define SYSCON_USB0CLKCTRL_PU_DISABLE_MASK       (0x10U)
#define SYSCON_USB0CLKCTRL_PU_DISABLE_SHIFT      (4U)
/*! PU_DISABLE - Internal pull-up disable control. */
#define SYSCON_USB0CLKCTRL_PU_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKCTRL_PU_DISABLE_SHIFT)) & SYSCON_USB0CLKCTRL_PU_DISABLE_MASK)
/*! @} */

/*! @name USB0CLKSTAT - USB0 clock status */
/*! @{ */

#define SYSCON_USB0CLKSTAT_DEV_NEED_CLKST_MASK   (0x1U)
#define SYSCON_USB0CLKSTAT_DEV_NEED_CLKST_SHIFT  (0U)
/*! DEV_NEED_CLKST - USB0 Device USB0_NEEDCLK signal status. */
#define SYSCON_USB0CLKSTAT_DEV_NEED_CLKST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKSTAT_DEV_NEED_CLKST_SHIFT)) & SYSCON_USB0CLKSTAT_DEV_NEED_CLKST_MASK)

#define SYSCON_USB0CLKSTAT_HOST_NEED_CLKST_MASK  (0x2U)
#define SYSCON_USB0CLKSTAT_HOST_NEED_CLKST_SHIFT (1U)
/*! HOST_NEED_CLKST - USB0 Host USB0_NEEDCLK signal status. */
#define SYSCON_USB0CLKSTAT_HOST_NEED_CLKST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKSTAT_HOST_NEED_CLKST_SHIFT)) & SYSCON_USB0CLKSTAT_HOST_NEED_CLKST_MASK)
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
/*! DIR - MCLK direction control. */
#define SYSCON_MCLKIO_DIR(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKIO_DIR_SHIFT)) & SYSCON_MCLKIO_DIR_MASK)
/*! @} */

/*! @name USB1CLKCTRL - USB1 clock control */
/*! @{ */

#define SYSCON_USB1CLKCTRL_AP_FS_DEV_CLK_MASK    (0x1U)
#define SYSCON_USB1CLKCTRL_AP_FS_DEV_CLK_SHIFT   (0U)
/*! AP_FS_DEV_CLK - USB1 Device need_clock signal control. */
#define SYSCON_USB1CLKCTRL_AP_FS_DEV_CLK(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKCTRL_AP_FS_DEV_CLK_SHIFT)) & SYSCON_USB1CLKCTRL_AP_FS_DEV_CLK_MASK)

#define SYSCON_USB1CLKCTRL_POL_FS_DEV_CLK_MASK   (0x2U)
#define SYSCON_USB1CLKCTRL_POL_FS_DEV_CLK_SHIFT  (1U)
/*! POL_FS_DEV_CLK - USB1 Device need_clock polarity for triggering the USB1 wake-up interrupt. */
#define SYSCON_USB1CLKCTRL_POL_FS_DEV_CLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKCTRL_POL_FS_DEV_CLK_SHIFT)) & SYSCON_USB1CLKCTRL_POL_FS_DEV_CLK_MASK)

#define SYSCON_USB1CLKCTRL_AP_FS_HOST_CLK_MASK   (0x4U)
#define SYSCON_USB1CLKCTRL_AP_FS_HOST_CLK_SHIFT  (2U)
/*! AP_FS_HOST_CLK - USB1 Host need_clock signal control. */
#define SYSCON_USB1CLKCTRL_AP_FS_HOST_CLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKCTRL_AP_FS_HOST_CLK_SHIFT)) & SYSCON_USB1CLKCTRL_AP_FS_HOST_CLK_MASK)

#define SYSCON_USB1CLKCTRL_POL_FS_HOST_CLK_MASK  (0x8U)
#define SYSCON_USB1CLKCTRL_POL_FS_HOST_CLK_SHIFT (3U)
/*! POL_FS_HOST_CLK - USB1 Host need_clock polarity for triggering the USB1 wake-up interrupt. */
#define SYSCON_USB1CLKCTRL_POL_FS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKCTRL_POL_FS_HOST_CLK_SHIFT)) & SYSCON_USB1CLKCTRL_POL_FS_HOST_CLK_MASK)

#define SYSCON_USB1CLKCTRL_HS_DEV_WAKEUP_N_MASK  (0x10U)
#define SYSCON_USB1CLKCTRL_HS_DEV_WAKEUP_N_SHIFT (4U)
/*! HS_DEV_WAKEUP_N - External user wake-up signal for device mode; asserting this signal (active
 *    low) will result in exiting the low power mode; input to asynchronous control logic.
 */
#define SYSCON_USB1CLKCTRL_HS_DEV_WAKEUP_N(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKCTRL_HS_DEV_WAKEUP_N_SHIFT)) & SYSCON_USB1CLKCTRL_HS_DEV_WAKEUP_N_MASK)
/*! @} */

/*! @name USB1CLKSTAT - USB1 clock status */
/*! @{ */

#define SYSCON_USB1CLKSTAT_DEV_NEED_CLKST_MASK   (0x1U)
#define SYSCON_USB1CLKSTAT_DEV_NEED_CLKST_SHIFT  (0U)
/*! DEV_NEED_CLKST - USB1 Device USB1_NEEDCLK signal status. */
#define SYSCON_USB1CLKSTAT_DEV_NEED_CLKST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKSTAT_DEV_NEED_CLKST_SHIFT)) & SYSCON_USB1CLKSTAT_DEV_NEED_CLKST_MASK)

#define SYSCON_USB1CLKSTAT_HOST_NEED_CLKST_MASK  (0x2U)
#define SYSCON_USB1CLKSTAT_HOST_NEED_CLKST_SHIFT (1U)
/*! HOST_NEED_CLKST - USB1 Device host USB1_NEEDCLK signal status. */
#define SYSCON_USB1CLKSTAT_HOST_NEED_CLKST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_USB1CLKSTAT_HOST_NEED_CLKST_SHIFT)) & SYSCON_USB1CLKSTAT_HOST_NEED_CLKST_MASK)
/*! @} */

/*! @name EMCSYSCTRL - EMC system control */
/*! @{ */

#define SYSCON_EMCSYSCTRL_EMCSC_MASK             (0x1U)
#define SYSCON_EMCSYSCTRL_EMCSC_SHIFT            (0U)
/*! EMCSC - EMC Shift Control. */
#define SYSCON_EMCSYSCTRL_EMCSC(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCSYSCTRL_EMCSC_SHIFT)) & SYSCON_EMCSYSCTRL_EMCSC_MASK)

#define SYSCON_EMCSYSCTRL_EMCRD_MASK             (0x2U)
#define SYSCON_EMCSYSCTRL_EMCRD_SHIFT            (1U)
/*! EMCRD - EMC Reset Disable. */
#define SYSCON_EMCSYSCTRL_EMCRD(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCSYSCTRL_EMCRD_SHIFT)) & SYSCON_EMCSYSCTRL_EMCRD_MASK)

#define SYSCON_EMCSYSCTRL_EMCBC_MASK             (0x4U)
#define SYSCON_EMCSYSCTRL_EMCBC_SHIFT            (2U)
/*! EMCBC - External Memory Controller burst control. */
#define SYSCON_EMCSYSCTRL_EMCBC(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCSYSCTRL_EMCBC_SHIFT)) & SYSCON_EMCSYSCTRL_EMCBC_MASK)

#define SYSCON_EMCSYSCTRL_EMCFBCLKINSEL_MASK     (0x8U)
#define SYSCON_EMCSYSCTRL_EMCFBCLKINSEL_SHIFT    (3U)
/*! EMCFBCLKINSEL - External Memory Controller clock select. */
#define SYSCON_EMCSYSCTRL_EMCFBCLKINSEL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCSYSCTRL_EMCFBCLKINSEL_SHIFT)) & SYSCON_EMCSYSCTRL_EMCFBCLKINSEL_MASK)
/*! @} */

/*! @name EMCDLYCTRL - EMC clock delay control */
/*! @{ */

#define SYSCON_EMCDLYCTRL_CMD_DELAY_MASK         (0x1FU)
#define SYSCON_EMCDLYCTRL_CMD_DELAY_SHIFT        (0U)
/*! CMD_DELAY - Programmable delay value for EMC outputs in command delayed mode. */
#define SYSCON_EMCDLYCTRL_CMD_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCDLYCTRL_CMD_DELAY_SHIFT)) & SYSCON_EMCDLYCTRL_CMD_DELAY_MASK)

#define SYSCON_EMCDLYCTRL_FBCLK_DELAY_MASK       (0x1F00U)
#define SYSCON_EMCDLYCTRL_FBCLK_DELAY_SHIFT      (8U)
/*! FBCLK_DELAY - Programmable delay value for the feedback clock that controls input data sampling. */
#define SYSCON_EMCDLYCTRL_FBCLK_DELAY(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCDLYCTRL_FBCLK_DELAY_SHIFT)) & SYSCON_EMCDLYCTRL_FBCLK_DELAY_MASK)
/*! @} */

/*! @name EMCDLYCAL - EMC delay chain calibration control */
/*! @{ */

#define SYSCON_EMCDLYCAL_CALVALUE_MASK           (0xFFU)
#define SYSCON_EMCDLYCAL_CALVALUE_SHIFT          (0U)
/*! CALVALUE - Returns the count of the approximately 50 MHz ring oscillator that occur during 32 clocks of the FRO 12 MHz. */
#define SYSCON_EMCDLYCAL_CALVALUE(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCDLYCAL_CALVALUE_SHIFT)) & SYSCON_EMCDLYCAL_CALVALUE_MASK)

#define SYSCON_EMCDLYCAL_START_MASK              (0x4000U)
#define SYSCON_EMCDLYCAL_START_SHIFT             (14U)
/*! START - Start control bit for the EMC calibration counter. */
#define SYSCON_EMCDLYCAL_START(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCDLYCAL_START_SHIFT)) & SYSCON_EMCDLYCAL_START_MASK)

#define SYSCON_EMCDLYCAL_DONE_MASK               (0x8000U)
#define SYSCON_EMCDLYCAL_DONE_SHIFT              (15U)
/*! DONE - Measurement completion flag. */
#define SYSCON_EMCDLYCAL_DONE(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_EMCDLYCAL_DONE_SHIFT)) & SYSCON_EMCDLYCAL_DONE_MASK)
/*! @} */

/*! @name ETHPHYSEL - Ethernet PHY Selection */
/*! @{ */

#define SYSCON_ETHPHYSEL_PHY_SEL_MASK            (0x4U)
#define SYSCON_ETHPHYSEL_PHY_SEL_SHIFT           (2U)
/*! PHY_SEL - PHY interface select. */
#define SYSCON_ETHPHYSEL_PHY_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ETHPHYSEL_PHY_SEL_SHIFT)) & SYSCON_ETHPHYSEL_PHY_SEL_MASK)
/*! @} */

/*! @name ETHSBDCTRL - Ethernet SBD flow control */
/*! @{ */

#define SYSCON_ETHSBDCTRL_SBD_CTRL_MASK          (0x3U)
#define SYSCON_ETHSBDCTRL_SBD_CTRL_SHIFT         (0U)
/*! SBD_CTRL - Sideband Flow Control. */
#define SYSCON_ETHSBDCTRL_SBD_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ETHSBDCTRL_SBD_CTRL_SHIFT)) & SYSCON_ETHSBDCTRL_SBD_CTRL_MASK)
/*! @} */

/*! @name SDIOCLKCTRL - SDIO CCLKIN phase and delay control */
/*! @{ */

#define SYSCON_SDIOCLKCTRL_CCLK_DRV_PHASE_MASK   (0x3U)
#define SYSCON_SDIOCLKCTRL_CCLK_DRV_PHASE_SHIFT  (0U)
/*! CCLK_DRV_PHASE - Programmable delay value by which cclk_in_drv is phase-shifted with regard to cclk_in. */
#define SYSCON_SDIOCLKCTRL_CCLK_DRV_PHASE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_CCLK_DRV_PHASE_SHIFT)) & SYSCON_SDIOCLKCTRL_CCLK_DRV_PHASE_MASK)

#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_PHASE_MASK (0xCU)
#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_PHASE_SHIFT (2U)
/*! CCLK_SAMPLE_PHASE - Programmable delay value by which cclk_in_sample is delayed with regard to cclk_in. */
#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_PHASE(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_PHASE_SHIFT)) & SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_PHASE_MASK)

#define SYSCON_SDIOCLKCTRL_PHASE_ACTIVE_MASK     (0x80U)
#define SYSCON_SDIOCLKCTRL_PHASE_ACTIVE_SHIFT    (7U)
/*! PHASE_ACTIVE - sdio_clk by 2, before feeding into ccl_in, cclk_in_sample, and cclk_in_drv. */
#define SYSCON_SDIOCLKCTRL_PHASE_ACTIVE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_PHASE_ACTIVE_SHIFT)) & SYSCON_SDIOCLKCTRL_PHASE_ACTIVE_MASK)

#define SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_MASK   (0x1F0000U)
#define SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_SHIFT  (16U)
/*! CCLK_DRV_DELAY - Programmable delay value by which cclk_in_drv is delayed with regard to cclk_in. */
#define SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_SHIFT)) & SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_MASK)

#define SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_ACTIVE_MASK (0x800000U)
#define SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_ACTIVE_SHIFT (23U)
/*! CCLK_DRV_DELAY_ACTIVE - Enables drive delay, as controlled by the CCLK_DRV_DELAY field. */
#define SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_ACTIVE_SHIFT)) & SYSCON_SDIOCLKCTRL_CCLK_DRV_DELAY_ACTIVE_MASK)

#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_MASK (0x1F000000U)
#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_SHIFT (24U)
/*! CCLK_SAMPLE_DELAY - Programmable delay value by which cclk_in_sample is delayed with regard to cclk_in. */
#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_SHIFT)) & SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_MASK)

#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_ACTIVE_MASK (0x80000000U)
#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_ACTIVE_SHIFT (31U)
/*! CCLK_SAMPLE_DELAY_ACTIVE - Enables sample delay, as controlled by the CCLK_SAMPLE_DELAY field. */
#define SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_ACTIVE_SHIFT)) & SYSCON_SDIOCLKCTRL_CCLK_SAMPLE_DELAY_ACTIVE_MASK)
/*! @} */

/*! @name FROCTRL - FRO oscillator control */
/*! @{ */

#define SYSCON_FROCTRL_TRIM_MASK                 (0x3FFFU)
#define SYSCON_FROCTRL_TRIM_SHIFT                (0U)
/*! TRIM - This value is factory trimmed to account for bias and temperature compensation. */
#define SYSCON_FROCTRL_TRIM(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_TRIM_SHIFT)) & SYSCON_FROCTRL_TRIM_MASK)

#define SYSCON_FROCTRL_SEL_MASK                  (0x4000U)
#define SYSCON_FROCTRL_SEL_SHIFT                 (14U)
/*! SEL - Select the FRO HF output frequency. */
#define SYSCON_FROCTRL_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_SEL_SHIFT)) & SYSCON_FROCTRL_SEL_MASK)

#define SYSCON_FROCTRL_FREQTRIM_MASK             (0xFF0000U)
#define SYSCON_FROCTRL_FREQTRIM_SHIFT            (16U)
/*! FREQTRIM - Frequency trim. */
#define SYSCON_FROCTRL_FREQTRIM(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_FREQTRIM_SHIFT)) & SYSCON_FROCTRL_FREQTRIM_MASK)

#define SYSCON_FROCTRL_USBCLKADJ_MASK            (0x1000000U)
#define SYSCON_FROCTRL_USBCLKADJ_SHIFT           (24U)
/*! USBCLKADJ - USB clock adjust mode. */
#define SYSCON_FROCTRL_USBCLKADJ(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_USBCLKADJ_SHIFT)) & SYSCON_FROCTRL_USBCLKADJ_MASK)

#define SYSCON_FROCTRL_USBMODCHG_MASK            (0x2000000U)
#define SYSCON_FROCTRL_USBMODCHG_SHIFT           (25U)
/*! USBMODCHG - USB Mode value Change flag. */
#define SYSCON_FROCTRL_USBMODCHG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_USBMODCHG_SHIFT)) & SYSCON_FROCTRL_USBMODCHG_MASK)

#define SYSCON_FROCTRL_HSPDCLK_MASK              (0x40000000U)
#define SYSCON_FROCTRL_HSPDCLK_SHIFT             (30U)
/*! HSPDCLK - High speed clock enable. */
#define SYSCON_FROCTRL_HSPDCLK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_HSPDCLK_SHIFT)) & SYSCON_FROCTRL_HSPDCLK_MASK)

#define SYSCON_FROCTRL_WRTRIM_MASK               (0x80000000U)
#define SYSCON_FROCTRL_WRTRIM_SHIFT              (31U)
/*! WRTRIM - Write Trim value. */
#define SYSCON_FROCTRL_WRTRIM(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROCTRL_WRTRIM_SHIFT)) & SYSCON_FROCTRL_WRTRIM_MASK)
/*! @} */

/*! @name SYSOSCCTRL - System oscillator control */
/*! @{ */

#define SYSCON_SYSOSCCTRL_BYPASS_MASK            (0x1U)
#define SYSCON_SYSOSCCTRL_BYPASS_SHIFT           (0U)
/*! BYPASS - Bypass system oscillator. */
#define SYSCON_SYSOSCCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSOSCCTRL_BYPASS_SHIFT)) & SYSCON_SYSOSCCTRL_BYPASS_MASK)

#define SYSCON_SYSOSCCTRL_FREQRANGE_MASK         (0x2U)
#define SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT        (1U)
/*! FREQRANGE - Determines frequency range for system oscillator. */
#define SYSCON_SYSOSCCTRL_FREQRANGE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSOSCCTRL_FREQRANGE_SHIFT)) & SYSCON_SYSOSCCTRL_FREQRANGE_MASK)
/*! @} */

/*! @name WDTOSCCTRL - Watchdog oscillator control */
/*! @{ */

#define SYSCON_WDTOSCCTRL_DIVSEL_MASK            (0x1FU)
#define SYSCON_WDTOSCCTRL_DIVSEL_SHIFT           (0U)
/*! DIVSEL - Divider select. */
#define SYSCON_WDTOSCCTRL_DIVSEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTOSCCTRL_DIVSEL_SHIFT)) & SYSCON_WDTOSCCTRL_DIVSEL_MASK)

#define SYSCON_WDTOSCCTRL_FREQSEL_MASK           (0x3E0U)
#define SYSCON_WDTOSCCTRL_FREQSEL_SHIFT          (5U)
/*! FREQSEL - Frequency select. */
#define SYSCON_WDTOSCCTRL_FREQSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTOSCCTRL_FREQSEL_SHIFT)) & SYSCON_WDTOSCCTRL_FREQSEL_MASK)
/*! @} */

/*! @name RTCOSCCTRL - RTC oscillator 32 kHz output control */
/*! @{ */

#define SYSCON_RTCOSCCTRL_EN_MASK                (0x1U)
#define SYSCON_RTCOSCCTRL_EN_SHIFT               (0U)
/*! EN - RTC 32 kHz clock enable. */
#define SYSCON_RTCOSCCTRL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_RTCOSCCTRL_EN_SHIFT)) & SYSCON_RTCOSCCTRL_EN_MASK)
/*! @} */

/*! @name USBPLLCTRL - USB PLL control */
/*! @{ */

#define SYSCON_USBPLLCTRL_MSEL_MASK              (0xFFU)
#define SYSCON_USBPLLCTRL_MSEL_SHIFT             (0U)
/*! MSEL - PLL feedback Divider value. */
#define SYSCON_USBPLLCTRL_MSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLCTRL_MSEL_SHIFT)) & SYSCON_USBPLLCTRL_MSEL_MASK)

#define SYSCON_USBPLLCTRL_PSEL_MASK              (0x300U)
#define SYSCON_USBPLLCTRL_PSEL_SHIFT             (8U)
/*! PSEL - PLL Divider value. */
#define SYSCON_USBPLLCTRL_PSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLCTRL_PSEL_SHIFT)) & SYSCON_USBPLLCTRL_PSEL_MASK)

#define SYSCON_USBPLLCTRL_NSEL_MASK              (0xC00U)
#define SYSCON_USBPLLCTRL_NSEL_SHIFT             (10U)
/*! NSEL - PLL feedback Divider value. */
#define SYSCON_USBPLLCTRL_NSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLCTRL_NSEL_SHIFT)) & SYSCON_USBPLLCTRL_NSEL_MASK)

#define SYSCON_USBPLLCTRL_DIRECT_MASK            (0x1000U)
#define SYSCON_USBPLLCTRL_DIRECT_SHIFT           (12U)
/*! DIRECT - Direct CCO clock output control.
 *  0b0..CCO Clock signal goes through post divider.
 *  0b1..CCO Clock signal goes directly to output(s)..
 */
#define SYSCON_USBPLLCTRL_DIRECT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLCTRL_DIRECT_SHIFT)) & SYSCON_USBPLLCTRL_DIRECT_MASK)

#define SYSCON_USBPLLCTRL_BYPASS_MASK            (0x2000U)
#define SYSCON_USBPLLCTRL_BYPASS_SHIFT           (13U)
/*! BYPASS - Input clock bypass control.
 *  0b0..CCO clock is sent to post dividers..
 *  0b1..PLL input clock is sent to post dividers..
 */
#define SYSCON_USBPLLCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLCTRL_BYPASS_SHIFT)) & SYSCON_USBPLLCTRL_BYPASS_MASK)

#define SYSCON_USBPLLCTRL_FBSEL_MASK             (0x4000U)
#define SYSCON_USBPLLCTRL_FBSEL_SHIFT            (14U)
/*! FBSEL - Feedback divider input clock control. */
#define SYSCON_USBPLLCTRL_FBSEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLCTRL_FBSEL_SHIFT)) & SYSCON_USBPLLCTRL_FBSEL_MASK)
/*! @} */

/*! @name USBPLLSTAT - USB PLL status */
/*! @{ */

#define SYSCON_USBPLLSTAT_LOCK_MASK              (0x1U)
#define SYSCON_USBPLLSTAT_LOCK_SHIFT             (0U)
/*! LOCK - USBPLL lock indicator. */
#define SYSCON_USBPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USBPLLSTAT_LOCK_SHIFT)) & SYSCON_USBPLLSTAT_LOCK_MASK)
/*! @} */

/*! @name SYSPLLCTRL - System PLL control */
/*! @{ */

#define SYSCON_SYSPLLCTRL_SELR_MASK              (0xFU)
#define SYSCON_SYSPLLCTRL_SELR_SHIFT             (0U)
/*! SELR - Bandwidth select R value. */
#define SYSCON_SYSPLLCTRL_SELR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELR_SHIFT)) & SYSCON_SYSPLLCTRL_SELR_MASK)

#define SYSCON_SYSPLLCTRL_SELI_MASK              (0x3F0U)
#define SYSCON_SYSPLLCTRL_SELI_SHIFT             (4U)
/*! SELI - Bandwidth select I value. */
#define SYSCON_SYSPLLCTRL_SELI(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELI_SHIFT)) & SYSCON_SYSPLLCTRL_SELI_MASK)

#define SYSCON_SYSPLLCTRL_SELP_MASK              (0x7C00U)
#define SYSCON_SYSPLLCTRL_SELP_SHIFT             (10U)
/*! SELP - Bandwidth select P value. */
#define SYSCON_SYSPLLCTRL_SELP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_SELP_SHIFT)) & SYSCON_SYSPLLCTRL_SELP_MASK)

#define SYSCON_SYSPLLCTRL_BYPASS_MASK            (0x8000U)
#define SYSCON_SYSPLLCTRL_BYPASS_SHIFT           (15U)
/*! BYPASS - PLL bypass control.
 *  0b0..Bypass disabled. PLL CCO is sent to the PLL post-dividers.
 *  0b1..Bypass enabled. PLL input clock is sent directly to the PLL output (default).
 */
#define SYSCON_SYSPLLCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_BYPASS_SHIFT)) & SYSCON_SYSPLLCTRL_BYPASS_MASK)

#define SYSCON_SYSPLLCTRL_UPLIMOFF_MASK          (0x20000U)
#define SYSCON_SYSPLLCTRL_UPLIMOFF_SHIFT         (17U)
/*! UPLIMOFF - Disable upper frequency limiter. */
#define SYSCON_SYSPLLCTRL_UPLIMOFF(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_UPLIMOFF_SHIFT)) & SYSCON_SYSPLLCTRL_UPLIMOFF_MASK)

#define SYSCON_SYSPLLCTRL_DIRECTI_MASK           (0x80000U)
#define SYSCON_SYSPLLCTRL_DIRECTI_SHIFT          (19U)
/*! DIRECTI - PLL0 direct input enable. */
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
/*! LOCK - PLL lock indicator. */
#define SYSCON_SYSPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLSTAT_LOCK_SHIFT)) & SYSCON_SYSPLLSTAT_LOCK_MASK)
/*! @} */

/*! @name SYSPLLNDEC - PLL N divider */
/*! @{ */

#define SYSCON_SYSPLLNDEC_NDEC_MASK              (0x3FFU)
#define SYSCON_SYSPLLNDEC_NDEC_SHIFT             (0U)
/*! NDEC - Decoded N-divider coefficient value. */
#define SYSCON_SYSPLLNDEC_NDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLNDEC_NDEC_SHIFT)) & SYSCON_SYSPLLNDEC_NDEC_MASK)

#define SYSCON_SYSPLLNDEC_NREQ_MASK              (0x400U)
#define SYSCON_SYSPLLNDEC_NREQ_SHIFT             (10U)
/*! NREQ - NDEC reload request. */
#define SYSCON_SYSPLLNDEC_NREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLNDEC_NREQ_SHIFT)) & SYSCON_SYSPLLNDEC_NREQ_MASK)
/*! @} */

/*! @name SYSPLLPDEC - PLL P divider */
/*! @{ */

#define SYSCON_SYSPLLPDEC_PDEC_MASK              (0x7FU)
#define SYSCON_SYSPLLPDEC_PDEC_SHIFT             (0U)
/*! PDEC - Decoded P-divider coefficient value. */
#define SYSCON_SYSPLLPDEC_PDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLPDEC_PDEC_SHIFT)) & SYSCON_SYSPLLPDEC_PDEC_MASK)

#define SYSCON_SYSPLLPDEC_PREQ_MASK              (0x80U)
#define SYSCON_SYSPLLPDEC_PREQ_SHIFT             (7U)
/*! PREQ - . */
#define SYSCON_SYSPLLPDEC_PREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLPDEC_PREQ_SHIFT)) & SYSCON_SYSPLLPDEC_PREQ_MASK)
/*! @} */

/*! @name SYSPLLMDEC - System PLL M divider */
/*! @{ */

#define SYSCON_SYSPLLMDEC_MDEC_MASK              (0x1FFFFU)
#define SYSCON_SYSPLLMDEC_MDEC_SHIFT             (0U)
/*! MDEC - Decoded M-divider coefficient value. */
#define SYSCON_SYSPLLMDEC_MDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLMDEC_MDEC_SHIFT)) & SYSCON_SYSPLLMDEC_MDEC_MASK)

#define SYSCON_SYSPLLMDEC_MREQ_MASK              (0x20000U)
#define SYSCON_SYSPLLMDEC_MREQ_SHIFT             (17U)
/*! MREQ - MDEC reload request. */
#define SYSCON_SYSPLLMDEC_MREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLMDEC_MREQ_SHIFT)) & SYSCON_SYSPLLMDEC_MREQ_MASK)
/*! @} */

/*! @name AUDPLLCTRL - Audio PLL control */
/*! @{ */

#define SYSCON_AUDPLLCTRL_SELR_MASK              (0xFU)
#define SYSCON_AUDPLLCTRL_SELR_SHIFT             (0U)
/*! SELR - Bandwidth select R value. */
#define SYSCON_AUDPLLCTRL_SELR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_SELR_SHIFT)) & SYSCON_AUDPLLCTRL_SELR_MASK)

#define SYSCON_AUDPLLCTRL_SELI_MASK              (0x3F0U)
#define SYSCON_AUDPLLCTRL_SELI_SHIFT             (4U)
/*! SELI - Bandwidth select I value. */
#define SYSCON_AUDPLLCTRL_SELI(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_SELI_SHIFT)) & SYSCON_AUDPLLCTRL_SELI_MASK)

#define SYSCON_AUDPLLCTRL_SELP_MASK              (0x7C00U)
#define SYSCON_AUDPLLCTRL_SELP_SHIFT             (10U)
/*! SELP - . */
#define SYSCON_AUDPLLCTRL_SELP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_SELP_SHIFT)) & SYSCON_AUDPLLCTRL_SELP_MASK)

#define SYSCON_AUDPLLCTRL_BYPASS_MASK            (0x8000U)
#define SYSCON_AUDPLLCTRL_BYPASS_SHIFT           (15U)
/*! BYPASS - PLL bypass control.
 *  0b0..Bypass disabled. PLL CCO is sent to the PLL post-dividers.
 *  0b1..Bypass enabled. PLL input clock is sent directly to the PLL output (default).
 */
#define SYSCON_AUDPLLCTRL_BYPASS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_BYPASS_SHIFT)) & SYSCON_AUDPLLCTRL_BYPASS_MASK)

#define SYSCON_AUDPLLCTRL_UPLIMOFF_MASK          (0x20000U)
#define SYSCON_AUDPLLCTRL_UPLIMOFF_SHIFT         (17U)
/*! UPLIMOFF - Disable upper frequency limiter. */
#define SYSCON_AUDPLLCTRL_UPLIMOFF(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_UPLIMOFF_SHIFT)) & SYSCON_AUDPLLCTRL_UPLIMOFF_MASK)

#define SYSCON_AUDPLLCTRL_DIRECTI_MASK           (0x80000U)
#define SYSCON_AUDPLLCTRL_DIRECTI_SHIFT          (19U)
/*! DIRECTI - PLL direct input enable. */
#define SYSCON_AUDPLLCTRL_DIRECTI(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_DIRECTI_SHIFT)) & SYSCON_AUDPLLCTRL_DIRECTI_MASK)

#define SYSCON_AUDPLLCTRL_DIRECTO_MASK           (0x100000U)
#define SYSCON_AUDPLLCTRL_DIRECTO_SHIFT          (20U)
/*! DIRECTO - PLL direct output enable
 *  0b0..Disabled. The PLL output divider (P divider) is used to create the PLL output.
 *  0b1..Enabled. The PLL output divider (P divider) is bypassed, the PLL CCO output is used as the PLL output.
 */
#define SYSCON_AUDPLLCTRL_DIRECTO(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLCTRL_DIRECTO_SHIFT)) & SYSCON_AUDPLLCTRL_DIRECTO_MASK)
/*! @} */

/*! @name AUDPLLSTAT - Audio PLL status */
/*! @{ */

#define SYSCON_AUDPLLSTAT_LOCK_MASK              (0x1U)
#define SYSCON_AUDPLLSTAT_LOCK_SHIFT             (0U)
/*! LOCK - PLL lock indicator. */
#define SYSCON_AUDPLLSTAT_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLSTAT_LOCK_SHIFT)) & SYSCON_AUDPLLSTAT_LOCK_MASK)
/*! @} */

/*! @name AUDPLLNDEC - Audio PLL N divider */
/*! @{ */

#define SYSCON_AUDPLLNDEC_NDEC_MASK              (0x3FFU)
#define SYSCON_AUDPLLNDEC_NDEC_SHIFT             (0U)
/*! NDEC - Decoded N-divider coefficient value. */
#define SYSCON_AUDPLLNDEC_NDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLNDEC_NDEC_SHIFT)) & SYSCON_AUDPLLNDEC_NDEC_MASK)

#define SYSCON_AUDPLLNDEC_NREQ_MASK              (0x400U)
#define SYSCON_AUDPLLNDEC_NREQ_SHIFT             (10U)
/*! NREQ - NDEC reload request. */
#define SYSCON_AUDPLLNDEC_NREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLNDEC_NREQ_SHIFT)) & SYSCON_AUDPLLNDEC_NREQ_MASK)
/*! @} */

/*! @name AUDPLLPDEC - Audio PLL P divider */
/*! @{ */

#define SYSCON_AUDPLLPDEC_PDEC_MASK              (0x7FU)
#define SYSCON_AUDPLLPDEC_PDEC_SHIFT             (0U)
/*! PDEC - Decoded P-divider coefficient value. */
#define SYSCON_AUDPLLPDEC_PDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLPDEC_PDEC_SHIFT)) & SYSCON_AUDPLLPDEC_PDEC_MASK)

#define SYSCON_AUDPLLPDEC_PREQ_MASK              (0x80U)
#define SYSCON_AUDPLLPDEC_PREQ_SHIFT             (7U)
/*! PREQ - PDEC reload request. */
#define SYSCON_AUDPLLPDEC_PREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLPDEC_PREQ_SHIFT)) & SYSCON_AUDPLLPDEC_PREQ_MASK)
/*! @} */

/*! @name AUDPLLMDEC - Audio PLL M divider */
/*! @{ */

#define SYSCON_AUDPLLMDEC_MDEC_MASK              (0x1FFFFU)
#define SYSCON_AUDPLLMDEC_MDEC_SHIFT             (0U)
/*! MDEC - Decoded M-divider coefficient value. */
#define SYSCON_AUDPLLMDEC_MDEC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLMDEC_MDEC_SHIFT)) & SYSCON_AUDPLLMDEC_MDEC_MASK)

#define SYSCON_AUDPLLMDEC_MREQ_MASK              (0x20000U)
#define SYSCON_AUDPLLMDEC_MREQ_SHIFT             (17U)
/*! MREQ - MDEC reload request. */
#define SYSCON_AUDPLLMDEC_MREQ(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLMDEC_MREQ_SHIFT)) & SYSCON_AUDPLLMDEC_MREQ_MASK)
/*! @} */

/*! @name AUDPLLFRAC - Audio PLL fractional divider control */
/*! @{ */

#define SYSCON_AUDPLLFRAC_CTRL_MASK              (0x3FFFFFU)
#define SYSCON_AUDPLLFRAC_CTRL_SHIFT             (0U)
/*! CTRL - PLL fractional divider control word */
#define SYSCON_AUDPLLFRAC_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLFRAC_CTRL_SHIFT)) & SYSCON_AUDPLLFRAC_CTRL_MASK)

#define SYSCON_AUDPLLFRAC_REQ_MASK               (0x400000U)
#define SYSCON_AUDPLLFRAC_REQ_SHIFT              (22U)
/*! REQ - Writing 1 to REQ signal loads CTRL value into fractional wrapper modulator. */
#define SYSCON_AUDPLLFRAC_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLFRAC_REQ_SHIFT)) & SYSCON_AUDPLLFRAC_REQ_MASK)

#define SYSCON_AUDPLLFRAC_SEL_EXT_MASK           (0x800000U)
#define SYSCON_AUDPLLFRAC_SEL_EXT_SHIFT          (23U)
/*! SEL_EXT - Select fractional divider. */
#define SYSCON_AUDPLLFRAC_SEL_EXT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AUDPLLFRAC_SEL_EXT_SHIFT)) & SYSCON_AUDPLLFRAC_SEL_EXT_MASK)
/*! @} */

/*! @name PDSLEEPCFG - Sleep configuration register */
/*! @{ */

#define SYSCON_PDSLEEPCFG_PDEN_USB1_PHY_MASK     (0x1U)
#define SYSCON_PDSLEEPCFG_PDEN_USB1_PHY_SHIFT    (0U)
/*! PDEN_USB1_PHY - USB1 high speed PHY (also, enable/disable bit 28 in PDRUNCFG0 register). */
#define SYSCON_PDSLEEPCFG_PDEN_USB1_PHY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_USB1_PHY_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_USB1_PHY_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_USB1_PLL_MASK     (0x2U)
#define SYSCON_PDSLEEPCFG_PDEN_USB1_PLL_SHIFT    (1U)
/*! PDEN_USB1_PLL - USB PLL (PLL1) power (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDSLEEPCFG_PDEN_USB1_PLL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_USB1_PLL_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_USB1_PLL_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_AUD_PLL_MASK      (0x4U)
#define SYSCON_PDSLEEPCFG_PDEN_AUD_PLL_SHIFT     (2U)
/*! PDEN_AUD_PLL - Audio PLL (PLL2) power and fractional divider (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDSLEEPCFG_PDEN_AUD_PLL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_AUD_PLL_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_AUD_PLL_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_SYSOSC_MASK       (0x8U)
#define SYSCON_PDSLEEPCFG_PDEN_SYSOSC_SHIFT      (3U)
/*! PDEN_SYSOSC - System Oscillator Power (also, enable/disable bit 9 in PDRUNCFG0 register). */
#define SYSCON_PDSLEEPCFG_PDEN_SYSOSC(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_SYSOSC_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_SYSOSC_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_FRO_MASK          (0x10U)
#define SYSCON_PDSLEEPCFG_PDEN_FRO_SHIFT         (4U)
/*! PDEN_FRO - FRO oscillator. */
#define SYSCON_PDSLEEPCFG_PDEN_FRO(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_FRO_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_FRO_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_EEPROM_MASK       (0x20U)
#define SYSCON_PDSLEEPCFG_PDEN_EEPROM_SHIFT      (5U)
/*! PDEN_EEPROM - EEPROM power (also, enable/disable bit 29 in PDRUNCFG0 register). */
#define SYSCON_PDSLEEPCFG_PDEN_EEPROM(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_EEPROM_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_EEPROM_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_TS_MASK           (0x40U)
#define SYSCON_PDSLEEPCFG_PDEN_TS_SHIFT          (6U)
/*! PDEN_TS - Temp sensor. */
#define SYSCON_PDSLEEPCFG_PDEN_TS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_TS_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_TS_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_BOD_RST_MASK      (0x80U)
#define SYSCON_PDSLEEPCFG_PDEN_BOD_RST_SHIFT     (7U)
/*! PDEN_BOD_RST - Brown-out Detect reset. */
#define SYSCON_PDSLEEPCFG_PDEN_BOD_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_BOD_RST_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_BOD_RST_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_RNG_MASK          (0x80U)
#define SYSCON_PDSLEEPCFG_PDEN_RNG_SHIFT         (7U)
/*! PDEN_RNG - Random Number Generator Power. */
#define SYSCON_PDSLEEPCFG_PDEN_RNG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_RNG_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_RNG_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_BOD_INTR_MASK     (0x100U)
#define SYSCON_PDSLEEPCFG_PDEN_BOD_INTR_SHIFT    (8U)
/*! PDEN_BOD_INTR - Brown-out Detect interrupt. */
#define SYSCON_PDSLEEPCFG_PDEN_BOD_INTR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_BOD_INTR_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_BOD_INTR_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VD2_ANA_MASK      (0x200U)
#define SYSCON_PDSLEEPCFG_PDEN_VD2_ANA_SHIFT     (9U)
/*! PDEN_VD2_ANA - Analog supply for System Oscillator (also enable/disable bit 3 in PDRUNCFG1
 *    register), Temperature Sensor (also, enable/disable bit 6), ADC (also, enable/disable bits 10, 19,
 *    and 23).
 */
#define SYSCON_PDSLEEPCFG_PDEN_VD2_ANA(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VD2_ANA_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VD2_ANA_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_ADC0_MASK         (0x400U)
#define SYSCON_PDSLEEPCFG_PDEN_ADC0_SHIFT        (10U)
/*! PDEN_ADC0 - ADC power. */
#define SYSCON_PDSLEEPCFG_PDEN_ADC0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_ADC0_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_ADC0_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_SRAMX_MASK        (0x2000U)
#define SYSCON_PDSLEEPCFG_PDEN_SRAMX_SHIFT       (13U)
/*! PDEN_SRAMX - PDEN_SRAMX controls SRAMX (also enable/disable bit 27). */
#define SYSCON_PDSLEEPCFG_PDEN_SRAMX(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_SRAMX_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_SRAMX_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_SRAM0_MASK        (0x4000U)
#define SYSCON_PDSLEEPCFG_PDEN_SRAM0_SHIFT       (14U)
/*! PDEN_SRAM0 - PDEN_SRAM0 controls SRAM0 (also enable/disable bit 27). */
#define SYSCON_PDSLEEPCFG_PDEN_SRAM0(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_SRAM0_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_SRAM0_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_SRAM1_2_3_MASK    (0x8000U)
#define SYSCON_PDSLEEPCFG_PDEN_SRAM1_2_3_SHIFT   (15U)
/*! PDEN_SRAM1_2_3 - PDEN_SRAM1_2_3 controls SRAM1, SRAM2, and SRAM3 (also enable/disable bit 27). */
#define SYSCON_PDSLEEPCFG_PDEN_SRAM1_2_3(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_SRAM1_2_3_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_SRAM1_2_3_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_USB_RAM_MASK      (0x10000U)
#define SYSCON_PDSLEEPCFG_PDEN_USB_RAM_SHIFT     (16U)
/*! PDEN_USB_RAM - PDEN_USB_SRAM controls USB_RAM (also enable/disable bit 27). */
#define SYSCON_PDSLEEPCFG_PDEN_USB_RAM(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_USB_RAM_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_USB_RAM_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_ROM_MASK          (0x20000U)
#define SYSCON_PDSLEEPCFG_PDEN_ROM_SHIFT         (17U)
/*! PDEN_ROM - ROM (also enable/disable bit 27). */
#define SYSCON_PDSLEEPCFG_PDEN_ROM(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_ROM_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_ROM_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VDDA_MASK         (0x80000U)
#define SYSCON_PDSLEEPCFG_PDEN_VDDA_SHIFT        (19U)
/*! PDEN_VDDA - Vdda to the ADC, must be enabled for the ADC to work (also enable/disable bit 9, 10, and 23). */
#define SYSCON_PDSLEEPCFG_PDEN_VDDA(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VDDA_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VDDA_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_WDT_OSC_MASK      (0x100000U)
#define SYSCON_PDSLEEPCFG_PDEN_WDT_OSC_SHIFT     (20U)
/*! PDEN_WDT_OSC - Watchdog oscillator. */
#define SYSCON_PDSLEEPCFG_PDEN_WDT_OSC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_WDT_OSC_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_WDT_OSC_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_USB0_PHY_MASK     (0x200000U)
#define SYSCON_PDSLEEPCFG_PDEN_USB0_PHY_SHIFT    (21U)
/*! PDEN_USB0_PHY - USB0 PHY power (also enable/disable bit 28). */
#define SYSCON_PDSLEEPCFG_PDEN_USB0_PHY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_USB0_PHY_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_USB0_PHY_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_SYS_PLL_MASK      (0x400000U)
#define SYSCON_PDSLEEPCFG_PDEN_SYS_PLL_SHIFT     (22U)
/*! PDEN_SYS_PLL - System PLL (PLL0) power (also enable/disable bit 26). */
#define SYSCON_PDSLEEPCFG_PDEN_SYS_PLL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_SYS_PLL_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_SYS_PLL_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VREFP_MASK        (0x800000U)
#define SYSCON_PDSLEEPCFG_PDEN_VREFP_SHIFT       (23U)
/*! PDEN_VREFP - VREFP to the ADC must be enabled for the ADC to work (also enable/disable bit 9, 10, and 19). */
#define SYSCON_PDSLEEPCFG_PDEN_VREFP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VREFP_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VREFP_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VD3_MASK          (0x4000000U)
#define SYSCON_PDSLEEPCFG_PDEN_VD3_SHIFT         (26U)
/*! PDEN_VD3 - Power control for all PLLs. */
#define SYSCON_PDSLEEPCFG_PDEN_VD3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VD3_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VD3_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VD4_MASK          (0x8000000U)
#define SYSCON_PDSLEEPCFG_PDEN_VD4_SHIFT         (27U)
/*! PDEN_VD4 - Power control for all SRAMs and ROM. */
#define SYSCON_PDSLEEPCFG_PDEN_VD4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VD4_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VD4_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VD5_MASK          (0x10000000U)
#define SYSCON_PDSLEEPCFG_PDEN_VD5_SHIFT         (28U)
/*! PDEN_VD5 - Power control both USB0 PHY and USB1 PHY. */
#define SYSCON_PDSLEEPCFG_PDEN_VD5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VD5_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VD5_MASK)

#define SYSCON_PDSLEEPCFG_PDEN_VD6_MASK          (0x20000000U)
#define SYSCON_PDSLEEPCFG_PDEN_VD6_SHIFT         (29U)
/*! PDEN_VD6 - Power control for EEPROM. */
#define SYSCON_PDSLEEPCFG_PDEN_VD6(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDSLEEPCFG_PDEN_VD6_SHIFT)) & SYSCON_PDSLEEPCFG_PDEN_VD6_MASK)
/*! @} */

/*! @name PDRUNCFG - Power configuration register */
/*! @{ */

#define SYSCON_PDRUNCFG_PDEN_USB1_PHY_MASK       (0x1U)
#define SYSCON_PDRUNCFG_PDEN_USB1_PHY_SHIFT      (0U)
/*! PDEN_USB1_PHY - USB1 high speed PHY (also, enable/disable bit 28 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFG_PDEN_USB1_PHY(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_USB1_PHY_SHIFT)) & SYSCON_PDRUNCFG_PDEN_USB1_PHY_MASK)

#define SYSCON_PDRUNCFG_PDEN_USB1_PLL_MASK       (0x2U)
#define SYSCON_PDRUNCFG_PDEN_USB1_PLL_SHIFT      (1U)
/*! PDEN_USB1_PLL - USB PLL (PLL1) power (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFG_PDEN_USB1_PLL(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_USB1_PLL_SHIFT)) & SYSCON_PDRUNCFG_PDEN_USB1_PLL_MASK)

#define SYSCON_PDRUNCFG_PDEN_AUD_PLL_MASK        (0x4U)
#define SYSCON_PDRUNCFG_PDEN_AUD_PLL_SHIFT       (2U)
/*! PDEN_AUD_PLL - Audio PLL (PLL2) power and fractional divider (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFG_PDEN_AUD_PLL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_AUD_PLL_SHIFT)) & SYSCON_PDRUNCFG_PDEN_AUD_PLL_MASK)

#define SYSCON_PDRUNCFG_PDEN_SYSOSC_MASK         (0x8U)
#define SYSCON_PDRUNCFG_PDEN_SYSOSC_SHIFT        (3U)
/*! PDEN_SYSOSC - System Oscillator Power (also, enable/disable bit 9 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFG_PDEN_SYSOSC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SYSOSC_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SYSOSC_MASK)

#define SYSCON_PDRUNCFG_PDEN_FRO_MASK            (0x10U)
#define SYSCON_PDRUNCFG_PDEN_FRO_SHIFT           (4U)
/*! PDEN_FRO - FRO oscillator. */
#define SYSCON_PDRUNCFG_PDEN_FRO(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_FRO_SHIFT)) & SYSCON_PDRUNCFG_PDEN_FRO_MASK)

#define SYSCON_PDRUNCFG_PDEN_EEPROM_MASK         (0x20U)
#define SYSCON_PDRUNCFG_PDEN_EEPROM_SHIFT        (5U)
/*! PDEN_EEPROM - EEPROM power (also, enable/disable bit 29 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFG_PDEN_EEPROM(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_EEPROM_SHIFT)) & SYSCON_PDRUNCFG_PDEN_EEPROM_MASK)

#define SYSCON_PDRUNCFG_PDEN_TS_MASK             (0x40U)
#define SYSCON_PDRUNCFG_PDEN_TS_SHIFT            (6U)
/*! PDEN_TS - Temp sensor. */
#define SYSCON_PDRUNCFG_PDEN_TS(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_TS_SHIFT)) & SYSCON_PDRUNCFG_PDEN_TS_MASK)

#define SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK        (0x80U)
#define SYSCON_PDRUNCFG_PDEN_BOD_RST_SHIFT       (7U)
/*! PDEN_BOD_RST - Brown-out Detect reset. */
#define SYSCON_PDRUNCFG_PDEN_BOD_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_BOD_RST_SHIFT)) & SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK)

#define SYSCON_PDRUNCFG_PDEN_RNG_MASK            (0x80U)
#define SYSCON_PDRUNCFG_PDEN_RNG_SHIFT           (7U)
/*! PDEN_RNG - Random Number Generator Power. */
#define SYSCON_PDRUNCFG_PDEN_RNG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_RNG_SHIFT)) & SYSCON_PDRUNCFG_PDEN_RNG_MASK)

#define SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK       (0x100U)
#define SYSCON_PDRUNCFG_PDEN_BOD_INTR_SHIFT      (8U)
/*! PDEN_BOD_INTR - Brown-out Detect interrupt. */
#define SYSCON_PDRUNCFG_PDEN_BOD_INTR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_BOD_INTR_SHIFT)) & SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK)

#define SYSCON_PDRUNCFG_PDEN_VD2_ANA_MASK        (0x200U)
#define SYSCON_PDRUNCFG_PDEN_VD2_ANA_SHIFT       (9U)
/*! PDEN_VD2_ANA - Analog supply for System Oscillator (also enable/disable bit 3 in PDRUNCFG1
 *    register), Temperature Sensor (also, enable/disable bit 6), ADC (also, enable/disable bits 10, 19,
 *    and 23).
 */
#define SYSCON_PDRUNCFG_PDEN_VD2_ANA(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VD2_ANA_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VD2_ANA_MASK)

#define SYSCON_PDRUNCFG_PDEN_ADC0_MASK           (0x400U)
#define SYSCON_PDRUNCFG_PDEN_ADC0_SHIFT          (10U)
/*! PDEN_ADC0 - ADC power. */
#define SYSCON_PDRUNCFG_PDEN_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_ADC0_SHIFT)) & SYSCON_PDRUNCFG_PDEN_ADC0_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAMX_MASK          (0x2000U)
#define SYSCON_PDRUNCFG_PDEN_SRAMX_SHIFT         (13U)
/*! PDEN_SRAMX - PDEN_SRAMX controls SRAMX (also enable/disable bit 27). */
#define SYSCON_PDRUNCFG_PDEN_SRAMX(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAMX_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAMX_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAM0_MASK          (0x4000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM0_SHIFT         (14U)
/*! PDEN_SRAM0 - PDEN_SRAM0 controls SRAM0 (also enable/disable bit 27). */
#define SYSCON_PDRUNCFG_PDEN_SRAM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM0_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM0_MASK)

#define SYSCON_PDRUNCFG_PDEN_SRAM1_2_3_MASK      (0x8000U)
#define SYSCON_PDRUNCFG_PDEN_SRAM1_2_3_SHIFT     (15U)
/*! PDEN_SRAM1_2_3 - PDEN_SRAM1_2_3 controls SRAM1, SRAM2, and SRAM3 (also enable/disable bit 27). */
#define SYSCON_PDRUNCFG_PDEN_SRAM1_2_3(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SRAM1_2_3_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SRAM1_2_3_MASK)

#define SYSCON_PDRUNCFG_PDEN_USB_RAM_MASK        (0x10000U)
#define SYSCON_PDRUNCFG_PDEN_USB_RAM_SHIFT       (16U)
/*! PDEN_USB_RAM - PDEN_USB_SRAM controls USB_RAM (also enable/disable bit 27). */
#define SYSCON_PDRUNCFG_PDEN_USB_RAM(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_USB_RAM_SHIFT)) & SYSCON_PDRUNCFG_PDEN_USB_RAM_MASK)

#define SYSCON_PDRUNCFG_PDEN_ROM_MASK            (0x20000U)
#define SYSCON_PDRUNCFG_PDEN_ROM_SHIFT           (17U)
/*! PDEN_ROM - ROM (also enable/disable bit 27). */
#define SYSCON_PDRUNCFG_PDEN_ROM(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_ROM_SHIFT)) & SYSCON_PDRUNCFG_PDEN_ROM_MASK)

#define SYSCON_PDRUNCFG_PDEN_VDDA_MASK           (0x80000U)
#define SYSCON_PDRUNCFG_PDEN_VDDA_SHIFT          (19U)
/*! PDEN_VDDA - Vdda to the ADC, must be enabled for the ADC to work (also enable/disable bit 9, 10, and 23). */
#define SYSCON_PDRUNCFG_PDEN_VDDA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VDDA_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VDDA_MASK)

#define SYSCON_PDRUNCFG_PDEN_WDT_OSC_MASK        (0x100000U)
#define SYSCON_PDRUNCFG_PDEN_WDT_OSC_SHIFT       (20U)
/*! PDEN_WDT_OSC - Watchdog oscillator. */
#define SYSCON_PDRUNCFG_PDEN_WDT_OSC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_WDT_OSC_SHIFT)) & SYSCON_PDRUNCFG_PDEN_WDT_OSC_MASK)

#define SYSCON_PDRUNCFG_PDEN_USB0_PHY_MASK       (0x200000U)
#define SYSCON_PDRUNCFG_PDEN_USB0_PHY_SHIFT      (21U)
/*! PDEN_USB0_PHY - USB0 PHY power (also enable/disable bit 28). */
#define SYSCON_PDRUNCFG_PDEN_USB0_PHY(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_USB0_PHY_SHIFT)) & SYSCON_PDRUNCFG_PDEN_USB0_PHY_MASK)

#define SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK        (0x400000U)
#define SYSCON_PDRUNCFG_PDEN_SYS_PLL_SHIFT       (22U)
/*! PDEN_SYS_PLL - System PLL (PLL0) power (also enable/disable bit 26). */
#define SYSCON_PDRUNCFG_PDEN_SYS_PLL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_SYS_PLL_SHIFT)) & SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK)

#define SYSCON_PDRUNCFG_PDEN_VREFP_MASK          (0x800000U)
#define SYSCON_PDRUNCFG_PDEN_VREFP_SHIFT         (23U)
/*! PDEN_VREFP - VREFP to the ADC must be enabled for the ADC to work (also enable/disable bit 9, 10, and 19). */
#define SYSCON_PDRUNCFG_PDEN_VREFP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VREFP_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VREFP_MASK)

#define SYSCON_PDRUNCFG_PDEN_VD3_MASK            (0x4000000U)
#define SYSCON_PDRUNCFG_PDEN_VD3_SHIFT           (26U)
/*! PDEN_VD3 - Power control for all PLLs. */
#define SYSCON_PDRUNCFG_PDEN_VD3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VD3_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VD3_MASK)

#define SYSCON_PDRUNCFG_PDEN_VD4_MASK            (0x8000000U)
#define SYSCON_PDRUNCFG_PDEN_VD4_SHIFT           (27U)
/*! PDEN_VD4 - Power control for all SRAMs and ROM. */
#define SYSCON_PDRUNCFG_PDEN_VD4(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VD4_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VD4_MASK)

#define SYSCON_PDRUNCFG_PDEN_VD5_MASK            (0x10000000U)
#define SYSCON_PDRUNCFG_PDEN_VD5_SHIFT           (28U)
/*! PDEN_VD5 - Power control both USB0 PHY and USB1 PHY. */
#define SYSCON_PDRUNCFG_PDEN_VD5(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VD5_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VD5_MASK)

#define SYSCON_PDRUNCFG_PDEN_VD6_MASK            (0x20000000U)
#define SYSCON_PDRUNCFG_PDEN_VD6_SHIFT           (29U)
/*! PDEN_VD6 - Power control for EEPROM. */
#define SYSCON_PDRUNCFG_PDEN_VD6(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFG_PDEN_VD6_SHIFT)) & SYSCON_PDRUNCFG_PDEN_VD6_MASK)
/*! @} */

/*! @name PDRUNCFGSET - Power configuration set register */
/*! @{ */

#define SYSCON_PDRUNCFGSET_PDEN_USB1_PHY_MASK    (0x1U)
#define SYSCON_PDRUNCFGSET_PDEN_USB1_PHY_SHIFT   (0U)
/*! PDEN_USB1_PHY - USB1 high speed PHY (also, enable/disable bit 28 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGSET_PDEN_USB1_PHY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_USB1_PHY_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_USB1_PHY_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_USB1_PLL_MASK    (0x2U)
#define SYSCON_PDRUNCFGSET_PDEN_USB1_PLL_SHIFT   (1U)
/*! PDEN_USB1_PLL - USB PLL (PLL1) power (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGSET_PDEN_USB1_PLL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_USB1_PLL_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_USB1_PLL_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_AUD_PLL_MASK     (0x4U)
#define SYSCON_PDRUNCFGSET_PDEN_AUD_PLL_SHIFT    (2U)
/*! PDEN_AUD_PLL - Audio PLL (PLL2) power and fractional divider (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGSET_PDEN_AUD_PLL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_AUD_PLL_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_AUD_PLL_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_SYSOSC_MASK      (0x8U)
#define SYSCON_PDRUNCFGSET_PDEN_SYSOSC_SHIFT     (3U)
/*! PDEN_SYSOSC - System Oscillator Power (also, enable/disable bit 9 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGSET_PDEN_SYSOSC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_SYSOSC_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_SYSOSC_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_FRO_MASK         (0x10U)
#define SYSCON_PDRUNCFGSET_PDEN_FRO_SHIFT        (4U)
/*! PDEN_FRO - FRO oscillator. */
#define SYSCON_PDRUNCFGSET_PDEN_FRO(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_FRO_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_FRO_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_EEPROM_MASK      (0x20U)
#define SYSCON_PDRUNCFGSET_PDEN_EEPROM_SHIFT     (5U)
/*! PDEN_EEPROM - EEPROM power (also, enable/disable bit 29 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGSET_PDEN_EEPROM(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_EEPROM_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_EEPROM_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_TS_MASK          (0x40U)
#define SYSCON_PDRUNCFGSET_PDEN_TS_SHIFT         (6U)
/*! PDEN_TS - Temp sensor. */
#define SYSCON_PDRUNCFGSET_PDEN_TS(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_TS_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_TS_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_BOD_RST_MASK     (0x80U)
#define SYSCON_PDRUNCFGSET_PDEN_BOD_RST_SHIFT    (7U)
/*! PDEN_BOD_RST - Brown-out Detect reset. */
#define SYSCON_PDRUNCFGSET_PDEN_BOD_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_BOD_RST_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_BOD_RST_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_RNG_MASK         (0x80U)
#define SYSCON_PDRUNCFGSET_PDEN_RNG_SHIFT        (7U)
/*! PDEN_RNG - Random Number Generator Power. */
#define SYSCON_PDRUNCFGSET_PDEN_RNG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_RNG_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_RNG_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_BOD_INTR_MASK    (0x100U)
#define SYSCON_PDRUNCFGSET_PDEN_BOD_INTR_SHIFT   (8U)
/*! PDEN_BOD_INTR - Brown-out Detect interrupt. */
#define SYSCON_PDRUNCFGSET_PDEN_BOD_INTR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_BOD_INTR_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_BOD_INTR_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VD2_ANA_MASK     (0x200U)
#define SYSCON_PDRUNCFGSET_PDEN_VD2_ANA_SHIFT    (9U)
/*! PDEN_VD2_ANA - Analog supply for System Oscillator (also enable/disable bit 3 in PDRUNCFG1
 *    register), Temperature Sensor (also, enable/disable bit 6), ADC (also, enable/disable bits 10, 19,
 *    and 23).
 */
#define SYSCON_PDRUNCFGSET_PDEN_VD2_ANA(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VD2_ANA_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VD2_ANA_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_ADC0_MASK        (0x400U)
#define SYSCON_PDRUNCFGSET_PDEN_ADC0_SHIFT       (10U)
/*! PDEN_ADC0 - ADC power. */
#define SYSCON_PDRUNCFGSET_PDEN_ADC0(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_ADC0_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_ADC0_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_SRAMX_MASK       (0x2000U)
#define SYSCON_PDRUNCFGSET_PDEN_SRAMX_SHIFT      (13U)
/*! PDEN_SRAMX - PDEN_SRAMX controls SRAMX (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGSET_PDEN_SRAMX(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_SRAMX_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_SRAMX_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_SRAM0_MASK       (0x4000U)
#define SYSCON_PDRUNCFGSET_PDEN_SRAM0_SHIFT      (14U)
/*! PDEN_SRAM0 - PDEN_SRAM0 controls SRAM0 (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGSET_PDEN_SRAM0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_SRAM0_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_SRAM0_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_SRAM1_2_3_MASK   (0x8000U)
#define SYSCON_PDRUNCFGSET_PDEN_SRAM1_2_3_SHIFT  (15U)
/*! PDEN_SRAM1_2_3 - PDEN_SRAM1_2_3 controls SRAM1, SRAM2, and SRAM3 (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGSET_PDEN_SRAM1_2_3(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_SRAM1_2_3_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_SRAM1_2_3_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_USB_RAM_MASK     (0x10000U)
#define SYSCON_PDRUNCFGSET_PDEN_USB_RAM_SHIFT    (16U)
/*! PDEN_USB_RAM - PDEN_USB_SRAM controls USB_RAM (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGSET_PDEN_USB_RAM(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_USB_RAM_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_USB_RAM_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_ROM_MASK         (0x20000U)
#define SYSCON_PDRUNCFGSET_PDEN_ROM_SHIFT        (17U)
/*! PDEN_ROM - ROM (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGSET_PDEN_ROM(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_ROM_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_ROM_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VDDA_MASK        (0x80000U)
#define SYSCON_PDRUNCFGSET_PDEN_VDDA_SHIFT       (19U)
/*! PDEN_VDDA - Vdda to the ADC, must be enabled for the ADC to work (also enable/disable bit 9, 10, and 23). */
#define SYSCON_PDRUNCFGSET_PDEN_VDDA(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VDDA_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VDDA_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_WDT_OSC_MASK     (0x100000U)
#define SYSCON_PDRUNCFGSET_PDEN_WDT_OSC_SHIFT    (20U)
/*! PDEN_WDT_OSC - Watchdog oscillator. */
#define SYSCON_PDRUNCFGSET_PDEN_WDT_OSC(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_WDT_OSC_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_WDT_OSC_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_USB0_PHY_MASK    (0x200000U)
#define SYSCON_PDRUNCFGSET_PDEN_USB0_PHY_SHIFT   (21U)
/*! PDEN_USB0_PHY - USB0 PHY power (also enable/disable bit 28). */
#define SYSCON_PDRUNCFGSET_PDEN_USB0_PHY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_USB0_PHY_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_USB0_PHY_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_SYS_PLL_MASK     (0x400000U)
#define SYSCON_PDRUNCFGSET_PDEN_SYS_PLL_SHIFT    (22U)
/*! PDEN_SYS_PLL - System PLL (PLL0) power (also enable/disable bit 26). */
#define SYSCON_PDRUNCFGSET_PDEN_SYS_PLL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_SYS_PLL_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_SYS_PLL_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VREFP_MASK       (0x800000U)
#define SYSCON_PDRUNCFGSET_PDEN_VREFP_SHIFT      (23U)
/*! PDEN_VREFP - VREFP to the ADC must be enabled for the ADC to work (also enable/disable bit 9, 10, and 19). */
#define SYSCON_PDRUNCFGSET_PDEN_VREFP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VREFP_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VREFP_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VD3_MASK         (0x4000000U)
#define SYSCON_PDRUNCFGSET_PDEN_VD3_SHIFT        (26U)
/*! PDEN_VD3 - Power control for all PLLs. */
#define SYSCON_PDRUNCFGSET_PDEN_VD3(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VD3_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VD3_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VD4_MASK         (0x8000000U)
#define SYSCON_PDRUNCFGSET_PDEN_VD4_SHIFT        (27U)
/*! PDEN_VD4 - Power control for all SRAMs and ROM. */
#define SYSCON_PDRUNCFGSET_PDEN_VD4(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VD4_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VD4_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VD5_MASK         (0x10000000U)
#define SYSCON_PDRUNCFGSET_PDEN_VD5_SHIFT        (28U)
/*! PDEN_VD5 - Power control both USB0 PHY and USB1 PHY. */
#define SYSCON_PDRUNCFGSET_PDEN_VD5(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VD5_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VD5_MASK)

#define SYSCON_PDRUNCFGSET_PDEN_VD6_MASK         (0x20000000U)
#define SYSCON_PDRUNCFGSET_PDEN_VD6_SHIFT        (29U)
/*! PDEN_VD6 - Power control for EEPROM. */
#define SYSCON_PDRUNCFGSET_PDEN_VD6(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGSET_PDEN_VD6_SHIFT)) & SYSCON_PDRUNCFGSET_PDEN_VD6_MASK)
/*! @} */

/*! @name PDRUNCFGCLR - Power configuration clear register */
/*! @{ */

#define SYSCON_PDRUNCFGCLR_PDEN_USB1_PHY_MASK    (0x1U)
#define SYSCON_PDRUNCFGCLR_PDEN_USB1_PHY_SHIFT   (0U)
/*! PDEN_USB1_PHY - USB1 high speed PHY (also, enable/disable bit 28 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGCLR_PDEN_USB1_PHY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_USB1_PHY_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_USB1_PHY_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_USB1_PLL_MASK    (0x2U)
#define SYSCON_PDRUNCFGCLR_PDEN_USB1_PLL_SHIFT   (1U)
/*! PDEN_USB1_PLL - USB PLL (PLL1) power (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGCLR_PDEN_USB1_PLL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_USB1_PLL_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_USB1_PLL_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_AUD_PLL_MASK     (0x4U)
#define SYSCON_PDRUNCFGCLR_PDEN_AUD_PLL_SHIFT    (2U)
/*! PDEN_AUD_PLL - Audio PLL (PLL2) power and fractional divider (also, enable/disable bit 26 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGCLR_PDEN_AUD_PLL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_AUD_PLL_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_AUD_PLL_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_SYSOSC_MASK      (0x8U)
#define SYSCON_PDRUNCFGCLR_PDEN_SYSOSC_SHIFT     (3U)
/*! PDEN_SYSOSC - System Oscillator Power (also, enable/disable bit 9 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGCLR_PDEN_SYSOSC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_SYSOSC_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_SYSOSC_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_FRO_MASK         (0x10U)
#define SYSCON_PDRUNCFGCLR_PDEN_FRO_SHIFT        (4U)
/*! PDEN_FRO - FRO oscillator. */
#define SYSCON_PDRUNCFGCLR_PDEN_FRO(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_FRO_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_FRO_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_EEPROM_MASK      (0x20U)
#define SYSCON_PDRUNCFGCLR_PDEN_EEPROM_SHIFT     (5U)
/*! PDEN_EEPROM - EEPROM power (also, enable/disable bit 29 in PDRUNCFG0 register). */
#define SYSCON_PDRUNCFGCLR_PDEN_EEPROM(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_EEPROM_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_EEPROM_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_TS_MASK          (0x40U)
#define SYSCON_PDRUNCFGCLR_PDEN_TS_SHIFT         (6U)
/*! PDEN_TS - Temp sensor. */
#define SYSCON_PDRUNCFGCLR_PDEN_TS(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_TS_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_TS_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_BOD_RST_MASK     (0x80U)
#define SYSCON_PDRUNCFGCLR_PDEN_BOD_RST_SHIFT    (7U)
/*! PDEN_BOD_RST - Brown-out Detect reset. */
#define SYSCON_PDRUNCFGCLR_PDEN_BOD_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_BOD_RST_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_BOD_RST_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_RNG_MASK         (0x80U)
#define SYSCON_PDRUNCFGCLR_PDEN_RNG_SHIFT        (7U)
/*! PDEN_RNG - Random Number Generator Power. */
#define SYSCON_PDRUNCFGCLR_PDEN_RNG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_RNG_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_RNG_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_BOD_INTR_MASK    (0x100U)
#define SYSCON_PDRUNCFGCLR_PDEN_BOD_INTR_SHIFT   (8U)
/*! PDEN_BOD_INTR - Brown-out Detect interrupt. */
#define SYSCON_PDRUNCFGCLR_PDEN_BOD_INTR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_BOD_INTR_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_BOD_INTR_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VD2_ANA_MASK     (0x200U)
#define SYSCON_PDRUNCFGCLR_PDEN_VD2_ANA_SHIFT    (9U)
/*! PDEN_VD2_ANA - Analog supply for System Oscillator (also enable/disable bit 3 in PDRUNCFG1
 *    register), Temperature Sensor (also, enable/disable bit 6), ADC (also, enable/disable bits 10, 19,
 *    and 23).
 */
#define SYSCON_PDRUNCFGCLR_PDEN_VD2_ANA(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VD2_ANA_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VD2_ANA_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_ADC0_MASK        (0x400U)
#define SYSCON_PDRUNCFGCLR_PDEN_ADC0_SHIFT       (10U)
/*! PDEN_ADC0 - ADC power. */
#define SYSCON_PDRUNCFGCLR_PDEN_ADC0(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_ADC0_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_ADC0_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_SRAMX_MASK       (0x2000U)
#define SYSCON_PDRUNCFGCLR_PDEN_SRAMX_SHIFT      (13U)
/*! PDEN_SRAMX - PDEN_SRAMX controls SRAMX (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGCLR_PDEN_SRAMX(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_SRAMX_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_SRAMX_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_SRAM0_MASK       (0x4000U)
#define SYSCON_PDRUNCFGCLR_PDEN_SRAM0_SHIFT      (14U)
/*! PDEN_SRAM0 - PDEN_SRAM0 controls SRAM0 (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGCLR_PDEN_SRAM0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_SRAM0_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_SRAM0_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_SRAM1_2_3_MASK   (0x8000U)
#define SYSCON_PDRUNCFGCLR_PDEN_SRAM1_2_3_SHIFT  (15U)
/*! PDEN_SRAM1_2_3 - PDEN_SRAM1_2_3 controls SRAM1, SRAM2, and SRAM3 (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGCLR_PDEN_SRAM1_2_3(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_SRAM1_2_3_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_SRAM1_2_3_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_USB_RAM_MASK     (0x10000U)
#define SYSCON_PDRUNCFGCLR_PDEN_USB_RAM_SHIFT    (16U)
/*! PDEN_USB_RAM - PDEN_USB_SRAM controls USB_RAM (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGCLR_PDEN_USB_RAM(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_USB_RAM_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_USB_RAM_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_ROM_MASK         (0x20000U)
#define SYSCON_PDRUNCFGCLR_PDEN_ROM_SHIFT        (17U)
/*! PDEN_ROM - ROM (also enable/disable bit 27). */
#define SYSCON_PDRUNCFGCLR_PDEN_ROM(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_ROM_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_ROM_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VDDA_MASK        (0x80000U)
#define SYSCON_PDRUNCFGCLR_PDEN_VDDA_SHIFT       (19U)
/*! PDEN_VDDA - Vdda to the ADC, must be enabled for the ADC to work (also enable/disable bit 9, 10, and 23). */
#define SYSCON_PDRUNCFGCLR_PDEN_VDDA(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VDDA_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VDDA_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_WDT_OSC_MASK     (0x100000U)
#define SYSCON_PDRUNCFGCLR_PDEN_WDT_OSC_SHIFT    (20U)
/*! PDEN_WDT_OSC - Watchdog oscillator. */
#define SYSCON_PDRUNCFGCLR_PDEN_WDT_OSC(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_WDT_OSC_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_WDT_OSC_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_USB0_PHY_MASK    (0x200000U)
#define SYSCON_PDRUNCFGCLR_PDEN_USB0_PHY_SHIFT   (21U)
/*! PDEN_USB0_PHY - USB0 PHY power (also enable/disable bit 28). */
#define SYSCON_PDRUNCFGCLR_PDEN_USB0_PHY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_USB0_PHY_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_USB0_PHY_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_SYS_PLL_MASK     (0x400000U)
#define SYSCON_PDRUNCFGCLR_PDEN_SYS_PLL_SHIFT    (22U)
/*! PDEN_SYS_PLL - System PLL (PLL0) power (also enable/disable bit 26). */
#define SYSCON_PDRUNCFGCLR_PDEN_SYS_PLL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_SYS_PLL_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_SYS_PLL_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VREFP_MASK       (0x800000U)
#define SYSCON_PDRUNCFGCLR_PDEN_VREFP_SHIFT      (23U)
/*! PDEN_VREFP - VREFP to the ADC must be enabled for the ADC to work (also enable/disable bit 9, 10, and 19). */
#define SYSCON_PDRUNCFGCLR_PDEN_VREFP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VREFP_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VREFP_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VD3_MASK         (0x4000000U)
#define SYSCON_PDRUNCFGCLR_PDEN_VD3_SHIFT        (26U)
/*! PDEN_VD3 - Power control for all PLLs. */
#define SYSCON_PDRUNCFGCLR_PDEN_VD3(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VD3_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VD3_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VD4_MASK         (0x8000000U)
#define SYSCON_PDRUNCFGCLR_PDEN_VD4_SHIFT        (27U)
/*! PDEN_VD4 - Power control for all SRAMs and ROM. */
#define SYSCON_PDRUNCFGCLR_PDEN_VD4(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VD4_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VD4_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VD5_MASK         (0x10000000U)
#define SYSCON_PDRUNCFGCLR_PDEN_VD5_SHIFT        (28U)
/*! PDEN_VD5 - Power control both USB0 PHY and USB1 PHY. */
#define SYSCON_PDRUNCFGCLR_PDEN_VD5(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VD5_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VD5_MASK)

#define SYSCON_PDRUNCFGCLR_PDEN_VD6_MASK         (0x20000000U)
#define SYSCON_PDRUNCFGCLR_PDEN_VD6_SHIFT        (29U)
/*! PDEN_VD6 - Power control for EEPROM. */
#define SYSCON_PDRUNCFGCLR_PDEN_VD6(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PDRUNCFGCLR_PDEN_VD6_SHIFT)) & SYSCON_PDRUNCFGCLR_PDEN_VD6_MASK)
/*! @} */

/*! @name STARTER - Start logic 0 wake-up enable register */
/*! @{ */

#define SYSCON_STARTER_PINT4_MASK                (0x1U)
#define SYSCON_STARTER_PINT4_SHIFT               (0U)
/*! PINT4 - GPIO pin interrupt 4 wake-up. */
#define SYSCON_STARTER_PINT4(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT4_SHIFT)) & SYSCON_STARTER_PINT4_MASK)

#define SYSCON_STARTER_WDT_BOD_MASK              (0x1U)
#define SYSCON_STARTER_WDT_BOD_SHIFT             (0U)
/*! WDT_BOD - WWDT and BOD interrupt wake-up. */
#define SYSCON_STARTER_WDT_BOD(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_WDT_BOD_SHIFT)) & SYSCON_STARTER_WDT_BOD_MASK)

#define SYSCON_STARTER_DMA_MASK                  (0x2U)
#define SYSCON_STARTER_DMA_SHIFT                 (1U)
/*! DMA - DMA wake-up. */
#define SYSCON_STARTER_DMA(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DMA_SHIFT)) & SYSCON_STARTER_DMA_MASK)

#define SYSCON_STARTER_PINT5_MASK                (0x2U)
#define SYSCON_STARTER_PINT5_SHIFT               (1U)
/*! PINT5 - GPIO pin interrupt 5 wake-up. */
#define SYSCON_STARTER_PINT5(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT5_SHIFT)) & SYSCON_STARTER_PINT5_MASK)

#define SYSCON_STARTER_GINT0_MASK                (0x4U)
#define SYSCON_STARTER_GINT0_SHIFT               (2U)
/*! GINT0 - Group interrupt 0 wake-up. */
#define SYSCON_STARTER_GINT0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT0_SHIFT)) & SYSCON_STARTER_GINT0_MASK)

#define SYSCON_STARTER_PINT6_MASK                (0x4U)
#define SYSCON_STARTER_PINT6_SHIFT               (2U)
/*! PINT6 - GPIO pin interrupt 6 wake-up. */
#define SYSCON_STARTER_PINT6(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT6_SHIFT)) & SYSCON_STARTER_PINT6_MASK)

#define SYSCON_STARTER_GINT1_MASK                (0x8U)
#define SYSCON_STARTER_GINT1_SHIFT               (3U)
/*! GINT1 - Group interrupt 1 wake-up. */
#define SYSCON_STARTER_GINT1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT1_SHIFT)) & SYSCON_STARTER_GINT1_MASK)

#define SYSCON_STARTER_PINT7_MASK                (0x8U)
#define SYSCON_STARTER_PINT7_SHIFT               (3U)
/*! PINT7 - GPIO pin interrupt 7 wake-up. */
#define SYSCON_STARTER_PINT7(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PINT7_SHIFT)) & SYSCON_STARTER_PINT7_MASK)

#define SYSCON_STARTER_CTIMER2_MASK              (0x10U)
#define SYSCON_STARTER_CTIMER2_SHIFT             (4U)
/*! CTIMER2 - Standard counter/timer CTIMER2 wake-up. */
#define SYSCON_STARTER_CTIMER2(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER2_SHIFT)) & SYSCON_STARTER_CTIMER2_MASK)

#define SYSCON_STARTER_PIN_INT0_MASK             (0x10U)
#define SYSCON_STARTER_PIN_INT0_SHIFT            (4U)
/*! PIN_INT0 - GPIO pin interrupt 0 wake-up. */
#define SYSCON_STARTER_PIN_INT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT0_SHIFT)) & SYSCON_STARTER_PIN_INT0_MASK)

#define SYSCON_STARTER_CTIMER4_MASK              (0x20U)
#define SYSCON_STARTER_CTIMER4_SHIFT             (5U)
/*! CTIMER4 - Standard counter/timer CTIMER4 wake-up. */
#define SYSCON_STARTER_CTIMER4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER4_SHIFT)) & SYSCON_STARTER_CTIMER4_MASK)

#define SYSCON_STARTER_PIN_INT1_MASK             (0x20U)
#define SYSCON_STARTER_PIN_INT1_SHIFT            (5U)
/*! PIN_INT1 - GPIO pin interrupt 1 wake-up. */
#define SYSCON_STARTER_PIN_INT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT1_SHIFT)) & SYSCON_STARTER_PIN_INT1_MASK)

#define SYSCON_STARTER_PIN_INT2_MASK             (0x40U)
#define SYSCON_STARTER_PIN_INT2_SHIFT            (6U)
/*! PIN_INT2 - GPIO pin interrupt 2 wake-up. */
#define SYSCON_STARTER_PIN_INT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT2_SHIFT)) & SYSCON_STARTER_PIN_INT2_MASK)

#define SYSCON_STARTER_PIN_INT3_MASK             (0x80U)
#define SYSCON_STARTER_PIN_INT3_SHIFT            (7U)
/*! PIN_INT3 - GPIO pin interrupt 3 wake-up. */
#define SYSCON_STARTER_PIN_INT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIN_INT3_SHIFT)) & SYSCON_STARTER_PIN_INT3_MASK)

#define SYSCON_STARTER_SPIFI_MASK                (0x80U)
#define SYSCON_STARTER_SPIFI_SHIFT               (7U)
/*! SPIFI - SPIFI interrupt wake-up. 0 = Wake-up disabled. 1 = Wake-up enabled. */
#define SYSCON_STARTER_SPIFI(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SPIFI_SHIFT)) & SYSCON_STARTER_SPIFI_MASK)

#define SYSCON_STARTER_FLEXCOMM8_MASK            (0x100U)
#define SYSCON_STARTER_FLEXCOMM8_SHIFT           (8U)
/*! FLEXCOMM8 - Flexcomm Interface 8 wake-up. */
#define SYSCON_STARTER_FLEXCOMM8(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM8_SHIFT)) & SYSCON_STARTER_FLEXCOMM8_MASK)

#define SYSCON_STARTER_UTICK_MASK                (0x100U)
#define SYSCON_STARTER_UTICK_SHIFT               (8U)
/*! UTICK - Micro-tick Timer wake-up. */
#define SYSCON_STARTER_UTICK(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_UTICK_SHIFT)) & SYSCON_STARTER_UTICK_MASK)

#define SYSCON_STARTER_FLEXCOMM9_MASK            (0x200U)
#define SYSCON_STARTER_FLEXCOMM9_SHIFT           (9U)
/*! FLEXCOMM9 - Flexcomm Interface 9 wake-up. */
#define SYSCON_STARTER_FLEXCOMM9(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM9_SHIFT)) & SYSCON_STARTER_FLEXCOMM9_MASK)

#define SYSCON_STARTER_MRT_MASK                  (0x200U)
#define SYSCON_STARTER_MRT_SHIFT                 (9U)
/*! MRT - Multi-Rate Timer wake-up. */
#define SYSCON_STARTER_MRT(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_MRT_SHIFT)) & SYSCON_STARTER_MRT_MASK)

#define SYSCON_STARTER_CTIMER0_MASK              (0x400U)
#define SYSCON_STARTER_CTIMER0_SHIFT             (10U)
/*! CTIMER0 - Standard counter/timer CTIMER0 wake-up. */
#define SYSCON_STARTER_CTIMER0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER0_SHIFT)) & SYSCON_STARTER_CTIMER0_MASK)

#define SYSCON_STARTER_CTIMER1_MASK              (0x800U)
#define SYSCON_STARTER_CTIMER1_SHIFT             (11U)
/*! CTIMER1 - Standard counter/timer CTIMER1 wake-up. */
#define SYSCON_STARTER_CTIMER1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER1_SHIFT)) & SYSCON_STARTER_CTIMER1_MASK)

#define SYSCON_STARTER_SCT0_MASK                 (0x1000U)
#define SYSCON_STARTER_SCT0_SHIFT                (12U)
/*! SCT0 - SCT0 wake-up. */
#define SYSCON_STARTER_SCT0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SCT0_SHIFT)) & SYSCON_STARTER_SCT0_MASK)

#define SYSCON_STARTER_CTIMER3_MASK              (0x2000U)
#define SYSCON_STARTER_CTIMER3_SHIFT             (13U)
/*! CTIMER3 - Standard counter/timer CTIMER3 wake-up. */
#define SYSCON_STARTER_CTIMER3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER3_SHIFT)) & SYSCON_STARTER_CTIMER3_MASK)

#define SYSCON_STARTER_FLEXCOMM0_MASK            (0x4000U)
#define SYSCON_STARTER_FLEXCOMM0_SHIFT           (14U)
/*! FLEXCOMM0 - Flexcomm0 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM0_SHIFT)) & SYSCON_STARTER_FLEXCOMM0_MASK)

#define SYSCON_STARTER_FLEXCOMM1_MASK            (0x8000U)
#define SYSCON_STARTER_FLEXCOMM1_SHIFT           (15U)
/*! FLEXCOMM1 - Flexcomm1 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM1_SHIFT)) & SYSCON_STARTER_FLEXCOMM1_MASK)

#define SYSCON_STARTER_USB1_MASK                 (0x8000U)
#define SYSCON_STARTER_USB1_SHIFT                (15U)
/*! USB1 - USB 1 wake-up. */
#define SYSCON_STARTER_USB1(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB1_SHIFT)) & SYSCON_STARTER_USB1_MASK)

#define SYSCON_STARTER_FLEXCOMM2_MASK            (0x10000U)
#define SYSCON_STARTER_FLEXCOMM2_SHIFT           (16U)
/*! FLEXCOMM2 - Flexcomm2 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM2_SHIFT)) & SYSCON_STARTER_FLEXCOMM2_MASK)

#define SYSCON_STARTER_USB1_ACT_MASK             (0x10000U)
#define SYSCON_STARTER_USB1_ACT_SHIFT            (16U)
/*! USB1_ACT - USB 1 activity wake-up. */
#define SYSCON_STARTER_USB1_ACT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB1_ACT_SHIFT)) & SYSCON_STARTER_USB1_ACT_MASK)

#define SYSCON_STARTER_ENET_INT1_MASK            (0x20000U)
#define SYSCON_STARTER_ENET_INT1_SHIFT           (17U)
/*! ENET_INT1 - Ethernet. */
#define SYSCON_STARTER_ENET_INT1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENET_INT1_SHIFT)) & SYSCON_STARTER_ENET_INT1_MASK)

#define SYSCON_STARTER_FLEXCOMM3_MASK            (0x20000U)
#define SYSCON_STARTER_FLEXCOMM3_SHIFT           (17U)
/*! FLEXCOMM3 - Flexcomm3 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM3_SHIFT)) & SYSCON_STARTER_FLEXCOMM3_MASK)

#define SYSCON_STARTER_ENET_INT2_MASK            (0x40000U)
#define SYSCON_STARTER_ENET_INT2_SHIFT           (18U)
/*! ENET_INT2 - Ethernet. */
#define SYSCON_STARTER_ENET_INT2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENET_INT2_SHIFT)) & SYSCON_STARTER_ENET_INT2_MASK)

#define SYSCON_STARTER_FLEXCOMM4_MASK            (0x40000U)
#define SYSCON_STARTER_FLEXCOMM4_SHIFT           (18U)
/*! FLEXCOMM4 - Flexcomm4 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM4(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM4_SHIFT)) & SYSCON_STARTER_FLEXCOMM4_MASK)

#define SYSCON_STARTER_ENET_INT0_MASK            (0x80000U)
#define SYSCON_STARTER_ENET_INT0_SHIFT           (19U)
/*! ENET_INT0 - Ethernet. */
#define SYSCON_STARTER_ENET_INT0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENET_INT0_SHIFT)) & SYSCON_STARTER_ENET_INT0_MASK)

#define SYSCON_STARTER_FLEXCOMM5_MASK            (0x80000U)
#define SYSCON_STARTER_FLEXCOMM5_SHIFT           (19U)
/*! FLEXCOMM5 - Flexcomm5 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM5(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM5_SHIFT)) & SYSCON_STARTER_FLEXCOMM5_MASK)

#define SYSCON_STARTER_FLEXCOMM6_MASK            (0x100000U)
#define SYSCON_STARTER_FLEXCOMM6_SHIFT           (20U)
/*! FLEXCOMM6 - Flexcomm6 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM6(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM6_SHIFT)) & SYSCON_STARTER_FLEXCOMM6_MASK)

#define SYSCON_STARTER_FLEXCOMM7_MASK            (0x200000U)
#define SYSCON_STARTER_FLEXCOMM7_SHIFT           (21U)
/*! FLEXCOMM7 - Flexcomm7 peripheral interrupt wake-up. */
#define SYSCON_STARTER_FLEXCOMM7(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXCOMM7_SHIFT)) & SYSCON_STARTER_FLEXCOMM7_MASK)

#define SYSCON_STARTER_ADC0_SEQA_MASK            (0x400000U)
#define SYSCON_STARTER_ADC0_SEQA_SHIFT           (22U)
/*! ADC0_SEQA - ADC0 sequence A interrupt wake-up. */
#define SYSCON_STARTER_ADC0_SEQA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_SEQA_SHIFT)) & SYSCON_STARTER_ADC0_SEQA_MASK)

#define SYSCON_STARTER_ADC0_SEQB_MASK            (0x800000U)
#define SYSCON_STARTER_ADC0_SEQB_SHIFT           (23U)
/*! ADC0_SEQB - ADC0 sequence B interrupt wake-up. */
#define SYSCON_STARTER_ADC0_SEQB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_SEQB_SHIFT)) & SYSCON_STARTER_ADC0_SEQB_MASK)

#define SYSCON_STARTER_SMARTCARD0_MASK           (0x800000U)
#define SYSCON_STARTER_SMARTCARD0_SHIFT          (23U)
/*! SMARTCARD0 - Smart card 0 wake-up. */
#define SYSCON_STARTER_SMARTCARD0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SMARTCARD0_SHIFT)) & SYSCON_STARTER_SMARTCARD0_MASK)

#define SYSCON_STARTER_ADC0_THCMP_MASK           (0x1000000U)
#define SYSCON_STARTER_ADC0_THCMP_SHIFT          (24U)
/*! ADC0_THCMP - ADC0 threshold and error interrupt wake-up. */
#define SYSCON_STARTER_ADC0_THCMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_THCMP_SHIFT)) & SYSCON_STARTER_ADC0_THCMP_MASK)

#define SYSCON_STARTER_SMARTCARD1_MASK           (0x1000000U)
#define SYSCON_STARTER_SMARTCARD1_SHIFT          (24U)
/*! SMARTCARD1 - Smart card 1 wake-up. */
#define SYSCON_STARTER_SMARTCARD1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SMARTCARD1_SHIFT)) & SYSCON_STARTER_SMARTCARD1_MASK)

#define SYSCON_STARTER_DMIC_MASK                 (0x2000000U)
#define SYSCON_STARTER_DMIC_SHIFT                (25U)
/*! DMIC - Digital microphone interrupt wake-up. */
#define SYSCON_STARTER_DMIC(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DMIC_SHIFT)) & SYSCON_STARTER_DMIC_MASK)

#define SYSCON_STARTER_HWVAD_MASK                (0x4000000U)
#define SYSCON_STARTER_HWVAD_SHIFT               (26U)
/*! HWVAD - Hardware voice activity detect interrupt wake-up. */
#define SYSCON_STARTER_HWVAD(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_HWVAD_SHIFT)) & SYSCON_STARTER_HWVAD_MASK)

#define SYSCON_STARTER_USB0_NEEDCLK_MASK         (0x8000000U)
#define SYSCON_STARTER_USB0_NEEDCLK_SHIFT        (27U)
/*! USB0_NEEDCLK - USB activity interrupt wake-up. */
#define SYSCON_STARTER_USB0_NEEDCLK(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB0_NEEDCLK_SHIFT)) & SYSCON_STARTER_USB0_NEEDCLK_MASK)

#define SYSCON_STARTER_USB0_MASK                 (0x10000000U)
#define SYSCON_STARTER_USB0_SHIFT                (28U)
/*! USB0 - USB function interrupt wake-up. */
#define SYSCON_STARTER_USB0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB0_SHIFT)) & SYSCON_STARTER_USB0_MASK)

#define SYSCON_STARTER_RTC_MASK                  (0x20000000U)
#define SYSCON_STARTER_RTC_SHIFT                 (29U)
/*! RTC - RTC interrupt alarm and wake-up timer. */
#define SYSCON_STARTER_RTC(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_RTC_SHIFT)) & SYSCON_STARTER_RTC_MASK)
/*! @} */

/*! @name STARTERSET - Set bits in STARTER */
/*! @{ */

#define SYSCON_STARTERSET_START_SET_MASK         (0xFFFFFFFFU)
#define SYSCON_STARTERSET_START_SET_SHIFT        (0U)
/*! START_SET - Writing ones to this register sets the corresponding bit or bits in the STARTER0 register, if they are implemented. */
#define SYSCON_STARTERSET_START_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_START_SET_SHIFT)) & SYSCON_STARTERSET_START_SET_MASK)
/*! @} */

/*! @name STARTERCLR - Clear bits in STARTER0 */
/*! @{ */

#define SYSCON_STARTERCLR_START_CLR_MASK         (0xFFFFFFFFU)
#define SYSCON_STARTERCLR_START_CLR_SHIFT        (0U)
/*! START_CLR - Writing ones to this register clears the corresponding bit or bits in the STARTER0 register, if they are implemented. */
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

#define SYSCON_HWWAKE_WAKEDMIC_MASK              (0x4U)
#define SYSCON_HWWAKE_WAKEDMIC_SHIFT             (2U)
/*! WAKEDMIC - Wake for Digital Microphone. When 1, the digital microphone input FIFO reaching the
 *    level specified by TRIGLVL of either channel will cause peripheral clocking to wake up
 *    temporarily while the related status is asserted.
 */
#define SYSCON_HWWAKE_WAKEDMIC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_HWWAKE_WAKEDMIC_SHIFT)) & SYSCON_HWWAKE_WAKEDMIC_MASK)

#define SYSCON_HWWAKE_WAKEDMA_MASK               (0x8U)
#define SYSCON_HWWAKE_WAKEDMA_SHIFT              (3U)
/*! WAKEDMA - Wake for DMA. When 1, DMA being busy will cause peripheral clocking to remain running
 *    until DMA completes. This is generally used in conjunction with bit 1 and/or 2 in order to
 *    prevent peripheral clocking from being shut down as soon as the cause of wake-up is cleared, but
 *    before DMA has completed its related activity.
 */
#define SYSCON_HWWAKE_WAKEDMA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_HWWAKE_WAKEDMA_SHIFT)) & SYSCON_HWWAKE_WAKEDMA_MASK)
/*! @} */

/*! @name AUTOCGOR - Auto Clock-Gate Override Register */
/*! @{ */

#define SYSCON_AUTOCGOR_RAM0X_MASK               (0x2U)
#define SYSCON_AUTOCGOR_RAM0X_SHIFT              (1U)
/*! RAM0X - When 1, automatic clock gating for RAMX and RAM0 are turned off. */
#define SYSCON_AUTOCGOR_RAM0X(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCGOR_RAM0X_SHIFT)) & SYSCON_AUTOCGOR_RAM0X_MASK)

#define SYSCON_AUTOCGOR_RAM1_MASK                (0x4U)
#define SYSCON_AUTOCGOR_RAM1_SHIFT               (2U)
/*! RAM1 - When 1, automatic clock gating for RAM1 are turned off. */
#define SYSCON_AUTOCGOR_RAM1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCGOR_RAM1_SHIFT)) & SYSCON_AUTOCGOR_RAM1_MASK)

#define SYSCON_AUTOCGOR_RAM2_MASK                (0x8U)
#define SYSCON_AUTOCGOR_RAM2_SHIFT               (3U)
/*! RAM2 - When 1, automatic clock gating for RAM1 are turned off. */
#define SYSCON_AUTOCGOR_RAM2(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCGOR_RAM2_SHIFT)) & SYSCON_AUTOCGOR_RAM2_MASK)

#define SYSCON_AUTOCGOR_RAM3_MASK                (0x10U)
#define SYSCON_AUTOCGOR_RAM3_SHIFT               (4U)
/*! RAM3 - When 1, automatic clock gating for RAM1 are turned off. */
#define SYSCON_AUTOCGOR_RAM3(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCGOR_RAM3_SHIFT)) & SYSCON_AUTOCGOR_RAM3_MASK)
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

