/*
** ###################################################################
**     Processors:          RW610ETA2I
**                          RW610HNA2I
**                          RW610UKA2I
**                          RW612ETA2I
**                          RW612HNA2I
**                          RW612UKA2I
**
**     Version:             rev. 3.0, 2025-04-07
**     Build:               b250519
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSPLL_T3
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**     - rev. 3.0 (2025-04-07)
**         Based on CRR Rev9.1.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSPLL_T3.h
 * @version 3.0
 * @date 2025-04-07
 * @brief CMSIS Peripheral Access Layer for SYSPLL_T3
 *
 * CMSIS Peripheral Access Layer for SYSPLL_T3
 */

#if !defined(PERI_SYSPLL_T3_H_)
#define PERI_SYSPLL_T3_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_RW610ETA2I) || defined(CPU_RW610HNA2I) || defined(CPU_RW610UKA2I))
#include "RW610_COMMON.h"
#elif (defined(CPU_RW612ETA2I) || defined(CPU_RW612HNA2I) || defined(CPU_RW612UKA2I))
#include "RW612_COMMON.h"
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
   -- SYSPLL_T3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPLL_T3_Peripheral_Access_Layer SYSPLL_T3 Peripheral Access Layer
 * @{
 */

/** SYSPLL_T3 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[192];
  __I  uint8_t SYSBYPASS_SOC_CTRL_ONE_RO_REG;      /**< SYSBYPASS_SOC_CTRL_ONE_RO_REG, offset: 0xC0 */
  __I  uint8_t SYSBYPASS_SOC_CTRL_TWO_RO_REG;      /**< SYSBYPASS_SOC_CTRL_TWO_RO_REG, offset: 0xC1 */
  __I  uint8_t SYSBYPASS_SOC_CTRL_THREE_RO_REG;    /**< SYSBYPASS_SOC_CTRL_THREE_RO_REG, offset: 0xC2 */
  __I  uint8_t SYSBYPASS_BBUD_CTRL_ONE_RO_REG;     /**< SYSBYPASS_BBUD_CTRL_ONE_RO_REG, offset: 0xC3 */
  __I  uint8_t REG_RO_REG;                         /**< REG_RO_REG, offset: 0xC4 */
  __IO uint8_t SYS_CTRL_REG;                       /**< SYS_CTRL_REG, offset: 0xC5 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_ONE_RW_REG;      /**< SYSBYPASS_SOC_CTRL_ONE_RW_REG, offset: 0xC6 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_TWO_RW_REG;      /**< SYSBYPASS_SOC_CTRL_TWO_RW_REG, offset: 0xC7 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_THREE_RW_REG;    /**< SYSBYPASS_SOC_CTRL_THREE_RW_REG, offset: 0xC8 */
  __IO uint8_t SYSBYPASS_BBUD_CTRL_FOUR_RW_REG;    /**< SYSBYPASS_BBUD_CTRL_FOUR_RW_REG, offset: 0xC9 */
  __IO uint8_t T3_CTRL_ONE_REG;                    /**< T3_CTRL_ONE_REG, offset: 0xCA */
  __IO uint8_t T3_CTRL_TWO_REG;                    /**< T3_CTRL_TWO_REG, offset: 0xCB */
  __IO uint8_t T3_CTRL_THREE_REG;                  /**< T3_CTRL_THREE_REG, offset: 0xCC */
  __IO uint8_t T3_CTRL_FOUR_REG;                   /**< T3_CTRL_FOUR_REG, offset: 0xCD */
  __IO uint8_t T3_CTRL_FIVE_REG;                   /**< T3_CTRL_FIVE_REG, offset: 0xCE */
  __IO uint8_t T3_CTRL_SIX_REG;                    /**< T3_CTRL_SIX_REG, offset: 0xCF */
  __IO uint8_t T3_CTRL_SEVEN_REG;                  /**< T3_CTRL_SEVEN_REG, offset: 0xD0 */
  __IO uint8_t T3_CTRL_EIGHT_REG;                  /**< T3_CTRL_EIGHT_REG, offset: 0xD1 */
  __IO uint8_t T3_CTRL_NINE_REG;                   /**< T3_CTRL_NINE_REG, offset: 0xD2 */
  __IO uint8_t T3_CTRL_TEN_REG;                    /**< T3_CTRL_TEN_REG, offset: 0xD3 */
  __IO uint8_t CLKTREE_CTRL_ONE_REG;               /**< CLKTREE_CTRL_ONE_REG, offset: 0xD4 */
  __IO uint8_t CLKTREE_CTRL_TWO_REG;               /**< CLKTREE_CTRL_TWO_REG, offset: 0xD5 */
  __IO uint8_t CLKTREE_CTRL_THREE_REG;             /**< CLKTREE_CTRL_THREE_REG, offset: 0xD6 */
  __IO uint8_t CLKTREE_CTRL_FOUR_REG;              /**< CLKTREE_CTRL_FOUR_REG, offset: 0xD7 */
  __IO uint8_t CLKTREE_CTRL_FIVE_REG;              /**< CLKTREE_CTRL_FIVE_REG, offset: 0xD8 */
  __IO uint8_t CLKTREE_CTRL_SIX_REG;               /**< CLKTREE_CTRL_SIX_REG, offset: 0xD9 */
  __IO uint8_t GPIO_CTRL_REG;                      /**< GPIO_CTRL_REG, offset: 0xDA */
  __IO uint8_t ATEST_CTRL_REG;                     /**< ATEST_CTRL_REG, offset: 0xDB */
  __IO uint8_t RESERVED_LO_ONE_REG;                /**< RESERVED_LO_ONE_REG, offset: 0xDC */
  __IO uint8_t RESERVED_HI_ONE_REG;                /**< RESERVED_HI_ONE_REG, offset: 0xDD */
  __IO uint8_t RESERVED_MIX_ONE_REG;               /**< RESERVED_MIX_ONE_REG, offset: 0xDE */
  __IO uint8_t RESERVED_MIX_TWO_REG;               /**< RESERVED_MIX_TWO_REG, offset: 0xDF */
} SYSPLL_T3_Type;

/* ----------------------------------------------------------------------------
   -- SYSPLL_T3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPLL_T3_Register_Masks SYSPLL_T3 Register Masks
 * @{
 */

/*! @name SYSBYPASS_SOC_CTRL_ONE_RO_REG - SYSBYPASS_SOC_CTRL_ONE_RO_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_ONE_RO - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_SHIFT)) & SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_TWO_RO_REG - SYSBYPASS_SOC_CTRL_TWO_RO_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_TWO_RO - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_SHIFT)) & SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_THREE_RO_REG - SYSBYPASS_SOC_CTRL_THREE_RO_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_THREE_RO - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_SHIFT)) & SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_BBUD_CTRL_ONE_RO_REG - SYSBYPASS_BBUD_CTRL_ONE_RO_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_BBUD_CTRL_ONE_RO_REG_SYSBYPASS_BBUD_CTRL_FOUR_RO_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_BBUD_CTRL_ONE_RO_REG_SYSBYPASS_BBUD_CTRL_FOUR_RO_SHIFT (0U)
/*! SYSBYPASS_BBUD_CTRL_FOUR_RO - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_BBUD_CTRL_ONE_RO_REG_SYSBYPASS_BBUD_CTRL_FOUR_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_BBUD_CTRL_ONE_RO_REG_SYSBYPASS_BBUD_CTRL_FOUR_RO_SHIFT)) & SYSPLL_T3_SYSBYPASS_BBUD_CTRL_ONE_RO_REG_SYSBYPASS_BBUD_CTRL_FOUR_RO_MASK)
/*! @} */

/*! @name REG_RO_REG - REG_RO_REG */
/*! @{ */

#define SYSPLL_T3_REG_RO_REG_REG_RO_MASK         (0xFFU)
#define SYSPLL_T3_REG_RO_REG_REG_RO_SHIFT        (0U)
/*! REG_RO - Reserved. (Do not change) */
#define SYSPLL_T3_REG_RO_REG_REG_RO(x)           (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_REG_RO_REG_REG_RO_SHIFT)) & SYSPLL_T3_REG_RO_REG_REG_RO_MASK)
/*! @} */

/*! @name SYS_CTRL_REG - SYS_CTRL_REG */
/*! @{ */

#define SYSPLL_T3_SYS_CTRL_REG_SYS_CTRL_MASK     (0xFFU)
#define SYSPLL_T3_SYS_CTRL_REG_SYS_CTRL_SHIFT    (0U)
/*! SYS_CTRL - Reserved. (Do not change) */
#define SYSPLL_T3_SYS_CTRL_REG_SYS_CTRL(x)       (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYS_CTRL_REG_SYS_CTRL_SHIFT)) & SYSPLL_T3_SYS_CTRL_REG_SYS_CTRL_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_ONE_RW_REG - SYSBYPASS_SOC_CTRL_ONE_RW_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_ONE_RW - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_SHIFT)) & SYSPLL_T3_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_TWO_RW_REG - SYSBYPASS_SOC_CTRL_TWO_RW_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_TWO_RW - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_SHIFT)) & SYSPLL_T3_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_THREE_RW_REG - SYSBYPASS_SOC_CTRL_THREE_RW_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_THREE_RW - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_SHIFT)) & SYSPLL_T3_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_BBUD_CTRL_FOUR_RW_REG - SYSBYPASS_BBUD_CTRL_FOUR_RW_REG */
/*! @{ */

#define SYSPLL_T3_SYSBYPASS_BBUD_CTRL_FOUR_RW_REG_SYSBYPASS_BBUD_CTRL_FOUR_RW_MASK (0xFFU)
#define SYSPLL_T3_SYSBYPASS_BBUD_CTRL_FOUR_RW_REG_SYSBYPASS_BBUD_CTRL_FOUR_RW_SHIFT (0U)
/*! SYSBYPASS_BBUD_CTRL_FOUR_RW - Reserved. (Do not change) */
#define SYSPLL_T3_SYSBYPASS_BBUD_CTRL_FOUR_RW_REG_SYSBYPASS_BBUD_CTRL_FOUR_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_SYSBYPASS_BBUD_CTRL_FOUR_RW_REG_SYSBYPASS_BBUD_CTRL_FOUR_RW_SHIFT)) & SYSPLL_T3_SYSBYPASS_BBUD_CTRL_FOUR_RW_REG_SYSBYPASS_BBUD_CTRL_FOUR_RW_MASK)
/*! @} */

/*! @name T3_CTRL_ONE_REG - T3_CTRL_ONE_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_ONE_REG_T3_CTRL_ONE_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_ONE_REG_T3_CTRL_ONE_SHIFT (0U)
/*! T3_CTRL_ONE - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_ONE_REG_T3_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_ONE_REG_T3_CTRL_ONE_SHIFT)) & SYSPLL_T3_T3_CTRL_ONE_REG_T3_CTRL_ONE_MASK)
/*! @} */

/*! @name T3_CTRL_TWO_REG - T3_CTRL_TWO_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_TWO_REG_T3_CTRL_TWO_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_TWO_REG_T3_CTRL_TWO_SHIFT (0U)
/*! T3_CTRL_TWO - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_TWO_REG_T3_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_TWO_REG_T3_CTRL_TWO_SHIFT)) & SYSPLL_T3_T3_CTRL_TWO_REG_T3_CTRL_TWO_MASK)
/*! @} */

/*! @name T3_CTRL_THREE_REG - T3_CTRL_THREE_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_THREE_REG_T3_CTRL_THREE_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_THREE_REG_T3_CTRL_THREE_SHIFT (0U)
/*! T3_CTRL_THREE - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_THREE_REG_T3_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_THREE_REG_T3_CTRL_THREE_SHIFT)) & SYSPLL_T3_T3_CTRL_THREE_REG_T3_CTRL_THREE_MASK)
/*! @} */

/*! @name T3_CTRL_FOUR_REG - T3_CTRL_FOUR_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_FOUR_REG_T3_CTRL_FOUR_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_FOUR_REG_T3_CTRL_FOUR_SHIFT (0U)
/*! T3_CTRL_FOUR - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_FOUR_REG_T3_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_FOUR_REG_T3_CTRL_FOUR_SHIFT)) & SYSPLL_T3_T3_CTRL_FOUR_REG_T3_CTRL_FOUR_MASK)
/*! @} */

/*! @name T3_CTRL_FIVE_REG - T3_CTRL_FIVE_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_FIVE_REG_T3_CTRL_FIVE_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_FIVE_REG_T3_CTRL_FIVE_SHIFT (0U)
/*! T3_CTRL_FIVE - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_FIVE_REG_T3_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_FIVE_REG_T3_CTRL_FIVE_SHIFT)) & SYSPLL_T3_T3_CTRL_FIVE_REG_T3_CTRL_FIVE_MASK)
/*! @} */

/*! @name T3_CTRL_SIX_REG - T3_CTRL_SIX_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_SIX_REG_T3_CTRL_SIX_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_SIX_REG_T3_CTRL_SIX_SHIFT (0U)
/*! T3_CTRL_SIX - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_SIX_REG_T3_CTRL_SIX(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_SIX_REG_T3_CTRL_SIX_SHIFT)) & SYSPLL_T3_T3_CTRL_SIX_REG_T3_CTRL_SIX_MASK)
/*! @} */

/*! @name T3_CTRL_SEVEN_REG - T3_CTRL_SEVEN_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_SEVEN_REG_T3_CTRL_SEVEN_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_SEVEN_REG_T3_CTRL_SEVEN_SHIFT (0U)
/*! T3_CTRL_SEVEN - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_SEVEN_REG_T3_CTRL_SEVEN(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_SEVEN_REG_T3_CTRL_SEVEN_SHIFT)) & SYSPLL_T3_T3_CTRL_SEVEN_REG_T3_CTRL_SEVEN_MASK)
/*! @} */

/*! @name T3_CTRL_EIGHT_REG - T3_CTRL_EIGHT_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_EIGHT_REG_T3_CTRL_EIGHT_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_EIGHT_REG_T3_CTRL_EIGHT_SHIFT (0U)
/*! T3_CTRL_EIGHT - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_EIGHT_REG_T3_CTRL_EIGHT(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_EIGHT_REG_T3_CTRL_EIGHT_SHIFT)) & SYSPLL_T3_T3_CTRL_EIGHT_REG_T3_CTRL_EIGHT_MASK)
/*! @} */

/*! @name T3_CTRL_NINE_REG - T3_CTRL_NINE_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_NINE_REG_T3_CTRL_NINE_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_NINE_REG_T3_CTRL_NINE_SHIFT (0U)
/*! T3_CTRL_NINE - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_NINE_REG_T3_CTRL_NINE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_NINE_REG_T3_CTRL_NINE_SHIFT)) & SYSPLL_T3_T3_CTRL_NINE_REG_T3_CTRL_NINE_MASK)
/*! @} */

/*! @name T3_CTRL_TEN_REG - T3_CTRL_TEN_REG */
/*! @{ */

#define SYSPLL_T3_T3_CTRL_TEN_REG_T3_CTRL_TEN_MASK (0xFFU)
#define SYSPLL_T3_T3_CTRL_TEN_REG_T3_CTRL_TEN_SHIFT (0U)
/*! T3_CTRL_TEN - Reserved. (Do not change) */
#define SYSPLL_T3_T3_CTRL_TEN_REG_T3_CTRL_TEN(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_T3_CTRL_TEN_REG_T3_CTRL_TEN_SHIFT)) & SYSPLL_T3_T3_CTRL_TEN_REG_T3_CTRL_TEN_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_ONE_REG - CLKTREE_CTRL_ONE_REG */
/*! @{ */

#define SYSPLL_T3_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_MASK (0xFFU)
#define SYSPLL_T3_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_SHIFT (0U)
/*! CLKTREE_CTRL_ONE - Reserved. (Do not change) */
#define SYSPLL_T3_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_TWO_REG - CLKTREE_CTRL_TWO_REG */
/*! @{ */

#define SYSPLL_T3_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_MASK (0xFFU)
#define SYSPLL_T3_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_SHIFT (0U)
/*! CLKTREE_CTRL_TWO - Reserved. (Do not change) */
#define SYSPLL_T3_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_THREE_REG - CLKTREE_CTRL_THREE_REG */
/*! @{ */

#define SYSPLL_T3_CLKTREE_CTRL_THREE_REG_CLKTREE_CTRL_THREE_MASK (0xFFU)
#define SYSPLL_T3_CLKTREE_CTRL_THREE_REG_CLKTREE_CTRL_THREE_SHIFT (0U)
/*! CLKTREE_CTRL_THREE - Reserved. (Do not change) */
#define SYSPLL_T3_CLKTREE_CTRL_THREE_REG_CLKTREE_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_THREE_REG_CLKTREE_CTRL_THREE_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_THREE_REG_CLKTREE_CTRL_THREE_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_FOUR_REG - CLKTREE_CTRL_FOUR_REG */
/*! @{ */

#define SYSPLL_T3_CLKTREE_CTRL_FOUR_REG_CLKTREE_CTRL_FOUR_MASK (0xFFU)
#define SYSPLL_T3_CLKTREE_CTRL_FOUR_REG_CLKTREE_CTRL_FOUR_SHIFT (0U)
/*! CLKTREE_CTRL_FOUR - Reserved. (Do not change) */
#define SYSPLL_T3_CLKTREE_CTRL_FOUR_REG_CLKTREE_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_FOUR_REG_CLKTREE_CTRL_FOUR_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_FOUR_REG_CLKTREE_CTRL_FOUR_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_FIVE_REG - CLKTREE_CTRL_FIVE_REG */
/*! @{ */

#define SYSPLL_T3_CLKTREE_CTRL_FIVE_REG_CLKTREE_CTRL_FIVE_MASK (0xFFU)
#define SYSPLL_T3_CLKTREE_CTRL_FIVE_REG_CLKTREE_CTRL_FIVE_SHIFT (0U)
/*! CLKTREE_CTRL_FIVE - Reserved. (Do not change) */
#define SYSPLL_T3_CLKTREE_CTRL_FIVE_REG_CLKTREE_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_FIVE_REG_CLKTREE_CTRL_FIVE_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_FIVE_REG_CLKTREE_CTRL_FIVE_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_SIX_REG - CLKTREE_CTRL_SIX_REG */
/*! @{ */

#define SYSPLL_T3_CLKTREE_CTRL_SIX_REG_TUNE_MCI_60MHZ_MASK (0xFU)
#define SYSPLL_T3_CLKTREE_CTRL_SIX_REG_TUNE_MCI_60MHZ_SHIFT (0U)
/*! TUNE_MCI_60MHZ - Tune MCI_60MHz. 0x5: 59.53 MHz, 0xA: 48.30 MHz */
#define SYSPLL_T3_CLKTREE_CTRL_SIX_REG_TUNE_MCI_60MHZ(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_SIX_REG_TUNE_MCI_60MHZ_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_SIX_REG_TUNE_MCI_60MHZ_MASK)

#define SYSPLL_T3_CLKTREE_CTRL_SIX_REG_RESERVED_MASK (0xF0U)
#define SYSPLL_T3_CLKTREE_CTRL_SIX_REG_RESERVED_SHIFT (4U)
/*! RESERVED - Reserved. (Do not change) */
#define SYSPLL_T3_CLKTREE_CTRL_SIX_REG_RESERVED(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_CLKTREE_CTRL_SIX_REG_RESERVED_SHIFT)) & SYSPLL_T3_CLKTREE_CTRL_SIX_REG_RESERVED_MASK)
/*! @} */

/*! @name GPIO_CTRL_REG - GPIO_CTRL_REG */
/*! @{ */

#define SYSPLL_T3_GPIO_CTRL_REG_GPIO_CTRL_MASK   (0xFFU)
#define SYSPLL_T3_GPIO_CTRL_REG_GPIO_CTRL_SHIFT  (0U)
/*! GPIO_CTRL - Reserved. (Do not change) */
#define SYSPLL_T3_GPIO_CTRL_REG_GPIO_CTRL(x)     (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_GPIO_CTRL_REG_GPIO_CTRL_SHIFT)) & SYSPLL_T3_GPIO_CTRL_REG_GPIO_CTRL_MASK)
/*! @} */

/*! @name ATEST_CTRL_REG - ATEST_CTRL_REG */
/*! @{ */

#define SYSPLL_T3_ATEST_CTRL_REG_ATEST_CTRL_MASK (0xFFU)
#define SYSPLL_T3_ATEST_CTRL_REG_ATEST_CTRL_SHIFT (0U)
/*! ATEST_CTRL - Reserved. (Do not change) */
#define SYSPLL_T3_ATEST_CTRL_REG_ATEST_CTRL(x)   (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_ATEST_CTRL_REG_ATEST_CTRL_SHIFT)) & SYSPLL_T3_ATEST_CTRL_REG_ATEST_CTRL_MASK)
/*! @} */

/*! @name RESERVED_LO_ONE_REG - RESERVED_LO_ONE_REG */
/*! @{ */

#define SYSPLL_T3_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_MASK (0xFFU)
#define SYSPLL_T3_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_SHIFT (0U)
/*! RESERVED_LO_ONE - Reserved. (Do not change) */
#define SYSPLL_T3_RESERVED_LO_ONE_REG_RESERVED_LO_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_SHIFT)) & SYSPLL_T3_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_MASK)
/*! @} */

/*! @name RESERVED_HI_ONE_REG - RESERVED_HI_ONE_REG */
/*! @{ */

#define SYSPLL_T3_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_MASK (0xFFU)
#define SYSPLL_T3_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_SHIFT (0U)
/*! RESERVED_HI_ONE - Reserved. (Do not change) */
#define SYSPLL_T3_RESERVED_HI_ONE_REG_RESERVED_HI_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_SHIFT)) & SYSPLL_T3_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_MASK)
/*! @} */

/*! @name RESERVED_MIX_ONE_REG - RESERVED_MIX_ONE_REG */
/*! @{ */

#define SYSPLL_T3_RESERVED_MIX_ONE_REG_RESERVED_MIX_ONE_MASK (0xFFU)
#define SYSPLL_T3_RESERVED_MIX_ONE_REG_RESERVED_MIX_ONE_SHIFT (0U)
/*! RESERVED_MIX_ONE - Reserved. (Do not change) */
#define SYSPLL_T3_RESERVED_MIX_ONE_REG_RESERVED_MIX_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_RESERVED_MIX_ONE_REG_RESERVED_MIX_ONE_SHIFT)) & SYSPLL_T3_RESERVED_MIX_ONE_REG_RESERVED_MIX_ONE_MASK)
/*! @} */

/*! @name RESERVED_MIX_TWO_REG - RESERVED_MIX_TWO_REG */
/*! @{ */

#define SYSPLL_T3_RESERVED_MIX_TWO_REG_RESERVED_MIX_TWO_MASK (0xFFU)
#define SYSPLL_T3_RESERVED_MIX_TWO_REG_RESERVED_MIX_TWO_SHIFT (0U)
/*! RESERVED_MIX_TWO - Reserved. (Do not change) */
#define SYSPLL_T3_RESERVED_MIX_TWO_REG_RESERVED_MIX_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_T3_RESERVED_MIX_TWO_REG_RESERVED_MIX_TWO_SHIFT)) & SYSPLL_T3_RESERVED_MIX_TWO_REG_RESERVED_MIX_TWO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSPLL_T3_Register_Masks */


/*!
 * @}
 */ /* end of group SYSPLL_T3_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSPLL_T3_H_ */

