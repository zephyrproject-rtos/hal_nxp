/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250624
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
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
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

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
#define SYSCON_PRESETCTRL_PRESETCTRLX_PRESETCTRLX_COUNT 3u
#define SYSCON_PRESETCTRLSET_COUNT                3u
#define SYSCON_PRESETCTRLCLR_COUNT                3u
#define SYSCON_AHBCLKCTRL_AHBCLKCTRLX_AHBCLKCTRLX_COUNT 3u
#define SYSCON_AHBCLKCTRLSET_COUNT                3u
#define SYSCON_AHBCLKCTRLCLR_COUNT                3u
#define SYSCON_SYSTICKCLKSEL_SYSTICKCLKSELX_SYSTICKCLKSELX_COUNT 1u
#define SYSCON_CTIMERCLKSEL_CTIMERCLKSELX_CTIMERCLKSELX_COUNT 5u
#define SYSCON_FCCLKSEL_FCCLKSELX_FCCLKSELX_COUNT 8u
#define SYSCON_FLEXFRGCTRL_FLEXFRGXCTRL_FLEXFRGXCTRL_COUNT 8u
#define SYSCON_STARTER_COUNT                      2u
#define SYSCON_STARTERSET_COUNT                   2u
#define SYSCON_STARTERCLR_COUNT                   2u

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t MEMORYREMAP;                       /**< Memory Remap control register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix priority control register Priority values are 3 = highest, 0 = lowest, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t BUFFERINGAHB2VPB0;                 /**< Buffering of write accesses on Synchronous System configuration APB interface, offset: 0x20 */
  __IO uint32_t BUFFERINGAHB2VPB1;                 /**< Buffering of write accesses on Synchronous System configuration APB interface, offset: 0x24 */
       uint8_t RESERVED_2[16];
  __IO uint32_t CPU0STCKCAL;                       /**< System tick calibration for secure part of CPU0, offset: 0x38 */
  __IO uint32_t CPU0NSTCKCAL;                      /**< System tick calibration for non-secure part of CPU0, offset: 0x3C */
       uint8_t RESERVED_3[8];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
       uint8_t RESERVED_4[180];
  union {                                          /* offset: 0x100 */
    struct {                                         /* offset: 0x100 */
      __IO uint32_t PRESETCTRL0;                       /**< Peripheral reset control 0, offset: 0x100 */
      __IO uint32_t PRESETCTRL1;                       /**< Peripheral reset control 1, offset: 0x104 */
      __IO uint32_t PRESETCTRL2;                       /**< Peripheral reset control 2, offset: 0x108 */
    } PRESETCTRL;
    __IO uint32_t PRESETCTRLX[SYSCON_PRESETCTRL_PRESETCTRLX_PRESETCTRLX_COUNT];   /**< Peripheral reset control register, array offset: 0x100, array step: 0x4 */
  };
       uint8_t RESERVED_5[20];
  __IO uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Peripheral reset control set register, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_6[20];
  __IO uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Peripheral reset control clear register, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_7[20];
  __O  uint32_t SWR_RESET;                         /**< generate a software_reset, offset: 0x160 */
       uint8_t RESERVED_8[156];
  union {                                          /* offset: 0x200 */
    struct {                                         /* offset: 0x200 */
      __IO uint32_t AHBCLKCTRL0;                       /**< AHB Clock control 0, offset: 0x200 */
      __IO uint32_t AHBCLKCTRL1;                       /**< AHB Clock control 1, offset: 0x204 */
      __IO uint32_t AHBCLKCTRL2;                       /**< AHB Clock control 2, offset: 0x208 */
    } AHBCLKCTRL;
    __IO uint32_t AHBCLKCTRLX[SYSCON_AHBCLKCTRL_AHBCLKCTRLX_AHBCLKCTRLX_COUNT];   /**< Peripheral reset control register, array offset: 0x200, array step: 0x4 */
  };
       uint8_t RESERVED_9[20];
  __IO uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< Peripheral reset control register, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_10[20];
  __IO uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< Peripheral reset control register, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_11[20];
  union {                                          /* offset: 0x260 */
    __IO uint32_t SYSTICKCLKSEL0;                    /**< System Tick Timer for CPU0 source select, offset: 0x260 */
    __IO uint32_t SYSTICKCLKSELX[SYSCON_SYSTICKCLKSEL_SYSTICKCLKSELX_SYSTICKCLKSELX_COUNT];   /**< System Tick Timer source select register, array offset: 0x260, array step: 0x4 */
  };
       uint8_t RESERVED_12[4];
  __IO uint32_t TRACECLKSEL;                       /**< Trace clock source select, offset: 0x268 */
  union {                                          /* offset: 0x26C */
    struct {                                         /* offset: 0x26C */
      __IO uint32_t CTIMERCLKSEL0;                     /**< CTimer 0 clock source select, offset: 0x26C */
      __IO uint32_t CTIMERCLKSEL1;                     /**< CTimer 1 clock source select, offset: 0x270 */
      __IO uint32_t CTIMERCLKSEL2;                     /**< CTimer 2 clock source select, offset: 0x274 */
      __IO uint32_t CTIMERCLKSEL3;                     /**< CTimer 3 clock source select, offset: 0x278 */
      __IO uint32_t CTIMERCLKSEL4;                     /**< CTimer 4 clock source select, offset: 0x27C */
    } CTIMERCLKSEL;
    __IO uint32_t CTIMERCLKSELX[SYSCON_CTIMERCLKSEL_CTIMERCLKSELX_CTIMERCLKSELX_COUNT];   /**< CTIMER clock source select register, array offset: 0x26C, array step: 0x4 */
  };
  __IO uint32_t MAINCLKSELA;                       /**< Main clock A source select, offset: 0x280 */
  __IO uint32_t MAINCLKSELB;                       /**< Main clock source select, offset: 0x284 */
  __IO uint32_t CLKOUTSEL;                         /**< CLKOUT clock source select, offset: 0x288 */
       uint8_t RESERVED_13[36];
  union {                                          /* offset: 0x2B0 */
    struct {                                         /* offset: 0x2B0 */
      __IO uint32_t FCCLKSEL0;                         /**< Flexcomm Interface 0 clock source select for Fractional Rate Divider, offset: 0x2B0 */
      __IO uint32_t FCCLKSEL1;                         /**< Flexcomm Interface 1 clock source select for Fractional Rate Divider, offset: 0x2B4 */
      __IO uint32_t FCCLKSEL2;                         /**< Flexcomm Interface 2 clock source select for Fractional Rate Divider, offset: 0x2B8 */
    } FCCLKSEL;
    __IO uint32_t FCCLKSELX[SYSCON_FCCLKSEL_FCCLKSELX_FCCLKSELX_COUNT];   /**< Flexcomm clock source select register for Fractional Rate Divider, array offset: 0x2B0, array step: 0x4 */
  };
  __IO uint32_t SPIFICLKSEL;                       /**< QuadSPI Flash Interface clock source select, offset: 0x2D0 */
       uint8_t RESERVED_14[28];
  __IO uint32_t SCTCLKSEL;                         /**< SCTimer/PWM clock source select, offset: 0x2F0 */
       uint8_t RESERVED_15[12];
  __IO uint32_t SYSTICKCLKDIV0;                    /**< System Tick Timer divider for CPU0, offset: 0x300 */
       uint8_t RESERVED_16[4];
  __IO uint32_t TRACECLKDIV;                       /**< TRACE clock divider, offset: 0x308 */
       uint8_t RESERVED_17[20];
  union {                                          /* offset: 0x320 */
    struct {                                         /* offset: 0x320 */
      __IO uint32_t FLEXFRG0CTRL;                      /**< Fractional rate divider for flexcomm 0, offset: 0x320 */
      __IO uint32_t FLEXFRG1CTRL;                      /**< Fractional rate divider for flexcomm 1, offset: 0x324 */
      __IO uint32_t FLEXFRG2CTRL;                      /**< Fractional rate divider for flexcomm 2, offset: 0x328 */
    } FLEXFRGCTRL;
    __IO uint32_t FLEXFRGXCTRL[SYSCON_FLEXFRGCTRL_FLEXFRGXCTRL_FLEXFRGXCTRL_COUNT];   /**< Peripheral reset control register, array offset: 0x320, array step: 0x4 */
  };
       uint8_t RESERVED_18[64];
  __IO uint32_t AHBCLKDIV;                         /**< System clock divider, offset: 0x380 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider, offset: 0x384 */
  __IO uint32_t FROHFDIV;                          /**< FRO_HF (32MHz) clock divider, offset: 0x388 */
  __IO uint32_t WDTCLKDIV;                         /**< WDT clock divider, offset: 0x38C */
       uint8_t RESERVED_19[36];
  __IO uint32_t SCTCLKDIV;                         /**< SCT/PWM clock divider, offset: 0x3B4 */
       uint8_t RESERVED_20[24];
  __IO uint32_t SPIFICLKDIV;                       /**< QuadSPI Flash Interface Clock divider, offset: 0x3D0 */
       uint8_t RESERVED_21[40];
  __IO uint32_t CLOCKGENUPDATELOCKOUT;             /**< Control clock configuration registers access (like xxxDIV, xxxSEL), offset: 0x3FC */
       uint8_t RESERVED_22[4];
  __IO uint32_t ROMCR;                             /**< ROM access configuration register, offset: 0x404 */
       uint8_t RESERVED_23[12];
  __IO uint32_t EZHINT;                            /**< EZH interrupt hijack, offset: 0x414 */
       uint8_t RESERVED_24[40];
  __IO uint32_t FLASHREMAP_SIZE;                   /**< This 32-bit register contains the size of the image to remap, in bytes. The 12 LSBs are ignored, so the size granularity is 4KB., offset: 0x440 */
  __IO uint32_t FLASHREMAP_SIZE_DP;                /**< This 32-bit register is a duplicate of FLASHREMAPSIZE for increased security., offset: 0x444 */
  __IO uint32_t FLASHREMAP_OFFSET;                 /**< This 32-bit register contains the offset by which the image is to be remapped. The 12 LSBs are ignored, so the remap granularity is 4KB., offset: 0x448 */
  __IO uint32_t FLASHREMAP_OFFSET_DP;              /**< This 32-bit register is a duplicate of FLASHREMAPOFFSET for increased security., offset: 0x44C */
  __IO uint32_t FLASHBANKENABLE;                   /**< Flash Banks control, offset: 0x450 */
       uint8_t RESERVED_25[8];
  __IO uint32_t FLASHREMAP_LOCK;                   /**< Control write access to FLASHREMAP_SIZE and FLASHREMAP_OFFSET registers., offset: 0x45C */
       uint8_t RESERVED_26[16];
  __IO uint32_t CASPER_CTRL;                       /**< Control CASPER integration., offset: 0x470 */
       uint8_t RESERVED_27[12];
  __IO uint32_t BOOT_LOCKOUT_ADDR;                 /**< When ROM address is below the Address Offset. The access to ROM is block if BOOT_LOCKOUT is LOCK., offset: 0x480 */
  __IO uint32_t BOOT_LOCKOUT_ADDR_DP;              /**< When ROM address is below the Address Offset. The access to ROM is block if BOOT_LOCKOUT is LOCK. Duplicate of BOOT_LOCKOUT_ADDR., offset: 0x484 */
  __IO uint32_t BOOT_LOCKOUT;                      /**< Control write access to BOOT_LOCKOUT_ADDR and BOOT_LOCKOUT_ADDR registers and ROM memory., offset: 0x488 */
       uint8_t RESERVED_28[500];
  __IO uint32_t STARTER[SYSCON_STARTER_COUNT];     /**< Start logic wake-up enable register, array offset: 0x680, array step: 0x4 */
       uint8_t RESERVED_29[24];
  __O  uint32_t STARTERSET[SYSCON_STARTERSET_COUNT]; /**< Set bits in STARTER, array offset: 0x6A0, array step: 0x4 */
       uint8_t RESERVED_30[24];
  __O  uint32_t STARTERCLR[SYSCON_STARTERCLR_COUNT]; /**< Clear bits in STARTER, array offset: 0x6C0, array step: 0x4 */
       uint8_t RESERVED_31[60];
  __IO uint32_t FUNCRETENTIONCTRL;                 /**< Functional retention control register, offset: 0x704 */
       uint8_t RESERVED_32[4];
  __IO uint32_t POWERDOWNSAFETY;                   /**< Override some powerdown control signals (for debug purposes), offset: 0x70C */
  __IO uint32_t MAINCLKSAFETY;                     /**< main clock is enable after MAINCLKSAFETY cycle, offset: 0x710 */
       uint8_t RESERVED_33[108];
  __IO uint32_t HARDWARESLEEP;                     /**< Hardware Sleep control, offset: 0x780 */
       uint8_t RESERVED_34[136];
  __I  uint32_t CPSTAT;                            /**< CPU Status, offset: 0x80C */
       uint8_t RESERVED_35[240];
  __IO uint32_t DICE_REG0;                         /**< Composite Device Identifier, offset: 0x900 */
  __IO uint32_t DICE_REG1;                         /**< Composite Device Identifier, offset: 0x904 */
  __IO uint32_t DICE_REG2;                         /**< Composite Device Identifier, offset: 0x908 */
  __IO uint32_t DICE_REG3;                         /**< Composite Device Identifier, offset: 0x90C */
  __IO uint32_t DICE_REG4;                         /**< Composite Device Identifier, offset: 0x910 */
  __IO uint32_t DICE_REG5;                         /**< Composite Device Identifier, offset: 0x914 */
  __IO uint32_t DICE_REG6;                         /**< Composite Device Identifier, offset: 0x918 */
  __IO uint32_t DICE_REG7;                         /**< Composite Device Identifier, offset: 0x91C */
  __IO uint32_t BOOT_SEED_REG0;                    /**< boot seed (256-bit random value), offset: 0x920 */
  __IO uint32_t BOOT_SEED_REG1;                    /**< boot seed (256-bit random value), offset: 0x924 */
  __IO uint32_t BOOT_SEED_REG2;                    /**< boot seed (256-bit random value), offset: 0x928 */
  __IO uint32_t BOOT_SEED_REG3;                    /**< boot seed (256-bit random value), offset: 0x92C */
  __IO uint32_t BOOT_SEED_REG4;                    /**< boot seed (256-bit random value), offset: 0x930 */
  __IO uint32_t BOOT_SEED_REG5;                    /**< boot seed (256-bit random value), offset: 0x934 */
  __IO uint32_t BOOT_SEED_REG6;                    /**< boot seed (256-bit random value), offset: 0x938 */
  __IO uint32_t BOOT_SEED_REG7;                    /**< boot seed (256-bit random value), offset: 0x93C */
  __IO uint32_t HMAC_REG0;                         /**< HMAC, offset: 0x940 */
  __IO uint32_t HMAC_REG1;                         /**< HMAC, offset: 0x944 */
  __IO uint32_t HMAC_REG2;                         /**< HMAC, offset: 0x948 */
  __IO uint32_t HMAC_REG3;                         /**< HMAC, offset: 0x94C */
  __IO uint32_t HMAC_REG4;                         /**< HMAC, offset: 0x950 */
  __IO uint32_t HMAC_REG5;                         /**< HMAC, offset: 0x954 */
  __IO uint32_t HMAC_REG6;                         /**< HMAC, offset: 0x958 */
  __IO uint32_t HMAC_REG7;                         /**< HMAC, offset: 0x95C */
  __IO uint32_t BOOT_LOCK;                         /**< Control write access to boot seed security registers., offset: 0x960 */
       uint8_t RESERVED_36[108];
  __I  uint32_t CSS_AS_CFG0;                       /**< CSS AS configuration, offset: 0x9D0 */
       uint8_t RESERVED_37[68];
  __IO uint32_t CLOCK_CTRL;                        /**< Various system clock controls : Clocks to Frequency Measures, offset: 0xA18 */
       uint8_t RESERVED_38[1000];
  __IO uint32_t AUTOCLKGATEOVERRIDE;               /**< Control automatic clock gating, offset: 0xE04 */
  __IO uint32_t GPIOPSYNC;                         /**< Enable bypass of the first stage of synchonization inside GPIO_INT module, offset: 0xE08 */
       uint8_t RESERVED_39[20];
  __IO uint32_t INVERTMAINCLK;                     /**< Invert Main clock, offset: 0xE20 */
       uint8_t RESERVED_40[356];
  __IO uint32_t HASHRESTHWKEY;                     /**< Controls whether the HASH AES hardware secret key is restricted to use by secure code, offset: 0xF88 */
       uint8_t RESERVED_41[20];
  __IO uint32_t DEBUG_LOCK_EN;                     /**< Write-once register to control write access to security registers., offset: 0xFA0 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex debug features control., offset: 0xFA4 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex debug features control. (duplicate), offset: 0xFA8 */
       uint8_t RESERVED_42[4];
  __O  uint32_t CODESECURITYPROTTEST;              /**< Security code to allow test (Design for Testability) access., offset: 0xFB0 */
  __IO uint32_t SWD_ACCESS_CPU0;                   /**< This register is used by ROM during DEBUG authentication mechanism to enable debug access port for CPU0., offset: 0xFB4 */
       uint8_t RESERVED_43[4];
  __O  uint32_t KEY_BLOCK;                         /**< block quiddikey/PUF all index., offset: 0xFBC */
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug authentication BEACON register, offset: 0xFC0 */
       uint8_t RESERVED_44[28];
  __IO uint32_t FLASHSIZECFG;                      /**< Flash size configuration, offset: 0xFE0 */
  __IO uint32_t CONFIGLOCKOUT;                     /**< Disable write access to FLASHSIZECFG, SRAMSIZECFG, CPUCFG., offset: 0xFE4 */
  __IO uint32_t RAMSIZECFG;                        /**< RAM size, offset: 0xFE8 */
  __IO uint32_t PERIPHENCFG;                       /**< Peripheral enable configuration, offset: 0xFEC */
       uint8_t RESERVED_45[8];
  __IO uint32_t DEVICE_ID0;                        /**< Device ID, offset: 0xFF8 */
  __I  uint32_t DIEID;                             /**< Chip revision ID and Number, offset: 0xFFC */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name MEMORYREMAP - Memory Remap control register */
/*! @{ */

#define SYSCON_MEMORYREMAP_MAP_MASK              (0x3U)
#define SYSCON_MEMORYREMAP_MAP_SHIFT             (0U)
/*! MAP - Select the location of the vector table :.
 *  0b00..Vector Table in ROM.
 *  0b01..Vector Table in RAM.
 *  0b10..Vector Table in Flash.
 *  0b11..Vector Table in Flash.
 */
#define SYSCON_MEMORYREMAP_MAP(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MEMORYREMAP_MAP_SHIFT)) & SYSCON_MEMORYREMAP_MAP_MASK)
/*! @} */

/*! @name AHBMATPRIO - AHB Matrix priority control register Priority values are 3 = highest, 0 = lowest */
/*! @{ */

#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK     (0x3U)
#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT    (0U)
/*! PRI_CPU0_CBUS - CPU0 C-AHB bus. */
#define SYSCON_AHBMATPRIO_PRI_CPU0_CBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU0_CBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_MASK     (0xCU)
#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_SHIFT    (2U)
/*! PRI_CPU0_SBUS - CPU0 S-AHB bus. */
#define SYSCON_AHBMATPRIO_PRI_CPU0_SBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CPU0_SBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_SDMA0_MASK         (0x30U)
#define SYSCON_AHBMATPRIO_PRI_SDMA0_SHIFT        (4U)
/*! PRI_SDMA0 - DMA0 controller priority. */
#define SYSCON_AHBMATPRIO_PRI_SDMA0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SDMA0_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SDMA0_MASK)

#define SYSCON_AHBMATPRIO_PRI_SDMA1_MASK         (0xC0U)
#define SYSCON_AHBMATPRIO_PRI_SDMA1_SHIFT        (6U)
/*! PRI_SDMA1 - DMA1 controller priority. */
#define SYSCON_AHBMATPRIO_PRI_SDMA1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_SDMA1_SHIFT)) & SYSCON_AHBMATPRIO_PRI_SDMA1_MASK)

#define SYSCON_AHBMATPRIO_PRI_EZH_B_D_MASK       (0x3000U)
#define SYSCON_AHBMATPRIO_PRI_EZH_B_D_SHIFT      (12U)
/*! PRI_EZH_B_D - EZH B data bus. */
#define SYSCON_AHBMATPRIO_PRI_EZH_B_D(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_EZH_B_D_SHIFT)) & SYSCON_AHBMATPRIO_PRI_EZH_B_D_MASK)

#define SYSCON_AHBMATPRIO_PRI_EZH_B_I_MASK       (0xC000U)
#define SYSCON_AHBMATPRIO_PRI_EZH_B_I_SHIFT      (14U)
/*! PRI_EZH_B_I - EZH B instruction bus. */
#define SYSCON_AHBMATPRIO_PRI_EZH_B_I(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_EZH_B_I_SHIFT)) & SYSCON_AHBMATPRIO_PRI_EZH_B_I_MASK)

#define SYSCON_AHBMATPRIO_PRI_HASH_AES_MASK      (0x30000U)
#define SYSCON_AHBMATPRIO_PRI_HASH_AES_SHIFT     (16U)
/*! PRI_HASH_AES - HASH_AES. */
#define SYSCON_AHBMATPRIO_PRI_HASH_AES(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_HASH_AES_SHIFT)) & SYSCON_AHBMATPRIO_PRI_HASH_AES_MASK)
/*! @} */

/*! @name BUFFERINGAHB2VPB0 - Buffering of write accesses on Synchronous System configuration APB interface */
/*! @{ */

#define SYSCON_BUFFERINGAHB2VPB0_SYSCON_MASK     (0x1U)
#define SYSCON_BUFFERINGAHB2VPB0_SYSCON_SHIFT    (0U)
/*! SYSCON - Enable buffering of write accesses on Synchronous System configuration APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_SYSCON(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_SYSCON_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_SYSCON_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_IOCON_MASK      (0x2U)
#define SYSCON_BUFFERINGAHB2VPB0_IOCON_SHIFT     (1U)
/*! IOCON - Enable buffering of write accesses on IO Configuration APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_IOCON(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_IOCON_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_IOCON_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_GPIOGLOBALINT0_MASK (0x4U)
#define SYSCON_BUFFERINGAHB2VPB0_GPIOGLOBALINT0_SHIFT (2U)
/*! GPIOGLOBALINT0 - Enable buffering of write accesses on GPIO Global Interrupt APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_GPIOGLOBALINT0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_GPIOGLOBALINT0_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_GPIOGLOBALINT0_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_GPIOINT_MASK    (0x10U)
#define SYSCON_BUFFERINGAHB2VPB0_GPIOINT_SHIFT   (4U)
/*! GPIOINT - Enable buffering of write accesses on GPIO Int APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_GPIOINT(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_GPIOINT_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_GPIOINT_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_SECGPIOINT_MASK (0x20U)
#define SYSCON_BUFFERINGAHB2VPB0_SECGPIOINT_SHIFT (5U)
/*! SECGPIOINT - Enable buffering of write accesses on secure GPIO Int APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_SECGPIOINT(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_SECGPIOINT_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_SECGPIOINT_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_INPUTMUX_MASK   (0x40U)
#define SYSCON_BUFFERINGAHB2VPB0_INPUTMUX_SHIFT  (6U)
/*! INPUTMUX - Enable buffering of write accesses on Peripheral Input Mux APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_INPUTMUX(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_INPUTMUX_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_INPUTMUX_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_CT32B0_MASK     (0x100U)
#define SYSCON_BUFFERINGAHB2VPB0_CT32B0_SHIFT    (8U)
/*! CT32B0 - Enable buffering of write accesses on Counter/Timer0 APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_CT32B0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_CT32B0_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_CT32B0_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_CT32B1_MASK     (0x200U)
#define SYSCON_BUFFERINGAHB2VPB0_CT32B1_SHIFT    (9U)
/*! CT32B1 - Enable buffering of write accesses on Counter/Timer1 APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_CT32B1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_CT32B1_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_CT32B1_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_WWDT_MASK       (0x1000U)
#define SYSCON_BUFFERINGAHB2VPB0_WWDT_SHIFT      (12U)
/*! WWDT - Enable buffering of write accesses on Watchdog Timer APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_WWDT(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_WWDT_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_WWDT_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_MRT_MASK        (0x2000U)
#define SYSCON_BUFFERINGAHB2VPB0_MRT_SHIFT       (13U)
/*! MRT - Enable buffering of write ac.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_MRT(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_MRT_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_MRT_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_UTICK_MASK      (0x4000U)
#define SYSCON_BUFFERINGAHB2VPB0_UTICK_SHIFT     (14U)
/*! UTICK - Enable buffering of write accesses on micro Tick APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_UTICK(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_UTICK_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_UTICK_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_ANACTRL_MASK    (0x80000U)
#define SYSCON_BUFFERINGAHB2VPB0_ANACTRL_SHIFT   (19U)
/*! ANACTRL - Enable buffering of write accesses on analog control APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_ANACTRL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_ANACTRL_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_ANACTRL_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_SCTIUP_MASK     (0x8000000U)
#define SYSCON_BUFFERINGAHB2VPB0_SCTIUP_SHIFT    (27U)
/*! SCTIUP - Enable buffering of write accesses on SCTIUP APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_SCTIUP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_SCTIUP_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_SCTIUP_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_EZH_MASK        (0x20000000U)
#define SYSCON_BUFFERINGAHB2VPB0_EZH_SHIFT       (29U)
/*! EZH - Enable buffering of write accesses on EZH APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_EZH(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_EZH_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_EZH_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_PROBSYNC_MASK   (0x40000000U)
#define SYSCON_BUFFERINGAHB2VPB0_PROBSYNC_SHIFT  (30U)
/*! PROBSYNC - Enable buffering of write accesses on prob IS (sync) APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_PROBSYNC(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_PROBSYNC_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_PROBSYNC_MASK)

#define SYSCON_BUFFERINGAHB2VPB0_PROBXVC_MASK    (0x80000000U)
#define SYSCON_BUFFERINGAHB2VPB0_PROBXVC_SHIFT   (31U)
/*! PROBXVC - Enable buffering of write accesses on prob IS (XVC) APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB0_PROBXVC(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB0_PROBXVC_SHIFT)) & SYSCON_BUFFERINGAHB2VPB0_PROBXVC_MASK)
/*! @} */

/*! @name BUFFERINGAHB2VPB1 - Buffering of write accesses on Synchronous System configuration APB interface */
/*! @{ */

#define SYSCON_BUFFERINGAHB2VPB1_PMC_MASK        (0x1U)
#define SYSCON_BUFFERINGAHB2VPB1_PMC_SHIFT       (0U)
/*! PMC - Enable buffering of write accesses on Power Management Controller APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_PMC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_PMC_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_PMC_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_SYSCTL_MASK     (0x8U)
#define SYSCON_BUFFERINGAHB2VPB1_SYSCTL_SHIFT    (3U)
/*! SYSCTL - Enable buffering of write accesses on system control APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_SYSCTL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_SYSCTL_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_SYSCTL_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_CT32B2_MASK     (0x100U)
#define SYSCON_BUFFERINGAHB2VPB1_CT32B2_SHIFT    (8U)
/*! CT32B2 - Enable buffering of write accesses on Counter/Timer2 APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_CT32B2(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_CT32B2_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_CT32B2_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_CT32B3_MASK     (0x200U)
#define SYSCON_BUFFERINGAHB2VPB1_CT32B3_SHIFT    (9U)
/*! CT32B3 - Enable buffering of write accesses on Counter/Timer3 APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_CT32B3(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_CT32B3_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_CT32B3_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_CT32B4_MASK     (0x400U)
#define SYSCON_BUFFERINGAHB2VPB1_CT32B4_SHIFT    (10U)
/*! CT32B4 - Enable buffering of write accesses on Counter/Timer4 APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_CT32B4(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_CT32B4_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_CT32B4_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_RTC_MASK        (0x1000U)
#define SYSCON_BUFFERINGAHB2VPB1_RTC_SHIFT       (12U)
/*! RTC - Enable buffering of write accesses on RTC APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_RTC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_RTC_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_RTC_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_OSEVENT_MASK    (0x2000U)
#define SYSCON_BUFFERINGAHB2VPB1_OSEVENT_SHIFT   (13U)
/*! OSEVENT - Enable buffering of write accesses on OS event timer APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_OSEVENT(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_OSEVENT_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_OSEVENT_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_FLASHCTRL_MASK  (0x100000U)
#define SYSCON_BUFFERINGAHB2VPB1_FLASHCTRL_SHIFT (20U)
/*! FLASHCTRL - Enable buffering of write accesses on Flash Controller APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_FLASHCTRL(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_FLASHCTRL_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_FLASHCTRL_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_PRINCE_MASK     (0x200000U)
#define SYSCON_BUFFERINGAHB2VPB1_PRINCE_SHIFT    (21U)
/*! PRINCE - Enable buffering of write accesses on Prince APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_PRINCE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_PRINCE_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_PRINCE_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_RNG_MASK        (0x4000000U)
#define SYSCON_BUFFERINGAHB2VPB1_RNG_SHIFT       (26U)
/*! RNG - Enable buffering of write accesses on Random Number Generator APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_RNG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_RNG_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_RNG_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_PUFF_MASK       (0x8000000U)
#define SYSCON_BUFFERINGAHB2VPB1_PUFF_SHIFT      (27U)
/*! PUFF - Enable buffering of write accesses on PUFF interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_PUFF(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_PUFF_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_PUFF_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_PLU_LUT_MASK    (0x20000000U)
#define SYSCON_BUFFERINGAHB2VPB1_PLU_LUT_SHIFT   (29U)
/*! PLU_LUT - Enable buffering of write accesses on PLU LUT interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_PLU_LUT(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_PLU_LUT_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_PLU_LUT_MASK)

#define SYSCON_BUFFERINGAHB2VPB1_CODEPATCH_MASK  (0x40000000U)
#define SYSCON_BUFFERINGAHB2VPB1_CODEPATCH_SHIFT (30U)
/*! CODEPATCH - Enable buffering of write accesses on Code Patch Unit APB interface:.
 *  0b0..Disable buffering.
 *  0b1..Enable buffering.
 */
#define SYSCON_BUFFERINGAHB2VPB1_CODEPATCH(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_BUFFERINGAHB2VPB1_CODEPATCH_SHIFT)) & SYSCON_BUFFERINGAHB2VPB1_CODEPATCH_MASK)
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
/*! SKEW - Initial value for the Systick timer. */
#define SYSCON_CPU0STCKCAL_SKEW(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0STCKCAL_SKEW_SHIFT)) & SYSCON_CPU0STCKCAL_SKEW_MASK)

#define SYSCON_CPU0STCKCAL_NOREF_MASK            (0x2000000U)
#define SYSCON_CPU0STCKCAL_NOREF_SHIFT           (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor: 0 = reference
 *    clock provided; 1 = no reference clock provided.
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
/*! SKEW - Indicates whether the TENMS value is exact: 0 = TENMS value is exact; 1 = TENMS value is inexact, or not given. */
#define SYSCON_CPU0NSTCKCAL_SKEW(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPU0NSTCKCAL_SKEW_SHIFT)) & SYSCON_CPU0NSTCKCAL_SKEW_MASK)

#define SYSCON_CPU0NSTCKCAL_NOREF_MASK           (0x2000000U)
#define SYSCON_CPU0NSTCKCAL_NOREF_SHIFT          (25U)
/*! NOREF - Initial value for the Systick timer. */
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

#define SYSCON_PRESETCTRL0_ROM_RST_MASK          (0x2U)
#define SYSCON_PRESETCTRL0_ROM_RST_SHIFT         (1U)
/*! ROM_RST - ROM reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_ROM_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_ROM_RST_SHIFT)) & SYSCON_PRESETCTRL0_ROM_RST_MASK)

#define SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_MASK   (0x8U)
#define SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_SHIFT  (3U)
/*! SRAM_CTRL1_RST - SRAM Controller 1 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_SRAM_CTRL1_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_SHIFT)) & SYSCON_PRESETCTRL0_SRAM_CTRL1_RST_MASK)

#define SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_MASK   (0x10U)
#define SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_SHIFT  (4U)
/*! SRAM_CTRL2_RST - SRAM Controller 2 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_SRAM_CTRL2_RST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_SHIFT)) & SYSCON_PRESETCTRL0_SRAM_CTRL2_RST_MASK)

#define SYSCON_PRESETCTRL0_FLASH_RST_MASK        (0x80U)
#define SYSCON_PRESETCTRL0_FLASH_RST_SHIFT       (7U)
/*! FLASH_RST - Flash controller reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_FLASH_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FLASH_RST_SHIFT)) & SYSCON_PRESETCTRL0_FLASH_RST_MASK)

#define SYSCON_PRESETCTRL0_FMC_RST_MASK          (0x100U)
#define SYSCON_PRESETCTRL0_FMC_RST_SHIFT         (8U)
/*! FMC_RST - FMC controller reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_FMC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_FMC_RST_SHIFT)) & SYSCON_PRESETCTRL0_FMC_RST_MASK)

#define SYSCON_PRESETCTRL0_MUX_RST_MASK          (0x800U)
#define SYSCON_PRESETCTRL0_MUX_RST_SHIFT         (11U)
/*! MUX_RST - Input Mux reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_MUX_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_MUX_RST_SHIFT)) & SYSCON_PRESETCTRL0_MUX_RST_MASK)

#define SYSCON_PRESETCTRL0_IOCON_RST_MASK        (0x2000U)
#define SYSCON_PRESETCTRL0_IOCON_RST_SHIFT       (13U)
/*! IOCON_RST - I/O controller reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_IOCON_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_IOCON_RST_SHIFT)) & SYSCON_PRESETCTRL0_IOCON_RST_MASK)

#define SYSCON_PRESETCTRL0_GPIO0_RST_MASK        (0x4000U)
#define SYSCON_PRESETCTRL0_GPIO0_RST_SHIFT       (14U)
/*! GPIO0_RST - GPIO0 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_GPIO0_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GPIO0_RST_SHIFT)) & SYSCON_PRESETCTRL0_GPIO0_RST_MASK)

#define SYSCON_PRESETCTRL0_PINT_RST_MASK         (0x40000U)
#define SYSCON_PRESETCTRL0_PINT_RST_SHIFT        (18U)
/*! PINT_RST - Pin interrupt (PINT) reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_PINT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_PINT_RST_SHIFT)) & SYSCON_PRESETCTRL0_PINT_RST_MASK)

#define SYSCON_PRESETCTRL0_GINT_RST_MASK         (0x80000U)
#define SYSCON_PRESETCTRL0_GINT_RST_SHIFT        (19U)
/*! GINT_RST - Group interrupt (GINT) reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_GINT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_GINT_RST_SHIFT)) & SYSCON_PRESETCTRL0_GINT_RST_MASK)

#define SYSCON_PRESETCTRL0_DMA0_RST_MASK         (0x100000U)
#define SYSCON_PRESETCTRL0_DMA0_RST_SHIFT        (20U)
/*! DMA0_RST - DMA0 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_DMA0_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_DMA0_RST_SHIFT)) & SYSCON_PRESETCTRL0_DMA0_RST_MASK)

#define SYSCON_PRESETCTRL0_CRCGEN_RST_MASK       (0x200000U)
#define SYSCON_PRESETCTRL0_CRCGEN_RST_SHIFT      (21U)
/*! CRCGEN_RST - CRCGEN reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_CRCGEN_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_CRCGEN_RST_SHIFT)) & SYSCON_PRESETCTRL0_CRCGEN_RST_MASK)

#define SYSCON_PRESETCTRL0_WWDT_RST_MASK         (0x400000U)
#define SYSCON_PRESETCTRL0_WWDT_RST_SHIFT        (22U)
/*! WWDT_RST - Watchdog Timer reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_WWDT_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_WWDT_RST_SHIFT)) & SYSCON_PRESETCTRL0_WWDT_RST_MASK)

#define SYSCON_PRESETCTRL0_RTC_RST_MASK          (0x800000U)
#define SYSCON_PRESETCTRL0_RTC_RST_SHIFT         (23U)
/*! RTC_RST - Real Time Clock (RTC) reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL0_RTC_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL0_RTC_RST_SHIFT)) & SYSCON_PRESETCTRL0_RTC_RST_MASK)
/*! @} */

/*! @name PRESETCTRL1 - Peripheral reset control 1 */
/*! @{ */

#define SYSCON_PRESETCTRL1_MRT_RST_MASK          (0x1U)
#define SYSCON_PRESETCTRL1_MRT_RST_SHIFT         (0U)
/*! MRT_RST - MRT reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_MRT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_MRT_RST_SHIFT)) & SYSCON_PRESETCTRL1_MRT_RST_MASK)

#define SYSCON_PRESETCTRL1_OSTIMER_RST_MASK      (0x2U)
#define SYSCON_PRESETCTRL1_OSTIMER_RST_SHIFT     (1U)
/*! OSTIMER_RST - OS Event Timer reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_OSTIMER_RST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_OSTIMER_RST_SHIFT)) & SYSCON_PRESETCTRL1_OSTIMER_RST_MASK)

#define SYSCON_PRESETCTRL1_SCT_RST_MASK          (0x4U)
#define SYSCON_PRESETCTRL1_SCT_RST_SHIFT         (2U)
/*! SCT_RST - SCT reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_SCT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_SCT_RST_SHIFT)) & SYSCON_PRESETCTRL1_SCT_RST_MASK)

#define SYSCON_PRESETCTRL1_UTICK_RST_MASK        (0x400U)
#define SYSCON_PRESETCTRL1_UTICK_RST_SHIFT       (10U)
/*! UTICK_RST - UTICK reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_UTICK_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_UTICK_RST_SHIFT)) & SYSCON_PRESETCTRL1_UTICK_RST_MASK)

#define SYSCON_PRESETCTRL1_FC0_RST_MASK          (0x800U)
#define SYSCON_PRESETCTRL1_FC0_RST_SHIFT         (11U)
/*! FC0_RST - FC0 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_FC0_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC0_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC0_RST_MASK)

#define SYSCON_PRESETCTRL1_FC1_RST_MASK          (0x1000U)
#define SYSCON_PRESETCTRL1_FC1_RST_SHIFT         (12U)
/*! FC1_RST - FC1 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_FC1_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC1_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC1_RST_MASK)

#define SYSCON_PRESETCTRL1_FC2_RST_MASK          (0x2000U)
#define SYSCON_PRESETCTRL1_FC2_RST_SHIFT         (13U)
/*! FC2_RST - FC2 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_FC2_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_FC2_RST_SHIFT)) & SYSCON_PRESETCTRL1_FC2_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER2_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL1_TIMER2_RST_SHIFT      (22U)
/*! TIMER2_RST - Timer 2 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_TIMER2_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER2_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER2_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER0_RST_MASK       (0x4000000U)
#define SYSCON_PRESETCTRL1_TIMER0_RST_SHIFT      (26U)
/*! TIMER0_RST - Timer 0 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_TIMER0_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER0_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER0_RST_MASK)

#define SYSCON_PRESETCTRL1_TIMER1_RST_MASK       (0x8000000U)
#define SYSCON_PRESETCTRL1_TIMER1_RST_SHIFT      (27U)
/*! TIMER1_RST - Timer 1 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_TIMER1_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_TIMER1_RST_SHIFT)) & SYSCON_PRESETCTRL1_TIMER1_RST_MASK)

#define SYSCON_PRESETCTRL1_EZHA_RST_MASK         (0x40000000U)
#define SYSCON_PRESETCTRL1_EZHA_RST_SHIFT        (30U)
/*! EZHA_RST - EZH a reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_EZHA_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_EZHA_RST_SHIFT)) & SYSCON_PRESETCTRL1_EZHA_RST_MASK)

#define SYSCON_PRESETCTRL1_EZHB_RST_MASK         (0x80000000U)
#define SYSCON_PRESETCTRL1_EZHB_RST_SHIFT        (31U)
/*! EZHB_RST - EZH b reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL1_EZHB_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL1_EZHB_RST_SHIFT)) & SYSCON_PRESETCTRL1_EZHB_RST_MASK)
/*! @} */

/*! @name PRESETCTRL2 - Peripheral reset control 2 */
/*! @{ */

#define SYSCON_PRESETCTRL2_DMA1_RST_MASK         (0x2U)
#define SYSCON_PRESETCTRL2_DMA1_RST_SHIFT        (1U)
/*! DMA1_RST - DMA1 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_DMA1_RST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_DMA1_RST_SHIFT)) & SYSCON_PRESETCTRL2_DMA1_RST_MASK)

#define SYSCON_PRESETCTRL2_BLE_RAM_MASK          (0x40U)
#define SYSCON_PRESETCTRL2_BLE_RAM_SHIFT         (6U)
/*! BLE_RAM - BLE packet RAM reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_BLE_RAM(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_BLE_RAM_SHIFT)) & SYSCON_PRESETCTRL2_BLE_RAM_MASK)

#define SYSCON_PRESETCTRL2_BLE_RADIO_RST_MASK    (0x80U)
#define SYSCON_PRESETCTRL2_BLE_RADIO_RST_SHIFT   (7U)
/*! BLE_RADIO_RST - BLE radio reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_BLE_RADIO_RST(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_BLE_RADIO_RST_SHIFT)) & SYSCON_PRESETCTRL2_BLE_RADIO_RST_MASK)

#define SYSCON_PRESETCTRL2_FREQME_RST_MASK       (0x100U)
#define SYSCON_PRESETCTRL2_FREQME_RST_SHIFT      (8U)
/*! FREQME_RST - Frequency meter reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_FREQME_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_FREQME_RST_SHIFT)) & SYSCON_PRESETCTRL2_FREQME_RST_MASK)

#define SYSCON_PRESETCTRL2_CWT_RST_MASK          (0x800U)
#define SYSCON_PRESETCTRL2_CWT_RST_SHIFT         (11U)
/*! CWT_RST - Code Watchdog reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_CWT_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_CWT_RST_SHIFT)) & SYSCON_PRESETCTRL2_CWT_RST_MASK)

#define SYSCON_PRESETCTRL2_RNG_RST_MASK          (0x2000U)
#define SYSCON_PRESETCTRL2_RNG_RST_SHIFT         (13U)
/*! RNG_RST - RNG reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_RNG_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_RNG_RST_SHIFT)) & SYSCON_PRESETCTRL2_RNG_RST_MASK)

#define SYSCON_PRESETCTRL2_SYSCTL_RST_MASK       (0x8000U)
#define SYSCON_PRESETCTRL2_SYSCTL_RST_SHIFT      (15U)
/*! SYSCTL_RST - SYSCTL Block reset.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_SYSCTL_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_SYSCTL_RST_SHIFT)) & SYSCON_PRESETCTRL2_SYSCTL_RST_MASK)

#define SYSCON_PRESETCTRL2_HASH_AES_RST_MASK     (0x40000U)
#define SYSCON_PRESETCTRL2_HASH_AES_RST_SHIFT    (18U)
/*! HASH_AES_RST - HASH_AES reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_HASH_AES_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_HASH_AES_RST_SHIFT)) & SYSCON_PRESETCTRL2_HASH_AES_RST_MASK)

#define SYSCON_PRESETCTRL2_PLULUT_RST_MASK       (0x100000U)
#define SYSCON_PRESETCTRL2_PLULUT_RST_SHIFT      (20U)
/*! PLULUT_RST - PLU LUT reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_PLULUT_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PLULUT_RST_SHIFT)) & SYSCON_PRESETCTRL2_PLULUT_RST_MASK)

#define SYSCON_PRESETCTRL2_TIMER3_RST_MASK       (0x200000U)
#define SYSCON_PRESETCTRL2_TIMER3_RST_SHIFT      (21U)
/*! TIMER3_RST - Timer 3 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_TIMER3_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TIMER3_RST_SHIFT)) & SYSCON_PRESETCTRL2_TIMER3_RST_MASK)

#define SYSCON_PRESETCTRL2_TIMER4_RST_MASK       (0x400000U)
#define SYSCON_PRESETCTRL2_TIMER4_RST_SHIFT      (22U)
/*! TIMER4_RST - Timer 4 reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_TIMER4_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_TIMER4_RST_SHIFT)) & SYSCON_PRESETCTRL2_TIMER4_RST_MASK)

#define SYSCON_PRESETCTRL2_PUF_RST_MASK          (0x800000U)
#define SYSCON_PRESETCTRL2_PUF_RST_SHIFT         (23U)
/*! PUF_RST - PUF reset control reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_PUF_RST(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_PUF_RST_SHIFT)) & SYSCON_PRESETCTRL2_PUF_RST_MASK)

#define SYSCON_PRESETCTRL2_CASPER_RST_MASK       (0x1000000U)
#define SYSCON_PRESETCTRL2_CASPER_RST_SHIFT      (24U)
/*! CASPER_RST - Casper reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_CASPER_RST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_CASPER_RST_SHIFT)) & SYSCON_PRESETCTRL2_CASPER_RST_MASK)

#define SYSCON_PRESETCTRL2_ANALOG_CTRL_RST_MASK  (0x8000000U)
#define SYSCON_PRESETCTRL2_ANALOG_CTRL_RST_SHIFT (27U)
/*! ANALOG_CTRL_RST - analog control reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_ANALOG_CTRL_RST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_ANALOG_CTRL_RST_SHIFT)) & SYSCON_PRESETCTRL2_ANALOG_CTRL_RST_MASK)

#define SYSCON_PRESETCTRL2_SPIFI_RST_MASK        (0x10000000U)
#define SYSCON_PRESETCTRL2_SPIFI_RST_SHIFT       (28U)
/*! SPIFI_RST - QuadSPI Flash Interface reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_SPIFI_RST(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_SPIFI_RST_SHIFT)) & SYSCON_PRESETCTRL2_SPIFI_RST_MASK)

#define SYSCON_PRESETCTRL2_GPIO_SEC_RST_MASK     (0x20000000U)
#define SYSCON_PRESETCTRL2_GPIO_SEC_RST_SHIFT    (29U)
/*! GPIO_SEC_RST - GPIO secure reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_GPIO_SEC_RST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_GPIO_SEC_RST_SHIFT)) & SYSCON_PRESETCTRL2_GPIO_SEC_RST_MASK)

#define SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_MASK (0x40000000U)
#define SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_SHIFT (30U)
/*! GPIO_SEC_INT_RST - GPIO secure int reset control.
 *  0b0..Bloc is not reset.
 *  0b1..Bloc is reset.
 */
#define SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_SHIFT)) & SYSCON_PRESETCTRL2_GPIO_SEC_INT_RST_MASK)
/*! @} */

/*! @name PRESETCTRLX - Peripheral reset control register */
/*! @{ */

#define SYSCON_PRESETCTRLX_DATA_MASK             (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLX_DATA_SHIFT            (0U)
/*! DATA - Data array value */
#define SYSCON_PRESETCTRLX_DATA(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLX_DATA_SHIFT)) & SYSCON_PRESETCTRLX_DATA_MASK)
/*! @} */

/* The count of SYSCON_PRESETCTRLX */
#define SYSCON_PRESETCTRLX_COUNT                 (3U)

/*! @name PRESETCTRLSET - Peripheral reset control set register */
/*! @{ */

#define SYSCON_PRESETCTRLSET_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLSET_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_PRESETCTRLSET_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLSET_DATA_SHIFT)) & SYSCON_PRESETCTRLSET_DATA_MASK)
/*! @} */

/*! @name PRESETCTRLCLR - Peripheral reset control clear register */
/*! @{ */

#define SYSCON_PRESETCTRLCLR_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_PRESETCTRLCLR_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_PRESETCTRLCLR_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PRESETCTRLCLR_DATA_SHIFT)) & SYSCON_PRESETCTRLCLR_DATA_MASK)
/*! @} */

/*! @name SWR_RESET - generate a software_reset */
/*! @{ */

#define SYSCON_SWR_RESET_SWR_RESET_MASK          (0xFFFFFFFFU)
#define SYSCON_SWR_RESET_SWR_RESET_SHIFT         (0U)
/*! SWR_RESET - Write 0x5A00_0001 to generate a software_reset.
 *  0b00000000000000000000000000000000..Bloc is not reset.
 *  0b01011010000000000000000000000001..Generate a software reset.
 */
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

#define SYSCON_AHBCLKCTRL1_TIMER2_MASK           (0x400000U)
#define SYSCON_AHBCLKCTRL1_TIMER2_SHIFT          (22U)
/*! TIMER2 - Enables the clock for the Timer 2.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_TIMER2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_TIMER2_SHIFT)) & SYSCON_AHBCLKCTRL1_TIMER2_MASK)

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

#define SYSCON_AHBCLKCTRL1_EZHA_MASK             (0x40000000U)
#define SYSCON_AHBCLKCTRL1_EZHA_SHIFT            (30U)
/*! EZHA - Enables the clock for the EZH a.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_EZHA(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_EZHA_SHIFT)) & SYSCON_AHBCLKCTRL1_EZHA_MASK)

#define SYSCON_AHBCLKCTRL1_EZHB_MASK             (0x80000000U)
#define SYSCON_AHBCLKCTRL1_EZHB_SHIFT            (31U)
/*! EZHB - Enables the clock for the EZH b.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL1_EZHB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL1_EZHB_SHIFT)) & SYSCON_AHBCLKCTRL1_EZHB_MASK)
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

#define SYSCON_AHBCLKCTRL2_BLE_RAM_MASK          (0x40U)
#define SYSCON_AHBCLKCTRL2_BLE_RAM_SHIFT         (6U)
/*! BLE_RAM - Enables the clock for the BLE packet RAM Controller.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_BLE_RAM(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_BLE_RAM_SHIFT)) & SYSCON_AHBCLKCTRL2_BLE_RAM_MASK)

#define SYSCON_AHBCLKCTRL2_BLE_RADIO_MASK        (0x80U)
#define SYSCON_AHBCLKCTRL2_BLE_RADIO_SHIFT       (7U)
/*! BLE_RADIO - Enables the clock for the BLE radio.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_BLE_RADIO(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_BLE_RADIO_SHIFT)) & SYSCON_AHBCLKCTRL2_BLE_RADIO_MASK)

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

#define SYSCON_AHBCLKCTRL2_SYSCTL_MASK           (0x8000U)
#define SYSCON_AHBCLKCTRL2_SYSCTL_SHIFT          (15U)
/*! SYSCTL - SYSCTL block clock.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_SYSCTL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SYSCTL_SHIFT)) & SYSCON_AHBCLKCTRL2_SYSCTL_MASK)

#define SYSCON_AHBCLKCTRL2_HASH_AES_MASK         (0x40000U)
#define SYSCON_AHBCLKCTRL2_HASH_AES_SHIFT        (18U)
/*! HASH_AES - Enables the clock for the HASH_AES.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_HASH_AES(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_HASH_AES_SHIFT)) & SYSCON_AHBCLKCTRL2_HASH_AES_MASK)

#define SYSCON_AHBCLKCTRL2_PLULUT_MASK           (0x100000U)
#define SYSCON_AHBCLKCTRL2_PLULUT_SHIFT          (20U)
/*! PLULUT - Enables the clock for the PLU LUT.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_PLULUT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_PLULUT_SHIFT)) & SYSCON_AHBCLKCTRL2_PLULUT_MASK)

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

#define SYSCON_AHBCLKCTRL2_CASPER_MASK           (0x1000000U)
#define SYSCON_AHBCLKCTRL2_CASPER_SHIFT          (24U)
/*! CASPER - Enables the clock for the Casper.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_CASPER(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_CASPER_SHIFT)) & SYSCON_AHBCLKCTRL2_CASPER_MASK)

#define SYSCON_AHBCLKCTRL2_ANALOG_CTRL_MASK      (0x8000000U)
#define SYSCON_AHBCLKCTRL2_ANALOG_CTRL_SHIFT     (27U)
/*! ANALOG_CTRL - Enables the clock for the analog control.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_ANALOG_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_ANALOG_CTRL_SHIFT)) & SYSCON_AHBCLKCTRL2_ANALOG_CTRL_MASK)

#define SYSCON_AHBCLKCTRL2_SPIFI_MASK            (0x10000000U)
#define SYSCON_AHBCLKCTRL2_SPIFI_SHIFT           (28U)
/*! SPIFI - Enables the clock for the QuadSPI Flash Interface.
 *  0b0..Disable Clock.
 *  0b1..Enable Clock.
 */
#define SYSCON_AHBCLKCTRL2_SPIFI(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRL2_SPIFI_SHIFT)) & SYSCON_AHBCLKCTRL2_SPIFI_MASK)

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

/*! @name AHBCLKCTRLX - Peripheral reset control register */
/*! @{ */

#define SYSCON_AHBCLKCTRLX_DATA_MASK             (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLX_DATA_SHIFT            (0U)
/*! DATA - Data array value */
#define SYSCON_AHBCLKCTRLX_DATA(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLX_DATA_SHIFT)) & SYSCON_AHBCLKCTRLX_DATA_MASK)
/*! @} */

/* The count of SYSCON_AHBCLKCTRLX */
#define SYSCON_AHBCLKCTRLX_COUNT                 (3U)

/*! @name AHBCLKCTRLSET - Peripheral reset control register */
/*! @{ */

#define SYSCON_AHBCLKCTRLSET_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_AHBCLKCTRLSET_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_AHBCLKCTRLSET_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKCTRLSET_DATA_SHIFT)) & SYSCON_AHBCLKCTRLSET_DATA_MASK)
/*! @} */

/*! @name AHBCLKCTRLCLR - Peripheral reset control register */
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

/*! @name SYSTICKCLKSELX - System Tick Timer source select register */
/*! @{ */

#define SYSCON_SYSTICKCLKSELX_DATA_MASK          (0xFFFFFFFFU)
#define SYSCON_SYSTICKCLKSELX_DATA_SHIFT         (0U)
/*! DATA - Data array value */
#define SYSCON_SYSTICKCLKSELX_DATA(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKSELX_DATA_SHIFT)) & SYSCON_SYSTICKCLKSELX_DATA_MASK)
/*! @} */

/* The count of SYSCON_SYSTICKCLKSELX */
#define SYSCON_SYSTICKCLKSELX_COUNT              (1U)

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

/*! @name CTIMERCLKSEL0 - CTimer 0 clock source select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL0_SEL_MASK            (0x7U)
#define SYSCON_CTIMERCLKSEL0_SEL_SHIFT           (0U)
/*! SEL - CTimer 0 clock source select.
 *  0b000..Main clock.
 *  0b001..No clock
 *  0b010..No clock.
 *  0b011..FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_CTIMERCLKSEL0_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL0_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL0_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSEL1 - CTimer 1 clock source select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL1_SEL_MASK            (0x7U)
#define SYSCON_CTIMERCLKSEL1_SEL_SHIFT           (0U)
/*! SEL - CTimer 1 clock source select.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..No clock.
 *  0b011..FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_CTIMERCLKSEL1_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL1_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL1_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSEL2 - CTimer 2 clock source select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL2_SEL_MASK            (0x7U)
#define SYSCON_CTIMERCLKSEL2_SEL_SHIFT           (0U)
/*! SEL - CTimer 2 clock source select.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..No clock.
 *  0b011..FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_CTIMERCLKSEL2_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL2_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL2_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSEL3 - CTimer 3 clock source select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL3_SEL_MASK            (0x7U)
#define SYSCON_CTIMERCLKSEL3_SEL_SHIFT           (0U)
/*! SEL - CTimer 3 clock source select.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..No clock.
 *  0b011..FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_CTIMERCLKSEL3_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL3_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL3_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSEL4 - CTimer 4 clock source select */
/*! @{ */

#define SYSCON_CTIMERCLKSEL4_SEL_MASK            (0x7U)
#define SYSCON_CTIMERCLKSEL4_SEL_SHIFT           (0U)
/*! SEL - CTimer 4 clock source select.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..No clock.
 *  0b011..FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_CTIMERCLKSEL4_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSEL4_SEL_SHIFT)) & SYSCON_CTIMERCLKSEL4_SEL_MASK)
/*! @} */

/*! @name CTIMERCLKSELX - CTIMER clock source select register */
/*! @{ */

#define SYSCON_CTIMERCLKSELX_DATA_MASK           (0xFFFFFFFFU)
#define SYSCON_CTIMERCLKSELX_DATA_SHIFT          (0U)
/*! DATA - Data array value */
#define SYSCON_CTIMERCLKSELX_DATA(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERCLKSELX_DATA_SHIFT)) & SYSCON_CTIMERCLKSELX_DATA_MASK)
/*! @} */

/* The count of SYSCON_CTIMERCLKSELX */
#define SYSCON_CTIMERCLKSELX_COUNT               (5U)

/*! @name MAINCLKSELA - Main clock A source select */
/*! @{ */

#define SYSCON_MAINCLKSELA_SEL_MASK              (0x7U)
#define SYSCON_MAINCLKSELA_SEL_SHIFT             (0U)
/*! SEL - Main clock A source select.
 *  0b000..FRO 12 MHz clock.
 *  0b001..CLKIN clock.
 *  0b010..FRO 1MHz clock.
 *  0b011..FRO 32 MHz clock.
 *  0b100..FRO 12 MHz clock.
 *  0b101..CLKIN clock.
 *  0b110..FRO 1MHz clock.
 *  0b111..FRO 32 MHz clock.
 */
#define SYSCON_MAINCLKSELA_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSELA_SEL_SHIFT)) & SYSCON_MAINCLKSELA_SEL_MASK)
/*! @} */

/*! @name MAINCLKSELB - Main clock source select */
/*! @{ */

#define SYSCON_MAINCLKSELB_SEL_MASK              (0x7U)
#define SYSCON_MAINCLKSELB_SEL_SHIFT             (0U)
/*! SEL - Main clock source select.
 *  0b000..Main Clock A.
 *  0b001..FRO 24MHz
 *  0b010..Oscillator 32 kHz clock.
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
 *  0b0001..No clock.
 *  0b0010..CLKIN clock.
 *  0b0011..FRO 32MHz
 *  0b0100..FRO 1MHz
 *  0b0101..FRO 24MHz
 *  0b0110..Oscillator 32kHz clock.
 *  0b0111..No clock.
 *  0b1000..No clock.
 *  0b1001..No clock.
 *  0b1010..No clock.
 *  0b1011..No clock.
 *  0b1100..No clock.
 *  0b1101..No clock.
 *  0b1110..No clock.
 *  0b1111..No clock.
 */
#define SYSCON_CLKOUTSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTSEL_SEL_SHIFT)) & SYSCON_CLKOUTSEL_SEL_MASK)
/*! @} */

/*! @name FCCLKSEL0 - Flexcomm Interface 0 clock source select for Fractional Rate Divider */
/*! @{ */

#define SYSCON_FCCLKSEL0_SEL_MASK                (0x7U)
#define SYSCON_FCCLKSEL0_SEL_SHIFT               (0U)
/*! SEL - Flexcomm Interface 0 clock source select for Fractional Rate Divider.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..FRO 12 MHz clock.
 *  0b011..Divided FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32 kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_FCCLKSEL0_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FCCLKSEL0_SEL_SHIFT)) & SYSCON_FCCLKSEL0_SEL_MASK)
/*! @} */

/*! @name FCCLKSEL1 - Flexcomm Interface 1 clock source select for Fractional Rate Divider */
/*! @{ */

#define SYSCON_FCCLKSEL1_SEL_MASK                (0x7U)
#define SYSCON_FCCLKSEL1_SEL_SHIFT               (0U)
/*! SEL - Flexcomm Interface 1 clock source select for Fractional Rate Divider.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..FRO 12MHz clock.
 *  0b011..Divided FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32 kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_FCCLKSEL1_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FCCLKSEL1_SEL_SHIFT)) & SYSCON_FCCLKSEL1_SEL_MASK)
/*! @} */

/*! @name FCCLKSEL2 - Flexcomm Interface 2 clock source select for Fractional Rate Divider */
/*! @{ */

#define SYSCON_FCCLKSEL2_SEL_MASK                (0x7U)
#define SYSCON_FCCLKSEL2_SEL_SHIFT               (0U)
/*! SEL - Flexcomm Interface 2 clock source select for Fractional Rate Divider.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..FRO 12MHz clock.
 *  0b011..Divided FRO 32MHz clock.
 *  0b100..FRO 1MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..Oscillator 32 kHz clock.
 *  0b111..No clock.
 */
#define SYSCON_FCCLKSEL2_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FCCLKSEL2_SEL_SHIFT)) & SYSCON_FCCLKSEL2_SEL_MASK)
/*! @} */

/*! @name FCCLKSELX - Flexcomm clock source select register for Fractional Rate Divider */
/*! @{ */

#define SYSCON_FCCLKSELX_DATA_MASK               (0xFFFFFFFFU)
#define SYSCON_FCCLKSELX_DATA_SHIFT              (0U)
/*! DATA - Data array value */
#define SYSCON_FCCLKSELX_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FCCLKSELX_DATA_SHIFT)) & SYSCON_FCCLKSELX_DATA_MASK)
/*! @} */

/* The count of SYSCON_FCCLKSELX */
#define SYSCON_FCCLKSELX_COUNT                   (8U)

/*! @name SPIFICLKSEL - QuadSPI Flash Interface clock source select */
/*! @{ */

#define SYSCON_SPIFICLKSEL_SEL_MASK              (0x7U)
#define SYSCON_SPIFICLKSEL_SEL_SHIFT             (0U)
/*! SEL - QuadSPI Flash Interface clock source select.
 *  0b000..Main clock
 *  0b001..FRO 64MHz clock
 *  0b010..FRO 32MHz clock
 *  0b011..Divided FRO 32MHz clock
 *  0b100..FRO 48MHz clock
 *  0b101..FRO 48MHz clock
 *  0b110..FRO 48MHz clock
 *  0b111..FRO 48MHz clock
 */
#define SYSCON_SPIFICLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKSEL_SEL_SHIFT)) & SYSCON_SPIFICLKSEL_SEL_MASK)
/*! @} */

/*! @name SCTCLKSEL - SCTimer/PWM clock source select */
/*! @{ */

#define SYSCON_SCTCLKSEL_SEL_MASK                (0x7U)
#define SYSCON_SCTCLKSEL_SEL_SHIFT               (0U)
/*! SEL - SCTimer/PWM clock source select.
 *  0b000..Main clock.
 *  0b001..No clock.
 *  0b010..CLKIN clock.
 *  0b011..FRO 32MHz clock.
 *  0b100..FRO 24MHz clock.
 *  0b101..FRO 24MHz clock.
 *  0b110..FRO 24MHz clock.
 *  0b111..FRO 24MHz clock.
 */
#define SYSCON_SCTCLKSEL_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKSEL_SEL_SHIFT)) & SYSCON_SCTCLKSEL_SEL_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV0 - System Tick Timer divider for CPU0 */
/*! @{ */

#define SYSCON_SYSTICKCLKDIV0_DIV_MASK           (0xFFU)
#define SYSCON_SYSTICKCLKDIV0_DIV_SHIFT          (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
#define SYSCON_SYSTICKCLKDIV0_DIV(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV0_DIV_SHIFT)) & SYSCON_SYSTICKCLKDIV0_DIV_MASK)

#define SYSCON_SYSTICKCLKDIV0_RESET_MASK         (0x20000000U)
#define SYSCON_SYSTICKCLKDIV0_RESET_SHIFT        (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_SYSTICKCLKDIV0_RESET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV0_RESET_SHIFT)) & SYSCON_SYSTICKCLKDIV0_RESET_MASK)

#define SYSCON_SYSTICKCLKDIV0_HALT_MASK          (0x40000000U)
#define SYSCON_SYSTICKCLKDIV0_HALT_SHIFT         (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_SYSTICKCLKDIV0_HALT(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV0_HALT_SHIFT)) & SYSCON_SYSTICKCLKDIV0_HALT_MASK)

#define SYSCON_SYSTICKCLKDIV0_REQFLAG_MASK       (0x80000000U)
#define SYSCON_SYSTICKCLKDIV0_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_SYSTICKCLKDIV0_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSTICKCLKDIV0_REQFLAG_SHIFT)) & SYSCON_SYSTICKCLKDIV0_REQFLAG_MASK)
/*! @} */

/*! @name TRACECLKDIV - TRACE clock divider */
/*! @{ */

#define SYSCON_TRACECLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_TRACECLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
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

#define SYSCON_TRACECLKDIV_REQFLAG_MASK          (0x80000000U)
#define SYSCON_TRACECLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_TRACECLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_TRACECLKDIV_REQFLAG_SHIFT)) & SYSCON_TRACECLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name FLEXFRG0CTRL - Fractional rate divider for flexcomm 0 */
/*! @{ */

#define SYSCON_FLEXFRG0CTRL_DIV_MASK             (0xFFU)
#define SYSCON_FLEXFRG0CTRL_DIV_SHIFT            (0U)
/*! DIV - Denominator of the fractional rate divider. */
#define SYSCON_FLEXFRG0CTRL_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRG0CTRL_DIV_SHIFT)) & SYSCON_FLEXFRG0CTRL_DIV_MASK)

#define SYSCON_FLEXFRG0CTRL_MULT_MASK            (0xFF00U)
#define SYSCON_FLEXFRG0CTRL_MULT_SHIFT           (8U)
/*! MULT - Numerator of the fractional rate divider. */
#define SYSCON_FLEXFRG0CTRL_MULT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRG0CTRL_MULT_SHIFT)) & SYSCON_FLEXFRG0CTRL_MULT_MASK)
/*! @} */

/*! @name FLEXFRG1CTRL - Fractional rate divider for flexcomm 1 */
/*! @{ */

#define SYSCON_FLEXFRG1CTRL_DIV_MASK             (0xFFU)
#define SYSCON_FLEXFRG1CTRL_DIV_SHIFT            (0U)
/*! DIV - Denominator of the fractional rate divider. */
#define SYSCON_FLEXFRG1CTRL_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRG1CTRL_DIV_SHIFT)) & SYSCON_FLEXFRG1CTRL_DIV_MASK)

#define SYSCON_FLEXFRG1CTRL_MULT_MASK            (0xFF00U)
#define SYSCON_FLEXFRG1CTRL_MULT_SHIFT           (8U)
/*! MULT - Numerator of the fractional rate divider. */
#define SYSCON_FLEXFRG1CTRL_MULT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRG1CTRL_MULT_SHIFT)) & SYSCON_FLEXFRG1CTRL_MULT_MASK)
/*! @} */

/*! @name FLEXFRG2CTRL - Fractional rate divider for flexcomm 2 */
/*! @{ */

#define SYSCON_FLEXFRG2CTRL_DIV_MASK             (0xFFU)
#define SYSCON_FLEXFRG2CTRL_DIV_SHIFT            (0U)
/*! DIV - Denominator of the fractional rate divider. */
#define SYSCON_FLEXFRG2CTRL_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRG2CTRL_DIV_SHIFT)) & SYSCON_FLEXFRG2CTRL_DIV_MASK)

#define SYSCON_FLEXFRG2CTRL_MULT_MASK            (0xFF00U)
#define SYSCON_FLEXFRG2CTRL_MULT_SHIFT           (8U)
/*! MULT - Numerator of the fractional rate divider. */
#define SYSCON_FLEXFRG2CTRL_MULT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRG2CTRL_MULT_SHIFT)) & SYSCON_FLEXFRG2CTRL_MULT_MASK)
/*! @} */

/*! @name FLEXFRGXCTRL - Peripheral reset control register */
/*! @{ */

#define SYSCON_FLEXFRGXCTRL_DATA_MASK            (0xFFFFFFFFU)
#define SYSCON_FLEXFRGXCTRL_DATA_SHIFT           (0U)
/*! DATA - Data array value */
#define SYSCON_FLEXFRGXCTRL_DATA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_FLEXFRGXCTRL_DATA_SHIFT)) & SYSCON_FLEXFRGXCTRL_DATA_MASK)
/*! @} */

/* The count of SYSCON_FLEXFRGXCTRL */
#define SYSCON_FLEXFRGXCTRL_COUNT                (8U)

/*! @name AHBCLKDIV - System clock divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)

#define SYSCON_AHBCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_AHBCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_AHBCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_REQFLAG_SHIFT)) & SYSCON_AHBCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLKOUTDIV - CLKOUT clock divider */
/*! @{ */

#define SYSCON_CLKOUTDIV_DIV_MASK                (0xFFU)
#define SYSCON_CLKOUTDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
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

#define SYSCON_CLKOUTDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_CLKOUTDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_CLKOUTDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKOUTDIV_REQFLAG_SHIFT)) & SYSCON_CLKOUTDIV_REQFLAG_MASK)
/*! @} */

/*! @name FROHFDIV - FRO_HF (32MHz) clock divider */
/*! @{ */

#define SYSCON_FROHFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROHFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
#define SYSCON_FROHFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_DIV_SHIFT)) & SYSCON_FROHFDIV_DIV_MASK)

#define SYSCON_FROHFDIV_REQFLAG_MASK             (0x80000000U)
#define SYSCON_FROHFDIV_REQFLAG_SHIFT            (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_FROHFDIV_REQFLAG(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_REQFLAG_SHIFT)) & SYSCON_FROHFDIV_REQFLAG_MASK)
/*! @} */

/*! @name WDTCLKDIV - WDT clock divider */
/*! @{ */

#define SYSCON_WDTCLKDIV_DIV_MASK                (0x3FU)
#define SYSCON_WDTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
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

#define SYSCON_WDTCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_WDTCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_WDTCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_WDTCLKDIV_REQFLAG_SHIFT)) & SYSCON_WDTCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SCTCLKDIV - SCT/PWM clock divider */
/*! @{ */

#define SYSCON_SCTCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_SCTCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
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
 *  0b1..Divider clock is stoped.
 */
#define SYSCON_SCTCLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_HALT_SHIFT)) & SYSCON_SCTCLKDIV_HALT_MASK)

#define SYSCON_SCTCLKDIV_REQFLAG_MASK            (0x80000000U)
#define SYSCON_SCTCLKDIV_REQFLAG_SHIFT           (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_SCTCLKDIV_REQFLAG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SCTCLKDIV_REQFLAG_SHIFT)) & SYSCON_SCTCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SPIFICLKDIV - QuadSPI Flash Interface Clock divider */
/*! @{ */

#define SYSCON_SPIFICLKDIV_DIV_MASK              (0xFFU)
#define SYSCON_SPIFICLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock divider value (0 means divide by 1). */
#define SYSCON_SPIFICLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_DIV_SHIFT)) & SYSCON_SPIFICLKDIV_DIV_MASK)

#define SYSCON_SPIFICLKDIV_RESET_MASK            (0x20000000U)
#define SYSCON_SPIFICLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets the divider counter.
 *  0b0..Divider is not reset.
 *  0b1..Divider is reset.
 */
#define SYSCON_SPIFICLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_RESET_SHIFT)) & SYSCON_SPIFICLKDIV_RESET_MASK)

#define SYSCON_SPIFICLKDIV_HALT_MASK             (0x40000000U)
#define SYSCON_SPIFICLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halts the divider counter.
 *  0b0..Divider clock is running.
 *  0b1..Divider clock is stopped.
 */
#define SYSCON_SPIFICLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_HALT_SHIFT)) & SYSCON_SPIFICLKDIV_HALT_MASK)

#define SYSCON_SPIFICLKDIV_REQFLAG_MASK          (0x80000000U)
#define SYSCON_SPIFICLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Divider status flag.
 *  0b0..Divider clock is stable.
 *  0b1..Clock frequency is not stable.
 */
#define SYSCON_SPIFICLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_SPIFICLKDIV_REQFLAG_SHIFT)) & SYSCON_SPIFICLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name CLOCKGENUPDATELOCKOUT - Control clock configuration registers access (like xxxDIV, xxxSEL) */
/*! @{ */

#define SYSCON_CLOCKGENUPDATELOCKOUT_CLOCKGENUPDATELOCKOUT_MASK (0xFFFFFFFFU)
#define SYSCON_CLOCKGENUPDATELOCKOUT_CLOCKGENUPDATELOCKOUT_SHIFT (0U)
/*! CLOCKGENUPDATELOCKOUT - Control clock configuration registers access (for example, xxxDIV, xxxSEL).
 *  0b00000000000000000000000000000000..all hardware clock configruration are freeze.
 *  0b00000000000000000000000000000001..update all clock configuration.
 */
#define SYSCON_CLOCKGENUPDATELOCKOUT_CLOCKGENUPDATELOCKOUT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCKGENUPDATELOCKOUT_CLOCKGENUPDATELOCKOUT_SHIFT)) & SYSCON_CLOCKGENUPDATELOCKOUT_CLOCKGENUPDATELOCKOUT_MASK)
/*! @} */

/*! @name ROMCR - ROM access configuration register */
/*! @{ */

#define SYSCON_ROMCR_WAIT_MASK                   (0x1U)
#define SYSCON_ROMCR_WAIT_SHIFT                  (0U)
/*! WAIT - An extra-wait state between ARM master and ROM access.
 *  0b0..No extra-wait state between ARM master and ROM access.
 *  0b1..An extra-wait state between ARM master and ROM access.
 */
#define SYSCON_ROMCR_WAIT(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_ROMCR_WAIT_SHIFT)) & SYSCON_ROMCR_WAIT_MASK)
/*! @} */

/*! @name EZHINT - EZH interrupt hijack */
/*! @{ */

#define SYSCON_EZHINT_EZHINT_MASK                (0xFFFFFFU)
#define SYSCON_EZHINT_EZHINT_SHIFT               (0U)
/*! EZHINT - EZH interrupt hijack. */
#define SYSCON_EZHINT_EZHINT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_EZHINT_EZHINT_SHIFT)) & SYSCON_EZHINT_EZHINT_MASK)
/*! @} */

/*! @name FLASHREMAP_SIZE - This 32-bit register contains the size of the image to remap, in bytes. The 12 LSBs are ignored, so the size granularity is 4KB. */
/*! @{ */

#define SYSCON_FLASHREMAP_SIZE_FLASHREMAP_SIZE_MASK (0xFFFFFFFFU)
#define SYSCON_FLASHREMAP_SIZE_FLASHREMAP_SIZE_SHIFT (0U)
#define SYSCON_FLASHREMAP_SIZE_FLASHREMAP_SIZE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHREMAP_SIZE_FLASHREMAP_SIZE_SHIFT)) & SYSCON_FLASHREMAP_SIZE_FLASHREMAP_SIZE_MASK)
/*! @} */

/*! @name FLASHREMAP_SIZE_DP - This 32-bit register is a duplicate of FLASHREMAPSIZE for increased security. */
/*! @{ */

#define SYSCON_FLASHREMAP_SIZE_DP_FLASHREMAP_SIZE_MASK (0xFFFFFFFFU)
#define SYSCON_FLASHREMAP_SIZE_DP_FLASHREMAP_SIZE_SHIFT (0U)
#define SYSCON_FLASHREMAP_SIZE_DP_FLASHREMAP_SIZE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHREMAP_SIZE_DP_FLASHREMAP_SIZE_SHIFT)) & SYSCON_FLASHREMAP_SIZE_DP_FLASHREMAP_SIZE_MASK)
/*! @} */

/*! @name FLASHREMAP_OFFSET - This 32-bit register contains the offset by which the image is to be remapped. The 12 LSBs are ignored, so the remap granularity is 4KB. */
/*! @{ */

#define SYSCON_FLASHREMAP_OFFSET_FLASHREMAP_OFFSET_MASK (0xFFFFFFFFU)
#define SYSCON_FLASHREMAP_OFFSET_FLASHREMAP_OFFSET_SHIFT (0U)
#define SYSCON_FLASHREMAP_OFFSET_FLASHREMAP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHREMAP_OFFSET_FLASHREMAP_OFFSET_SHIFT)) & SYSCON_FLASHREMAP_OFFSET_FLASHREMAP_OFFSET_MASK)
/*! @} */

/*! @name FLASHREMAP_OFFSET_DP - This 32-bit register is a duplicate of FLASHREMAPOFFSET for increased security. */
/*! @{ */

#define SYSCON_FLASHREMAP_OFFSET_DP_FLASHREMAP_OFFSET_MASK (0xFFFFFFFFU)
#define SYSCON_FLASHREMAP_OFFSET_DP_FLASHREMAP_OFFSET_SHIFT (0U)
#define SYSCON_FLASHREMAP_OFFSET_DP_FLASHREMAP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHREMAP_OFFSET_DP_FLASHREMAP_OFFSET_SHIFT)) & SYSCON_FLASHREMAP_OFFSET_DP_FLASHREMAP_OFFSET_MASK)
/*! @} */

/*! @name FLASHBANKENABLE - Flash Banks control */
/*! @{ */

#define SYSCON_FLASHBANKENABLE_BANK0_MASK        (0xFU)
#define SYSCON_FLASHBANKENABLE_BANK0_SHIFT       (0U)
/*! BANK0 - Flash Bank0 control.
 *  0b0000..Flash BANK0 checker is enabled (all Flash pages inside this bank cannot be erased nor programmed).
 *  0b1010..Flash BANK0 checker is disabled (all Flash pages inside this bank can be erased and programmed).
 */
#define SYSCON_FLASHBANKENABLE_BANK0(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHBANKENABLE_BANK0_SHIFT)) & SYSCON_FLASHBANKENABLE_BANK0_MASK)

#define SYSCON_FLASHBANKENABLE_BANK1_MASK        (0xF0U)
#define SYSCON_FLASHBANKENABLE_BANK1_SHIFT       (4U)
/*! BANK1 - Flash Bank1 control.
 *  0b0000..Flash BANK1 checker is enabled (all Flash pages inside this bank cannot be erased nor programmed).
 *  0b1010..Flash BANK1 checker is disabled (all Flash pages inside this bank can be erased and programmed).
 */
#define SYSCON_FLASHBANKENABLE_BANK1(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHBANKENABLE_BANK1_SHIFT)) & SYSCON_FLASHBANKENABLE_BANK1_MASK)

#define SYSCON_FLASHBANKENABLE_BANK2_MASK        (0xF00U)
#define SYSCON_FLASHBANKENABLE_BANK2_SHIFT       (8U)
/*! BANK2 - Flash Bank2 control.
 *  0b0000..Flash BANK2 checker is enabled (all Flash pages inside this bank cannot be erased nor programmed).
 *  0b1010..Flash BANK2 checker is disabled (all Flash pages inside this bank can be erased and programmed).
 */
#define SYSCON_FLASHBANKENABLE_BANK2(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHBANKENABLE_BANK2_SHIFT)) & SYSCON_FLASHBANKENABLE_BANK2_MASK)

#define SYSCON_FLASHBANKENABLE_BANK3_MASK        (0xF000U)
#define SYSCON_FLASHBANKENABLE_BANK3_SHIFT       (12U)
/*! BANK3 - Flash Bank3 control.
 *  0b0000..Flash BANK3 checker is enabled (all Flash pages inside this bank cannot be erased nor programmed).
 *  0b1010..Flash BANK3 checker is disabled (all Flash pages inside this bank can be erased and programmed).
 */
#define SYSCON_FLASHBANKENABLE_BANK3(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHBANKENABLE_BANK3_SHIFT)) & SYSCON_FLASHBANKENABLE_BANK3_MASK)

#define SYSCON_FLASHBANKENABLE_IFR1_MASK         (0xF0000U)
#define SYSCON_FLASHBANKENABLE_IFR1_SHIFT        (16U)
/*! IFR1 - IFR1 read access control.
 *  0b0000..IFR1 bank is disabled to read.
 *  0b1010..IFR1 bank is enabled to read.
 */
#define SYSCON_FLASHBANKENABLE_IFR1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHBANKENABLE_IFR1_SHIFT)) & SYSCON_FLASHBANKENABLE_IFR1_MASK)
/*! @} */

/*! @name FLASHREMAP_LOCK - Control write access to FLASHREMAP_SIZE and FLASHREMAP_OFFSET registers. */
/*! @{ */

#define SYSCON_FLASHREMAP_LOCK_LOCK_MASK         (0xFFFFFFFFU)
#define SYSCON_FLASHREMAP_LOCK_LOCK_SHIFT        (0U)
/*! LOCK - Control write access to FLASHREMAP_SIZE and FLASHREMAP_OFFSET registers. Any value other
 *    than 0xC33CA55A and 0x3CC35AA5 does not modify the state.
 *  0b00111100110000110101101010100101..Write access to 4 registers FLASHREMAP_SIZE* and FLASHREMAP_OFFSET* is unlocked.
 *  0b11000011001111001010010101011010..Write access to 4 registers FLASHREMAP_SIZE* and FLASHREMAP_OFFSET* is locked.
 */
#define SYSCON_FLASHREMAP_LOCK_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHREMAP_LOCK_LOCK_SHIFT)) & SYSCON_FLASHREMAP_LOCK_LOCK_MASK)
/*! @} */

/*! @name CASPER_CTRL - Control CASPER integration. */
/*! @{ */

#define SYSCON_CASPER_CTRL_INTERLEAVE_MASK       (0x1U)
#define SYSCON_CASPER_CTRL_INTERLEAVE_SHIFT      (0U)
/*! INTERLEAVE - Control RAM access for RAMX0 and RAMX1.
 *  0b0..RAM access to RAMX0 and RAMX1 is consecutive.
 *  0b1..RAM access to RAMX0 and RAMX1 is interleaved.
 */
#define SYSCON_CASPER_CTRL_INTERLEAVE(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_CASPER_CTRL_INTERLEAVE_SHIFT)) & SYSCON_CASPER_CTRL_INTERLEAVE_MASK)
/*! @} */

/*! @name BOOT_LOCKOUT_ADDR - When ROM address is below the Address Offset. The access to ROM is block if BOOT_LOCKOUT is LOCK. */
/*! @{ */

#define SYSCON_BOOT_LOCKOUT_ADDR_ADDR_OFFSET_MASK (0x7FFFU)
#define SYSCON_BOOT_LOCKOUT_ADDR_ADDR_OFFSET_SHIFT (0U)
/*! ADDR_OFFSET - Address offset (32 bits addressing). Under this value the ROM access is blocked if BOOT_LOCKOUT is LOCK. */
#define SYSCON_BOOT_LOCKOUT_ADDR_ADDR_OFFSET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_LOCKOUT_ADDR_ADDR_OFFSET_SHIFT)) & SYSCON_BOOT_LOCKOUT_ADDR_ADDR_OFFSET_MASK)
/*! @} */

/*! @name BOOT_LOCKOUT_ADDR_DP - When ROM address is below the Address Offset. The access to ROM is block if BOOT_LOCKOUT is LOCK. Duplicate of BOOT_LOCKOUT_ADDR. */
/*! @{ */

#define SYSCON_BOOT_LOCKOUT_ADDR_DP_ADDR_OFFSET_MASK (0x7FFFU)
#define SYSCON_BOOT_LOCKOUT_ADDR_DP_ADDR_OFFSET_SHIFT (0U)
/*! ADDR_OFFSET - Address offset (32 bits addressing). Under this value the ROM access is blocked if BOOT_LOCKOUT is LOCK. */
#define SYSCON_BOOT_LOCKOUT_ADDR_DP_ADDR_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_LOCKOUT_ADDR_DP_ADDR_OFFSET_SHIFT)) & SYSCON_BOOT_LOCKOUT_ADDR_DP_ADDR_OFFSET_MASK)
/*! @} */

/*! @name BOOT_LOCKOUT - Control write access to BOOT_LOCKOUT_ADDR and BOOT_LOCKOUT_ADDR registers and ROM memory. */
/*! @{ */

#define SYSCON_BOOT_LOCKOUT_LOCK_MASK            (0xFFFFFFFFU)
#define SYSCON_BOOT_LOCKOUT_LOCK_SHIFT           (0U)
/*! LOCK - Control write access to BOOT_LOCKOUT_ADDR and BOOT_LOCKOUT_ADDR registers and ROM memory.
 *  0b00111100110000110101101010100101..ROM access is alowed, and registers BOOT_LOCKOUT_ADDR and BOOT_LOCKOUT_ADDR_DP is writable.
 *  0b11000011001111001010010101011010..ROM access is locked, and registers BOOT_LOCKOUT_ADDR and BOOT_LOCKOUT_ADDR_DP is write protected.
 */
#define SYSCON_BOOT_LOCKOUT_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_LOCKOUT_LOCK_SHIFT)) & SYSCON_BOOT_LOCKOUT_LOCK_MASK)
/*! @} */

/*! @name STARTER - Start logic wake-up enable register */
/*! @{ */

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

#define SYSCON_STARTER_PIO_INT1_MASK             (0x20U)
#define SYSCON_STARTER_PIO_INT1_SHIFT            (5U)
/*! PIO_INT1 - PIO_INT1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PIO_INT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIO_INT1_SHIFT)) & SYSCON_STARTER_PIO_INT1_MASK)

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

#define SYSCON_STARTER_PIO_INT3_MASK             (0x80U)
#define SYSCON_STARTER_PIO_INT3_SHIFT            (7U)
/*! PIO_INT3 - PIO_INT3 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PIO_INT3(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PIO_INT3_SHIFT)) & SYSCON_STARTER_PIO_INT3_MASK)

#define SYSCON_STARTER_SPIFI_MASK                (0x80U)
#define SYSCON_STARTER_SPIFI_SHIFT               (7U)
/*! SPIFI - SPIFI interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SPIFI(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SPIFI_SHIFT)) & SYSCON_STARTER_SPIFI_MASK)

#define SYSCON_STARTER_UTICK0_MASK               (0x100U)
#define SYSCON_STARTER_UTICK0_SHIFT              (8U)
/*! UTICK0 - UTICK0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_UTICK0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_UTICK0_SHIFT)) & SYSCON_STARTER_UTICK0_MASK)

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

#define SYSCON_STARTER_CTIMER1_MASK              (0x800U)
#define SYSCON_STARTER_CTIMER1_SHIFT             (11U)
/*! CTIMER1 - CTIMER1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CTIMER1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CTIMER1_SHIFT)) & SYSCON_STARTER_CTIMER1_MASK)

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

#define SYSCON_STARTER_FLEXINT0_MASK             (0x4000U)
#define SYSCON_STARTER_FLEXINT0_SHIFT            (14U)
/*! FLEXINT0 - FLEXINT0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT0_SHIFT)) & SYSCON_STARTER_FLEXINT0_MASK)

#define SYSCON_STARTER_FLEXINT1_MASK             (0x8000U)
#define SYSCON_STARTER_FLEXINT1_SHIFT            (15U)
/*! FLEXINT1 - FLEXINT1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT1_SHIFT)) & SYSCON_STARTER_FLEXINT1_MASK)

#define SYSCON_STARTER_FLEXINT2_MASK             (0x10000U)
#define SYSCON_STARTER_FLEXINT2_SHIFT            (16U)
/*! FLEXINT2 - FLEXINT2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_FLEXINT2(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_FLEXINT2_SHIFT)) & SYSCON_STARTER_FLEXINT2_MASK)

#define SYSCON_STARTER_SEC_HYPERVISOR_CALL_MASK  (0x20000U)
#define SYSCON_STARTER_SEC_HYPERVISOR_CALL_SHIFT (17U)
/*! SEC_HYPERVISOR_CALL - SEC_HYPERVISOR_CALL interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_HYPERVISOR_CALL(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_HYPERVISOR_CALL_SHIFT)) & SYSCON_STARTER_SEC_HYPERVISOR_CALL_MASK)

#define SYSCON_STARTER_SEC_GPIO_INT00_MASK       (0x40000U)
#define SYSCON_STARTER_SEC_GPIO_INT00_SHIFT      (18U)
/*! SEC_GPIO_INT00 - SEC_GPIO_INT00 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_GPIO_INT00(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_GPIO_INT00_SHIFT)) & SYSCON_STARTER_SEC_GPIO_INT00_MASK)

#define SYSCON_STARTER_SEC_GPIO_INT01_MASK       (0x80000U)
#define SYSCON_STARTER_SEC_GPIO_INT01_SHIFT      (19U)
/*! SEC_GPIO_INT01 - SEC_GPIO_INT01 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_GPIO_INT01(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_GPIO_INT01_SHIFT)) & SYSCON_STARTER_SEC_GPIO_INT01_MASK)

#define SYSCON_STARTER_PLU_MASK                  (0x100000U)
#define SYSCON_STARTER_PLU_SHIFT                 (20U)
/*! PLU - PLU interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_PLU(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_PLU_SHIFT)) & SYSCON_STARTER_PLU_MASK)

#define SYSCON_STARTER_SEC_VIO_MASK              (0x200000U)
#define SYSCON_STARTER_SEC_VIO_SHIFT             (21U)
/*! SEC_VIO - SEC_VIO interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SEC_VIO(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SEC_VIO_SHIFT)) & SYSCON_STARTER_SEC_VIO_MASK)

#define SYSCON_STARTER_BLE_LL_MASK               (0x400000U)
#define SYSCON_STARTER_BLE_LL_SHIFT              (22U)
/*! BLE_LL - BLE link layer interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_BLE_LL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_BLE_LL_SHIFT)) & SYSCON_STARTER_BLE_LL_MASK)

#define SYSCON_STARTER_SHA_MASK                  (0x400000U)
#define SYSCON_STARTER_SHA_SHIFT                 (22U)
/*! SHA - SHA interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SHA(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SHA_SHIFT)) & SYSCON_STARTER_SHA_MASK)

#define SYSCON_STARTER_BLE_SLP_TMR_MASK          (0x800000U)
#define SYSCON_STARTER_BLE_SLP_TMR_SHIFT         (23U)
/*! BLE_SLP_TMR - BLE sleep timer interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_BLE_SLP_TMR(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_BLE_SLP_TMR_SHIFT)) & SYSCON_STARTER_BLE_SLP_TMR_MASK)

#define SYSCON_STARTER_CASPER_MASK               (0x800000U)
#define SYSCON_STARTER_CASPER_SHIFT              (23U)
/*! CASPER - CASPER interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_CASPER(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_CASPER_SHIFT)) & SYSCON_STARTER_CASPER_MASK)

#define SYSCON_STARTER_QDDKEY_MASK               (0x1000000U)
#define SYSCON_STARTER_QDDKEY_SHIFT              (24U)
/*! QDDKEY - QDDKEY interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_QDDKEY(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_QDDKEY_SHIFT)) & SYSCON_STARTER_QDDKEY_MASK)

#define SYSCON_STARTER_SDMA1_MASK                (0x4000000U)
#define SYSCON_STARTER_SDMA1_SHIFT               (26U)
/*! SDMA1 - SDMA1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_SDMA1(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_SDMA1_SHIFT)) & SYSCON_STARTER_SDMA1_MASK)

#define SYSCON_STARTER_BOD1_MASK                 (0x8000000U)
#define SYSCON_STARTER_BOD1_SHIFT                (27U)
/*! BOD1 - BOD1 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_BOD1(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_BOD1_SHIFT)) & SYSCON_STARTER_BOD1_MASK)

#define SYSCON_STARTER_BOD2_MASK                 (0x10000000U)
#define SYSCON_STARTER_BOD2_SHIFT                (28U)
/*! BOD2 - BOD2 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_BOD2(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_BOD2_SHIFT)) & SYSCON_STARTER_BOD2_MASK)

#define SYSCON_STARTER_RTC_LITE0_MASK            (0x20000000U)
#define SYSCON_STARTER_RTC_LITE0_SHIFT           (29U)
/*! RTC_LITE0 - RTC_LITE0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_RTC_LITE0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_RTC_LITE0_SHIFT)) & SYSCON_STARTER_RTC_LITE0_MASK)

#define SYSCON_STARTER_EZH_ARCH_B0_MASK          (0x40000000U)
#define SYSCON_STARTER_EZH_ARCH_B0_SHIFT         (30U)
/*! EZH_ARCH_B0 - EZH_ARCH_B0 interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_EZH_ARCH_B0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_EZH_ARCH_B0_SHIFT)) & SYSCON_STARTER_EZH_ARCH_B0_MASK)

#define SYSCON_STARTER_WAKEUP_MASK               (0x80000000U)
#define SYSCON_STARTER_WAKEUP_SHIFT              (31U)
/*! WAKEUP - WAKEUP from deepsleep interrupt wake-up.
 *  0b0..Wake-up disabled.
 *  0b1..Wake-up enabled.
 */
#define SYSCON_STARTER_WAKEUP(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_WAKEUP_SHIFT)) & SYSCON_STARTER_WAKEUP_MASK)

#define SYSCON_STARTER_WAKEUPPADS_MASK           (0x80000000U)
#define SYSCON_STARTER_WAKEUPPADS_SHIFT          (31U)
/*! WAKEUPPADS - WAKEUPPADS interrupt wake-up. */
#define SYSCON_STARTER_WAKEUPPADS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTER_WAKEUPPADS_SHIFT)) & SYSCON_STARTER_WAKEUPPADS_MASK)
/*! @} */

/*! @name STARTERSET - Set bits in STARTER */
/*! @{ */

#define SYSCON_STARTERSET_GPIO_INT04_SET_MASK    (0x1U)
#define SYSCON_STARTERSET_GPIO_INT04_SET_SHIFT   (0U)
/*! GPIO_INT04_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT04_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT04_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT04_SET_MASK)

#define SYSCON_STARTERSET_SYS_SET_MASK           (0x1U)
#define SYSCON_STARTERSET_SYS_SET_SHIFT          (0U)
/*! SYS_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_SYS_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SYS_SET_SHIFT)) & SYSCON_STARTERSET_SYS_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT05_SET_MASK    (0x2U)
#define SYSCON_STARTERSET_GPIO_INT05_SET_SHIFT   (1U)
/*! GPIO_INT05_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT05_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT05_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT05_SET_MASK)

#define SYSCON_STARTERSET_SDMA0_SET_MASK         (0x2U)
#define SYSCON_STARTERSET_SDMA0_SET_SHIFT        (1U)
/*! SDMA0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_SDMA0_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SDMA0_SET_SHIFT)) & SYSCON_STARTERSET_SDMA0_SET_MASK)

#define SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_MASK (0x4U)
#define SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_SHIFT (2U)
/*! GPIO_GLOBALINT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_GLOBALINT0_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_GLOBALINT0_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT06_SET_MASK    (0x4U)
#define SYSCON_STARTERSET_GPIO_INT06_SET_SHIFT   (2U)
/*! GPIO_INT06_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT06_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT06_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT06_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT07_SET_MASK    (0x8U)
#define SYSCON_STARTERSET_GPIO_INT07_SET_SHIFT   (3U)
/*! GPIO_INT07_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_GPIO_INT07_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT07_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT07_SET_MASK)

#define SYSCON_STARTERSET_CTIMER2_SET_MASK       (0x10U)
#define SYSCON_STARTERSET_CTIMER2_SET_SHIFT      (4U)
/*! CTIMER2_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_CTIMER2_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER2_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER2_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT00_SET_MASK    (0x10U)
#define SYSCON_STARTERSET_GPIO_INT00_SET_SHIFT   (4U)
/*! GPIO_INT00_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT00_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT00_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT00_SET_MASK)

#define SYSCON_STARTERSET_CTIMER4_SET_MASK       (0x20U)
#define SYSCON_STARTERSET_CTIMER4_SET_SHIFT      (5U)
/*! CTIMER4_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_CTIMER4_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER4_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER4_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT01_SET_MASK    (0x20U)
#define SYSCON_STARTERSET_GPIO_INT01_SET_SHIFT   (5U)
/*! GPIO_INT01_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT01_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT01_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT01_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT02_SET_MASK    (0x40U)
#define SYSCON_STARTERSET_GPIO_INT02_SET_SHIFT   (6U)
/*! GPIO_INT02_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT02_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT02_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT02_SET_MASK)

#define SYSCON_STARTERSET_OS_EVENT_SET_MASK      (0x40U)
#define SYSCON_STARTERSET_OS_EVENT_SET_SHIFT     (6U)
/*! OS_EVENT_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_OS_EVENT_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_OS_EVENT_SET_SHIFT)) & SYSCON_STARTERSET_OS_EVENT_SET_MASK)

#define SYSCON_STARTERSET_GPIO_INT03_SET_MASK    (0x80U)
#define SYSCON_STARTERSET_GPIO_INT03_SET_SHIFT   (7U)
/*! GPIO_INT03_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_GPIO_INT03_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_GPIO_INT03_SET_SHIFT)) & SYSCON_STARTERSET_GPIO_INT03_SET_MASK)

#define SYSCON_STARTERSET_SPIFI_SET_MASK         (0x80U)
#define SYSCON_STARTERSET_SPIFI_SET_SHIFT        (7U)
/*! SPIFI_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SPIFI_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SPIFI_SET_SHIFT)) & SYSCON_STARTERSET_SPIFI_SET_MASK)

#define SYSCON_STARTERSET_UTICK0_SET_MASK        (0x100U)
#define SYSCON_STARTERSET_UTICK0_SET_SHIFT       (8U)
/*! UTICK0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_UTICK0_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_UTICK0_SET_SHIFT)) & SYSCON_STARTERSET_UTICK0_SET_MASK)

#define SYSCON_STARTERSET_MRT0_SET_MASK          (0x200U)
#define SYSCON_STARTERSET_MRT0_SET_SHIFT         (9U)
/*! MRT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_MRT0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_MRT0_SET_SHIFT)) & SYSCON_STARTERSET_MRT0_SET_MASK)

#define SYSCON_STARTERSET_CTIMER0_SET_MASK       (0x400U)
#define SYSCON_STARTERSET_CTIMER0_SET_SHIFT      (10U)
/*! CTIMER0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_CTIMER0_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER0_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER0_SET_MASK)

#define SYSCON_STARTERSET_CTIMER1_SET_MASK       (0x800U)
#define SYSCON_STARTERSET_CTIMER1_SET_SHIFT      (11U)
/*! CTIMER1_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_CTIMER1_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER1_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER1_SET_MASK)

#define SYSCON_STARTERSET_SCT0_SET_MASK          (0x1000U)
#define SYSCON_STARTERSET_SCT0_SET_SHIFT         (12U)
/*! SCT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_SCT0_SET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SCT0_SET_SHIFT)) & SYSCON_STARTERSET_SCT0_SET_MASK)

#define SYSCON_STARTERSET_CTIMER3_SET_MASK       (0x2000U)
#define SYSCON_STARTERSET_CTIMER3_SET_SHIFT      (13U)
/*! CTIMER3_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_CTIMER3_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CTIMER3_SET_SHIFT)) & SYSCON_STARTERSET_CTIMER3_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT0_SET_MASK      (0x4000U)
#define SYSCON_STARTERSET_FLEXINT0_SET_SHIFT     (14U)
/*! FLEXINT0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT0_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT0_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT0_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT1_SET_MASK      (0x8000U)
#define SYSCON_STARTERSET_FLEXINT1_SET_SHIFT     (15U)
/*! FLEXINT1_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT1_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT1_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT1_SET_MASK)

#define SYSCON_STARTERSET_FLEXINT2_SET_MASK      (0x10000U)
#define SYSCON_STARTERSET_FLEXINT2_SET_SHIFT     (16U)
/*! FLEXINT2_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_FLEXINT2_SET(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_FLEXINT2_SET_SHIFT)) & SYSCON_STARTERSET_FLEXINT2_SET_MASK)

#define SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_MASK (0x20000U)
#define SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_SHIFT (17U)
/*! SEC_HYPERVISOR_CALL_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_SHIFT)) & SYSCON_STARTERSET_SEC_HYPERVISOR_CALL_SET_MASK)

#define SYSCON_STARTERSET_SEC_GPIO_INT00_SET_MASK (0x40000U)
#define SYSCON_STARTERSET_SEC_GPIO_INT00_SET_SHIFT (18U)
/*! SEC_GPIO_INT00_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_GPIO_INT00_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_GPIO_INT00_SET_SHIFT)) & SYSCON_STARTERSET_SEC_GPIO_INT00_SET_MASK)

#define SYSCON_STARTERSET_SEC_GPIO_INT01_SET_MASK (0x80000U)
#define SYSCON_STARTERSET_SEC_GPIO_INT01_SET_SHIFT (19U)
/*! SEC_GPIO_INT01_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_GPIO_INT01_SET(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_GPIO_INT01_SET_SHIFT)) & SYSCON_STARTERSET_SEC_GPIO_INT01_SET_MASK)

#define SYSCON_STARTERSET_PLU_SET_MASK           (0x100000U)
#define SYSCON_STARTERSET_PLU_SET_SHIFT          (20U)
/*! PLU_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_PLU_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_PLU_SET_SHIFT)) & SYSCON_STARTERSET_PLU_SET_MASK)

#define SYSCON_STARTERSET_SEC_VIO_SET_MASK       (0x200000U)
#define SYSCON_STARTERSET_SEC_VIO_SET_SHIFT      (21U)
/*! SEC_VIO_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SEC_VIO_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SEC_VIO_SET_SHIFT)) & SYSCON_STARTERSET_SEC_VIO_SET_MASK)

#define SYSCON_STARTERSET_BLE_LL_INT_SET_MASK    (0x400000U)
#define SYSCON_STARTERSET_BLE_LL_INT_SET_SHIFT   (22U)
/*! BLE_LL_INT_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_BLE_LL_INT_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_BLE_LL_INT_SET_SHIFT)) & SYSCON_STARTERSET_BLE_LL_INT_SET_MASK)

#define SYSCON_STARTERSET_SHA_SET_MASK           (0x400000U)
#define SYSCON_STARTERSET_SHA_SET_SHIFT          (22U)
/*! SHA_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SHA_SET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SHA_SET_SHIFT)) & SYSCON_STARTERSET_SHA_SET_MASK)

#define SYSCON_STARTERSET_BLE_SLP_TMR_INT_SET_MASK (0x800000U)
#define SYSCON_STARTERSET_BLE_SLP_TMR_INT_SET_SHIFT (23U)
/*! BLE_SLP_TMR_INT_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_BLE_SLP_TMR_INT_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_BLE_SLP_TMR_INT_SET_SHIFT)) & SYSCON_STARTERSET_BLE_SLP_TMR_INT_SET_MASK)

#define SYSCON_STARTERSET_CASPER_SET_MASK        (0x800000U)
#define SYSCON_STARTERSET_CASPER_SET_SHIFT       (23U)
/*! CASPER_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_CASPER_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_CASPER_SET_SHIFT)) & SYSCON_STARTERSET_CASPER_SET_MASK)

#define SYSCON_STARTERSET_QDDKEY_SET_MASK        (0x1000000U)
#define SYSCON_STARTERSET_QDDKEY_SET_SHIFT       (24U)
/*! QDDKEY_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_QDDKEY_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_QDDKEY_SET_SHIFT)) & SYSCON_STARTERSET_QDDKEY_SET_MASK)

#define SYSCON_STARTERSET_SDMA1_SET_MASK         (0x4000000U)
#define SYSCON_STARTERSET_SDMA1_SET_SHIFT        (26U)
/*! SDMA1_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_SDMA1_SET(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_SDMA1_SET_SHIFT)) & SYSCON_STARTERSET_SDMA1_SET_MASK)

#define SYSCON_STARTERSET_BOD1INT_SET_MASK       (0x8000000U)
#define SYSCON_STARTERSET_BOD1INT_SET_SHIFT      (27U)
/*! BOD1INT_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_BOD1INT_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_BOD1INT_SET_SHIFT)) & SYSCON_STARTERSET_BOD1INT_SET_MASK)

#define SYSCON_STARTERSET_BOD2INT_SET_MASK       (0x10000000U)
#define SYSCON_STARTERSET_BOD2INT_SET_SHIFT      (28U)
/*! BOD2INT_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_BOD2INT_SET(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_BOD2INT_SET_SHIFT)) & SYSCON_STARTERSET_BOD2INT_SET_MASK)

#define SYSCON_STARTERSET_RTC_LITE0_SET_MASK     (0x20000000U)
#define SYSCON_STARTERSET_RTC_LITE0_SET_SHIFT    (29U)
/*! RTC_LITE0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_RTC_LITE0_SET(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_RTC_LITE0_SET_SHIFT)) & SYSCON_STARTERSET_RTC_LITE0_SET_MASK)

#define SYSCON_STARTERSET_EZH_ARCH_B0_SET_MASK   (0x40000000U)
#define SYSCON_STARTERSET_EZH_ARCH_B0_SET_SHIFT  (30U)
/*! EZH_ARCH_B0_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_EZH_ARCH_B0_SET(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_EZH_ARCH_B0_SET_SHIFT)) & SYSCON_STARTERSET_EZH_ARCH_B0_SET_MASK)

#define SYSCON_STARTERSET_WAKEUPPADS_SET_MASK    (0x80000000U)
#define SYSCON_STARTERSET_WAKEUPPADS_SET_SHIFT   (31U)
/*! WAKEUPPADS_SET - Writing ones to this register sets the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERSET_WAKEUPPADS_SET(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_WAKEUPPADS_SET_SHIFT)) & SYSCON_STARTERSET_WAKEUPPADS_SET_MASK)

#define SYSCON_STARTERSET_WAKEUP_SET_MASK        (0x80000000U)
#define SYSCON_STARTERSET_WAKEUP_SET_SHIFT       (31U)
/*! WAKEUP_SET - Writing ones to this register sets the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERSET_WAKEUP_SET(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERSET_WAKEUP_SET_SHIFT)) & SYSCON_STARTERSET_WAKEUP_SET_MASK)
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

#define SYSCON_STARTERCLR_SPIFI_CLR_MASK         (0x80U)
#define SYSCON_STARTERCLR_SPIFI_CLR_SHIFT        (7U)
/*! SPIFI_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SPIFI_CLR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SPIFI_CLR_SHIFT)) & SYSCON_STARTERCLR_SPIFI_CLR_MASK)

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

#define SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_MASK (0x20000U)
#define SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_SHIFT (17U)
/*! SEC_HYPERVISOR_CALL_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_HYPERVISOR_CALL_CLR_MASK)

#define SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_MASK (0x40000U)
#define SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_SHIFT (18U)
/*! SEC_GPIO_INT00_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_GPIO_INT00_CLR_MASK)

#define SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_MASK (0x80000U)
#define SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_SHIFT (19U)
/*! SEC_GPIO_INT01_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_GPIO_INT01_CLR_MASK)

#define SYSCON_STARTERCLR_PLU_CLR_MASK           (0x100000U)
#define SYSCON_STARTERCLR_PLU_CLR_SHIFT          (20U)
/*! PLU_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_PLU_CLR(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_PLU_CLR_SHIFT)) & SYSCON_STARTERCLR_PLU_CLR_MASK)

#define SYSCON_STARTERCLR_SEC_VIO_CLR_MASK       (0x200000U)
#define SYSCON_STARTERCLR_SEC_VIO_CLR_SHIFT      (21U)
/*! SEC_VIO_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SEC_VIO_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SEC_VIO_CLR_SHIFT)) & SYSCON_STARTERCLR_SEC_VIO_CLR_MASK)

#define SYSCON_STARTERCLR_BLE_LL_INT_CLR_MASK    (0x400000U)
#define SYSCON_STARTERCLR_BLE_LL_INT_CLR_SHIFT   (22U)
/*! BLE_LL_INT_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_BLE_LL_INT_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_BLE_LL_INT_CLR_SHIFT)) & SYSCON_STARTERCLR_BLE_LL_INT_CLR_MASK)

#define SYSCON_STARTERCLR_SHA_CLR_MASK           (0x400000U)
#define SYSCON_STARTERCLR_SHA_CLR_SHIFT          (22U)
/*! SHA_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SHA_CLR(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SHA_CLR_SHIFT)) & SYSCON_STARTERCLR_SHA_CLR_MASK)

#define SYSCON_STARTERCLR_BLE_SLP_TMR_INT_CLR_MASK (0x800000U)
#define SYSCON_STARTERCLR_BLE_SLP_TMR_INT_CLR_SHIFT (23U)
/*! BLE_SLP_TMR_INT_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_BLE_SLP_TMR_INT_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_BLE_SLP_TMR_INT_CLR_SHIFT)) & SYSCON_STARTERCLR_BLE_SLP_TMR_INT_CLR_MASK)

#define SYSCON_STARTERCLR_CASPER_CLR_MASK        (0x800000U)
#define SYSCON_STARTERCLR_CASPER_CLR_SHIFT       (23U)
/*! CASPER_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_CASPER_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_CASPER_CLR_SHIFT)) & SYSCON_STARTERCLR_CASPER_CLR_MASK)

#define SYSCON_STARTERCLR_QDDKEY_CLR_MASK        (0x1000000U)
#define SYSCON_STARTERCLR_QDDKEY_CLR_SHIFT       (24U)
/*! QDDKEY_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_QDDKEY_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_QDDKEY_CLR_SHIFT)) & SYSCON_STARTERCLR_QDDKEY_CLR_MASK)

#define SYSCON_STARTERCLR_SDMA1_CLR_MASK         (0x4000000U)
#define SYSCON_STARTERCLR_SDMA1_CLR_SHIFT        (26U)
/*! SDMA1_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_SDMA1_CLR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_SDMA1_CLR_SHIFT)) & SYSCON_STARTERCLR_SDMA1_CLR_MASK)

#define SYSCON_STARTERCLR_BOD1INT_CLR_MASK       (0x8000000U)
#define SYSCON_STARTERCLR_BOD1INT_CLR_SHIFT      (27U)
/*! BOD1INT_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_BOD1INT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_BOD1INT_CLR_SHIFT)) & SYSCON_STARTERCLR_BOD1INT_CLR_MASK)

#define SYSCON_STARTERCLR_BOD2INT_CLR_MASK       (0x10000000U)
#define SYSCON_STARTERCLR_BOD2INT_CLR_SHIFT      (28U)
/*! BOD2INT_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_BOD2INT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_BOD2INT_CLR_SHIFT)) & SYSCON_STARTERCLR_BOD2INT_CLR_MASK)

#define SYSCON_STARTERCLR_RTC_LITE0_CLR_MASK     (0x20000000U)
#define SYSCON_STARTERCLR_RTC_LITE0_CLR_SHIFT    (29U)
/*! RTC_LITE0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_RTC_LITE0_CLR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_RTC_LITE0_CLR_SHIFT)) & SYSCON_STARTERCLR_RTC_LITE0_CLR_MASK)

#define SYSCON_STARTERCLR_EZH_ARCH_B0_CLR_MASK   (0x40000000U)
#define SYSCON_STARTERCLR_EZH_ARCH_B0_CLR_SHIFT  (30U)
/*! EZH_ARCH_B0_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_EZH_ARCH_B0_CLR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_EZH_ARCH_B0_CLR_SHIFT)) & SYSCON_STARTERCLR_EZH_ARCH_B0_CLR_MASK)

#define SYSCON_STARTERCLR_WAKEUPPADS_CLR_MASK    (0x80000000U)
#define SYSCON_STARTERCLR_WAKEUPPADS_CLR_SHIFT   (31U)
/*! WAKEUPPADS_CLR - Writing ones to this register clears the corresponding bit in the STARTER1 register. */
#define SYSCON_STARTERCLR_WAKEUPPADS_CLR(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_WAKEUPPADS_CLR_SHIFT)) & SYSCON_STARTERCLR_WAKEUPPADS_CLR_MASK)

#define SYSCON_STARTERCLR_WAKEUP_CLR_MASK        (0x80000000U)
#define SYSCON_STARTERCLR_WAKEUP_CLR_SHIFT       (31U)
/*! WAKEUP_CLR - Writing ones to this register clears the corresponding bit in the STARTER0 register. */
#define SYSCON_STARTERCLR_WAKEUP_CLR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_STARTERCLR_WAKEUP_CLR_SHIFT)) & SYSCON_STARTERCLR_WAKEUP_CLR_MASK)
/*! @} */

/*! @name FUNCRETENTIONCTRL - Functional retention control register */
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
/*! RET_LENTH - length of scan chains to save. */
#define SYSCON_FUNCRETENTIONCTRL_RET_LENTH(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_FUNCRETENTIONCTRL_RET_LENTH_SHIFT)) & SYSCON_FUNCRETENTIONCTRL_RET_LENTH_MASK)
/*! @} */

/*! @name POWERDOWNSAFETY - Override some powerdown control signals (for debug purposes) */
/*! @{ */

#define SYSCON_POWERDOWNSAFETY_OVERRIDEFRO_MASK  (0x1U)
#define SYSCON_POWERDOWNSAFETY_OVERRIDEFRO_SHIFT (0U)
/*! OVERRIDEFRO - Overrides the fro_is_dead' signal in Sleepcon module, in case this doesn't work on silicon. */
#define SYSCON_POWERDOWNSAFETY_OVERRIDEFRO(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_POWERDOWNSAFETY_OVERRIDEFRO_SHIFT)) & SYSCON_POWERDOWNSAFETY_OVERRIDEFRO_MASK)
/*! @} */

/*! @name MAINCLKSAFETY - main clock is enable after MAINCLKSAFETY cycle */
/*! @{ */

#define SYSCON_MAINCLKSAFETY_MAINCLKSAFETY_MASK  (0xFFFFFFFFU)
#define SYSCON_MAINCLKSAFETY_MAINCLKSAFETY_SHIFT (0U)
/*! MAINCLKSAFETY - main clock is enable after MAINCLKSAFETY cycle. */
#define SYSCON_MAINCLKSAFETY_MAINCLKSAFETY(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSAFETY_MAINCLKSAFETY_SHIFT)) & SYSCON_MAINCLKSAFETY_MAINCLKSAFETY_MASK)
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

#define SYSCON_HARDWARESLEEP_SDMA0_MASK          (0x8U)
#define SYSCON_HARDWARESLEEP_SDMA0_SHIFT         (3U)
/*! SDMA0 - Wake for DMA0. */
#define SYSCON_HARDWARESLEEP_SDMA0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_SDMA0_SHIFT)) & SYSCON_HARDWARESLEEP_SDMA0_MASK)

#define SYSCON_HARDWARESLEEP_SDMA1_MASK          (0x20U)
#define SYSCON_HARDWARESLEEP_SDMA1_SHIFT         (5U)
/*! SDMA1 - Wake for DMA1. */
#define SYSCON_HARDWARESLEEP_SDMA1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HARDWARESLEEP_SDMA1_SHIFT)) & SYSCON_HARDWARESLEEP_SDMA1_MASK)
/*! @} */

/*! @name CPSTAT - CPU Status */
/*! @{ */

#define SYSCON_CPSTAT_CPU0SLEEPING_MASK          (0x1U)
#define SYSCON_CPSTAT_CPU0SLEEPING_SHIFT         (0U)
/*! CPU0SLEEPING - The CPU0 sleeping state.
 *  0b0..the CPU is not sleeping.
 *  0b1..the CPU is sleeping.
 */
#define SYSCON_CPSTAT_CPU0SLEEPING(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTAT_CPU0SLEEPING_SHIFT)) & SYSCON_CPSTAT_CPU0SLEEPING_MASK)

#define SYSCON_CPSTAT_CPU0LOCKUP_MASK            (0x4U)
#define SYSCON_CPSTAT_CPU0LOCKUP_SHIFT           (2U)
/*! CPU0LOCKUP - The CPU0 lockup state.
 *  0b0..the CPU is not in lockup.
 *  0b1..the CPU is in lockup.
 */
#define SYSCON_CPSTAT_CPU0LOCKUP(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CPSTAT_CPU0LOCKUP_SHIFT)) & SYSCON_CPSTAT_CPU0LOCKUP_MASK)
/*! @} */

/*! @name DICE_REG0 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG0_DICE_REG0_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG0_DICE_REG0_SHIFT         (0U)
#define SYSCON_DICE_REG0_DICE_REG0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG0_DICE_REG0_SHIFT)) & SYSCON_DICE_REG0_DICE_REG0_MASK)
/*! @} */

/*! @name DICE_REG1 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG1_DICE_REG1_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG1_DICE_REG1_SHIFT         (0U)
#define SYSCON_DICE_REG1_DICE_REG1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG1_DICE_REG1_SHIFT)) & SYSCON_DICE_REG1_DICE_REG1_MASK)
/*! @} */

/*! @name DICE_REG2 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG2_DICE_REG2_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG2_DICE_REG2_SHIFT         (0U)
#define SYSCON_DICE_REG2_DICE_REG2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG2_DICE_REG2_SHIFT)) & SYSCON_DICE_REG2_DICE_REG2_MASK)
/*! @} */

/*! @name DICE_REG3 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG3_DICE_REG3_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG3_DICE_REG3_SHIFT         (0U)
#define SYSCON_DICE_REG3_DICE_REG3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG3_DICE_REG3_SHIFT)) & SYSCON_DICE_REG3_DICE_REG3_MASK)
/*! @} */

/*! @name DICE_REG4 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG4_DICE_REG4_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG4_DICE_REG4_SHIFT         (0U)
#define SYSCON_DICE_REG4_DICE_REG4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG4_DICE_REG4_SHIFT)) & SYSCON_DICE_REG4_DICE_REG4_MASK)
/*! @} */

/*! @name DICE_REG5 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG5_DICE_REG5_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG5_DICE_REG5_SHIFT         (0U)
#define SYSCON_DICE_REG5_DICE_REG5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG5_DICE_REG5_SHIFT)) & SYSCON_DICE_REG5_DICE_REG5_MASK)
/*! @} */

/*! @name DICE_REG6 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG6_DICE_REG6_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG6_DICE_REG6_SHIFT         (0U)
#define SYSCON_DICE_REG6_DICE_REG6(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG6_DICE_REG6_SHIFT)) & SYSCON_DICE_REG6_DICE_REG6_MASK)
/*! @} */

/*! @name DICE_REG7 - Composite Device Identifier */
/*! @{ */

#define SYSCON_DICE_REG7_DICE_REG7_MASK          (0xFFFFFFFFU)
#define SYSCON_DICE_REG7_DICE_REG7_SHIFT         (0U)
#define SYSCON_DICE_REG7_DICE_REG7(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DICE_REG7_DICE_REG7_SHIFT)) & SYSCON_DICE_REG7_DICE_REG7_MASK)
/*! @} */

/*! @name BOOT_SEED_REG0 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG0_BOOT_SEED_REG0_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG0_BOOT_SEED_REG0_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG0_BOOT_SEED_REG0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG0_BOOT_SEED_REG0_SHIFT)) & SYSCON_BOOT_SEED_REG0_BOOT_SEED_REG0_MASK)
/*! @} */

/*! @name BOOT_SEED_REG1 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG1_BOOT_SEED_REG1_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG1_BOOT_SEED_REG1_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG1_BOOT_SEED_REG1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG1_BOOT_SEED_REG1_SHIFT)) & SYSCON_BOOT_SEED_REG1_BOOT_SEED_REG1_MASK)
/*! @} */

/*! @name BOOT_SEED_REG2 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG2_BOOT_SEED_REG2_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG2_BOOT_SEED_REG2_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG2_BOOT_SEED_REG2(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG2_BOOT_SEED_REG2_SHIFT)) & SYSCON_BOOT_SEED_REG2_BOOT_SEED_REG2_MASK)
/*! @} */

/*! @name BOOT_SEED_REG3 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG3_BOOT_SEED_REG3_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG3_BOOT_SEED_REG3_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG3_BOOT_SEED_REG3(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG3_BOOT_SEED_REG3_SHIFT)) & SYSCON_BOOT_SEED_REG3_BOOT_SEED_REG3_MASK)
/*! @} */

/*! @name BOOT_SEED_REG4 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG4_BOOT_SEED_REG4_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG4_BOOT_SEED_REG4_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG4_BOOT_SEED_REG4(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG4_BOOT_SEED_REG4_SHIFT)) & SYSCON_BOOT_SEED_REG4_BOOT_SEED_REG4_MASK)
/*! @} */

/*! @name BOOT_SEED_REG5 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG5_BOOT_SEED_REG5_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG5_BOOT_SEED_REG5_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG5_BOOT_SEED_REG5(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG5_BOOT_SEED_REG5_SHIFT)) & SYSCON_BOOT_SEED_REG5_BOOT_SEED_REG5_MASK)
/*! @} */

/*! @name BOOT_SEED_REG6 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG6_BOOT_SEED_REG6_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG6_BOOT_SEED_REG6_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG6_BOOT_SEED_REG6(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG6_BOOT_SEED_REG6_SHIFT)) & SYSCON_BOOT_SEED_REG6_BOOT_SEED_REG6_MASK)
/*! @} */

/*! @name BOOT_SEED_REG7 - boot seed (256-bit random value) */
/*! @{ */

#define SYSCON_BOOT_SEED_REG7_BOOT_SEED_REG7_MASK (0xFFFFFFFFU)
#define SYSCON_BOOT_SEED_REG7_BOOT_SEED_REG7_SHIFT (0U)
#define SYSCON_BOOT_SEED_REG7_BOOT_SEED_REG7(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_SEED_REG7_BOOT_SEED_REG7_SHIFT)) & SYSCON_BOOT_SEED_REG7_BOOT_SEED_REG7_MASK)
/*! @} */

/*! @name HMAC_REG0 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG0_HMAC_REG0_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG0_HMAC_REG0_SHIFT         (0U)
#define SYSCON_HMAC_REG0_HMAC_REG0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG0_HMAC_REG0_SHIFT)) & SYSCON_HMAC_REG0_HMAC_REG0_MASK)
/*! @} */

/*! @name HMAC_REG1 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG1_HMAC_REG1_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG1_HMAC_REG1_SHIFT         (0U)
#define SYSCON_HMAC_REG1_HMAC_REG1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG1_HMAC_REG1_SHIFT)) & SYSCON_HMAC_REG1_HMAC_REG1_MASK)
/*! @} */

/*! @name HMAC_REG2 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG2_HMAC_REG2_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG2_HMAC_REG2_SHIFT         (0U)
#define SYSCON_HMAC_REG2_HMAC_REG2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG2_HMAC_REG2_SHIFT)) & SYSCON_HMAC_REG2_HMAC_REG2_MASK)
/*! @} */

/*! @name HMAC_REG3 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG3_HMAC_REG3_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG3_HMAC_REG3_SHIFT         (0U)
#define SYSCON_HMAC_REG3_HMAC_REG3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG3_HMAC_REG3_SHIFT)) & SYSCON_HMAC_REG3_HMAC_REG3_MASK)
/*! @} */

/*! @name HMAC_REG4 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG4_HMAC_REG4_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG4_HMAC_REG4_SHIFT         (0U)
#define SYSCON_HMAC_REG4_HMAC_REG4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG4_HMAC_REG4_SHIFT)) & SYSCON_HMAC_REG4_HMAC_REG4_MASK)
/*! @} */

/*! @name HMAC_REG5 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG5_HMAC_REG5_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG5_HMAC_REG5_SHIFT         (0U)
#define SYSCON_HMAC_REG5_HMAC_REG5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG5_HMAC_REG5_SHIFT)) & SYSCON_HMAC_REG5_HMAC_REG5_MASK)
/*! @} */

/*! @name HMAC_REG6 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG6_HMAC_REG6_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG6_HMAC_REG6_SHIFT         (0U)
#define SYSCON_HMAC_REG6_HMAC_REG6(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG6_HMAC_REG6_SHIFT)) & SYSCON_HMAC_REG6_HMAC_REG6_MASK)
/*! @} */

/*! @name HMAC_REG7 - HMAC */
/*! @{ */

#define SYSCON_HMAC_REG7_HMAC_REG7_MASK          (0xFFFFFFFFU)
#define SYSCON_HMAC_REG7_HMAC_REG7_SHIFT         (0U)
#define SYSCON_HMAC_REG7_HMAC_REG7(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_HMAC_REG7_HMAC_REG7_SHIFT)) & SYSCON_HMAC_REG7_HMAC_REG7_MASK)
/*! @} */

/*! @name BOOT_LOCK - Control write access to boot seed security registers. */
/*! @{ */

#define SYSCON_BOOT_LOCK_LOCK_BOOT_SEED_MASK     (0x1U)
#define SYSCON_BOOT_LOCK_LOCK_BOOT_SEED_SHIFT    (0U)
/*! LOCK_BOOT_SEED - Control write access to BOOT_SEED_REG registers.
 *  0b1..write access to all 8 registers BOOT_SEED_REG is locked. This register is write once.
 */
#define SYSCON_BOOT_LOCK_LOCK_BOOT_SEED(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_LOCK_LOCK_BOOT_SEED_SHIFT)) & SYSCON_BOOT_LOCK_LOCK_BOOT_SEED_MASK)

#define SYSCON_BOOT_LOCK_LOCK_HMAC_MASK          (0x2U)
#define SYSCON_BOOT_LOCK_LOCK_HMAC_SHIFT         (1U)
/*! LOCK_HMAC - Control write access to HMAC_REG registers.
 *  0b1..write access to all 8 registers HMAC_REG is locked. This register is write once.
 */
#define SYSCON_BOOT_LOCK_LOCK_HMAC(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_BOOT_LOCK_LOCK_HMAC_SHIFT)) & SYSCON_BOOT_LOCK_LOCK_HMAC_MASK)
/*! @} */

/*! @name CSS_AS_CFG0 - CSS AS configuration */
/*! @{ */

#define SYSCON_CSS_AS_CFG0_CFG_CWDT_ENABLED_MASK (0x2000U)
#define SYSCON_CSS_AS_CFG0_CFG_CWDT_ENABLED_SHIFT (13U)
/*! CFG_CWDT_ENABLED - When Code Watchdog Timer is activated, this bit indicates state 1. */
#define SYSCON_CSS_AS_CFG0_CFG_CWDT_ENABLED(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_CSS_AS_CFG0_CFG_CWDT_ENABLED_SHIFT)) & SYSCON_CSS_AS_CFG0_CFG_CWDT_ENABLED_MASK)
/*! @} */

/*! @name CLOCK_CTRL - Various system clock controls : Clocks to Frequency Measures */
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
/*! ANA_FRO12M_CLK_ENA - Enable FRO 12MHz clock from the FRO 192MHz (excluding the PMC clock).
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK)

#define SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_MASK    (0x100U)
#define SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_SHIFT   (8U)
/*! XO_CAL_CLK_ENA - Enable clock for cristal oscilator calibration.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_XO_CAL_CLK_ENA_MASK)

#define SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_MASK (0x200U)
#define SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_SHIFT (9U)
/*! PLU_DEGLITCH_CLK_ENA - Enable clocks FRO_1MHz and FRO_12MHz for PLU deglitching.
 *  0b0..The clock is not enabled.
 *  0b1..The clock is enabled.
 */
#define SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_SHIFT)) & SYSCON_CLOCK_CTRL_PLU_DEGLITCH_CLK_ENA_MASK)
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

#define SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL_MASK (0x2U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL_SHIFT (1U)
/*! RAMX_CTRL - Control automatic clock gating of RAMX controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL_MASK (0x4U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL_SHIFT (2U)
/*! RAM0_CTRL - Control automatic clock gating of RAM0 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL_MASK (0x8U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL_SHIFT (3U)
/*! RAM1_CTRL - Control automatic clock gating of RAM1 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL_MASK (0x10U)
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL_SHIFT (4U)
/*! RAM2_CTRL - Control automatic clock gating of RAM2 controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL_MASK)

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

#define SYSCON_AUTOCLKGATEOVERRIDE_FLASH_MASK    (0x200U)
#define SYSCON_AUTOCLKGATEOVERRIDE_FLASH_SHIFT   (9U)
/*! FLASH - Control automatic clock gating of FLASH controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_FLASH(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_FLASH_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_FLASH_MASK)

#define SYSCON_AUTOCLKGATEOVERRIDE_FMC_MASK      (0x400U)
#define SYSCON_AUTOCLKGATEOVERRIDE_FMC_SHIFT     (10U)
/*! FMC - Control automatic clock gating of FMC controller.
 *  0b0..Automatic clock gating is not overridden.
 *  0b1..Automatic clock gating is overridden (Clock gating is disabled).
 */
#define SYSCON_AUTOCLKGATEOVERRIDE_FMC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AUTOCLKGATEOVERRIDE_FMC_SHIFT)) & SYSCON_AUTOCLKGATEOVERRIDE_FMC_MASK)

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

/*! @name GPIOPSYNC - Enable bypass of the first stage of synchonization inside GPIO_INT module */
/*! @{ */

#define SYSCON_GPIOPSYNC_PSYNC_MASK              (0x1U)
#define SYSCON_GPIOPSYNC_PSYNC_SHIFT             (0U)
/*! PSYNC - Enable bypass of the first stage of synchonization inside GPIO_INT module.
 *  0b0..use the first stage of synchonization inside GPIO_INT module.
 *  0b1..bypass of the first stage of synchonization inside GPIO_INT module.
 */
#define SYSCON_GPIOPSYNC_PSYNC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_GPIOPSYNC_PSYNC_SHIFT)) & SYSCON_GPIOPSYNC_PSYNC_MASK)
/*! @} */

/*! @name INVERTMAINCLK - Invert Main clock */
/*! @{ */

#define SYSCON_INVERTMAINCLK_INVERT_MASK         (0x1U)
#define SYSCON_INVERTMAINCLK_INVERT_SHIFT        (0U)
/*! INVERT - Invert main_clock (AHB system clock). */
#define SYSCON_INVERTMAINCLK_INVERT(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_INVERTMAINCLK_INVERT_SHIFT)) & SYSCON_INVERTMAINCLK_INVERT_MASK)
/*! @} */

/*! @name HASHRESTHWKEY - Controls whether the HASH AES hardware secret key is restricted to use by secure code */
/*! @{ */

#define SYSCON_HASHRESTHWKEY_UNLOCKCODE_MASK     (0xFFFFFFFFU)
#define SYSCON_HASHRESTHWKEY_UNLOCKCODE_SHIFT    (0U)
/*! UNLOCKCODE - Code value that controls whether HASH AES hardware secret key is unlocked
 *  0b11000011001111001010010101011010..HASH AES hardware secret key is unlocked for use by non-secure code. Any
 *                                      other value means that the hardware secret key is restricted to use by
 *                                      secure code only.
 */
#define SYSCON_HASHRESTHWKEY_UNLOCKCODE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_HASHRESTHWKEY_UNLOCKCODE_SHIFT)) & SYSCON_HASHRESTHWKEY_UNLOCKCODE_MASK)
/*! @} */

/*! @name DEBUG_LOCK_EN - Write-once register to control write access to security registers. */
/*! @{ */

#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK       (0xFU)
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT      (0U)
/*! LOCK_ALL - Control write access to security registers.
 *  0b0000..Any other value than b1010: disable write access to all registers.
 *  0b1010..1010: Enable write access to all registers.
 */
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT)) & SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK)
/*! @} */

/*! @name DEBUG_FEATURES - Cortex debug features control. */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN_MASK    (0x3U)
#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT   (0U)
/*! CPU0_DBGEN - CPU0 Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_CPU0_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN_MASK    (0xCU)
#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT   (2U)
/*! CPU0_NIDEN - CPU0 Non Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_CPU0_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_MASK   (0x30U)
#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT  (4U)
/*! CPU0_SPIDEN - CPU0 Secure Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_CPU0_SPIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_MASK  (0xC0U)
#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 Secure Non Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CPU0_SPNIDEN_MASK)
/*! @} */

/*! @name DEBUG_FEATURES_DP - Cortex debug features control. (duplicate) */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK (0x3U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT (0U)
/*! CPU0_DBGEN - CPU0 (CPU0) Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK (0xCU)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT (2U)
/*! CPU0_NIDEN - CPU0 Non Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK (0x30U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT (4U)
/*! CPU0_SPIDEN - CPU0 Secure Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK (0xC0U)
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT (6U)
/*! CPU0_SPNIDEN - CPU0 Secure Non Invasive debug control:.
 *  0b01..Any other value than b10: invasive debug is disable.
 *  0b10..10: Invasive debug is enabled.
 */
#define SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK)
/*! @} */

/*! @name CODESECURITYPROTTEST - Security code to allow test (Design for Testability) access. */
/*! @{ */

#define SYSCON_CODESECURITYPROTTEST_SEC_CODE_MASK (0xFFFFFFFFU)
#define SYSCON_CODESECURITYPROTTEST_SEC_CODE_SHIFT (0U)
/*! SEC_CODE - Security code to allow test access : 0x12345678.
 *  0b00000000000000000000000000000000..test access is not allowed.
 *  0b00010010001101000101011001111000..Security code to allow test access.
 */
#define SYSCON_CODESECURITYPROTTEST_SEC_CODE(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CODESECURITYPROTTEST_SEC_CODE_SHIFT)) & SYSCON_CODESECURITYPROTTEST_SEC_CODE_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU0 - This register is used by ROM during DEBUG authentication mechanism to enable debug access port for CPU0. */
/*! @{ */

#define SYSCON_SWD_ACCESS_CPU0_SEC_CODE_MASK     (0xFFFFFFFFU)
#define SYSCON_SWD_ACCESS_CPU0_SEC_CODE_SHIFT    (0U)
/*! SEC_CODE - CPU0 SWD-AP: 0x12345678.
 *  0b00000000000000000000000000000000..CPU0 DAP is not allowed. Reading back register will be read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable CPU0 SWD access. Reading back register will be read as 0xA.
 */
#define SYSCON_SWD_ACCESS_CPU0_SEC_CODE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ACCESS_CPU0_SEC_CODE_SHIFT)) & SYSCON_SWD_ACCESS_CPU0_SEC_CODE_MASK)
/*! @} */

/*! @name KEY_BLOCK - block quiddikey/PUF all index. */
/*! @{ */

#define SYSCON_KEY_BLOCK_KEY_BLOCK_MASK          (0xFFFFFFFFU)
#define SYSCON_KEY_BLOCK_KEY_BLOCK_SHIFT         (0U)
/*! KEY_BLOCK - Write a value to block quiddikey/PUF all index. */
#define SYSCON_KEY_BLOCK_KEY_BLOCK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_KEY_BLOCK_KEY_BLOCK_SHIFT)) & SYSCON_KEY_BLOCK_KEY_BLOCK_MASK)
/*! @} */

/*! @name DEBUG_AUTH_BEACON - Debug authentication BEACON register */
/*! @{ */

#define SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK     (0xFFFFFFFFU)
#define SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT    (0U)
/*! BEACON - Set by the debug authentication code in ROM to pass the debug beacons (Credential
 *    Beacon and Authentication Beacon) to application code.
 */
#define SYSCON_DEBUG_AUTH_BEACON_BEACON(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT)) & SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK)
/*! @} */

/*! @name FLASHSIZECFG - Flash size configuration */
/*! @{ */

#define SYSCON_FLASHSIZECFG_FLASHSIZE_MASK       (0x1FFU)
#define SYSCON_FLASHSIZECFG_FLASHSIZE_SHIFT      (0U)
/*! FLASHSIZE - Flash_size.
 *  0b000000000..0KB when 9'b000000000.
 *  0b000000001..0KB when 9'b000000001.
 *  0b000000010..256KB when 9'b000000010.
 *  0b000000011..256KB when 9'b000000011.
 *  0b000000100..512KB when 9'b000000100.
 *  0b000000101..512KB when 9'b000000101.
 *  0b000000110..768KB when 9'b000000110.
 *  0b000000111..768KB when 9'b000000111.
 *  0b111111111..1016KB when others.
 */
#define SYSCON_FLASHSIZECFG_FLASHSIZE(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHSIZECFG_FLASHSIZE_SHIFT)) & SYSCON_FLASHSIZECFG_FLASHSIZE_MASK)

#define SYSCON_FLASHSIZECFG_FLASHSTART_MASK      (0x200U)
#define SYSCON_FLASHSIZECFG_FLASHSTART_SHIFT     (9U)
/*! FLASHSTART - Flash start address.
 *  0b0..No private flash space in the main flash array
 *  0b1..Private flash start 8kB before last address.
 */
#define SYSCON_FLASHSIZECFG_FLASHSTART(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASHSIZECFG_FLASHSTART_SHIFT)) & SYSCON_FLASHSIZECFG_FLASHSTART_MASK)
/*! @} */

/*! @name CONFIGLOCKOUT - Disable write access to FLASHSIZECFG, SRAMSIZECFG, CPUCFG. */
/*! @{ */

#define SYSCON_CONFIGLOCKOUT_LOCK_MASK           (0x1U)
#define SYSCON_CONFIGLOCKOUT_LOCK_SHIFT          (0U)
/*! LOCK - Disable write access to FLASHSIZECFG, SRAMSIZECFG and PERIPHENCFG
 *  0b0..Enable write access to FLASHSIZECFG, SRAMSIZECFG and PERIPHENCFG
 *  0b1..Disable write access to FLASHSIZECFG, SRAMSIZECFG and PERIPHENCFG
 */
#define SYSCON_CONFIGLOCKOUT_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CONFIGLOCKOUT_LOCK_SHIFT)) & SYSCON_CONFIGLOCKOUT_LOCK_MASK)

#define SYSCON_CONFIGLOCKOUT_FLASHBANK0_LOCK_MASK (0x4U)
#define SYSCON_CONFIGLOCKOUT_FLASHBANK0_LOCK_SHIFT (2U)
/*! FLASHBANK0_LOCK - Disable write access to the BANK0 field in the FLASHBANKENABLE register.
 *  0b0..Enable write access to the BANK0 field in the FLASHBANKENABLE register.
 *  0b1..Disable write access to the BANK0 field in the FLASHBANKENABLE register.
 */
#define SYSCON_CONFIGLOCKOUT_FLASHBANK0_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CONFIGLOCKOUT_FLASHBANK0_LOCK_SHIFT)) & SYSCON_CONFIGLOCKOUT_FLASHBANK0_LOCK_MASK)

#define SYSCON_CONFIGLOCKOUT_FLASHBANK1_LOCK_MASK (0x8U)
#define SYSCON_CONFIGLOCKOUT_FLASHBANK1_LOCK_SHIFT (3U)
/*! FLASHBANK1_LOCK - Disable write access to the BANK1 field in the FLASHBANKENABLE register.
 *  0b0..Enable write access to the BANK1 field in the FLASHBANKENABLE register.
 *  0b1..Disable write access to the BANK1 field in the FLASHBANKENABLE register.
 */
#define SYSCON_CONFIGLOCKOUT_FLASHBANK1_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CONFIGLOCKOUT_FLASHBANK1_LOCK_SHIFT)) & SYSCON_CONFIGLOCKOUT_FLASHBANK1_LOCK_MASK)

#define SYSCON_CONFIGLOCKOUT_FLASHBANK2_LOCK_MASK (0x10U)
#define SYSCON_CONFIGLOCKOUT_FLASHBANK2_LOCK_SHIFT (4U)
/*! FLASHBANK2_LOCK - Disable write access to the BANK2 field in the FLASHBANKENABLE register.
 *  0b0..Enable write access to the BANK2 field in the FLASHBANKENABLE register.
 *  0b1..Disable write access to the BANK2 field in the FLASHBANKENABLE register.
 */
#define SYSCON_CONFIGLOCKOUT_FLASHBANK2_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CONFIGLOCKOUT_FLASHBANK2_LOCK_SHIFT)) & SYSCON_CONFIGLOCKOUT_FLASHBANK2_LOCK_MASK)

#define SYSCON_CONFIGLOCKOUT_FLASHBANK3_LOCK_MASK (0x20U)
#define SYSCON_CONFIGLOCKOUT_FLASHBANK3_LOCK_SHIFT (5U)
/*! FLASHBANK3_LOCK - Disable write access to the BANK3 field in the FLASHBANKENABLE register.
 *  0b0..Enable write access to the BANK3 field in the FLASHBANKENABLE register.
 *  0b1..Disable write access to the BANK3 field in the FLASHBANKENABLE register.
 */
#define SYSCON_CONFIGLOCKOUT_FLASHBANK3_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_CONFIGLOCKOUT_FLASHBANK3_LOCK_SHIFT)) & SYSCON_CONFIGLOCKOUT_FLASHBANK3_LOCK_MASK)
/*! @} */

/*! @name RAMSIZECFG - RAM size */
/*! @{ */

#define SYSCON_RAMSIZECFG_RAMX_SIZE_MASK         (0x3U)
#define SYSCON_RAMSIZECFG_RAMX_SIZE_SHIFT        (0U)
/*! RAMX_SIZE - RAMX size:.
 *  0b00..RAMX size is 0 KByte.
 *  0b01..RAMX size is 8 KByte.
 *  0b11..RAMX size is 16 KByte. (same for value 0b10)
 */
#define SYSCON_RAMSIZECFG_RAMX_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_RAMSIZECFG_RAMX_SIZE_SHIFT)) & SYSCON_RAMSIZECFG_RAMX_SIZE_MASK)

#define SYSCON_RAMSIZECFG_RAM0_SIZE_MASK         (0xCU)
#define SYSCON_RAMSIZECFG_RAM0_SIZE_SHIFT        (2U)
/*! RAM0_SIZE - RAM0 size:.
 *  0b00..RAM0 size is 0 KByte.
 *  0b01..RAM0 size is 8 Kbyte.
 *  0b11..RAM0 size is 16 Kbyte. (same for value 0b10)
 */
#define SYSCON_RAMSIZECFG_RAM0_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_RAMSIZECFG_RAM0_SIZE_SHIFT)) & SYSCON_RAMSIZECFG_RAM0_SIZE_MASK)

#define SYSCON_RAMSIZECFG_RAM1_SIZE_MASK         (0x30U)
#define SYSCON_RAMSIZECFG_RAM1_SIZE_SHIFT        (4U)
/*! RAM1_SIZE - RAM1 size:.
 *  0b00..RAM1 size is 0 KByte.
 *  0b01..RAM1 size is 16 Kbyte.
 *  0b11..RAM1 size is 32 Kbyte. (same for value 0b10)
 */
#define SYSCON_RAMSIZECFG_RAM1_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_RAMSIZECFG_RAM1_SIZE_SHIFT)) & SYSCON_RAMSIZECFG_RAM1_SIZE_MASK)

#define SYSCON_RAMSIZECFG_RAM2_SIZE_MASK         (0xC0U)
#define SYSCON_RAMSIZECFG_RAM2_SIZE_SHIFT        (6U)
/*! RAM2_SIZE - RAM2 size:.
 *  0b00..RAM2 size is 0 KByte.
 *  0b01..RAM2 size is 16 Kbyte.
 *  0b10..RAM2 size is 32 Kbyte.
 *  0b11..RAM2 size is 64 Kbyte.
 */
#define SYSCON_RAMSIZECFG_RAM2_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_RAMSIZECFG_RAM2_SIZE_SHIFT)) & SYSCON_RAMSIZECFG_RAM2_SIZE_MASK)
/*! @} */

/*! @name PERIPHENCFG - Peripheral enable configuration */
/*! @{ */

#define SYSCON_PERIPHENCFG_SCTEN_MASK            (0x1U)
#define SYSCON_PERIPHENCFG_SCTEN_SHIFT           (0U)
/*! SCTEN - SCT enable.
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_SCTEN(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_SCTEN_SHIFT)) & SYSCON_PERIPHENCFG_SCTEN_MASK)

#define SYSCON_PERIPHENCFG_DMA1EN_MASK           (0x8U)
#define SYSCON_PERIPHENCFG_DMA1EN_SHIFT          (3U)
/*! DMA1EN - DMA1 enable.
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_DMA1EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_DMA1EN_SHIFT)) & SYSCON_PERIPHENCFG_DMA1EN_MASK)

#define SYSCON_PERIPHENCFG_PUFFEN_MASK           (0x40U)
#define SYSCON_PERIPHENCFG_PUFFEN_SHIFT          (6U)
/*! PUFFEN - Puff enable.
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_PUFFEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_PUFFEN_SHIFT)) & SYSCON_PERIPHENCFG_PUFFEN_MASK)

#define SYSCON_PERIPHENCFG_CASPEREN_MASK         (0x80U)
#define SYSCON_PERIPHENCFG_CASPEREN_SHIFT        (7U)
/*! CASPEREN - CASPER enable.
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_CASPEREN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_CASPEREN_SHIFT)) & SYSCON_PERIPHENCFG_CASPEREN_MASK)

#define SYSCON_PERIPHENCFG_EZHBEN_MASK           (0x200U)
#define SYSCON_PERIPHENCFG_EZHBEN_SHIFT          (9U)
/*! EZHBEN - EZH B enable.
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_EZHBEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_EZHBEN_SHIFT)) & SYSCON_PERIPHENCFG_EZHBEN_MASK)

#define SYSCON_PERIPHENCFG_GPIOEN_MASK           (0x800U)
#define SYSCON_PERIPHENCFG_GPIOEN_SHIFT          (11U)
/*! GPIOEN - Enable pins PIO0_5/6/7/8/9/10
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_GPIOEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_GPIOEN_SHIFT)) & SYSCON_PERIPHENCFG_GPIOEN_MASK)

#define SYSCON_PERIPHENCFG_HASHEN_MASK           (0x1000U)
#define SYSCON_PERIPHENCFG_HASHEN_SHIFT          (12U)
/*! HASHEN - HASH enable.
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_HASHEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_HASHEN_SHIFT)) & SYSCON_PERIPHENCFG_HASHEN_MASK)

#define SYSCON_PERIPHENCFG_SPIFIEN_MASK          (0x2000U)
#define SYSCON_PERIPHENCFG_SPIFIEN_SHIFT         (13U)
/*! SPIFIEN - Enable SPIFI
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_SPIFIEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_SPIFIEN_SHIFT)) & SYSCON_PERIPHENCFG_SPIFIEN_MASK)

#define SYSCON_PERIPHENCFG_PRINCEEN_MASK         (0x4000U)
#define SYSCON_PERIPHENCFG_PRINCEEN_SHIFT        (14U)
/*! PRINCEEN - PRINCE
 *  0b0..peripheral is disable.
 *  0b1..peripheral is enable.
 */
#define SYSCON_PERIPHENCFG_PRINCEEN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_PRINCEEN_SHIFT)) & SYSCON_PERIPHENCFG_PRINCEEN_MASK)

#define SYSCON_PERIPHENCFG_SWFRO_MASK            (0x8000U)
#define SYSCON_PERIPHENCFG_SWFRO_SHIFT           (15U)
/*! SWFRO - Spare bit available for boot ROM to select FRO mode. */
#define SYSCON_PERIPHENCFG_SWFRO(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PERIPHENCFG_SWFRO_SHIFT)) & SYSCON_PERIPHENCFG_SWFRO_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_PARTCONFIG_MASK        (0x7FU)
#define SYSCON_DEVICE_ID0_PARTCONFIG_SHIFT       (0U)
/*! PARTCONFIG - Device type number. (E.g : NHS5204 stored as 04 decimal) */
#define SYSCON_DEVICE_ID0_PARTCONFIG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_PARTCONFIG_SHIFT)) & SYSCON_DEVICE_ID0_PARTCONFIG_MASK)

#define SYSCON_DEVICE_ID0_DEVICE_TYPE_SEC_MASK   (0x80U)
#define SYSCON_DEVICE_ID0_DEVICE_TYPE_SEC_SHIFT  (7U)
/*! DEVICE_TYPE_SEC - Security device type */
#define SYSCON_DEVICE_ID0_DEVICE_TYPE_SEC(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_DEVICE_TYPE_SEC_SHIFT)) & SYSCON_DEVICE_ID0_DEVICE_TYPE_SEC_MASK)

#define SYSCON_DEVICE_ID0_SRAM_SIZE_MASK         (0xF00U)
#define SYSCON_DEVICE_ID0_SRAM_SIZE_SHIFT        (8U)
/*! SRAM_SIZE - SRAM size */
#define SYSCON_DEVICE_ID0_SRAM_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_SRAM_SIZE_SHIFT)) & SYSCON_DEVICE_ID0_SRAM_SIZE_MASK)

#define SYSCON_DEVICE_ID0_FLASH_SIZE_MASK        (0x7000U)
#define SYSCON_DEVICE_ID0_FLASH_SIZE_SHIFT       (12U)
/*! FLASH_SIZE - Flash size */
#define SYSCON_DEVICE_ID0_FLASH_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_FLASH_SIZE_SHIFT)) & SYSCON_DEVICE_ID0_FLASH_SIZE_MASK)

#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK     (0xF00000U)
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT    (20U)
/*! ROM_REV_MINOR - ROM revision. */
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT)) & SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK)

#define SYSCON_DEVICE_ID0_MODELNUM_EXTENTION_MASK (0x7000000U)
#define SYSCON_DEVICE_ID0_MODELNUM_EXTENTION_SHIFT (24U)
/*! MODELNUM_EXTENTION - Model number extention */
#define SYSCON_DEVICE_ID0_MODELNUM_EXTENTION(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_MODELNUM_EXTENTION_SHIFT)) & SYSCON_DEVICE_ID0_MODELNUM_EXTENTION_MASK)
/*! @} */

/*! @name DIEID - Chip revision ID and Number */
/*! @{ */

#define SYSCON_DIEID_REV_ID_MASK                 (0xFU)
#define SYSCON_DIEID_REV_ID_SHIFT                (0U)
/*! REV_ID - Chip Metal Revision ID. */
#define SYSCON_DIEID_REV_ID(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_REV_ID_SHIFT)) & SYSCON_DIEID_REV_ID_MASK)

#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK      (0xFFFFF0U)
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT     (4U)
/*! MCO_NUM_IN_DIE_ID - Chip Number 0x426B. */
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT)) & SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK)
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

