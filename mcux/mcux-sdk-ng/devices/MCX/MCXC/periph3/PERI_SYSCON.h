/*
** ###################################################################
**     Processors:          MCXC151VFG
**                          MCXC151VFK
**                          MCXC151VFM
**                          MCXC151VFT
**                          MCXC151VLF
**                          MCXC161VFG
**                          MCXC161VFK
**                          MCXC161VFM
**                          MCXC161VFT
**                          MCXC161VLF
**                          MCXC162VFG
**                          MCXC162VFK
**                          MCXC162VFM
**                          MCXC162VFT
**                          MCXC162VLF
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b260202
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for SYSCON
 *
 * CMSIS Peripheral Access Layer for SYSCON
 */

#if !defined(PERI_SYSCON_H_)
#define PERI_SYSCON_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC151VFG) || defined(CPU_MCXC151VFK) || defined(CPU_MCXC151VFM) || defined(CPU_MCXC151VFT) || defined(CPU_MCXC151VLF))
#include "MCXC151_COMMON.h"
#elif (defined(CPU_MCXC161VFG) || defined(CPU_MCXC161VFK) || defined(CPU_MCXC161VFM) || defined(CPU_MCXC161VFT) || defined(CPU_MCXC161VLF))
#include "MCXC161_COMMON.h"
#elif (defined(CPU_MCXC162VFG) || defined(CPU_MCXC162VFK) || defined(CPU_MCXC162VFM) || defined(CPU_MCXC162VFT) || defined(CPU_MCXC162VLF))
#include "MCXC162_COMMON.h"
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
       uint8_t RESERVED_0[16];
  __IO uint32_t AHBMATPRIO;                        /**< AHB Matrix Priority Control, offset: 0x10 */
       uint8_t RESERVED_1[52];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x48 */
  __IO uint32_t PROTLVL;                           /**< Protect Level Control, offset: 0x4C */
       uint8_t RESERVED_2[48];
  __IO uint32_t AHBCLKDIV;                         /**< System Clock Divider, offset: 0x80 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SLOWCLKDIV;                        /**< SLOW_CLK Clock Divider, offset: 0x88 */
       uint8_t RESERVED_4[4];
  __IO uint32_t FROHFDIV;                          /**< FRO_HF_DIV Clock Divider, offset: 0x90 */
  __IO uint32_t FROLFDIV;                          /**< FRO_LF_DIV Clock Divider, offset: 0x94 */
       uint8_t RESERVED_5[100];
  __IO uint32_t CLKUNLOCK;                         /**< Clock Configuration Unlock, offset: 0xFC */
       uint8_t RESERVED_6[256];
  __IO uint32_t NVM_CTRL;                          /**< NVM Control, offset: 0x200 */
       uint8_t RESERVED_7[56];
       uint32_t BOOTROM;                           /**< Immediate cessation of execution following the completion of ROM execution, offset: 0x23C */
       uint8_t RESERVED_8[204];
  __I  uint32_t CPUSTAT;                           /**< CPU Status, offset: 0x30C */
       uint8_t RESERVED_9[296];
  __IO uint32_t PWM0SUBCTL;                        /**< PWM0 Submodule Control, offset: 0x438 */
       uint8_t RESERVED_10[4];
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER Global Start Enable, offset: 0x440 */
  __IO uint32_t RAM_CTRL;                          /**< RAM Control, offset: 0x444 */
       uint8_t RESERVED_11[936];
  __I  uint32_t JTAG_ID;                           /**< JTAG Chip ID, offset: 0x7F0 */
  __I  uint32_t DEVICE_TYPE;                       /**< Device Type, offset: 0x7F4 */
  __I  uint32_t DEVICE_ID0;                        /**< Device ID, offset: 0x7F8 */
} SYSCON_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON_Register_Masks SYSCON Register Masks
 * @{
 */

/*! @name AHBMATPRIO - AHB Matrix Priority Control */
/*! @{ */

#define SYSCON_AHBMATPRIO_CPU0_SBUS_MASK         (0xCU)
#define SYSCON_AHBMATPRIO_CPU0_SBUS_SHIFT        (2U)
/*! CPU0_SBUS - CPU0 S-AHB bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_CPU0_SBUS(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_CPU0_SBUS_SHIFT)) & SYSCON_AHBMATPRIO_CPU0_SBUS_MASK)

#define SYSCON_AHBMATPRIO_DMA0_MASK              (0x300U)
#define SYSCON_AHBMATPRIO_DMA0_SHIFT             (8U)
/*! DMA0 - DMA0 controller bus master priority level
 *  0b00..level 0
 *  0b01..level 1
 *  0b10..level 2
 *  0b11..level 3
 */
#define SYSCON_AHBMATPRIO_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_AHBMATPRIO_DMA0_SHIFT)) & SYSCON_AHBMATPRIO_DMA0_MASK)
/*! @} */

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON_NMISRC_IRQCPU0_MASK               (0xFFU)
#define SYSCON_NMISRC_IRQCPU0_SHIFT              (0U)
/*! IRQCPU0 - The IRQ number of the interrupt that acts as the Non-Maskable Interrupt (NMI) for CPU0, if enabled by NMIENCPU0. */
#define SYSCON_NMISRC_IRQCPU0(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_IRQCPU0_SHIFT)) & SYSCON_NMISRC_IRQCPU0_MASK)

#define SYSCON_NMISRC_NMIENCPU0_MASK             (0x80000000U)
#define SYSCON_NMISRC_NMIENCPU0_SHIFT            (31U)
/*! NMIENCPU0 - Enables the Non-Maskable Interrupt (NMI) source selected by IRQCPU0.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define SYSCON_NMISRC_NMIENCPU0(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_NMISRC_NMIENCPU0_SHIFT)) & SYSCON_NMISRC_NMIENCPU0_MASK)
/*! @} */

/*! @name PROTLVL - Protect Level Control */
/*! @{ */

#define SYSCON_PROTLVL_PRIV_MASK                 (0x1U)
#define SYSCON_PROTLVL_PRIV_SHIFT                (0U)
/*! PRIV - Control privileged access of EIM, ERM, Flexcan, MBC, SCG, DMA, ROMCP and Flexspi.
 *  0b0..privileged access is disabled. the peripherals could be access in user mode.
 *  0b1..privileged access is enabled. the peripherals could be access in privilege mode.
 */
#define SYSCON_PROTLVL_PRIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PROTLVL_PRIV_SHIFT)) & SYSCON_PROTLVL_PRIV_MASK)

#define SYSCON_PROTLVL_LOCKNSMPU_MASK            (0x10000U)
#define SYSCON_PROTLVL_LOCKNSMPU_SHIFT           (16U)
/*! LOCKNSMPU - Control write access to Nonsecure MPU memory regions.
 *  0b0..Unlock these registers. privileged access to Nonsecure MPU memory regions is allowed.
 *  0b1..Disable writes to the MPU_CTRL_NS, MPU_RNR_NS, MPU_RBAR_NS, MPU_RLAR_NS, MPU_RBAR_A_NSn and
 *       MPU_RLAR_A_NSn. All writes to the registers are ignored.
 */
#define SYSCON_PROTLVL_LOCKNSMPU(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_PROTLVL_LOCKNSMPU_SHIFT)) & SYSCON_PROTLVL_LOCKNSMPU_MASK)

#define SYSCON_PROTLVL_LOCK_MASK                 (0x80000000U)
#define SYSCON_PROTLVL_LOCK_SHIFT                (31U)
/*! LOCK - This 1-bit field provides a mechanism to limit writes to this register to protect its
 *    contents. Once set, this bit remains asserted until a system reset.
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered until a system reset.
 */
#define SYSCON_PROTLVL_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_PROTLVL_LOCK_SHIFT)) & SYSCON_PROTLVL_LOCK_MASK)
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

/*! @name SLOWCLKDIV - SLOW_CLK Clock Divider */
/*! @{ */

#define SYSCON_SLOWCLKDIV_DIV_MASK               (0xFFU)
#define SYSCON_SLOWCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value */
#define SYSCON_SLOWCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_DIV_SHIFT)) & SYSCON_SLOWCLKDIV_DIV_MASK)

#define SYSCON_SLOWCLKDIV_RESET_MASK             (0x20000000U)
#define SYSCON_SLOWCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_SLOWCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_RESET_SHIFT)) & SYSCON_SLOWCLKDIV_RESET_MASK)

#define SYSCON_SLOWCLKDIV_HALT_MASK              (0x40000000U)
#define SYSCON_SLOWCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_SLOWCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_HALT_SHIFT)) & SYSCON_SLOWCLKDIV_HALT_MASK)

#define SYSCON_SLOWCLKDIV_UNSTAB_MASK            (0x80000000U)
#define SYSCON_SLOWCLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_SLOWCLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_SLOWCLKDIV_UNSTAB_SHIFT)) & SYSCON_SLOWCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROHFDIV - FRO_HF_DIV Clock Divider */
/*! @{ */

#define SYSCON_FROHFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROHFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value */
#define SYSCON_FROHFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_DIV_SHIFT)) & SYSCON_FROHFDIV_DIV_MASK)

#define SYSCON_FROHFDIV_RESET_MASK               (0x20000000U)
#define SYSCON_FROHFDIV_RESET_SHIFT              (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FROHFDIV_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_RESET_SHIFT)) & SYSCON_FROHFDIV_RESET_MASK)

#define SYSCON_FROHFDIV_HALT_MASK                (0x40000000U)
#define SYSCON_FROHFDIV_HALT_SHIFT               (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FROHFDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_HALT_SHIFT)) & SYSCON_FROHFDIV_HALT_MASK)

#define SYSCON_FROHFDIV_UNSTAB_MASK              (0x80000000U)
#define SYSCON_FROHFDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FROHFDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROHFDIV_UNSTAB_SHIFT)) & SYSCON_FROHFDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROLFDIV - FRO_LF_DIV Clock Divider */
/*! @{ */

#define SYSCON_FROLFDIV_DIV_MASK                 (0xFFU)
#define SYSCON_FROLFDIV_DIV_SHIFT                (0U)
/*! DIV - Clock divider value */
#define SYSCON_FROLFDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_DIV_SHIFT)) & SYSCON_FROLFDIV_DIV_MASK)

#define SYSCON_FROLFDIV_RESET_MASK               (0x20000000U)
#define SYSCON_FROLFDIV_RESET_SHIFT              (29U)
/*! RESET - Resets the divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define SYSCON_FROLFDIV_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_RESET_SHIFT)) & SYSCON_FROLFDIV_RESET_MASK)

#define SYSCON_FROLFDIV_HALT_MASK                (0x40000000U)
#define SYSCON_FROLFDIV_HALT_SHIFT               (30U)
/*! HALT - Halts the divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define SYSCON_FROLFDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_HALT_SHIFT)) & SYSCON_FROLFDIV_HALT_MASK)

#define SYSCON_FROLFDIV_UNSTAB_MASK              (0x80000000U)
#define SYSCON_FROLFDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency is not stable
 */
#define SYSCON_FROLFDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_FROLFDIV_UNSTAB_SHIFT)) & SYSCON_FROLFDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKUNLOCK - Clock Configuration Unlock */
/*! @{ */

#define SYSCON_CLKUNLOCK_UNLOCK_MASK             (0x1U)
#define SYSCON_CLKUNLOCK_UNLOCK_SHIFT            (0U)
/*! UNLOCK - Controls clock configuration registers access (for example, SLOWCLKDIV, BUSCLKDIV,
 *    AHBCLKDIV, FROHFDIV, FROLFDIV, PLLxCLKDIV, MRCC_xxx_CLKDIV, MRCC_xxx_CLKSEL, MRCC_GLB_xxx)
 *  0b0..Updates are allowed to all clock configuration registers
 *  0b1..Freezes all clock configuration registers update.
 */
#define SYSCON_CLKUNLOCK_UNLOCK(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_CLKUNLOCK_UNLOCK_SHIFT)) & SYSCON_CLKUNLOCK_UNLOCK_MASK)
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
/*! DIS_MBECC_ERR_INST
 *  0b0..Enables bus error on multi-bit ECC error for instruction
 *  0b1..Disables bus error on multi-bit ECC error for instruction
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_INST_MASK)

#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK  (0x20000U)
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT (17U)
/*! DIS_MBECC_ERR_DATA
 *  0b0..Enables bus error on multi-bit ECC error for data
 *  0b1..Disables bus error on multi-bit ECC error for data
 */
#define SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_SHIFT)) & SYSCON_NVM_CTRL_DIS_MBECC_ERR_DATA_MASK)
/*! @} */

/*! @name CPUSTAT - CPU Status */
/*! @{ */

#define SYSCON_CPUSTAT_CPU0SLEEPING_MASK         (0x1U)
#define SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT        (0U)
/*! CPU0SLEEPING - CPU0 sleeping state
 *  0b0..CPU is not sleeping
 *  0b1..CPU is sleeping
 */
#define SYSCON_CPUSTAT_CPU0SLEEPING(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0SLEEPING_SHIFT)) & SYSCON_CPUSTAT_CPU0SLEEPING_MASK)

#define SYSCON_CPUSTAT_CPU0LOCKUP_MASK           (0x4U)
#define SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT          (2U)
/*! CPU0LOCKUP - CPU0 lockup state
 *  0b0..CPU is not in lockup
 *  0b1..CPU is in lockup
 */
#define SYSCON_CPUSTAT_CPU0LOCKUP(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON_CPUSTAT_CPU0LOCKUP_SHIFT)) & SYSCON_CPUSTAT_CPU0LOCKUP_MASK)
/*! @} */

/*! @name PWM0SUBCTL - PWM0 Submodule Control */
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
/*! @} */

/*! @name RAM_CTRL - RAM Control */
/*! @{ */

#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_MASK     (0x1U)
#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_SHIFT    (0U)
/*! RAMA_ECC_ENABLE - RAMA ECC enable
 *  0b0..ECC is disabled
 *  0b1..ECC is enabled
 */
#define SYSCON_RAM_CTRL_RAMA_ECC_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_SHIFT)) & SYSCON_RAM_CTRL_RAMA_ECC_ENABLE_MASK)

#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_MASK    (0x10000U)
#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_SHIFT   (16U)
/*! RAMA_CG_OVERRIDE - RAMA bank clock gating control, only avaiable when RAMA_ECC_ENABLE = 0.
 *  0b0..Memory bank clock is gated automatically if no access more than 16 clock cycles
 *  0b1..Auto clock gating feature is disabled
 */
#define SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_SHIFT)) & SYSCON_RAM_CTRL_RAMA_CG_OVERRIDE_MASK)
/*! @} */

/*! @name JTAG_ID - JTAG Chip ID */
/*! @{ */

#define SYSCON_JTAG_ID_JTAG_ID_MASK              (0xFFFFFFFFU)
#define SYSCON_JTAG_ID_JTAG_ID_SHIFT             (0U)
/*! JTAG_ID - Indicates the device ID */
#define SYSCON_JTAG_ID_JTAG_ID(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_JTAG_ID_JTAG_ID_SHIFT)) & SYSCON_JTAG_ID_JTAG_ID_MASK)
/*! @} */

/*! @name DEVICE_TYPE - Device Type */
/*! @{ */

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK  (0xFFFFU)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT (0U)
/*! DEVICE_TYPE_NUM - Indicates the device part number */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK  (0x10000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT (16U)
/*! DEVICE_TYPE_SEC - Indicates the device type
 *  0b0..Non Secure
 *  0b1..Secure
 */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK  (0xF00000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT (20U)
/*! DEVICE_TYPE_PKG - Indicates the device's package type
 *  0b0000..HLQFP
 *  0b0001..HTQFP
 *  0b0010..BGA
 *  0b0011..HDQFP
 *  0b0100..QFN
 *  0b0101..CSP
 *  0b0110..LQFP
 */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK)

#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK  (0xFF000000U)
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT (24U)
/*! DEVICE_TYPE_PIN - Indicates the device's pin number */
#define SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT)) & SYSCON_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK)
/*! @} */

/*! @name DEVICE_ID0 - Device ID */
/*! @{ */

#define SYSCON_DEVICE_ID0_RAM_SIZE_MASK          (0xFU)
#define SYSCON_DEVICE_ID0_RAM_SIZE_SHIFT         (0U)
/*! RAM_SIZE - Indicates the device's ram size
 *  0b0000..6KB.
 *  0b0001..12KB.
 *  0b0010..32KB.
 *  0b0011..64KB.
 *  0b0100..96KB.
 *  0b0101..128KB.
 *  0b0110..160KB.
 *  0b0111..192KB.
 *  0b1000..256KB.
 *  0b1001..288KB.
 *  0b1010..352KB.
 *  0b1011..512KB.
 *  0b1100..640KB.
 */
#define SYSCON_DEVICE_ID0_RAM_SIZE(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_RAM_SIZE_SHIFT)) & SYSCON_DEVICE_ID0_RAM_SIZE_MASK)

#define SYSCON_DEVICE_ID0_FLASH_SIZE_MASK        (0xF0U)
#define SYSCON_DEVICE_ID0_FLASH_SIZE_SHIFT       (4U)
/*! FLASH_SIZE - Indicates the device's flash size
 *  0b0000..32KB.
 *  0b0001..64KB.
 *  0b0010..128KB.
 *  0b0011..256KB.
 *  0b0100..512KB.
 *  0b0101..768KB.
 *  0b0110..1MB.
 *  0b0111..1.5MB.
 *  0b1000..2MB.
 */
#define SYSCON_DEVICE_ID0_FLASH_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_FLASH_SIZE_SHIFT)) & SYSCON_DEVICE_ID0_FLASH_SIZE_MASK)

#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK     (0xF00000U)
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT    (20U)
/*! ROM_REV_MINOR - Indicates the device's ROM revision */
#define SYSCON_DEVICE_ID0_ROM_REV_MINOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_ROM_REV_MINOR_SHIFT)) & SYSCON_DEVICE_ID0_ROM_REV_MINOR_MASK)

#define SYSCON_DEVICE_ID0_SECURITY_MASK          (0xF000000U)
#define SYSCON_DEVICE_ID0_SECURITY_SHIFT         (24U)
/*! SECURITY
 *  0b0101..Secure version. (All values other than 1010b represent the secure version.)
 *  0b1010..Non secure version.
 */
#define SYSCON_DEVICE_ID0_SECURITY(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON_DEVICE_ID0_SECURITY_SHIFT)) & SYSCON_DEVICE_ID0_SECURITY_MASK)
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

