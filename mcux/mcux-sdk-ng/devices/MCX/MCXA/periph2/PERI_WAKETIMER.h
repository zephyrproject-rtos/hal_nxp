/*
** ###################################################################
**     Processors:          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**                          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**                          MCXA346VLH
**                          MCXA346VLL
**                          MCXA346VLQ
**                          MCXA346VPN
**                          MCXA366VLH
**                          MCXA366VLL
**                          MCXA366VLQ
**                          MCXA366VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250729
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WAKETIMER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_WAKETIMER.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for WAKETIMER
 *
 * CMSIS Peripheral Access Layer for WAKETIMER
 */

#if !defined(PERI_WAKETIMER_H_)
#define PERI_WAKETIMER_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
#elif (defined(CPU_MCXA345VLH) || defined(CPU_MCXA345VLL) || defined(CPU_MCXA345VLQ) || defined(CPU_MCXA345VPN))
#include "MCXA345_COMMON.h"
#elif (defined(CPU_MCXA346VLH) || defined(CPU_MCXA346VLL) || defined(CPU_MCXA346VLQ) || defined(CPU_MCXA346VPN))
#include "MCXA346_COMMON.h"
#elif (defined(CPU_MCXA366VLH) || defined(CPU_MCXA366VLL) || defined(CPU_MCXA366VLQ) || defined(CPU_MCXA366VPN))
#include "MCXA366_COMMON.h"
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
   -- WAKETIMER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKETIMER_Peripheral_Access_Layer WAKETIMER Peripheral Access Layer
 * @{
 */

/** WAKETIMER - Register Layout Typedef */
typedef struct {
  __IO uint32_t WAKE_TIMER_CTRL;                   /**< Wake Timer Control, offset: 0x0 */
       uint8_t RESERVED_0[8];
  __IO uint32_t WAKE_TIMER_CNT;                    /**< Wake Timer Counter, offset: 0xC */
} WAKETIMER_Type;

/* ----------------------------------------------------------------------------
   -- WAKETIMER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKETIMER_Register_Masks WAKETIMER Register Masks
 * @{
 */

/*! @name WAKE_TIMER_CTRL - Wake Timer Control */
/*! @{ */

#define WAKETIMER_WAKE_TIMER_CTRL_WAKE_FLAG_MASK (0x2U)
#define WAKETIMER_WAKE_TIMER_CTRL_WAKE_FLAG_SHIFT (1U)
/*! WAKE_FLAG - Wake Timer Status Flag
 *  0b0..Wake timer has not timed out.
 *  0b1..Wake timer has timed out.
 */
#define WAKETIMER_WAKE_TIMER_CTRL_WAKE_FLAG(x)   (((uint32_t)(((uint32_t)(x)) << WAKETIMER_WAKE_TIMER_CTRL_WAKE_FLAG_SHIFT)) & WAKETIMER_WAKE_TIMER_CTRL_WAKE_FLAG_MASK)

#define WAKETIMER_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_MASK (0x4U)
#define WAKETIMER_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_SHIFT (2U)
/*! CLR_WAKE_TIMER - Clear Wake Timer
 *  0b0..No effect.
 *  0b1..Clears the wake timer counter and halts operation until a new count value is loaded.
 */
#define WAKETIMER_WAKE_TIMER_CTRL_CLR_WAKE_TIMER(x) (((uint32_t)(((uint32_t)(x)) << WAKETIMER_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_SHIFT)) & WAKETIMER_WAKE_TIMER_CTRL_CLR_WAKE_TIMER_MASK)

#define WAKETIMER_WAKE_TIMER_CTRL_OSC_DIV_ENA_MASK (0x10U)
#define WAKETIMER_WAKE_TIMER_CTRL_OSC_DIV_ENA_SHIFT (4U)
/*! OSC_DIV_ENA - OSC Divide Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define WAKETIMER_WAKE_TIMER_CTRL_OSC_DIV_ENA(x) (((uint32_t)(((uint32_t)(x)) << WAKETIMER_WAKE_TIMER_CTRL_OSC_DIV_ENA_SHIFT)) & WAKETIMER_WAKE_TIMER_CTRL_OSC_DIV_ENA_MASK)

#define WAKETIMER_WAKE_TIMER_CTRL_INTR_EN_MASK   (0x20U)
#define WAKETIMER_WAKE_TIMER_CTRL_INTR_EN_SHIFT  (5U)
/*! INTR_EN - Enable Interrupt
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define WAKETIMER_WAKE_TIMER_CTRL_INTR_EN(x)     (((uint32_t)(((uint32_t)(x)) << WAKETIMER_WAKE_TIMER_CTRL_INTR_EN_SHIFT)) & WAKETIMER_WAKE_TIMER_CTRL_INTR_EN_MASK)
/*! @} */

/*! @name WAKE_TIMER_CNT - Wake Timer Counter */
/*! @{ */

#define WAKETIMER_WAKE_TIMER_CNT_WAKE_CNT_MASK   (0xFFFFFFFFU)
#define WAKETIMER_WAKE_TIMER_CNT_WAKE_CNT_SHIFT  (0U)
/*! WAKE_CNT - Wake Counter */
#define WAKETIMER_WAKE_TIMER_CNT_WAKE_CNT(x)     (((uint32_t)(((uint32_t)(x)) << WAKETIMER_WAKE_TIMER_CNT_WAKE_CNT_SHIFT)) & WAKETIMER_WAKE_TIMER_CNT_WAKE_CNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKETIMER_Register_Masks */


/*!
 * @}
 */ /* end of group WAKETIMER_Peripheral_Access_Layer */


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


#endif  /* PERI_WAKETIMER_H_ */

