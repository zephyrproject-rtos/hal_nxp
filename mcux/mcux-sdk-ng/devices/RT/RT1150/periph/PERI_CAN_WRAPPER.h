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
**         CMSIS Peripheral Access Layer for CAN_WRAPPER
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
 * @file PERI_CAN_WRAPPER.h
 * @version 0.2
 * @date 2026-02-26
 * @brief CMSIS Peripheral Access Layer for CAN_WRAPPER
 *
 * CMSIS Peripheral Access Layer for CAN_WRAPPER
 */

#if !defined(PERI_CAN_WRAPPER_H_)
#define PERI_CAN_WRAPPER_H_                      /**< Symbol preventing repeated inclusion */

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
   -- CAN_WRAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_WRAPPER_Peripheral_Access_Layer CAN_WRAPPER Peripheral Access Layer
 * @{
 */

/** CAN_WRAPPER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2528];
  __IO uint32_t GFWR;                              /**< Glitch Filter Width Register, offset: 0x9E0 */
} CAN_WRAPPER_Type;

/* ----------------------------------------------------------------------------
   -- CAN_WRAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_WRAPPER_Register_Masks CAN_WRAPPER Register Masks
 * @{
 */

/*! @name GFWR - Glitch Filter Width Register */
/*! @{ */

#define CAN_WRAPPER_GFWR_GFWR_MASK               (0xFFU)
#define CAN_WRAPPER_GFWR_GFWR_SHIFT              (0U)
/*! GFWR - Glitch Filter Width */
#define CAN_WRAPPER_GFWR_GFWR(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WRAPPER_GFWR_GFWR_SHIFT)) & CAN_WRAPPER_GFWR_GFWR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAN_WRAPPER_Register_Masks */


/*!
 * @}
 */ /* end of group CAN_WRAPPER_Peripheral_Access_Layer */


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


#endif  /* PERI_CAN_WRAPPER_H_ */

