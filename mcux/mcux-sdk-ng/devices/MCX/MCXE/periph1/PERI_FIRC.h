/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FIRC
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
 * @file PERI_FIRC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for FIRC
 *
 * CMSIS Peripheral Access Layer for FIRC
 */

#if !defined(PERI_FIRC_H_)
#define PERI_FIRC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- FIRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FIRC_Peripheral_Access_Layer FIRC Peripheral Access Layer
 * @{
 */

/** FIRC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __I  uint32_t STATUS_REGISTER;                   /**< Status Register, offset: 0x4 */
  __IO uint32_t STDBY_ENABLE;                      /**< Standby Enable Register, offset: 0x8 */
} FIRC_Type;

/* ----------------------------------------------------------------------------
   -- FIRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FIRC_Register_Masks FIRC Register Masks
 * @{
 */

/*! @name STATUS_REGISTER - Status Register */
/*! @{ */

#define FIRC_STATUS_REGISTER_STATUS_MASK         (0x1U)
#define FIRC_STATUS_REGISTER_STATUS_SHIFT        (0U)
/*! STATUS - Status bit for FIRC
 *  0b0..FIRC is off or unstable.
 *  0b1..FIRC is on and stable.
 */
#define FIRC_STATUS_REGISTER_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << FIRC_STATUS_REGISTER_STATUS_SHIFT)) & FIRC_STATUS_REGISTER_STATUS_MASK)
/*! @} */

/*! @name STDBY_ENABLE - Standby Enable Register */
/*! @{ */

#define FIRC_STDBY_ENABLE_STDBY_EN_MASK          (0x1U)
#define FIRC_STDBY_ENABLE_STDBY_EN_SHIFT         (0U)
/*! STDBY_EN - Enables or disables FIRC in chip's Standby mode.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FIRC_STDBY_ENABLE_STDBY_EN(x)            (((uint32_t)(((uint32_t)(x)) << FIRC_STDBY_ENABLE_STDBY_EN_SHIFT)) & FIRC_STDBY_ENABLE_STDBY_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FIRC_Register_Masks */


/*!
 * @}
 */ /* end of group FIRC_Peripheral_Access_Layer */


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


#endif  /* PERI_FIRC_H_ */

