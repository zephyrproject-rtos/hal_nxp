/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SIRC
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
 * @file PERI_SIRC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for SIRC
 *
 * CMSIS Peripheral Access Layer for SIRC
 */

#if !defined(PERI_SIRC_H_)
#define PERI_SIRC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- SIRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIRC_Peripheral_Access_Layer SIRC Peripheral Access Layer
 * @{
 */

/** SIRC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __I  uint32_t SR;                                /**< Status Register, offset: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MISCELLANEOUS_IN;                  /**< Miscellaneous input, offset: 0xC */
} SIRC_Type;

/* ----------------------------------------------------------------------------
   -- SIRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIRC_Register_Masks SIRC Register Masks
 * @{
 */

/*! @name SR - Status Register */
/*! @{ */

#define SIRC_SR_STATUS_MASK                      (0x1U)
#define SIRC_SR_STATUS_SHIFT                     (0U)
/*! STATUS - Status bit for SIRC
 *  0b0..SIRC is off or unstable
 *  0b1..SIRC is on and stable
 */
#define SIRC_SR_STATUS(x)                        (((uint32_t)(((uint32_t)(x)) << SIRC_SR_STATUS_SHIFT)) & SIRC_SR_STATUS_MASK)
/*! @} */

/*! @name MISCELLANEOUS_IN - Miscellaneous input */
/*! @{ */

#define SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE_MASK (0x100U)
#define SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE_SHIFT (8U)
/*! STANDBY_ENABLE - Standby Enable for SIRC
 *  0b0..SIRC disables in Standby mode
 *  0b1..SIRC enables in Standby mode
 */
#define SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE_SHIFT)) & SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIRC_Register_Masks */


/*!
 * @}
 */ /* end of group SIRC_Peripheral_Access_Layer */


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


#endif  /* PERI_SIRC_H_ */

