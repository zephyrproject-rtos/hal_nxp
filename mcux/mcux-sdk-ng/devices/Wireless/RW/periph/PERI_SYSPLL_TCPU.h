/*
** ###################################################################
**     Processors:          RW610ETA2I
**                          RW610HNA2I
**                          RW610UKA2I
**                          RW612ETA2I
**                          RW612HNA2I
**                          RW612UKA2I
**
**     Version:             rev. 1.0, 2021-03-16
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSPLL_TCPU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-16)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file SYSPLL_TCPU.h
 * @version 1.0
 * @date 2021-03-16
 * @brief CMSIS Peripheral Access Layer for SYSPLL_TCPU
 *
 * CMSIS Peripheral Access Layer for SYSPLL_TCPU
 */

#if !defined(SYSPLL_TCPU_H_)
#define SYSPLL_TCPU_H_                           /**< Symbol preventing repeated inclusion */

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
   -- SYSPLL_TCPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPLL_TCPU_Peripheral_Access_Layer SYSPLL_TCPU Peripheral Access Layer
 * @{
 */

/** SYSPLL_TCPU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[224];
  __I  uint8_t SYSBYPASS_SOC_CTRL_ONE_RO_REG;      /**< offset: 0xE0 */
  __I  uint8_t SYSBYPASS_SOC_CTRL_TWO_RO_REG;      /**< offset: 0xE1 */
  __I  uint8_t SYSBYPASS_SOC_CTRL_THREE_RO_REG;    /**< offset: 0xE2 */
  __I  uint8_t REG_RO_REG;                         /**< offset: 0xE3 */
  __IO uint8_t SYS_CTRL_REG;                       /**< offset: 0xE4 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_ONE_RW_REG;      /**< offset: 0xE5 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_TWO_RW_REG;      /**< offset: 0xE6 */
  __IO uint8_t SYSBYPASS_SOC_CTRL_THREE_RW_REG;    /**< offset: 0xE7 */
  __IO uint8_t TCPU_CTRL_ONE_REG;                  /**< offset: 0xE8 */
  __IO uint8_t TCPU_CTRL_TWO_REG;                  /**< offset: 0xE9 */
  __IO uint8_t TCPU_CTRL_THREE_REG;                /**< offset: 0xEA */
  __IO uint8_t TCPU_CTRL_FOUR_REG;                 /**< offset: 0xEB */
  __IO uint8_t TCPU_CTRL_FIVE_REG;                 /**< offset: 0xEC */
  __IO uint8_t TCPU_CTRL_SIX_REG;                  /**< offset: 0xED */
  __IO uint8_t CLKTREE_CTRL_ONE_REG;               /**< offset: 0xEE */
  __IO uint8_t CLKTREE_CTRL_TWO_REG;               /**< offset: 0xEF */
  __IO uint8_t GPIO_CTRL_REG;                      /**< offset: 0xF0 */
  __IO uint8_t ATEST_CTRL_REG;                     /**< offset: 0xF1 */
  __IO uint8_t RESERVED_LO_REG;                    /**< offset: 0xF2 */
  __IO uint8_t RESERVED_HI_REG;                    /**< offset: 0xF3 */
} SYSPLL_TCPU_Type;

/* ----------------------------------------------------------------------------
   -- SYSPLL_TCPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSPLL_TCPU_Register_Masks SYSPLL_TCPU Register Masks
 * @{
 */

/*! @name SYSBYPASS_SOC_CTRL_ONE_RO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_MASK (0xFFU)
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_ONE_RO - SYSBYPASS_SOC_CTRL_ONE_RO */
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_SHIFT)) & SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RO_REG_SYSBYPASS_SOC_CTRL_ONE_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_TWO_RO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_MASK (0xFFU)
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_TWO_RO - SYSBYPASS_SOC_CTRL_TWO_RO */
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_SHIFT)) & SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RO_REG_SYSBYPASS_SOC_CTRL_TWO_RO_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_THREE_RO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_MASK (0xFFU)
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_THREE_RO - SYSBYPASS_SOC_CTRL_THREE_RO */
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_SHIFT)) & SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RO_REG_SYSBYPASS_SOC_CTRL_THREE_RO_MASK)
/*! @} */

/*! @name REG_RO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_REG_RO_REG_REG_RO_MASK       (0xFFU)
#define SYSPLL_TCPU_REG_RO_REG_REG_RO_SHIFT      (0U)
/*! REG_RO - REG_RO */
#define SYSPLL_TCPU_REG_RO_REG_REG_RO(x)         (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_REG_RO_REG_REG_RO_SHIFT)) & SYSPLL_TCPU_REG_RO_REG_REG_RO_MASK)
/*! @} */

/*! @name SYS_CTRL_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYS_CTRL_REG_SYS_CTRL_MASK   (0xFFU)
#define SYSPLL_TCPU_SYS_CTRL_REG_SYS_CTRL_SHIFT  (0U)
/*! SYS_CTRL - SYS_CTRL */
#define SYSPLL_TCPU_SYS_CTRL_REG_SYS_CTRL(x)     (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYS_CTRL_REG_SYS_CTRL_SHIFT)) & SYSPLL_TCPU_SYS_CTRL_REG_SYS_CTRL_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_ONE_RW_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_MASK (0xFFU)
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_ONE_RW - SYSBYPASS_SOC_CTRL_ONE_RW */
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_SHIFT)) & SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_ONE_RW_REG_SYSBYPASS_SOC_CTRL_ONE_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_TWO_RW_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_MASK (0xFFU)
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_TWO_RW - SYSBYPASS_SOC_CTRL_TWO_RW */
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_SHIFT)) & SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_TWO_RW_REG_SYSBYPASS_SOC_CTRL_TWO_RW_MASK)
/*! @} */

/*! @name SYSBYPASS_SOC_CTRL_THREE_RW_REG -  */
/*! @{ */

#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_MASK (0xFFU)
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_SHIFT (0U)
/*! SYSBYPASS_SOC_CTRL_THREE_RW - SYSBYPASS_SOC_CTRL_THREE_RW */
#define SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_SHIFT)) & SYSPLL_TCPU_SYSBYPASS_SOC_CTRL_THREE_RW_REG_SYSBYPASS_SOC_CTRL_THREE_RW_MASK)
/*! @} */

/*! @name TCPU_CTRL_ONE_REG -  */
/*! @{ */

#define SYSPLL_TCPU_TCPU_CTRL_ONE_REG_TCPU_CTRL_ONE_MASK (0xFFU)
#define SYSPLL_TCPU_TCPU_CTRL_ONE_REG_TCPU_CTRL_ONE_SHIFT (0U)
/*! TCPU_CTRL_ONE - TCPU_CTRL_ONE */
#define SYSPLL_TCPU_TCPU_CTRL_ONE_REG_TCPU_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_TCPU_CTRL_ONE_REG_TCPU_CTRL_ONE_SHIFT)) & SYSPLL_TCPU_TCPU_CTRL_ONE_REG_TCPU_CTRL_ONE_MASK)
/*! @} */

/*! @name TCPU_CTRL_TWO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_TCPU_CTRL_TWO_REG_TCPU_CTRL_TWO_MASK (0xFFU)
#define SYSPLL_TCPU_TCPU_CTRL_TWO_REG_TCPU_CTRL_TWO_SHIFT (0U)
/*! TCPU_CTRL_TWO - TCPU_CTRL_TWO */
#define SYSPLL_TCPU_TCPU_CTRL_TWO_REG_TCPU_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_TCPU_CTRL_TWO_REG_TCPU_CTRL_TWO_SHIFT)) & SYSPLL_TCPU_TCPU_CTRL_TWO_REG_TCPU_CTRL_TWO_MASK)
/*! @} */

/*! @name TCPU_CTRL_THREE_REG -  */
/*! @{ */

#define SYSPLL_TCPU_TCPU_CTRL_THREE_REG_TCPU_CTRL_THREE_MASK (0xFFU)
#define SYSPLL_TCPU_TCPU_CTRL_THREE_REG_TCPU_CTRL_THREE_SHIFT (0U)
/*! TCPU_CTRL_THREE - TCPU_CTRL_THREE */
#define SYSPLL_TCPU_TCPU_CTRL_THREE_REG_TCPU_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_TCPU_CTRL_THREE_REG_TCPU_CTRL_THREE_SHIFT)) & SYSPLL_TCPU_TCPU_CTRL_THREE_REG_TCPU_CTRL_THREE_MASK)
/*! @} */

/*! @name TCPU_CTRL_FOUR_REG -  */
/*! @{ */

#define SYSPLL_TCPU_TCPU_CTRL_FOUR_REG_TCPU_CTRL_FOUR_MASK (0xFFU)
#define SYSPLL_TCPU_TCPU_CTRL_FOUR_REG_TCPU_CTRL_FOUR_SHIFT (0U)
/*! TCPU_CTRL_FOUR - TCPU_CTRL_FOUR */
#define SYSPLL_TCPU_TCPU_CTRL_FOUR_REG_TCPU_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_TCPU_CTRL_FOUR_REG_TCPU_CTRL_FOUR_SHIFT)) & SYSPLL_TCPU_TCPU_CTRL_FOUR_REG_TCPU_CTRL_FOUR_MASK)
/*! @} */

/*! @name TCPU_CTRL_FIVE_REG -  */
/*! @{ */

#define SYSPLL_TCPU_TCPU_CTRL_FIVE_REG_TCPU_CTRL_FIVE_MASK (0xFFU)
#define SYSPLL_TCPU_TCPU_CTRL_FIVE_REG_TCPU_CTRL_FIVE_SHIFT (0U)
/*! TCPU_CTRL_FIVE - TCPU_CTRL_FIVE */
#define SYSPLL_TCPU_TCPU_CTRL_FIVE_REG_TCPU_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_TCPU_CTRL_FIVE_REG_TCPU_CTRL_FIVE_SHIFT)) & SYSPLL_TCPU_TCPU_CTRL_FIVE_REG_TCPU_CTRL_FIVE_MASK)
/*! @} */

/*! @name TCPU_CTRL_SIX_REG -  */
/*! @{ */

#define SYSPLL_TCPU_TCPU_CTRL_SIX_REG_TCPU_CTRL_SIX_MASK (0xFFU)
#define SYSPLL_TCPU_TCPU_CTRL_SIX_REG_TCPU_CTRL_SIX_SHIFT (0U)
/*! TCPU_CTRL_SIX - TCPU_CTRL_SIX */
#define SYSPLL_TCPU_TCPU_CTRL_SIX_REG_TCPU_CTRL_SIX(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_TCPU_CTRL_SIX_REG_TCPU_CTRL_SIX_SHIFT)) & SYSPLL_TCPU_TCPU_CTRL_SIX_REG_TCPU_CTRL_SIX_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_ONE_REG -  */
/*! @{ */

#define SYSPLL_TCPU_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_MASK (0xFFU)
#define SYSPLL_TCPU_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_SHIFT (0U)
/*! CLKTREE_CTRL_ONE - CLKTREE_CTRL_ONE */
#define SYSPLL_TCPU_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_SHIFT)) & SYSPLL_TCPU_CLKTREE_CTRL_ONE_REG_CLKTREE_CTRL_ONE_MASK)
/*! @} */

/*! @name CLKTREE_CTRL_TWO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_MASK (0xFFU)
#define SYSPLL_TCPU_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_SHIFT (0U)
/*! CLKTREE_CTRL_TWO - CLKTREE_CTRL_TWO */
#define SYSPLL_TCPU_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_SHIFT)) & SYSPLL_TCPU_CLKTREE_CTRL_TWO_REG_CLKTREE_CTRL_TWO_MASK)
/*! @} */

/*! @name GPIO_CTRL_REG -  */
/*! @{ */

#define SYSPLL_TCPU_GPIO_CTRL_REG_GPIO_CTRL_MASK (0xFFU)
#define SYSPLL_TCPU_GPIO_CTRL_REG_GPIO_CTRL_SHIFT (0U)
/*! GPIO_CTRL - GPIO_CTRL */
#define SYSPLL_TCPU_GPIO_CTRL_REG_GPIO_CTRL(x)   (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_GPIO_CTRL_REG_GPIO_CTRL_SHIFT)) & SYSPLL_TCPU_GPIO_CTRL_REG_GPIO_CTRL_MASK)
/*! @} */

/*! @name ATEST_CTRL_REG -  */
/*! @{ */

#define SYSPLL_TCPU_ATEST_CTRL_REG_ATEST_CTRL_MASK (0xFFU)
#define SYSPLL_TCPU_ATEST_CTRL_REG_ATEST_CTRL_SHIFT (0U)
/*! ATEST_CTRL - ATEST_CTRL */
#define SYSPLL_TCPU_ATEST_CTRL_REG_ATEST_CTRL(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_ATEST_CTRL_REG_ATEST_CTRL_SHIFT)) & SYSPLL_TCPU_ATEST_CTRL_REG_ATEST_CTRL_MASK)
/*! @} */

/*! @name RESERVED_LO_REG -  */
/*! @{ */

#define SYSPLL_TCPU_RESERVED_LO_REG_RESERVED_LO_MASK (0xFFU)
#define SYSPLL_TCPU_RESERVED_LO_REG_RESERVED_LO_SHIFT (0U)
/*! RESERVED_LO - RESERVED_LO */
#define SYSPLL_TCPU_RESERVED_LO_REG_RESERVED_LO(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_RESERVED_LO_REG_RESERVED_LO_SHIFT)) & SYSPLL_TCPU_RESERVED_LO_REG_RESERVED_LO_MASK)
/*! @} */

/*! @name RESERVED_HI_REG -  */
/*! @{ */

#define SYSPLL_TCPU_RESERVED_HI_REG_RESERVED_HI_MASK (0xFFU)
#define SYSPLL_TCPU_RESERVED_HI_REG_RESERVED_HI_SHIFT (0U)
/*! RESERVED_HI - RESERVED_HI */
#define SYSPLL_TCPU_RESERVED_HI_REG_RESERVED_HI(x) (((uint8_t)(((uint8_t)(x)) << SYSPLL_TCPU_RESERVED_HI_REG_RESERVED_HI_SHIFT)) & SYSPLL_TCPU_RESERVED_HI_REG_RESERVED_HI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSPLL_TCPU_Register_Masks */


/*!
 * @}
 */ /* end of group SYSPLL_TCPU_Peripheral_Access_Layer */


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


#endif  /* SYSPLL_TCPU_H_ */

