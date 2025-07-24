/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
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
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(PERI_SYSCON_H_)
#define PERI_SYSCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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

/** SYSCON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t REMAP;                             /**< AHB Matrix Remap Control, offset: 0x200 */
       uint8_t RESERVED_1[12];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix Priority Control, offset: 0x210 */
       uint8_t RESERVED_2[36];
  __IO uint32_t CM33STCKCAL;                       /**< Secure CM33 System Tick Calibration, offset: 0x238 */
  __IO uint32_t CM33NSTCKCAL;                      /**< Non-Secure CM33 System Tick Calibration, offset: 0x23C */
       uint8_t RESERVED_3[8];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x248 */
       uint8_t RESERVED_4[300];
  __IO uint32_t AHBAIPSCLKDIV;                     /**< AHB2AIPS Bridge Clock Divider, offset: 0x378 */
       uint8_t RESERVED_5[4];
  __IO uint32_t AHBCLKDIV;                         /**< System Clock Divider, offset: 0x380 */
       uint8_t RESERVED_6[120];
  __IO uint32_t CLKUNLOCK;                         /**< Clock Configuration Unlock, offset: 0x3FC */
  __IO uint32_t NVM_CTRL;                          /**< NVM Control, offset: 0x400 */
  __IO uint32_t ROMCR;                             /**< ROM Wait State, offset: 0x404 */
  __IO uint32_t ROMCPCLKCTRL;                      /**< ROMCP Clock Control, offset: 0x408 */
       uint8_t RESERVED_7[100];
  __IO uint32_t SRAM_INTERLEAVE;                   /**< Control SRAM Interleave Integration, offset: 0x470 */
       uint8_t RESERVED_8[140];
  __IO uint32_t SRAMCTL;                           /**< SRAM TMTR CTRL register, offset: 0x500 */
       uint8_t RESERVED_9[36];
  __IO uint32_t PULSECAPSYNC_BYPASS;               /**< Pulse Capture Logic Bypass, offset: 0x528 */
       uint8_t RESERVED_10[8];
  __IO uint32_t PULSE_CAP_CMP_CLK_MUXSEL;          /**< Comparator Pulse Capture Clock MUX Select, offset: 0x534 */
  __IO uint32_t FLASH_ADVC_PROTECT;                /**< FMU RF Active Control, offset: 0x538 */
       uint8_t RESERVED_11[8];
  __IO uint32_t AONAUXCLKDIV;                      /**< AON AUX Clock Divider Control, offset: 0x544 */
       uint8_t RESERVED_12[128];
  __IO uint32_t HYPERVISORINTCTRL;                 /**< Hypervisor Interrupt Control, offset: 0x5C8 */
       uint8_t RESERVED_13[576];
  __I  uint32_t CM33STAT;                          /**< CM33 Status, offset: 0x80C */
  __IO uint32_t CM33_SLEEPING_SELECT;              /**< Masking CM33 Sleeping For IPG_DOZE, offset: 0x810 */
       uint8_t RESERVED_14[16];
  __IO uint32_t LPCAC_CTRL;                        /**< LPCAC Control, offset: 0x824 */
       uint8_t RESERVED_15[272];
  __IO uint32_t PWM0SUBCTL;                        /**< PWM0 Sub-module Control, offset: 0x938 */
       uint8_t RESERVED_16[4];
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER Global Start Enable, offset: 0x940 */
  __IO uint32_t RAM_CTRL;                          /**< RAM Control, offset: 0x944 */
       uint8_t RESERVED_17[536];
  __IO uint32_t GRAY_CODE_LSB;                     /**< Gray to Binary Converter Gray Code [31:0], offset: 0xB60 */
  __IO uint32_t GRAY_CODE_MSB;                     /**< Gray to Binary Converter Gray Code [41:32], offset: 0xB64 */
  __I  uint32_t BINARY_CODE_LSB;                   /**< Gray to Binary Converter Binary Code [31:0], offset: 0xB68 */
  __I  uint32_t BINARY_CODE_MSB;                   /**< Gray to Binary Converter Binary Code [41:32], offset: 0xB6C */
       uint8_t RESERVED_18[684];
  __IO uint32_t FLASH_CFG;                         /**< Flash Configuration, offset: 0xE1C */
       uint8_t RESERVED_19[28];
  __IO uint32_t ROP_STATE;                         /**< ROP State, offset: 0xE3C */
       uint8_t RESERVED_20[24];
  __IO uint32_t SRAM_XEN;                          /**< RAM XEN Control, offset: 0xE58 */
  __IO uint32_t SRAM_XEN_DP;                       /**< RAM XEN Control (Duplicate), offset: 0xE5C */
       uint8_t RESERVED_21[84];
  __IO uint32_t CSS_BOOT_STATE_LOCK;               /**< CSS Boot State Lock Down, offset: 0xEB4 */
       uint8_t RESERVED_22[232];
  __IO uint32_t DEBUG_LOCK_EN;                     /**< Control Write Access to Security, offset: 0xFA0 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex Debug Features Control, offset: 0xFA4 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex Debug Features Control (Duplicate), offset: 0xFA8 */
       uint8_t RESERVED_23[8];
  __IO uint32_t SWD_ACCESS_CM33;                   /**< CM33 Software Debug Access, offset: 0xFB4 */
       uint8_t RESERVED_24[8];
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug Authentication BEACON, offset: 0xFC0 */
       uint8_t RESERVED_25[44];
  __I  uint32_t JTAG_ID;                           /**< JTAG Chip ID, offset: 0xFF0 */
  __I  uint32_t DEVICE_TYPE;                       /**< Device Type, offset: 0xFF4 */
  __I  uint32_t DEVICE_ID0;                        /**< Device ID, offset: 0xFF8 */
  __I  uint32_t DIEID;                             /**< Chip Revision ID and Number, offset: 0xFFC */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name REMAP - AHB Matrix Remap Control */
/*! @{ */

#define SYSCON_REMAP_REMAP_CM33_SBUS_MASK        (0x3U)
#define SYSCON_REMAP_REMAP_CM33_SBUS_SHIFT       (0U)
/*! REMAP_CM33_SBUS - RAMX0 address remap for CM33 System bus
 *  0b00..RAMX0: 0x04000000 - 0x04001fff
 *  0b01..RAMX0: 0x27ffe000 - 0x27ffffff
 */
#define SYSCON_REMAP_REMAP_CM33_SBUS(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_REMAP_CM33_SBUS_SHIFT)) & SYSCON_REMAP_REMAP_CM33_SBUS_MASK)

#define SYSCON_REMAP_REMAP_DMA0_MASK             (0xCU)
#define SYSCON_REMAP_REMAP_DMA0_SHIFT            (2U)
/*! REMAP_DMA0 - RAMX0 address remap for DMA0
 *  0b00..RAMX0: 0x04000000 - 0x04001fff
 *  0b01..RAMX0: 0x27ffe000 - 0x27ffffff
 */
#define SYSCON_REMAP_REMAP_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_REMAP_DMA0_SHIFT)) & SYSCON_REMAP_REMAP_DMA0_MASK)

#define SYSCON_REMAP_REMAP_PKC_MASK              (0x30U)
#define SYSCON_REMAP_REMAP_PKC_SHIFT             (4U)
/*! REMAP_PKC - RAMX0 address remap for PKC
 *  0b00..RAMX0: 0x04000000 - 0x04001fff
 *  0b01..RAMX0: 0x27ffe000 - 0x27ffffff
 */
#define SYSCON_REMAP_REMAP_PKC(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_REMAP_PKC_SHIFT)) & SYSCON_REMAP_REMAP_PKC_MASK)

#define SYSCON_REMAP_REMAP_DMA1_MASK             (0xC0U)
#define SYSCON_REMAP_REMAP_DMA1_SHIFT            (6U)
/*! REMAP_DMA1 - RAMX0 address remap for DMA1
 *  0b00..RAMX0: 0x04000000 - 0x04001fff
 *  0b01..RAMX0: 0x27ffe000 - 0x27ffffff
 */
#define SYSCON_REMAP_REMAP_DMA1(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_REMAP_DMA1_SHIFT)) & SYSCON_REMAP_REMAP_DMA1_MASK)

#define SYSCON_REMAP_LOCK_MASK                   (0x80000000U)
#define SYSCON_REMAP_LOCK_SHIFT                  (31U)
/*! LOCK - This 1-bit field provides a mechanism to limit writes to the this register to protect its
 *    contents. Once set, this bit remains asserted until the next reset.
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered.
 */
#define SYSCON_REMAP_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << SYSCON_REMAP_LOCK_SHIFT)) & SYSCON_REMAP_LOCK_MASK)
/*! @} */

/*! @name AHBMATPRIO - AHB Matrix Priority Control */
/*! @{ */

#define SYSCON_AHBMATPRIO_PRI_CM33_CBUS_MASK     (0x3U)
#define SYSCON_AHBMATPRIO_PRI_CM33_CBUS_SHIFT    (0U)
/*! PRI_CM33_CBUS - CM33 C-AHB bus priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_CM33_CBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CM33_CBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CM33_CBUS_MASK)

#define SYSCON_AHBMATPRIO_PRI_CM33_SBUS_MASK     (0xCU)
#define SYSCON_AHBMATPRIO_PRI_CM33_SBUS_SHIFT    (2U)
/*! PRI_CM33_SBUS - CM33 S-AHB bus priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_CM33_SBUS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_CM33_SBUS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_CM33_SBUS_MASK)

#define SYSCON_AHBMATPRIO_DMA0_MASK              (0x300U)
#define SYSCON_AHBMATPRIO_DMA0_SHIFT             (8U)
/*! DMA0 - DMA0 controller priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA0_SHIFT)) & SYSCON_AHBMATPRIO_DMA0_MASK)

#define SYSCON_AHBMATPRIO_DMA1_MASK              (0xC00U)
#define SYSCON_AHBMATPRIO_DMA1_SHIFT             (10U)
/*! DMA1 - DMA1 controller priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA1_SHIFT)) & SYSCON_AHBMATPRIO_DMA1_MASK)

#define SYSCON_AHBMATPRIO_PRI_PKC_CSS_MASK       (0x3000U)
#define SYSCON_AHBMATPRIO_PRI_PKC_CSS_SHIFT      (12U)
/*! PRI_PKC_CSS - PKC/CSS priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_PRI_PKC_CSS(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_PRI_PKC_CSS_SHIFT)) & SYSCON_AHBMATPRIO_PRI_PKC_CSS_MASK)
/*! @} */

/*! @name CM33STCKCAL - Secure CM33 System Tick Calibration */
/*! @{ */

#define SYSCON_CM33STCKCAL_TENMS_MASK            (0xFFFFFFU)
#define SYSCON_CM33STCKCAL_TENMS_SHIFT           (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CM33STCKCAL_TENMS(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33STCKCAL_TENMS_SHIFT)) & SYSCON_CM33STCKCAL_TENMS_MASK)

#define SYSCON_CM33STCKCAL_SKEW_MASK             (0x1000000U)
#define SYSCON_CM33STCKCAL_SKEW_SHIFT            (24U)
/*! SKEW - Indicates whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SYSCON_CM33STCKCAL_SKEW(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33STCKCAL_SKEW_SHIFT)) & SYSCON_CM33STCKCAL_SKEW_MASK)

#define SYSCON_CM33STCKCAL_NOREF_MASK            (0x2000000U)
#define SYSCON_CM33STCKCAL_NOREF_SHIFT           (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SYSCON_CM33STCKCAL_NOREF(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33STCKCAL_NOREF_SHIFT)) & SYSCON_CM33STCKCAL_NOREF_MASK)
/*! @} */

/*! @name CM33NSTCKCAL - Non-Secure CM33 System Tick Calibration */
/*! @{ */

#define SYSCON_CM33NSTCKCAL_TENMS_MASK           (0xFFFFFFU)
#define SYSCON_CM33NSTCKCAL_TENMS_SHIFT          (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SYSCON_CM33NSTCKCAL_TENMS(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33NSTCKCAL_TENMS_SHIFT)) & SYSCON_CM33NSTCKCAL_TENMS_MASK)

#define SYSCON_CM33NSTCKCAL_SKEW_MASK            (0x1000000U)
#define SYSCON_CM33NSTCKCAL_SKEW_SHIFT           (24U)
/*! SKEW - Indicates whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SYSCON_CM33NSTCKCAL_SKEW(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33NSTCKCAL_SKEW_SHIFT)) & SYSCON_CM33NSTCKCAL_SKEW_MASK)

#define SYSCON_CM33NSTCKCAL_NOREF_MASK           (0x2000000U)
#define SYSCON_CM33NSTCKCAL_NOREF_SHIFT          (25U)
/*! NOREF - Indicates whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SYSCON_CM33NSTCKCAL_NOREF(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33NSTCKCAL_NOREF_SHIFT)) & SYSCON_CM33NSTCKCAL_NOREF_MASK)
/*! @} */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON_NMISRC_IRQCM33_MASK               (0xFFU)
#define SYSCON_NMISRC_IRQCM33_SHIFT              (0U)
/*! IRQCM33 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for the CM33, if enabled by NMIENCM33. */
#define SYSCON_NMISRC_IRQCM33(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQCM33_SHIFT)) & SYSCON_NMISRC_IRQCM33_MASK)

#define SYSCON_NMISRC_NMIENCM33_MASK             (0x80000000U)
#define SYSCON_NMISRC_NMIENCM33_SHIFT            (31U)
/*! NMIENCM33 - Writing a 1 to this bit enables the Non-Maskable Interrupt (NMI) source selected by IRQCM33. */
#define SYSCON_NMISRC_NMIENCM33(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENCM33_SHIFT)) & SYSCON_NMISRC_NMIENCM33_MASK)
/*! @} */

/*! @name AHBAIPSCLKDIV - AHB2AIPS Bridge Clock Divider */
/*! @{ */

#define SYSCON_AHBAIPSCLKDIV_RESET_MASK          (0x20000000U)
#define SYSCON_AHBAIPSCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_AHBAIPSCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBAIPSCLKDIV_RESET_SHIFT)) & SYSCON_AHBAIPSCLKDIV_RESET_MASK)

#define SYSCON_AHBAIPSCLKDIV_HALT_MASK           (0x40000000U)
#define SYSCON_AHBAIPSCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_AHBAIPSCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBAIPSCLKDIV_HALT_SHIFT)) & SYSCON_AHBAIPSCLKDIV_HALT_MASK)

#define SYSCON_AHBAIPSCLKDIV_UNSTAB_MASK         (0x80000000U)
#define SYSCON_AHBAIPSCLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_AHBAIPSCLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBAIPSCLKDIV_UNSTAB_SHIFT)) & SYSCON_AHBAIPSCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name AHBCLKDIV - System Clock Divider */
/*! @{ */

#define SYSCON_AHBCLKDIV_DIV_MASK                (0xFFU)
#define SYSCON_AHBCLKDIV_DIV_SHIFT               (0U)
/*! DIV - Clock divider value */
#define SYSCON_AHBCLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_DIV_SHIFT)) & SYSCON_AHBCLKDIV_DIV_MASK)

#define SYSCON_AHBCLKDIV_UNSTAB_MASK             (0x80000000U)
#define SYSCON_AHBCLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_AHBCLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBCLKDIV_UNSTAB_SHIFT)) & SYSCON_AHBCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKUNLOCK - Clock Configuration Unlock */
/*! @{ */

#define SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK     (0x1U)
#define SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_SHIFT    (0U)
/*! CLKGEN_LOCKOUT - Controls clock configuration registers access (for example, xxxDIV, xxxSEL)
 *  0b0..Unlocks all hardware clock control logic
 *  0b1..Locks all clock configuration
 */
#define SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_SHIFT)) & SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK)
/*! @} */

/*! @name NVM_CTRL - NVM Control */
/*! @{ */

#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC_MASK      (0x1U)
#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC_SHIFT     (0U)
/*! DIS_FLASH_SPEC - Flash speculation control
 *  0b0..Enables flash speculation
 *  0b1..Disables flash speculation
 */
#define SYSCON_NVM_CTRL_DIS_FLASH_SPEC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_FLASH_SPEC_SHIFT)) & SYSCON_NVM_CTRL_DIS_FLASH_SPEC_MASK)

#define SYSCON_NVM_CTRL_DIS_DATA_SPEC_MASK       (0x2U)
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC_SHIFT      (1U)
/*! DIS_DATA_SPEC - Flash data speculation control
 *  0b0..Enables data speculation
 *  0b1..Disables data speculation
 */
#define SYSCON_NVM_CTRL_DIS_DATA_SPEC(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_DATA_SPEC_SHIFT)) & SYSCON_NVM_CTRL_DIS_DATA_SPEC_MASK)

#define SYSCON_NVM_CTRL_FLASH_STALL_EN_MASK      (0x400U)
#define SYSCON_NVM_CTRL_FLASH_STALL_EN_SHIFT     (10U)
/*! FLASH_STALL_EN - FLASH stall on busy control
 *  0b0..No stall on FLASH busy
 *  0b1..Stall on FLASH busy
 */
#define SYSCON_NVM_CTRL_FLASH_STALL_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_FLASH_STALL_EN_SHIFT)) & SYSCON_NVM_CTRL_FLASH_STALL_EN_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK  (0x10000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT (16U)
/*! DIS_MBECC_ERR_INST - Bus error on instruction multi-bit ecc error control
 *  0b0..Enables bus error on multi-bit ecc error for instruction
 *  0b1..Disables bus error on multi-bit ecc error for instruction
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK  (0x20000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT (17U)
/*! DIS_MBECC_ERR_DATA - Bus error on data multi-bit ecc error control
 *  0b0..Enables bus error on multi-bit ecc error for data
 *  0b1..Disables bus error on multi-bit ecc error for data
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK)
/*! @} */

/*! @name ROMCR - ROM Wait State */
/*! @{ */

#define SYSCON_ROMCR_ROM_WAIT_MASK               (0x1U)
#define SYSCON_ROMCR_ROM_WAIT_SHIFT              (0U)
/*! ROM_WAIT - ROM waiting Arm core and other masters */
#define SYSCON_ROMCR_ROM_WAIT(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_ROMCR_ROM_WAIT_SHIFT)) & SYSCON_ROMCR_ROM_WAIT_MASK)
/*! @} */

/*! @name ROMCPCLKCTRL - ROMCP Clock Control */
/*! @{ */

#define SYSCON_ROMCPCLKCTRL_ROMCP_SLEEPING_OVERRIDE_MASK (0x1U)
#define SYSCON_ROMCPCLKCTRL_ROMCP_SLEEPING_OVERRIDE_SHIFT (0U)
/*! ROMCP_SLEEPING_OVERRIDE - This bit is used to override UTEAL sleeping clock gating to ROMCP HCLK
 *  0b0..Disable UTEAL sleeping clock gating to ROMCP HCLK
 *  0b1..Enables UTEAL sleeping clock gating to ROMCP HCLK
 */
#define SYSCON_ROMCPCLKCTRL_ROMCP_SLEEPING_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ROMCPCLKCTRL_ROMCP_SLEEPING_OVERRIDE_SHIFT)) & SYSCON_ROMCPCLKCTRL_ROMCP_SLEEPING_OVERRIDE_MASK)

#define SYSCON_ROMCPCLKCTRL_ROMCP_AUTOCG_OVERRIDE_MASK (0x2U)
#define SYSCON_ROMCPCLKCTRL_ROMCP_AUTOCG_OVERRIDE_SHIFT (1U)
/*! ROMCP_AUTOCG_OVERRIDE - This bit is used to override auto clock gating to ROMCP HCLK
 *  0b0..Disable auto clock gating to ROMCP HCLK
 *  0b1..Enables auto clock gating to ROMCP HCLK
 */
#define SYSCON_ROMCPCLKCTRL_ROMCP_AUTOCG_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_ROMCPCLKCTRL_ROMCP_AUTOCG_OVERRIDE_SHIFT)) & SYSCON_ROMCPCLKCTRL_ROMCP_AUTOCG_OVERRIDE_MASK)
/*! @} */

/*! @name SRAM_INTERLEAVE - Control SRAM Interleave Integration */
/*! @{ */

#define SYSCON_SRAM_INTERLEAVE_INTERLEAVE_MASK   (0x1U)
#define SYSCON_SRAM_INTERLEAVE_INTERLEAVE_SHIFT  (0U)
/*! INTERLEAVE - Controls SRAM access for SRAM B3 and SRAM B4
 *  0b0..Access to SRAM B3 and SRAM B4 is consecutive.
 *  0b1..Access to SRAM B3 and SRAM B4 is interleaved. This setting is need for PKC L0 memory access.
 */
#define SYSCON_SRAM_INTERLEAVE_INTERLEAVE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_INTERLEAVE_INTERLEAVE_SHIFT)) & SYSCON_SRAM_INTERLEAVE_INTERLEAVE_MASK)
/*! @} */

/*! @name SRAMCTL - SRAM TMTR CTRL register */
/*! @{ */

#define SYSCON_SRAMCTL_SRAMCTL_TMTR_REQ_MASK     (0x40000000U)
#define SYSCON_SRAMCTL_SRAMCTL_TMTR_REQ_SHIFT    (30U)
/*! SRAMCTL_TMTR_REQ - This bit will give TMTR values written req */
#define SYSCON_SRAMCTL_SRAMCTL_TMTR_REQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAMCTL_SRAMCTL_TMTR_REQ_SHIFT)) & SYSCON_SRAMCTL_SRAMCTL_TMTR_REQ_MASK)

#define SYSCON_SRAMCTL_SRAMCTL_TMTR_ACK_MASK     (0x80000000U)
#define SYSCON_SRAMCTL_SRAMCTL_TMTR_ACK_SHIFT    (31U)
/*! SRAMCTL_TMTR_ACK - This bit will give TMTR values written ack. write this bit 1 to clear the ack */
#define SYSCON_SRAMCTL_SRAMCTL_TMTR_ACK(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAMCTL_SRAMCTL_TMTR_ACK_SHIFT)) & SYSCON_SRAMCTL_SRAMCTL_TMTR_ACK_MASK)
/*! @} */

/*! @name PULSECAPSYNC_BYPASS - Pulse Capture Logic Bypass */
/*! @{ */

#define SYSCON_PULSECAPSYNC_BYPASS_LPUART0_0_MASK (0x1U)
#define SYSCON_PULSECAPSYNC_BYPASS_LPUART0_0_SHIFT (0U)
/*! LPUART0_0 - LPUART1 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_LPUART0_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_LPUART0_0_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_LPUART0_0_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_LPUART1_0_MASK (0x2U)
#define SYSCON_PULSECAPSYNC_BYPASS_LPUART1_0_SHIFT (1U)
/*! LPUART1_0 - LPUART0 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_LPUART1_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_LPUART1_0_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_LPUART1_0_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_LPCMP0_0_MASK (0x4U)
#define SYSCON_PULSECAPSYNC_BYPASS_LPCMP0_0_SHIFT (2U)
/*! LPCMP0_0 - LPCMP0 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_LPCMP0_0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_LPCMP0_0_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_LPCMP0_0_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_4_MASK (0x8U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_4_SHIFT (3U)
/*! CTIMER2_4 - CTIMER2_4 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_4(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_4_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_4_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_3_MASK (0x10U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_3_SHIFT (4U)
/*! CTIMER2_3 - CTIMER2_3 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_3(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_3_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_3_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_2_MASK (0x20U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_2_SHIFT (5U)
/*! CTIMER2_2 - CTIMER2_2 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_2(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_2_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_2_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_1_MASK (0x40U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_1_SHIFT (6U)
/*! CTIMER2_1 - CTIMER2_1 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_1_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_1_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_0_MASK (0x80U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_0_SHIFT (7U)
/*! CTIMER2_0 - CTIMER2_0 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_0_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER2_0_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_4_MASK (0x100U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_4_SHIFT (8U)
/*! CTIMER1_4 - CTIMER1_4 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_4(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_4_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_4_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_3_MASK (0x200U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_3_SHIFT (9U)
/*! CTIMER1_3 - CTIMER1_3 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_3(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_3_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_3_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_2_MASK (0x400U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_2_SHIFT (10U)
/*! CTIMER1_2 - CTIMER1_2 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_2(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_2_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_2_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_1_MASK (0x800U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_1_SHIFT (11U)
/*! CTIMER1_1 - CTIMER1_1 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_1_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_1_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_0_MASK (0x1000U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_0_SHIFT (12U)
/*! CTIMER1_0 - CTIMER1_0 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_0_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER1_0_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_4_MASK (0x2000U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_4_SHIFT (13U)
/*! CTIMER0_4 - CTIMER0_4 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_4(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_4_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_4_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_3_MASK (0x4000U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_3_SHIFT (14U)
/*! CTIMER0_3 - CTIMER0_3 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_3(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_3_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_3_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_2_MASK (0x8000U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_2_SHIFT (15U)
/*! CTIMER0_2 - CTIMER0_2 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_2(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_2_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_2_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_1_MASK (0x10000U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_1_SHIFT (16U)
/*! CTIMER0_1 - CTIMER0_1 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_1_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_1_MASK)

#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_0_MASK (0x20000U)
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_0_SHIFT (17U)
/*! CTIMER0_0 - CTIMER0_0 Trigger Bypass Control Bit
 *  0b0..Pulse capture sync bypassed
 *  0b1..Pulse capture sync enabled
 */
#define SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_0_SHIFT)) & SYSCON_PULSECAPSYNC_BYPASS_CTIMER0_0_MASK)
/*! @} */

/*! @name PULSE_CAP_CMP_CLK_MUXSEL - Comparator Pulse Capture Clock MUX Select */
/*! @{ */

#define SYSCON_PULSE_CAP_CMP_CLK_MUXSEL_CMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_MASK (0x3U)
#define SYSCON_PULSE_CAP_CMP_CLK_MUXSEL_CMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_SHIFT (0U)
/*! CMP0_PULSE_CAP_SYNC_CLK_MUX_SEL - Clock source select for CMP0
 *  0b00..Clock Source 1
 *  0b01..Clock source 2
 *  0b10..Clock source 3
 *  0b11..Clock source 4
 */
#define SYSCON_PULSE_CAP_CMP_CLK_MUXSEL_CMP0_PULSE_CAP_SYNC_CLK_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_PULSE_CAP_CMP_CLK_MUXSEL_CMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_SHIFT)) & SYSCON_PULSE_CAP_CMP_CLK_MUXSEL_CMP0_PULSE_CAP_SYNC_CLK_MUX_SEL_MASK)
/*! @} */

/*! @name FLASH_ADVC_PROTECT - FMU RF Active Control */
/*! @{ */

#define SYSCON_FLASH_ADVC_PROTECT_FLASH_ADVC_PROTECT_MASK (0x1U)
#define SYSCON_FLASH_ADVC_PROTECT_FLASH_ADVC_PROTECT_SHIFT (0U)
/*! FLASH_ADVC_PROTECT - Bit to gate CCOB commands while running ADVC. Use to prevent CCOB commands to run when ADVC is active.
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON_FLASH_ADVC_PROTECT_FLASH_ADVC_PROTECT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_ADVC_PROTECT_FLASH_ADVC_PROTECT_SHIFT)) & SYSCON_FLASH_ADVC_PROTECT_FLASH_ADVC_PROTECT_MASK)
/*! @} */

/*! @name AONAUXCLKDIV - AON AUX Clock Divider Control */
/*! @{ */

#define SYSCON_AONAUXCLKDIV_DIV_MASK             (0x1FU)
#define SYSCON_AONAUXCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Clock divider value */
#define SYSCON_AONAUXCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_AONAUXCLKDIV_DIV_SHIFT)) & SYSCON_AONAUXCLKDIV_DIV_MASK)

#define SYSCON_AONAUXCLKDIV_RESET_MASK           (0x20000000U)
#define SYSCON_AONAUXCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_AONAUXCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_AONAUXCLKDIV_RESET_SHIFT)) & SYSCON_AONAUXCLKDIV_RESET_MASK)

#define SYSCON_AONAUXCLKDIV_HALT_MASK            (0x40000000U)
#define SYSCON_AONAUXCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_AONAUXCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_AONAUXCLKDIV_HALT_SHIFT)) & SYSCON_AONAUXCLKDIV_HALT_MASK)

#define SYSCON_AONAUXCLKDIV_UNSTAB_MASK          (0x80000000U)
#define SYSCON_AONAUXCLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_AONAUXCLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_AONAUXCLKDIV_UNSTAB_SHIFT)) & SYSCON_AONAUXCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name HYPERVISORINTCTRL - Hypervisor Interrupt Control */
/*! @{ */

#define SYSCON_HYPERVISORINTCTRL_HYPERVISOR_INT_CTRL_MASK (0x1U)
#define SYSCON_HYPERVISORINTCTRL_HYPERVISOR_INT_CTRL_SHIFT (0U)
/*! HYPERVISOR_INT_CTRL - Hypervisor interrupt control bit used to deassert hypervisor interrupt after interrupt sevice routine
 *  0b0..Interrupt will be enabled
 *  0b1..Interrupt will be disabled
 */
#define SYSCON_HYPERVISORINTCTRL_HYPERVISOR_INT_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_HYPERVISORINTCTRL_HYPERVISOR_INT_CTRL_SHIFT)) & SYSCON_HYPERVISORINTCTRL_HYPERVISOR_INT_CTRL_MASK)
/*! @} */

/*! @name CM33STAT - CM33 Status */
/*! @{ */

#define SYSCON_CM33STAT_CM33SLEEPING_MASK        (0x1U)
#define SYSCON_CM33STAT_CM33SLEEPING_SHIFT       (0U)
/*! CM33SLEEPING - CM33 sleeping state
 *  0b0..CM33 is not sleeping
 *  0b1..CM33 is sleeping
 */
#define SYSCON_CM33STAT_CM33SLEEPING(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33STAT_CM33SLEEPING_SHIFT)) & SYSCON_CM33STAT_CM33SLEEPING_MASK)

#define SYSCON_CM33STAT_CM33LOCKUP_MASK          (0x4U)
#define SYSCON_CM33STAT_CM33LOCKUP_SHIFT         (2U)
/*! CM33LOCKUP - CM33 lockup state
 *  0b0..CM33 is not in lockup
 *  0b1..CM33 is in lockup
 */
#define SYSCON_CM33STAT_CM33LOCKUP(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33STAT_CM33LOCKUP_SHIFT)) & SYSCON_CM33STAT_CM33LOCKUP_MASK)
/*! @} */

/*! @name CM33_SLEEPING_SELECT - Masking CM33 Sleeping For IPG_DOZE */
/*! @{ */

#define SYSCON_CM33_SLEEPING_SELECT_IPG_DOZE_CM33_SEL_MASK (0x1U)
#define SYSCON_CM33_SLEEPING_SELECT_IPG_DOZE_CM33_SEL_SHIFT (0U)
/*! IPG_DOZE_CM33_SEL - Used to select CM33 sleeping for IPG_DOZE
 *  0b0..CM33 sleeping not selected for IPG_DOZE
 *  0b1..CM33 sleeping selected for IPG_DOZE
 */
#define SYSCON_CM33_SLEEPING_SELECT_IPG_DOZE_CM33_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CM33_SLEEPING_SELECT_IPG_DOZE_CM33_SEL_SHIFT)) & SYSCON_CM33_SLEEPING_SELECT_IPG_DOZE_CM33_SEL_MASK)
/*! @} */

/*! @name LPCAC_CTRL - LPCAC Control */
/*! @{ */

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK         (0x1U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT        (0U)
/*! DIS_LPCAC - Disables/enables the cache function.
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK         (0x2U)
#define SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT        (1U)
/*! CLR_LPCAC - Clears the cache function.
 *  0b0..Unclears the cache.
 *  0b1..Clears the cache.
 */
#define SYSCON_LPCAC_CTRL_CLR_LPCAC(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_CLR_LPCAC_SHIFT)) & SYSCON_LPCAC_CTRL_CLR_LPCAC_MASK)

#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK      (0x4U)
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT     (2U)
/*! FRC_NO_ALLOC - Forces no allocation.
 *  0b0..Forces allocation.
 *  0b1..Forces no allocation.
 */
#define SYSCON_LPCAC_CTRL_FRC_NO_ALLOC(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_SHIFT)) & SYSCON_LPCAC_CTRL_FRC_NO_ALLOC_MASK)

#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_MASK    (0x10U)
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_SHIFT   (4U)
/*! DIS_LPCAC_WTBF - Disables LPCAC write through buffer.
 *  0b0..Enables write through buffer.
 *  0b1..Disables write through buffer.
 */
#define SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_SHIFT)) & SYSCON_LPCAC_CTRL_DIS_LPCAC_WTBF_MASK)

#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_MASK    (0x20U)
#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_SHIFT   (5U)
/*! LIM_LPCAC_WTBF - Limits LPCAC write through Buffer.
 *  0b0..Write buffer enabled when transaction is bufferable.
 *  0b1..Write buffer enabled when transaction is cacheable and bufferable.
 */
#define SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_SHIFT)) & SYSCON_LPCAC_CTRL_LIM_LPCAC_WTBF_MASK)

#define SYSCON_LPCAC_CTRL_LPCAC_XOM_MASK         (0x80U)
#define SYSCON_LPCAC_CTRL_LPCAC_XOM_SHIFT        (7U)
/*! LPCAC_XOM - LPCAC XOM (eXecute-Only-Memory) attribute control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON_LPCAC_CTRL_LPCAC_XOM(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LPCAC_XOM_SHIFT)) & SYSCON_LPCAC_CTRL_LPCAC_XOM_MASK)

#define SYSCON_LPCAC_CTRL_LPCAC_MEM_REQ_MASK     (0x100U)
#define SYSCON_LPCAC_CTRL_LPCAC_MEM_REQ_SHIFT    (8U)
/*! LPCAC_MEM_REQ - Request LPCAC memories.
 *  0b0..LPCAC is disabled. Configures RAMX1 (shared memories) as Code TCM.
 *  0b1..Enables RAMX1 (shared memories) as LPCAC memories. Write one to lock.
 */
#define SYSCON_LPCAC_CTRL_LPCAC_MEM_REQ(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_LPCAC_CTRL_LPCAC_MEM_REQ_SHIFT)) & SYSCON_LPCAC_CTRL_LPCAC_MEM_REQ_MASK)
/*! @} */

/*! @name PWM0SUBCTL - PWM0 Sub-module Control */
/*! @{ */

#define SYSCON_PWM0SUBCTL_CLK0_EN_MASK           (0x1U)
#define SYSCON_PWM0SUBCTL_CLK0_EN_SHIFT          (0U)
/*! CLK0_EN - Enables PWM0 SUB Clock0
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_PWM0SUBCTL_CLK0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK0_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK0_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK1_EN_MASK           (0x2U)
#define SYSCON_PWM0SUBCTL_CLK1_EN_SHIFT          (1U)
/*! CLK1_EN - Enables PWM0 SUB Clock1
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_PWM0SUBCTL_CLK1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK1_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK1_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK2_EN_MASK           (0x4U)
#define SYSCON_PWM0SUBCTL_CLK2_EN_SHIFT          (2U)
/*! CLK2_EN - Enables PWM0 SUB Clock2
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_PWM0SUBCTL_CLK2_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK2_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK2_EN_MASK)

#define SYSCON_PWM0SUBCTL_CLK3_EN_MASK           (0x8U)
#define SYSCON_PWM0SUBCTL_CLK3_EN_SHIFT          (3U)
/*! CLK3_EN - Enables PWM0 SUB Clock3
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_PWM0SUBCTL_CLK3_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_PWM0SUBCTL_CLK3_EN_SHIFT)) & SYSCON_PWM0SUBCTL_CLK3_EN_MASK)
/*! @} */

/*! @name CTIMERGLOBALSTARTEN - CTIMER Global Start Enable */
/*! @{ */

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK (0x1U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT (0U)
/*! CTIMER0_CLK_EN - Enables the CTIMER0 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK (0x2U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT (1U)
/*! CTIMER1_CLK_EN - Enables the CTIMER1 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK)

#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK (0x4U)
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT (2U)
/*! CTIMER2_CLK_EN - Enables the CTIMER2 function clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT)) & SYSCON_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK)
/*! @} */

/*! @name RAM_CTRL - RAM Control */
/*! @{ */

#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_MASK     (0x1U)
#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_SHIFT    (0U)
/*! RAMA_ECC_ENABLE - RAMA ECC enable.
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_SHIFT)) & SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_MASK)

#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_MASK    (0x10000U)
#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_SHIFT   (16U)
/*! RAMA_CG_OVERRIDE - RAMA bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_MASK)

#define SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_MASK    (0x20000U)
#define SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_SHIFT   (17U)
/*! RAMX_CG_OVERRIDE - RAMX bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMX_CG_OVERRIDE_MASK)

#define SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_MASK    (0x40000U)
#define SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_SHIFT   (18U)
/*! RAMB_CG_OVERRIDE - RAMB bank clock gating control
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMB_CG_OVERRIDE_MASK)
/*! @} */

/*! @name GRAY_CODE_LSB - Gray to Binary Converter Gray Code [31:0] */
/*! @{ */

#define SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK (0xFFFFFFFFU)
#define SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT (0U)
/*! CODE_GRAY_31_0 - Gray code [31:0] */
#define SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT)) & SYSCON_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK)
/*! @} */

/*! @name GRAY_CODE_MSB - Gray to Binary Converter Gray Code [41:32] */
/*! @{ */

#define SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_MASK (0x3FFU)
#define SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_SHIFT (0U)
/*! CODE_GRAY_41_32 - Gray code [41:32] */
#define SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_SHIFT)) & SYSCON_GRAY_CODE_MSB_CODE_GRAY_41_32_MASK)
/*! @} */

/*! @name BINARY_CODE_LSB - Gray to Binary Converter Binary Code [31:0] */
/*! @{ */

#define SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_MASK (0xFFFFFFFFU)
#define SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT (0U)
/*! CODE_BIN_31_0 - Binary code [31:0] */
#define SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT)) & SYSCON_BINARY_CODE_LSB_CODE_BIN_31_0_MASK)
/*! @} */

/*! @name BINARY_CODE_MSB - Gray to Binary Converter Binary Code [41:32] */
/*! @{ */

#define SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_MASK (0x3FFU)
#define SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_SHIFT (0U)
/*! CODE_BIN_41_32 - Binary code [41:32] */
#define SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_SHIFT)) & SYSCON_BINARY_CODE_MSB_CODE_BIN_41_32_MASK)
/*! @} */

/*! @name FLASH_CFG - Flash Configuration */
/*! @{ */

#define SYSCON_FLASH_CFG_IFR_ERASE_DIS_MASK      (0xFU)
#define SYSCON_FLASH_CFG_IFR_ERASE_DIS_SHIFT     (0U)
/*! IFR_ERASE_DIS - user IFR erase control
 *  0b0000..bit N enable IFR sector N erase(N=0-3).
 *  0b1111..bit N disable IFR sector N erase(N=0-3), write one lock.
 */
#define SYSCON_FLASH_CFG_IFR_ERASE_DIS(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_CFG_IFR_ERASE_DIS_SHIFT)) & SYSCON_FLASH_CFG_IFR_ERASE_DIS_MASK)

#define SYSCON_FLASH_CFG_MASS_ERASE_DIS_MASK     (0x100U)
#define SYSCON_FLASH_CFG_MASS_ERASE_DIS_SHIFT    (8U)
/*! MASS_ERASE_DIS - Mass erase control
 *  0b0..Enables mass erase
 *  0b1..Disables mass erase, write one lock
 */
#define SYSCON_FLASH_CFG_MASS_ERASE_DIS(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_FLASH_CFG_MASS_ERASE_DIS_SHIFT)) & SYSCON_FLASH_CFG_MASS_ERASE_DIS_MASK)
/*! @} */

/*! @name ROP_STATE - ROP State */
/*! @{ */

#define SYSCON_ROP_STATE_ROP_STATE_MASK          (0xFFFFFFFFU)
#define SYSCON_ROP_STATE_ROP_STATE_SHIFT         (0U)
/*! ROP_STATE - ROP state */
#define SYSCON_ROP_STATE_ROP_STATE(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_ROP_STATE_ROP_STATE_SHIFT)) & SYSCON_ROP_STATE_ROP_STATE_MASK)
/*! @} */

/*! @name SRAM_XEN - RAM XEN Control */
/*! @{ */

#define SYSCON_SRAM_XEN_RAMX0_XEN_MASK           (0x1U)
#define SYSCON_SRAM_XEN_RAMX0_XEN_SHIFT          (0U)
/*! RAMX0_XEN - RAMX0 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SYSCON_SRAM_XEN_RAMX0_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMX0_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMX0_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMX1_XEN_MASK           (0x2U)
#define SYSCON_SRAM_XEN_RAMX1_XEN_SHIFT          (1U)
/*! RAMX1_XEN - RAMX1 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SYSCON_SRAM_XEN_RAMX1_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMX1_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMX1_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMA0_XEN_MASK           (0x4U)
#define SYSCON_SRAM_XEN_RAMA0_XEN_SHIFT          (2U)
/*! RAMA0_XEN - RAMA0 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SYSCON_SRAM_XEN_RAMA0_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMA0_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMA0_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMA1_XEN_MASK           (0x8U)
#define SYSCON_SRAM_XEN_RAMA1_XEN_SHIFT          (3U)
/*! RAMA1_XEN - RAMA1 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SYSCON_SRAM_XEN_RAMA1_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMA1_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMA1_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMB0_XEN_MASK           (0x10U)
#define SYSCON_SRAM_XEN_RAMB0_XEN_SHIFT          (4U)
/*! RAMB0_XEN - RAMB0 Executable Permission Control
 *  0b0..Execute permission is disabled, R/W are enabled
 *  0b1..Execute permission is enabled, R/W/X are enabled
 */
#define SYSCON_SRAM_XEN_RAMB0_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMB0_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMB0_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMA2_XEN_MASK           (0x20U)
#define SYSCON_SRAM_XEN_RAMA2_XEN_SHIFT          (5U)
/*! RAMA2_XEN - RAMA1 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SYSCON_SRAM_XEN_RAMA2_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMA2_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMA2_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMA3_XEN_MASK           (0x40U)
#define SYSCON_SRAM_XEN_RAMA3_XEN_SHIFT          (6U)
/*! RAMA3_XEN - RAMA1 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SYSCON_SRAM_XEN_RAMA3_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMA3_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMA3_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMB1_XEN_MASK           (0x80U)
#define SYSCON_SRAM_XEN_RAMB1_XEN_SHIFT          (7U)
/*! RAMB1_XEN - RAMB1 Executable Permission Control
 *  0b0..Execute permission is disabled, R/W are enabled
 *  0b1..Execute permission is enabled, R/W/X are enabled
 */
#define SYSCON_SRAM_XEN_RAMB1_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMB1_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMB1_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMB2_XEN_MASK           (0x100U)
#define SYSCON_SRAM_XEN_RAMB2_XEN_SHIFT          (8U)
/*! RAMB2_XEN - RAMB2 Executable Permission Control
 *  0b0..Execute permission is disabled, R/W are enabled
 *  0b1..Execute permission is enabled, R/W/X are enabled
 */
#define SYSCON_SRAM_XEN_RAMB2_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMB2_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMB2_XEN_MASK)

#define SYSCON_SRAM_XEN_RAMB3_XEN_MASK           (0x200U)
#define SYSCON_SRAM_XEN_RAMB3_XEN_SHIFT          (9U)
/*! RAMB3_XEN - RAMB3 and RAMB4 Interleaved Executable Permission Control
 *  0b0..Execute permission is disabled, R/W are enabled
 *  0b1..Execute permission is enabled, R/W/X are enabled
 */
#define SYSCON_SRAM_XEN_RAMB3_XEN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_RAMB3_XEN_SHIFT)) & SYSCON_SRAM_XEN_RAMB3_XEN_MASK)

#define SYSCON_SRAM_XEN_LOCK_MASK                (0x80000000U)
#define SYSCON_SRAM_XEN_LOCK_SHIFT               (31U)
/*! LOCK - This 1-bit field provides a mechanism to limit writes to the this register (and
 *    SRAM_XEN_DP) to protect its contents. Once set, this bit remains asserted until the next reset.
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered.
 */
#define SYSCON_SRAM_XEN_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_LOCK_SHIFT)) & SYSCON_SRAM_XEN_LOCK_MASK)
/*! @} */

/*! @name SRAM_XEN_DP - RAM XEN Control (Duplicate) */
/*! @{ */

#define SYSCON_SRAM_XEN_DP_RAMX0_XEN_DP_MASK     (0x1U)
#define SYSCON_SRAM_XEN_DP_RAMX0_XEN_DP_SHIFT    (0U)
/*! RAMX0_XEN_DP - Refer to RAMX0_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMX0_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMX0_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMX0_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMX1_XEN_DP_MASK     (0x2U)
#define SYSCON_SRAM_XEN_DP_RAMX1_XEN_DP_SHIFT    (1U)
/*! RAMX1_XEN_DP - Refer to RAMX1_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMX1_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMX1_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMX1_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMA0_XEN_DP_MASK     (0x4U)
#define SYSCON_SRAM_XEN_DP_RAMA0_XEN_DP_SHIFT    (2U)
/*! RAMA0_XEN_DP - Refer to RAMA0_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMA0_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMA0_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMA0_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMA1_XEN_DP_MASK     (0x8U)
#define SYSCON_SRAM_XEN_DP_RAMA1_XEN_DP_SHIFT    (3U)
/*! RAMA1_XEN_DP - Refer to RAMA1_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMA1_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMA1_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMA1_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMB0_XEN_DP_MASK     (0x10U)
#define SYSCON_SRAM_XEN_DP_RAMB0_XEN_DP_SHIFT    (4U)
/*! RAMB0_XEN_DP - Refer to RAMB0_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMB0_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMB0_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMB0_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMA2_XEN_DP_MASK     (0x20U)
#define SYSCON_SRAM_XEN_DP_RAMA2_XEN_DP_SHIFT    (5U)
/*! RAMA2_XEN_DP - Refer to RAMA1_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMA2_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMA2_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMA2_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMA3_XEN_DP_MASK     (0x40U)
#define SYSCON_SRAM_XEN_DP_RAMA3_XEN_DP_SHIFT    (6U)
/*! RAMA3_XEN_DP - Refer to RAMA1_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMA3_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMA3_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMA3_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMB1_XEN_DP_MASK     (0x80U)
#define SYSCON_SRAM_XEN_DP_RAMB1_XEN_DP_SHIFT    (7U)
/*! RAMB1_XEN_DP - Refer to RAMB1_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMB1_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMB1_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMB1_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMB2_XEN_DP_MASK     (0x100U)
#define SYSCON_SRAM_XEN_DP_RAMB2_XEN_DP_SHIFT    (8U)
/*! RAMB2_XEN_DP - Refer to RAMB2_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMB2_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMB2_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMB2_XEN_DP_MASK)

#define SYSCON_SRAM_XEN_DP_RAMB3_XEN_DP_MASK     (0x200U)
#define SYSCON_SRAM_XEN_DP_RAMB3_XEN_DP_SHIFT    (9U)
/*! RAMB3_XEN_DP - Refer to RAMB3_XEN for more details. */
#define SYSCON_SRAM_XEN_DP_RAMB3_XEN_DP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SRAM_XEN_DP_RAMB3_XEN_DP_SHIFT)) & SYSCON_SRAM_XEN_DP_RAMB3_XEN_DP_MASK)
/*! @} */

/*! @name CSS_BOOT_STATE_LOCK - CSS Boot State Lock Down */
/*! @{ */

#define SYSCON_CSS_BOOT_STATE_LOCK_BOOT_STATE_LOCK_MASK (0xFU)
#define SYSCON_CSS_BOOT_STATE_LOCK_BOOT_STATE_LOCK_SHIFT (0U)
/*! BOOT_STATE_LOCK - Boot state lock down bit */
#define SYSCON_CSS_BOOT_STATE_LOCK_BOOT_STATE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_CSS_BOOT_STATE_LOCK_BOOT_STATE_LOCK_SHIFT)) & SYSCON_CSS_BOOT_STATE_LOCK_BOOT_STATE_LOCK_MASK)
/*! @} */

/*! @name DEBUG_LOCK_EN - Control Write Access to Security */
/*! @{ */

#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK       (0xFU)
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT      (0U)
/*! LOCK_ALL - Controls write access to the security registers
 *  0b0000..Any other value than b1010: disables write access to all registers
 *  0b1010..1010: Enables write access to all registers
 */
#define SYSCON_DEBUG_LOCK_EN_LOCK_ALL(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT)) & SYSCON_DEBUG_LOCK_EN_LOCK_ALL_MASK)
/*! @} */

/*! @name DEBUG_FEATURES - Cortex Debug Features Control */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_CM33_DBGEN_MASK    (0x3U)
#define SYSCON_DEBUG_FEATURES_CM33_DBGEN_SHIFT   (0U)
/*! CM33_DBGEN - CM33 invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Disables debug
 */
#define SYSCON_DEBUG_FEATURES_CM33_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CM33_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CM33_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_CM33_NIDEN_MASK    (0xCU)
#define SYSCON_DEBUG_FEATURES_CM33_NIDEN_SHIFT   (2U)
/*! CM33_NIDEN - CM33 non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Disables debug
 */
#define SYSCON_DEBUG_FEATURES_CM33_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CM33_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CM33_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CM33_SPIDEN_MASK   (0x30U)
#define SYSCON_DEBUG_FEATURES_CM33_SPIDEN_SHIFT  (4U)
/*! CM33_SPIDEN - CM33 secure privileged invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CM33_SPIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CM33_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CM33_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_CM33_SPNIDEN_MASK  (0xC0U)
#define SYSCON_DEBUG_FEATURES_CM33_SPNIDEN_SHIFT (6U)
/*! CM33_SPNIDEN - CM33 secure privileged non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_CM33_SPNIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_CM33_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_CM33_SPNIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM0P_SEL_MASK (0x3000000U)
#define SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM0P_SEL_SHIFT (24U)
/*! IPG_DEBUGEN_CM0P_SEL - IPG Debug CM0+ Enable Control
 *  0b00..CM0+ IPG debug disable
 *  0b01..CM0+ IPG debug disable
 *  0b10..CM0+ IPG debug enable
 *  0b11..CM0+ IPG debug disable
 */
#define SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM0P_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM0P_SEL_SHIFT)) & SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM0P_SEL_MASK)

#define SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM33_SEL_MASK (0xC000000U)
#define SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM33_SEL_SHIFT (26U)
/*! IPG_DEBUGEN_CM33_SEL - IPG Debug CM33 Enable Control
 *  0b00..CM33 IPG debug disable
 *  0b01..CM33 IPG debug disable
 *  0b10..CM33 IPG debug enable
 *  0b11..CM33 IPG debug disable
 */
#define SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM33_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM33_SEL_SHIFT)) & SYSCON_DEBUG_FEATURES_IPG_DEBUGEN_CM33_SEL_MASK)
/*! @} */

/*! @name DEBUG_FEATURES_DP - Cortex Debug Features Control (Duplicate) */
/*! @{ */

#define SYSCON_DEBUG_FEATURES_DP_CM33_DBGEN_MASK (0x3U)
#define SYSCON_DEBUG_FEATURES_DP_CM33_DBGEN_SHIFT (0U)
/*! CM33_DBGEN - CM33 invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Disables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CM33_DBGEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CM33_DBGEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CM33_DBGEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CM33_NIDEN_MASK (0xCU)
#define SYSCON_DEBUG_FEATURES_DP_CM33_NIDEN_SHIFT (2U)
/*! CM33_NIDEN - CM33 non-invasive debug control
 *  0b00..Disables debug
 *  0b01..Disables debug
 *  0b10..Enables debug
 *  0b11..Disables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CM33_NIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CM33_NIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CM33_NIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CM33_SPIDEN_MASK (0x30U)
#define SYSCON_DEBUG_FEATURES_DP_CM33_SPIDEN_SHIFT (4U)
/*! CM33_SPIDEN - CM33 secure privileged invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CM33_SPIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CM33_SPIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CM33_SPIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_CM33_SPNIDEN_MASK (0xC0U)
#define SYSCON_DEBUG_FEATURES_DP_CM33_SPNIDEN_SHIFT (6U)
/*! CM33_SPNIDEN - CM33 secure privileged non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SYSCON_DEBUG_FEATURES_DP_CM33_SPNIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_CM33_SPNIDEN_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_CM33_SPNIDEN_MASK)

#define SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM0P_SEL_MASK (0x3000000U)
#define SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM0P_SEL_SHIFT (24U)
/*! IPG_DEBUGEN_CM0P_SEL - IPG Debug CM0+ Enable Control
 *  0b00..CM0+ IPG debug disable
 *  0b01..CM0+ IPG debug disable
 *  0b10..CM0+ IPG debug enable
 *  0b11..CM0+ IPG debug disable
 */
#define SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM0P_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM0P_SEL_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM0P_SEL_MASK)

#define SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM33_SEL_MASK (0xC000000U)
#define SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM33_SEL_SHIFT (26U)
/*! IPG_DEBUGEN_CM33_SEL - IPG Debug CM33 Enable Control
 *  0b00..CM33 IPG debug disable
 *  0b01..CM33 IPG debug disable
 *  0b10..CM33 IPG debug enable
 *  0b11..CM33 IPG debug disable
 */
#define SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM33_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM33_SEL_SHIFT)) & SYSCON_DEBUG_FEATURES_DP_IPG_DEBUGEN_CM33_SEL_MASK)
/*! @} */

/*! @name SWD_ACCESS_CM33 - CM33 Software Debug Access */
/*! @{ */

#define SYSCON_SWD_ACCESS_CM33_SEC_CODE_MASK     (0xFFFFFFFFU)
#define SYSCON_SWD_ACCESS_CM33_SEC_CODE_SHIFT    (0U)
/*! SEC_CODE - CM33 SWD-AP: 0x12345678
 *  0b00000000000000000000000000000000..CM33 DAP is not allowed. Reading back register is read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable CM33 SWD access. Reading back register is read as 0xA.
 */
#define SYSCON_SWD_ACCESS_CM33_SEC_CODE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_SWD_ACCESS_CM33_SEC_CODE_SHIFT)) & SYSCON_SWD_ACCESS_CM33_SEC_CODE_MASK)
/*! @} */

/*! @name DEBUG_AUTH_BEACON - Debug Authentication BEACON */
/*! @{ */

#define SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK     (0xFFFFFFFFU)
#define SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT    (0U)
/*! BEACON - Sets by the debug authentication code in ROM to pass the debug beacons (Credential
 *    Beacon and Authentication Beacon) to the application code.
 */
#define SYSCON_DEBUG_AUTH_BEACON_BEACON(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEBUG_AUTH_BEACON_BEACON_SHIFT)) & SYSCON_DEBUG_AUTH_BEACON_BEACON_MASK)
/*! @} */

/*! @name JTAG_ID - JTAG Chip ID */
/*! @{ */

#define SYSCON_JTAG_ID_JTAG_ID_MASK              (0xFFFFFFFFU)
#define SYSCON_JTAG_ID_JTAG_ID_SHIFT             (0U)
/*! JTAG_ID - Indicates the JTAG Chip ID */
#define SYSCON_JTAG_ID_JTAG_ID(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAG_ID_JTAG_ID_SHIFT)) & SYSCON_JTAG_ID_JTAG_ID_MASK)
/*! @} */

/*! @name DEVICE_TYPE - Device Type */
/*! @{ */

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_MASK      (0xFFFFFFFFU)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SHIFT     (0U)
/*! DEVICE_TYPE - Indicates the device type */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK     (0xF00000U)
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT    (20U)
/*! ROM_REV_MINOR - ROM revision. */
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT)) & SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK)
/*! @} */

/*! @name DIEID - Chip Revision ID and Number */
/*! @{ */

#define SYSCON_DIEID_Minor_Rev_MASK              (0xFU)
#define SYSCON_DIEID_Minor_Rev_SHIFT             (0U)
/*! Minor_Rev - Chip metal revision ID */
#define SYSCON_DIEID_Minor_Rev(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_Minor_Rev_SHIFT)) & SYSCON_DIEID_Minor_Rev_MASK)

#define SYSCON_DIEID_Major_Rev_MASK              (0xF0U)
#define SYSCON_DIEID_Major_Rev_SHIFT             (4U)
/*! Major_Rev - Chip metal Layer */
#define SYSCON_DIEID_Major_Rev(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_DIEID_Major_Rev_SHIFT)) & SYSCON_DIEID_Major_Rev_MASK)

#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_MASK      (0xFFFFF00U)
#define SYSCON_DIEID_MCO_NUM_IN_DIE_ID_SHIFT     (8U)
/*! MCO_NUM_IN_DIE_ID - Chip number */
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

