/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCTL0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCTL0
 *
 * CMSIS Peripheral Access Layer for SYSCTL0
 */

#if !defined(PERI_SYSCTL0_H_)
#define PERI_SYSCTL0_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
#define SYSCTL0_BOOTSTATESEED_COUNT               8u
#define SYSCTL0_BOOTSTATEHMAC_COUNT               8u
#define SYSCTL0_DICEHWREG_COUNT                   8u
#define SYSCTL0_UUID_COUNT                        4u

/** SYSCTL0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12];
  __IO uint32_t DSPSTALL;                          /**< DSP stall register, offset: 0xC */
  __IO uint32_t AHBMATRIXPRIOR;                    /**< AHB matrix priority, offset: 0x10 */
  __IO uint32_t PACKERENABLE;                      /**< Packer enable for DSP RAM packer, offset: 0x14 */
       uint8_t RESERVED_1[24];
  __IO uint32_t M33NMISRCSEL;                      /**< M33 nmi source selection, offset: 0x30 */
  __IO uint32_t SYSTEM_STICK_CALIB;                /**< system stick calibration, offset: 0x34 */
  __IO uint32_t SYSTEM_NSTICK_CALIB;               /**< system nstick calibration, offset: 0x38 */
       uint8_t RESERVED_2[36];
  __I  uint32_t PRODUCT_ID;                        /**< product ID, offset: 0x60 */
  __I  uint32_t SILICONREV_ID;                     /**< SILICONREV ID, offset: 0x64 */
  __I  uint32_t JTAG_ID;                           /**< jtag ID, offset: 0x68 */
       uint8_t RESERVED_3[20];
  __IO uint32_t AUTOCLKGATEOVERRIDE0;              /**< auto clock gating override 0, offset: 0x80 */
  __IO uint32_t AUTOCLKGATEOVERRIDE1;              /**< auto clock gating override 1, offset: 0x84 */
       uint8_t RESERVED_4[24];
  __IO uint32_t CLKGATEOVERRIDE0;                  /**< Clock gate override 0, offset: 0xA0 */
       uint8_t RESERVED_5[92];
  __IO uint32_t AHB_SRAM_ACCESS_DISABLE;           /**< AHB SRAM access disable, offset: 0x100 */
  __IO uint32_t DSP_SRAM_ACCESS_DISABLE;           /**< DSP SRAM access disable, offset: 0x104 */
       uint8_t RESERVED_6[48];
  __IO uint32_t AHB_FLEXSPI_ACCESS_DISABLE;        /**< AHB Flexspi access control, offset: 0x138 */
  __IO uint32_t DSP_FLEXSPI_ACCESS_DISABLE;        /**< DSP Flexspi access control, offset: 0x13C */
       uint8_t RESERVED_7[576];
  __IO uint32_t FLEXSPI_BOOTROM_SCRATCH0;          /**< FLEXSPI NOR flash configure context register, offset: 0x380 */
       uint8_t RESERVED_8[136];
  __IO uint32_t USBCLKCTRL;                        /**< USB clock control, offset: 0x40C */
  __I  uint32_t USBCLKSTAT;                        /**< USB clock status, offset: 0x410 */
  __IO uint32_t USBPHYPLL0LOCKTIMEDIV2;            /**< USB PHY PLL0 lock time division 2, offset: 0x414 */
       uint8_t RESERVED_9[488];
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
  __O  uint32_t PDRUNCFG2_CLR;                     /**< Run configuration 2 clear, offset: 0x638 */
  __O  uint32_t PDRUNCFG3_CLR;                     /**< Run configuration 3 clear, offset: 0x63C */
       uint8_t RESERVED_10[32];
  __IO uint32_t PDWAKECFG;                         /**< PD Wake Configuration, offset: 0x660 */
       uint8_t RESERVED_11[28];
  __IO uint32_t STARTEN0;                          /**< Start enable 0, offset: 0x680 */
  __IO uint32_t STARTEN1;                          /**< Start enable 1, offset: 0x684 */
       uint8_t RESERVED_12[24];
  __O  uint32_t STARTEN0_SET;                      /**< Start enable 0 set, offset: 0x6A0 */
  __O  uint32_t STARTEN1_SET;                      /**< Start enable 1 set, offset: 0x6A4 */
       uint8_t RESERVED_13[24];
  __O  uint32_t STARTEN0_CLR;                      /**< Start enable 0 clear, offset: 0x6C0 */
  __O  uint32_t STARTEN1_CLR;                      /**< Start enable 1 clear, offset: 0x6C4 */
       uint8_t RESERVED_14[72];
  __IO uint32_t MAINCLKSAFETY;                     /**< Main Clock Safety, offset: 0x710 */
       uint8_t RESERVED_15[108];
  __IO uint32_t HWWAKE;                            /**< Hardware Wake-up control, offset: 0x780 */
       uint8_t RESERVED_16[1672];
  __IO uint32_t TEMPSENSORCTL;                     /**< tempsensor ctrl, offset: 0xE0C */
       uint8_t RESERVED_17[64];
  __IO uint32_t BOOTSTATESEED[SYSCTL0_BOOTSTATESEED_COUNT]; /**< boot state seed register, array offset: 0xE50, array step: 0x4 */
  __IO uint32_t BOOTSTATEHMAC[SYSCTL0_BOOTSTATEHMAC_COUNT]; /**< boot state hmac register, array offset: 0xE70, array step: 0x4 */
       uint8_t RESERVED_18[104];
  __IO uint32_t FLEXSPIPADCTRL;                    /**< FLEXSPI IO pads ctrl register, offset: 0xEF8 */
  __IO uint32_t SDIOPADCTL;                        /**< sdio pad ctrl, offset: 0xEFC */
  __IO uint32_t DICEHWREG[SYSCTL0_DICEHWREG_COUNT]; /**< DICE General Purpose 32-Bit Data Register, array offset: 0xF00, array step: 0x4 */
       uint8_t RESERVED_19[48];
  __I  uint32_t UUID[SYSCTL0_UUID_COUNT];          /**< UUIDn 32-Bit Data Register, array offset: 0xF50, array step: 0x4 */
       uint8_t RESERVED_20[32];
  __IO uint32_t AESKEY_SRCSEL;                     /**< AES key source selection, offset: 0xF80 */
       uint8_t RESERVED_21[4];
  __IO uint32_t HASHHWKEYDISABLE;                  /**< Hash hardware key disable, offset: 0xF88 */
       uint8_t RESERVED_22[20];
  __IO uint32_t DBG_LOCKEN;                        /**< Debug Write Lock registers, offset: 0xFA0 */
  __IO uint32_t DBG_FEATURES;                      /**< Debug features control for the CM33, offset: 0xFA4 */
  __IO uint32_t DBG_FEATURES_DP;                   /**< Debug features duplicate, offset: 0xFA8 */
  __IO uint32_t HWUNLOCK_DISABLE;                  /**< HW unlock disable, offset: 0xFAC */
       uint8_t RESERVED_23[4];
  __IO uint32_t CS_PROTCPU0;                       /**< Code Security for CPU0, offset: 0xFB4 */
  __IO uint32_t CS_PROTCPU1;                       /**< Code Security for CPU1, offset: 0xFB8 */
       uint8_t RESERVED_24[4];
  __IO uint32_t DBG_AUTH_SCRATCH;                  /**< Debug authorization scratch, offset: 0xFC0 */
       uint8_t RESERVED_25[12];
  __IO uint32_t KEY_BLOCK;                         /**< Key block, offset: 0xFD0 */
} SYSCTL0_Type;

/* ----------------------------------------------------------------------------
   -- SYSCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL0_Register_Masks SYSCTL0 Register Masks
 * @{
 */

/*! @name DSPSTALL - DSP stall register */
/*! @{ */

#define SYSCTL0_DSPSTALL_DSPSTALL_MASK           (0x1U)
#define SYSCTL0_DSPSTALL_DSPSTALL_SHIFT          (0U)
/*! DSPSTALL - Run / Stall Register. . .
 *  0b0..Run (Normal) Mode.
 *  0b1..Stall Mode.
 */
#define SYSCTL0_DSPSTALL_DSPSTALL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSPSTALL_DSPSTALL_SHIFT)) & SYSCTL0_DSPSTALL_DSPSTALL_MASK)
/*! @} */

/*! @name AHBMATRIXPRIOR - AHB matrix priority */
/*! @{ */

#define SYSCTL0_AHBMATRIXPRIOR_M0_MASK           (0x3U)
#define SYSCTL0_AHBMATRIXPRIOR_M0_SHIFT          (0U)
/*! M0 - Master 0 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. (0 High) */
#define SYSCTL0_AHBMATRIXPRIOR_M0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M0_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M0_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M1_MASK           (0xCU)
#define SYSCTL0_AHBMATRIXPRIOR_M1_SHIFT          (2U)
/*! M1 - Master 1 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M1_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M1_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M2_MASK           (0x30U)
#define SYSCTL0_AHBMATRIXPRIOR_M2_SHIFT          (4U)
/*! M2 - Master 2 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M2_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M2_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M3_MASK           (0xC0U)
#define SYSCTL0_AHBMATRIXPRIOR_M3_SHIFT          (6U)
/*! M3 - Master 3 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M3_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M3_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M4_MASK           (0x300U)
#define SYSCTL0_AHBMATRIXPRIOR_M4_SHIFT          (8U)
/*! M4 - Master 4 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M4(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M4_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M4_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M5_MASK           (0xC00U)
#define SYSCTL0_AHBMATRIXPRIOR_M5_SHIFT          (10U)
/*! M5 - Master 5 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M5(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M5_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M5_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M6_MASK           (0x3000U)
#define SYSCTL0_AHBMATRIXPRIOR_M6_SHIFT          (12U)
/*! M6 - Master 6 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M6(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M6_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M6_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M7_MASK           (0xC000U)
#define SYSCTL0_AHBMATRIXPRIOR_M7_SHIFT          (14U)
/*! M7 - Master 7 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M7(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M7_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M7_MASK)

#define SYSCTL0_AHBMATRIXPRIOR_M8_MASK           (0x30000U)
#define SYSCTL0_AHBMATRIXPRIOR_M8_SHIFT          (16U)
/*! M8 - Master 8 Priority. . . 0: 0, 1: 1, 2: 2, 3: 3. */
#define SYSCTL0_AHBMATRIXPRIOR_M8(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHBMATRIXPRIOR_M8_SHIFT)) & SYSCTL0_AHBMATRIXPRIOR_M8_MASK)
/*! @} */

/*! @name PACKERENABLE - Packer enable for DSP RAM packer */
/*! @{ */

#define SYSCTL0_PACKERENABLE_WRPENABLE_MASK      (0x1U)
#define SYSCTL0_PACKERENABLE_WRPENABLE_SHIFT     (0U)
/*! WRPENABLE - Write Packer Enable.
 *  0b0..disabled
 *  0b1..enabled
 */
#define SYSCTL0_PACKERENABLE_WRPENABLE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PACKERENABLE_WRPENABLE_SHIFT)) & SYSCTL0_PACKERENABLE_WRPENABLE_MASK)

#define SYSCTL0_PACKERENABLE_RDPENABLE_MASK      (0x2U)
#define SYSCTL0_PACKERENABLE_RDPENABLE_SHIFT     (1U)
/*! RDPENABLE - Read Packer Enable
 *  0b0..disabled
 *  0b1..enabled
 */
#define SYSCTL0_PACKERENABLE_RDPENABLE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PACKERENABLE_RDPENABLE_SHIFT)) & SYSCTL0_PACKERENABLE_RDPENABLE_MASK)
/*! @} */

/*! @name M33NMISRCSEL - M33 nmi source selection */
/*! @{ */

#define SYSCTL0_M33NMISRCSEL_NMISRCSEL_MASK      (0x7FU)
#define SYSCTL0_M33NMISRCSEL_NMISRCSEL_SHIFT     (0U)
/*! NMISRCSEL - Selects one of the M33 interrupt sources as the NMI source. See M33 Interrupt Slot Table for Interrupt Slot Numers. */
#define SYSCTL0_M33NMISRCSEL_NMISRCSEL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_M33NMISRCSEL_NMISRCSEL_SHIFT)) & SYSCTL0_M33NMISRCSEL_NMISRCSEL_MASK)

#define SYSCTL0_M33NMISRCSEL_NMIEN_MASK          (0x80000000U)
#define SYSCTL0_M33NMISRCSEL_NMIEN_SHIFT         (31U)
/*! NMIEN - NMI interrupt enable
 *  0b0..Disable NMI Interrupt
 *  0b1..Enable NMI Interrupt.
 */
#define SYSCTL0_M33NMISRCSEL_NMIEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_M33NMISRCSEL_NMIEN_SHIFT)) & SYSCTL0_M33NMISRCSEL_NMIEN_MASK)
/*! @} */

/*! @name SYSTEM_STICK_CALIB - system stick calibration */
/*! @{ */

#define SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_MASK (0x3FFFFFFU)
#define SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_SHIFT (0U)
/*! SYSTEM_STICK_CALIB - Selects the system secure tick calibration value of the M33. */
#define SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_SHIFT)) & SYSCTL0_SYSTEM_STICK_CALIB_SYSTEM_STICK_CALIB_MASK)
/*! @} */

/*! @name SYSTEM_NSTICK_CALIB - system nstick calibration */
/*! @{ */

#define SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_MASK (0x3FFFFFFU)
#define SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_SHIFT (0U)
/*! SYSTEM_NSTICK_CALIB - Selects the system non-secure tick calibration value of the M33. */
#define SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_SHIFT)) & SYSCTL0_SYSTEM_NSTICK_CALIB_SYSTEM_NSTICK_CALIB_MASK)
/*! @} */

/*! @name PRODUCT_ID - product ID */
/*! @{ */

#define SYSCTL0_PRODUCT_ID_PRODUCT_ID_MASK       (0xFFFFU)
#define SYSCTL0_PRODUCT_ID_PRODUCT_ID_SHIFT      (0U)
/*! PRODUCT_ID - This register contains the product ID which is unique for each part number. */
#define SYSCTL0_PRODUCT_ID_PRODUCT_ID(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PRODUCT_ID_PRODUCT_ID_SHIFT)) & SYSCTL0_PRODUCT_ID_PRODUCT_ID_MASK)
/*! @} */

/*! @name SILICONREV_ID - SILICONREV ID */
/*! @{ */

#define SYSCTL0_SILICONREV_ID_MINOR_MASK         (0xFU)
#define SYSCTL0_SILICONREV_ID_MINOR_SHIFT        (0U)
/*! MINOR - Silicon revision minor tag. (IE, 0, 2, 3, etc) */
#define SYSCTL0_SILICONREV_ID_MINOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SILICONREV_ID_MINOR_SHIFT)) & SYSCTL0_SILICONREV_ID_MINOR_MASK)

#define SYSCTL0_SILICONREV_ID_MAJOR_MASK         (0xF0000U)
#define SYSCTL0_SILICONREV_ID_MAJOR_SHIFT        (16U)
/*! MAJOR - Silicon revision major tag. (IE, A, B, C, etc) */
#define SYSCTL0_SILICONREV_ID_MAJOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SILICONREV_ID_MAJOR_SHIFT)) & SYSCTL0_SILICONREV_ID_MAJOR_MASK)
/*! @} */

/*! @name JTAG_ID - jtag ID */
/*! @{ */

#define SYSCTL0_JTAG_ID_FIXBIT_MASK              (0x1U)
#define SYSCTL0_JTAG_ID_FIXBIT_SHIFT             (0U)
/*! FIXBIT - JTAG IDCODE fix bit */
#define SYSCTL0_JTAG_ID_FIXBIT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_FIXBIT_SHIFT)) & SYSCTL0_JTAG_ID_FIXBIT_MASK)

#define SYSCTL0_JTAG_ID_MANU_MASK                (0xFFEU)
#define SYSCTL0_JTAG_ID_MANU_SHIFT               (1U)
/*! MANU - JTAG IDCODE manufacturer identity */
#define SYSCTL0_JTAG_ID_MANU(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_MANU_SHIFT)) & SYSCTL0_JTAG_ID_MANU_MASK)

#define SYSCTL0_JTAG_ID_PARTNUM_MASK             (0xFFFF000U)
#define SYSCTL0_JTAG_ID_PARTNUM_SHIFT            (12U)
/*! PARTNUM - JTAG IDCODE part number */
#define SYSCTL0_JTAG_ID_PARTNUM(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_PARTNUM_SHIFT)) & SYSCTL0_JTAG_ID_PARTNUM_MASK)

#define SYSCTL0_JTAG_ID_VERNUM_MASK              (0xF0000000U)
#define SYSCTL0_JTAG_ID_VERNUM_SHIFT             (28U)
/*! VERNUM - JTAG IDCODE version number */
#define SYSCTL0_JTAG_ID_VERNUM(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_JTAG_ID_VERNUM_SHIFT)) & SYSCTL0_JTAG_ID_VERNUM_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE0 - auto clock gating override 0 */
/*! @{ */

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_MASK (0x1U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_SHIFT (0U)
/*! AHB2APB0 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB0_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_MASK (0x2U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_SHIFT (1U)
/*! AHB2APB1 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_AHB2APB1_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_MASK (0x4U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_SHIFT (2U)
/*! CRC_Engine - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_CRC_ENGINE_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_MASK (0x8U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_SHIFT (3U)
/*! Casper - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_CASPER_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_MASK  (0x10U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_SHIFT (4U)
/*! DMAC0 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC0_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_MASK  (0x20U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_SHIFT (5U)
/*! DMAC1 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE0_DMAC1_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE1 - auto clock gating override 1 */
/*! @{ */

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF0_MASK (0x1U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF0_SHIFT (0U)
/*! SRAM_IF0 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF0(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF0_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF0_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF1_MASK (0x2U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF1_SHIFT (1U)
/*! SRAM_IF1 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF1(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF1_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF1_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF2_MASK (0x4U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF2_SHIFT (2U)
/*! SRAM_IF2 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF2(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF2_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF2_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF3_MASK (0x8U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF3_SHIFT (3U)
/*! SRAM_IF3 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF3(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF3_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF3_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF4_MASK (0x10U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF4_SHIFT (4U)
/*! SRAM_IF4 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF4(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF4_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF4_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF5_MASK (0x20U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF5_SHIFT (5U)
/*! SRAM_IF5 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF5(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF5_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF5_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF6_MASK (0x40U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF6_SHIFT (6U)
/*! SRAM_IF6 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF6(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF6_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF6_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF7_MASK (0x80U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF7_SHIFT (7U)
/*! SRAM_IF7 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF7(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF7_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF7_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF8_MASK (0x100U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF8_SHIFT (8U)
/*! SRAM_IF8 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF8(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF8_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF8_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF9_MASK (0x200U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF9_SHIFT (9U)
/*! SRAM_IF9 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF9(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF9_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF9_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF10_MASK (0x400U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF10_SHIFT (10U)
/*! SRAM_IF10 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF10(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF10_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF10_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF11_MASK (0x800U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF11_SHIFT (11U)
/*! SRAM_IF11 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF11(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF11_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF11_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF12_MASK (0x1000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF12_SHIFT (12U)
/*! SRAM_IF12 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF12(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF12_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF12_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF13_MASK (0x2000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF13_SHIFT (13U)
/*! SRAM_IF13 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF13(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF13_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF13_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF14_MASK (0x4000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF14_SHIFT (14U)
/*! SRAM_IF14 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF14(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF14_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF14_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF15_MASK (0x8000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF15_SHIFT (15U)
/*! SRAM_IF15 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF15(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF15_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF15_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF16_MASK (0x10000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF16_SHIFT (16U)
/*! SRAM_IF16 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF16(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF16_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF16_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF17_MASK (0x20000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF17_SHIFT (17U)
/*! SRAM_IF17 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF17(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF17_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF17_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF18_MASK (0x40000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF18_SHIFT (18U)
/*! SRAM_IF18 - auto clock gating enable */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF18(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF18_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF18_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF19_MASK (0x80000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF19_SHIFT (19U)
/*! SRAM_IF19 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF19(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF19_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF19_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF20_MASK (0x100000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF20_SHIFT (20U)
/*! SRAM_IF20 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF20(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF20_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF20_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF21_MASK (0x200000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF21_SHIFT (21U)
/*! SRAM_IF21 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF21(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF21_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF21_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF22_MASK (0x400000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF22_SHIFT (22U)
/*! SRAM_IF22 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF22(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF22_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF22_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF23_MASK (0x800000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF23_SHIFT (23U)
/*! SRAM_IF23 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF23(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF23_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF23_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF24_MASK (0x1000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF24_SHIFT (24U)
/*! SRAM_IF24 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF24(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF24_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF24_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF25_MASK (0x2000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF25_SHIFT (25U)
/*! SRAM_IF25 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF25(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF25_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF25_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF26_MASK (0x4000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF26_SHIFT (26U)
/*! SRAM_IF26 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF26(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF26_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF26_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF27_MASK (0x8000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF27_SHIFT (27U)
/*! SRAM_IF27 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF27(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF27_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF27_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF28_MASK (0x10000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF28_SHIFT (28U)
/*! SRAM_IF28 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF28(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF28_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF28_MASK)

#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF29_MASK (0x20000000U)
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF29_SHIFT (29U)
/*! SRAM_IF29 - auto clock gating enable
 *  0b0..Enable Auto-Clk
 *  0b1..Disable Auto-Clk
 */
#define SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF29(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF29_SHIFT)) & SYSCTL0_AUTOCLKGATEOVERRIDE1_SRAM_IF29_MASK)
/*! @} */

/*! @name CLKGATEOVERRIDE0 - Clock gate override 0 */
/*! @{ */

#define SYSCTL0_CLKGATEOVERRIDE0_SDIO_0_MASK     (0x1U)
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO_0_SHIFT    (0U)
/*! SDIO_0 - sdio 0 clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO_0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_SDIO_0_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_SDIO_0_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_SDIO_1_MASK     (0x2U)
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO_1_SHIFT    (1U)
/*! SDIO_1 - sdio 1 clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_SDIO_1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_SDIO_1_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_SDIO_1_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_USBHSPHY_MASK   (0x4U)
#define SYSCTL0_CLKGATEOVERRIDE0_USBHSPHY_SHIFT  (2U)
/*! USBHSPHY - usbhsphy clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_USBHSPHY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_USBHSPHY_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_USBHSPHY_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_ADC_MASK        (0x8U)
#define SYSCTL0_CLKGATEOVERRIDE0_ADC_SHIFT       (3U)
/*! ADC - adc clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_ADC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_ADC_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_ADC_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_MU_MASK         (0x10U)
#define SYSCTL0_CLKGATEOVERRIDE0_MU_SHIFT        (4U)
/*! MU - mu clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_MU(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_MU_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_MU_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_ACMP_MASK       (0x20U)
#define SYSCTL0_CLKGATEOVERRIDE0_ACMP_SHIFT      (5U)
/*! ACMP - acomparator clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_ACMP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_ACMP_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_ACMP_MASK)

#define SYSCTL0_CLKGATEOVERRIDE0_PMC_MASK        (0x40U)
#define SYSCTL0_CLKGATEOVERRIDE0_PMC_SHIFT       (6U)
/*! PMC - pmc clock override
 *  0b0..no effect
 *  0b1..override
 */
#define SYSCTL0_CLKGATEOVERRIDE0_PMC(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CLKGATEOVERRIDE0_PMC_SHIFT)) & SYSCTL0_CLKGATEOVERRIDE0_PMC_MASK)
/*! @} */

/*! @name AHB_SRAM_ACCESS_DISABLE - AHB SRAM access disable */
/*! @{ */

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK (0x1U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT (0U)
/*! SRAM00_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK (0x2U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT (1U)
/*! SRAM01_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK (0x4U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT (2U)
/*! SRAM02_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK (0x8U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT (3U)
/*! SRAM03_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK (0x10U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT (4U)
/*! SRAM04_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK (0x20U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT (5U)
/*! SRAM05_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK (0x40U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT (6U)
/*! SRAM06_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK (0x80U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT (7U)
/*! SRAM07_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK (0x100U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT (8U)
/*! SRAM08_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK (0x200U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT (9U)
/*! SRAM09_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM10_IF_MASK (0x400U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM10_IF_SHIFT (10U)
/*! SRAM10_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM10_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM10_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM10_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM11_IF_MASK (0x800U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM11_IF_SHIFT (11U)
/*! SRAM11_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM11_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM11_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM11_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM12_IF_MASK (0x1000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM12_IF_SHIFT (12U)
/*! SRAM12_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM12_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM12_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM12_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM13_IF_MASK (0x2000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM13_IF_SHIFT (13U)
/*! SRAM13_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM13_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM13_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM13_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM14_IF_MASK (0x4000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM14_IF_SHIFT (14U)
/*! SRAM14_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM14_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM14_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM14_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM15_IF_MASK (0x8000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM15_IF_SHIFT (15U)
/*! SRAM15_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM15_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM15_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM15_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM16_IF_MASK (0x10000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM16_IF_SHIFT (16U)
/*! SRAM16_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM16_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM16_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM16_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM17_IF_MASK (0x20000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM17_IF_SHIFT (17U)
/*! SRAM17_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM17_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM17_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM17_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM18_IF_MASK (0x40000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM18_IF_SHIFT (18U)
/*! SRAM18_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM18_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM18_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM18_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM19_IF_MASK (0x80000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM19_IF_SHIFT (19U)
/*! SRAM19_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM19_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM19_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM19_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM20_IF_MASK (0x100000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM20_IF_SHIFT (20U)
/*! SRAM20_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM20_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM20_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM20_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM21_IF_MASK (0x200000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM21_IF_SHIFT (21U)
/*! SRAM21_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM21_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM21_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM21_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM22_IF_MASK (0x400000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM22_IF_SHIFT (22U)
/*! SRAM22_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM22_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM22_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM22_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM23_IF_MASK (0x800000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM23_IF_SHIFT (23U)
/*! SRAM23_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM23_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM23_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM23_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM24_IF_MASK (0x1000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM24_IF_SHIFT (24U)
/*! SRAM24_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM24_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM24_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM24_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM25_IF_MASK (0x2000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM25_IF_SHIFT (25U)
/*! SRAM25_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM25_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM25_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM25_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM26_IF_MASK (0x4000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM26_IF_SHIFT (26U)
/*! SRAM26_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM26_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM26_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM26_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM27_IF_MASK (0x8000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM27_IF_SHIFT (27U)
/*! SRAM27_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM27_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM27_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM27_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM28_IF_MASK (0x10000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM28_IF_SHIFT (28U)
/*! SRAM28_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM28_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM28_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM28_IF_MASK)

#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM29_IF_MASK (0x20000000U)
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM29_IF_SHIFT (29U)
/*! SRAM29_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM29_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM29_IF_SHIFT)) & SYSCTL0_AHB_SRAM_ACCESS_DISABLE_SRAM29_IF_MASK)
/*! @} */

/*! @name DSP_SRAM_ACCESS_DISABLE - DSP SRAM access disable */
/*! @{ */

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK (0x1U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT (0U)
/*! SRAM00_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM00_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM00_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM00_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK (0x2U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT (1U)
/*! SRAM01_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM01_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM01_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM01_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK (0x4U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT (2U)
/*! SRAM02_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM02_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM02_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM02_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK (0x8U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT (3U)
/*! SRAM03_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM03_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM03_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM03_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK (0x10U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT (4U)
/*! SRAM04_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM04_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM04_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM04_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK (0x20U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT (5U)
/*! SRAM05_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM05_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM05_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM05_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK (0x40U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT (6U)
/*! SRAM06_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM06_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM06_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM06_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK (0x80U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT (7U)
/*! SRAM07_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM07_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM07_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM07_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK (0x100U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT (8U)
/*! SRAM08_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM08_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM08_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM08_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK (0x200U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT (9U)
/*! SRAM09_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM09_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM09_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM09_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_MASK (0x400U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_SHIFT (10U)
/*! SRAM10_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM10_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_MASK (0x800U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_SHIFT (11U)
/*! SRAM11_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM11_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_MASK (0x1000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_SHIFT (12U)
/*! SRAM12_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM12_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_MASK (0x2000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_SHIFT (13U)
/*! SRAM13_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM13_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_MASK (0x4000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_SHIFT (14U)
/*! SRAM14_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM14_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_MASK (0x8000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_SHIFT (15U)
/*! SRAM15_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM15_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_MASK (0x10000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_SHIFT (16U)
/*! SRAM16_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM16_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_MASK (0x20000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_SHIFT (17U)
/*! SRAM17_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM17_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_MASK (0x40000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_SHIFT (18U)
/*! SRAM18_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM18_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_MASK (0x80000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_SHIFT (19U)
/*! SRAM19_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM19_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_MASK (0x100000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_SHIFT (20U)
/*! SRAM20_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM20_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_MASK (0x200000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_SHIFT (21U)
/*! SRAM21_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM21_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_MASK (0x400000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_SHIFT (22U)
/*! SRAM22_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM22_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_MASK (0x800000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_SHIFT (23U)
/*! SRAM23_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM23_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_MASK (0x1000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_SHIFT (24U)
/*! SRAM24_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM24_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_MASK (0x2000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_SHIFT (25U)
/*! SRAM25_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM25_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_MASK (0x4000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_SHIFT (26U)
/*! SRAM26_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM26_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_MASK (0x8000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_SHIFT (27U)
/*! SRAM27_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM27_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_MASK (0x10000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_SHIFT (28U)
/*! SRAM28_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM28_IF_MASK)

#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_MASK (0x20000000U)
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_SHIFT (29U)
/*! SRAM29_IF
 *  0b0..enable
 *  0b1..disable
 */
#define SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_SHIFT)) & SYSCTL0_DSP_SRAM_ACCESS_DISABLE_SRAM29_IF_MASK)
/*! @} */

/*! @name AHB_FLEXSPI_ACCESS_DISABLE - AHB Flexspi access control */
/*! @{ */

#define SYSCTL0_AHB_FLEXSPI_ACCESS_DISABLE_AHB_FLEXSPI_ACCESS_DISABLE_MASK (0x1U)
#define SYSCTL0_AHB_FLEXSPI_ACCESS_DISABLE_AHB_FLEXSPI_ACCESS_DISABLE_SHIFT (0U)
/*! AHB_FLEXSPI_ACCESS_DISABLE
 *  0b0..Enable AHB access to FLEXSPI
 *  0b1..Disable AHB access to FLEXSPI
 */
#define SYSCTL0_AHB_FLEXSPI_ACCESS_DISABLE_AHB_FLEXSPI_ACCESS_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AHB_FLEXSPI_ACCESS_DISABLE_AHB_FLEXSPI_ACCESS_DISABLE_SHIFT)) & SYSCTL0_AHB_FLEXSPI_ACCESS_DISABLE_AHB_FLEXSPI_ACCESS_DISABLE_MASK)
/*! @} */

/*! @name DSP_FLEXSPI_ACCESS_DISABLE - DSP Flexspi access control */
/*! @{ */

#define SYSCTL0_DSP_FLEXSPI_ACCESS_DISABLE_DSP_FLEXSPI_ACCESS_DISABLE_MASK (0x1U)
#define SYSCTL0_DSP_FLEXSPI_ACCESS_DISABLE_DSP_FLEXSPI_ACCESS_DISABLE_SHIFT (0U)
/*! DSP_FLEXSPI_ACCESS_DISABLE
 *  0b0..Enable DSP access to FLEXSPI
 *  0b1..Disable DSP access to FLEXSPI
 */
#define SYSCTL0_DSP_FLEXSPI_ACCESS_DISABLE_DSP_FLEXSPI_ACCESS_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DSP_FLEXSPI_ACCESS_DISABLE_DSP_FLEXSPI_ACCESS_DISABLE_SHIFT)) & SYSCTL0_DSP_FLEXSPI_ACCESS_DISABLE_DSP_FLEXSPI_ACCESS_DISABLE_MASK)
/*! @} */

/*! @name FLEXSPI_BOOTROM_SCRATCH0 - FLEXSPI NOR flash configure context register */
/*! @{ */

#define SYSCTL0_FLEXSPI_BOOTROM_SCRATCH0_SCRATCH_MASK (0xFFFFFFFFU)
#define SYSCTL0_FLEXSPI_BOOTROM_SCRATCH0_SCRATCH_SHIFT (0U)
#define SYSCTL0_FLEXSPI_BOOTROM_SCRATCH0_SCRATCH(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPI_BOOTROM_SCRATCH0_SCRATCH_SHIFT)) & SYSCTL0_FLEXSPI_BOOTROM_SCRATCH0_SCRATCH_MASK)
/*! @} */

/*! @name USBCLKCTRL - USB clock control */
/*! @{ */

#define SYSCTL0_USBCLKCTRL_AP_DEV_CLK_MASK       (0x1U)
#define SYSCTL0_USBCLKCTRL_AP_DEV_CLK_SHIFT      (0U)
/*! AP_DEV_CLK - USB0 Device need clock signal control
 *  0b0..Under hardware control.
 *  0b1..Forced high.
 */
#define SYSCTL0_USBCLKCTRL_AP_DEV_CLK(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKCTRL_AP_DEV_CLK_SHIFT)) & SYSCTL0_USBCLKCTRL_AP_DEV_CLK_MASK)

#define SYSCTL0_USBCLKCTRL_POL_DEV_CLK_MASK      (0x2U)
#define SYSCTL0_USBCLKCTRL_POL_DEV_CLK_SHIFT     (1U)
/*! POL_DEV_CLK - USB0 Device need clock polarity for triggering the USB1 wake-up interrupt
 *  0b0..Falling edge of device need_clock triggers wake-up.
 *  0b1..Rising edge of device need_clock triggers wake-up.
 */
#define SYSCTL0_USBCLKCTRL_POL_DEV_CLK(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKCTRL_POL_DEV_CLK_SHIFT)) & SYSCTL0_USBCLKCTRL_POL_DEV_CLK_MASK)

#define SYSCTL0_USBCLKCTRL_AP_HOST_CLK_MASK      (0x4U)
#define SYSCTL0_USBCLKCTRL_AP_HOST_CLK_SHIFT     (2U)
/*! AP_HOST_CLK - USB0 Host need clock signal control
 *  0b0..Under hardware control.
 *  0b1..Forced high.
 */
#define SYSCTL0_USBCLKCTRL_AP_HOST_CLK(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKCTRL_AP_HOST_CLK_SHIFT)) & SYSCTL0_USBCLKCTRL_AP_HOST_CLK_MASK)

#define SYSCTL0_USBCLKCTRL_POL_HOST_CLK_MASK     (0x8U)
#define SYSCTL0_USBCLKCTRL_POL_HOST_CLK_SHIFT    (3U)
/*! POL_HOST_CLK - USB0 HOST need clock polarity for triggering the USB1 wake-up interrupt
 *  0b0..Falling edge of host need_clock triggers wake-up.
 *  0b1..Rising edge of host need_clock triggers wake-up.
 */
#define SYSCTL0_USBCLKCTRL_POL_HOST_CLK(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKCTRL_POL_HOST_CLK_SHIFT)) & SYSCTL0_USBCLKCTRL_POL_HOST_CLK_MASK)

#define SYSCTL0_USBCLKCTRL_HS_DEV_WAKEUP_N_MASK  (0x10U)
#define SYSCTL0_USBCLKCTRL_HS_DEV_WAKEUP_N_SHIFT (4U)
/*! HS_DEV_WAKEUP_N - External user wake-up signal for device mode; asserting this signal (active
 *    low) will result in exiting the low power mode; input to asynchronous control logic
 *  0b0..Forces USB0 PHY to wake-up.
 *  0b1..Normal USB0 PHY behavior.
 */
#define SYSCTL0_USBCLKCTRL_HS_DEV_WAKEUP_N(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKCTRL_HS_DEV_WAKEUP_N_SHIFT)) & SYSCTL0_USBCLKCTRL_HS_DEV_WAKEUP_N_MASK)
/*! @} */

/*! @name USBCLKSTAT - USB clock status */
/*! @{ */

#define SYSCTL0_USBCLKSTAT_DEV_NEED_CLKST_MASK   (0x1U)
#define SYSCTL0_USBCLKSTAT_DEV_NEED_CLKST_SHIFT  (0U)
/*! DEV_NEED_CLKST - USB Device USB_NEEDCLK signal status:
 *  0b0..low
 *  0b1..high
 */
#define SYSCTL0_USBCLKSTAT_DEV_NEED_CLKST(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKSTAT_DEV_NEED_CLKST_SHIFT)) & SYSCTL0_USBCLKSTAT_DEV_NEED_CLKST_MASK)

#define SYSCTL0_USBCLKSTAT_HOST_NEED_CLKST_MASK  (0x2U)
#define SYSCTL0_USBCLKSTAT_HOST_NEED_CLKST_SHIFT (1U)
/*! HOST_NEED_CLKST - USB Device Host USB_NEEDCLK signal status:
 *  0b0..low
 *  0b1..high
 */
#define SYSCTL0_USBCLKSTAT_HOST_NEED_CLKST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBCLKSTAT_HOST_NEED_CLKST_SHIFT)) & SYSCTL0_USBCLKSTAT_HOST_NEED_CLKST_MASK)
/*! @} */

/*! @name USBPHYPLL0LOCKTIMEDIV2 - USB PHY PLL0 lock time division 2 */
/*! @{ */

#define SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK (0xFFFFU)
#define SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT (0U)
/*! LOCKTIMEDIV2 - USBPHYPLL0 Lock Time: Programmed lock time is in uS (micro-seconds) and is programmed as half the actual lock time value */
#define SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_SHIFT)) & SYSCTL0_USBPHYPLL0LOCKTIMEDIV2_LOCKTIMEDIV2_MASK)
/*! @} */

/*! @name PDSLEEPCFG0 - Sleep configuration 0 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_MASK (0x1U)
#define SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_SHIFT (0U)
/*! MAINCLK_SHUTOFF - main clock shut off
 *  0b0..Clocks enabled
 *  0b1..Clocks gated
 */
#define SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_SHIFT)) & SYSCTL0_PDSLEEPCFG0_MAINCLK_SHUTOFF_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_MASK      (0x2U)
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_SHIFT     (1U)
/*! PMIC_MODE0
 *  0b0..Set Mode0 to '0'.
 *  0b1..Set Mode0 to '1'.
 */
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMIC_MODE0_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_MASK      (0x4U)
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_SHIFT     (2U)
/*! PMIC_MODE1
 *  0b0..Set Mode1 to 0.
 *  0b1..Set Mode1 to 1.
 */
#define SYSCTL0_PDSLEEPCFG0_PMIC_MODE1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMIC_MODE1_MASK)

#define SYSCTL0_PDSLEEPCFG0_DEEP_PD_MASK         (0x8U)
#define SYSCTL0_PDSLEEPCFG0_DEEP_PD_SHIFT        (3U)
/*! DEEP_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_DEEP_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_DEEP_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_DEEP_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_MASK   (0x10U)
#define SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_SHIFT  (4U)
/*! VDDCOREREG_LP
 *  0b0..VDDCOREREG HP Mode
 *  0b1..LP Mode
 */
#define SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_PMCREF_LP_MASK       (0x40U)
#define SYSCTL0_PDSLEEPCFG0_PMCREF_LP_SHIFT      (6U)
/*! PMCREF_LP
 *  0b0..PMCREF HP Mode
 *  0b1..PMCREF LP Mode
 */
#define SYSCTL0_PDSLEEPCFG0_PMCREF_LP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PMCREF_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PMCREF_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_MASK       (0x80U)
#define SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_SHIFT      (7U)
/*! HVD1V8_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_HVD1V8_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HVD1V8_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_PORCORE_LP_MASK      (0x100U)
#define SYSCTL0_PDSLEEPCFG0_PORCORE_LP_SHIFT     (8U)
/*! PORCORE_LP
 *  0b0..LVD0V6 HP Mode
 *  0b1..LVD0V6 LP Mode
 */
#define SYSCTL0_PDSLEEPCFG0_PORCORE_LP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_PORCORE_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_PORCORE_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_MASK      (0x200U)
#define SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_SHIFT     (9U)
/*! LVDCORE_LP
 *  0b0..LVD0V85 HP Mode
 *  0b1..LVD0V85 LP Mode.
 */
#define SYSCTL0_PDSLEEPCFG0_LVDCORE_LP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_LVDCORE_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_MASK      (0x400U)
#define SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_SHIFT     (10U)
/*! HVDCORE_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_HVDCORE_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HVDCORE_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_RBB_PD_MASK          (0x800U)
#define SYSCTL0_PDSLEEPCFG0_RBB_PD_SHIFT         (11U)
/*! RBB_PD - Writes to this bit in PDRUNCFG, but not PDSLEEPCFG, can be disabled by an OTP bit.
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_RBB_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_RBB_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_RBB_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_FBB_PD_MASK          (0x1000U)
#define SYSCTL0_PDSLEEPCFG0_FBB_PD_SHIFT         (12U)
/*! FBB_PD - Writes to this bit in PDRUNCFG, but not PDSLEEPCFG, can be disabled by an OTP bit.
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_FBB_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_FBB_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_FBB_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_MASK      (0x2000U)
#define SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_SHIFT     (13U)
/*! SYSXTAL_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SYSXTAL_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_LPOSC_PD_MASK        (0x4000U)
#define SYSCTL0_PDSLEEPCFG0_LPOSC_PD_SHIFT       (14U)
/*! LPOSC_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_LPOSC_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_LPOSC_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_LPOSC_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SFRO_PD_MASK         (0x8000U)
#define SYSCTL0_PDSLEEPCFG0_SFRO_PD_SHIFT        (15U)
/*! SFRO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_SFRO_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SFRO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SFRO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_FFRO_PD_MASK         (0x10000U)
#define SYSCTL0_PDSLEEPCFG0_FFRO_PD_SHIFT        (16U)
/*! FFRO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_FFRO_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_FFRO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_FFRO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_MASK    (0x20000U)
#define SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_SHIFT   (17U)
/*! SYSPLLLDO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_MASK    (0x40000U)
#define SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_SHIFT   (18U)
/*! SYSPLLANA_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_MASK    (0x80000U)
#define SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_SHIFT   (19U)
/*! AUDPLLLDO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_MASK    (0x100000U)
#define SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_SHIFT   (20U)
/*! AUDPLLANA_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_ADC_PD_MASK          (0x200000U)
#define SYSCTL0_PDSLEEPCFG0_ADC_PD_SHIFT         (21U)
/*! ADC_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_ADC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ADC_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ADC_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_ADC_LP_MASK          (0x400000U)
#define SYSCTL0_PDSLEEPCFG0_ADC_LP_SHIFT         (22U)
/*! ADC_LP
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_ADC_LP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ADC_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ADC_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_ADCTEMPSNS_PD_MASK   (0x800000U)
#define SYSCTL0_PDSLEEPCFG0_ADCTEMPSNS_PD_SHIFT  (23U)
/*! ADCTEMPSNS_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_ADCTEMPSNS_PD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ADCTEMPSNS_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ADCTEMPSNS_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_ACMP_PD_MASK         (0x2000000U)
#define SYSCTL0_PDSLEEPCFG0_ACMP_PD_SHIFT        (25U)
/*! ACMP_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG0_ACMP_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_ACMP_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_ACMP_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD0_VDET_LP_MASK  (0x4000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD0_VDET_LP_SHIFT (26U)
/*! HSPAD0_VDET_LP
 *  0b0..High Speed Pad VDET in Normal Mode
 *  0b1..High Speed Pad VDET in Sleep Mode
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD0_VDET_LP(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD0_VDET_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD0_VDET_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD0_REF_PD_MASK   (0x8000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD0_REF_PD_SHIFT  (27U)
/*! HSPAD0_REF_PD
 *  0b0..High Speed Pad VREF Enabled
 *  0b1..High Speed Pad VREF in Power Down
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD0_REF_PD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD0_REF_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD0_REF_PD_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD2_VDET_LP_MASK  (0x10000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD2_VDET_LP_SHIFT (28U)
/*! HSPAD2_VDET_LP
 *  0b0..High Speed Pad VDET in Normal Mode
 *  0b1..High Speed Pad VDET in Sleep Mode
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD2_VDET_LP(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD2_VDET_LP_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD2_VDET_LP_MASK)

#define SYSCTL0_PDSLEEPCFG0_HSPAD2_REF_PD_MASK   (0x20000000U)
#define SYSCTL0_PDSLEEPCFG0_HSPAD2_REF_PD_SHIFT  (29U)
/*! HSPAD2_REF_PD
 *  0b0..High Speed Pad VREF Enabled
 *  0b1..High Speed Pad VREF in Power Down
 */
#define SYSCTL0_PDSLEEPCFG0_HSPAD2_REF_PD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG0_HSPAD2_REF_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG0_HSPAD2_REF_PD_MASK)
/*! @} */

/*! @name PDSLEEPCFG1 - Sleep configuration 1 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_APD_MASK     (0x1U)
#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_APD_SHIFT    (0U)
/*! PQ_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_PQ_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_PQ_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_MASK     (0x2U)
#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_SHIFT    (1U)
/*! PQ_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_APD_SHIFT (2U)
/*! FLEXSPI_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_FLEXSPI_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_MASK  (0x10U)
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_SHIFT (4U)
/*! USBHS_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_MASK  (0x20U)
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_SHIFT (5U)
/*! USBHS_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_MASK (0x40U)
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_SHIFT (6U)
/*! USDHC0_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_MASK (0x80U)
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_SHIFT (7U)
/*! USDHC0_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_MASK (0x100U)
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_SHIFT (8U)
/*! USDHC1_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_MASK (0x200U)
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_SHIFT (9U)
/*! USDHC1_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_APD_MASK (0x400U)
#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_APD_SHIFT (10U)
/*! CASPER_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_MASK (0x800U)
#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_SHIFT (11U)
/*! CASPER_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_APD_MASK (0x1000000U)
#define SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_APD_SHIFT (24U)
/*! DSPCACHE_REGF_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_PPD_MASK (0x2000000U)
#define SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_PPD_SHIFT (25U)
/*! DSPCACHE_REGF_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_DSPCACHE_REGF_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_APD_MASK (0x4000000U)
#define SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_APD_SHIFT (26U)
/*! DSPTCM_REGF_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_APD_MASK)

#define SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_PPD_MASK (0x8000000U)
#define SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_PPD_SHIFT (27U)
/*! DSPTCM_REGF_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_DSPTCM_REGF_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG1_ROM_PD_MASK          (0x10000000U)
#define SYSCTL0_PDSLEEPCFG1_ROM_PD_SHIFT         (28U)
/*! ROM_PD - array power and periph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG1_ROM_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_ROM_PD_SHIFT)) & SYSCTL0_PDSLEEPCFG1_ROM_PD_MASK)

#define SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_MASK      (0x80000000U)
#define SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_SHIFT     (31U)
/*! SRAM_SLEEP
 *  0b0..RAM Normal Mode
 *  0b1..RAM Sleep Mode.
 */
#define SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDSLEEPCFG1_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDSLEEPCFG2 - Sleep configuration 2 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_MASK    (0x1U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_SHIFT   (0U)
/*! SRAM_IF0_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_MASK    (0x2U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_SHIFT   (1U)
/*! SRAM_IF1_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_MASK    (0x4U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_SHIFT   (2U)
/*! SRAM_IF2_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_MASK    (0x8U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_SHIFT   (3U)
/*! SRAM_IF3_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_MASK    (0x10U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_SHIFT   (4U)
/*! SRAM_IF4_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_MASK    (0x20U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_SHIFT   (5U)
/*! SRAM_IF5_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_MASK    (0x40U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_SHIFT   (6U)
/*! SRAM_IF6_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_MASK    (0x80U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_SHIFT   (7U)
/*! SRAM_IF7_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_MASK    (0x100U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_SHIFT   (8U)
/*! SRAM_IF8_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_MASK    (0x200U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_SHIFT   (9U)
/*! SRAM_IF9_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_MASK   (0x400U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_SHIFT  (10U)
/*! SRAM_IF10_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_MASK   (0x800U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_SHIFT  (11U)
/*! SRAM_IF11_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_MASK   (0x1000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_SHIFT  (12U)
/*! SRAM_IF12_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_MASK   (0x2000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_SHIFT  (13U)
/*! SRAM_IF13_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_MASK   (0x4000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_SHIFT  (14U)
/*! SRAM_IF14_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_MASK   (0x8000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_SHIFT  (15U)
/*! SRAM_IF15_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_MASK   (0x10000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_SHIFT  (16U)
/*! SRAM_IF16_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_MASK   (0x20000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_SHIFT  (17U)
/*! SRAM_IF17_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_MASK   (0x40000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_SHIFT  (18U)
/*! SRAM_IF18_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_MASK   (0x80000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_SHIFT  (19U)
/*! SRAM_IF19_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_MASK   (0x100000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_SHIFT  (20U)
/*! SRAM_IF20_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_MASK   (0x200000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_SHIFT  (21U)
/*! SRAM_IF21_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_MASK   (0x400000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_SHIFT  (22U)
/*! SRAM_IF22_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_MASK   (0x800000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_SHIFT  (23U)
/*! SRAM_IF23_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_MASK   (0x1000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_SHIFT  (24U)
/*! SRAM_IF24_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_MASK   (0x2000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_SHIFT  (25U)
/*! SRAM_IF25_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_MASK   (0x4000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_SHIFT  (26U)
/*! SRAM_IF26_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_MASK   (0x8000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_SHIFT  (27U)
/*! SRAM_IF27_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_MASK   (0x10000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_SHIFT  (28U)
/*! SRAM_IF28_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_MASK   (0x20000000U)
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_SHIFT  (29U)
/*! SRAM_IF29_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDSLEEPCFG2_SRAM_IF29_APD_MASK)
/*! @} */

/*! @name PDSLEEPCFG3 - Sleep configuration 3 */
/*! @{ */

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_MASK    (0x1U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_SHIFT   (0U)
/*! SRAM_IF0_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_MASK    (0x2U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_SHIFT   (1U)
/*! SRAM_IF1_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_MASK    (0x4U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_SHIFT   (2U)
/*! SRAM_IF2_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_MASK    (0x8U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_SHIFT   (3U)
/*! SRAM_IF3_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_MASK    (0x10U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_SHIFT   (4U)
/*! SRAM_IF4_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_MASK    (0x20U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_SHIFT   (5U)
/*! SRAM_IF5_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_MASK    (0x40U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_SHIFT   (6U)
/*! SRAM_IF6_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_MASK    (0x80U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_SHIFT   (7U)
/*! SRAM_IF7_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_MASK    (0x100U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_SHIFT   (8U)
/*! SRAM_IF8_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_MASK    (0x200U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_SHIFT   (9U)
/*! SRAM_IF9_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_MASK   (0x400U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_SHIFT  (10U)
/*! SRAM_IF10_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_MASK   (0x800U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_SHIFT  (11U)
/*! SRAM_IF11_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_MASK   (0x1000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_SHIFT  (12U)
/*! SRAM_IF12_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_MASK   (0x2000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_SHIFT  (13U)
/*! SRAM_IF13_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_MASK   (0x4000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_SHIFT  (14U)
/*! SRAM_IF14_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_MASK   (0x8000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_SHIFT  (15U)
/*! SRAM_IF15_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_MASK   (0x10000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_SHIFT  (16U)
/*! SRAM_IF16_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_MASK   (0x20000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_SHIFT  (17U)
/*! SRAM_IF17_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_MASK   (0x40000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_SHIFT  (18U)
/*! SRAM_IF18_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_MASK   (0x80000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_SHIFT  (19U)
/*! SRAM_IF19_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_MASK   (0x100000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_SHIFT  (20U)
/*! SRAM_IF20_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_MASK   (0x200000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_SHIFT  (21U)
/*! SRAM_IF21_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_MASK   (0x400000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_SHIFT  (22U)
/*! SRAM_IF22_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_MASK   (0x800000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_SHIFT  (23U)
/*! SRAM_IF23_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_MASK   (0x1000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_SHIFT  (24U)
/*! SRAM_IF24_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_MASK   (0x2000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_SHIFT  (25U)
/*! SRAM_IF25_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_MASK   (0x4000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_SHIFT  (26U)
/*! SRAM_IF26_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_MASK   (0x8000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_SHIFT  (27U)
/*! SRAM_IF27_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_MASK   (0x10000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_SHIFT  (28U)
/*! SRAM_IF28_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_MASK   (0x20000000U)
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_SHIFT  (29U)
/*! SRAM_IF29_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDSLEEPCFG3_SRAM_IF29_PPD_MASK)
/*! @} */

/*! @name PDRUNCFG0 - Run configuration 0 */
/*! @{ */

#define SYSCTL0_PDRUNCFG0_PMIC_MODE0_MASK        (0x2U)
#define SYSCTL0_PDRUNCFG0_PMIC_MODE0_SHIFT       (1U)
/*! PMIC_MODE0
 *  0b0..Set Mode0 to 0.
 *  0b1..Set Mode0 to 1.
 */
#define SYSCTL0_PDRUNCFG0_PMIC_MODE0(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMIC_MODE0_SHIFT)) & SYSCTL0_PDRUNCFG0_PMIC_MODE0_MASK)

#define SYSCTL0_PDRUNCFG0_PMIC_MODE1_MASK        (0x4U)
#define SYSCTL0_PDRUNCFG0_PMIC_MODE1_SHIFT       (2U)
/*! PMIC_MODE1
 *  0b0..Set Mode1 to 0.
 *  0b1..Set Mode1 to 1.
 */
#define SYSCTL0_PDRUNCFG0_PMIC_MODE1(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMIC_MODE1_SHIFT)) & SYSCTL0_PDRUNCFG0_PMIC_MODE1_MASK)

#define SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_MASK     (0x10U)
#define SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_SHIFT    (4U)
/*! VDDCOREREG_LP
 *  0b0..VDDCOREREG HP Mode
 *  0b1..LP Mode
 */
#define SYSCTL0_PDRUNCFG0_VDDCOREREG_LP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDRUNCFG0_PMCREF_LP_MASK         (0x40U)
#define SYSCTL0_PDRUNCFG0_PMCREF_LP_SHIFT        (6U)
/*! PMCREF_LP
 *  0b0..PMCREF HP Mode
 *  0b1..PMCREF LP Mode
 */
#define SYSCTL0_PDRUNCFG0_PMCREF_LP(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PMCREF_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_PMCREF_LP_MASK)

#define SYSCTL0_PDRUNCFG0_HVD1V8_PD_MASK         (0x80U)
#define SYSCTL0_PDRUNCFG0_HVD1V8_PD_SHIFT        (7U)
/*! HVD1V8_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_HVD1V8_PD(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HVD1V8_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HVD1V8_PD_MASK)

#define SYSCTL0_PDRUNCFG0_PORCORE_LP_MASK        (0x100U)
#define SYSCTL0_PDRUNCFG0_PORCORE_LP_SHIFT       (8U)
/*! PORCORE_LP
 *  0b0..LVD0V6 HP Mode
 *  0b1..LVD0V6 LP Mode
 */
#define SYSCTL0_PDRUNCFG0_PORCORE_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_PORCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_PORCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_LVDCORE_LP_MASK        (0x200U)
#define SYSCTL0_PDRUNCFG0_LVDCORE_LP_SHIFT       (9U)
/*! LVDCORE_LP
 *  0b0..LVD0V85 HP Mode
 *  0b1..LVD0V85 LP Mode.
 */
#define SYSCTL0_PDRUNCFG0_LVDCORE_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_LVDCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_LVDCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_HVDCORE_PD_MASK        (0x400U)
#define SYSCTL0_PDRUNCFG0_HVDCORE_PD_SHIFT       (10U)
/*! HVDCORE_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_HVDCORE_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HVDCORE_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HVDCORE_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SYSXTAL_PD_MASK        (0x2000U)
#define SYSCTL0_PDRUNCFG0_SYSXTAL_PD_SHIFT       (13U)
/*! SYSXTAL_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_SYSXTAL_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SYSXTAL_PD_MASK)

#define SYSCTL0_PDRUNCFG0_LPOSC_PD_MASK          (0x4000U)
#define SYSCTL0_PDRUNCFG0_LPOSC_PD_SHIFT         (14U)
/*! LPOSC_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_LPOSC_PD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_LPOSC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_LPOSC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SFRO_PD_MASK           (0x8000U)
#define SYSCTL0_PDRUNCFG0_SFRO_PD_SHIFT          (15U)
/*! SFRO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_SFRO_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_FFRO_PD_MASK           (0x10000U)
#define SYSCTL0_PDRUNCFG0_FFRO_PD_SHIFT          (16U)
/*! FFRO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_FFRO_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_FFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_FFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_MASK      (0x20000U)
#define SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_SHIFT     (17U)
/*! SYSPLLLDO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_MASK      (0x40000U)
#define SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_SHIFT     (18U)
/*! SYSPLLANA_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_SYSPLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_MASK      (0x80000U)
#define SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_SHIFT     (19U)
/*! AUDPLLLDO_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_MASK      (0x100000U)
#define SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_SHIFT     (20U)
/*! AUDPLLANA_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_AUDPLLANA_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_ADC_PD_MASK            (0x200000U)
#define SYSCTL0_PDRUNCFG0_ADC_PD_SHIFT           (21U)
/*! ADC_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_ADC_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ADC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_ADC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_ADC_LP_MASK            (0x400000U)
#define SYSCTL0_PDRUNCFG0_ADC_LP_SHIFT           (22U)
/*! ADC_LP
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_ADC_LP(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ADC_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_ADC_LP_MASK)

#define SYSCTL0_PDRUNCFG0_ADCTEMPSNS_PD_MASK     (0x800000U)
#define SYSCTL0_PDRUNCFG0_ADCTEMPSNS_PD_SHIFT    (23U)
/*! ADCTEMPSNS_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_ADCTEMPSNS_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ADCTEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_ADCTEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_ACMP_PD_MASK           (0x2000000U)
#define SYSCTL0_PDRUNCFG0_ACMP_PD_SHIFT          (25U)
/*! ACMP_PD
 *  0b0..enabled
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG0_ACMP_PD(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_ACMP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_ACMP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD0_VDET_LP_MASK    (0x4000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD0_VDET_LP_SHIFT   (26U)
/*! HSPAD0_VDET_LP - High Speed Pad vdde0 voltage detect block
 *  0b0..High Speed Pad VDET in Normal Mode
 *  0b1..High Speed Pad VDET in Sleep Mode
 */
#define SYSCTL0_PDRUNCFG0_HSPAD0_VDET_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD0_VDET_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD0_VDET_LP_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD0_REF_PD_MASK     (0x8000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD0_REF_PD_SHIFT    (27U)
/*! HSPAD0_REF_PD - High speed Pad vdde0 reference blocks
 *  0b0..High Speed Pad VREF Enabled
 *  0b1..High Speed Pad VREF in Power Down
 */
#define SYSCTL0_PDRUNCFG0_HSPAD0_REF_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD2_VDET_LP_MASK    (0x10000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD2_VDET_LP_SHIFT   (28U)
/*! HSPAD2_VDET_LP - High Speed Pad vdde2 voltage detect block
 *  0b0..High Speed Pad VDET in Normal Mode
 *  0b1..High Speed Pad VDET in Sleep Mode
 */
#define SYSCTL0_PDRUNCFG0_HSPAD2_VDET_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD2_VDET_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD2_VDET_LP_MASK)

#define SYSCTL0_PDRUNCFG0_HSPAD2_REF_PD_MASK     (0x20000000U)
#define SYSCTL0_PDRUNCFG0_HSPAD2_REF_PD_SHIFT    (29U)
/*! HSPAD2_REF_PD - High speed Pad vdde2 reference blocks
 *  0b0..High Speed Pad VREF Enabled
 *  0b1..High Speed Pad VREF in Power Down
 */
#define SYSCTL0_PDRUNCFG0_HSPAD2_REF_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_HSPAD2_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_HSPAD2_REF_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1 - Run configuration 1 */
/*! @{ */

#define SYSCTL0_PDRUNCFG1_PQ_SRAM_APD_MASK       (0x1U)
#define SYSCTL0_PDRUNCFG1_PQ_SRAM_APD_SHIFT      (0U)
/*! PQ_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_PQ_SRAM_APD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_PQ_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_PQ_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_MASK       (0x2U)
#define SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_SHIFT      (1U)
/*! PQ_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_APD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_APD_SHIFT (2U)
/*! FLEXSPI_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_PPD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_FLEXSPI_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_MASK    (0x10U)
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_SHIFT   (4U)
/*! USBHS_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_MASK    (0x20U)
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_SHIFT   (5U)
/*! USBHS_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_MASK   (0x40U)
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_SHIFT  (6U)
/*! USDHC0_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_MASK   (0x80U)
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_SHIFT  (7U)
/*! USDHC0_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_MASK   (0x100U)
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_SHIFT  (8U)
/*! USDHC1_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_MASK   (0x200U)
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_SHIFT  (9U)
/*! USDHC1_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_APD_MASK   (0x400U)
#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_APD_SHIFT  (10U)
/*! CASPER_SRAM_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CASPER_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CASPER_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_MASK   (0x800U)
#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_SHIFT  (11U)
/*! CASPER_SRAM_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_APD_SHIFT (24U)
/*! DSPCACHE_REGF_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_APD_MASK)

#define SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_PPD_SHIFT (25U)
/*! DSPCACHE_REGF_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_DSPCACHE_REGF_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_DSPTCM_REGF_APD_MASK   (0x4000000U)
#define SYSCTL0_PDRUNCFG1_DSPTCM_REGF_APD_SHIFT  (26U)
/*! DSPTCM_REGF_APD - Array power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_DSPTCM_REGF_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_DSPTCM_REGF_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_DSPTCM_REGF_APD_MASK)

#define SYSCTL0_PDRUNCFG1_DSPTCM_REGF_PPD_MASK   (0x8000000U)
#define SYSCTL0_PDRUNCFG1_DSPTCM_REGF_PPD_SHIFT  (27U)
/*! DSPTCM_REGF_PPD - Peiph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_DSPTCM_REGF_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_DSPTCM_REGF_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_DSPTCM_REGF_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_ROM_PD_MASK            (0x10000000U)
#define SYSCTL0_PDRUNCFG1_ROM_PD_SHIFT           (28U)
/*! ROM_PD - array power and periph power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG1_ROM_PD(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_ROM_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_ROM_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SRAM_SLEEP_MASK        (0x80000000U)
#define SYSCTL0_PDRUNCFG1_SRAM_SLEEP_SHIFT       (31U)
/*! SRAM_SLEEP
 *  0b0..RAM Normal Mode
 *  0b1..RAM Sleep Mode.
 */
#define SYSCTL0_PDRUNCFG1_SRAM_SLEEP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDRUNCFG1_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG2 - Run configuration 2 */
/*! @{ */

#define SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_MASK      (0x1U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_SHIFT     (0U)
/*! SRAM_IF0_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF0_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_MASK      (0x2U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_SHIFT     (1U)
/*! SRAM_IF1_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF1_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_MASK      (0x4U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_SHIFT     (2U)
/*! SRAM_IF2_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF2_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_MASK      (0x8U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_SHIFT     (3U)
/*! SRAM_IF3_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF3_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_MASK      (0x10U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_SHIFT     (4U)
/*! SRAM_IF4_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF4_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_MASK      (0x20U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_SHIFT     (5U)
/*! SRAM_IF5_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF5_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_MASK      (0x40U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_SHIFT     (6U)
/*! SRAM_IF6_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF6_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_MASK      (0x80U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_SHIFT     (7U)
/*! SRAM_IF7_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF7_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_MASK      (0x100U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_SHIFT     (8U)
/*! SRAM_IF8_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF8_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_MASK      (0x200U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_SHIFT     (9U)
/*! SRAM_IF9_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF9_APD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_MASK     (0x400U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_SHIFT    (10U)
/*! SRAM_IF10_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF10_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_MASK     (0x800U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_SHIFT    (11U)
/*! SRAM_IF11_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF11_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_MASK     (0x1000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_SHIFT    (12U)
/*! SRAM_IF12_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF12_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_MASK     (0x2000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_SHIFT    (13U)
/*! SRAM_IF13_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF13_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_MASK     (0x4000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_SHIFT    (14U)
/*! SRAM_IF14_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF14_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_MASK     (0x8000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_SHIFT    (15U)
/*! SRAM_IF15_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF15_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_MASK     (0x10000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_SHIFT    (16U)
/*! SRAM_IF16_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF16_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_MASK     (0x20000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_SHIFT    (17U)
/*! SRAM_IF17_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF17_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_MASK     (0x40000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_SHIFT    (18U)
/*! SRAM_IF18_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF18_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_MASK     (0x80000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_SHIFT    (19U)
/*! SRAM_IF19_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF19_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_MASK     (0x100000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_SHIFT    (20U)
/*! SRAM_IF20_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF20_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_MASK     (0x200000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_SHIFT    (21U)
/*! SRAM_IF21_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF21_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_MASK     (0x400000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_SHIFT    (22U)
/*! SRAM_IF22_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF22_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_MASK     (0x800000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_SHIFT    (23U)
/*! SRAM_IF23_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF23_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_MASK     (0x1000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_SHIFT    (24U)
/*! SRAM_IF24_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF24_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_MASK     (0x2000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_SHIFT    (25U)
/*! SRAM_IF25_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF25_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_MASK     (0x4000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_SHIFT    (26U)
/*! SRAM_IF26_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF26_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_MASK     (0x8000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_SHIFT    (27U)
/*! SRAM_IF27_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF27_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_MASK     (0x10000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_SHIFT    (28U)
/*! SRAM_IF28_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF28_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_MASK     (0x20000000U)
#define SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_SHIFT    (29U)
/*! SRAM_IF29_APD - Array Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG2_SRAM_IF29_APD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SRAM_IF29_APD_MASK)
/*! @} */

/*! @name PDRUNCFG3 - Run configuration 3 */
/*! @{ */

#define SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_MASK      (0x1U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_SHIFT     (0U)
/*! SRAM_IF0_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_MASK      (0x2U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_SHIFT     (1U)
/*! SRAM_IF1_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_MASK      (0x4U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_SHIFT     (2U)
/*! SRAM_IF2_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_MASK      (0x8U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_SHIFT     (3U)
/*! SRAM_IF3_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_MASK      (0x10U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_SHIFT     (4U)
/*! SRAM_IF4_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_MASK      (0x20U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_SHIFT     (5U)
/*! SRAM_IF5_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_MASK      (0x40U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_SHIFT     (6U)
/*! SRAM_IF6_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_MASK      (0x80U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_SHIFT     (7U)
/*! SRAM_IF7_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_MASK      (0x100U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_SHIFT     (8U)
/*! SRAM_IF8_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_MASK      (0x200U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_SHIFT     (9U)
/*! SRAM_IF9_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_MASK     (0x400U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_SHIFT    (10U)
/*! SRAM_IF10_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_MASK     (0x800U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_SHIFT    (11U)
/*! SRAM_IF11_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_MASK     (0x1000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_SHIFT    (12U)
/*! SRAM_IF12_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_MASK     (0x2000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_SHIFT    (13U)
/*! SRAM_IF13_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_MASK     (0x4000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_SHIFT    (14U)
/*! SRAM_IF14_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_MASK     (0x8000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_SHIFT    (15U)
/*! SRAM_IF15_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_MASK     (0x10000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_SHIFT    (16U)
/*! SRAM_IF16_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_MASK     (0x20000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_SHIFT    (17U)
/*! SRAM_IF17_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_MASK     (0x40000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_SHIFT    (18U)
/*! SRAM_IF18_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_MASK     (0x80000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_SHIFT    (19U)
/*! SRAM_IF19_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_MASK     (0x100000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_SHIFT    (20U)
/*! SRAM_IF20_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_MASK     (0x200000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_SHIFT    (21U)
/*! SRAM_IF21_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_MASK     (0x400000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_SHIFT    (22U)
/*! SRAM_IF22_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_MASK     (0x800000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_SHIFT    (23U)
/*! SRAM_IF23_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_MASK     (0x1000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_SHIFT    (24U)
/*! SRAM_IF24_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_MASK     (0x2000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_SHIFT    (25U)
/*! SRAM_IF25_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_MASK     (0x4000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_SHIFT    (26U)
/*! SRAM_IF26_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_MASK     (0x8000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_SHIFT    (27U)
/*! SRAM_IF27_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_MASK     (0x10000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_SHIFT    (28U)
/*! SRAM_IF28_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_MASK     (0x20000000U)
#define SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_SHIFT    (29U)
/*! SRAM_IF29_PPD - Periph Power
 *  0b0..enable
 *  0b1..power down
 */
#define SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SRAM_IF29_PPD_MASK)
/*! @} */

/*! @name PDRUNCFG0_SET - Run configuration 0 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_MASK    (0x2U)
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_SHIFT   (1U)
/*! PMIC_MODE0
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMIC_MODE0_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_MASK    (0x4U)
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_SHIFT   (2U)
/*! PMIC_MODE1
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMIC_MODE1_MASK)

#define SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_MASK (0x10U)
#define SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_SHIFT (4U)
/*! VDDCOREREG_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_MASK     (0x40U)
#define SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_SHIFT    (6U)
/*! PMCREF_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PMCREF_LP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PMCREF_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_MASK     (0x80U)
#define SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_SHIFT    (7U)
/*! HVD1V8_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HVD1V8_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_MASK    (0x100U)
#define SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_SHIFT   (8U)
/*! PORCORE_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_PORCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_PORCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_MASK    (0x200U)
#define SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_SHIFT   (9U)
/*! LVDCORE_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_LVDCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_MASK    (0x400U)
#define SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_SHIFT   (10U)
/*! HVDCORE_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HVDCORE_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_RBB_PD_MASK        (0x800U)
#define SYSCTL0_PDRUNCFG0_SET_RBB_PD_SHIFT       (11U)
/*! RBB_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_RBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_RBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_RBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_FBB_PD_MASK        (0x1000U)
#define SYSCTL0_PDRUNCFG0_SET_FBB_PD_SHIFT       (12U)
/*! FBB_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_FBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_FBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_FBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_MASK    (0x2000U)
#define SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_SHIFT   (13U)
/*! SYSXTAL_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SYSXTAL_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_MASK      (0x4000U)
#define SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_SHIFT     (14U)
/*! LPOSC_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_LPOSC_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_LPOSC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SFRO_PD_MASK       (0x8000U)
#define SYSCTL0_PDRUNCFG0_SET_SFRO_PD_SHIFT      (15U)
/*! SFRO_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SFRO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_FFRO_PD_MASK       (0x10000U)
#define SYSCTL0_PDRUNCFG0_SET_FFRO_PD_SHIFT      (16U)
/*! FFRO_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_FFRO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_FFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_FFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_MASK  (0x20000U)
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_SHIFT (17U)
/*! SYSPLLLDO_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_MASK  (0x40000U)
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_SHIFT (18U)
/*! SYSPLLANA_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_MASK  (0x80000U)
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_SHIFT (19U)
/*! AUDPLLLDO_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_MASK  (0x100000U)
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_SHIFT (20U)
/*! AUDPLLANA_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ADC_PD_MASK        (0x200000U)
#define SYSCTL0_PDRUNCFG0_SET_ADC_PD_SHIFT       (21U)
/*! ADC_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ADC_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ADC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ADC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ADC_LP_MASK        (0x400000U)
#define SYSCTL0_PDRUNCFG0_SET_ADC_LP_SHIFT       (22U)
/*! ADC_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ADC_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ADC_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ADC_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ADCTEMPSNS_PD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG0_SET_ADCTEMPSNS_PD_SHIFT (23U)
/*! ADCTEMPSNS_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ADCTEMPSNS_PD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ADCTEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ADCTEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_ACMP_PD_MASK       (0x2000000U)
#define SYSCTL0_PDRUNCFG0_SET_ACMP_PD_SHIFT      (25U)
/*! ACMP_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_ACMP_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_ACMP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_ACMP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD0_VDET_LP_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD0_VDET_LP_SHIFT (26U)
/*! HSPAD0_VDET_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD0_VDET_LP(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD0_VDET_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD0_VDET_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD0_REF_PD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD0_REF_PD_SHIFT (27U)
/*! HSPAD0_REF_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD0_REF_PD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD2_VDET_LP_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD2_VDET_LP_SHIFT (28U)
/*! HSPAD2_VDET_LP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD2_VDET_LP(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD2_VDET_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD2_VDET_LP_MASK)

#define SYSCTL0_PDRUNCFG0_SET_HSPAD2_REF_PD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG0_SET_HSPAD2_REF_PD_SHIFT (29U)
/*! HSPAD2_REF_PD
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_SET_HSPAD2_REF_PD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_SET_HSPAD2_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_SET_HSPAD2_REF_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1_SET - Run configuration 1 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_MASK   (0x1U)
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_SHIFT  (0U)
/*! PQ_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_MASK   (0x2U)
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_SHIFT  (1U)
/*! PQ_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_APD_SHIFT (2U)
/*! FLEXSPI_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_FLEXSPI_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_MASK (0x10U)
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_SHIFT (4U)
/*! USBHS_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_MASK (0x20U)
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_SHIFT (5U)
/*! USBHS_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_MASK (0x40U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_SHIFT (6U)
/*! USDHC0_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_MASK (0x80U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_SHIFT (7U)
/*! USDHC0_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_MASK (0x100U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_SHIFT (8U)
/*! USDHC1_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_MASK (0x200U)
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_SHIFT (9U)
/*! USDHC1_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_APD_SHIFT (10U)
/*! CASPER_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_SHIFT (11U)
/*! CASPER_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_APD_SHIFT (24U)
/*! DSPCACHE_REGF_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_PPD_SHIFT (25U)
/*! DSPCACHE_REGF_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_DSPCACHE_REGF_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_APD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_APD_SHIFT (26U)
/*! DSPTCM_REGF_APD - Array power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_APD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_PPD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_PPD_SHIFT (27U)
/*! DSPTCM_REGF_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_DSPTCM_REGF_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_ROM_PD_MASK        (0x10000000U)
#define SYSCTL0_PDRUNCFG1_SET_ROM_PD_SHIFT       (28U)
/*! ROM_PD - array power and periph power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_ROM_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_ROM_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_ROM_PD_MASK)

#define SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_MASK    (0x80000000U)
#define SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_SHIFT   (31U)
/*! SRAM_SLEEP
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDRUNCFG1_SET_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG2_SET - Run configuration 2 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_SHIFT (0U)
/*! SRAM_IF0_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_SHIFT (1U)
/*! SRAM_IF1_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_SHIFT (2U)
/*! SRAM_IF2_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_SHIFT (3U)
/*! SRAM_IF3_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_SHIFT (4U)
/*! SRAM_IF4_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_SHIFT (5U)
/*! SRAM_IF5_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_SHIFT (6U)
/*! SRAM_IF6_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_SHIFT (7U)
/*! SRAM_IF7_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_SHIFT (8U)
/*! SRAM_IF8_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_SHIFT (9U)
/*! SRAM_IF9_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_SHIFT (10U)
/*! SRAM_IF10_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_SHIFT (11U)
/*! SRAM_IF11_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_SHIFT (12U)
/*! SRAM_IF12_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_SHIFT (13U)
/*! SRAM_IF13_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_SHIFT (14U)
/*! SRAM_IF14_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_SHIFT (15U)
/*! SRAM_IF15_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_SHIFT (16U)
/*! SRAM_IF16_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_SHIFT (17U)
/*! SRAM_IF17_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_SHIFT (18U)
/*! SRAM_IF18_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_SHIFT (19U)
/*! SRAM_IF19_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_SHIFT (20U)
/*! SRAM_IF20_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_SHIFT (21U)
/*! SRAM_IF21_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_SHIFT (22U)
/*! SRAM_IF22_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_SHIFT (23U)
/*! SRAM_IF23_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_SHIFT (24U)
/*! SRAM_IF24_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_SHIFT (25U)
/*! SRAM_IF25_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_SHIFT (26U)
/*! SRAM_IF26_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_SHIFT (27U)
/*! SRAM_IF27_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_SHIFT (28U)
/*! SRAM_IF28_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_SHIFT (29U)
/*! SRAM_IF29_APD - Array Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_SET_SRAM_IF29_APD_MASK)
/*! @} */

/*! @name PDRUNCFG3_SET - Run configuration 3 set */
/*! @{ */

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_SHIFT (0U)
/*! SRAM_IF0_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_SHIFT (1U)
/*! SRAM_IF1_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_SHIFT (2U)
/*! SRAM_IF2_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_SHIFT (3U)
/*! SRAM_IF3_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_SHIFT (4U)
/*! SRAM_IF4_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_SHIFT (5U)
/*! SRAM_IF5_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_SHIFT (6U)
/*! SRAM_IF6_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_SHIFT (7U)
/*! SRAM_IF7_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_SHIFT (8U)
/*! SRAM_IF8_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_SHIFT (9U)
/*! SRAM_IF9_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_SHIFT (10U)
/*! SRAM_IF10_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_SHIFT (11U)
/*! SRAM_IF11_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_SHIFT (12U)
/*! SRAM_IF12_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_SHIFT (13U)
/*! SRAM_IF13_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_SHIFT (14U)
/*! SRAM_IF14_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_SHIFT (15U)
/*! SRAM_IF15_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_SHIFT (16U)
/*! SRAM_IF16_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_SHIFT (17U)
/*! SRAM_IF17_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_SHIFT (18U)
/*! SRAM_IF18_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_SHIFT (19U)
/*! SRAM_IF19_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_SHIFT (20U)
/*! SRAM_IF20_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_SHIFT (21U)
/*! SRAM_IF21_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_SHIFT (22U)
/*! SRAM_IF22_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_SHIFT (23U)
/*! SRAM_IF23_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_SHIFT (24U)
/*! SRAM_IF24_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_SHIFT (25U)
/*! SRAM_IF25_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_SHIFT (26U)
/*! SRAM_IF26_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_SHIFT (27U)
/*! SRAM_IF27_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_SHIFT (28U)
/*! SRAM_IF28_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_SHIFT (29U)
/*! SRAM_IF29_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Sets the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_SET_SRAM_IF29_PPD_MASK)
/*! @} */

/*! @name PDRUNCFG0_CLR - Run configuration 0 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_MASK    (0x2U)
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_SHIFT   (1U)
/*! PMIC_MODE0
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE0_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_MASK    (0x4U)
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_SHIFT   (2U)
/*! PMIC_MODE1
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMIC_MODE1_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_MASK (0x10U)
#define SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_SHIFT (4U)
/*! VDDCOREREG_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_VDDCOREREG_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_MASK     (0x40U)
#define SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_SHIFT    (6U)
/*! PMCREF_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PMCREF_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_MASK     (0x80U)
#define SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_SHIFT    (7U)
/*! HVD1V8_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HVD1V8_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_MASK    (0x100U)
#define SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_SHIFT   (8U)
/*! PORCORE_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_PORCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_MASK    (0x200U)
#define SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_SHIFT   (9U)
/*! LVDCORE_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_LVDCORE_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_MASK    (0x400U)
#define SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_SHIFT   (10U)
/*! HVDCORE_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HVDCORE_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_RBB_PD_MASK        (0x800U)
#define SYSCTL0_PDRUNCFG0_CLR_RBB_PD_SHIFT       (11U)
/*! RBB_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_RBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_RBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_RBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_FBB_PD_MASK        (0x1000U)
#define SYSCTL0_PDRUNCFG0_CLR_FBB_PD_SHIFT       (12U)
/*! FBB_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_FBB_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_FBB_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_FBB_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_MASK    (0x2000U)
#define SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_SHIFT   (13U)
/*! SYSXTAL_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SYSXTAL_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_MASK      (0x4000U)
#define SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_SHIFT     (14U)
/*! LPOSC_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_LPOSC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SFRO_PD_MASK       (0x8000U)
#define SYSCTL0_PDRUNCFG0_CLR_SFRO_PD_SHIFT      (15U)
/*! SFRO_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SFRO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_MASK       (0x10000U)
#define SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_SHIFT      (16U)
/*! FFRO_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_FFRO_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_FFRO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_MASK  (0x20000U)
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_SHIFT (17U)
/*! SYSPLLLDO_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SYSPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_MASK  (0x40000U)
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_SHIFT (18U)
/*! SYSPLLANA_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_SYSPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_MASK  (0x80000U)
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_SHIFT (19U)
/*! AUDPLLLDO_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_AUDPLLLDO_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_MASK  (0x100000U)
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_SHIFT (20U)
/*! AUDPLLANA_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_AUDPLLANA_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ADC_PD_MASK        (0x200000U)
#define SYSCTL0_PDRUNCFG0_CLR_ADC_PD_SHIFT       (21U)
/*! ADC_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ADC_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ADC_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ADC_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ADC_LP_MASK        (0x400000U)
#define SYSCTL0_PDRUNCFG0_CLR_ADC_LP_SHIFT       (22U)
/*! ADC_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ADC_LP(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ADC_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ADC_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ADCTEMPSNS_PD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG0_CLR_ADCTEMPSNS_PD_SHIFT (23U)
/*! ADCTEMPSNS_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ADCTEMPSNS_PD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ADCTEMPSNS_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ADCTEMPSNS_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_MASK       (0x2000000U)
#define SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_SHIFT      (25U)
/*! ACMP_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_ACMP_PD(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_ACMP_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD0_VDET_LP_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD0_VDET_LP_SHIFT (26U)
/*! HSPAD0_VDET_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD0_VDET_LP(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD0_VDET_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD0_VDET_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD0_REF_PD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD0_REF_PD_SHIFT (27U)
/*! HSPAD0_REF_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD0_REF_PD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD0_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD0_REF_PD_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD2_VDET_LP_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD2_VDET_LP_SHIFT (28U)
/*! HSPAD2_VDET_LP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD2_VDET_LP(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD2_VDET_LP_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD2_VDET_LP_MASK)

#define SYSCTL0_PDRUNCFG0_CLR_HSPAD2_REF_PD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD2_REF_PD_SHIFT (29U)
/*! HSPAD2_REF_PD
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG0 Bit
 */
#define SYSCTL0_PDRUNCFG0_CLR_HSPAD2_REF_PD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG0_CLR_HSPAD2_REF_PD_SHIFT)) & SYSCTL0_PDRUNCFG0_CLR_HSPAD2_REF_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1_CLR - Run configuration 1 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_MASK   (0x1U)
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_SHIFT  (0U)
/*! PQ_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_MASK   (0x2U)
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_SHIFT  (1U)
/*! PQ_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_PQ_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_APD_MASK (0x4U)
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_APD_SHIFT (2U)
/*! FLEXSPI_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_PPD_MASK (0x8U)
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_PPD_SHIFT (3U)
/*! FLEXSPI_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_FLEXSPI_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_MASK (0x10U)
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_SHIFT (4U)
/*! USBHS_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_MASK (0x20U)
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_SHIFT (5U)
/*! USBHS_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USBHS_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_MASK (0x40U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_SHIFT (6U)
/*! USDHC0_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_MASK (0x80U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_SHIFT (7U)
/*! USDHC0_SRAM_PPD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC0_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_MASK (0x100U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_SHIFT (8U)
/*! USDHC1_SRAM_APD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_MASK (0x200U)
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_SHIFT (9U)
/*! USDHC1_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_USDHC1_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_APD_SHIFT (10U)
/*! CASPER_SRAM_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_SHIFT (11U)
/*! CASPER_SRAM_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_CASPER_SRAM_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_APD_SHIFT (24U)
/*! DSPCACHE_REGF_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_PPD_SHIFT (25U)
/*! DSPCACHE_REGF_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_DSPCACHE_REGF_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_APD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_APD_SHIFT (26U)
/*! DSPTCM_REGF_APD - Array power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_APD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_APD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_APD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_PPD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_PPD_SHIFT (27U)
/*! DSPTCM_REGF_PPD - Peiph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_PPD(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_PPD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_DSPTCM_REGF_PPD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_ROM_PD_MASK        (0x10000000U)
#define SYSCTL0_PDRUNCFG1_CLR_ROM_PD_SHIFT       (28U)
/*! ROM_PD - array power and periph power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_ROM_PD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_ROM_PD_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_ROM_PD_MASK)

#define SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_MASK    (0x80000000U)
#define SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_SHIFT   (31U)
/*! SRAM_SLEEP
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG1 Bit
 */
#define SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_SHIFT)) & SYSCTL0_PDRUNCFG1_CLR_SRAM_SLEEP_MASK)
/*! @} */

/*! @name PDRUNCFG2_CLR - Run configuration 2 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_SHIFT (0U)
/*! SRAM_IF0_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF0_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_SHIFT (1U)
/*! SRAM_IF1_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF1_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_SHIFT (2U)
/*! SRAM_IF2_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF2_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_SHIFT (3U)
/*! SRAM_IF3_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF3_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_SHIFT (4U)
/*! SRAM_IF4_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF4_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_SHIFT (5U)
/*! SRAM_IF5_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF5_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_SHIFT (6U)
/*! SRAM_IF6_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF6_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_SHIFT (7U)
/*! SRAM_IF7_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF7_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_SHIFT (8U)
/*! SRAM_IF8_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF8_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_SHIFT (9U)
/*! SRAM_IF9_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF9_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_SHIFT (10U)
/*! SRAM_IF10_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF10_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_SHIFT (11U)
/*! SRAM_IF11_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF11_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_SHIFT (12U)
/*! SRAM_IF12_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF12_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_SHIFT (13U)
/*! SRAM_IF13_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF13_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_SHIFT (14U)
/*! SRAM_IF14_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF14_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_SHIFT (15U)
/*! SRAM_IF15_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF15_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_SHIFT (16U)
/*! SRAM_IF16_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF16_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_SHIFT (17U)
/*! SRAM_IF17_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF17_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_SHIFT (18U)
/*! SRAM_IF18_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF18_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_SHIFT (19U)
/*! SRAM_IF19_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF19_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_SHIFT (20U)
/*! SRAM_IF20_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF20_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_SHIFT (21U)
/*! SRAM_IF21_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF21_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_SHIFT (22U)
/*! SRAM_IF22_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF22_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_SHIFT (23U)
/*! SRAM_IF23_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF23_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_SHIFT (24U)
/*! SRAM_IF24_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF24_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_SHIFT (25U)
/*! SRAM_IF25_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF25_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_SHIFT (26U)
/*! SRAM_IF26_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF26_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_SHIFT (27U)
/*! SRAM_IF27_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF27_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_SHIFT (28U)
/*! SRAM_IF28_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF28_APD_MASK)

#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_SHIFT (29U)
/*! SRAM_IF29_APD - Array Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG2 Bit
 */
#define SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_SHIFT)) & SYSCTL0_PDRUNCFG2_CLR_SRAM_IF29_APD_MASK)
/*! @} */

/*! @name PDRUNCFG3_CLR - Run configuration 3 clear */
/*! @{ */

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_MASK  (0x1U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_SHIFT (0U)
/*! SRAM_IF0_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF0_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_MASK  (0x2U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_SHIFT (1U)
/*! SRAM_IF1_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF1_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_MASK  (0x4U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_SHIFT (2U)
/*! SRAM_IF2_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF2_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_MASK  (0x8U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_SHIFT (3U)
/*! SRAM_IF3_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF3_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_MASK  (0x10U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_SHIFT (4U)
/*! SRAM_IF4_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF4_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_MASK  (0x20U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_SHIFT (5U)
/*! SRAM_IF5_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF5_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_MASK  (0x40U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_SHIFT (6U)
/*! SRAM_IF6_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF6_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_MASK  (0x80U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_SHIFT (7U)
/*! SRAM_IF7_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF7_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_MASK  (0x100U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_SHIFT (8U)
/*! SRAM_IF8_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF8_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_MASK  (0x200U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_SHIFT (9U)
/*! SRAM_IF9_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF9_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_MASK (0x400U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_SHIFT (10U)
/*! SRAM_IF10_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF10_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_MASK (0x800U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_SHIFT (11U)
/*! SRAM_IF11_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF11_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_MASK (0x1000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_SHIFT (12U)
/*! SRAM_IF12_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF12_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_MASK (0x2000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_SHIFT (13U)
/*! SRAM_IF13_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF13_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_MASK (0x4000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_SHIFT (14U)
/*! SRAM_IF14_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF14_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_MASK (0x8000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_SHIFT (15U)
/*! SRAM_IF15_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF15_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_MASK (0x10000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_SHIFT (16U)
/*! SRAM_IF16_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF16_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_MASK (0x20000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_SHIFT (17U)
/*! SRAM_IF17_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF17_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_MASK (0x40000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_SHIFT (18U)
/*! SRAM_IF18_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF18_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_MASK (0x80000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_SHIFT (19U)
/*! SRAM_IF19_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF19_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_MASK (0x100000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_SHIFT (20U)
/*! SRAM_IF20_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF20_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_MASK (0x200000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_SHIFT (21U)
/*! SRAM_IF21_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF21_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_MASK (0x400000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_SHIFT (22U)
/*! SRAM_IF22_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF22_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_MASK (0x800000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_SHIFT (23U)
/*! SRAM_IF23_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF23_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_MASK (0x1000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_SHIFT (24U)
/*! SRAM_IF24_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF24_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_MASK (0x2000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_SHIFT (25U)
/*! SRAM_IF25_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF25_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_MASK (0x4000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_SHIFT (26U)
/*! SRAM_IF26_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF26_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_MASK (0x8000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_SHIFT (27U)
/*! SRAM_IF27_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF27_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_MASK (0x10000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_SHIFT (28U)
/*! SRAM_IF28_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF28_PPD_MASK)

#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_MASK (0x20000000U)
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_SHIFT (29U)
/*! SRAM_IF29_PPD - Periph Power
 *  0b0..No effect
 *  0b1..Clears the PDRUNCFG3 Bit
 */
#define SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_SHIFT)) & SYSCTL0_PDRUNCFG3_CLR_SRAM_IF29_PPD_MASK)
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
/*! @} */

/*! @name STARTEN0 - Start enable 0 */
/*! @{ */

#define SYSCTL0_STARTEN0_WDT0_MASK               (0x1U)
#define SYSCTL0_STARTEN0_WDT0_SHIFT              (0U)
/*! WDT0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_WDT0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_WDT0_SHIFT)) & SYSCTL0_STARTEN0_WDT0_MASK)

#define SYSCTL0_STARTEN0_DMAC0_MASK              (0x2U)
#define SYSCTL0_STARTEN0_DMAC0_SHIFT             (1U)
/*! DMAC0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_DMAC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_DMAC0_SHIFT)) & SYSCTL0_STARTEN0_DMAC0_MASK)

#define SYSCTL0_STARTEN0_NSHSGPIO_INT0_MASK      (0x4U)
#define SYSCTL0_STARTEN0_NSHSGPIO_INT0_SHIFT     (2U)
/*! NSHSGPIO_INT0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_NSHSGPIO_INT0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_NSHSGPIO_INT0_SHIFT)) & SYSCTL0_STARTEN0_NSHSGPIO_INT0_MASK)

#define SYSCTL0_STARTEN0_NSHSGPIO_INT1_MASK      (0x8U)
#define SYSCTL0_STARTEN0_NSHSGPIO_INT1_SHIFT     (3U)
/*! NSHSGPIO_INT1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_NSHSGPIO_INT1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_NSHSGPIO_INT1_SHIFT)) & SYSCTL0_STARTEN0_NSHSGPIO_INT1_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_MASK     (0x10U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_SHIFT    (4U)
/*! GPIO_INT0_IRQ0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ0_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_MASK     (0x20U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_SHIFT    (5U)
/*! GPIO_INT0_IRQ1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ1(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ1_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_MASK     (0x40U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_SHIFT    (6U)
/*! GPIO_INT0_IRQ2
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ2(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ2_MASK)

#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_MASK     (0x80U)
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_SHIFT    (7U)
/*! GPIO_INT0_IRQ3
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_GPIO_INT0_IRQ3(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_SHIFT)) & SYSCTL0_STARTEN0_GPIO_INT0_IRQ3_MASK)

#define SYSCTL0_STARTEN0_UTICK0_MASK             (0x100U)
#define SYSCTL0_STARTEN0_UTICK0_SHIFT            (8U)
/*! UTICK0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_UTICK0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_UTICK0_SHIFT)) & SYSCTL0_STARTEN0_UTICK0_MASK)

#define SYSCTL0_STARTEN0_MRT0_MASK               (0x200U)
#define SYSCTL0_STARTEN0_MRT0_SHIFT              (9U)
/*! MRT0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_MRT0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_MRT0_SHIFT)) & SYSCTL0_STARTEN0_MRT0_MASK)

#define SYSCTL0_STARTEN0_CT32BIT0_MASK           (0x400U)
#define SYSCTL0_STARTEN0_CT32BIT0_SHIFT          (10U)
/*! CT32BIT0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_CT32BIT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CT32BIT0_SHIFT)) & SYSCTL0_STARTEN0_CT32BIT0_MASK)

#define SYSCTL0_STARTEN0_CT32BIT1_MASK           (0x800U)
#define SYSCTL0_STARTEN0_CT32BIT1_SHIFT          (11U)
/*! CT32BIT1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_CT32BIT1(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CT32BIT1_SHIFT)) & SYSCTL0_STARTEN0_CT32BIT1_MASK)

#define SYSCTL0_STARTEN0_SCT0_MASK               (0x1000U)
#define SYSCTL0_STARTEN0_SCT0_SHIFT              (12U)
/*! SCT0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_SCT0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SCT0_SHIFT)) & SYSCTL0_STARTEN0_SCT0_MASK)

#define SYSCTL0_STARTEN0_CT32BIT3_MASK           (0x2000U)
#define SYSCTL0_STARTEN0_CT32BIT3_SHIFT          (13U)
/*! CT32BIT3
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_CT32BIT3(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CT32BIT3_SHIFT)) & SYSCTL0_STARTEN0_CT32BIT3_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM0_MASK          (0x4000U)
#define SYSCTL0_STARTEN0_FLEXCOMM0_SHIFT         (14U)
/*! FLEXCOMM0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM0_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM0_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM1_MASK          (0x8000U)
#define SYSCTL0_STARTEN0_FLEXCOMM1_SHIFT         (15U)
/*! FLEXCOMM1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM1_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM1_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM2_MASK          (0x10000U)
#define SYSCTL0_STARTEN0_FLEXCOMM2_SHIFT         (16U)
/*! FLEXCOMM2
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM2_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM2_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM3_MASK          (0x20000U)
#define SYSCTL0_STARTEN0_FLEXCOMM3_SHIFT         (17U)
/*! FLEXCOMM3
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM3_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM3_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM4_MASK          (0x40000U)
#define SYSCTL0_STARTEN0_FLEXCOMM4_SHIFT         (18U)
/*! FLEXCOMM4
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM4_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM4_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM5_MASK          (0x80000U)
#define SYSCTL0_STARTEN0_FLEXCOMM5_SHIFT         (19U)
/*! FLEXCOMM5
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM5_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM5_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM14_MASK         (0x100000U)
#define SYSCTL0_STARTEN0_FLEXCOMM14_SHIFT        (20U)
/*! FLEXCOMM14
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM14(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM14_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM14_MASK)

#define SYSCTL0_STARTEN0_FLEXCOMM15_MASK         (0x200000U)
#define SYSCTL0_STARTEN0_FLEXCOMM15_SHIFT        (21U)
/*! FLEXCOMM15
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_FLEXCOMM15(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_FLEXCOMM15_SHIFT)) & SYSCTL0_STARTEN0_FLEXCOMM15_MASK)

#define SYSCTL0_STARTEN0_ADC0_MASK               (0x400000U)
#define SYSCTL0_STARTEN0_ADC0_SHIFT              (22U)
/*! ADC0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_ADC0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_ADC0_SHIFT)) & SYSCTL0_STARTEN0_ADC0_MASK)

#define SYSCTL0_STARTEN0_ACMP_MASK               (0x1000000U)
#define SYSCTL0_STARTEN0_ACMP_SHIFT              (24U)
/*! ACMP
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_ACMP(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_ACMP_SHIFT)) & SYSCTL0_STARTEN0_ACMP_MASK)

#define SYSCTL0_STARTEN0_DMIC0_MASK              (0x2000000U)
#define SYSCTL0_STARTEN0_DMIC0_SHIFT             (25U)
/*! DMIC0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_DMIC0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_DMIC0_SHIFT)) & SYSCTL0_STARTEN0_DMIC0_MASK)

#define SYSCTL0_STARTEN0_HYPERVISOR_MASK         (0x8000000U)
#define SYSCTL0_STARTEN0_HYPERVISOR_SHIFT        (27U)
/*! HYPERVISOR
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_HYPERVISOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_HYPERVISOR_SHIFT)) & SYSCTL0_STARTEN0_HYPERVISOR_MASK)

#define SYSCTL0_STARTEN0_SECUREVIOLATION_MASK    (0x10000000U)
#define SYSCTL0_STARTEN0_SECUREVIOLATION_SHIFT   (28U)
/*! SECUREVIOLATION
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_SECUREVIOLATION(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SECUREVIOLATION_SHIFT)) & SYSCTL0_STARTEN0_SECUREVIOLATION_MASK)

#define SYSCTL0_STARTEN0_HWVAD0_MASK             (0x20000000U)
#define SYSCTL0_STARTEN0_HWVAD0_SHIFT            (29U)
/*! HWVAD0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_HWVAD0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_HWVAD0_SHIFT)) & SYSCTL0_STARTEN0_HWVAD0_MASK)

#define SYSCTL0_STARTEN0_RNG_MASK                (0x80000000U)
#define SYSCTL0_STARTEN0_RNG_SHIFT               (31U)
/*! RNG
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN0_RNG(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_RNG_SHIFT)) & SYSCTL0_STARTEN0_RNG_MASK)
/*! @} */

/*! @name STARTEN1 - Start enable 1 */
/*! @{ */

#define SYSCTL0_STARTEN1_RTC_LITE0_ALARM_OR_WAKEUP_MASK (0x1U)
#define SYSCTL0_STARTEN1_RTC_LITE0_ALARM_OR_WAKEUP_SHIFT (0U)
/*! RTC_LITE0_ALARM_or_WAKEUP
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_RTC_LITE0_ALARM_OR_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_RTC_LITE0_ALARM_OR_WAKEUP_SHIFT)) & SYSCTL0_STARTEN1_RTC_LITE0_ALARM_OR_WAKEUP_MASK)

#define SYSCTL0_STARTEN1_MU_MASK                 (0x4U)
#define SYSCTL0_STARTEN1_MU_SHIFT                (2U)
/*! MU
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_MU(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_MU_SHIFT)) & SYSCTL0_STARTEN1_MU_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_MASK     (0x8U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_SHIFT    (3U)
/*! GPIO_INT0_IRQ4
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ4(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ4_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_MASK     (0x10U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_SHIFT    (4U)
/*! GPIO_INT0_IRQ5
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ5(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ5_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_MASK     (0x20U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_SHIFT    (5U)
/*! GPIO_INT0_IRQ6
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ6(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ6_MASK)

#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_MASK     (0x40U)
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_SHIFT    (6U)
/*! GPIO_INT0_IRQ7
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_GPIO_INT0_IRQ7(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_SHIFT)) & SYSCTL0_STARTEN1_GPIO_INT0_IRQ7_MASK)

#define SYSCTL0_STARTEN1_CT32BIT2_MASK           (0x80U)
#define SYSCTL0_STARTEN1_CT32BIT2_SHIFT          (7U)
/*! CT32BIT2
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_CT32BIT2(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CT32BIT2_SHIFT)) & SYSCTL0_STARTEN1_CT32BIT2_MASK)

#define SYSCTL0_STARTEN1_CT32BIT4_MASK           (0x100U)
#define SYSCTL0_STARTEN1_CT32BIT4_SHIFT          (8U)
/*! CT32BIT4
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_CT32BIT4(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CT32BIT4_SHIFT)) & SYSCTL0_STARTEN1_CT32BIT4_MASK)

#define SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_MASK  (0x200U)
#define SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_SHIFT (9U)
/*! OS_EVENT_TIMER_WU
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_SHIFT)) & SYSCTL0_STARTEN1_OS_EVENT_TIMER_WU_MASK)

#define SYSCTL0_STARTEN1_FLEXSPI_MASK            (0x400U)
#define SYSCTL0_STARTEN1_FLEXSPI_SHIFT           (10U)
/*! FLEXSPI
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_FLEXSPI(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXSPI_SHIFT)) & SYSCTL0_STARTEN1_FLEXSPI_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM6_MASK          (0x800U)
#define SYSCTL0_STARTEN1_FLEXCOMM6_SHIFT         (11U)
/*! FLEXCOMM6
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_FLEXCOMM6(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM6_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM6_MASK)

#define SYSCTL0_STARTEN1_FLEXCOMM7_MASK          (0x1000U)
#define SYSCTL0_STARTEN1_FLEXCOMM7_SHIFT         (12U)
/*! FLEXCOMM7
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_FLEXCOMM7(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_FLEXCOMM7_SHIFT)) & SYSCTL0_STARTEN1_FLEXCOMM7_MASK)

#define SYSCTL0_STARTEN1_SDIO0_MASK              (0x2000U)
#define SYSCTL0_STARTEN1_SDIO0_SHIFT             (13U)
/*! SDIO0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_SDIO0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SDIO0_SHIFT)) & SYSCTL0_STARTEN1_SDIO0_MASK)

#define SYSCTL0_STARTEN1_SDIO1_MASK              (0x4000U)
#define SYSCTL0_STARTEN1_SDIO1_SHIFT             (14U)
/*! SDIO1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_SDIO1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SDIO1_SHIFT)) & SYSCTL0_STARTEN1_SDIO1_MASK)

#define SYSCTL0_STARTEN1_SHSGPIO_INT0_MASK       (0x8000U)
#define SYSCTL0_STARTEN1_SHSGPIO_INT0_SHIFT      (15U)
/*! SHSGPIO_INT0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_SHSGPIO_INT0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SHSGPIO_INT0_SHIFT)) & SYSCTL0_STARTEN1_SHSGPIO_INT0_MASK)

#define SYSCTL0_STARTEN1_SHSGPIO_INT1_MASK       (0x10000U)
#define SYSCTL0_STARTEN1_SHSGPIO_INT1_SHIFT      (16U)
/*! SHSGPIO_INT1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_SHSGPIO_INT1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SHSGPIO_INT1_SHIFT)) & SYSCTL0_STARTEN1_SHSGPIO_INT1_MASK)

#define SYSCTL0_STARTEN1_I3C0_MASK               (0x20000U)
#define SYSCTL0_STARTEN1_I3C0_SHIFT              (17U)
/*! I3C0
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_I3C0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_I3C0_SHIFT)) & SYSCTL0_STARTEN1_I3C0_MASK)

#define SYSCTL0_STARTEN1_USB_IRQ_MASK            (0x40000U)
#define SYSCTL0_STARTEN1_USB_IRQ_SHIFT           (18U)
/*! USB_IRQ
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_USB_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_USB_IRQ_SHIFT)) & SYSCTL0_STARTEN1_USB_IRQ_MASK)

#define SYSCTL0_STARTEN1_USB_NEEDCLK_MASK        (0x80000U)
#define SYSCTL0_STARTEN1_USB_NEEDCLK_SHIFT       (19U)
/*! USB_NEEDCLK
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_USB_NEEDCLK(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_USB_NEEDCLK_SHIFT)) & SYSCTL0_STARTEN1_USB_NEEDCLK_MASK)

#define SYSCTL0_STARTEN1_DMAC1_MASK              (0x400000U)
#define SYSCTL0_STARTEN1_DMAC1_SHIFT             (22U)
/*! DMAC1
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_DMAC1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_DMAC1_SHIFT)) & SYSCTL0_STARTEN1_DMAC1_MASK)

#define SYSCTL0_STARTEN1_PUF_MASK                (0x800000U)
#define SYSCTL0_STARTEN1_PUF_SHIFT               (23U)
/*! PUF
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_PUF(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_PUF_SHIFT)) & SYSCTL0_STARTEN1_PUF_MASK)

#define SYSCTL0_STARTEN1_POWERQUAD_MASK          (0x1000000U)
#define SYSCTL0_STARTEN1_POWERQUAD_SHIFT         (24U)
/*! POWERQUAD
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_POWERQUAD(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_POWERQUAD_SHIFT)) & SYSCTL0_STARTEN1_POWERQUAD_MASK)

#define SYSCTL0_STARTEN1_CASPER_MASK             (0x2000000U)
#define SYSCTL0_STARTEN1_CASPER_SHIFT            (25U)
/*! CASPER
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_CASPER(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CASPER_SHIFT)) & SYSCTL0_STARTEN1_CASPER_MASK)

#define SYSCTL0_STARTEN1_PMIC_MASK               (0x4000000U)
#define SYSCTL0_STARTEN1_PMIC_SHIFT              (26U)
/*! PMIC
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_PMIC(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_PMIC_SHIFT)) & SYSCTL0_STARTEN1_PMIC_MASK)

#define SYSCTL0_STARTEN1_SHA_MASK                (0x8000000U)
#define SYSCTL0_STARTEN1_SHA_SHIFT               (27U)
/*! SHA
 *  0b0..disbale
 *  0b1..enable
 */
#define SYSCTL0_STARTEN1_SHA(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SHA_SHIFT)) & SYSCTL0_STARTEN1_SHA_MASK)
/*! @} */

/*! @name STARTEN0_SET - Start enable 0 set */
/*! @{ */

#define SYSCTL0_STARTEN0_SET_WDT0_MASK           (0x1U)
#define SYSCTL0_STARTEN0_SET_WDT0_SHIFT          (0U)
/*! WDT0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_WDT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_WDT0_SHIFT)) & SYSCTL0_STARTEN0_SET_WDT0_MASK)

#define SYSCTL0_STARTEN0_SET_DMAC0_MASK          (0x2U)
#define SYSCTL0_STARTEN0_SET_DMAC0_SHIFT         (1U)
/*! DMAC0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_DMAC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_DMAC0_SHIFT)) & SYSCTL0_STARTEN0_SET_DMAC0_MASK)

#define SYSCTL0_STARTEN0_SET_NSHSGPIO_INT0_MASK  (0x4U)
#define SYSCTL0_STARTEN0_SET_NSHSGPIO_INT0_SHIFT (2U)
/*! NSHSGPIO_INT0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_NSHSGPIO_INT0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_NSHSGPIO_INT0_SHIFT)) & SYSCTL0_STARTEN0_SET_NSHSGPIO_INT0_MASK)

#define SYSCTL0_STARTEN0_SET_NSHSGPIO_INT1_MASK  (0x8U)
#define SYSCTL0_STARTEN0_SET_NSHSGPIO_INT1_SHIFT (3U)
/*! NSHSGPIO_INT1
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_NSHSGPIO_INT1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_NSHSGPIO_INT1_SHIFT)) & SYSCTL0_STARTEN0_SET_NSHSGPIO_INT1_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_MASK (0x10U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_SHIFT (4U)
/*! GPIO_INT0_IRQ0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ0_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_MASK (0x20U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_SHIFT (5U)
/*! GPIO_INT0_IRQ1
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ1_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_MASK (0x40U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_SHIFT (6U)
/*! GPIO_INT0_IRQ2
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ2_MASK)

#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_MASK (0x80U)
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_SHIFT (7U)
/*! GPIO_INT0_IRQ3
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_SHIFT)) & SYSCTL0_STARTEN0_SET_GPIO_INT0_IRQ3_MASK)

#define SYSCTL0_STARTEN0_SET_UTICK0_MASK         (0x100U)
#define SYSCTL0_STARTEN0_SET_UTICK0_SHIFT        (8U)
/*! UTICK0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_UTICK0_SHIFT)) & SYSCTL0_STARTEN0_SET_UTICK0_MASK)

#define SYSCTL0_STARTEN0_SET_MRT0_MASK           (0x200U)
#define SYSCTL0_STARTEN0_SET_MRT0_SHIFT          (9U)
/*! MRT0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_MRT0_SHIFT)) & SYSCTL0_STARTEN0_SET_MRT0_MASK)

#define SYSCTL0_STARTEN0_SET_CT32BIT0_MASK       (0x400U)
#define SYSCTL0_STARTEN0_SET_CT32BIT0_SHIFT      (10U)
/*! CT32BIT0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_CT32BIT0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_CT32BIT0_SHIFT)) & SYSCTL0_STARTEN0_SET_CT32BIT0_MASK)

#define SYSCTL0_STARTEN0_SET_CT32BIT1_MASK       (0x800U)
#define SYSCTL0_STARTEN0_SET_CT32BIT1_SHIFT      (11U)
/*! CT32BIT1
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_CT32BIT1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_CT32BIT1_SHIFT)) & SYSCTL0_STARTEN0_SET_CT32BIT1_MASK)

#define SYSCTL0_STARTEN0_SET_SCT0_MASK           (0x1000U)
#define SYSCTL0_STARTEN0_SET_SCT0_SHIFT          (12U)
/*! SCT0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_SCT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_SCT0_SHIFT)) & SYSCTL0_STARTEN0_SET_SCT0_MASK)

#define SYSCTL0_STARTEN0_SET_CT32BIT3_MASK       (0x2000U)
#define SYSCTL0_STARTEN0_SET_CT32BIT3_SHIFT      (13U)
/*! CT32BIT3
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_CT32BIT3(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_CT32BIT3_SHIFT)) & SYSCTL0_STARTEN0_SET_CT32BIT3_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM0_MASK      (0x4000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM0_SHIFT     (14U)
/*! FLEXCOMM0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM0_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM0_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM1_MASK      (0x8000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM1_SHIFT     (15U)
/*! FLEXCOMM1
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM1_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM1_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM2_MASK      (0x10000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM2_SHIFT     (16U)
/*! FLEXCOMM2
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM2(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM2_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM2_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM3_MASK      (0x20000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM3_SHIFT     (17U)
/*! FLEXCOMM3
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM3(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM3_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM3_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM4_MASK      (0x40000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM4_SHIFT     (18U)
/*! FLEXCOMM4
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM4(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM4_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM4_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM5_MASK      (0x80000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM5_SHIFT     (19U)
/*! FLEXCOMM5
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM5(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM5_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM5_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM14_MASK     (0x100000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM14_SHIFT    (20U)
/*! FLEXCOMM14
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM14(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM14_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM14_MASK)

#define SYSCTL0_STARTEN0_SET_FLEXCOMM15_MASK     (0x200000U)
#define SYSCTL0_STARTEN0_SET_FLEXCOMM15_SHIFT    (21U)
/*! FLEXCOMM15
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_FLEXCOMM15(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_FLEXCOMM15_SHIFT)) & SYSCTL0_STARTEN0_SET_FLEXCOMM15_MASK)

#define SYSCTL0_STARTEN0_SET_ADC0_MASK           (0x400000U)
#define SYSCTL0_STARTEN0_SET_ADC0_SHIFT          (22U)
/*! ADC0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_ADC0_SHIFT)) & SYSCTL0_STARTEN0_SET_ADC0_MASK)

#define SYSCTL0_STARTEN0_SET_ACMP_MASK           (0x1000000U)
#define SYSCTL0_STARTEN0_SET_ACMP_SHIFT          (24U)
/*! ACMP
 *  0b0..No Effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_ACMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_ACMP_SHIFT)) & SYSCTL0_STARTEN0_SET_ACMP_MASK)

#define SYSCTL0_STARTEN0_SET_DMIC0_MASK          (0x2000000U)
#define SYSCTL0_STARTEN0_SET_DMIC0_SHIFT         (25U)
/*! DMIC0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_DMIC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_DMIC0_SHIFT)) & SYSCTL0_STARTEN0_SET_DMIC0_MASK)

#define SYSCTL0_STARTEN0_SET_HYPERVISOR_MASK     (0x8000000U)
#define SYSCTL0_STARTEN0_SET_HYPERVISOR_SHIFT    (27U)
/*! HYPERVISOR
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_HYPERVISOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_HYPERVISOR_SHIFT)) & SYSCTL0_STARTEN0_SET_HYPERVISOR_MASK)

#define SYSCTL0_STARTEN0_SET_SECUREVIOLATION_MASK (0x10000000U)
#define SYSCTL0_STARTEN0_SET_SECUREVIOLATION_SHIFT (28U)
/*! SECUREVIOLATION
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_SECUREVIOLATION(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_SECUREVIOLATION_SHIFT)) & SYSCTL0_STARTEN0_SET_SECUREVIOLATION_MASK)

#define SYSCTL0_STARTEN0_SET_HWVAD0_MASK         (0x20000000U)
#define SYSCTL0_STARTEN0_SET_HWVAD0_SHIFT        (29U)
/*! HWVAD0
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_HWVAD0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_HWVAD0_SHIFT)) & SYSCTL0_STARTEN0_SET_HWVAD0_MASK)

#define SYSCTL0_STARTEN0_SET_RNG_MASK            (0x80000000U)
#define SYSCTL0_STARTEN0_SET_RNG_SHIFT           (31U)
/*! RNG
 *  0b0..No effect
 *  0b1..Sets the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_SET_RNG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_SET_RNG_SHIFT)) & SYSCTL0_STARTEN0_SET_RNG_MASK)
/*! @} */

/*! @name STARTEN1_SET - Start enable 1 set */
/*! @{ */

#define SYSCTL0_STARTEN1_SET_RTC_LITE0_ALARM_OR_WAKEUP_MASK (0x1U)
#define SYSCTL0_STARTEN1_SET_RTC_LITE0_ALARM_OR_WAKEUP_SHIFT (0U)
/*! RTC_LITE0_ALARM_or_WAKEUP
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_RTC_LITE0_ALARM_OR_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_RTC_LITE0_ALARM_OR_WAKEUP_SHIFT)) & SYSCTL0_STARTEN1_SET_RTC_LITE0_ALARM_OR_WAKEUP_MASK)

#define SYSCTL0_STARTEN1_SET_MU_MASK             (0x4U)
#define SYSCTL0_STARTEN1_SET_MU_SHIFT            (2U)
/*! MU
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_MU(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_MU_SHIFT)) & SYSCTL0_STARTEN1_SET_MU_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_MASK (0x8U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_SHIFT (3U)
/*! GPIO_INT0_IRQ4
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ4_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_MASK (0x10U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_SHIFT (4U)
/*! GPIO_INT0_IRQ5
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ5_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_MASK (0x20U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_SHIFT (5U)
/*! GPIO_INT0_IRQ6
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ6_MASK)

#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_MASK (0x40U)
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_SHIFT (6U)
/*! GPIO_INT0_IRQ7
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_SHIFT)) & SYSCTL0_STARTEN1_SET_GPIO_INT0_IRQ7_MASK)

#define SYSCTL0_STARTEN1_SET_CT32BIT2_MASK       (0x80U)
#define SYSCTL0_STARTEN1_SET_CT32BIT2_SHIFT      (7U)
/*! CT32BIT2
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_CT32BIT2(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_CT32BIT2_SHIFT)) & SYSCTL0_STARTEN1_SET_CT32BIT2_MASK)

#define SYSCTL0_STARTEN1_SET_CT32BIT4_MASK       (0x100U)
#define SYSCTL0_STARTEN1_SET_CT32BIT4_SHIFT      (8U)
/*! CT32BIT4
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_CT32BIT4(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_CT32BIT4_SHIFT)) & SYSCTL0_STARTEN1_SET_CT32BIT4_MASK)

#define SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_MASK (0x200U)
#define SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_SHIFT (9U)
/*! OS_EVENT_TIMER_WU
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_SHIFT)) & SYSCTL0_STARTEN1_SET_OS_EVENT_TIMER_WU_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXSPI_MASK        (0x400U)
#define SYSCTL0_STARTEN1_SET_FLEXSPI_SHIFT       (10U)
/*! FLEXSPI
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXSPI(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXSPI_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXSPI_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM6_MASK      (0x800U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM6_SHIFT     (11U)
/*! FLEXCOMM6
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM6(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM6_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM6_MASK)

#define SYSCTL0_STARTEN1_SET_FLEXCOMM7_MASK      (0x1000U)
#define SYSCTL0_STARTEN1_SET_FLEXCOMM7_SHIFT     (12U)
/*! FLEXCOMM7
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_FLEXCOMM7(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_FLEXCOMM7_SHIFT)) & SYSCTL0_STARTEN1_SET_FLEXCOMM7_MASK)

#define SYSCTL0_STARTEN1_SET_SDIO0_MASK          (0x2000U)
#define SYSCTL0_STARTEN1_SET_SDIO0_SHIFT         (13U)
/*! SDIO0
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SDIO0_SHIFT)) & SYSCTL0_STARTEN1_SET_SDIO0_MASK)

#define SYSCTL0_STARTEN1_SET_SDIO1_MASK          (0x4000U)
#define SYSCTL0_STARTEN1_SET_SDIO1_SHIFT         (14U)
/*! SDIO1
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SDIO1_SHIFT)) & SYSCTL0_STARTEN1_SET_SDIO1_MASK)

#define SYSCTL0_STARTEN1_SET_SHSGPIO_INT0_MASK   (0x8000U)
#define SYSCTL0_STARTEN1_SET_SHSGPIO_INT0_SHIFT  (15U)
/*! SHSGPIO_INT0
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SHSGPIO_INT0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SHSGPIO_INT0_SHIFT)) & SYSCTL0_STARTEN1_SET_SHSGPIO_INT0_MASK)

#define SYSCTL0_STARTEN1_SET_SHSGPIO_INT1_MASK   (0x10000U)
#define SYSCTL0_STARTEN1_SET_SHSGPIO_INT1_SHIFT  (16U)
/*! SHSGPIO_INT1
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SHSGPIO_INT1(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SHSGPIO_INT1_SHIFT)) & SYSCTL0_STARTEN1_SET_SHSGPIO_INT1_MASK)

#define SYSCTL0_STARTEN1_SET_I3C0_MASK           (0x20000U)
#define SYSCTL0_STARTEN1_SET_I3C0_SHIFT          (17U)
/*! I3C0
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_I3C0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_I3C0_SHIFT)) & SYSCTL0_STARTEN1_SET_I3C0_MASK)

#define SYSCTL0_STARTEN1_SET_USB_IRQ_MASK        (0x40000U)
#define SYSCTL0_STARTEN1_SET_USB_IRQ_SHIFT       (18U)
/*! USB_IRQ
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_USB_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_USB_IRQ_SHIFT)) & SYSCTL0_STARTEN1_SET_USB_IRQ_MASK)

#define SYSCTL0_STARTEN1_SET_USB_NEEDCLK_MASK    (0x80000U)
#define SYSCTL0_STARTEN1_SET_USB_NEEDCLK_SHIFT   (19U)
/*! USB_NEEDCLK
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_USB_NEEDCLK(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_USB_NEEDCLK_SHIFT)) & SYSCTL0_STARTEN1_SET_USB_NEEDCLK_MASK)

#define SYSCTL0_STARTEN1_SET_DMAC1_MASK          (0x400000U)
#define SYSCTL0_STARTEN1_SET_DMAC1_SHIFT         (22U)
/*! DMAC1
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_DMAC1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_DMAC1_SHIFT)) & SYSCTL0_STARTEN1_SET_DMAC1_MASK)

#define SYSCTL0_STARTEN1_SET_PUF_MASK            (0x800000U)
#define SYSCTL0_STARTEN1_SET_PUF_SHIFT           (23U)
/*! PUF
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_PUF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_PUF_SHIFT)) & SYSCTL0_STARTEN1_SET_PUF_MASK)

#define SYSCTL0_STARTEN1_SET_POWERQUAD_MASK      (0x1000000U)
#define SYSCTL0_STARTEN1_SET_POWERQUAD_SHIFT     (24U)
/*! POWERQUAD
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_POWERQUAD_SHIFT)) & SYSCTL0_STARTEN1_SET_POWERQUAD_MASK)

#define SYSCTL0_STARTEN1_SET_CASPER_MASK         (0x2000000U)
#define SYSCTL0_STARTEN1_SET_CASPER_SHIFT        (25U)
/*! CASPER
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_CASPER_SHIFT)) & SYSCTL0_STARTEN1_SET_CASPER_MASK)

#define SYSCTL0_STARTEN1_SET_PMIC_MASK           (0x4000000U)
#define SYSCTL0_STARTEN1_SET_PMIC_SHIFT          (26U)
/*! PMIC
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_PMIC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_PMIC_SHIFT)) & SYSCTL0_STARTEN1_SET_PMIC_MASK)

#define SYSCTL0_STARTEN1_SET_SHA_MASK            (0x8000000U)
#define SYSCTL0_STARTEN1_SET_SHA_SHIFT           (27U)
/*! SHA
 *  0b0..No effect
 *  0b1..Sets the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_SET_SHA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_SET_SHA_SHIFT)) & SYSCTL0_STARTEN1_SET_SHA_MASK)
/*! @} */

/*! @name STARTEN0_CLR - Start enable 0 clear */
/*! @{ */

#define SYSCTL0_STARTEN0_CLR_WDT0_MASK           (0x1U)
#define SYSCTL0_STARTEN0_CLR_WDT0_SHIFT          (0U)
/*! WDT0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_WDT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_WDT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_WDT0_MASK)

#define SYSCTL0_STARTEN0_CLR_DMAC0_MASK          (0x2U)
#define SYSCTL0_STARTEN0_CLR_DMAC0_SHIFT         (1U)
/*! DMAC0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_DMAC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_DMAC0_SHIFT)) & SYSCTL0_STARTEN0_CLR_DMAC0_MASK)

#define SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT0_MASK  (0x4U)
#define SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT0_SHIFT (2U)
/*! NSHSGPIO_INT0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT0(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT0_MASK)

#define SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT1_MASK  (0x8U)
#define SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT1_SHIFT (3U)
/*! NSHSGPIO_INT1
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT1(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT1_SHIFT)) & SYSCTL0_STARTEN0_CLR_NSHSGPIO_INT1_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_MASK (0x10U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_SHIFT (4U)
/*! GPIO_INT0_IRQ0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ0_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_MASK (0x20U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_SHIFT (5U)
/*! GPIO_INT0_IRQ1
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ1_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_MASK (0x40U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_SHIFT (6U)
/*! GPIO_INT0_IRQ2
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ2_MASK)

#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_MASK (0x80U)
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_SHIFT (7U)
/*! GPIO_INT0_IRQ3
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_SHIFT)) & SYSCTL0_STARTEN0_CLR_GPIO_INT0_IRQ3_MASK)

#define SYSCTL0_STARTEN0_CLR_UTICK0_MASK         (0x100U)
#define SYSCTL0_STARTEN0_CLR_UTICK0_SHIFT        (8U)
/*! UTICK0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_UTICK0_SHIFT)) & SYSCTL0_STARTEN0_CLR_UTICK0_MASK)

#define SYSCTL0_STARTEN0_CLR_MRT0_MASK           (0x200U)
#define SYSCTL0_STARTEN0_CLR_MRT0_SHIFT          (9U)
/*! MRT0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_MRT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_MRT0_MASK)

#define SYSCTL0_STARTEN0_CLR_CT32BIT0_MASK       (0x400U)
#define SYSCTL0_STARTEN0_CLR_CT32BIT0_SHIFT      (10U)
/*! CT32BIT0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_CT32BIT0(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_CT32BIT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_CT32BIT0_MASK)

#define SYSCTL0_STARTEN0_CLR_CT32BIT1_MASK       (0x800U)
#define SYSCTL0_STARTEN0_CLR_CT32BIT1_SHIFT      (11U)
/*! CT32BIT1
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_CT32BIT1(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_CT32BIT1_SHIFT)) & SYSCTL0_STARTEN0_CLR_CT32BIT1_MASK)

#define SYSCTL0_STARTEN0_CLR_SCT0_MASK           (0x1000U)
#define SYSCTL0_STARTEN0_CLR_SCT0_SHIFT          (12U)
/*! SCT0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_SCT0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_SCT0_SHIFT)) & SYSCTL0_STARTEN0_CLR_SCT0_MASK)

#define SYSCTL0_STARTEN0_CLR_CT32BIT3_MASK       (0x2000U)
#define SYSCTL0_STARTEN0_CLR_CT32BIT3_SHIFT      (13U)
/*! CT32BIT3
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_CT32BIT3(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_CT32BIT3_SHIFT)) & SYSCTL0_STARTEN0_CLR_CT32BIT3_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM0_MASK      (0x4000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM0_SHIFT     (14U)
/*! FLEXCOMM0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM0(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM0_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM0_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM1_MASK      (0x8000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM1_SHIFT     (15U)
/*! FLEXCOMM1
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM1(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM1_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM1_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM2_MASK      (0x10000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM2_SHIFT     (16U)
/*! FLEXCOMM2
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM2(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM2_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM2_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM3_MASK      (0x20000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM3_SHIFT     (17U)
/*! FLEXCOMM3
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM3(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM3_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM3_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM4_MASK      (0x40000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM4_SHIFT     (18U)
/*! FLEXCOMM4
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM4(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM4_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM4_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM5_MASK      (0x80000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM5_SHIFT     (19U)
/*! FLEXCOMM5
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM5(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM5_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM5_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM14_MASK     (0x100000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM14_SHIFT    (20U)
/*! FLEXCOMM14
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM14(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM14_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM14_MASK)

#define SYSCTL0_STARTEN0_CLR_FLEXCOMM15_MASK     (0x200000U)
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM15_SHIFT    (21U)
/*! FLEXCOMM15
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_FLEXCOMM15(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_FLEXCOMM15_SHIFT)) & SYSCTL0_STARTEN0_CLR_FLEXCOMM15_MASK)

#define SYSCTL0_STARTEN0_CLR_ADC0_MASK           (0x400000U)
#define SYSCTL0_STARTEN0_CLR_ADC0_SHIFT          (22U)
/*! ADC0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_ADC0_SHIFT)) & SYSCTL0_STARTEN0_CLR_ADC0_MASK)

#define SYSCTL0_STARTEN0_CLR_ACMP_MASK           (0x1000000U)
#define SYSCTL0_STARTEN0_CLR_ACMP_SHIFT          (24U)
/*! ACMP
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_ACMP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_ACMP_SHIFT)) & SYSCTL0_STARTEN0_CLR_ACMP_MASK)

#define SYSCTL0_STARTEN0_CLR_DMIC0_MASK          (0x2000000U)
#define SYSCTL0_STARTEN0_CLR_DMIC0_SHIFT         (25U)
/*! DMIC0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_DMIC0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_DMIC0_SHIFT)) & SYSCTL0_STARTEN0_CLR_DMIC0_MASK)

#define SYSCTL0_STARTEN0_CLR_HYPERVISOR_MASK     (0x8000000U)
#define SYSCTL0_STARTEN0_CLR_HYPERVISOR_SHIFT    (27U)
/*! HYPERVISOR
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_HYPERVISOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_HYPERVISOR_SHIFT)) & SYSCTL0_STARTEN0_CLR_HYPERVISOR_MASK)

#define SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_MASK (0x10000000U)
#define SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_SHIFT (28U)
/*! SECUREVIOLATION
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_SECUREVIOLATION(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_SHIFT)) & SYSCTL0_STARTEN0_CLR_SECUREVIOLATION_MASK)

#define SYSCTL0_STARTEN0_CLR_HWVAD0_MASK         (0x20000000U)
#define SYSCTL0_STARTEN0_CLR_HWVAD0_SHIFT        (29U)
/*! HWVAD0
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_HWVAD0(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_HWVAD0_SHIFT)) & SYSCTL0_STARTEN0_CLR_HWVAD0_MASK)

#define SYSCTL0_STARTEN0_CLR_RNG_MASK            (0x80000000U)
#define SYSCTL0_STARTEN0_CLR_RNG_SHIFT           (31U)
/*! RNG
 *  0b0..No effect
 *  0b1..Clears the START_EN0 Bit
 */
#define SYSCTL0_STARTEN0_CLR_RNG(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN0_CLR_RNG_SHIFT)) & SYSCTL0_STARTEN0_CLR_RNG_MASK)
/*! @} */

/*! @name STARTEN1_CLR - Start enable 1 clear */
/*! @{ */

#define SYSCTL0_STARTEN1_CLR_RTC_LITE0_ALARM_OR_WAKEUP_MASK (0x1U)
#define SYSCTL0_STARTEN1_CLR_RTC_LITE0_ALARM_OR_WAKEUP_SHIFT (0U)
/*! RTC_LITE0_ALARM_or_WAKEUP
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_RTC_LITE0_ALARM_OR_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_RTC_LITE0_ALARM_OR_WAKEUP_SHIFT)) & SYSCTL0_STARTEN1_CLR_RTC_LITE0_ALARM_OR_WAKEUP_MASK)

#define SYSCTL0_STARTEN1_CLR_MU_MASK             (0x4U)
#define SYSCTL0_STARTEN1_CLR_MU_SHIFT            (2U)
/*! MU
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_MU(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_MU_SHIFT)) & SYSCTL0_STARTEN1_CLR_MU_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_MASK (0x8U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_SHIFT (3U)
/*! GPIO_INT0_IRQ4
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ4_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_MASK (0x10U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_SHIFT (4U)
/*! GPIO_INT0_IRQ5
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ5_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_MASK (0x20U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_SHIFT (5U)
/*! GPIO_INT0_IRQ6
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ6_MASK)

#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_MASK (0x40U)
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_SHIFT (6U)
/*! GPIO_INT0_IRQ7
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_SHIFT)) & SYSCTL0_STARTEN1_CLR_GPIO_INT0_IRQ7_MASK)

#define SYSCTL0_STARTEN1_CLR_CT32BIT2_MASK       (0x80U)
#define SYSCTL0_STARTEN1_CLR_CT32BIT2_SHIFT      (7U)
/*! CT32BIT2
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_CT32BIT2(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_CT32BIT2_SHIFT)) & SYSCTL0_STARTEN1_CLR_CT32BIT2_MASK)

#define SYSCTL0_STARTEN1_CLR_CT32BIT4_MASK       (0x100U)
#define SYSCTL0_STARTEN1_CLR_CT32BIT4_SHIFT      (8U)
/*! CT32BIT4
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_CT32BIT4(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_CT32BIT4_SHIFT)) & SYSCTL0_STARTEN1_CLR_CT32BIT4_MASK)

#define SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_MASK (0x200U)
#define SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_SHIFT (9U)
/*! OS_EVENT_TIMER_WU
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_SHIFT)) & SYSCTL0_STARTEN1_CLR_OS_EVENT_TIMER_WU_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXSPI_MASK        (0x400U)
#define SYSCTL0_STARTEN1_CLR_FLEXSPI_SHIFT       (10U)
/*! FLEXSPI
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXSPI(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXSPI_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXSPI_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM6_MASK      (0x800U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM6_SHIFT     (11U)
/*! FLEXCOMM6
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM6(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM6_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM6_MASK)

#define SYSCTL0_STARTEN1_CLR_FLEXCOMM7_MASK      (0x1000U)
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM7_SHIFT     (12U)
/*! FLEXCOMM7
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_FLEXCOMM7(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_FLEXCOMM7_SHIFT)) & SYSCTL0_STARTEN1_CLR_FLEXCOMM7_MASK)

#define SYSCTL0_STARTEN1_CLR_SDIO0_MASK          (0x2000U)
#define SYSCTL0_STARTEN1_CLR_SDIO0_SHIFT         (13U)
/*! SDIO0
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SDIO0_SHIFT)) & SYSCTL0_STARTEN1_CLR_SDIO0_MASK)

#define SYSCTL0_STARTEN1_CLR_SDIO1_MASK          (0x4000U)
#define SYSCTL0_STARTEN1_CLR_SDIO1_SHIFT         (14U)
/*! SDIO1
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SDIO1_SHIFT)) & SYSCTL0_STARTEN1_CLR_SDIO1_MASK)

#define SYSCTL0_STARTEN1_CLR_SHSGPIO_INT0_MASK   (0x8000U)
#define SYSCTL0_STARTEN1_CLR_SHSGPIO_INT0_SHIFT  (15U)
/*! SHSGPIO_INT0
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SHSGPIO_INT0(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SHSGPIO_INT0_SHIFT)) & SYSCTL0_STARTEN1_CLR_SHSGPIO_INT0_MASK)

#define SYSCTL0_STARTEN1_CLR_SHSGPIO_INT1_MASK   (0x10000U)
#define SYSCTL0_STARTEN1_CLR_SHSGPIO_INT1_SHIFT  (16U)
/*! SHSGPIO_INT1
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SHSGPIO_INT1(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SHSGPIO_INT1_SHIFT)) & SYSCTL0_STARTEN1_CLR_SHSGPIO_INT1_MASK)

#define SYSCTL0_STARTEN1_CLR_I3C0_MASK           (0x20000U)
#define SYSCTL0_STARTEN1_CLR_I3C0_SHIFT          (17U)
/*! I3C0
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_I3C0(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_I3C0_SHIFT)) & SYSCTL0_STARTEN1_CLR_I3C0_MASK)

#define SYSCTL0_STARTEN1_CLR_USB_IRQ_MASK        (0x40000U)
#define SYSCTL0_STARTEN1_CLR_USB_IRQ_SHIFT       (18U)
/*! USB_IRQ
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_USB_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_USB_IRQ_SHIFT)) & SYSCTL0_STARTEN1_CLR_USB_IRQ_MASK)

#define SYSCTL0_STARTEN1_CLR_USB_NEEDCLK_MASK    (0x80000U)
#define SYSCTL0_STARTEN1_CLR_USB_NEEDCLK_SHIFT   (19U)
/*! USB_NEEDCLK
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_USB_NEEDCLK(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_USB_NEEDCLK_SHIFT)) & SYSCTL0_STARTEN1_CLR_USB_NEEDCLK_MASK)

#define SYSCTL0_STARTEN1_CLR_DMAC1_MASK          (0x400000U)
#define SYSCTL0_STARTEN1_CLR_DMAC1_SHIFT         (22U)
/*! DMAC1
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_DMAC1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_DMAC1_SHIFT)) & SYSCTL0_STARTEN1_CLR_DMAC1_MASK)

#define SYSCTL0_STARTEN1_CLR_PUF_MASK            (0x800000U)
#define SYSCTL0_STARTEN1_CLR_PUF_SHIFT           (23U)
/*! PUF
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_PUF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_PUF_SHIFT)) & SYSCTL0_STARTEN1_CLR_PUF_MASK)

#define SYSCTL0_STARTEN1_CLR_POWERQUAD_MASK      (0x1000000U)
#define SYSCTL0_STARTEN1_CLR_POWERQUAD_SHIFT     (24U)
/*! POWERQUAD
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_POWERQUAD_SHIFT)) & SYSCTL0_STARTEN1_CLR_POWERQUAD_MASK)

#define SYSCTL0_STARTEN1_CLR_CASPER_MASK         (0x2000000U)
#define SYSCTL0_STARTEN1_CLR_CASPER_SHIFT        (25U)
/*! CASPER
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_CASPER_SHIFT)) & SYSCTL0_STARTEN1_CLR_CASPER_MASK)

#define SYSCTL0_STARTEN1_CLR_PMIC_MASK           (0x4000000U)
#define SYSCTL0_STARTEN1_CLR_PMIC_SHIFT          (26U)
/*! PMIC
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_PMIC(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_PMIC_SHIFT)) & SYSCTL0_STARTEN1_CLR_PMIC_MASK)

#define SYSCTL0_STARTEN1_CLR_SHA_MASK            (0x8000000U)
#define SYSCTL0_STARTEN1_CLR_SHA_SHIFT           (27U)
/*! SHA
 *  0b0..No effect
 *  0b1..Clears the START_EN1 Bit
 */
#define SYSCTL0_STARTEN1_CLR_SHA(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_STARTEN1_CLR_SHA_SHIFT)) & SYSCTL0_STARTEN1_CLR_SHA_MASK)
/*! @} */

/*! @name MAINCLKSAFETY - Main Clock Safety */
/*! @{ */

#define SYSCTL0_MAINCLKSAFETY_DELAY_MASK         (0xFFFFU)
#define SYSCTL0_MAINCLKSAFETY_DELAY_SHIFT        (0U)
/*! DELAY - Main Clock turn on delay for Deep Sleep wake up */
#define SYSCTL0_MAINCLKSAFETY_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_MAINCLKSAFETY_DELAY_SHIFT)) & SYSCTL0_MAINCLKSAFETY_DELAY_MASK)
/*! @} */

/*! @name HWWAKE - Hardware Wake-up control */
/*! @{ */

#define SYSCTL0_HWWAKE_FORCEWAKE_MASK            (0x1U)
#define SYSCTL0_HWWAKE_FORCEWAKE_SHIFT           (0U)
/*! FORCEWAKE - Force peripheral clocking to stay on during deep-sleep mode. When 1, clocking to
 *    peripherals is prevented from being shut down when the CPU enters deep-sleep mode. This is
 *    intended to allow a coprocessor to continue operating while the main CPU(s) are shut down.
 */
#define SYSCTL0_HWWAKE_FORCEWAKE(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_FORCEWAKE_SHIFT)) & SYSCTL0_HWWAKE_FORCEWAKE_MASK)

#define SYSCTL0_HWWAKE_FCWAKE_MASK               (0x2U)
#define SYSCTL0_HWWAKE_FCWAKE_SHIFT              (1U)
/*! FCWAKE - Wake for Flexcomm Interfaces. When 1, any Flexcomm Interface FIFO reaching the level
 *    specified by its own TXLVL will cause peripheral clocking to wake up temporarily while the
 *    related status is asserted.
 */
#define SYSCTL0_HWWAKE_FCWAKE(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_FCWAKE_SHIFT)) & SYSCTL0_HWWAKE_FCWAKE_MASK)

#define SYSCTL0_HWWAKE_DMICWAKE_MASK             (0x4U)
#define SYSCTL0_HWWAKE_DMICWAKE_SHIFT            (2U)
/*! DMICWAKE - Wake for Digital Microphone. When 1, the digital microphone input FIFO reaching the
 *    level specified by TRIGLVL of either channel will cause peripheral clocking to wake up
 *    temporarily while the related status is asserted.
 */
#define SYSCTL0_HWWAKE_DMICWAKE(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_DMICWAKE_SHIFT)) & SYSCTL0_HWWAKE_DMICWAKE_MASK)

#define SYSCTL0_HWWAKE_DMAC0WAKE_MASK            (0x8U)
#define SYSCTL0_HWWAKE_DMAC0WAKE_SHIFT           (3U)
/*! DMAC0WAKE - Wake for DMAC0. When 1, DMAC0 being busy will cause peripheral clocking to remain
 *    running until DMAC0 completes. This is generally used in conjunction with bit 1 and/or 2 in
 *    order to prevent peripheral clocking from being shut down as soon as the cause of wake-up is
 *    cleared, but before DMAC0 has completed its related activity.
 */
#define SYSCTL0_HWWAKE_DMAC0WAKE(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_DMAC0WAKE_SHIFT)) & SYSCTL0_HWWAKE_DMAC0WAKE_MASK)

#define SYSCTL0_HWWAKE_DMAC1WAKE_MASK            (0x10U)
#define SYSCTL0_HWWAKE_DMAC1WAKE_SHIFT           (4U)
/*! DMAC1WAKE - Wake for DMAC1. When 1, DMAC1 being busy will cause peripheral clocking to remain
 *    running until DMAC1 completes. This is generally used in conjunction with bit 1 and/or 2 in
 *    order to prevent peripheral clocking from being shut down as soon as the cause of wake-up is
 *    cleared, but before DMAC1 has completed its related activity.
 */
#define SYSCTL0_HWWAKE_DMAC1WAKE(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_DMAC1WAKE_SHIFT)) & SYSCTL0_HWWAKE_DMAC1WAKE_MASK)

#define SYSCTL0_HWWAKE_ESPIWAKE_MASK             (0x20U)
#define SYSCTL0_HWWAKE_ESPIWAKE_SHIFT            (5U)
/*! ESPIWAKE - Wake for ESPI. When 1, ESPI being busy will cause peripheral clocking to remain
 *    running until ESPI completes. This is generally used in conjunction with bit 1 and/or 2 in order to
 *    prevent peripheral clocking from being shut down as soon as the cause of wake-up is cleared,
 *    but before ESPI has completed its related activity.
 */
#define SYSCTL0_HWWAKE_ESPIWAKE(x)               (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWWAKE_ESPIWAKE_SHIFT)) & SYSCTL0_HWWAKE_ESPIWAKE_MASK)
/*! @} */

/*! @name TEMPSENSORCTL - tempsensor ctrl */
/*! @{ */

#define SYSCTL0_TEMPSENSORCTL_TSSRC_MASK         (0x1U)
#define SYSCTL0_TEMPSENSORCTL_TSSRC_SHIFT        (0U)
/*! TSSRC - Temperature Sensor Source. . .
 *  0b0..ADC Built-in Temperature Sensor.
 *  0b1..Reserved.
 */
#define SYSCTL0_TEMPSENSORCTL_TSSRC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_TEMPSENSORCTL_TSSRC_SHIFT)) & SYSCTL0_TEMPSENSORCTL_TSSRC_MASK)
/*! @} */

/*! @name BOOTSTATESEED - boot state seed register */
/*! @{ */

#define SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_MASK (0xFFFFFFFFU)
#define SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_SHIFT (0U)
#define SYSCTL0_BOOTSTATESEED_BOOTSTATESEED(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_SHIFT)) & SYSCTL0_BOOTSTATESEED_BOOTSTATESEED_MASK)
/*! @} */

/*! @name BOOTSTATEHMAC - boot state hmac register */
/*! @{ */

#define SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_MASK (0xFFFFFFFFU)
#define SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_SHIFT (0U)
#define SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_SHIFT)) & SYSCTL0_BOOTSTATEHMAC_BOOTSTATEHMAC_MASK)
/*! @} */

/*! @name FLEXSPIPADCTRL - FLEXSPI IO pads ctrl register */
/*! @{ */

#define SYSCTL0_FLEXSPIPADCTRL_RASRCN_MASK       (0xFU)
#define SYSCTL0_FLEXSPIPADCTRL_RASRCN_SHIFT      (0U)
/*! RASRCN - Drive FLEXSPI pad compensation circuit */
#define SYSCTL0_FLEXSPIPADCTRL_RASRCN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_RASRCN_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_RASRCN_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_RASRCP_MASK       (0xF0U)
#define SYSCTL0_FLEXSPIPADCTRL_RASRCP_SHIFT      (4U)
/*! RASRCP - Drive FLEXSPI pad compensation circuit */
#define SYSCTL0_FLEXSPIPADCTRL_RASRCP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_RASRCP_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_RASRCP_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_FASTFRZ_MASK      (0x100U)
#define SYSCTL0_FLEXSPIPADCTRL_FASTFRZ_SHIFT     (8U)
/*! FASTFRZ - Drive FLEXSPI pad compensation circuit */
#define SYSCTL0_FLEXSPIPADCTRL_FASTFRZ(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_FASTFRZ_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_FASTFRZ_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_FREEZE_MASK       (0x200U)
#define SYSCTL0_FLEXSPIPADCTRL_FREEZE_SHIFT      (9U)
/*! FREEZE - Drive FLEXSPI pad compensation circuit */
#define SYSCTL0_FLEXSPIPADCTRL_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_FREEZE_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_FREEZE_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_COMPTQ_MASK       (0x400U)
#define SYSCTL0_FLEXSPIPADCTRL_COMPTQ_SHIFT      (10U)
/*! COMPTQ - Drive FLEXSPI pad compensation circuit */
#define SYSCTL0_FLEXSPIPADCTRL_COMPTQ(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_COMPTQ_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_COMPTQ_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_COMPEN_MASK       (0x800U)
#define SYSCTL0_FLEXSPIPADCTRL_COMPEN_SHIFT      (11U)
/*! COMPEN - Drive FLEXSPI pad compensation circuit */
#define SYSCTL0_FLEXSPIPADCTRL_COMPEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_COMPEN_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_COMPEN_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_NASRCN_MASK       (0xF0000U)
#define SYSCTL0_FLEXSPIPADCTRL_NASRCN_SHIFT      (16U)
/*! NASRCN - FLEXSPI pad compensation circuit status */
#define SYSCTL0_FLEXSPIPADCTRL_NASRCN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_NASRCN_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_NASRCN_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_NASRCP_MASK       (0xF00000U)
#define SYSCTL0_FLEXSPIPADCTRL_NASRCP_SHIFT      (20U)
/*! NASRCP - FLEXSPI pad compensation circuit status */
#define SYSCTL0_FLEXSPIPADCTRL_NASRCP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_NASRCP_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_NASRCP_MASK)

#define SYSCTL0_FLEXSPIPADCTRL_COMPOK_MASK       (0x1000000U)
#define SYSCTL0_FLEXSPIPADCTRL_COMPOK_SHIFT      (24U)
/*! COMPOK - FLEXSPI pad compensation circuit status */
#define SYSCTL0_FLEXSPIPADCTRL_COMPOK(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_FLEXSPIPADCTRL_COMPOK_SHIFT)) & SYSCTL0_FLEXSPIPADCTRL_COMPOK_MASK)
/*! @} */

/*! @name SDIOPADCTL - sdio pad ctrl */
/*! @{ */

#define SYSCTL0_SDIOPADCTL_RASRCN_MASK           (0xFU)
#define SYSCTL0_SDIOPADCTL_RASRCN_SHIFT          (0U)
/*! RASRCN - Drives SDIO Pad Compensation Circuit */
#define SYSCTL0_SDIOPADCTL_RASRCN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_RASRCN_SHIFT)) & SYSCTL0_SDIOPADCTL_RASRCN_MASK)

#define SYSCTL0_SDIOPADCTL_RASRCP_MASK           (0xF0U)
#define SYSCTL0_SDIOPADCTL_RASRCP_SHIFT          (4U)
/*! RASRCP - Drives SDIO Pad Compensation Circuit */
#define SYSCTL0_SDIOPADCTL_RASRCP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_RASRCP_SHIFT)) & SYSCTL0_SDIOPADCTL_RASRCP_MASK)

#define SYSCTL0_SDIOPADCTL_FASTFRZ_MASK          (0x100U)
#define SYSCTL0_SDIOPADCTL_FASTFRZ_SHIFT         (8U)
/*! FASTFRZ - Drives SDIO Pad Compensation Circuit */
#define SYSCTL0_SDIOPADCTL_FASTFRZ(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_FASTFRZ_SHIFT)) & SYSCTL0_SDIOPADCTL_FASTFRZ_MASK)

#define SYSCTL0_SDIOPADCTL_FREEZE_MASK           (0x200U)
#define SYSCTL0_SDIOPADCTL_FREEZE_SHIFT          (9U)
/*! FREEZE - Drives SDIO Pad Compensation Circuit */
#define SYSCTL0_SDIOPADCTL_FREEZE(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_FREEZE_SHIFT)) & SYSCTL0_SDIOPADCTL_FREEZE_MASK)

#define SYSCTL0_SDIOPADCTL_COMPTQ_MASK           (0x400U)
#define SYSCTL0_SDIOPADCTL_COMPTQ_SHIFT          (10U)
/*! COMPTQ - Drives SDIO Pad Compensation Circuit */
#define SYSCTL0_SDIOPADCTL_COMPTQ(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_COMPTQ_SHIFT)) & SYSCTL0_SDIOPADCTL_COMPTQ_MASK)

#define SYSCTL0_SDIOPADCTL_COMPEN_MASK           (0x800U)
#define SYSCTL0_SDIOPADCTL_COMPEN_SHIFT          (11U)
/*! COMPEN - Drives SDIO Pad Compensation Circuit */
#define SYSCTL0_SDIOPADCTL_COMPEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_COMPEN_SHIFT)) & SYSCTL0_SDIOPADCTL_COMPEN_MASK)

#define SYSCTL0_SDIOPADCTL_NASRCN_MASK           (0xF0000U)
#define SYSCTL0_SDIOPADCTL_NASRCN_SHIFT          (16U)
/*! NASRCN - SDIO Pad Compensation Circuit Status */
#define SYSCTL0_SDIOPADCTL_NASRCN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_NASRCN_SHIFT)) & SYSCTL0_SDIOPADCTL_NASRCN_MASK)

#define SYSCTL0_SDIOPADCTL_NASRCP_MASK           (0xF00000U)
#define SYSCTL0_SDIOPADCTL_NASRCP_SHIFT          (20U)
/*! NASRCP - SDIO Pad Compensation Circuit Status */
#define SYSCTL0_SDIOPADCTL_NASRCP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_NASRCP_SHIFT)) & SYSCTL0_SDIOPADCTL_NASRCP_MASK)

#define SYSCTL0_SDIOPADCTL_COMPOK_MASK           (0x1000000U)
#define SYSCTL0_SDIOPADCTL_COMPOK_SHIFT          (24U)
/*! COMPOK - SDIO Pad Compensation Circuit Status */
#define SYSCTL0_SDIOPADCTL_COMPOK(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL0_SDIOPADCTL_COMPOK_SHIFT)) & SYSCTL0_SDIOPADCTL_COMPOK_MASK)
/*! @} */

/*! @name DICEHWREG - DICE General Purpose 32-Bit Data Register */
/*! @{ */

#define SYSCTL0_DICEHWREG_DICEHWREG_MASK         (0xFFFFFFFFU)
#define SYSCTL0_DICEHWREG_DICEHWREG_SHIFT        (0U)
/*! DICEHWREG - DICE General Purpose 32-Bit Data Register */
#define SYSCTL0_DICEHWREG_DICEHWREG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DICEHWREG_DICEHWREG_SHIFT)) & SYSCTL0_DICEHWREG_DICEHWREG_MASK)
/*! @} */

/*! @name UUID - UUIDn 32-Bit Data Register */
/*! @{ */

#define SYSCTL0_UUID_UUID_MASK                   (0xFFFFFFFFU)
#define SYSCTL0_UUID_UUID_SHIFT                  (0U)
#define SYSCTL0_UUID_UUID(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCTL0_UUID_UUID_SHIFT)) & SYSCTL0_UUID_UUID_MASK)
/*! @} */

/*! @name AESKEY_SRCSEL - AES key source selection */
/*! @{ */

#define SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_MASK (0x3U)
#define SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_SHIFT (0U)
/*! AESKEY_SRCSEL - AES Key Source Select: */
#define SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_SHIFT)) & SYSCTL0_AESKEY_SRCSEL_AESKEY_SRCSEL_MASK)
/*! @} */

/*! @name HASHHWKEYDISABLE - Hash hardware key disable */
/*! @{ */

#define SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_MASK (0xFFFFFFFFU)
#define SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_SHIFT (0U)
#define SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_SHIFT)) & SYSCTL0_HASHHWKEYDISABLE_HASHHWKEYDISABLE_MASK)
/*! @} */

/*! @name DBG_LOCKEN - Debug Write Lock registers */
/*! @{ */

#define SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_MASK       (0xFU)
#define SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_SHIFT      (0U)
#define SYSCTL0_DBG_LOCKEN_DBG_LOCKEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_SHIFT)) & SYSCTL0_DBG_LOCKEN_DBG_LOCKEN_MASK)
/*! @} */

/*! @name DBG_FEATURES - Debug features control for the CM33 */
/*! @{ */

#define SYSCTL0_DBG_FEATURES_DBGEN_MASK          (0x3U)
#define SYSCTL0_DBG_FEATURES_DBGEN_SHIFT         (0U)
/*! DBGEN - CM33 Debug Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_DBGEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DBGEN_SHIFT)) & SYSCTL0_DBG_FEATURES_DBGEN_MASK)

#define SYSCTL0_DBG_FEATURES_NIDEN_MASK          (0xCU)
#define SYSCTL0_DBG_FEATURES_NIDEN_SHIFT         (2U)
/*! NIDEN - CM33 NID Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_NIDEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_NIDEN_SHIFT)) & SYSCTL0_DBG_FEATURES_NIDEN_MASK)

#define SYSCTL0_DBG_FEATURES_SPIDEN_MASK         (0x30U)
#define SYSCTL0_DBG_FEATURES_SPIDEN_SHIFT        (4U)
/*! SPIDEN - CM33 SPID Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_SPIDEN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_SPIDEN_SHIFT)) & SYSCTL0_DBG_FEATURES_SPIDEN_MASK)

#define SYSCTL0_DBG_FEATURES_SPNIDEN_MASK        (0xC0U)
#define SYSCTL0_DBG_FEATURES_SPNIDEN_SHIFT       (6U)
/*! SPNIDEN - CM33 SPNIDEN Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_SPNIDEN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_SPNIDEN_SHIFT)) & SYSCTL0_DBG_FEATURES_SPNIDEN_MASK)
/*! @} */

/*! @name DBG_FEATURES_DP - Debug features duplicate */
/*! @{ */

#define SYSCTL0_DBG_FEATURES_DP_DBGEN_MASK       (0x3U)
#define SYSCTL0_DBG_FEATURES_DP_DBGEN_SHIFT      (0U)
/*! DBGEN - CM33 Debug Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_DBGEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_DBGEN_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_DBGEN_MASK)

#define SYSCTL0_DBG_FEATURES_DP_NIDEN_MASK       (0xCU)
#define SYSCTL0_DBG_FEATURES_DP_NIDEN_SHIFT      (2U)
/*! NIDEN - CM33 NID Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_NIDEN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_NIDEN_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_NIDEN_MASK)

#define SYSCTL0_DBG_FEATURES_DP_SPIDEN_MASK      (0x30U)
#define SYSCTL0_DBG_FEATURES_DP_SPIDEN_SHIFT     (4U)
/*! SPIDEN - CM33 SPID Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_SPIDEN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_SPIDEN_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_SPIDEN_MASK)

#define SYSCTL0_DBG_FEATURES_DP_SPNIDEN_MASK     (0xC0U)
#define SYSCTL0_DBG_FEATURES_DP_SPNIDEN_SHIFT    (6U)
/*! SPNIDEN - CM33 SPNIDEN Enable Control
 *  0b00..enabled
 *  0b01..disabled
 *  0b10..disabled
 *  0b11..disabled
 */
#define SYSCTL0_DBG_FEATURES_DP_SPNIDEN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_DBG_FEATURES_DP_SPNIDEN_SHIFT)) & SYSCTL0_DBG_FEATURES_DP_SPNIDEN_MASK)
/*! @} */

/*! @name HWUNLOCK_DISABLE - HW unlock disable */
/*! @{ */

#define SYSCTL0_HWUNLOCK_DISABLE_HWUNLOCK_DISABLE_MASK (0xFU)
#define SYSCTL0_HWUNLOCK_DISABLE_HWUNLOCK_DISABLE_SHIFT (0U)
#define SYSCTL0_HWUNLOCK_DISABLE_HWUNLOCK_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL0_HWUNLOCK_DISABLE_HWUNLOCK_DISABLE_SHIFT)) & SYSCTL0_HWUNLOCK_DISABLE_HWUNLOCK_DISABLE_MASK)
/*! @} */

/*! @name CS_PROTCPU0 - Code Security for CPU0 */
/*! @{ */

#define SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_MASK     (0xFFFFFFFFU)
#define SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_SHIFT    (0U)
/*! CS_PROTCPU0 - Controls M33 AP Enable. Magic Value: 0x1234 5678 */
#define SYSCTL0_CS_PROTCPU0_CS_PROTCPU0(x)       (((uint32_t)(((uint32_t)(x)) << SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_SHIFT)) & SYSCTL0_CS_PROTCPU0_CS_PROTCPU0_MASK)
/*! @} */

/*! @name CS_PROTCPU1 - Code Security for CPU1 */
/*! @{ */

#define SYSCTL0_CS_PROTCPU1_CS_PROTCPU1_MASK     (0xFFFFFFFFU)
#define SYSCTL0_CS_PROTCPU1_CS_PROTCPU1_SHIFT    (0U)
/*! CS_PROTCPU1 - Controls HIFI4 AP Enable. Magic Value: 0x1234 5678 */
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
/*! KEY_BLOCK - key block register */
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

