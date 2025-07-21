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
**         CMSIS Peripheral Access Layer for SYSCTL
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
 * @file PERI_SYSCTL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCTL
 *
 * CMSIS Peripheral Access Layer for SYSCTL
 */

#if !defined(PERI_SYSCTL_H_)
#define PERI_SYSCTL_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SYSCTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL_Peripheral_Access_Layer SYSCTL Peripheral Access Layer
 * @{
 */

/** SYSCTL - Register Layout Typedef */
typedef struct {
  __IO uint32_t UPDATELCKOUT;                      /**< update lock out control, offset: 0x0 */
       uint8_t RESERVED_0[252];
  __IO uint32_t AUX_FLASH_CTRL;                    /**< Auxiliary flash control, offset: 0x100 */
       uint8_t RESERVED_1[124];
  __IO uint32_t CODE_GRAY_LSB;                     /**< CODE_GRAY LSB input Register, offset: 0x180 */
  __IO uint32_t CODE_GRAY_MSB;                     /**< CODE_GRAY MSB input Register, offset: 0x184 */
  __I  uint32_t CODE_BIN_LSB;                      /**< CODE_BIN LSB output Register, offset: 0x188 */
  __I  uint32_t CODE_BIN_MSB;                      /**< CODE_BIN MSB output Register, offset: 0x18C */
       uint8_t RESERVED_2[112];
  __IO uint32_t AUX_RNG_CTRL;                      /**< Auxiliary Random Number Generator Control, offset: 0x200 */
       uint8_t RESERVED_3[4];
  __I  uint32_t AUX_RNG_STATUS;                    /**< Auxiliary Random Number Generator Status, offset: 0x208 */
} SYSCTL_Type;

/* ----------------------------------------------------------------------------
   -- SYSCTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL_Register_Masks SYSCTL Register Masks
 * @{
 */

/*! @name UPDATELCKOUT - update lock out control */
/*! @{ */

#define SYSCTL_UPDATELCKOUT_UPDATELCKOUT_MASK    (0x1U)
#define SYSCTL_UPDATELCKOUT_UPDATELCKOUT_SHIFT   (0U)
/*! UPDATELCKOUT - All Registers
 *  0b0..Normal Mode. Can be written to.
 *  0b1..Protected Mode. Cannot be written to.
 */
#define SYSCTL_UPDATELCKOUT_UPDATELCKOUT(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_UPDATELCKOUT_UPDATELCKOUT_SHIFT)) & SYSCTL_UPDATELCKOUT_UPDATELCKOUT_MASK)
/*! @} */

/*! @name AUX_FLASH_CTRL - Auxiliary flash control */
/*! @{ */

#define SYSCTL_AUX_FLASH_CTRL_FLASH_STALL_EN_MASK (0x1U)
#define SYSCTL_AUX_FLASH_CTRL_FLASH_STALL_EN_SHIFT (0U)
/*! FLASH_STALL_EN - Flash stall enable
 *  0b0..Flash busy will terminate in an AHB bus error
 *  0b1..Flash busy will stall until the flash is available
 */
#define SYSCTL_AUX_FLASH_CTRL_FLASH_STALL_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_FLASH_STALL_EN_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_FLASH_STALL_EN_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_INST_MASK (0x2U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_INST_SHIFT (1U)
/*! DIS_MBECC_BERR_INST - Bus error on ECC error enable for instruction fetch
 *  0b0..Instruction fetches leading to a flash ECC error will terminate in an AHB bus error
 *  0b1..Instruction fetches leading to a flash ECC error will result in whatever data the flash can return and
 *       will not terminate in an AHB bus error
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_INST(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_INST_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_INST_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA_MASK (0x4U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA_SHIFT (2U)
/*! DIS_MBECC_BERR_DATA - Bus error on ECC error enable for data fetch
 *  0b0..Data fetches leading to a flash ECC error will terminate in an AHB bus error
 *  0b1..Data fetches leading to a flash ECC error will result in whatever data the flash can return and will not terminate in an AHB bus error
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA_MASK)

#define SYSCTL_AUX_FLASH_CTRL_NPX_CLR_STATE_MASK (0x8U)
#define SYSCTL_AUX_FLASH_CTRL_NPX_CLR_STATE_SHIFT (3U)
/*! NPX_CLR_STATE - Clear Program Model Key region
 *  0b0..No operation
 *  0b1..Force clear of all Program Model Key information
 */
#define SYSCTL_AUX_FLASH_CTRL_NPX_CLR_STATE(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_NPX_CLR_STATE_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_NPX_CLR_STATE_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_MASK (0x10U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_SHIFT (4U)
/*! DIS_FLASH_CACHE - Disable all flash cache
 *  0b0..Enable flash cache
 *  0b1..Disable all flash cache
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_INST_MASK (0x20U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_INST_SHIFT (5U)
/*! DIS_FLASH_CACHE_INST - Disable cache for instruction fetches
 *  0b0..Enable instruction fetch cache (if cache enabled)
 *  0b1..Disable instruction fetch cache
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_INST(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_INST_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_INST_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_DATA_MASK (0x40U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_DATA_SHIFT (6U)
/*! DIS_FLASH_CACHE_DATA - Disable cache for data fetches
 *  0b0..Enable data fetch cache (if cache enabled)
 *  0b1..Disable instruction data cache
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_DATA(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_DATA_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_CACHE_DATA_MASK)

#define SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE_MASK (0x80U)
#define SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE_SHIFT (7U)
/*! CLR_FLASH_CACHE - Clear the flash cache
 *  0b0..No operation
 *  0b1..Clear the flash cache
 */
#define SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE(x) (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC_MASK (0x100U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC_SHIFT (8U)
/*! DIS_FLASH_SPEC - Disable and clear the flash speculation buffer
 *  0b0..Enable the use of the speculation buffer
 *  0b1..Disable and clear the flash speculation buffer
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC(x)  (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC_MASK)

#define SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC_MASK (0x200U)
#define SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC_SHIFT (9U)
/*! DIS_DATA_SPEC - Disable and clear the flash speculation buffer for data
 *  0b0..Enable buffering data fetches (if speculation is enabled)
 *  0b1..Disable buffering data fetches (if speculation is enabled)
 */
#define SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC_SHIFT)) & SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC_MASK)
/*! @} */

/*! @name CODE_GRAY_LSB - CODE_GRAY LSB input Register */
/*! @{ */

#define SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_MASK  (0xFFFFFFFFU)
#define SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_SHIFT (0U)
/*! CODE_GRAY_LSB - Gray code (42bits) to be converted back to binary */
#define SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_SHIFT)) & SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_MASK)
/*! @} */

/*! @name CODE_GRAY_MSB - CODE_GRAY MSB input Register */
/*! @{ */

#define SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_MASK  (0x3FFU)
#define SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_SHIFT (0U)
/*! CODE_GRAY_MSB - Gray code (42bits) to be converted back to binary */
#define SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_SHIFT)) & SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_MASK)
/*! @} */

/*! @name CODE_BIN_LSB - CODE_BIN LSB output Register */
/*! @{ */

#define SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_MASK    (0xFFFFFFFFU)
#define SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_SHIFT   (0U)
/*! CODE_BIN_LSB - Binary converted code (42bits) */
#define SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_SHIFT)) & SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_MASK)
/*! @} */

/*! @name CODE_BIN_MSB - CODE_BIN MSB output Register */
/*! @{ */

#define SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_MASK    (0x3FFU)
#define SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_SHIFT   (0U)
/*! CODE_BIN_MSB - Binary converted code (42bits) */
#define SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_SHIFT)) & SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_MASK)
/*! @} */

/*! @name AUX_RNG_CTRL - Auxiliary Random Number Generator Control */
/*! @{ */

#define SYSCTL_AUX_RNG_CTRL_OSC_BYPASS_MASK      (0x1U)
#define SYSCTL_AUX_RNG_CTRL_OSC_BYPASS_SHIFT     (0U)
/*! OSC_BYPASS - Oscillator bypass control
 *  0b0..Oscillator bypass is disabled
 *  0b1..Oscillator bypass is enabled
 */
#define SYSCTL_AUX_RNG_CTRL_OSC_BYPASS(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_RNG_CTRL_OSC_BYPASS_SHIFT)) & SYSCTL_AUX_RNG_CTRL_OSC_BYPASS_MASK)
/*! @} */

/*! @name AUX_RNG_STATUS - Auxiliary Random Number Generator Status */
/*! @{ */

#define SYSCTL_AUX_RNG_STATUS_BUSY_MASK          (0x1U)
#define SYSCTL_AUX_RNG_STATUS_BUSY_SHIFT         (0U)
/*! BUSY - Random Number Generator is busy
 *  0b0..Random Number Generator is not busy
 *  0b1..Random Number Generator is busy
 */
#define SYSCTL_AUX_RNG_STATUS_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_RNG_STATUS_BUSY_SHIFT)) & SYSCTL_AUX_RNG_STATUS_BUSY_MASK)

#define SYSCTL_AUX_RNG_STATUS_HWERR_MASK         (0x2U)
#define SYSCTL_AUX_RNG_STATUS_HWERR_SHIFT        (1U)
/*! HWERR - Random Number Generator signals occurence of a hardware error
 *  0b0..No hardware error detected
 *  0b1..Hardware error detected
 */
#define SYSCTL_AUX_RNG_STATUS_HWERR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL_AUX_RNG_STATUS_HWERR_SHIFT)) & SYSCTL_AUX_RNG_STATUS_HWERR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCTL_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCTL_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCTL_H_ */

