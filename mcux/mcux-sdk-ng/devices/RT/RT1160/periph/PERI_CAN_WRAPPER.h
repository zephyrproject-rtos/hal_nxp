/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAN_WRAPPER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CAN_WRAPPER.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAN_WRAPPER
 *
 * CMSIS Peripheral Access Layer for CAN_WRAPPER
 */

#if !defined(PERI_CAN_WRAPPER_H_)
#define PERI_CAN_WRAPPER_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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

