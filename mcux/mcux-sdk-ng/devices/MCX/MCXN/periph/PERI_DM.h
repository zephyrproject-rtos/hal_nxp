/*
** ###################################################################
**     Processors:          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 2.0, 2023-02-01
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**
** ###################################################################
*/

/*!
 * @file DM.h
 * @version 2.0
 * @date 2023-02-01
 * @brief CMSIS Peripheral Access Layer for DM
 *
 * CMSIS Peripheral Access Layer for DM
 */

#if !defined(DM_H_)
#define DM_H_                                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- DM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DM_Peripheral_Access_Layer DM Peripheral Access Layer
 * @{
 */

/** DM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSW;                               /**< Command and Status Word, offset: 0x0 */
  __IO uint32_t REQUEST;                           /**< Request Value, offset: 0x4 */
  __IO uint32_t RETURN;                            /**< Return Value, offset: 0x8 */
       uint8_t RESERVED_0[240];
  __I  uint32_t ID;                                /**< Identification, offset: 0xFC */
} DM_Type;

/* ----------------------------------------------------------------------------
   -- DM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DM_Register_Masks DM Register Masks
 * @{
 */

/*! @name CSW - Command and Status Word */
/*! @{ */

#define DM_CSW_RESYNCH_REQ_MASK                  (0x1U)
#define DM_CSW_RESYNCH_REQ_SHIFT                 (0U)
/*! RESYNCH_REQ - Resynchronization Request
 *  0b0..No request
 *  0b1..Request for resynchronization
 */
#define DM_CSW_RESYNCH_REQ(x)                    (((uint32_t)(((uint32_t)(x)) << DM_CSW_RESYNCH_REQ_SHIFT)) & DM_CSW_RESYNCH_REQ_MASK)

#define DM_CSW_REQ_PENDING_MASK                  (0x2U)
#define DM_CSW_REQ_PENDING_SHIFT                 (1U)
/*! REQ_PENDING - Request Pending
 *  0b0..No request pending
 *  0b1..Request for resynchronization pending
 */
#define DM_CSW_REQ_PENDING(x)                    (((uint32_t)(((uint32_t)(x)) << DM_CSW_REQ_PENDING_SHIFT)) & DM_CSW_REQ_PENDING_MASK)

#define DM_CSW_DBG_OR_ERR_MASK                   (0x4U)
#define DM_CSW_DBG_OR_ERR_SHIFT                  (2U)
/*! DBG_OR_ERR - DBGMB Overrun Error
 *  0b0..No DBGMB Overrun error
 *  0b1..DBGMB overrun error. A DBGMB overrun occurred.
 */
#define DM_CSW_DBG_OR_ERR(x)                     (((uint32_t)(((uint32_t)(x)) << DM_CSW_DBG_OR_ERR_SHIFT)) & DM_CSW_DBG_OR_ERR_MASK)

#define DM_CSW_AHB_OR_ERR_MASK                   (0x8U)
#define DM_CSW_AHB_OR_ERR_SHIFT                  (3U)
/*! AHB_OR_ERR - AHB Overrun Error
 *  0b0..No AHB Overrun Error
 *  0b1..AHB Overrun Error. An AHB overrun occurred.
 */
#define DM_CSW_AHB_OR_ERR(x)                     (((uint32_t)(((uint32_t)(x)) << DM_CSW_AHB_OR_ERR_SHIFT)) & DM_CSW_AHB_OR_ERR_MASK)

#define DM_CSW_SOFT_RESET_MASK                   (0x10U)
#define DM_CSW_SOFT_RESET_SHIFT                  (4U)
/*! SOFT_RESET - Soft Reset */
#define DM_CSW_SOFT_RESET(x)                     (((uint32_t)(((uint32_t)(x)) << DM_CSW_SOFT_RESET_SHIFT)) & DM_CSW_SOFT_RESET_MASK)

#define DM_CSW_CHIP_RESET_REQ_MASK               (0x20U)
#define DM_CSW_CHIP_RESET_REQ_SHIFT              (5U)
/*! CHIP_RESET_REQ - Chip Reset Request */
#define DM_CSW_CHIP_RESET_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << DM_CSW_CHIP_RESET_REQ_SHIFT)) & DM_CSW_CHIP_RESET_REQ_MASK)
/*! @} */

/*! @name REQUEST - Request Value */
/*! @{ */

#define DM_REQUEST_REQUEST_MASK                  (0xFFFFFFFFU)
#define DM_REQUEST_REQUEST_SHIFT                 (0U)
/*! REQUEST - Request Value */
#define DM_REQUEST_REQUEST(x)                    (((uint32_t)(((uint32_t)(x)) << DM_REQUEST_REQUEST_SHIFT)) & DM_REQUEST_REQUEST_MASK)
/*! @} */

/*! @name RETURN - Return Value */
/*! @{ */

#define DM_RETURN_RET_MASK                       (0xFFFFFFFFU)
#define DM_RETURN_RET_SHIFT                      (0U)
/*! RET - Return Value */
#define DM_RETURN_RET(x)                         (((uint32_t)(((uint32_t)(x)) << DM_RETURN_RET_SHIFT)) & DM_RETURN_RET_MASK)
/*! @} */

/*! @name ID - Identification */
/*! @{ */

#define DM_ID_ID_MASK                            (0xFFFFFFFFU)
#define DM_ID_ID_SHIFT                           (0U)
/*! ID - Identification Value */
#define DM_ID_ID(x)                              (((uint32_t)(((uint32_t)(x)) << DM_ID_ID_SHIFT)) & DM_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DM_Register_Masks */


/*!
 * @}
 */ /* end of group DM_Peripheral_Access_Layer */


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


#endif  /* DM_H_ */

