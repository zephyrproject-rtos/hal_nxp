/*
** ###################################################################
**     Processors:          MCXW727AMFTA_cm33_core0
**                          MCXW727AMFTA_cm33_core1
**                          MCXW727CMFTA_cm33_core0
**                          MCXW727CMFTA_cm33_core1
**                          MCXW727DMFTA_cm33_core0
**                          MCXW727DMFTA_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DBGMB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DBGMB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DBGMB
 *
 * CMSIS Peripheral Access Layer for DBGMB
 */

#if !defined(PERI_DBGMB_H_)
#define PERI_DBGMB_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW727AMFTA_cm33_core0))
#include "MCXW727A_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727AMFTA_cm33_core1))
#include "MCXW727A_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core0))
#include "MCXW727C_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core1))
#include "MCXW727C_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core0))
#include "MCXW727D_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core1))
#include "MCXW727D_cm33_core1_COMMON.h"
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
   -- DBGMB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DBGMB_Peripheral_Access_Layer DBGMB Peripheral Access Layer
 * @{
 */

/** DBGMB - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and Status Word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} DBGMB_Type;

/* ----------------------------------------------------------------------------
   -- DBGMB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DBGMB_Register_Masks DBGMB Register Masks
 * @{
 */

/*! @name CSW - Command and Status Word */
/*! @{ */

#define DBGMB_CSW_RESYNCH_REQ_MASK               (0x1U)
#define DBGMB_CSW_RESYNCH_REQ_SHIFT              (0U)
/*! RESYNCH_REQ - Resynchronization Request
 *  0b0..No request
 *  0b1..Request for resynchronization
 */
#define DBGMB_CSW_RESYNCH_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << DBGMB_CSW_RESYNCH_REQ_SHIFT)) & DBGMB_CSW_RESYNCH_REQ_MASK)

#define DBGMB_CSW_REQ_PENDING_MASK               (0x2U)
#define DBGMB_CSW_REQ_PENDING_SHIFT              (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No request pending
 *  0b1..Request for resynchronization pending
 */
#define DBGMB_CSW_REQ_PENDING(x)                 (((uint32_t)(((uint32_t)(x)) << DBGMB_CSW_REQ_PENDING_SHIFT)) & DBGMB_CSW_REQ_PENDING_MASK)

#define DBGMB_CSW_DBG_OR_ERR_MASK                (0x4U)
#define DBGMB_CSW_DBG_OR_ERR_SHIFT               (2U)
/*! DBG_OR_ERR - DBGMB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DBGMB_CSW_DBG_OR_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << DBGMB_CSW_DBG_OR_ERR_SHIFT)) & DBGMB_CSW_DBG_OR_ERR_MASK)

#define DBGMB_CSW_AHB_OR_ERR_MASK                (0x8U)
#define DBGMB_CSW_AHB_OR_ERR_SHIFT               (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No overrun
 *  0b1..Overrun occurred
 */
#define DBGMB_CSW_AHB_OR_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << DBGMB_CSW_AHB_OR_ERR_SHIFT)) & DBGMB_CSW_AHB_OR_ERR_MASK)

#define DBGMB_CSW_SOFT_RESET_MASK                (0x10U)
#define DBGMB_CSW_SOFT_RESET_SHIFT               (4U)
/*! SOFT_RESET - Soft Reset
 *  0b0..No effect
 *  0b1..Reset
 */
#define DBGMB_CSW_SOFT_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << DBGMB_CSW_SOFT_RESET_SHIFT)) & DBGMB_CSW_SOFT_RESET_MASK)

#define DBGMB_CSW_CHIP_RESET_REQ_MASK            (0x20U)
#define DBGMB_CSW_CHIP_RESET_REQ_SHIFT           (5U)
/*! CHIP_RESET_REQ - Chip Reset Request
 *  0b0..No effect
 *  0b1..Reset
 */
#define DBGMB_CSW_CHIP_RESET_REQ(x)              (((uint32_t)(((uint32_t)(x)) << DBGMB_CSW_CHIP_RESET_REQ_SHIFT)) & DBGMB_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define DBGMB_REQUEST_REQUEST_MASK               (0xFFFFFFFFU)
#define DBGMB_REQUEST_REQUEST_SHIFT              (0U)
/*! REQUEST - Request Value */
#define DBGMB_REQUEST_REQUEST(x)                 (((uint32_t)(((uint32_t)(x)) << DBGMB_REQUEST_REQUEST_SHIFT)) & DBGMB_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define DBGMB_RETURN_RET_MASK                    (0xFFFFFFFFU)
#define DBGMB_RETURN_RET_SHIFT                   (0U)
/*! RET - Return Value */
#define DBGMB_RETURN_RET(x)                      (((uint32_t)(((uint32_t)(x)) << DBGMB_RETURN_RET_SHIFT)) & DBGMB_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define DBGMB_ID_ID_MASK                         (0xFFFFFFFFU)
#define DBGMB_ID_ID_SHIFT                        (0U)
/*! ID - Identification Value */
#define DBGMB_ID_ID(x)                           (((uint32_t)(((uint32_t)(x)) << DBGMB_ID_ID_SHIFT)) & DBGMB_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DBGMB_Register_Masks */


/*!
 * @}
 */ /* end of group DBGMB_Peripheral_Access_Layer */


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


#endif  /* PERI_DBGMB_H_ */

