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

/** SYSCON - Register Layout Typedef */
typedef struct {
  __IO uint32_t MEMORYREMAP;                       /**< Memory Remap control register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix priority control register Priority values are 3 = highest, 0 = lowest, offset: 0x10 */
       uint8_t RESERVED_1[36];
  __IO uint32_t CPU0STCKCAL;                       /**< System tick calibration for secure part of CPU0, offset: 0x38 */
  __IO uint32_t CPU0NSTCKCAL;                      /**< System tick calibration for non-secure part of CPU0, offset: 0x3C */
       uint8_t RESERVED_2[8];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
       uint8_t RESERVED_3[180];
  union {                                          /* offset: 0x100 */
    struct {                                         /* offset: 0x100 */
      __IO uint32_t PRESETCTRL0;                       /**< Peripheral reset control 0, offset: 0x100 */
      __IO uint32_t PRESETCTRL1;                       /**< Peripheral reset control 1, offset: 0x104 */
      __IO uint32_t PRESETCTRL2;                       /**< Peripheral reset control 2, offset: 0x108 */
    } PRESETCTRL;
    __IO uint32_t PRESETCTRLX[SYSCON_PRESETCTRL_PRESETCTRLX_PRESETCTRLX_COUNT];   /**< Peripheral reset control register, array offset: 0x100, array step: 0x4 */
  };
       uint8_t RESERVED_4[20];
  __IO uint32_t PRESETCTRLSET[SYSCON_PRESETCTRLSET_COUNT]; /**< Peripheral reset control set register, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_5[20];
  __IO uint32_t PRESETCTRLCLR[SYSCON_PRESETCTRLCLR_COUNT]; /**< Peripheral reset control clear register, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_6[20];
  __O  uint32_t SWR_RESET;                         /**< generate a software_reset, offset: 0x160 */
       uint8_t RESERVED_7[156];
  union {                                          /* offset: 0x200 */
    struct {                                         /* offset: 0x200 */
      __IO uint32_t AHBCLKCTRL0;                       /**< AHB Clock control 0, offset: 0x200 */
      __IO uint32_t AHBCLKCTRL1;                       /**< AHB Clock control 1, offset: 0x204 */
      __IO uint32_t AHBCLKCTRL2;                       /**< AHB Clock control 2, offset: 0x208 */
    } AHBCLKCTRL;
    __IO uint32_t AHBCLKCTRLX[SYSCON_AHBCLKCTRL_AHBCLKCTRLX_AHBCLKCTRLX_COUNT];   /**< Peripheral reset control register, array offset: 0x200, array step: 0x4 */
  };
       uint8_t RESERVED_8[20];
  __IO uint32_t AHBCLKCTRLSET[SYSCON_AHBCLKCTRLSET_COUNT]; /**< Peripheral reset control register, array offset: 0x220, array step: 0x4 */
       uint8_t RESERVED_9[20];
  __IO uint32_t AHBCLKCTRLCLR[SYSCON_AHBCLKCTRLCLR_COUNT]; /**< Peripheral reset control register, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_10[20];
  union {                                          /* offset: 0x260 */
    __IO uint32_t SYSTICKCLKSEL0;                    /**< System Tick Timer for CPU0 source select, offset: 0x260 */
    __IO uint32_t SYSTICKCLKSELX[SYSCON_SYSTICKCLKSEL_SYSTICKCLKSELX_SYSTICKCLKSELX_COUNT];   /**< System Tick Timer source select register, array offset: 0x260, array step: 0x4 */
  };
       uint8_t RESERVED_11[4];
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
       uint8_t RESERVED_12[36];
  union {                                          /* offset: 0x2B0 */
    struct {                                         /* offset: 0x2B0 */
      __IO uint32_t FCCLKSEL0;                         /**< Flexcomm Interface 0 clock source select for Fractional Rate Divider, offset: 0x2B0 */
      __IO uint32_t FCCLKSEL1;                         /**< Flexcomm Interface 1 clock source select for Fractional Rate Divider, offset: 0x2B4 */
      __IO uint32_t FCCLKSEL2;                         /**< Flexcomm Interface 2 clock source select for Fractional Rate Divider, offset: 0x2B8 */
    } FCCLKSEL;
    __IO uint32_t FCCLKSELX[SYSCON_FCCLKSEL_FCCLKSELX_FCCLKSELX_COUNT];   /**< Flexcomm clock source select register for Fractional Rate Divider, array offset: 0x2B0, array step: 0x4 */
  };
  __IO uint32_t SPIFICLKSEL;                       /**< QuadSPI Flash Interface clock source select, offset: 0x2D0 */
       uint8_t RESERVED_13[28];
  __IO uint32_t SCTCLKSEL;                         /**< SCTimer/PWM clock source select, offset: 0x2F0 */
       uint8_t RESERVED_14[12];
  __IO uint32_t SYSTICKCLKDIV0;                    /**< System Tick Timer divider for CPU0, offset: 0x300 */
       uint8_t RESERVED_15[4];
  __IO uint32_t TRACECLKDIV;                       /**< TRACE clock divider, offset: 0x308 */
       uint8_t RESERVED_16[20];
  union {                                          /* offset: 0x320 */
    struct {                                         /* offset: 0x320 */
      __IO uint32_t FLEXFRG0CTRL;                      /**< Fractional rate divider for flexcomm 0, offset: 0x320 */
      __IO uint32_t FLEXFRG1CTRL;                      /**< Fractional rate divider for flexcomm 1, offset: 0x324 */
      __IO uint32_t FLEXFRG2CTRL;                      /**< Fractional rate divider for flexcomm 2, offset: 0x328 */
    } FLEXFRGCTRL;
    __IO uint32_t FLEXFRGXCTRL[SYSCON_FLEXFRGCTRL_FLEXFRGXCTRL_FLEXFRGXCTRL_COUNT];   /**< Peripheral reset control register, array offset: 0x320, array step: 0x4 */
  };
       uint8_t RESERVED_17[64];
  __IO uint32_t AHBCLKDIV;                         /**< System clock divider, offset: 0x380 */
  __IO uint32_t CLKOUTDIV;                         /**< CLKOUT clock divider, offset: 0x384 */
  __IO uint32_t FROHFDIV;                          /**< FRO_HF (32MHz) clock divider, offset: 0x388 */
  __IO uint32_t WDTCLKDIV;                         /**< WDT clock divider, offset: 0x38C */
       uint8_t RESERVED_18[36];
  __IO uint32_t SCTCLKDIV;                         /**< SCT/PWM clock divider, offset: 0x3B4 */
       uint8_t RESERVED_19[24];
  __IO uint32_t SPIFICLKDIV;                       /**< QuadSPI Flash Interface Clock divider, offset: 0x3D0 */
       uint8_t RESERVED_20[40];
  __IO uint32_t CLOCKGENUPDATELOCKOUT;             /**< Control clock configuration registers access (like xxxDIV, xxxSEL), offset: 0x3FC */
       uint8_t RESERVED_21[64];
  __IO uint32_t FLASHREMAP_SIZE;                   /**< This 32-bit register contains the size of the image to remap, in bytes. The 12 LSBs are ignored, so the size granularity is 4KB., offset: 0x440 */
  __IO uint32_t FLASHREMAP_SIZE_DP;                /**< This 32-bit register is a duplicate of FLASHREMAPSIZE for increased security., offset: 0x444 */
  __IO uint32_t FLASHREMAP_OFFSET;                 /**< This 32-bit register contains the offset by which the image is to be remapped. The 12 LSBs are ignored, so the remap granularity is 4KB., offset: 0x448 */
  __IO uint32_t FLASHREMAP_OFFSET_DP;              /**< This 32-bit register is a duplicate of FLASHREMAPOFFSET for increased security., offset: 0x44C */
       uint8_t RESERVED_22[12];
  __IO uint32_t FLASHREMAP_LOCK;                   /**< Control write access to FLASHREMAP_SIZE and FLASHREMAP_OFFSET registers., offset: 0x45C */
       uint8_t RESERVED_23[16];
  __IO uint32_t CASPER_CTRL;                       /**< Control CASPER integration., offset: 0x470 */
       uint8_t RESERVED_24[656];
  __IO uint32_t FUNCRETENTIONCTRL;                 /**< Functional retention control register, offset: 0x704 */
       uint8_t RESERVED_25[260];
  __I  uint32_t CPSTAT;                            /**< CPU Status, offset: 0x80C */
       uint8_t RESERVED_26[272];
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
       uint8_t RESERVED_27[108];
  __I  uint32_t CSS_AS_CFG0;                       /**< CSS AS configuration, offset: 0x9D0 */
       uint8_t RESERVED_28[68];
  __IO uint32_t CLOCK_CTRL;                        /**< Various system clock controls : Clocks to Frequency Measures, offset: 0xA18 */
       uint8_t RESERVED_29[1000];
  __IO uint32_t AUTOCLKGATEOVERRIDE;               /**< Control automatic clock gating, offset: 0xE04 */
  __IO uint32_t GPIOPSYNC;                         /**< Enable bypass of the first stage of synchonization inside GPIO_INT module, offset: 0xE08 */
       uint8_t RESERVED_30[380];
  __IO uint32_t HASHRESTHWKEY;                     /**< Controls whether the HASH AES hardware secret key is restricted to use by secure code, offset: 0xF88 */
       uint8_t RESERVED_31[20];
  __IO uint32_t DEBUG_LOCK_EN;                     /**< Write-once register to control write access to security registers., offset: 0xFA0 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex debug features control., offset: 0xFA4 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex debug features control. (duplicate), offset: 0xFA8 */
       uint8_t RESERVED_32[8];
  __IO uint32_t SWD_ACCESS_CPU0;                   /**< This register is used by ROM during DEBUG authentication mechanism to enable debug access port for CPU0., offset: 0xFB4 */
       uint8_t RESERVED_33[4];
  __O  uint32_t KEY_BLOCK;                         /**< block quiddikey/PUF all index., offset: 0xFBC */
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug authentication BEACON register, offset: 0xFC0 */
       uint8_t RESERVED_34[52];
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

#define SYSCON_AHBMATPRIO_PRI_HASH_AES_MASK      (0x30000U)
#define SYSCON_AHBMATPRIO_PRI_HASH_AES_SHIFT     (16U)
/*! PRI_HASH_AES - HASH_AES. */
#define SYSCON_AHBMATPRIO_PRI_HASH_AES(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_HASH_AES_SHIFT)) & SYSCON_AHBMATPRIO_PRI_HASH_AES_MASK)
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
 *  0b100..Reserved.
 *  0b101..Reserved.
 *  0b110..Reserved.
 *  0b111..Reserved.
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

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK     (0xF00000U)
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT    (20U)
/*! ROM_REV_MINOR - ROM revision. */
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT)) & SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK)
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

