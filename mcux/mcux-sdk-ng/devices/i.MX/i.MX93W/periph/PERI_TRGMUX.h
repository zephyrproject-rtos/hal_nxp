/*
** ###################################################################
**     Processors:          MIMX93W32610GCM_ca55
**                          MIMX93W32610GCM_cm33
**                          MIMX93W52610GCM_ca55
**                          MIMX93W52610GCM_cm33
**
**     Version:             rev. 1.0, 2025-12-13
**     Build:               b260114
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TRGMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-12-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_TRGMUX.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX93W32610GCM_ca55))
#include "MIMX93W32_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W32610GCM_cm33))
#include "MIMX93W32_cm33_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_ca55))
#include "MIMX93W52_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_cm33))
#include "MIMX93W52_cm33_COMMON.h"
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

#if defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG0;                              /**< TRGMUX REG0, offset: 0x0 */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name REG0 - TRGMUX REG0 */
/*! @{ */

#define TRGMUX_REG0_SEL0_MASK                    (0xFU)
#define TRGMUX_REG0_SEL0_SHIFT                   (0U)
/*! SEL0 - TRGMUX Source Select 0 */
#define TRGMUX_REG0_SEL0(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG0_SEL0_SHIFT)) & TRGMUX_REG0_SEL0_MASK)

#define TRGMUX_REG0_SEL1_MASK                    (0xF00U)
#define TRGMUX_REG0_SEL1_SHIFT                   (8U)
/*! SEL1 - TRGMUX Source Select 1 */
#define TRGMUX_REG0_SEL1(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG0_SEL1_SHIFT)) & TRGMUX_REG0_SEL1_MASK)

#define TRGMUX_REG0_LK_MASK                      (0x80000000U)
#define TRGMUX_REG0_LK_SHIFT                     (31U)
/*! LK - TRGMUX Register Lock
 *  0b0..Register is writable
 *  0b1..Register is not writable until the next system reset
 */
#define TRGMUX_REG0_LK(x)                        (((uint32_t)(((uint32_t)(x)) << TRGMUX_REG0_LK_SHIFT)) & TRGMUX_REG0_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */


/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_TRGMUX_H_ */

