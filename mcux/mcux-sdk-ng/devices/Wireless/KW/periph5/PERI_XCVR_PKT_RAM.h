/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XCVR_PKT_RAM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file XCVR_PKT_RAM.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_PKT_RAM
 *
 * CMSIS Peripheral Access Layer for XCVR_PKT_RAM
 */

#if !defined(XCVR_PKT_RAM_H_)
#define XCVR_PKT_RAM_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- XCVR_PKT_RAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PKT_RAM_Peripheral_Access_Layer XCVR_PKT_RAM Peripheral Access Layer
 * @{
 */

/** XCVR_PKT_RAM - Size of Registers Arrays */
#define XCVR_PKT_RAM_PACKET_RAM_0_COUNT           544u
#define XCVR_PKT_RAM_PACKET_RAM_1_COUNT           544u

/** XCVR_PKT_RAM - Register Layout Typedef */
typedef struct {
  __IO uint16_t PACKET_RAM_0[XCVR_PKT_RAM_PACKET_RAM_0_COUNT]; /**< Shared Packet RAM for multiple Link Layer usage., array offset: 0x0, array step: 0x2 */
  __IO uint16_t PACKET_RAM_1[XCVR_PKT_RAM_PACKET_RAM_1_COUNT]; /**< Shared Packet RAM for multiple Link Layer usage., array offset: 0x440, array step: 0x2 */
} XCVR_PKT_RAM_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_PKT_RAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_PKT_RAM_Register_Masks XCVR_PKT_RAM Register Masks
 * @{
 */

/*! @name PACKET_RAM_0 - Shared Packet RAM for multiple Link Layer usage. */
/*! @{ */

#define XCVR_PKT_RAM_PACKET_RAM_0_LSBYTE_MASK    (0xFFU)
#define XCVR_PKT_RAM_PACKET_RAM_0_LSBYTE_SHIFT   (0U)
/*! LSBYTE - LSBYTE */
#define XCVR_PKT_RAM_PACKET_RAM_0_LSBYTE(x)      (((uint16_t)(((uint16_t)(x)) << XCVR_PKT_RAM_PACKET_RAM_0_LSBYTE_SHIFT)) & XCVR_PKT_RAM_PACKET_RAM_0_LSBYTE_MASK)

#define XCVR_PKT_RAM_PACKET_RAM_0_MSBYTE_MASK    (0xFF00U)
#define XCVR_PKT_RAM_PACKET_RAM_0_MSBYTE_SHIFT   (8U)
/*! MSBYTE - MSBYTE */
#define XCVR_PKT_RAM_PACKET_RAM_0_MSBYTE(x)      (((uint16_t)(((uint16_t)(x)) << XCVR_PKT_RAM_PACKET_RAM_0_MSBYTE_SHIFT)) & XCVR_PKT_RAM_PACKET_RAM_0_MSBYTE_MASK)
/*! @} */

/*! @name PACKET_RAM_1 - Shared Packet RAM for multiple Link Layer usage. */
/*! @{ */

#define XCVR_PKT_RAM_PACKET_RAM_1_LSBYTE_MASK    (0xFFU)
#define XCVR_PKT_RAM_PACKET_RAM_1_LSBYTE_SHIFT   (0U)
/*! LSBYTE - LSBYTE */
#define XCVR_PKT_RAM_PACKET_RAM_1_LSBYTE(x)      (((uint16_t)(((uint16_t)(x)) << XCVR_PKT_RAM_PACKET_RAM_1_LSBYTE_SHIFT)) & XCVR_PKT_RAM_PACKET_RAM_1_LSBYTE_MASK)

#define XCVR_PKT_RAM_PACKET_RAM_1_MSBYTE_MASK    (0xFF00U)
#define XCVR_PKT_RAM_PACKET_RAM_1_MSBYTE_SHIFT   (8U)
/*! MSBYTE - MSBYTE */
#define XCVR_PKT_RAM_PACKET_RAM_1_MSBYTE(x)      (((uint16_t)(((uint16_t)(x)) << XCVR_PKT_RAM_PACKET_RAM_1_MSBYTE_SHIFT)) & XCVR_PKT_RAM_PACKET_RAM_1_MSBYTE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_PKT_RAM_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_PKT_RAM_Peripheral_Access_Layer */


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


#endif  /* XCVR_PKT_RAM_H_ */

