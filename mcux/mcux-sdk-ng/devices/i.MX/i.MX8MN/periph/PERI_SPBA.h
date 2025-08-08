/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPBA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SPBA.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPBA
 *
 * CMSIS Peripheral Access Layer for SPBA
 */

#if !defined(PERI_SPBA_H_)
#define PERI_SPBA_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- SPBA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPBA_Peripheral_Access_Layer SPBA Peripheral Access Layer
 * @{
 */

/** SPBA - Size of Registers Arrays */
#define SPBA_PRR_COUNT                            32u

/** SPBA - Register Layout Typedef */
typedef struct {
  __IO uint32_t PRR[SPBA_PRR_COUNT];               /**< Peripheral Rights Register, array offset: 0x0, array step: 0x4 */
} SPBA_Type;

/* ----------------------------------------------------------------------------
   -- SPBA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPBA_Register_Masks SPBA Register Masks
 * @{
 */

/*! @name PRR - Peripheral Rights Register */
/*! @{ */

#define SPBA_PRR_RARA_MASK                       (0x1U)
#define SPBA_PRR_RARA_SHIFT                      (0U)
/*! RARA
 *  0b0..Access to peripheral is not allowed.
 *  0b1..Access to peripheral is granted.
 */
#define SPBA_PRR_RARA(x)                         (((uint32_t)(((uint32_t)(x)) << SPBA_PRR_RARA_SHIFT)) & SPBA_PRR_RARA_MASK)

#define SPBA_PRR_RARB_MASK                       (0x2U)
#define SPBA_PRR_RARB_SHIFT                      (1U)
/*! RARB
 *  0b0..Access to peripheral is not allowed.
 *  0b1..Access to peripheral is granted.
 */
#define SPBA_PRR_RARB(x)                         (((uint32_t)(((uint32_t)(x)) << SPBA_PRR_RARB_SHIFT)) & SPBA_PRR_RARB_MASK)

#define SPBA_PRR_RARC_MASK                       (0x4U)
#define SPBA_PRR_RARC_SHIFT                      (2U)
/*! RARC
 *  0b0..Access to peripheral is not allowed.
 *  0b1..Access to peripheral is granted.
 */
#define SPBA_PRR_RARC(x)                         (((uint32_t)(((uint32_t)(x)) << SPBA_PRR_RARC_SHIFT)) & SPBA_PRR_RARC_MASK)

#define SPBA_PRR_ROI_MASK                        (0x30000U)
#define SPBA_PRR_ROI_SHIFT                       (16U)
/*! ROI
 *  0b00..Unowned resource.
 *  0b01..The resource is owned by master A port.
 *  0b10..The resource is owned by master B port.
 *  0b11..The resource is owned by master C port.
 */
#define SPBA_PRR_ROI(x)                          (((uint32_t)(((uint32_t)(x)) << SPBA_PRR_ROI_SHIFT)) & SPBA_PRR_ROI_MASK)

#define SPBA_PRR_RMO_MASK                        (0xC0000000U)
#define SPBA_PRR_RMO_SHIFT                       (30U)
/*! RMO
 *  0b00..The resource is unowned.
 *  0b01..Reserved.
 *  0b10..The resource is owned by another master.
 *  0b11..The resource is owned by the requesting master.
 */
#define SPBA_PRR_RMO(x)                          (((uint32_t)(((uint32_t)(x)) << SPBA_PRR_RMO_SHIFT)) & SPBA_PRR_RMO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPBA_Register_Masks */


/*!
 * @}
 */ /* end of group SPBA_Peripheral_Access_Layer */


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


#endif  /* PERI_SPBA_H_ */

