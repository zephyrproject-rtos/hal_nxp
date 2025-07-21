/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSTIMER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OSTIMER.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSTIMER
 *
 * CMSIS Peripheral Access Layer for OSTIMER
 */

#if !defined(PERI_OSTIMER_H_)
#define PERI_OSTIMER_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
  __I  uint32_t EVTIMERL;                          /**< EVTIMER Low Register, offset: 0x0 */
  __I  uint32_t EVTIMERH;                          /**< EVTIMER High Register, offset: 0x4 */
  __I  uint32_t CAPTURE_L;                         /**< Local Capture Low Register, offset: 0x8 */
  __I  uint32_t CAPTURE_H;                         /**< Local Capture High Register, offset: 0xC */
  __IO uint32_t MATCH_L;                           /**< Local Match Low Register, offset: 0x10 */
  __IO uint32_t MATCH_H;                           /**< Match High Register, offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t OSEVENT_CTRL;                      /**< OS_EVENT TIMER Control Register, offset: 0x1C */
} OSTIMER_Type;

/* ----------------------------------------------------------------------------
   -- OSTIMER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSTIMER_Register_Masks OSTIMER Register Masks
 * @{
 */

/*! @name EVTIMERL - EVTIMER Low Register */
/*! @{ */

#define OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_MASK (0xFFFFFFFFU)
#define OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_SHIFT (0U)
/*! EVTIMER_COUNT_VALUE - A read reflects the current value of the lower 32 bits of the EVTIMER.
 *    Note there is physically only one EVTimer, readable from all domains.
 */
#define OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE(x)  (((uint32_t)(((uint32_t)(x)) << OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_SHIFT)) & OSTIMER_EVTIMERL_EVTIMER_COUNT_VALUE_MASK)
/*! @} */

/*! @name EVTIMERH - EVTIMER High Register */
/*! @{ */

#define OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_MASK (0xFFFFFFFFU)
#define OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_SHIFT (0U)
/*! EVTIMER_COUNT_VALUE - A read reflects the current value of the upper 32 bits of the EVTIMER.
 *    Note there is physically only one EVTimer, readable from all domains.
 */
#define OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE(x)  (((uint32_t)(((uint32_t)(x)) << OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_SHIFT)) & OSTIMER_EVTIMERH_EVTIMER_COUNT_VALUE_MASK)
/*! @} */

/*! @name CAPTURE_L - Local Capture Low Register */
/*! @{ */

#define OSTIMER_CAPTURE_L_CAPTURE_VALUE_MASK     (0xFFFFFFFFU)
#define OSTIMER_CAPTURE_L_CAPTURE_VALUE_SHIFT    (0U)
/*! CAPTURE_VALUE - A read reflects the value of the lower 32 bits of the central EVTIMER at the
 *    time the last capture signal was generated by the CPU. A separate pair of CAPTURE registers are
 *    implemented for each CPU. Each CPU reads its own capture value at the same pair of addresses.
 */
#define OSTIMER_CAPTURE_L_CAPTURE_VALUE(x)       (((uint32_t)(((uint32_t)(x)) << OSTIMER_CAPTURE_L_CAPTURE_VALUE_SHIFT)) & OSTIMER_CAPTURE_L_CAPTURE_VALUE_MASK)
/*! @} */

/*! @name CAPTURE_H - Local Capture High Register */
/*! @{ */

#define OSTIMER_CAPTURE_H_CAPTURE_VALUE_MASK     (0xFFFFFFFFU)
#define OSTIMER_CAPTURE_H_CAPTURE_VALUE_SHIFT    (0U)
/*! CAPTURE_VALUE - A read reflects the value of the upper 32 bits of the central EVTIMER at the
 *    time the last capture signal was generated by the CPU. A separate pair of CAPTURE registers are
 *    implemented for each CPU. Each CPU reads its own capture value at the same pair of addresses.
 */
#define OSTIMER_CAPTURE_H_CAPTURE_VALUE(x)       (((uint32_t)(((uint32_t)(x)) << OSTIMER_CAPTURE_H_CAPTURE_VALUE_SHIFT)) & OSTIMER_CAPTURE_H_CAPTURE_VALUE_MASK)
/*! @} */

/*! @name MATCH_L - Local Match Low Register */
/*! @{ */

#define OSTIMER_MATCH_L_MATCH_VALUE_MASK         (0xFFFFFFFFU)
#define OSTIMER_MATCH_L_MATCH_VALUE_SHIFT        (0U)
/*! MATCH_VALUE - The value written to the MATCH (L/H) register pair is compared against the central
 *    EVTIMER. When a match occurs, an interrupt request is generated if enabled. A separate pair
 *    of MATCH registers are implemented for each CPU. Each CPU reads its own local value at the same
 *    pair of addresses.
 */
#define OSTIMER_MATCH_L_MATCH_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << OSTIMER_MATCH_L_MATCH_VALUE_SHIFT)) & OSTIMER_MATCH_L_MATCH_VALUE_MASK)
/*! @} */

/*! @name MATCH_H - Match High Register */
/*! @{ */

#define OSTIMER_MATCH_H_MATCH_VALUE_MASK         (0xFFFFFFFFU)
#define OSTIMER_MATCH_H_MATCH_VALUE_SHIFT        (0U)
/*! MATCH_VALUE - The value written to the MATCH (L/H) register pair is compared against the central
 *    EVTIMER. When a match occurs, an interrupt request is generated if enabled. A separate pair
 *    of MATCH registers are implemented for each CPU. Each CPU reads its own local value at the same
 *    pair of addresses.
 */
#define OSTIMER_MATCH_H_MATCH_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << OSTIMER_MATCH_H_MATCH_VALUE_SHIFT)) & OSTIMER_MATCH_H_MATCH_VALUE_MASK)
/*! @} */

/*! @name OSEVENT_CTRL - OS_EVENT TIMER Control Register */
/*! @{ */

#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_MASK (0x1U)
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_SHIFT (0U)
/*! OSTIMER_INTRFLAG - This bit is set when a match occurs between the central 64-bit EVTIMER and
 *    the value programmed in the Match-register pair for the associated CPU This bit is cleared by
 *    writing a '1'. Writes to clear this bit are asynchronous. This should be done before a new match
 *    value is written into the MATCH_L/H registers
 */
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG(x) (((uint32_t)(((uint32_t)(x)) << OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_SHIFT)) & OSTIMER_OSEVENT_CTRL_OSTIMER_INTRFLAG_MASK)

#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK (0x2U)
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_SHIFT (1U)
/*! OSTIMER_INTENA - When this bit is '1' an interrupt/wakeup request to the Domainn processor will
 *    be asserted when the OSTIMER_INTR flag is set. When this bit is '0', interrupt/wakeup requests
 *    due to the OSTIMER_INTR flag are blocked.A separate OSEVENT_CTRL register is implemented for
 *    each CPU. Each CPU reads its own local value at the same address.
 */
#define OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA(x)   (((uint32_t)(((uint32_t)(x)) << OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_SHIFT)) & OSTIMER_OSEVENT_CTRL_OSTIMER_INTENA_MASK)

#define OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_MASK   (0x4U)
#define OSTIMER_OSEVENT_CTRL_MATCH_WR_RDY_SHIFT  (2U)
/*! MATCH_WR_RDY - This bit will be low when it is safe to write to reload the Match Registers. In
 *    typical applications it should not be necessary to test this bit.
 */
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


#endif  /* PERI_OSTIMER_H_ */

