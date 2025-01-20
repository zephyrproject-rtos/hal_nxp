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
**         CMSIS Peripheral Access Layer for VPU_BLK_CTRL_VPUMIX
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
 * @file VPU_BLK_CTRL_VPUMIX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for VPU_BLK_CTRL_VPUMIX
 *
 * CMSIS Peripheral Access Layer for VPU_BLK_CTRL_VPUMIX
 */

#if !defined(VPU_BLK_CTRL_VPUMIX_H_)
#define VPU_BLK_CTRL_VPUMIX_H_                   /**< Symbol preventing repeated inclusion */

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
   -- VPU_BLK_CTRL_VPUMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_BLK_CTRL_VPUMIX_Peripheral_Access_Layer VPU_BLK_CTRL_VPUMIX Peripheral Access Layer
 * @{
 */

/** VPU_BLK_CTRL_VPUMIX - Register Layout Typedef */
typedef struct {
  __I  uint32_t VPU_STATUS;                        /**< VPU Status Register, offset: 0x0 */
  __I  uint32_t INIT_PENDING_TX;                   /**< Initiator Pending Transaction Register, offset: 0x4 */
  __IO uint32_t CLOCK_GATING_CONTROL;              /**< Clock Gating Control Register, offset: 0x8 */
} VPU_BLK_CTRL_VPUMIX_Type;

/* ----------------------------------------------------------------------------
   -- VPU_BLK_CTRL_VPUMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_BLK_CTRL_VPUMIX_Register_Masks VPU_BLK_CTRL_VPUMIX Register Masks
 * @{
 */

/*! @name VPU_STATUS - VPU Status Register */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_VPU_IDLE_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_VPU_IDLE_SHIFT (0U)
/*! VPU_IDLE - VPU idle status
 *  0b1..VPU is idle
 *  0b0..VPU is not idle
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_VPU_IDLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_STATUS_VPU_IDLE_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_STATUS_VPU_IDLE_MASK)
/*! @} */

/*! @name INIT_PENDING_TX - Initiator Pending Transaction Register */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Primary_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Primary_SHIFT (0U)
/*! VPU_Primary - Status information from initiator NIU NoC that indicates if there are pending
 *    transaction in the NoC for VPU Primary NIUs
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Primary(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Primary_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Primary_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Secondary_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Secondary_SHIFT (1U)
/*! VPU_Secondary - Status information from initiator NIU NoC that indicates if there are pending
 *    transaction in the NoC for VPU Secondary NIUs
 *  0b1..Pending transaction
 *  0b0..No pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Secondary(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Secondary_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_VPU_Secondary_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_MASK (0x4U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_SHIFT (2U)
/*! JPEG_Encode - Status information from initiator NIU NoC that indicates if there are pending
 *    transaction in the NoC for JPEG Encode NIUs
 *  0b1..Pending transaction
 *  0b0..No pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_MASK (0x8U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_SHIFT (3U)
/*! JPEG_Decode - Status information from initiator NIU NoC that indicates if there are pending
 *    transaction in the NoC for JPEG Decode NIUs
 *  0b1..Pending transaction
 *  0b0..No pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_MASK)
/*! @} */

/*! @name CLOCK_GATING_CONTROL - Clock Gating Control Register */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_Wave_VPU_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_Wave_VPU_SHIFT (0U)
/*! Wave_VPU - Gate the VPU clock (VPU_CLK_ROOT) and its associated network interface units
 *  0b1..Clock is disabled (gated)
 *  0b0..Clock is enabled
 */
#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_Wave_VPU(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_Wave_VPU_SHIFT)) & VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_Wave_VPU_MASK)

#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_ENC_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_ENC_SHIFT (1U)
/*! JPEG_ENC - Gate the JPEG ENC clock (VPU_JPEG_CLK_ROOT) and its associated network interface unit
 *  0b1..Clock is disabled (gated)
 *  0b0..Clock is enabled
 */
#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_ENC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_ENC_SHIFT)) & VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_ENC_MASK)

#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_DEC_MASK (0x4U)
#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_DEC_SHIFT (2U)
/*! JPEG_DEC - Gate the JPEG DEC clock (VPU_JPEG_CLK_ROOT) and its associated network interface unit
 *  0b0..Clock is enabled
 *  0b1..Clock is disabled (gated)
 */
#define VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_DEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_DEC_SHIFT)) & VPU_BLK_CTRL_VPUMIX_CLOCK_GATING_CONTROL_JPEG_DEC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_BLK_CTRL_VPUMIX_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_BLK_CTRL_VPUMIX_Peripheral_Access_Layer */


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


#endif  /* VPU_BLK_CTRL_VPUMIX_H_ */

