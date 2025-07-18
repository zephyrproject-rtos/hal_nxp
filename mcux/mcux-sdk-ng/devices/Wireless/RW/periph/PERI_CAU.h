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
**         CMSIS Peripheral Access Layer for CAU
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
 * @file PERI_CAU.h
 * @version 3.0
 * @date 2025-04-07
 * @brief CMSIS Peripheral Access Layer for CAU
 *
 * CMSIS Peripheral Access Layer for CAU
 */

#if !defined(PERI_CAU_H_)
#define PERI_CAU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CAU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Peripheral_Access_Layer CAU Peripheral Access Layer
 * @{
 */

/** CAU - Register Layout Typedef */
typedef struct {
  __I  uint8_t BYPASS_SOC_PD_CTRL_RO_REG;          /**< BYPASS_SOC_PD_CTRL_RO_REG, offset: 0x0 */
  __I  uint8_t BYPASS_SOC_CTRL_ONE_RO_REG;         /**< BYPASS_SOC_CTRL_ONE_RO_REG, offset: 0x1 */
  __I  uint8_t BYPASS_SOC_CTRL_TWO_RO_REG;         /**< BYPASS_SOC_CTRL_TWO_RO_REG, offset: 0x2 */
  __I  uint8_t BYPASS_RFU_CTRL_ONE_RO_REG;         /**< BYPASS_RFU_CTRL_ONE_RO_REG, offset: 0x3 */
  __I  uint8_t REG_RO_ONE_REG;                     /**< REG_RO_ONE_REG, offset: 0x4 */
  __I  uint8_t REG_RO_TWO_REG;                     /**< REG_RO_TWO_REG, offset: 0x5 */
  __I  uint8_t REG_RO_THREE_REG;                   /**< REG_RO_THREE_REG, offset: 0x6 */
  __I  uint8_t REG_RO_FOUR_REG;                    /**< REG_RO_FOUR_REG, offset: 0x7 */
  __I  uint8_t REG_RO_FIVE_REG;                    /**< REG_RO_FIVE_REG, offset: 0x8 */
  __I  uint8_t REG_RO_SIX_REG;                     /**< REG_RO_SIX_REG, offset: 0x9 */
  __IO uint8_t SW_RESET_B_REG;                     /**< SW_RESET_B_REG, offset: 0xA */
  __IO uint8_t SYS_CTRL_REG;                       /**< SYS_CTRL_REG, offset: 0xB */
  __IO uint8_t SYS_CTRL_PWR_OPT_SEL_REG;           /**< SYS_CTRL_PWR_OPT_SEL_REG, offset: 0xC */
  __IO uint8_t BYPASS_SOC_PD_CTRL_RW_REG;          /**< BYPASS_SOC_PD_CTRL_RW_REG, offset: 0xD */
  __IO uint8_t BYPASS_SOC_CTRL_ONE_RW_REG;         /**< BYPASS_SOC_CTRL_ONE_RW_REG, offset: 0xE */
  __IO uint8_t BYPASS_SOC_CTRL_TWO_RW_REG;         /**< BYPASS_SOC_CTRL_TWO_RW_REG, offset: 0xF */
  __IO uint8_t BYPASS_RFU_CTRL_ONE_RW_REG;         /**< BYPASS_RFU_CTRL_ONE_RW_REG, offset: 0x10 */
  __IO uint8_t PD_CTRL_ONE_REG;                    /**< PD_CTRL_ONE_REG, offset: 0x11 */
  __IO uint8_t PD_CTRL_TWO_REG;                    /**< PD_CTRL_TWO_REG, offset: 0x12 */
  __IO uint8_t SLP_CTRL_ONE_REG;                   /**< SLP_CTRL_ONE_REG, offset: 0x13 */
  __IO uint8_t SLP_CTRL_TWO_REG;                   /**< SLP_CTRL_TWO_REG, offset: 0x14 */
  __IO uint8_t BG_CTRL_REG;                        /**< BG_CTRL_REG, offset: 0x15 */
  __IO uint8_t CPREG_CTRL_ONE_REG;                 /**< CPREG_CTRL_ONE_REG, offset: 0x16 */
  __IO uint8_t CPREG_CTRL_TWO_REG;                 /**< CPREG_CTRL_TWO_REG, offset: 0x17 */
  __IO uint8_t CPREG_CTRL_THREE_REG;               /**< CPREG_CTRL_THREE_REG, offset: 0x18 */
  __IO uint8_t PSEN_CTRL_ONE_REG;                  /**< PSEN_CTRL_ONE_REG, offset: 0x19 */
  __IO uint8_t PSEN_CTRL_TWO_REG;                  /**< PSEN_CTRL_TWO_REG, offset: 0x1A */
  __IO uint8_t TSEN_CTRL_ONE_REG;                  /**< TSEN_CTRL_ONE_REG, offset: 0x1B */
  __IO uint8_t TSEN_CTRL_THREE_REG;                /**< TSEN_CTRL_THREE_REG, offset: 0x1C */
  __IO uint8_t ADC_CTRL_ONE_REG;                   /**< ADC_CTRL_ONE_REG, offset: 0x1D */
  __IO uint8_t RCAL_CTRL_ONE_REG;                  /**< RCAL_CTRL_ONE_REG, offset: 0x1E */
  __IO uint8_t RCAL_CTRL_TWO_REG;                  /**< RCAL_CTRL_TWO_REG, offset: 0x1F */
  __IO uint8_t XTAL_CTRL_ONE_REG;                  /**< XTAL_CTRL_ONE_REG, offset: 0x20 */
  __IO uint8_t XTAL_CTRL_TWO_REG;                  /**< XTAL_CTRL_TWO_REG, offset: 0x21 */
  __IO uint8_t XTAL_CTRL_THREE_REG;                /**< XTAL_CTRL_THREE_REG, offset: 0x22 */
  __IO uint8_t XTAL_CTRL_FOUR_REG;                 /**< XTAL_CTRL_FOUR_REG, offset: 0x23 */
  __IO uint8_t XTAL_CTRL_FIVE_REG;                 /**< XTAL_CTRL_FIVE_REG, offset: 0x24 */
  __IO uint8_t XTAL_CTRL_SIX_REG;                  /**< XTAL_CTRL_SIX_REG, offset: 0x25 */
  __IO uint8_t XTAL_CTRL_SEVEN_REG;                /**< XTAL_CTRL_SEVEN_REG, offset: 0x26 */
  __IO uint8_t XTAL_CTRL_EIGHT_REG;                /**< XTAL_CTRL_EIGHT_REG, offset: 0x27 */
  __IO uint8_t XTAL_CTRL_NINE_REG;                 /**< XTAL_CTRL_NINE_REG, offset: 0x28 */
  __IO uint8_t XTAL_CTRL_TEN_REG;                  /**< XTAL_CTRL_TEN_REG, offset: 0x29 */
  __IO uint8_t XTAL_CTRL_ELEVEN_REG;               /**< XTAL_CTRL_ELEVEN_REG, offset: 0x2A */
  __IO uint8_t XTAL_CTRL_TWELVE_REG;               /**< XTAL_CTRL_TWELVE_REG, offset: 0x2B */
  __IO uint8_t XTAL_CTRL_THIRTEEN_REG;             /**< XTAL_CTRL_THIRTEEN_REG, offset: 0x2C */
  __IO uint8_t XTAL_CTRL_FOURTEEN_REG;             /**< XTAL_CTRL_FOURTEEN_REG, offset: 0x2D */
  __IO uint8_t XTAL_CTRL_FIFTEEN_REG;              /**< XTAL_CTRL_FIFTEEN_REG, offset: 0x2E */
  __IO uint8_t T1_CTRL_RSVD_HI_REG;                /**< T1_CTRL_RSVD_HI_REG, offset: 0x2F */
  __IO uint8_t T1_CTRL_RSVD_LO_REG;                /**< T1_CTRL_RSVD_LO_REG, offset: 0x30 */
  __IO uint8_t GPIO_CTRL_REG;                      /**< GPIO_CTRL_REG, offset: 0x31 */
  __IO uint8_t ATEST_CTRL_ONE_REG;                 /**< ATEST_CTRL_ONE_REG, offset: 0x32 */
  __IO uint8_t ATEST_CTRL_TWO_REG;                 /**< ATEST_CTRL_TWO_REG, offset: 0x33 */
  __IO uint8_t ATEST_CTRL_THREE_REG;               /**< ATEST_CTRL_THREE_REG, offset: 0x34 */
  __IO uint8_t ATEST_CTRL_FOUR_REG;                /**< ATEST_CTRL_FOUR_REG, offset: 0x35 */
  __IO uint8_t ATEST_CTRL_FIVE_REG;                /**< ATEST_CTRL_FIVE_REG, offset: 0x36 */
  __IO uint8_t ATEST_CTRL_SIX_REG;                 /**< ATEST_CTRL_SIX_REG, offset: 0x37 */
  __IO uint8_t ATEST_CTRL_SEVEN_REG;               /**< ATEST_CTRL_SEVEN_REG, offset: 0x38 */
  __IO uint8_t RESERVED_LO_ONE_REG;                /**< RESERVED_LO_ONE_REG, offset: 0x39 */
  __IO uint8_t RESERVED_LO_TWO_REG;                /**< RESERVED_LO_TWO_REG, offset: 0x3A */
  __IO uint8_t RESERVED_HI_ONE_REG;                /**< RESERVED_HI_ONE_REG, offset: 0x3B */
  __IO uint8_t RESERVED_HI_TWO_REG;                /**< RESERVED_HI_TWO_REG, offset: 0x3C */
} CAU_Type;

/* ----------------------------------------------------------------------------
   -- CAU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Register_Masks CAU Register Masks
 * @{
 */

/*! @name BYPASS_SOC_PD_CTRL_RO_REG - BYPASS_SOC_PD_CTRL_RO_REG */
/*! @{ */

#define CAU_BYPASS_SOC_PD_CTRL_RO_REG_BYPASS_SOC_PD_CTRL_RO_MASK (0xFFU)
#define CAU_BYPASS_SOC_PD_CTRL_RO_REG_BYPASS_SOC_PD_CTRL_RO_SHIFT (0U)
/*! BYPASS_SOC_PD_CTRL_RO - Reserved. (Do not change) */
#define CAU_BYPASS_SOC_PD_CTRL_RO_REG_BYPASS_SOC_PD_CTRL_RO(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_SOC_PD_CTRL_RO_REG_BYPASS_SOC_PD_CTRL_RO_SHIFT)) & CAU_BYPASS_SOC_PD_CTRL_RO_REG_BYPASS_SOC_PD_CTRL_RO_MASK)
/*! @} */

/*! @name BYPASS_SOC_CTRL_ONE_RO_REG - BYPASS_SOC_CTRL_ONE_RO_REG */
/*! @{ */

#define CAU_BYPASS_SOC_CTRL_ONE_RO_REG_BYPASS_SOC_CTRL_ONE_RO_MASK (0xFFU)
#define CAU_BYPASS_SOC_CTRL_ONE_RO_REG_BYPASS_SOC_CTRL_ONE_RO_SHIFT (0U)
/*! BYPASS_SOC_CTRL_ONE_RO - Reserved. (Do not change) */
#define CAU_BYPASS_SOC_CTRL_ONE_RO_REG_BYPASS_SOC_CTRL_ONE_RO(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_SOC_CTRL_ONE_RO_REG_BYPASS_SOC_CTRL_ONE_RO_SHIFT)) & CAU_BYPASS_SOC_CTRL_ONE_RO_REG_BYPASS_SOC_CTRL_ONE_RO_MASK)
/*! @} */

/*! @name BYPASS_SOC_CTRL_TWO_RO_REG - BYPASS_SOC_CTRL_TWO_RO_REG */
/*! @{ */

#define CAU_BYPASS_SOC_CTRL_TWO_RO_REG_BYPASS_SOC_CTRL_TWO_RO_MASK (0xFFU)
#define CAU_BYPASS_SOC_CTRL_TWO_RO_REG_BYPASS_SOC_CTRL_TWO_RO_SHIFT (0U)
/*! BYPASS_SOC_CTRL_TWO_RO - Reserved. (Do not change) */
#define CAU_BYPASS_SOC_CTRL_TWO_RO_REG_BYPASS_SOC_CTRL_TWO_RO(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_SOC_CTRL_TWO_RO_REG_BYPASS_SOC_CTRL_TWO_RO_SHIFT)) & CAU_BYPASS_SOC_CTRL_TWO_RO_REG_BYPASS_SOC_CTRL_TWO_RO_MASK)
/*! @} */

/*! @name BYPASS_RFU_CTRL_ONE_RO_REG - BYPASS_RFU_CTRL_ONE_RO_REG */
/*! @{ */

#define CAU_BYPASS_RFU_CTRL_ONE_RO_REG_BYPASS_RFU_CTRL_ONE_RO_MASK (0xFFU)
#define CAU_BYPASS_RFU_CTRL_ONE_RO_REG_BYPASS_RFU_CTRL_ONE_RO_SHIFT (0U)
/*! BYPASS_RFU_CTRL_ONE_RO - Reserved. (Do not change) */
#define CAU_BYPASS_RFU_CTRL_ONE_RO_REG_BYPASS_RFU_CTRL_ONE_RO(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_RFU_CTRL_ONE_RO_REG_BYPASS_RFU_CTRL_ONE_RO_SHIFT)) & CAU_BYPASS_RFU_CTRL_ONE_RO_REG_BYPASS_RFU_CTRL_ONE_RO_MASK)
/*! @} */

/*! @name REG_RO_ONE_REG - REG_RO_ONE_REG */
/*! @{ */

#define CAU_REG_RO_ONE_REG_REG_RO_ONE_MASK       (0xFFU)
#define CAU_REG_RO_ONE_REG_REG_RO_ONE_SHIFT      (0U)
/*! REG_RO_ONE - Reserved. (Do not change) */
#define CAU_REG_RO_ONE_REG_REG_RO_ONE(x)         (((uint8_t)(((uint8_t)(x)) << CAU_REG_RO_ONE_REG_REG_RO_ONE_SHIFT)) & CAU_REG_RO_ONE_REG_REG_RO_ONE_MASK)
/*! @} */

/*! @name REG_RO_TWO_REG - REG_RO_TWO_REG */
/*! @{ */

#define CAU_REG_RO_TWO_REG_REG_RO_TWO_MASK       (0xFFU)
#define CAU_REG_RO_TWO_REG_REG_RO_TWO_SHIFT      (0U)
/*! REG_RO_TWO - Reserved. (Do not change) */
#define CAU_REG_RO_TWO_REG_REG_RO_TWO(x)         (((uint8_t)(((uint8_t)(x)) << CAU_REG_RO_TWO_REG_REG_RO_TWO_SHIFT)) & CAU_REG_RO_TWO_REG_REG_RO_TWO_MASK)
/*! @} */

/*! @name REG_RO_THREE_REG - REG_RO_THREE_REG */
/*! @{ */

#define CAU_REG_RO_THREE_REG_REG_RO_THREE_MASK   (0xFFU)
#define CAU_REG_RO_THREE_REG_REG_RO_THREE_SHIFT  (0U)
/*! REG_RO_THREE - Reserved. (Do not change) */
#define CAU_REG_RO_THREE_REG_REG_RO_THREE(x)     (((uint8_t)(((uint8_t)(x)) << CAU_REG_RO_THREE_REG_REG_RO_THREE_SHIFT)) & CAU_REG_RO_THREE_REG_REG_RO_THREE_MASK)
/*! @} */

/*! @name REG_RO_FOUR_REG - REG_RO_FOUR_REG */
/*! @{ */

#define CAU_REG_RO_FOUR_REG_REG_RO_FOUR_MASK     (0xFFU)
#define CAU_REG_RO_FOUR_REG_REG_RO_FOUR_SHIFT    (0U)
/*! REG_RO_FOUR - Reserved. (Do not change) */
#define CAU_REG_RO_FOUR_REG_REG_RO_FOUR(x)       (((uint8_t)(((uint8_t)(x)) << CAU_REG_RO_FOUR_REG_REG_RO_FOUR_SHIFT)) & CAU_REG_RO_FOUR_REG_REG_RO_FOUR_MASK)
/*! @} */

/*! @name REG_RO_FIVE_REG - REG_RO_FIVE_REG */
/*! @{ */

#define CAU_REG_RO_FIVE_REG_REG_RO_FIVE_MASK     (0xFFU)
#define CAU_REG_RO_FIVE_REG_REG_RO_FIVE_SHIFT    (0U)
/*! REG_RO_FIVE - Reserved. (Do not change) */
#define CAU_REG_RO_FIVE_REG_REG_RO_FIVE(x)       (((uint8_t)(((uint8_t)(x)) << CAU_REG_RO_FIVE_REG_REG_RO_FIVE_SHIFT)) & CAU_REG_RO_FIVE_REG_REG_RO_FIVE_MASK)
/*! @} */

/*! @name REG_RO_SIX_REG - REG_RO_SIX_REG */
/*! @{ */

#define CAU_REG_RO_SIX_REG_REG_RO_SIX_MASK       (0xFFU)
#define CAU_REG_RO_SIX_REG_REG_RO_SIX_SHIFT      (0U)
/*! REG_RO_SIX - Reserved. (Do not change) */
#define CAU_REG_RO_SIX_REG_REG_RO_SIX(x)         (((uint8_t)(((uint8_t)(x)) << CAU_REG_RO_SIX_REG_REG_RO_SIX_SHIFT)) & CAU_REG_RO_SIX_REG_REG_RO_SIX_MASK)
/*! @} */

/*! @name SW_RESET_B_REG - SW_RESET_B_REG */
/*! @{ */

#define CAU_SW_RESET_B_REG_SW_RESET_B_MASK       (0xFFU)
#define CAU_SW_RESET_B_REG_SW_RESET_B_SHIFT      (0U)
/*! SW_RESET_B - Reserved. (Do not change) */
#define CAU_SW_RESET_B_REG_SW_RESET_B(x)         (((uint8_t)(((uint8_t)(x)) << CAU_SW_RESET_B_REG_SW_RESET_B_SHIFT)) & CAU_SW_RESET_B_REG_SW_RESET_B_MASK)
/*! @} */

/*! @name SYS_CTRL_REG - SYS_CTRL_REG */
/*! @{ */

#define CAU_SYS_CTRL_REG_SYS_CTRL_MASK           (0xFFU)
#define CAU_SYS_CTRL_REG_SYS_CTRL_SHIFT          (0U)
/*! SYS_CTRL - Reserved. (Do not change) */
#define CAU_SYS_CTRL_REG_SYS_CTRL(x)             (((uint8_t)(((uint8_t)(x)) << CAU_SYS_CTRL_REG_SYS_CTRL_SHIFT)) & CAU_SYS_CTRL_REG_SYS_CTRL_MASK)
/*! @} */

/*! @name SYS_CTRL_PWR_OPT_SEL_REG - SYS_CTRL_PWR_OPT_SEL_REG */
/*! @{ */

#define CAU_SYS_CTRL_PWR_OPT_SEL_REG_SYS_CTRL_PWR_OPT_SEL_MASK (0xFFU)
#define CAU_SYS_CTRL_PWR_OPT_SEL_REG_SYS_CTRL_PWR_OPT_SEL_SHIFT (0U)
/*! SYS_CTRL_PWR_OPT_SEL - Reserved. (Do not change) */
#define CAU_SYS_CTRL_PWR_OPT_SEL_REG_SYS_CTRL_PWR_OPT_SEL(x) (((uint8_t)(((uint8_t)(x)) << CAU_SYS_CTRL_PWR_OPT_SEL_REG_SYS_CTRL_PWR_OPT_SEL_SHIFT)) & CAU_SYS_CTRL_PWR_OPT_SEL_REG_SYS_CTRL_PWR_OPT_SEL_MASK)
/*! @} */

/*! @name BYPASS_SOC_PD_CTRL_RW_REG - BYPASS_SOC_PD_CTRL_RW_REG */
/*! @{ */

#define CAU_BYPASS_SOC_PD_CTRL_RW_REG_BYPASS_SOC_PD_CTRL_RW_MASK (0xFFU)
#define CAU_BYPASS_SOC_PD_CTRL_RW_REG_BYPASS_SOC_PD_CTRL_RW_SHIFT (0U)
/*! BYPASS_SOC_PD_CTRL_RW - Reserved. (Do not change) */
#define CAU_BYPASS_SOC_PD_CTRL_RW_REG_BYPASS_SOC_PD_CTRL_RW(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_SOC_PD_CTRL_RW_REG_BYPASS_SOC_PD_CTRL_RW_SHIFT)) & CAU_BYPASS_SOC_PD_CTRL_RW_REG_BYPASS_SOC_PD_CTRL_RW_MASK)
/*! @} */

/*! @name BYPASS_SOC_CTRL_ONE_RW_REG - BYPASS_SOC_CTRL_ONE_RW_REG */
/*! @{ */

#define CAU_BYPASS_SOC_CTRL_ONE_RW_REG_BYPASS_SOC_CTRL_ONE_RW_MASK (0xFFU)
#define CAU_BYPASS_SOC_CTRL_ONE_RW_REG_BYPASS_SOC_CTRL_ONE_RW_SHIFT (0U)
/*! BYPASS_SOC_CTRL_ONE_RW - Reserved. (Do not change) */
#define CAU_BYPASS_SOC_CTRL_ONE_RW_REG_BYPASS_SOC_CTRL_ONE_RW(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_SOC_CTRL_ONE_RW_REG_BYPASS_SOC_CTRL_ONE_RW_SHIFT)) & CAU_BYPASS_SOC_CTRL_ONE_RW_REG_BYPASS_SOC_CTRL_ONE_RW_MASK)
/*! @} */

/*! @name BYPASS_SOC_CTRL_TWO_RW_REG - BYPASS_SOC_CTRL_TWO_RW_REG */
/*! @{ */

#define CAU_BYPASS_SOC_CTRL_TWO_RW_REG_BYPASS_SOC_CTRL_TWO_RW_MASK (0xFFU)
#define CAU_BYPASS_SOC_CTRL_TWO_RW_REG_BYPASS_SOC_CTRL_TWO_RW_SHIFT (0U)
/*! BYPASS_SOC_CTRL_TWO_RW - Reserved. (Do not change) */
#define CAU_BYPASS_SOC_CTRL_TWO_RW_REG_BYPASS_SOC_CTRL_TWO_RW(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_SOC_CTRL_TWO_RW_REG_BYPASS_SOC_CTRL_TWO_RW_SHIFT)) & CAU_BYPASS_SOC_CTRL_TWO_RW_REG_BYPASS_SOC_CTRL_TWO_RW_MASK)
/*! @} */

/*! @name BYPASS_RFU_CTRL_ONE_RW_REG - BYPASS_RFU_CTRL_ONE_RW_REG */
/*! @{ */

#define CAU_BYPASS_RFU_CTRL_ONE_RW_REG_BYPASS_RFU_CTRL_ONE_RW_MASK (0xFFU)
#define CAU_BYPASS_RFU_CTRL_ONE_RW_REG_BYPASS_RFU_CTRL_ONE_RW_SHIFT (0U)
/*! BYPASS_RFU_CTRL_ONE_RW - Reserved. (Do not change) */
#define CAU_BYPASS_RFU_CTRL_ONE_RW_REG_BYPASS_RFU_CTRL_ONE_RW(x) (((uint8_t)(((uint8_t)(x)) << CAU_BYPASS_RFU_CTRL_ONE_RW_REG_BYPASS_RFU_CTRL_ONE_RW_SHIFT)) & CAU_BYPASS_RFU_CTRL_ONE_RW_REG_BYPASS_RFU_CTRL_ONE_RW_MASK)
/*! @} */

/*! @name PD_CTRL_ONE_REG - PD_CTRL_ONE_REG */
/*! @{ */

#define CAU_PD_CTRL_ONE_REG_RESERVED0_MASK       (0x3U)
#define CAU_PD_CTRL_ONE_REG_RESERVED0_SHIFT      (0U)
/*! RESERVED0 - Reserved. (Do not change) */
#define CAU_PD_CTRL_ONE_REG_RESERVED0(x)         (((uint8_t)(((uint8_t)(x)) << CAU_PD_CTRL_ONE_REG_RESERVED0_SHIFT)) & CAU_PD_CTRL_ONE_REG_RESERVED0_MASK)

#define CAU_PD_CTRL_ONE_REG_SLPBIAS_PD_MASK      (0x4U)
#define CAU_PD_CTRL_ONE_REG_SLPBIAS_PD_SHIFT     (2U)
/*! SLPBIAS_PD - SLPBIAS_PD */
#define CAU_PD_CTRL_ONE_REG_SLPBIAS_PD(x)        (((uint8_t)(((uint8_t)(x)) << CAU_PD_CTRL_ONE_REG_SLPBIAS_PD_SHIFT)) & CAU_PD_CTRL_ONE_REG_SLPBIAS_PD_MASK)

#define CAU_PD_CTRL_ONE_REG_RESERVED1_MASK       (0xF8U)
#define CAU_PD_CTRL_ONE_REG_RESERVED1_SHIFT      (3U)
/*! RESERVED1 - Reserved. (Do not change) */
#define CAU_PD_CTRL_ONE_REG_RESERVED1(x)         (((uint8_t)(((uint8_t)(x)) << CAU_PD_CTRL_ONE_REG_RESERVED1_SHIFT)) & CAU_PD_CTRL_ONE_REG_RESERVED1_MASK)
/*! @} */

/*! @name PD_CTRL_TWO_REG - PD_CTRL_TWO_REG */
/*! @{ */

#define CAU_PD_CTRL_TWO_REG_PD_CTRL_TWO_MASK     (0xFFU)
#define CAU_PD_CTRL_TWO_REG_PD_CTRL_TWO_SHIFT    (0U)
/*! PD_CTRL_TWO - Reserved. (Do not change) */
#define CAU_PD_CTRL_TWO_REG_PD_CTRL_TWO(x)       (((uint8_t)(((uint8_t)(x)) << CAU_PD_CTRL_TWO_REG_PD_CTRL_TWO_SHIFT)) & CAU_PD_CTRL_TWO_REG_PD_CTRL_TWO_MASK)
/*! @} */

/*! @name SLP_CTRL_ONE_REG - SLP_CTRL_ONE_REG */
/*! @{ */

#define CAU_SLP_CTRL_ONE_REG_SLP_CTRL_ONE_MASK   (0xFFU)
#define CAU_SLP_CTRL_ONE_REG_SLP_CTRL_ONE_SHIFT  (0U)
/*! SLP_CTRL_ONE - "" */
#define CAU_SLP_CTRL_ONE_REG_SLP_CTRL_ONE(x)     (((uint8_t)(((uint8_t)(x)) << CAU_SLP_CTRL_ONE_REG_SLP_CTRL_ONE_SHIFT)) & CAU_SLP_CTRL_ONE_REG_SLP_CTRL_ONE_MASK)
/*! @} */

/*! @name SLP_CTRL_TWO_REG - SLP_CTRL_TWO_REG */
/*! @{ */

#define CAU_SLP_CTRL_TWO_REG_SLP_CTRL_TWO_MASK   (0xFFU)
#define CAU_SLP_CTRL_TWO_REG_SLP_CTRL_TWO_SHIFT  (0U)
/*! SLP_CTRL_TWO - "" */
#define CAU_SLP_CTRL_TWO_REG_SLP_CTRL_TWO(x)     (((uint8_t)(((uint8_t)(x)) << CAU_SLP_CTRL_TWO_REG_SLP_CTRL_TWO_SHIFT)) & CAU_SLP_CTRL_TWO_REG_SLP_CTRL_TWO_MASK)
/*! @} */

/*! @name BG_CTRL_REG - BG_CTRL_REG */
/*! @{ */

#define CAU_BG_CTRL_REG_BG_CTRL_MASK             (0xFFU)
#define CAU_BG_CTRL_REG_BG_CTRL_SHIFT            (0U)
/*! BG_CTRL - Reserved. (Do not change) */
#define CAU_BG_CTRL_REG_BG_CTRL(x)               (((uint8_t)(((uint8_t)(x)) << CAU_BG_CTRL_REG_BG_CTRL_SHIFT)) & CAU_BG_CTRL_REG_BG_CTRL_MASK)
/*! @} */

/*! @name CPREG_CTRL_ONE_REG - CPREG_CTRL_ONE_REG */
/*! @{ */

#define CAU_CPREG_CTRL_ONE_REG_CPREG_CTRL_ONE_MASK (0xFFU)
#define CAU_CPREG_CTRL_ONE_REG_CPREG_CTRL_ONE_SHIFT (0U)
/*! CPREG_CTRL_ONE - Reserved. (Do not change) */
#define CAU_CPREG_CTRL_ONE_REG_CPREG_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << CAU_CPREG_CTRL_ONE_REG_CPREG_CTRL_ONE_SHIFT)) & CAU_CPREG_CTRL_ONE_REG_CPREG_CTRL_ONE_MASK)
/*! @} */

/*! @name CPREG_CTRL_TWO_REG - CPREG_CTRL_TWO_REG */
/*! @{ */

#define CAU_CPREG_CTRL_TWO_REG_CPREG_CTRL_TWO_MASK (0xFFU)
#define CAU_CPREG_CTRL_TWO_REG_CPREG_CTRL_TWO_SHIFT (0U)
/*! CPREG_CTRL_TWO - Reserved. (Do not change) */
#define CAU_CPREG_CTRL_TWO_REG_CPREG_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << CAU_CPREG_CTRL_TWO_REG_CPREG_CTRL_TWO_SHIFT)) & CAU_CPREG_CTRL_TWO_REG_CPREG_CTRL_TWO_MASK)
/*! @} */

/*! @name CPREG_CTRL_THREE_REG - CPREG_CTRL_THREE_REG */
/*! @{ */

#define CAU_CPREG_CTRL_THREE_REG_CPREG_CTRL_THREE_MASK (0xFFU)
#define CAU_CPREG_CTRL_THREE_REG_CPREG_CTRL_THREE_SHIFT (0U)
/*! CPREG_CTRL_THREE - Reserved. (Do not change) */
#define CAU_CPREG_CTRL_THREE_REG_CPREG_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << CAU_CPREG_CTRL_THREE_REG_CPREG_CTRL_THREE_SHIFT)) & CAU_CPREG_CTRL_THREE_REG_CPREG_CTRL_THREE_MASK)
/*! @} */

/*! @name PSEN_CTRL_ONE_REG - PSEN_CTRL_ONE_REG */
/*! @{ */

#define CAU_PSEN_CTRL_ONE_REG_PSEN_CTRL_ONE_MASK (0xFFU)
#define CAU_PSEN_CTRL_ONE_REG_PSEN_CTRL_ONE_SHIFT (0U)
/*! PSEN_CTRL_ONE - Reserved. (Do not change) */
#define CAU_PSEN_CTRL_ONE_REG_PSEN_CTRL_ONE(x)   (((uint8_t)(((uint8_t)(x)) << CAU_PSEN_CTRL_ONE_REG_PSEN_CTRL_ONE_SHIFT)) & CAU_PSEN_CTRL_ONE_REG_PSEN_CTRL_ONE_MASK)
/*! @} */

/*! @name PSEN_CTRL_TWO_REG - PSEN_CTRL_TWO_REG */
/*! @{ */

#define CAU_PSEN_CTRL_TWO_REG_PSEN_CTRL_TWO_MASK (0xFFU)
#define CAU_PSEN_CTRL_TWO_REG_PSEN_CTRL_TWO_SHIFT (0U)
/*! PSEN_CTRL_TWO - Reserved. (Do not change) */
#define CAU_PSEN_CTRL_TWO_REG_PSEN_CTRL_TWO(x)   (((uint8_t)(((uint8_t)(x)) << CAU_PSEN_CTRL_TWO_REG_PSEN_CTRL_TWO_SHIFT)) & CAU_PSEN_CTRL_TWO_REG_PSEN_CTRL_TWO_MASK)
/*! @} */

/*! @name TSEN_CTRL_ONE_REG - TSEN_CTRL_ONE_REG */
/*! @{ */

#define CAU_TSEN_CTRL_ONE_REG_TSEN_CTRL_ONE_MASK (0xFFU)
#define CAU_TSEN_CTRL_ONE_REG_TSEN_CTRL_ONE_SHIFT (0U)
/*! TSEN_CTRL_ONE - Reserved. (Do not change) */
#define CAU_TSEN_CTRL_ONE_REG_TSEN_CTRL_ONE(x)   (((uint8_t)(((uint8_t)(x)) << CAU_TSEN_CTRL_ONE_REG_TSEN_CTRL_ONE_SHIFT)) & CAU_TSEN_CTRL_ONE_REG_TSEN_CTRL_ONE_MASK)
/*! @} */

/*! @name TSEN_CTRL_THREE_REG - TSEN_CTRL_THREE_REG */
/*! @{ */

#define CAU_TSEN_CTRL_THREE_REG_TSEN_CTRL_TWO_MASK (0xFFU)
#define CAU_TSEN_CTRL_THREE_REG_TSEN_CTRL_TWO_SHIFT (0U)
/*! TSEN_CTRL_TWO - Reserved. (Do not change) */
#define CAU_TSEN_CTRL_THREE_REG_TSEN_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << CAU_TSEN_CTRL_THREE_REG_TSEN_CTRL_TWO_SHIFT)) & CAU_TSEN_CTRL_THREE_REG_TSEN_CTRL_TWO_MASK)
/*! @} */

/*! @name ADC_CTRL_ONE_REG - ADC_CTRL_ONE_REG */
/*! @{ */

#define CAU_ADC_CTRL_ONE_REG_ADC_CTRL_MASK       (0xFFU)
#define CAU_ADC_CTRL_ONE_REG_ADC_CTRL_SHIFT      (0U)
/*! ADC_CTRL - Reserved. (Do not change) */
#define CAU_ADC_CTRL_ONE_REG_ADC_CTRL(x)         (((uint8_t)(((uint8_t)(x)) << CAU_ADC_CTRL_ONE_REG_ADC_CTRL_SHIFT)) & CAU_ADC_CTRL_ONE_REG_ADC_CTRL_MASK)
/*! @} */

/*! @name RCAL_CTRL_ONE_REG - RCAL_CTRL_ONE_REG */
/*! @{ */

#define CAU_RCAL_CTRL_ONE_REG_RCAL_CTRL_ONE_MASK (0xFFU)
#define CAU_RCAL_CTRL_ONE_REG_RCAL_CTRL_ONE_SHIFT (0U)
/*! RCAL_CTRL_ONE - Reserved. (Do not change) */
#define CAU_RCAL_CTRL_ONE_REG_RCAL_CTRL_ONE(x)   (((uint8_t)(((uint8_t)(x)) << CAU_RCAL_CTRL_ONE_REG_RCAL_CTRL_ONE_SHIFT)) & CAU_RCAL_CTRL_ONE_REG_RCAL_CTRL_ONE_MASK)
/*! @} */

/*! @name RCAL_CTRL_TWO_REG - RCAL_CTRL_TWO_REG */
/*! @{ */

#define CAU_RCAL_CTRL_TWO_REG_RCAL_CTRL_TWO_MASK (0xFFU)
#define CAU_RCAL_CTRL_TWO_REG_RCAL_CTRL_TWO_SHIFT (0U)
/*! RCAL_CTRL_TWO - Reserved. (Do not change) */
#define CAU_RCAL_CTRL_TWO_REG_RCAL_CTRL_TWO(x)   (((uint8_t)(((uint8_t)(x)) << CAU_RCAL_CTRL_TWO_REG_RCAL_CTRL_TWO_SHIFT)) & CAU_RCAL_CTRL_TWO_REG_RCAL_CTRL_TWO_MASK)
/*! @} */

/*! @name XTAL_CTRL_ONE_REG - XTAL_CTRL_ONE_REG */
/*! @{ */

#define CAU_XTAL_CTRL_ONE_REG_XTAL_CTRL_ONE_MASK (0xFFU)
#define CAU_XTAL_CTRL_ONE_REG_XTAL_CTRL_ONE_SHIFT (0U)
/*! XTAL_CTRL_ONE - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_ONE_REG_XTAL_CTRL_ONE(x)   (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_ONE_REG_XTAL_CTRL_ONE_SHIFT)) & CAU_XTAL_CTRL_ONE_REG_XTAL_CTRL_ONE_MASK)
/*! @} */

/*! @name XTAL_CTRL_TWO_REG - XTAL_CTRL_TWO_REG */
/*! @{ */

#define CAU_XTAL_CTRL_TWO_REG_XTAL_CTRL_TWO_MASK (0xFFU)
#define CAU_XTAL_CTRL_TWO_REG_XTAL_CTRL_TWO_SHIFT (0U)
/*! XTAL_CTRL_TWO - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_TWO_REG_XTAL_CTRL_TWO(x)   (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_TWO_REG_XTAL_CTRL_TWO_SHIFT)) & CAU_XTAL_CTRL_TWO_REG_XTAL_CTRL_TWO_MASK)
/*! @} */

/*! @name XTAL_CTRL_THREE_REG - XTAL_CTRL_THREE_REG */
/*! @{ */

#define CAU_XTAL_CTRL_THREE_REG_XTAL_CTRL_THREE_MASK (0xFFU)
#define CAU_XTAL_CTRL_THREE_REG_XTAL_CTRL_THREE_SHIFT (0U)
/*! XTAL_CTRL_THREE - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_THREE_REG_XTAL_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_THREE_REG_XTAL_CTRL_THREE_SHIFT)) & CAU_XTAL_CTRL_THREE_REG_XTAL_CTRL_THREE_MASK)
/*! @} */

/*! @name XTAL_CTRL_FOUR_REG - XTAL_CTRL_FOUR_REG */
/*! @{ */

#define CAU_XTAL_CTRL_FOUR_REG_XTAL_CTRL_FOUR_MASK (0xFFU)
#define CAU_XTAL_CTRL_FOUR_REG_XTAL_CTRL_FOUR_SHIFT (0U)
/*! XTAL_CTRL_FOUR - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_FOUR_REG_XTAL_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_FOUR_REG_XTAL_CTRL_FOUR_SHIFT)) & CAU_XTAL_CTRL_FOUR_REG_XTAL_CTRL_FOUR_MASK)
/*! @} */

/*! @name XTAL_CTRL_FIVE_REG - XTAL_CTRL_FIVE_REG */
/*! @{ */

#define CAU_XTAL_CTRL_FIVE_REG_XTAL_CTRL_FIVE_MASK (0xFFU)
#define CAU_XTAL_CTRL_FIVE_REG_XTAL_CTRL_FIVE_SHIFT (0U)
/*! XTAL_CTRL_FIVE - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_FIVE_REG_XTAL_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_FIVE_REG_XTAL_CTRL_FIVE_SHIFT)) & CAU_XTAL_CTRL_FIVE_REG_XTAL_CTRL_FIVE_MASK)
/*! @} */

/*! @name XTAL_CTRL_SIX_REG - XTAL_CTRL_SIX_REG */
/*! @{ */

#define CAU_XTAL_CTRL_SIX_REG_XTAL_CTRL_SIX_MASK (0xFFU)
#define CAU_XTAL_CTRL_SIX_REG_XTAL_CTRL_SIX_SHIFT (0U)
/*! XTAL_CTRL_SIX - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_SIX_REG_XTAL_CTRL_SIX(x)   (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_SIX_REG_XTAL_CTRL_SIX_SHIFT)) & CAU_XTAL_CTRL_SIX_REG_XTAL_CTRL_SIX_MASK)
/*! @} */

/*! @name XTAL_CTRL_SEVEN_REG - XTAL_CTRL_SEVEN_REG */
/*! @{ */

#define CAU_XTAL_CTRL_SEVEN_REG_XTAL_CTRL_SEVEN_MASK (0xFFU)
#define CAU_XTAL_CTRL_SEVEN_REG_XTAL_CTRL_SEVEN_SHIFT (0U)
/*! XTAL_CTRL_SEVEN - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_SEVEN_REG_XTAL_CTRL_SEVEN(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_SEVEN_REG_XTAL_CTRL_SEVEN_SHIFT)) & CAU_XTAL_CTRL_SEVEN_REG_XTAL_CTRL_SEVEN_MASK)
/*! @} */

/*! @name XTAL_CTRL_EIGHT_REG - XTAL_CTRL_EIGHT_REG */
/*! @{ */

#define CAU_XTAL_CTRL_EIGHT_REG_XTAL_CTRL_EIGHT_MASK (0xFFU)
#define CAU_XTAL_CTRL_EIGHT_REG_XTAL_CTRL_EIGHT_SHIFT (0U)
/*! XTAL_CTRL_EIGHT - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_EIGHT_REG_XTAL_CTRL_EIGHT(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_EIGHT_REG_XTAL_CTRL_EIGHT_SHIFT)) & CAU_XTAL_CTRL_EIGHT_REG_XTAL_CTRL_EIGHT_MASK)
/*! @} */

/*! @name XTAL_CTRL_NINE_REG - XTAL_CTRL_NINE_REG */
/*! @{ */

#define CAU_XTAL_CTRL_NINE_REG_XTAL_CTRL_NINE_MASK (0xFFU)
#define CAU_XTAL_CTRL_NINE_REG_XTAL_CTRL_NINE_SHIFT (0U)
/*! XTAL_CTRL_NINE - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_NINE_REG_XTAL_CTRL_NINE(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_NINE_REG_XTAL_CTRL_NINE_SHIFT)) & CAU_XTAL_CTRL_NINE_REG_XTAL_CTRL_NINE_MASK)
/*! @} */

/*! @name XTAL_CTRL_TEN_REG - XTAL_CTRL_TEN_REG */
/*! @{ */

#define CAU_XTAL_CTRL_TEN_REG_XTAL_CTRL_TEN_MASK (0xFFU)
#define CAU_XTAL_CTRL_TEN_REG_XTAL_CTRL_TEN_SHIFT (0U)
/*! XTAL_CTRL_TEN - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_TEN_REG_XTAL_CTRL_TEN(x)   (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_TEN_REG_XTAL_CTRL_TEN_SHIFT)) & CAU_XTAL_CTRL_TEN_REG_XTAL_CTRL_TEN_MASK)
/*! @} */

/*! @name XTAL_CTRL_ELEVEN_REG - XTAL_CTRL_ELEVEN_REG */
/*! @{ */

#define CAU_XTAL_CTRL_ELEVEN_REG_XTAL_CTRL_ELEVEN_MASK (0xFFU)
#define CAU_XTAL_CTRL_ELEVEN_REG_XTAL_CTRL_ELEVEN_SHIFT (0U)
/*! XTAL_CTRL_ELEVEN - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_ELEVEN_REG_XTAL_CTRL_ELEVEN(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_ELEVEN_REG_XTAL_CTRL_ELEVEN_SHIFT)) & CAU_XTAL_CTRL_ELEVEN_REG_XTAL_CTRL_ELEVEN_MASK)
/*! @} */

/*! @name XTAL_CTRL_TWELVE_REG - XTAL_CTRL_TWELVE_REG */
/*! @{ */

#define CAU_XTAL_CTRL_TWELVE_REG_XTAL_CTRL_TWELVE_MASK (0xFFU)
#define CAU_XTAL_CTRL_TWELVE_REG_XTAL_CTRL_TWELVE_SHIFT (0U)
/*! XTAL_CTRL_TWELVE - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_TWELVE_REG_XTAL_CTRL_TWELVE(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_TWELVE_REG_XTAL_CTRL_TWELVE_SHIFT)) & CAU_XTAL_CTRL_TWELVE_REG_XTAL_CTRL_TWELVE_MASK)
/*! @} */

/*! @name XTAL_CTRL_THIRTEEN_REG - XTAL_CTRL_THIRTEEN_REG */
/*! @{ */

#define CAU_XTAL_CTRL_THIRTEEN_REG_XTAL_CTRL_THIRTEEN_MASK (0xFFU)
#define CAU_XTAL_CTRL_THIRTEEN_REG_XTAL_CTRL_THIRTEEN_SHIFT (0U)
/*! XTAL_CTRL_THIRTEEN - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_THIRTEEN_REG_XTAL_CTRL_THIRTEEN(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_THIRTEEN_REG_XTAL_CTRL_THIRTEEN_SHIFT)) & CAU_XTAL_CTRL_THIRTEEN_REG_XTAL_CTRL_THIRTEEN_MASK)
/*! @} */

/*! @name XTAL_CTRL_FOURTEEN_REG - XTAL_CTRL_FOURTEEN_REG */
/*! @{ */

#define CAU_XTAL_CTRL_FOURTEEN_REG_XTAL_CTRL_FOURTEEN_MASK (0xFFU)
#define CAU_XTAL_CTRL_FOURTEEN_REG_XTAL_CTRL_FOURTEEN_SHIFT (0U)
/*! XTAL_CTRL_FOURTEEN - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_FOURTEEN_REG_XTAL_CTRL_FOURTEEN(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_FOURTEEN_REG_XTAL_CTRL_FOURTEEN_SHIFT)) & CAU_XTAL_CTRL_FOURTEEN_REG_XTAL_CTRL_FOURTEEN_MASK)
/*! @} */

/*! @name XTAL_CTRL_FIFTEEN_REG - XTAL_CTRL_FIFTEEN_REG */
/*! @{ */

#define CAU_XTAL_CTRL_FIFTEEN_REG_XTAL_CTRL_FIFTEEN_MASK (0xFFU)
#define CAU_XTAL_CTRL_FIFTEEN_REG_XTAL_CTRL_FIFTEEN_SHIFT (0U)
/*! XTAL_CTRL_FIFTEEN - Reserved. (Do not change) */
#define CAU_XTAL_CTRL_FIFTEEN_REG_XTAL_CTRL_FIFTEEN(x) (((uint8_t)(((uint8_t)(x)) << CAU_XTAL_CTRL_FIFTEEN_REG_XTAL_CTRL_FIFTEEN_SHIFT)) & CAU_XTAL_CTRL_FIFTEEN_REG_XTAL_CTRL_FIFTEEN_MASK)
/*! @} */

/*! @name T1_CTRL_RSVD_HI_REG - T1_CTRL_RSVD_HI_REG */
/*! @{ */

#define CAU_T1_CTRL_RSVD_HI_REG_XTAL_CTRL_RSVD_HI_MASK (0xFFU)
#define CAU_T1_CTRL_RSVD_HI_REG_XTAL_CTRL_RSVD_HI_SHIFT (0U)
/*! XTAL_CTRL_RSVD_HI - Reserved. (Do not change) */
#define CAU_T1_CTRL_RSVD_HI_REG_XTAL_CTRL_RSVD_HI(x) (((uint8_t)(((uint8_t)(x)) << CAU_T1_CTRL_RSVD_HI_REG_XTAL_CTRL_RSVD_HI_SHIFT)) & CAU_T1_CTRL_RSVD_HI_REG_XTAL_CTRL_RSVD_HI_MASK)
/*! @} */

/*! @name T1_CTRL_RSVD_LO_REG - T1_CTRL_RSVD_LO_REG */
/*! @{ */

#define CAU_T1_CTRL_RSVD_LO_REG_XTAL_CTRL_RSVD_LO_MASK (0xFFU)
#define CAU_T1_CTRL_RSVD_LO_REG_XTAL_CTRL_RSVD_LO_SHIFT (0U)
/*! XTAL_CTRL_RSVD_LO - Reserved. (Do not change) */
#define CAU_T1_CTRL_RSVD_LO_REG_XTAL_CTRL_RSVD_LO(x) (((uint8_t)(((uint8_t)(x)) << CAU_T1_CTRL_RSVD_LO_REG_XTAL_CTRL_RSVD_LO_SHIFT)) & CAU_T1_CTRL_RSVD_LO_REG_XTAL_CTRL_RSVD_LO_MASK)
/*! @} */

/*! @name GPIO_CTRL_REG - GPIO_CTRL_REG */
/*! @{ */

#define CAU_GPIO_CTRL_REG_GPIO_CTRL_MASK         (0xFFU)
#define CAU_GPIO_CTRL_REG_GPIO_CTRL_SHIFT        (0U)
/*! GPIO_CTRL - Reserved. (Do not change) */
#define CAU_GPIO_CTRL_REG_GPIO_CTRL(x)           (((uint8_t)(((uint8_t)(x)) << CAU_GPIO_CTRL_REG_GPIO_CTRL_SHIFT)) & CAU_GPIO_CTRL_REG_GPIO_CTRL_MASK)
/*! @} */

/*! @name ATEST_CTRL_ONE_REG - ATEST_CTRL_ONE_REG */
/*! @{ */

#define CAU_ATEST_CTRL_ONE_REG_ATEST_CTRL_ONE_MASK (0xFFU)
#define CAU_ATEST_CTRL_ONE_REG_ATEST_CTRL_ONE_SHIFT (0U)
/*! ATEST_CTRL_ONE - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_ONE_REG_ATEST_CTRL_ONE(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_ONE_REG_ATEST_CTRL_ONE_SHIFT)) & CAU_ATEST_CTRL_ONE_REG_ATEST_CTRL_ONE_MASK)
/*! @} */

/*! @name ATEST_CTRL_TWO_REG - ATEST_CTRL_TWO_REG */
/*! @{ */

#define CAU_ATEST_CTRL_TWO_REG_ATEST_CTRL_TWO_MASK (0xFFU)
#define CAU_ATEST_CTRL_TWO_REG_ATEST_CTRL_TWO_SHIFT (0U)
/*! ATEST_CTRL_TWO - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_TWO_REG_ATEST_CTRL_TWO(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_TWO_REG_ATEST_CTRL_TWO_SHIFT)) & CAU_ATEST_CTRL_TWO_REG_ATEST_CTRL_TWO_MASK)
/*! @} */

/*! @name ATEST_CTRL_THREE_REG - ATEST_CTRL_THREE_REG */
/*! @{ */

#define CAU_ATEST_CTRL_THREE_REG_ATEST_CTRL_THREE_MASK (0xFFU)
#define CAU_ATEST_CTRL_THREE_REG_ATEST_CTRL_THREE_SHIFT (0U)
/*! ATEST_CTRL_THREE - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_THREE_REG_ATEST_CTRL_THREE(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_THREE_REG_ATEST_CTRL_THREE_SHIFT)) & CAU_ATEST_CTRL_THREE_REG_ATEST_CTRL_THREE_MASK)
/*! @} */

/*! @name ATEST_CTRL_FOUR_REG - ATEST_CTRL_FOUR_REG */
/*! @{ */

#define CAU_ATEST_CTRL_FOUR_REG_ATEST_CTRL_FOUR_MASK (0xFFU)
#define CAU_ATEST_CTRL_FOUR_REG_ATEST_CTRL_FOUR_SHIFT (0U)
/*! ATEST_CTRL_FOUR - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_FOUR_REG_ATEST_CTRL_FOUR(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_FOUR_REG_ATEST_CTRL_FOUR_SHIFT)) & CAU_ATEST_CTRL_FOUR_REG_ATEST_CTRL_FOUR_MASK)
/*! @} */

/*! @name ATEST_CTRL_FIVE_REG - ATEST_CTRL_FIVE_REG */
/*! @{ */

#define CAU_ATEST_CTRL_FIVE_REG_ATEST_CTRL_FIVE_MASK (0xFFU)
#define CAU_ATEST_CTRL_FIVE_REG_ATEST_CTRL_FIVE_SHIFT (0U)
/*! ATEST_CTRL_FIVE - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_FIVE_REG_ATEST_CTRL_FIVE(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_FIVE_REG_ATEST_CTRL_FIVE_SHIFT)) & CAU_ATEST_CTRL_FIVE_REG_ATEST_CTRL_FIVE_MASK)
/*! @} */

/*! @name ATEST_CTRL_SIX_REG - ATEST_CTRL_SIX_REG */
/*! @{ */

#define CAU_ATEST_CTRL_SIX_REG_ATEST_CTRL_SIX_MASK (0xFFU)
#define CAU_ATEST_CTRL_SIX_REG_ATEST_CTRL_SIX_SHIFT (0U)
/*! ATEST_CTRL_SIX - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_SIX_REG_ATEST_CTRL_SIX(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_SIX_REG_ATEST_CTRL_SIX_SHIFT)) & CAU_ATEST_CTRL_SIX_REG_ATEST_CTRL_SIX_MASK)
/*! @} */

/*! @name ATEST_CTRL_SEVEN_REG - ATEST_CTRL_SEVEN_REG */
/*! @{ */

#define CAU_ATEST_CTRL_SEVEN_REG_ATEST_CTRL_SEVEN_MASK (0xFFU)
#define CAU_ATEST_CTRL_SEVEN_REG_ATEST_CTRL_SEVEN_SHIFT (0U)
/*! ATEST_CTRL_SEVEN - Reserved. (Do not change) */
#define CAU_ATEST_CTRL_SEVEN_REG_ATEST_CTRL_SEVEN(x) (((uint8_t)(((uint8_t)(x)) << CAU_ATEST_CTRL_SEVEN_REG_ATEST_CTRL_SEVEN_SHIFT)) & CAU_ATEST_CTRL_SEVEN_REG_ATEST_CTRL_SEVEN_MASK)
/*! @} */

/*! @name RESERVED_LO_ONE_REG - RESERVED_LO_ONE_REG */
/*! @{ */

#define CAU_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_MASK (0xFFU)
#define CAU_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_SHIFT (0U)
/*! RESERVED_LO_ONE - Reserved. (Do not change) */
#define CAU_RESERVED_LO_ONE_REG_RESERVED_LO_ONE(x) (((uint8_t)(((uint8_t)(x)) << CAU_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_SHIFT)) & CAU_RESERVED_LO_ONE_REG_RESERVED_LO_ONE_MASK)
/*! @} */

/*! @name RESERVED_LO_TWO_REG - RESERVED_LO_TWO_REG */
/*! @{ */

#define CAU_RESERVED_LO_TWO_REG_RESERVED_LO_TWO_MASK (0xFFU)
#define CAU_RESERVED_LO_TWO_REG_RESERVED_LO_TWO_SHIFT (0U)
/*! RESERVED_LO_TWO - Reserved. (Do not change) */
#define CAU_RESERVED_LO_TWO_REG_RESERVED_LO_TWO(x) (((uint8_t)(((uint8_t)(x)) << CAU_RESERVED_LO_TWO_REG_RESERVED_LO_TWO_SHIFT)) & CAU_RESERVED_LO_TWO_REG_RESERVED_LO_TWO_MASK)
/*! @} */

/*! @name RESERVED_HI_ONE_REG - RESERVED_HI_ONE_REG */
/*! @{ */

#define CAU_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_MASK (0xFFU)
#define CAU_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_SHIFT (0U)
/*! RESERVED_HI_ONE - Reserved. (Do not change) */
#define CAU_RESERVED_HI_ONE_REG_RESERVED_HI_ONE(x) (((uint8_t)(((uint8_t)(x)) << CAU_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_SHIFT)) & CAU_RESERVED_HI_ONE_REG_RESERVED_HI_ONE_MASK)
/*! @} */

/*! @name RESERVED_HI_TWO_REG - RESERVED_HI_TWO_REG */
/*! @{ */

#define CAU_RESERVED_HI_TWO_REG_RESERVED_HI_TWO_MASK (0xFFU)
#define CAU_RESERVED_HI_TWO_REG_RESERVED_HI_TWO_SHIFT (0U)
/*! RESERVED_HI_TWO - Reserved. (Do not change) */
#define CAU_RESERVED_HI_TWO_REG_RESERVED_HI_TWO(x) (((uint8_t)(((uint8_t)(x)) << CAU_RESERVED_HI_TWO_REG_RESERVED_HI_TWO_SHIFT)) & CAU_RESERVED_HI_TWO_REG_RESERVED_HI_TWO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAU_Register_Masks */


/*!
 * @}
 */ /* end of group CAU_Peripheral_Access_Layer */


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


#endif  /* PERI_CAU_H_ */

