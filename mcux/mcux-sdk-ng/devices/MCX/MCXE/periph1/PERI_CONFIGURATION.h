/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CONFIGURATION
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_CONFIGURATION.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for CONFIGURATION
 *
 * CMSIS Peripheral Access Layer for CONFIGURATION
 */

#if !defined(PERI_CONFIGURATION_H_)
#define PERI_CONFIGURATION_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- CONFIGURATION Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_Peripheral_Access_Layer CONFIGURATION Peripheral Access Layer
 * @{
 */

/** CONFIGURATION - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[28];
  __I  uint32_t CONFIG_REG0;                       /**< General Purpose Configuration 0, offset: 0x1C */
       uint8_t RESERVED_1[20];
  __I  uint32_t CONFIG_REG6;                       /**< General Purpose Configuration 6, offset: 0x34 */
  __I  uint32_t CONFIG_RAMPR;                      /**< Configuration RAM Protected Region, offset: 0x38 */
  __I  uint32_t CONFIG_CFPRL;                      /**< Configuration Code Flash Memory Active Block, offset: 0x3C */
  __I  uint32_t CONFIG_CFPRH;                      /**< Configuration Code Flash Memory Passive Block, offset: 0x40 */
  __I  uint32_t CONFIG_DFPR;                       /**< Configuration Data Flash Memory Protected Region, offset: 0x44 */
       uint8_t RESERVED_2[8];
  __I  uint32_t CONFIG_PE_LOCK;                    /**< Configuration Program and Erase Lock, offset: 0x50 */
  __I  uint32_t CONFIG_RAMPR_ALT;                  /**< Configuration RAM Protected Region Alternate, offset: 0x54 */
  __I  uint32_t CONFIG_CFPRL_ALT;                  /**< Configuration Code Flash Memory Active Block Alternate, offset: 0x58 */
  __I  uint32_t CONFIG_CFPRH_ALT;                  /**< Configuration Code Flash Memory Passive Block Alternate, offset: 0x5C */
  __I  uint32_t CONFIG_DFPR_ALT;                   /**< Configuration Data Flash Memory Protected Region Alternate, offset: 0x60 */
  __IO uint32_t CONFIG_REG_GPR;                    /**< Configuration REG_GPR, offset: 0x64 */
} CONFIGURATION_Type;

/* ----------------------------------------------------------------------------
   -- CONFIGURATION Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CONFIGURATION_Register_Masks CONFIGURATION Register Masks
 * @{
 */

/*! @name CONFIG_REG0 - General Purpose Configuration 0 */
/*! @{ */

#define CONFIGURATION_CONFIG_REG0_EDB_MASK       (0x40U)
#define CONFIGURATION_CONFIG_REG0_EDB_SHIFT      (6U)
/*! EDB - Hardware Debugger Attached
 *  0b0..Debugger not connected
 *  0b1..Debugger connected
 */
#define CONFIGURATION_CONFIG_REG0_EDB(x)         (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG0_EDB_SHIFT)) & CONFIGURATION_CONFIG_REG0_EDB_MASK)
/*! @} */

/*! @name CONFIG_REG6 - General Purpose Configuration 6 */
/*! @{ */

#define CONFIGURATION_CONFIG_REG6_QUADSPI_SDID_PCTL_MASK (0x1U)
#define CONFIGURATION_CONFIG_REG6_QUADSPI_SDID_PCTL_SHIFT (0U)
/*! QUADSPI_SDID_PCTL - QuadSPI Clock Gating
 *  0b0..Clock is off (gated)
 *  0b1..Clock is on
 */
#define CONFIGURATION_CONFIG_REG6_QUADSPI_SDID_PCTL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG6_QUADSPI_SDID_PCTL_SHIFT)) & CONFIGURATION_CONFIG_REG6_QUADSPI_SDID_PCTL_MASK)

#define CONFIGURATION_CONFIG_REG6_EMAC_CLOCK_GATE_MASK (0x4U)
#define CONFIGURATION_CONFIG_REG6_EMAC_CLOCK_GATE_SHIFT (2U)
/*! EMAC_CLOCK_GATE - Ethernet Clock Gating
 *  0b0..Clock is off (gated)
 *  0b1..Clock is on
 */
#define CONFIGURATION_CONFIG_REG6_EMAC_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG6_EMAC_CLOCK_GATE_SHIFT)) & CONFIGURATION_CONFIG_REG6_EMAC_CLOCK_GATE_MASK)

#define CONFIGURATION_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK (0x10U)
#define CONFIGURATION_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT (4U)
/*! FLEXIO_CLOCK_GATE - FlexIO Clock Gating
 *  0b0..Clock is off (gated)
 *  0b1..Clock is on
 */
#define CONFIGURATION_CONFIG_REG6_FLEXIO_CLOCK_GATE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG6_FLEXIO_CLOCK_GATE_SHIFT)) & CONFIGURATION_CONFIG_REG6_FLEXIO_CLOCK_GATE_MASK)

#define CONFIGURATION_CONFIG_REG6_SAI_SDID_PCTL_MASK (0x20U)
#define CONFIGURATION_CONFIG_REG6_SAI_SDID_PCTL_SHIFT (5U)
/*! SAI_SDID_PCTL - SAI0 and SAI1 clock gating
 *  0b0..Clock is off (gated)
 *  0b1..Clock is on
 */
#define CONFIGURATION_CONFIG_REG6_SAI_SDID_PCTL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG6_SAI_SDID_PCTL_SHIFT)) & CONFIGURATION_CONFIG_REG6_SAI_SDID_PCTL_MASK)

#define CONFIGURATION_CONFIG_REG6_HL_MASK        (0x80000000U)
#define CONFIGURATION_CONFIG_REG6_HL_SHIFT       (31U)
/*! HL - Hard Lock
 *  0b0..You can write to this register
 *  0b1..Register is locked for any write
 */
#define CONFIGURATION_CONFIG_REG6_HL(x)          (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG6_HL_SHIFT)) & CONFIGURATION_CONFIG_REG6_HL_MASK)
/*! @} */

/*! @name CONFIG_RAMPR - Configuration RAM Protected Region */
/*! @{ */

#define CONFIGURATION_CONFIG_RAMPR_SECURE_SIZE_MASK (0x1FFFE0U)
#define CONFIGURATION_CONFIG_RAMPR_SECURE_SIZE_SHIFT (5U)
/*! SECURE_SIZE - Secure Size */
#define CONFIGURATION_CONFIG_RAMPR_SECURE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_RAMPR_SECURE_SIZE_SHIFT)) & CONFIGURATION_CONFIG_RAMPR_SECURE_SIZE_MASK)

#define CONFIGURATION_CONFIG_RAMPR_SOFT_LOCK_MASK (0x40000000U)
#define CONFIGURATION_CONFIG_RAMPR_SOFT_LOCK_SHIFT (30U)
/*! SOFT_LOCK - Soft Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed
 */
#define CONFIGURATION_CONFIG_RAMPR_SOFT_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_RAMPR_SOFT_LOCK_SHIFT)) & CONFIGURATION_CONFIG_RAMPR_SOFT_LOCK_MASK)

#define CONFIGURATION_CONFIG_RAMPR_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_CONFIG_RAMPR_HARD_LOCK_SHIFT (31U)
/*! HARD_LOCK - Hard Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed until next functional reset
 */
#define CONFIGURATION_CONFIG_RAMPR_HARD_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_RAMPR_HARD_LOCK_SHIFT)) & CONFIGURATION_CONFIG_RAMPR_HARD_LOCK_MASK)
/*! @} */

/*! @name CONFIG_CFPRL - Configuration Code Flash Memory Active Block */
/*! @{ */

#define CONFIGURATION_CONFIG_CFPRL_SECURE_SIZE_MASK (0x1FE000U)
#define CONFIGURATION_CONFIG_CFPRL_SECURE_SIZE_SHIFT (13U)
/*! SECURE_SIZE - Secure Size */
#define CONFIGURATION_CONFIG_CFPRL_SECURE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRL_SECURE_SIZE_SHIFT)) & CONFIGURATION_CONFIG_CFPRL_SECURE_SIZE_MASK)

#define CONFIGURATION_CONFIG_CFPRL_SOFT_LOCK_MASK (0x40000000U)
#define CONFIGURATION_CONFIG_CFPRL_SOFT_LOCK_SHIFT (30U)
/*! SOFT_LOCK - Soft Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed
 */
#define CONFIGURATION_CONFIG_CFPRL_SOFT_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRL_SOFT_LOCK_SHIFT)) & CONFIGURATION_CONFIG_CFPRL_SOFT_LOCK_MASK)

#define CONFIGURATION_CONFIG_CFPRL_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_CONFIG_CFPRL_HARD_LOCK_SHIFT (31U)
/*! HARD_LOCK - Hard Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed until next functional reset
 */
#define CONFIGURATION_CONFIG_CFPRL_HARD_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRL_HARD_LOCK_SHIFT)) & CONFIGURATION_CONFIG_CFPRL_HARD_LOCK_MASK)
/*! @} */

/*! @name CONFIG_CFPRH - Configuration Code Flash Memory Passive Block */
/*! @{ */

#define CONFIGURATION_CONFIG_CFPRH_SECURE_SIZE_MASK (0x1FE000U)
#define CONFIGURATION_CONFIG_CFPRH_SECURE_SIZE_SHIFT (13U)
/*! SECURE_SIZE - Secure Size */
#define CONFIGURATION_CONFIG_CFPRH_SECURE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRH_SECURE_SIZE_SHIFT)) & CONFIGURATION_CONFIG_CFPRH_SECURE_SIZE_MASK)

#define CONFIGURATION_CONFIG_CFPRH_SOFT_LOCK_MASK (0x40000000U)
#define CONFIGURATION_CONFIG_CFPRH_SOFT_LOCK_SHIFT (30U)
/*! SOFT_LOCK - Soft Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed
 */
#define CONFIGURATION_CONFIG_CFPRH_SOFT_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRH_SOFT_LOCK_SHIFT)) & CONFIGURATION_CONFIG_CFPRH_SOFT_LOCK_MASK)

#define CONFIGURATION_CONFIG_CFPRH_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_CONFIG_CFPRH_HARD_LOCK_SHIFT (31U)
/*! HARD_LOCK - Hard Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed until next functional reset
 */
#define CONFIGURATION_CONFIG_CFPRH_HARD_LOCK(x)  (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRH_HARD_LOCK_SHIFT)) & CONFIGURATION_CONFIG_CFPRH_HARD_LOCK_MASK)
/*! @} */

/*! @name CONFIG_DFPR - Configuration Data Flash Memory Protected Region */
/*! @{ */

#define CONFIGURATION_CONFIG_DFPR_SECURE_SIZE_MASK (0x1FE000U)
#define CONFIGURATION_CONFIG_DFPR_SECURE_SIZE_SHIFT (13U)
/*! SECURE_SIZE - Secure Size */
#define CONFIGURATION_CONFIG_DFPR_SECURE_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_DFPR_SECURE_SIZE_SHIFT)) & CONFIGURATION_CONFIG_DFPR_SECURE_SIZE_MASK)

#define CONFIGURATION_CONFIG_DFPR_SOFT_LOCK_MASK (0x40000000U)
#define CONFIGURATION_CONFIG_DFPR_SOFT_LOCK_SHIFT (30U)
/*! SOFT_LOCK - Soft Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed
 */
#define CONFIGURATION_CONFIG_DFPR_SOFT_LOCK(x)   (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_DFPR_SOFT_LOCK_SHIFT)) & CONFIGURATION_CONFIG_DFPR_SOFT_LOCK_MASK)

#define CONFIGURATION_CONFIG_DFPR_HARD_LOCK_MASK (0x80000000U)
#define CONFIGURATION_CONFIG_DFPR_HARD_LOCK_SHIFT (31U)
/*! HARD_LOCK - Hard Lock
 *  0b0..Write access is allowed
 *  0b1..Write access is not allowed until next functional reset
 */
#define CONFIGURATION_CONFIG_DFPR_HARD_LOCK(x)   (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_DFPR_HARD_LOCK_SHIFT)) & CONFIGURATION_CONFIG_DFPR_HARD_LOCK_MASK)
/*! @} */

/*! @name CONFIG_PE_LOCK - Configuration Program and Erase Lock */
/*! @{ */

#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_0_MASK (0x1000U)
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_0_SHIFT (12U)
/*! PE_LOCK_BLOCK_0 - Program/Erase Lock for Block 0
 *  0b0..Block 0 lock request is clear
 *  0b1..Block 0 lock requested
 */
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_0(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_0_SHIFT)) & CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_0_MASK)

#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_1_MASK (0x2000U)
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_1_SHIFT (13U)
/*! PE_LOCK_BLOCK_1 - Program/Erase Lock for Block 1
 *  0b0..Block 1 lock request is clear
 *  0b1..Block 1 lock requested
 */
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_1(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_1_SHIFT)) & CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_1_MASK)

#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_2_MASK (0x4000U)
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_2_SHIFT (14U)
/*! PE_LOCK_BLOCK_2 - Program/Erase Lock for Block 2
 *  0b0..Block 2 lock request is clear
 *  0b1..Block 2 lock requested
 */
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_2(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_2_SHIFT)) & CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_2_MASK)

#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_3_MASK (0x8000U)
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_3_SHIFT (15U)
/*! PE_LOCK_BLOCK_3 - Program/Erase Lock for Block 3
 *  0b0..Block 3 lock request is clear
 *  0b1..Block 3 lock requested
 */
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_3(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_3_SHIFT)) & CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_3_MASK)

#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_4_MASK (0x10000U)
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_4_SHIFT (16U)
/*! PE_LOCK_BLOCK_4 - Program/Erase Lock for Block 4
 *  0b0..Block 4 lock request is clear
 *  0b1..Block 4 lock requested
 */
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_4(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_4_SHIFT)) & CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_BLOCK_4_MASK)

#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_UTEST_MASK (0x40000U)
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_UTEST_SHIFT (18U)
/*! PE_LOCK_UTEST - Program/Erase Lock for UTEST
 *  0b0..UTEST lock request is clear
 *  0b1..UTEST lock requested
 */
#define CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_UTEST(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_UTEST_SHIFT)) & CONFIGURATION_CONFIG_PE_LOCK_PE_LOCK_UTEST_MASK)
/*! @} */

/*! @name CONFIG_RAMPR_ALT - Configuration RAM Protected Region Alternate */
/*! @{ */

#define CONFIGURATION_CONFIG_RAMPR_ALT_INVERT_VALUE_RAMPR_MASK (0xFFFFFFFFU)
#define CONFIGURATION_CONFIG_RAMPR_ALT_INVERT_VALUE_RAMPR_SHIFT (0U)
/*! INVERT_VALUE_RAMPR - Invert Value RAMPR */
#define CONFIGURATION_CONFIG_RAMPR_ALT_INVERT_VALUE_RAMPR(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_RAMPR_ALT_INVERT_VALUE_RAMPR_SHIFT)) & CONFIGURATION_CONFIG_RAMPR_ALT_INVERT_VALUE_RAMPR_MASK)
/*! @} */

/*! @name CONFIG_CFPRL_ALT - Configuration Code Flash Memory Active Block Alternate */
/*! @{ */

#define CONFIGURATION_CONFIG_CFPRL_ALT_INVERT_VALUE_CFPRAB_MASK (0xFFFFFFFFU)
#define CONFIGURATION_CONFIG_CFPRL_ALT_INVERT_VALUE_CFPRAB_SHIFT (0U)
/*! INVERT_VALUE_CFPRAB - Invert Value CFPRAB */
#define CONFIGURATION_CONFIG_CFPRL_ALT_INVERT_VALUE_CFPRAB(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRL_ALT_INVERT_VALUE_CFPRAB_SHIFT)) & CONFIGURATION_CONFIG_CFPRL_ALT_INVERT_VALUE_CFPRAB_MASK)
/*! @} */

/*! @name CONFIG_CFPRH_ALT - Configuration Code Flash Memory Passive Block Alternate */
/*! @{ */

#define CONFIGURATION_CONFIG_CFPRH_ALT_INVERT_VALUE_CFPRP_MASK (0xFFFFFFFFU)
#define CONFIGURATION_CONFIG_CFPRH_ALT_INVERT_VALUE_CFPRP_SHIFT (0U)
/*! INVERT_VALUE_CFPRP - Invert Value CFPRP */
#define CONFIGURATION_CONFIG_CFPRH_ALT_INVERT_VALUE_CFPRP(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_CFPRH_ALT_INVERT_VALUE_CFPRP_SHIFT)) & CONFIGURATION_CONFIG_CFPRH_ALT_INVERT_VALUE_CFPRP_MASK)
/*! @} */

/*! @name CONFIG_DFPR_ALT - Configuration Data Flash Memory Protected Region Alternate */
/*! @{ */

#define CONFIGURATION_CONFIG_DFPR_ALT_INVERT_VALUE_DFPR_MASK (0xFFFFFFFFU)
#define CONFIGURATION_CONFIG_DFPR_ALT_INVERT_VALUE_DFPR_SHIFT (0U)
/*! INVERT_VALUE_DFPR - Invert Value CFPRP */
#define CONFIGURATION_CONFIG_DFPR_ALT_INVERT_VALUE_DFPR(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_DFPR_ALT_INVERT_VALUE_DFPR_SHIFT)) & CONFIGURATION_CONFIG_DFPR_ALT_INVERT_VALUE_DFPR_MASK)
/*! @} */

/*! @name CONFIG_REG_GPR - Configuration REG_GPR */
/*! @{ */

#define CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK (0x3U)
#define CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL_SHIFT (0U)
/*! FIRC_DIV_SEL - FIRC Divider
 *  0b00..Divided by 2
 *  0b01..Divided by 2
 *  0b10..Divided by 16
 *  0b11..Undivided
 */
#define CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL_SHIFT)) & CONFIGURATION_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK)

#define CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC_MASK (0xE0000000U)
#define CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT (29U)
/*! APP_CORE_ACC - FIRC Divider
 *  0b101..Application core can write this field [FIRC_DIV_SEL]
 *  *..No access to application core
 */
#define CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC(x) (((uint32_t)(((uint32_t)(x)) << CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT)) & CONFIGURATION_CONFIG_REG_GPR_APP_CORE_ACC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CONFIGURATION_Register_Masks */


/*!
 * @}
 */ /* end of group CONFIGURATION_Peripheral_Access_Layer */


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


#endif  /* PERI_CONFIGURATION_H_ */

