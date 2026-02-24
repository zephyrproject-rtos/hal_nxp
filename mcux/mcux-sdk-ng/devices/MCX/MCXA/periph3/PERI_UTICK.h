/*
** ###################################################################
**     Processors:          MCXA173VFM
**                          MCXA173VLF
**                          MCXA173VLH
**                          MCXA173VLL
**                          MCXA174VFM
**                          MCXA174VLF
**                          MCXA174VLH
**                          MCXA174VLL
**                          MCXA183VFM
**                          MCXA183VLF
**                          MCXA183VLH
**                          MCXA183VLL
**                          MCXA184VFM
**                          MCXA184VLF
**                          MCXA184VLH
**                          MCXA184VLL
**                          MCXA343VFM
**                          MCXA343VLF
**                          MCXA343VLH
**                          MCXA343VLL
**                          MCXA344VFM
**                          MCXA344VLF
**                          MCXA344VLH
**                          MCXA344VLL
**                          MCXA353VFM
**                          MCXA353VLF
**                          MCXA353VLH
**                          MCXA353VLL
**                          MCXA354VFM
**                          MCXA354VLF
**                          MCXA354VLH
**                          MCXA354VLL
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b251111
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UTICK
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_UTICK.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for UTICK
 *
 * CMSIS Peripheral Access Layer for UTICK
 */

#if !defined(PERI_UTICK_H_)
#define PERI_UTICK_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA173VFM) || defined(CPU_MCXA173VLF) || defined(CPU_MCXA173VLH) || defined(CPU_MCXA173VLL))
#include "MCXA173_COMMON.h"
#elif (defined(CPU_MCXA174VFM) || defined(CPU_MCXA174VLF) || defined(CPU_MCXA174VLH) || defined(CPU_MCXA174VLL))
#include "MCXA174_COMMON.h"
#elif (defined(CPU_MCXA183VFM) || defined(CPU_MCXA183VLF) || defined(CPU_MCXA183VLH) || defined(CPU_MCXA183VLL))
#include "MCXA183_COMMON.h"
#elif (defined(CPU_MCXA184VFM) || defined(CPU_MCXA184VLF) || defined(CPU_MCXA184VLH) || defined(CPU_MCXA184VLL))
#include "MCXA184_COMMON.h"
#elif (defined(CPU_MCXA343VFM) || defined(CPU_MCXA343VLF) || defined(CPU_MCXA343VLH) || defined(CPU_MCXA343VLL))
#include "MCXA343_COMMON.h"
#elif (defined(CPU_MCXA344VFM) || defined(CPU_MCXA344VLF) || defined(CPU_MCXA344VLH) || defined(CPU_MCXA344VLL))
#include "MCXA344_COMMON.h"
#elif (defined(CPU_MCXA353VFM) || defined(CPU_MCXA353VLF) || defined(CPU_MCXA353VLH) || defined(CPU_MCXA353VLL))
#include "MCXA353_COMMON.h"
#elif (defined(CPU_MCXA354VFM) || defined(CPU_MCXA354VLF) || defined(CPU_MCXA354VLH) || defined(CPU_MCXA354VLL))
#include "MCXA354_COMMON.h"
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
   -- UTICK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UTICK_Peripheral_Access_Layer UTICK Peripheral Access Layer
 * @{
 */

/** UTICK - Size of Registers Arrays */
#define UTICK_CAP_COUNT                           4u

/** UTICK - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control, offset: 0x0 */
  __IO uint32_t STAT;                              /**< Status, offset: 0x4 */
  __IO uint32_t CFG;                               /**< Capture Configuration, offset: 0x8 */
  __O  uint32_t CAPCLR;                            /**< Capture Clear, offset: 0xC */
  __I  uint32_t CAP[UTICK_CAP_COUNT];              /**< Capture, array offset: 0x10, array step: 0x4 */
} UTICK_Type;

/* ----------------------------------------------------------------------------
   -- UTICK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UTICK_Register_Masks UTICK Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define UTICK_CTRL_DELAYVAL_MASK                 (0x7FFFFFFFU)
#define UTICK_CTRL_DELAYVAL_SHIFT                (0U)
/*! DELAYVAL - Tick Interval
 *  0b0000000000000000000000000000000..
 *  *..Clock cycles as defined in the description
 */
#define UTICK_CTRL_DELAYVAL(x)                   (((uint32_t)(((uint32_t)(x)) << UTICK_CTRL_DELAYVAL_SHIFT)) & UTICK_CTRL_DELAYVAL_MASK)

#define UTICK_CTRL_REPEAT_MASK                   (0x80000000U)
#define UTICK_CTRL_REPEAT_SHIFT                  (31U)
/*! REPEAT - Repeat Delay
 *  0b0..One-time delay
 *  0b1..Delay repeats continuously
 */
#define UTICK_CTRL_REPEAT(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CTRL_REPEAT_SHIFT)) & UTICK_CTRL_REPEAT_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define UTICK_STAT_INTR_MASK                     (0x1U)
#define UTICK_STAT_INTR_SHIFT                    (0U)
/*! INTR - Interrupt Flag
 *  0b0..Not pending
 *  0b1..Pending
 */
#define UTICK_STAT_INTR(x)                       (((uint32_t)(((uint32_t)(x)) << UTICK_STAT_INTR_SHIFT)) & UTICK_STAT_INTR_MASK)

#define UTICK_STAT_ACTIVE_MASK                   (0x2U)
#define UTICK_STAT_ACTIVE_SHIFT                  (1U)
/*! ACTIVE - Timer Active Flag
 *  0b0..Inactive (stopped)
 *  0b1..Active
 */
#define UTICK_STAT_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_STAT_ACTIVE_SHIFT)) & UTICK_STAT_ACTIVE_MASK)
/*! @} */

/*! @name CFG - Capture Configuration */
/*! @{ */

#define UTICK_CFG_CAPEN0_MASK                    (0x1U)
#define UTICK_CFG_CAPEN0_SHIFT                   (0U)
/*! CAPEN0 - Enable Capture 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN0(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN0_SHIFT)) & UTICK_CFG_CAPEN0_MASK)

#define UTICK_CFG_CAPEN1_MASK                    (0x2U)
#define UTICK_CFG_CAPEN1_SHIFT                   (1U)
/*! CAPEN1 - Enable Capture 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN1(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN1_SHIFT)) & UTICK_CFG_CAPEN1_MASK)

#define UTICK_CFG_CAPEN2_MASK                    (0x4U)
#define UTICK_CFG_CAPEN2_SHIFT                   (2U)
/*! CAPEN2 - Enable Capture 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN2(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN2_SHIFT)) & UTICK_CFG_CAPEN2_MASK)

#define UTICK_CFG_CAPEN3_MASK                    (0x8U)
#define UTICK_CFG_CAPEN3_SHIFT                   (3U)
/*! CAPEN3 - Enable Capture 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define UTICK_CFG_CAPEN3(x)                      (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPEN3_SHIFT)) & UTICK_CFG_CAPEN3_MASK)

#define UTICK_CFG_CAPPOL0_MASK                   (0x100U)
#define UTICK_CFG_CAPPOL0_SHIFT                  (8U)
/*! CAPPOL0 - Capture Polarity 0
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL0(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL0_SHIFT)) & UTICK_CFG_CAPPOL0_MASK)

#define UTICK_CFG_CAPPOL1_MASK                   (0x200U)
#define UTICK_CFG_CAPPOL1_SHIFT                  (9U)
/*! CAPPOL1 - Capture-Polarity 1
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL1(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL1_SHIFT)) & UTICK_CFG_CAPPOL1_MASK)

#define UTICK_CFG_CAPPOL2_MASK                   (0x400U)
#define UTICK_CFG_CAPPOL2_SHIFT                  (10U)
/*! CAPPOL2 - Capture Polarity 2
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL2(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL2_SHIFT)) & UTICK_CFG_CAPPOL2_MASK)

#define UTICK_CFG_CAPPOL3_MASK                   (0x800U)
#define UTICK_CFG_CAPPOL3_SHIFT                  (11U)
/*! CAPPOL3 - Capture Polarity 3
 *  0b0..Positive
 *  0b1..Negative
 */
#define UTICK_CFG_CAPPOL3(x)                     (((uint32_t)(((uint32_t)(x)) << UTICK_CFG_CAPPOL3_SHIFT)) & UTICK_CFG_CAPPOL3_MASK)
/*! @} */

/*! @name CAPCLR - Capture Clear */
/*! @{ */

#define UTICK_CAPCLR_CAPCLR0_MASK                (0x1U)
#define UTICK_CAPCLR_CAPCLR0_SHIFT               (0U)
/*! CAPCLR0 - Clear Capture 0
 *  0b0..Does nothing
 *  0b1..Clears the CAP0 register value
 */
#define UTICK_CAPCLR_CAPCLR0(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR0_SHIFT)) & UTICK_CAPCLR_CAPCLR0_MASK)

#define UTICK_CAPCLR_CAPCLR1_MASK                (0x2U)
#define UTICK_CAPCLR_CAPCLR1_SHIFT               (1U)
/*! CAPCLR1 - Clear Capture 1
 *  0b0..Does nothing
 *  0b1..Clears the CAP1 register value
 */
#define UTICK_CAPCLR_CAPCLR1(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR1_SHIFT)) & UTICK_CAPCLR_CAPCLR1_MASK)

#define UTICK_CAPCLR_CAPCLR2_MASK                (0x4U)
#define UTICK_CAPCLR_CAPCLR2_SHIFT               (2U)
/*! CAPCLR2 - Clear Capture 2
 *  0b0..Does nothing
 *  0b1..Clears the CAP2 register value
 */
#define UTICK_CAPCLR_CAPCLR2(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR2_SHIFT)) & UTICK_CAPCLR_CAPCLR2_MASK)

#define UTICK_CAPCLR_CAPCLR3_MASK                (0x8U)
#define UTICK_CAPCLR_CAPCLR3_SHIFT               (3U)
/*! CAPCLR3 - Clear Capture 3
 *  0b0..Does nothing
 *  0b1..Clears the CAP3 register value
 */
#define UTICK_CAPCLR_CAPCLR3(x)                  (((uint32_t)(((uint32_t)(x)) << UTICK_CAPCLR_CAPCLR3_SHIFT)) & UTICK_CAPCLR_CAPCLR3_MASK)
/*! @} */

/*! @name CAP - Capture */
/*! @{ */

#define UTICK_CAP_CAP_VALUE_MASK                 (0x7FFFFFFFU)
#define UTICK_CAP_CAP_VALUE_SHIFT                (0U)
/*! CAP_VALUE - Captured Value for the Related Capture Event */
#define UTICK_CAP_CAP_VALUE(x)                   (((uint32_t)(((uint32_t)(x)) << UTICK_CAP_CAP_VALUE_SHIFT)) & UTICK_CAP_CAP_VALUE_MASK)

#define UTICK_CAP_VALID_MASK                     (0x80000000U)
#define UTICK_CAP_VALID_SHIFT                    (31U)
/*! VALID - Captured Value Valid Flag
 *  0b0..Valid value not captured
 *  0b1..Valid value captured
 */
#define UTICK_CAP_VALID(x)                       (((uint32_t)(((uint32_t)(x)) << UTICK_CAP_VALID_SHIFT)) & UTICK_CAP_VALID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UTICK_Register_Masks */


/*!
 * @}
 */ /* end of group UTICK_Peripheral_Access_Layer */


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


#endif  /* PERI_UTICK_H_ */

