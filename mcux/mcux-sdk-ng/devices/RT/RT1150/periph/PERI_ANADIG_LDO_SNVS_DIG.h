/*
** ###################################################################
**     Processors:          MIMXRT1151DHM8B
**                          MIMXRT1151DVM8B
**                          MIMXRT1151XHM8B
**                          MIMXRT1151XVM8B
**                          MIMXRT1152AHM6B
**                          MIMXRT1152AVM6B
**                          MIMXRT1152DHM8B
**                          MIMXRT1152DVM8B
**                          MIMXRT1152XHM8B
**                          MIMXRT1152XVM8B
**
**     Version:             rev. 0.2, 2026-02-26
**     Build:               b260622
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANADIG_LDO_SNVS_DIG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2026-01-09)
**         Initial version.
**     - rev. 0.2 (2026-02-26)
**         Update header file based on RM Rev1.
**
** ###################################################################
*/

/*!
 * @file PERI_ANADIG_LDO_SNVS_DIG.h
 * @version 0.2
 * @date 2026-02-26
 * @brief CMSIS Peripheral Access Layer for ANADIG_LDO_SNVS_DIG
 *
 * CMSIS Peripheral Access Layer for ANADIG_LDO_SNVS_DIG
 */

#if !defined(PERI_ANADIG_LDO_SNVS_DIG_H_)
#define PERI_ANADIG_LDO_SNVS_DIG_H_              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1151DHM8B) || defined(CPU_MIMXRT1151DVM8B) || defined(CPU_MIMXRT1151XHM8B) || defined(CPU_MIMXRT1151XVM8B))
#include "MIMXRT1151_COMMON.h"
#elif (defined(CPU_MIMXRT1152AHM6B) || defined(CPU_MIMXRT1152AVM6B) || defined(CPU_MIMXRT1152DHM8B) || defined(CPU_MIMXRT1152DVM8B) || defined(CPU_MIMXRT1152XHM8B) || defined(CPU_MIMXRT1152XVM8B))
#include "MIMXRT1152_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ANADIG_LDO_SNVS_DIG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_LDO_SNVS_DIG_Peripheral_Access_Layer ANADIG_LDO_SNVS_DIG Peripheral Access Layer
 * @{
 */

/** ANADIG_LDO_SNVS_DIG - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1344];
  __IO uint32_t PMU_LDO_SNVS_DIG;                  /**< PMU_LDO_SNVS_DIG_REGISTER, offset: 0x540 */
} ANADIG_LDO_SNVS_DIG_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_LDO_SNVS_DIG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_LDO_SNVS_DIG_Register_Masks ANADIG_LDO_SNVS_DIG Register Masks
 * @{
 */

/*! @name PMU_LDO_SNVS_DIG - PMU_LDO_SNVS_DIG_REGISTER */
/*! @{ */

#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_LP_EN_MASK (0x1U)
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_LP_EN_SHIFT (0U)
/*! REG_LP_EN - REG_LP_EN */
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_LP_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_LP_EN_SHIFT)) & ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_LP_EN_MASK)

#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TEST_OVERRIDE_MASK (0x2U)
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TEST_OVERRIDE_SHIFT (1U)
/*! TEST_OVERRIDE - test_override */
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TEST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TEST_OVERRIDE_SHIFT)) & ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TEST_OVERRIDE_MASK)

#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_EN_MASK (0x4U)
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_EN_SHIFT (2U)
/*! REG_EN - REG_EN */
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_EN_SHIFT)) & ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_REG_EN_MASK)

#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TRIM_MASK (0x1F00U)
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TRIM_SHIFT (8U)
/*! TRIM - trim */
#define ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TRIM(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TRIM_SHIFT)) & ANADIG_LDO_SNVS_DIG_PMU_LDO_SNVS_DIG_TRIM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_LDO_SNVS_DIG_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_LDO_SNVS_DIG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_ANADIG_LDO_SNVS_DIG_H_ */

