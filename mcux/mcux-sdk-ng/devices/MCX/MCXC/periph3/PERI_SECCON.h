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
**     Build:               b260121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SECCON
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
 * @file PERI_SECCON.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for SECCON
 *
 * CMSIS Peripheral Access Layer for SECCON
 */

#if !defined(PERI_SECCON_H_)
#define PERI_SECCON_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SECCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECCON_Peripheral_Access_Layer SECCON Peripheral Access Layer
 * @{
 */

/** SECCON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[80];
  __IO uint32_t CPU0STCKCAL;                       /**< CPU0 System Tick Calibration, offset: 0x50 */
       uint8_t RESERVED_1[1480];
  __IO uint32_t MSFCFG;                            /**< MSF Configuration, offset: 0x61C */
       uint8_t RESERVED_2[28];
  __I  uint32_t CFPA_LC_STATE;                     /**< CFPA State Register, offset: 0x63C */
       uint8_t RESERVED_3[24];
  __IO uint32_t RAM_XEN;                           /**< RAM XEN Control, offset: 0x658 */
  __IO uint32_t RAM_XEN_DP;                        /**< RAM XEN Control (Duplicate), offset: 0x65C */
       uint8_t RESERVED_4[32];
  __I  uint32_t ELS_OTP_LC_STATE;                  /**< Life Cycle State Register, offset: 0x680 */
  __I  uint32_t ELS_OTP_LC_STATE_DP;               /**< Life Cycle State Register (Duplicate), offset: 0x684 */
       uint8_t RESERVED_5[280];
  __IO uint32_t DEBUG_LOCK_EN;                     /**< Control Write Access to Security, offset: 0x7A0 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex Debug Features Control, offset: 0x7A4 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex Debug Features Control (Duplicate), offset: 0x7A8 */
       uint8_t RESERVED_6[8];
  __IO uint32_t SWD_ACCESS_CPU0;                   /**< CPU0 Software Debug Access, offset: 0x7B4 */
} SECCON_Type;

/* ----------------------------------------------------------------------------
   -- SECCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECCON_Register_Masks SECCON Register Masks
 * @{
 */

/*! @name CPU0STCKCAL - CPU0 System Tick Calibration */
/*! @{ */

#define SECCON_CPU0STCKCAL_TENMS_MASK            (0xFFFFFFU)
#define SECCON_CPU0STCKCAL_TENMS_SHIFT           (0U)
/*! TENMS - Reload value for 10 ms (100 Hz) timing, subject to system clock skew errors. If the
 *    value reads as zero, the calibration value is not known.
 */
#define SECCON_CPU0STCKCAL_TENMS(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0STCKCAL_TENMS_SHIFT)) & SECCON_CPU0STCKCAL_TENMS_MASK)

#define SECCON_CPU0STCKCAL_SKEW_MASK             (0x1000000U)
#define SECCON_CPU0STCKCAL_SKEW_SHIFT            (24U)
/*! SKEW - Whether the TENMS value is exact.
 *  0b0..TENMS value is exact
 *  0b1..TENMS value is not exact or not given
 */
#define SECCON_CPU0STCKCAL_SKEW(x)               (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0STCKCAL_SKEW_SHIFT)) & SECCON_CPU0STCKCAL_SKEW_MASK)

#define SECCON_CPU0STCKCAL_NOREF_MASK            (0x2000000U)
#define SECCON_CPU0STCKCAL_NOREF_SHIFT           (25U)
/*! NOREF - Whether the device provides a reference clock to the processor.
 *  0b0..Reference clock is provided
 *  0b1..No reference clock is provided
 */
#define SECCON_CPU0STCKCAL_NOREF(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_CPU0STCKCAL_NOREF_SHIFT)) & SECCON_CPU0STCKCAL_NOREF_MASK)
/*! @} */

/*! @name MSFCFG - MSF Configuration */
/*! @{ */

#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS0_MASK (0x1U)
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS0_SHIFT (0U)
/*! IFR_BLOCK0_ERASE_DIS0 - user IFR block0 sector 0 erase control
 *  0b0..Enable IFR sector erase.
 *  0b1..Disable IFR sector erase, write one lock until a system reset.
 */
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS0(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS0_SHIFT)) & SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS0_MASK)

#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS1_MASK (0x2U)
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS1_SHIFT (1U)
/*! IFR_BLOCK0_ERASE_DIS1 - user IFR block0 sector 1 erase control
 *  0b0..Enable IFR sector erase.
 *  0b1..Disable IFR sector erase, write one lock until a system reset.
 */
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS1(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS1_SHIFT)) & SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS1_MASK)

#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS2_MASK (0x4U)
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS2_SHIFT (2U)
/*! IFR_BLOCK0_ERASE_DIS2 - user IFR block0 sector 2 erase control
 *  0b0..Enable IFR sector erase.
 *  0b1..Disable IFR sector erase, write one lock until a system reset.
 */
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS2(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS2_SHIFT)) & SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS2_MASK)

#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS3_MASK (0x8U)
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS3_SHIFT (3U)
/*! IFR_BLOCK0_ERASE_DIS3 - user IFR block0 sector 3 erase control
 *  0b0..Enable IFR sector erase.
 *  0b1..Disable IFR sector erase, write one lock until a system reset.
 */
#define SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS3(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS3_SHIFT)) & SECCON_MSFCFG_IFR_BLOCK0_ERASE_DIS3_MASK)

#define SECCON_MSFCFG_MASS_ERASE_DIS_MASK        (0x100U)
#define SECCON_MSFCFG_MASS_ERASE_DIS_SHIFT       (8U)
/*! MASS_ERASE_DIS - Mass erase control
 *  0b0..Enables mass erase
 *  0b1..Disables mass erase, write one lock until a system reset.
 */
#define SECCON_MSFCFG_MASS_ERASE_DIS(x)          (((uint32_t)(((uint32_t)(x)) << SECCON_MSFCFG_MASS_ERASE_DIS_SHIFT)) & SECCON_MSFCFG_MASS_ERASE_DIS_MASK)
/*! @} */

/*! @name CFPA_LC_STATE - CFPA State Register */
/*! @{ */

#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE_MASK  (0xFFFFFFFFU)
#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE_SHIFT (0U)
/*! CFPA_LC_STATE - CFPA state */
#define SECCON_CFPA_LC_STATE_CFPA_LC_STATE(x)    (((uint32_t)(((uint32_t)(x)) << SECCON_CFPA_LC_STATE_CFPA_LC_STATE_SHIFT)) & SECCON_CFPA_LC_STATE_CFPA_LC_STATE_MASK)
/*! @} */

/*! @name RAM_XEN - RAM XEN Control */
/*! @{ */

#define SECCON_RAM_XEN_RAMA0_XEN_MASK            (0x4U)
#define SECCON_RAM_XEN_RAMA0_XEN_SHIFT           (2U)
/*! RAMA0_XEN - RAMA0 Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SECCON_RAM_XEN_RAMA0_XEN(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_RAM_XEN_RAMA0_XEN_SHIFT)) & SECCON_RAM_XEN_RAMA0_XEN_MASK)

#define SECCON_RAM_XEN_RAMA1_XEN_MASK            (0x8U)
#define SECCON_RAM_XEN_RAMA1_XEN_SHIFT           (3U)
/*! RAMA1_XEN - RAMAx (excepts RAMA0) Execute permission control.
 *  0b0..Execute permission is disabled, R/W are enabled.
 *  0b1..Execute permission is enabled, R/W/X are enabled.
 */
#define SECCON_RAM_XEN_RAMA1_XEN(x)              (((uint32_t)(((uint32_t)(x)) << SECCON_RAM_XEN_RAMA1_XEN_SHIFT)) & SECCON_RAM_XEN_RAMA1_XEN_MASK)

#define SECCON_RAM_XEN_LOCK_MASK                 (0x80000000U)
#define SECCON_RAM_XEN_LOCK_SHIFT                (31U)
/*! LOCK - This 1-bit field provides a mechanism to limit writes to this register (and RAM_XEN_DP)
 *    to protect its contents. Once set, this bit remains asserted until a system reset.
 *  0b0..This register is not locked and can be altered.
 *  0b1..This register is locked and cannot be altered.
 */
#define SECCON_RAM_XEN_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << SECCON_RAM_XEN_LOCK_SHIFT)) & SECCON_RAM_XEN_LOCK_MASK)
/*! @} */

/*! @name RAM_XEN_DP - RAM XEN Control (Duplicate) */
/*! @{ */

#define SECCON_RAM_XEN_DP_RAMA0_XEN_MASK         (0x4U)
#define SECCON_RAM_XEN_DP_RAMA0_XEN_SHIFT        (2U)
/*! RAMA0_XEN - Refer to RAM_XEN for more details. */
#define SECCON_RAM_XEN_DP_RAMA0_XEN(x)           (((uint32_t)(((uint32_t)(x)) << SECCON_RAM_XEN_DP_RAMA0_XEN_SHIFT)) & SECCON_RAM_XEN_DP_RAMA0_XEN_MASK)

#define SECCON_RAM_XEN_DP_RAMA1_XEN_MASK         (0x8U)
#define SECCON_RAM_XEN_DP_RAMA1_XEN_SHIFT        (3U)
/*! RAMA1_XEN - Refer to RAM_XEN for more details. */
#define SECCON_RAM_XEN_DP_RAMA1_XEN(x)           (((uint32_t)(((uint32_t)(x)) << SECCON_RAM_XEN_DP_RAMA1_XEN_SHIFT)) & SECCON_RAM_XEN_DP_RAMA1_XEN_MASK)
/*! @} */

/*! @name ELS_OTP_LC_STATE - Life Cycle State Register */
/*! @{ */

#define SECCON_ELS_OTP_LC_STATE_OTP_LC_STATE_MASK (0xFFU)
#define SECCON_ELS_OTP_LC_STATE_OTP_LC_STATE_SHIFT (0U)
/*! OTP_LC_STATE - OTP life cycle state */
#define SECCON_ELS_OTP_LC_STATE_OTP_LC_STATE(x)  (((uint32_t)(((uint32_t)(x)) << SECCON_ELS_OTP_LC_STATE_OTP_LC_STATE_SHIFT)) & SECCON_ELS_OTP_LC_STATE_OTP_LC_STATE_MASK)
/*! @} */

/*! @name ELS_OTP_LC_STATE_DP - Life Cycle State Register (Duplicate) */
/*! @{ */

#define SECCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_MASK (0xFFU)
#define SECCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_SHIFT (0U)
/*! OTP_LC_STATE_DP - OTP life cycle state */
#define SECCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP(x) (((uint32_t)(((uint32_t)(x)) << SECCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_SHIFT)) & SECCON_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_MASK)
/*! @} */

/*! @name DEBUG_LOCK_EN - Control Write Access to Security */
/*! @{ */

#define SECCON_DEBUG_LOCK_EN_LOCK_ALL_MASK       (0xFU)
#define SECCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT      (0U)
/*! LOCK_ALL - Controls write access to the security registers
 *  0b0000..Any other value than b1010: disables write access to all registers
 *  0b1010..Enables write access to all registers
 */
#define SECCON_DEBUG_LOCK_EN_LOCK_ALL(x)         (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_LOCK_EN_LOCK_ALL_SHIFT)) & SECCON_DEBUG_LOCK_EN_LOCK_ALL_MASK)
/*! @} */

/*! @name DEBUG_FEATURES - Cortex Debug Features Control */
/*! @{ */

#define SECCON_DEBUG_FEATURES_CPU0_DBGEN_MASK    (0x3U)
#define SECCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT   (0U)
/*! CPU0_DBGEN - CPU0 invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SECCON_DEBUG_FEATURES_CPU0_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURES_CPU0_DBGEN_SHIFT)) & SECCON_DEBUG_FEATURES_CPU0_DBGEN_MASK)

#define SECCON_DEBUG_FEATURES_CPU0_NIDEN_MASK    (0xCU)
#define SECCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT   (2U)
/*! CPU0_NIDEN - CPU0 non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SECCON_DEBUG_FEATURES_CPU0_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURES_CPU0_NIDEN_SHIFT)) & SECCON_DEBUG_FEATURES_CPU0_NIDEN_MASK)
/*! @} */

/*! @name DEBUG_FEATURES_DP - Cortex Debug Features Control (Duplicate) */
/*! @{ */

#define SECCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK (0x3U)
#define SECCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT (0U)
/*! CPU0_DBGEN - CPU0 invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SECCON_DEBUG_FEATURES_DP_CPU0_DBGEN(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT)) & SECCON_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK)

#define SECCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK (0xCU)
#define SECCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT (2U)
/*! CPU0_NIDEN - CPU0 non-invasive debug control
 *  0b01..Disables debug
 *  0b10..Enables debug
 */
#define SECCON_DEBUG_FEATURES_DP_CPU0_NIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SECCON_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT)) & SECCON_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU0 - CPU0 Software Debug Access */
/*! @{ */

#define SECCON_SWD_ACCESS_CPU0_SEC_CODE_MASK     (0xFFFFFFFFU)
#define SECCON_SWD_ACCESS_CPU0_SEC_CODE_SHIFT    (0U)
/*! SEC_CODE - CPU0 SWD-AP: 0x12345678
 *  0b00000000000000000000000000000000..CPU0 DAP is not allowed. Reading back register is read as 0x5.
 *  0b00010010001101000101011001111000..Value to write to enable CPU0 SWD access. Reading back register is read as 0xA.
 */
#define SECCON_SWD_ACCESS_CPU0_SEC_CODE(x)       (((uint32_t)(((uint32_t)(x)) << SECCON_SWD_ACCESS_CPU0_SEC_CODE_SHIFT)) & SECCON_SWD_ACCESS_CPU0_SEC_CODE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SECCON_Register_Masks */


/*!
 * @}
 */ /* end of group SECCON_Peripheral_Access_Layer */


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


#endif  /* PERI_SECCON_H_ */

