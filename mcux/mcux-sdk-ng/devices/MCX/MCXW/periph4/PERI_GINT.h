/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GINT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GINT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GINT
 *
 * CMSIS Peripheral Access Layer for GINT
 */

#if !defined(PERI_GINT_H_)
#define PERI_GINT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
   -- GINT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GINT_Peripheral_Access_Layer GINT Peripheral Access Layer
 * @{
 */

/** GINT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< GPIO grouped interrupt control register, offset: 0x0 */
       uint8_t RESERVED_0[28];
  __IO uint32_t PORT_POL;                          /**< GPIO grouped interrupt port 0 polarity register, offset: 0x20 */
       uint8_t RESERVED_1[28];
  __IO uint32_t PORT_ENA;                          /**< GPIO grouped interrupt port 0 enable register, offset: 0x40 */
} GINT_Type;

/* ----------------------------------------------------------------------------
   -- GINT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GINT_Register_Masks GINT Register Masks
 * @{
 */

/*! @name CTRL - GPIO grouped interrupt control register */
/*! @{ */

#define GINT_CTRL_INT_MASK                       (0x1U)
#define GINT_CTRL_INT_SHIFT                      (0U)
/*! INT - Group interrupt status. This bit is cleared by writing a one to it. Writing zero has no effect.
 *  0b0..No request. No interrupt request is pending.
 *  0b1..Request active. Interrupt request is active.
 */
#define GINT_CTRL_INT(x)                         (((uint32_t)(((uint32_t)(x)) << GINT_CTRL_INT_SHIFT)) & GINT_CTRL_INT_MASK)

#define GINT_CTRL_COMB_MASK                      (0x2U)
#define GINT_CTRL_COMB_SHIFT                     (1U)
/*! COMB - Combine enabled inputs for group interrupt
 *  0b0..Or. OR functionality: A grouped interrupt is generated when any one of the enabled inputs is active (based on its programmed polarity).
 *  0b1..And. AND functionality: An interrupt is generated when all enabled bits are active (based on their programmed polarity).
 */
#define GINT_CTRL_COMB(x)                        (((uint32_t)(((uint32_t)(x)) << GINT_CTRL_COMB_SHIFT)) & GINT_CTRL_COMB_MASK)

#define GINT_CTRL_TRIG_MASK                      (0x4U)
#define GINT_CTRL_TRIG_SHIFT                     (2U)
/*! TRIG - Group interrupt trigger
 *  0b0..Edge-triggered.
 *  0b1..Level-triggered.
 */
#define GINT_CTRL_TRIG(x)                        (((uint32_t)(((uint32_t)(x)) << GINT_CTRL_TRIG_SHIFT)) & GINT_CTRL_TRIG_MASK)
/*! @} */

/*! @name PORT_POL - GPIO grouped interrupt port 0 polarity register */
/*! @{ */

#define GINT_PORT_POL_POL_MASK                   (0x7FFFFFU)
#define GINT_PORT_POL_POL_SHIFT                  (0U)
/*! POL - Configure pin polarity of port m pins for group interrupt. */
#define GINT_PORT_POL_POL(x)                     (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL_SHIFT)) & GINT_PORT_POL_POL_MASK)
/*! @} */

/*! @name PORT_ENA - GPIO grouped interrupt port 0 enable register */
/*! @{ */

#define GINT_PORT_ENA_ENA_MASK                   (0x7FFFFFU)
#define GINT_PORT_ENA_ENA_SHIFT                  (0U)
/*! ENA - Enable port 0 pin for group interrupt. */
#define GINT_PORT_ENA_ENA(x)                     (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA_SHIFT)) & GINT_PORT_ENA_ENA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GINT_Register_Masks */


/*!
 * @}
 */ /* end of group GINT_Peripheral_Access_Layer */


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


#endif  /* PERI_GINT_H_ */

