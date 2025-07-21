/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SELFTEST
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
 * @file PERI_SELFTEST.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for SELFTEST
 *
 * CMSIS Peripheral Access Layer for SELFTEST
 */

#if !defined(PERI_SELFTEST_H_)
#define PERI_SELFTEST_H_                         /**< Symbol preventing repeated inclusion */

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
   -- SELFTEST Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SELFTEST_Peripheral_Access_Layer SELFTEST Peripheral Access Layer
 * @{
 */

/** SELFTEST - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONFIG_REG;                        /**< Configuration register, offset: 0x0 */
       uint8_t RESERVED_0[16];
  __IO uint32_t LBIST_PROG_REG;                    /**< LBIST Program, offset: 0x14 */
} SELFTEST_Type;

/* ----------------------------------------------------------------------------
   -- SELFTEST Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SELFTEST_Register_Masks SELFTEST Register Masks
 * @{
 */

/*! @name CONFIG_REG - Configuration register */
/*! @{ */

#define SELFTEST_CONFIG_REG_PCS_STEP_SIZE_MASK   (0x70U)
#define SELFTEST_CONFIG_REG_PCS_STEP_SIZE_SHIFT  (4U)
/*! PCS_STEP_SIZE - PCS Step Size */
#define SELFTEST_CONFIG_REG_PCS_STEP_SIZE(x)     (((uint32_t)(((uint32_t)(x)) << SELFTEST_CONFIG_REG_PCS_STEP_SIZE_SHIFT)) & SELFTEST_CONFIG_REG_PCS_STEP_SIZE_MASK)

#define SELFTEST_CONFIG_REG_PCS_ENABLE_START_MASK (0x80U)
#define SELFTEST_CONFIG_REG_PCS_ENABLE_START_SHIFT (7U)
/*! PCS_ENABLE_START - PCS Enable Start */
#define SELFTEST_CONFIG_REG_PCS_ENABLE_START(x)  (((uint32_t)(((uint32_t)(x)) << SELFTEST_CONFIG_REG_PCS_ENABLE_START_SHIFT)) & SELFTEST_CONFIG_REG_PCS_ENABLE_START_MASK)

#define SELFTEST_CONFIG_REG_PCS_ENABLE_END_MASK  (0x100U)
#define SELFTEST_CONFIG_REG_PCS_ENABLE_END_SHIFT (8U)
/*! PCS_ENABLE_END - PCS Enable End */
#define SELFTEST_CONFIG_REG_PCS_ENABLE_END(x)    (((uint32_t)(((uint32_t)(x)) << SELFTEST_CONFIG_REG_PCS_ENABLE_END_SHIFT)) & SELFTEST_CONFIG_REG_PCS_ENABLE_END_MASK)
/*! @} */

/*! @name LBIST_PROG_REG - LBIST Program */
/*! @{ */

#define SELFTEST_LBIST_PROG_REG_LBIST_SHIFT_COUNT_MASK (0xFFU)
#define SELFTEST_LBIST_PROG_REG_LBIST_SHIFT_COUNT_SHIFT (0U)
/*! LBIST_SHIFT_COUNT - LBIST Shift Count */
#define SELFTEST_LBIST_PROG_REG_LBIST_SHIFT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << SELFTEST_LBIST_PROG_REG_LBIST_SHIFT_COUNT_SHIFT)) & SELFTEST_LBIST_PROG_REG_LBIST_SHIFT_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SELFTEST_Register_Masks */


/*!
 * @}
 */ /* end of group SELFTEST_Peripheral_Access_Layer */


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


#endif  /* PERI_SELFTEST_H_ */

