/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON1
 *
 * CMSIS Peripheral Access Layer for SYSCON1
 */

#if !defined(PERI_SYSCON1_H_)
#define PERI_SYSCON1_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- SYSCON1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON1_Peripheral_Access_Layer SYSCON1 Peripheral Access Layer
 * @{
 */

/** SYSCON1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[20];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER Global Start Enable, offset: 0x1C */
       uint8_t RESERVED_2[88];
  __IO uint32_t AHBMATPRIO;                        /**< Bus Matrix Priority, offset: 0x78 */
       uint8_t RESERVED_3[20];
  __IO uint32_t SYSTEM_STICK_CALIB;                /**< System Secure Tick Calibration, offset: 0x90 */
  __IO uint32_t SYSTEM_NSTICK_CALIB;               /**< System Non-Secure Tick Calibration, offset: 0x94 */
       uint8_t RESERVED_4[56];
  __IO uint32_t GPIO_PSYNC;                        /**< GPIO Synchronization Stages, offset: 0xD0 */
       uint8_t RESERVED_5[112];
  __IO uint32_t EDMA2_MEM_CTRL;                    /**< eDMA2 Memory Control, offset: 0x144 */
  __IO uint32_t EDMA3_MEM_CTRL;                    /**< eDMA3 Memory Control, offset: 0x148 */
       uint8_t RESERVED_6[244];
  __IO uint32_t SAI3_MCLK_CTRL;                    /**< SAI3 MCLK IO Direction Control, offset: 0x240 */
       uint8_t RESERVED_7[76];
  __IO uint32_t SENSE_DEBUG_HALTED_SEL;            /**< VDD1_SENSE Debug Halted Select, offset: 0x290 */
       uint8_t RESERVED_8[108];
  __IO uint32_t DSPSTALL;                          /**< HiFi1 DSP Stall, offset: 0x300 */
  __IO uint32_t OCDHALTONRESET;                    /**< HiFi1 OCDHaltOnReset, offset: 0x304 */
  __I  uint32_t HIFI1_GPR0;                        /**< HiFi1 General Purpose Register 0, offset: 0x308 */
       uint8_t RESERVED_9[8];
  __I  uint32_t HIFI1_GPR1;                        /**< HiFi1 General Purpose Register 1, offset: 0x314 */
  __I  uint32_t HIFI1_GPR2;                        /**< HiFi1 General Purpose Register 2, offset: 0x318 */
  __IO uint32_t DSP_VECT_REMAP;                    /**< HiFi1 DSP Vector Remap, offset: 0x31C */
       uint8_t RESERVED_10[256];
  __IO uint32_t EDMA2_EN0;                         /**< eDMA2 Request Enable 0, offset: 0x420 */
  __IO uint32_t EDMA2_EN1;                         /**< eDMA2 Request Enable 1, offset: 0x424 */
       uint8_t RESERVED_11[8];
  __IO uint32_t EDMA3_EN0;                         /**< eDMA3 Request Enable 0, offset: 0x430 */
  __IO uint32_t EDMA3_EN1;                         /**< eDMA3 Request Enable 1, offset: 0x434 */
       uint8_t RESERVED_12[496];
  __IO uint32_t I3C_ASYNC_WAKEUP_CTRL;             /**< I3C Asynchronous Wake-up Control, offset: 0x628 */
} SYSCON1_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON1_Register_Masks SYSCON1 Register Masks
 * @{
 */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON1_NMISRC_IRQCPU1_MASK              (0xFFU)
#define SYSCON1_NMISRC_IRQCPU1_SHIFT             (0U)
/*! IRQCPU1 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for CPU1, if enabled by NMIENCPU1 */
#define SYSCON1_NMISRC_IRQCPU1(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON1_NMISRC_IRQCPU1_SHIFT)) & SYSCON1_NMISRC_IRQCPU1_MASK)

#define SYSCON1_NMISRC_NMIENCPU1_MASK            (0x80000000U)
#define SYSCON1_NMISRC_NMIENCPU1_SHIFT           (31U)
/*! NMIENCPU1 - Enables the Non-Maskable Interrupt (NMI) source selected by IRQCPU1
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_NMISRC_NMIENCPU1(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON1_NMISRC_NMIENCPU1_SHIFT)) & SYSCON1_NMISRC_NMIENCPU1_MASK)
/*! @} */

/*! @name CTIMERGLOBALSTARTEN - CTIMER Global Start Enable */
/*! @{ */

#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK (0x1U)
#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT (0U)
/*! CTIMER0_CLK_EN - CTIMER5 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT)) & SYSCON1_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK)

#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK (0x2U)
#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT (1U)
/*! CTIMER1_CLK_EN - CTIMER6 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT)) & SYSCON1_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK)

#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK (0x4U)
#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT (2U)
/*! CTIMER2_CLK_EN - CTIMER7 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT)) & SYSCON1_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK)
/*! @} */

/*! @name AHBMATPRIO - Bus Matrix Priority */
/*! @{ */

#define SYSCON1_AHBMATPRIO_SBUS_M0_MASK          (0x3U)
#define SYSCON1_AHBMATPRIO_SBUS_M0_SHIFT         (0U)
/*! SBUS_M0 - S-Bus M0 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON1_AHBMATPRIO_SBUS_M0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON1_AHBMATPRIO_SBUS_M0_SHIFT)) & SYSCON1_AHBMATPRIO_SBUS_M0_MASK)

#define SYSCON1_AHBMATPRIO_SBUS_M1_MASK          (0xCU)
#define SYSCON1_AHBMATPRIO_SBUS_M1_SHIFT         (2U)
/*! SBUS_M1 - S-Bus M1 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON1_AHBMATPRIO_SBUS_M1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON1_AHBMATPRIO_SBUS_M1_SHIFT)) & SYSCON1_AHBMATPRIO_SBUS_M1_MASK)

#define SYSCON1_AHBMATPRIO_SBUS_M2_MASK          (0x30U)
#define SYSCON1_AHBMATPRIO_SBUS_M2_SHIFT         (4U)
/*! SBUS_M2 - S-Bus M2 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON1_AHBMATPRIO_SBUS_M2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON1_AHBMATPRIO_SBUS_M2_SHIFT)) & SYSCON1_AHBMATPRIO_SBUS_M2_MASK)

#define SYSCON1_AHBMATPRIO_SBUS_M3_MASK          (0xC0U)
#define SYSCON1_AHBMATPRIO_SBUS_M3_SHIFT         (6U)
/*! SBUS_M3 - S-Bus M3 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON1_AHBMATPRIO_SBUS_M3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON1_AHBMATPRIO_SBUS_M3_SHIFT)) & SYSCON1_AHBMATPRIO_SBUS_M3_MASK)

#define SYSCON1_AHBMATPRIO_SBUS_M4_MASK          (0x300U)
#define SYSCON1_AHBMATPRIO_SBUS_M4_SHIFT         (8U)
/*! SBUS_M4 - S-Bus M4 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON1_AHBMATPRIO_SBUS_M4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON1_AHBMATPRIO_SBUS_M4_SHIFT)) & SYSCON1_AHBMATPRIO_SBUS_M4_MASK)

#define SYSCON1_AHBMATPRIO_SBUS_M5_MASK          (0xC00U)
#define SYSCON1_AHBMATPRIO_SBUS_M5_SHIFT         (10U)
/*! SBUS_M5 - S-Bus M5 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON1_AHBMATPRIO_SBUS_M5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON1_AHBMATPRIO_SBUS_M5_SHIFT)) & SYSCON1_AHBMATPRIO_SBUS_M5_MASK)
/*! @} */

/*! @name SYSTEM_STICK_CALIB - System Secure Tick Calibration */
/*! @{ */

#define SYSCON1_SYSTEM_STICK_CALIB_TENMS_MASK    (0xFFFFFFU)
#define SYSCON1_SYSTEM_STICK_CALIB_TENMS_SHIFT   (0U)
/*! TENMS - Ten Milliseconds */
#define SYSCON1_SYSTEM_STICK_CALIB_TENMS(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_SYSTEM_STICK_CALIB_TENMS_SHIFT)) & SYSCON1_SYSTEM_STICK_CALIB_TENMS_MASK)

#define SYSCON1_SYSTEM_STICK_CALIB_SKEW_MASK     (0x1000000U)
#define SYSCON1_SYSTEM_STICK_CALIB_SKEW_SHIFT    (24U)
/*! SKEW - SKEW
 *  0b0..Exact
 *  0b1..Inexact, or not given
 */
#define SYSCON1_SYSTEM_STICK_CALIB_SKEW(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_SYSTEM_STICK_CALIB_SKEW_SHIFT)) & SYSCON1_SYSTEM_STICK_CALIB_SKEW_MASK)

#define SYSCON1_SYSTEM_STICK_CALIB_NOREF_MASK    (0x2000000U)
#define SYSCON1_SYSTEM_STICK_CALIB_NOREF_SHIFT   (25U)
/*! NOREF - No Reference Clock
 *  0b0..Provides
 *  0b1..Not provide
 */
#define SYSCON1_SYSTEM_STICK_CALIB_NOREF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_SYSTEM_STICK_CALIB_NOREF_SHIFT)) & SYSCON1_SYSTEM_STICK_CALIB_NOREF_MASK)
/*! @} */

/*! @name SYSTEM_NSTICK_CALIB - System Non-Secure Tick Calibration */
/*! @{ */

#define SYSCON1_SYSTEM_NSTICK_CALIB_TENMS_MASK   (0xFFFFFFU)
#define SYSCON1_SYSTEM_NSTICK_CALIB_TENMS_SHIFT  (0U)
/*! TENMS - Ten Milliseconds */
#define SYSCON1_SYSTEM_NSTICK_CALIB_TENMS(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON1_SYSTEM_NSTICK_CALIB_TENMS_SHIFT)) & SYSCON1_SYSTEM_NSTICK_CALIB_TENMS_MASK)

#define SYSCON1_SYSTEM_NSTICK_CALIB_SKEW_MASK    (0x1000000U)
#define SYSCON1_SYSTEM_NSTICK_CALIB_SKEW_SHIFT   (24U)
/*! SKEW - SKEW
 *  0b0..Exact
 *  0b1..Inexact, or not given
 */
#define SYSCON1_SYSTEM_NSTICK_CALIB_SKEW(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_SYSTEM_NSTICK_CALIB_SKEW_SHIFT)) & SYSCON1_SYSTEM_NSTICK_CALIB_SKEW_MASK)

#define SYSCON1_SYSTEM_NSTICK_CALIB_NOREF_MASK   (0x2000000U)
#define SYSCON1_SYSTEM_NSTICK_CALIB_NOREF_SHIFT  (25U)
/*! NOREF - No Reference Clock
 *  0b0..Provides
 *  0b1..Not provide
 */
#define SYSCON1_SYSTEM_NSTICK_CALIB_NOREF(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON1_SYSTEM_NSTICK_CALIB_NOREF_SHIFT)) & SYSCON1_SYSTEM_NSTICK_CALIB_NOREF_MASK)
/*! @} */

/*! @name GPIO_PSYNC - GPIO Synchronization Stages */
/*! @{ */

#define SYSCON1_GPIO_PSYNC_PSYNC_MASK            (0x1U)
#define SYSCON1_GPIO_PSYNC_PSYNC_SHIFT           (0U)
/*! PSYNC - Synchronization Stage Setting
 *  0b0..2-stage sync
 *  0b1..1-stage sync
 */
#define SYSCON1_GPIO_PSYNC_PSYNC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON1_GPIO_PSYNC_PSYNC_SHIFT)) & SYSCON1_GPIO_PSYNC_PSYNC_MASK)
/*! @} */

/*! @name EDMA2_MEM_CTRL - eDMA2 Memory Control */
/*! @{ */

#define SYSCON1_EDMA2_MEM_CTRL_PWR_STDBY_MASK    (0x80U)
#define SYSCON1_EDMA2_MEM_CTRL_PWR_STDBY_SHIFT   (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON1_EDMA2_MEM_CTRL_PWR_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON1_EDMA2_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON1_EDMA2_MEM_CTRL_PWR_IG_MASK       (0x100U)
#define SYSCON1_EDMA2_MEM_CTRL_PWR_IG_SHIFT      (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON1_EDMA2_MEM_CTRL_PWR_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON1_EDMA2_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name EDMA3_MEM_CTRL - eDMA3 Memory Control */
/*! @{ */

#define SYSCON1_EDMA3_MEM_CTRL_PWR_STDBY_MASK    (0x80U)
#define SYSCON1_EDMA3_MEM_CTRL_PWR_STDBY_SHIFT   (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON1_EDMA3_MEM_CTRL_PWR_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON1_EDMA3_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON1_EDMA3_MEM_CTRL_PWR_IG_MASK       (0x100U)
#define SYSCON1_EDMA3_MEM_CTRL_PWR_IG_SHIFT      (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON1_EDMA3_MEM_CTRL_PWR_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON1_EDMA3_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name SAI3_MCLK_CTRL - SAI3 MCLK IO Direction Control */
/*! @{ */

#define SYSCON1_SAI3_MCLK_CTRL_SAIMCLKDIR_MASK   (0x1U)
#define SYSCON1_SAI3_MCLK_CTRL_SAIMCLKDIR_SHIFT  (0U)
/*! SAIMCLKDIR - SAI3 MCLK Direction Control
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCON1_SAI3_MCLK_CTRL_SAIMCLKDIR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON1_SAI3_MCLK_CTRL_SAIMCLKDIR_SHIFT)) & SYSCON1_SAI3_MCLK_CTRL_SAIMCLKDIR_MASK)
/*! @} */

/*! @name SENSE_DEBUG_HALTED_SEL - VDD1_SENSE Debug Halted Select */
/*! @{ */

#define SYSCON1_SENSE_DEBUG_HALTED_SEL_WWDT3_SEL_MASK (0x1U)
#define SYSCON1_SENSE_DEBUG_HALTED_SEL_WWDT3_SEL_SHIFT (0U)
/*! WWDT3_SEL - WWDT3 Select
 *  0b0..XOCD mode from HiFi1 will be used for WWDT3
 *  0b1..HALTED from CPU1 will be used for WWDT3
 */
#define SYSCON1_SENSE_DEBUG_HALTED_SEL_WWDT3_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_SENSE_DEBUG_HALTED_SEL_WWDT3_SEL_SHIFT)) & SYSCON1_SENSE_DEBUG_HALTED_SEL_WWDT3_SEL_MASK)

#define SYSCON1_SENSE_DEBUG_HALTED_SEL_CDOG4_SEL_MASK (0x2U)
#define SYSCON1_SENSE_DEBUG_HALTED_SEL_CDOG4_SEL_SHIFT (1U)
/*! CDOG4_SEL - CDOG4 Select
 *  0b0..XOCD mode from HiFi1 will be used for CDOG4
 *  0b1..HALTED from CPU1 will be used for CDOG4
 */
#define SYSCON1_SENSE_DEBUG_HALTED_SEL_CDOG4_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_SENSE_DEBUG_HALTED_SEL_CDOG4_SEL_SHIFT)) & SYSCON1_SENSE_DEBUG_HALTED_SEL_CDOG4_SEL_MASK)
/*! @} */

/*! @name DSPSTALL - HiFi1 DSP Stall */
/*! @{ */

#define SYSCON1_DSPSTALL_DSPSTALL_MASK           (0x1U)
#define SYSCON1_DSPSTALL_DSPSTALL_SHIFT          (0U)
/*! DSPSTALL - Run/Stall Control
 *  0b0..Run (normal mode)
 *  0b1..Stall mode
 */
#define SYSCON1_DSPSTALL_DSPSTALL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON1_DSPSTALL_DSPSTALL_SHIFT)) & SYSCON1_DSPSTALL_DSPSTALL_MASK)
/*! @} */

/*! @name OCDHALTONRESET - HiFi1 OCDHaltOnReset */
/*! @{ */

#define SYSCON1_OCDHALTONRESET_OCDHALTONRESET_MASK (0x1U)
#define SYSCON1_OCDHALTONRESET_OCDHALTONRESET_SHIFT (0U)
/*! OCDHALTONRESET - OCDHaltOnReset
 *  0b0..Allow normal operation when HiFi1 exits reset (starts fetching and executing instructions from memory)
 *  0b1..Force HiFi1 to enter OCD Halt mode when HiFi1 exits reset
 */
#define SYSCON1_OCDHALTONRESET_OCDHALTONRESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_OCDHALTONRESET_OCDHALTONRESET_SHIFT)) & SYSCON1_OCDHALTONRESET_OCDHALTONRESET_MASK)
/*! @} */

/*! @name HIFI1_GPR0 - HiFi1 General Purpose Register 0 */
/*! @{ */

#define SYSCON1_HIFI1_GPR0_PFAULTINFOVLD_MASK    (0x1U)
#define SYSCON1_HIFI1_GPR0_PFAULTINFOVLD_SHIFT   (0U)
/*! PFAULTINFOVLD - PFaultInfoValid
 *  0b0..Not asserted
 *  0b1..Asserted
 */
#define SYSCON1_HIFI1_GPR0_PFAULTINFOVLD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_HIFI1_GPR0_PFAULTINFOVLD_SHIFT)) & SYSCON1_HIFI1_GPR0_PFAULTINFOVLD_MASK)

#define SYSCON1_HIFI1_GPR0_PFATALERR_MASK        (0x2U)
#define SYSCON1_HIFI1_GPR0_PFATALERR_SHIFT       (1U)
/*! PFATALERR - PFatalError
 *  0b0..No error occurs
 *  0b1..Error occurs
 */
#define SYSCON1_HIFI1_GPR0_PFATALERR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_HIFI1_GPR0_PFATALERR_SHIFT)) & SYSCON1_HIFI1_GPR0_PFATALERR_MASK)

#define SYSCON1_HIFI1_GPR0_EXCEPTIONERR_MASK     (0x4U)
#define SYSCON1_HIFI1_GPR0_EXCEPTIONERR_SHIFT    (2U)
/*! EXCEPTIONERR - DoubleExceptionError
 *  0b0..No error occurs
 *  0b1..Error occurs
 */
#define SYSCON1_HIFI1_GPR0_EXCEPTIONERR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_HIFI1_GPR0_EXCEPTIONERR_SHIFT)) & SYSCON1_HIFI1_GPR0_EXCEPTIONERR_MASK)
/*! @} */

/*! @name HIFI1_GPR1 - HiFi1 General Purpose Register 1 */
/*! @{ */

#define SYSCON1_HIFI1_GPR1_PFAULTINFO_MASK       (0xFFFFFFFFU)
#define SYSCON1_HIFI1_GPR1_PFAULTINFO_SHIFT      (0U)
/*! PFAULTINFO - PFaultInfo */
#define SYSCON1_HIFI1_GPR1_PFAULTINFO(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_HIFI1_GPR1_PFAULTINFO_SHIFT)) & SYSCON1_HIFI1_GPR1_PFAULTINFO_MASK)
/*! @} */

/*! @name HIFI1_GPR2 - HiFi1 General Purpose Register 2 */
/*! @{ */

#define SYSCON1_HIFI1_GPR2_TIE_EXPSTATE_MASK     (0xFFFFFFFFU)
#define SYSCON1_HIFI1_GPR2_TIE_EXPSTATE_SHIFT    (0U)
/*! TIE_EXPSTATE - GPIO32 Option TIE Output State */
#define SYSCON1_HIFI1_GPR2_TIE_EXPSTATE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_HIFI1_GPR2_TIE_EXPSTATE_SHIFT)) & SYSCON1_HIFI1_GPR2_TIE_EXPSTATE_MASK)
/*! @} */

/*! @name DSP_VECT_REMAP - HiFi1 DSP Vector Remap */
/*! @{ */

#define SYSCON1_DSP_VECT_REMAP_DSP_VECT_REMAP_MASK (0xFFFU)
#define SYSCON1_DSP_VECT_REMAP_DSP_VECT_REMAP_SHIFT (0U)
/*! DSP_VECT_REMAP - DSP Vector Remap */
#define SYSCON1_DSP_VECT_REMAP_DSP_VECT_REMAP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_DSP_VECT_REMAP_DSP_VECT_REMAP_SHIFT)) & SYSCON1_DSP_VECT_REMAP_DSP_VECT_REMAP_MASK)

#define SYSCON1_DSP_VECT_REMAP_STATVECSELECT_MASK (0x1000U)
#define SYSCON1_DSP_VECT_REMAP_STATVECSELECT_SHIFT (12U)
/*! STATVECSELECT - Static Vector Select
 *  0b0..0058_0000h to another address in RAM0
 *  0b1..0060_0000h to another address in RAM1
 */
#define SYSCON1_DSP_VECT_REMAP_STATVECSELECT(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON1_DSP_VECT_REMAP_STATVECSELECT_SHIFT)) & SYSCON1_DSP_VECT_REMAP_STATVECSELECT_MASK)
/*! @} */

/*! @name EDMA2_EN0 - eDMA2 Request Enable 0 */
/*! @{ */

#define SYSCON1_EDMA2_EN0_MICFIL_EN_MASK         (0x2U)
#define SYSCON1_EDMA2_EN0_MICFIL_EN_SHIFT        (1U)
/*! MICFIL_EN - MICFIL Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_MICFIL_EN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_MICFIL_EN_SHIFT)) & SYSCON1_EDMA2_EN0_MICFIL_EN_MASK)

#define SYSCON1_EDMA2_EN0_XSPI2_RX_EN_MASK       (0x4U)
#define SYSCON1_EDMA2_EN0_XSPI2_RX_EN_SHIFT      (2U)
/*! XSPI2_RX_EN - XSPI2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_XSPI2_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_XSPI2_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN0_XSPI2_RX_EN_MASK)

#define SYSCON1_EDMA2_EN0_XSPI2_TX_EN_MASK       (0x8U)
#define SYSCON1_EDMA2_EN0_XSPI2_TX_EN_SHIFT      (3U)
/*! XSPI2_TX_EN - XSPI2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_XSPI2_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_XSPI2_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN0_XSPI2_TX_EN_MASK)

#define SYSCON1_EDMA2_EN0_PINT1_IRQ0_EN_MASK     (0x10U)
#define SYSCON1_EDMA2_EN0_PINT1_IRQ0_EN_SHIFT    (4U)
/*! PINT1_IRQ0_EN - PINT1 Interrupt 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_PINT1_IRQ0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_PINT1_IRQ0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_PINT1_IRQ0_EN_MASK)

#define SYSCON1_EDMA2_EN0_PINT1_IRQ1_EN_MASK     (0x20U)
#define SYSCON1_EDMA2_EN0_PINT1_IRQ1_EN_SHIFT    (5U)
/*! PINT1_IRQ1_EN - PINT1 Interrupt 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_PINT1_IRQ1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_PINT1_IRQ1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_PINT1_IRQ1_EN_MASK)

#define SYSCON1_EDMA2_EN0_PINT1_IRQ2_EN_MASK     (0x40U)
#define SYSCON1_EDMA2_EN0_PINT1_IRQ2_EN_SHIFT    (6U)
/*! PINT1_IRQ2_EN - PINT1 Interrupt 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_PINT1_IRQ2_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_PINT1_IRQ2_EN_SHIFT)) & SYSCON1_EDMA2_EN0_PINT1_IRQ2_EN_MASK)

#define SYSCON1_EDMA2_EN0_PINT1_IRQ3_EN_MASK     (0x80U)
#define SYSCON1_EDMA2_EN0_PINT1_IRQ3_EN_SHIFT    (7U)
/*! PINT1_IRQ3_EN - PINT1 Interrupt 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_PINT1_IRQ3_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_PINT1_IRQ3_EN_SHIFT)) & SYSCON1_EDMA2_EN0_PINT1_IRQ3_EN_MASK)

#define SYSCON1_EDMA2_EN0_CTIMER5_M0_EN_MASK     (0x100U)
#define SYSCON1_EDMA2_EN0_CTIMER5_M0_EN_SHIFT    (8U)
/*! CTIMER5_M0_EN - CTIMER5 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_CTIMER5_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_CTIMER5_M0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_CTIMER5_M0_EN_MASK)

#define SYSCON1_EDMA2_EN0_CTIMER5_M1_EN_MASK     (0x200U)
#define SYSCON1_EDMA2_EN0_CTIMER5_M1_EN_SHIFT    (9U)
/*! CTIMER5_M1_EN - CTIMER5 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_CTIMER5_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_CTIMER5_M1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_CTIMER5_M1_EN_MASK)

#define SYSCON1_EDMA2_EN0_CTIMER6_M0_EN_MASK     (0x400U)
#define SYSCON1_EDMA2_EN0_CTIMER6_M0_EN_SHIFT    (10U)
/*! CTIMER6_M0_EN - CTIMER6 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_CTIMER6_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_CTIMER6_M0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_CTIMER6_M0_EN_MASK)

#define SYSCON1_EDMA2_EN0_CTIMER6_M1_EN_MASK     (0x800U)
#define SYSCON1_EDMA2_EN0_CTIMER6_M1_EN_SHIFT    (11U)
/*! CTIMER6_M1_EN - CTIMER6 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_CTIMER6_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_CTIMER6_M1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_CTIMER6_M1_EN_MASK)

#define SYSCON1_EDMA2_EN0_CTIMER7_M0_EN_MASK     (0x1000U)
#define SYSCON1_EDMA2_EN0_CTIMER7_M0_EN_SHIFT    (12U)
/*! CTIMER7_M0_EN - CTIMER7 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_CTIMER7_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_CTIMER7_M0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_CTIMER7_M0_EN_MASK)

#define SYSCON1_EDMA2_EN0_CTIMER7_M1_EN_MASK     (0x2000U)
#define SYSCON1_EDMA2_EN0_CTIMER7_M1_EN_SHIFT    (13U)
/*! CTIMER7_M1_EN - CTIMER7 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_CTIMER7_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_CTIMER7_M1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_CTIMER7_M1_EN_MASK)

#define SYSCON1_EDMA2_EN0_ADC0_FIFO0_EN_MASK     (0x4000U)
#define SYSCON1_EDMA2_EN0_ADC0_FIFO0_EN_SHIFT    (14U)
/*! ADC0_FIFO0_EN - ADC0 FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_ADC0_FIFO0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_ADC0_FIFO0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_ADC0_FIFO0_EN_MASK)

#define SYSCON1_EDMA2_EN0_ADC0_FIFO1_EN_MASK     (0x8000U)
#define SYSCON1_EDMA2_EN0_ADC0_FIFO1_EN_SHIFT    (15U)
/*! ADC0_FIFO1_EN - ADC0 FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_ADC0_FIFO1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_ADC0_FIFO1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_ADC0_FIFO1_EN_MASK)

#define SYSCON1_EDMA2_EN0_SDADC_FIFO0_EN_MASK    (0x10000U)
#define SYSCON1_EDMA2_EN0_SDADC_FIFO0_EN_SHIFT   (16U)
/*! SDADC_FIFO0_EN - SDADC FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_SDADC_FIFO0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_SDADC_FIFO0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_SDADC_FIFO0_EN_MASK)

#define SYSCON1_EDMA2_EN0_SDADC_FIFO1_EN_MASK    (0x20000U)
#define SYSCON1_EDMA2_EN0_SDADC_FIFO1_EN_SHIFT   (17U)
/*! SDADC_FIFO1_EN - SDADC FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_SDADC_FIFO1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_SDADC_FIFO1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_SDADC_FIFO1_EN_MASK)

#define SYSCON1_EDMA2_EN0_SDADC_FIFO2_EN_MASK    (0x40000U)
#define SYSCON1_EDMA2_EN0_SDADC_FIFO2_EN_SHIFT   (18U)
/*! SDADC_FIFO2_EN - SDADC FIFO2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_SDADC_FIFO2_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_SDADC_FIFO2_EN_SHIFT)) & SYSCON1_EDMA2_EN0_SDADC_FIFO2_EN_MASK)

#define SYSCON1_EDMA2_EN0_SDADC_FIFO3_EN_MASK    (0x80000U)
#define SYSCON1_EDMA2_EN0_SDADC_FIFO3_EN_SHIFT   (19U)
/*! SDADC_FIFO3_EN - SDADC FIFO3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_SDADC_FIFO3_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_SDADC_FIFO3_EN_SHIFT)) & SYSCON1_EDMA2_EN0_SDADC_FIFO3_EN_MASK)

#define SYSCON1_EDMA2_EN0_ACMP_EN_MASK           (0x100000U)
#define SYSCON1_EDMA2_EN0_ACMP_EN_SHIFT          (20U)
/*! ACMP_EN - ACMP0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_ACMP_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_ACMP_EN_SHIFT)) & SYSCON1_EDMA2_EN0_ACMP_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER0_EN_MASK (0x800000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER0_EN_SHIFT (23U)
/*! FLEXIO_SHFT_TIMER0_EN - FLEXIO Shift Timer 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER0_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER0_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER0_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER1_EN_MASK (0x1000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER1_EN_SHIFT (24U)
/*! FLEXIO_SHFT_TIMER1_EN - FLEXIO Shift Timer 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER1_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER1_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER1_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER2_EN_MASK (0x2000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER2_EN_SHIFT (25U)
/*! FLEXIO_SHFT_TIMER2_EN - FLEXIO Shift Timer 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER2_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER2_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER2_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER3_EN_MASK (0x4000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER3_EN_SHIFT (26U)
/*! FLEXIO_SHFT_TIMER3_EN - FLEXIO Shift Timer 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER3_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER3_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER3_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER4_EN_MASK (0x8000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER4_EN_SHIFT (27U)
/*! FLEXIO_SHFT_TIMER4_EN - FLEXIO Shift Timer 4 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER4_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER4_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER4_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER5_EN_MASK (0x10000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER5_EN_SHIFT (28U)
/*! FLEXIO_SHFT_TIMER5_EN - FLEXIO Shift Timer 5 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER5_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER5_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER5_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER6_EN_MASK (0x20000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER6_EN_SHIFT (29U)
/*! FLEXIO_SHFT_TIMER6_EN - FLEXIO Shift Timer 6 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER6_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER6_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER6_EN_MASK)

#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER7_EN_MASK (0x40000000U)
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER7_EN_SHIFT (30U)
/*! FLEXIO_SHFT_TIMER7_EN - FLEXIO Shift Timer 7 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER7_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER7_EN_SHIFT)) & SYSCON1_EDMA2_EN0_FLEXIO_SHFT_TIMER7_EN_MASK)

#define SYSCON1_EDMA2_EN0_LP_FLEXCOMM17_RX_EN_MASK (0x80000000U)
#define SYSCON1_EDMA2_EN0_LP_FLEXCOMM17_RX_EN_SHIFT (31U)
/*! LP_FLEXCOMM17_RX_EN - LP_FLEXCOMM17 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN0_LP_FLEXCOMM17_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN0_LP_FLEXCOMM17_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN0_LP_FLEXCOMM17_RX_EN_MASK)
/*! @} */

/*! @name EDMA2_EN1 - eDMA2 Request Enable 1 */
/*! @{ */

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM17_TX_EN_MASK (0x1U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM17_TX_EN_SHIFT (0U)
/*! LP_FLEXCOMM17_TX_EN - LP_FLEXCOMM17 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM17_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM17_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM17_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_RX_EN_MASK (0x2U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_RX_EN_SHIFT (1U)
/*! LP_FLEXCOMM18_RX_EN - LP_FLEXCOMM18 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_TX_EN_MASK (0x4U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_TX_EN_SHIFT (2U)
/*! LP_FLEXCOMM18_TX_EN - LP_FLEXCOMM18 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM18_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_RX_EN_MASK (0x8U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_RX_EN_SHIFT (3U)
/*! LP_FLEXCOMM19_RX_EN - LP_FLEXCOMM19 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_TX_EN_MASK (0x10U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_TX_EN_SHIFT (4U)
/*! LP_FLEXCOMM19_TX_EN - LP_FLEXCOMM19 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM19_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_RX_EN_MASK (0x20U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_RX_EN_SHIFT (5U)
/*! LP_FLEXCOMM20_RX_EN - LP_FLEXCOMM20 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_TX_EN_MASK (0x40U)
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_TX_EN_SHIFT (6U)
/*! LP_FLEXCOMM20_TX_EN - LP_FLEXCOMM20 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LP_FLEXCOMM20_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_I3C2_RX_EN_MASK        (0x80U)
#define SYSCON1_EDMA2_EN1_I3C2_RX_EN_SHIFT       (7U)
/*! I3C2_RX_EN - I3C2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_I3C2_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_I3C2_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_I3C2_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_I3C2_TX_EN_MASK        (0x100U)
#define SYSCON1_EDMA2_EN1_I3C2_TX_EN_SHIFT       (8U)
/*! I3C2_TX_EN - I3C2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_I3C2_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_I3C2_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_I3C2_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_I3C3_RX_EN_MASK        (0x200U)
#define SYSCON1_EDMA2_EN1_I3C3_RX_EN_SHIFT       (9U)
/*! I3C3_RX_EN - I3C3 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_I3C3_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_I3C3_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_I3C3_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_I3C3_TX_EN_MASK        (0x400U)
#define SYSCON1_EDMA2_EN1_I3C3_TX_EN_SHIFT       (10U)
/*! I3C3_TX_EN - I3C3 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_I3C3_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_I3C3_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_I3C3_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_SAI3_RX_EN_MASK        (0x800U)
#define SYSCON1_EDMA2_EN1_SAI3_RX_EN_SHIFT       (11U)
/*! SAI3_RX_EN - SAI3 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_SAI3_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_SAI3_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_SAI3_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_SAI3_TX_EN_MASK        (0x1000U)
#define SYSCON1_EDMA2_EN1_SAI3_TX_EN_SHIFT       (12U)
/*! SAI3_TX_EN - SAI3 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_SAI3_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_SAI3_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_SAI3_TX_EN_MASK)

#define SYSCON1_EDMA2_EN1_GPIO8_DMA0_EN_MASK     (0x2000U)
#define SYSCON1_EDMA2_EN1_GPIO8_DMA0_EN_SHIFT    (13U)
/*! GPIO8_DMA0_EN - GPIO8 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_GPIO8_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_GPIO8_DMA0_EN_SHIFT)) & SYSCON1_EDMA2_EN1_GPIO8_DMA0_EN_MASK)

#define SYSCON1_EDMA2_EN1_GPIO8_DMA1_EN_MASK     (0x4000U)
#define SYSCON1_EDMA2_EN1_GPIO8_DMA1_EN_SHIFT    (14U)
/*! GPIO8_DMA1_EN - GPIO8 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_GPIO8_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_GPIO8_DMA1_EN_SHIFT)) & SYSCON1_EDMA2_EN1_GPIO8_DMA1_EN_MASK)

#define SYSCON1_EDMA2_EN1_GPIO9_DMA0_EN_MASK     (0x8000U)
#define SYSCON1_EDMA2_EN1_GPIO9_DMA0_EN_SHIFT    (15U)
/*! GPIO9_DMA0_EN - GPIO9 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_GPIO9_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_GPIO9_DMA0_EN_SHIFT)) & SYSCON1_EDMA2_EN1_GPIO9_DMA0_EN_MASK)

#define SYSCON1_EDMA2_EN1_GPIO9_DMA1_EN_MASK     (0x10000U)
#define SYSCON1_EDMA2_EN1_GPIO9_DMA1_EN_SHIFT    (16U)
/*! GPIO9_DMA1_EN - GPIO9 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_GPIO9_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_GPIO9_DMA1_EN_SHIFT)) & SYSCON1_EDMA2_EN1_GPIO9_DMA1_EN_MASK)

#define SYSCON1_EDMA2_EN1_GPIO10_DMA0_EN_MASK    (0x20000U)
#define SYSCON1_EDMA2_EN1_GPIO10_DMA0_EN_SHIFT   (17U)
/*! GPIO10_DMA0_EN - GPIO10 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_GPIO10_DMA0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_GPIO10_DMA0_EN_SHIFT)) & SYSCON1_EDMA2_EN1_GPIO10_DMA0_EN_MASK)

#define SYSCON1_EDMA2_EN1_GPIO10_DMA1_EN_MASK    (0x40000U)
#define SYSCON1_EDMA2_EN1_GPIO10_DMA1_EN_SHIFT   (18U)
/*! GPIO10_DMA1_EN - GPIO10 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_GPIO10_DMA1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_GPIO10_DMA1_EN_SHIFT)) & SYSCON1_EDMA2_EN1_GPIO10_DMA1_EN_MASK)

#define SYSCON1_EDMA2_EN1_LPI2C15_RX_EN_MASK     (0x80000U)
#define SYSCON1_EDMA2_EN1_LPI2C15_RX_EN_SHIFT    (19U)
/*! LPI2C15_RX_EN - LPI2C15 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LPI2C15_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LPI2C15_RX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LPI2C15_RX_EN_MASK)

#define SYSCON1_EDMA2_EN1_LPI2C15_TX_EN_MASK     (0x100000U)
#define SYSCON1_EDMA2_EN1_LPI2C15_TX_EN_SHIFT    (20U)
/*! LPI2C15_TX_EN - LPI2C15 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA2_EN1_LPI2C15_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA2_EN1_LPI2C15_TX_EN_SHIFT)) & SYSCON1_EDMA2_EN1_LPI2C15_TX_EN_MASK)
/*! @} */

/*! @name EDMA3_EN0 - eDMA3 Request Enable 0 */
/*! @{ */

#define SYSCON1_EDMA3_EN0_MICFIL_EN_MASK         (0x2U)
#define SYSCON1_EDMA3_EN0_MICFIL_EN_SHIFT        (1U)
/*! MICFIL_EN - MICFIL Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_MICFIL_EN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_MICFIL_EN_SHIFT)) & SYSCON1_EDMA3_EN0_MICFIL_EN_MASK)

#define SYSCON1_EDMA3_EN0_XSPI2_RX_EN_MASK       (0x4U)
#define SYSCON1_EDMA3_EN0_XSPI2_RX_EN_SHIFT      (2U)
/*! XSPI2_RX_EN - XSPI2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_XSPI2_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_XSPI2_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN0_XSPI2_RX_EN_MASK)

#define SYSCON1_EDMA3_EN0_XSPI2_TX_EN_MASK       (0x8U)
#define SYSCON1_EDMA3_EN0_XSPI2_TX_EN_SHIFT      (3U)
/*! XSPI2_TX_EN - XSPI2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_XSPI2_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_XSPI2_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN0_XSPI2_TX_EN_MASK)

#define SYSCON1_EDMA3_EN0_PINT1_IRQ0_EN_MASK     (0x10U)
#define SYSCON1_EDMA3_EN0_PINT1_IRQ0_EN_SHIFT    (4U)
/*! PINT1_IRQ0_EN - PINT1 Interrupt 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_PINT1_IRQ0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_PINT1_IRQ0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_PINT1_IRQ0_EN_MASK)

#define SYSCON1_EDMA3_EN0_PINT1_IRQ1_EN_MASK     (0x20U)
#define SYSCON1_EDMA3_EN0_PINT1_IRQ1_EN_SHIFT    (5U)
/*! PINT1_IRQ1_EN - PINT1 Interrupt 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_PINT1_IRQ1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_PINT1_IRQ1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_PINT1_IRQ1_EN_MASK)

#define SYSCON1_EDMA3_EN0_PINT1_IRQ2_EN_MASK     (0x40U)
#define SYSCON1_EDMA3_EN0_PINT1_IRQ2_EN_SHIFT    (6U)
/*! PINT1_IRQ2_EN - PINT1 Interrupt 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_PINT1_IRQ2_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_PINT1_IRQ2_EN_SHIFT)) & SYSCON1_EDMA3_EN0_PINT1_IRQ2_EN_MASK)

#define SYSCON1_EDMA3_EN0_PINT1_IRQ3_EN_MASK     (0x80U)
#define SYSCON1_EDMA3_EN0_PINT1_IRQ3_EN_SHIFT    (7U)
/*! PINT1_IRQ3_EN - PINT1 Interrupt 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_PINT1_IRQ3_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_PINT1_IRQ3_EN_SHIFT)) & SYSCON1_EDMA3_EN0_PINT1_IRQ3_EN_MASK)

#define SYSCON1_EDMA3_EN0_CTIMER5_M0_EN_MASK     (0x100U)
#define SYSCON1_EDMA3_EN0_CTIMER5_M0_EN_SHIFT    (8U)
/*! CTIMER5_M0_EN - CTIMER5 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_CTIMER5_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_CTIMER5_M0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_CTIMER5_M0_EN_MASK)

#define SYSCON1_EDMA3_EN0_CTIMER5_M1_EN_MASK     (0x200U)
#define SYSCON1_EDMA3_EN0_CTIMER5_M1_EN_SHIFT    (9U)
/*! CTIMER5_M1_EN - CTIMER5 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_CTIMER5_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_CTIMER5_M1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_CTIMER5_M1_EN_MASK)

#define SYSCON1_EDMA3_EN0_CTIMER6_M0_EN_MASK     (0x400U)
#define SYSCON1_EDMA3_EN0_CTIMER6_M0_EN_SHIFT    (10U)
/*! CTIMER6_M0_EN - CTIMER6 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_CTIMER6_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_CTIMER6_M0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_CTIMER6_M0_EN_MASK)

#define SYSCON1_EDMA3_EN0_CTIMER6_M1_EN_MASK     (0x800U)
#define SYSCON1_EDMA3_EN0_CTIMER6_M1_EN_SHIFT    (11U)
/*! CTIMER6_M1_EN - CTIMER6 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_CTIMER6_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_CTIMER6_M1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_CTIMER6_M1_EN_MASK)

#define SYSCON1_EDMA3_EN0_CTIMER7_M0_EN_MASK     (0x1000U)
#define SYSCON1_EDMA3_EN0_CTIMER7_M0_EN_SHIFT    (12U)
/*! CTIMER7_M0_EN - CTIMER7 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_CTIMER7_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_CTIMER7_M0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_CTIMER7_M0_EN_MASK)

#define SYSCON1_EDMA3_EN0_CTIMER7_M1_EN_MASK     (0x2000U)
#define SYSCON1_EDMA3_EN0_CTIMER7_M1_EN_SHIFT    (13U)
/*! CTIMER7_M1_EN - CTIMER7 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_CTIMER7_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_CTIMER7_M1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_CTIMER7_M1_EN_MASK)

#define SYSCON1_EDMA3_EN0_ADC0_FIFO0_EN_MASK     (0x4000U)
#define SYSCON1_EDMA3_EN0_ADC0_FIFO0_EN_SHIFT    (14U)
/*! ADC0_FIFO0_EN - ADC0 FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_ADC0_FIFO0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_ADC0_FIFO0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_ADC0_FIFO0_EN_MASK)

#define SYSCON1_EDMA3_EN0_ADC0_FIFO1_EN_MASK     (0x8000U)
#define SYSCON1_EDMA3_EN0_ADC0_FIFO1_EN_SHIFT    (15U)
/*! ADC0_FIFO1_EN - ADC0 FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_ADC0_FIFO1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_ADC0_FIFO1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_ADC0_FIFO1_EN_MASK)

#define SYSCON1_EDMA3_EN0_SDADC_FIFO0_EN_MASK    (0x10000U)
#define SYSCON1_EDMA3_EN0_SDADC_FIFO0_EN_SHIFT   (16U)
/*! SDADC_FIFO0_EN - SDADC FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_SDADC_FIFO0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_SDADC_FIFO0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_SDADC_FIFO0_EN_MASK)

#define SYSCON1_EDMA3_EN0_SDADC_FIFO1_EN_MASK    (0x20000U)
#define SYSCON1_EDMA3_EN0_SDADC_FIFO1_EN_SHIFT   (17U)
/*! SDADC_FIFO1_EN - SDADC FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_SDADC_FIFO1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_SDADC_FIFO1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_SDADC_FIFO1_EN_MASK)

#define SYSCON1_EDMA3_EN0_SDADC_FIFO2_EN_MASK    (0x40000U)
#define SYSCON1_EDMA3_EN0_SDADC_FIFO2_EN_SHIFT   (18U)
/*! SDADC_FIFO2_EN - SDADC FIFO2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_SDADC_FIFO2_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_SDADC_FIFO2_EN_SHIFT)) & SYSCON1_EDMA3_EN0_SDADC_FIFO2_EN_MASK)

#define SYSCON1_EDMA3_EN0_SDADC_FIFO3_EN_MASK    (0x80000U)
#define SYSCON1_EDMA3_EN0_SDADC_FIFO3_EN_SHIFT   (19U)
/*! SDADC_FIFO3_EN - SDADC FIFO3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_SDADC_FIFO3_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_SDADC_FIFO3_EN_SHIFT)) & SYSCON1_EDMA3_EN0_SDADC_FIFO3_EN_MASK)

#define SYSCON1_EDMA3_EN0_ACMP_EN_MASK           (0x100000U)
#define SYSCON1_EDMA3_EN0_ACMP_EN_SHIFT          (20U)
/*! ACMP_EN - ACMP0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_ACMP_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_ACMP_EN_SHIFT)) & SYSCON1_EDMA3_EN0_ACMP_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER0_EN_MASK (0x800000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER0_EN_SHIFT (23U)
/*! FLEXIO_SHFT_TIMER0_EN - FLEXIO Shift Timer 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER0_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER0_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER0_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER1_EN_MASK (0x1000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER1_EN_SHIFT (24U)
/*! FLEXIO_SHFT_TIMER1_EN - FLEXIO Shift Timer 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER1_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER1_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER1_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER2_EN_MASK (0x2000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER2_EN_SHIFT (25U)
/*! FLEXIO_SHFT_TIMER2_EN - FLEXIO Shift Timer 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER2_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER2_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER2_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER3_EN_MASK (0x4000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER3_EN_SHIFT (26U)
/*! FLEXIO_SHFT_TIMER3_EN - FLEXIO Shift Timer 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER3_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER3_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER3_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER4_EN_MASK (0x8000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER4_EN_SHIFT (27U)
/*! FLEXIO_SHFT_TIMER4_EN - FLEXIO Shift Timer 4 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER4_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER4_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER4_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER5_EN_MASK (0x10000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER5_EN_SHIFT (28U)
/*! FLEXIO_SHFT_TIMER5_EN - FLEXIO Shift Timer 5 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER5_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER5_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER5_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER6_EN_MASK (0x20000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER6_EN_SHIFT (29U)
/*! FLEXIO_SHFT_TIMER6_EN - FLEXIO Shift Timer 6 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER6_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER6_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER6_EN_MASK)

#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER7_EN_MASK (0x40000000U)
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER7_EN_SHIFT (30U)
/*! FLEXIO_SHFT_TIMER7_EN - FLEXIO Shift Timer 7 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER7_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER7_EN_SHIFT)) & SYSCON1_EDMA3_EN0_FLEXIO_SHFT_TIMER7_EN_MASK)

#define SYSCON1_EDMA3_EN0_LP_FLEXCOMM17_RX_EN_MASK (0x80000000U)
#define SYSCON1_EDMA3_EN0_LP_FLEXCOMM17_RX_EN_SHIFT (31U)
/*! LP_FLEXCOMM17_RX_EN - LP_FLEXCOMM17 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN0_LP_FLEXCOMM17_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN0_LP_FLEXCOMM17_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN0_LP_FLEXCOMM17_RX_EN_MASK)
/*! @} */

/*! @name EDMA3_EN1 - eDMA3 Request Enable 1 */
/*! @{ */

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM17_TX_EN_MASK (0x1U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM17_TX_EN_SHIFT (0U)
/*! LP_FLEXCOMM17_TX_EN - LP_FLEXCOMM17 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM17_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM17_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM17_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_RX_EN_MASK (0x2U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_RX_EN_SHIFT (1U)
/*! LP_FLEXCOMM18_RX_EN - LP_FLEXCOMM18 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_TX_EN_MASK (0x4U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_TX_EN_SHIFT (2U)
/*! LP_FLEXCOMM18_TX_EN - LP_FLEXCOMM18 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM18_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_RX_EN_MASK (0x8U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_RX_EN_SHIFT (3U)
/*! LP_FLEXCOMM19_RX_EN - LP_FLEXCOMM19 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_TX_EN_MASK (0x10U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_TX_EN_SHIFT (4U)
/*! LP_FLEXCOMM19_TX_EN - LP_FLEXCOMM19 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM19_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_RX_EN_MASK (0x20U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_RX_EN_SHIFT (5U)
/*! LP_FLEXCOMM20_RX_EN - LP_FLEXCOMM20 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_TX_EN_MASK (0x40U)
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_TX_EN_SHIFT (6U)
/*! LP_FLEXCOMM20_TX_EN - LP_FLEXCOMM20 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LP_FLEXCOMM20_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_I3C2_RX_EN_MASK        (0x80U)
#define SYSCON1_EDMA3_EN1_I3C2_RX_EN_SHIFT       (7U)
/*! I3C2_RX_EN - I3C2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_I3C2_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_I3C2_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_I3C2_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_I3C2_TX_EN_MASK        (0x100U)
#define SYSCON1_EDMA3_EN1_I3C2_TX_EN_SHIFT       (8U)
/*! I3C2_TX_EN - I3C2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_I3C2_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_I3C2_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_I3C2_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_I3C3_RX_EN_MASK        (0x200U)
#define SYSCON1_EDMA3_EN1_I3C3_RX_EN_SHIFT       (9U)
/*! I3C3_RX_EN - I3C3 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_I3C3_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_I3C3_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_I3C3_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_I3C3_TX_EN_MASK        (0x400U)
#define SYSCON1_EDMA3_EN1_I3C3_TX_EN_SHIFT       (10U)
/*! I3C3_TX_EN - I3C3 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_I3C3_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_I3C3_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_I3C3_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_SAI3_RX_EN_MASK        (0x800U)
#define SYSCON1_EDMA3_EN1_SAI3_RX_EN_SHIFT       (11U)
/*! SAI3_RX_EN - SAI3 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_SAI3_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_SAI3_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_SAI3_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_SAI3_TX_EN_MASK        (0x1000U)
#define SYSCON1_EDMA3_EN1_SAI3_TX_EN_SHIFT       (12U)
/*! SAI3_TX_EN - SAI3 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_SAI3_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_SAI3_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_SAI3_TX_EN_MASK)

#define SYSCON1_EDMA3_EN1_GPIO8_DMA0_EN_MASK     (0x2000U)
#define SYSCON1_EDMA3_EN1_GPIO8_DMA0_EN_SHIFT    (13U)
/*! GPIO8_DMA0_EN - GPIO8 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_GPIO8_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_GPIO8_DMA0_EN_SHIFT)) & SYSCON1_EDMA3_EN1_GPIO8_DMA0_EN_MASK)

#define SYSCON1_EDMA3_EN1_GPIO8_DMA1_EN_MASK     (0x4000U)
#define SYSCON1_EDMA3_EN1_GPIO8_DMA1_EN_SHIFT    (14U)
/*! GPIO8_DMA1_EN - GPIO8 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_GPIO8_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_GPIO8_DMA1_EN_SHIFT)) & SYSCON1_EDMA3_EN1_GPIO8_DMA1_EN_MASK)

#define SYSCON1_EDMA3_EN1_GPIO9_DMA0_EN_MASK     (0x8000U)
#define SYSCON1_EDMA3_EN1_GPIO9_DMA0_EN_SHIFT    (15U)
/*! GPIO9_DMA0_EN - GPIO9 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_GPIO9_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_GPIO9_DMA0_EN_SHIFT)) & SYSCON1_EDMA3_EN1_GPIO9_DMA0_EN_MASK)

#define SYSCON1_EDMA3_EN1_GPIO9_DMA1_EN_MASK     (0x10000U)
#define SYSCON1_EDMA3_EN1_GPIO9_DMA1_EN_SHIFT    (16U)
/*! GPIO9_DMA1_EN - GPIO9 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_GPIO9_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_GPIO9_DMA1_EN_SHIFT)) & SYSCON1_EDMA3_EN1_GPIO9_DMA1_EN_MASK)

#define SYSCON1_EDMA3_EN1_RGPI10_DMA0_EN_MASK    (0x20000U)
#define SYSCON1_EDMA3_EN1_RGPI10_DMA0_EN_SHIFT   (17U)
/*! RGPI10_DMA0_EN - GPIO10 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_RGPI10_DMA0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_RGPI10_DMA0_EN_SHIFT)) & SYSCON1_EDMA3_EN1_RGPI10_DMA0_EN_MASK)

#define SYSCON1_EDMA3_EN1_RGPI10_DMA1_EN_MASK    (0x40000U)
#define SYSCON1_EDMA3_EN1_RGPI10_DMA1_EN_SHIFT   (18U)
/*! RGPI10_DMA1_EN - GPIO10 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_RGPI10_DMA1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_RGPI10_DMA1_EN_SHIFT)) & SYSCON1_EDMA3_EN1_RGPI10_DMA1_EN_MASK)

#define SYSCON1_EDMA3_EN1_LPI2C15_RX_EN_MASK     (0x80000U)
#define SYSCON1_EDMA3_EN1_LPI2C15_RX_EN_SHIFT    (19U)
/*! LPI2C15_RX_EN - LPI2C15 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LPI2C15_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LPI2C15_RX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LPI2C15_RX_EN_MASK)

#define SYSCON1_EDMA3_EN1_LPI2C15_TX_EN_MASK     (0x100000U)
#define SYSCON1_EDMA3_EN1_LPI2C15_TX_EN_SHIFT    (20U)
/*! LPI2C15_TX_EN - LPI2C15 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON1_EDMA3_EN1_LPI2C15_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON1_EDMA3_EN1_LPI2C15_TX_EN_SHIFT)) & SYSCON1_EDMA3_EN1_LPI2C15_TX_EN_MASK)
/*! @} */

/*! @name I3C_ASYNC_WAKEUP_CTRL - I3C Asynchronous Wake-up Control */
/*! @{ */

#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C2_ON_CHIP_STRONG_PULL_DIS_MASK (0x1U)
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C2_ON_CHIP_STRONG_PULL_DIS_SHIFT (0U)
/*! I3C2_ON_CHIP_STRONG_PULL_DIS - I3C2 On-Chip Strong Pull Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C2_ON_CHIP_STRONG_PULL_DIS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C2_ON_CHIP_STRONG_PULL_DIS_SHIFT)) & SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C2_ON_CHIP_STRONG_PULL_DIS_MASK)

#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN2_MASK (0x2U)
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN2_SHIFT (1U)
/*! IRQ_EN2 - I3C2 Controller Mode Asynchronous Wake-up Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN2(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN2_SHIFT)) & SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN2_MASK)

#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C3_ON_CHIP_STRONG_PULL_DIS_MASK (0x100U)
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C3_ON_CHIP_STRONG_PULL_DIS_SHIFT (8U)
/*! I3C3_ON_CHIP_STRONG_PULL_DIS - I3C3 On-Chip Strong Pull Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C3_ON_CHIP_STRONG_PULL_DIS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C3_ON_CHIP_STRONG_PULL_DIS_SHIFT)) & SYSCON1_I3C_ASYNC_WAKEUP_CTRL_I3C3_ON_CHIP_STRONG_PULL_DIS_MASK)

#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN3_MASK (0x200U)
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN3_SHIFT (9U)
/*! IRQ_EN3 - I3C3 Controller Mode Asynchronous Wake-up Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN3(x) (((uint32_t)(((uint32_t)(x)) << SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN3_SHIFT)) & SYSCON1_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON1_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON1_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCON1_H_ */

