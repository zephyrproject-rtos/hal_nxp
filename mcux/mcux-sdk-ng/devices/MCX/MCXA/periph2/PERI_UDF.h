/*
** ###################################################################
**     Processors:          MCXA165VLH
**                          MCXA165VLL
**                          MCXA165VLQ
**                          MCXA165VPN
**                          MCXA166VLH
**                          MCXA166VLL
**                          MCXA166VLQ
**                          MCXA166VPN
**                          MCXA175VLH
**                          MCXA175VLL
**                          MCXA175VLQ
**                          MCXA175VPN
**                          MCXA176VLH
**                          MCXA176VLL
**                          MCXA176VLQ
**                          MCXA176VPN
**                          MCXA275VLH
**                          MCXA275VLL
**                          MCXA275VLQ
**                          MCXA275VPN
**                          MCXA276VLH
**                          MCXA276VLL
**                          MCXA276VLQ
**                          MCXA276VPN
**
**     Version:             rev. 1.0, 2024-03-26
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UDF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**
** ###################################################################
*/

/*!
 * @file UDF.h
 * @version 1.0
 * @date 2024-03-26
 * @brief CMSIS Peripheral Access Layer for UDF
 *
 * CMSIS Peripheral Access Layer for UDF
 */

#if !defined(UDF_H_)
#define UDF_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA165VLH) || defined(CPU_MCXA165VLL) || defined(CPU_MCXA165VLQ) || defined(CPU_MCXA165VPN))
#include "MCXA165_COMMON.h"
#elif (defined(CPU_MCXA166VLH) || defined(CPU_MCXA166VLL) || defined(CPU_MCXA166VLQ) || defined(CPU_MCXA166VPN))
#include "MCXA166_COMMON.h"
#elif (defined(CPU_MCXA175VLH) || defined(CPU_MCXA175VLL) || defined(CPU_MCXA175VLQ) || defined(CPU_MCXA175VPN))
#include "MCXA175_COMMON.h"
#elif (defined(CPU_MCXA176VLH) || defined(CPU_MCXA176VLL) || defined(CPU_MCXA176VLQ) || defined(CPU_MCXA176VPN))
#include "MCXA176_COMMON.h"
#elif (defined(CPU_MCXA275VLH) || defined(CPU_MCXA275VLL) || defined(CPU_MCXA275VLQ) || defined(CPU_MCXA275VPN))
#include "MCXA275_COMMON.h"
#elif (defined(CPU_MCXA276VLH) || defined(CPU_MCXA276VLL) || defined(CPU_MCXA276VLQ) || defined(CPU_MCXA276VPN))
#include "MCXA276_COMMON.h"
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
   -- UDF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UDF_Peripheral_Access_Layer UDF Peripheral Access Layer
 * @{
 */

/** UDF - Register Layout Typedef */
typedef struct {
  __IO uint32_t UDF_CTRL;                          /**< Control register, offset: 0x0 */
  __I  uint32_t UDF_STATUS;                        /**< Status register, offset: 0x4 */
  __O  uint32_t UDF_WR_DATA;                       /**< Data In Register, offset: 0x8 */
  __I  uint32_t UDF_RD_DATA;                       /**< Data Out Register, offset: 0xC */
} UDF_Type;

/* ----------------------------------------------------------------------------
   -- UDF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UDF_Register_Masks UDF Register Masks
 * @{
 */

/*! @name UDF_CTRL - Control register */
/*! @{ */

#define UDF_UDF_CTRL_salt_MASK                   (0xFFFFU)
#define UDF_UDF_CTRL_salt_SHIFT                  (0U)
/*! salt - Bits are internally XORed with i_custom */
#define UDF_UDF_CTRL_salt(x)                     (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_salt_SHIFT)) & UDF_UDF_CTRL_salt_MASK)

#define UDF_UDF_CTRL_lock_MASK                   (0x70000U)
#define UDF_UDF_CTRL_lock_SHIFT                  (16U)
/*! lock - Lock access to UDF */
#define UDF_UDF_CTRL_lock(x)                     (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_lock_SHIFT)) & UDF_UDF_CTRL_lock_MASK)

#define UDF_UDF_CTRL_reserved21_MASK             (0x380000U)
#define UDF_UDF_CTRL_reserved21_SHIFT            (19U)
/*! reserved21 - RFU */
#define UDF_UDF_CTRL_reserved21(x)               (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_reserved21_SHIFT)) & UDF_UDF_CTRL_reserved21_MASK)

#define UDF_UDF_CTRL_udf_en_MASK                 (0x1C00000U)
#define UDF_UDF_CTRL_udf_en_SHIFT                (22U)
/*! udf_en - Enable the UDF block */
#define UDF_UDF_CTRL_udf_en(x)                   (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_udf_en_SHIFT)) & UDF_UDF_CTRL_udf_en_MASK)

#define UDF_UDF_CTRL_reserved25_MASK             (0x2000000U)
#define UDF_UDF_CTRL_reserved25_SHIFT            (25U)
/*! reserved25 - RFU */
#define UDF_UDF_CTRL_reserved25(x)               (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_reserved25_SHIFT)) & UDF_UDF_CTRL_reserved25_MASK)

#define UDF_UDF_CTRL_reserved27_MASK             (0xC000000U)
#define UDF_UDF_CTRL_reserved27_SHIFT            (26U)
/*! reserved27 - RFU */
#define UDF_UDF_CTRL_reserved27(x)               (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_reserved27_SHIFT)) & UDF_UDF_CTRL_reserved27_MASK)

#define UDF_UDF_CTRL_flush_MASK                  (0x70000000U)
#define UDF_UDF_CTRL_flush_SHIFT                 (28U)
/*! flush - Flush UDF and return to reset state */
#define UDF_UDF_CTRL_flush(x)                    (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_flush_SHIFT)) & UDF_UDF_CTRL_flush_MASK)

#define UDF_UDF_CTRL_reserved31_MASK             (0x80000000U)
#define UDF_UDF_CTRL_reserved31_SHIFT            (31U)
/*! reserved31 - reserved */
#define UDF_UDF_CTRL_reserved31(x)               (((uint32_t)(((uint32_t)(x)) << UDF_UDF_CTRL_reserved31_SHIFT)) & UDF_UDF_CTRL_reserved31_MASK)
/*! @} */

/*! @name UDF_STATUS - Status register */
/*! @{ */

#define UDF_UDF_STATUS_o_status_MASK             (0x1FU)
#define UDF_UDF_STATUS_o_status_SHIFT            (0U)
/*! o_status - Status bits
 *  0b00001..5'b00001 = Reset
 *  0b00010..5'b00010 = Init
 *  0b00100..5'b00100 = Warmup
 *  0b01000..5'b01000 = Ready
 *  0b10000..5'b10000 = Error
 */
#define UDF_UDF_STATUS_o_status(x)               (((uint32_t)(((uint32_t)(x)) << UDF_UDF_STATUS_o_status_SHIFT)) & UDF_UDF_STATUS_o_status_MASK)

#define UDF_UDF_STATUS_rsv_MASK                  (0x7FFFFFE0U)
#define UDF_UDF_STATUS_rsv_SHIFT                 (5U)
/*! rsv - RFU */
#define UDF_UDF_STATUS_rsv(x)                    (((uint32_t)(((uint32_t)(x)) << UDF_UDF_STATUS_rsv_SHIFT)) & UDF_UDF_STATUS_rsv_MASK)

#define UDF_UDF_STATUS_o_wait_MASK               (0x80000000U)
#define UDF_UDF_STATUS_o_wait_SHIFT              (31U)
/*! o_wait - Indicates UDF is processing data */
#define UDF_UDF_STATUS_o_wait(x)                 (((uint32_t)(((uint32_t)(x)) << UDF_UDF_STATUS_o_wait_SHIFT)) & UDF_UDF_STATUS_o_wait_MASK)
/*! @} */

/*! @name UDF_WR_DATA - Data In Register */
/*! @{ */

#define UDF_UDF_WR_DATA_i_dat_MASK               (0xFFFFFFFFU)
#define UDF_UDF_WR_DATA_i_dat_SHIFT              (0U)
#define UDF_UDF_WR_DATA_i_dat(x)                 (((uint32_t)(((uint32_t)(x)) << UDF_UDF_WR_DATA_i_dat_SHIFT)) & UDF_UDF_WR_DATA_i_dat_MASK)
/*! @} */

/*! @name UDF_RD_DATA - Data Out Register */
/*! @{ */

#define UDF_UDF_RD_DATA_o_dat_MASK               (0xFFFFFFFFU)
#define UDF_UDF_RD_DATA_o_dat_SHIFT              (0U)
#define UDF_UDF_RD_DATA_o_dat(x)                 (((uint32_t)(((uint32_t)(x)) << UDF_UDF_RD_DATA_o_dat_SHIFT)) & UDF_UDF_RD_DATA_o_dat_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UDF_Register_Masks */


/*!
 * @}
 */ /* end of group UDF_Peripheral_Access_Layer */


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


#endif  /* UDF_H_ */

