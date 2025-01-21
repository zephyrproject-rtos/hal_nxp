/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 4.0, 2018-01-26
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPBA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**
** ###################################################################
*/

/*!
 * @file SPBA.h
 * @version 4.0
 * @date 2018-01-26
 * @brief CMSIS Peripheral Access Layer for SPBA
 *
 * CMSIS Peripheral Access Layer for SPBA
 */

#if !defined(SPBA_H_)
#define SPBA_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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


#endif  /* SPBA_H_ */

