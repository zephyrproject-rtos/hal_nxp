/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANA_OSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_ANA_OSC.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for ANA_OSC
 *
 * CMSIS Peripheral Access Layer for ANA_OSC
 */

#if !defined(PERI_ANA_OSC_H_)
#define PERI_ANA_OSC_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- ANA_OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANA_OSC_Peripheral_Access_Layer ANA_OSC Peripheral Access Layer
 * @{
 */

/** ANA_OSC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __I  uint32_t DIGPROG_DEVICE_ID;                 /**< Device ID, offset: 0x800 */
} ANA_OSC_Type;

/* ----------------------------------------------------------------------------
   -- ANA_OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANA_OSC_Register_Masks ANA_OSC Register Masks
 * @{
 */

/*! @name DIGPROG_DEVICE_ID - Device ID */
/*! @{ */

#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK (0xFFU)
#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT (0U)
/*! DIGPROG_MINOR - Bit[3:0] is the metal layer revision. Bit[7:4] is the base layer revision. */
#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MINOR(x) (((uint32_t)(((uint32_t)(x)) << ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MINOR_SHIFT)) & ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MINOR_MASK)

#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_MASK (0xFF00U)
#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_SHIFT (8U)
/*! DIGPROG_MAJOR_LOWER - DIGPROG_MAJOR_LOWER */
#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER(x) (((uint32_t)(((uint32_t)(x)) << ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_SHIFT)) & ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_LOWER_MASK)

#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_MASK (0xFF0000U)
#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_SHIFT (16U)
/*! DIGPROG_MAJOR_UPPER - DIGPROG_MAJOR_UPPER */
#define ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER(x) (((uint32_t)(((uint32_t)(x)) << ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_SHIFT)) & ANA_OSC_DIGPROG_DEVICE_ID_DIGPROG_MAJOR_UPPER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANA_OSC_Register_Masks */


/*!
 * @}
 */ /* end of group ANA_OSC_Peripheral_Access_Layer */


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


#endif  /* PERI_ANA_OSC_H_ */
