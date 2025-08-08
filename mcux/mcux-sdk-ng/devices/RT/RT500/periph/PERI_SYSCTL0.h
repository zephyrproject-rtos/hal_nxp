/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCTL0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCTL0.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCTL0
 *
 * CMSIS Peripheral Access Layer for SYSCTL0
 */

#if !defined(PERI_SYSCTL0_H_)
#define PERI_SYSCTL0_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SYSCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL0_Peripheral_Access_Layer SYSCTL0 Peripheral Access Layer
 * @{
 */

/** SYSCTL0 - Size of Registers Arrays */
#define SYSCTL0_AHBBRIDGEBUFFERN_COUNT            2u
#define SYSCTL0_BOOTSTATESEED_COUNT               8u
#define SYSCTL0_BOOTSTATEHMAC_COUNT               8u
#define SYSCTL0_UUID_COUNT                        4u

/** SYSCTL0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t DSP_VECT_REMAP;                    /**< DSP Vector Remap, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DSPSTALL;                          /**< DSP Stall Control, offset: 0xC */
  __IO uint32_t AHBMATRIXPRIOR;                    /**< AHB MAX Priority, offset: 0x10 */
       uint8_t RESERVED_2[12];
  __IO uint32_t AHBBRIDGEBUFFER[SYSCTL0_AHBBRIDGEBUFFERN_COUNT]; /**< AHB Buffer, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_3[4];
  __IO uint32_t BOOTROM_LCKOUT;                    /**< BOOT ROM lockout, offset: 0x2C */
  __IO uint32_t M33NMISRCSEL;                      /**< M33 NMI source selection, offset: 0x30 */
  __IO uint32_t SYSTEM_STICK_CALIB;                /**< System secure tick calibration, offset: 0x34 */
  __IO uint32_t SYSTEM_NSTICK_CALIB;               /**< System non-secure tick calibration, offset: 0x38 */
       uint8_t RESERVED_4[36];
  __IO uint32_t PRODUCT_ID;                        /**< Product ID, offset: 0x60 */
  __I  uint32_t SILICONREV_ID;                     /**< Silicon Revision ID, offset: 0x64 */
  __I  uint32_t JTAG_ID;                           /**< JTAG ID, offset: 0x68 */
       uint8_t RESERVED_5[4];
  __IO uint32_t NSGPIO_PSYNC;                      /**< Non-secure GPIO PSYNC, offset: 0x70 */
  __IO uint32_t SGPIO_PSYNC;                       /**< Secure GPIO PSYNC, offset: 0x74 */
       uint8_t RESERVED_6[8];
  __IO uint32_t AUTOCLKGATEOVERRIDE0;              /**< Auto clock gate override 0, offset: 0x80 */
  __IO uint32_t AUTOCLKGATEOVERRIDE1;              /**< Auto clock gate override 1, offset: 0x84 */
       uint8_t RESERVED_7[24];
  __IO uint32_t CLKGATEOVERRIDE0;                  /**< Clock gate override 0, offset: 0xA0 */
       uint8_t RESERVED_8[88];
  __IO uint32_t AHB_SRAM_ACCESS_DISABLE;           /**< AHB SRAM access disable, offset: 0xFC */
  __IO uint32_t AXI_SRAM_ACCESS_DISABLE;           /**< AXI SRAM access disable, offset: 0x100 */
  __IO uint32_t DSP_SRAM_ACCESS_DISABLE;           /**< DSP SRAM access disable, offset: 0x104 */
       uint8_t RESERVED_9[8];
  __IO uint32_t PQ_MEM_CTRL;                       /**< Power-Quad Memory Control, offset: 0x110 */
  __IO uint32_t FLEXSPI0_MEM_CTRL;                 /**< FlexSPI0 Memory Control, offset: 0x114 */
  __IO uint32_t USBHS_MEM_CTRL;                    /**< USBHS Memory Control, offset: 0x118 */
  __IO uint32_t USDHC0_MEM_CTRL;                   /**< USDHC0 Memory Control, offset: 0x11C */
  __IO uint32_t USDHC1_MEM_CTRL;                   /**< USDHC1 Memory Control, offset: 0x120 */
  __IO uint32_t CASPER_MEM_CTRL;                   /**< CASPER Memory Control, offset: 0x124 */
  __IO uint32_t ROM_MEM_CTRL;                      /**< ROM Memory Control, offset: 0x128 */
  __IO uint32_t FLEXSPI1_MEM_CTRL;                 /**< FlexSPI1 Memory Control, offset: 0x12C */
  __IO uint32_t GPU_MEM_CTRL;                      /**< GPU Memory Control, offset: 0x130 */
  __IO uint32_t MIPI_MEM_CTRL;                     /**< MIPI Memory Control, offset: 0x134 */
  __IO uint32_t DCN_MEM_CTRL;                      /**< LCDIF Memory Control, offset: 0x138 */
  __IO uint32_t SMARTDMA_MEM_CTRL;                 /**< SMARTDMA Memory Control, offset: 0x13C */
       uint8_t RESERVED_10[704];
  __IO uint32_t MIPI_DSI_CTRL;                     /**< MIPI DSI Control, offset: 0x400 */
       uint8_t RESERVED_11[8];
  __IO uint32_t USB0CLKCTRL;                       /**< USB Clock Control, offset: 0x40C */
  __I  uint32_t USB0CLKSTAT;                       /**< USB Clock Status, offset: 0x410 */
  __IO uint32_t USBPHYPLL0LOCKTIMEDIV2;            /**< USB PHY PLL0 lock time division, offset: 0x414 */
       uint8_t RESERVED_12[488];
  __IO uint32_t PDSLEEPCFG0;                       /**< Sleep configuration 0, offset: 0x600 */
  __IO uint32_t PDSLEEPCFG1;                       /**< Sleep configuration 1, offset: 0x604 */
  __IO uint32_t PDSLEEPCFG2;                       /**< Sleep configuration 2, offset: 0x608 */
  __IO uint32_t PDSLEEPCFG3;                       /**< Sleep configuration 3, offset: 0x60C */
  __IO uint32_t PDRUNCFG0;                         /**< Run configuration 0, offset: 0x610 */
  __IO uint32_t PDRUNCFG1;                         /**< Run configuration 1, offset: 0x614 */
  __IO uint32_t PDRUNCFG2;                         /**< Run configuration 2, offset: 0x618 */
  __IO uint32_t PDRUNCFG3;                         /**< Run configuration 3, offset: 0x61C */
  __O  uint32_t PDRUNCFG0_SET;                     /**< Run configuration 0 set, offset: 0x620 */
  __O  uint32_t PDRUNCFG1_SET;                     /**< Run configuration 1 set, offset: 0x624 */
  __O  uint32_t PDRUNCFG2_SET;                     /**< Run configuration 2 set, offset: 0x628 */
  __O  uint32_t PDRUNCFG3_SET;                     /**< Run configuration 3 set, offset: 0x62C */
  __O  uint32_t PDRUNCFG0_CLR;                     /**< Run configuration 0 clear, offset: 0x630 */
  __O  uint32_t PDRUNCFG1_CLR;                     /**< Run configuration 1 clear, offset: 0x634 */
  __IO uint32_t PDRUNCFG2_CLR;                     /**< Run configuration 2 clear, offset: 0x638 */
  __IO uint32_t PDRUNCFG3_CLR;                     /**< Run configuration 3 clear, offset: 0x63C */
       uint8_t RESERVED_13[32];
  __IO uint32_t PDWAKECFG;                         /**< PD Wake Configuration, offset: 0x660 */
       uint8_t RESERVED_14[28];
  __IO uint32_t STARTEN0;                          /**< Start Enable 0, offset: 0x680 */
  __IO uint32_t STARTEN1;                          /**< Start Enable 1, offset: 0x684 */
  __IO uint32_t STARTEN2;                          /**< Start Enable 2, offset: 0x688 */
       uint8_t RESERVED_15[20];
  __IO uint32_t STARTEN0_SET;                      /**< Start Enable 0 Set, offset: 0x6A0 */
  __IO uint32_t STARTEN1_SET;                      /**< Start Enable 1 Set, offset: 0x6A4 */
  __IO uint32_t STARTEN2_SET;                      /**< Start Enable 2, offset: 0x6A8 */
       uint8_t RESERVED_16[20];
  __IO uint32_t STARTEN0_CLR;                      /**< Start Enable 0 clear, offset: 0x6C0 */
  __IO uint32_t STARTEN1_CLR;                      /**< Start Enable 1 clear, offset: 0x6C4 */
  __IO uint32_t STARTEN2_CLR;                      /**< Start Enable 2, offset: 0x6C8 */
       uint8_t RESERVED_17[56];
  __IO uint32_t FROSAFETY;                         /**< FRO Safety, offset: 0x704 */
       uint8_t RESERVED_18[8];
  __IO uint32_t MAINCLKSAFETY;                     /**< Main Clock Safety, offset: 0x710 */
       uint8_t RESERVED_19[108];
  __IO uint32_t HWWAKE;                            /**< Hardware Wake, offset: 0x780 */
       uint8_t RESERVED_20[1672];
  __IO uint32_t TEMPSENSORCTL;                     /**< Temperature Sensor Control, offset: 0xE0C */
       uint8_t RESERVED_21[48];
  __IO uint32_t BOOTSTATELOCK;                     /**< Boot State Lock, offset: 0xE40 */
       uint8_t RESERVED_22[12];
  __IO uint32_t BOOTSTATESEED[SYSCTL0_BOOTSTATESEED_COUNT]; /**< Boot State Seed, array offset: 0xE50, array step: 0x4 */
  __IO uint32_t BOOTSTATEHMAC[SYSCTL0_BOOTSTATEHMAC_COUNT]; /**< HMAC of boot state used for attestation., array offset: 0xE70, array step: 0x4 */
       uint8_t RESERVED_23[96];
  __IO uint32_t FLEXSPI0PADCTL;                    /**< FLEXSPI0 Pad Control, offset: 0xEF0 */
  __IO uint32_t FLEXSPI1PADCTL;                    /**< FLEXSPI1 Pad Control, offset: 0xEF4 */
  __IO uint32_t SDIO0PADCTL;                       /**< SDIO0 Pad Control, offset: 0xEF8 */
  __IO uint32_t SDIO1PADCTL;                       /**< SDIO1 Pad Control, offset: 0xEFC */
  __IO uint32_t DICEHWREGN;                        /**< Compound Device Identifier (CDI), offset: 0xF00 */
       uint8_t RESERVED_24[76];
  __IO uint32_t UUID[SYSCTL0_UUID_COUNT];          /**< UUID, array offset: 0xF50, array step: 0x4 */
       uint8_t RESERVED_25[32];
  __IO uint32_t AESKEY_SRCSEL;                     /**< AES Key Source Select, offset: 0xF80 */
  __IO uint32_t OTFADKEY_SRCSEL;                   /**< OTFAD Key Source Select, offset: 0xF84 */
  __IO uint32_t HASHHWKEYDISABLE;                  /**< HASH Hardware Key Disable, offset: 0xF88 */
       uint8_t RESERVED_26[20];
  __IO uint32_t DBG_LOCKEN;                        /**< Debug Lock Enable, offset: 0xFA0 */
  __IO uint32_t DBG_FEATURES;                      /**< Debug Features, offset: 0xFA4 */
  __IO uint32_t DBG_FEATURES_DP;                   /**< Debug Features Duplicate, offset: 0xFA8 */
       uint8_t RESERVED_27[8];
  __IO uint32_t CS_PROTCPU0;                       /**< Code Security for CPU0, offset: 0xFB4 */
  __IO uint32_t CS_PROTCPU1;                       /**< Code Security for CPU1, offset: 0xFB8 */
       uint8_t RESERVED_28[4];
  __IO uint32_t DBG_AUTH_SCRATCH;                  /**< Debug authorization scratch, offset: 0xFC0 */
       uint8_t RESERVED_29[12];
  __IO uint32_t KEY_BLOCK;                         /**< Key block, offset: 0xFD0 */
} SYSCTL0_Type;

/* ----------------------------------------------------------------------------
   -- SYSCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL0_Register_Masks SYSCTL0 Register Masks
 * @{
 */

/*! @name DSP_VECT_REMAP - DSP Vector Remap */
/*! @{ */

#define SYSCTL0_DSP_VECT_REMAP_DSP_VECT_REMAP_MASK (0xFFFU)
#define SYSCTL0_DSP_VECT_REMAP_DSP_VECT_REMAP_SHIFT (0U)
/*! DSP_VECT_REMAP - DSP_VECT_REMAP */
#define SYSCTL0_DSP_VECT_REMAP_DSP_VECT_REMAP(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_VECT_REMAP_DSP_VECT_REMAP_SHIFT)) & SYSCTL0_DSP_VECT_REMAP_DSP_VECT_REMAP_MASK)

#define SYSCTL0_DSP_VECT_REMAP_STATVECSELECT_MASK (0x1000U)
#define SYSCTL0_DSP_VECT_REMAP_STATVECSELECT_SHIFT (12U)
/*! STATVECSELECT - Static Vector Select
 *  0b0..Selects the primary static vector base address on Fusion DSP (0x0000_0000)
 *  0b1..Selects the alternate static vector base address on Fusion DSP (0x0040_0000)
 */
#define SYSCTL0_DSP_VECT_REMAP_STATVECSELECT(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_VECT_REMAP_STATVECSELECT_SHIFT)) & SYSCTL0_DSP_VECT_REMAP_STATVECSELECT_MASK)
/*! @} */

/*! @name DSPSTALL - DSP Stall Control */
/*! @{ */

#define SYSCTL0_DSPSTALL_DSPSTALL_MASK           (0x1U)
#define SYSCTL0_DSPSTALL_DSPSTALL_SHIFT          (0U)
/*! DSPSTALL - DSPSTALL
 *  0b0..Run(Normal mode)
 *  0b1..Stall mode
 */
#define SYSCTL0_DSPSTALL_DSPSTALL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSPSTALL_DSPSTALL_SHIFT)) & SYSCTL0_DSPSTALL_DSPSTALL_MASK)
/*! @} */

/*! @name AHBMATRIXPRIOR - AHB MAX Priority */
/*! @{ */

#define SYSCTL0_AHBMATRIXPRIOR_M0_MASK           (0x3U)
#define SYSCTL0_AHBMATRIXPRIOR_M0_SHIFT          (0U)
/*! M0 - Master 0 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M0_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M0_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M1_MASK           (0xCU)
#define SYSCTL0_AHBMATRIXPRIOR_M1_SHIFT          (2U)
/*! M1 - Master 1 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M1_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M1_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M2_MASK           (0x30U)
#define SYSCTL0_AHBMATRIXPRIOR_M2_SHIFT          (4U)
/*! M2 - Master 2 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M2_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M2_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M3_MASK           (0xC0U)
#define SYSCTL0_AHBMATRIXPRIOR_M3_SHIFT          (6U)
/*! M3 - Master 3 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M3_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M3_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M4_MASK           (0x300U)
#define SYSCTL0_AHBMATRIXPRIOR_M4_SHIFT          (8U)
/*! M4 - Master 4 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M4(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M4_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M4_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M5_MASK           (0xC00U)
#define SYSCTL0_AHBMATRIXPRIOR_M5_SHIFT          (10U)
/*! M5 - Master 5 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M5(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M5_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M5_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M6_MASK           (0x3000U)
#define SYSCTL0_AHBMATRIXPRIOR_M6_SHIFT          (12U)
/*! M6 - Master 6 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M6(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M6_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M6_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M7_MASK           (0xC000U)
#define SYSCTL0_AHBMATRIXPRIOR_M7_SHIFT          (14U)
/*! M7 - Master 7 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M7(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M7_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M7_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M8_MASK           (0x30000U)
#define SYSCTL0_AHBMATRIXPRIOR_M8_SHIFT          (16U)
/*! M8 - Master 8 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M8(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M8_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M8_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M9_MASK           (0xC0000U)
#define SYSCTL0_AHBMATRIXPRIOR_M9_SHIFT          (18U)
/*! M9 - Master 9 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M9(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M9_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M9_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M10_MASK          (0x300000U)
#define SYSCTL0_AHBMATRIXPRIOR_M10_SHIFT         (20U)
/*! M10 - Master 10 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M10(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M10_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M10_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M11_MASK          (0xC00000U)
#define SYSCTL0_AHBMATRIXPRIOR_M11_SHIFT         (22U)
/*! M11 - Master 10 Priority */
#define SYSCTL0_AHBMATRIXPRIOR_M11(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M11_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M11_MASK)
/*! @} */

/*! @name AHBBRIDGEBUFFER - AHB Buffer */
/*! @{ */

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE0_MASK      (0x1U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE0_SHIFT     (0U)
/*! SLAVE0 - SLAVE0 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE0_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE0_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE1_MASK      (0x2U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE1_SHIFT     (1U)
/*! SLAVE1 - SLAVE1 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE1_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE1_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE2_MASK      (0x4U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE2_SHIFT     (2U)
/*! SLAVE2 - SLAVE2 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE2(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE2_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE2_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE3_MASK      (0x8U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE3_SHIFT     (3U)
/*! SLAVE3 - SLAVE3 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE3(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE3_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE3_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE4_MASK      (0x10U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE4_SHIFT     (4U)
/*! SLAVE4 - SLAVE4 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE4(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE4_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE4_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE5_MASK      (0x20U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE5_SHIFT     (5U)
/*! SLAVE5 - SLAVE5 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE5(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE5_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE5_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE6_MASK      (0x40U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE6_SHIFT     (6U)
/*! SLAVE6 - SLAVE6 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE6(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE6_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE6_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE7_MASK      (0x80U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE7_SHIFT     (7U)
/*! SLAVE7 - SLAVE7 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE7(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE7_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE7_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE8_MASK      (0x100U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE8_SHIFT     (8U)
/*! SLAVE8 - SLAVE8 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE8(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE8_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE8_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE9_MASK      (0x200U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE9_SHIFT     (9U)
/*! SLAVE9 - SLAVE9 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE9(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE9_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE9_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE10_MASK     (0x400U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE10_SHIFT    (10U)
/*! SLAVE10 - SLAVE10 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE10(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE10_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE10_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE11_MASK     (0x800U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE11_SHIFT    (11U)
/*! SLAVE11 - SLAVE11 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE11(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE11_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE11_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE12_MASK     (0x1000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE12_SHIFT    (12U)
/*! SLAVE12 - SLAVE12 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE12(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE12_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE12_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE13_MASK     (0x2000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE13_SHIFT    (13U)
/*! SLAVE13 - SLAVE13 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE13(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE13_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE13_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE14_MASK     (0x4000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE14_SHIFT    (14U)
/*! SLAVE14 - SLAVE14 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE14(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE14_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE14_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE15_MASK     (0x8000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE15_SHIFT    (15U)
/*! SLAVE15 - SLAVE15 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE15(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE15_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE15_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE16_MASK     (0x10000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE16_SHIFT    (16U)
/*! SLAVE16 - SLAVE16 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE16(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE16_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE16_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE17_MASK     (0x20000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE17_SHIFT    (17U)
/*! SLAVE17 - SLAVE17 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE17(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE17_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE17_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE18_MASK     (0x40000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE18_SHIFT    (18U)
/*! SLAVE18 - SLAVE18 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE18(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE18_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE18_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE19_MASK     (0x80000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE19_SHIFT    (19U)
/*! SLAVE19 - SLAVE19 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE19(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE19_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE19_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE20_MASK     (0x100000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE20_SHIFT    (20U)
/*! SLAVE20 - SLAVE20 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE20(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE20_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE20_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE21_MASK     (0x200000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE21_SHIFT    (21U)
/*! SLAVE21 - SLAVE21 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE21(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE21_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE21_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE22_MASK     (0x400000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE22_SHIFT    (22U)
/*! SLAVE22 - SLAVE22 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE22(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE22_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE22_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE23_MASK     (0x800000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE23_SHIFT    (23U)
/*! SLAVE23 - SLAVE23 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE23(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE23_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE23_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE24_MASK     (0x1000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE24_SHIFT    (24U)
/*! SLAVE24 - SLAVE24 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE24(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE24_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE24_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE25_MASK     (0x2000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE25_SHIFT    (25U)
/*! SLAVE25 - SLAVE25 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE25(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE25_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE25_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE26_MASK     (0x4000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE26_SHIFT    (26U)
/*! SLAVE26 - SLAVE26 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE26(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE26_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE26_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE27_MASK     (0x8000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE27_SHIFT    (27U)
/*! SLAVE27 - SLAVE27 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE27(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE27_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE27_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE28_MASK     (0x10000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE28_SHIFT    (28U)
/*! SLAVE28 - SLAVE28 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE28(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE28_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE28_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE29_MASK     (0x20000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE29_SHIFT    (29U)
/*! SLAVE29 - SLAVE29 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE29(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE29_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE29_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE30_MASK     (0x40000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE30_SHIFT    (30U)
/*! SLAVE30 - SLAVE30 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE30(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE30_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE30_MASK)

#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE31_MASK     (0x80000000U)
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE31_SHIFT    (31U)
/*! SLAVE31 - SLAVE31 buffering
 *  0b0..No Buffering
 *  0b1..Buffering
 */
#define SYSCTL0_AHBBRIDGEBUFFER_SLAVE31(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBBRIDGEBUFFER_SLAVE31_SHIFT)) & SYSCTL0_AHBBRIDGEBUFFER_SLAVE31_MASK)
/*! @} */

/* The count of SYSCTL0_AHBBRIDGEBUFFER */
#define SYSCTL0_AHBBRIDGEBUFFER_COUNT            (2U)

/*! @name BOOTROM_LCKOUT - BOOT ROM lockout */
/*! @{ */

#define SYSCTL0_BOOTROM_LCKOUT_READ_LCKOUT_SPACE_MASK (0x1FFFFU)
#define SYSCTL0_BOOTROM_LCKOUT_READ_LCKOUT_SPACE_SHIFT (0U)
/*! READ_LCKOUT_SPACE - Read Lockout */
#define SYSCTL0_BOOTROM_LCKOUT_READ_LCKOUT_SPACE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTROM_LCKOUT_READ_LCKOUT_SPACE_SHIFT)) & SYSCTL0_BOOTROM_LCKOUT_READ_LCKOUT_SPACE_MASK)

#define SYSCTL0_BOOTROM_LCKOUT_WRITE_LOCK_MASK   (0xC0000000U)
#define SYSCTL0_BOOTROM_LCKOUT_WRITE_LOCK_SHIFT  (30U)
/*! WRITE_LOCK - Self Write Disable
 *  0b00..Write disable
 *  0b01..Write disable
 *  0b10..Write enable
 *  0b11..Write disable
 */
#define SYSCTL0_BOOTROM_LCKOUT_WRITE_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTROM_LCKOUT_WRITE_LOCK_SHIFT)) & SYSCTL0_BOOTROM_LCKOUT_WRITE_LOCK_MASK)
/*! @} */

/*! @name M33NMISRCSEL - M33 NMI source selection */
/*! @{ */

#define SYSCTL0_M33NMISRCSEL_NMISRCSEL_MASK      (0x7FU)
#define SYSCTL0_M33NMISRCSEL_NMISRCSEL_SHIFT     (0U)
/*! NMISRCSEL - Selects one of the M33 interrupt sources as the NMI source interrupt. */
#define SYSCTL0_M33NMISRCSEL_NMISRCSEL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_M33NMISRCSEL_NMISRCSEL_SHIFT)) & SYSCTL0_M33NMISRCSEL_NMISRCSEL_MASK)

#define SYSCTL0_M33NMISRCSEL_NMI_ENABLE_MASK     (0x80000000U)
#define SYSCTL0_M33NMISRCSEL_NMI_ENABLE_SHIFT    (31U)
/*! NMI_Enable
 *  0b0..Disable NMI interrupt
 *  0b1..Enable NMI interrupt
 */
#define SYSCTL0_M33NMISRCSEL_NMI_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_M33NMISRCSEL_NMI_ENABLE_SHIFT)) & SYSCTL0_M33NMISRCSEL_NMI_ENABLE_MASK)
/*! @} */

/*! @name SYSTEM_STICK_CALIB - System secure tick calibration */
/*! @{ */

#define SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_MASK (0x7FFFFFFU)
#define SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_SHIFT (0U)
/*! SYSTEM_STICK_CALIB - M33 secure tick calibration */
#define SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_SHIFT)) & SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_MASK)
/*! @} */

/*! @name SYSTEM_NSTICK_CALIB - System non-secure tick calibration */
/*! @{ */

#define SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_MASK (0x7FFFFFFU)
#define SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_SHIFT (0U)
/*! SYSTEM_NSTICK_CALIB - M33 non secure tick calibration */
#define SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_SHIFT)) & SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_MASK)
/*! @} */

/*! @name PRODUCT_ID - Product ID */
/*! @{ */

#define SYSCTL0_PRODUCT_ID_PRODUCT_ID_MASK       (0xFFFFU)
#define SYSCTL0_PRODUCT_ID_PRODUCT_ID_SHIFT      (0U)
/*! PRODUCT_ID - PRODUCT ID */
#define SYSCTL0_PRODUCT_ID_PRODUCT_ID(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PRODUCT_ID_PRODUCT_ID_SHIFT)) & SYSCTL0_PRODUCT_ID_PRODUCT_ID_MASK)
/*! @} */

/*! @name SILICONREV_ID - Silicon Revision ID */
/*! @{ */

#define SYSCTL0_SILICONREV_ID_MINOR_MASK         (0xFU)
#define SYSCTL0_SILICONREV_ID_MINOR_SHIFT        (0U)
/*! MINOR - MINOR */
#define SYSCTL0_SILICONREV_ID_MINOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SILICONREV_ID_MINOR_SHIFT)) & SYSCTL0_SILICONREV_ID_MINOR_MASK)

#define SYSCTL0_SILICONREV_ID_MAJOR_MASK         (0xF0000U)
#define SYSCTL0_SILICONREV_ID_MAJOR_SHIFT        (16U)
/*! MAJOR - MAJOR */
#define SYSCTL0_SILICONREV_ID_MAJOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SILICONREV_ID_MAJOR_SHIFT)) & SYSCTL0_SILICONREV_ID_MAJOR_MASK)
/*! @} */

/*! @name JTAG_ID - JTAG ID */
/*! @{ */

#define SYSCTL0_JTAG_ID_FIXBIT_MASK              (0x1U)
#define SYSCTL0_JTAG_ID_FIXBIT_SHIFT             (0U)
/*! FIXBIT - JTAG ID fix bit. */
#define SYSCTL0_JTAG_ID_FIXBIT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_FIXBIT_SHIFT)) & SYSCTL0_JTAG_ID_FIXBIT_MASK)

#define SYSCTL0_JTAG_ID_MANU_MASK                (0xFFEU)
#define SYSCTL0_JTAG_ID_MANU_SHIFT               (1U)
/*! MANU - JTAG ID Manufacturer */
#define SYSCTL0_JTAG_ID_MANU(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_MANU_SHIFT)) & SYSCTL0_JTAG_ID_MANU_MASK)

#define SYSCTL0_JTAG_ID_PRODUCT_ID_MASK          (0xFFFF000U)
#define SYSCTL0_JTAG_ID_PRODUCT_ID_SHIFT         (12U)
/*! PRODUCT_ID - JTAG ID Product ID as defined in the Product ID register */
#define SYSCTL0_JTAG_ID_PRODUCT_ID(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_PRODUCT_ID_SHIFT)) & SYSCTL0_JTAG_ID_PRODUCT_ID_MASK)

#define SYSCTL0_JTAG_ID_CHIPREV_MASK             (0xF0000000U)
#define SYSCTL0_JTAG_ID_CHIPREV_SHIFT            (28U)
/*! CHIPREV - JTAG ID 4-Bit Chip Silicon Revision */
#define SYSCTL0_JTAG_ID_CHIPREV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_CHIPREV_SHIFT)) & SYSCTL0_JTAG_ID_CHIPREV_MASK)
/*! @} */

/*! @name NSGPIO_PSYNC - Non-secure GPIO PSYNC */
/*! @{ */

#define SYSCTL0_NSGPIO_PSYNC_PSYNC_MASK          (0x1U)
#define SYSCTL0_NSGPIO_PSYNC_PSYNC_SHIFT         (0U)
/*! PSYNC - Synchronization Stage Setting: */
#define SYSCTL0_NSGPIO_PSYNC_PSYNC(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_NSGPIO_PSYNC_PSYNC_SHIFT)) & SYSCTL0_NSGPIO_PSYNC_PSYNC_MASK)
/*! @} */

/*! @name SGPIO_PSYNC - Secure GPIO PSYNC */
/*! @{ */

#define SYSCTL0_SGPIO_PSYNC_PSYNC_MASK           (0x1U)
#define SYSCTL0_SGPIO_PSYNC_PSYNC_SHIFT          (0U)
/*! PSYNC - Synchronization Stage Setting:
 *  0b0..2-Stage Sync
 *  0b1..1-Stage Sync
 */
#define SYSCTL0_SGPIO_PSYNC_PSYNC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SGPIO_PSYNC_PSYNC_SHIFT)) & SYSCTL0_SGPIO_PSYNC_PSYNC_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE0 - Auto clock gate override 0 */
/*! @{ */

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_MASK (0x1U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_SHIFT (0U)
/*! AHB2APB0 - AHB2APB0
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_MASK (0x2U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_SHIFT (1U)
/*! AHB2APB1 - AHB2APB1
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_MASK (0x4U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_SHIFT (2U)
/*! CRC_ENGINE - CRC_ENGINE
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_MASK (0x8U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_SHIFT (3U)
/*! CASPER - CASPER
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_MASK  (0x10U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_SHIFT (4U)
/*! DMAC0 - DMAC0
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_MASK  (0x20U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_SHIFT (5U)
/*! DMAC1 - DMAC1
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE1 - Auto clock gate override 1 */
/*! @{ */

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM0_IF_MASK (0x1U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM0_IF_SHIFT (0U)
/*! SRAM0_IF - SRAM0_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM0_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM0_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM0_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM1_IF_MASK (0x2U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM1_IF_SHIFT (1U)
/*! SRAM1_IF - SRAM1_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM1_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM1_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM1_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM2_IF_MASK (0x4U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM2_IF_SHIFT (2U)
/*! SRAM2_IF - SRAM2_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM2_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM2_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM2_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM3_IF_MASK (0x8U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM3_IF_SHIFT (3U)
/*! SRAM3_IF - SRAM3_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM3_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM3_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM3_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM4_IF_MASK (0x10U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM4_IF_SHIFT (4U)
/*! SRAM4_IF - SRAM4_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM4_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM4_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM4_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM5_IF_MASK (0x20U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM5_IF_SHIFT (5U)
/*! SRAM5_IF - SRAM5_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM5_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM5_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM5_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM6_IF_MASK (0x40U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM6_IF_SHIFT (6U)
/*! SRAM6_IF - SRAM6_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM6_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM6_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM6_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM7_IF_MASK (0x80U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM7_IF_SHIFT (7U)
/*! SRAM7_IF - SRAM7_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM7_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM7_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM7_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM8_IF_MASK (0x100U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM8_IF_SHIFT (8U)
/*! SRAM8_IF - SRAM8_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM8_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM8_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM8_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM9_IF_MASK (0x200U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM9_IF_SHIFT (9U)
/*! SRAM9_IF - SRAM9_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM9_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM9_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM9_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM10_IF_MASK (0x400U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM10_IF_SHIFT (10U)
/*! SRAM10_IF - SRAM10_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM10_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM10_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM10_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM11_IF_MASK (0x800U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM11_IF_SHIFT (11U)
/*! SRAM11_IF - SRAM11_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM11_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM11_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM11_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM12_IF_MASK (0x1000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM12_IF_SHIFT (12U)
/*! SRAM12_IF - SRAM12_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM12_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM12_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM12_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM13_IF_MASK (0x2000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM13_IF_SHIFT (13U)
/*! SRAM13_IF - SRAM13_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM13_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM13_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM13_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM14_IF_MASK (0x4000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM14_IF_SHIFT (14U)
/*! SRAM14_IF - SRAM14_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM14_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM14_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM14_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM15_IF_MASK (0x8000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM15_IF_SHIFT (15U)
/*! SRAM15_IF - SRAM15_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM15_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM15_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM15_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM16_IF_MASK (0x10000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM16_IF_SHIFT (16U)
/*! SRAM16_IF - SRAM16_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM16_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM16_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM16_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM17_IF_MASK (0x20000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM17_IF_SHIFT (17U)
/*! SRAM17_IF - SRAM17_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM17_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM17_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM17_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM18_IF_MASK (0x40000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM18_IF_SHIFT (18U)
/*! SRAM18_IF - SRAM18_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM18_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM18_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM18_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM19_IF_MASK (0x80000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM19_IF_SHIFT (19U)
/*! SRAM19_IF - SRAM19_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM19_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM19_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM19_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM20_IF_MASK (0x100000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM20_IF_SHIFT (20U)
/*! SRAM20_IF - SRAM20_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM20_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM20_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM20_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM21_IF_MASK (0x200000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM21_IF_SHIFT (21U)
/*! SRAM21_IF - SRAM21_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM21_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM21_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM21_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM22_IF_MASK (0x400000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM22_IF_SHIFT (22U)
/*! SRAM22_IF - SRAM22_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM22_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM22_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM22_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM23_IF_MASK (0x800000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM23_IF_SHIFT (23U)
/*! SRAM23_IF - SRAM23_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM23_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM23_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM23_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM24_IF_MASK (0x1000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM24_IF_SHIFT (24U)
/*! SRAM24_IF - SRAM24_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM24_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM24_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM24_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM25_IF_MASK (0x2000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM25_IF_SHIFT (25U)
/*! SRAM25_IF - SRAM25_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM25_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM25_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM25_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM26_IF_MASK (0x4000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM26_IF_SHIFT (26U)
/*! SRAM26_IF - SRAM26_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM26_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM26_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM26_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM27_IF_MASK (0x8000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM27_IF_SHIFT (27U)
/*! SRAM27_IF - SRAM27_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM27_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM27_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM27_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM28_IF_MASK (0x10000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM28_IF_SHIFT (28U)
/*! SRAM28_IF - SRAM28_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM28_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM28_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM28_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM29_IF_MASK (0x20000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM29_IF_SHIFT (29U)
/*! SRAM29_IF - SRAM29_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM29_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM29_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM29_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM30_IF_MASK (0x40000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM30_IF_SHIFT (30U)
/*! SRAM30_IF - SRAM30_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM30_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM30_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM30_IF_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM31_IF_MASK (0x80000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM31_IF_SHIFT (31U)
/*! SRAM31_IF - SRAM31_IF
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM31_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM31_IF_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM31_IF_MASK)
/*! @} */

/*! @name CLKGATEOVERRIDE0 - Clock gate override 0 */
/*! @{ */

#define SYSCTL0_CLKGATEOVERRIDE0_SDIO0_MASK      (0x1U)
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO0_SHIFT     (0U)
/*! SDIO0 - SDIO0
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_SDIO0_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_SDIO0_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_SDIO1_MASK      (0x2U)
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO1_SHIFT     (1U)
/*! SDIO1 - SDIO1
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_SDIO1_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_SDIO1_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_USBPHY_MASK     (0x4U)
#define SYSCTL0_CLKGATEOVERRIDE0_USBPHY_SHIFT    (2U)
/*! USBPHY - USBPHY
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_USBPHY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_USBPHY_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_USBPHY_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_ADC_MASK        (0x8U)
#define SYSCTL0_CLKGATEOVERRIDE0_ADC_SHIFT       (3U)
/*! ADC - ADC
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_ADC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_ADC_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_ADC_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_MU_MASK         (0x10U)
#define SYSCTL0_CLKGATEOVERRIDE0_MU_SHIFT        (4U)
/*! MU - MU
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_MU(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_MU_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_MU_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_ACMP_MASK       (0x20U)
#define SYSCTL0_CLKGATEOVERRIDE0_ACMP_SHIFT      (5U)
/*! ACMP - ACMP
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_ACMP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_ACMP_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_ACMP_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_PMC_MASK        (0x40U)
#define SYSCTL0_CLKGATEOVERRIDE0_PMC_SHIFT       (6U)
/*! PMC - PMC
 *  0b0..Enable clock gating
 *  0b1..Continuous Clocking
 */
#define SYSCTL0_CLKGATEOVERRIDE0_PMC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_PMC_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_PMC_MASK)
/*! @} */

/*! @name AHB_SRAM_ACCESS_DISABLE - AHB SRAM access disable */
/*! @{ */

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK (0x1U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT (0U)
/*! SRAM00_IF - Control AHB access to SRAM partition 0
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK (0x2U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT (1U)
/*! SRAM01_IF - Control AHB access to SRAM partition 1
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK (0x4U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT (2U)
/*! SRAM02_IF - Control AHB access to SRAM partition 2
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK (0x8U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT (3U)
/*! SRAM03_IF - Control AHB access to SRAM partition 3
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK (0x10U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT (4U)
/*! SRAM04_IF - Control AHB access to SRAM partition 4
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK (0x20U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT (5U)
/*! SRAM05_IF - Control AHB access to SRAM partition 5
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK (0x40U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT (6U)
/*! SRAM06_IF - Control AHB access to SRAM partition 6
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK (0x80U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT (7U)
/*! SRAM07_IF - Control AHB access to SRAM partition 7
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK (0x100U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT (8U)
/*! SRAM08_IF - Control AHB access to SRAM partition 8
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK (0x200U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT (9U)
/*! SRAM09_IF - Control AHB access to SRAM partition 9
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM010_IF_MASK (0x400U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM010_IF_SHIFT (10U)
/*! SRAM010_IF - Control AHB access to SRAM partition 10
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM010_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM010_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM010_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM011_IF_MASK (0x800U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM011_IF_SHIFT (11U)
/*! SRAM011_IF - Control AHB access to SRAM partition 11
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM011_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM011_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM011_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM012_IF_MASK (0x1000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM012_IF_SHIFT (12U)
/*! SRAM012_IF - Control AHB access to SRAM partition 12
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM012_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM012_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM012_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM013_IF_MASK (0x2000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM013_IF_SHIFT (13U)
/*! SRAM013_IF - Control AHB access to SRAM partition 13
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM013_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM013_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM013_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM014_IF_MASK (0x4000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM014_IF_SHIFT (14U)
/*! SRAM014_IF - Control AHB access to SRAM partition 14
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM014_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM014_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM014_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM015_IF_MASK (0x8000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM015_IF_SHIFT (15U)
/*! SRAM015_IF - Control AHB access to SRAM partition 15
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM015_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM015_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM015_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM016_IF_MASK (0x10000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM016_IF_SHIFT (16U)
/*! SRAM016_IF - Control AHB access to SRAM partition 16
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM016_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM016_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM016_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM017_IF_MASK (0x20000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM017_IF_SHIFT (17U)
/*! SRAM017_IF - Control AHB access to SRAM partition 17
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM017_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM017_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM017_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM018_IF_MASK (0x40000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM018_IF_SHIFT (18U)
/*! SRAM018_IF - Control AHB access to SRAM partition 18
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM018_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM018_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM018_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM019_IF_MASK (0x80000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM019_IF_SHIFT (19U)
/*! SRAM019_IF - Control AHB access to SRAM partition 19
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM019_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM019_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM019_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM020_IF_MASK (0x100000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM020_IF_SHIFT (20U)
/*! SRAM020_IF - Control AHB access to SRAM partition 20
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM020_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM020_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM020_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM021_IF_MASK (0x200000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM021_IF_SHIFT (21U)
/*! SRAM021_IF - Control AHB access to SRAM partition 21
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM021_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM021_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM021_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM022_IF_MASK (0x400000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM022_IF_SHIFT (22U)
/*! SRAM022_IF - Control AHB access to SRAM partition 22
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM022_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM022_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM022_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM023_IF_MASK (0x800000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM023_IF_SHIFT (23U)
/*! SRAM023_IF - Control AHB access to SRAM partition 23
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM023_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM023_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM023_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM024_IF_MASK (0x1000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM024_IF_SHIFT (24U)
/*! SRAM024_IF - Control AHB access to SRAM partition 24
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM024_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM024_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM024_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM025_IF_MASK (0x2000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM025_IF_SHIFT (25U)
/*! SRAM025_IF - Control AHB access to SRAM partition 25
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM025_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM025_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM025_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM026_IF_MASK (0x4000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM026_IF_SHIFT (26U)
/*! SRAM026_IF - Control AHB access to SRAM partition 26
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM026_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM026_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM026_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM027_IF_MASK (0x8000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM027_IF_SHIFT (27U)
/*! SRAM027_IF - Control AHB access to SRAM partition 27
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM027_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM027_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM027_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM028_IF_MASK (0x10000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM028_IF_SHIFT (28U)
/*! SRAM028_IF - Control AHB access to SRAM partition 28
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM028_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM028_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM028_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM029_IF_MASK (0x20000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM029_IF_SHIFT (29U)
/*! SRAM029_IF - Control AHB access to SRAM partition 29
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM029_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM029_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM029_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM030_IF_MASK (0x40000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM030_IF_SHIFT (30U)
/*! SRAM030_IF - Control AHB access to SRAM partition 30
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM030_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM030_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM030_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM031_IF_MASK (0x80000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM031_IF_SHIFT (31U)
/*! SRAM031_IF - Control AHB access to SRAM partition 31
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM031_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM031_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM031_IF_MASK)
/*! @} */

/*! @name AXI_SRAM_ACCESS_DISABLE - AXI SRAM access disable */
/*! @{ */

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK (0x1U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT (0U)
/*! SRAM00_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM00_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK (0x2U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT (1U)
/*! SRAM01_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM01_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK (0x4U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT (2U)
/*! SRAM02_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM02_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK (0x8U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT (3U)
/*! SRAM03_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM03_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK (0x10U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT (4U)
/*! SRAM04_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM04_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK (0x20U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT (5U)
/*! SRAM05_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM05_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK (0x40U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT (6U)
/*! SRAM06_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM06_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK (0x80U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT (7U)
/*! SRAM07_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM07_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK (0x100U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT (8U)
/*! SRAM08_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM08_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK (0x200U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT (9U)
/*! SRAM09_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM09_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM010_IF_MASK (0x400U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM010_IF_SHIFT (10U)
/*! SRAM010_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM010_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM010_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM010_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM011_IF_MASK (0x800U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM011_IF_SHIFT (11U)
/*! SRAM011_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM011_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM011_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM011_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM012_IF_MASK (0x1000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM012_IF_SHIFT (12U)
/*! SRAM012_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM012_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM012_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM012_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM013_IF_MASK (0x2000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM013_IF_SHIFT (13U)
/*! SRAM013_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM013_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM013_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM013_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM014_IF_MASK (0x4000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM014_IF_SHIFT (14U)
/*! SRAM014_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM014_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM014_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM014_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM015_IF_MASK (0x8000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM015_IF_SHIFT (15U)
/*! SRAM015_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM015_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM015_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM015_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM016_IF_MASK (0x10000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM016_IF_SHIFT (16U)
/*! SRAM016_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM016_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM016_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM016_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM017_IF_MASK (0x20000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM017_IF_SHIFT (17U)
/*! SRAM017_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM017_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM017_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM017_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM018_IF_MASK (0x40000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM018_IF_SHIFT (18U)
/*! SRAM018_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM018_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM018_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM018_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM019_IF_MASK (0x80000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM019_IF_SHIFT (19U)
/*! SRAM019_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM019_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM019_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM019_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM020_IF_MASK (0x100000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM020_IF_SHIFT (20U)
/*! SRAM020_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM020_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM020_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM020_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM021_IF_MASK (0x200000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM021_IF_SHIFT (21U)
/*! SRAM021_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM021_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM021_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM021_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM022_IF_MASK (0x400000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM022_IF_SHIFT (22U)
/*! SRAM022_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM022_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM022_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM022_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM023_IF_MASK (0x800000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM023_IF_SHIFT (23U)
/*! SRAM023_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM023_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM023_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM023_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM024_IF_MASK (0x1000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM024_IF_SHIFT (24U)
/*! SRAM024_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM024_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM024_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM024_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM025_IF_MASK (0x2000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM025_IF_SHIFT (25U)
/*! SRAM025_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM025_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM025_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM025_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM026_IF_MASK (0x4000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM026_IF_SHIFT (26U)
/*! SRAM026_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM026_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM026_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM026_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM027_IF_MASK (0x8000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM027_IF_SHIFT (27U)
/*! SRAM027_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM027_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM027_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM027_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM028_IF_MASK (0x10000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM028_IF_SHIFT (28U)
/*! SRAM028_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM028_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM028_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM028_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM029_IF_MASK (0x20000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM029_IF_SHIFT (29U)
/*! SRAM029_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM029_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM029_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM029_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM030_IF_MASK (0x40000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM030_IF_SHIFT (30U)
/*! SRAM030_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM030_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM030_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM030_IF_MASK)

#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM031_IF_MASK (0x80000000U)
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM031_IF_SHIFT (31U)
/*! SRAM031_IF - Control AXI access to SRAM partition
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM031_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM031_IF_SHIFT)) & SYSCTL0_AXI_SRAM_ACCESS_DISABLE_SRAM031_IF_MASK)
/*! @} */

/*! @name DSP_SRAM_ACCESS_DISABLE - DSP SRAM access disable */
/*! @{ */

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM0_IF_MASK (0x1U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM0_IF_SHIFT (0U)
/*! SRAM0_IF - SRAM0_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM0_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM0_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM0_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM1_IF_MASK (0x2U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM1_IF_SHIFT (1U)
/*! SRAM1_IF - SRAM1_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM1_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM1_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM1_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM2_IF_MASK (0x4U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM2_IF_SHIFT (2U)
/*! SRAM2_IF - SRAM2_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM2_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM2_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM2_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM3_IF_MASK (0x8U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM3_IF_SHIFT (3U)
/*! SRAM3_IF - SRAM3_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM3_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM3_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM3_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM4_IF_MASK (0x10U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM4_IF_SHIFT (4U)
/*! SRAM4_IF - SRAM4_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM4_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM4_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM4_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM5_IF_MASK (0x20U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM5_IF_SHIFT (5U)
/*! SRAM5_IF - SRAM5_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM5_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM5_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM5_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM6_IF_MASK (0x40U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM6_IF_SHIFT (6U)
/*! SRAM6_IF - SRAM6_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM6_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM6_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM6_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM7_IF_MASK (0x80U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM7_IF_SHIFT (7U)
/*! SRAM7_IF - SRAM7_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM7_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM7_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM7_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM8_IF_MASK (0x100U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM8_IF_SHIFT (8U)
/*! SRAM8_IF - SRAM8_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM8_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM8_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM8_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM9_IF_MASK (0x200U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM9_IF_SHIFT (9U)
/*! SRAM9_IF - SRAM9_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM9_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM9_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM9_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_MASK (0x400U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_SHIFT (10U)
/*! SRAM10_IF - SRAM10_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_MASK (0x800U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_SHIFT (11U)
/*! SRAM11_IF - SRAM11_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_MASK (0x1000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_SHIFT (12U)
/*! SRAM12_IF - SRAM12_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_MASK (0x2000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_SHIFT (13U)
/*! SRAM13_IF - SRAM13_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_MASK (0x4000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_SHIFT (14U)
/*! SRAM14_IF - SRAM14_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_MASK (0x8000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_SHIFT (15U)
/*! SRAM15_IF - SRAM15_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_MASK (0x10000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_SHIFT (16U)
/*! SRAM16_IF - SRAM16_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_MASK (0x20000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_SHIFT (17U)
/*! SRAM17_IF - SRAM17_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_MASK (0x40000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_SHIFT (18U)
/*! SRAM18_IF - SRAM18_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_MASK (0x80000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_SHIFT (19U)
/*! SRAM19_IF - SRAM19_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_MASK (0x100000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_SHIFT (20U)
/*! SRAM20_IF - SRAM20_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_MASK (0x200000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_SHIFT (21U)
/*! SRAM21_IF - SRAM21_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_MASK (0x400000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_SHIFT (22U)
/*! SRAM22_IF - SRAM22_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_MASK (0x800000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_SHIFT (23U)
/*! SRAM23_IF - SRAM23_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_MASK (0x1000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_SHIFT (24U)
/*! SRAM24_IF - SRAM24_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_MASK (0x2000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_SHIFT (25U)
/*! SRAM25_IF - SRAM25_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_MASK (0x4000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_SHIFT (26U)
/*! SRAM26_IF - SRAM26_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_MASK (0x8000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_SHIFT (27U)
/*! SRAM27_IF - SRAM27_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_MASK (0x10000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_SHIFT (28U)
/*! SRAM28_IF - SRAM28_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_MASK (0x20000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_SHIFT (29U)
/*! SRAM29_IF - SRAM29_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM30_IF_MASK (0x40000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM30_IF_SHIFT (30U)
/*! SRAM30_IF - SRAM30_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM30_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM30_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM30_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM31_IF_MASK (0x80000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM31_IF_SHIFT (31U)
/*! SRAM31_IF - SRAM31_IF
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM31_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM31_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM31_IF_MASK)
/*! @} */

/*! @name PQ_MEM_CTRL - Power-Quad Memory Control */
/*! @{ */

#define SYSCTL0_PQ_MEM_CTRL_SRAM_IG_MASK         (0x1U)
#define SYSCTL0_PQ_MEM_CTRL_SRAM_IG_SHIFT        (0U)
/*! SRAM_IG - SRAM Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_PQ_MEM_CTRL_SRAM_IG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PQ_MEM_CTRL_SRAM_IG_SHIFT)) & SYSCTL0_PQ_MEM_CTRL_SRAM_IG_MASK)

#define SYSCTL0_PQ_MEM_CTRL_SRAM_STDBY_MASK      (0x2U)
#define SYSCTL0_PQ_MEM_CTRL_SRAM_STDBY_SHIFT     (1U)
/*! SRAM_STDBY - SRAM Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_PQ_MEM_CTRL_SRAM_STDBY(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PQ_MEM_CTRL_SRAM_STDBY_SHIFT)) & SYSCTL0_PQ_MEM_CTRL_SRAM_STDBY_MASK)
/*! @} */

/*! @name FLEXSPI0_MEM_CTRL - FlexSPI0 Memory Control */
/*! @{ */

#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_RIG_MASK   (0x1U)
#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_RIG_SHIFT  (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_RIG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_WIG_MASK   (0x2U)
#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_WIG_SHIFT  (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_WIG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_STDBY_MASK (0x4U)
#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_STDBY_SHIFT (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_STDBY(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_FLEXSPI0_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name USBHS_MEM_CTRL - USBHS Memory Control */
/*! @{ */

#define SYSCTL0_USBHS_MEM_CTRL_MEM_IG_MASK       (0x1U)
#define SYSCTL0_USBHS_MEM_CTRL_MEM_IG_SHIFT      (0U)
/*! MEM_IG - Memory Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USBHS_MEM_CTRL_MEM_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBHS_MEM_CTRL_MEM_IG_SHIFT)) & SYSCTL0_USBHS_MEM_CTRL_MEM_IG_MASK)

#define SYSCTL0_USBHS_MEM_CTRL_MEM_STDBY_MASK    (0x2U)
#define SYSCTL0_USBHS_MEM_CTRL_MEM_STDBY_SHIFT   (1U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USBHS_MEM_CTRL_MEM_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBHS_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_USBHS_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name USDHC0_MEM_CTRL - USDHC0 Memory Control */
/*! @{ */

#define SYSCTL0_USDHC0_MEM_CTRL_MEM_RIG_MASK     (0x1U)
#define SYSCTL0_USDHC0_MEM_CTRL_MEM_RIG_SHIFT    (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USDHC0_MEM_CTRL_MEM_RIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USDHC0_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_USDHC0_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_USDHC0_MEM_CTRL_MEM_WIG_MASK     (0x2U)
#define SYSCTL0_USDHC0_MEM_CTRL_MEM_WIG_SHIFT    (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USDHC0_MEM_CTRL_MEM_WIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USDHC0_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_USDHC0_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_USDHC0_MEM_CTRL_MEM_STDBY_MASK   (0x4U)
#define SYSCTL0_USDHC0_MEM_CTRL_MEM_STDBY_SHIFT  (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USDHC0_MEM_CTRL_MEM_STDBY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USDHC0_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_USDHC0_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name USDHC1_MEM_CTRL - USDHC1 Memory Control */
/*! @{ */

#define SYSCTL0_USDHC1_MEM_CTRL_MEM_RIG_MASK     (0x1U)
#define SYSCTL0_USDHC1_MEM_CTRL_MEM_RIG_SHIFT    (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USDHC1_MEM_CTRL_MEM_RIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USDHC1_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_USDHC1_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_USDHC1_MEM_CTRL_MEM_WIG_MASK     (0x2U)
#define SYSCTL0_USDHC1_MEM_CTRL_MEM_WIG_SHIFT    (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USDHC1_MEM_CTRL_MEM_WIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USDHC1_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_USDHC1_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_USDHC1_MEM_CTRL_MEM_STDBY_MASK   (0x4U)
#define SYSCTL0_USDHC1_MEM_CTRL_MEM_STDBY_SHIFT  (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_USDHC1_MEM_CTRL_MEM_STDBY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USDHC1_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_USDHC1_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name CASPER_MEM_CTRL - CASPER Memory Control */
/*! @{ */

#define SYSCTL0_CASPER_MEM_CTRL_MEM_IG_MASK      (0x1U)
#define SYSCTL0_CASPER_MEM_CTRL_MEM_IG_SHIFT     (0U)
/*! MEM_IG - Auto Input Gate Control Disable
 *  0b0..Input Gate is controlled by auto clock gating signal.
 *  0b1..Input Gate Is forced low.
 */
#define SYSCTL0_CASPER_MEM_CTRL_MEM_IG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CASPER_MEM_CTRL_MEM_IG_SHIFT)) & SYSCTL0_CASPER_MEM_CTRL_MEM_IG_MASK)

#define SYSCTL0_CASPER_MEM_CTRL_MEM_STDBY_MASK   (0x2U)
#define SYSCTL0_CASPER_MEM_CTRL_MEM_STDBY_SHIFT  (1U)
/*! MEM_STDBY - Auto Standby Control Disable
 *  0b0..STDBY is controlled by auto clock gating signal.
 *  0b1..STDBY Is forced low.
 */
#define SYSCTL0_CASPER_MEM_CTRL_MEM_STDBY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CASPER_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_CASPER_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name ROM_MEM_CTRL - ROM Memory Control */
/*! @{ */

#define SYSCTL0_ROM_MEM_CTRL_MEM_IG_MASK         (0x1U)
#define SYSCTL0_ROM_MEM_CTRL_MEM_IG_SHIFT        (0U)
/*! MEM_IG - Memory Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_ROM_MEM_CTRL_MEM_IG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_ROM_MEM_CTRL_MEM_IG_SHIFT)) & SYSCTL0_ROM_MEM_CTRL_MEM_IG_MASK)

#define SYSCTL0_ROM_MEM_CTRL_MEM_STDBY_MASK      (0x2U)
#define SYSCTL0_ROM_MEM_CTRL_MEM_STDBY_SHIFT     (1U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_ROM_MEM_CTRL_MEM_STDBY(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_ROM_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_ROM_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCTL0_ROM_MEM_CTRL_MEM_LS_MASK         (0x4U)
#define SYSCTL0_ROM_MEM_CTRL_MEM_LS_SHIFT        (2U)
/*! MEM_LS - MEM LS
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_ROM_MEM_CTRL_MEM_LS(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_ROM_MEM_CTRL_MEM_LS_SHIFT)) & SYSCTL0_ROM_MEM_CTRL_MEM_LS_MASK)
/*! @} */

/*! @name FLEXSPI1_MEM_CTRL - FlexSPI1 Memory Control */
/*! @{ */

#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_RIG_MASK   (0x1U)
#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_RIG_SHIFT  (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_RIG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_WIG_MASK   (0x2U)
#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_WIG_SHIFT  (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_WIG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_STDBY_MASK (0x4U)
#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_STDBY_SHIFT (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_STDBY(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_FLEXSPI1_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name GPU_MEM_CTRL - GPU Memory Control */
/*! @{ */

#define SYSCTL0_GPU_MEM_CTRL_MEM_RIG_MASK        (0x1U)
#define SYSCTL0_GPU_MEM_CTRL_MEM_RIG_SHIFT       (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_GPU_MEM_CTRL_MEM_RIG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_GPU_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_GPU_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_GPU_MEM_CTRL_MEM_WIG_MASK        (0x2U)
#define SYSCTL0_GPU_MEM_CTRL_MEM_WIG_SHIFT       (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_GPU_MEM_CTRL_MEM_WIG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_GPU_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_GPU_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_GPU_MEM_CTRL_MEM_STDBY_MASK      (0x4U)
#define SYSCTL0_GPU_MEM_CTRL_MEM_STDBY_SHIFT     (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_GPU_MEM_CTRL_MEM_STDBY(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_GPU_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_GPU_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name MIPI_MEM_CTRL - MIPI Memory Control */
/*! @{ */

#define SYSCTL0_MIPI_MEM_CTRL_MEM_RIG_MASK       (0x1U)
#define SYSCTL0_MIPI_MEM_CTRL_MEM_RIG_SHIFT      (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_MIPI_MEM_CTRL_MEM_RIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MIPI_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_MIPI_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_MIPI_MEM_CTRL_MEM_WIG_MASK       (0x2U)
#define SYSCTL0_MIPI_MEM_CTRL_MEM_WIG_SHIFT      (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_MIPI_MEM_CTRL_MEM_WIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MIPI_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_MIPI_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_MIPI_MEM_CTRL_MEM_STDBY_MASK     (0x4U)
#define SYSCTL0_MIPI_MEM_CTRL_MEM_STDBY_SHIFT    (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_MIPI_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MIPI_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_MIPI_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name DCN_MEM_CTRL - LCDIF Memory Control */
/*! @{ */

#define SYSCTL0_DCN_MEM_CTRL_MEM_RIG_MASK        (0x1U)
#define SYSCTL0_DCN_MEM_CTRL_MEM_RIG_SHIFT       (0U)
/*! MEM_RIG - Memory Read Input Gate - Blocks the read input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DCN_MEM_CTRL_MEM_RIG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DCN_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCTL0_DCN_MEM_CTRL_MEM_RIG_MASK)

#define SYSCTL0_DCN_MEM_CTRL_MEM_WIG_MASK        (0x2U)
#define SYSCTL0_DCN_MEM_CTRL_MEM_WIG_SHIFT       (1U)
/*! MEM_WIG - Memory Write Input Gate - Blocks the write input signals to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DCN_MEM_CTRL_MEM_WIG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DCN_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCTL0_DCN_MEM_CTRL_MEM_WIG_MASK)

#define SYSCTL0_DCN_MEM_CTRL_MEM_STDBY_MASK      (0x4U)
#define SYSCTL0_DCN_MEM_CTRL_MEM_STDBY_SHIFT     (2U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_DCN_MEM_CTRL_MEM_STDBY(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DCN_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_DCN_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name SMARTDMA_MEM_CTRL - SMARTDMA Memory Control */
/*! @{ */

#define SYSCTL0_SMARTDMA_MEM_CTRL_MEM_IG_MASK    (0x1U)
#define SYSCTL0_SMARTDMA_MEM_CTRL_MEM_IG_SHIFT   (0U)
/*! MEM_IG - Memory Input Gate
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_SMARTDMA_MEM_CTRL_MEM_IG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SMARTDMA_MEM_CTRL_MEM_IG_SHIFT)) & SYSCTL0_SMARTDMA_MEM_CTRL_MEM_IG_MASK)

#define SYSCTL0_SMARTDMA_MEM_CTRL_MEM_STDBY_MASK (0x2U)
#define SYSCTL0_SMARTDMA_MEM_CTRL_MEM_STDBY_SHIFT (1U)
/*! MEM_STDBY - Memory Standby - Powers the driver to dual-port memory
 *  0b0..Enable
 *  0b1..Disable
 */
#define SYSCTL0_SMARTDMA_MEM_CTRL_MEM_STDBY(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SMARTDMA_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCTL0_SMARTDMA_MEM_CTRL_MEM_STDBY_MASK)
/*! @} */

/*! @name MIPI_DSI_CTRL - MIPI DSI Control */
/*! @{ */

#define SYSCTL0_MIPI_DSI_CTRL_DSI_SD_MASK        (0x1U)
#define SYSCTL0_MIPI_DSI_CTRL_DSI_SD_SHIFT       (0U)
/*! DSI_SD - DSI Shutdown Control.
 *  0b0..Shutdown command not to be sent to the Type-4 display (default).
 *  0b1..Shutdown command to be sent to the Type-4 display
 */
#define SYSCTL0_MIPI_DSI_CTRL_DSI_SD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MIPI_DSI_CTRL_DSI_SD_SHIFT)) & SYSCTL0_MIPI_DSI_CTRL_DSI_SD_MASK)

#define SYSCTL0_MIPI_DSI_CTRL_DSI_CM_MASK        (0x2U)
#define SYSCTL0_MIPI_DSI_CTRL_DSI_CM_SHIFT       (1U)
/*! DSI_CM - DSI Color Mode Control.
 *  0b0..Normal mode (full color) (default)
 *  0b1..Low color mode (8-bit)
 */
#define SYSCTL0_MIPI_DSI_CTRL_DSI_CM(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MIPI_DSI_CTRL_DSI_CM_SHIFT)) & SYSCTL0_MIPI_DSI_CTRL_DSI_CM_MASK)

#define SYSCTL0_MIPI_DSI_CTRL_DSI_TX_ACTIVE_MASK (0x4U)
#define SYSCTL0_MIPI_DSI_CTRL_DSI_TX_ACTIVE_SHIFT (2U)
/*! DSI_TX_ACTIVE - DSI TX ACTIVE */
#define SYSCTL0_MIPI_DSI_CTRL_DSI_TX_ACTIVE(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MIPI_DSI_CTRL_DSI_TX_ACTIVE_SHIFT)) & SYSCTL0_MIPI_DSI_CTRL_DSI_TX_ACTIVE_MASK)
/*! @} */

/*! @name USB0CLKCTRL - USB Clock Control */
/*! @{ */

#define SYSCTL0_USB0CLKCTRL_AP_FS_DEV_CLK_MASK   (0x1U)
#define SYSCTL0_USB0CLKCTRL_AP_FS_DEV_CLK_SHIFT  (0U)
/*! AP_FS_DEV_CLK - USB0 Device need clock signal control
 *  0b0..Under hardware control
 *  0b1..Forced high
 */
#define SYSCTL0_USB0CLKCTRL_AP_FS_DEV_CLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKCTRL_AP_FS_DEV_CLK_SHIFT)) & SYSCTL0_USB0CLKCTRL_AP_FS_DEV_CLK_MASK)

#define SYSCTL0_USB0CLKCTRL_POL_FS_DEV_CLK_MASK  (0x2U)
#define SYSCTL0_USB0CLKCTRL_POL_FS_DEV_CLK_SHIFT (1U)
/*! POL_FS_DEV_CLK - USB0 Device need clock polarity for triggering the USB0 wake-up interrupt
 *  0b0..Falling edge of device need_clock triggers wake-up
 *  0b1..Rising edge of device need_clock triggers wake-up
 */
#define SYSCTL0_USB0CLKCTRL_POL_FS_DEV_CLK(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKCTRL_POL_FS_DEV_CLK_SHIFT)) & SYSCTL0_USB0CLKCTRL_POL_FS_DEV_CLK_MASK)

#define SYSCTL0_USB0CLKCTRL_AP_FS_HOST_CLK_MASK  (0x4U)
#define SYSCTL0_USB0CLKCTRL_AP_FS_HOST_CLK_SHIFT (2U)
/*! AP_FS_HOST_CLK - USB0 Host need clock signal control
 *  0b0..Under hardware control
 *  0b1..Forced high
 */
#define SYSCTL0_USB0CLKCTRL_AP_FS_HOST_CLK(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKCTRL_AP_FS_HOST_CLK_SHIFT)) & SYSCTL0_USB0CLKCTRL_AP_FS_HOST_CLK_MASK)

#define SYSCTL0_USB0CLKCTRL_POL_FS_HOST_CLK_MASK (0x8U)
#define SYSCTL0_USB0CLKCTRL_POL_FS_HOST_CLK_SHIFT (3U)
/*! POL_FS_HOST_CLK - USB0 HOST need clock polarity for triggering the USB0 wake-up interrupt
 *  0b0..Falling edge of host need_clock triggers wake-up
 *  0b1..Rising edge of host need_clock triggers wake-up
 */
#define SYSCTL0_USB0CLKCTRL_POL_FS_HOST_CLK(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKCTRL_POL_FS_HOST_CLK_SHIFT)) & SYSCTL0_USB0CLKCTRL_POL_FS_HOST_CLK_MASK)

#define SYSCTL0_USB0CLKCTRL_HS_DEV_WAKEUP_N_MASK (0x10U)
#define SYSCTL0_USB0CLKCTRL_HS_DEV_WAKEUP_N_SHIFT (4U)
/*! HS_DEV_WAKEUP_N - External user wake-up signal for device mode
 *  0b0..Forces USB0 PHY to wake-up
 *  0b1..Normal USB0 PHY behavior
 */
#define SYSCTL0_USB0CLKCTRL_HS_DEV_WAKEUP_N(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKCTRL_HS_DEV_WAKEUP_N_SHIFT)) & SYSCTL0_USB0CLKCTRL_HS_DEV_WAKEUP_N_MASK)
/*! @} */

/*! @name USB0CLKSTAT - USB Clock Status */
/*! @{ */

#define SYSCTL0_USB0CLKSTAT_DEV_NEED_CLKST_MASK  (0x1U)
#define SYSCTL0_USB0CLKSTAT_DEV_NEED_CLKST_SHIFT (0U)
/*! DEV_NEED_CLKST - USB0 Device USB0_NEEDCLK signal status
 *  0b0..Low
 *  0b1..High
 */
#define SYSCTL0_USB0CLKSTAT_DEV_NEED_CLKST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKSTAT_DEV_NEED_CLKST_SHIFT)) & SYSCTL0_USB0CLKSTAT_DEV_NEED_CLKST_MASK)

#define SYSCTL0_USB0CLKSTAT_HOST_NEED_CLKST_MASK (0x2U)
#define SYSCTL0_USB0CLKSTAT_HOST_NEED_CLKST_SHIFT (1U)
/*! HOST_NEED_CLKST - USB0 Device Host USB0_NEEDCLK signal status
 *  0b0..Low
 *  0b1..High
 */
#define SYSCTL0_USB0CLKSTAT_HOST_NEED_CLKST(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USB0CLKSTAT_HOST_NEED_CLKST_SHIFT)) & SYSCTL0_USB0CLKSTAT_HOST_NEED_CLKST_MASK)
/*! @} */

/*! @name USBPHYPLL0LOCKTIMEDIV2 - USB PHY PLL0 lock time division */
/*! @{ */

#define SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - USBPHYPLL0 Lock Time */
#define SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name PDSLEEPCFG0 - Sleep configuration 0 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_MASK (0x1U)
#define SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_SHIFT (0U)
/*! MAINCLK_SHUTOFF - Main clock shut off
 *  0b0..Clocks enabled
 *  0b1..Clocks disabled
 */
#define SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_SHIFT)) & SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_MASK      (0x2U)
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_SHIFT     (1U)
/*! PMIC_MODE0 - PMIC_MODE0 device pin
 *  0b0..Set mode to 0
 *  0b1..Set mode to 1
 */
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_MASK      (0x4U)
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_SHIFT     (2U)
/*! PMIC_MODE1 - PMIC_MODE1 device pin
 *  0b0..Set mode to 0
 *  0b1..Set mode to 1
 */
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_MASK)

#define SYSCTL0_PDSLEEPCFG0_DEEP_PD_MASK         (0x8U)
#define SYSCTL0_PDSLEEPCFG0_DEEP_PD_SHIFT        (3U)
/*! DEEP_PD - Deep power-down mode
 *  0b0..VDDCORE supply remains on during WFI (deep_sleep mode)
 *  0b1..VDDCORE powered-off during WFI (deep_powerdown mode)
 */
#define SYSCTL0_PDSLEEPCFG0_DEEP_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_DEEP_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_DEEP_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_MASK   (0x10U)
#define SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_SHIFT  (4U)
/*! VDDCOREREG_LP - Vddcore regulator mode
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_FRO_CG_MASK          (0x20U)
#define SYSCTL0_PDSLEEPCFG0_FRO_CG_SHIFT         (5U)
/*! FRO_CG - 192/96 FRO Clock Gate
 *  0b0..FRO clock to the dividers is NOT gated
 *  0b1..FRO clock to the dividers is gated off
 */
#define SYSCTL0_PDSLEEPCFG0_FRO_CG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_FRO_CG_SHIFT)) & SYSCTL0_PDSLEEPCFG0_FRO_CG_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMCREF_LP_MASK       (0x40U)
#define SYSCTL0_PDSLEEPCFG0_PMCREF_LP_SHIFT      (6U)
/*! PMCREF_LP - Internal PMC references LP mode
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDSLEEPCFG0_PMCREF_LP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMCREF_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMCREF_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_MASK       (0x80U)
#define SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_SHIFT      (7U)
/*! HVD1V8_PD - HVD
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_HVD1V8_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_PORCORE_LP_MASK      (0x100U)
#define SYSCTL0_PDSLEEPCFG0_PORCORE_LP_SHIFT     (8U)
/*! PORCORE_LP - LVD
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDSLEEPCFG0_PORCORE_LP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PORCORE_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PORCORE_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_MASK      (0x200U)
#define SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_SHIFT     (9U)
/*! LVDCORE_LP - LVD
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDSLEEPCFG0_LVDCORE_LP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_MASK      (0x400U)
#define SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_SHIFT     (10U)
/*! HVDCORE_PD - HVD
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_HVDCORE_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_RBB_PD_MASK          (0x800U)
#define SYSCTL0_PDSLEEPCFG0_RBB_PD_SHIFT         (11U)
/*! RBB_PD - Reverse body-bias
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_RBB_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_RBB_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_RBB_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_FBB_PD_MASK          (0x1000U)
#define SYSCTL0_PDSLEEPCFG0_FBB_PD_SHIFT         (12U)
/*! FBB_PD - Forward body-bias
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_FBB_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_FBB_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_FBB_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_MASK      (0x2000U)
#define SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_SHIFT     (13U)
/*! SYSXTAL_PD - Main crystal oscillator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_LPOSC_PD_MASK        (0x4000U)
#define SYSCTL0_PDSLEEPCFG0_LPOSC_PD_SHIFT       (14U)
/*! LPOSC_PD - 1 MHz Low-Power oscillator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_LPOSC_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_LPOSC_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_LPOSC_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_RBBSRAM_PD_MASK      (0x8000U)
#define SYSCTL0_PDSLEEPCFG0_RBBSRAM_PD_SHIFT     (15U)
/*! RBBSRAM_PD - RBBSRAM
 *  0b0..Enables SRAM Reverse Body Bias
 *  0b1..Disables SRAM Reverse Body Bias
 */
#define SYSCTL0_PDSLEEPCFG0_RBBSRAM_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_RBBSRAM_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_RBBSRAM_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_FFRO_PD_MASK         (0x10000U)
#define SYSCTL0_PDSLEEPCFG0_FFRO_PD_SHIFT        (16U)
/*! FFRO_PD - FRO 192/96 MHz internal oscillator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_FFRO_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_FFRO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_FFRO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_MASK    (0x20000U)
#define SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_SHIFT   (17U)
/*! SYSPLLLDO_PD - System PLL internal regulator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_MASK    (0x40000U)
#define SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_SHIFT   (18U)
/*! SYSPLLANA_PD - System PLL analog functions
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_MASK    (0x80000U)
#define SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_SHIFT   (19U)
/*! AUDPLLLDO_PD - Audio PLL internal regulator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_MASK    (0x100000U)
#define SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_SHIFT   (20U)
/*! AUDPLLANA_PD - Audio PLL analog functions
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_ADC_PD_MASK          (0x200000U)
#define SYSCTL0_PDSLEEPCFG0_ADC_PD_SHIFT         (21U)
/*! ADC_PD - ADC analog functions
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_ADC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ADC_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ADC_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_ADC_LP_MASK          (0x400000U)
#define SYSCTL0_PDSLEEPCFG0_ADC_LP_SHIFT         (22U)
/*! ADC_LP - ADC low power mode
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_ADC_LP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ADC_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ADC_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_ADC_TEMPSNS_PD_MASK  (0x800000U)
#define SYSCTL0_PDSLEEPCFG0_ADC_TEMPSNS_PD_SHIFT (23U)
/*! ADC_TEMPSNS_PD - ADC temperature sensor
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_ADC_TEMPSNS_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ADC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ADC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMC_TEMPSNS_PD_MASK  (0x1000000U)
#define SYSCTL0_PDSLEEPCFG0_PMC_TEMPSNS_PD_SHIFT (24U)
/*! PMC_TEMPSNS_PD - PMC temperature sensor
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_PMC_TEMPSNS_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_ACMP_PD_MASK         (0x2000000U)
#define SYSCTL0_PDSLEEPCFG0_ACMP_PD_SHIFT        (25U)
/*! ACMP_PD - Analog comparator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG0_ACMP_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ACMP_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ACMP_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI0_REF_PD_MASK (0x8000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI0_REF_PD_SHIFT (27U)
/*! HSPAD_FSPI0_REF_PD - High speed pad sleep mode
 *  0b0..High speed pad refs in normal mode
 *  0b1..High speed pad refs in sleep mode
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI0_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI0_REF_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI0_REF_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD_SDIO0_REF_PD_MASK (0x20000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD_SDIO0_REF_PD_SHIFT (29U)
/*! HSPAD_SDIO0_REF_PD - High Speed Pad VREF
 *  0b0..Normal mode
 *  0b1..Sleep mode
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD_SDIO0_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD_SDIO0_REF_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD_SDIO0_REF_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI1_REF_PD_MASK (0x80000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI1_REF_PD_SHIFT (31U)
/*! HSPAD_FSPI1_REF_PD - Hi speed pad sleep mode
 *  0b0..High speed pad refs in normal mode
 *  0b1..High speed pad refs in sleep mode
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI1_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI1_REF_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD_FSPI1_REF_PD_MASK)
/*! @} */

/*! @name PDSLEEPCFG1 - Sleep configuration 1 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_MASK     (0x2U)
#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_SHIFT    (1U)
/*! PQ_SRAM_PPD - Periphery power for PowerQuad RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_APD_SHIFT (2U)
/*! FLEXSPI0_SRAM_APD - Array power for FLEXSPI0 RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI0_SRAM_PPD - Periphery power for FLEXSPI0 RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_FLEXSPI0_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_APD_MASK (0x10U)
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_APD_SHIFT (4U)
/*! FLEXSPI1_SRAM_APD - Array power for FLEXSPI1 RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_PPD_MASK (0x20U)
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_PPD_SHIFT (5U)
/*! FLEXSPI1_SRAM_PPD - Periphery power for FLEXSPI1 RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_FLEXSPI1_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_MASK  (0x40U)
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_SHIFT (6U)
/*! USBHS_SRAM_APD - Array power for USB RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_MASK  (0x80U)
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_SHIFT (7U)
/*! USBHS_SRAM_PPD - Periphery power for USB RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_MASK (0x100U)
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_SHIFT (8U)
/*! USDHC0_SRAM_APD - Array power for uSDHC0 (SD/MMC/SDIO interface) RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_MASK (0x200U)
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_SHIFT (9U)
/*! USDHC0_SRAM_PPD - Periphery power for uSDHC0 (SD/MMC/SDIO interface) RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_MASK (0x400U)
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_SHIFT (10U)
/*! USDHC1_SRAM_APD - Array power for Casper RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_MASK (0x800U)
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_SHIFT (11U)
/*! USDHC1_SRAM_PPD - Periphery power for uSDHC1 (SD/MMC/SDIO interface) RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_MASK (0x2000U)
#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_SHIFT (13U)
/*! CASPER_SRAM_PPD - Periphery power for Casper RAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_GPU_SRAM_APD_MASK    (0x4000U)
#define SYSCTL0_PDSLEEPCFG1_GPU_SRAM_APD_SHIFT   (14U)
/*! GPU_SRAM_APD - Array Power for GPU SRAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_GPU_SRAM_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_GPU_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_GPU_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_GPU_SRAM_PPD_MASK    (0x8000U)
#define SYSCTL0_PDSLEEPCFG1_GPU_SRAM_PPD_SHIFT   (15U)
/*! GPU_SRAM_PPD - Periphery Power for GPU SRAM
 *  0b0..Enable
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG1_GPU_SRAM_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_GPU_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_GPU_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_APD_MASK (0x10000U)
#define SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_APD_SHIFT (16U)
/*! SMARTDMA_SRAM_APD - Array Power for SMARTDMA SRAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_PPD_MASK (0x20000U)
#define SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_PPD_SHIFT (17U)
/*! SMARTDMA_SRAM_PPD - Periphery Power for SMARTDMA SRAM
 *  0b0..Enable
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_SMARTDMA_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_APD_MASK (0x40000U)
#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_APD_SHIFT (18U)
/*! MIPIDSI_SRAM_APD - Array Power for MIPIDSI SRAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_PPD_MASK (0x80000U)
#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_PPD_SHIFT (19U)
/*! MIPIDSI_SRAM_PPD - Periphery Power for MIPIDSI SRAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_MIPIDSI_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_APD_MASK  (0x100000U)
#define SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_APD_SHIFT (20U)
/*! LCDIF_SRAM_APD - Array Power for LCDIF SRAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_PPD_MASK  (0x200000U)
#define SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_PPD_SHIFT (21U)
/*! LCDIF_SRAM_PPD - Periphery Power for LCDIF SRAM
 *  0b0..Power down disabled or Powered ON
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_LCDIF_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_DSP_PD_MASK          (0x2000000U)
#define SYSCTL0_PDSLEEPCFG1_DSP_PD_SHIFT         (25U)
/*! DSP_PD - DSP
 *  0b0..DSP not power gated
 *  0b1..DSP power gated
 */
#define SYSCTL0_PDSLEEPCFG1_DSP_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_DSP_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_DSP_PD_MASK)

#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_PD_MASK      (0x4000000U)
#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_PD_SHIFT     (26U)
/*! MIPIDSI_PD - MIPIDSI
 *  0b0..MIPI DSI not power gated
 *  0b1..MIPI DSI power gated
 */
#define SYSCTL0_PDSLEEPCFG1_MIPIDSI_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_MIPIDSI_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_MIPIDSI_PD_MASK)

#define SYSCTL0_PDSLEEPCFG1_OTP_PD_MASK          (0x8000000U)
#define SYSCTL0_PDSLEEPCFG1_OTP_PD_SHIFT         (27U)
/*! OTP_PD - OTP
 *  0b0..Powered
 *  0b1..Not Powered
 */
#define SYSCTL0_PDSLEEPCFG1_OTP_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_OTP_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_OTP_PD_MASK)

#define SYSCTL0_PDSLEEPCFG1_ROM_PD_MASK          (0x10000000U)
#define SYSCTL0_PDSLEEPCFG1_ROM_PD_SHIFT         (28U)
/*! ROM_PD - ROM
 *  0b0..ROM Powered
 *  0b1..ROM not Powered
 */
#define SYSCTL0_PDSLEEPCFG1_ROM_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_ROM_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_ROM_PD_MASK)

#define SYSCTL0_PDSLEEPCFG1_HSPAD_SDIO1_REF_PD_MASK (0x40000000U)
#define SYSCTL0_PDSLEEPCFG1_HSPAD_SDIO1_REF_PD_SHIFT (30U)
/*! HSPAD_SDIO1_REF_PD - High speed pad SDIO1 sleep mode
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDSLEEPCFG1_HSPAD_SDIO1_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_HSPAD_SDIO1_REF_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_HSPAD_SDIO1_REF_PD_MASK)

#define SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_MASK      (0x80000000U)
#define SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_SHIFT     (31U)
/*! SRAM_SLEEP - SRAM sleep mode
 *  0b0..RAM Normal mode
 *  0b1..RAM Sleep mode. Needed when vddcore can be < 0.6V to ensure contents retained. Memories not accessible in this mode.
 */
#define SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDSLEEPCFG2 - Sleep configuration 2 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_MASK    (0x1U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_SHIFT   (0U)
/*! SRAM_IF0_APD - Array power for RAM interface 0
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_MASK    (0x2U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_SHIFT   (1U)
/*! SRAM_IF1_APD - Array power for RAM interface 1
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_MASK    (0x4U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_SHIFT   (2U)
/*! SRAM_IF2_APD - Array power for RAM interface 2
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_MASK    (0x8U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_SHIFT   (3U)
/*! SRAM_IF3_APD - Array power for RAM interface 3
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_MASK    (0x10U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_SHIFT   (4U)
/*! SRAM_IF4_APD - Array power for RAM interface 4
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_MASK    (0x20U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_SHIFT   (5U)
/*! SRAM_IF5_APD - Array power for RAM interface 5
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_MASK    (0x40U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_SHIFT   (6U)
/*! SRAM_IF6_APD - Array power for RAM interface 6
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_MASK    (0x80U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_SHIFT   (7U)
/*! SRAM_IF7_APD - Array power for RAM interface 7
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_MASK    (0x100U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_SHIFT   (8U)
/*! SRAM_IF8_APD - Array power for RAM interface 8
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_MASK    (0x200U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_SHIFT   (9U)
/*! SRAM_IF9_APD - Array power for RAM interface 9
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_MASK   (0x400U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_SHIFT  (10U)
/*! SRAM_IF10_APD - Array power for RAM interface 10
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_MASK   (0x800U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_SHIFT  (11U)
/*! SRAM_IF11_APD - Array power for RAM interface 11
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_MASK   (0x1000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_SHIFT  (12U)
/*! SRAM_IF12_APD - Array power for RAM interface 12
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_MASK   (0x2000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_SHIFT  (13U)
/*! SRAM_IF13_APD - Array power for RAM interface 13
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_MASK   (0x4000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_SHIFT  (14U)
/*! SRAM_IF14_APD - Array power for RAM interface 14
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_MASK   (0x8000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_SHIFT  (15U)
/*! SRAM_IF15_APD - Array power for RAM interface 15
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_MASK   (0x10000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_SHIFT  (16U)
/*! SRAM_IF16_APD - Array power for RAM interface 16
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_MASK   (0x20000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_SHIFT  (17U)
/*! SRAM_IF17_APD - Array power for RAM interface 17
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_MASK   (0x40000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_SHIFT  (18U)
/*! SRAM_IF18_APD - Array power for RAM interface 18
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_MASK   (0x80000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_SHIFT  (19U)
/*! SRAM_IF19_APD - Array power for RAM interface 19
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_MASK   (0x100000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_SHIFT  (20U)
/*! SRAM_IF20_APD - Array power for RAM interface 20
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_MASK   (0x200000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_SHIFT  (21U)
/*! SRAM_IF21_APD - Array power for RAM interface 21
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_MASK   (0x400000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_SHIFT  (22U)
/*! SRAM_IF22_APD - Array power for RAM interface 22
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_MASK   (0x800000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_SHIFT  (23U)
/*! SRAM_IF23_APD - Array power for RAM interface 23
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_MASK   (0x1000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_SHIFT  (24U)
/*! SRAM_IF24_APD - Array power for RAM interface 24
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_MASK   (0x2000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_SHIFT  (25U)
/*! SRAM_IF25_APD - Array power for RAM interface 25
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_MASK   (0x4000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_SHIFT  (26U)
/*! SRAM_IF26_APD - Array power for RAM interface 26
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_MASK   (0x8000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_SHIFT  (27U)
/*! SRAM_IF27_APD - Array power for RAM interface 27
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_MASK   (0x10000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_SHIFT  (28U)
/*! SRAM_IF28_APD - Array power for RAM interface 28
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_MASK   (0x20000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_SHIFT  (29U)
/*! SRAM_IF29_APD - Array power for RAM interface 29
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF30_APD_MASK   (0x40000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF30_APD_SHIFT  (30U)
/*! SRAM_IF30_APD - Array power for RAM interface 30
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF30_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF30_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF30_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF31_APD_MASK   (0x80000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF31_APD_SHIFT  (31U)
/*! SRAM_IF31_APD - Array power for RAM interface 31
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF31_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF31_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF31_APD_MASK)
/*! @} */

/*! @name PDSLEEPCFG3 - Sleep configuration 3 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_MASK    (0x1U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_SHIFT   (0U)
/*! SRAM_IF0_PPD - Periphery power for RAM interface 0
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_MASK    (0x2U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_SHIFT   (1U)
/*! SRAM_IF1_PPD - Periphery power for RAM interface 1
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_MASK    (0x4U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_SHIFT   (2U)
/*! SRAM_IF2_PPD - Periphery power for RAM interface 2
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_MASK    (0x8U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_SHIFT   (3U)
/*! SRAM_IF3_PPD - Periphery power for RAM interface 3
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_MASK    (0x10U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_SHIFT   (4U)
/*! SRAM_IF4_PPD - Periphery power for RAM interface 4
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_MASK    (0x20U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_SHIFT   (5U)
/*! SRAM_IF5_PPD - Periphery power for RAM interface 5
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_MASK    (0x40U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_SHIFT   (6U)
/*! SRAM_IF6_PPD - Periphery power for RAM interface 6
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_MASK    (0x80U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_SHIFT   (7U)
/*! SRAM_IF7_PPD - Periphery power for RAM interface 7
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_MASK    (0x100U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_SHIFT   (8U)
/*! SRAM_IF8_PPD - Periphery power for RAM interface 8
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_MASK    (0x200U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_SHIFT   (9U)
/*! SRAM_IF9_PPD - Periphery power for RAM interface 9
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_MASK   (0x400U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_SHIFT  (10U)
/*! SRAM_IF10_PPD - Periphery power for RAM interface 10
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_MASK   (0x800U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_SHIFT  (11U)
/*! SRAM_IF11_PPD - Periphery power for RAM interface 11
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_MASK   (0x1000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_SHIFT  (12U)
/*! SRAM_IF12_PPD - Periphery power for RAM interface 12
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_MASK   (0x2000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_SHIFT  (13U)
/*! SRAM_IF13_PPD - Periphery power for RAM interface 13
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_MASK   (0x4000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_SHIFT  (14U)
/*! SRAM_IF14_PPD - Periphery power for RAM interface 14
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_MASK   (0x8000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_SHIFT  (15U)
/*! SRAM_IF15_PPD - Periphery power for RAM interface 15
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_MASK   (0x10000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_SHIFT  (16U)
/*! SRAM_IF16_PPD - Periphery power for RAM interface 16
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_MASK   (0x20000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_SHIFT  (17U)
/*! SRAM_IF17_PPD - Periphery power for RAM interface 17
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_MASK   (0x40000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_SHIFT  (18U)
/*! SRAM_IF18_PPD - Periphery power for RAM interface 18
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_MASK   (0x80000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_SHIFT  (19U)
/*! SRAM_IF19_PPD - Periphery power for RAM interface 19
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_MASK   (0x100000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_SHIFT  (20U)
/*! SRAM_IF20_PPD - Periphery power for RAM interface 20
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_MASK   (0x200000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_SHIFT  (21U)
/*! SRAM_IF21_PPD - Periphery power for RAM interface 21
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_MASK   (0x400000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_SHIFT  (22U)
/*! SRAM_IF22_PPD - Periphery power for RAM interface 22
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_MASK   (0x800000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_SHIFT  (23U)
/*! SRAM_IF23_PPD - Periphery power for RAM interface 23
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_MASK   (0x1000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_SHIFT  (24U)
/*! SRAM_IF24_PPD - Periphery power for RAM interface 24
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_MASK   (0x2000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_SHIFT  (25U)
/*! SRAM_IF25_PPD - Periphery power for RAM interface 25
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_MASK   (0x4000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_SHIFT  (26U)
/*! SRAM_IF26_PPD - Periphery power for RAM interface 26
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_MASK   (0x8000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_SHIFT  (27U)
/*! SRAM_IF27_PPD - Periphery power for RAM interface 27
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_MASK   (0x10000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_SHIFT  (28U)
/*! SRAM_IF28_PPD - Periphery power for RAM interface 28
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_MASK   (0x20000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_SHIFT  (29U)
/*! SRAM_IF29_PPD - Periphery power for RAM interface 29
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF30_PPD_MASK   (0x40000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF30_PPD_SHIFT  (30U)
/*! SRAM_IF30_PPD - Periphery power for RAM interface 30
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF30_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF30_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF30_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF31_PPD_MASK   (0x80000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF31_PPD_SHIFT  (31U)
/*! SRAM_IF31_PPD - Periphery power for RAM interface 31
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF31_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF31_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF31_PPD_MASK)
/*! @} */

/*! @name PDRUNCFG0 - Run configuration 0 */
/*! @{ */

#define SYSCTL0_PDRUNCFG0_MAINCLK_SHUTOFF_MASK   (0x1U)
#define SYSCTL0_PDRUNCFG0_MAINCLK_SHUTOFF_SHIFT  (0U)
/*! MAINCLK_SHUTOFF - Main clock shut off
 *  0b0..Clocks enabled
 *  0b1..Clocks gated
 */
#define SYSCTL0_PDRUNCFG0_MAINCLK_SHUTOFF(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_MAINCLK_SHUTOFF_SHIFT)) & SYSCTL0_PDRUNCFG0_MAINCLK_SHUTOFF_MASK)

#define SYSCTL0_PDRUNCFG0_PMIC_MODE0_MASK        (0x2U)
#define SYSCTL0_PDRUNCFG0_PMIC_MODE0_SHIFT       (1U)
/*! PMIC_MODE0 - PMIC_MODE0 device pin
 *  0b0..Set mode to 0
 *  0b1..Set mode to 1
 */
#define SYSCTL0_PDRUNCFG0_PMIC_MODE0(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMIC_MODE0_SHIFT)) & SYSCTL0_PDRUNCFG0_PMIC_MODE0_MASK)

#define SYSCTL0_PDRUNCFG0_PMIC_MODE1_MASK        (0x4U)
#define SYSCTL0_PDRUNCFG0_PMIC_MODE1_SHIFT       (2U)
/*! PMIC_MODE1 - PMIC_MODE1 device pin
 *  0b0..Set mode to 0
 *  0b1..Set mode to 1
 */
#define SYSCTL0_PDRUNCFG0_PMIC_MODE1(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMIC_MODE1_SHIFT)) & SYSCTL0_PDRUNCFG0_PMIC_MODE1_MASK)

#define SYSCTL0_PDRUNCFG0_DEEP_PD_MASK           (0x8U)
#define SYSCTL0_PDRUNCFG0_DEEP_PD_SHIFT          (3U)
/*! DEEP_PD - Deep power-down mode
 *  0b0..VDDCORE supply remains on during WFI (deep_sleep mode)
 *  0b1..VDDCORE powered-off during WFI (deep_powerdown mode)
 */
#define SYSCTL0_PDRUNCFG0_DEEP_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_DEEP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_DEEP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_MASK     (0x10U)
#define SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_SHIFT    (4U)
/*! VDDCOREREG_LP - Vddcore regulator mode
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDRUNCFG0_VDDCOREREG_LP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDRUNCFG0_FRO_CG_MASK            (0x20U)
#define SYSCTL0_PDRUNCFG0_FRO_CG_SHIFT           (5U)
/*! FRO_CG - 192/96 FRO Clock Gate
 *  0b0..FRO clock to the dividers is NOT gated
 *  0b1..FRO clock to the dividers is gated off
 */
#define SYSCTL0_PDRUNCFG0_FRO_CG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_FRO_CG_SHIFT)) & SYSCTL0_PDRUNCFG0_FRO_CG_MASK)

#define SYSCTL0_PDRUNCFG0_PMCREF_LP_MASK         (0x40U)
#define SYSCTL0_PDRUNCFG0_PMCREF_LP_SHIFT        (6U)
/*! PMCREF_LP - Internal PMC references LP mode
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDRUNCFG0_PMCREF_LP(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMCREF_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_PMCREF_LP_MASK)

#define SYSCTL0_PDRUNCFG0_HVD1V8_PD_MASK         (0x80U)
#define SYSCTL0_PDRUNCFG0_HVD1V8_PD_SHIFT        (7U)
/*! HVD1V8_PD - HVD
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_HVD1V8_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HVD1V8_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HVD1V8_PD_MASK)

#define SYSCTL0_PDRUNCFG0_PORCORE_LP_MASK        (0x100U)
#define SYSCTL0_PDRUNCFG0_PORCORE_LP_SHIFT       (8U)
/*! PORCORE_LP - LVD
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDRUNCFG0_PORCORE_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PORCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_PORCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_LVDCORE_LP_MASK        (0x200U)
#define SYSCTL0_PDRUNCFG0_LVDCORE_LP_SHIFT       (9U)
/*! LVDCORE_LP - LVD
 *  0b0..HP mode
 *  0b1..LP mode
 */
#define SYSCTL0_PDRUNCFG0_LVDCORE_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_LVDCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_LVDCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_HVDCORE_PD_MASK        (0x400U)
#define SYSCTL0_PDRUNCFG0_HVDCORE_PD_SHIFT       (10U)
/*! HVDCORE_PD - HVD
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_HVDCORE_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HVDCORE_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HVDCORE_PD_MASK)

#define SYSCTL0_PDRUNCFG0_RBB_PD_MASK            (0x800U)
#define SYSCTL0_PDRUNCFG0_RBB_PD_SHIFT           (11U)
/*! RBB_PD - Reverse body-bias
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_RBB_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_RBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_RBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_FBB_PD_MASK            (0x1000U)
#define SYSCTL0_PDRUNCFG0_FBB_PD_SHIFT           (12U)
/*! FBB_PD - Forward body-bias
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_FBB_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_FBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_FBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SYSXTAL_PD_MASK        (0x2000U)
#define SYSCTL0_PDRUNCFG0_SYSXTAL_PD_SHIFT       (13U)
/*! SYSXTAL_PD - Main crystal oscillator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_SYSXTAL_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SYSXTAL_PD_MASK)

#define SYSCTL0_PDRUNCFG0_LPOSC_PD_MASK          (0x4000U)
#define SYSCTL0_PDRUNCFG0_LPOSC_PD_SHIFT         (14U)
/*! LPOSC_PD - 1 MHz Low-Power oscillator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_LPOSC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_LPOSC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_LPOSC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_RBBSRAM_PD_MASK        (0x8000U)
#define SYSCTL0_PDRUNCFG0_RBBSRAM_PD_SHIFT       (15U)
/*! RBBSRAM_PD - Reverse body-bias SRAM
 *  0b0..Enables SRAM Reverse Body Bias
 *  0b1..Disables SRAM Reverse Body Bias
 */
#define SYSCTL0_PDRUNCFG0_RBBSRAM_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_RBBSRAM_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_RBBSRAM_PD_MASK)

#define SYSCTL0_PDRUNCFG0_FFRO_PD_MASK           (0x10000U)
#define SYSCTL0_PDRUNCFG0_FFRO_PD_SHIFT          (16U)
/*! FFRO_PD - FFRO 192/96 MHz internal oscillator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_FFRO_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_FFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_FFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_MASK      (0x20000U)
#define SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_SHIFT     (17U)
/*! SYSPLLLDO_PD - System PLL internal regulator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_MASK      (0x40000U)
#define SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_SHIFT     (18U)
/*! SYSPLLANA_PD - System PLL analog functions
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_SYSPLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_MASK      (0x80000U)
#define SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_SHIFT     (19U)
/*! AUDPLLLDO_PD - Audio PLL internal regulator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_MASK      (0x100000U)
#define SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_SHIFT     (20U)
/*! AUDPLLANA_PD - Audio PLL analog functions
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_AUDPLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_ADC_PD_MASK            (0x200000U)
#define SYSCTL0_PDRUNCFG0_ADC_PD_SHIFT           (21U)
/*! ADC_PD - ADC analog functions
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_ADC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ADC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_ADC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_ADC_LP_MASK            (0x400000U)
#define SYSCTL0_PDRUNCFG0_ADC_LP_SHIFT           (22U)
/*! ADC_LP - ADC low power mode
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_ADC_LP(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ADC_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_ADC_LP_MASK)

#define SYSCTL0_PDRUNCFG0_ADC_TEMPSNS_PD_MASK    (0x800000U)
#define SYSCTL0_PDRUNCFG0_ADC_TEMPSNS_PD_SHIFT   (23U)
/*! ADC_TEMPSNS_PD - ADC temperature sensor
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_ADC_TEMPSNS_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ADC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_ADC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_PMC_TEMPSNS_PD_MASK    (0x1000000U)
#define SYSCTL0_PDRUNCFG0_PMC_TEMPSNS_PD_SHIFT   (24U)
/*! PMC_TEMPSNS_PD - PMC temperature sensor
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_PMC_TEMPSNS_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_PMC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_ACMP_PD_MASK           (0x2000000U)
#define SYSCTL0_PDRUNCFG0_ACMP_PD_SHIFT          (25U)
/*! ACMP_PD - Analog comparator
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG0_ACMP_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ACMP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_ACMP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD_FSPI0_REF_PD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD_FSPI0_REF_PD_SHIFT (27U)
/*! HSPAD_FSPI0_REF_PD - Hi-speed pad sleep mode
 *  0b0..High speed pad refs in normal mode
 *  0b1..High speed pad refs in sleep mode
 */
#define SYSCTL0_PDRUNCFG0_HSPAD_FSPI0_REF_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD_FSPI0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD_FSPI0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD_SDIO0_REF_PD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD_SDIO0_REF_PD_SHIFT (29U)
/*! HSPAD_SDIO0_REF_PD - High Speed Pad VREF
 *  0b0..Normal mode
 *  0b1..Sleep mode
 */
#define SYSCTL0_PDRUNCFG0_HSPAD_SDIO0_REF_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD_SDIO0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD_SDIO0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD_FSPI1_REF_PD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD_FSPI1_REF_PD_SHIFT (31U)
/*! HSPAD_FSPI1_REF_PD - Hi speed pad sleep mode
 *  0b0..High speed pad refs in normal mode
 *  0b1..High speed pad refs in sleep mode
 */
#define SYSCTL0_PDRUNCFG0_HSPAD_FSPI1_REF_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD_FSPI1_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD_FSPI1_REF_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1 - Run configuration 1 */
/*! @{ */

#define SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_MASK       (0x2U)
#define SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_SHIFT      (1U)
/*! PQ_SRAM_PPD - Power Quad SRAM Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_APD_SHIFT (2U)
/*! FLEXSPI0_SRAM_APD - FLEXSPI0 SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI0_SRAM_PPD - FLEXSPI0 SRAM Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_FLEXSPI0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_APD_MASK (0x10U)
#define SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_APD_SHIFT (4U)
/*! FLEXSPI1_SRAM_APD - FLEXSPI1 SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_PPD_MASK (0x20U)
#define SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_PPD_SHIFT (5U)
/*! FLEXSPI1_SRAM_PPD - FLEXSPI1 SRAM Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_FLEXSPI1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_MASK    (0x40U)
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_SHIFT   (6U)
/*! USBHS_SRAM_APD - USBHS SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_MASK    (0x80U)
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_SHIFT   (7U)
/*! USBHS_SRAM_PPD - USBHS SRAM Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_MASK   (0x100U)
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_SHIFT  (8U)
/*! USDHC0_SRAM_APD - USDHC0 SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_MASK   (0x200U)
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_SHIFT  (9U)
/*! USDHC0_SRAM_PPD - USDHC0 SRAM_ Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_MASK   (0x400U)
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_SHIFT  (10U)
/*! USDHC1_SRAM_APD - USDHC1 SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_MASK   (0x800U)
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_SHIFT  (11U)
/*! USDHC1_SRAM_PPD - USDHC1 SRAM Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_MASK   (0x2000U)
#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_SHIFT  (13U)
/*! CASPER_SRAM_PPD - CASPER SRAM Periphery Power
 *  0b0..Enable
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_GPU_SRAM_APD_MASK      (0x4000U)
#define SYSCTL0_PDRUNCFG1_GPU_SRAM_APD_SHIFT     (14U)
/*! GPU_SRAM_APD - GPU Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_GPU_SRAM_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_GPU_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_GPU_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_GPU_SRAM_PPD_MASK      (0x8000U)
#define SYSCTL0_PDRUNCFG1_GPU_SRAM_PPD_SHIFT     (15U)
/*! GPU_SRAM_PPD - GPU Periphery Power
 *  0b0..Enable
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG1_GPU_SRAM_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_GPU_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_GPU_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_APD_SHIFT (16U)
/*! SMARTDMA_SRAM_APD - SMARTDMA SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_PPD_SHIFT (17U)
/*! SMARTDMA_SRAM_PPD - SMARTDMA SRAM Periphery Power
 *  0b0..Enable
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SMARTDMA_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_APD_MASK  (0x40000U)
#define SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_APD_SHIFT (18U)
/*! MIPIDSI_SRAM_APD - MIPIDSI SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_PPD_MASK  (0x80000U)
#define SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_PPD_SHIFT (19U)
/*! MIPIDSI_SRAM_PPD - MIPIDSI SRAM Periphery Power
 *  0b0..Enable
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_MIPIDSI_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_LCDIF_SRAM_APD_MASK    (0x100000U)
#define SYSCTL0_PDRUNCFG1_LCDIF_SRAM_APD_SHIFT   (20U)
/*! LCDIF_SRAM_APD - LCDIF SRAM Array Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG1_LCDIF_SRAM_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_LCDIF_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_LCDIF_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_LCDIF_SRAM_PPD_MASK    (0x200000U)
#define SYSCTL0_PDRUNCFG1_LCDIF_SRAM_PPD_SHIFT   (21U)
/*! LCDIF_SRAM_PPD - LCDIF SRAM Periphery Power
 *  0b0..Power down disabled or Powered ON
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG1_LCDIF_SRAM_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_LCDIF_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_LCDIF_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_DSP_PD_MASK            (0x2000000U)
#define SYSCTL0_PDRUNCFG1_DSP_PD_SHIFT           (25U)
/*! DSP_PD - DSP
 *  0b0..DSP not power gated
 *  0b1..DSP power gated
 */
#define SYSCTL0_PDRUNCFG1_DSP_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_DSP_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_DSP_PD_MASK)

#define SYSCTL0_PDRUNCFG1_MIPIDSI_PD_MASK        (0x4000000U)
#define SYSCTL0_PDRUNCFG1_MIPIDSI_PD_SHIFT       (26U)
/*! MIPIDSI_PD - MIPIDSI
 *  0b0..MIPI DSI not power gated
 *  0b1..MIPI DSI power gated
 */
#define SYSCTL0_PDRUNCFG1_MIPIDSI_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_MIPIDSI_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_MIPIDSI_PD_MASK)

#define SYSCTL0_PDRUNCFG1_OTP_PD_MASK            (0x8000000U)
#define SYSCTL0_PDRUNCFG1_OTP_PD_SHIFT           (27U)
/*! OTP_PD - OTP
 *  0b0..Powered
 *  0b1..Not Powered
 */
#define SYSCTL0_PDRUNCFG1_OTP_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_OTP_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_OTP_PD_MASK)

#define SYSCTL0_PDRUNCFG1_ROM_PD_MASK            (0x10000000U)
#define SYSCTL0_PDRUNCFG1_ROM_PD_SHIFT           (28U)
/*! ROM_PD - Array periphery power for ROM
 *  0b0..ROM Powered
 *  0b1..ROM not Powered
 */
#define SYSCTL0_PDRUNCFG1_ROM_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_ROM_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_ROM_PD_MASK)

#define SYSCTL0_PDRUNCFG1_HSPAD_SDIO1_REF_PD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG1_HSPAD_SDIO1_REF_PD_SHIFT (30U)
/*! HSPAD_SDIO1_REF_PD - High speed pad SDIO1 sleep mode
 *  0b0..Enabled
 *  0b1..Powerdown
 */
#define SYSCTL0_PDRUNCFG1_HSPAD_SDIO1_REF_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_HSPAD_SDIO1_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_HSPAD_SDIO1_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SRAM_SLEEP_MASK        (0x80000000U)
#define SYSCTL0_PDRUNCFG1_SRAM_SLEEP_SHIFT       (31U)
/*! SRAM_SLEEP - SRAM sleep mode
 *  0b0..RAM Normal mode
 *  0b1..RAM Sleep mode. Needed when vddcore can be < 0.6V to ensure contents retained. Memories not accessible in this mode.
 */
#define SYSCTL0_PDRUNCFG1_SRAM_SLEEP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDRUNCFG1_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG2 - Run configuration 2 */
/*! @{ */

#define SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_MASK      (0x1U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_SHIFT     (0U)
/*! SRAM_IF0_APD - Array Power for RAM interface 0
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF0_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_MASK      (0x2U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_SHIFT     (1U)
/*! SRAM_IF1_APD - Array Power for RAM interface 1
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF1_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_MASK      (0x4U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_SHIFT     (2U)
/*! SRAM_IF2_APD - Array Power for RAM interface 2
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF2_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_MASK      (0x8U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_SHIFT     (3U)
/*! SRAM_IF3_APD - Array Power for RAM interface 3
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF3_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_MASK      (0x10U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_SHIFT     (4U)
/*! SRAM_IF4_APD - Array Power for RAM interface 4
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF4_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_MASK      (0x20U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_SHIFT     (5U)
/*! SRAM_IF5_APD - Array Power for RAM interface 5
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF5_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_MASK      (0x40U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_SHIFT     (6U)
/*! SRAM_IF6_APD - Array Power for RAM interface 6
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF6_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_MASK      (0x80U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_SHIFT     (7U)
/*! SRAM_IF7_APD - Array Power for RAM interface 7
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF7_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_MASK      (0x100U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_SHIFT     (8U)
/*! SRAM_IF8_APD - Array Power for RAM interface 8
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF8_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_MASK      (0x200U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_SHIFT     (9U)
/*! SRAM_IF9_APD - Array Power for RAM interface 9
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF9_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_MASK     (0x400U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_SHIFT    (10U)
/*! SRAM_IF10_APD - Array Power for RAM interface 10
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF10_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_MASK     (0x800U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_SHIFT    (11U)
/*! SRAM_IF11_APD - Array Power for RAM interface 11
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF11_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_MASK     (0x1000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_SHIFT    (12U)
/*! SRAM_IF12_APD - Array Power for RAM interface 12
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF12_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_MASK     (0x2000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_SHIFT    (13U)
/*! SRAM_IF13_APD - Array Power for RAM interface 13
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF13_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_MASK     (0x4000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_SHIFT    (14U)
/*! SRAM_IF14_APD - Array Power for RAM interface 14
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF14_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_MASK     (0x8000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_SHIFT    (15U)
/*! SRAM_IF15_APD - Array Power for RAM interface 15
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF15_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_MASK     (0x10000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_SHIFT    (16U)
/*! SRAM_IF16_APD - Array Power for RAM interface 16
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF16_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_MASK     (0x20000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_SHIFT    (17U)
/*! SRAM_IF17_APD - Array Power for RAM interface 17
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF17_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_MASK     (0x40000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_SHIFT    (18U)
/*! SRAM_IF18_APD - Array Power for RAM interface 18
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF18_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_MASK     (0x80000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_SHIFT    (19U)
/*! SRAM_IF19_APD - Array Power for RAM interface 19
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF19_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_MASK     (0x100000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_SHIFT    (20U)
/*! SRAM_IF20_APD - Array Power for RAM interface 20
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF20_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_MASK     (0x200000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_SHIFT    (21U)
/*! SRAM_IF21_APD - Array Power for RAM interface 21
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF21_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_MASK     (0x400000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_SHIFT    (22U)
/*! SRAM_IF22_APD - Array Power for RAM interface 22
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF22_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_MASK     (0x800000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_SHIFT    (23U)
/*! SRAM_IF23_APD - Array Power for RAM interface 23
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF23_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_MASK     (0x1000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_SHIFT    (24U)
/*! SRAM_IF24_APD - Array Power for RAM interface 24
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF24_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_MASK     (0x2000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_SHIFT    (25U)
/*! SRAM_IF25_APD - Array Power for RAM interface 25
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF25_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_MASK     (0x4000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_SHIFT    (26U)
/*! SRAM_IF26_APD - Array Power for RAM interface 26
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF26_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_MASK     (0x8000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_SHIFT    (27U)
/*! SRAM_IF27_APD - Array Power for RAM interface 27
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF27_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_MASK     (0x10000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_SHIFT    (28U)
/*! SRAM_IF28_APD - Array Power for RAM interface 28
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF28_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_MASK     (0x20000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_SHIFT    (29U)
/*! SRAM_IF29_APD - Array Power for RAM interface 29
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF29_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF30_APD_MASK     (0x40000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF30_APD_SHIFT    (30U)
/*! SRAM_IF30_APD - Array Power for RAM interface 30
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF30_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF30_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF30_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF31_APD_MASK     (0x80000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF31_APD_SHIFT    (31U)
/*! SRAM_IF31_APD - Array Power for RAM interface 31
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF31_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF31_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF31_APD_MASK)
/*! @} */

/*! @name PDRUNCFG3 - Run configuration 3 */
/*! @{ */

#define SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_MASK      (0x1U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_SHIFT     (0U)
/*! SRAM_IF0_PPD - Periphery power for RAM interface 0.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_MASK      (0x2U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_SHIFT     (1U)
/*! SRAM_IF1_PPD - Periphery power for RAM interface 1.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_MASK      (0x4U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_SHIFT     (2U)
/*! SRAM_IF2_PPD - Periphery power for RAM interface 2.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_MASK      (0x8U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_SHIFT     (3U)
/*! SRAM_IF3_PPD - Periphery power for RAM interface 3.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_MASK      (0x10U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_SHIFT     (4U)
/*! SRAM_IF4_PPD - Periphery power for RAM interface 4.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_MASK      (0x20U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_SHIFT     (5U)
/*! SRAM_IF5_PPD - Periphery power for RAM interface 5.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_MASK      (0x40U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_SHIFT     (6U)
/*! SRAM_IF6_PPD - Periphery power for RAM interface 6.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_MASK      (0x80U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_SHIFT     (7U)
/*! SRAM_IF7_PPD - Periphery power for RAM interface 7.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_MASK      (0x100U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_SHIFT     (8U)
/*! SRAM_IF8_PPD - Periphery power for RAM interface 8.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_MASK      (0x200U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_SHIFT     (9U)
/*! SRAM_IF9_PPD - Periphery power for RAM interface 9.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_MASK     (0x400U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_SHIFT    (10U)
/*! SRAM_IF10_PPD - Periphery power for RAM interface 10.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_MASK     (0x800U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_SHIFT    (11U)
/*! SRAM_IF11_PPD - Periphery power for RAM interface 11.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_MASK     (0x1000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_SHIFT    (12U)
/*! SRAM_IF12_PPD - Periphery power for RAM interface 12.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_MASK     (0x2000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_SHIFT    (13U)
/*! SRAM_IF13_PPD - Periphery power for RAM interface 13.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_MASK     (0x4000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_SHIFT    (14U)
/*! SRAM_IF14_PPD - Periphery power for RAM interface 14.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_MASK     (0x8000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_SHIFT    (15U)
/*! SRAM_IF15_PPD - Periphery power for RAM interface 15.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_MASK     (0x10000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_SHIFT    (16U)
/*! SRAM_IF16_PPD - Periphery power for RAM interface 16.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_MASK     (0x20000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_SHIFT    (17U)
/*! SRAM_IF17_PPD - Periphery power for RAM interface 17.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_MASK     (0x40000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_SHIFT    (18U)
/*! SRAM_IF18_PPD - Periphery power for RAM interface 18.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_MASK     (0x80000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_SHIFT    (19U)
/*! SRAM_IF19_PPD - Periphery power for RAM interface 19.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_MASK     (0x100000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_SHIFT    (20U)
/*! SRAM_IF20_PPD - Periphery power for RAM interface 20.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_MASK     (0x200000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_SHIFT    (21U)
/*! SRAM_IF21_PPD - Periphery power for RAM interface 21.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_MASK     (0x400000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_SHIFT    (22U)
/*! SRAM_IF22_PPD - Periphery power for RAM interface 22.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_MASK     (0x800000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_SHIFT    (23U)
/*! SRAM_IF23_PPD - Periphery power for RAM interface 23.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_MASK     (0x1000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_SHIFT    (24U)
/*! SRAM_IF24_PPD - Periphery power for RAM interface 24.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_MASK     (0x2000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_SHIFT    (25U)
/*! SRAM_IF25_PPD - Periphery power for RAM interface 25.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_MASK     (0x4000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_SHIFT    (26U)
/*! SRAM_IF26_PPD - Periphery power for RAM interface 26.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_MASK     (0x8000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_SHIFT    (27U)
/*! SRAM_IF27_PPD - Periphery power for RAM interface 27.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_MASK     (0x10000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_SHIFT    (28U)
/*! SRAM_IF28_PPD - Periphery power for RAM interface 28.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_MASK     (0x20000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_SHIFT    (29U)
/*! SRAM_IF29_PPD - Periphery power for RAM interface 29.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF30_PPD_MASK     (0x40000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF30_PPD_SHIFT    (30U)
/*! SRAM_IF30_PPD - Periphery power for RAM interface 30.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF30_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF30_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF30_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF31_PPD_MASK     (0x80000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF31_PPD_SHIFT    (31U)
/*! SRAM_IF31_PPD - Periphery power for RAM interface 31.
 *  0b0..Power down disabled or Powered ON
 *  0b1..Power down enabled or Powered OFF
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF31_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF31_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF31_PPD_MASK)
/*! @} */

/*! @name PDRUNCFG0_SET - Run configuration 0 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG0_SET_MAINCLK_SHUTOFF_MASK (0x1U)
#define SYSCTL0_PDRUNCFG0_SET_MAINCLK_SHUTOFF_SHIFT (0U)
/*! MAINCLK_SHUTOFF - Main clock shut off
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_MAINCLK_SHUTOFF_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_MAINCLK_SHUTOFF_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_MASK    (0x2U)
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_SHIFT   (1U)
/*! PMIC_MODE0 - PMIC_MODE0 pin
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_MASK    (0x4U)
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_SHIFT   (2U)
/*! PMIC_MODE1 - PMIC_MODE1 pin
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_MASK)

#define SYSCTL0_PDRUNCFG0_SET_DEEP_PD_MASK       (0x8U)
#define SYSCTL0_PDRUNCFG0_SET_DEEP_PD_SHIFT      (3U)
/*! DEEP_PD - Deep power-down mode
 *  0b0..VDDCORE supply remains on during WFI (deep_sleep mode)
 *  0b1..VDDCORE powered-off during WFI (deep_powerdown mode)
 */
#define SYSCTL0_PDRUNCFG0_SET_DEEP_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_DEEP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_DEEP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_MASK (0x10U)
#define SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_SHIFT (4U)
/*! VDDCOREREG_LP - Vddcore regulator mode when using on-chip regulator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_FRO_CG_MASK        (0x20U)
#define SYSCTL0_PDRUNCFG0_SET_FRO_CG_SHIFT       (5U)
/*! FRO_CG - 192/96 FRO Clock Gate
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_FRO_CG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_FRO_CG_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_FRO_CG_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_MASK     (0x40U)
#define SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_SHIFT    (6U)
/*! PMCREF_LP - Internal PMC references LP mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMCREF_LP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_MASK     (0x80U)
#define SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_SHIFT    (7U)
/*! HVD1V8_PD - HVD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_MASK    (0x100U)
#define SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_SHIFT   (8U)
/*! PORCORE_LP - Internal PMC references LP mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PORCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_MASK    (0x200U)
#define SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_SHIFT   (9U)
/*! LVDCORE_LP - LVD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_MASK    (0x400U)
#define SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_SHIFT   (10U)
/*! HVDCORE_PD - HVD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_RBB_PD_MASK        (0x800U)
#define SYSCTL0_PDRUNCFG0_SET_RBB_PD_SHIFT       (11U)
/*! RBB_PD - Reverse body-bias
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_RBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_RBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_RBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_FBB_PD_MASK        (0x1000U)
#define SYSCTL0_PDRUNCFG0_SET_FBB_PD_SHIFT       (12U)
/*! FBB_PD - Forward body-bias
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_FBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_FBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_FBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_MASK    (0x2000U)
#define SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_SHIFT   (13U)
/*! SYSXTAL_PD - Main crystal oscillator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_MASK      (0x4000U)
#define SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_SHIFT     (14U)
/*! LPOSC_PD - 1 MHz Low-Power oscillator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_LPOSC_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_RBBSRAM_PD_MASK    (0x8000U)
#define SYSCTL0_PDRUNCFG0_SET_RBBSRAM_PD_SHIFT   (15U)
/*! RBBSRAM_PD - Reverse body-bias SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_RBBSRAM_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_RBBSRAM_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_RBBSRAM_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_FFRO_PD_MASK       (0x10000U)
#define SYSCTL0_PDRUNCFG0_SET_FFRO_PD_SHIFT      (16U)
/*! FFRO_PD - FFRO 19296 MHz internal oscillator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_FFRO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_FFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_FFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_MASK  (0x20000U)
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_SHIFT (17U)
/*! SYSPLLLDO_PD - System PLL internal regulator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_MASK  (0x40000U)
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_SHIFT (18U)
/*! SYSPLLANA_PD - System PLL analog functions
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_MASK  (0x80000U)
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_SHIFT (19U)
/*! AUDPLLLDO_PD - Audio PLL internal regulator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_MASK  (0x100000U)
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_SHIFT (20U)
/*! AUDPLLANA_PD - Audio PLL analog functions
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ADC_PD_MASK        (0x200000U)
#define SYSCTL0_PDRUNCFG0_SET_ADC_PD_SHIFT       (21U)
/*! ADC_PD - ADC analog functions
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ADC_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ADC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ADC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ADC_LP_MASK        (0x400000U)
#define SYSCTL0_PDRUNCFG0_SET_ADC_LP_SHIFT       (22U)
/*! ADC_LP - ADC low power mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ADC_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ADC_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ADC_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ADC_TEMPSNS_PD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG0_SET_ADC_TEMPSNS_PD_SHIFT (23U)
/*! ADC_TEMPSNS_PD - ADC temperature sensor
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ADC_TEMPSNS_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ADC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ADC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PMC_TEMPSNS_PD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG0_SET_PMC_TEMPSNS_PD_SHIFT (24U)
/*! PMC_TEMPSNS_PD - PMC temperature sensor
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMC_TEMPSNS_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ACMP_PD_MASK       (0x2000000U)
#define SYSCTL0_PDRUNCFG0_SET_ACMP_PD_SHIFT      (25U)
/*! ACMP_PD - Analog comparator
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ACMP_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ACMP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ACMP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI0_REF_PD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI0_REF_PD_SHIFT (27U)
/*! HSPAD_FSPI0_REF_PD - High speed pad FSPI0 voltage detect sleep mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI0_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD_SDIO0_REF_PD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD_SDIO0_REF_PD_SHIFT (29U)
/*! HSPAD_SDIO0_REF_PD - High speed pad sleep mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD_SDIO0_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD_SDIO0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD_SDIO0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI1_REF_PD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI1_REF_PD_SHIFT (31U)
/*! HSPAD_FSPI1_REF_PD - High speed pad FSPI1 sleep mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI1_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI1_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD_FSPI1_REF_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1_SET - Run configuration 1 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_MASK   (0x1U)
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_SHIFT  (0U)
/*! PQ_SRAM_APD - Array power for PowerQuad RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_MASK   (0x2U)
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_SHIFT  (1U)
/*! PQ_SRAM_PPD - Periphery power for PowerQuad RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_APD_SHIFT (2U)
/*! FLEXSPI0_SRAM_APD - Array power for FLEXSPI0
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI0_SRAM_PPD - Periphery power for FLEXSPI0
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_FLEXSPI0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_APD_MASK (0x10U)
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_APD_SHIFT (4U)
/*! FLEXSPI1_SRAM_APD - Array power for FLEXSPI1
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_PPD_MASK (0x20U)
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_PPD_SHIFT (5U)
/*! FLEXSPI1_SRAM_PPD - Periphery power for FLEXSPI1
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_FLEXSPI1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_MASK (0x40U)
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_SHIFT (6U)
/*! USBHS_SRAM_APD - Array power for USB RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_MASK (0x80U)
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_SHIFT (7U)
/*! USBHS_SRAM_PPD - Periphery power for USB RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_MASK (0x100U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_SHIFT (8U)
/*! USDHC0_SRAM_APD - Array power for uSDHC0 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_MASK (0x200U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_SHIFT (9U)
/*! USDHC0_SRAM_PPD - Periphery power for uSDHC0 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_SHIFT (10U)
/*! USDHC1_SRAM_APD - Array power for uSDHC1 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_SHIFT (11U)
/*! USDHC1_SRAM_PPD - Periphery power for uSDHC1 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_SHIFT (13U)
/*! CASPER_SRAM_PPD - Periphery power for Casper RAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_APD_MASK  (0x4000U)
#define SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_APD_SHIFT (14U)
/*! GPU_SRAM_APD - Array power for GPU SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_PPD_MASK  (0x8000U)
#define SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_PPD_SHIFT (15U)
/*! GPU_SRAM_PPD - Periphery power for GPU SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_GPU_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_APD_SHIFT (16U)
/*! SMARTDMA_SRAM_APD - Array power for SMARTDMA SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_PPD_SHIFT (17U)
/*! SMARTDMA_SRAM_PPD - Periphery power for SMARTDMA SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_SMARTDMA_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_APD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_APD_SHIFT (18U)
/*! MIPIDSI_SRAM_APD - Array power for MIPIDSI SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_PPD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_PPD_SHIFT (19U)
/*! MIPIDSI_SRAM_PPD - Periphery power for MIPIDSI SRAM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_MIPIDSI_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_APD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_APD_SHIFT (20U)
/*! LCDIF_SRAM_APD - Array power for LCDIF
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_PPD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_PPD_SHIFT (21U)
/*! LCDIF_SRAM_PPD - Periphery power for LCDIF
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_LCDIF_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_DSP_PD_MASK        (0x2000000U)
#define SYSCTL0_PDRUNCFG1_SET_DSP_PD_SHIFT       (25U)
/*! DSP_PD - Array and periphery power for DSP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_DSP_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_DSP_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_DSP_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_PD_MASK    (0x4000000U)
#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_PD_SHIFT   (26U)
/*! MIPIDSI_PD - Array and periphery power for MIPIDSI
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_MIPIDSI_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_MIPIDSI_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_MIPIDSI_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_OTP_PD_MASK        (0x8000000U)
#define SYSCTL0_PDRUNCFG1_SET_OTP_PD_SHIFT       (27U)
/*! OTP_PD - Array and periphery power for OTP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_OTP_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_OTP_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_OTP_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_ROM_PD_MASK        (0x10000000U)
#define SYSCTL0_PDRUNCFG1_SET_ROM_PD_SHIFT       (28U)
/*! ROM_PD - Array and periphery power for ROM
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_ROM_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_ROM_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_ROM_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_HSPAD_SDIO1_REF_PD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG1_SET_HSPAD_SDIO1_REF_PD_SHIFT (30U)
/*! HSPAD_SDIO1_REF_PD - High speed pad sleep mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_HSPAD_SDIO1_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_HSPAD_SDIO1_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_HSPAD_SDIO1_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_MASK    (0x80000000U)
#define SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_SHIFT   (31U)
/*! SRAM_SLEEP - SRAM sleep mode
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG2_SET - Run configuration 2 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_SHIFT (0U)
/*! SRAM_IF0_APD - Array power for SRAM interface 0.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_SHIFT (1U)
/*! SRAM_IF1_APD - Array power for SRAM interface 1.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_SHIFT (2U)
/*! SRAM_IF2_APD - Array power for SRAM interface 2.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_SHIFT (3U)
/*! SRAM_IF3_APD - Array power for SRAM interface 3.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_SHIFT (4U)
/*! SRAM_IF4_APD - Array power for SRAM interface 4.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_SHIFT (5U)
/*! SRAM_IF5_APD - Array power for SRAM interface 5.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_SHIFT (6U)
/*! SRAM_IF6_APD - Array power for SRAM interface 6.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_SHIFT (7U)
/*! SRAM_IF7_APD - Array power for SRAM interface 7.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_SHIFT (8U)
/*! SRAM_IF8_APD - Array power for SRAM interface 8.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_SHIFT (9U)
/*! SRAM_IF9_APD - Array power for SRAM interface 9.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_SHIFT (10U)
/*! SRAM_IF10_APD - Array power for SRAM interface 10.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_SHIFT (11U)
/*! SRAM_IF11_APD - Array power for SRAM interface 11.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_SHIFT (12U)
/*! SRAM_IF12_APD - Array power for SRAM interface 12.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_SHIFT (13U)
/*! SRAM_IF13_APD - Array power for SRAM interface 13.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_SHIFT (14U)
/*! SRAM_IF14_APD - Array power for SRAM interface 14.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_SHIFT (15U)
/*! SRAM_IF15_APD - Array power for SRAM interface 15.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_SHIFT (16U)
/*! SRAM_IF16_APD - Array power for SRAM interface 16.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_SHIFT (17U)
/*! SRAM_IF17_APD - Array power for SRAM interface 17.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_SHIFT (18U)
/*! SRAM_IF18_APD - Array power for SRAM interface 18.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_SHIFT (19U)
/*! SRAM_IF19_APD - Array power for SRAM interface 19.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_SHIFT (20U)
/*! SRAM_IF20_APD - Array power for SRAM interface 20.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_SHIFT (21U)
/*! SRAM_IF21_APD - Array power for SRAM interface 21.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_SHIFT (22U)
/*! SRAM_IF22_APD - Array power for SRAM interface 22.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_SHIFT (23U)
/*! SRAM_IF23_APD - Array power for SRAM interface 23.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_SHIFT (24U)
/*! SRAM_IF24_APD - Array power for SRAM interface 24.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_SHIFT (25U)
/*! SRAM_IF25_APD - Array power for SRAM interface 25.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_SHIFT (26U)
/*! SRAM_IF26_APD - Array power for SRAM interface 26.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_SHIFT (27U)
/*! SRAM_IF27_APD - Array power for SRAM interface 27.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_SHIFT (28U)
/*! SRAM_IF28_APD - Array power for SRAM interface 28.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_SHIFT (29U)
/*! SRAM_IF29_APD - Array power for SRAM interface 29.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF30_APD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF30_APD_SHIFT (30U)
/*! SRAM_IF30_APD - Array power for SRAM interface 30.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF30_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF30_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF30_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF31_APD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF31_APD_SHIFT (31U)
/*! SRAM_IF31_APD - Array power for SRAM interface 31.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF31_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF31_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF31_APD_MASK)
/*! @} */

/*! @name PDRUNCFG3_SET - Run configuration 3 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_SHIFT (0U)
/*! SRAM_IF0_PPD - Periphery power for RAM interface 0.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_SHIFT (1U)
/*! SRAM_IF1_PPD - Periphery power for RAM interface 1.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_SHIFT (2U)
/*! SRAM_IF2_PPD - Periphery power for RAM interface 2.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_SHIFT (3U)
/*! SRAM_IF3_PPD - Periphery power for RAM interface 3.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_SHIFT (4U)
/*! SRAM_IF4_PPD - Periphery power for RAM interface 4.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_SHIFT (5U)
/*! SRAM_IF5_PPD - Periphery power for RAM interface 5.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_SHIFT (6U)
/*! SRAM_IF6_PPD - Periphery power for RAM interface 6.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_SHIFT (7U)
/*! SRAM_IF7_PPD - Periphery power for RAM interface 7.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_SHIFT (8U)
/*! SRAM_IF8_PPD - Periphery power for RAM interface 8.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_SHIFT (9U)
/*! SRAM_IF9_PPD - Periphery power for RAM interface 9.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_SHIFT (10U)
/*! SRAM_IF10_PPD - Periphery power for RAM interface 10.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_SHIFT (11U)
/*! SRAM_IF11_PPD - Periphery power for RAM interface 11.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_SHIFT (12U)
/*! SRAM_IF12_PPD - Periphery power for RAM interface 12.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_SHIFT (13U)
/*! SRAM_IF13_PPD - Periphery power for RAM interface 13.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_SHIFT (14U)
/*! SRAM_IF14_PPD - Periphery power for RAM interface 14.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_SHIFT (15U)
/*! SRAM_IF15_PPD - Periphery power for RAM interface 15.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_SHIFT (16U)
/*! SRAM_IF16_PPD - Periphery power for RAM interface 16.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_SHIFT (17U)
/*! SRAM_IF17_PPD - Periphery power for RAM interface 17.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_SHIFT (18U)
/*! SRAM_IF18_PPD - Periphery power for RAM interface 18.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_SHIFT (19U)
/*! SRAM_IF19_PPD - Periphery power for RAM interface 19.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_SHIFT (20U)
/*! SRAM_IF20_PPD - Periphery power for RAM interface 20.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_SHIFT (21U)
/*! SRAM_IF21_PPD - Periphery power for RAM interface 21.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_SHIFT (22U)
/*! SRAM_IF22_PPD - Periphery power for RAM interface 22.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_SHIFT (23U)
/*! SRAM_IF23_PPD - Periphery power for RAM interface 23.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_SHIFT (24U)
/*! SRAM_IF24_PPD - Periphery power for RAM interface 24.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_SHIFT (25U)
/*! SRAM_IF25_PPD - Periphery power for RAM interface 25.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_SHIFT (26U)
/*! SRAM_IF26_PPD - Periphery power for RAM interface 26.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_SHIFT (27U)
/*! SRAM_IF27_PPD - Periphery power for RAM interface 27.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_SHIFT (28U)
/*! SRAM_IF28_PPD - Periphery power for RAM interface 28.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_SHIFT (29U)
/*! SRAM_IF29_PPD - Periphery power for RAM interface 29.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF30_PPD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF30_PPD_SHIFT (30U)
/*! SRAM_IF30_PPD - Periphery power for RAM interface 30.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF30_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF30_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF30_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF31_PPD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF31_PPD_SHIFT (31U)
/*! SRAM_IF31_PPD - Periphery power for RAM interface 31.
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF31_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF31_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF31_PPD_MASK)
/*! @} */

/*! @name PDRUNCFG0_CLR - Run configuration 0 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG0_CLR_MAINCLK_SHUTOFF_MASK (0x1U)
#define SYSCTL0_PDRUNCFG0_CLR_MAINCLK_SHUTOFF_SHIFT (0U)
/*! MAINCLK_SHUTOFF - Main clock shut off
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_MAINCLK_SHUTOFF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_MAINCLK_SHUTOFF_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_MAINCLK_SHUTOFF_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_MASK    (0x2U)
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_SHIFT   (1U)
/*! PMIC_MODE0 - PMIC_MODE0 device pin
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_MASK    (0x4U)
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_SHIFT   (2U)
/*! PMIC_MODE1 - PMIC_MODE1 device pin
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_DEEP_PD_MASK       (0x8U)
#define SYSCTL0_PDRUNCFG0_CLR_DEEP_PD_SHIFT      (3U)
/*! DEEP_PD - Deep power-down mode
 *  0b0..VDDCORE supply remains on during WFI (deep_sleep mode)
 *  0b1..VDDCORE powered-off during WFI (deep_powerdown mode)
 */
#define SYSCTL0_PDRUNCFG0_CLR_DEEP_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_DEEP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_DEEP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_MASK (0x10U)
#define SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_SHIFT (4U)
/*! VDDCOREREG_LP - Vddcore regulator mode when using on-chip regulator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_FRO_CG_MASK        (0x20U)
#define SYSCTL0_PDRUNCFG0_CLR_FRO_CG_SHIFT       (5U)
/*! FRO_CG - 192/96 FRO Clock Gate
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_FRO_CG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_FRO_CG_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_FRO_CG_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_MASK     (0x40U)
#define SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_SHIFT    (6U)
/*! PMCREF_LP - Internal PMC references LP mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_MASK     (0x80U)
#define SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_SHIFT    (7U)
/*! HVD1V8_PD - HVD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_MASK    (0x100U)
#define SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_SHIFT   (8U)
/*! PORCORE_LP - LVD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_MASK    (0x200U)
#define SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_SHIFT   (9U)
/*! LVDCORE_LP - LVD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_MASK    (0x400U)
#define SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_SHIFT   (10U)
/*! HVDCORE_PD - HVD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_RBB_PD_MASK        (0x800U)
#define SYSCTL0_PDRUNCFG0_CLR_RBB_PD_SHIFT       (11U)
/*! RBB_PD - Reverse body-bias
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_RBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_RBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_RBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_FBB_PD_MASK        (0x1000U)
#define SYSCTL0_PDRUNCFG0_CLR_FBB_PD_SHIFT       (12U)
/*! FBB_PD - Forward body-bias
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_FBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_FBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_FBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_MASK    (0x2000U)
#define SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_SHIFT   (13U)
/*! SYSXTAL_PD - Main crystal oscillator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_MASK      (0x4000U)
#define SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_SHIFT     (14U)
/*! LPOSC_PD - 1 MHz Low-Power oscillator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_RBBSRAM_PD_MASK    (0x8000U)
#define SYSCTL0_PDRUNCFG0_CLR_RBBSRAM_PD_SHIFT   (15U)
/*! RBBSRAM_PD - Reverse body-bias SRAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_RBBSRAM_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_RBBSRAM_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_RBBSRAM_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_MASK       (0x10000U)
#define SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_SHIFT      (16U)
/*! FFRO_PD - FRO 16 MHz internal oscillator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_FFRO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_MASK  (0x20000U)
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_SHIFT (17U)
/*! SYSPLLLDO_PD - System PLL internal regulator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_MASK  (0x40000U)
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_SHIFT (18U)
/*! SYSPLLANA_PD - System PLL analog functions
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_MASK  (0x80000U)
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_SHIFT (19U)
/*! AUDPLLLDO_PD - Audio PLL internal regulator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_MASK  (0x100000U)
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_SHIFT (20U)
/*! AUDPLLANA_PD - Audio PLL analog functions
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ADC_PD_MASK        (0x200000U)
#define SYSCTL0_PDRUNCFG0_CLR_ADC_PD_SHIFT       (21U)
/*! ADC_PD - ADC analog functions
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ADC_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ADC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ADC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ADC_LP_MASK        (0x400000U)
#define SYSCTL0_PDRUNCFG0_CLR_ADC_LP_SHIFT       (22U)
/*! ADC_LP - ADC low power mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ADC_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ADC_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ADC_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ADC_TEMPSNS_PD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG0_CLR_ADC_TEMPSNS_PD_SHIFT (23U)
/*! ADC_TEMPSNS_PD - ADC temperature sensor
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ADC_TEMPSNS_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ADC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ADC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PMC_TEMPSNS_PD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG0_CLR_PMC_TEMPSNS_PD_SHIFT (24U)
/*! PMC_TEMPSNS_PD - PMC temperature sensor
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMC_TEMPSNS_PD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMC_TEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMC_TEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_MASK       (0x2000000U)
#define SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_SHIFT      (25U)
/*! ACMP_PD - Analog comparator
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ACMP_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI0_REF_PD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI0_REF_PD_SHIFT (27U)
/*! HSPAD_FSPI0_REF_PD - High speed pad FSPIO0 sleep mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI0_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_SDIO0_REF_PD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_SDIO0_REF_PD_SHIFT (29U)
/*! HSPAD_SDIO0_REF_PD - High speed pad sleep mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_SDIO0_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD_SDIO0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD_SDIO0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI1_REF_PD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI1_REF_PD_SHIFT (31U)
/*! HSPAD_FSPI1_REF_PD - High speed pad FSPIO1 sleep mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI1_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI1_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD_FSPI1_REF_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1_CLR - Run configuration 1 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_MASK   (0x1U)
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_SHIFT  (0U)
/*! PQ_SRAM_APD - Array power for PowerQuad RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_MASK   (0x2U)
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_SHIFT  (1U)
/*! PQ_SRAM_PPD - Periphery power for PowerQuad RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_APD_SHIFT (2U)
/*! FLEXSPI0_SRAM_APD - Array power for FlexSPI0
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI0_SRAM_PPD - Periphery power for FlexSPI0
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_FLEXSPI0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_APD_MASK (0x10U)
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_APD_SHIFT (4U)
/*! FLEXSPI1_SRAM_APD - Array power for FlexSPI1
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_PPD_MASK (0x20U)
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_PPD_SHIFT (5U)
/*! FLEXSPI1_SRAM_PPD - Periphery power for FlexSPI1
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_FLEXSPI1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_MASK (0x40U)
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_SHIFT (6U)
/*! USBHS_SRAM_APD - Array power for USB RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_MASK (0x80U)
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_SHIFT (7U)
/*! USBHS_SRAM_PPD - Periphery power for USB RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_MASK (0x100U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_SHIFT (8U)
/*! USDHC0_SRAM_APD - Array power for uSDHC0 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_MASK (0x200U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_SHIFT (9U)
/*! USDHC0_SRAM_PPD - Periphery power for uSDHC0 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_SHIFT (10U)
/*! USDHC1_SRAM_APD - Array power for uSDHC1 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_SHIFT (11U)
/*! USDHC1_SRAM_PPD - Periphery power for uSDHC1 (SD/MMC/SDIO interface) RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_SHIFT (13U)
/*! CASPER_SRAM_PPD - Periphery power for Casper RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_APD_MASK  (0x4000U)
#define SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_APD_SHIFT (14U)
/*! GPU_SRAM_APD - Array power for GPU SRAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_PPD_MASK  (0x8000U)
#define SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_PPD_SHIFT (15U)
/*! GPU_SRAM_PPD - Periphery power for GPU RAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_GPU_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_APD_SHIFT (16U)
/*! SMARTDMA_SRAM_APD - Array power for SMARTDMA SRAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_PPD_SHIFT (17U)
/*! SMARTDMA_SRAM_PPD - Periphery power for SMARTDMA SRAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_SMARTDMA_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_APD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_APD_SHIFT (18U)
/*! MIPIDSI_SRAM_APD - Array power for MIPIDSI SRAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_PPD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_PPD_SHIFT (19U)
/*! MIPIDSI_SRAM_PPD - Periphery power for MIPIDSI SRAM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_APD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_APD_SHIFT (20U)
/*! LCDIF_SRAM_APD - Array power for LCDIF
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_PPD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_PPD_SHIFT (21U)
/*! LCDIF_SRAM_PPD - Periphery power for LCDIF
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_LCDIF_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_DSP_PD_MASK        (0x2000000U)
#define SYSCTL0_PDRUNCFG1_CLR_DSP_PD_SHIFT       (25U)
/*! DSP_PD - Array and periphery power for DSP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_DSP_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_DSP_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_DSP_PD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_PD_MASK    (0x4000000U)
#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_PD_SHIFT   (26U)
/*! MIPIDSI_PD - Array and periphery power for MIPIDSI
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_MIPIDSI_PD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_OTP_PD_MASK        (0x8000000U)
#define SYSCTL0_PDRUNCFG1_CLR_OTP_PD_SHIFT       (27U)
/*! OTP_PD - Array and periphery power for OTP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_OTP_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_OTP_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_OTP_PD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_ROM_PD_MASK        (0x10000000U)
#define SYSCTL0_PDRUNCFG1_CLR_ROM_PD_SHIFT       (28U)
/*! ROM_PD - Array and periphery power for ROM
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_ROM_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_ROM_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_ROM_PD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_HSPAD_SDIO1_REF_PD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG1_CLR_HSPAD_SDIO1_REF_PD_SHIFT (30U)
/*! HSPAD_SDIO1_REF_PD - High speed pad sleep mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_HSPAD_SDIO1_REF_PD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_HSPAD_SDIO1_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_HSPAD_SDIO1_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_MASK    (0x80000000U)
#define SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_SHIFT   (31U)
/*! SRAM_SLEEP - SRAM sleep mode
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG2_CLR - Run configuration 2 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_SHIFT (0U)
/*! SRAM_IF0_APD - Array power for RAM interface 0
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_SHIFT (1U)
/*! SRAM_IF1_APD - Array power for RAM interface 1
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_SHIFT (2U)
/*! SRAM_IF2_APD - Array power for RAM interface 2
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_SHIFT (3U)
/*! SRAM_IF3_APD - Array power for RAM interface 3
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_SHIFT (4U)
/*! SRAM_IF4_APD - Array power for RAM interface 4
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_SHIFT (5U)
/*! SRAM_IF5_APD - Array power for RAM interface 5
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_SHIFT (6U)
/*! SRAM_IF6_APD - Array power for RAM interface 6
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_SHIFT (7U)
/*! SRAM_IF7_APD - Array power for RAM interface 7
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_SHIFT (8U)
/*! SRAM_IF8_APD - Array power for RAM interface 8
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_SHIFT (9U)
/*! SRAM_IF9_APD - Array power for RAM interface 9
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_SHIFT (10U)
/*! SRAM_IF10_APD - Array power for RAM interface 10
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_SHIFT (11U)
/*! SRAM_IF11_APD - Array power for RAM interface 11
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_SHIFT (12U)
/*! SRAM_IF12_APD - Array power for RAM interface 12
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_SHIFT (13U)
/*! SRAM_IF13_APD - Array power for RAM interface 13
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_SHIFT (14U)
/*! SRAM_IF14_APD - Array power for RAM interface 14
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_SHIFT (15U)
/*! SRAM_IF15_APD - Array power for RAM interface 15
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_SHIFT (16U)
/*! SRAM_IF16_APD - Array power for RAM interface 16
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_SHIFT (17U)
/*! SRAM_IF17_APD - Array power for RAM interface 17
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_SHIFT (18U)
/*! SRAM_IF18_APD - Array power for RAM interface 18
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_SHIFT (19U)
/*! SRAM_IF19_APD - Array power for RAM interface 19
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_SHIFT (20U)
/*! SRAM_IF20_APD - Array power for RAM interface 20
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_SHIFT (21U)
/*! SRAM_IF21_APD - Array power for RAM interface 21
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_SHIFT (22U)
/*! SRAM_IF22_APD - Array power for RAM interface 22
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_SHIFT (23U)
/*! SRAM_IF23_APD - Array power for RAM interface 23
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_SHIFT (24U)
/*! SRAM_IF24_APD - Array power for RAM interface 24
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_SHIFT (25U)
/*! SRAM_IF25_APD - Array power for RAM interface 25
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_SHIFT (26U)
/*! SRAM_IF26_APD - Array power for RAM interface 26
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_SHIFT (27U)
/*! SRAM_IF27_APD - Array power for RAM interface 27
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_SHIFT (28U)
/*! SRAM_IF28_APD - Array power for RAM interface 28
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_SHIFT (29U)
/*! SRAM_IF29_APD - Array power for RAM interface 29
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF30_APD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF30_APD_SHIFT (30U)
/*! SRAM_IF30_APD - Array power for RAM interface 30
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF30_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF30_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF30_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF31_APD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF31_APD_SHIFT (31U)
/*! SRAM_IF31_APD - Array power for RAM interface 31
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF31_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF31_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF31_APD_MASK)
/*! @} */

/*! @name PDRUNCFG3_CLR - Run configuration 3 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_SHIFT (0U)
/*! SRAM_IF0_PPD - Periphery power for RAM interface 0
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_SHIFT (1U)
/*! SRAM_IF1_PPD - Periphery power for RAM interface 1
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_SHIFT (2U)
/*! SRAM_IF2_PPD - Periphery power for RAM interface 2
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_SHIFT (3U)
/*! SRAM_IF3_PPD - Periphery power for RAM interface 3
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_SHIFT (4U)
/*! SRAM_IF4_PPD - Periphery power for RAM interface 4
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_SHIFT (5U)
/*! SRAM_IF5_PPD - Periphery power for RAM interface 5
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_SHIFT (6U)
/*! SRAM_IF6_PPD - Periphery power for RAM interface 6
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_SHIFT (7U)
/*! SRAM_IF7_PPD - Periphery power for RAM interface 7
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_SHIFT (8U)
/*! SRAM_IF8_PPD - Periphery power for RAM interface 8
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_SHIFT (9U)
/*! SRAM_IF9_PPD - Periphery power for RAM interface 9
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_SHIFT (10U)
/*! SRAM_IF10_PPD - Periphery power for RAM interface 10
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_SHIFT (11U)
/*! SRAM_IF11_PPD - Periphery power for RAM interface 11
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_SHIFT (12U)
/*! SRAM_IF12_PPD - Periphery power for RAM interface 12
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_SHIFT (13U)
/*! SRAM_IF13_PPD - Periphery power for RAM interface 13
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_SHIFT (14U)
/*! SRAM_IF14_PPD - Periphery power for RAM interface 14
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_SHIFT (15U)
/*! SRAM_IF15_PPD - Periphery power for RAM interface 15
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_SHIFT (16U)
/*! SRAM_IF16_PPD - Periphery power for RAM interface 16
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_SHIFT (17U)
/*! SRAM_IF17_PPD - Periphery power for RAM interface 17
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_SHIFT (18U)
/*! SRAM_IF18_PPD - Periphery power for RAM interface 18
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_SHIFT (19U)
/*! SRAM_IF19_PPD - Periphery power for RAM interface 19
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_SHIFT (20U)
/*! SRAM_IF20_PPD - Periphery power for RAM interface 20
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_SHIFT (21U)
/*! SRAM_IF21_PPD - Periphery power for RAM interface 21
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_SHIFT (22U)
/*! SRAM_IF22_PPD - Periphery power for RAM interface 22
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_SHIFT (23U)
/*! SRAM_IF23_PPD - Periphery power for RAM interface 23
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_SHIFT (24U)
/*! SRAM_IF24_PPD - Periphery power for RAM interface 24
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_SHIFT (25U)
/*! SRAM_IF25_PPD - Periphery power for RAM interface 25
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_SHIFT (26U)
/*! SRAM_IF26_PPD - Periphery power for RAM interface 26
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_SHIFT (27U)
/*! SRAM_IF27_PPD - Periphery power for RAM interface 27
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_SHIFT (28U)
/*! SRAM_IF28_PPD - Periphery power for RAM interface 28
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_SHIFT (29U)
/*! SRAM_IF29_PPD - Periphery power for RAM interface 29
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF30_PPD_MASK (0x40000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF30_PPD_SHIFT (30U)
/*! SRAM_IF30_PPD - Periphery power for RAM interface 30
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF30_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF30_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF30_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF31_PPD_MASK (0x80000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF31_PPD_SHIFT (31U)
/*! SRAM_IF31_PPD - Periphery power for RAM interface 31
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF31_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF31_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF31_PPD_MASK)
/*! @} */

/*! @name PDWAKECFG - PD Wake Configuration */
/*! @{ */

#define SYSCTL0_PDWAKECFG_RBBKEEPST_MASK         (0x1U)
#define SYSCTL0_PDWAKECFG_RBBKEEPST_SHIFT        (0U)
/*! RBBKEEPST - RBB mode on wakeup
 *  0b0..Use value of RBB_PD in PDRUNCFG on wakeup.
 *  0b1..Copy PDSLEEPCFG RBB_PD value to PDRUNCFG RBB_PD on wakeup to keep RBB state.
 */
#define SYSCTL0_PDWAKECFG_RBBKEEPST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDWAKECFG_RBBKEEPST_SHIFT)) & SYSCTL0_PDWAKECFG_RBBKEEPST_MASK)

#define SYSCTL0_PDWAKECFG_FBBKEEPST_MASK         (0x2U)
#define SYSCTL0_PDWAKECFG_FBBKEEPST_SHIFT        (1U)
/*! FBBKEEPST - FBB mode on wakeup
 *  0b0..Use value of FBB_PD in PDRUNCFG on wakeup
 *  0b1..Copy PDSLEEPCFG FBB_PD value to PDRUNCFG FBB_PD on wakeup to keep FBB state
 */
#define SYSCTL0_PDWAKECFG_FBBKEEPST(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDWAKECFG_FBBKEEPST_SHIFT)) & SYSCTL0_PDWAKECFG_FBBKEEPST_MASK)

#define SYSCTL0_PDWAKECFG_RBBSRAMKEEPST_MASK     (0x4U)
#define SYSCTL0_PDWAKECFG_RBBSRAMKEEPST_SHIFT    (2U)
/*! RBBSRAMKEEPST - RBB SRAM mode on wakeup
 *  0b0..Use value of RBBSRAM_PD in PDRUNCFG on wakeup
 *  0b1..Copy PDSLEEPCFG RBBSRAM_PD value to PDRUNCFG RBBSRAM_PD on wakeupto keep RBB state
 */
#define SYSCTL0_PDWAKECFG_RBBSRAMKEEPST(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDWAKECFG_RBBSRAMKEEPST_SHIFT)) & SYSCTL0_PDWAKECFG_RBBSRAMKEEPST_MASK)

#define SYSCTL0_PDWAKECFG_MIPIPDKEEPST_MASK      (0x8U)
#define SYSCTL0_PDWAKECFG_MIPIPDKEEPST_SHIFT     (3U)
/*! MIPIPDKEEPST - MIPI_PD value on wakeup
 *  0b0..Use value of MIPI_PD in PDRUNCFG on wakeup
 *  0b1..Copy PDSLEEPCFG MIPI_PD value to PDRUNCFG MIPI_PD on wakeupto keep MIPI state
 */
#define SYSCTL0_PDWAKECFG_MIPIPDKEEPST(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDWAKECFG_MIPIPDKEEPST_SHIFT)) & SYSCTL0_PDWAKECFG_MIPIPDKEEPST_MASK)

#define SYSCTL0_PDWAKECFG_DSPPDKEEPST_MASK       (0x10U)
#define SYSCTL0_PDWAKECFG_DSPPDKEEPST_SHIFT      (4U)
/*! DSPPDKEEPST - DSP_PD value on wakeup
 *  0b0..Use value of DSP_PD in PDRUNCFG on wakeup
 *  0b1..Copy PDSLEEPCFG DSP_PD value to PDRUNCFG DSP_PD on wakeupto keep DSP state
 */
#define SYSCTL0_PDWAKECFG_DSPPDKEEPST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDWAKECFG_DSPPDKEEPST_SHIFT)) & SYSCTL0_PDWAKECFG_DSPPDKEEPST_MASK)

#define SYSCTL0_PDWAKECFG_OTPPDKEEPST_MASK       (0x20U)
#define SYSCTL0_PDWAKECFG_OTPPDKEEPST_SHIFT      (5U)
/*! OTPPDKEEPST - OTP_PD value on wakeup
 *  0b0..Use value of OTP_PD in PDRUNCFG on wakeup
 *  0b1..Copy PDSLEEPCFG OTP_PD value to PDRUNCFG OTP_PD on wakeupto keep OTP state
 */
#define SYSCTL0_PDWAKECFG_OTPPDKEEPST(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDWAKECFG_OTPPDKEEPST_SHIFT)) & SYSCTL0_PDWAKECFG_OTPPDKEEPST_MASK)
/*! @} */

/*! @name STARTEN0 - Start Enable 0 */
/*! @{ */

#define SYSCTL0_STARTEN0_WDT0_MASK               (0x1U)
#define SYSCTL0_STARTEN0_WDT0_SHIFT              (0U)
/*! WDT0 - Watchdog timer 0 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_WDT0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_WDT0_SHIFT)) & SYSCTL0_STARTEN0_WDT0_MASK)

#define SYSCTL0_STARTEN0_DMAC0_MASK              (0x2U)
#define SYSCTL0_STARTEN0_DMAC0_SHIFT             (1U)
/*! DMAC0 - DMA controller 0 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_DMAC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_DMAC0_SHIFT)) & SYSCTL0_STARTEN0_DMAC0_MASK)

#define SYSCTL0_STARTEN0_GPIO_INTA_MASK          (0x4U)
#define SYSCTL0_STARTEN0_GPIO_INTA_SHIFT         (2U)
/*! GPIO_INTA - Non-secure GPIO interrupt A wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_GPIO_INTA(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INTA_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INTA_MASK)

#define SYSCTL0_STARTEN0_GPIO_INTB_MASK          (0x8U)
#define SYSCTL0_STARTEN0_GPIO_INTB_SHIFT         (3U)
/*! GPIO_INTB - Non-secure GPIO interrupt B wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_GPIO_INTB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INTB_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INTB_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_MASK     (0x10U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_SHIFT    (4U)
/*! GPIO_INT0_IRQ0 - GPIO pin interrupt 0 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_MASK     (0x20U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_SHIFT    (5U)
/*! GPIO_INT0_IRQ1 - GPIO pin interrupt 1 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_MASK     (0x40U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_SHIFT    (6U)
/*! GPIO_INT0_IRQ2 - GPIO pin interrupt 2 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ2(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_MASK     (0x80U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_SHIFT    (7U)
/*! GPIO_INT0_IRQ3 - GPIO pin interrupt 3 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ3(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_MASK)

#define SYSCTL0_STARTEN0_UTICK0_MASK             (0x100U)
#define SYSCTL0_STARTEN0_UTICK0_SHIFT            (8U)
/*! UTICK0 - UTICK wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_UTICK0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_UTICK0_SHIFT)) & SYSCTL0_STARTEN0_UTICK0_MASK)

#define SYSCTL0_STARTEN0_MRT0_MASK               (0x200U)
#define SYSCTL0_STARTEN0_MRT0_SHIFT              (9U)
/*! MRT0 - MRT wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_MRT0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_MRT0_SHIFT)) & SYSCTL0_STARTEN0_MRT0_MASK)

#define SYSCTL0_STARTEN0_CT32BIT0_MASK           (0x400U)
#define SYSCTL0_STARTEN0_CT32BIT0_SHIFT          (10U)
/*! CT32BIT0 - CTIMER 0 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_CT32BIT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CT32BIT0_SHIFT)) & SYSCTL0_STARTEN0_CT32BIT0_MASK)

#define SYSCTL0_STARTEN0_CT32BIT1_MASK           (0x800U)
#define SYSCTL0_STARTEN0_CT32BIT1_SHIFT          (11U)
/*! CT32BIT1 - CTIMER 1 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_CT32BIT1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CT32BIT1_SHIFT)) & SYSCTL0_STARTEN0_CT32BIT1_MASK)

#define SYSCTL0_STARTEN0_SCT0_MASK               (0x1000U)
#define SYSCTL0_STARTEN0_SCT0_SHIFT              (12U)
/*! SCT0 - SCTimer/PWM wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_SCT0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SCT0_SHIFT)) & SYSCTL0_STARTEN0_SCT0_MASK)

#define SYSCTL0_STARTEN0_CT32BIT3_MASK           (0x2000U)
#define SYSCTL0_STARTEN0_CT32BIT3_SHIFT          (13U)
/*! CT32BIT3 - CTIMER 3 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_CT32BIT3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CT32BIT3_SHIFT)) & SYSCTL0_STARTEN0_CT32BIT3_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM0_MASK          (0x4000U)
#define SYSCTL0_STARTEN0_FLEXCOMM0_SHIFT         (14U)
/*! FLEXCOMM0 - Flexcomm 0 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM0_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM0_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM1_MASK          (0x8000U)
#define SYSCTL0_STARTEN0_FLEXCOMM1_SHIFT         (15U)
/*! FLEXCOMM1 - Flexcomm 1 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM1_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM1_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM2_MASK          (0x10000U)
#define SYSCTL0_STARTEN0_FLEXCOMM2_SHIFT         (16U)
/*! FLEXCOMM2 - Flexcomm 2 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM2_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM2_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM3_MASK          (0x20000U)
#define SYSCTL0_STARTEN0_FLEXCOMM3_SHIFT         (17U)
/*! FLEXCOMM3 - Flexcomm 3 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM3_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM3_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM4_MASK          (0x40000U)
#define SYSCTL0_STARTEN0_FLEXCOMM4_SHIFT         (18U)
/*! FLEXCOMM4 - Flexcomm 4 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM4_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM4_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM5_MASK          (0x80000U)
#define SYSCTL0_STARTEN0_FLEXCOMM5_SHIFT         (19U)
/*! FLEXCOMM5 - Flexcomm 5 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM5_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM5_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM14_MASK         (0x100000U)
#define SYSCTL0_STARTEN0_FLEXCOMM14_SHIFT        (20U)
/*! FLEXCOMM14 - Flexcomm 14 (High Speed SPI) peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM14(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM14_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM14_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM15_MASK         (0x200000U)
#define SYSCTL0_STARTEN0_FLEXCOMM15_SHIFT        (21U)
/*! FLEXCOMM15 - Flexcomm 15 (PMIC I2C) peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_FLEXCOMM15(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM15_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM15_MASK)

#define SYSCTL0_STARTEN0_ADC0_MASK               (0x400000U)
#define SYSCTL0_STARTEN0_ADC0_SHIFT              (22U)
/*! ADC0 - ADC wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_ADC0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_ADC0_SHIFT)) & SYSCTL0_STARTEN0_ADC0_MASK)

#define SYSCTL0_STARTEN0_ACMP_MASK               (0x1000000U)
#define SYSCTL0_STARTEN0_ACMP_SHIFT              (24U)
/*! ACMP - ACMP wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_ACMP(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_ACMP_SHIFT)) & SYSCTL0_STARTEN0_ACMP_MASK)

#define SYSCTL0_STARTEN0_DMIC0_MASK              (0x2000000U)
#define SYSCTL0_STARTEN0_DMIC0_SHIFT             (25U)
/*! DMIC0 - DMIC wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_DMIC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_DMIC0_SHIFT)) & SYSCTL0_STARTEN0_DMIC0_MASK)

#define SYSCTL0_STARTEN0_HYPERVISOR_MASK         (0x8000000U)
#define SYSCTL0_STARTEN0_HYPERVISOR_SHIFT        (27U)
/*! HYPERVISOR - Hypervisor interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_HYPERVISOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_HYPERVISOR_SHIFT)) & SYSCTL0_STARTEN0_HYPERVISOR_MASK)

#define SYSCTL0_STARTEN0_SECUREVIOLATION_MASK    (0x10000000U)
#define SYSCTL0_STARTEN0_SECUREVIOLATION_SHIFT   (28U)
/*! SECUREVIOLATION - Secure Violation wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_SECUREVIOLATION(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SECUREVIOLATION_SHIFT)) & SYSCTL0_STARTEN0_SECUREVIOLATION_MASK)

#define SYSCTL0_STARTEN0_HWVAD0_MASK             (0x20000000U)
#define SYSCTL0_STARTEN0_HWVAD0_SHIFT            (29U)
/*! HWVAD0 - Hardware VAD wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_HWVAD0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_HWVAD0_SHIFT)) & SYSCTL0_STARTEN0_HWVAD0_MASK)

#define SYSCTL0_STARTEN0_PMC_MASK                (0x40000000U)
#define SYSCTL0_STARTEN0_PMC_SHIFT               (30U)
/*! PMC - PMC wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_PMC(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_PMC_SHIFT)) & SYSCTL0_STARTEN0_PMC_MASK)

#define SYSCTL0_STARTEN0_RNG_MASK                (0x80000000U)
#define SYSCTL0_STARTEN0_RNG_SHIFT               (31U)
/*! RNG - RNG wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN0_RNG(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_RNG_SHIFT)) & SYSCTL0_STARTEN0_RNG_MASK)
/*! @} */

/*! @name STARTEN1 - Start Enable 1 */
/*! @{ */

#define SYSCTL0_STARTEN1_RTC_LITE0_WAKEUP_MASK   (0x1U)
#define SYSCTL0_STARTEN1_RTC_LITE0_WAKEUP_SHIFT  (0U)
/*! RTC_LITE0_WAKEUP - RTC wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_RTC_LITE0_WAKEUP(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_RTC_LITE0_WAKEUP_SHIFT)) & SYSCTL0_STARTEN1_RTC_LITE0_WAKEUP_MASK)

#define SYSCTL0_STARTEN1_DSP_TIE_EXPSTATE1_MASK  (0x2U)
#define SYSCTL0_STARTEN1_DSP_TIE_EXPSTATE1_SHIFT (1U)
/*! DSP_TIE_EXPSTATE1 - DSP wake-up.
 *  0b0..No effect
 *  0b1..Sets the corresponding STARTEN1 bit
 */
#define SYSCTL0_STARTEN1_DSP_TIE_EXPSTATE1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_DSP_TIE_EXPSTATE1_SHIFT)) & SYSCTL0_STARTEN1_DSP_TIE_EXPSTATE1_MASK)

#define SYSCTL0_STARTEN1_MU_MASK                 (0x4U)
#define SYSCTL0_STARTEN1_MU_SHIFT                (2U)
/*! MU - Message Unit wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_MU(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_MU_SHIFT)) & SYSCTL0_STARTEN1_MU_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_MASK     (0x8U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_SHIFT    (3U)
/*! GPIO_INT0_IRQ4 - GPIO pin interrupt 4 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ4(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_MASK     (0x10U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_SHIFT    (4U)
/*! GPIO_INT0_IRQ5 - GPIO pin interrupt 5 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ5(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_MASK     (0x20U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_SHIFT    (5U)
/*! GPIO_INT0_IRQ6 - GPIO pin interrupt 6 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ6(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_MASK     (0x40U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_SHIFT    (6U)
/*! GPIO_INT0_IRQ7 - GPIO pin interrupt 7 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ7(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_MASK)

#define SYSCTL0_STARTEN1_CT32BIT2_MASK           (0x80U)
#define SYSCTL0_STARTEN1_CT32BIT2_SHIFT          (7U)
/*! CT32BIT2 - CTIMER 2 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_CT32BIT2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CT32BIT2_SHIFT)) & SYSCTL0_STARTEN1_CT32BIT2_MASK)

#define SYSCTL0_STARTEN1_CT32BIT4_MASK           (0x100U)
#define SYSCTL0_STARTEN1_CT32BIT4_SHIFT          (8U)
/*! CT32BIT4 - CTIMER 4 wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_CT32BIT4(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CT32BIT4_SHIFT)) & SYSCTL0_STARTEN1_CT32BIT4_MASK)

#define SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_MASK  (0x200U)
#define SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_SHIFT (9U)
/*! OS_EVENT_TIMER_WU - OS Event Timer wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_SHIFT)) & SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_MASK)

#define SYSCTL0_STARTEN1_FLEXSPI_MASK            (0x400U)
#define SYSCTL0_STARTEN1_FLEXSPI_SHIFT           (10U)
/*! FLEXSPI - Quad/octal SPI wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXSPI(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXSPI_SHIFT)) & SYSCTL0_STARTEN1_FLEXSPI_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM6_MASK          (0x800U)
#define SYSCTL0_STARTEN1_FLEXCOMM6_SHIFT         (11U)
/*! FLEXCOMM6 - FLEXCOMM 6 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXCOMM6(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM6_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM6_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM7_MASK          (0x1000U)
#define SYSCTL0_STARTEN1_FLEXCOMM7_SHIFT         (12U)
/*! FLEXCOMM7 - FLEXCOMM 7 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXCOMM7(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM7_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM7_MASK)

#define SYSCTL0_STARTEN1_SDIO0_MASK              (0x2000U)
#define SYSCTL0_STARTEN1_SDIO0_SHIFT             (13U)
/*! SDIO0 - SDIO0 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_SDIO0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SDIO0_SHIFT)) & SYSCTL0_STARTEN1_SDIO0_MASK)

#define SYSCTL0_STARTEN1_SDIO1_MASK              (0x4000U)
#define SYSCTL0_STARTEN1_SDIO1_SHIFT             (14U)
/*! SDIO1 - SDIO0 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_SDIO1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SDIO1_SHIFT)) & SYSCTL0_STARTEN1_SDIO1_MASK)

#define SYSCTL0_STARTEN1_SGPIO_INTA_MASK         (0x8000U)
#define SYSCTL0_STARTEN1_SGPIO_INTA_SHIFT        (15U)
/*! SGPIO_INTA - Secure GPIO interrupt A wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_SGPIO_INTA(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SGPIO_INTA_SHIFT)) & SYSCTL0_STARTEN1_SGPIO_INTA_MASK)

#define SYSCTL0_STARTEN1_SGPIO_INTB_MASK         (0x10000U)
#define SYSCTL0_STARTEN1_SGPIO_INTB_SHIFT        (16U)
/*! SGPIO_INTB - Secure GPIO interrupt B wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_SGPIO_INTB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SGPIO_INTB_SHIFT)) & SYSCTL0_STARTEN1_SGPIO_INTB_MASK)

#define SYSCTL0_STARTEN1_USB0_NEEDCLK_MASK       (0x80000U)
#define SYSCTL0_STARTEN1_USB0_NEEDCLK_SHIFT      (19U)
/*! USB0_NEEDCLK - USB activity wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_USB0_NEEDCLK(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_USB0_NEEDCLK_SHIFT)) & SYSCTL0_STARTEN1_USB0_NEEDCLK_MASK)

#define SYSCTL0_STARTEN1_USB_PHYDCD_MASK         (0x200000U)
#define SYSCTL0_STARTEN1_USB_PHYDCD_SHIFT        (21U)
/*! USB_PHYDCD - USB PHY DCD interrupt wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_USB_PHYDCD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_USB_PHYDCD_SHIFT)) & SYSCTL0_STARTEN1_USB_PHYDCD_MASK)

#define SYSCTL0_STARTEN1_DMAC1_MASK              (0x400000U)
#define SYSCTL0_STARTEN1_DMAC1_SHIFT             (22U)
/*! DMAC1 - DMA controller 1 wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_DMAC1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_DMAC1_SHIFT)) & SYSCTL0_STARTEN1_DMAC1_MASK)

#define SYSCTL0_STARTEN1_PUF_MASK                (0x800000U)
#define SYSCTL0_STARTEN1_PUF_SHIFT               (23U)
/*! PUF - PUF wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_PUF(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_PUF_SHIFT)) & SYSCTL0_STARTEN1_PUF_MASK)

#define SYSCTL0_STARTEN1_POWERQUAD_MASK          (0x1000000U)
#define SYSCTL0_STARTEN1_POWERQUAD_SHIFT         (24U)
/*! POWERQUAD - POWERQUAD co-processor wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_POWERQUAD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_POWERQUAD_SHIFT)) & SYSCTL0_STARTEN1_POWERQUAD_MASK)

#define SYSCTL0_STARTEN1_CASPER_MASK             (0x2000000U)
#define SYSCTL0_STARTEN1_CASPER_SHIFT            (25U)
/*! CASPER - CASPER co-processor wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_CASPER(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CASPER_SHIFT)) & SYSCTL0_STARTEN1_CASPER_MASK)

#define SYSCTL0_STARTEN1_PMIC_MASK               (0x4000000U)
#define SYSCTL0_STARTEN1_PMIC_SHIFT              (26U)
/*! PMIC - Wake-up from on-chip PMC or off-chip PMIC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_PMIC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_PMIC_SHIFT)) & SYSCTL0_STARTEN1_PMIC_MASK)

#define SYSCTL0_STARTEN1_SHA_MASK                (0x8000000U)
#define SYSCTL0_STARTEN1_SHA_SHIFT               (27U)
/*! SHA - Hash-AES wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_SHA(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SHA_SHIFT)) & SYSCTL0_STARTEN1_SHA_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM8_MASK          (0x10000000U)
#define SYSCTL0_STARTEN1_FLEXCOMM8_SHIFT         (28U)
/*! FLEXCOMM8 - FLEXCOMM 8 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXCOMM8(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM8_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM8_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM9_MASK          (0x20000000U)
#define SYSCTL0_STARTEN1_FLEXCOMM9_SHIFT         (29U)
/*! FLEXCOMM9 - FLEXCOMM 9 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXCOMM9(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM9_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM9_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM10_MASK         (0x40000000U)
#define SYSCTL0_STARTEN1_FLEXCOMM10_SHIFT        (30U)
/*! FLEXCOMM10 - FLEXCOMM 10 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXCOMM10(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM10_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM10_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM11_MASK         (0x80000000U)
#define SYSCTL0_STARTEN1_FLEXCOMM11_SHIFT        (31U)
/*! FLEXCOMM11 - FLEXCOMM 11 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_FLEXCOMM11(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM11_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM11_MASK)
/*! @} */

/*! @name STARTEN2 - Start Enable 2 */
/*! @{ */

#define SYSCTL0_STARTEN2_FLEXCOMM12_MASK         (0x1U)
#define SYSCTL0_STARTEN2_FLEXCOMM12_SHIFT        (0U)
/*! FLEXCOMM12 - FlexComm 12 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN2_FLEXCOMM12(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_FLEXCOMM12_SHIFT)) & SYSCTL0_STARTEN2_FLEXCOMM12_MASK)

#define SYSCTL0_STARTEN2_FLEXCOMM13_MASK         (0x2U)
#define SYSCTL0_STARTEN2_FLEXCOMM13_SHIFT        (1U)
/*! FLEXCOMM13 - FlexComm 13 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN2_FLEXCOMM13(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_FLEXCOMM13_SHIFT)) & SYSCTL0_STARTEN2_FLEXCOMM13_MASK)

#define SYSCTL0_STARTEN2_FLEXCOMM16_MASK         (0x4U)
#define SYSCTL0_STARTEN2_FLEXCOMM16_SHIFT        (2U)
/*! FLEXCOMM16 - FlexComm 16 peripheral interrupt wake-up.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN2_FLEXCOMM16(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_FLEXCOMM16_SHIFT)) & SYSCTL0_STARTEN2_FLEXCOMM16_MASK)
/*! @} */

/*! @name STARTEN0_SET - Start Enable 0 Set */
/*! @{ */

#define SYSCTL0_STARTEN0_SET_WDT0_MASK           (0x1U)
#define SYSCTL0_STARTEN0_SET_WDT0_SHIFT          (0U)
/*! WDT0 - Watchdog timer 0 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_WDT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_WDT0_SHIFT)) & SYSCTL0_STARTEN0_SET_WDT0_MASK)

#define SYSCTL0_STARTEN0_SET_DMAC0_MASK          (0x2U)
#define SYSCTL0_STARTEN0_SET_DMAC0_SHIFT         (1U)
/*! DMAC0 - DMA controller 0 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_DMAC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_DMAC0_SHIFT)) & SYSCTL0_STARTEN0_SET_DMAC0_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INTA_MASK      (0x4U)
#define SYSCTL0_STARTEN0_SET_GPIO_INTA_SHIFT     (2U)
/*! GPIO_INTA - Non-secure GPIO interrupt A wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INTA(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INTA_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INTA_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INTB_MASK      (0x8U)
#define SYSCTL0_STARTEN0_SET_GPIO_INTB_SHIFT     (3U)
/*! GPIO_INTB - Non-secure GPIO interrupt B wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INTB(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INTB_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INTB_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_MASK (0x10U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_SHIFT (4U)
/*! GPIO_INT0_IRQ0 - GPIO pin interrupt 0 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_MASK (0x20U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_SHIFT (5U)
/*! GPIO_INT0_IRQ1 - GPIO pin interrupt 1 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_MASK (0x40U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_SHIFT (6U)
/*! GPIO_INT0_IRQ2 - GPIO pin interrupt 2 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_MASK (0x80U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_SHIFT (7U)
/*! GPIO_INT0_IRQ3 - GPIO pin interrupt 3 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_MASK)

#define SYSCTL0_STARTEN0_SET_UTICK0_MASK         (0x100U)
#define SYSCTL0_STARTEN0_SET_UTICK0_SHIFT        (8U)
/*! UTICK0 - UTICK wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_UTICK0_SHIFT)) & SYSCTL0_STARTEN0_SET_UTICK0_MASK)

#define SYSCTL0_STARTEN0_SET_MRT0_MASK           (0x200U)
#define SYSCTL0_STARTEN0_SET_MRT0_SHIFT          (9U)
/*! MRT0 - MRT wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_MRT0_SHIFT)) & SYSCTL0_STARTEN0_SET_MRT0_MASK)

#define SYSCTL0_STARTEN0_SET_CT32BIT0_MASK       (0x400U)
#define SYSCTL0_STARTEN0_SET_CT32BIT0_SHIFT      (10U)
/*! CT32BIT0 - CTIMER 0 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_CT32BIT0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_CT32BIT0_SHIFT)) & SYSCTL0_STARTEN0_SET_CT32BIT0_MASK)

#define SYSCTL0_STARTEN0_SET_CT32BIT1_MASK       (0x800U)
#define SYSCTL0_STARTEN0_SET_CT32BIT1_SHIFT      (11U)
/*! CT32BIT1 - CTIMER 1 wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_CT32BIT1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_CT32BIT1_SHIFT)) & SYSCTL0_STARTEN0_SET_CT32BIT1_MASK)

#define SYSCTL0_STARTEN0_SET_SCT0_MASK           (0x1000U)
#define SYSCTL0_STARTEN0_SET_SCT0_SHIFT          (12U)
/*! SCT0 - SCTimer/PWM wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_SCT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_SCT0_SHIFT)) & SYSCTL0_STARTEN0_SET_SCT0_MASK)

#define SYSCTL0_STARTEN0_SET_CT32BIT3_MASK       (0x2000U)
#define SYSCTL0_STARTEN0_SET_CT32BIT3_SHIFT      (13U)
/*! CT32BIT3 - CTIMER 3 wake-up
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_CT32BIT3(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_CT32BIT3_SHIFT)) & SYSCTL0_STARTEN0_SET_CT32BIT3_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM14_MASK     (0x100000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM14_SHIFT    (20U)
/*! FLEXCOMM14 - FlexComm 14 (High Speed SPI) peripheral interrupt wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM14(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM14_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM14_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM15_MASK     (0x200000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM15_SHIFT    (21U)
/*! FLEXCOMM15 - FlexComm 15 (PMIC I2C) peripheral interrupt wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM15(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM15_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM15_MASK)

#define SYSCTL0_STARTEN0_SET_ADC0_MASK           (0x400000U)
#define SYSCTL0_STARTEN0_SET_ADC0_SHIFT          (22U)
/*! ADC0 - ADC wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_ADC0_SHIFT)) & SYSCTL0_STARTEN0_SET_ADC0_MASK)

#define SYSCTL0_STARTEN0_SET_ACMP_MASK           (0x1000000U)
#define SYSCTL0_STARTEN0_SET_ACMP_SHIFT          (24U)
/*! ACMP - ACMP wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_ACMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_ACMP_SHIFT)) & SYSCTL0_STARTEN0_SET_ACMP_MASK)

#define SYSCTL0_STARTEN0_SET_DMIC0_MASK          (0x2000000U)
#define SYSCTL0_STARTEN0_SET_DMIC0_SHIFT         (25U)
/*! DMIC0 - DMIC wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_DMIC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_DMIC0_SHIFT)) & SYSCTL0_STARTEN0_SET_DMIC0_MASK)

#define SYSCTL0_STARTEN0_SET_HYPERVISOR_MASK     (0x8000000U)
#define SYSCTL0_STARTEN0_SET_HYPERVISOR_SHIFT    (27U)
/*! HYPERVISOR - Hypervisor interrupt wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_HYPERVISOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_HYPERVISOR_SHIFT)) & SYSCTL0_STARTEN0_SET_HYPERVISOR_MASK)

#define SYSCTL0_STARTEN0_SET_SECUREVIOLATION_MASK (0x10000000U)
#define SYSCTL0_STARTEN0_SET_SECUREVIOLATION_SHIFT (28U)
/*! SECUREVIOLATION - Secure Violation wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_SECUREVIOLATION(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_SECUREVIOLATION_SHIFT)) & SYSCTL0_STARTEN0_SET_SECUREVIOLATION_MASK)

#define SYSCTL0_STARTEN0_SET_HWVAD0_MASK         (0x20000000U)
#define SYSCTL0_STARTEN0_SET_HWVAD0_SHIFT        (29U)
/*! HWVAD0 - Hardware VAD wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_HWVAD0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_HWVAD0_SHIFT)) & SYSCTL0_STARTEN0_SET_HWVAD0_MASK)

#define SYSCTL0_STARTEN0_SET_PMC_MASK            (0x40000000U)
#define SYSCTL0_STARTEN0_SET_PMC_SHIFT           (30U)
/*! PMC - PMC wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_PMC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_PMC_SHIFT)) & SYSCTL0_STARTEN0_SET_PMC_MASK)

#define SYSCTL0_STARTEN0_SET_RNG_MASK            (0x80000000U)
#define SYSCTL0_STARTEN0_SET_RNG_SHIFT           (31U)
/*! RNG - RNG wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_RNG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_RNG_SHIFT)) & SYSCTL0_STARTEN0_SET_RNG_MASK)
/*! @} */

/*! @name STARTEN1_SET - Start Enable 1 Set */
/*! @{ */

#define SYSCTL0_STARTEN1_SET_RTC_LITE0_WAKEUP_MASK (0x1U)
#define SYSCTL0_STARTEN1_SET_RTC_LITE0_WAKEUP_SHIFT (0U)
/*! RTC_LITE0_WAKEUP - RTC wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_RTC_LITE0_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_RTC_LITE0_WAKEUP_SHIFT)) & SYSCTL0_STARTEN1_SET_RTC_LITE0_WAKEUP_MASK)

#define SYSCTL0_STARTEN1_SET_DSP_TIE_EXPSTATE1_MASK (0x2U)
#define SYSCTL0_STARTEN1_SET_DSP_TIE_EXPSTATE1_SHIFT (1U)
/*! DSP_TIE_EXPSTATE1 - DSP wake-up
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCTL0_STARTEN1_SET_DSP_TIE_EXPSTATE1(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_DSP_TIE_EXPSTATE1_SHIFT)) & SYSCTL0_STARTEN1_SET_DSP_TIE_EXPSTATE1_MASK)

#define SYSCTL0_STARTEN1_SET_MU_MASK             (0x4U)
#define SYSCTL0_STARTEN1_SET_MU_SHIFT            (2U)
/*! MU - Message Unit wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_MU(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_MU_SHIFT)) & SYSCTL0_STARTEN1_SET_MU_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_MASK (0x8U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_SHIFT (3U)
/*! GPIO_INT0_IRQ4 - Message Unit wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_MASK (0x10U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_SHIFT (4U)
/*! GPIO_INT0_IRQ5 - GPIO pin interrupt 5 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_MASK (0x20U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_SHIFT (5U)
/*! GPIO_INT0_IRQ6 - GPIO pin interrupt 6 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_MASK (0x40U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_SHIFT (6U)
/*! GPIO_INT0_IRQ7 - GPIO pin interrupt 7 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_MASK)

#define SYSCTL0_STARTEN1_SET_CT32BIT2_MASK       (0x80U)
#define SYSCTL0_STARTEN1_SET_CT32BIT2_SHIFT      (7U)
/*! CT32BIT2 - CTIMER 2 wake-up
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_CT32BIT2(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_CT32BIT2_SHIFT)) & SYSCTL0_STARTEN1_SET_CT32BIT2_MASK)

#define SYSCTL0_STARTEN1_SET_CT32BIT4_MASK       (0x100U)
#define SYSCTL0_STARTEN1_SET_CT32BIT4_SHIFT      (8U)
/*! CT32BIT4 - CTIMER 4 wake-up
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_CT32BIT4(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_CT32BIT4_SHIFT)) & SYSCTL0_STARTEN1_SET_CT32BIT4_MASK)

#define SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_MASK (0x200U)
#define SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_SHIFT (9U)
/*! OS_EVENT_TIMER_WU - OS Event Timer wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_SHIFT)) & SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXSPI_MASK        (0x400U)
#define SYSCTL0_STARTEN1_SET_FLEXSPI_SHIFT       (10U)
/*! FLEXSPI - Quad/octal SPI wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXSPI(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXSPI_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXSPI_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM6_MASK      (0x800U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM6_SHIFT     (11U)
/*! FLEXCOMM6 - FLEXCOMM6 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM6(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM6_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM6_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM7_MASK      (0x1000U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM7_SHIFT     (12U)
/*! FLEXCOMM7 - FLEXCOMM7 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM7(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM7_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM7_MASK)

#define SYSCTL0_STARTEN1_SET_SDIO0_MASK          (0x2000U)
#define SYSCTL0_STARTEN1_SET_SDIO0_SHIFT         (13U)
/*! SDIO0 - SDIO0 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SDIO0_SHIFT)) & SYSCTL0_STARTEN1_SET_SDIO0_MASK)

#define SYSCTL0_STARTEN1_SET_SDIO1_MASK          (0x4000U)
#define SYSCTL0_STARTEN1_SET_SDIO1_SHIFT         (14U)
/*! SDIO1 - SDIO01 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SDIO1_SHIFT)) & SYSCTL0_STARTEN1_SET_SDIO1_MASK)

#define SYSCTL0_STARTEN1_SET_SGPIO_INTA_MASK     (0x8000U)
#define SYSCTL0_STARTEN1_SET_SGPIO_INTA_SHIFT    (15U)
/*! SGPIO_INTA - Secure GPIO interrupt A wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SGPIO_INTA(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SGPIO_INTA_SHIFT)) & SYSCTL0_STARTEN1_SET_SGPIO_INTA_MASK)

#define SYSCTL0_STARTEN1_SET_SGPIO_INTB_MASK     (0x10000U)
#define SYSCTL0_STARTEN1_SET_SGPIO_INTB_SHIFT    (16U)
/*! SGPIO_INTB - Secure GPIO interrupt B wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SGPIO_INTB(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SGPIO_INTB_SHIFT)) & SYSCTL0_STARTEN1_SET_SGPIO_INTB_MASK)

#define SYSCTL0_STARTEN1_SET_USB0_NEEDCLK_MASK   (0x80000U)
#define SYSCTL0_STARTEN1_SET_USB0_NEEDCLK_SHIFT  (19U)
/*! USB0_NEEDCLK - USB activity wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_USB0_NEEDCLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_USB0_NEEDCLK_SHIFT)) & SYSCTL0_STARTEN1_SET_USB0_NEEDCLK_MASK)

#define SYSCTL0_STARTEN1_SET_USB_PHYDCD_MASK     (0x200000U)
#define SYSCTL0_STARTEN1_SET_USB_PHYDCD_SHIFT    (21U)
/*! USB_PHYDCD - USB PHY DCD interrupt wake-up
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_USB_PHYDCD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_USB_PHYDCD_SHIFT)) & SYSCTL0_STARTEN1_SET_USB_PHYDCD_MASK)

#define SYSCTL0_STARTEN1_SET_DMAC1_MASK          (0x400000U)
#define SYSCTL0_STARTEN1_SET_DMAC1_SHIFT         (22U)
/*! DMAC1 - DMA controller 1 wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_DMAC1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_DMAC1_SHIFT)) & SYSCTL0_STARTEN1_SET_DMAC1_MASK)

#define SYSCTL0_STARTEN1_SET_PUF_MASK            (0x800000U)
#define SYSCTL0_STARTEN1_SET_PUF_SHIFT           (23U)
/*! PUF - PUF wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_PUF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_PUF_SHIFT)) & SYSCTL0_STARTEN1_SET_PUF_MASK)

#define SYSCTL0_STARTEN1_SET_POWERQUAD_MASK      (0x1000000U)
#define SYSCTL0_STARTEN1_SET_POWERQUAD_SHIFT     (24U)
/*! POWERQUAD - POWERQUAD co-processor wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_POWERQUAD_SHIFT)) & SYSCTL0_STARTEN1_SET_POWERQUAD_MASK)

#define SYSCTL0_STARTEN1_SET_CASPER_MASK         (0x2000000U)
#define SYSCTL0_STARTEN1_SET_CASPER_SHIFT        (25U)
/*! CASPER - CASPER co-processor wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_CASPER_SHIFT)) & SYSCTL0_STARTEN1_SET_CASPER_MASK)

#define SYSCTL0_STARTEN1_SET_PMIC_MASK           (0x4000000U)
#define SYSCTL0_STARTEN1_SET_PMIC_SHIFT          (26U)
/*! PMIC - Wake-up from on-chip PMC or off-chip PMIC.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_PMIC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_PMIC_SHIFT)) & SYSCTL0_STARTEN1_SET_PMIC_MASK)

#define SYSCTL0_STARTEN1_SET_SHA_MASK            (0x8000000U)
#define SYSCTL0_STARTEN1_SET_SHA_SHIFT           (27U)
/*! SHA - Hash-AES wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SHA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SHA_SHIFT)) & SYSCTL0_STARTEN1_SET_SHA_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM8_MASK      (0x10000000U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM8_SHIFT     (28U)
/*! FLEXCOMM8 - FLEXCOMM 8 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM8(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM8_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM8_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM9_MASK      (0x20000000U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM9_SHIFT     (29U)
/*! FLEXCOMM9 - FLEXCOMM 9 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM9(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM9_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM9_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM10_MASK     (0x40000000U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM10_SHIFT    (30U)
/*! FLEXCOMM10 - FLEXCOMM 10 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM10(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM10_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM10_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM11_MASK     (0x80000000U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM11_SHIFT    (31U)
/*! FLEXCOMM11 - FLEXCOMM 11 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Sets the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM11(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM11_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM11_MASK)
/*! @} */

/*! @name STARTEN2_SET - Start Enable 2 */
/*! @{ */

#define SYSCTL0_STARTEN2_SET_FLEXCOMMC12_MASK    (0x1U)
#define SYSCTL0_STARTEN2_SET_FLEXCOMMC12_SHIFT   (0U)
/*! FLEXCOMMC12 - FlexComm 12 interrupt wake-up
 *  0b0..No effect
 *  0b1..Sets the STARTEN2 bit
 */
#define SYSCTL0_STARTEN2_SET_FLEXCOMMC12(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_SET_FLEXCOMMC12_SHIFT)) & SYSCTL0_STARTEN2_SET_FLEXCOMMC12_MASK)

#define SYSCTL0_STARTEN2_SET_FLEXCOMM13_MASK     (0x2U)
#define SYSCTL0_STARTEN2_SET_FLEXCOMM13_SHIFT    (1U)
/*! FLEXCOMM13 - FlexComm 13 interrupt wake-up
 *  0b0..No effect
 *  0b1..Sets the STARTEN2 bit
 */
#define SYSCTL0_STARTEN2_SET_FLEXCOMM13(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_SET_FLEXCOMM13_SHIFT)) & SYSCTL0_STARTEN2_SET_FLEXCOMM13_MASK)

#define SYSCTL0_STARTEN2_SET_FLEXCOMM16_MASK     (0x4U)
#define SYSCTL0_STARTEN2_SET_FLEXCOMM16_SHIFT    (2U)
/*! FLEXCOMM16 - FlexComm16 interrupt wake-up
 *  0b0..No effect
 *  0b1..Sets the STARTEN2 bit
 */
#define SYSCTL0_STARTEN2_SET_FLEXCOMM16(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_SET_FLEXCOMM16_SHIFT)) & SYSCTL0_STARTEN2_SET_FLEXCOMM16_MASK)
/*! @} */

/*! @name STARTEN0_CLR - Start Enable 0 clear */
/*! @{ */

#define SYSCTL0_STARTEN0_CLR_WDT0_MASK           (0x1U)
#define SYSCTL0_STARTEN0_CLR_WDT0_SHIFT          (0U)
/*! WDT0 - Watchdog timer 0 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_WDT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_WDT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_WDT0_MASK)

#define SYSCTL0_STARTEN0_CLR_DMAC0_MASK          (0x2U)
#define SYSCTL0_STARTEN0_CLR_DMAC0_SHIFT         (1U)
/*! DMAC0 - DMA controller 0 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_DMAC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_DMAC0_SHIFT)) & SYSCTL0_STARTEN0_CLR_DMAC0_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INTA_MASK      (0x4U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INTA_SHIFT     (2U)
/*! GPIO_INTA - Non-secure GPIO interrupt A wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INTA(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INTA_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INTA_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INTB_MASK      (0x8U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INTB_SHIFT     (3U)
/*! GPIO_INTB - Non-secure GPIO interrupt B wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INTB(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INTB_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INTB_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_MASK (0x10U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_SHIFT (4U)
/*! GPIO_INT0_IRQ0 - GPIO pin interrupt 0 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_MASK (0x20U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_SHIFT (5U)
/*! GPIO_INT0_IRQ1 - GPIO pin interrupt 1 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_MASK (0x40U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_SHIFT (6U)
/*! GPIO_INT0_IRQ2 - GPIO pin interrupt 2 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_MASK (0x80U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_SHIFT (7U)
/*! GPIO_INT0_IRQ3 - GPIO pin interrupt 3 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_MASK)

#define SYSCTL0_STARTEN0_CLR_UTICK0_MASK         (0x100U)
#define SYSCTL0_STARTEN0_CLR_UTICK0_SHIFT        (8U)
/*! UTICK0 - UTICK wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_UTICK0_SHIFT)) & SYSCTL0_STARTEN0_CLR_UTICK0_MASK)

#define SYSCTL0_STARTEN0_CLR_MRT0_MASK           (0x200U)
#define SYSCTL0_STARTEN0_CLR_MRT0_SHIFT          (9U)
/*! MRT0 - MRT wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_MRT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_MRT0_MASK)

#define SYSCTL0_STARTEN0_CLR_CT32BIT0_MASK       (0x400U)
#define SYSCTL0_STARTEN0_CLR_CT32BIT0_SHIFT      (10U)
/*! CT32BIT0 - CTIMER 0 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_CT32BIT0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_CT32BIT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_CT32BIT0_MASK)

#define SYSCTL0_STARTEN0_CLR_CT32BIT1_MASK       (0x800U)
#define SYSCTL0_STARTEN0_CLR_CT32BIT1_SHIFT      (11U)
/*! CT32BIT1 - CTIMER 1 wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_CT32BIT1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_CT32BIT1_SHIFT)) & SYSCTL0_STARTEN0_CLR_CT32BIT1_MASK)

#define SYSCTL0_STARTEN0_CLR_SCT0_MASK           (0x1000U)
#define SYSCTL0_STARTEN0_CLR_SCT0_SHIFT          (12U)
/*! SCT0 - SCTimer/PWM wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_SCT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_SCT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_SCT0_MASK)

#define SYSCTL0_STARTEN0_CLR_CT32BIT3_MASK       (0x2000U)
#define SYSCTL0_STARTEN0_CLR_CT32BIT3_SHIFT      (13U)
/*! CT32BIT3 - CTIMER 3 wake-up
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_CT32BIT3(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_CT32BIT3_SHIFT)) & SYSCTL0_STARTEN0_CLR_CT32BIT3_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM14_MASK     (0x100000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM14_SHIFT    (20U)
/*! FLEXCOMM14 - FlexComm 14 (High Speed SPI) peripheral interrupt wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM14(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM14_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM14_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM15_MASK     (0x200000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM15_SHIFT    (21U)
/*! FLEXCOMM15 - FlexComm 15 (PMIC I2C) peripheral interrupt wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM15(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM15_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM15_MASK)

#define SYSCTL0_STARTEN0_CLR_ADC0_MASK           (0x400000U)
#define SYSCTL0_STARTEN0_CLR_ADC0_SHIFT          (22U)
/*! ADC0 - ADC wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_ADC0_SHIFT)) & SYSCTL0_STARTEN0_CLR_ADC0_MASK)

#define SYSCTL0_STARTEN0_CLR_ACMP_MASK           (0x1000000U)
#define SYSCTL0_STARTEN0_CLR_ACMP_SHIFT          (24U)
/*! ACMP - ACMP wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_ACMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_ACMP_SHIFT)) & SYSCTL0_STARTEN0_CLR_ACMP_MASK)

#define SYSCTL0_STARTEN0_CLR_DMIC0_MASK          (0x2000000U)
#define SYSCTL0_STARTEN0_CLR_DMIC0_SHIFT         (25U)
/*! DMIC0 - DMIC wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_DMIC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_DMIC0_SHIFT)) & SYSCTL0_STARTEN0_CLR_DMIC0_MASK)

#define SYSCTL0_STARTEN0_CLR_HYPERVISOR_MASK     (0x8000000U)
#define SYSCTL0_STARTEN0_CLR_HYPERVISOR_SHIFT    (27U)
/*! HYPERVISOR - Hypervisor interrupt wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_HYPERVISOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_HYPERVISOR_SHIFT)) & SYSCTL0_STARTEN0_CLR_HYPERVISOR_MASK)

#define SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_MASK (0x10000000U)
#define SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_SHIFT (28U)
/*! SECUREVIOLATION - Secure Violation wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_SECUREVIOLATION(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_SHIFT)) & SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_MASK)

#define SYSCTL0_STARTEN0_CLR_HWVAD0_MASK         (0x20000000U)
#define SYSCTL0_STARTEN0_CLR_HWVAD0_SHIFT        (29U)
/*! HWVAD0 - Hardware VAD wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_HWVAD0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_HWVAD0_SHIFT)) & SYSCTL0_STARTEN0_CLR_HWVAD0_MASK)

#define SYSCTL0_STARTEN0_CLR_PMC_MASK            (0x40000000U)
#define SYSCTL0_STARTEN0_CLR_PMC_SHIFT           (30U)
/*! PMC - PMC wake-up.
 *  0b0..No effect
 *  0b1..Sets the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_PMC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_PMC_SHIFT)) & SYSCTL0_STARTEN0_CLR_PMC_MASK)

#define SYSCTL0_STARTEN0_CLR_RNG_MASK            (0x80000000U)
#define SYSCTL0_STARTEN0_CLR_RNG_SHIFT           (31U)
/*! RNG - RNG wake-up.
 *  0b0..No effect
 *  0b1..Clears the STARTEN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_RNG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_RNG_SHIFT)) & SYSCTL0_STARTEN0_CLR_RNG_MASK)
/*! @} */

/*! @name STARTEN1_CLR - Start Enable 1 clear */
/*! @{ */

#define SYSCTL0_STARTEN1_CLR_RTC_LITE0_WAKEUP_MASK (0x1U)
#define SYSCTL0_STARTEN1_CLR_RTC_LITE0_WAKEUP_SHIFT (0U)
/*! RTC_LITE0_WAKEUP - RTC wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_RTC_LITE0_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_RTC_LITE0_WAKEUP_SHIFT)) & SYSCTL0_STARTEN1_CLR_RTC_LITE0_WAKEUP_MASK)

#define SYSCTL0_STARTEN1_CLR_MU_MASK             (0x4U)
#define SYSCTL0_STARTEN1_CLR_MU_SHIFT            (2U)
/*! MU - Message Unit wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_MU(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_MU_SHIFT)) & SYSCTL0_STARTEN1_CLR_MU_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_MASK (0x8U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_SHIFT (3U)
/*! GPIO_INT0_IRQ4 - Message Unit wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_MASK (0x10U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_SHIFT (4U)
/*! GPIO_INT0_IRQ5 - GPIO pin interrupt 5 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_MASK (0x20U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_SHIFT (5U)
/*! GPIO_INT0_IRQ6 - GPIO pin interrupt 6 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_MASK (0x40U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_SHIFT (6U)
/*! GPIO_INT0_IRQ7 - GPIO pin interrupt 7 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_MASK)

#define SYSCTL0_STARTEN1_CLR_CT32BIT2_MASK       (0x80U)
#define SYSCTL0_STARTEN1_CLR_CT32BIT2_SHIFT      (7U)
/*! CT32BIT2 - CTIMER 2 wake-up
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_CT32BIT2(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_CT32BIT2_SHIFT)) & SYSCTL0_STARTEN1_CLR_CT32BIT2_MASK)

#define SYSCTL0_STARTEN1_CLR_CT32BIT4_MASK       (0x100U)
#define SYSCTL0_STARTEN1_CLR_CT32BIT4_SHIFT      (8U)
/*! CT32BIT4 - CTIMER 4 wake-up
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_CT32BIT4(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_CT32BIT4_SHIFT)) & SYSCTL0_STARTEN1_CLR_CT32BIT4_MASK)

#define SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_MASK (0x200U)
#define SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_SHIFT (9U)
/*! OS_EVENT_TIMER_WU - OS Event Timer wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_SHIFT)) & SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXSPI_MASK        (0x400U)
#define SYSCTL0_STARTEN1_CLR_FLEXSPI_SHIFT       (10U)
/*! FLEXSPI - Quad/octal SPI wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXSPI(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXSPI_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXSPI_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM6_MASK      (0x800U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM6_SHIFT     (11U)
/*! FLEXCOMM6 - FLEXCOMM6 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM6(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM6_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM6_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM7_MASK      (0x1000U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM7_SHIFT     (12U)
/*! FLEXCOMM7 - FLEXCOMM7 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM7(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM7_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM7_MASK)

#define SYSCTL0_STARTEN1_CLR_SDIO0_MASK          (0x2000U)
#define SYSCTL0_STARTEN1_CLR_SDIO0_SHIFT         (13U)
/*! SDIO0 - SDIO0 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SDIO0_SHIFT)) & SYSCTL0_STARTEN1_CLR_SDIO0_MASK)

#define SYSCTL0_STARTEN1_CLR_SDIO1_MASK          (0x4000U)
#define SYSCTL0_STARTEN1_CLR_SDIO1_SHIFT         (14U)
/*! SDIO1 - SDIO01 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SDIO1_SHIFT)) & SYSCTL0_STARTEN1_CLR_SDIO1_MASK)

#define SYSCTL0_STARTEN1_CLR_SGPIO_INTA_MASK     (0x8000U)
#define SYSCTL0_STARTEN1_CLR_SGPIO_INTA_SHIFT    (15U)
/*! SGPIO_INTA - Secure GPIO interrupt A wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SGPIO_INTA(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SGPIO_INTA_SHIFT)) & SYSCTL0_STARTEN1_CLR_SGPIO_INTA_MASK)

#define SYSCTL0_STARTEN1_CLR_SGPIO_INTB_MASK     (0x10000U)
#define SYSCTL0_STARTEN1_CLR_SGPIO_INTB_SHIFT    (16U)
/*! SGPIO_INTB - Secure GPIO interrupt B wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SGPIO_INTB(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SGPIO_INTB_SHIFT)) & SYSCTL0_STARTEN1_CLR_SGPIO_INTB_MASK)

#define SYSCTL0_STARTEN1_CLR_USB0_NEEDCLK_MASK   (0x80000U)
#define SYSCTL0_STARTEN1_CLR_USB0_NEEDCLK_SHIFT  (19U)
/*! USB0_NEEDCLK - USB activity wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_USB0_NEEDCLK(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_USB0_NEEDCLK_SHIFT)) & SYSCTL0_STARTEN1_CLR_USB0_NEEDCLK_MASK)

#define SYSCTL0_STARTEN1_CLR_USB_PHYDCD_MASK     (0x200000U)
#define SYSCTL0_STARTEN1_CLR_USB_PHYDCD_SHIFT    (21U)
/*! USB_PHYDCD - USB PHY DCD interrupt wake-up
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_USB_PHYDCD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_USB_PHYDCD_SHIFT)) & SYSCTL0_STARTEN1_CLR_USB_PHYDCD_MASK)

#define SYSCTL0_STARTEN1_CLR_DMAC1_MASK          (0x400000U)
#define SYSCTL0_STARTEN1_CLR_DMAC1_SHIFT         (22U)
/*! DMAC1 - DMA controller 1 wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_DMAC1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_DMAC1_SHIFT)) & SYSCTL0_STARTEN1_CLR_DMAC1_MASK)

#define SYSCTL0_STARTEN1_CLR_PUF_MASK            (0x800000U)
#define SYSCTL0_STARTEN1_CLR_PUF_SHIFT           (23U)
/*! PUF - PUF wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_PUF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_PUF_SHIFT)) & SYSCTL0_STARTEN1_CLR_PUF_MASK)

#define SYSCTL0_STARTEN1_CLR_POWERQUAD_MASK      (0x1000000U)
#define SYSCTL0_STARTEN1_CLR_POWERQUAD_SHIFT     (24U)
/*! POWERQUAD - POWERQUAD co-processor wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_POWERQUAD_SHIFT)) & SYSCTL0_STARTEN1_CLR_POWERQUAD_MASK)

#define SYSCTL0_STARTEN1_CLR_CASPER_MASK         (0x2000000U)
#define SYSCTL0_STARTEN1_CLR_CASPER_SHIFT        (25U)
/*! CASPER - CASPER co-processor wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_CASPER_SHIFT)) & SYSCTL0_STARTEN1_CLR_CASPER_MASK)

#define SYSCTL0_STARTEN1_CLR_PMIC_MASK           (0x4000000U)
#define SYSCTL0_STARTEN1_CLR_PMIC_SHIFT          (26U)
/*! PMIC - Wake-up from on-chip PMC or off-chip PMIC.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_PMIC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_PMIC_SHIFT)) & SYSCTL0_STARTEN1_CLR_PMIC_MASK)

#define SYSCTL0_STARTEN1_CLR_SHA_MASK            (0x8000000U)
#define SYSCTL0_STARTEN1_CLR_SHA_SHIFT           (27U)
/*! SHA - Hash-AES wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SHA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SHA_SHIFT)) & SYSCTL0_STARTEN1_CLR_SHA_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM8_MASK      (0x10000000U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM8_SHIFT     (28U)
/*! FLEXCOMM8 - FLEXCOMM 8 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM8(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM8_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM8_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM9_MASK      (0x20000000U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM9_SHIFT     (29U)
/*! FLEXCOMM9 - FLEXCOMM 9 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM9(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM9_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM9_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM10_MASK     (0x40000000U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM10_SHIFT    (30U)
/*! FLEXCOMM10 - FLEXCOMM 10 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM10(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM10_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM10_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM11_MASK     (0x80000000U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM11_SHIFT    (31U)
/*! FLEXCOMM11 - FLEXCOMM 11 peripheral interrupt wake-up.
 *  0b0..No Effect
 *  0b1..Clears the STARTEN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM11(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM11_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM11_MASK)
/*! @} */

/*! @name STARTEN2_CLR - Start Enable 2 */
/*! @{ */

#define SYSCTL0_STARTEN2_CLR_FLEXCOMM12_MASK     (0x1U)
#define SYSCTL0_STARTEN2_CLR_FLEXCOMM12_SHIFT    (0U)
/*! FLEXCOMM12 - FlexComm 12 interrupt wake-up
 *  0b0..No effect
 *  0b1..Clears the STARTEN2 bit
 */
#define SYSCTL0_STARTEN2_CLR_FLEXCOMM12(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_CLR_FLEXCOMM12_SHIFT)) & SYSCTL0_STARTEN2_CLR_FLEXCOMM12_MASK)

#define SYSCTL0_STARTEN2_CLR_FLEXCOMM13_MASK     (0x2U)
#define SYSCTL0_STARTEN2_CLR_FLEXCOMM13_SHIFT    (1U)
/*! FLEXCOMM13 - FlexComm 13 interrupt wake-up
 *  0b0..No effect
 *  0b1..Clears the STARTEN2 bit
 */
#define SYSCTL0_STARTEN2_CLR_FLEXCOMM13(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_CLR_FLEXCOMM13_SHIFT)) & SYSCTL0_STARTEN2_CLR_FLEXCOMM13_MASK)

#define SYSCTL0_STARTEN2_CLR_FLEXCOMM16_MASK     (0x4U)
#define SYSCTL0_STARTEN2_CLR_FLEXCOMM16_SHIFT    (2U)
/*! FLEXCOMM16 - FlexComm 16 interrupt wake-up
 *  0b0..No effect
 *  0b1..Clears the STARTEN2 bit
 */
#define SYSCTL0_STARTEN2_CLR_FLEXCOMM16(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN2_CLR_FLEXCOMM16_SHIFT)) & SYSCTL0_STARTEN2_CLR_FLEXCOMM16_MASK)
/*! @} */

/*! @name FROSAFETY - FRO Safety */
/*! @{ */

#define SYSCTL0_FROSAFETY_FROSAFETY_MASK         (0xFFFFFFFFU)
#define SYSCTL0_FROSAFETY_FROSAFETY_SHIFT        (0U)
/*! FROSAFETY - FRO Safety */
#define SYSCTL0_FROSAFETY_FROSAFETY(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FROSAFETY_FROSAFETY_SHIFT)) & SYSCTL0_FROSAFETY_FROSAFETY_MASK)
/*! @} */

/*! @name MAINCLKSAFETY - Main Clock Safety */
/*! @{ */

#define SYSCTL0_MAINCLKSAFETY_DELAY_MASK         (0xFFFFU)
#define SYSCTL0_MAINCLKSAFETY_DELAY_SHIFT        (0U)
/*! DELAY - Main Clock turn on delay for Deep Sleep wake up */
#define SYSCTL0_MAINCLKSAFETY_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MAINCLKSAFETY_DELAY_SHIFT)) & SYSCTL0_MAINCLKSAFETY_DELAY_MASK)
/*! @} */

/*! @name HWWAKE - Hardware Wake */
/*! @{ */

#define SYSCTL0_HWWAKE_FORCEWAKE_MASK            (0x1U)
#define SYSCTL0_HWWAKE_FORCEWAKE_SHIFT           (0U)
/*! FORCEWAKE - Force peripheral clocking to stay on during deep-sleep mode. */
#define SYSCTL0_HWWAKE_FORCEWAKE(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_FORCEWAKE_SHIFT)) & SYSCTL0_HWWAKE_FORCEWAKE_MASK)

#define SYSCTL0_HWWAKE_FCWAKE_MASK               (0x2U)
#define SYSCTL0_HWWAKE_FCWAKE_SHIFT              (1U)
/*! FCWAKE - Wake for FlexComm Interfaces. */
#define SYSCTL0_HWWAKE_FCWAKE(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_FCWAKE_SHIFT)) & SYSCTL0_HWWAKE_FCWAKE_MASK)

#define SYSCTL0_HWWAKE_DMICWAKE_MASK             (0x4U)
#define SYSCTL0_HWWAKE_DMICWAKE_SHIFT            (2U)
/*! DMICWAKE - Wake for Digital Microphone. */
#define SYSCTL0_HWWAKE_DMICWAKE(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_DMICWAKE_SHIFT)) & SYSCTL0_HWWAKE_DMICWAKE_MASK)

#define SYSCTL0_HWWAKE_DMAC0WAKE_MASK            (0x8U)
#define SYSCTL0_HWWAKE_DMAC0WAKE_SHIFT           (3U)
/*! DMAC0WAKE - Wake for DMAC0. */
#define SYSCTL0_HWWAKE_DMAC0WAKE(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_DMAC0WAKE_SHIFT)) & SYSCTL0_HWWAKE_DMAC0WAKE_MASK)

#define SYSCTL0_HWWAKE_DMAC1WAKE_MASK            (0x10U)
#define SYSCTL0_HWWAKE_DMAC1WAKE_SHIFT           (4U)
/*! DMAC1WAKE - Wake for DMAC1. */
#define SYSCTL0_HWWAKE_DMAC1WAKE(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_DMAC1WAKE_SHIFT)) & SYSCTL0_HWWAKE_DMAC1WAKE_MASK)
/*! @} */

/*! @name TEMPSENSORCTL - Temperature Sensor Control */
/*! @{ */

#define SYSCTL0_TEMPSENSORCTL_TSSRC_MASK         (0x1U)
#define SYSCTL0_TEMPSENSORCTL_TSSRC_SHIFT        (0U)
/*! TSSRC - Temperature Sensor Source
 *  0b0..ADC Built-in Temperature Sensor
 *  0b1..PMC Temperature Sensor
 */
#define SYSCTL0_TEMPSENSORCTL_TSSRC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_TEMPSENSORCTL_TSSRC_SHIFT)) & SYSCTL0_TEMPSENSORCTL_TSSRC_MASK)
/*! @} */

/*! @name BOOTSTATELOCK - Boot State Lock */
/*! @{ */

#define SYSCTL0_BOOTSTATELOCK_BOOTSTATESEEDLOCK_MASK (0x1U)
#define SYSCTL0_BOOTSTATELOCK_BOOTSTATESEEDLOCK_SHIFT (0U)
/*! BOOTSTATESEEDLOCK - Boot State Seed Lockout
 *  0b0..BOOTSTATESEED[0:7] can be changed
 *  0b1..BOOTSTATESEED[0:7] cannot be changed
 */
#define SYSCTL0_BOOTSTATELOCK_BOOTSTATESEEDLOCK(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTSTATELOCK_BOOTSTATESEEDLOCK_SHIFT)) & SYSCTL0_BOOTSTATELOCK_BOOTSTATESEEDLOCK_MASK)

#define SYSCTL0_BOOTSTATELOCK_BOOTSTATEHMACLOCK_MASK (0x2U)
#define SYSCTL0_BOOTSTATELOCK_BOOTSTATEHMACLOCK_SHIFT (1U)
/*! BOOTSTATEHMACLOCK - Boot State HMA Lockout
 *  0b0..BOOTSTATEHMAC[0:7] can be changed
 *  0b1..BOOTSTATEHMAC[0:7] cannot be changed
 */
#define SYSCTL0_BOOTSTATELOCK_BOOTSTATEHMACLOCK(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTSTATELOCK_BOOTSTATEHMACLOCK_SHIFT)) & SYSCTL0_BOOTSTATELOCK_BOOTSTATEHMACLOCK_MASK)
/*! @} */

/*! @name BOOTSTATESEED - Boot State Seed */
/*! @{ */

#define SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_MASK (0xFFFFFFFFU)
#define SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_SHIFT (0U)
/*! BOOTSTATESEED - BOOTSTATESEED[0:7] */
#define SYSCTL0_BOOTSTATESEED_BOOTSTATESEED(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_SHIFT)) & SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_MASK)
/*! @} */

/*! @name BOOTSTATEHMAC - HMAC of boot state used for attestation. */
/*! @{ */

#define SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_MASK (0xFFFFFFFFU)
#define SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_SHIFT (0U)
/*! BOOTSTATEHMAC - BOOTSTATEHMAC[0:7] */
#define SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_SHIFT)) & SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_MASK)
/*! @} */

/*! @name FLEXSPI0PADCTL - FLEXSPI0 Pad Control */
/*! @{ */

#define SYSCTL0_FLEXSPI0PADCTL_RASRCN_3_0_MASK   (0xFU)
#define SYSCTL0_FLEXSPI0PADCTL_RASRCN_3_0_SHIFT  (0U)
/*! RASRCN_3_0 - Drives FLEXSPI0 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI0PADCTL_RASRCN_3_0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_RASRCN_3_0_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_RASRCN_3_0_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_RASRCP_3_0_MASK   (0xF0U)
#define SYSCTL0_FLEXSPI0PADCTL_RASRCP_3_0_SHIFT  (4U)
/*! RASRCP_3_0 - Drives FLEXSPI0 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI0PADCTL_RASRCP_3_0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_RASRCP_3_0_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_RASRCP_3_0_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_FASTFRZ_MASK      (0x100U)
#define SYSCTL0_FLEXSPI0PADCTL_FASTFRZ_SHIFT     (8U)
/*! FASTFRZ - Drives FLEXSPI0 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI0PADCTL_FASTFRZ(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_FASTFRZ_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_FASTFRZ_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_FREEZE_MASK       (0x200U)
#define SYSCTL0_FLEXSPI0PADCTL_FREEZE_SHIFT      (9U)
/*! FREEZE - Drives FLEXSPI0 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI0PADCTL_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_FREEZE_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_FREEZE_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_COMPTQ_MASK       (0x400U)
#define SYSCTL0_FLEXSPI0PADCTL_COMPTQ_SHIFT      (10U)
/*! COMPTQ - Drives FLEXSPI0 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI0PADCTL_COMPTQ(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_COMPTQ_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_COMPTQ_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_COMPEN_MASK       (0x800U)
#define SYSCTL0_FLEXSPI0PADCTL_COMPEN_SHIFT      (11U)
/*! COMPEN - Drives FLEXSPI0 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI0PADCTL_COMPEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_COMPEN_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_COMPEN_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_NASRCN_MASK       (0xF0000U)
#define SYSCTL0_FLEXSPI0PADCTL_NASRCN_SHIFT      (16U)
/*! NASRCN - FLEXSPI0 Pad Compensation Circuit Status */
#define SYSCTL0_FLEXSPI0PADCTL_NASRCN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_NASRCN_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_NASRCN_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_NASRCP_MASK       (0xF00000U)
#define SYSCTL0_FLEXSPI0PADCTL_NASRCP_SHIFT      (20U)
/*! NASRCP - FLEXSPI0 Pad Compensation Circuit Status */
#define SYSCTL0_FLEXSPI0PADCTL_NASRCP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_NASRCP_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_NASRCP_MASK)

#define SYSCTL0_FLEXSPI0PADCTL_COMPOK_MASK       (0x1000000U)
#define SYSCTL0_FLEXSPI0PADCTL_COMPOK_SHIFT      (24U)
/*! COMPOK - FLEXSPI0 Pad Compensation Circuit Status */
#define SYSCTL0_FLEXSPI0PADCTL_COMPOK(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI0PADCTL_COMPOK_SHIFT)) & SYSCTL0_FLEXSPI0PADCTL_COMPOK_MASK)
/*! @} */

/*! @name FLEXSPI1PADCTL - FLEXSPI1 Pad Control */
/*! @{ */

#define SYSCTL0_FLEXSPI1PADCTL_RASRCN_3_0_MASK   (0xFU)
#define SYSCTL0_FLEXSPI1PADCTL_RASRCN_3_0_SHIFT  (0U)
/*! RASRCN_3_0 - Drives FLEXSPI1 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI1PADCTL_RASRCN_3_0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_RASRCN_3_0_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_RASRCN_3_0_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_RASRCP_3_0_MASK   (0xF0U)
#define SYSCTL0_FLEXSPI1PADCTL_RASRCP_3_0_SHIFT  (4U)
/*! RASRCP_3_0 - Drives FLEXSPI1 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI1PADCTL_RASRCP_3_0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_RASRCP_3_0_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_RASRCP_3_0_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_FASTFRZ_MASK      (0x100U)
#define SYSCTL0_FLEXSPI1PADCTL_FASTFRZ_SHIFT     (8U)
/*! FASTFRZ - Drives FLEXSPI1 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI1PADCTL_FASTFRZ(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_FASTFRZ_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_FASTFRZ_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_FREEZE_MASK       (0x200U)
#define SYSCTL0_FLEXSPI1PADCTL_FREEZE_SHIFT      (9U)
/*! FREEZE - Drives FLEXSPI1 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI1PADCTL_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_FREEZE_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_FREEZE_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_COMPTQ_MASK       (0x400U)
#define SYSCTL0_FLEXSPI1PADCTL_COMPTQ_SHIFT      (10U)
/*! COMPTQ - Drives FLEXSPI1 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI1PADCTL_COMPTQ(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_COMPTQ_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_COMPTQ_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_COMPEN_MASK       (0x800U)
#define SYSCTL0_FLEXSPI1PADCTL_COMPEN_SHIFT      (11U)
/*! COMPEN - Drives FLEXSPI1 Pad Compensation Circuit */
#define SYSCTL0_FLEXSPI1PADCTL_COMPEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_COMPEN_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_COMPEN_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_NASRCN_3_0_MASK   (0xF0000U)
#define SYSCTL0_FLEXSPI1PADCTL_NASRCN_3_0_SHIFT  (16U)
/*! NASRCN_3_0 - FLEXSPI1 Pad Compensation Circuit Status */
#define SYSCTL0_FLEXSPI1PADCTL_NASRCN_3_0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_NASRCN_3_0_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_NASRCN_3_0_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_NASRCP_3_0_MASK   (0xF00000U)
#define SYSCTL0_FLEXSPI1PADCTL_NASRCP_3_0_SHIFT  (20U)
/*! NASRCP_3_0 - FLEXSPI1 Pad Compensation Circuit Status */
#define SYSCTL0_FLEXSPI1PADCTL_NASRCP_3_0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_NASRCP_3_0_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_NASRCP_3_0_MASK)

#define SYSCTL0_FLEXSPI1PADCTL_COMPOK_MASK       (0x1000000U)
#define SYSCTL0_FLEXSPI1PADCTL_COMPOK_SHIFT      (24U)
/*! COMPOK - FLEXSPI1 Pad Compensation Circuit Status */
#define SYSCTL0_FLEXSPI1PADCTL_COMPOK(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI1PADCTL_COMPOK_SHIFT)) & SYSCTL0_FLEXSPI1PADCTL_COMPOK_MASK)
/*! @} */

/*! @name SDIO0PADCTL - SDIO0 Pad Control */
/*! @{ */

#define SYSCTL0_SDIO0PADCTL_RASRCN_MASK          (0xFU)
#define SYSCTL0_SDIO0PADCTL_RASRCN_SHIFT         (0U)
/*! RASRCN - Drives SDIO0 Pad Compensation Circuit */
#define SYSCTL0_SDIO0PADCTL_RASRCN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_RASRCN_SHIFT)) & SYSCTL0_SDIO0PADCTL_RASRCN_MASK)

#define SYSCTL0_SDIO0PADCTL_RASRCP_MASK          (0xF0U)
#define SYSCTL0_SDIO0PADCTL_RASRCP_SHIFT         (4U)
/*! RASRCP - Drives SDIO0 Pad Compensation Circuit */
#define SYSCTL0_SDIO0PADCTL_RASRCP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_RASRCP_SHIFT)) & SYSCTL0_SDIO0PADCTL_RASRCP_MASK)

#define SYSCTL0_SDIO0PADCTL_FASTFRZ_MASK         (0x100U)
#define SYSCTL0_SDIO0PADCTL_FASTFRZ_SHIFT        (8U)
/*! FASTFRZ - Drives SDIO0 Pad Compensation Circuit */
#define SYSCTL0_SDIO0PADCTL_FASTFRZ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_FASTFRZ_SHIFT)) & SYSCTL0_SDIO0PADCTL_FASTFRZ_MASK)

#define SYSCTL0_SDIO0PADCTL_FREEZE_MASK          (0x200U)
#define SYSCTL0_SDIO0PADCTL_FREEZE_SHIFT         (9U)
/*! FREEZE - Drives SDIO0 Pad Compensation Circuit */
#define SYSCTL0_SDIO0PADCTL_FREEZE(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_FREEZE_SHIFT)) & SYSCTL0_SDIO0PADCTL_FREEZE_MASK)

#define SYSCTL0_SDIO0PADCTL_COMPTQ_MASK          (0x400U)
#define SYSCTL0_SDIO0PADCTL_COMPTQ_SHIFT         (10U)
/*! COMPTQ - Drives SDIO0 Pad Compensation Circuit */
#define SYSCTL0_SDIO0PADCTL_COMPTQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_COMPTQ_SHIFT)) & SYSCTL0_SDIO0PADCTL_COMPTQ_MASK)

#define SYSCTL0_SDIO0PADCTL_COMPEN_MASK          (0x800U)
#define SYSCTL0_SDIO0PADCTL_COMPEN_SHIFT         (11U)
/*! COMPEN - Drives SDIO0 Pad Compensation Circuit */
#define SYSCTL0_SDIO0PADCTL_COMPEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_COMPEN_SHIFT)) & SYSCTL0_SDIO0PADCTL_COMPEN_MASK)

#define SYSCTL0_SDIO0PADCTL_NASRCN_MASK          (0xF0000U)
#define SYSCTL0_SDIO0PADCTL_NASRCN_SHIFT         (16U)
/*! NASRCN - SDIO0 Pad Compensation Circuit Status */
#define SYSCTL0_SDIO0PADCTL_NASRCN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_NASRCN_SHIFT)) & SYSCTL0_SDIO0PADCTL_NASRCN_MASK)

#define SYSCTL0_SDIO0PADCTL_NASRCP_MASK          (0xF00000U)
#define SYSCTL0_SDIO0PADCTL_NASRCP_SHIFT         (20U)
/*! NASRCP - SDIO0 Pad Compensation Circuit Status */
#define SYSCTL0_SDIO0PADCTL_NASRCP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_NASRCP_SHIFT)) & SYSCTL0_SDIO0PADCTL_NASRCP_MASK)

#define SYSCTL0_SDIO0PADCTL_COMPOK_MASK          (0x1000000U)
#define SYSCTL0_SDIO0PADCTL_COMPOK_SHIFT         (24U)
/*! COMPOK - SDIO0 Pad Compensation Circuit Status */
#define SYSCTL0_SDIO0PADCTL_COMPOK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO0PADCTL_COMPOK_SHIFT)) & SYSCTL0_SDIO0PADCTL_COMPOK_MASK)
/*! @} */

/*! @name SDIO1PADCTL - SDIO1 Pad Control */
/*! @{ */

#define SYSCTL0_SDIO1PADCTL_RASRCN_MASK          (0xFU)
#define SYSCTL0_SDIO1PADCTL_RASRCN_SHIFT         (0U)
/*! RASRCN - Drives SDIO1 Pad Compensation Circuit */
#define SYSCTL0_SDIO1PADCTL_RASRCN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_RASRCN_SHIFT)) & SYSCTL0_SDIO1PADCTL_RASRCN_MASK)

#define SYSCTL0_SDIO1PADCTL_RASRCP_MASK          (0xF0U)
#define SYSCTL0_SDIO1PADCTL_RASRCP_SHIFT         (4U)
/*! RASRCP - Drives SDIO1 Pad Compensation Circuit */
#define SYSCTL0_SDIO1PADCTL_RASRCP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_RASRCP_SHIFT)) & SYSCTL0_SDIO1PADCTL_RASRCP_MASK)

#define SYSCTL0_SDIO1PADCTL_FASTFRZ_MASK         (0x100U)
#define SYSCTL0_SDIO1PADCTL_FASTFRZ_SHIFT        (8U)
/*! FASTFRZ - Drives SDIO1 Pad Compensation Circuit */
#define SYSCTL0_SDIO1PADCTL_FASTFRZ(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_FASTFRZ_SHIFT)) & SYSCTL0_SDIO1PADCTL_FASTFRZ_MASK)

#define SYSCTL0_SDIO1PADCTL_FREEZE_MASK          (0x200U)
#define SYSCTL0_SDIO1PADCTL_FREEZE_SHIFT         (9U)
/*! FREEZE - Drives SDIO1 Pad Compensation Circuit */
#define SYSCTL0_SDIO1PADCTL_FREEZE(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_FREEZE_SHIFT)) & SYSCTL0_SDIO1PADCTL_FREEZE_MASK)

#define SYSCTL0_SDIO1PADCTL_COMPTQ_MASK          (0x400U)
#define SYSCTL0_SDIO1PADCTL_COMPTQ_SHIFT         (10U)
/*! COMPTQ - Drives SDIO1 Pad Compensation Circuit */
#define SYSCTL0_SDIO1PADCTL_COMPTQ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_COMPTQ_SHIFT)) & SYSCTL0_SDIO1PADCTL_COMPTQ_MASK)

#define SYSCTL0_SDIO1PADCTL_COMPEN_MASK          (0x800U)
#define SYSCTL0_SDIO1PADCTL_COMPEN_SHIFT         (11U)
/*! COMPEN - Drives SDIO1 Pad Compensation Circuit */
#define SYSCTL0_SDIO1PADCTL_COMPEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_COMPEN_SHIFT)) & SYSCTL0_SDIO1PADCTL_COMPEN_MASK)

#define SYSCTL0_SDIO1PADCTL_NASRCN_MASK          (0xF0000U)
#define SYSCTL0_SDIO1PADCTL_NASRCN_SHIFT         (16U)
/*! NASRCN - SDIO1 Pad Compensation Circuit Status */
#define SYSCTL0_SDIO1PADCTL_NASRCN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_NASRCN_SHIFT)) & SYSCTL0_SDIO1PADCTL_NASRCN_MASK)

#define SYSCTL0_SDIO1PADCTL_NASRCP_MASK          (0xF00000U)
#define SYSCTL0_SDIO1PADCTL_NASRCP_SHIFT         (20U)
/*! NASRCP - SDIO1 Pad Compensation Circuit Status */
#define SYSCTL0_SDIO1PADCTL_NASRCP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_NASRCP_SHIFT)) & SYSCTL0_SDIO1PADCTL_NASRCP_MASK)

#define SYSCTL0_SDIO1PADCTL_COMPOK_MASK          (0x1000000U)
#define SYSCTL0_SDIO1PADCTL_COMPOK_SHIFT         (24U)
/*! COMPOK - SDIO1 Pad Compensation Circuit Status */
#define SYSCTL0_SDIO1PADCTL_COMPOK(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIO1PADCTL_COMPOK_SHIFT)) & SYSCTL0_SDIO1PADCTL_COMPOK_MASK)
/*! @} */

/*! @name DICEHWREGN - Compound Device Identifier (CDI) */
/*! @{ */

#define SYSCTL0_DICEHWREGN_DICEHWREGN_MASK       (0xFFFFFFFFU)
#define SYSCTL0_DICEHWREGN_DICEHWREGN_SHIFT      (0U)
/*! DICEHWREGN - DICE General Purpose 32-Bit Data Register */
#define SYSCTL0_DICEHWREGN_DICEHWREGN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DICEHWREGN_DICEHWREGN_SHIFT)) & SYSCTL0_DICEHWREGN_DICEHWREGN_MASK)
/*! @} */

/*! @name UUID - UUID */
/*! @{ */

#define SYSCTL0_UUID_UUIDN_MASK                  (0xFFFFFFFFU)
#define SYSCTL0_UUID_UUIDN_SHIFT                 (0U)
/*! UUIDN - UUIDn 32-Bit Data Register */
#define SYSCTL0_UUID_UUIDN(x)                    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_UUID_UUIDN_SHIFT)) & SYSCTL0_UUID_UUIDN_MASK)
/*! @} */

/*! @name AESKEY_SRCSEL - AES Key Source Select */
/*! @{ */

#define SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_MASK (0x3U)
#define SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_SHIFT (0U)
/*! AESKEY_SRCSEL - AES Key Source Select
 *  0b00..PUF
 *  0b01..PUF
 *  0b10..OTP
 *  0b11..PUF
 */
#define SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_SHIFT)) & SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_MASK)
/*! @} */

/*! @name OTFADKEY_SRCSEL - OTFAD Key Source Select */
/*! @{ */

#define SYSCTL0_OTFADKEY_SRCSEL_OTFADKEY_SRCSEL_MASK (0x3U)
#define SYSCTL0_OTFADKEY_SRCSEL_OTFADKEY_SRCSEL_SHIFT (0U)
/*! OTFADKEY_SRCSEL - OTFAD Key Source Select
 *  0b00..PUF
 *  0b01..PUF
 *  0b10..OTP
 *  0b11..PUF
 */
#define SYSCTL0_OTFADKEY_SRCSEL_OTFADKEY_SRCSEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_OTFADKEY_SRCSEL_OTFADKEY_SRCSEL_SHIFT)) & SYSCTL0_OTFADKEY_SRCSEL_OTFADKEY_SRCSEL_MASK)
/*! @} */

/*! @name HASHHWKEYDISABLE - HASH Hardware Key Disable */
/*! @{ */

#define SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_MASK (0xFFFFFFFFU)
#define SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_SHIFT (0U)
/*! HASHHWKEYDISABLE - HASH Hardware Key Disable */
#define SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_SHIFT)) & SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_MASK)
/*! @} */

/*! @name DBG_LOCKEN - Debug Lock Enable */
/*! @{ */

#define SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_MASK       (0xFU)
#define SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_SHIFT      (0U)
/*! DBG_LOCKEN - Debug Write Lock the following registers */
#define SYSCTL0_DBG_LOCKEN_DBG_LOCKEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_SHIFT)) & SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_MASK)
/*! @} */

/*! @name DBG_FEATURES - Debug Features */
/*! @{ */

#define SYSCTL0_DBG_FEATURES_DBGEN1_MASK         (0x3U)
#define SYSCTL0_DBG_FEATURES_DBGEN1_SHIFT        (0U)
/*! DBGEN1 - CM33 Debug Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_DBGEN1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DBGEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_DBGEN1_MASK)

#define SYSCTL0_DBG_FEATURES_NIDEN1_MASK         (0xCU)
#define SYSCTL0_DBG_FEATURES_NIDEN1_SHIFT        (2U)
/*! NIDEN1 - CM33 NID Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_NIDEN1(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_NIDEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_NIDEN1_MASK)

#define SYSCTL0_DBG_FEATURES_SPIDEN1_MASK        (0x30U)
#define SYSCTL0_DBG_FEATURES_SPIDEN1_SHIFT       (4U)
/*! SPIDEN1 - CM33 SPID Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_SPIDEN1(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_SPIDEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_SPIDEN1_MASK)

#define SYSCTL0_DBG_FEATURES_SPNIDEN1_MASK       (0xC0U)
#define SYSCTL0_DBG_FEATURES_SPNIDEN1_SHIFT      (6U)
/*! SPNIDEN1 - CM33 SPNIDEN Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_SPNIDEN1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_SPNIDEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_SPNIDEN1_MASK)
/*! @} */

/*! @name DBG_FEATURES_DP - Debug Features Duplicate */
/*! @{ */

#define SYSCTL0_DBG_FEATURES_DP_DBGEN1_MASK      (0x3U)
#define SYSCTL0_DBG_FEATURES_DP_DBGEN1_SHIFT     (0U)
/*! DBGEN1 - CM33 Debug Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_DBGEN1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_DBGEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_DBGEN1_MASK)

#define SYSCTL0_DBG_FEATURES_DP_NIDEN1_MASK      (0xCU)
#define SYSCTL0_DBG_FEATURES_DP_NIDEN1_SHIFT     (2U)
/*! NIDEN1 - CM33 NID Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_NIDEN1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_NIDEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_NIDEN1_MASK)

#define SYSCTL0_DBG_FEATURES_DP_SPIDEN1_MASK     (0x30U)
#define SYSCTL0_DBG_FEATURES_DP_SPIDEN1_SHIFT    (4U)
/*! SPIDEN1 - CM33 SPID Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_SPIDEN1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_SPIDEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_SPIDEN1_MASK)

#define SYSCTL0_DBG_FEATURES_DP_SPNIDEN1_MASK    (0xC0U)
#define SYSCTL0_DBG_FEATURES_DP_SPNIDEN1_SHIFT   (6U)
/*! SPNIDEN1 - CM33 SPNIDEN Enable Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_SPNIDEN1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_SPNIDEN1_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_SPNIDEN1_MASK)
/*! @} */

/*! @name CS_PROTCPU0 - Code Security for CPU0 */
/*! @{ */

#define SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_MASK     (0xFFFFFFFFU)
#define SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_SHIFT    (0U)
/*! CS_PROTCPU0 - Controls M33 AP Enable */
#define SYSCTL0_CS_PROTCPU0_CS_PROTCPU0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_SHIFT)) & SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_MASK)
/*! @} */

/*! @name CS_PROTCPU1 - Code Security for CPU1 */
/*! @{ */

#define SYSCTL0_CS_PROTCPU1_CS_PROTCPU1_MASK     (0xFFFFFFFFU)
#define SYSCTL0_CS_PROTCPU1_CS_PROTCPU1_SHIFT    (0U)
/*! CS_PROTCPU1 - Controls AP Enable */
#define SYSCTL0_CS_PROTCPU1_CS_PROTCPU1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CS_PROTCPU1_CS_PROTCPU1_SHIFT)) & SYSCTL0_CS_PROTCPU1_CS_PROTCPU1_MASK)
/*! @} */

/*! @name DBG_AUTH_SCRATCH - Debug authorization scratch */
/*! @{ */

#define SYSCTL0_DBG_AUTH_SCRATCH_DBG_AUTH_SCRATCH_MASK (0xFFFFFFFFU)
#define SYSCTL0_DBG_AUTH_SCRATCH_DBG_AUTH_SCRATCH_SHIFT (0U)
/*! DBG_AUTH_SCRATCH - Debug authorization scratch register for S/W. */
#define SYSCTL0_DBG_AUTH_SCRATCH_DBG_AUTH_SCRATCH(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_AUTH_SCRATCH_DBG_AUTH_SCRATCH_SHIFT)) & SYSCTL0_DBG_AUTH_SCRATCH_DBG_AUTH_SCRATCH_MASK)
/*! @} */

/*! @name KEY_BLOCK - Key block */
/*! @{ */

#define SYSCTL0_KEY_BLOCK_KEY_BLOCK_MASK         (0xFFFFFFFFU)
#define SYSCTL0_KEY_BLOCK_KEY_BLOCK_SHIFT        (0U)
/*! KEY_BLOCK - PUF key and data output */
#define SYSCTL0_KEY_BLOCK_KEY_BLOCK(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_KEY_BLOCK_KEY_BLOCK_SHIFT)) & SYSCTL0_KEY_BLOCK_KEY_BLOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCTL0_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCTL0_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SYSCTL0_H_ */

