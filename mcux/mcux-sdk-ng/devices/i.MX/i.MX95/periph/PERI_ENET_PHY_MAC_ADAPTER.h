/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ENET_PHY_MAC_ADAPTER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ENET_PHY_MAC_ADAPTER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY_MAC_ADAPTER
 *
 * CMSIS Peripheral Access Layer for ENET_PHY_MAC_ADAPTER
 */

#if !defined(ENET_PHY_MAC_ADAPTER_H_)
#define ENET_PHY_MAC_ADAPTER_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- ENET_PHY_MAC_ADAPTER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_MAC_ADAPTER_Peripheral_Access_Layer ENET_PHY_MAC_ADAPTER Peripheral Access Layer
 * @{
 */

/** ENET_PHY_MAC_ADAPTER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint16_t MAC_ADAPTER_LOCK_PHY;              /**< PHY Lock, offset: 0x200 */
       uint8_t RESERVED_1[2];
  __IO uint16_t MAC_ADAPTER_LOCK_MPLLA;            /**< MPLLA Lock, offset: 0x204 */
       uint8_t RESERVED_2[2];
  __IO uint16_t MAC_ADAPTER_LOCK_MPLLB;            /**< MPLLB Lock, offset: 0x208 */
       uint8_t RESERVED_3[2];
  __IO uint16_t MAC_ADAPTER_LOCK_ROM;              /**< ROM Lock, offset: 0x20C */
       uint8_t RESERVED_4[2];
  __IO uint16_t MAC_ADAPTER_LOCK_RAM;              /**< RAM Lock, offset: 0x210 */
       uint8_t RESERVED_5[2];
  __IO uint16_t MAC_ADAPTER_ERROR_EVENT;           /**< Error Event for FIFO, offset: 0x214 */
} ENET_PHY_MAC_ADAPTER_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY_MAC_ADAPTER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_MAC_ADAPTER_Register_Masks ENET_PHY_MAC_ADAPTER Register Masks
 * @{
 */

/*! @name MAC_ADAPTER_LOCK_PHY - PHY Lock */
/*! @{ */

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_MASK (0xFU)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_SHIFT (0U)
/*! LOCK_OWNER - Lock Owner */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_OWNER_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_MASK (0x80U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_SHIFT (7U)
/*! LOCK - Lock Bit
 *  0b0..Unlocked
 *  0b1..Locked
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_LOCK_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_WHOAMI_MASK (0xF000U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_WHOAMI_SHIFT (12U)
/*! WHOAMI - Port ID */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_WHOAMI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_WHOAMI_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_PHY_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_MPLLA - MPLLA Lock */
/*! @{ */

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_MASK (0xFU)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_SHIFT (0U)
/*! LOCK_OWNER - Lock Owner */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_OWNER_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_MASK (0x80U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_SHIFT (7U)
/*! LOCK - Lock Bit
 *  0b0..Unlocked
 *  0b1..Locked
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_LOCK_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_MASK (0xF000U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_SHIFT (12U)
/*! WHOAMI - Port ID */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_WHOAMI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLA_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_MPLLB - MPLLB Lock */
/*! @{ */

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_MASK (0xFU)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_SHIFT (0U)
/*! LOCK_OWNER - Lock Owner */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_OWNER_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_MASK (0x80U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_SHIFT (7U)
/*! LOCK - Lock Bit
 *  0b0..Unlocked
 *  0b1..Locked
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_LOCK_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_MASK (0xF000U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_SHIFT (12U)
/*! WHOAMI - Port ID */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_WHOAMI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_MPLLB_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_ROM - ROM Lock */
/*! @{ */

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_OWNER_MASK (0xFU)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_OWNER_SHIFT (0U)
/*! LOCK_OWNER - Lock Owner */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_OWNER_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_OWNER_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_MASK (0x80U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_SHIFT (7U)
/*! LOCK - Lock Bit
 *  0b0..Unlocked
 *  0b1..Locked
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_LOCK_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_WHOAMI_MASK (0xF000U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_WHOAMI_SHIFT (12U)
/*! WHOAMI - Port ID */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_WHOAMI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_WHOAMI_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_ROM_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_LOCK_RAM - RAM Lock */
/*! @{ */

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_MASK (0xFU)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_SHIFT (0U)
/*! LOCK_OWNER - Lock Owner */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_OWNER_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_MASK (0x80U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_SHIFT (7U)
/*! LOCK - Lock Bit
 *  0b0..Unlocked
 *  0b1..Locked
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_LOCK_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_WHOAMI_MASK (0xF000U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_WHOAMI_SHIFT (12U)
/*! WHOAMI - Port ID */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_WHOAMI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_WHOAMI_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_LOCK_RAM_WHOAMI_MASK)
/*! @} */

/*! @name MAC_ADAPTER_ERROR_EVENT - Error Event for FIFO */
/*! @{ */

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_RX_FIFO_OVF_MASK (0x1U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_RX_FIFO_OVF_SHIFT (0U)
/*! SGMII_RX_FIFO_OVF - FIFO Overflow for SGMII RX Path
 *  0b0..No event
 *  0b1..Overflow detected
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_RX_FIFO_OVF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_RX_FIFO_OVF_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_RX_FIFO_OVF_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_TX_FIFO_UDF_MASK (0x10U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_TX_FIFO_UDF_SHIFT (4U)
/*! SGMII_TX_FIFO_UDF - FIFO Underflow for SGMII TX Path
 *  0b0..No event
 *  0b1..Underflow detected
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_TX_FIFO_UDF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_TX_FIFO_UDF_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_SGMII_TX_FIFO_UDF_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_RX_FIFO_OVF_MASK (0x100U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_RX_FIFO_OVF_SHIFT (8U)
/*! XGMII_RX_FIFO_OVF - FIFO Overflow for XGMII RX Path
 *  0b0..No event
 *  0b1..Overflow detected
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_RX_FIFO_OVF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_RX_FIFO_OVF_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_RX_FIFO_OVF_MASK)

#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_TX_FIFO_UDF_MASK (0x1000U)
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_TX_FIFO_UDF_SHIFT (12U)
/*! XGMII_TX_FIFO_UDF - FIFO Underflow for XGMII TX Path
 *  0b0..No event
 *  0b1..Underflow detected
 */
#define ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_TX_FIFO_UDF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_TX_FIFO_UDF_SHIFT)) & ENET_PHY_MAC_ADAPTER_MAC_ADAPTER_ERROR_EVENT_XGMII_TX_FIFO_UDF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENET_PHY_MAC_ADAPTER_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_PHY_MAC_ADAPTER_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_MAC_ADAPTER_H_ */

