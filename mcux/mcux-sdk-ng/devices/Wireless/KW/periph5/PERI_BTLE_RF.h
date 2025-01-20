/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BTLE_RF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file BTLE_RF.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for BTLE_RF
 *
 * CMSIS Peripheral Access Layer for BTLE_RF
 */

#if !defined(BTLE_RF_H_)
#define BTLE_RF_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- BTLE_RF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTLE_RF_Peripheral_Access_Layer BTLE_RF Peripheral Access Layer
 * @{
 */

/** BTLE_RF - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[1536];
  __I  uint16_t BLE_PART_ID;                       /**< BLUETOOTH LOW ENERGY PART ID, offset: 0x600 */
       uint8_t RESERVED_1[2];
  __I  uint16_t DSM_STATUS;                        /**< BLE DSM STATUS, offset: 0x604 */
       uint8_t RESERVED_2[2];
  __IO uint16_t MISC_CTRL;                         /**< BLUETOOTH LOW ENERGY MISCELLANEOUS CONTROL, offset: 0x608 */
} BTLE_RF_Type;

/* ----------------------------------------------------------------------------
   -- BTLE_RF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BTLE_RF_Register_Masks BTLE_RF Register Masks
 * @{
 */

/*! @name BLE_PART_ID - BLUETOOTH LOW ENERGY PART ID */
/*! @{ */

#define BTLE_RF_BLE_PART_ID_BLE_PART_ID_MASK     (0xFFFFU)
#define BTLE_RF_BLE_PART_ID_BLE_PART_ID_SHIFT    (0U)
/*! BLE_PART_ID - BLE Part ID
 *  0b0000000000000000..Pre-production
 *  0b0000000000000001..Pre-production
 *  0b0000000000000010..KW40Z
 *  0b0000000000000011..KW41Z
 */
#define BTLE_RF_BLE_PART_ID_BLE_PART_ID(x)       (((uint16_t)(((uint16_t)(x)) << BTLE_RF_BLE_PART_ID_BLE_PART_ID_SHIFT)) & BTLE_RF_BLE_PART_ID_BLE_PART_ID_MASK)
/*! @} */

/*! @name DSM_STATUS - BLE DSM STATUS */
/*! @{ */

#define BTLE_RF_DSM_STATUS_ORF_SYSCLK_REQ_MASK   (0x1U)
#define BTLE_RF_DSM_STATUS_ORF_SYSCLK_REQ_SHIFT  (0U)
/*! ORF_SYSCLK_REQ - RF Oscillator Requested */
#define BTLE_RF_DSM_STATUS_ORF_SYSCLK_REQ(x)     (((uint16_t)(((uint16_t)(x)) << BTLE_RF_DSM_STATUS_ORF_SYSCLK_REQ_SHIFT)) & BTLE_RF_DSM_STATUS_ORF_SYSCLK_REQ_MASK)

#define BTLE_RF_DSM_STATUS_RIF_LL_ACTIVE_MASK    (0x2U)
#define BTLE_RF_DSM_STATUS_RIF_LL_ACTIVE_SHIFT   (1U)
/*! RIF_LL_ACTIVE - Link Layer Active */
#define BTLE_RF_DSM_STATUS_RIF_LL_ACTIVE(x)      (((uint16_t)(((uint16_t)(x)) << BTLE_RF_DSM_STATUS_RIF_LL_ACTIVE_SHIFT)) & BTLE_RF_DSM_STATUS_RIF_LL_ACTIVE_MASK)

#define BTLE_RF_DSM_STATUS_XCVR_BUSY_MASK        (0x4U)
#define BTLE_RF_DSM_STATUS_XCVR_BUSY_SHIFT       (2U)
/*! XCVR_BUSY - Transceiver Busy Status Bit
 *  0b0..RF Channel in available (TSM is idle)
 *  0b1..RF Channel in use (TSM is busy)
 */
#define BTLE_RF_DSM_STATUS_XCVR_BUSY(x)          (((uint16_t)(((uint16_t)(x)) << BTLE_RF_DSM_STATUS_XCVR_BUSY_SHIFT)) & BTLE_RF_DSM_STATUS_XCVR_BUSY_MASK)
/*! @} */

/*! @name MISC_CTRL - BLUETOOTH LOW ENERGY MISCELLANEOUS CONTROL */
/*! @{ */

#define BTLE_RF_MISC_CTRL_TSM_INTR_EN_MASK       (0x2U)
#define BTLE_RF_MISC_CTRL_TSM_INTR_EN_SHIFT      (1U)
/*! TSM_INTR_EN - TSM Interrupt Enable
 *  0b0..a TSM Interrupt during a BLE TX or RX sequence will not set bit [8] of BLE EVENT_STATUS
 *  0b1..a TSM Interrupt during a BLE TX or RX sequence will set bit [8] of BLE EVENT_STATUS
 */
#define BTLE_RF_MISC_CTRL_TSM_INTR_EN(x)         (((uint16_t)(((uint16_t)(x)) << BTLE_RF_MISC_CTRL_TSM_INTR_EN_SHIFT)) & BTLE_RF_MISC_CTRL_TSM_INTR_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BTLE_RF_Register_Masks */


/*!
 * @}
 */ /* end of group BTLE_RF_Peripheral_Access_Layer */


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


#endif  /* BTLE_RF_H_ */

