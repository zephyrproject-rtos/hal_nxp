/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
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
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
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

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
#define SYSCON_PRESETCTRLSET_COUNT                4u
#define SYSCON_PRESETCTRLCLR_COUNT                4u
#define SYSCON_AHBCLKCTRLSET_COUNT                4u
#define SYSCON_AHBCLKCTRLCLR_COUNT                4u
#define SYSCON_CTIMERCLKSEL_COUNT                 5u
#define SYSCON_FCCLKSEL_COUNT                     8u
#define SYSCON_SYSTICKCLKDIV_COUNT                1u
#define SYSCON_FRGCTRL_COUNT                      8u
#define SYSCON_CTIMERXCLKDIV_COUNT                5u
#define SYSCON_DAC_COUNT                          3u
#define SYSCON_STARTER_COUNT                      4u
#define SYSCON_STARTERSET_COUNT                   4u
#define SYSCON_STARTERCLR_COUNT                   2u
#define SYSCON_FRGCLKSEL_COUNT                    8u
#define SYSCON_FLEXCOMMXCLKDIV_COUNT              8u
#define SYSCON_SWD_ACCESS_CPU_COUNT               1u

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t MEMORYREMAP;                       /**< Memory Remap Control, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix priority control, offset: 0x10 */
  __IO uint32_t AHBMATPRIO1;                       /**< AHB Matrix priority control, offset: 0x14 */
       uint8_t RESERVED_1[32];
  __IO uint32_t CPU0STCKCAL;                       /**< System tick calibration for secure part of CPU0, offset: 0x38 */
  __IO uint32_t CPU0NSTCKCAL;                      /**< System tick calibration for non-secure part of CPU0, offset: 0x3C */
       uint8_t RESERVED_2[8];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
       uint8_t RESERVED_3[180];
  __IO uint32_t PRESETCTRL0;                       /**< Peripheral reset control 0, offset: 0x100 */
  __IO uint32_t PRESETCTRL1;                       /**< Peripheral reset control 1, offset: 0x104 */
  __IO uint32_t PRESETCTRL2;                       /**< Peripheral reset control 2, offset: 0x108 */
  __IO uint32_t PRESETCTRL3;                       /**< Peripheral reset control 3, offset: 0x10C */
       uint8_t RESERVED_4[16];
  __O  uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Peripheral reset control set n, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __O  uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Peripheral reset control clear n, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_6[16];
  __O  uint32_t SWR_RESET;                         /**< Software Reset, offset: 0x160 */
       uint8_t RESERVED_7[156];
  __IO uint32_t AHBCLKCTRL0;                       /**< AHB Clock control 0, offset: 0x200 */
  __IO uint32_t AHBCLKCTRL1;                       /**< AHB Clock control 1, offset: 0x204 */
  __IO uint32_t AHBCLKCTRL2;                       /**< AHB Clock control 2, offset: 0x208 */
  __IO uint32_t AHBCLKCTRL3;                       /**< AHB Clock Control 3, offset: 0x20C */
       uint8_t RESERVED_8[16];
  __IO uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< AHB Clock Control Set, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< AHB Clock Control Clear, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_10[16];
  __IO uint32_t SYSTICKCLKSEL0;                    /**< System Tick Timer for CPU0 source select, offset: 0x260 */
       uint8_t RESERVED_11[4];
  __IO uint32_t TRACECLKSEL;                       /**< Trace clock source select, offset: 0x268 */
  __IO uint32_t CTIMERCLKSEL[SYSCON_CTIMERCLKSEL_COUNT]; /**< CTimer 0 clock source select..CTimer 4 clock source select, array offset: 0x26C, array step: 0x4 */
  __IO uint32_t MAINCLKSELA;                       /**< Main clock source select A, offset: 0x280 */
  __IO uint32_t MAINCLKSELB;                       /**< Main clock source select B, offset: 0x284 */
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT clock source select, offset: 0x288 */
       uint8_t RESERVED_12[4];
  __IO uint32_t PLL0CLKSEL;                        /**< PLL0 clock source select, offset: 0x290 */
  __IO uint32_t PLL1CLKSEL;                        /**< PLL1 clock source select, offset: 0x294 */
       uint8_t RESERVED_13[8];
  __IO uint32_t CANCLKSEL;                         /**< CAN clock source select, offset: 0x2A0 */
  __IO uint32_t ADC0CLKSEL;                        /**< ADC0 clock source select, offset: 0x2A4 */
  __IO uint32_t USB0CLKSEL;                        /**< FS USB clock source select, offset: 0x2A8 */
       uint8_t RESERVED_14[4];
  __IO uint32_t FCCLKSEL[SYSCON_FCCLKSEL_COUNT];   /**< Flexcomm 0 clock source select for Fractional Rate Divider..Flexcomm 7 clock source select for Fractional Rate Divider, array offset: 0x2B0, array step: 0x4 */
  __IO uint32_t HSSPICLKSEL;                       /**< HS SPI clock source select, offset: 0x2D0 */
       uint8_t RESERVED_15[12];
  __IO uint32_t MCLKCLKSEL;                        /**< MCLK clock source select, offset: 0x2E0 */
       uint8_t RESERVED_16[12];
  __IO uint32_t SCTCLKSEL;                         /**< SCTimer/PWM clock source select, offset: 0x2F0 */
       uint8_t RESERVED_17[12];
  __IO uint32_t SYSTICKCLKDIV[SYSCON_SYSTICKCLKDIV_COUNT]; /**< System Tick Timer divider for CPU0, array offset: 0x300, array step: 0x4 */
       uint8_t RESERVED_18[4];
  __IO uint32_t TRACECLKDIV;                       /**< TRACE clock divider, offset: 0x308 */
  __IO uint32_t CANCLKDIV;                         /**< CAN clock divider, offset: 0x30C */
       uint8_t RESERVED_19[16];
  __IO uint32_t FRGCTRL[SYSCON_FRGCTRL_COUNT];     /**< Fractional rate divider for flexcomm 0..Fractional rate divider for flexcomm 7, array offset: 0x320, array step: 0x4 */
       uint8_t RESERVED_20[64];
  __IO uint32_t AHBCLKDIV;                         /**< System clock divider, offset: 0x380 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider, offset: 0x384 */
  __IO uint32_t FROHFDIV;                          /**< FRO_HF (96MHz) clock divider, offset: 0x388 */
  __IO uint32_t WDTCLKDIV;                         /**< WDT clock divider, offset: 0x38C */
       uint8_t RESERVED_21[4];
  __IO uint32_t ADC0CLKDIV;                        /**< ADC0 clock divider, offset: 0x394 */
  __IO uint32_t USB0CLKDIV;                        /**< USB0-FS Clock divider, offset: 0x398 */
       uint8_t RESERVED_22[16];
  __IO uint32_t MCLKDIV;                           /**< I2S MCLK clock divider, offset: 0x3AC */
       uint8_t RESERVED_23[4];
  __IO uint32_t SCTCLKDIV;                         /**< SCT/PWM clock divider, offset: 0x3B4 */
       uint8_t RESERVED_24[12];
  __IO uint32_t PLLCLKDIV;                         /**< PLL clock divider, offset: 0x3C4 */
       uint8_t RESERVED_25[8];
  __IO uint32_t CTIMERCLKDIV[SYSCON_CTIMERXCLKDIV_COUNT]; /**< CTimer 0 clock divider..CTimer 4 clock divider, array offset: 0x3D0, array step: 0x4 */
       uint8_t RESERVED_26[24];
  __IO uint32_t CLKUNLOCK;                         /**< Clock configuration unlock, offset: 0x3FC */
  __IO uint32_t FMCCR;                             /**< FMC configuration, offset: 0x400 */
  __IO uint32_t ROMCR;                             /**< ROM wait state, offset: 0x404 */
       uint8_t RESERVED_27[4];
  __IO uint32_t USB0NEEDCLKCTRL;                   /**< USB0-FS need clock control, offset: 0x40C */
  __I  uint32_t USB0NEEDCLKSTAT;                   /**< USB0-FS need clock status, offset: 0x410 */
       uint8_t RESERVED_28[8];
  __O  uint32_t FMCFLUSH;                          /**< FMC flush control, offset: 0x41C */
  __IO uint32_t MCLKIO;                            /**< MCLK control, offset: 0x420 */
       uint8_t RESERVED_29[64];
  __IO uint32_t ADC1CLKSEL;                        /**< ADC1 clock source select, offset: 0x464 */
  __IO uint32_t ADC1CLKDIV;                        /**< ADC1 clock divider, offset: 0x468 */
       uint8_t RESERVED_30[4];
  __IO uint32_t RAM_INTERLEAVE;                    /**< Control RAM interleave integration, offset: 0x470 */
       uint8_t RESERVED_31[28];
  struct {                                         /* offset: 0x490, array step: 0x8 */
    __IO uint32_t CLKSEL;                            /**< DAC0 functional clock selection..DAC2 functional clock selection, array offset: 0x490, array step: 0x8 */
    __IO uint32_t CLKDIV;                            /**< DAC0 functional clock divider..DAC2 functional clock divider, array offset: 0x494, array step: 0x8 */
  } DAC[SYSCON_DAC_COUNT];
  __IO uint32_t FLEXSPICLKSEL;                     /**< FLEXSPI clock selection, offset: 0x4A8 */
  __IO uint32_t FLEXSPICLKDIV;                     /**< FLEXSPI clock divider, offset: 0x4AC */
  __IO uint32_t CDPA_ENABLE;                       /**< Enable protection, offset: 0x4B0 */
  __IO uint32_t CDPA_ENABLE_DP;                    /**< Enable protection duplicate, offset: 0x4B4 */
  __IO uint32_t CDPA_CONFIG;                       /**< CDPA base address, offset: 0x4B8 */
       uint8_t RESERVED_32[20];
  __IO uint32_t FLASH_HIDING_LOCKOUT_ADDR;         /**< Flash hiding lockout address, offset: 0x4D0 */
  __IO uint32_t FLASH_HIDING_BASE_ADDR;            /**< Flash hiding base address, offset: 0x4D4 */
  __IO uint32_t FLASH_HIDING_BASE_DP_ADDR;         /**< Flash hiding base DP address, offset: 0x4D8 */
  __IO uint32_t FLASH_HIDING_SIZE_ADDR;            /**< Hiding size address, offset: 0x4DC */
  __IO uint32_t FLASH_HIDING_SIZE_DP_ADDR;         /**< Hiding size DP address, offset: 0x4E0 */
       uint8_t RESERVED_33[72];
  __IO uint32_t PLLCLKDIVSEL;                      /**< PLL clock divider clock selection, offset: 0x52C */
  __IO uint32_t I3CFCLKSEL;                        /**< I3C functional clock selection, offset: 0x530 */
  __IO uint32_t I3CFCLKSTCSEL;                     /**< I3C FCLK_STC clock selection, offset: 0x534 */
  __IO uint32_t I3CFCLKSTCDIV;                     /**< I3C FCLK_STC clock divider, offset: 0x538 */
  __IO uint32_t I3CFCLKSDIV;                       /**< I3C FCLKS clock divider, offset: 0x53C */
  __IO uint32_t I3CFCLKDIV;                        /**< I3C FCLK divider, offset: 0x540 */
  __IO uint32_t I3CFCLKSSEL;                       /**< I3C FCLK_S selection, offset: 0x544 */
  __IO uint32_t DMICFCLKSEL;                       /**< DMIC clock selection, offset: 0x548 */
  __IO uint32_t DMICFCLKDIV;                       /**< DMIC clock division, offset: 0x54C */
       uint8_t RESERVED_34[16];
  __IO uint32_t PLL1CTRL;                          /**< PLL1 550m control, offset: 0x560 */
  __I  uint32_t PLL1STAT;                          /**< PLL1 550m status, offset: 0x564 */
  __IO uint32_t PLL1NDEC;                          /**< PLL1 550m N divider, offset: 0x568 */
  __IO uint32_t PLL1MDEC;                          /**< PLL1 550m M divider, offset: 0x56C */
  __IO uint32_t PLL1PDEC;                          /**< PLL1 550m P divider, offset: 0x570 */
       uint8_t RESERVED_35[12];
  __IO uint32_t PLL0CTRL;                          /**< PLL0 550m control, offset: 0x580 */
  __I  uint32_t PLL0STAT;                          /**< PLL0 550m status, offset: 0x584 */
  __IO uint32_t PLL0NDEC;                          /**< PLL0 550m N divider, offset: 0x588 */
  __IO uint32_t PLL0PDEC;                          /**< PLL0 550m P divider, offset: 0x58C */
  __IO uint32_t PLL0SSCG0;                         /**< PLL0 Spread Spectrum control 0, offset: 0x590 */
  __IO uint32_t PLL0SSCG1;                         /**< PLL0 Spread Spectrum control 1, offset: 0x594 */
       uint8_t RESERVED_36[56];
  __IO uint32_t DAC_ISO_CTRL;                      /**< DAC Isolation Control, offset: 0x5D0 */
       uint8_t RESERVED_37[172];
  __IO uint32_t STARTER[SYSCON_STARTER_COUNT];     /**< Start logic wake-up enable, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_38[16];
  __IO uint32_t STARTERSET[SYSCON_STARTERSET_COUNT]; /**< Set bits in STARTER, array offset: 0x6A0, array step: 0x4 */
       uint8_t RESERVED_39[16];
  __O  uint32_t STARTERCLR[SYSCON_STARTERCLR_COUNT]; /**< Clear bits in STARTER, array offset: 0x6C0, array step: 0x4 */
       uint8_t RESERVED_40[60];
  __IO uint32_t FUNCRETENTIONCTRL;                 /**< Functional retention control, offset: 0x704 */
       uint8_t RESERVED_41[120];
  __IO uint32_t HARDWARESLEEP;                     /**< Hardware Sleep control, offset: 0x780 */
       uint8_t RESERVED_42[136];
  __I  uint32_t CPUSTAT;                           /**< CPU Status, offset: 0x80C */
       uint8_t RESERVED_43[20];
  __IO uint32_t LPCAC_CTRL;                        /**< LPCAC control, offset: 0x824 */
       uint8_t RESERVED_44[4];
  __IO uint32_t FC32KCLKSEL;                       /**< Flexcomm 32K clock select, offset: 0x82C */
  __IO uint32_t FRGCLKSEL[SYSCON_FRGCLKSEL_COUNT]; /**< FRG Clock Source Select, array offset: 0x830, array step: 0x4 */
  __IO uint32_t FLEXCOMMCLKDIV[SYSCON_FLEXCOMMXCLKDIV_COUNT]; /**< Flexcomm clock divider, array offset: 0x850, array step: 0x4 */
       uint8_t RESERVED_45[280];
  __IO uint32_t ELS_TEMPORAL_STATE;                /**< ELS temporal state, offset: 0x988 */
  __IO uint32_t ELS_KDF_MASK;                      /**< Key derivation function mask, offset: 0x98C */
  __IO uint32_t ELS_FEATURE0;                      /**< ELS command feature, offset: 0x990 */
  __IO uint32_t ELS_FEATURE1;                      /**< ELS command feature, offset: 0x994 */
  __IO uint32_t ELS_FEATURE0_DP;                   /**< ELS command feature - duplicate version, offset: 0x998 */
  __IO uint32_t ELS_FEATURE1_DP;                   /**< ELS command feature - duplicate version, offset: 0x99C */
       uint8_t RESERVED_46[4];
  __IO uint32_t ELS_BOOT_RETRY_CNT;                /**< ELS boot retry counter, offset: 0x9A4 */
       uint8_t RESERVED_47[8];
  __IO uint32_t ELS_CLK_CTRL;                      /**< ELS clock control, offset: 0x9B0 */
  __O  uint32_t ELS_CLK_CTRL_SET;                  /**< ELS clock control set, offset: 0x9B4 */
  __O  uint32_t ELS_CLK_CTRL_CLR;                  /**< ELS clock control clear, offset: 0x9B8 */
  __IO uint32_t ELS_CLK_SEL;                       /**< ELS clock select, offset: 0x9BC */
       uint8_t RESERVED_48[16];
  __I  uint32_t ELS_AS_CFG0;                       /**< ELS AS configuration, offset: 0x9D0 */
  __I  uint32_t ELS_AS_CFG1;                       /**< ELS AS configuration1, offset: 0x9D4 */
  __I  uint32_t ELS_AS_CFG2;                       /**< ELS AS configuration2, offset: 0x9D8 */
       uint8_t RESERVED_49[4];
  __I  uint32_t ELS_AS_ST0;                        /**< ELS AS state register, offset: 0x9E0 */
  __I  uint32_t ELS_AS_ST1;                        /**< ELS AS state1, offset: 0x9E4 */
  __I  uint32_t ELS_AS_ST2;                        /**< ELS AS state2, offset: 0x9E8 */
       uint8_t RESERVED_50[4];
  __I  uint32_t ELS_AS_FLAG0;                      /**< ELS AS flag0, offset: 0x9F0 */
       uint8_t RESERVED_51[36];
  __IO uint32_t CLOCK_CTRL;                        /**< Clock Control, offset: 0xA18 */
       uint8_t RESERVED_52[244];
  __IO uint32_t COMP_INT_CTRL;                     /**< Comparator Interrupt control, offset: 0xB10 */
  __I  uint32_t COMP_INT_STATUS;                   /**< Comparator Interrupt status, offset: 0xB14 */
       uint8_t RESERVED_53[748];
  __IO uint32_t AUTOCLKGATEOVERRIDE;               /**< Control automatic clock gating, offset: 0xE04 */
  __IO uint32_t GPIOPSYNC;                         /**< GPIO Synchronization, offset: 0xE08 */
       uint8_t RESERVED_54[24];
  __IO uint32_t AUTOCLKGATEOVERRIDE1;              /**< Control automatic clock gating, offset: 0xE24 */
       uint8_t RESERVED_55[8];
  __IO uint32_t ENABLE_MEM_PARITY_ECC_CHECK;       /**< Memory parity ECC enable, offset: 0xE30 */
  __I  uint32_t MEM_PARITY_ECC_ERROR_FLAG;         /**< Memory parity ECC error flag, offset: 0xE34 */
  __IO uint32_t PWM0SUBCTL;                        /**< PWM0 submodule control, offset: 0xE38 */
  __IO uint32_t PWM1SUBCTL;                        /**< PWM1 submodule control, offset: 0xE3C */
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER global start enable, offset: 0xE40 */
       uint8_t RESERVED_56[348];
  __IO uint32_t DEBUG_LOCK_EN;                     /**< Control write access to security, offset: 0xFA0 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex debug features control, offset: 0xFA4 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex debug features control (duplicate), offset: 0xFA8 */
       uint8_t RESERVED_57[8];
  __IO uint32_t SWD_ACCESS_CPU[SYSCON_SWD_ACCESS_CPU_COUNT]; /**< CPU0 Software Debug Access, array offset: 0xFB4, array step: 0x4 */
       uint8_t RESERVED_58[8];
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug authentication BEACON, offset: 0xFC0 */
  __IO uint32_t SWD_ACCESS_DSP;                    /**< DSP Software Debug Access, offset: 0xFC4 */
       uint8_t RESERVED_59[48];
  __I  uint32_t DEVICE_ID0;                        /**< Device ID, offset: 0xFF8 */
  __I  uint32_t DIEID;                             /**< Chip revision ID and Number, offset: 0xFFC */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name MEMORYREMAP - Memory Remap Control */
/*! @{ */

#define SYSCON_MEMORYREMAP_MAP_MASK              (0x3U)
#define SYSCON_MEMORYREMAP_MAP_SHIFT             (0U)
/*! MAP - Select the location of the vector table:
 *  0b00..Vector Table in ROM.
 *  0b01..Vector Table in RAM.
 *  0b1x..Vector Table in Flash.
 */
#define SYSCON_MEMORYREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MEMORYREMAP_MAP_SHIFT)) & SYSCON_MEMORYREMAP_MAP_MASK)
/*! @} */

/*! @name AHBMATPRIO - AHB Matrix priority control */
/*! @{ */

#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK     (0x3U)
#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT    (0U)
/*! PRI_CPU0_CBUS - CPU0 C-AHB bus. */
#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_MASK     (0xCU)
#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_SHIFT    (2U)
/*! PRI_CPU0_SBUS - CPU0 S-AHB bus. */
#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB_FSD_MASK       (0x300U)
#define SYSCON_AHBMATPRIO_PRI_USB_FSD_SHIFT      (8U)
/*! PRI_USB_FSD - USB0-FS Device.(USB0) */
#define SYSCON_AHBMATPRIO_PRI_USB_FSD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB_FSD_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB_FSD_MASK)

#define SYSCON_AHBMATPRIO_PRI_SDMA0_MASK         (0xC00U)
#define SYSCON_AHBMATPRIO_PRI_SDMA0_SHIFT        (10U)
/*! PRI_SDMA0 - DMA0 controller priority. */
#define SYSCON_AHBMATPRIO_PRI_SDMA0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SDMA0_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SDMA0_MASK)

#define SYSCON_AHBMATPRIO_PRI_PQ_MASK            (0xC0000U)
#define SYSCON_AHBMATPRIO_PRI_PQ_SHIFT           (18U)
/*! PRI_PQ - PQ (HW Accelerator). */
#define SYSCON_AHBMATPRIO_PRI_PQ(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_PQ_SHIFT)) & SYSCON_AHBMATPRIO_PRI_PQ_MASK)

#define SYSCON_AHBMATPRIO_PRI_ELS_MASK           (0x300000U)
#define SYSCON_AHBMATPRIO_PRI_ELS_SHIFT          (20U)
/*! PRI_ELS - ELS */
#define SYSCON_AHBMATPRIO_PRI_ELS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_ELS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_ELS_MASK)

#define SYSCON_AHBMATPRIO_PRI_USB_FS_MASK        (0xC00000U)
#define SYSCON_AHBMATPRIO_PRI_USB_FS_SHIFT       (22U)
/*! PRI_USB_FS - USB-FS host */
#define SYSCON_AHBMATPRIO_PRI_USB_FS(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_USB_FS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_USB_FS_MASK)

#define SYSCON_AHBMATPRIO_PRI_SDMA1_MASK         (0x3000000U)
#define SYSCON_AHBMATPRIO_PRI_SDMA1_SHIFT        (24U)
/*! PRI_SDMA1 - DMA1 controller priority. */
#define SYSCON_AHBMATPRIO_PRI_SDMA1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SDMA1_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SDMA1_MASK)

#define SYSCON_AHBMATPRIO_PRI_MCAN_MASK          (0xC000000U)
#define SYSCON_AHBMATPRIO_PRI_MCAN_SHIFT         (26U)
/*! PRI_MCAN - MCAN */
#define SYSCON_AHBMATPRIO_PRI_MCAN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_MCAN_SHIFT)) & SYSCON_AHBMATPRIO_PRI_MCAN_MASK)

#define SYSCON_AHBMATPRIO_PKC_MASK               (0xC0000000U)
#define SYSCON_AHBMATPRIO_PKC_SHIFT              (30U)
/*! PKC - PKC */
#define SYSCON_AHBMATPRIO_PKC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PKC_SHIFT)) & SYSCON_AHBMATPRIO_PKC_MASK)
/*! @} */

/*! @name AHBMATPRIO1 - AHB Matrix priority control */
/*! @{ */

#define SYSCON_AHBMATPRIO1_DSP_D_MASK            (0xCU)
#define SYSCON_AHBMATPRIO1_DSP_D_SHIFT           (2U)
/*! DSP_D - DSP D bus */
#define SYSCON_AHBMATPRIO1_DSP_D(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO1_DSP_D_SHIFT)) & SYSCON_AHBMATPRIO1_DSP_D_MASK)

#define SYSCON_AHBMATPRIO1_DSP_I_MASK            (0x30U)
#define SYSCON_AHBMATPRIO1_DSP_I_SHIFT           (4U)
/*! DSP_I - DSP I bus */
#define SYSCON_AHBMATPRIO1_DSP_I(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO1_DSP_I_SHIFT)) & SYSCON_AHBMATPRIO1_DSP_I_MASK)
/*! @} */

/*! @name CPU0STCKCAL - System tick calibration for secure part of CPU0 */
/*! @{ */

#define SYSCON_CPU0STCKCAL_TENMS_MASK            (0xFFFFFFU)
#define SYSCON_CPU0STCKCAL_TENMS_SHIFT           (0U)
/*! TENMS - Reload value for 10ms (100Hz) timing, subject to system clock skew errors. If the value
 *    reads as zero, the calibration value is not known.
 */
#define SYSCON_CPU0STCKCAL_TENMS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_TENMS_SHIFT)) & SYSCON_CPU0STCKCAL_TENMS_MASK)

#define SYSCON_CPU0STCKCAL_SKEW_MASK             (0x1000000U)
#define SYSCON_CPU0STCKCAL_SKEW_SHIFT            (24U)
/*! SKEW - Indicates whether the TENMS value is exact:
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is inexact, or not given
 */
#define SYSCON_CPU0STCKCAL_SKEW(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_SKEW_SHIFT)) & SYSCON_CPU0STCKCAL_SKEW_MASK)

#define SYSCON_CPU0STCKCAL_NOREF_MASK            (0x2000000U)
#define SYSCON_CPU0STCKCAL_NOREF_SHIFT           (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor
 *  0b0..Reference clock provided
 *  0b1..No reference clock provided
 */
#define SYSCON_CPU0STCKCAL_NOREF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_NOREF_SHIFT)) & SYSCON_CPU0STCKCAL_NOREF_MASK)
/*! @} */

/*! @name CPU0NSTCKCAL - System tick calibration for non-secure part of CPU0 */
/*! @{ */

#define SYSCON_CPU0NSTCKCAL_TENMS_MASK           (0xFFFFFFU)
#define SYSCON_CPU0NSTCKCAL_TENMS_SHIFT          (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CPU0NSTCKCAL_TENMS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_TENMS_SHIFT)) & SYSCON_CPU0NSTCKCAL_TENMS_MASK)

#define SYSCON_CPU0NSTCKCAL_SKEW_MASK            (0x1000000U)
#define SYSCON_CPU0NSTCKCAL_SKEW_SHIFT           (24U)
/*! SKEW - Indicates whether the TENMS value is exact:
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is inexact, or not given
 */
#define SYSCON_CPU0NSTCKCAL_SKEW(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_SKEW_SHIFT)) & SYSCON_CPU0NSTCKCAL_SKEW_MASK)

#define SYSCON_CPU0NSTCKCAL_NOREF_MASK           (0x2000000U)
#define SYSCON_CPU0NSTCKCAL_NOREF_SHIFT          (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor:
 *  0b0..Reference clock provided
 *  0b1..No reference clock provided
 */
#define SYSCON_CPU0NSTCKCAL_NOREF(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_NOREF_SHIFT)) & SYSCON_CPU0NSTCKCAL_NOREF_MASK)
/*! @} */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON_NMISRC_IRQCPU0_MASK               (0x3FU)
#define SYSCON_NMISRC_IRQCPU0_SHIFT              (0U)
/*! IRQCPU0 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for the CPU0, if enabled by NMIENCPU0. */
#define SYSCON_NMISRC_IRQCPU0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQCPU0_SHIFT)) & SYSCON_NMISRC_IRQCPU0_MASK)

#define SYSCON_NMISRC_NMIENCPU0_MASK             (0x80000000U)
#define SYSCON_NMISRC_NMIENCPU0_SHIFT            (31U)
/*! NMIENCPU0 - Write a 1 to this bit to enable the Non-Maskable Interrupt (NMI) source selected by IRQCPU0. */
#define SYSCON_NMISRC_NMIENCPU0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENCPU0_SHIFT)) & SYSCON_NMISRC_NMIENCPU0_MASK)
/*! @} */

/*! @name PRESETCTRL0 - Peripheral reset control 0 */
/*! @{ */

#define SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_MASK   (0x8U)
#define SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_SHIFT  (3U)
/*! SRAM_CTRL1_RST - SRAM Controller 1 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_SRAM_CTRL1_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_SHIFT)) & SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_MASK)

#define SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_MASK   (0x10U)
#define SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_SHIFT  (4U)
/*! SRAM_CTRL2_RST - SRAM Controller 2 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_SRAM_CTRL2_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_SHIFT)) & SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_MASK)

#define SYSCON_PRESETCTRL0_SRAM_CTRL3_RST_MASK   (0x20U)
#define SYSCON_PRESETCTRL0_SRAM_CTRL3_RST_SHIFT  (5U)
/*! SRAM_CTRL3_RST - SRAM Controller 3 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_SRAM_CTRL3_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SRAM_CTRL3_RST_SHIFT)) & SYSCON_PRESETCTRL0_SRAM_CTRL3_RST_MASK)

#define SYSCON_PRESETCTRL0_SRAM_CTRL4_RST_MASK   (0x40U)
#define SYSCON_PRESETCTRL0_SRAM_CTRL4_RST_SHIFT  (6U)
/*! SRAM_CTRL4_RST - SRAM Controller 4 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_SRAM_CTRL4_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SRAM_CTRL4_RST_SHIFT)) & SYSCON_PRESETCTRL0_SRAM_CTRL4_RST_MASK)

#define SYSCON_PRESETCTRL0_FLASH_RST_MASK        (0x80U)
#define SYSCON_PRESETCTRL0_FLASH_RST_SHIFT       (7U)
/*! FLASH_RST - Flash controller reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_FLASH_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FLASH_RST_SHIFT)) & SYSCON_PRESETCTRL0_FLASH_RST_MASK)

#define SYSCON_PRESETCTRL0_FMC_RST_MASK          (0x100U)
#define SYSCON_PRESETCTRL0_FMC_RST_SHIFT         (8U)
/*! FMC_RST - FMC controller reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_FMC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FMC_RST_SHIFT)) & SYSCON_PRESETCTRL0_FMC_RST_MASK)

#define SYSCON_PRESETCTRL0_FLEXSPI_RST_MASK      (0x400U)
#define SYSCON_PRESETCTRL0_FLEXSPI_RST_SHIFT     (10U)
/*! FLEXSPI_RST - FLEXSPI reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_FLEXSPI_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FLEXSPI_RST_SHIFT)) & SYSCON_PRESETCTRL0_FLEXSPI_RST_MASK)

#define SYSCON_PRESETCTRL0_IOCON_RST_MASK        (0x2000U)
#define SYSCON_PRESETCTRL0_IOCON_RST_SHIFT       (13U)
/*! IOCON_RST - I/O controller reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_IOCON_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_IOCON_RST_SHIFT)) & SYSCON_PRESETCTRL0_IOCON_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO0_RST_MASK        (0x4000U)
#define SYSCON_PRESETCTRL0_GPIO0_RST_SHIFT       (14U)
/*! GPIO0_RST - GPIO0 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_GPIO0_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO0_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO0_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO1_RST_MASK        (0x8000U)
#define SYSCON_PRESETCTRL0_GPIO1_RST_SHIFT       (15U)
/*! GPIO1_RST - GPIO1 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_GPIO1_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO1_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO1_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO2_RST_MASK        (0x10000U)
#define SYSCON_PRESETCTRL0_GPIO2_RST_SHIFT       (16U)
/*! GPIO2_RST - GPIO2 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_GPIO2_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO2_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO2_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO3_RST_MASK        (0x20000U)
#define SYSCON_PRESETCTRL0_GPIO3_RST_SHIFT       (17U)
/*! GPIO3_RST - GPIO3 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_GPIO3_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO3_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO3_RST_MASK)

#define SYSCON_PRESETCTRL0_PINT_RST_MASK         (0x40000U)
#define SYSCON_PRESETCTRL0_PINT_RST_SHIFT        (18U)
/*! PINT_RST - Pin interrupt (PINT) reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_PINT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PINT_RST_SHIFT)) & SYSCON_PRESETCTRL0_PINT_RST_MASK)

#define SYSCON_PRESETCTRL0_GINT_RST_MASK         (0x80000U)
#define SYSCON_PRESETCTRL0_GINT_RST_SHIFT        (19U)
/*! GINT_RST - Group interrupt (GINT) reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_GINT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GINT_RST_SHIFT)) & SYSCON_PRESETCTRL0_GINT_RST_MASK)

#define SYSCON_PRESETCTRL0_DMA0_RST_MASK         (0x100000U)
#define SYSCON_PRESETCTRL0_DMA0_RST_SHIFT        (20U)
/*! DMA0_RST - DMA0 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_DMA0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DMA0_RST_SHIFT)) & SYSCON_PRESETCTRL0_DMA0_RST_MASK)

#define SYSCON_PRESETCTRL0_CRCGEN_RST_MASK       (0x200000U)
#define SYSCON_PRESETCTRL0_CRCGEN_RST_SHIFT      (21U)
/*! CRCGEN_RST - CRCGEN reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_CRCGEN_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CRCGEN_RST_SHIFT)) & SYSCON_PRESETCTRL0_CRCGEN_RST_MASK)

#define SYSCON_PRESETCTRL0_WWDT_RST_MASK         (0x400000U)
#define SYSCON_PRESETCTRL0_WWDT_RST_SHIFT        (22U)
/*! WWDT_RST - Watchdog Timer reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_WWDT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_WWDT_RST_SHIFT)) & SYSCON_PRESETCTRL0_WWDT_RST_MASK)

#define SYSCON_PRESETCTRL0_RTC_RST_MASK          (0x800000U)
#define SYSCON_PRESETCTRL0_RTC_RST_SHIFT         (23U)
/*! RTC_RST - Real Time Clock (RTC) reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_RTC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_RTC_RST_SHIFT)) & SYSCON_PRESETCTRL0_RTC_RST_MASK)

#define SYSCON_PRESETCTRL0_MAILBOX_RST_MASK      (0x4000000U)
#define SYSCON_PRESETCTRL0_MAILBOX_RST_SHIFT     (26U)
/*! MAILBOX_RST - Inter CPU communication Mailbox reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_MAILBOX_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_MAILBOX_RST_SHIFT)) & SYSCON_PRESETCTRL0_MAILBOX_RST_MASK)

#define SYSCON_PRESETCTRL0_ADC0_RST_MASK         (0x8000000U)
#define SYSCON_PRESETCTRL0_ADC0_RST_SHIFT        (27U)
/*! ADC0_RST - ADC0 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_ADC0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ADC0_RST_SHIFT)) & SYSCON_PRESETCTRL0_ADC0_RST_MASK)

#define SYSCON_PRESETCTRL0_ADC1_RST_MASK         (0x10000000U)
#define SYSCON_PRESETCTRL0_ADC1_RST_SHIFT        (28U)
/*! ADC1_RST - ADC1 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_ADC1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ADC1_RST_SHIFT)) & SYSCON_PRESETCTRL0_ADC1_RST_MASK)

#define SYSCON_PRESETCTRL0_DAC0_RST_MASK         (0x20000000U)
#define SYSCON_PRESETCTRL0_DAC0_RST_SHIFT        (29U)
/*! DAC0_RST - DAC0 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL0_DAC0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DAC0_RST_SHIFT)) & SYSCON_PRESETCTRL0_DAC0_RST_MASK)
/*! @} */

/*! @name PRESETCTRL1 - Peripheral reset control 1 */
/*! @{ */

#define SYSCON_PRESETCTRL1_MRT_RST_MASK          (0x1U)
#define SYSCON_PRESETCTRL1_MRT_RST_SHIFT         (0U)
/*! MRT_RST - MRT reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_MRT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_MRT_RST_SHIFT)) & SYSCON_PRESETCTRL1_MRT_RST_MASK)

#define SYSCON_PRESETCTRL1_OSTIMER_RST_MASK      (0x2U)
#define SYSCON_PRESETCTRL1_OSTIMER_RST_SHIFT     (1U)
/*! OSTIMER_RST - OS Event Timer reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_OSTIMER_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_OSTIMER_RST_SHIFT)) & SYSCON_PRESETCTRL1_OSTIMER_RST_MASK)

#define SYSCON_PRESETCTRL1_SCT_RST_MASK          (0x4U)
#define SYSCON_PRESETCTRL1_SCT_RST_SHIFT         (2U)
/*! SCT_RST - SCT reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_SCT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_SCT_RST_SHIFT)) & SYSCON_PRESETCTRL1_SCT_RST_MASK)

#define SYSCON_PRESETCTRL1_CAN_RST_MASK          (0x80U)
#define SYSCON_PRESETCTRL1_CAN_RST_SHIFT         (7U)
/*! CAN_RST - CAN reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_CAN_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_CAN_RST_SHIFT)) & SYSCON_PRESETCTRL1_CAN_RST_MASK)

#define SYSCON_PRESETCTRL1_UTICK_RST_MASK        (0x400U)
#define SYSCON_PRESETCTRL1_UTICK_RST_SHIFT       (10U)
/*! UTICK_RST - UTICK reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_UTICK_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_UTICK_RST_SHIFT)) & SYSCON_PRESETCTRL1_UTICK_RST_MASK)

#define SYSCON_PRESETCTRL1_FC0_RST_MASK          (0x800U)
#define SYSCON_PRESETCTRL1_FC0_RST_SHIFT         (11U)
/*! FC0_RST - FC0 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC0_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC0_RST_MASK)

#define SYSCON_PRESETCTRL1_FC1_RST_MASK          (0x1000U)
#define SYSCON_PRESETCTRL1_FC1_RST_SHIFT         (12U)
/*! FC1_RST - FC1 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC1_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC1_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC1_RST_MASK)

#define SYSCON_PRESETCTRL1_FC2_RST_MASK          (0x2000U)
#define SYSCON_PRESETCTRL1_FC2_RST_SHIFT         (13U)
/*! FC2_RST - FC2 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC2_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC2_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC2_RST_MASK)

#define SYSCON_PRESETCTRL1_FC3_RST_MASK          (0x4000U)
#define SYSCON_PRESETCTRL1_FC3_RST_SHIFT         (14U)
/*! FC3_RST - FC3 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC3_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC3_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC3_RST_MASK)

#define SYSCON_PRESETCTRL1_FC4_RST_MASK          (0x8000U)
#define SYSCON_PRESETCTRL1_FC4_RST_SHIFT         (15U)
/*! FC4_RST - FC4 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC4_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC4_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC4_RST_MASK)

#define SYSCON_PRESETCTRL1_FC5_RST_MASK          (0x10000U)
#define SYSCON_PRESETCTRL1_FC5_RST_SHIFT         (16U)
/*! FC5_RST - FC5 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC5_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC5_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC5_RST_MASK)

#define SYSCON_PRESETCTRL1_FC6_RST_MASK          (0x20000U)
#define SYSCON_PRESETCTRL1_FC6_RST_SHIFT         (17U)
/*! FC6_RST - FC6 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC6_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC6_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC6_RST_MASK)

#define SYSCON_PRESETCTRL1_FC7_RST_MASK          (0x40000U)
#define SYSCON_PRESETCTRL1_FC7_RST_SHIFT         (18U)
/*! FC7_RST - FC7 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_FC7_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC7_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC7_RST_MASK)

#define SYSCON_PRESETCTRL1_DMIC_RST_MASK         (0x80000U)
#define SYSCON_PRESETCTRL1_DMIC_RST_SHIFT        (19U)
/*! DMIC_RST - DMIC reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_DMIC_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_DMIC_RST_SHIFT)) & SYSCON_PRESETCTRL1_DMIC_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER2_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL1_TIMER2_RST_SHIFT      (22U)
/*! TIMER2_RST - Timer 2 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_TIMER2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER2_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER2_RST_MASK)

#define SYSCON_PRESETCTRL1_USB0_DEV_RST_MASK     (0x2000000U)
#define SYSCON_PRESETCTRL1_USB0_DEV_RST_SHIFT    (25U)
/*! USB0_DEV_RST - USB0-FS DEV reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_USB0_DEV_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_USB0_DEV_RST_SHIFT)) & SYSCON_PRESETCTRL1_USB0_DEV_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER0_RST_MASK       (0x4000000U)
#define SYSCON_PRESETCTRL1_TIMER0_RST_SHIFT      (26U)
/*! TIMER0_RST - Timer 0 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_TIMER0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER0_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER0_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER1_RST_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL1_TIMER1_RST_SHIFT      (27U)
/*! TIMER1_RST - Timer 1 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL1_TIMER1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER1_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER1_RST_MASK)
/*! @} */

/*! @name PRESETCTRL2 - Peripheral reset control 2 */
/*! @{ */

#define SYSCON_PRESETCTRL2_DMA1_RST_MASK         (0x2U)
#define SYSCON_PRESETCTRL2_DMA1_RST_SHIFT        (1U)
/*! DMA1_RST - DMA1 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_DMA1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_DMA1_RST_SHIFT)) & SYSCON_PRESETCTRL2_DMA1_RST_MASK)

#define SYSCON_PRESETCTRL2_COMP_RST_MASK         (0x4U)
#define SYSCON_PRESETCTRL2_COMP_RST_SHIFT        (2U)
/*! COMP_RST - Analog comparator reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_COMP_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_COMP_RST_SHIFT)) & SYSCON_PRESETCTRL2_COMP_RST_MASK)

#define SYSCON_PRESETCTRL2_FREQME_RST_MASK       (0x100U)
#define SYSCON_PRESETCTRL2_FREQME_RST_SHIFT      (8U)
/*! FREQME_RST - Frequency meter reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_FREQME_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_FREQME_RST_SHIFT)) & SYSCON_PRESETCTRL2_FREQME_RST_MASK)

#define SYSCON_PRESETCTRL2_RNG_RST_MASK          (0x2000U)
#define SYSCON_PRESETCTRL2_RNG_RST_SHIFT         (13U)
/*! RNG_RST - RNG reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_RNG_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_RNG_RST_SHIFT)) & SYSCON_PRESETCTRL2_RNG_RST_MASK)

#define SYSCON_PRESETCTRL2_SYSCTL_RST_MASK       (0x8000U)
#define SYSCON_PRESETCTRL2_SYSCTL_RST_SHIFT      (15U)
/*! SYSCTL_RST - SYSCTL Block reset.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_SYSCTL_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_SYSCTL_RST_SHIFT)) & SYSCON_PRESETCTRL2_SYSCTL_RST_MASK)

#define SYSCON_PRESETCTRL2_USB0_HOSTM_RST_MASK   (0x10000U)
#define SYSCON_PRESETCTRL2_USB0_HOSTM_RST_SHIFT  (16U)
/*! USB0_HOSTM_RST - USB0-FS Host Master reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_USB0_HOSTM_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_USB0_HOSTM_RST_SHIFT)) & SYSCON_PRESETCTRL2_USB0_HOSTM_RST_MASK)

#define SYSCON_PRESETCTRL2_USB0_HOSTS_RST_MASK   (0x20000U)
#define SYSCON_PRESETCTRL2_USB0_HOSTS_RST_SHIFT  (17U)
/*! USB0_HOSTS_RST - USB0-FS Host Slave reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_USB0_HOSTS_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_USB0_HOSTS_RST_SHIFT)) & SYSCON_PRESETCTRL2_USB0_HOSTS_RST_MASK)

#define SYSCON_PRESETCTRL2_ELS_RST_MASK          (0x40000U)
#define SYSCON_PRESETCTRL2_ELS_RST_SHIFT         (18U)
/*! ELS_RST - ELS reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_ELS_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_ELS_RST_SHIFT)) & SYSCON_PRESETCTRL2_ELS_RST_MASK)

#define SYSCON_PRESETCTRL2_PQ_RST_MASK           (0x80000U)
#define SYSCON_PRESETCTRL2_PQ_RST_SHIFT          (19U)
/*! PQ_RST - Power Quad reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_PQ_RST(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PQ_RST_SHIFT)) & SYSCON_PRESETCTRL2_PQ_RST_MASK)

#define SYSCON_PRESETCTRL2_TIMER3_RST_MASK       (0x200000U)
#define SYSCON_PRESETCTRL2_TIMER3_RST_SHIFT      (21U)
/*! TIMER3_RST - Timer 3 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_TIMER3_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TIMER3_RST_SHIFT)) & SYSCON_PRESETCTRL2_TIMER3_RST_MASK)

#define SYSCON_PRESETCTRL2_TIMER4_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL2_TIMER4_RST_SHIFT      (22U)
/*! TIMER4_RST - Timer 4 reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_TIMER4_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TIMER4_RST_SHIFT)) & SYSCON_PRESETCTRL2_TIMER4_RST_MASK)

#define SYSCON_PRESETCTRL2_PUF_RST_MASK          (0x800000U)
#define SYSCON_PRESETCTRL2_PUF_RST_SHIFT         (23U)
/*! PUF_RST - PUF reset control reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_PUF_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PUF_RST_SHIFT)) & SYSCON_PRESETCTRL2_PUF_RST_MASK)

#define SYSCON_PRESETCTRL2_PKC_RST_MASK          (0x1000000U)
#define SYSCON_PRESETCTRL2_PKC_RST_SHIFT         (24U)
/*! PKC_RST - PKC reset control.
 *  0b0..Block is not reset.g
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_PKC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PKC_RST_SHIFT)) & SYSCON_PRESETCTRL2_PKC_RST_MASK)

#define SYSCON_PRESETCTRL2_ANACTRL_RST_MASK      (0x8000000U)
#define SYSCON_PRESETCTRL2_ANACTRL_RST_SHIFT     (27U)
/*! ANACTRL_RST - Analog control reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_ANACTRL_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_ANACTRL_RST_SHIFT)) & SYSCON_PRESETCTRL2_ANACTRL_RST_MASK)

#define SYSCON_PRESETCTRL2_HS_SPI_RST_MASK       (0x10000000U)
#define SYSCON_PRESETCTRL2_HS_SPI_RST_SHIFT      (28U)
/*! HS_SPI_RST - HS SPI reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_HS_SPI_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_HS_SPI_RST_SHIFT)) & SYSCON_PRESETCTRL2_HS_SPI_RST_MASK)

#define SYSCON_PRESETCTRL2_GPIO_SEC_RST_MASK     (0x20000000U)
#define SYSCON_PRESETCTRL2_GPIO_SEC_RST_SHIFT    (29U)
/*! GPIO_SEC_RST - GPIO secure reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_GPIO_SEC_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_GPIO_SEC_RST_SHIFT)) & SYSCON_PRESETCTRL2_GPIO_SEC_RST_MASK)

#define SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_MASK (0x40000000U)
#define SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_SHIFT (30U)
/*! GPIO_SEC_INT_RST - GPIO secure int reset control.
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_SHIFT)) & SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_MASK)
/*! @} */

/*! @name PRESETCTRL3 - Peripheral reset control 3 */
/*! @{ */

#define SYSCON_PRESETCTRL3_I3C0_RST_MASK         (0x1U)
#define SYSCON_PRESETCTRL3_I3C0_RST_SHIFT        (0U)
/*! I3C0_RST - I3C reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_I3C0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_I3C0_RST_SHIFT)) & SYSCON_PRESETCTRL3_I3C0_RST_MASK)

#define SYSCON_PRESETCTRL3_ENC0_RST_MASK         (0x8U)
#define SYSCON_PRESETCTRL3_ENC0_RST_SHIFT        (3U)
/*! ENC0_RST - ENC0 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_ENC0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_ENC0_RST_SHIFT)) & SYSCON_PRESETCTRL3_ENC0_RST_MASK)

#define SYSCON_PRESETCTRL3_ENC1_RST_MASK         (0x10U)
#define SYSCON_PRESETCTRL3_ENC1_RST_SHIFT        (4U)
/*! ENC1_RST - ENC1 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_ENC1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_ENC1_RST_SHIFT)) & SYSCON_PRESETCTRL3_ENC1_RST_MASK)

#define SYSCON_PRESETCTRL3_PWM0_RST_MASK         (0x20U)
#define SYSCON_PRESETCTRL3_PWM0_RST_SHIFT        (5U)
/*! PWM0_RST - PWM0 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_PWM0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_PWM0_RST_SHIFT)) & SYSCON_PRESETCTRL3_PWM0_RST_MASK)

#define SYSCON_PRESETCTRL3_PWM1_RST_MASK         (0x40U)
#define SYSCON_PRESETCTRL3_PWM1_RST_SHIFT        (6U)
/*! PWM1_RST - PWM1 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_PWM1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_PWM1_RST_SHIFT)) & SYSCON_PRESETCTRL3_PWM1_RST_MASK)

#define SYSCON_PRESETCTRL3_AOI0_RST_MASK         (0x80U)
#define SYSCON_PRESETCTRL3_AOI0_RST_SHIFT        (7U)
/*! AOI0_RST - AOI0 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_AOI0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_AOI0_RST_SHIFT)) & SYSCON_PRESETCTRL3_AOI0_RST_MASK)

#define SYSCON_PRESETCTRL3_AOI1_RST_MASK         (0x100U)
#define SYSCON_PRESETCTRL3_AOI1_RST_SHIFT        (8U)
/*! AOI1_RST - AOI1 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_AOI1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_AOI1_RST_SHIFT)) & SYSCON_PRESETCTRL3_AOI1_RST_MASK)

#define SYSCON_PRESETCTRL3_FTM0_RST_MASK         (0x200U)
#define SYSCON_PRESETCTRL3_FTM0_RST_SHIFT        (9U)
/*! FTM0_RST - FTM0 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_FTM0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_FTM0_RST_SHIFT)) & SYSCON_PRESETCTRL3_FTM0_RST_MASK)

#define SYSCON_PRESETCTRL3_DAC1_RST_MASK         (0x400U)
#define SYSCON_PRESETCTRL3_DAC1_RST_SHIFT        (10U)
/*! DAC1_RST - DAC1 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_DAC1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_DAC1_RST_SHIFT)) & SYSCON_PRESETCTRL3_DAC1_RST_MASK)

#define SYSCON_PRESETCTRL3_DAC2_RST_MASK         (0x800U)
#define SYSCON_PRESETCTRL3_DAC2_RST_SHIFT        (11U)
/*! DAC2_RST - DAC2 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_DAC2_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_DAC2_RST_SHIFT)) & SYSCON_PRESETCTRL3_DAC2_RST_MASK)

#define SYSCON_PRESETCTRL3_OPAMP0_RST_MASK       (0x1000U)
#define SYSCON_PRESETCTRL3_OPAMP0_RST_SHIFT      (12U)
/*! OPAMP0_RST - OPAMP0 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_OPAMP0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_OPAMP0_RST_SHIFT)) & SYSCON_PRESETCTRL3_OPAMP0_RST_MASK)

#define SYSCON_PRESETCTRL3_OPAMP1_RST_MASK       (0x2000U)
#define SYSCON_PRESETCTRL3_OPAMP1_RST_SHIFT      (13U)
/*! OPAMP1_RST - OPAMP1 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_OPAMP1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_OPAMP1_RST_SHIFT)) & SYSCON_PRESETCTRL3_OPAMP1_RST_MASK)

#define SYSCON_PRESETCTRL3_OPAMP2_RST_MASK       (0x4000U)
#define SYSCON_PRESETCTRL3_OPAMP2_RST_SHIFT      (14U)
/*! OPAMP2_RST - OPAMP2 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_OPAMP2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_OPAMP2_RST_SHIFT)) & SYSCON_PRESETCTRL3_OPAMP2_RST_MASK)

#define SYSCON_PRESETCTRL3_HSCMP0_RST_MASK       (0x8000U)
#define SYSCON_PRESETCTRL3_HSCMP0_RST_SHIFT      (15U)
/*! HSCMP0_RST - HSCMP0 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_HSCMP0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_HSCMP0_RST_SHIFT)) & SYSCON_PRESETCTRL3_HSCMP0_RST_MASK)

#define SYSCON_PRESETCTRL3_HSCMP1_RST_MASK       (0x10000U)
#define SYSCON_PRESETCTRL3_HSCMP1_RST_SHIFT      (16U)
/*! HSCMP1_RST - HSCMP1 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_HSCMP1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_HSCMP1_RST_SHIFT)) & SYSCON_PRESETCTRL3_HSCMP1_RST_MASK)

#define SYSCON_PRESETCTRL3_HSCMP2_RST_MASK       (0x20000U)
#define SYSCON_PRESETCTRL3_HSCMP2_RST_SHIFT      (17U)
/*! HSCMP2_RST - HSCMP2 reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_HSCMP2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_HSCMP2_RST_SHIFT)) & SYSCON_PRESETCTRL3_HSCMP2_RST_MASK)

#define SYSCON_PRESETCTRL3_VREF_RST_MASK         (0x40000U)
#define SYSCON_PRESETCTRL3_VREF_RST_SHIFT        (18U)
/*! VREF_RST - VREF reset control
 *  0b0..Block is not reset.
 *  0b1..Block is reset.
 */
#define SYSCON_PRESETCTRL3_VREF_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL3_VREF_RST_SHIFT)) & SYSCON_PRESETCTRL3_VREF_RST_MASK)
/*! @} */

/*! @name PRESETCTRLSET - Peripheral reset control set n */
/*! @{ */

#define SYSCON_PRESETCTRLSET_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLSET_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_PRESETCTRLSET_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_DATA_SHIFT)) & SYSCON_PRESETCTRLSET_DATA_MASK)

#define SYSCON_PRESETCTRLSET_DATA_L_MASK         (0x7FFU)
#define SYSCON_PRESETCTRLSET_DATA_L_SHIFT        (0U)
/*! DATA_L - Data array value */
#define SYSCON_PRESETCTRLSET_DATA_L(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_DATA_L_SHIFT)) & SYSCON_PRESETCTRLSET_DATA_L_MASK)

#define SYSCON_PRESETCTRLSET_DATA_U_MASK         (0xFFFFF000U)
#define SYSCON_PRESETCTRLSET_DATA_U_SHIFT        (12U)
/*! DATA_U - Data array value */
#define SYSCON_PRESETCTRLSET_DATA_U(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_DATA_U_SHIFT)) & SYSCON_PRESETCTRLSET_DATA_U_MASK)
/*! @} */

/*! @name PRESETCTRLCLR - Peripheral reset control clear n */
/*! @{ */

#define SYSCON_PRESETCTRLCLR_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLCLR_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_PRESETCTRLCLR_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_DATA_SHIFT)) & SYSCON_PRESETCTRLCLR_DATA_MASK)

#define SYSCON_PRESETCTRLCLR_DATA_L_MASK         (0x7FFU)
#define SYSCON_PRESETCTRLCLR_DATA_L_SHIFT        (0U)
/*! DATA_L - Data array value */
#define SYSCON_PRESETCTRLCLR_DATA_L(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_DATA_L_SHIFT)) & SYSCON_PRESETCTRLCLR_DATA_L_MASK)

#define SYSCON_PRESETCTRLCLR_DATA_U_MASK         (0xFFFFF000U)
#define SYSCON_PRESETCTRLCLR_DATA_U_SHIFT        (12U)
/*! DATA_U - Data array value */
#define SYSCON_PRESETCTRLCLR_DATA_U(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_DATA_U_SHIFT)) & SYSCON_PRESETCTRLCLR_DATA_U_MASK)
/*! @} */

/*! @name SWR_RESET - Software Reset */
/*! @{ */

#define SYSCON_SWR_RESET_SWR_RESET_MASK          (0xFFFFFFFFU)
#define SYSCON_SWR_RESET_SWR_RESET_SHIFT         (0U)
/*! SWR_RESET - Write 0x5A00_0001 to generate a software_reset. */
#define SYSCON_SWR_RESET_SWR_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SWR_RESET_SWR_RESET_SHIFT)) & SYSCON_SWR_RESET_SWR_RESET_MASK)
/*! @} */

/*! @name AHBCLKCTRL0 - AHB Clock control 0 */
/*! @{ */

#define SYSCON_AHBCLKCTRL0_ROM_MASK              (0x2U)
#define SYSCON_AHBCLKCTRL0_ROM_SHIFT             (1U)
/*! ROM - Enables the clock for the ROM.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_ROM(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_ROM_SHIFT)) & SYSCON_AHBCLKCTRL0_ROM_MASK)

#define SYSCON_AHBCLKCTRL0_SRAM_CTRL1_MASK       (0x8U)
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL1_SHIFT      (3U)
/*! SRAM_CTRL1 - Enables the clock for the SRAM Controller 1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_SRAM_CTRL1_SHIFT)) & SYSCON_AHBCLKCTRL0_SRAM_CTRL1_MASK)

#define SYSCON_AHBCLKCTRL0_SRAM_CTRL2_MASK       (0x10U)
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL2_SHIFT      (4U)
/*! SRAM_CTRL2 - Enables the clock for the SRAM Controller 2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL2(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_SRAM_CTRL2_SHIFT)) & SYSCON_AHBCLKCTRL0_SRAM_CTRL2_MASK)

#define SYSCON_AHBCLKCTRL0_SRAM_CTRL3_MASK       (0x20U)
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL3_SHIFT      (5U)
/*! SRAM_CTRL3 - Enables the clock for the SRAM Controller 3.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL3(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_SRAM_CTRL3_SHIFT)) & SYSCON_AHBCLKCTRL0_SRAM_CTRL3_MASK)

#define SYSCON_AHBCLKCTRL0_SRAM_CTRL4_MASK       (0x40U)
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL4_SHIFT      (6U)
/*! SRAM_CTRL4 - Enables the clock for the SRAM Controller 4.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_SRAM_CTRL4(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_SRAM_CTRL4_SHIFT)) & SYSCON_AHBCLKCTRL0_SRAM_CTRL4_MASK)

#define SYSCON_AHBCLKCTRL0_FLASH_MASK            (0x80U)
#define SYSCON_AHBCLKCTRL0_FLASH_SHIFT           (7U)
/*! FLASH - Enables the clock for the Flash controller.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_FLASH(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_FLASH_SHIFT)) & SYSCON_AHBCLKCTRL0_FLASH_MASK)

#define SYSCON_AHBCLKCTRL0_FMC_MASK              (0x100U)
#define SYSCON_AHBCLKCTRL0_FMC_SHIFT             (8U)
/*! FMC - Enables the clock for the FMC controller.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_FMC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_FMC_SHIFT)) & SYSCON_AHBCLKCTRL0_FMC_MASK)

#define SYSCON_AHBCLKCTRL0_FLEXSPI_MASK          (0x400U)
#define SYSCON_AHBCLKCTRL0_FLEXSPI_SHIFT         (10U)
/*! FLEXSPI - Enables the clock for the Flexspi.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_FLEXSPI(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_FLEXSPI_SHIFT)) & SYSCON_AHBCLKCTRL0_FLEXSPI_MASK)

#define SYSCON_AHBCLKCTRL0_MUX_MASK              (0x800U)
#define SYSCON_AHBCLKCTRL0_MUX_SHIFT             (11U)
/*! MUX - Enables the clock for the Input Mux.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_MUX(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_MUX_SHIFT)) & SYSCON_AHBCLKCTRL0_MUX_MASK)

#define SYSCON_AHBCLKCTRL0_IOCON_MASK            (0x2000U)
#define SYSCON_AHBCLKCTRL0_IOCON_SHIFT           (13U)
/*! IOCON - Enables the clock for the I/O controller.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_IOCON(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_IOCON_SHIFT)) & SYSCON_AHBCLKCTRL0_IOCON_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO0_MASK            (0x4000U)
#define SYSCON_AHBCLKCTRL0_GPIO0_SHIFT           (14U)
/*! GPIO0 - Enables the clock for the GPIO0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO0_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO0_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO1_MASK            (0x8000U)
#define SYSCON_AHBCLKCTRL0_GPIO1_SHIFT           (15U)
/*! GPIO1 - Enables the clock for the GPIO1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO1_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO1_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO2_MASK            (0x10000U)
#define SYSCON_AHBCLKCTRL0_GPIO2_SHIFT           (16U)
/*! GPIO2 - Enables the clock for the GPIO2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO2_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO2_MASK)

#define SYSCON_AHBCLKCTRL0_GPIO3_MASK            (0x20000U)
#define SYSCON_AHBCLKCTRL0_GPIO3_SHIFT           (17U)
/*! GPIO3 - Enables the clock for the GPIO3.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GPIO3_SHIFT)) & SYSCON_AHBCLKCTRL0_GPIO3_MASK)

#define SYSCON_AHBCLKCTRL0_PINT_MASK             (0x40000U)
#define SYSCON_AHBCLKCTRL0_PINT_SHIFT            (18U)
/*! PINT - Enables the clock for the Pin interrupt (PINT).
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_PINT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_PINT_SHIFT)) & SYSCON_AHBCLKCTRL0_PINT_MASK)

#define SYSCON_AHBCLKCTRL0_GINT_MASK             (0x80000U)
#define SYSCON_AHBCLKCTRL0_GINT_SHIFT            (19U)
/*! GINT - Enables the clock for the Group interrupt (GINT).
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_GINT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_GINT_SHIFT)) & SYSCON_AHBCLKCTRL0_GINT_MASK)

#define SYSCON_AHBCLKCTRL0_DMA0_MASK             (0x100000U)
#define SYSCON_AHBCLKCTRL0_DMA0_SHIFT            (20U)
/*! DMA0 - Enables the clock for the DMA0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_DMA0_SHIFT)) & SYSCON_AHBCLKCTRL0_DMA0_MASK)

#define SYSCON_AHBCLKCTRL0_CRCGEN_MASK           (0x200000U)
#define SYSCON_AHBCLKCTRL0_CRCGEN_SHIFT          (21U)
/*! CRCGEN - Enables the clock for the CRCGEN.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_CRCGEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_CRCGEN_SHIFT)) & SYSCON_AHBCLKCTRL0_CRCGEN_MASK)

#define SYSCON_AHBCLKCTRL0_WWDT_MASK             (0x400000U)
#define SYSCON_AHBCLKCTRL0_WWDT_SHIFT            (22U)
/*! WWDT - Enables the clock for the Watchdog Timer.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_WWDT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_WWDT_SHIFT)) & SYSCON_AHBCLKCTRL0_WWDT_MASK)

#define SYSCON_AHBCLKCTRL0_RTC_MASK              (0x800000U)
#define SYSCON_AHBCLKCTRL0_RTC_SHIFT             (23U)
/*! RTC - Enables the clock for the Real Time Clock (RTC).
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_RTC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_RTC_SHIFT)) & SYSCON_AHBCLKCTRL0_RTC_MASK)

#define SYSCON_AHBCLKCTRL0_MAILBOX_MASK          (0x4000000U)
#define SYSCON_AHBCLKCTRL0_MAILBOX_SHIFT         (26U)
/*! MAILBOX - Enables the clock for the Inter CPU communication Mailbox.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_MAILBOX(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_MAILBOX_SHIFT)) & SYSCON_AHBCLKCTRL0_MAILBOX_MASK)

#define SYSCON_AHBCLKCTRL0_ADC0_MASK             (0x8000000U)
#define SYSCON_AHBCLKCTRL0_ADC0_SHIFT            (27U)
/*! ADC0 - Enables the clock for ADC0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_ADC0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_ADC0_SHIFT)) & SYSCON_AHBCLKCTRL0_ADC0_MASK)

#define SYSCON_AHBCLKCTRL0_ADC1_MASK             (0x10000000U)
#define SYSCON_AHBCLKCTRL0_ADC1_SHIFT            (28U)
/*! ADC1 - Enables the clock for ADC1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_ADC1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_ADC1_SHIFT)) & SYSCON_AHBCLKCTRL0_ADC1_MASK)

#define SYSCON_AHBCLKCTRL0_DAC0_MASK             (0x20000000U)
#define SYSCON_AHBCLKCTRL0_DAC0_SHIFT            (29U)
/*! DAC0 - Enables the clock for DAC0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL0_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL0_DAC0_SHIFT)) & SYSCON_AHBCLKCTRL0_DAC0_MASK)
/*! @} */

/*! @name AHBCLKCTRL1 - AHB Clock control 1 */
/*! @{ */

#define SYSCON_AHBCLKCTRL1_MRT_MASK              (0x1U)
#define SYSCON_AHBCLKCTRL1_MRT_SHIFT             (0U)
/*! MRT - Enables the clock for the MRT.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_MRT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_MRT_SHIFT)) & SYSCON_AHBCLKCTRL1_MRT_MASK)

#define SYSCON_AHBCLKCTRL1_OSTIMER_MASK          (0x2U)
#define SYSCON_AHBCLKCTRL1_OSTIMER_SHIFT         (1U)
/*! OSTIMER - Enables the clock for the OS Event Timer.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_OSTIMER(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_OSTIMER_SHIFT)) & SYSCON_AHBCLKCTRL1_OSTIMER_MASK)

#define SYSCON_AHBCLKCTRL1_SCT_MASK              (0x4U)
#define SYSCON_AHBCLKCTRL1_SCT_SHIFT             (2U)
/*! SCT - Enables the clock for the SCT.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_SCT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_SCT_SHIFT)) & SYSCON_AHBCLKCTRL1_SCT_MASK)

#define SYSCON_AHBCLKCTRL1_CAN_MASK              (0x80U)
#define SYSCON_AHBCLKCTRL1_CAN_SHIFT             (7U)
/*! CAN - Enables the clock for the CAN.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_CAN(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_CAN_SHIFT)) & SYSCON_AHBCLKCTRL1_CAN_MASK)

#define SYSCON_AHBCLKCTRL1_UTICK_MASK            (0x400U)
#define SYSCON_AHBCLKCTRL1_UTICK_SHIFT           (10U)
/*! UTICK - Enables the clock for the UTICK.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_UTICK(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_UTICK_SHIFT)) & SYSCON_AHBCLKCTRL1_UTICK_MASK)

#define SYSCON_AHBCLKCTRL1_FC0_MASK              (0x800U)
#define SYSCON_AHBCLKCTRL1_FC0_SHIFT             (11U)
/*! FC0 - Enables the clock for the FC0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC0_SHIFT)) & SYSCON_AHBCLKCTRL1_FC0_MASK)

#define SYSCON_AHBCLKCTRL1_FC1_MASK              (0x1000U)
#define SYSCON_AHBCLKCTRL1_FC1_SHIFT             (12U)
/*! FC1 - Enables the clock for the FC1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC1_SHIFT)) & SYSCON_AHBCLKCTRL1_FC1_MASK)

#define SYSCON_AHBCLKCTRL1_FC2_MASK              (0x2000U)
#define SYSCON_AHBCLKCTRL1_FC2_SHIFT             (13U)
/*! FC2 - Enables the clock for the FC2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC2(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC2_SHIFT)) & SYSCON_AHBCLKCTRL1_FC2_MASK)

#define SYSCON_AHBCLKCTRL1_FC3_MASK              (0x4000U)
#define SYSCON_AHBCLKCTRL1_FC3_SHIFT             (14U)
/*! FC3 - Enables the clock for the FC3.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC3_SHIFT)) & SYSCON_AHBCLKCTRL1_FC3_MASK)

#define SYSCON_AHBCLKCTRL1_FC4_MASK              (0x8000U)
#define SYSCON_AHBCLKCTRL1_FC4_SHIFT             (15U)
/*! FC4 - Enables the clock for the FC4.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC4_SHIFT)) & SYSCON_AHBCLKCTRL1_FC4_MASK)

#define SYSCON_AHBCLKCTRL1_FC5_MASK              (0x10000U)
#define SYSCON_AHBCLKCTRL1_FC5_SHIFT             (16U)
/*! FC5 - Enables the clock for the FC5.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC5(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC5_SHIFT)) & SYSCON_AHBCLKCTRL1_FC5_MASK)

#define SYSCON_AHBCLKCTRL1_FC6_MASK              (0x20000U)
#define SYSCON_AHBCLKCTRL1_FC6_SHIFT             (17U)
/*! FC6 - Enables the clock for the FC6.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC6(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC6_SHIFT)) & SYSCON_AHBCLKCTRL1_FC6_MASK)

#define SYSCON_AHBCLKCTRL1_FC7_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL1_FC7_SHIFT             (18U)
/*! FC7 - Enables the clock for the FC7.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_FC7(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_FC7_SHIFT)) & SYSCON_AHBCLKCTRL1_FC7_MASK)

#define SYSCON_AHBCLKCTRL1_DMIC_MASK             (0x80000U)
#define SYSCON_AHBCLKCTRL1_DMIC_SHIFT            (19U)
/*! DMIC - Enables the clock for DMIC.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_DMIC(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_DMIC_SHIFT)) & SYSCON_AHBCLKCTRL1_DMIC_MASK)

#define SYSCON_AHBCLKCTRL1_TIMER2_MASK           (0x400000U)
#define SYSCON_AHBCLKCTRL1_TIMER2_SHIFT          (22U)
/*! TIMER2 - Enables the clock for the Timer 2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_TIMER2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER2_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER2_MASK)

#define SYSCON_AHBCLKCTRL1_USB0_DEV_MASK         (0x2000000U)
#define SYSCON_AHBCLKCTRL1_USB0_DEV_SHIFT        (25U)
/*! USB0_DEV - Enables the clock for the USB0-FS device.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_USB0_DEV(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_USB0_DEV_SHIFT)) & SYSCON_AHBCLKCTRL1_USB0_DEV_MASK)

#define SYSCON_AHBCLKCTRL1_TIMER0_MASK           (0x4000000U)
#define SYSCON_AHBCLKCTRL1_TIMER0_SHIFT          (26U)
/*! TIMER0 - Enables the clock for the Timer 0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_TIMER0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER0_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER0_MASK)

#define SYSCON_AHBCLKCTRL1_TIMER1_MASK           (0x8000000U)
#define SYSCON_AHBCLKCTRL1_TIMER1_SHIFT          (27U)
/*! TIMER1 - Enables the clock for the Timer 1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_TIMER1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER1_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER1_MASK)
/*! @} */

/*! @name AHBCLKCTRL2 - AHB Clock control 2 */
/*! @{ */

#define SYSCON_AHBCLKCTRL2_DMA1_MASK             (0x2U)
#define SYSCON_AHBCLKCTRL2_DMA1_SHIFT            (1U)
/*! DMA1 - Enables the clock for the DMA1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_DMA1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_DMA1_SHIFT)) & SYSCON_AHBCLKCTRL2_DMA1_MASK)

#define SYSCON_AHBCLKCTRL2_COMP_MASK             (0x4U)
#define SYSCON_AHBCLKCTRL2_COMP_SHIFT            (2U)
/*! COMP - Enables the clock for the Analog comparator.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_COMP(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_COMP_SHIFT)) & SYSCON_AHBCLKCTRL2_COMP_MASK)

#define SYSCON_AHBCLKCTRL2_FREQME_MASK           (0x100U)
#define SYSCON_AHBCLKCTRL2_FREQME_SHIFT          (8U)
/*! FREQME - Enables the clock for the Frequency meter.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_FREQME(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_FREQME_SHIFT)) & SYSCON_AHBCLKCTRL2_FREQME_MASK)

#define SYSCON_AHBCLKCTRL2_RNG_MASK              (0x2000U)
#define SYSCON_AHBCLKCTRL2_RNG_SHIFT             (13U)
/*! RNG - Enables the clock for the RNG.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_RNG(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_RNG_SHIFT)) & SYSCON_AHBCLKCTRL2_RNG_MASK)

#define SYSCON_AHBCLKCTRL2_PMUX1_MASK            (0x4000U)
#define SYSCON_AHBCLKCTRL2_PMUX1_SHIFT           (14U)
/*! PMUX1 - Enables the clock for Peripheral Input Mux 1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_PMUX1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PMUX1_SHIFT)) & SYSCON_AHBCLKCTRL2_PMUX1_MASK)

#define SYSCON_AHBCLKCTRL2_SYSCTL_MASK           (0x8000U)
#define SYSCON_AHBCLKCTRL2_SYSCTL_SHIFT          (15U)
/*! SYSCTL - SYSCTL block clock.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_SYSCTL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SYSCTL_SHIFT)) & SYSCON_AHBCLKCTRL2_SYSCTL_MASK)

#define SYSCON_AHBCLKCTRL2_USB0_HOSTM_MASK       (0x10000U)
#define SYSCON_AHBCLKCTRL2_USB0_HOSTM_SHIFT      (16U)
/*! USB0_HOSTM - Enables the clock for the USB0-FS Host Master.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_USB0_HOSTM(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_USB0_HOSTM_SHIFT)) & SYSCON_AHBCLKCTRL2_USB0_HOSTM_MASK)

#define SYSCON_AHBCLKCTRL2_USB0_HOSTS_MASK       (0x20000U)
#define SYSCON_AHBCLKCTRL2_USB0_HOSTS_SHIFT      (17U)
/*! USB0_HOSTS - Enables the clock for the USB0-FS Host Slave.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_USB0_HOSTS(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_USB0_HOSTS_SHIFT)) & SYSCON_AHBCLKCTRL2_USB0_HOSTS_MASK)

#define SYSCON_AHBCLKCTRL2_ELS_MASK              (0x40000U)
#define SYSCON_AHBCLKCTRL2_ELS_SHIFT             (18U)
/*! ELS - Enables the clock for ELS.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_ELS(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_ELS_SHIFT)) & SYSCON_AHBCLKCTRL2_ELS_MASK)

#define SYSCON_AHBCLKCTRL2_PQ_MASK               (0x80000U)
#define SYSCON_AHBCLKCTRL2_PQ_SHIFT              (19U)
/*! PQ - Enables the clock for the Power Quad.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_PQ(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PQ_SHIFT)) & SYSCON_AHBCLKCTRL2_PQ_MASK)

#define SYSCON_AHBCLKCTRL2_TIMER3_MASK           (0x200000U)
#define SYSCON_AHBCLKCTRL2_TIMER3_SHIFT          (21U)
/*! TIMER3 - Enables the clock for the Timer 3.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_TIMER3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_TIMER3_SHIFT)) & SYSCON_AHBCLKCTRL2_TIMER3_MASK)

#define SYSCON_AHBCLKCTRL2_TIMER4_MASK           (0x400000U)
#define SYSCON_AHBCLKCTRL2_TIMER4_SHIFT          (22U)
/*! TIMER4 - Enables the clock for the Timer 4.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_TIMER4(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_TIMER4_SHIFT)) & SYSCON_AHBCLKCTRL2_TIMER4_MASK)

#define SYSCON_AHBCLKCTRL2_PUF_MASK              (0x800000U)
#define SYSCON_AHBCLKCTRL2_PUF_SHIFT             (23U)
/*! PUF - Enables the clock for the PUF reset control.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_PUF(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PUF_SHIFT)) & SYSCON_AHBCLKCTRL2_PUF_MASK)

#define SYSCON_AHBCLKCTRL2_PKC_MASK              (0x1000000U)
#define SYSCON_AHBCLKCTRL2_PKC_SHIFT             (24U)
/*! PKC - Enables the clock for the PKC.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_PKC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PKC_SHIFT)) & SYSCON_AHBCLKCTRL2_PKC_MASK)

#define SYSCON_AHBCLKCTRL2_ANALOG_CTRL_MASK      (0x8000000U)
#define SYSCON_AHBCLKCTRL2_ANALOG_CTRL_SHIFT     (27U)
/*! ANALOG_CTRL - Enables the clock for the Analog Controller block.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_ANALOG_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_ANALOG_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL2_ANALOG_CTRL_MASK)

#define SYSCON_AHBCLKCTRL2_HS_SPI_MASK           (0x10000000U)
#define SYSCON_AHBCLKCTRL2_HS_SPI_SHIFT          (28U)
/*! HS_SPI - Enables the clock for the HS SPI.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_HS_SPI(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_HS_SPI_SHIFT)) & SYSCON_AHBCLKCTRL2_HS_SPI_MASK)

#define SYSCON_AHBCLKCTRL2_GPIO_SEC_MASK         (0x20000000U)
#define SYSCON_AHBCLKCTRL2_GPIO_SEC_SHIFT        (29U)
/*! GPIO_SEC - Enables the clock for the GPIO secure.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_GPIO_SEC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_GPIO_SEC_SHIFT)) & SYSCON_AHBCLKCTRL2_GPIO_SEC_MASK)

#define SYSCON_AHBCLKCTRL2_GPIO_SEC_INT_MASK     (0x40000000U)
#define SYSCON_AHBCLKCTRL2_GPIO_SEC_INT_SHIFT    (30U)
/*! GPIO_SEC_INT - Enables the clock for the GPIO secure int.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_GPIO_SEC_INT(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_GPIO_SEC_INT_SHIFT)) & SYSCON_AHBCLKCTRL2_GPIO_SEC_INT_MASK)
/*! @} */

/*! @name AHBCLKCTRL3 - AHB Clock Control 3 */
/*! @{ */

#define SYSCON_AHBCLKCTRL3_I3C0_MASK             (0x1U)
#define SYSCON_AHBCLKCTRL3_I3C0_SHIFT            (0U)
/*! I3C0 - Enables the clock for I3C0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_I3C0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_I3C0_SHIFT)) & SYSCON_AHBCLKCTRL3_I3C0_MASK)

#define SYSCON_AHBCLKCTRL3_ENC0_MASK             (0x8U)
#define SYSCON_AHBCLKCTRL3_ENC0_SHIFT            (3U)
/*! ENC0 - Enables the clock for ENC0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_ENC0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_ENC0_SHIFT)) & SYSCON_AHBCLKCTRL3_ENC0_MASK)

#define SYSCON_AHBCLKCTRL3_ENC1_MASK             (0x10U)
#define SYSCON_AHBCLKCTRL3_ENC1_SHIFT            (4U)
/*! ENC1 - Enables the clock for ENC1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_ENC1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_ENC1_SHIFT)) & SYSCON_AHBCLKCTRL3_ENC1_MASK)

#define SYSCON_AHBCLKCTRL3_PWM0_MASK             (0x20U)
#define SYSCON_AHBCLKCTRL3_PWM0_SHIFT            (5U)
/*! PWM0 - Enables the clock for PWM0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_PWM0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_PWM0_SHIFT)) & SYSCON_AHBCLKCTRL3_PWM0_MASK)

#define SYSCON_AHBCLKCTRL3_PWM1_MASK             (0x40U)
#define SYSCON_AHBCLKCTRL3_PWM1_SHIFT            (6U)
/*! PWM1 - Enables the clock for PWM1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_PWM1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_PWM1_SHIFT)) & SYSCON_AHBCLKCTRL3_PWM1_MASK)

#define SYSCON_AHBCLKCTRL3_AOI0_MASK             (0x80U)
#define SYSCON_AHBCLKCTRL3_AOI0_SHIFT            (7U)
/*! AOI0 - Enables the clock for AOI0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_AOI0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_AOI0_SHIFT)) & SYSCON_AHBCLKCTRL3_AOI0_MASK)

#define SYSCON_AHBCLKCTRL3_AOI1_MASK             (0x100U)
#define SYSCON_AHBCLKCTRL3_AOI1_SHIFT            (8U)
/*! AOI1 - Enables the clock for AOI1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_AOI1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_AOI1_SHIFT)) & SYSCON_AHBCLKCTRL3_AOI1_MASK)

#define SYSCON_AHBCLKCTRL3_FTM0_MASK             (0x200U)
#define SYSCON_AHBCLKCTRL3_FTM0_SHIFT            (9U)
/*! FTM0 - Enables the clock for FTM0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_FTM0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_FTM0_SHIFT)) & SYSCON_AHBCLKCTRL3_FTM0_MASK)

#define SYSCON_AHBCLKCTRL3_DAC1_MASK             (0x400U)
#define SYSCON_AHBCLKCTRL3_DAC1_SHIFT            (10U)
/*! DAC1 - Enables the clock for DAC1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_DAC1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_DAC1_SHIFT)) & SYSCON_AHBCLKCTRL3_DAC1_MASK)

#define SYSCON_AHBCLKCTRL3_DAC2_MASK             (0x800U)
#define SYSCON_AHBCLKCTRL3_DAC2_SHIFT            (11U)
/*! DAC2 - Enables the clock for DAC2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_DAC2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_DAC2_SHIFT)) & SYSCON_AHBCLKCTRL3_DAC2_MASK)

#define SYSCON_AHBCLKCTRL3_OPAMP0_MASK           (0x1000U)
#define SYSCON_AHBCLKCTRL3_OPAMP0_SHIFT          (12U)
/*! OPAMP0 - Enables the clock for OPAMP0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_OPAMP0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_OPAMP0_SHIFT)) & SYSCON_AHBCLKCTRL3_OPAMP0_MASK)

#define SYSCON_AHBCLKCTRL3_OPAMP1_MASK           (0x2000U)
#define SYSCON_AHBCLKCTRL3_OPAMP1_SHIFT          (13U)
/*! OPAMP1 - Enables the clock for OPAMP1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_OPAMP1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_OPAMP1_SHIFT)) & SYSCON_AHBCLKCTRL3_OPAMP1_MASK)

#define SYSCON_AHBCLKCTRL3_OPAMP2_MASK           (0x4000U)
#define SYSCON_AHBCLKCTRL3_OPAMP2_SHIFT          (14U)
/*! OPAMP2 - Enables the clock for OPAMP2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_OPAMP2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_OPAMP2_SHIFT)) & SYSCON_AHBCLKCTRL3_OPAMP2_MASK)

#define SYSCON_AHBCLKCTRL3_HSCMP0_MASK           (0x8000U)
#define SYSCON_AHBCLKCTRL3_HSCMP0_SHIFT          (15U)
/*! HSCMP0 - Enables the clock for HSCMP0.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_HSCMP0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_HSCMP0_SHIFT)) & SYSCON_AHBCLKCTRL3_HSCMP0_MASK)

#define SYSCON_AHBCLKCTRL3_HSCMP1_MASK           (0x10000U)
#define SYSCON_AHBCLKCTRL3_HSCMP1_SHIFT          (16U)
/*! HSCMP1 - Enables the clock for HSCMP1.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_HSCMP1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_HSCMP1_SHIFT)) & SYSCON_AHBCLKCTRL3_HSCMP1_MASK)

#define SYSCON_AHBCLKCTRL3_HSCMP2_MASK           (0x20000U)
#define SYSCON_AHBCLKCTRL3_HSCMP2_SHIFT          (17U)
/*! HSCMP2 - Enables the clock for HSCMP2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_HSCMP2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_HSCMP2_SHIFT)) & SYSCON_AHBCLKCTRL3_HSCMP2_MASK)

#define SYSCON_AHBCLKCTRL3_VREF_MASK             (0x40000U)
#define SYSCON_AHBCLKCTRL3_VREF_SHIFT            (18U)
/*! VREF - Enables the clock for VREF.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL3_VREF(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL3_VREF_SHIFT)) & SYSCON_AHBCLKCTRL3_VREF_MASK)
/*! @} */

/*! @name AHBCLKCTRLSET - AHB Clock Control Set */
/*! @{ */

#define SYSCON_AHBCLKCTRLSET_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLSET_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_AHBCLKCTRLSET_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLSET_DATA_SHIFT)) & SYSCON_AHBCLKCTRLSET_DATA_MASK)
/*! @} */

/*! @name AHBCLKCTRLCLR - AHB Clock Control Clear */
/*! @{ */

#define SYSCON_AHBCLKCTRLCLR_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLCLR_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_AHBCLKCTRLCLR_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLCLR_DATA_SHIFT)) & SYSCON_AHBCLKCTRLCLR_DATA_MASK)
/*! @} */

/*! @name SYSTICKCLKSEL0 - System Tick Timer for CPU0 source select */
/*! @{ */

#define SYSCON_SYSTICKCLKSEL0_SEL_MASK           (0x7U)
#define SYSCON_SYSTICKCLKSEL0_SEL_SHIFT          (0U)
/*! SEL - System Tick Timer for CPU0 source select.
 *  0b000..System Tick 0 divided clock.
 *  0b001..FRO 1MHz clock.
 *  0b010..Oscillator 32 kHz clock.
 *  0b011..No clock.
 *  0b100..No clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_SYSTICKCLKSEL0_SEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKSEL0_SEL_SHIFT)) & SYSCON_SYSTICKCLKSEL0_SEL_MASK)
/*! @} */

/*! @name TRACECLKSEL - Trace clock source select */
/*! @{ */

#define SYSCON_TRACECLKSEL_SEL_MASK              (0x7U)
#define SYSCON_TRACECLKSEL_SEL_SHIFT             (0U)
/*! SEL - Trace clock source select.
 *  0b000..Trace divided clock.
 *  0b001..FRO 1MHz clock.
 *  0b010..Oscillator 32 kHz clock.
 *  0b011..No clock.
 *  0b100..No clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_TRACECLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKSEL_SEL_SHIFT)) & SYSCON_TRACECLKSEL_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSEL - CTimer 0 clock source select..CTimer 4 clock source select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL_SEL_MASK             (0x7U)
#define SYSCON_CTIMERCLKSEL_SEL_SHIFT            (0U)
/*! SEL - CTimer 4 clock source select.
 *  0b000..Main clock.
 *  0b001..PLL0 clock.
 *  0b010..PLL1 clock.
 *  0b011..FRO 96 MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..MCLK clock.
 *  0b110..Oscillator 32kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_CTIMERCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELA - Main clock source select A */
/*! @{ */

#define SYSCON_MAINCLKSELA_SEL_MASK              (0x7U)
#define SYSCON_MAINCLKSELA_SEL_SHIFT             (0U)
/*! SEL - Main clock source select A
 *  0b000..FRO 12 MHz clock.
 *  0b001..CLKIN clock.
 *  0b010..FRO 1MHz clock.
 *  0b011..FRO 96 MHz clock.
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..Reserved.
 */
#define SYSCON_MAINCLKSELA_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELA_SEL_SHIFT)) & SYSCON_MAINCLKSELA_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELB - Main clock source select B */
/*! @{ */

#define SYSCON_MAINCLKSELB_SEL_MASK              (0x7U)
#define SYSCON_MAINCLKSELB_SEL_SHIFT             (0U)
/*! SEL - Main clock source select B
 *  0b000..Use the source selected in MAINCLKSELA.
 *  0b001..PLL0 clock.
 *  0b010..PLL1 clock.
 *  0b011..Oscillator 32 kHz clock.
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..Reserved.
 */
#define SYSCON_MAINCLKSELB_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELB_SEL_SHIFT)) & SYSCON_MAINCLKSELB_SEL_MASK)
/*! @} */

/*! @name CLKOUTSEL - CLKOUT clock source select */
/*! @{ */

#define SYSCON_CLKOUTSEL_SEL_MASK                (0xFU)
#define SYSCON_CLKOUTSEL_SEL_SHIFT               (0U)
/*! SEL - CLKOUT clock source select.
 *  0b0000..Main clock.
 *  0b0001..PLL0 clock.
 *  0b0010..CLKIN clock.
 *  0b0011..FRO 96 MHz clock.
 *  0b0100..FRO 1MHz clock.
 *  0b0101..PLL1 clock.
 *  0b0110..Oscillator 32kHz clock.
 *  0b0111..No clock.
 *  0b1000..Reserved.
 *  0b1001..Reserved.
 *  0b1010..Reserved.
 *  0b1011..Reserved.
 *  0b1100..No clock.
 *  0b1101..No clock.
 *  0b1110..No clock.
 *  0b1111..No clock.
 */
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSEL_SEL_SHIFT)) & SYSCON_CLKOUTSEL_SEL_MASK)
/*! @} */

/*! @name PLL0CLKSEL - PLL0 clock source select */
/*! @{ */

#define SYSCON_PLL0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_PLL0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - PLL0 clock source select.
 *  0b000..FRO 12 MHz clock.
 *  0b001..CLKIN clock.
 *  0b010..FRO 1MHz clock.
 *  0b011..Oscillator 32kHz clock.
 *  0b100..No clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_PLL0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CLKSEL_SEL_SHIFT)) & SYSCON_PLL0CLKSEL_SEL_MASK)
/*! @} */

/*! @name PLL1CLKSEL - PLL1 clock source select */
/*! @{ */

#define SYSCON_PLL1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_PLL1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - PLL1 clock source select.
 *  0b000..FRO 12 MHz clock.
 *  0b001..CLKIN clock.
 *  0b010..FRO 1MHz clock.
 *  0b011..Oscillator 32kHz clock.
 *  0b100..No clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_PLL1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CLKSEL_SEL_SHIFT)) & SYSCON_PLL1CLKSEL_SEL_MASK)
/*! @} */

/*! @name CANCLKSEL - CAN clock source select */
/*! @{ */

#define SYSCON_CANCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_CANCLKSEL_SEL_SHIFT               (0U)
/*! SEL - CAN clock source select.
 *  0b000..CAN divided clock.
 *  0b001..FRO 1MHz clock.
 *  0b010..Oscillator 32 kHz clock.
 *  0b011..No clock.
 *  0b100..No clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_CANCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CANCLKSEL_SEL_SHIFT)) & SYSCON_CANCLKSEL_SEL_MASK)
/*! @} */

/*! @name ADC0CLKSEL - ADC0 clock source select */
/*! @{ */

#define SYSCON_ADC0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_ADC0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - ADC clock source select.
 *  0b000..Main clock.
 *  0b001..PLL0 clock.
 *  0b010..FRO 96 MHz clock.
 *  0b011..Reserved.
 *  0b100..XO to ADC Clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_ADC0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKSEL_SEL_SHIFT)) & SYSCON_ADC0CLKSEL_SEL_MASK)
/*! @} */

/*! @name USB0CLKSEL - FS USB clock source select */
/*! @{ */

#define SYSCON_USB0CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_USB0CLKSEL_SEL_SHIFT              (0U)
/*! SEL - FS USB clock source select.
 *  0b000..Main clock.
 *  0b001..PLL0 clock.
 *  0b010..No clock.
 *  0b011..FRO 96 MHz clock.
 *  0b100..No clock.
 *  0b101..PLL1 clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_USB0CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKSEL_SEL_SHIFT)) & SYSCON_USB0CLKSEL_SEL_MASK)
/*! @} */

/*! @name FCCLKSEL - Flexcomm 0 clock source select for Fractional Rate Divider..Flexcomm 7 clock source select for Fractional Rate Divider */
/*! @{ */

#define SYSCON_FCCLKSEL_SEL_MASK                 (0x7U)
#define SYSCON_FCCLKSEL_SEL_SHIFT                (0U)
/*! SEL - Flexcomm 7 clock source select for Fractional Rate Divider.
 *  0b000..Main clock.
 *  0b001..system PLL divided clock.
 *  0b010..FRO 12 MHz clock.
 *  0b011..FRO 96 MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..MCLK clock.
 *  0b110..Oscillator 32 kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_FCCLKSEL_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FCCLKSEL_SEL_SHIFT)) & SYSCON_FCCLKSEL_SEL_MASK)
/*! @} */

/*! @name HSSPICLKSEL - HS SPI clock source select */
/*! @{ */

#define SYSCON_HSSPICLKSEL_SEL_MASK              (0x7U)
#define SYSCON_HSSPICLKSEL_SEL_SHIFT             (0U)
/*! SEL - HS SPI clock source select.
 *  0b000..Main clock.
 *  0b001..system PLL divided clock.
 *  0b010..FRO 12 MHz clock.
 *  0b011..FRO 96 MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..No clock.
 *  0b110..Oscillator 32 kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_HSSPICLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_HSSPICLKSEL_SEL_SHIFT)) & SYSCON_HSSPICLKSEL_SEL_MASK)
/*! @} */

/*! @name MCLKCLKSEL - MCLK clock source select */
/*! @{ */

#define SYSCON_MCLKCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_MCLKCLKSEL_SEL_SHIFT              (0U)
/*! SEL - MCLK clock source select.
 *  0b000..FRO 96 MHz clock.
 *  0b001..PLL0 clock.
 *  0b010..Reserved.
 *  0b011..Reserved.
 *  0b100..No clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_MCLKCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKCLKSEL_SEL_SHIFT)) & SYSCON_MCLKCLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTCLKSEL - SCTimer/PWM clock source select */
/*! @{ */

#define SYSCON_SCTCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_SCTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - SCTimer/PWM clock source select.
 *  0b000..Main clock.
 *  0b001..PLL0 clock.
 *  0b010..CLKIN clock.
 *  0b011..FRO 96 MHz clock.
 *  0b100..PLL1 clock.
 *  0b101..MCLK clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_SCTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKSEL_SEL_SHIFT)) & SYSCON_SCTCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV - System Tick Timer divider for CPU0 */
/*! @{ */

#define SYSCON_SYSTICKCLKDIV_DIV_MASK            (0xFFU)
#define SYSCON_SYSTICKCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SYSTICKCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_DIV_SHIFT)) & SYSCON_SYSTICKCLKDIV_DIV_MASK)

#define SYSCON_SYSTICKCLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_SYSTICKCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_SYSTICKCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_RESET_SHIFT)) & SYSCON_SYSTICKCLKDIV_RESET_MASK)

#define SYSCON_SYSTICKCLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_SYSTICKCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_SYSTICKCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_HALT_SHIFT)) & SYSCON_SYSTICKCLKDIV_HALT_MASK)

#define SYSCON_SYSTICKCLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_SYSTICKCLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_SYSTICKCLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV_UNSTAB_SHIFT)) & SYSCON_SYSTICKCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name TRACECLKDIV - TRACE clock divider */
/*! @{ */

#define SYSCON_TRACECLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_TRACECLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value. */
#define SYSCON_TRACECLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_DIV_SHIFT)) & SYSCON_TRACECLKDIV_DIV_MASK)

#define SYSCON_TRACECLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_TRACECLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_TRACECLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_RESET_SHIFT)) & SYSCON_TRACECLKDIV_RESET_MASK)

#define SYSCON_TRACECLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_TRACECLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_TRACECLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_HALT_SHIFT)) & SYSCON_TRACECLKDIV_HALT_MASK)

#define SYSCON_TRACECLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_TRACECLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_TRACECLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_UNSTAB_SHIFT)) & SYSCON_TRACECLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CANCLKDIV - CAN clock divider */
/*! @{ */

#define SYSCON_CANCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_CANCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_CANCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CANCLKDIV_DIV_SHIFT)) & SYSCON_CANCLKDIV_DIV_MASK)

#define SYSCON_CANCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_CANCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_CANCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CANCLKDIV_RESET_SHIFT)) & SYSCON_CANCLKDIV_RESET_MASK)

#define SYSCON_CANCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_CANCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_CANCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CANCLKDIV_HALT_SHIFT)) & SYSCON_CANCLKDIV_HALT_MASK)

#define SYSCON_CANCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_CANCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_CANCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CANCLKDIV_UNSTAB_SHIFT)) & SYSCON_CANCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FRGCTRL - Fractional rate divider for flexcomm 0..Fractional rate divider for flexcomm 7 */
/*! @{ */

#define SYSCON_FRGCTRL_DIV_MASK                  (0xFFU)
#define SYSCON_FRGCTRL_DIV_SHIFT                 (0U)
/*! DIV - Denominator of the fractional rate divider. */
#define SYSCON_FRGCTRL_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FRGCTRL_DIV_SHIFT)) & SYSCON_FRGCTRL_DIV_MASK)

#define SYSCON_FRGCTRL_MULT_MASK                 (0xFF00U)
#define SYSCON_FRGCTRL_MULT_SHIFT                (8U)
/*! MULT - Numerator of the fractional rate divider. */
#define SYSCON_FRGCTRL_MULT(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FRGCTRL_MULT_SHIFT)) & SYSCON_FRGCTRL_MULT_MASK)
/*! @} */

/*! @name AHBCLKDIV - System clock divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)

#define SYSCON_AHBCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_AHBCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_AHBCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_RESET_SHIFT)) & SYSCON_AHBCLKDIV_RESET_MASK)

#define SYSCON_AHBCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_AHBCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_AHBCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_HALT_SHIFT)) & SYSCON_AHBCLKDIV_HALT_MASK)

#define SYSCON_AHBCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_AHBCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_AHBCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_UNSTAB_SHIFT)) & SYSCON_AHBCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_CLKOUTDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_DIV_SHIFT)) & SYSCON_CLKOUTDIV_DIV_MASK)

#define SYSCON_CLKOUTDIV_RESET_MASK              (0x20000000U)
#define SYSCON_CLKOUTDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_CLKOUTDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_RESET_SHIFT)) & SYSCON_CLKOUTDIV_RESET_MASK)

#define SYSCON_CLKOUTDIV_HALT_MASK               (0x40000000U)
#define SYSCON_CLKOUTDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_CLKOUTDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_HALT_SHIFT)) & SYSCON_CLKOUTDIV_HALT_MASK)

#define SYSCON_CLKOUTDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_CLKOUTDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_CLKOUTDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_UNSTAB_SHIFT)) & SYSCON_CLKOUTDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROHFDIV - FRO_HF (96MHz) clock divider */
/*! @{ */

#define SYSCON_FROHFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROHFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value. */
#define SYSCON_FROHFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_DIV_SHIFT)) & SYSCON_FROHFDIV_DIV_MASK)

#define SYSCON_FROHFDIV_RESET_MASK               (0x20000000U)
#define SYSCON_FROHFDIV_RESET_SHIFT              (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_FROHFDIV_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_RESET_SHIFT)) & SYSCON_FROHFDIV_RESET_MASK)

#define SYSCON_FROHFDIV_HALT_MASK                (0x40000000U)
#define SYSCON_FROHFDIV_HALT_SHIFT               (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_FROHFDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_HALT_SHIFT)) & SYSCON_FROHFDIV_HALT_MASK)

#define SYSCON_FROHFDIV_UNSTAB_MASK              (0x80000000U)
#define SYSCON_FROHFDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_FROHFDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_UNSTAB_SHIFT)) & SYSCON_FROHFDIV_UNSTAB_MASK)
/*! @} */

/*! @name WDTCLKDIV - WDT clock divider */
/*! @{ */

#define SYSCON_WDTCLKDIV_DIV_MASK                (0x3FU)
#define SYSCON_WDTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_WDTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKDIV_DIV_SHIFT)) & SYSCON_WDTCLKDIV_DIV_MASK)

#define SYSCON_WDTCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_WDTCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_WDTCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKDIV_RESET_SHIFT)) & SYSCON_WDTCLKDIV_RESET_MASK)

#define SYSCON_WDTCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_WDTCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_WDTCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKDIV_HALT_SHIFT)) & SYSCON_WDTCLKDIV_HALT_MASK)

#define SYSCON_WDTCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_WDTCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_WDTCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKDIV_UNSTAB_SHIFT)) & SYSCON_WDTCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name ADC0CLKDIV - ADC0 clock divider */
/*! @{ */

#define SYSCON_ADC0CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_ADC0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_ADC0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_DIV_SHIFT)) & SYSCON_ADC0CLKDIV_DIV_MASK)

#define SYSCON_ADC0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_ADC0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_ADC0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_RESET_SHIFT)) & SYSCON_ADC0CLKDIV_RESET_MASK)

#define SYSCON_ADC0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_ADC0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_ADC0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_HALT_SHIFT)) & SYSCON_ADC0CLKDIV_HALT_MASK)

#define SYSCON_ADC0CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_ADC0CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_ADC0CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC0CLKDIV_UNSTAB_SHIFT)) & SYSCON_ADC0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name USB0CLKDIV - USB0-FS Clock divider */
/*! @{ */

#define SYSCON_USB0CLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_USB0CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_USB0CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_DIV_SHIFT)) & SYSCON_USB0CLKDIV_DIV_MASK)

#define SYSCON_USB0CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_USB0CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_USB0CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_RESET_SHIFT)) & SYSCON_USB0CLKDIV_RESET_MASK)

#define SYSCON_USB0CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_USB0CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_USB0CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_HALT_SHIFT)) & SYSCON_USB0CLKDIV_HALT_MASK)

#define SYSCON_USB0CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_USB0CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_USB0CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0CLKDIV_UNSTAB_SHIFT)) & SYSCON_USB0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MCLKDIV - I2S MCLK clock divider */
/*! @{ */

#define SYSCON_MCLKDIV_DIV_MASK                  (0xFFU)
#define SYSCON_MCLKDIV_DIV_SHIFT                 (0U)
/*! DIV - Clock divider value. */
#define SYSCON_MCLKDIV_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_DIV_SHIFT)) & SYSCON_MCLKDIV_DIV_MASK)

#define SYSCON_MCLKDIV_RESET_MASK                (0x20000000U)
#define SYSCON_MCLKDIV_RESET_SHIFT               (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_MCLKDIV_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_RESET_SHIFT)) & SYSCON_MCLKDIV_RESET_MASK)

#define SYSCON_MCLKDIV_HALT_MASK                 (0x40000000U)
#define SYSCON_MCLKDIV_HALT_SHIFT                (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_MCLKDIV_HALT(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_HALT_SHIFT)) & SYSCON_MCLKDIV_HALT_MASK)

#define SYSCON_MCLKDIV_UNSTAB_MASK               (0x80000000U)
#define SYSCON_MCLKDIV_UNSTAB_SHIFT              (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_MCLKDIV_UNSTAB(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKDIV_UNSTAB_SHIFT)) & SYSCON_MCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name SCTCLKDIV - SCT/PWM clock divider */
/*! @{ */

#define SYSCON_SCTCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SCTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_SCTCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_DIV_SHIFT)) & SYSCON_SCTCLKDIV_DIV_MASK)

#define SYSCON_SCTCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_SCTCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_SCTCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_RESET_SHIFT)) & SYSCON_SCTCLKDIV_RESET_MASK)

#define SYSCON_SCTCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_SCTCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_SCTCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_HALT_SHIFT)) & SYSCON_SCTCLKDIV_HALT_MASK)

#define SYSCON_SCTCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_SCTCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_SCTCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_UNSTAB_SHIFT)) & SYSCON_SCTCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name PLLCLKDIV - PLL clock divider */
/*! @{ */

#define SYSCON_PLLCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_PLLCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value. */
#define SYSCON_PLLCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_DIV_SHIFT)) & SYSCON_PLLCLKDIV_DIV_MASK)

#define SYSCON_PLLCLKDIV_RESET_MASK              (0x20000000U)
#define SYSCON_PLLCLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_PLLCLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_RESET_SHIFT)) & SYSCON_PLLCLKDIV_RESET_MASK)

#define SYSCON_PLLCLKDIV_HALT_MASK               (0x40000000U)
#define SYSCON_PLLCLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_PLLCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_HALT_SHIFT)) & SYSCON_PLLCLKDIV_HALT_MASK)

#define SYSCON_PLLCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_PLLCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_PLLCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIV_UNSTAB_SHIFT)) & SYSCON_PLLCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CTIMERXCLKDIV_CTIMERCLKDIV - CTimer 0 clock divider..CTimer 4 clock divider */
/*! @{ */

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_MASK (0xFFU)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_SHIFT (0U)
/*! DIV - Clock divider value */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_DIV_MASK)

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_MASK (0x20000000U)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_SHIFT (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_RESET_MASK)

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_MASK (0x40000000U)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_SHIFT (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running.
 *  0b1..Divider clock has stopped.
 */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_HALT_MASK)

#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_MASK (0x80000000U)
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_SHIFT (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Stable divider clock.
 *  0b1..Unstable clock frequency.
 */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_SHIFT)) & SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_UNSTAB_MASK)
/*! @} */

/* The count of SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV */
#define SYSCON_CTIMERXCLKDIV_CTIMERCLKDIV_COUNT  (5U)

/*! @name CLKUNLOCK - Clock configuration unlock */
/*! @{ */

#define SYSCON_CLKUNLOCK_UNLOCK_MASK             (0xFFFFFFFFU)
#define SYSCON_CLKUNLOCK_UNLOCK_SHIFT            (0U)
/*! UNLOCK - Control clock configuration registers access (for example, xxxDIV, xxxSEL).
 *  0b00000000000000000000000000000000..All hardware clock configruration are freeze.
 *  0b00000000000000000000000000000001..Update all clock configuration.
 */
#define SYSCON_CLKUNLOCK_UNLOCK(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKUNLOCK_UNLOCK_SHIFT)) & SYSCON_CLKUNLOCK_UNLOCK_MASK)
/*! @} */

/*! @name FMCCR - FMC configuration */
/*! @{ */

#define SYSCON_FMCCR_FETCHCFG_MASK               (0x3U)
#define SYSCON_FMCCR_FETCHCFG_SHIFT              (0U)
/*! FETCHCFG - Instruction fetch configuration.
 *  0b00..Instruction fetches from flash are not buffered.
 *  0b01..One buffer is used for all instruction fetches.
 *  0b10..All buffers may be used for instruction fetches.
 */
#define SYSCON_FMCCR_FETCHCFG(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_FETCHCFG_SHIFT)) & SYSCON_FMCCR_FETCHCFG_MASK)

#define SYSCON_FMCCR_DATACFG_MASK                (0xCU)
#define SYSCON_FMCCR_DATACFG_SHIFT               (2U)
/*! DATACFG - Data read configuration.
 *  0b00..Data accesses from flash are not buffered.
 *  0b01..One buffer is used for all data accesses.
 *  0b10..All buffers can be used for data accesses.
 */
#define SYSCON_FMCCR_DATACFG(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_DATACFG_SHIFT)) & SYSCON_FMCCR_DATACFG_MASK)

#define SYSCON_FMCCR_ACCEL_MASK                  (0x10U)
#define SYSCON_FMCCR_ACCEL_SHIFT                 (4U)
/*! ACCEL - Acceleration enable.
 *  0b0..Flash acceleration is disabled.
 *  0b1..Flash acceleration is enabled.
 */
#define SYSCON_FMCCR_ACCEL(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_ACCEL_SHIFT)) & SYSCON_FMCCR_ACCEL_MASK)

#define SYSCON_FMCCR_PREFEN_MASK                 (0x20U)
#define SYSCON_FMCCR_PREFEN_SHIFT                (5U)
/*! PREFEN - Prefetch enable.
 *  0b0..No instruction prefetch is performed.
 *  0b1..Instruction prefetch is enabled.
 */
#define SYSCON_FMCCR_PREFEN(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_PREFEN_SHIFT)) & SYSCON_FMCCR_PREFEN_MASK)

#define SYSCON_FMCCR_PREFOVR_MASK                (0x40U)
#define SYSCON_FMCCR_PREFOVR_SHIFT               (6U)
/*! PREFOVR - Prefetch override.
 *  0b0..Any previously initiated prefetch will be completed.
 *  0b1..Any previously initiated prefetch will be aborted, and the next flash line following the current
 *       execution address will be prefetched if not already buffered.
 */
#define SYSCON_FMCCR_PREFOVR(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_PREFOVR_SHIFT)) & SYSCON_FMCCR_PREFOVR_MASK)

#define SYSCON_FMCCR_FLASHTIM_MASK               (0xF000U)
#define SYSCON_FMCCR_FLASHTIM_SHIFT              (12U)
/*! FLASHTIM - Flash memory access time.
 *  0b0000..1 system clock flash access time (for system clock rates up to 11 MHz).
 *  0b0001..2 system clocks flash access time (for system clock rates up to 22 MHz).
 *  0b0010..3 system clocks flash access time (for system clock rates up to 33 MHz).
 *  0b0011..4 system clocks flash access time (for system clock rates up to 44 MHz).
 *  0b0100..5 system clocks flash access time (for system clock rates up to 55 MHz).
 *  0b0101..6 system clocks flash access time (for system clock rates up to 66 MHz).
 *  0b0110..7 system clocks flash access time (for system clock rates up to 77 MHz).
 *  0b0111..8 system clocks flash access time (for system clock rates up to 88 MHz).
 *  0b1000..9 system clocks flash access time (for system clock rates up to 100 MHz).
 *  0b1001..10 system clocks flash access time (for system clock rates up to 115 MHz).
 *  0b1010..11 system clocks flash access time (for system clock rates up to 130 MHz).
 *  0b1011..12 system clocks flash access time (for system clock rates up to 150 MHz).
 */
#define SYSCON_FMCCR_FLASHTIM(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_FLASHTIM_SHIFT)) & SYSCON_FMCCR_FLASHTIM_MASK)

#define SYSCON_FMCCR_ECCABORTEN_MASK             (0x300000U)
#define SYSCON_FMCCR_ECCABORTEN_SHIFT            (20U)
/*! ECCABORTEN - ECC error abort enable */
#define SYSCON_FMCCR_ECCABORTEN(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_ECCABORTEN_SHIFT)) & SYSCON_FMCCR_ECCABORTEN_MASK)

#define SYSCON_FMCCR_CLKDIV_MASK                 (0xC000000U)
#define SYSCON_FMCCR_CLKDIV_SHIFT                (26U)
/*! CLKDIV - CLKDIV; default value is 00.
 *  0b00..1 division
 *  0b01..2 division
 *  0b10..3 division
 *  0b11..4 division
 */
#define SYSCON_FMCCR_CLKDIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCCR_CLKDIV_SHIFT)) & SYSCON_FMCCR_CLKDIV_MASK)
/*! @} */

/*! @name ROMCR - ROM wait state */
/*! @{ */

#define SYSCON_ROMCR_ROM_WAIT_MASK               (0x1U)
#define SYSCON_ROMCR_ROM_WAIT_SHIFT              (0U)
/*! ROM_WAIT - ROM waiting Arm core and other masters. */
#define SYSCON_ROMCR_ROM_WAIT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ROMCR_ROM_WAIT_SHIFT)) & SYSCON_ROMCR_ROM_WAIT_MASK)
/*! @} */

/*! @name USB0NEEDCLKCTRL - USB0-FS need clock control */
/*! @{ */

#define SYSCON_USB0NEEDCLKCTRL_AP_FS_DEV_NEEDCLK_MASK (0x1U)
#define SYSCON_USB0NEEDCLKCTRL_AP_FS_DEV_NEEDCLK_SHIFT (0U)
/*! AP_FS_DEV_NEEDCLK - USB0-FS Device USB0_NEEDCLK signal control:.
 *  0b0..Under hardware control.
 *  0b1..Forced high.
 */
#define SYSCON_USB0NEEDCLKCTRL_AP_FS_DEV_NEEDCLK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0NEEDCLKCTRL_AP_FS_DEV_NEEDCLK_SHIFT)) & SYSCON_USB0NEEDCLKCTRL_AP_FS_DEV_NEEDCLK_MASK)

#define SYSCON_USB0NEEDCLKCTRL_POL_FS_DEV_NEEDCLK_MASK (0x2U)
#define SYSCON_USB0NEEDCLKCTRL_POL_FS_DEV_NEEDCLK_SHIFT (1U)
/*! POL_FS_DEV_NEEDCLK - USB0-FS Device USB0_NEEDCLK polarity for triggering the USB0-FS wake-up interrupt:.
 *  0b0..Falling edge of device USB0_NEEDCLK triggers wake-up.
 *  0b1..Rising edge of device USB0_NEEDCLK triggers wake-up.
 */
#define SYSCON_USB0NEEDCLKCTRL_POL_FS_DEV_NEEDCLK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0NEEDCLKCTRL_POL_FS_DEV_NEEDCLK_SHIFT)) & SYSCON_USB0NEEDCLKCTRL_POL_FS_DEV_NEEDCLK_MASK)

#define SYSCON_USB0NEEDCLKCTRL_AP_FS_HOST_NEEDCLK_MASK (0x4U)
#define SYSCON_USB0NEEDCLKCTRL_AP_FS_HOST_NEEDCLK_SHIFT (2U)
/*! AP_FS_HOST_NEEDCLK - USB0-FS Host USB0_NEEDCLK signal control:.
 *  0b0..Under hardware control.
 *  0b1..Forced high.
 */
#define SYSCON_USB0NEEDCLKCTRL_AP_FS_HOST_NEEDCLK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0NEEDCLKCTRL_AP_FS_HOST_NEEDCLK_SHIFT)) & SYSCON_USB0NEEDCLKCTRL_AP_FS_HOST_NEEDCLK_MASK)

#define SYSCON_USB0NEEDCLKCTRL_POL_FS_HOST_NEEDCLK_MASK (0x8U)
#define SYSCON_USB0NEEDCLKCTRL_POL_FS_HOST_NEEDCLK_SHIFT (3U)
/*! POL_FS_HOST_NEEDCLK - USB0-FS Host USB0_NEEDCLK polarity for triggering the USB0-FS wake-up interrupt:.
 *  0b0..Falling edge of device USB0_NEEDCLK triggers wake-up.
 *  0b1..Rising edge of device USB0_NEEDCLK triggers wake-up.
 */
#define SYSCON_USB0NEEDCLKCTRL_POL_FS_HOST_NEEDCLK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0NEEDCLKCTRL_POL_FS_HOST_NEEDCLK_SHIFT)) & SYSCON_USB0NEEDCLKCTRL_POL_FS_HOST_NEEDCLK_MASK)
/*! @} */

/*! @name USB0NEEDCLKSTAT - USB0-FS need clock status */
/*! @{ */

#define SYSCON_USB0NEEDCLKSTAT_DEV_NEEDCLK_MASK  (0x1U)
#define SYSCON_USB0NEEDCLKSTAT_DEV_NEEDCLK_SHIFT (0U)
/*! DEV_NEEDCLK - USB0-FS Device USB0_NEEDCLK signal status:.
 *  0b0..USB0-FS Device clock is low.
 *  0b1..USB0-FS Device clock is high.
 */
#define SYSCON_USB0NEEDCLKSTAT_DEV_NEEDCLK(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0NEEDCLKSTAT_DEV_NEEDCLK_SHIFT)) & SYSCON_USB0NEEDCLKSTAT_DEV_NEEDCLK_MASK)

#define SYSCON_USB0NEEDCLKSTAT_HOST_NEEDCLK_MASK (0x2U)
#define SYSCON_USB0NEEDCLKSTAT_HOST_NEEDCLK_SHIFT (1U)
/*! HOST_NEEDCLK - USB0-FS Host USB0_NEEDCLK signal status:.
 *  0b0..USB0-FS Host clock is low.
 *  0b1..USB0-FS Host clock is high.
 */
#define SYSCON_USB0NEEDCLKSTAT_HOST_NEEDCLK(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_USB0NEEDCLKSTAT_HOST_NEEDCLK_SHIFT)) & SYSCON_USB0NEEDCLKSTAT_HOST_NEEDCLK_MASK)
/*! @} */

/*! @name FMCFLUSH - FMC flush control */
/*! @{ */

#define SYSCON_FMCFLUSH_FLUSH_MASK               (0x1U)
#define SYSCON_FMCFLUSH_FLUSH_SHIFT              (0U)
/*! FLUSH - Flush control
 *  0b0..No action.
 *  0b1..Flush the FMC buffer contents.
 */
#define SYSCON_FMCFLUSH_FLUSH(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FMCFLUSH_FLUSH_SHIFT)) & SYSCON_FMCFLUSH_FLUSH_MASK)
/*! @} */

/*! @name MCLKIO - MCLK control */
/*! @{ */

#define SYSCON_MCLKIO_MCLKIO_MASK                (0x1U)
#define SYSCON_MCLKIO_MCLKIO_SHIFT               (0U)
/*! MCLKIO - MCLK control.
 *  0b0..input mode.
 *  0b1..output mode.
 */
#define SYSCON_MCLKIO_MCLKIO(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_MCLKIO_MCLKIO_SHIFT)) & SYSCON_MCLKIO_MCLKIO_MASK)
/*! @} */

/*! @name ADC1CLKSEL - ADC1 clock source select */
/*! @{ */

#define SYSCON_ADC1CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_ADC1CLKSEL_SEL_SHIFT              (0U)
/*! SEL - ADC clock source select.
 *  0b000..Main clock.
 *  0b001..PLL0 clock.
 *  0b010..FRO 96 MHz clock.
 *  0b011..Reserved.
 *  0b100..XO to ADC clock.
 *  0b101..No clock.
 *  0b110..No clock.
 *  0b111..No clock.
 */
#define SYSCON_ADC1CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKSEL_SEL_SHIFT)) & SYSCON_ADC1CLKSEL_SEL_MASK)
/*! @} */

/*! @name ADC1CLKDIV - ADC1 clock divider */
/*! @{ */

#define SYSCON_ADC1CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_ADC1CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_ADC1CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_DIV_SHIFT)) & SYSCON_ADC1CLKDIV_DIV_MASK)

#define SYSCON_ADC1CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_ADC1CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_ADC1CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_RESET_SHIFT)) & SYSCON_ADC1CLKDIV_RESET_MASK)

#define SYSCON_ADC1CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_ADC1CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_ADC1CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_HALT_SHIFT)) & SYSCON_ADC1CLKDIV_HALT_MASK)

#define SYSCON_ADC1CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_ADC1CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_ADC1CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ADC1CLKDIV_UNSTAB_SHIFT)) & SYSCON_ADC1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name RAM_INTERLEAVE - Control RAM interleave integration */
/*! @{ */

#define SYSCON_RAM_INTERLEAVE_INTERLEAVE_MASK    (0x1U)
#define SYSCON_RAM_INTERLEAVE_INTERLEAVE_SHIFT   (0U)
/*! INTERLEAVE - Control RAM access for RAM_02 and RAM_03.
 *  0b0..RAM access to RAM_02 and RAM_03 is consecutive.
 *  0b1..RAM access to RAM_02 and RAM_03 is interleaved. This setting is need for PKC L0 memory access.
 */
#define SYSCON_RAM_INTERLEAVE_INTERLEAVE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_INTERLEAVE_INTERLEAVE_SHIFT)) & SYSCON_RAM_INTERLEAVE_INTERLEAVE_MASK)
/*! @} */

/*! @name DAC_CLKSEL - DAC0 functional clock selection..DAC2 functional clock selection */
/*! @{ */

#define SYSCON_DAC_CLKSEL_SEL_MASK               (0x7U)
#define SYSCON_DAC_CLKSEL_SEL_SHIFT              (0U)
/*! SEL - DAC clock source select.
 *  0b000..Main clock.
 *  0b001..PLL0 clock.
 *  0b010..No clock.
 *  0b011..FRO_HF.
 *  0b100..FRO_12M.
 *  0b101..PLL1 clock.
 *  0b110..FRO_1M.
 *  0b111..No clock.
 */
#define SYSCON_DAC_CLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKSEL_SEL_SHIFT)) & SYSCON_DAC_CLKSEL_SEL_MASK)
/*! @} */

/* The count of SYSCON_DAC_CLKSEL */
#define SYSCON_DAC_CLKSEL_COUNT                  (3U)

/*! @name DAC_CLKDIV - DAC0 functional clock divider..DAC2 functional clock divider */
/*! @{ */

#define SYSCON_DAC_CLKDIV_DIV_MASK               (0x7U)
#define SYSCON_DAC_CLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_DAC_CLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_DIV_SHIFT)) & SYSCON_DAC_CLKDIV_DIV_MASK)

#define SYSCON_DAC_CLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_DAC_CLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_DAC_CLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_RESET_SHIFT)) & SYSCON_DAC_CLKDIV_RESET_MASK)

#define SYSCON_DAC_CLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_DAC_CLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_DAC_CLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_HALT_SHIFT)) & SYSCON_DAC_CLKDIV_HALT_MASK)

#define SYSCON_DAC_CLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_DAC_CLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_DAC_CLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_CLKDIV_UNSTAB_SHIFT)) & SYSCON_DAC_CLKDIV_UNSTAB_MASK)
/*! @} */

/* The count of SYSCON_DAC_CLKDIV */
#define SYSCON_DAC_CLKDIV_COUNT                  (3U)

/*! @name FLEXSPICLKSEL - FLEXSPI clock selection */
/*! @{ */

#define SYSCON_FLEXSPICLKSEL_SEL_MASK            (0xFU)
#define SYSCON_FLEXSPICLKSEL_SEL_SHIFT           (0U)
/*! SEL - Flexspi clock select
 *  0b0000..Main clock
 *  0b0001..PLL0 clock
 *  0b0010..No clock
 *  0b0011..FRO_HF
 *  0b0100..No clock
 *  0b0101..PLL1 clock
 *  0b0110..No clock
 *  0b0111..No clock
 *  0b1000..No clock
 *  0b1001..No clock
 *  0b1010..No clock
 *  0b1011..No clock
 *  0b1100..No clock
 *  0b1101..No clock
 *  0b1110..No clock
 *  0b1111..No clock
 */
#define SYSCON_FLEXSPICLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKSEL_SEL_SHIFT)) & SYSCON_FLEXSPICLKSEL_SEL_MASK)
/*! @} */

/*! @name FLEXSPICLKDIV - FLEXSPI clock divider */
/*! @{ */

#define SYSCON_FLEXSPICLKDIV_DIV_MASK            (0x7U)
#define SYSCON_FLEXSPICLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value. */
#define SYSCON_FLEXSPICLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_DIV_SHIFT)) & SYSCON_FLEXSPICLKDIV_DIV_MASK)

#define SYSCON_FLEXSPICLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_FLEXSPICLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_FLEXSPICLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_RESET_SHIFT)) & SYSCON_FLEXSPICLKDIV_RESET_MASK)

#define SYSCON_FLEXSPICLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_FLEXSPICLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_FLEXSPICLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_HALT_SHIFT)) & SYSCON_FLEXSPICLKDIV_HALT_MASK)

#define SYSCON_FLEXSPICLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_FLEXSPICLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_FLEXSPICLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXSPICLKDIV_UNSTAB_SHIFT)) & SYSCON_FLEXSPICLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CDPA_ENABLE - Enable protection */
/*! @{ */

#define SYSCON_CDPA_ENABLE_CDPA_ENABLE_MASK      (0x3U)
#define SYSCON_CDPA_ENABLE_CDPA_ENABLE_SHIFT     (0U)
/*! CDPA_ENABLE - Enable control */
#define SYSCON_CDPA_ENABLE_CDPA_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_CDPA_ENABLE_CDPA_ENABLE_SHIFT)) & SYSCON_CDPA_ENABLE_CDPA_ENABLE_MASK)
/*! @} */

/*! @name CDPA_ENABLE_DP - Enable protection duplicate */
/*! @{ */

#define SYSCON_CDPA_ENABLE_DP_CDPA_ENABLE_DP_MASK (0x3U)
#define SYSCON_CDPA_ENABLE_DP_CDPA_ENABLE_DP_SHIFT (0U)
/*! CDPA_ENABLE_DP - Enable control */
#define SYSCON_CDPA_ENABLE_DP_CDPA_ENABLE_DP(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CDPA_ENABLE_DP_CDPA_ENABLE_DP_SHIFT)) & SYSCON_CDPA_ENABLE_DP_CDPA_ENABLE_DP_MASK)
/*! @} */

/*! @name CDPA_CONFIG - CDPA base address */
/*! @{ */

#define SYSCON_CDPA_CONFIG_CDPA_START_PAGE_MASK  (0x1FFU)
#define SYSCON_CDPA_CONFIG_CDPA_START_PAGE_SHIFT (0U)
/*! CDPA_START_PAGE - Specifies the starting page number of CDPA. */
#define SYSCON_CDPA_CONFIG_CDPA_START_PAGE(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_CDPA_CONFIG_CDPA_START_PAGE_SHIFT)) & SYSCON_CDPA_CONFIG_CDPA_START_PAGE_MASK)

#define SYSCON_CDPA_CONFIG_CDPA_SIZE_MASK        (0x1FF0000U)
#define SYSCON_CDPA_CONFIG_CDPA_SIZE_SHIFT       (16U)
/*! CDPA_SIZE - Specifies the size of CDPA in number of pages. */
#define SYSCON_CDPA_CONFIG_CDPA_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CDPA_CONFIG_CDPA_SIZE_SHIFT)) & SYSCON_CDPA_CONFIG_CDPA_SIZE_MASK)
/*! @} */

/*! @name FLASH_HIDING_LOCKOUT_ADDR - Flash hiding lockout address */
/*! @{ */

#define SYSCON_FLASH_HIDING_LOCKOUT_ADDR_flash_hiding_lockout_addr_MASK (0xFFFFFFFFU)
#define SYSCON_FLASH_HIDING_LOCKOUT_ADDR_flash_hiding_lockout_addr_SHIFT (0U)
/*! flash_hiding_lockout_addr - while flash hiding is disabled, register write is locked. */
#define SYSCON_FLASH_HIDING_LOCKOUT_ADDR_flash_hiding_lockout_addr(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_HIDING_LOCKOUT_ADDR_flash_hiding_lockout_addr_SHIFT)) & SYSCON_FLASH_HIDING_LOCKOUT_ADDR_flash_hiding_lockout_addr_MASK)
/*! @} */

/*! @name FLASH_HIDING_BASE_ADDR - Flash hiding base address */
/*! @{ */

#define SYSCON_FLASH_HIDING_BASE_ADDR_flash_hiding_base_addr_MASK (0x3FFFFU)
#define SYSCON_FLASH_HIDING_BASE_ADDR_flash_hiding_base_addr_SHIFT (0U)
/*! flash_hiding_base_addr - Base address for flash hiding */
#define SYSCON_FLASH_HIDING_BASE_ADDR_flash_hiding_base_addr(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_HIDING_BASE_ADDR_flash_hiding_base_addr_SHIFT)) & SYSCON_FLASH_HIDING_BASE_ADDR_flash_hiding_base_addr_MASK)
/*! @} */

/*! @name FLASH_HIDING_BASE_DP_ADDR - Flash hiding base DP address */
/*! @{ */

#define SYSCON_FLASH_HIDING_BASE_DP_ADDR_flash_hiding_base_addr_MASK (0x3FFFFU)
#define SYSCON_FLASH_HIDING_BASE_DP_ADDR_flash_hiding_base_addr_SHIFT (0U)
/*! flash_hiding_base_addr - Base address for flash hiding */
#define SYSCON_FLASH_HIDING_BASE_DP_ADDR_flash_hiding_base_addr(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_HIDING_BASE_DP_ADDR_flash_hiding_base_addr_SHIFT)) & SYSCON_FLASH_HIDING_BASE_DP_ADDR_flash_hiding_base_addr_MASK)
/*! @} */

/*! @name FLASH_HIDING_SIZE_ADDR - Hiding size address */
/*! @{ */

#define SYSCON_FLASH_HIDING_SIZE_ADDR_flash_hiding_size_addr_MASK (0x3FFFFU)
#define SYSCON_FLASH_HIDING_SIZE_ADDR_flash_hiding_size_addr_SHIFT (0U)
/*! flash_hiding_size_addr - Size address for flash hiding */
#define SYSCON_FLASH_HIDING_SIZE_ADDR_flash_hiding_size_addr(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_HIDING_SIZE_ADDR_flash_hiding_size_addr_SHIFT)) & SYSCON_FLASH_HIDING_SIZE_ADDR_flash_hiding_size_addr_MASK)
/*! @} */

/*! @name FLASH_HIDING_SIZE_DP_ADDR - Hiding size DP address */
/*! @{ */

#define SYSCON_FLASH_HIDING_SIZE_DP_ADDR_flash_hiding_size_dp_addr_MASK (0x3FFFFU)
#define SYSCON_FLASH_HIDING_SIZE_DP_ADDR_flash_hiding_size_dp_addr_SHIFT (0U)
/*! flash_hiding_size_dp_addr - Size address for flash hiding */
#define SYSCON_FLASH_HIDING_SIZE_DP_ADDR_flash_hiding_size_dp_addr(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_HIDING_SIZE_DP_ADDR_flash_hiding_size_dp_addr_SHIFT)) & SYSCON_FLASH_HIDING_SIZE_DP_ADDR_flash_hiding_size_dp_addr_MASK)
/*! @} */

/*! @name PLLCLKDIVSEL - PLL clock divider clock selection */
/*! @{ */

#define SYSCON_PLLCLKDIVSEL_SEL_MASK             (0x7U)
#define SYSCON_PLLCLKDIVSEL_SEL_SHIFT            (0U)
/*! SEL - Flexspi clock select
 *  0b000..PLL0 clock
 *  0b001..PLL1 clock
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_PLLCLKDIVSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLLCLKDIVSEL_SEL_SHIFT)) & SYSCON_PLLCLKDIVSEL_SEL_MASK)
/*! @} */

/*! @name I3CFCLKSEL - I3C functional clock selection */
/*! @{ */

#define SYSCON_I3CFCLKSEL_SEL_MASK               (0x7U)
#define SYSCON_I3CFCLKSEL_SEL_SHIFT              (0U)
/*! SEL - I3C clock select
 *  0b000..Main clock
 *  0b001..FRO_HF_DIV
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3CFCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSEL_SEL_SHIFT)) & SYSCON_I3CFCLKSEL_SEL_MASK)
/*! @} */

/*! @name I3CFCLKSTCSEL - I3C FCLK_STC clock selection */
/*! @{ */

#define SYSCON_I3CFCLKSTCSEL_SEL_MASK            (0x7U)
#define SYSCON_I3CFCLKSTCSEL_SEL_SHIFT           (0U)
/*! SEL - I3C FCLK_STC clock select
 *  0b000..I3CFCLK
 *  0b001..FRO_1M
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3CFCLKSTCSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSTCSEL_SEL_SHIFT)) & SYSCON_I3CFCLKSTCSEL_SEL_MASK)
/*! @} */

/*! @name I3CFCLKSTCDIV - I3C FCLK_STC clock divider */
/*! @{ */

#define SYSCON_I3CFCLKSTCDIV_DIV_MASK            (0x7U)
#define SYSCON_I3CFCLKSTCDIV_DIV_SHIFT           (0U)
/*! DIV - Clock divider value. */
#define SYSCON_I3CFCLKSTCDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSTCDIV_DIV_SHIFT)) & SYSCON_I3CFCLKSTCDIV_DIV_MASK)

#define SYSCON_I3CFCLKSTCDIV_RESET_MASK          (0x20000000U)
#define SYSCON_I3CFCLKSTCDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_I3CFCLKSTCDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSTCDIV_RESET_SHIFT)) & SYSCON_I3CFCLKSTCDIV_RESET_MASK)

#define SYSCON_I3CFCLKSTCDIV_HALT_MASK           (0x40000000U)
#define SYSCON_I3CFCLKSTCDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_I3CFCLKSTCDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSTCDIV_HALT_SHIFT)) & SYSCON_I3CFCLKSTCDIV_HALT_MASK)

#define SYSCON_I3CFCLKSTCDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_I3CFCLKSTCDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_I3CFCLKSTCDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSTCDIV_UNSTAB_SHIFT)) & SYSCON_I3CFCLKSTCDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3CFCLKSDIV - I3C FCLKS clock divider */
/*! @{ */

#define SYSCON_I3CFCLKSDIV_DIV_MASK              (0x7U)
#define SYSCON_I3CFCLKSDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value. */
#define SYSCON_I3CFCLKSDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSDIV_DIV_SHIFT)) & SYSCON_I3CFCLKSDIV_DIV_MASK)

#define SYSCON_I3CFCLKSDIV_RESET_MASK            (0x20000000U)
#define SYSCON_I3CFCLKSDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_I3CFCLKSDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSDIV_RESET_SHIFT)) & SYSCON_I3CFCLKSDIV_RESET_MASK)

#define SYSCON_I3CFCLKSDIV_HALT_MASK             (0x40000000U)
#define SYSCON_I3CFCLKSDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_I3CFCLKSDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSDIV_HALT_SHIFT)) & SYSCON_I3CFCLKSDIV_HALT_MASK)

#define SYSCON_I3CFCLKSDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_I3CFCLKSDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_I3CFCLKSDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSDIV_UNSTAB_SHIFT)) & SYSCON_I3CFCLKSDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3CFCLKDIV - I3C FCLK divider */
/*! @{ */

#define SYSCON_I3CFCLKDIV_DIV_MASK               (0x7U)
#define SYSCON_I3CFCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value. */
#define SYSCON_I3CFCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKDIV_DIV_SHIFT)) & SYSCON_I3CFCLKDIV_DIV_MASK)

#define SYSCON_I3CFCLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_I3CFCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_I3CFCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKDIV_RESET_SHIFT)) & SYSCON_I3CFCLKDIV_RESET_MASK)

#define SYSCON_I3CFCLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_I3CFCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_I3CFCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKDIV_HALT_SHIFT)) & SYSCON_I3CFCLKDIV_HALT_MASK)

#define SYSCON_I3CFCLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_I3CFCLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_I3CFCLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKDIV_UNSTAB_SHIFT)) & SYSCON_I3CFCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name I3CFCLKSSEL - I3C FCLK_S selection */
/*! @{ */

#define SYSCON_I3CFCLKSSEL_SEL_MASK              (0x7U)
#define SYSCON_I3CFCLKSSEL_SEL_SHIFT             (0U)
/*! SEL - I3C FCLK_S clock select
 *  0b000..FRO_1M
 *  0b001..No clock
 *  0b010..No clock
 *  0b011..No clock
 *  0b100..No clock
 *  0b101..No clock
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_I3CFCLKSSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_I3CFCLKSSEL_SEL_SHIFT)) & SYSCON_I3CFCLKSSEL_SEL_MASK)
/*! @} */

/*! @name DMICFCLKSEL - DMIC clock selection */
/*! @{ */

#define SYSCON_DMICFCLKSEL_SEL_MASK              (0x7U)
#define SYSCON_DMICFCLKSEL_SEL_SHIFT             (0U)
/*! SEL - DMIC clock select
 *  0b000..Main clock
 *  0b001..PLL0 clock
 *  0b010..Clock in
 *  0b011..FRO_HF
 *  0b100..PLL1 clock
 *  0b101..MCLK in
 *  0b110..No clock
 *  0b111..No clock
 */
#define SYSCON_DMICFCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICFCLKSEL_SEL_SHIFT)) & SYSCON_DMICFCLKSEL_SEL_MASK)
/*! @} */

/*! @name DMICFCLKDIV - DMIC clock division */
/*! @{ */

#define SYSCON_DMICFCLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_DMICFCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value. */
#define SYSCON_DMICFCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICFCLKDIV_DIV_SHIFT)) & SYSCON_DMICFCLKDIV_DIV_MASK)

#define SYSCON_DMICFCLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_DMICFCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_DMICFCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICFCLKDIV_RESET_SHIFT)) & SYSCON_DMICFCLKDIV_RESET_MASK)

#define SYSCON_DMICFCLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_DMICFCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_DMICFCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICFCLKDIV_HALT_SHIFT)) & SYSCON_DMICFCLKDIV_HALT_MASK)

#define SYSCON_DMICFCLKDIV_UNSTAB_MASK           (0x80000000U)
#define SYSCON_DMICFCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_DMICFCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_DMICFCLKDIV_UNSTAB_SHIFT)) & SYSCON_DMICFCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name PLL1CTRL - PLL1 550m control */
/*! @{ */

#define SYSCON_PLL1CTRL_SELR_MASK                (0xFU)
#define SYSCON_PLL1CTRL_SELR_SHIFT               (0U)
/*! SELR - Bandwidth select R value. */
#define SYSCON_PLL1CTRL_SELR(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_SELR_SHIFT)) & SYSCON_PLL1CTRL_SELR_MASK)

#define SYSCON_PLL1CTRL_SELI_MASK                (0x3F0U)
#define SYSCON_PLL1CTRL_SELI_SHIFT               (4U)
/*! SELI - Bandwidth select I value. */
#define SYSCON_PLL1CTRL_SELI(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_SELI_SHIFT)) & SYSCON_PLL1CTRL_SELI_MASK)

#define SYSCON_PLL1CTRL_SELP_MASK                (0x7C00U)
#define SYSCON_PLL1CTRL_SELP_SHIFT               (10U)
/*! SELP - Bandwidth select P value. */
#define SYSCON_PLL1CTRL_SELP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_SELP_SHIFT)) & SYSCON_PLL1CTRL_SELP_MASK)

#define SYSCON_PLL1CTRL_BYPASSPLL_MASK           (0x8000U)
#define SYSCON_PLL1CTRL_BYPASSPLL_SHIFT          (15U)
/*! BYPASSPLL - Bypass PLL input clock is sent directly to the PLL output (default).
 *  0b0..use PLL.
 *  0b1..PLL input clock is sent directly to the PLL output.
 */
#define SYSCON_PLL1CTRL_BYPASSPLL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_BYPASSPLL_SHIFT)) & SYSCON_PLL1CTRL_BYPASSPLL_MASK)

#define SYSCON_PLL1CTRL_BYPASSPOSTDIV2_MASK      (0x10000U)
#define SYSCON_PLL1CTRL_BYPASSPOSTDIV2_SHIFT     (16U)
/*! BYPASSPOSTDIV2 - bypass of the divide-by-2 divider in the post-divider.
 *  0b0..use the divide-by-2 divider in the post-divider.
 *  0b1..bypass of the divide-by-2 divider in the post-divider.
 */
#define SYSCON_PLL1CTRL_BYPASSPOSTDIV2(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_BYPASSPOSTDIV2_SHIFT)) & SYSCON_PLL1CTRL_BYPASSPOSTDIV2_MASK)

#define SYSCON_PLL1CTRL_LIMUPOFF_MASK            (0x20000U)
#define SYSCON_PLL1CTRL_LIMUPOFF_SHIFT           (17U)
/*! LIMUPOFF - limup_off = 1 in spread spectrum and fractional PLL applications. */
#define SYSCON_PLL1CTRL_LIMUPOFF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_LIMUPOFF_SHIFT)) & SYSCON_PLL1CTRL_LIMUPOFF_MASK)

#define SYSCON_PLL1CTRL_BWDIRECT_MASK            (0x40000U)
#define SYSCON_PLL1CTRL_BWDIRECT_SHIFT           (18U)
/*! BWDIRECT - control of the bandwidth of the PLL.
 *  0b0..the bandwidth is changed synchronously with the feedback-divider.
 *  0b1..modify the bandwidth of the PLL directly.
 */
#define SYSCON_PLL1CTRL_BWDIRECT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_BWDIRECT_SHIFT)) & SYSCON_PLL1CTRL_BWDIRECT_MASK)

#define SYSCON_PLL1CTRL_BYPASSPREDIV_MASK        (0x80000U)
#define SYSCON_PLL1CTRL_BYPASSPREDIV_SHIFT       (19U)
/*! BYPASSPREDIV - bypass of the pre-divider.
 *  0b0..use the pre-divider.
 *  0b1..bypass of the pre-divider.
 */
#define SYSCON_PLL1CTRL_BYPASSPREDIV(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_BYPASSPREDIV_SHIFT)) & SYSCON_PLL1CTRL_BYPASSPREDIV_MASK)

#define SYSCON_PLL1CTRL_BYPASSPOSTDIV_MASK       (0x100000U)
#define SYSCON_PLL1CTRL_BYPASSPOSTDIV_SHIFT      (20U)
/*! BYPASSPOSTDIV - bypass of the post-divider.
 *  0b0..use the post-divider.
 *  0b1..bypass of the post-divider.
 */
#define SYSCON_PLL1CTRL_BYPASSPOSTDIV(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_BYPASSPOSTDIV_SHIFT)) & SYSCON_PLL1CTRL_BYPASSPOSTDIV_MASK)

#define SYSCON_PLL1CTRL_CLKEN_MASK               (0x200000U)
#define SYSCON_PLL1CTRL_CLKEN_SHIFT              (21U)
/*! CLKEN - enable the output clock.
 *  0b0..Disable the output clock.
 *  0b1..Enable the output clock.
 */
#define SYSCON_PLL1CTRL_CLKEN(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_CLKEN_SHIFT)) & SYSCON_PLL1CTRL_CLKEN_MASK)

#define SYSCON_PLL1CTRL_FRMEN_MASK               (0x400000U)
#define SYSCON_PLL1CTRL_FRMEN_SHIFT              (22U)
/*! FRMEN - 1: free running mode. */
#define SYSCON_PLL1CTRL_FRMEN(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_FRMEN_SHIFT)) & SYSCON_PLL1CTRL_FRMEN_MASK)

#define SYSCON_PLL1CTRL_FRMCLKSTABLE_MASK        (0x800000U)
#define SYSCON_PLL1CTRL_FRMCLKSTABLE_SHIFT       (23U)
/*! FRMCLKSTABLE - free running mode clockstable: Warning: Only make frm_clockstable = 1 after the PLL output frequency is stable. */
#define SYSCON_PLL1CTRL_FRMCLKSTABLE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_FRMCLKSTABLE_SHIFT)) & SYSCON_PLL1CTRL_FRMCLKSTABLE_MASK)

#define SYSCON_PLL1CTRL_SKEWEN_MASK              (0x1000000U)
#define SYSCON_PLL1CTRL_SKEWEN_SHIFT             (24U)
/*! SKEWEN - Skew mode.
 *  0b0..skewmode is disable.
 *  0b1..skewmode is enable.
 */
#define SYSCON_PLL1CTRL_SKEWEN(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1CTRL_SKEWEN_SHIFT)) & SYSCON_PLL1CTRL_SKEWEN_MASK)
/*! @} */

/*! @name PLL1STAT - PLL1 550m status */
/*! @{ */

#define SYSCON_PLL1STAT_LOCK_MASK                (0x1U)
#define SYSCON_PLL1STAT_LOCK_SHIFT               (0U)
/*! LOCK - lock detector output (active high) Warning: The lock signal is only reliable between fref[2] :100 kHz to 20 MHz. */
#define SYSCON_PLL1STAT_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1STAT_LOCK_SHIFT)) & SYSCON_PLL1STAT_LOCK_MASK)

#define SYSCON_PLL1STAT_PREDIVACK_MASK           (0x2U)
#define SYSCON_PLL1STAT_PREDIVACK_SHIFT          (1U)
/*! PREDIVACK - pre-divider ratio change acknowledge. */
#define SYSCON_PLL1STAT_PREDIVACK(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1STAT_PREDIVACK_SHIFT)) & SYSCON_PLL1STAT_PREDIVACK_MASK)

#define SYSCON_PLL1STAT_FEEDDIVACK_MASK          (0x4U)
#define SYSCON_PLL1STAT_FEEDDIVACK_SHIFT         (2U)
/*! FEEDDIVACK - feedback divider ratio change acknowledge. */
#define SYSCON_PLL1STAT_FEEDDIVACK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1STAT_FEEDDIVACK_SHIFT)) & SYSCON_PLL1STAT_FEEDDIVACK_MASK)

#define SYSCON_PLL1STAT_POSTDIVACK_MASK          (0x8U)
#define SYSCON_PLL1STAT_POSTDIVACK_SHIFT         (3U)
/*! POSTDIVACK - post-divider ratio change acknowledge. */
#define SYSCON_PLL1STAT_POSTDIVACK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1STAT_POSTDIVACK_SHIFT)) & SYSCON_PLL1STAT_POSTDIVACK_MASK)

#define SYSCON_PLL1STAT_FRMDET_MASK              (0x10U)
#define SYSCON_PLL1STAT_FRMDET_SHIFT             (4U)
/*! FRMDET - free running detector output (active high). */
#define SYSCON_PLL1STAT_FRMDET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1STAT_FRMDET_SHIFT)) & SYSCON_PLL1STAT_FRMDET_MASK)
/*! @} */

/*! @name PLL1NDEC - PLL1 550m N divider */
/*! @{ */

#define SYSCON_PLL1NDEC_NDIV_MASK                (0xFFU)
#define SYSCON_PLL1NDEC_NDIV_SHIFT               (0U)
/*! NDIV - pre-divider divider ratio (N-divider). */
#define SYSCON_PLL1NDEC_NDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1NDEC_NDIV_SHIFT)) & SYSCON_PLL1NDEC_NDIV_MASK)

#define SYSCON_PLL1NDEC_NREQ_MASK                (0x100U)
#define SYSCON_PLL1NDEC_NREQ_SHIFT               (8U)
/*! NREQ - pre-divider ratio change request. */
#define SYSCON_PLL1NDEC_NREQ(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1NDEC_NREQ_SHIFT)) & SYSCON_PLL1NDEC_NREQ_MASK)
/*! @} */

/*! @name PLL1MDEC - PLL1 550m M divider */
/*! @{ */

#define SYSCON_PLL1MDEC_MDIV_MASK                (0xFFFFU)
#define SYSCON_PLL1MDEC_MDIV_SHIFT               (0U)
/*! MDIV - feedback divider divider ratio (M-divider). */
#define SYSCON_PLL1MDEC_MDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1MDEC_MDIV_SHIFT)) & SYSCON_PLL1MDEC_MDIV_MASK)

#define SYSCON_PLL1MDEC_MREQ_MASK                (0x10000U)
#define SYSCON_PLL1MDEC_MREQ_SHIFT               (16U)
/*! MREQ - feedback ratio change request. */
#define SYSCON_PLL1MDEC_MREQ(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1MDEC_MREQ_SHIFT)) & SYSCON_PLL1MDEC_MREQ_MASK)
/*! @} */

/*! @name PLL1PDEC - PLL1 550m P divider */
/*! @{ */

#define SYSCON_PLL1PDEC_PDIV_MASK                (0x1FU)
#define SYSCON_PLL1PDEC_PDIV_SHIFT               (0U)
/*! PDIV - post-divider divider ratio (P-divider) */
#define SYSCON_PLL1PDEC_PDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1PDEC_PDIV_SHIFT)) & SYSCON_PLL1PDEC_PDIV_MASK)

#define SYSCON_PLL1PDEC_PREQ_MASK                (0x20U)
#define SYSCON_PLL1PDEC_PREQ_SHIFT               (5U)
/*! PREQ - feedback ratio change request. */
#define SYSCON_PLL1PDEC_PREQ(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL1PDEC_PREQ_SHIFT)) & SYSCON_PLL1PDEC_PREQ_MASK)
/*! @} */

/*! @name PLL0CTRL - PLL0 550m control */
/*! @{ */

#define SYSCON_PLL0CTRL_SELR_MASK                (0xFU)
#define SYSCON_PLL0CTRL_SELR_SHIFT               (0U)
/*! SELR - Bandwidth select R value. */
#define SYSCON_PLL0CTRL_SELR(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_SELR_SHIFT)) & SYSCON_PLL0CTRL_SELR_MASK)

#define SYSCON_PLL0CTRL_SELI_MASK                (0x3F0U)
#define SYSCON_PLL0CTRL_SELI_SHIFT               (4U)
/*! SELI - Bandwidth select I value. */
#define SYSCON_PLL0CTRL_SELI(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_SELI_SHIFT)) & SYSCON_PLL0CTRL_SELI_MASK)

#define SYSCON_PLL0CTRL_SELP_MASK                (0x7C00U)
#define SYSCON_PLL0CTRL_SELP_SHIFT               (10U)
/*! SELP - Bandwidth select P value. */
#define SYSCON_PLL0CTRL_SELP(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_SELP_SHIFT)) & SYSCON_PLL0CTRL_SELP_MASK)

#define SYSCON_PLL0CTRL_BYPASSPLL_MASK           (0x8000U)
#define SYSCON_PLL0CTRL_BYPASSPLL_SHIFT          (15U)
/*! BYPASSPLL - Bypass PLL input clock is sent directly to the PLL output (default).
 *  0b0..use PLL.
 *  0b1..Bypass PLL input clock is sent directly to the PLL output.
 */
#define SYSCON_PLL0CTRL_BYPASSPLL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_BYPASSPLL_SHIFT)) & SYSCON_PLL0CTRL_BYPASSPLL_MASK)

#define SYSCON_PLL0CTRL_BYPASSPOSTDIV2_MASK      (0x10000U)
#define SYSCON_PLL0CTRL_BYPASSPOSTDIV2_SHIFT     (16U)
/*! BYPASSPOSTDIV2 - bypass of the divide-by-2 divider in the post-divider.
 *  0b0..use the divide-by-2 divider in the post-divider.
 *  0b1..bypass of the divide-by-2 divider in the post-divider.
 */
#define SYSCON_PLL0CTRL_BYPASSPOSTDIV2(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_BYPASSPOSTDIV2_SHIFT)) & SYSCON_PLL0CTRL_BYPASSPOSTDIV2_MASK)

#define SYSCON_PLL0CTRL_LIMUPOFF_MASK            (0x20000U)
#define SYSCON_PLL0CTRL_LIMUPOFF_SHIFT           (17U)
/*! LIMUPOFF - limup_off = 1 in spread spectrum and fractional PLL applications. */
#define SYSCON_PLL0CTRL_LIMUPOFF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_LIMUPOFF_SHIFT)) & SYSCON_PLL0CTRL_LIMUPOFF_MASK)

#define SYSCON_PLL0CTRL_BWDIRECT_MASK            (0x40000U)
#define SYSCON_PLL0CTRL_BWDIRECT_SHIFT           (18U)
/*! BWDIRECT - Control of the bandwidth of the PLL.
 *  0b0..the bandwidth is changed synchronously with the feedback-divider.
 *  0b1..modify the bandwidth of the PLL directly.
 */
#define SYSCON_PLL0CTRL_BWDIRECT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_BWDIRECT_SHIFT)) & SYSCON_PLL0CTRL_BWDIRECT_MASK)

#define SYSCON_PLL0CTRL_BYPASSPREDIV_MASK        (0x80000U)
#define SYSCON_PLL0CTRL_BYPASSPREDIV_SHIFT       (19U)
/*! BYPASSPREDIV - bypass of the pre-divider.
 *  0b0..use the pre-divider.
 *  0b1..bypass of the pre-divider.
 */
#define SYSCON_PLL0CTRL_BYPASSPREDIV(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_BYPASSPREDIV_SHIFT)) & SYSCON_PLL0CTRL_BYPASSPREDIV_MASK)

#define SYSCON_PLL0CTRL_BYPASSPOSTDIV_MASK       (0x100000U)
#define SYSCON_PLL0CTRL_BYPASSPOSTDIV_SHIFT      (20U)
/*! BYPASSPOSTDIV - bypass of the post-divider.
 *  0b0..use the post-divider.
 *  0b1..bypass of the post-divider.
 */
#define SYSCON_PLL0CTRL_BYPASSPOSTDIV(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_BYPASSPOSTDIV_SHIFT)) & SYSCON_PLL0CTRL_BYPASSPOSTDIV_MASK)

#define SYSCON_PLL0CTRL_CLKEN_MASK               (0x200000U)
#define SYSCON_PLL0CTRL_CLKEN_SHIFT              (21U)
/*! CLKEN - enable the output clock.
 *  0b0..disable the output clock.
 *  0b1..enable the output clock.
 */
#define SYSCON_PLL0CTRL_CLKEN(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_CLKEN_SHIFT)) & SYSCON_PLL0CTRL_CLKEN_MASK)

#define SYSCON_PLL0CTRL_FRMEN_MASK               (0x400000U)
#define SYSCON_PLL0CTRL_FRMEN_SHIFT              (22U)
/*! FRMEN - free running mode.
 *  0b0..free running mode is disable.
 *  0b1..free running mode is enable.
 */
#define SYSCON_PLL0CTRL_FRMEN(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_FRMEN_SHIFT)) & SYSCON_PLL0CTRL_FRMEN_MASK)

#define SYSCON_PLL0CTRL_FRMCLKSTABLE_MASK        (0x800000U)
#define SYSCON_PLL0CTRL_FRMCLKSTABLE_SHIFT       (23U)
/*! FRMCLKSTABLE - free running mode clockstable: Warning: Only make frm_clockstable =1 after the PLL output frequency is stable. */
#define SYSCON_PLL0CTRL_FRMCLKSTABLE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_FRMCLKSTABLE_SHIFT)) & SYSCON_PLL0CTRL_FRMCLKSTABLE_MASK)

#define SYSCON_PLL0CTRL_SKEWEN_MASK              (0x1000000U)
#define SYSCON_PLL0CTRL_SKEWEN_SHIFT             (24U)
/*! SKEWEN - skew mode.
 *  0b0..skew mode is disable.
 *  0b1..skew mode is enable.
 */
#define SYSCON_PLL0CTRL_SKEWEN(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0CTRL_SKEWEN_SHIFT)) & SYSCON_PLL0CTRL_SKEWEN_MASK)
/*! @} */

/*! @name PLL0STAT - PLL0 550m status */
/*! @{ */

#define SYSCON_PLL0STAT_LOCK_MASK                (0x1U)
#define SYSCON_PLL0STAT_LOCK_SHIFT               (0U)
/*! LOCK - lock detector output (active high) Warning: The lock signal is only reliable between fref[2] :100 kHz to 20 MHz. */
#define SYSCON_PLL0STAT_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0STAT_LOCK_SHIFT)) & SYSCON_PLL0STAT_LOCK_MASK)

#define SYSCON_PLL0STAT_PREDIVACK_MASK           (0x2U)
#define SYSCON_PLL0STAT_PREDIVACK_SHIFT          (1U)
/*! PREDIVACK - pre-divider ratio change acknowledge. */
#define SYSCON_PLL0STAT_PREDIVACK(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0STAT_PREDIVACK_SHIFT)) & SYSCON_PLL0STAT_PREDIVACK_MASK)

#define SYSCON_PLL0STAT_FEEDDIVACK_MASK          (0x4U)
#define SYSCON_PLL0STAT_FEEDDIVACK_SHIFT         (2U)
/*! FEEDDIVACK - feedback divider ratio change acknowledge. */
#define SYSCON_PLL0STAT_FEEDDIVACK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0STAT_FEEDDIVACK_SHIFT)) & SYSCON_PLL0STAT_FEEDDIVACK_MASK)

#define SYSCON_PLL0STAT_POSTDIVACK_MASK          (0x8U)
#define SYSCON_PLL0STAT_POSTDIVACK_SHIFT         (3U)
/*! POSTDIVACK - post-divider ratio change acknowledge. */
#define SYSCON_PLL0STAT_POSTDIVACK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0STAT_POSTDIVACK_SHIFT)) & SYSCON_PLL0STAT_POSTDIVACK_MASK)

#define SYSCON_PLL0STAT_FRMDET_MASK              (0x10U)
#define SYSCON_PLL0STAT_FRMDET_SHIFT             (4U)
/*! FRMDET - free running detector output (active high). */
#define SYSCON_PLL0STAT_FRMDET(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0STAT_FRMDET_SHIFT)) & SYSCON_PLL0STAT_FRMDET_MASK)
/*! @} */

/*! @name PLL0NDEC - PLL0 550m N divider */
/*! @{ */

#define SYSCON_PLL0NDEC_NDIV_MASK                (0xFFU)
#define SYSCON_PLL0NDEC_NDIV_SHIFT               (0U)
/*! NDIV - pre-divider divider ratio (N-divider). */
#define SYSCON_PLL0NDEC_NDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0NDEC_NDIV_SHIFT)) & SYSCON_PLL0NDEC_NDIV_MASK)

#define SYSCON_PLL0NDEC_NREQ_MASK                (0x100U)
#define SYSCON_PLL0NDEC_NREQ_SHIFT               (8U)
/*! NREQ - pre-divider ratio change request. */
#define SYSCON_PLL0NDEC_NREQ(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0NDEC_NREQ_SHIFT)) & SYSCON_PLL0NDEC_NREQ_MASK)
/*! @} */

/*! @name PLL0PDEC - PLL0 550m P divider */
/*! @{ */

#define SYSCON_PLL0PDEC_PDIV_MASK                (0x1FU)
#define SYSCON_PLL0PDEC_PDIV_SHIFT               (0U)
/*! PDIV - post-divider divider ratio (P-divider) */
#define SYSCON_PLL0PDEC_PDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0PDEC_PDIV_SHIFT)) & SYSCON_PLL0PDEC_PDIV_MASK)

#define SYSCON_PLL0PDEC_PREQ_MASK                (0x20U)
#define SYSCON_PLL0PDEC_PREQ_SHIFT               (5U)
/*! PREQ - feedback ratio change request. */
#define SYSCON_PLL0PDEC_PREQ(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0PDEC_PREQ_SHIFT)) & SYSCON_PLL0PDEC_PREQ_MASK)
/*! @} */

/*! @name PLL0SSCG0 - PLL0 Spread Spectrum control 0 */
/*! @{ */

#define SYSCON_PLL0SSCG0_MD_LBS_MASK             (0xFFFFFFFFU)
#define SYSCON_PLL0SSCG0_MD_LBS_SHIFT            (0U)
/*! MD_LBS - input word of the wrapper bit 31 to 0. */
#define SYSCON_PLL0SSCG0_MD_LBS(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG0_MD_LBS_SHIFT)) & SYSCON_PLL0SSCG0_MD_LBS_MASK)
/*! @} */

/*! @name PLL0SSCG1 - PLL0 Spread Spectrum control 1 */
/*! @{ */

#define SYSCON_PLL0SSCG1_MD_MBS_MASK             (0x1U)
#define SYSCON_PLL0SSCG1_MD_MBS_SHIFT            (0U)
/*! MD_MBS - input word of the wrapper bit 32. */
#define SYSCON_PLL0SSCG1_MD_MBS(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MD_MBS_SHIFT)) & SYSCON_PLL0SSCG1_MD_MBS_MASK)

#define SYSCON_PLL0SSCG1_MD_REQ_MASK             (0x2U)
#define SYSCON_PLL0SSCG1_MD_REQ_SHIFT            (1U)
/*! MD_REQ - md change request. */
#define SYSCON_PLL0SSCG1_MD_REQ(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MD_REQ_SHIFT)) & SYSCON_PLL0SSCG1_MD_REQ_MASK)

#define SYSCON_PLL0SSCG1_MF_MASK                 (0x1CU)
#define SYSCON_PLL0SSCG1_MF_SHIFT                (2U)
/*! MF - programmable modulation frequency fm = Fref/Nss mf[2:0] = 000 => Nss=512 (fm ~ 3. */
#define SYSCON_PLL0SSCG1_MF(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MF_SHIFT)) & SYSCON_PLL0SSCG1_MF_MASK)

#define SYSCON_PLL0SSCG1_MR_MASK                 (0xE0U)
#define SYSCON_PLL0SSCG1_MR_SHIFT                (5U)
/*! MR - programmable frequency modulation depth Dfmodpk-pk = Fref*kss/Fcco = kss/(2*md[32:25]dec)
 *    mr[2:0] = 000 => kss = 0 (no spread spectrum) mr[2:0] = 001 => kss ~ 1 mr[2:0] = 010 => kss ~ 1.
 */
#define SYSCON_PLL0SSCG1_MR(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MR_SHIFT)) & SYSCON_PLL0SSCG1_MR_MASK)

#define SYSCON_PLL0SSCG1_MC_MASK                 (0x300U)
#define SYSCON_PLL0SSCG1_MC_SHIFT                (8U)
/*! MC - modulation waveform control Compensation for low pass filtering of the PLL to get a
 *    triangular modulation at the output of the PLL, giving a flat frequency spectrum.
 */
#define SYSCON_PLL0SSCG1_MC(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MC_SHIFT)) & SYSCON_PLL0SSCG1_MC_MASK)

#define SYSCON_PLL0SSCG1_MDIV_EXT_MASK           (0x3FFFC00U)
#define SYSCON_PLL0SSCG1_MDIV_EXT_SHIFT          (10U)
/*! MDIV_EXT - to select an external mdiv value. */
#define SYSCON_PLL0SSCG1_MDIV_EXT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MDIV_EXT_SHIFT)) & SYSCON_PLL0SSCG1_MDIV_EXT_MASK)

#define SYSCON_PLL0SSCG1_MREQ_MASK               (0x4000000U)
#define SYSCON_PLL0SSCG1_MREQ_SHIFT              (26U)
/*! MREQ - to select an external mreq value. */
#define SYSCON_PLL0SSCG1_MREQ(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_MREQ_SHIFT)) & SYSCON_PLL0SSCG1_MREQ_MASK)

#define SYSCON_PLL0SSCG1_DITHER_MASK             (0x8000000U)
#define SYSCON_PLL0SSCG1_DITHER_SHIFT            (27U)
/*! DITHER - dithering between two modulation frequencies in a random way or in a pseudo random way
 *    (white noise), in order to decrease the probability that the modulated waveform will occur
 *    with the same phase on a particular point on the screen.
 */
#define SYSCON_PLL0SSCG1_DITHER(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_DITHER_SHIFT)) & SYSCON_PLL0SSCG1_DITHER_MASK)

#define SYSCON_PLL0SSCG1_SEL_EXT_MASK            (0x10000000U)
#define SYSCON_PLL0SSCG1_SEL_EXT_SHIFT           (28U)
/*! SEL_EXT - to select mdiv_ext and mreq_ext sel_ext = 0: mdiv ~ md[32:0], mreq = 1 sel_ext = 1 : mdiv = mdiv_ext, mreq = mreq_ext. */
#define SYSCON_PLL0SSCG1_SEL_EXT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PLL0SSCG1_SEL_EXT_SHIFT)) & SYSCON_PLL0SSCG1_SEL_EXT_MASK)
/*! @} */

/*! @name DAC_ISO_CTRL - DAC Isolation Control */
/*! @{ */

#define SYSCON_DAC_ISO_CTRL_DAC0_ISO_MASK        (0x1U)
#define SYSCON_DAC_ISO_CTRL_DAC0_ISO_SHIFT       (0U)
/*! DAC0_ISO - DAC0 Isolation
 *  0b0..DAC0 isolation disabled
 *  0b1..DAC0 isolation enabled
 */
#define SYSCON_DAC_ISO_CTRL_DAC0_ISO(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_ISO_CTRL_DAC0_ISO_SHIFT)) & SYSCON_DAC_ISO_CTRL_DAC0_ISO_MASK)

#define SYSCON_DAC_ISO_CTRL_DAC1_ISO_MASK        (0x2U)
#define SYSCON_DAC_ISO_CTRL_DAC1_ISO_SHIFT       (1U)
/*! DAC1_ISO - DAC1 Isolation
 *  0b0..DAC1 isolation disabled
 *  0b1..DAC1 isolation enabled
 */
#define SYSCON_DAC_ISO_CTRL_DAC1_ISO(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_ISO_CTRL_DAC1_ISO_SHIFT)) & SYSCON_DAC_ISO_CTRL_DAC1_ISO_MASK)

#define SYSCON_DAC_ISO_CTRL_DAC2_ISO_MASK        (0x4U)
#define SYSCON_DAC_ISO_CTRL_DAC2_ISO_SHIFT       (2U)
/*! DAC2_ISO - DAC2 Isolation
 *  0b0..DAC2 isolation disabled
 *  0b1..DAC2 isolation enabled
 */
#define SYSCON_DAC_ISO_CTRL_DAC2_ISO(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DAC_ISO_CTRL_DAC2_ISO_SHIFT)) & SYSCON_DAC_ISO_CTRL_DAC2_ISO_MASK)
/*! @} */

/*! @name STARTER - Start logic wake-up enable */
/*! @{ */

#define SYSCON_STARTER_FLEXPWM1_COMPARE1_IRQ_MASK (0x1U)
#define SYSCON_STARTER_FLEXPWM1_COMPARE1_IRQ_SHIFT (0U)
/*! FLEXPWM1_COMPARE1_IRQ - FlexPWM1 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_COMPARE1_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_COMPARE1_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_COMPARE1_IRQ_MASK)

#define SYSCON_STARTER_GPIO_INT04_MASK           (0x1U)
#define SYSCON_STARTER_GPIO_INT04_SHIFT          (0U)
/*! GPIO_INT04 - GPIO_INT04 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_GPIO_INT04(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GPIO_INT04_SHIFT)) & SYSCON_STARTER_GPIO_INT04_MASK)

#define SYSCON_STARTER_SYS_MASK                  (0x1U)
#define SYSCON_STARTER_SYS_SHIFT                 (0U)
/*! SYS - SYS interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SYS(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SYS_SHIFT)) & SYSCON_STARTER_SYS_MASK)

#define SYSCON_STARTER_ELS_IRQ1_MASK             (0x2U)
#define SYSCON_STARTER_ELS_IRQ1_SHIFT            (1U)
/*! ELS_IRQ1 - ELS_IRQ1 (Digital Glitch Detect)
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ELS_IRQ1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ELS_IRQ1_SHIFT)) & SYSCON_STARTER_ELS_IRQ1_MASK)

#define SYSCON_STARTER_FLEXPWM1_RELOAD1_IRQ_MASK (0x2U)
#define SYSCON_STARTER_FLEXPWM1_RELOAD1_IRQ_SHIFT (1U)
/*! FLEXPWM1_RELOAD1_IRQ - FlexPWM1 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_RELOAD1_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_RELOAD1_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_RELOAD1_IRQ_MASK)

#define SYSCON_STARTER_GPIO_INT05_MASK           (0x2U)
#define SYSCON_STARTER_GPIO_INT05_SHIFT          (1U)
/*! GPIO_INT05 - GPIO_INT05 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_GPIO_INT05(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GPIO_INT05_SHIFT)) & SYSCON_STARTER_GPIO_INT05_MASK)

#define SYSCON_STARTER_SDMA0_MASK                (0x2U)
#define SYSCON_STARTER_SDMA0_SHIFT               (1U)
/*! SDMA0 - SDMA0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SDMA0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SDMA0_SHIFT)) & SYSCON_STARTER_SDMA0_MASK)

#define SYSCON_STARTER_FLEXPWM1_COMPARE2_IRQ_MASK (0x4U)
#define SYSCON_STARTER_FLEXPWM1_COMPARE2_IRQ_SHIFT (2U)
/*! FLEXPWM1_COMPARE2_IRQ - FlexPWM1 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_COMPARE2_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_COMPARE2_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_COMPARE2_IRQ_MASK)

#define SYSCON_STARTER_GINT0_MASK                (0x4U)
#define SYSCON_STARTER_GINT0_SHIFT               (2U)
/*! GINT0 - GINT0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_GINT0(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT0_SHIFT)) & SYSCON_STARTER_GINT0_MASK)

#define SYSCON_STARTER_GPIO_INT06_MASK           (0x4U)
#define SYSCON_STARTER_GPIO_INT06_SHIFT          (2U)
/*! GPIO_INT06 - GPIO_INT06 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_GPIO_INT06(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GPIO_INT06_SHIFT)) & SYSCON_STARTER_GPIO_INT06_MASK)

#define SYSCON_STARTER_TAMPER_IRQ_MASK           (0x4U)
#define SYSCON_STARTER_TAMPER_IRQ_SHIFT          (2U)
/*! TAMPER_IRQ - Tamper interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_TAMPER_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_TAMPER_IRQ_SHIFT)) & SYSCON_STARTER_TAMPER_IRQ_MASK)

#define SYSCON_STARTER_FLEXPWM1_RELOAD2_IRQ_MASK (0x8U)
#define SYSCON_STARTER_FLEXPWM1_RELOAD2_IRQ_SHIFT (3U)
/*! FLEXPWM1_RELOAD2_IRQ - FlexPWM1 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_RELOAD2_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_RELOAD2_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_RELOAD2_IRQ_MASK)

#define SYSCON_STARTER_GINT1_MASK                (0x8U)
#define SYSCON_STARTER_GINT1_SHIFT               (3U)
/*! GINT1 - GINT1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_GINT1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GINT1_SHIFT)) & SYSCON_STARTER_GINT1_MASK)

#define SYSCON_STARTER_GPIO_INT07_MASK           (0x8U)
#define SYSCON_STARTER_GPIO_INT07_SHIFT          (3U)
/*! GPIO_INT07 - GPIO_INT07 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_GPIO_INT07(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_GPIO_INT07_SHIFT)) & SYSCON_STARTER_GPIO_INT07_MASK)

#define SYSCON_STARTER_CTIMER2_MASK              (0x10U)
#define SYSCON_STARTER_CTIMER2_SHIFT             (4U)
/*! CTIMER2 - CTIMER2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CTIMER2(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER2_SHIFT)) & SYSCON_STARTER_CTIMER2_MASK)

#define SYSCON_STARTER_FLEXPWM1_COMPARE3_IRQ_MASK (0x10U)
#define SYSCON_STARTER_FLEXPWM1_COMPARE3_IRQ_SHIFT (4U)
/*! FLEXPWM1_COMPARE3_IRQ - FlexPWM1 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_COMPARE3_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_COMPARE3_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_COMPARE3_IRQ_MASK)

#define SYSCON_STARTER_PIO_INT0_MASK             (0x10U)
#define SYSCON_STARTER_PIO_INT0_SHIFT            (4U)
/*! PIO_INT0 - PIO_INT0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PIO_INT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIO_INT0_SHIFT)) & SYSCON_STARTER_PIO_INT0_MASK)

#define SYSCON_STARTER_CTIMER4_MASK              (0x20U)
#define SYSCON_STARTER_CTIMER4_SHIFT             (5U)
/*! CTIMER4 - CTIMER4 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CTIMER4(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER4_SHIFT)) & SYSCON_STARTER_CTIMER4_MASK)

#define SYSCON_STARTER_FLEXPWM1_RELOAD3_IRQ_MASK (0x20U)
#define SYSCON_STARTER_FLEXPWM1_RELOAD3_IRQ_SHIFT (5U)
/*! FLEXPWM1_RELOAD3_IRQ - FlexPWM1 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_RELOAD3_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_RELOAD3_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_RELOAD3_IRQ_MASK)

#define SYSCON_STARTER_PIO_INT1_MASK             (0x20U)
#define SYSCON_STARTER_PIO_INT1_SHIFT            (5U)
/*! PIO_INT1 - PIO_INT1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PIO_INT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIO_INT1_SHIFT)) & SYSCON_STARTER_PIO_INT1_MASK)

#define SYSCON_STARTER_ENCO_COMPARE_IRQ_MASK     (0x40U)
#define SYSCON_STARTER_ENCO_COMPARE_IRQ_SHIFT    (6U)
/*! ENCO_COMPARE_IRQ - ENC0 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENCO_COMPARE_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENCO_COMPARE_IRQ_SHIFT)) & SYSCON_STARTER_ENCO_COMPARE_IRQ_MASK)

#define SYSCON_STARTER_OS_EVENT_MASK             (0x40U)
#define SYSCON_STARTER_OS_EVENT_SHIFT            (6U)
/*! OS_EVENT - OS_EVENT interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_OS_EVENT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_OS_EVENT_SHIFT)) & SYSCON_STARTER_OS_EVENT_MASK)

#define SYSCON_STARTER_PIO_INT2_MASK             (0x40U)
#define SYSCON_STARTER_PIO_INT2_SHIFT            (6U)
/*! PIO_INT2 - PIO_INT2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PIO_INT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIO_INT2_SHIFT)) & SYSCON_STARTER_PIO_INT2_MASK)

#define SYSCON_STARTER_ENCO_HOME_IRQ_MASK        (0x80U)
#define SYSCON_STARTER_ENCO_HOME_IRQ_SHIFT       (7U)
/*! ENCO_HOME_IRQ - ENC0 home interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENCO_HOME_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENCO_HOME_IRQ_SHIFT)) & SYSCON_STARTER_ENCO_HOME_IRQ_MASK)

#define SYSCON_STARTER_FLEXSPI_MASK              (0x80U)
#define SYSCON_STARTER_FLEXSPI_SHIFT             (7U)
/*! FLEXSPI - FLEXSPI interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXSPI(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXSPI_SHIFT)) & SYSCON_STARTER_FLEXSPI_MASK)

#define SYSCON_STARTER_PIO_INT3_MASK             (0x80U)
#define SYSCON_STARTER_PIO_INT3_SHIFT            (7U)
/*! PIO_INT3 - PIO_INT3 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PIO_INT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIO_INT3_SHIFT)) & SYSCON_STARTER_PIO_INT3_MASK)

#define SYSCON_STARTER_ENCO_WDG_IRQ_MASK         (0x100U)
#define SYSCON_STARTER_ENCO_WDG_IRQ_SHIFT        (8U)
/*! ENCO_WDG_IRQ - ENC0 WDOG interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENCO_WDG_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENCO_WDG_IRQ_SHIFT)) & SYSCON_STARTER_ENCO_WDG_IRQ_MASK)

#define SYSCON_STARTER_UTICK0_MASK               (0x100U)
#define SYSCON_STARTER_UTICK0_SHIFT              (8U)
/*! UTICK0 - UTICK0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_UTICK0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_UTICK0_SHIFT)) & SYSCON_STARTER_UTICK0_MASK)

#define SYSCON_STARTER_ENCO_IDX_IRQ_MASK         (0x200U)
#define SYSCON_STARTER_ENCO_IDX_IRQ_SHIFT        (9U)
/*! ENCO_IDX_IRQ - ENC0 IDX interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENCO_IDX_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENCO_IDX_IRQ_SHIFT)) & SYSCON_STARTER_ENCO_IDX_IRQ_MASK)

#define SYSCON_STARTER_MRT0_MASK                 (0x200U)
#define SYSCON_STARTER_MRT0_SHIFT                (9U)
/*! MRT0 - MRT0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_MRT0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_MRT0_SHIFT)) & SYSCON_STARTER_MRT0_MASK)

#define SYSCON_STARTER_CTIMER0_MASK              (0x400U)
#define SYSCON_STARTER_CTIMER0_SHIFT             (10U)
/*! CTIMER0 - CTIMER0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CTIMER0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER0_SHIFT)) & SYSCON_STARTER_CTIMER0_MASK)

#define SYSCON_STARTER_DAC0_IRQ_MASK             (0x400U)
#define SYSCON_STARTER_DAC0_IRQ_SHIFT            (10U)
/*! DAC0_IRQ - DAC0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_DAC0_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DAC0_IRQ_SHIFT)) & SYSCON_STARTER_DAC0_IRQ_MASK)

#define SYSCON_STARTER_ENC1_COMPARE_IRQ_MASK     (0x400U)
#define SYSCON_STARTER_ENC1_COMPARE_IRQ_SHIFT    (10U)
/*! ENC1_COMPARE_IRQ - ENC1 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENC1_COMPARE_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENC1_COMPARE_IRQ_SHIFT)) & SYSCON_STARTER_ENC1_COMPARE_IRQ_MASK)

#define SYSCON_STARTER_CAN0_IRQ0_MASK            (0x800U)
#define SYSCON_STARTER_CAN0_IRQ0_SHIFT           (11U)
/*! CAN0_IRQ0 - CAN0_IRQ0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CAN0_IRQ0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CAN0_IRQ0_SHIFT)) & SYSCON_STARTER_CAN0_IRQ0_MASK)

#define SYSCON_STARTER_CTIMER1_MASK              (0x800U)
#define SYSCON_STARTER_CTIMER1_SHIFT             (11U)
/*! CTIMER1 - CTIMER1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CTIMER1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER1_SHIFT)) & SYSCON_STARTER_CTIMER1_MASK)

#define SYSCON_STARTER_DAC1_IRQ_MASK             (0x800U)
#define SYSCON_STARTER_DAC1_IRQ_SHIFT            (11U)
/*! DAC1_IRQ - DAC1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_DAC1_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DAC1_IRQ_SHIFT)) & SYSCON_STARTER_DAC1_IRQ_MASK)

#define SYSCON_STARTER_ENC1_HOME_IRQ_MASK        (0x800U)
#define SYSCON_STARTER_ENC1_HOME_IRQ_SHIFT       (11U)
/*! ENC1_HOME_IRQ - ENC1 home interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENC1_HOME_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENC1_HOME_IRQ_SHIFT)) & SYSCON_STARTER_ENC1_HOME_IRQ_MASK)

#define SYSCON_STARTER_CAN0_IRQ1_MASK            (0x1000U)
#define SYSCON_STARTER_CAN0_IRQ1_SHIFT           (12U)
/*! CAN0_IRQ1 - CAN0_IRQ0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CAN0_IRQ1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CAN0_IRQ1_SHIFT)) & SYSCON_STARTER_CAN0_IRQ1_MASK)

#define SYSCON_STARTER_DAC2_IRQ_MASK             (0x1000U)
#define SYSCON_STARTER_DAC2_IRQ_SHIFT            (12U)
/*! DAC2_IRQ - DAC2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_DAC2_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DAC2_IRQ_SHIFT)) & SYSCON_STARTER_DAC2_IRQ_MASK)

#define SYSCON_STARTER_ENC1_WDG_IRQ_MASK         (0x1000U)
#define SYSCON_STARTER_ENC1_WDG_IRQ_SHIFT        (12U)
/*! ENC1_WDG_IRQ - ENC1 WDOG interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENC1_WDG_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENC1_WDG_IRQ_SHIFT)) & SYSCON_STARTER_ENC1_WDG_IRQ_MASK)

#define SYSCON_STARTER_SCT0_MASK                 (0x1000U)
#define SYSCON_STARTER_SCT0_SHIFT                (12U)
/*! SCT0 - SCT0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SCT0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SCT0_SHIFT)) & SYSCON_STARTER_SCT0_MASK)

#define SYSCON_STARTER_CTIMER3_MASK              (0x2000U)
#define SYSCON_STARTER_CTIMER3_SHIFT             (13U)
/*! CTIMER3 - CTIMER3 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CTIMER3(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER3_SHIFT)) & SYSCON_STARTER_CTIMER3_MASK)

#define SYSCON_STARTER_ENC1_IDX_IRQ_MASK         (0x2000U)
#define SYSCON_STARTER_ENC1_IDX_IRQ_SHIFT        (13U)
/*! ENC1_IDX_IRQ - ENC1 IDX interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ENC1_IDX_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ENC1_IDX_IRQ_SHIFT)) & SYSCON_STARTER_ENC1_IDX_IRQ_MASK)

#define SYSCON_STARTER_HS_CMP0_IRQ_MASK          (0x2000U)
#define SYSCON_STARTER_HS_CMP0_IRQ_SHIFT         (13U)
/*! HS_CMP0_IRQ - HS_CMP0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_HS_CMP0_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_HS_CMP0_IRQ_SHIFT)) & SYSCON_STARTER_HS_CMP0_IRQ_MASK)

#define SYSCON_STARTER_SPI_FILTER_MASK           (0x2000U)
#define SYSCON_STARTER_SPI_FILTER_SHIFT          (13U)
/*! SPI_FILTER - SPI_FILTER interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SPI_FILTER(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SPI_FILTER_SHIFT)) & SYSCON_STARTER_SPI_FILTER_MASK)

#define SYSCON_STARTER_FLEXINT0_MASK             (0x4000U)
#define SYSCON_STARTER_FLEXINT0_SHIFT            (14U)
/*! FLEXINT0 - FLEXINT0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT0_SHIFT)) & SYSCON_STARTER_FLEXINT0_MASK)

#define SYSCON_STARTER_HS_CMP1_IRQ_MASK          (0x4000U)
#define SYSCON_STARTER_HS_CMP1_IRQ_SHIFT         (14U)
/*! HS_CMP1_IRQ - HS_CMP1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_HS_CMP1_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_HS_CMP1_IRQ_SHIFT)) & SYSCON_STARTER_HS_CMP1_IRQ_MASK)

#define SYSCON_STARTER_ITRC_IRQ_MASK             (0x4000U)
#define SYSCON_STARTER_ITRC_IRQ_SHIFT            (14U)
/*! ITRC_IRQ - ITRC interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ITRC_IRQ(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ITRC_IRQ_SHIFT)) & SYSCON_STARTER_ITRC_IRQ_MASK)

#define SYSCON_STARTER_FLEXINT1_MASK             (0x8000U)
#define SYSCON_STARTER_FLEXINT1_SHIFT            (15U)
/*! FLEXINT1 - FLEXINT1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT1_SHIFT)) & SYSCON_STARTER_FLEXINT1_MASK)

#define SYSCON_STARTER_HS_CMP2_IRQ_MASK          (0x8000U)
#define SYSCON_STARTER_HS_CMP2_IRQ_SHIFT         (15U)
/*! HS_CMP2_IRQ - HS_CMP2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_HS_CMP2_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_HS_CMP2_IRQ_SHIFT)) & SYSCON_STARTER_HS_CMP2_IRQ_MASK)

#define SYSCON_STARTER_ELS_ERR_MASK              (0x10000U)
#define SYSCON_STARTER_ELS_ERR_SHIFT             (16U)
/*! ELS_ERR - ELS error interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ELS_ERR(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ELS_ERR_SHIFT)) & SYSCON_STARTER_ELS_ERR_MASK)

#define SYSCON_STARTER_FLEXINT2_MASK             (0x10000U)
#define SYSCON_STARTER_FLEXINT2_SHIFT            (16U)
/*! FLEXINT2 - FLEXINT2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT2_SHIFT)) & SYSCON_STARTER_FLEXINT2_MASK)

#define SYSCON_STARTER_FLEXPWM0_CAPTURE_IRQ_MASK (0x10000U)
#define SYSCON_STARTER_FLEXPWM0_CAPTURE_IRQ_SHIFT (16U)
/*! FLEXPWM0_CAPTURE_IRQ - FlexPWM0 capture interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_CAPTURE_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_CAPTURE_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_CAPTURE_IRQ_MASK)

#define SYSCON_STARTER_FLEXINT3_MASK             (0x20000U)
#define SYSCON_STARTER_FLEXINT3_SHIFT            (17U)
/*! FLEXINT3 - FLEXINT3 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT3_SHIFT)) & SYSCON_STARTER_FLEXINT3_MASK)

#define SYSCON_STARTER_FLEXPWM0_FAULT_IRQ_MASK   (0x20000U)
#define SYSCON_STARTER_FLEXPWM0_FAULT_IRQ_SHIFT  (17U)
/*! FLEXPWM0_FAULT_IRQ - FlexPWM0 fault interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_FAULT_IRQ(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_FAULT_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_FAULT_IRQ_MASK)

#define SYSCON_STARTER_PKC_ERR_IRQ_MASK          (0x20000U)
#define SYSCON_STARTER_PKC_ERR_IRQ_SHIFT         (17U)
/*! PKC_ERR_IRQ - PKC error interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PKC_ERR_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PKC_ERR_IRQ_SHIFT)) & SYSCON_STARTER_PKC_ERR_IRQ_MASK)

#define SYSCON_STARTER_SEC_HYPERVISOR_CALL_MASK  (0x20000U)
#define SYSCON_STARTER_SEC_HYPERVISOR_CALL_SHIFT (17U)
/*! SEC_HYPERVISOR_CALL - SEC_HYPERVISOR_CALL interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_HYPERVISOR_CALL(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_HYPERVISOR_CALL_SHIFT)) & SYSCON_STARTER_SEC_HYPERVISOR_CALL_MASK)

#define SYSCON_STARTER_FLEXINT4_MASK             (0x40000U)
#define SYSCON_STARTER_FLEXINT4_SHIFT            (18U)
/*! FLEXINT4 - FLEXINT4 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT4(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT4_SHIFT)) & SYSCON_STARTER_FLEXINT4_MASK)

#define SYSCON_STARTER_FLEXPWM0_RELOAD_ERR_IRQ_MASK (0x40000U)
#define SYSCON_STARTER_FLEXPWM0_RELOAD_ERR_IRQ_SHIFT (18U)
/*! FLEXPWM0_RELOAD_ERR_IRQ - FlexPWM0 reload error interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_RELOAD_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_RELOAD_ERR_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_RELOAD_ERR_IRQ_MASK)

#define SYSCON_STARTER_PVTVF0_AMBER_IRQ_MASK     (0x40000U)
#define SYSCON_STARTER_PVTVF0_AMBER_IRQ_SHIFT    (18U)
/*! PVTVF0_AMBER_IRQ - PVTVF0 amber interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PVTVF0_AMBER_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PVTVF0_AMBER_IRQ_SHIFT)) & SYSCON_STARTER_PVTVF0_AMBER_IRQ_MASK)

#define SYSCON_STARTER_SEC_GPIO_INT00_MASK       (0x40000U)
#define SYSCON_STARTER_SEC_GPIO_INT00_SHIFT      (18U)
/*! SEC_GPIO_INT00 - SEC_GPIO_INT00 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_GPIO_INT00(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_GPIO_INT00_SHIFT)) & SYSCON_STARTER_SEC_GPIO_INT00_MASK)

#define SYSCON_STARTER_FLEXINT5_MASK             (0x80000U)
#define SYSCON_STARTER_FLEXINT5_SHIFT            (19U)
/*! FLEXINT5 - FLEXINT5 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT5(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT5_SHIFT)) & SYSCON_STARTER_FLEXINT5_MASK)

#define SYSCON_STARTER_FLEXPWM0_COMPARE0_IRQ_MASK (0x80000U)
#define SYSCON_STARTER_FLEXPWM0_COMPARE0_IRQ_SHIFT (19U)
/*! FLEXPWM0_COMPARE0_IRQ - FlexPWM0 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_COMPARE0_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_COMPARE0_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_COMPARE0_IRQ_MASK)

#define SYSCON_STARTER_PVTVF0_RED_IRQ_MASK       (0x80000U)
#define SYSCON_STARTER_PVTVF0_RED_IRQ_SHIFT      (19U)
/*! PVTVF0_RED_IRQ - PVTVF0 red interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PVTVF0_RED_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PVTVF0_RED_IRQ_SHIFT)) & SYSCON_STARTER_PVTVF0_RED_IRQ_MASK)

#define SYSCON_STARTER_SEC_GPIO_INT01_MASK       (0x80000U)
#define SYSCON_STARTER_SEC_GPIO_INT01_SHIFT      (19U)
/*! SEC_GPIO_INT01 - SEC_GPIO_INT01 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_GPIO_INT01(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_GPIO_INT01_SHIFT)) & SYSCON_STARTER_SEC_GPIO_INT01_MASK)

#define SYSCON_STARTER_FLEXINT6_MASK             (0x100000U)
#define SYSCON_STARTER_FLEXINT6_SHIFT            (20U)
/*! FLEXINT6 - FLEXINT6 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT6(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT6_SHIFT)) & SYSCON_STARTER_FLEXINT6_MASK)

#define SYSCON_STARTER_FLEXPWM0_RELOAD0_IRQ_MASK (0x100000U)
#define SYSCON_STARTER_FLEXPWM0_RELOAD0_IRQ_SHIFT (20U)
/*! FLEXPWM0_RELOAD0_IRQ - FlexPWM0 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_RELOAD0_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_RELOAD0_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_RELOAD0_IRQ_MASK)

#define SYSCON_STARTER_FREQ_ME_PLUS_MASK         (0x100000U)
#define SYSCON_STARTER_FREQ_ME_PLUS_SHIFT        (20U)
/*! FREQ_ME_PLUS - FREQME interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FREQ_ME_PLUS(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FREQ_ME_PLUS_SHIFT)) & SYSCON_STARTER_FREQ_ME_PLUS_MASK)

#define SYSCON_STARTER_PVTVF1_AMBER_IRQ_MASK     (0x100000U)
#define SYSCON_STARTER_PVTVF1_AMBER_IRQ_SHIFT    (20U)
/*! PVTVF1_AMBER_IRQ - PVTVF1 amber interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PVTVF1_AMBER_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PVTVF1_AMBER_IRQ_SHIFT)) & SYSCON_STARTER_PVTVF1_AMBER_IRQ_MASK)

#define SYSCON_STARTER_FLEXINT7_MASK             (0x200000U)
#define SYSCON_STARTER_FLEXINT7_SHIFT            (21U)
/*! FLEXINT7 - FLEXINT7 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT7(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT7_SHIFT)) & SYSCON_STARTER_FLEXINT7_MASK)

#define SYSCON_STARTER_FLEXPWM0_COMPARE1_IRQ_MASK (0x200000U)
#define SYSCON_STARTER_FLEXPWM0_COMPARE1_IRQ_SHIFT (21U)
/*! FLEXPWM0_COMPARE1_IRQ - FlexPWM0 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_COMPARE1_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_COMPARE1_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_COMPARE1_IRQ_MASK)

#define SYSCON_STARTER_PVTVF1_RED_IRQ_MASK       (0x200000U)
#define SYSCON_STARTER_PVTVF1_RED_IRQ_SHIFT      (21U)
/*! PVTVF1_RED_IRQ - PVTVF1 red interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PVTVF1_RED_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PVTVF1_RED_IRQ_SHIFT)) & SYSCON_STARTER_PVTVF1_RED_IRQ_MASK)

#define SYSCON_STARTER_SEC_VIO_MASK              (0x200000U)
#define SYSCON_STARTER_SEC_VIO_SHIFT             (21U)
/*! SEC_VIO - SEC_VIO interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_VIO(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_VIO_SHIFT)) & SYSCON_STARTER_SEC_VIO_MASK)

#define SYSCON_STARTER_ADC0_MASK                 (0x400000U)
#define SYSCON_STARTER_ADC0_SHIFT                (22U)
/*! ADC0 - ADC0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ADC0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC0_SHIFT)) & SYSCON_STARTER_ADC0_MASK)

#define SYSCON_STARTER_FLEXPWM0_RELOAD1_IRQ_MASK (0x400000U)
#define SYSCON_STARTER_FLEXPWM0_RELOAD1_IRQ_SHIFT (22U)
/*! FLEXPWM0_RELOAD1_IRQ - FlexPWM0 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_RELOAD1_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_RELOAD1_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_RELOAD1_IRQ_MASK)

#define SYSCON_STARTER_SHA_MASK                  (0x400000U)
#define SYSCON_STARTER_SHA_SHIFT                 (22U)
/*! SHA - SHA interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SHA(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SHA_SHIFT)) & SYSCON_STARTER_SHA_MASK)

#define SYSCON_STARTER_ADC1_MASK                 (0x800000U)
#define SYSCON_STARTER_ADC1_SHIFT                (23U)
/*! ADC1 - ADC1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ADC1(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ADC1_SHIFT)) & SYSCON_STARTER_ADC1_MASK)

#define SYSCON_STARTER_FLEXPWM0_COMPARE2_IRQ_MASK (0x800000U)
#define SYSCON_STARTER_FLEXPWM0_COMPARE2_IRQ_SHIFT (23U)
/*! FLEXPWM0_COMPARE2_IRQ - FlexPWM0 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_COMPARE2_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_COMPARE2_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_COMPARE2_IRQ_MASK)

#define SYSCON_STARTER_PKC_MASK                  (0x800000U)
#define SYSCON_STARTER_PKC_SHIFT                 (23U)
/*! PKC - PKC interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PKC(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PKC_SHIFT)) & SYSCON_STARTER_PKC_MASK)

#define SYSCON_STARTER_ACMP_OVR_MASK             (0x1000000U)
#define SYSCON_STARTER_ACMP_OVR_SHIFT            (24U)
/*! ACMP_OVR - ACMP_OVR interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_ACMP_OVR(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_ACMP_OVR_SHIFT)) & SYSCON_STARTER_ACMP_OVR_MASK)

#define SYSCON_STARTER_FLEXPWM0_RELOAD2_IRQ_MASK (0x1000000U)
#define SYSCON_STARTER_FLEXPWM0_RELOAD2_IRQ_SHIFT (24U)
/*! FLEXPWM0_RELOAD2_IRQ - FlexPWM0 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_RELOAD2_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_RELOAD2_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_RELOAD2_IRQ_MASK)

#define SYSCON_STARTER_QDDKEY_MASK               (0x1000000U)
#define SYSCON_STARTER_QDDKEY_SHIFT              (24U)
/*! QDDKEY - QDDKEY interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_QDDKEY(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_QDDKEY_SHIFT)) & SYSCON_STARTER_QDDKEY_MASK)

#define SYSCON_STARTER_DMIC_MASK                 (0x2000000U)
#define SYSCON_STARTER_DMIC_SHIFT                (25U)
/*! DMIC - DMIC interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_DMIC(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_DMIC_SHIFT)) & SYSCON_STARTER_DMIC_MASK)

#define SYSCON_STARTER_FLEXPWM0_COMPARE3_IRQ_MASK (0x2000000U)
#define SYSCON_STARTER_FLEXPWM0_COMPARE3_IRQ_SHIFT (25U)
/*! FLEXPWM0_COMPARE3_IRQ - FlexPWM0 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_COMPARE3_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_COMPARE3_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_COMPARE3_IRQ_MASK)

#define SYSCON_STARTER_PQ_MASK                   (0x2000000U)
#define SYSCON_STARTER_PQ_SHIFT                  (25U)
/*! PQ - PQ interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PQ(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PQ_SHIFT)) & SYSCON_STARTER_PQ_MASK)

#define SYSCON_STARTER_FLEXPWM0_RELOAD3_IRQ_MASK (0x4000000U)
#define SYSCON_STARTER_FLEXPWM0_RELOAD3_IRQ_SHIFT (26U)
/*! FLEXPWM0_RELOAD3_IRQ - FlexPWM0 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM0_RELOAD3_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM0_RELOAD3_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM0_RELOAD3_IRQ_MASK)

#define SYSCON_STARTER_SDMA1_MASK                (0x4000000U)
#define SYSCON_STARTER_SDMA1_SHIFT               (26U)
/*! SDMA1 - SDMA1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SDMA1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SDMA1_SHIFT)) & SYSCON_STARTER_SDMA1_MASK)

#define SYSCON_STARTER_FLEXPWM1_CAPTURE_IRQ_MASK (0x8000000U)
#define SYSCON_STARTER_FLEXPWM1_CAPTURE_IRQ_SHIFT (27U)
/*! FLEXPWM1_CAPTURE_IRQ - FlexPWM1 capture interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_CAPTURE_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_CAPTURE_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_CAPTURE_IRQ_MASK)

#define SYSCON_STARTER_SPI_HS_MASK               (0x8000000U)
#define SYSCON_STARTER_SPI_HS_SHIFT              (27U)
/*! SPI_HS - SPI_HS interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SPI_HS(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SPI_HS_SHIFT)) & SYSCON_STARTER_SPI_HS_MASK)

#define SYSCON_STARTER_USB0_NEEDCLK_MASK         (0x8000000U)
#define SYSCON_STARTER_USB0_NEEDCLK_SHIFT        (27U)
/*! USB0_NEEDCLK - USB0_NEEDCLK interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_USB0_NEEDCLK(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB0_NEEDCLK_SHIFT)) & SYSCON_STARTER_USB0_NEEDCLK_MASK)

#define SYSCON_STARTER_CODE_WDG0_MASK            (0x10000000U)
#define SYSCON_STARTER_CODE_WDG0_SHIFT           (28U)
/*! CODE_WDG0 - CODE WDG0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CODE_WDG0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CODE_WDG0_SHIFT)) & SYSCON_STARTER_CODE_WDG0_MASK)

#define SYSCON_STARTER_FLEXPWM1_FAULT_IRQ_MASK   (0x10000000U)
#define SYSCON_STARTER_FLEXPWM1_FAULT_IRQ_SHIFT  (28U)
/*! FLEXPWM1_FAULT_IRQ - FlexPWM1 fault interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_FAULT_IRQ(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_FAULT_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_FAULT_IRQ_MASK)

#define SYSCON_STARTER_USB0_MASK                 (0x10000000U)
#define SYSCON_STARTER_USB0_SHIFT                (28U)
/*! USB0 - USB0-FS interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_USB0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_USB0_SHIFT)) & SYSCON_STARTER_USB0_MASK)

#define SYSCON_STARTER_FLEXPWM1_RELOAD_ERR_IRQ_MASK (0x20000000U)
#define SYSCON_STARTER_FLEXPWM1_RELOAD_ERR_IRQ_SHIFT (29U)
/*! FLEXPWM1_RELOAD_ERR_IRQ - FlexPWM1 reload error interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_RELOAD_ERR_IRQ(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_RELOAD_ERR_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_RELOAD_ERR_IRQ_MASK)

#define SYSCON_STARTER_RTC_LITE0_MASK            (0x20000000U)
#define SYSCON_STARTER_RTC_LITE0_SHIFT           (29U)
/*! RTC_LITE0 - RTC_LITE0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_RTC_LITE0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_RTC_LITE0_SHIFT)) & SYSCON_STARTER_RTC_LITE0_MASK)

#define SYSCON_STARTER_FLEXPWM1_COMPARE0_IRQ_MASK (0x40000000U)
#define SYSCON_STARTER_FLEXPWM1_COMPARE0_IRQ_SHIFT (30U)
/*! FLEXPWM1_COMPARE0_IRQ - FlexPWM1 compare interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_COMPARE0_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_COMPARE0_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_COMPARE0_IRQ_MASK)

#define SYSCON_STARTER_I3C0_MASK                 (0x40000000U)
#define SYSCON_STARTER_I3C0_SHIFT                (30U)
/*! I3C0 - I3C0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_I3C0(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_I3C0_SHIFT)) & SYSCON_STARTER_I3C0_MASK)

#define SYSCON_STARTER_FLEXPWM1_RELOAD0_IRQ_MASK (0x80000000U)
#define SYSCON_STARTER_FLEXPWM1_RELOAD0_IRQ_SHIFT (31U)
/*! FLEXPWM1_RELOAD0_IRQ - FlexPWM1 reload interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXPWM1_RELOAD0_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXPWM1_RELOAD0_IRQ_SHIFT)) & SYSCON_STARTER_FLEXPWM1_RELOAD0_IRQ_MASK)

#define SYSCON_STARTER_WAKEUP_MAILBOX0_MASK      (0x80000000U)
#define SYSCON_STARTER_WAKEUP_MAILBOX0_SHIFT     (31U)
/*! WAKEUP_MAILBOX0 - WAKEUP_MAILBOX0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_WAKEUP_MAILBOX0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_WAKEUP_MAILBOX0_SHIFT)) & SYSCON_STARTER_WAKEUP_MAILBOX0_MASK)
/*! @} */

/*! @name STARTERSET - Set bits in STARTER */
/*! @{ */

#define SYSCON_STARTERSET_FLEXPWM1_COMPARE1_SET_MASK (0x1U)
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE1_SET_SHIFT (0U)
/*! FLEXPWM1_COMPARE1_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE1_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_COMPARE1_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_COMPARE1_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT04_SET_MASK    (0x1U)
#define SYSCON_STARTERSET_GPIO_INT04_SET_SHIFT   (0U)
/*! GPIO_INT04_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT04_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT04_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT04_SET_MASK)

#define SYSCON_STARTERSET_SYS_SET_MASK           (0x1U)
#define SYSCON_STARTERSET_SYS_SET_SHIFT          (0U)
/*! SYS_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_SYS_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SYS_SET_SHIFT)) & SYSCON_STARTERSET_SYS_SET_MASK)

#define SYSCON_STARTERSET_ELS_SET_MASK           (0x2U)
#define SYSCON_STARTERSET_ELS_SET_SHIFT          (1U)
/*! ELS_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_ELS_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ELS_SET_SHIFT)) & SYSCON_STARTERSET_ELS_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_RELOAD1_SET_MASK (0x2U)
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD1_SET_SHIFT (1U)
/*! FLEXPWM1_RELOAD1_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD1_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_RELOAD1_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_RELOAD1_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT05_SET_MASK    (0x2U)
#define SYSCON_STARTERSET_GPIO_INT05_SET_SHIFT   (1U)
/*! GPIO_INT05_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT05_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT05_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT05_SET_MASK)

#define SYSCON_STARTERSET_SDMA0_SET_MASK         (0x2U)
#define SYSCON_STARTERSET_SDMA0_SET_SHIFT        (1U)
/*! SDMA0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_SDMA0_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SDMA0_SET_SHIFT)) & SYSCON_STARTERSET_SDMA0_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_COMPARE2_SET_MASK (0x4U)
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE2_SET_SHIFT (2U)
/*! FLEXPWM1_COMPARE2_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE2_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_COMPARE2_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_COMPARE2_SET_MASK)

#define SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_MASK (0x4U)
#define SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_SHIFT (2U)
/*! GPIO_GLOBALINT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_GLOBALINT0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT06_SET_MASK    (0x4U)
#define SYSCON_STARTERSET_GPIO_INT06_SET_SHIFT   (2U)
/*! GPIO_INT06_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT06_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT06_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT06_SET_MASK)

#define SYSCON_STARTERSET_TAMPER_SET_MASK        (0x4U)
#define SYSCON_STARTERSET_TAMPER_SET_SHIFT       (2U)
/*! TAMPER_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_TAMPER_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_TAMPER_SET_SHIFT)) & SYSCON_STARTERSET_TAMPER_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_RELOAD2_SET_MASK (0x8U)
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD2_SET_SHIFT (3U)
/*! FLEXPWM1_RELOAD2_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD2_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_RELOAD2_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_RELOAD2_SET_MASK)

#define SYSCON_STARTERSET_GPIO_GLOBALINT1_SET_MASK (0x8U)
#define SYSCON_STARTERSET_GPIO_GLOBALINT1_SET_SHIFT (3U)
/*! GPIO_GLOBALINT1_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_GLOBALINT1_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_GLOBALINT1_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_GLOBALINT1_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT07_SET_MASK    (0x8U)
#define SYSCON_STARTERSET_GPIO_INT07_SET_SHIFT   (3U)
/*! GPIO_INT07_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT07_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT07_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT07_SET_MASK)

#define SYSCON_STARTERSET_CTIMER2_SET_MASK       (0x10U)
#define SYSCON_STARTERSET_CTIMER2_SET_SHIFT      (4U)
/*! CTIMER2_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_CTIMER2_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER2_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER2_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_COMPARE3_SET_MASK (0x10U)
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE3_SET_SHIFT (4U)
/*! FLEXPWM1_COMPARE3_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE3_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_COMPARE3_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_COMPARE3_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT00_SET_MASK    (0x10U)
#define SYSCON_STARTERSET_GPIO_INT00_SET_SHIFT   (4U)
/*! GPIO_INT00_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT00_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT00_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT00_SET_MASK)

#define SYSCON_STARTERSET_CTIMER4_SET_MASK       (0x20U)
#define SYSCON_STARTERSET_CTIMER4_SET_SHIFT      (5U)
/*! CTIMER4_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_CTIMER4_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER4_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER4_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_RELOAD3_SET_MASK (0x20U)
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD3_SET_SHIFT (5U)
/*! FLEXPWM1_RELOAD3_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD3_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_RELOAD3_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_RELOAD3_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT01_SET_MASK    (0x20U)
#define SYSCON_STARTERSET_GPIO_INT01_SET_SHIFT   (5U)
/*! GPIO_INT01_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT01_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT01_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT01_SET_MASK)

#define SYSCON_STARTERSET_ENC0_COMPARE_SET_MASK  (0x40U)
#define SYSCON_STARTERSET_ENC0_COMPARE_SET_SHIFT (6U)
/*! ENC0_COMPARE_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC0_COMPARE_SET(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC0_COMPARE_SET_SHIFT)) & SYSCON_STARTERSET_ENC0_COMPARE_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT02_SET_MASK    (0x40U)
#define SYSCON_STARTERSET_GPIO_INT02_SET_SHIFT   (6U)
/*! GPIO_INT02_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT02_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT02_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT02_SET_MASK)

#define SYSCON_STARTERSET_OS_EVENT_SET_MASK      (0x40U)
#define SYSCON_STARTERSET_OS_EVENT_SET_SHIFT     (6U)
/*! OS_EVENT_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_OS_EVENT_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_OS_EVENT_SET_SHIFT)) & SYSCON_STARTERSET_OS_EVENT_SET_MASK)

#define SYSCON_STARTERSET_ENC0_HOME_SET_MASK     (0x80U)
#define SYSCON_STARTERSET_ENC0_HOME_SET_SHIFT    (7U)
/*! ENC0_HOME_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC0_HOME_SET(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC0_HOME_SET_SHIFT)) & SYSCON_STARTERSET_ENC0_HOME_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT03_SET_MASK    (0x80U)
#define SYSCON_STARTERSET_GPIO_INT03_SET_SHIFT   (7U)
/*! GPIO_INT03_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT03_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT03_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT03_SET_MASK)

#define SYSCON_STARTERSET_ENC0_WDG_SET_MASK      (0x100U)
#define SYSCON_STARTERSET_ENC0_WDG_SET_SHIFT     (8U)
/*! ENC0_WDG_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC0_WDG_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC0_WDG_SET_SHIFT)) & SYSCON_STARTERSET_ENC0_WDG_SET_MASK)

#define SYSCON_STARTERSET_UTICK0_SET_MASK        (0x100U)
#define SYSCON_STARTERSET_UTICK0_SET_SHIFT       (8U)
/*! UTICK0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_UTICK0_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_UTICK0_SET_SHIFT)) & SYSCON_STARTERSET_UTICK0_SET_MASK)

#define SYSCON_STARTERSET_ENC0_IDX_SET_MASK      (0x200U)
#define SYSCON_STARTERSET_ENC0_IDX_SET_SHIFT     (9U)
/*! ENC0_IDX_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC0_IDX_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC0_IDX_SET_SHIFT)) & SYSCON_STARTERSET_ENC0_IDX_SET_MASK)

#define SYSCON_STARTERSET_MRT0_SET_MASK          (0x200U)
#define SYSCON_STARTERSET_MRT0_SET_SHIFT         (9U)
/*! MRT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_MRT0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_MRT0_SET_SHIFT)) & SYSCON_STARTERSET_MRT0_SET_MASK)

#define SYSCON_STARTERSET_CTIMER0_SET_MASK       (0x400U)
#define SYSCON_STARTERSET_CTIMER0_SET_SHIFT      (10U)
/*! CTIMER0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_CTIMER0_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER0_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER0_SET_MASK)

#define SYSCON_STARTERSET_DAC0_SET_MASK          (0x400U)
#define SYSCON_STARTERSET_DAC0_SET_SHIFT         (10U)
/*! DAC0_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_DAC0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_DAC0_SET_SHIFT)) & SYSCON_STARTERSET_DAC0_SET_MASK)

#define SYSCON_STARTERSET_ENC1_COMPARE_SET_MASK  (0x400U)
#define SYSCON_STARTERSET_ENC1_COMPARE_SET_SHIFT (10U)
/*! ENC1_COMPARE_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC1_COMPARE_SET(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC1_COMPARE_SET_SHIFT)) & SYSCON_STARTERSET_ENC1_COMPARE_SET_MASK)

#define SYSCON_STARTERSET_CTIMER1_SET_MASK       (0x800U)
#define SYSCON_STARTERSET_CTIMER1_SET_SHIFT      (11U)
/*! CTIMER1_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_CTIMER1_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER1_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER1_SET_MASK)

#define SYSCON_STARTERSET_DAC1_SET_MASK          (0x800U)
#define SYSCON_STARTERSET_DAC1_SET_SHIFT         (11U)
/*! DAC1_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_DAC1_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_DAC1_SET_SHIFT)) & SYSCON_STARTERSET_DAC1_SET_MASK)

#define SYSCON_STARTERSET_ENC1_HOME_SET_MASK     (0x800U)
#define SYSCON_STARTERSET_ENC1_HOME_SET_SHIFT    (11U)
/*! ENC1_HOME_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC1_HOME_SET(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC1_HOME_SET_SHIFT)) & SYSCON_STARTERSET_ENC1_HOME_SET_MASK)

#define SYSCON_STARTERSET_DAC2_SET_MASK          (0x1000U)
#define SYSCON_STARTERSET_DAC2_SET_SHIFT         (12U)
/*! DAC2_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_DAC2_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_DAC2_SET_SHIFT)) & SYSCON_STARTERSET_DAC2_SET_MASK)

#define SYSCON_STARTERSET_ENC1_WDG_SET_MASK      (0x1000U)
#define SYSCON_STARTERSET_ENC1_WDG_SET_SHIFT     (12U)
/*! ENC1_WDG_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC1_WDG_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC1_WDG_SET_SHIFT)) & SYSCON_STARTERSET_ENC1_WDG_SET_MASK)

#define SYSCON_STARTERSET_SCT0_SET_MASK          (0x1000U)
#define SYSCON_STARTERSET_SCT0_SET_SHIFT         (12U)
/*! SCT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_SCT0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SCT0_SET_SHIFT)) & SYSCON_STARTERSET_SCT0_SET_MASK)

#define SYSCON_STARTERSET_CTIMER3_SET_MASK       (0x2000U)
#define SYSCON_STARTERSET_CTIMER3_SET_SHIFT      (13U)
/*! CTIMER3_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_CTIMER3_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER3_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER3_SET_MASK)

#define SYSCON_STARTERSET_ENC1_IDX_SET_MASK      (0x2000U)
#define SYSCON_STARTERSET_ENC1_IDX_SET_SHIFT     (13U)
/*! ENC1_IDX_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ENC1_IDX_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ENC1_IDX_SET_SHIFT)) & SYSCON_STARTERSET_ENC1_IDX_SET_MASK)

#define SYSCON_STARTERSET_HS_CMP0_SET_MASK       (0x2000U)
#define SYSCON_STARTERSET_HS_CMP0_SET_SHIFT      (13U)
/*! HS_CMP0_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_HS_CMP0_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_HS_CMP0_SET_SHIFT)) & SYSCON_STARTERSET_HS_CMP0_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT0_SET_MASK      (0x4000U)
#define SYSCON_STARTERSET_FLEXINT0_SET_SHIFT     (14U)
/*! FLEXINT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT0_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT0_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT0_SET_MASK)

#define SYSCON_STARTERSET_HS_CMP1_SET_MASK       (0x4000U)
#define SYSCON_STARTERSET_HS_CMP1_SET_SHIFT      (14U)
/*! HS_CMP1_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_HS_CMP1_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_HS_CMP1_SET_SHIFT)) & SYSCON_STARTERSET_HS_CMP1_SET_MASK)

#define SYSCON_STARTERSET_ITRC_SET_MASK          (0x4000U)
#define SYSCON_STARTERSET_ITRC_SET_SHIFT         (14U)
/*! ITRC_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ITRC_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ITRC_SET_SHIFT)) & SYSCON_STARTERSET_ITRC_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT1_SET_MASK      (0x8000U)
#define SYSCON_STARTERSET_FLEXINT1_SET_SHIFT     (15U)
/*! FLEXINT1_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT1_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT1_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT1_SET_MASK)

#define SYSCON_STARTERSET_HS_CMP2_SET_MASK       (0x8000U)
#define SYSCON_STARTERSET_HS_CMP2_SET_SHIFT      (15U)
/*! HS_CMP2_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_HS_CMP2_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_HS_CMP2_SET_SHIFT)) & SYSCON_STARTERSET_HS_CMP2_SET_MASK)

#define SYSCON_STARTERSET_ELS_ERR_SET_MASK       (0x10000U)
#define SYSCON_STARTERSET_ELS_ERR_SET_SHIFT      (16U)
/*! ELS_ERR_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_ELS_ERR_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ELS_ERR_SET_SHIFT)) & SYSCON_STARTERSET_ELS_ERR_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT2_SET_MASK      (0x10000U)
#define SYSCON_STARTERSET_FLEXINT2_SET_SHIFT     (16U)
/*! FLEXINT2_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT2_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT2_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT2_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_CAPTURE_SET_MASK (0x10000U)
#define SYSCON_STARTERSET_FLEXPWM0_CAPTURE_SET_SHIFT (16U)
/*! FLEXPWM0_CAPTURE_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_CAPTURE_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_CAPTURE_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_CAPTURE_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT3_SET_MASK      (0x20000U)
#define SYSCON_STARTERSET_FLEXINT3_SET_SHIFT     (17U)
/*! FLEXINT3_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT3_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT3_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT3_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_FAULT_SET_MASK (0x20000U)
#define SYSCON_STARTERSET_FLEXPWM0_FAULT_SET_SHIFT (17U)
/*! FLEXPWM0_FAULT_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_FAULT_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_FAULT_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_FAULT_SET_MASK)

#define SYSCON_STARTERSET_PKC_ERR_SET_MASK       (0x20000U)
#define SYSCON_STARTERSET_PKC_ERR_SET_SHIFT      (17U)
/*! PKC_ERR_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_PKC_ERR_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PKC_ERR_SET_SHIFT)) & SYSCON_STARTERSET_PKC_ERR_SET_MASK)

#define SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_MASK (0x20000U)
#define SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_SHIFT (17U)
/*! SEC_HYPERVISOR_CALL_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_SHIFT)) & SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT4_SET_MASK      (0x40000U)
#define SYSCON_STARTERSET_FLEXINT4_SET_SHIFT     (18U)
/*! FLEXINT4_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT4_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT4_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT4_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_RELOAD_ERROR_SET_MASK (0x40000U)
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD_ERROR_SET_SHIFT (18U)
/*! FLEXPWM0_RELOAD_ERROR_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD_ERROR_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_RELOAD_ERROR_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_RELOAD_ERROR_SET_MASK)

#define SYSCON_STARTERSET_PVTVF0_AMBER_SET_MASK  (0x40000U)
#define SYSCON_STARTERSET_PVTVF0_AMBER_SET_SHIFT (18U)
/*! PVTVF0_AMBER_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_PVTVF0_AMBER_SET(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PVTVF0_AMBER_SET_SHIFT)) & SYSCON_STARTERSET_PVTVF0_AMBER_SET_MASK)

#define SYSCON_STARTERSET_SEC_GPIO_INT00_SET_MASK (0x40000U)
#define SYSCON_STARTERSET_SEC_GPIO_INT00_SET_SHIFT (18U)
/*! SEC_GPIO_INT00_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_GPIO_INT00_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_GPIO_INT00_SET_SHIFT)) & SYSCON_STARTERSET_SEC_GPIO_INT00_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT5_SET_MASK      (0x80000U)
#define SYSCON_STARTERSET_FLEXINT5_SET_SHIFT     (19U)
/*! FLEXINT5_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT5_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT5_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT5_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_COMPARE0_SET_MASK (0x80000U)
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE0_SET_SHIFT (19U)
/*! FLEXPWM0_COMPARE0_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_COMPARE0_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_COMPARE0_SET_MASK)

#define SYSCON_STARTERSET_PVTVF0_RED_SET_MASK    (0x80000U)
#define SYSCON_STARTERSET_PVTVF0_RED_SET_SHIFT   (19U)
/*! PVTVF0_RED_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_PVTVF0_RED_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PVTVF0_RED_SET_SHIFT)) & SYSCON_STARTERSET_PVTVF0_RED_SET_MASK)

#define SYSCON_STARTERSET_SEC_GPIO_INT01_SET_MASK (0x80000U)
#define SYSCON_STARTERSET_SEC_GPIO_INT01_SET_SHIFT (19U)
/*! SEC_GPIO_INT01_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_GPIO_INT01_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_GPIO_INT01_SET_SHIFT)) & SYSCON_STARTERSET_SEC_GPIO_INT01_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT6_SET_MASK      (0x100000U)
#define SYSCON_STARTERSET_FLEXINT6_SET_SHIFT     (20U)
/*! FLEXINT6_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT6_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT6_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT6_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_RELOAD0_SET_MASK (0x100000U)
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD0_SET_SHIFT (20U)
/*! FLEXPWM0_RELOAD0_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_RELOAD0_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_RELOAD0_SET_MASK)

#define SYSCON_STARTERSET_PVTVF1_AMBER_SET_MASK  (0x100000U)
#define SYSCON_STARTERSET_PVTVF1_AMBER_SET_SHIFT (20U)
/*! PVTVF1_AMBER_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_PVTVF1_AMBER_SET(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PVTVF1_AMBER_SET_SHIFT)) & SYSCON_STARTERSET_PVTVF1_AMBER_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT7_SET_MASK      (0x200000U)
#define SYSCON_STARTERSET_FLEXINT7_SET_SHIFT     (21U)
/*! FLEXINT7_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT7_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT7_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT7_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_COMPARE1_SET_MASK (0x200000U)
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE1_SET_SHIFT (21U)
/*! FLEXPWM0_COMPARE1_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE1_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_COMPARE1_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_COMPARE1_SET_MASK)

#define SYSCON_STARTERSET_PVTVF1_RED_SET_MASK    (0x200000U)
#define SYSCON_STARTERSET_PVTVF1_RED_SET_SHIFT   (21U)
/*! PVTVF1_RED_SET - Writing ones to this register sets the corresponding bit in the STARTER3 register. */
#define SYSCON_STARTERSET_PVTVF1_RED_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PVTVF1_RED_SET_SHIFT)) & SYSCON_STARTERSET_PVTVF1_RED_SET_MASK)

#define SYSCON_STARTERSET_ADC0_SET_MASK          (0x400000U)
#define SYSCON_STARTERSET_ADC0_SET_SHIFT         (22U)
/*! ADC0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_ADC0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ADC0_SET_SHIFT)) & SYSCON_STARTERSET_ADC0_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_RELOAD1_SET_MASK (0x400000U)
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD1_SET_SHIFT (22U)
/*! FLEXPWM0_RELOAD1_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD1_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_RELOAD1_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_RELOAD1_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_COMPARE2_SET_MASK (0x800000U)
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE2_SET_SHIFT (23U)
/*! FLEXPWM0_COMPARE2_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE2_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_COMPARE2_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_COMPARE2_SET_MASK)

#define SYSCON_STARTERSET_ADC0_THCMP_OVR_SET_MASK (0x1000000U)
#define SYSCON_STARTERSET_ADC0_THCMP_OVR_SET_SHIFT (24U)
/*! ADC0_THCMP_OVR_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_ADC0_THCMP_OVR_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_ADC0_THCMP_OVR_SET_SHIFT)) & SYSCON_STARTERSET_ADC0_THCMP_OVR_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_RELOAD2_SET_MASK (0x1000000U)
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD2_SET_SHIFT (24U)
/*! FLEXPWM0_RELOAD2_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD2_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_RELOAD2_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_RELOAD2_SET_MASK)

#define SYSCON_STARTERSET_QDDKEY_SET_MASK        (0x1000000U)
#define SYSCON_STARTERSET_QDDKEY_SET_SHIFT       (24U)
/*! QDDKEY_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_QDDKEY_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_QDDKEY_SET_SHIFT)) & SYSCON_STARTERSET_QDDKEY_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_COMPARE3_SET_MASK (0x2000000U)
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE3_SET_SHIFT (25U)
/*! FLEXPWM0_COMPARE3_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_COMPARE3_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_COMPARE3_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_COMPARE3_SET_MASK)

#define SYSCON_STARTERSET_PQ_SET_MASK            (0x2000000U)
#define SYSCON_STARTERSET_PQ_SET_SHIFT           (25U)
/*! PQ_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_PQ_SET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PQ_SET_SHIFT)) & SYSCON_STARTERSET_PQ_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM0_RELOAD3_SET_MASK (0x4000000U)
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD3_SET_SHIFT (26U)
/*! FLEXPWM0_RELOAD3_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM0_RELOAD3_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM0_RELOAD3_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM0_RELOAD3_SET_MASK)

#define SYSCON_STARTERSET_SDMA1_SET_MASK         (0x4000000U)
#define SYSCON_STARTERSET_SDMA1_SET_SHIFT        (26U)
/*! SDMA1_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SDMA1_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SDMA1_SET_SHIFT)) & SYSCON_STARTERSET_SDMA1_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_CAPTURE_SET_MASK (0x8000000U)
#define SYSCON_STARTERSET_FLEXPWM1_CAPTURE_SET_SHIFT (27U)
/*! FLEXPWM1_CAPTURE_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM1_CAPTURE_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_CAPTURE_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_CAPTURE_SET_MASK)

#define SYSCON_STARTERSET_SPI_HS_SET_MASK        (0x8000000U)
#define SYSCON_STARTERSET_SPI_HS_SET_SHIFT       (27U)
/*! SPI_HS_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SPI_HS_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SPI_HS_SET_SHIFT)) & SYSCON_STARTERSET_SPI_HS_SET_MASK)

#define SYSCON_STARTERSET_USB0_NEEDCLK_SET_MASK  (0x8000000U)
#define SYSCON_STARTERSET_USB0_NEEDCLK_SET_SHIFT (27U)
/*! USB0_NEEDCLK_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_USB0_NEEDCLK_SET(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_USB0_NEEDCLK_SET_SHIFT)) & SYSCON_STARTERSET_USB0_NEEDCLK_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_FAULT_SET_MASK (0x10000000U)
#define SYSCON_STARTERSET_FLEXPWM1_FAULT_SET_SHIFT (28U)
/*! FLEXPWM1_FAULT_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM1_FAULT_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_FAULT_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_FAULT_SET_MASK)

#define SYSCON_STARTERSET_USB0_SET_MASK          (0x10000000U)
#define SYSCON_STARTERSET_USB0_SET_SHIFT         (28U)
/*! USB0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_USB0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_USB0_SET_SHIFT)) & SYSCON_STARTERSET_USB0_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_RELOAD_ERROR_SET_MASK (0x20000000U)
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD_ERROR_SET_SHIFT (29U)
/*! FLEXPWM1_RELOAD_ERROR_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD_ERROR_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_RELOAD_ERROR_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_RELOAD_ERROR_SET_MASK)

#define SYSCON_STARTERSET_RTC_LITE0_SET_MASK     (0x20000000U)
#define SYSCON_STARTERSET_RTC_LITE0_SET_SHIFT    (29U)
/*! RTC_LITE0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_RTC_LITE0_SET(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_RTC_LITE0_SET_SHIFT)) & SYSCON_STARTERSET_RTC_LITE0_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_COMPARE0_SET_MASK (0x40000000U)
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE0_SET_SHIFT (30U)
/*! FLEXPWM1_COMPARE0_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM1_COMPARE0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_COMPARE0_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_COMPARE0_SET_MASK)

#define SYSCON_STARTERSET_FLEXPWM1_RELOAD0_SET_MASK (0x80000000U)
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD0_SET_SHIFT (31U)
/*! FLEXPWM1_RELOAD0_SET - Writing ones to this register sets the corresponding bit in the STARTER2 register. */
#define SYSCON_STARTERSET_FLEXPWM1_RELOAD0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXPWM1_RELOAD0_SET_SHIFT)) & SYSCON_STARTERSET_FLEXPWM1_RELOAD0_SET_MASK)

#define SYSCON_STARTERSET_WAKEUPPADS_SET_MASK    (0x80000000U)
#define SYSCON_STARTERSET_WAKEUPPADS_SET_SHIFT   (31U)
/*! WAKEUPPADS_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_WAKEUPPADS_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_WAKEUPPADS_SET_SHIFT)) & SYSCON_STARTERSET_WAKEUPPADS_SET_MASK)

#define SYSCON_STARTERSET_WAKEUP_MAILBOX0_SET_MASK (0x80000000U)
#define SYSCON_STARTERSET_WAKEUP_MAILBOX0_SET_SHIFT (31U)
/*! WAKEUP_MAILBOX0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_WAKEUP_MAILBOX0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_WAKEUP_MAILBOX0_SET_SHIFT)) & SYSCON_STARTERSET_WAKEUP_MAILBOX0_SET_MASK)
/*! @} */

/*! @name STARTERCLR - Clear bits in STARTER */
/*! @{ */

#define SYSCON_STARTERCLR_GPIO_INT04_CLR_MASK    (0x1U)
#define SYSCON_STARTERCLR_GPIO_INT04_CLR_SHIFT   (0U)
/*! GPIO_INT04_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_GPIO_INT04_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT04_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT04_CLR_MASK)

#define SYSCON_STARTERCLR_SYS_CLR_MASK           (0x1U)
#define SYSCON_STARTERCLR_SYS_CLR_SHIFT          (0U)
/*! SYS_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_SYS_CLR(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SYS_CLR_SHIFT)) & SYSCON_STARTERCLR_SYS_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT05_CLR_MASK    (0x2U)
#define SYSCON_STARTERCLR_GPIO_INT05_CLR_SHIFT   (1U)
/*! GPIO_INT05_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_GPIO_INT05_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT05_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT05_CLR_MASK)

#define SYSCON_STARTERCLR_SDMA0_CLR_MASK         (0x2U)
#define SYSCON_STARTERCLR_SDMA0_CLR_SHIFT        (1U)
/*! SDMA0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_SDMA0_CLR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SDMA0_CLR_SHIFT)) & SYSCON_STARTERCLR_SDMA0_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_GLOBALINT0_CLR_MASK (0x4U)
#define SYSCON_STARTERCLR_GPIO_GLOBALINT0_CLR_SHIFT (2U)
/*! GPIO_GLOBALINT0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_GPIO_GLOBALINT0_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_GLOBALINT0_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_GLOBALINT0_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT06_CLR_MASK    (0x4U)
#define SYSCON_STARTERCLR_GPIO_INT06_CLR_SHIFT   (2U)
/*! GPIO_INT06_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_GPIO_INT06_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT06_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT06_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_GLOBALINT1_CLR_MASK (0x8U)
#define SYSCON_STARTERCLR_GPIO_GLOBALINT1_CLR_SHIFT (3U)
/*! GPIO_GLOBALINT1_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_GPIO_GLOBALINT1_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_GLOBALINT1_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_GLOBALINT1_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT07_CLR_MASK    (0x8U)
#define SYSCON_STARTERCLR_GPIO_INT07_CLR_SHIFT   (3U)
/*! GPIO_INT07_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_GPIO_INT07_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT07_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT07_CLR_MASK)

#define SYSCON_STARTERCLR_CTIMER2_CLR_MASK       (0x10U)
#define SYSCON_STARTERCLR_CTIMER2_CLR_SHIFT      (4U)
/*! CTIMER2_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_CTIMER2_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_CTIMER2_CLR_SHIFT)) & SYSCON_STARTERCLR_CTIMER2_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT00_CLR_MASK    (0x10U)
#define SYSCON_STARTERCLR_GPIO_INT00_CLR_SHIFT   (4U)
/*! GPIO_INT00_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_GPIO_INT00_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT00_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT00_CLR_MASK)

#define SYSCON_STARTERCLR_CTIMER4_CLR_MASK       (0x20U)
#define SYSCON_STARTERCLR_CTIMER4_CLR_SHIFT      (5U)
/*! CTIMER4_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_CTIMER4_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_CTIMER4_CLR_SHIFT)) & SYSCON_STARTERCLR_CTIMER4_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT01_CLR_MASK    (0x20U)
#define SYSCON_STARTERCLR_GPIO_INT01_CLR_SHIFT   (5U)
/*! GPIO_INT01_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_GPIO_INT01_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT01_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT01_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT02_CLR_MASK    (0x40U)
#define SYSCON_STARTERCLR_GPIO_INT02_CLR_SHIFT   (6U)
/*! GPIO_INT02_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_GPIO_INT02_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT02_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT02_CLR_MASK)

#define SYSCON_STARTERCLR_OS_EVENT_CLR_MASK      (0x40U)
#define SYSCON_STARTERCLR_OS_EVENT_CLR_SHIFT     (6U)
/*! OS_EVENT_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_OS_EVENT_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_OS_EVENT_CLR_SHIFT)) & SYSCON_STARTERCLR_OS_EVENT_CLR_MASK)

#define SYSCON_STARTERCLR_GPIO_INT03_CLR_MASK    (0x80U)
#define SYSCON_STARTERCLR_GPIO_INT03_CLR_SHIFT   (7U)
/*! GPIO_INT03_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_GPIO_INT03_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_GPIO_INT03_CLR_SHIFT)) & SYSCON_STARTERCLR_GPIO_INT03_CLR_MASK)

#define SYSCON_STARTERCLR_UTICK0_CLR_MASK        (0x100U)
#define SYSCON_STARTERCLR_UTICK0_CLR_SHIFT       (8U)
/*! UTICK0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_UTICK0_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_UTICK0_CLR_SHIFT)) & SYSCON_STARTERCLR_UTICK0_CLR_MASK)

#define SYSCON_STARTERCLR_MRT0_CLR_MASK          (0x200U)
#define SYSCON_STARTERCLR_MRT0_CLR_SHIFT         (9U)
/*! MRT0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_MRT0_CLR(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_MRT0_CLR_SHIFT)) & SYSCON_STARTERCLR_MRT0_CLR_MASK)

#define SYSCON_STARTERCLR_CTIMER0_CLR_MASK       (0x400U)
#define SYSCON_STARTERCLR_CTIMER0_CLR_SHIFT      (10U)
/*! CTIMER0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_CTIMER0_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_CTIMER0_CLR_SHIFT)) & SYSCON_STARTERCLR_CTIMER0_CLR_MASK)

#define SYSCON_STARTERCLR_CTIMER1_CLR_MASK       (0x800U)
#define SYSCON_STARTERCLR_CTIMER1_CLR_SHIFT      (11U)
/*! CTIMER1_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_CTIMER1_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_CTIMER1_CLR_SHIFT)) & SYSCON_STARTERCLR_CTIMER1_CLR_MASK)

#define SYSCON_STARTERCLR_SCT0_CLR_MASK          (0x1000U)
#define SYSCON_STARTERCLR_SCT0_CLR_SHIFT         (12U)
/*! SCT0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_SCT0_CLR(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SCT0_CLR_SHIFT)) & SYSCON_STARTERCLR_SCT0_CLR_MASK)

#define SYSCON_STARTERCLR_CTIMER3_CLR_MASK       (0x2000U)
#define SYSCON_STARTERCLR_CTIMER3_CLR_SHIFT      (13U)
/*! CTIMER3_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_CTIMER3_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_CTIMER3_CLR_SHIFT)) & SYSCON_STARTERCLR_CTIMER3_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT0_CLR_MASK      (0x4000U)
#define SYSCON_STARTERCLR_FLEXINT0_CLR_SHIFT     (14U)
/*! FLEXINT0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT0_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT0_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT0_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT1_CLR_MASK      (0x8000U)
#define SYSCON_STARTERCLR_FLEXINT1_CLR_SHIFT     (15U)
/*! FLEXINT1_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT1_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT1_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT1_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT2_CLR_MASK      (0x10000U)
#define SYSCON_STARTERCLR_FLEXINT2_CLR_SHIFT     (16U)
/*! FLEXINT2_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT2_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT2_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT2_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT3_CLR_MASK      (0x20000U)
#define SYSCON_STARTERCLR_FLEXINT3_CLR_SHIFT     (17U)
/*! FLEXINT3_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT3_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT3_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT3_CLR_MASK)

#define SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_MASK (0x20000U)
#define SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_SHIFT (17U)
/*! SEC_HYPERVISOR_CALL_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT4_CLR_MASK      (0x40000U)
#define SYSCON_STARTERCLR_FLEXINT4_CLR_SHIFT     (18U)
/*! FLEXINT4_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT4_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT4_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT4_CLR_MASK)

#define SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_MASK (0x40000U)
#define SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_SHIFT (18U)
/*! SEC_GPIO_INT00_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT5_CLR_MASK      (0x80000U)
#define SYSCON_STARTERCLR_FLEXINT5_CLR_SHIFT     (19U)
/*! FLEXINT5_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT5_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT5_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT5_CLR_MASK)

#define SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_MASK (0x80000U)
#define SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_SHIFT (19U)
/*! SEC_GPIO_INT01_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT6_CLR_MASK      (0x100000U)
#define SYSCON_STARTERCLR_FLEXINT6_CLR_SHIFT     (20U)
/*! FLEXINT6_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT6_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT6_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT6_CLR_MASK)

#define SYSCON_STARTERCLR_FLEXINT7_CLR_MASK      (0x200000U)
#define SYSCON_STARTERCLR_FLEXINT7_CLR_SHIFT     (21U)
/*! FLEXINT7_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_FLEXINT7_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_FLEXINT7_CLR_SHIFT)) & SYSCON_STARTERCLR_FLEXINT7_CLR_MASK)

#define SYSCON_STARTERCLR_ADC0_CLR_MASK          (0x400000U)
#define SYSCON_STARTERCLR_ADC0_CLR_SHIFT         (22U)
/*! ADC0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_ADC0_CLR(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_ADC0_CLR_SHIFT)) & SYSCON_STARTERCLR_ADC0_CLR_MASK)

#define SYSCON_STARTERCLR_ADC0_THCMP_OVR_CLR_MASK (0x1000000U)
#define SYSCON_STARTERCLR_ADC0_THCMP_OVR_CLR_SHIFT (24U)
/*! ADC0_THCMP_OVR_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_ADC0_THCMP_OVR_CLR(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_ADC0_THCMP_OVR_CLR_SHIFT)) & SYSCON_STARTERCLR_ADC0_THCMP_OVR_CLR_MASK)

#define SYSCON_STARTERCLR_QDDKEY_CLR_MASK        (0x1000000U)
#define SYSCON_STARTERCLR_QDDKEY_CLR_SHIFT       (24U)
/*! QDDKEY_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_QDDKEY_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_QDDKEY_CLR_SHIFT)) & SYSCON_STARTERCLR_QDDKEY_CLR_MASK)

#define SYSCON_STARTERCLR_PQ_CLR_MASK            (0x2000000U)
#define SYSCON_STARTERCLR_PQ_CLR_SHIFT           (25U)
/*! PQ_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_PQ_CLR(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_PQ_CLR_SHIFT)) & SYSCON_STARTERCLR_PQ_CLR_MASK)

#define SYSCON_STARTERCLR_SDMA1_CLR_MASK         (0x4000000U)
#define SYSCON_STARTERCLR_SDMA1_CLR_SHIFT        (26U)
/*! SDMA1_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SDMA1_CLR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SDMA1_CLR_SHIFT)) & SYSCON_STARTERCLR_SDMA1_CLR_MASK)

#define SYSCON_STARTERCLR_SPI_HS_CLR_MASK        (0x8000000U)
#define SYSCON_STARTERCLR_SPI_HS_CLR_SHIFT       (27U)
/*! SPI_HS_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SPI_HS_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SPI_HS_CLR_SHIFT)) & SYSCON_STARTERCLR_SPI_HS_CLR_MASK)

#define SYSCON_STARTERCLR_USB0_NEEDCLK_CLR_MASK  (0x8000000U)
#define SYSCON_STARTERCLR_USB0_NEEDCLK_CLR_SHIFT (27U)
/*! USB0_NEEDCLK_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_USB0_NEEDCLK_CLR(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_USB0_NEEDCLK_CLR_SHIFT)) & SYSCON_STARTERCLR_USB0_NEEDCLK_CLR_MASK)

#define SYSCON_STARTERCLR_USB0_CLR_MASK          (0x10000000U)
#define SYSCON_STARTERCLR_USB0_CLR_SHIFT         (28U)
/*! USB0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_USB0_CLR(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_USB0_CLR_SHIFT)) & SYSCON_STARTERCLR_USB0_CLR_MASK)

#define SYSCON_STARTERCLR_RTC_LITE0_CLR_MASK     (0x20000000U)
#define SYSCON_STARTERCLR_RTC_LITE0_CLR_SHIFT    (29U)
/*! RTC_LITE0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_RTC_LITE0_CLR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_RTC_LITE0_CLR_SHIFT)) & SYSCON_STARTERCLR_RTC_LITE0_CLR_MASK)

#define SYSCON_STARTERCLR_WAKEUPPADS_CLR_MASK    (0x80000000U)
#define SYSCON_STARTERCLR_WAKEUPPADS_CLR_SHIFT   (31U)
/*! WAKEUPPADS_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_WAKEUPPADS_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_WAKEUPPADS_CLR_SHIFT)) & SYSCON_STARTERCLR_WAKEUPPADS_CLR_MASK)

#define SYSCON_STARTERCLR_WAKEUP_MAILBOX0_CLR_MASK (0x80000000U)
#define SYSCON_STARTERCLR_WAKEUP_MAILBOX0_CLR_SHIFT (31U)
/*! WAKEUP_MAILBOX0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_WAKEUP_MAILBOX0_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_WAKEUP_MAILBOX0_CLR_SHIFT)) & SYSCON_STARTERCLR_WAKEUP_MAILBOX0_CLR_MASK)
/*! @} */

/*! @name FUNCRETENTIONCTRL - Functional retention control */
/*! @{ */

#define SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_MASK (0x1U)
#define SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_SHIFT (0U)
/*! FUNCRETENA - functional retention in power down only.
 *  0b0..disable functional retention.
 *  0b1..enable functional retention.
 */
#define SYSCON_FUNCRETENTIONCTRL_FUNCRETENA(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_SHIFT)) & SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_MASK)

#define SYSCON_FUNCRETENTIONCTRL_RET_START_MASK  (0x3FFEU)
#define SYSCON_FUNCRETENTIONCTRL_RET_START_SHIFT (1U)
/*! RET_START - Start address divided by 4 inside SRAMX bank. */
#define SYSCON_FUNCRETENTIONCTRL_RET_START(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_FUNCRETENTIONCTRL_RET_START_SHIFT)) & SYSCON_FUNCRETENTIONCTRL_RET_START_MASK)

#define SYSCON_FUNCRETENTIONCTRL_RET_LENTH_MASK  (0xFFC000U)
#define SYSCON_FUNCRETENTIONCTRL_RET_LENTH_SHIFT (14U)
/*! RET_LENTH - lenth of Scan chains to save. */
#define SYSCON_FUNCRETENTIONCTRL_RET_LENTH(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_FUNCRETENTIONCTRL_RET_LENTH_SHIFT)) & SYSCON_FUNCRETENTIONCTRL_RET_LENTH_MASK)
/*! @} */

/*! @name HARDWARESLEEP - Hardware Sleep control */
/*! @{ */

#define SYSCON_HARDWARESLEEP_FORCED_MASK         (0x1U)
#define SYSCON_HARDWARESLEEP_FORCED_SHIFT        (0U)
/*! FORCED - Force peripheral clocking to stay on during Deep Sleep and Power-down modes. */
#define SYSCON_HARDWARESLEEP_FORCED(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_FORCED_SHIFT)) & SYSCON_HARDWARESLEEP_FORCED_MASK)

#define SYSCON_HARDWARESLEEP_PERIPHERALS_MASK    (0x2U)
#define SYSCON_HARDWARESLEEP_PERIPHERALS_SHIFT   (1U)
/*! PERIPHERALS - Wake for Flexcomms. */
#define SYSCON_HARDWARESLEEP_PERIPHERALS(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_PERIPHERALS_SHIFT)) & SYSCON_HARDWARESLEEP_PERIPHERALS_MASK)

#define SYSCON_HARDWARESLEEP_DMIC_MASK           (0x4U)
#define SYSCON_HARDWARESLEEP_DMIC_SHIFT          (2U)
/*! DMIC - Wake for DMIC. */
#define SYSCON_HARDWARESLEEP_DMIC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_DMIC_SHIFT)) & SYSCON_HARDWARESLEEP_DMIC_MASK)

#define SYSCON_HARDWARESLEEP_SDMA0_MASK          (0x8U)
#define SYSCON_HARDWARESLEEP_SDMA0_SHIFT         (3U)
/*! SDMA0 - Wake for DMA0. */
#define SYSCON_HARDWARESLEEP_SDMA0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_SDMA0_SHIFT)) & SYSCON_HARDWARESLEEP_SDMA0_MASK)

#define SYSCON_HARDWARESLEEP_SDMA1_MASK          (0x20U)
#define SYSCON_HARDWARESLEEP_SDMA1_SHIFT         (5U)
/*! SDMA1 - Wake for DMA1. */
#define SYSCON_HARDWARESLEEP_SDMA1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_SDMA1_SHIFT)) & SYSCON_HARDWARESLEEP_SDMA1_MASK)

#define SYSCON_HARDWARESLEEP_DAC_MASK            (0x40U)
#define SYSCON_HARDWARESLEEP_DAC_SHIFT           (6U)
/*! DAC - Wake for DAC0/1/2. */
#define SYSCON_HARDWARESLEEP_DAC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_DAC_SHIFT)) & SYSCON_HARDWARESLEEP_DAC_MASK)

#define SYSCON_HARDWARESLEEP_HW_ENABLE_FRO192M_MASK (0x80000000U)
#define SYSCON_HARDWARESLEEP_HW_ENABLE_FRO192M_SHIFT (31U)
/*! HW_ENABLE_FRO192M - Set this bit if FRO192M is diabled. */
#define SYSCON_HARDWARESLEEP_HW_ENABLE_FRO192M(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_HW_ENABLE_FRO192M_SHIFT)) & SYSCON_HARDWARESLEEP_HW_ENABLE_FRO192M_MASK)
/*! @} */

/*! @name CPUSTAT - CPU Status */
/*! @{ */

#define SYSCON_CPUSTAT_CPU0SLEEPING_MASK         (0x1U)
#define SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT        (0U)
/*! CPU0SLEEPING - The CPU0 sleeping state.
 *  0b0..the CPU is not sleeping.
 *  0b1..the CPU is sleeping.
 */
#define SYSCON_CPUSTAT_CPU0SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT)) & SYSCON_CPUSTAT_CPU0SLEEPING_MASK)

#define SYSCON_CPUSTAT_CPU0LOCKUP_MASK           (0x4U)
#define SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT          (2U)
/*! CPU0LOCKUP - The CPU0 lockup state.
 *  0b0..the CPU is not in lockup.
 *  0b1..the CPU is in lockup.
 */
#define SYSCON_CPUSTAT_CPU0LOCKUP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT)) & SYSCON_CPUSTAT_CPU0LOCKUP_MASK)
/*! @} */

/*! @name LPCAC_CTRL - LPCAC control */
/*! @{ */

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK         (0x1U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT        (0U)
/*! DIS_LPCAC - Disable/enable cache function. Default value is 1.
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK         (0x2U)
#define SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT        (1U)
/*! CLR_LPCAC - Clear cache function. Default value is 0.
 *  0b0..Unclear cache
 *  0b1..Clear cache
 */
#define SYSCON_LPCAC_CTRL_CLR_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK      (0x4U)
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT     (2U)
/*! FRC_NO_ALLOC - Force no allocation. Default value is 0.
 *  0b0..Force allocation
 *  0b1..Force no allocation
 */
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT)) & SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK)

#define SYSCON_LPCAC_CTRL_PARITY_MISS_EN_MASK    (0x8U)
#define SYSCON_LPCAC_CTRL_PARITY_MISS_EN_SHIFT   (3U)
/*! PARITY_MISS_EN - Enable parity miss. Default value is 0.
 *  0b0..Disable
 *  0b1..Enable parity, miss on parity error
 */
#define SYSCON_LPCAC_CTRL_PARITY_MISS_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_PARITY_MISS_EN_SHIFT)) & SYSCON_LPCAC_CTRL_PARITY_MISS_EN_MASK)
/*! @} */

/*! @name FC32KCLKSEL - Flexcomm 32K clock select */
/*! @{ */

#define SYSCON_FC32KCLKSEL_FC32KCLKSEL_MASK      (0x1U)
#define SYSCON_FC32KCLKSEL_FC32KCLKSEL_SHIFT     (0U)
/*! FC32KCLKSEL - Flexcomm 32K clock select
 *  0b0..FRO32K
 *  0b1..XTAL 32K
 */
#define SYSCON_FC32KCLKSEL_FC32KCLKSEL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_FC32KCLKSEL_FC32KCLKSEL_SHIFT)) & SYSCON_FC32KCLKSEL_FC32KCLKSEL_MASK)
/*! @} */

/*! @name FRGCLKSEL - FRG Clock Source Select */
/*! @{ */

#define SYSCON_FRGCLKSEL_FRG_SRC_SEL_MASK        (0x7U)
#define SYSCON_FRGCLKSEL_FRG_SRC_SEL_SHIFT       (0U)
/*! FRG_SRC_SEL - FRG clock source select
 *  0b000..main clock
 *  0b001..PLL clock
 *  0b010..fro_div_hf
 *  0b011..None
 *  0b100..None
 *  0b101..None
 *  0b110..None
 *  0b111..None
 */
#define SYSCON_FRGCLKSEL_FRG_SRC_SEL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FRGCLKSEL_FRG_SRC_SEL_SHIFT)) & SYSCON_FRGCLKSEL_FRG_SRC_SEL_MASK)
/*! @} */

/*! @name FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV - Flexcomm clock divider */
/*! @{ */

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_MASK (0xFFU)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_SHIFT (0U)
/*! DIV - Clock divider value: */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_DIV_MASK)

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_MASK (0x20000000U)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_SHIFT (29U)
/*! RESET - Reset
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_RESET_MASK)

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_MASK (0x40000000U)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_SHIFT (30U)
/*! HALT - Reset
 *  0b0..Divider clock is running
 *  0b1..Divider clock has stopped
 */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_HALT_MASK)

#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_REQFLAG_MASK (0x80000000U)
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_REQFLAG_SHIFT (31U)
/*! REQFLAG - Reset
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_REQFLAG(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_REQFLAG_SHIFT)) & SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_REQFLAG_MASK)
/*! @} */

/* The count of SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV */
#define SYSCON_FLEXCOMMXCLKDIV_FLEXCOMMCLKDIV_COUNT (8U)

/*! @name ELS_TEMPORAL_STATE - ELS temporal state */
/*! @{ */

#define SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_MASK (0xFU)
#define SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_SHIFT (0U)
/*! TEMPORAL_STATE - Temporal state */
#define SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_SHIFT)) & SYSCON_ELS_TEMPORAL_STATE_TEMPORAL_STATE_MASK)
/*! @} */

/*! @name ELS_KDF_MASK - Key derivation function mask */
/*! @{ */

#define SYSCON_ELS_KDF_MASK_KDF_MASK_MASK        (0xFFFFFFFFU)
#define SYSCON_ELS_KDF_MASK_KDF_MASK_SHIFT       (0U)
/*! KDF_MASK - Key derivation function mask. */
#define SYSCON_ELS_KDF_MASK_KDF_MASK(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_KDF_MASK_KDF_MASK_SHIFT)) & SYSCON_ELS_KDF_MASK_KDF_MASK_MASK)
/*! @} */

/*! @name ELS_FEATURE0 - ELS command feature */
/*! @{ */

#define SYSCON_ELS_FEATURE0_CIPHER_MASK          (0x3U)
#define SYSCON_ELS_FEATURE0_CIPHER_SHIFT         (0U)
/*! CIPHER - Enables CIPHER command. */
#define SYSCON_ELS_FEATURE0_CIPHER(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_CIPHER_SHIFT)) & SYSCON_ELS_FEATURE0_CIPHER_MASK)

#define SYSCON_ELS_FEATURE0_AUTH_CIPHER_MASK     (0xCU)
#define SYSCON_ELS_FEATURE0_AUTH_CIPHER_SHIFT    (2U)
/*! AUTH_CIPHER - Enables AUTH_CIPHER command. */
#define SYSCON_ELS_FEATURE0_AUTH_CIPHER(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_AUTH_CIPHER_SHIFT)) & SYSCON_ELS_FEATURE0_AUTH_CIPHER_MASK)

#define SYSCON_ELS_FEATURE0_ECSIGN_MASK          (0x300U)
#define SYSCON_ELS_FEATURE0_ECSIGN_SHIFT         (8U)
/*! ECSIGN - Enables ECSIGN command. */
#define SYSCON_ELS_FEATURE0_ECSIGN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_ECSIGN_SHIFT)) & SYSCON_ELS_FEATURE0_ECSIGN_MASK)

#define SYSCON_ELS_FEATURE0_ECVFY_MASK           (0xC00U)
#define SYSCON_ELS_FEATURE0_ECVFY_SHIFT          (10U)
/*! ECVFY - Enables ECVFY command. */
#define SYSCON_ELS_FEATURE0_ECVFY(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_ECVFY_SHIFT)) & SYSCON_ELS_FEATURE0_ECVFY_MASK)

#define SYSCON_ELS_FEATURE0_ECKXCH_MASK          (0x3000U)
#define SYSCON_ELS_FEATURE0_ECKXCH_SHIFT         (12U)
/*! ECKXCH - Enables ECKXCH command. */
#define SYSCON_ELS_FEATURE0_ECKXCH(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_ECKXCH_SHIFT)) & SYSCON_ELS_FEATURE0_ECKXCH_MASK)

#define SYSCON_ELS_FEATURE0_KEYGEN_MASK          (0x30000U)
#define SYSCON_ELS_FEATURE0_KEYGEN_SHIFT         (16U)
/*! KEYGEN - Enables KEYGEN command. */
#define SYSCON_ELS_FEATURE0_KEYGEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_KEYGEN_SHIFT)) & SYSCON_ELS_FEATURE0_KEYGEN_MASK)

#define SYSCON_ELS_FEATURE0_KEYIN_MASK           (0xC0000U)
#define SYSCON_ELS_FEATURE0_KEYIN_SHIFT          (18U)
/*! KEYIN - Enables KEYIN command. */
#define SYSCON_ELS_FEATURE0_KEYIN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_KEYIN_SHIFT)) & SYSCON_ELS_FEATURE0_KEYIN_MASK)

#define SYSCON_ELS_FEATURE0_KEYOUT_MASK          (0x300000U)
#define SYSCON_ELS_FEATURE0_KEYOUT_SHIFT         (20U)
/*! KEYOUT - Enables KEYOUT command. */
#define SYSCON_ELS_FEATURE0_KEYOUT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_KEYOUT_SHIFT)) & SYSCON_ELS_FEATURE0_KEYOUT_MASK)

#define SYSCON_ELS_FEATURE0_KDELETE_MASK         (0xC00000U)
#define SYSCON_ELS_FEATURE0_KDELETE_SHIFT        (22U)
/*! KDELETE - Enables KDELETE command. */
#define SYSCON_ELS_FEATURE0_KDELETE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_KDELETE_SHIFT)) & SYSCON_ELS_FEATURE0_KDELETE_MASK)
/*! @} */

/*! @name ELS_FEATURE1 - ELS command feature */
/*! @{ */

#define SYSCON_ELS_FEATURE1_CKDF_MASK            (0x3U)
#define SYSCON_ELS_FEATURE1_CKDF_SHIFT           (0U)
/*! CKDF - Enables CKDF command. */
#define SYSCON_ELS_FEATURE1_CKDF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_CKDF_SHIFT)) & SYSCON_ELS_FEATURE1_CKDF_MASK)

#define SYSCON_ELS_FEATURE1_HKDF_MASK            (0xCU)
#define SYSCON_ELS_FEATURE1_HKDF_SHIFT           (2U)
/*! HKDF - Enables HKDF command. */
#define SYSCON_ELS_FEATURE1_HKDF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_HKDF_SHIFT)) & SYSCON_ELS_FEATURE1_HKDF_MASK)

#define SYSCON_ELS_FEATURE1_TLS_INIT_MASK        (0x30U)
#define SYSCON_ELS_FEATURE1_TLS_INIT_SHIFT       (4U)
/*! TLS_INIT - Enables TLS_INIT command. */
#define SYSCON_ELS_FEATURE1_TLS_INIT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_TLS_INIT_SHIFT)) & SYSCON_ELS_FEATURE1_TLS_INIT_MASK)

#define SYSCON_ELS_FEATURE1_HASH_MASK            (0x300U)
#define SYSCON_ELS_FEATURE1_HASH_SHIFT           (8U)
/*! HASH - Enables HASH command. */
#define SYSCON_ELS_FEATURE1_HASH(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_HASH_SHIFT)) & SYSCON_ELS_FEATURE1_HASH_MASK)

#define SYSCON_ELS_FEATURE1_HMAC_MASK            (0xC00U)
#define SYSCON_ELS_FEATURE1_HMAC_SHIFT           (10U)
/*! HMAC - Enables HMAC command. */
#define SYSCON_ELS_FEATURE1_HMAC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_HMAC_SHIFT)) & SYSCON_ELS_FEATURE1_HMAC_MASK)

#define SYSCON_ELS_FEATURE1_CMAC_MASK            (0x3000U)
#define SYSCON_ELS_FEATURE1_CMAC_SHIFT           (12U)
/*! CMAC - Enables CMAC command. */
#define SYSCON_ELS_FEATURE1_CMAC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_CMAC_SHIFT)) & SYSCON_ELS_FEATURE1_CMAC_MASK)

#define SYSCON_ELS_FEATURE1_DRBG_REQ_MASK        (0x30000U)
#define SYSCON_ELS_FEATURE1_DRBG_REQ_SHIFT       (16U)
/*! DRBG_REQ - Enables DRBG_REQ command. */
#define SYSCON_ELS_FEATURE1_DRBG_REQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DRBG_REQ_SHIFT)) & SYSCON_ELS_FEATURE1_DRBG_REQ_MASK)

#define SYSCON_ELS_FEATURE1_DRBG_TEST_MASK       (0xC0000U)
#define SYSCON_ELS_FEATURE1_DRBG_TEST_SHIFT      (18U)
/*! DRBG_TEST - Enables DRBG_TEST command. */
#define SYSCON_ELS_FEATURE1_DRBG_TEST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DRBG_TEST_SHIFT)) & SYSCON_ELS_FEATURE1_DRBG_TEST_MASK)

#define SYSCON_ELS_FEATURE1_DTRNG_CFG_LOAD_MASK  (0x3000000U)
#define SYSCON_ELS_FEATURE1_DTRNG_CFG_LOAD_SHIFT (24U)
/*! DTRNG_CFG_LOAD - Enables DTRNG_CFG_LOAD command. */
#define SYSCON_ELS_FEATURE1_DTRNG_CFG_LOAD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DTRNG_CFG_LOAD_SHIFT)) & SYSCON_ELS_FEATURE1_DTRNG_CFG_LOAD_MASK)

#define SYSCON_ELS_FEATURE1_DTRNG_EVAL_MASK      (0xC000000U)
#define SYSCON_ELS_FEATURE1_DTRNG_EVAL_SHIFT     (26U)
/*! DTRNG_EVAL - Enables DTRNG_EVAL command. */
#define SYSCON_ELS_FEATURE1_DTRNG_EVAL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DTRNG_EVAL_SHIFT)) & SYSCON_ELS_FEATURE1_DTRNG_EVAL_MASK)

#define SYSCON_ELS_FEATURE1_GDET_CFG_LOAD_MASK   (0x30000000U)
#define SYSCON_ELS_FEATURE1_GDET_CFG_LOAD_SHIFT  (28U)
/*! GDET_CFG_LOAD - Enables GDET_CFG_LOAD command. */
#define SYSCON_ELS_FEATURE1_GDET_CFG_LOAD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_GDET_CFG_LOAD_SHIFT)) & SYSCON_ELS_FEATURE1_GDET_CFG_LOAD_MASK)
/*! @} */

/*! @name ELS_FEATURE0_DP - ELS command feature - duplicate version */
/*! @{ */

#define SYSCON_ELS_FEATURE0_DP_CIPHER_MASK       (0x3U)
#define SYSCON_ELS_FEATURE0_DP_CIPHER_SHIFT      (0U)
/*! CIPHER - Enables CIPHER command. */
#define SYSCON_ELS_FEATURE0_DP_CIPHER(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_CIPHER_SHIFT)) & SYSCON_ELS_FEATURE0_DP_CIPHER_MASK)

#define SYSCON_ELS_FEATURE0_DP_AUTH_CIPHER_MASK  (0xCU)
#define SYSCON_ELS_FEATURE0_DP_AUTH_CIPHER_SHIFT (2U)
/*! AUTH_CIPHER - Enables AUTH_CIPHER command. */
#define SYSCON_ELS_FEATURE0_DP_AUTH_CIPHER(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_AUTH_CIPHER_SHIFT)) & SYSCON_ELS_FEATURE0_DP_AUTH_CIPHER_MASK)

#define SYSCON_ELS_FEATURE0_DP_ECSIGN_MASK       (0x300U)
#define SYSCON_ELS_FEATURE0_DP_ECSIGN_SHIFT      (8U)
/*! ECSIGN - Enables ECSIGN command. */
#define SYSCON_ELS_FEATURE0_DP_ECSIGN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_ECSIGN_SHIFT)) & SYSCON_ELS_FEATURE0_DP_ECSIGN_MASK)

#define SYSCON_ELS_FEATURE0_DP_ECVFY_MASK        (0xC00U)
#define SYSCON_ELS_FEATURE0_DP_ECVFY_SHIFT       (10U)
/*! ECVFY - Enables ECSIGN command. */
#define SYSCON_ELS_FEATURE0_DP_ECVFY(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_ECVFY_SHIFT)) & SYSCON_ELS_FEATURE0_DP_ECVFY_MASK)

#define SYSCON_ELS_FEATURE0_DP_ECKXCH_MASK       (0x3000U)
#define SYSCON_ELS_FEATURE0_DP_ECKXCH_SHIFT      (12U)
/*! ECKXCH - Enables ECSIGN command. */
#define SYSCON_ELS_FEATURE0_DP_ECKXCH(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_ECKXCH_SHIFT)) & SYSCON_ELS_FEATURE0_DP_ECKXCH_MASK)

#define SYSCON_ELS_FEATURE0_DP_KEYGEN_MASK       (0x30000U)
#define SYSCON_ELS_FEATURE0_DP_KEYGEN_SHIFT      (16U)
/*! KEYGEN - Enables KEYGEN command. */
#define SYSCON_ELS_FEATURE0_DP_KEYGEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_KEYGEN_SHIFT)) & SYSCON_ELS_FEATURE0_DP_KEYGEN_MASK)

#define SYSCON_ELS_FEATURE0_DP_KEYIN_MASK        (0xC0000U)
#define SYSCON_ELS_FEATURE0_DP_KEYIN_SHIFT       (18U)
/*! KEYIN - Enables KEYIN command. */
#define SYSCON_ELS_FEATURE0_DP_KEYIN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_KEYIN_SHIFT)) & SYSCON_ELS_FEATURE0_DP_KEYIN_MASK)

#define SYSCON_ELS_FEATURE0_DP_KEYOUT_MASK       (0x300000U)
#define SYSCON_ELS_FEATURE0_DP_KEYOUT_SHIFT      (20U)
/*! KEYOUT - Enables KEYOUT command. */
#define SYSCON_ELS_FEATURE0_DP_KEYOUT(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_KEYOUT_SHIFT)) & SYSCON_ELS_FEATURE0_DP_KEYOUT_MASK)

#define SYSCON_ELS_FEATURE0_DP_KDELETE_MASK      (0xC00000U)
#define SYSCON_ELS_FEATURE0_DP_KDELETE_SHIFT     (22U)
/*! KDELETE - Enables KDELETE command. */
#define SYSCON_ELS_FEATURE0_DP_KDELETE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE0_DP_KDELETE_SHIFT)) & SYSCON_ELS_FEATURE0_DP_KDELETE_MASK)
/*! @} */

/*! @name ELS_FEATURE1_DP - ELS command feature - duplicate version */
/*! @{ */

#define SYSCON_ELS_FEATURE1_DP_CKDF_MASK         (0x3U)
#define SYSCON_ELS_FEATURE1_DP_CKDF_SHIFT        (0U)
/*! CKDF - Enables CKDF command. */
#define SYSCON_ELS_FEATURE1_DP_CKDF(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_CKDF_SHIFT)) & SYSCON_ELS_FEATURE1_DP_CKDF_MASK)

#define SYSCON_ELS_FEATURE1_DP_HKDF_MASK         (0xCU)
#define SYSCON_ELS_FEATURE1_DP_HKDF_SHIFT        (2U)
/*! HKDF - Enables HKDF command. */
#define SYSCON_ELS_FEATURE1_DP_HKDF(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_HKDF_SHIFT)) & SYSCON_ELS_FEATURE1_DP_HKDF_MASK)

#define SYSCON_ELS_FEATURE1_DP_TLS_INIT_MASK     (0x30U)
#define SYSCON_ELS_FEATURE1_DP_TLS_INIT_SHIFT    (4U)
/*! TLS_INIT - Enables TLS_INIT command. */
#define SYSCON_ELS_FEATURE1_DP_TLS_INIT(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_TLS_INIT_SHIFT)) & SYSCON_ELS_FEATURE1_DP_TLS_INIT_MASK)

#define SYSCON_ELS_FEATURE1_DP_HASH_MASK         (0x300U)
#define SYSCON_ELS_FEATURE1_DP_HASH_SHIFT        (8U)
/*! HASH - Enables HASH command. */
#define SYSCON_ELS_FEATURE1_DP_HASH(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_HASH_SHIFT)) & SYSCON_ELS_FEATURE1_DP_HASH_MASK)

#define SYSCON_ELS_FEATURE1_DP_HMAC_MASK         (0xC00U)
#define SYSCON_ELS_FEATURE1_DP_HMAC_SHIFT        (10U)
/*! HMAC - Enables HMAC command. */
#define SYSCON_ELS_FEATURE1_DP_HMAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_HMAC_SHIFT)) & SYSCON_ELS_FEATURE1_DP_HMAC_MASK)

#define SYSCON_ELS_FEATURE1_DP_CMAC_MASK         (0x3000U)
#define SYSCON_ELS_FEATURE1_DP_CMAC_SHIFT        (12U)
/*! CMAC - Enables CMAC command. */
#define SYSCON_ELS_FEATURE1_DP_CMAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_CMAC_SHIFT)) & SYSCON_ELS_FEATURE1_DP_CMAC_MASK)

#define SYSCON_ELS_FEATURE1_DP_DRBG_REQ_MASK     (0x30000U)
#define SYSCON_ELS_FEATURE1_DP_DRBG_REQ_SHIFT    (16U)
/*! DRBG_REQ - Enables DRBG_REQ command. */
#define SYSCON_ELS_FEATURE1_DP_DRBG_REQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_DRBG_REQ_SHIFT)) & SYSCON_ELS_FEATURE1_DP_DRBG_REQ_MASK)

#define SYSCON_ELS_FEATURE1_DP_DRBG_TEST_MASK    (0xC0000U)
#define SYSCON_ELS_FEATURE1_DP_DRBG_TEST_SHIFT   (18U)
/*! DRBG_TEST - Enables DRBG_TEST command. */
#define SYSCON_ELS_FEATURE1_DP_DRBG_TEST(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_DRBG_TEST_SHIFT)) & SYSCON_ELS_FEATURE1_DP_DRBG_TEST_MASK)

#define SYSCON_ELS_FEATURE1_DP_DTRNG_CFG_LOAD_MASK (0x3000000U)
#define SYSCON_ELS_FEATURE1_DP_DTRNG_CFG_LOAD_SHIFT (24U)
/*! DTRNG_CFG_LOAD - Enables DTRNG_CFG_LOAD command. */
#define SYSCON_ELS_FEATURE1_DP_DTRNG_CFG_LOAD(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_DTRNG_CFG_LOAD_SHIFT)) & SYSCON_ELS_FEATURE1_DP_DTRNG_CFG_LOAD_MASK)

#define SYSCON_ELS_FEATURE1_DP_DTRNG_EVAL_MASK   (0xC000000U)
#define SYSCON_ELS_FEATURE1_DP_DTRNG_EVAL_SHIFT  (26U)
/*! DTRNG_EVAL - Enables DTRNG_EVAL command. */
#define SYSCON_ELS_FEATURE1_DP_DTRNG_EVAL(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_DTRNG_EVAL_SHIFT)) & SYSCON_ELS_FEATURE1_DP_DTRNG_EVAL_MASK)

#define SYSCON_ELS_FEATURE1_DP_GDET_CFG_LOAD_MASK (0x30000000U)
#define SYSCON_ELS_FEATURE1_DP_GDET_CFG_LOAD_SHIFT (28U)
/*! GDET_CFG_LOAD - Enables GDET_CFG_LOAD command. */
#define SYSCON_ELS_FEATURE1_DP_GDET_CFG_LOAD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_FEATURE1_DP_GDET_CFG_LOAD_SHIFT)) & SYSCON_ELS_FEATURE1_DP_GDET_CFG_LOAD_MASK)
/*! @} */

/*! @name ELS_BOOT_RETRY_CNT - ELS boot retry counter */
/*! @{ */

#define SYSCON_ELS_BOOT_RETRY_CNT_BOOT_RETRY_CNT_MASK (0xFFFFFFFFU)
#define SYSCON_ELS_BOOT_RETRY_CNT_BOOT_RETRY_CNT_SHIFT (0U)
/*! BOOT_RETRY_CNT - Boot retry counter bit. */
#define SYSCON_ELS_BOOT_RETRY_CNT_BOOT_RETRY_CNT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_BOOT_RETRY_CNT_BOOT_RETRY_CNT_SHIFT)) & SYSCON_ELS_BOOT_RETRY_CNT_BOOT_RETRY_CNT_MASK)
/*! @} */

/*! @name ELS_CLK_CTRL - ELS clock control */
/*! @{ */

#define SYSCON_ELS_CLK_CTRL_GDET_REFCLK_EN_MASK  (0x1U)
#define SYSCON_ELS_CLK_CTRL_GDET_REFCLK_EN_SHIFT (0U)
/*! GDET_REFCLK_EN - GDET reference clock enable bit. */
#define SYSCON_ELS_CLK_CTRL_GDET_REFCLK_EN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_CTRL_GDET_REFCLK_EN_SHIFT)) & SYSCON_ELS_CLK_CTRL_GDET_REFCLK_EN_MASK)

#define SYSCON_ELS_CLK_CTRL_DTRNG_REFCLK_EN_MASK (0x2U)
#define SYSCON_ELS_CLK_CTRL_DTRNG_REFCLK_EN_SHIFT (1U)
/*! DTRNG_REFCLK_EN - DTRNG reference clock enable bit. */
#define SYSCON_ELS_CLK_CTRL_DTRNG_REFCLK_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_CTRL_DTRNG_REFCLK_EN_SHIFT)) & SYSCON_ELS_CLK_CTRL_DTRNG_REFCLK_EN_MASK)
/*! @} */

/*! @name ELS_CLK_CTRL_SET - ELS clock control set */
/*! @{ */

#define SYSCON_ELS_CLK_CTRL_SET_GDET_REFCLK_EN_SET_MASK (0x1U)
#define SYSCON_ELS_CLK_CTRL_SET_GDET_REFCLK_EN_SET_SHIFT (0U)
/*! GDET_REFCLK_EN_SET - GDET reference clock enable set bit. */
#define SYSCON_ELS_CLK_CTRL_SET_GDET_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_CTRL_SET_GDET_REFCLK_EN_SET_SHIFT)) & SYSCON_ELS_CLK_CTRL_SET_GDET_REFCLK_EN_SET_MASK)

#define SYSCON_ELS_CLK_CTRL_SET_DTRNG_REFCLK_EN_SET_MASK (0x2U)
#define SYSCON_ELS_CLK_CTRL_SET_DTRNG_REFCLK_EN_SET_SHIFT (1U)
/*! DTRNG_REFCLK_EN_SET - DTRNG reference clock enable set bit. */
#define SYSCON_ELS_CLK_CTRL_SET_DTRNG_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_CTRL_SET_DTRNG_REFCLK_EN_SET_SHIFT)) & SYSCON_ELS_CLK_CTRL_SET_DTRNG_REFCLK_EN_SET_MASK)
/*! @} */

/*! @name ELS_CLK_CTRL_CLR - ELS clock control clear */
/*! @{ */

#define SYSCON_ELS_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_MASK (0x1U)
#define SYSCON_ELS_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_SHIFT (0U)
/*! GDET_REFCLK_EN_CLR - GDET reference clock enable clear bit. */
#define SYSCON_ELS_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_SHIFT)) & SYSCON_ELS_CLK_CTRL_CLR_GDET_REFCLK_EN_CLR_MASK)

#define SYSCON_ELS_CLK_CTRL_CLR_DTRNG_REFCLK_EN_CLR_MASK (0x2U)
#define SYSCON_ELS_CLK_CTRL_CLR_DTRNG_REFCLK_EN_CLR_SHIFT (1U)
/*! DTRNG_REFCLK_EN_CLR - DTRNG reference clock enable clear bit. */
#define SYSCON_ELS_CLK_CTRL_CLR_DTRNG_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_CTRL_CLR_DTRNG_REFCLK_EN_CLR_SHIFT)) & SYSCON_ELS_CLK_CTRL_CLR_DTRNG_REFCLK_EN_CLR_MASK)
/*! @} */

/*! @name ELS_CLK_SEL - ELS clock select */
/*! @{ */

#define SYSCON_ELS_CLK_SEL_GDET_REFCLK_SEL_MASK  (0x3U)
#define SYSCON_ELS_CLK_SEL_GDET_REFCLK_SEL_SHIFT (0U)
/*! GDET_REFCLK_SEL - GDET reference clock select bit. */
#define SYSCON_ELS_CLK_SEL_GDET_REFCLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_CLK_SEL_GDET_REFCLK_SEL_SHIFT)) & SYSCON_ELS_CLK_SEL_GDET_REFCLK_SEL_MASK)
/*! @} */

/*! @name ELS_AS_CFG0 - ELS AS configuration */
/*! @{ */

#define SYSCON_ELS_AS_CFG0_CFG_LC_STATE_MASK     (0xFFU)
#define SYSCON_ELS_AS_CFG0_CFG_LC_STATE_SHIFT    (0U)
/*! CFG_LC_STATE - LC state configuration bit. */
#define SYSCON_ELS_AS_CFG0_CFG_LC_STATE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_LC_STATE_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_LC_STATE_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_RESET_ENABLED_MASK (0x100U)
#define SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_RESET_ENABLED_SHIFT (8U)
/*! CFG_BOD_VBAT_RESET_ENABLED - When BOD VDDMAIN analog detector is turned on and BOD VDDMAIN reset is enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_BOD_CORE_RESET_ENABLED_MASK (0x200U)
#define SYSCON_ELS_AS_CFG0_CFG_BOD_CORE_RESET_ENABLED_SHIFT (9U)
/*! CFG_BOD_CORE_RESET_ENABLED - When BOD CORE analog detector is turned on and BOD CORE reset is enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_BOD_CORE_RESET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_BOD_CORE_RESET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_BOD_CORE_RESET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_IRQ_ENABLED_MASK (0x400U)
#define SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_IRQ_ENABLED_SHIFT (10U)
/*! CFG_BOD_VBAT_IRQ_ENABLED - When BOD VDDMAIN analog detector is turned on and BOD VDDMAIN IRQ is enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_IRQ_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_IRQ_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_BOD_VBAT_IRQ_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_WDT_ENABLED_MASK  (0x1000U)
#define SYSCON_ELS_AS_CFG0_CFG_WDT_ENABLED_SHIFT (12U)
/*! CFG_WDT_ENABLED - When WatchDog Timer is activated, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_WDT_ENABLED(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_WDT_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_WDT_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_CWDT_ENABLED_MASK (0x2000U)
#define SYSCON_ELS_AS_CFG0_CFG_CWDT_ENABLED_SHIFT (13U)
/*! CFG_CWDT_ENABLED - When Code WatchDog Timer is activated, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_CWDT_ENABLED(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_CWDT_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_CWDT_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_MASK (0x8000U)
#define SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_SHIFT (15U)
/*! CFG_ELS_GDET_ENABLED - When ELS GDET is enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_ELS_GDET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_MASK (0x20000U)
#define SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_SHIFT (17U)
/*! CFG_TAMPER_DET_ENABLED - When tamper detector is enabled in RTC, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_TAMPER_DET_ENABLED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_MASK (0x40000U)
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_SHIFT (18U)
/*! CFG_FLASH_IS_REMAPPED - When FLASHREMAP_OFFSET register (0x4000_0448) is not equal to 0x0000_0000, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_DP_MASK (0x80000U)
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_DP_SHIFT (19U)
/*! CFG_FLASH_IS_REMAPPED_DP - When FLASHREMAP_OFFSET_DP register (0x4000_044C) is not equal to 0x0000_0000, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_DP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_DP_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_FLASH_IS_REMAPPED_DP_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK0_ENABLE_MASK (0xF00000U)
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK0_ENABLE_SHIFT (20U)
/*! CFG_FLASH_BANK0_ENABLE - The state of FLASHBANK_ENABLE0 register (0x4000_0450) reflects to this register as below. */
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK0_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK0_ENABLE_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK0_ENABLE_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK1_ENABLE_MASK (0xF000000U)
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK1_ENABLE_SHIFT (24U)
/*! CFG_FLASH_BANK1_ENABLE - The state of FLASHBANK_ENABLE1 register (0x4000_0454) reflects to this register as below: */
#define SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK1_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK1_ENABLE_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_FLASH_BANK1_ENABLE_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_MASK (0x10000000U)
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_SHIFT (28U)
/*! CFG_QK_DISABLE_ENROLL - When CONFIG[DIS_PUF_ENROLL] bit is set 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_ENROLL_MASK)

#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_MASK (0x20000000U)
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_SHIFT (29U)
/*! CFG_QK_DISABLE_WRAP - When CONFIG[DIS_PUF_WRAP_KEY] bit is set 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_SHIFT)) & SYSCON_ELS_AS_CFG0_CFG_QK_DISABLE_WRAP_MASK)
/*! @} */

/*! @name ELS_AS_CFG1 - ELS AS configuration1 */
/*! @{ */

#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_MASK (0x2U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_SHIFT (1U)
/*! CFG_SEC_DIS_STRICT_MODE - When "CFG_SEC_ENA_SEC_CHK" indicates state 0 or when
 *    "DISABLE_STRICT_MODE" bits in "MISC_CTRL_REG" and "MISC_CTRL_DP_REG" on AHB secure controller, both bits are
 *    equal to 01, this bit indicates state 1.
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_STRICT_MODE_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_MASK (0x4U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_SHIFT (2U)
/*! CFG_SEC_DIS_VIOL_ABORT - When "DISABLE_VIOLATION_ABORT" bits in "MISC_CTRL_REG" and
 *    "MISC_CTRL_DP_REG" on AHB secure controller, both bits are not equal to 10, this bit indicates state 1.
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_DIS_VIOL_ABORT_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_MASK (0x8U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_SHIFT (3U)
/*! CFG_SEC_ENA_NS_PRIV_CHK - When "ENABLE_NS_PRIV_CHECK" bits in "MISC_CTRL_REG" and
 *    "MISC_CTRL_DP_REG" on AHB secure controller, both bits are not equal to 10, this bit indicates state 1.
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_NS_PRIV_CHK_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_MASK (0x10U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_SHIFT (4U)
/*! CFG_SEC_ENA_S_PRIV_CHK - When "ENABLE_S_PRIV_CHECK" bits in "MISC_CTRL_REG" and
 *    "MISC_CTRL_DP_REG" on AHB secure controller, both bits are not equal to 10, this bit indicates state 1.
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_S_PRIV_CHK_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_MASK (0x20U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_SHIFT (5U)
/*! CFG_SEC_ENA_SEC_CHK - When "ENABLE_SECURE_CHECKING" bits in "MISC_CTRL_REG" and
 *    "MISC_CTRL_DP_REG" on AHB secure controller, both bits are not equal to 10, this bit indicates state 1.
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_ENA_SEC_CHK_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_MASK (0x40U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_SHIFT (6U)
/*! CFG_SEC_IDAU_ALLNS - When "IDAU_ALL_NS" bits in "MISC_CTRL_REG" and "MISC_CTRL_DP_REG" on AHB
 *    secure controller, both bits are equal to 01, this bit indicates state 1.
 */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_IDAU_ALLNS_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_MASK (0x100U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_SHIFT (8U)
/*! CFG_SEC_LOCK_NS_MPU - When "LOCK_NS_MPU" bits in "CPU0_LOCK_REG" on AHB secure controller are not equal to 10, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_MPU_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_MASK (0x200U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_SHIFT (9U)
/*! CFG_SEC_LOCK_NS_VTOR - When "LOCK_NS_VTOR" bits in "CPU0_LOCK_REG" on AHB secure controller are not equal to 10, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_NS_VTOR_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_MASK (0x400U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_SHIFT (10U)
/*! CFG_SEC_LOCK_S_MPU - When "LOCK_S_MPU" bits in "CPU0_LOCK_REG" on AHB secure controller are not equal to 10, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_MPU_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_MASK (0x800U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_SHIFT (11U)
/*! CFG_SEC_LOCK_S_VTAIRCR - When "LOCK_S_VTAIRCR" bits in "CPU0_LOCK_REG" on AHB secure controller are not equal to 10, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_S_VTAIRCR_MASK)

#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_MASK (0x1000U)
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_SHIFT (12U)
/*! CFG_SEC_LOCK_SAU - When "LOCK_SAU" bits in "CPU0_LOCK_REG" on AHB secure controller are not equal to 10, this bit indicates state 1. */
#define SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_SHIFT)) & SYSCON_ELS_AS_CFG1_CFG_SEC_LOCK_SAU_MASK)
/*! @} */

/*! @name ELS_AS_CFG2 - ELS AS configuration2 */
/*! @{ */

#define SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_MASK   (0xFFFFFFFFU)
#define SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_SHIFT  (0U)
/*! CFG_ELS_CMD_EN - ELS configuration command enable bit. */
#define SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_SHIFT)) & SYSCON_ELS_AS_CFG2_CFG_ELS_CMD_EN_MASK)
/*! @} */

/*! @name ELS_AS_ST0 - ELS AS state register */
/*! @{ */

#define SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_MASK (0xFU)
#define SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_SHIFT (0U)
/*! ST_TEMPORAL_STATE - "TEMPORAL_STATE[3:0]" on "ELS_TEMPORAL_STATE" register reflects this register. */
#define SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_SHIFT)) & SYSCON_ELS_AS_ST0_ST_TEMPORAL_STATE_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_MASK     (0x10U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_SHIFT    (4U)
/*! ST_CPU0_DBGEN - When CPU0 (CM33) "deben" input is state 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_DBGEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_MASK     (0x20U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_SHIFT    (5U)
/*! ST_CPU0_NIDEN - When CPU0 (CM33) "niden" input is state 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_NIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_MASK    (0x40U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_SHIFT   (6U)
/*! ST_CPU0_SPIDEN - When CPU0 (CM33) "spiden" input is state 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_SPIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_MASK   (0x80U)
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_SHIFT  (7U)
/*! ST_CPU0_SPNIDEN - When CPU0 (CM33) "spniden" input is state 1, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_CPU0_SPNIDEN_MASK)

#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_MASK (0x400U)
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_SHIFT (10U)
/*! ST_DAP_ENABLE_CPU0 - When DAP to AP0 for CPU0 (CM33) debug access is allowed, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_SHIFT)) & SYSCON_ELS_AS_ST0_ST_DAP_ENABLE_CPU0_MASK)

#define SYSCON_ELS_AS_ST0_ST_ELS_DEBUG_EN_MASK   (0x2000U)
#define SYSCON_ELS_AS_ST0_ST_ELS_DEBUG_EN_SHIFT  (13U)
/*! ST_ELS_DEBUG_EN - When ELS uCode code fetch out of AHB for debug is enabled, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_ELS_DEBUG_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_ELS_DEBUG_EN_SHIFT)) & SYSCON_ELS_AS_ST0_ST_ELS_DEBUG_EN_MASK)

#define SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_MASK (0x4000U)
#define SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_SHIFT (14U)
/*! ST_ALLOW_TEST_ACCESS - When JTAG TAP access is allowed, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_SHIFT)) & SYSCON_ELS_AS_ST0_ST_ALLOW_TEST_ACCESS_MASK)

#define SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_MASK   (0x8000U)
#define SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_SHIFT  (15U)
/*! ST_XO32K_FAILED - When XO32K oscillation fail flag is state 1 in PMC register block, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST0_ST_XO32K_FAILED(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_SHIFT)) & SYSCON_ELS_AS_ST0_ST_XO32K_FAILED_MASK)
/*! @} */

/*! @name ELS_AS_ST1 - ELS AS state1 */
/*! @{ */

#define SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_MASK   (0xFU)
#define SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_SHIFT  (0U)
/*! ST_QK_PUF_SCORE - These register bits indicate the state of "qk_puf_score[3:0]" outputs from QK PUF block. */
#define SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_SHIFT)) & SYSCON_ELS_AS_ST1_ST_QK_PUF_SCORE_MASK)

#define SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_MASK    (0x10U)
#define SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_SHIFT   (4U)
/*! ST_QK_ZEROIZED - This register bit indicates the state of "qk_zeroized" output from QK PUF block. */
#define SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_SHIFT)) & SYSCON_ELS_AS_ST1_ST_QK_ZEROIZED_MASK)

#define SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_MASK (0x20U)
#define SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_SHIFT (5U)
/*! ST_MAIN_CLK_IS_EXT - When MAIN_CLK is running from external clock source either XO32M, XO32K or GPIO CLKIN, this bit indicates state 1. */
#define SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_MASK)

#define SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_MASK      (0x3C0U)
#define SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_SHIFT     (6U)
/*! ST_DCDC_VOUT - VOUT[3:0] setting on DCDC0 register in PMC block will reflect to this register. */
#define SYSCON_ELS_AS_ST1_ST_DCDC_VOUT(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_DCDC_VOUT_MASK)

#define SYSCON_ELS_AS_ST1_ST_BOOT_MODE_MASK      (0xC00U)
#define SYSCON_ELS_AS_ST1_ST_BOOT_MODE_SHIFT     (10U)
/*! ST_BOOT_MODE - BOOTMODE[1:0] status on STATUS register in PMC block will reflect to this register. */
#define SYSCON_ELS_AS_ST1_ST_BOOT_MODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_BOOT_MODE_SHIFT)) & SYSCON_ELS_AS_ST1_ST_BOOT_MODE_MASK)

#define SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_MASK (0xF000U)
#define SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_SHIFT (12U)
/*! ST_BOOT_RETRY_CNT - "BOOT_RETRY_CNT[3:0]" on "ELS_BOOT_RETRY_CNT" register reflects this register. */
#define SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_SHIFT)) & SYSCON_ELS_AS_ST1_ST_BOOT_RETRY_CNT_MASK)
/*! @} */

/*! @name ELS_AS_ST2 - ELS AS state2 */
/*! @{ */

#define SYSCON_ELS_AS_ST2_ELS_AS_ST2_MASK        (0xFFFFFFFFU)
#define SYSCON_ELS_AS_ST2_ELS_AS_ST2_SHIFT       (0U)
/*! ELS_AS_ST2 - "BOOT_STATE[31:0]" on "ELS_BOOT_STATE" register reflects this register. */
#define SYSCON_ELS_AS_ST2_ELS_AS_ST2(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_ST2_ELS_AS_ST2_SHIFT)) & SYSCON_ELS_AS_ST2_ELS_AS_ST2_MASK)
/*! @} */

/*! @name ELS_AS_FLAG0 - ELS AS flag0 */
/*! @{ */

#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_MASK (0x1U)
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_SHIFT (0U)
/*! FLAG_AP_ENABLE_CPU0 - This flag bit is set 1 when DAP enables AP0 for CPU0 (CM33) debug access. The register is cleared 0 by PMC reset event. */
#define SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_RESET_OCCURED_MASK (0x10U)
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_RESET_OCCURED_SHIFT (4U)
/*! FLAG_BOD_VBAT_RESET_OCCURED - This flag bit is set 1 when BOD VDDMAIN reset is enabled and BOD
 *    VDDMAIN analog detector is tripped. This register is cleared 0 by AO domain POR.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_RESET_OCCURED_MASK (0x20U)
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_RESET_OCCURED_SHIFT (5U)
/*! FLAG_BOD_CORE_RESET_OCCURED - This flag bit is set 1 when BOD CORE reset is enabled and BOD CORE
 *    analog detector is tripped. This register is cleared 0 by AO domain POR.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_IRQ_OCCURED_MASK (0x40U)
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_IRQ_OCCURED_SHIFT (6U)
/*! FLAG_BOD_VBAT_IRQ_OCCURED - This flag bit is set 1 when BOD VDDMAIN IRQ is enabled and BOD
 *    VDDMAIN analog detector is tripped. This register is cleared 0 by PMC reset event.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_BOD_VBAT_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_IRQ_OCCURED_MASK (0x80U)
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_IRQ_OCCURED_SHIFT (7U)
/*! FLAG_BOD_CORE_IRQ_OCCURED - This flag bit is set 1 when BOD CORE IRQ is enabled and BOD CORE
 *    analog detector is tripped. This register is cleared 0 by PMC reset event.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_BOD_CORE_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_WDT_RESET_OCCURED_MASK (0x100U)
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT_RESET_OCCURED_SHIFT (8U)
/*! FLAG_WDT_RESET_OCCURED - This flag bit is set 1 when WatchDog Timer reset is enabled and reset
 *    event is triggered. This register is cleared 0 by AO domain POR.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_WDT_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_WDT_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT_RESET_OCCURED_MASK (0x200U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT_RESET_OCCURED_SHIFT (9U)
/*! FLAG_CWDT_RESET_OCCURED - This flag bit is set 1 when Code WatchDog Timer reset is enabled and
 *    reset event is triggered. This register is cleared 0 by AO domain POR.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CWDT_RESET_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CWDT_RESET_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_WDT_IRQ_OCCURED_MASK (0x400U)
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT_IRQ_OCCURED_SHIFT (10U)
/*! FLAG_WDT_IRQ_OCCURED - This flag register is set 1 when WatchDog Timer IRQ is enabled and IRQ
 *    event is triggered. This register is cleared 0 by PMC reset event.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_WDT_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_WDT_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_WDT_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT_IRQ_OCCURED_MASK (0x800U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT_IRQ_OCCURED_SHIFT (11U)
/*! FLAG_CWDT_IRQ_OCCURED - This flag bit is set 1 when Code WatchDog Timer IRQ is enabled and IRQ
 *    event is triggered. This register is cleared 0 by PMC reset event.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CWDT_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CWDT_IRQ_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CWDT_IRQ_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_MASK   (0x1000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_SHIFT  (12U)
/*! FLAG_QK_ERROR - This flag bit is set 1 when QK_ERROR is flagged from QK PUF block. This register is cleared 0 by PMC reset event. */
#define SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_QK_ERROR_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_MASK (0x2000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_SHIFT (13U)
/*! FLAG_ELS_GLITCH_DETECTED - This flag bit is set 1 when GDET error is flagged from ELS. This register is cleared 0 by PMC reset event. */
#define SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_ELS_GLITCH_DETECTED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_MASK (0x8000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_SHIFT (15U)
/*! FLAG_TAMPER_EVENT_DETECTED - This flag bit is set 1 when tamper event is flagged from RTC. This
 *    register is cleared 0 by AO domain POR or by PMC reset event, if ranmpr detection event is
 *    cleared by software.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_TAMPER_EVENT_DETECTED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_MASK (0x10000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_SHIFT (16U)
/*! FLAG_FLASH_ECC_INVALID - This flag bit is set 1 when FLASH controller indicates ECC error. This register is cleared 0 by PMC reset event. */
#define SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_FLASH_ECC_INVALID_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_MASK (0x20000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_SHIFT (17U)
/*! FLAG_SEC_VIOL_IRQ_OCURRED - This flag bit is set 1 when security violation is indicated from FLASH sub-system or AHB bus matrix. */
#define SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_SEC_VIOL_IRQ_OCURRED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_MASK (0x40000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_SHIFT (18U)
/*! FLAG_CPU0_NS_C_ACC_OCCURED - This flag bit is set 1 when CPU0 (CM33) makes non-secure code
 *    transactions. This register is cleared 0 by PMC reset event.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_MASK)

#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_MASK (0x80000U)
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_SHIFT (19U)
/*! FLAG_CPU0_NS_D_ACC_OCCURED - This flag register is set 1 when CPU0 (CM33) makes non-secure data
 *    transactions. This register is cleared 0 by PMC reset event.
 */
#define SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_SHIFT)) & SYSCON_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_MASK)
/*! @} */

/*! @name CLOCK_CTRL - Clock Control */
/*! @{ */

#define SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_MASK (0x2U)
#define SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_SHIFT (1U)
/*! XTAL32MHZ_FREQM_ENA - Enable XTAL32MHz clock for Frequency Measure module.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_MASK (0x4U)
#define SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_SHIFT (2U)
/*! FRO1MHZ_UTICK_ENA - Enable FRO 1MHz clock for Frequency Measure module and for UTICK.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO12MHZ_FREQM_ENA_MASK (0x8U)
#define SYSCON_CLOCK_CTRL_FRO12MHZ_FREQM_ENA_SHIFT (3U)
/*! FRO12MHZ_FREQM_ENA - Enable FRO 12MHz clock for Frequency Measure module.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_FRO12MHZ_FREQM_ENA(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO12MHZ_FREQM_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO12MHZ_FREQM_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO_HF_FREQM_ENA_MASK  (0x10U)
#define SYSCON_CLOCK_CTRL_FRO_HF_FREQM_ENA_SHIFT (4U)
/*! FRO_HF_FREQM_ENA - Enable FRO 96MHz clock for Frequency Measure module.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_FRO_HF_FREQM_ENA(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO_HF_FREQM_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO_HF_FREQM_ENA_MASK)

#define SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK         (0x20U)
#define SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT        (5U)
/*! CLKIN_ENA - Enable clock_in clock for clock module.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_CLKIN_ENA(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK)

#define SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK   (0x40U)
#define SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_SHIFT  (6U)
/*! FRO1MHZ_CLK_ENA - Enable FRO 1MHz clock for clock muxing in clock gen.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK)

#define SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK (0x80U)
#define SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT (7U)
/*! ANA_FRO12M_CLK_ENA - Enable FRO 12MHz clock for analog control of the FRO 192MHz.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK)

#define SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_MASK    (0x100U)
#define SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_SHIFT   (8U)
/*! XO_CAL_CLK_ENA - Enable clock for crystal oscillator calibration
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_MASK)
/*! @} */

/*! @name COMP_INT_CTRL - Comparator Interrupt control */
/*! @{ */

#define SYSCON_COMP_INT_CTRL_INT_ENABLE_MASK     (0x1U)
#define SYSCON_COMP_INT_CTRL_INT_ENABLE_SHIFT    (0U)
/*! INT_ENABLE - Analog Comparator interrupt enable control:.
 *  0b0..interrupt disable.
 *  0b1..interrupt enable.
 */
#define SYSCON_COMP_INT_CTRL_INT_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_CTRL_INT_ENABLE_SHIFT)) & SYSCON_COMP_INT_CTRL_INT_ENABLE_MASK)

#define SYSCON_COMP_INT_CTRL_INT_CLEAR_MASK      (0x2U)
#define SYSCON_COMP_INT_CTRL_INT_CLEAR_SHIFT     (1U)
/*! INT_CLEAR - Analog Comparator interrupt clear.
 *  0b0..No effect.
 *  0b1..Clear the interrupt. Self-cleared bit.
 */
#define SYSCON_COMP_INT_CTRL_INT_CLEAR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_CTRL_INT_CLEAR_SHIFT)) & SYSCON_COMP_INT_CTRL_INT_CLEAR_MASK)

#define SYSCON_COMP_INT_CTRL_INT_CTRL_MASK       (0x1CU)
#define SYSCON_COMP_INT_CTRL_INT_CTRL_SHIFT      (2U)
/*! INT_CTRL - Comparator interrupt type selector:.
 *  0b000..The analog comparator interrupt edge sensitive is disabled.
 *  0b001..The analog comparator interrupt level sensitive is disabled.
 *  0b010..analog comparator interrupt is rising edge sensitive.
 *  0b011..Analog Comparator interrupt is high level sensitive.
 *  0b100..analog comparator interrupt is falling edge sensitive.
 *  0b101..Analog Comparator interrupt is low level sensitive.
 *  0b110..analog comparator interrupt is rising and falling edge sensitive.
 *  0b111..The analog comparator interrupt level sensitive is disabled.
 */
#define SYSCON_COMP_INT_CTRL_INT_CTRL(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_CTRL_INT_CTRL_SHIFT)) & SYSCON_COMP_INT_CTRL_INT_CTRL_MASK)

#define SYSCON_COMP_INT_CTRL_INT_SOURCE_MASK     (0x20U)
#define SYSCON_COMP_INT_CTRL_INT_SOURCE_SHIFT    (5U)
/*! INT_SOURCE - Select which Analog comparator output (filtered our un-filtered) is used for interrupt detection.
 *  0b0..Select Analog Comparator filtered output as input for interrupt detection.
 *  0b1..Select Analog Comparator raw output (unfiltered) as input for interrupt detection. Must be used when
 *       Analog comparator is used as wake up source in Power down mode.
 */
#define SYSCON_COMP_INT_CTRL_INT_SOURCE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_CTRL_INT_SOURCE_SHIFT)) & SYSCON_COMP_INT_CTRL_INT_SOURCE_MASK)
/*! @} */

/*! @name COMP_INT_STATUS - Comparator Interrupt status */
/*! @{ */

#define SYSCON_COMP_INT_STATUS_STATUS_MASK       (0x1U)
#define SYSCON_COMP_INT_STATUS_STATUS_SHIFT      (0U)
/*! STATUS - Interrupt status BEFORE Interrupt Enable.
 *  0b0..No interrupt pending.
 *  0b1..Interrupt pending.
 */
#define SYSCON_COMP_INT_STATUS_STATUS(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_STATUS_STATUS_SHIFT)) & SYSCON_COMP_INT_STATUS_STATUS_MASK)

#define SYSCON_COMP_INT_STATUS_INT_STATUS_MASK   (0x2U)
#define SYSCON_COMP_INT_STATUS_INT_STATUS_SHIFT  (1U)
/*! INT_STATUS - Interrupt status AFTER Interrupt Enable.
 *  0b0..no interrupt pending.
 *  0b1..interrupt pending.
 */
#define SYSCON_COMP_INT_STATUS_INT_STATUS(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_STATUS_INT_STATUS_SHIFT)) & SYSCON_COMP_INT_STATUS_INT_STATUS_MASK)

#define SYSCON_COMP_INT_STATUS_VAL_MASK          (0x4U)
#define SYSCON_COMP_INT_STATUS_VAL_SHIFT         (2U)
/*! VAL - comparator analog output.
 *  0b0..P+ is smaller than P-.
 *  0b1..P+ is greater than P-.
 */
#define SYSCON_COMP_INT_STATUS_VAL(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_COMP_INT_STATUS_VAL_SHIFT)) & SYSCON_COMP_INT_STATUS_VAL_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE - Control automatic clock gating */
/*! @{ */

#define SYSCON_AUTOCLKGATEOVERRIDE_ROM_MASK      (0x1U)
#define SYSCON_AUTOCLKGATEOVERRIDE_ROM_SHIFT     (0U)
/*! ROM - Control automatic clock gating of ROM controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_ROM(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_ROM_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_ROM_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMX_MASK     (0x2U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMX_SHIFT    (1U)
/*! RAMX - Control automatic clock gating of RAMX controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMX(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMX_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMX_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM0_MASK     (0x4U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM0_SHIFT    (2U)
/*! RAM0 - Control automatic clock gating of RAM0 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM1_MASK     (0x8U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM1_SHIFT    (3U)
/*! RAM1 - Control automatic clock gating of RAM1 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM1_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM1_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM2_MASK     (0x10U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM2_SHIFT    (4U)
/*! RAM2 - Control automatic clock gating of RAM2 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM2(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM2_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM2_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM3_MASK     (0x20U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM3_SHIFT    (5U)
/*! RAM3 - Control automatic clock gating of RAM3 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM3(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM3_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM3_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM4_MASK     (0x40U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM4_SHIFT    (6U)
/*! RAM4 - Control automatic clock gating of RAM4 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM4(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM4_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM4_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB_MASK (0x80U)
#define SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB_SHIFT (7U)
/*! SYNC0_APB - Control automatic clock gating of synchronous bridge controller 0.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB_MASK (0x100U)
#define SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB_SHIFT (8U)
/*! SYNC1_APB - Control automatic clock gating of synchronous bridge controller 1.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN_MASK   (0x800U)
#define SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN_SHIFT  (11U)
/*! CRCGEN - Control automatic clock gating of CRCGEN controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_SDMA0_MASK    (0x1000U)
#define SYSCON_AUTOCLKGATEOVERRIDE_SDMA0_SHIFT   (12U)
/*! SDMA0 - Control automatic clock gating of DMA0 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_SDMA0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_SDMA0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_SDMA0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_SDMA1_MASK    (0x2000U)
#define SYSCON_AUTOCLKGATEOVERRIDE_SDMA1_SHIFT   (13U)
/*! SDMA1 - Control automatic clock gating of DMA1 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_SDMA1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_SDMA1_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_SDMA1_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_USB0_MASK     (0x4000U)
#define SYSCON_AUTOCLKGATEOVERRIDE_USB0_SHIFT    (14U)
/*! USB0 - Control automatic clock gating of USB controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_USB0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_USB0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_USB0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_SYSCON_MASK   (0x8000U)
#define SYSCON_AUTOCLKGATEOVERRIDE_SYSCON_SHIFT  (15U)
/*! SYSCON - Control automatic clock gating of synchronous system controller registers bank.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_SYSCON(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_SYSCON_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_SYSCON_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE_MASK (0xFFFF0000U)
#define SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE_SHIFT (16U)
/*! ENABLEUPDATE - The value 0xC0DE must be written for AUTOCLKGATEOVERRIDE registers fields updates to have effect.
 *  0b0000000000000000..Bit Fields 0 - 15 of this register are not updated
 *  0b1100000011011110..Bit Fields 0 - 15 of this register are updated
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE_MASK)
/*! @} */

/*! @name GPIOPSYNC - GPIO Synchronization */
/*! @{ */

#define SYSCON_GPIOPSYNC_PSYNC_MASK              (0x1U)
#define SYSCON_GPIOPSYNC_PSYNC_SHIFT             (0U)
/*! PSYNC - Enable bypass of the first stage of synchronization inside GPIO_INT module.
 *  0b0..Use the first stage of synchronization inside GPIO_INT module.
 *  0b1..Bypass of the first stage of synchronization inside GPIO_INT module.
 */
#define SYSCON_GPIOPSYNC_PSYNC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_GPIOPSYNC_PSYNC_SHIFT)) & SYSCON_GPIOPSYNC_PSYNC_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE1 - Control automatic clock gating */
/*! @{ */

#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC0_MASK    (0x1U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC0_SHIFT   (0U)
/*! DAC0 - DAC0 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_DAC0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_DAC0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC1_MASK    (0x2U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC1_SHIFT   (1U)
/*! DAC1 - DAC1 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_DAC1_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_DAC1_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC2_MASK    (0x4U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC2_SHIFT   (2U)
/*! DAC2 - DAC2 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_DAC2(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_DAC2_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_DAC2_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP0_MASK  (0x8U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP0_SHIFT (3U)
/*! OPAMP0 - OPAMP0 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP1_MASK  (0x10U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP1_SHIFT (4U)
/*! OPAMP1 - OPAMP1 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP1_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP1_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP2_MASK  (0x20U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP2_SHIFT (5U)
/*! OPAMP2 - OPAMP2 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP2(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP2_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_OPAMP2_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP0_MASK  (0x40U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP0_SHIFT (6U)
/*! HSCMP0 - HSCMP0 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP1_MASK  (0x80U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP1_SHIFT (7U)
/*! HSCMP1 - HSCMP0 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP1_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP1_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP2_MASK  (0x100U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP2_SHIFT (8U)
/*! HSCMP2 - HSCMP2 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP2(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP2_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_HSCMP2_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_VREF_MASK    (0x200U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_VREF_SHIFT   (9U)
/*! VREF - VREF */
#define SYSCON_AUTOCLKGATEOVERRIDE1_VREF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_VREF_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_VREF_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_PWM0_MASK    (0x400U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_PWM0_SHIFT   (10U)
/*! PWM0 - PWM0 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_PWM0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_PWM0_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_PWM0_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE1_PWM1_MASK    (0x800U)
#define SYSCON_AUTOCLKGATEOVERRIDE1_PWM1_SHIFT   (11U)
/*! PWM1 - PWM1 */
#define SYSCON_AUTOCLKGATEOVERRIDE1_PWM1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE1_PWM1_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE1_PWM1_MASK)
/*! @} */

/*! @name ENABLE_MEM_PARITY_ECC_CHECK - Memory parity ECC enable */
/*! @{ */

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx_MASK (0x1U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx_SHIFT (0U)
/*! ENABLE_RAMx - Enable RAMx parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM00_MASK (0x2U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM00_SHIFT (1U)
/*! ENABLE_RAM00 - Enable RAM00 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM00(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM00_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM00_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM01_MASK (0x4U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM01_SHIFT (2U)
/*! ENABLE_RAM01 - Enable RAM01 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM01(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM01_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM01_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx02_MASK (0x8U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx02_SHIFT (3U)
/*! ENABLE_RAMx02 - Enable RAMx02 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx02(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx02_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAMx02_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM03_MASK (0x10U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM03_SHIFT (4U)
/*! ENABLE_RAM03 - Enable RAM03 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM03(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM03_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM03_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_MBIT_MASK (0x20U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_MBIT_SHIFT (5U)
/*! ENABLE_RAM1_MBIT - Enable RAM1 ECC mbit error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_MBIT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_MBIT_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_MBIT_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_SBIT_MASK (0x40U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_SBIT_SHIFT (6U)
/*! ENABLE_RAM1_SBIT - Enable RAM1 ECC sbit error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_SBIT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_SBIT_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM1_SBIT_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM2_MASK (0x80U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM2_SHIFT (7U)
/*! ENABLE_RAM2 - Enable RAM2 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM2(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM2_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM2_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM3_MASK (0x100U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM3_SHIFT (8U)
/*! ENABLE_RAM3 - Enable RAM3 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM3(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM3_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM3_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM40_MASK (0x200U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM40_SHIFT (9U)
/*! ENABLE_RAM40 - Enable RAM40 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM40(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM40_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM40_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM41_MASK (0x400U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM41_SHIFT (10U)
/*! ENABLE_RAM41 - Enable RAM41 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM41(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM41_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM41_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM42_MASK (0x800U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM42_SHIFT (11U)
/*! ENABLE_RAM42 - Enable RAM42 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM42(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM42_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM42_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM43_MASK (0x1000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM43_SHIFT (12U)
/*! ENABLE_RAM43 - Enable RAM43 parity error check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM43(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM43_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_ENABLE_RAM43_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAMX_PARITY_ERROR_INTEN_MASK (0x100000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAMX_PARITY_ERROR_INTEN_SHIFT (20U)
/*! RAMX_PARITY_ERROR_INTEN - Interrupt enable for RAMX parity error
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAMX parity error status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAMX_PARITY_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAMX_PARITY_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAMX_PARITY_ERROR_INTEN_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM0_PARITY_ERROR_INTEN_MASK (0x200000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM0_PARITY_ERROR_INTEN_SHIFT (21U)
/*! RAM0_PARITY_ERROR_INTEN - Interrupt enable for RAM0 parity error
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAM0 parity error status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM0_PARITY_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM0_PARITY_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM0_PARITY_ERROR_INTEN_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_MBIT_ERROR_INTEN_MASK (0x400000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_MBIT_ERROR_INTEN_SHIFT (22U)
/*! RAM1_ECC_MBIT_ERROR_INTEN - Interrupt enable for RAM1 ECC mbit_err
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAM1 ECC mbit_err status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_MBIT_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_MBIT_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_MBIT_ERROR_INTEN_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_SBIT_ERROR_INTEN_MASK (0x800000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_SBIT_ERROR_INTEN_SHIFT (23U)
/*! RAM1_ECC_SBIT_ERROR_INTEN - Interrupt enable for RAM1 ECC sbit_err
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAM1 ECC sbit_err status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_SBIT_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_SBIT_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM1_ECC_SBIT_ERROR_INTEN_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM2_PARITY_ERROR_INTEN_MASK (0x1000000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM2_PARITY_ERROR_INTEN_SHIFT (24U)
/*! RAM2_PARITY_ERROR_INTEN - Interrupt enable for RAM2 parity error
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAM2 parity error status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM2_PARITY_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM2_PARITY_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM2_PARITY_ERROR_INTEN_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM3_PARITY_ERROR_INTEN_MASK (0x2000000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM3_PARITY_ERROR_INTEN_SHIFT (25U)
/*! RAM3_PARITY_ERROR_INTEN - Interrupt enable for RAM3 parity error
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAM3 parity error status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM3_PARITY_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM3_PARITY_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM3_PARITY_ERROR_INTEN_MASK)

#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM4_PARITY_ERROR_INTEN_MASK (0x4000000U)
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM4_PARITY_ERROR_INTEN_SHIFT (26U)
/*! RAM4_PARITY_ERROR_INTEN - Interrupt enable for RAM4 parity error
 *  0b0..Disable.
 *  0b1..Enable RAM error interrupt when RAM4 parity error status flag is set.
 */
#define SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM4_PARITY_ERROR_INTEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM4_PARITY_ERROR_INTEN_SHIFT)) & SYSCON_ENABLE_MEM_PARITY_ECC_CHECK_RAM4_PARITY_ERROR_INTEN_MASK)
/*! @} */

/*! @name MEM_PARITY_ECC_ERROR_FLAG - Memory parity ECC error flag */
/*! @{ */

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAMX_PARITY_ERROR_MASK (0x1U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAMX_PARITY_ERROR_SHIFT (0U)
/*! RAMX_PARITY_ERROR - RAMx parity error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAMX_PARITY_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAMX_PARITY_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAMX_PARITY_ERROR_MASK)

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM0_PARITY_ERROR_MASK (0x2U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM0_PARITY_ERROR_SHIFT (1U)
/*! RAM0_PARITY_ERROR - RAM0 parity error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM0_PARITY_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM0_PARITY_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM0_PARITY_ERROR_MASK)

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_MBIT_ERROR_MASK (0x4U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_MBIT_ERROR_SHIFT (2U)
/*! RAM1_ECC_MBIT_ERROR - RAM1 ECC mbit error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_MBIT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_MBIT_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_MBIT_ERROR_MASK)

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_SBIT_ERROR_MASK (0x8U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_SBIT_ERROR_SHIFT (3U)
/*! RAM1_ECC_SBIT_ERROR - RAM1 ECC sbit error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_SBIT_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_SBIT_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM1_ECC_SBIT_ERROR_MASK)

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM2_PARITY_ERROR_MASK (0x10U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM2_PARITY_ERROR_SHIFT (4U)
/*! RAM2_PARITY_ERROR - RAM2 parity error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM2_PARITY_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM2_PARITY_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM2_PARITY_ERROR_MASK)

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM3_PARITY_ERROR_MASK (0x20U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM3_PARITY_ERROR_SHIFT (5U)
/*! RAM3_PARITY_ERROR - RAM3 parity error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM3_PARITY_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM3_PARITY_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM3_PARITY_ERROR_MASK)

#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM4_PARITY_ERROR_MASK (0x40U)
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM4_PARITY_ERROR_SHIFT (6U)
/*! RAM4_PARITY_ERROR - RAM4 parity error detected
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM4_PARITY_ERROR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM4_PARITY_ERROR_SHIFT)) & SYSCON_MEM_PARITY_ECC_ERROR_FLAG_RAM4_PARITY_ERROR_MASK)
/*! @} */

/*! @name PWM0SUBCTL - PWM0 submodule control */
/*! @{ */

#define SYSCON_PWM0SUBCTL_CLK0_EN_MASK           (0x1U)
#define SYSCON_PWM0SUBCTL_CLK0_EN_SHIFT          (0U)
/*! CLK0_EN - PWM0 SUB Clock0 enable */
#define SYSCON_PWM0SUBCTL_CLK0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK0_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK0_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK1_EN_MASK           (0x2U)
#define SYSCON_PWM0SUBCTL_CLK1_EN_SHIFT          (1U)
/*! CLK1_EN - PWM0 SUB Clock1 enable */
#define SYSCON_PWM0SUBCTL_CLK1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK1_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK1_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK2_EN_MASK           (0x4U)
#define SYSCON_PWM0SUBCTL_CLK2_EN_SHIFT          (2U)
/*! CLK2_EN - PWM0 SUB Clock2 enable */
#define SYSCON_PWM0SUBCTL_CLK2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK2_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK2_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK3_EN_MASK           (0x8U)
#define SYSCON_PWM0SUBCTL_CLK3_EN_SHIFT          (3U)
/*! CLK3_EN - PWM0 SUB Clock3 enable */
#define SYSCON_PWM0SUBCTL_CLK3_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK3_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK3_EN_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM0_MASK          (0x1000U)
#define SYSCON_PWM0SUBCTL_DMAVALM0_SHIFT         (12U)
/*! DMAVALM0 - PWM0 submodule 0 DMA Compare Value Done Mask */
#define SYSCON_PWM0SUBCTL_DMAVALM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM0_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM0_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM1_MASK          (0x2000U)
#define SYSCON_PWM0SUBCTL_DMAVALM1_SHIFT         (13U)
/*! DMAVALM1 - PWM0 submodule 1 DMA Compare Value Done Mask */
#define SYSCON_PWM0SUBCTL_DMAVALM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM1_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM1_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM2_MASK          (0x4000U)
#define SYSCON_PWM0SUBCTL_DMAVALM2_SHIFT         (14U)
/*! DMAVALM2 - PWM0 submodule 2 DMA Compare Value Done Mask */
#define SYSCON_PWM0SUBCTL_DMAVALM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM2_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM2_MASK)

#define SYSCON_PWM0SUBCTL_DMAVALM3_MASK          (0x8000U)
#define SYSCON_PWM0SUBCTL_DMAVALM3_SHIFT         (15U)
/*! DMAVALM3 - PWM0 submodule 3 DMA Compare Value Done Mask */
#define SYSCON_PWM0SUBCTL_DMAVALM3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_DMAVALM3_SHIFT)) & SYSCON_PWM0SUBCTL_DMAVALM3_MASK)
/*! @} */

/*! @name PWM1SUBCTL - PWM1 submodule control */
/*! @{ */

#define SYSCON_PWM1SUBCTL_CLK0_EN_MASK           (0x1U)
#define SYSCON_PWM1SUBCTL_CLK0_EN_SHIFT          (0U)
/*! CLK0_EN - PWM1 SUB Clock0 enable */
#define SYSCON_PWM1SUBCTL_CLK0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK0_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK0_EN_MASK)

#define SYSCON_PWM1SUBCTL_CLK1_EN_MASK           (0x2U)
#define SYSCON_PWM1SUBCTL_CLK1_EN_SHIFT          (1U)
/*! CLK1_EN - PWM1 SUB Clock1 enable */
#define SYSCON_PWM1SUBCTL_CLK1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK1_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK1_EN_MASK)

#define SYSCON_PWM1SUBCTL_CLK2_EN_MASK           (0x4U)
#define SYSCON_PWM1SUBCTL_CLK2_EN_SHIFT          (2U)
/*! CLK2_EN - PWM1 SUB Clock2 enable */
#define SYSCON_PWM1SUBCTL_CLK2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK2_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK2_EN_MASK)

#define SYSCON_PWM1SUBCTL_CLK3_EN_MASK           (0x8U)
#define SYSCON_PWM1SUBCTL_CLK3_EN_SHIFT          (3U)
/*! CLK3_EN - PWM1 SUB Clock3 enable */
#define SYSCON_PWM1SUBCTL_CLK3_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_CLK3_EN_SHIFT)) & SYSCON_PWM1SUBCTL_CLK3_EN_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM0_MASK          (0x1000U)
#define SYSCON_PWM1SUBCTL_DMAVALM0_SHIFT         (12U)
/*! DMAVALM0 - PWM1 submodule 0 DMA Compare Value Done Mask */
#define SYSCON_PWM1SUBCTL_DMAVALM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM0_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM0_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM1_MASK          (0x2000U)
#define SYSCON_PWM1SUBCTL_DMAVALM1_SHIFT         (13U)
/*! DMAVALM1 - PWM1 submodule 1 DMA Compare Value Done Mask */
#define SYSCON_PWM1SUBCTL_DMAVALM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM1_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM1_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM2_MASK          (0x4000U)
#define SYSCON_PWM1SUBCTL_DMAVALM2_SHIFT         (14U)
/*! DMAVALM2 - PWM1 submodule 2 DMA Compare Value Done Mask */
#define SYSCON_PWM1SUBCTL_DMAVALM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM2_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM2_MASK)

#define SYSCON_PWM1SUBCTL_DMAVALM3_MASK          (0x8000U)
#define SYSCON_PWM1SUBCTL_DMAVALM3_SHIFT         (15U)
/*! DMAVALM3 - PWM1 submodule 3 DMA Compare Value Done Mask */
#define SYSCON_PWM1SUBCTL_DMAVALM3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM1SUBCTL_DMAVALM3_SHIFT)) & SYSCON_PWM1SUBCTL_DMAVALM3_MASK)
/*! @} */

/*! @name CTIMERGLOBALSTARTEN - CTIMER global start enable */
/*! @{ */

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK (0x1U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT (0U)
/*! CTIMER0_CLK_EN - CTIMER0 function clock enable */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK (0x2U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT (1U)
/*! CTIMER1_CLK_EN - CTIMER1 function clock enable */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK (0x4U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT (2U)
/*! CTIMER2_CLK_EN - CTIMER2 function clock enable */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK (0x8U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT (3U)
/*! CTIMER3_CLK_EN - CTIMER3 function clock enable */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK (0x10U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT (4U)
/*! CTIMER4_CLK_EN - CTIMER4 function clock enable */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK)
/*! @} */

/*! @name DEBUG_LOCK_EN - Control write access to security */
/*! @{ */

#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK       (0xFU)
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT      (0U)
/*! LOCK_ALL - Control write access to security registers.
 *  0b0000..Any other value than b1010: disable write access to all registers.
 *  0b1010..1010: Enable write access to all registers.
 */
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT)) & SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK)
/*! @} */

/*! @name DEBUG_FEATURES - Cortex debug features control */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN_MASK    (0x3U)
#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT   (0U)
/*! CPU0_DBGEN - CPU0 Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN_MASK    (0xCU)
#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT   (2U)
/*! CPU0_NIDEN - CPU0 Non Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_MASK   (0x30U)
#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT  (4U)
/*! CPU0_SPIDEN - CPU0 Secure Privileged Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_MASK  (0xC0U)
#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 Secure Privileged Non Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_MASK)
/*! @} */

/*! @name DEBUG_FEATURES_DP - Cortex debug features control (duplicate) */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK (0x3U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT (0U)
/*! CPU0_DBGEN - CPU0 Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK (0xCU)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT (2U)
/*! CPU0_NIDEN - CPU0 Non Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK (0x30U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT (4U)
/*! CPU0_SPIDEN - CPU0 Secure Privileged Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK (0xC0U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 Secure Privileged Non Invasive Debug Control
 *  0b01..Disable debug
 *  0b10..Enable debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU - CPU0 Software Debug Access */
/*! @{ */

#define SYSCON_SWD_ACCESS_CPU_SEC_CODE_MASK      (0xFFFFFFFFU)
#define SYSCON_SWD_ACCESS_CPU_SEC_CODE_SHIFT     (0U)
/*! SEC_CODE - CPU0 SWD-AP: 0x12345678.
 *  0b00000000000000000000000000000000..CPU0 DAP is not allowed. Reading back register will be read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable CPU0 SWD access. Reading back register will be read as 0xA.
 */
#define SYSCON_SWD_ACCESS_CPU_SEC_CODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ACCESS_CPU_SEC_CODE_SHIFT)) & SYSCON_SWD_ACCESS_CPU_SEC_CODE_MASK)
/*! @} */

/*! @name DEBUG_AUTH_BEACON - Debug authentication BEACON */
/*! @{ */

#define SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK     (0xFFFFFFFFU)
#define SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT    (0U)
/*! BEACON - Set by the debug authentication code in ROM to pass the debug beacons (Credential
 *    Beacon and Authentication Beacon) to application code.
 */
#define SYSCON_DEBUG_AUTH_BEACON_BEACON(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT)) & SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK)
/*! @} */

/*! @name SWD_ACCESS_DSP - DSP Software Debug Access */
/*! @{ */

#define SYSCON_SWD_ACCESS_DSP_SEC_CODE_MASK      (0xFFFFFFFFU)
#define SYSCON_SWD_ACCESS_DSP_SEC_CODE_SHIFT     (0U)
/*! SEC_CODE - DSP SWD-AP: 0x12345678.
 *  0b00000000000000000000000000000000..DSP DAP is not allowed. Reading back register will be read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable DSP SWD access. Reading back register will be read as 0xA.
 */
#define SYSCON_SWD_ACCESS_DSP_SEC_CODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ACCESS_DSP_SEC_CODE_SHIFT)) & SYSCON_SWD_ACCESS_DSP_SEC_CODE_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_DEVICE_ID_MASK         (0xFFFFFFFFU)
#define SYSCON_DEVICE_ID0_DEVICE_ID_SHIFT        (0U)
/*! DEVICE_ID - Device ID. */
#define SYSCON_DEVICE_ID0_DEVICE_ID(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_DEVICE_ID_SHIFT)) & SYSCON_DEVICE_ID0_DEVICE_ID_MASK)
/*! @} */

/*! @name DIEID - Chip revision ID and Number */
/*! @{ */

#define SYSCON_DIEID_REV_ID_MASK                 (0xFU)
#define SYSCON_DIEID_REV_ID_SHIFT                (0U)
/*! REV_ID - Device Revision. Value read as 0x0 applies to device revision 0A and 1 applies to device revision 1B. */
#define SYSCON_DIEID_REV_ID(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_REV_ID_SHIFT)) & SYSCON_DIEID_REV_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON_Register_Masks */

/*!
 * @brief Get the chip value.
 *
 * @return chip version, 0x0: A0 version chip, 0x1: A1 version chip, 0xFF: invalid version.
 */
static inline uint32_t Chip_GetVersion(void)
{
    uint32_t deviceRevision;

    deviceRevision = SYSCON->DIEID & SYSCON_DIEID_REV_ID_MASK;

    if(0UL == deviceRevision) /* A0 device revision is 0 */
    {
        return 0x0;
    }
    else if(1UL == deviceRevision) /* A1 device revision is 1 */
    {
        return 0x1;
    }
    else
    {
        return 0xFF;
    }
}


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

