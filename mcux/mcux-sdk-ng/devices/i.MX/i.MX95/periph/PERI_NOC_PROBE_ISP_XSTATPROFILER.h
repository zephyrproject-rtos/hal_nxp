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
**         CMSIS Peripheral Access Layer for NOC_PROBE_ISP_XSTATPROFILER
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
 * @file NOC_PROBE_ISP_XSTATPROFILER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NOC_PROBE_ISP_XSTATPROFILER
 *
 * CMSIS Peripheral Access Layer for NOC_PROBE_ISP_XSTATPROFILER
 */

#if !defined(NOC_PROBE_ISP_XSTATPROFILER_H_)
#define NOC_PROBE_ISP_XSTATPROFILER_H_           /**< Symbol preventing repeated inclusion */

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
   -- NOC_PROBE_ISP_XSTATPROFILER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_PROBE_ISP_XSTATPROFILER_Peripheral_Access_Layer NOC_PROBE_ISP_XSTATPROFILER Peripheral Access Layer
 * @{
 */

/** NOC_PROBE_ISP_XSTATPROFILER - Size of Registers Arrays */
#define NOC_PROBE_ISP_XSTATPROFILER_OBSERVEDSEL_COUNT 4u
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_COUNT 3u
#define NOC_PROBE_ISP_XSTATPROFILER_THRESHOLDS_COUNT 4u
#define NOC_PROBE_ISP_XSTATPROFILER_THRESHOLDS_TRANSACTIONSTATPROFILER_THRESHOLDS_J_COUNT 4u

/** NOC_PROBE_ISP_XSTATPROFILER - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID_COREID;                         /**< Core ID, offset: 0x0 */
  __I  uint32_t ID_REVISIONID;                     /**< Revision ID, offset: 0x4 */
  __IO uint32_t EN;                                /**< Enable, offset: 0x8 */
  __IO uint32_t MODE;                              /**< Mode, offset: 0xC */
  __IO uint32_t TRANSACTIONSTATPROFILER_OBSERVEDSEL[NOC_PROBE_ISP_XSTATPROFILER_OBSERVEDSEL_COUNT]; /**< ObservedSel n, array offset: 0x10, array step: 0x4 */
  __IO uint32_t NTENURELINES[NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_COUNT]; /**< NTENURELINES n, array offset: 0x20, array step: 0x4 */
  __IO uint32_t TRANSACTIONSTATPROFILER_THRESHOLDS_[NOC_PROBE_ISP_XSTATPROFILER_THRESHOLDS_COUNT][NOC_PROBE_ISP_XSTATPROFILER_THRESHOLDS_TRANSACTIONSTATPROFILER_THRESHOLDS_J_COUNT]; /**< Transaction Profiler Thresholds, array offset: 0x2C, array step: index*0x10, index2*0x4 */
  __I  uint32_t OVERFLOWSTATUS;                    /**< Overflow Status, offset: 0x6C */
  __O  uint32_t OVERFLOWRESET;                     /**< Overflow Reset, offset: 0x70 */
  __IO uint32_t PENDINGEVENTMODE;                  /**< Pending Event Mode, offset: 0x74 */
  __IO uint32_t PRESCALER;                         /**< Pre Scaler, offset: 0x78 */
} NOC_PROBE_ISP_XSTATPROFILER_Type;

/* ----------------------------------------------------------------------------
   -- NOC_PROBE_ISP_XSTATPROFILER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_PROBE_ISP_XSTATPROFILER_Register_Masks NOC_PROBE_ISP_XSTATPROFILER Register Masks
 * @{
 */

/*! @name ID_COREID - Core ID */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORETYPEID_MASK (0xFFU)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORETYPEID_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORETYPEID(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORETYPEID_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORETYPEID_MASK)

#define NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORECHECKSUM_MASK (0xFFFFFF00U)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORECHECKSUM_SHIFT (8U)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORECHECKSUM(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORECHECKSUM_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_ID_COREID_CORECHECKSUM_MASK)
/*! @} */

/*! @name ID_REVISIONID - Revision ID */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_USERID_MASK (0xFFU)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_USERID_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_USERID(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_USERID_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_USERID_MASK)

#define NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_NOCID_MASK (0xFFFFFF00U)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_NOCID_SHIFT (8U)
#define NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_NOCID(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_NOCID_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_ID_REVISIONID_NOCID_MASK)
/*! @} */

/*! @name EN - Enable */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_EN_EN_MASK   (0x1U)
#define NOC_PROBE_ISP_XSTATPROFILER_EN_EN_SHIFT  (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_EN_EN(x)     (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_EN_EN_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_EN_EN_MASK)
/*! @} */

/*! @name MODE - Mode */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_MODE_MODE_MASK (0xFU)
#define NOC_PROBE_ISP_XSTATPROFILER_MODE_MODE_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_MODE_MODE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_MODE_MODE_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_MODE_MODE_MASK)
/*! @} */

/*! @name TRANSACTIONSTATPROFILER_OBSERVEDSEL - ObservedSel n */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL_OBSERVEDSEL_MASK (0x3U)
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL_OBSERVEDSEL_SHIFT (0U)
/*! OBSERVEDSEL - ObservedSel n */
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL_OBSERVEDSEL(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL_OBSERVEDSEL_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL_OBSERVEDSEL_MASK)
/*! @} */

/* The count of NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL */
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_OBSERVEDSEL_COUNT (4U)

/*! @name NTENURELINES - NTENURELINES n */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_0_MASK (0xFU)
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_0_SHIFT (0U)
/*! NTenurelines_0 - Ntenurelines n */
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_0(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_0_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_0_MASK)

#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_1_MASK (0xFU)
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_1_SHIFT (0U)
/*! NTenurelines_1 - Ntenurelines n */
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_1(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_1_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_1_MASK)

#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_2_MASK (0xFU)
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_2_SHIFT (0U)
/*! NTenurelines_2 - Ntenurelines n */
#define NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_2(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_2_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_NTENURELINES_NTenurelines_2_MASK)
/*! @} */

/*! @name TRANSACTIONSTATPROFILER_THRESHOLDS_ - Transaction Profiler Thresholds */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__THRESHOLDS_MASK (0x7FFU)
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__THRESHOLDS_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__THRESHOLDS(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__THRESHOLDS_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__THRESHOLDS_MASK)
/*! @} */

/* The count of NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS_ */
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__COUNT (4U)

/* The count of NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS_ */
#define NOC_PROBE_ISP_XSTATPROFILER_TRANSACTIONSTATPROFILER_THRESHOLDS__COUNT2 (4U)

/*! @name OVERFLOWSTATUS - Overflow Status */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWSTATUS_OVERFLOWSTATUS_MASK (0xFU)
#define NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWSTATUS_OVERFLOWSTATUS_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWSTATUS_OVERFLOWSTATUS(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWSTATUS_OVERFLOWSTATUS_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWSTATUS_OVERFLOWSTATUS_MASK)
/*! @} */

/*! @name OVERFLOWRESET - Overflow Reset */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWRESET_OVERFLOWRESET_MASK (0xFU)
#define NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWRESET_OVERFLOWRESET_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWRESET_OVERFLOWRESET(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWRESET_OVERFLOWRESET_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_OVERFLOWRESET_OVERFLOWRESET_MASK)
/*! @} */

/*! @name PENDINGEVENTMODE - Pending Event Mode */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_PENDINGEVENTMODE_PENDINGEVENTMODE_MASK (0x1U)
#define NOC_PROBE_ISP_XSTATPROFILER_PENDINGEVENTMODE_PENDINGEVENTMODE_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_PENDINGEVENTMODE_PENDINGEVENTMODE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_PENDINGEVENTMODE_PENDINGEVENTMODE_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_PENDINGEVENTMODE_PENDINGEVENTMODE_MASK)
/*! @} */

/*! @name PRESCALER - Pre Scaler */
/*! @{ */

#define NOC_PROBE_ISP_XSTATPROFILER_PRESCALER_PRESCALER_MASK (0xFFU)
#define NOC_PROBE_ISP_XSTATPROFILER_PRESCALER_PRESCALER_SHIFT (0U)
#define NOC_PROBE_ISP_XSTATPROFILER_PRESCALER_PRESCALER(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_ISP_XSTATPROFILER_PRESCALER_PRESCALER_SHIFT)) & NOC_PROBE_ISP_XSTATPROFILER_PRESCALER_PRESCALER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NOC_PROBE_ISP_XSTATPROFILER_Register_Masks */


/*!
 * @}
 */ /* end of group NOC_PROBE_ISP_XSTATPROFILER_Peripheral_Access_Layer */


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


#endif  /* NOC_PROBE_ISP_XSTATPROFILER_H_ */

