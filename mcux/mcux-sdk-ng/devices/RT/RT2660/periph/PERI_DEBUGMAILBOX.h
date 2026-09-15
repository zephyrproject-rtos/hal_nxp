/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DEBUGMAILBOX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DEBUGMAILBOX.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DEBUGMAILBOX
 *
 * CMSIS Peripheral Access Layer for DEBUGMAILBOX
 */

#if !defined(PERI_DEBUGMAILBOX_H_)
#define PERI_DEBUGMAILBOX_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- DEBUGMAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUGMAILBOX_Peripheral_Access_Layer DEBUGMAILBOX Peripheral Access Layer
 * @{
 */

/** DEBUGMAILBOX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and Status Word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} DEBUGMAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- DEBUGMAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUGMAILBOX_Register_Masks DEBUGMAILBOX Register Masks
 * @{
 */

/*! @name CSW - Command and Status Word */
/*! @{ */

#define DEBUGMAILBOX_CSW_RESYNCH_REQ_MASK        (0x1U)
#define DEBUGMAILBOX_CSW_RESYNCH_REQ_SHIFT       (0U)
/*! RESYNCH_REQ - Resynchronization Request
 *  0b0..No request
 *  0b1..Request for resynchronization
 */
#define DEBUGMAILBOX_CSW_RESYNCH_REQ(x)          (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_RESYNCH_REQ_SHIFT)) & DEBUGMAILBOX_CSW_RESYNCH_REQ_MASK)

#define DEBUGMAILBOX_CSW_REQ_PENDING_MASK        (0x2U)
#define DEBUGMAILBOX_CSW_REQ_PENDING_SHIFT       (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No request pending
 *  0b1..The debugger has written a value into the REQUEST register and it's pending the chip reading REQUEST
 */
#define DEBUGMAILBOX_CSW_REQ_PENDING(x)          (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_REQ_PENDING_SHIFT)) & DEBUGMAILBOX_CSW_REQ_PENDING_MASK)

#define DEBUGMAILBOX_CSW_DBG_OR_ERR_MASK         (0x4U)
#define DEBUGMAILBOX_CSW_DBG_OR_ERR_SHIFT        (2U)
/*! DBG_OR_ERR - DBGMB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DEBUGMAILBOX_CSW_DBG_OR_ERR(x)           (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_DBG_OR_ERR_SHIFT)) & DEBUGMAILBOX_CSW_DBG_OR_ERR_MASK)

#define DEBUGMAILBOX_CSW_AHB_OR_ERR_MASK         (0x8U)
#define DEBUGMAILBOX_CSW_AHB_OR_ERR_SHIFT        (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DEBUGMAILBOX_CSW_AHB_OR_ERR(x)           (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_AHB_OR_ERR_SHIFT)) & DEBUGMAILBOX_CSW_AHB_OR_ERR_MASK)

#define DEBUGMAILBOX_CSW_SOFT_RESET_MASK         (0x10U)
#define DEBUGMAILBOX_CSW_SOFT_RESET_SHIFT        (4U)
/*! SOFT_RESET - Soft Reset
 *  0b0..No effect
 *  0b1..Reset
 */
#define DEBUGMAILBOX_CSW_SOFT_RESET(x)           (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_SOFT_RESET_SHIFT)) & DEBUGMAILBOX_CSW_SOFT_RESET_MASK)

#define DEBUGMAILBOX_CSW_CHIP_RESET_REQ_MASK     (0x20U)
#define DEBUGMAILBOX_CSW_CHIP_RESET_REQ_SHIFT    (5U)
/*! CHIP_RESET_REQ - Chip Reset Request
 *  0b0..No effect
 *  0b1..Reset
 */
#define DEBUGMAILBOX_CSW_CHIP_RESET_REQ(x)       (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_CSW_CHIP_RESET_REQ_SHIFT)) & DEBUGMAILBOX_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define DEBUGMAILBOX_REQUEST_REQUEST_MASK        (0xFFFFFFFFU)
#define DEBUGMAILBOX_REQUEST_REQUEST_SHIFT       (0U)
/*! REQUEST - Request Value */
#define DEBUGMAILBOX_REQUEST_REQUEST(x)          (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_REQUEST_REQUEST_SHIFT)) & DEBUGMAILBOX_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define DEBUGMAILBOX_RETURN_RET_MASK             (0xFFFFFFFFU)
#define DEBUGMAILBOX_RETURN_RET_SHIFT            (0U)
/*! RET - Return Value */
#define DEBUGMAILBOX_RETURN_RET(x)               (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_RETURN_RET_SHIFT)) & DEBUGMAILBOX_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define DEBUGMAILBOX_ID_ID_MASK                  (0xFFFFFFFFU)
#define DEBUGMAILBOX_ID_ID_SHIFT                 (0U)
/*! ID - Identification Value */
#define DEBUGMAILBOX_ID_ID(x)                    (((uint32_t)(((uint32_t)(x)) << DEBUGMAILBOX_ID_ID_SHIFT)) & DEBUGMAILBOX_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DEBUGMAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group DEBUGMAILBOX_Peripheral_Access_Layer */


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


#endif  /* PERI_DEBUGMAILBOX_H_ */

