/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 5.0, 2020-08-27
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSTIMER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**
** ###################################################################
*/

/*!
 * @file OSTIMER.h
 * @version 5.0
 * @date 2020-08-27
 * @brief CMSIS Peripheral Access Layer for OSTIMER
 *
 * CMSIS Peripheral Access Layer for OSTIMER
 */

#if !defined(OSTIMER_H_)
#define OSTIMER_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OSTIMER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSTIMER_Peripheral_Access_Layer OSTIMER Peripheral Access Layer
 * @{
 */

/** OSTIMER - Register Layout Typedef */
typedef struct {
  __I  uint32_t EVTIMERL;                          /**< EVTIMER Low, offset: 0x0 */
  __I  uint32_t EVTIMERH;                          /**< EVTIMER High, offset: 0x4 */
  __I  uint32_t CAPTURE_L;                         /**< Local Capture Low for CPU, offset: 0x8 */
  __I  uint32_t CAPTURE_H;                         /**< Local Capture High for CPU, offset: 0xC */
  __IO uint32_t MATCH_L;                           /**< Local Match Low for CPU, offset: 0x10 */
  __IO uint32_t MATCH_H;                           /**< Local Match High for CPU, offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t OSEVENT_CTRL;                      /**< OSTIMER Control for CPU, offset: 0x1C */
} OSTIMER_Type;

/* ----------------------------------------------------------------------------
   -- OSTIMER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSTIMER_Register_Masks OSTIMER Register Masks
 * @{
 */

/*! @name EVTIMERL - EVTIMER Low */
/*! @{ */

#define OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_MASK (0xFFFFFFFFU)
#define OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_SHIFT (0U)
/*! EVTIMER_COUNT_VALUE - EVTimer Count Value */
#define OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE(x)  (((uint32_t)(((uint32_t)(x)) << OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_SHIFT)) & OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_MASK)
/*! @} */

/*! @name EVTIMERH - EVTIMER High */
/*! @{ */

#define OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_MASK (0xFFFFFFFFU)
#define OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_SHIFT (0U)
/*! EVTIMER_COUNT_VALUE - EVTimer Count Value */
#define OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE(x)  (((uint32_t)(((uint32_t)(x)) << OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_SHIFT)) & OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_MASK)
/*! @} */

/*! @name CAPTURE_L - Local Capture Low for CPU */
/*! @{ */

#define OSTIMER_CAPTURE_L_CAPTURE_VALUE_MASK     (0xFFFFFFFFU)
#define OSTIMER_CAPTURE_L_CAPTURE_VALUE_SHIFT    (0U)
/*! CAPTURE_VALUE - EVTimer Capture Value */
#define OSTIMER_CAPTURE_L_CAPTURE_VALUE(x)       (((uint32_t)(((uint32_t)(x)) << OSTIMER_CAPTURE_L_CAPTURE_VALUE_SHIFT)) & OSTIMER_CAPTURE_L_CAPTURE_VALUE_MASK)
/*! @} */

/*! @name CAPTURE_H - Local Capture High for CPU */
/*! @{ */

#define OSTIMER_CAPTURE_H_CAPTURE_VALUE_MASK     (0xFFFFFFFFU)
#define OSTIMER_CAPTURE_H_CAPTURE_VALUE_SHIFT    (0U)
/*! CAPTURE_VALUE - EVTimer Capture Value */
#define OSTIMER_CAPTURE_H_CAPTURE_VALUE(x)       (((uint32_t)(((uint32_t)(x)) << OSTIMER_CAPTURE_H_CAPTURE_VALUE_SHIFT)) & OSTIMER_CAPTURE_H_CAPTURE_VALUE_MASK)
/*! @} */

/*! @name MATCH_L - Local Match Low for CPU */
/*! @{ */

#define OSTIMER_MATCH_L_MATCH_VALUE_MASK         (0xFFFFFFFFU)
#define OSTIMER_MATCH_L_MATCH_VALUE_SHIFT        (0U)
/*! MATCH_VALUE - EVTimer Match Value */
#define OSTIMER_MATCH_L_MATCH_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << OSTIMER_MATCH_L_MATCH_VALUE_SHIFT)) & OSTIMER_MATCH_L_MATCH_VALUE_MASK)
/*! @} */

/*! @name MATCH_H - Local Match High for CPU */
/*! @{ */

#define OSTIMER_MATCH_H_MATCH_VALUE_MASK         (0xFFFFFFFFU)
#define OSTIMER_MATCH_H_MATCH_VALUE_SHIFT        (0U)
/*! MATCH_VALUE - EVTimer Match Value */
#define OSTIMER_MATCH_H_MATCH_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << OSTIMER_MATCH_H_MATCH_VALUE_SHIFT)) & OSTIMER_MATCH_H_MATCH_VALUE_MASK)
/*! @} */

/*! @name OSEVENT_CTRL - OSTIMER Control for CPU */
/*! @{ */

#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_MASK (0x1U)
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_SHIFT (0U)
/*! OSTIMER_INTRFLAG - Interrupt Flag */
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG(x) (((uint32_t)(((uint32_t)(x)) << OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_SHIFT)) & OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_MASK)

#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK (0x2U)
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_SHIFT (1U)
/*! OSTIMER_INTENA - Interrupt or Wake-Up Request
 *  0b0..Interrupts blocked
 *  0b1..Interrupts enabled
 */
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA(x)   (((uint32_t)(((uint32_t)(x)) << OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_SHIFT)) & OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK)

#define OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_MASK   (0x4U)
#define OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_SHIFT  (2U)
/*! MATCH_WR_RDY - EVTimer Match Write Ready */
#define OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY(x)     (((uint32_t)(((uint32_t)(x)) << OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_SHIFT)) & OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSTIMER_Register_Masks */


/*!
 * @}
 */ /* end of group OSTIMER_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* OSTIMER_H_ */

