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
**     Build:               b250106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_CRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
 * @file AON_CRC.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_CRC
 *
 * CMSIS Peripheral Access Layer for AON_CRC
 */

#if !defined(AON_CRC_H_)
#define AON_CRC_H_                               /**< Symbol preventing repeated inclusion */

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
   -- AON_CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_CRC_Peripheral_Access_Layer AON_CRC Peripheral Access Layer
 * @{
 */

/** AON_CRC - Size of Registers Arrays */
#define AON_CRC_CHANNEL_COUNT                     3u

/** AON_CRC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t CFG;                               /**< Configuration Register, array offset: 0x0, array step: 0x10 */
    __IO uint32_t INP;                               /**< Input Register, array offset: 0x4, array step: 0x10 */
    __IO uint32_t CSTAT;                             /**< Current Status Register, array offset: 0x8, array step: 0x10 */
    __I  uint32_t OUTP;                              /**< Output Register, array offset: 0xC, array step: 0x10 */
  } CHANNEL[AON_CRC_CHANNEL_COUNT];
} AON_CRC_Type;

/* ----------------------------------------------------------------------------
   -- AON_CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_CRC_Register_Masks AON_CRC Register Masks
 * @{
 */

/*! @name CFG - Configuration Register */
/*! @{ */

#define AON_CRC_CFG_INV_MASK                     (0x1U)
#define AON_CRC_CFG_INV_SHIFT                    (0U)
/*! INV - Inversion selection
 *  0b0..No inversion selection applied on the CRC_OUTP content
 *  0b1..Inversion selection (bit x bit) applied on the CRC_OUTP content
 */
#define AON_CRC_CFG_INV(x)                       (((uint32_t)(((uint32_t)(x)) << AON_CRC_CFG_INV_SHIFT)) & AON_CRC_CFG_INV_MASK)

#define AON_CRC_CFG_SWAP_MASK                    (0x2U)
#define AON_CRC_CFG_SWAP_SHIFT                   (1U)
/*! SWAP - Swap selection
 *  0b0..No swap selection applied on the CRC_OUTP content
 *  0b1..Swap selection (MSB to LSB, LSB to MSB) applied to the CRC_OUTP content
 */
#define AON_CRC_CFG_SWAP(x)                      (((uint32_t)(((uint32_t)(x)) << AON_CRC_CFG_SWAP_SHIFT)) & AON_CRC_CFG_SWAP_MASK)

#define AON_CRC_CFG_POLYG_MASK                   (0xCU)
#define AON_CRC_CFG_POLYG_SHIFT                  (2U)
/*! POLYG - Polynomial selection
 *  0b00..CRC-CCITT polynomial
 *  0b01..CRC-32 polynomial
 *  0b10..CRC-8 polynomial
 *  0b11..CRC-8-H2F AUTOSAR polynomial
 */
#define AON_CRC_CFG_POLYG(x)                     (((uint32_t)(((uint32_t)(x)) << AON_CRC_CFG_POLYG_SHIFT)) & AON_CRC_CFG_POLYG_MASK)

#define AON_CRC_CFG_SWAP_BITWISE_MASK            (0x10U)
#define AON_CRC_CFG_SWAP_BITWISE_SHIFT           (4U)
/*! SWAP_BITWISE - Swap CRC_INP bit-wise
 *  0b0..Do not swap
 *  0b1..Perform bit-wise swap on CRC_INP input data internally for CRC-8 and CRC-16 and CRC-32 polynomial calculations
 */
#define AON_CRC_CFG_SWAP_BITWISE(x)              (((uint32_t)(((uint32_t)(x)) << AON_CRC_CFG_SWAP_BITWISE_SHIFT)) & AON_CRC_CFG_SWAP_BITWISE_MASK)

#define AON_CRC_CFG_SWAP_BYTEWISE_MASK           (0x20U)
#define AON_CRC_CFG_SWAP_BYTEWISE_SHIFT          (5U)
/*! SWAP_BYTEWISE - Swap CRC_INP byte-wise
 *  0b0..Do not swap
 *  0b1..Perform byte-wise swap on CRC_INP input data internally for CRC-16 and CRC-32 polynomial calculations
 */
#define AON_CRC_CFG_SWAP_BYTEWISE(x)             (((uint32_t)(((uint32_t)(x)) << AON_CRC_CFG_SWAP_BYTEWISE_SHIFT)) & AON_CRC_CFG_SWAP_BYTEWISE_MASK)
/*! @} */

/* The count of AON_CRC_CFG */
#define AON_CRC_CFG_COUNT                        (3U)

/*! @name INP - Input Register */
/*! @{ */

#define AON_CRC_INP_INP_MASK                     (0xFFFFFFFFU)
#define AON_CRC_INP_INP_SHIFT                    (0U)
/*! INP - Input data for the CRC computation */
#define AON_CRC_INP_INP(x)                       (((uint32_t)(((uint32_t)(x)) << AON_CRC_INP_INP_SHIFT)) & AON_CRC_INP_INP_MASK)
/*! @} */

/* The count of AON_CRC_INP */
#define AON_CRC_INP_COUNT                        (3U)

/*! @name CSTAT - Current Status Register */
/*! @{ */

#define AON_CRC_CSTAT_CSTAT_MASK                 (0xFFFFFFFFU)
#define AON_CRC_CSTAT_CSTAT_SHIFT                (0U)
/*! CSTAT - CRC signature status */
#define AON_CRC_CSTAT_CSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << AON_CRC_CSTAT_CSTAT_SHIFT)) & AON_CRC_CSTAT_CSTAT_MASK)
/*! @} */

/* The count of AON_CRC_CSTAT */
#define AON_CRC_CSTAT_COUNT                      (3U)

/*! @name OUTP - Output Register */
/*! @{ */

#define AON_CRC_OUTP_OUTP_MASK                   (0xFFFFFFFFU)
#define AON_CRC_OUTP_OUTP_SHIFT                  (0U)
/*! OUTP - Final CRC signature */
#define AON_CRC_OUTP_OUTP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_CRC_OUTP_OUTP_SHIFT)) & AON_CRC_OUTP_OUTP_MASK)
/*! @} */

/* The count of AON_CRC_OUTP */
#define AON_CRC_OUTP_COUNT                       (3U)


/*!
 * @}
 */ /* end of group AON_CRC_Register_Masks */


/*!
 * @}
 */ /* end of group AON_CRC_Peripheral_Access_Layer */


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


#endif  /* AON_CRC_H_ */

