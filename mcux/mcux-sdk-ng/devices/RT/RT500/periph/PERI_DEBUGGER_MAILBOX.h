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
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DEBUGGER_MAILBOX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DEBUGGER_MAILBOX.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DEBUGGER_MAILBOX
 *
 * CMSIS Peripheral Access Layer for DEBUGGER_MAILBOX
 */

#if !defined(PERI_DEBUGGER_MAILBOX_H_)
#define PERI_DEBUGGER_MAILBOX_H_                 /**< Symbol preventing repeated inclusion */

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
   -- DEBUGGER_MAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUGGER_MAILBOX_Peripheral_Access_Layer DEBUGGER_MAILBOX Peripheral Access Layer
 * @{
 */

/** DEBUGGER_MAILBOX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and status word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} DEBUGGER_MAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- DEBUGGER_MAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUGGER_MAILBOX_Register_Masks DEBUGGER_MAILBOX Register Masks
 * @{
 */

/*! @name CSW - Command and status word */
/*! @{ */

#define DEBUGGER_MAILBOX_CSW_RESYNCH_REQ_MASK    (0x1U)
#define DEBUGGER_MAILBOX_CSW_RESYNCH_REQ_SHIFT   (0U)
/*! RESYNCH_REQ - Re-synchronization Request
 *  0b0..No Request
 *  0b1..Request for re-synchronization
 */
#define DEBUGGER_MAILBOX_CSW_RESYNCH_REQ(x)      (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_CSW_RESYNCH_REQ_SHIFT)) & DEBUGGER_MAILBOX_CSW_RESYNCH_REQ_MASK)

#define DEBUGGER_MAILBOX_CSW_REQ_PENDING_MASK    (0x2U)
#define DEBUGGER_MAILBOX_CSW_REQ_PENDING_SHIFT   (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No Request Pending
 *  0b1..Request for Re-synchronization Pending
 */
#define DEBUGGER_MAILBOX_CSW_REQ_PENDING(x)      (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_CSW_REQ_PENDING_SHIFT)) & DEBUGGER_MAILBOX_CSW_REQ_PENDING_MASK)

#define DEBUGGER_MAILBOX_CSW_DBG_OR_ERR_MASK     (0x4U)
#define DEBUGGER_MAILBOX_CSW_DBG_OR_ERR_SHIFT    (2U)
/*! DBG_OR_ERR - Debug Overrun Error
 *  0b0..No Debug Overrun error
 *  0b1..Debug Overrun Error. A debug overrun occurred.
 */
#define DEBUGGER_MAILBOX_CSW_DBG_OR_ERR(x)       (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_CSW_DBG_OR_ERR_SHIFT)) & DEBUGGER_MAILBOX_CSW_DBG_OR_ERR_MASK)

#define DEBUGGER_MAILBOX_CSW_AHB_OR_ERR_MASK     (0x8U)
#define DEBUGGER_MAILBOX_CSW_AHB_OR_ERR_SHIFT    (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No AHB Overrun Error
 *  0b1..AHB Overrun Error. An AHB overrun occurred.
 */
#define DEBUGGER_MAILBOX_CSW_AHB_OR_ERR(x)       (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_CSW_AHB_OR_ERR_SHIFT)) & DEBUGGER_MAILBOX_CSW_AHB_OR_ERR_MASK)

#define DEBUGGER_MAILBOX_CSW_SOFT_RESET_MASK     (0x10U)
#define DEBUGGER_MAILBOX_CSW_SOFT_RESET_SHIFT    (4U)
/*! SOFT_RESET - Soft Reset */
#define DEBUGGER_MAILBOX_CSW_SOFT_RESET(x)       (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_CSW_SOFT_RESET_SHIFT)) & DEBUGGER_MAILBOX_CSW_SOFT_RESET_MASK)

#define DEBUGGER_MAILBOX_CSW_CHIP_RESET_REQ_MASK (0x20U)
#define DEBUGGER_MAILBOX_CSW_CHIP_RESET_REQ_SHIFT (5U)
/*! CHIP_RESET_REQ - Chip Reset Request */
#define DEBUGGER_MAILBOX_CSW_CHIP_RESET_REQ(x)   (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_CSW_CHIP_RESET_REQ_SHIFT)) & DEBUGGER_MAILBOX_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define DEBUGGER_MAILBOX_REQUEST_REQUEST_MASK    (0xFFFFFFFFU)
#define DEBUGGER_MAILBOX_REQUEST_REQUEST_SHIFT   (0U)
/*! REQUEST - Request Value */
#define DEBUGGER_MAILBOX_REQUEST_REQUEST(x)      (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_REQUEST_REQUEST_SHIFT)) & DEBUGGER_MAILBOX_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define DEBUGGER_MAILBOX_RETURN_RETURN_MASK      (0xFFFFFFFFU)
#define DEBUGGER_MAILBOX_RETURN_RETURN_SHIFT     (0U)
/*! RETURN - Return Value */
#define DEBUGGER_MAILBOX_RETURN_RETURN(x)        (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_RETURN_RETURN_SHIFT)) & DEBUGGER_MAILBOX_RETURN_RETURN_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define DEBUGGER_MAILBOX_ID_ID_MASK              (0xFFFFFFFFU)
#define DEBUGGER_MAILBOX_ID_ID_SHIFT             (0U)
/*! ID - Identification Value */
#define DEBUGGER_MAILBOX_ID_ID(x)                (((uint32_t)(((uint32_t)(x)) << DEBUGGER_MAILBOX_ID_ID_SHIFT)) & DEBUGGER_MAILBOX_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DEBUGGER_MAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group DEBUGGER_MAILBOX_Peripheral_Access_Layer */


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


#endif  /* PERI_DEBUGGER_MAILBOX_H_ */

