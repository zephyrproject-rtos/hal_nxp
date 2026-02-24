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
**         CMSIS Peripheral Access Layer for WAKEUP_AHBRM
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
 * @file PERI_WAKEUP_AHBRM.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for WAKEUP_AHBRM
 *
 * CMSIS Peripheral Access Layer for WAKEUP_AHBRM
 */

#if !defined(PERI_WAKEUP_AHBRM_H_)
#define PERI_WAKEUP_AHBRM_H_                     /**< Symbol preventing repeated inclusion */

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
   -- WAKEUP_AHBRM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AHBRM_Peripheral_Access_Layer WAKEUP_AHBRM Peripheral Access Layer
 * @{
 */

/** WAKEUP_AHBRM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __IO uint32_t CR;                                /**< Control, offset: 0x800 */
} WAKEUP_AHBRM_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_AHBRM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AHBRM_Register_Masks WAKEUP_AHBRM Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define WAKEUP_AHBRM_CR_ENB_MASK                 (0x1U)
#define WAKEUP_AHBRM_CR_ENB_SHIFT                (0U)
/*! ENB - Enable Remap
 *  0b0..The module is disabled and all input AHB addresses and attributes are simply routed to the output AHB address and attributes buses.
 *  0b1..All AHB addresses from the Cortex-M33 and ELE are remapped using the constant offset defined by the
 *       CR[RADDR] field. AHB accesses from other bus masters are simply passed through the module as if it was disabled.
 */
#define WAKEUP_AHBRM_CR_ENB(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_ENB_SHIFT)) & WAKEUP_AHBRM_CR_ENB_MASK)

#define WAKEUP_AHBRM_CR_LK_MASK                  (0x8U)
#define WAKEUP_AHBRM_CR_LK_SHIFT                 (3U)
/*! LK - Sticky lock bit */
#define WAKEUP_AHBRM_CR_LK(x)                    (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_LK_SHIFT)) & WAKEUP_AHBRM_CR_LK_MASK)

#define WAKEUP_AHBRM_CR_RADDR_MASK               (0xFFFFF80U)
#define WAKEUP_AHBRM_CR_RADDR_SHIFT              (7U)
/*! RADDR - Remap address */
#define WAKEUP_AHBRM_CR_RADDR(x)                 (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_RADDR_SHIFT)) & WAKEUP_AHBRM_CR_RADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKEUP_AHBRM_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_AHBRM_Peripheral_Access_Layer */


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


#endif  /* PERI_WAKEUP_AHBRM_H_ */

