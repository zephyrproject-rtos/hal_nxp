/*
** ###################################################################
**     Processors:          MCXA175VLH
**                          MCXA175VLL
**                          MCXA175VLQ
**                          MCXA175VPN
**                          MCXA176VLH
**                          MCXA176VLL
**                          MCXA176VLQ
**                          MCXA176VPN
**                          MCXA185VLH
**                          MCXA185VLL
**                          MCXA185VLQ
**                          MCXA185VPN
**                          MCXA186VLH
**                          MCXA186VLL
**                          MCXA186VLQ
**                          MCXA186VPN
**                          MCXA255VLH
**                          MCXA255VLL
**                          MCXA255VLQ
**                          MCXA255VPN
**                          MCXA256VLH
**                          MCXA256VLL
**                          MCXA256VLQ
**                          MCXA256VPN
**                          MCXA265VLH
**                          MCXA265VLL
**                          MCXA265VLQ
**                          MCXA265VPN
**                          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250804
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

#if (defined(CPU_MCXA175VLH) || defined(CPU_MCXA175VLL) || defined(CPU_MCXA175VLQ) || defined(CPU_MCXA175VPN))
#include "MCXA175_COMMON.h"
#elif (defined(CPU_MCXA176VLH) || defined(CPU_MCXA176VLL) || defined(CPU_MCXA176VLQ) || defined(CPU_MCXA176VPN))
#include "MCXA176_COMMON.h"
#elif (defined(CPU_MCXA185VLH) || defined(CPU_MCXA185VLL) || defined(CPU_MCXA185VLQ) || defined(CPU_MCXA185VPN))
#include "MCXA185_COMMON.h"
#elif (defined(CPU_MCXA186VLH) || defined(CPU_MCXA186VLL) || defined(CPU_MCXA186VLQ) || defined(CPU_MCXA186VPN))
#include "MCXA186_COMMON.h"
#elif (defined(CPU_MCXA255VLH) || defined(CPU_MCXA255VLL) || defined(CPU_MCXA255VLQ) || defined(CPU_MCXA255VPN))
#include "MCXA255_COMMON.h"
#elif (defined(CPU_MCXA256VLH) || defined(CPU_MCXA256VLL) || defined(CPU_MCXA256VLQ) || defined(CPU_MCXA256VPN))
#include "MCXA256_COMMON.h"
#elif (defined(CPU_MCXA265VLH) || defined(CPU_MCXA265VLL) || defined(CPU_MCXA265VLQ) || defined(CPU_MCXA265VPN))
#include "MCXA265_COMMON.h"
#elif (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
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

