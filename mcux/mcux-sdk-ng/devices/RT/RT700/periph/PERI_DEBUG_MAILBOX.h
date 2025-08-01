/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DEBUG_MAILBOX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DEBUG_MAILBOX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DEBUG_MAILBOX
 *
 * CMSIS Peripheral Access Layer for DEBUG_MAILBOX
 */

#if !defined(PERI_DEBUG_MAILBOX_H_)
#define PERI_DEBUG_MAILBOX_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- DEBUG_MAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUG_MAILBOX_Peripheral_Access_Layer DEBUG_MAILBOX Peripheral Access Layer
 * @{
 */

/** DEBUG_MAILBOX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and Status Word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} DEBUG_MAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- DEBUG_MAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DEBUG_MAILBOX_Register_Masks DEBUG_MAILBOX Register Masks
 * @{
 */

/*! @name CSW - Command and Status Word */
/*! @{ */

#define DEBUG_MAILBOX_CSW_RESYNCH_REQ_MASK       (0x1U)
#define DEBUG_MAILBOX_CSW_RESYNCH_REQ_SHIFT      (0U)
/*! RESYNCH_REQ - Resynchronization Request
 *  0b0..No request
 *  0b1..Request for resynchronization
 */
#define DEBUG_MAILBOX_CSW_RESYNCH_REQ(x)         (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_CSW_RESYNCH_REQ_SHIFT)) & DEBUG_MAILBOX_CSW_RESYNCH_REQ_MASK)

#define DEBUG_MAILBOX_CSW_REQ_PENDING_MASK       (0x2U)
#define DEBUG_MAILBOX_CSW_REQ_PENDING_SHIFT      (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No request pending
 *  0b1..Request for resynchronization pending
 */
#define DEBUG_MAILBOX_CSW_REQ_PENDING(x)         (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_CSW_REQ_PENDING_SHIFT)) & DEBUG_MAILBOX_CSW_REQ_PENDING_MASK)

#define DEBUG_MAILBOX_CSW_DBG_OR_ERR_MASK        (0x4U)
#define DEBUG_MAILBOX_CSW_DBG_OR_ERR_SHIFT       (2U)
/*! DBG_OR_ERR - DBGMB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DEBUG_MAILBOX_CSW_DBG_OR_ERR(x)          (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_CSW_DBG_OR_ERR_SHIFT)) & DEBUG_MAILBOX_CSW_DBG_OR_ERR_MASK)

#define DEBUG_MAILBOX_CSW_AHB_OR_ERR_MASK        (0x8U)
#define DEBUG_MAILBOX_CSW_AHB_OR_ERR_SHIFT       (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DEBUG_MAILBOX_CSW_AHB_OR_ERR(x)          (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_CSW_AHB_OR_ERR_SHIFT)) & DEBUG_MAILBOX_CSW_AHB_OR_ERR_MASK)

#define DEBUG_MAILBOX_CSW_SOFT_RESET_MASK        (0x10U)
#define DEBUG_MAILBOX_CSW_SOFT_RESET_SHIFT       (4U)
/*! SOFT_RESET - Soft Reset
 *  0b0..No effect
 *  0b1..Reset
 */
#define DEBUG_MAILBOX_CSW_SOFT_RESET(x)          (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_CSW_SOFT_RESET_SHIFT)) & DEBUG_MAILBOX_CSW_SOFT_RESET_MASK)

#define DEBUG_MAILBOX_CSW_CHIP_RESET_REQ_MASK    (0x20U)
#define DEBUG_MAILBOX_CSW_CHIP_RESET_REQ_SHIFT   (5U)
/*! CHIP_RESET_REQ - Chip Reset Request
 *  0b0..No effect
 *  0b1..Reset
 */
#define DEBUG_MAILBOX_CSW_CHIP_RESET_REQ(x)      (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_CSW_CHIP_RESET_REQ_SHIFT)) & DEBUG_MAILBOX_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define DEBUG_MAILBOX_REQUEST_REQUEST_MASK       (0xFFFFFFFFU)
#define DEBUG_MAILBOX_REQUEST_REQUEST_SHIFT      (0U)
/*! REQUEST - Request Value */
#define DEBUG_MAILBOX_REQUEST_REQUEST(x)         (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_REQUEST_REQUEST_SHIFT)) & DEBUG_MAILBOX_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define DEBUG_MAILBOX_RETURN_RET_MASK            (0xFFFFFFFFU)
#define DEBUG_MAILBOX_RETURN_RET_SHIFT           (0U)
/*! RET - Return Value */
#define DEBUG_MAILBOX_RETURN_RET(x)              (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_RETURN_RET_SHIFT)) & DEBUG_MAILBOX_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define DEBUG_MAILBOX_ID_ID_MASK                 (0xFFFFFFFFU)
#define DEBUG_MAILBOX_ID_ID_SHIFT                (0U)
/*! ID - Identification Value */
#define DEBUG_MAILBOX_ID_ID(x)                   (((uint32_t)(((uint32_t)(x)) << DEBUG_MAILBOX_ID_ID_SHIFT)) & DEBUG_MAILBOX_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DEBUG_MAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group DEBUG_MAILBOX_Peripheral_Access_Layer */


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


#endif  /* PERI_DEBUG_MAILBOX_H_ */

