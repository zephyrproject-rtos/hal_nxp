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
**         CMSIS Peripheral Access Layer for AON_CSTCU
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
 * @file AON_CSTCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_CSTCU
 *
 * CMSIS Peripheral Access Layer for AON_CSTCU
 */

#if !defined(AON_CSTCU_H_)
#define AON_CSTCU_H_                             /**< Symbol preventing repeated inclusion */

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
   -- AON_CSTCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_CSTCU_Peripheral_Access_Layer AON_CSTCU Peripheral Access Layer
 * @{
 */

/** AON_CSTCU - Size of Registers Arrays */
#define AON_CSTCU_LRFSTAT_COUNT                   1u
#define AON_CSTCU_LUFSTAT_COUNT                   1u
#define AON_CSTCU_BYPLSTCU_COUNT                  1u
#define AON_CSTCU_LSTCU_MBSCH_COUNT               5u

/** AON_CSTCU - Register Layout Typedef */
typedef struct {
  __IO uint32_t RUNSWREG;                          /**< Run Software, offset: 0x0 */
  __IO uint32_t LSCHLVLD;                          /**< LSTCU Scheduler List Valid, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t IE;                                /**< Interrupt Enable, offset: 0x10 */
  __IO uint32_t IF;                                /**< Interrupt Flag, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t ERR_STAT;                          /**< Error Status, offset: 0x20 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ERR_FM;                            /**< Error Fault Mapping, offset: 0x28 */
       uint8_t RESERVED_3[4];
  __I  uint32_t LRFSTAT[AON_CSTCU_LRFSTAT_COUNT];  /**< LSTCU Recoverable Fault Status, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_4[12];
  __I  uint32_t LUFSTAT[AON_CSTCU_LUFSTAT_COUNT];  /**< LSTCU Unrecoverable Fault Status, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_5[12];
  __IO uint32_t RDEN;                              /**< Reset Domain Self-Test Enable, offset: 0x50 */
  __I  uint32_t RDENSTAT;                          /**< Reset Domain Enable Status, offset: 0x54 */
  __I  uint32_t LASTRDEN;                          /**< Last Run Reset Domain Enable, offset: 0x58 */
       uint8_t RESERVED_6[4];
  __IO uint32_t BYPLSTCU[AON_CSTCU_BYPLSTCU_COUNT]; /**< Bypass LSTCU, array offset: 0x60, array step: 0x4 */
       uint8_t RESERVED_7[12];
  __IO uint32_t STAG;                              /**< Stagger, offset: 0x70 */
       uint8_t RESERVED_8[396];
  __IO uint32_t LMBPTR[AON_CSTCU_LSTCU_MBSCH_COUNT]; /**< LSTCU MBIST Run Phase Scheduler Pointer, array offset: 0x200, array step: 0x4 */
} AON_CSTCU_Type;

/* ----------------------------------------------------------------------------
   -- AON_CSTCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_CSTCU_Register_Masks AON_CSTCU Register Masks
 * @{
 */

/*! @name RUNSWREG - Run Software */
/*! @{ */

#define AON_CSTCU_RUNSWREG_RUNSW_MASK            (0x1U)
#define AON_CSTCU_RUNSWREG_RUNSW_SHIFT           (0U)
/*! RUNSW - Run Software
 *  0b0..No self-test run in progress
 *  0b0..No effect
 *  0b1..Self-test in progress
 *  0b1..Starts self-test
 */
#define AON_CSTCU_RUNSWREG_RUNSW(x)              (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RUNSWREG_RUNSW_SHIFT)) & AON_CSTCU_RUNSWREG_RUNSW_MASK)

#define AON_CSTCU_RUNSWREG_SW_ABORT_MASK         (0x10U)
#define AON_CSTCU_RUNSWREG_SW_ABORT_SHIFT        (4U)
/*! SW_ABORT - Software Abort
 *  0b0..No self-test abort request
 *  0b0..No effect
 *  0b1..Aborts self-test
 */
#define AON_CSTCU_RUNSWREG_SW_ABORT(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RUNSWREG_SW_ABORT_SHIFT)) & AON_CSTCU_RUNSWREG_SW_ABORT_MASK)
/*! @} */

/*! @name LSCHLVLD - LSTCU Scheduler List Valid */
/*! @{ */

#define AON_CSTCU_LSCHLVLD_MBPLVLD_MASK          (0x100U)
#define AON_CSTCU_LSCHLVLD_MBPLVLD_SHIFT         (8U)
/*! MBPLVLD - LSTCU MBIST Pointer List Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define AON_CSTCU_LSCHLVLD_MBPLVLD(x)            (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LSCHLVLD_MBPLVLD_SHIFT)) & AON_CSTCU_LSCHLVLD_MBPLVLD_MASK)
/*! @} */

/*! @name IE - Interrupt Enable */
/*! @{ */

#define AON_CSTCU_IE_STEND_IE_MASK               (0x1U)
#define AON_CSTCU_IE_STEND_IE_SHIFT              (0U)
/*! STEND_IE - Self-Test End Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_CSTCU_IE_STEND_IE(x)                 (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_IE_STEND_IE_SHIFT)) & AON_CSTCU_IE_STEND_IE_MASK)
/*! @} */

/*! @name IF - Interrupt Flag */
/*! @{ */

#define AON_CSTCU_IF_STEND_IF_MASK               (0x1U)
#define AON_CSTCU_IF_STEND_IF_SHIFT              (0U)
/*! STEND_IF - Self-Test End Interrupt Flag
 *  0b0..No pending interrupt
 *  0b0..No effect
 *  0b1..Pending interrupt
 *  0b1..Clear the flag
 */
#define AON_CSTCU_IF_STEND_IF(x)                 (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_IF_STEND_IF_SHIFT)) & AON_CSTCU_IF_STEND_IF_MASK)
/*! @} */

/*! @name ERR_STAT - Error Status */
/*! @{ */

#define AON_CSTCU_ERR_STAT_INVP_MB_MASK          (0x2U)
#define AON_CSTCU_ERR_STAT_INVP_MB_SHIFT         (1U)
/*! INVP_MB - Invalid LSTCU Pointer During MBIST Scheduling
 *  0b0..No invalid LSTCU pointer
 *  0b1..Invalid LSTCU pointer
 */
#define AON_CSTCU_ERR_STAT_INVP_MB(x)            (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_ERR_STAT_INVP_MB_SHIFT)) & AON_CSTCU_ERR_STAT_INVP_MB_MASK)

#define AON_CSTCU_ERR_STAT_ABORTSW_MASK          (0x200U)
#define AON_CSTCU_ERR_STAT_ABORTSW_SHIFT         (9U)
/*! ABORTSW - Software Abort Flag
 *  0b0..No abort detected
 *  0b1..Abort detected
 */
#define AON_CSTCU_ERR_STAT_ABORTSW(x)            (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_ERR_STAT_ABORTSW_SHIFT)) & AON_CSTCU_ERR_STAT_ABORTSW_MASK)

#define AON_CSTCU_ERR_STAT_UFSF_MASK             (0x10000U)
#define AON_CSTCU_ERR_STAT_UFSF_SHIFT            (16U)
/*! UFSF - Unrecoverable Fault Status Flag
 *  0b0..No unrecoverable fault occurred
 *  0b1..Unrecoverable fault occurred
 */
#define AON_CSTCU_ERR_STAT_UFSF(x)               (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_ERR_STAT_UFSF_SHIFT)) & AON_CSTCU_ERR_STAT_UFSF_MASK)

#define AON_CSTCU_ERR_STAT_RFSF_MASK             (0x20000U)
#define AON_CSTCU_ERR_STAT_RFSF_SHIFT            (17U)
/*! RFSF - Recoverable Fault Status Flag
 *  0b0..No recoverable fault occurred
 *  0b1..Recoverable fault occurred
 */
#define AON_CSTCU_ERR_STAT_RFSF(x)               (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_ERR_STAT_RFSF_SHIFT)) & AON_CSTCU_ERR_STAT_RFSF_MASK)
/*! @} */

/*! @name ERR_FM - Error Fault Mapping */
/*! @{ */

#define AON_CSTCU_ERR_FM_INVPFMMB_MASK           (0x2U)
#define AON_CSTCU_ERR_FM_INVPFMMB_SHIFT          (1U)
/*! INVPFMMB - MBIST Fault Mapping
 *  0b0..Recoverable fault
 *  0b1..Unrecoverable fault
 */
#define AON_CSTCU_ERR_FM_INVPFMMB(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_ERR_FM_INVPFMMB_SHIFT)) & AON_CSTCU_ERR_FM_INVPFMMB_MASK)
/*! @} */

/*! @name LRFSTAT - LSTCU Recoverable Fault Status */
/*! @{ */

#define AON_CSTCU_LRFSTAT_RFSLSTCU0_MASK         (0x1U)
#define AON_CSTCU_LRFSTAT_RFSLSTCU0_SHIFT        (0U)
/*! RFSLSTCU0 - Recoverable Fault Occurrence Status from LSTCU0
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LRFSTAT_RFSLSTCU0(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LRFSTAT_RFSLSTCU0_SHIFT)) & AON_CSTCU_LRFSTAT_RFSLSTCU0_MASK)

#define AON_CSTCU_LRFSTAT_RFSLSTCU1_MASK         (0x2U)
#define AON_CSTCU_LRFSTAT_RFSLSTCU1_SHIFT        (1U)
/*! RFSLSTCU1 - Recoverable Fault Occurrence Status from LSTCU1
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LRFSTAT_RFSLSTCU1(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LRFSTAT_RFSLSTCU1_SHIFT)) & AON_CSTCU_LRFSTAT_RFSLSTCU1_MASK)

#define AON_CSTCU_LRFSTAT_RFSLSTCU2_MASK         (0x4U)
#define AON_CSTCU_LRFSTAT_RFSLSTCU2_SHIFT        (2U)
/*! RFSLSTCU2 - Recoverable Fault Occurrence Status from LSTCU2
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LRFSTAT_RFSLSTCU2(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LRFSTAT_RFSLSTCU2_SHIFT)) & AON_CSTCU_LRFSTAT_RFSLSTCU2_MASK)

#define AON_CSTCU_LRFSTAT_RFSLSTCU3_MASK         (0x8U)
#define AON_CSTCU_LRFSTAT_RFSLSTCU3_SHIFT        (3U)
/*! RFSLSTCU3 - Recoverable Fault Occurrence Status from LSTCU3
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LRFSTAT_RFSLSTCU3(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LRFSTAT_RFSLSTCU3_SHIFT)) & AON_CSTCU_LRFSTAT_RFSLSTCU3_MASK)

#define AON_CSTCU_LRFSTAT_RFSLSTCU4_MASK         (0x10U)
#define AON_CSTCU_LRFSTAT_RFSLSTCU4_SHIFT        (4U)
/*! RFSLSTCU4 - Recoverable Fault Occurrence Status from LSTCU4
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LRFSTAT_RFSLSTCU4(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LRFSTAT_RFSLSTCU4_SHIFT)) & AON_CSTCU_LRFSTAT_RFSLSTCU4_MASK)
/*! @} */

/*! @name LUFSTAT - LSTCU Unrecoverable Fault Status */
/*! @{ */

#define AON_CSTCU_LUFSTAT_UFSLSTCU0_MASK         (0x1U)
#define AON_CSTCU_LUFSTAT_UFSLSTCU0_SHIFT        (0U)
/*! UFSLSTCU0 - Unrecoverable Fault Occurrence Status from LSTCU0
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LUFSTAT_UFSLSTCU0(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LUFSTAT_UFSLSTCU0_SHIFT)) & AON_CSTCU_LUFSTAT_UFSLSTCU0_MASK)

#define AON_CSTCU_LUFSTAT_UFSLSTCU1_MASK         (0x2U)
#define AON_CSTCU_LUFSTAT_UFSLSTCU1_SHIFT        (1U)
/*! UFSLSTCU1 - Unrecoverable Fault Occurrence Status from LSTCU1
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LUFSTAT_UFSLSTCU1(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LUFSTAT_UFSLSTCU1_SHIFT)) & AON_CSTCU_LUFSTAT_UFSLSTCU1_MASK)

#define AON_CSTCU_LUFSTAT_UFSLSTCU2_MASK         (0x4U)
#define AON_CSTCU_LUFSTAT_UFSLSTCU2_SHIFT        (2U)
/*! UFSLSTCU2 - Unrecoverable Fault Occurrence Status from LSTCU2
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LUFSTAT_UFSLSTCU2(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LUFSTAT_UFSLSTCU2_SHIFT)) & AON_CSTCU_LUFSTAT_UFSLSTCU2_MASK)

#define AON_CSTCU_LUFSTAT_UFSLSTCU3_MASK         (0x8U)
#define AON_CSTCU_LUFSTAT_UFSLSTCU3_SHIFT        (3U)
/*! UFSLSTCU3 - Unrecoverable Fault Occurrence Status from LSTCU3
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LUFSTAT_UFSLSTCU3(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LUFSTAT_UFSLSTCU3_SHIFT)) & AON_CSTCU_LUFSTAT_UFSLSTCU3_MASK)

#define AON_CSTCU_LUFSTAT_UFSLSTCU4_MASK         (0x10U)
#define AON_CSTCU_LUFSTAT_UFSLSTCU4_SHIFT        (4U)
/*! UFSLSTCU4 - Unrecoverable Fault Occurrence Status from LSTCU4
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define AON_CSTCU_LUFSTAT_UFSLSTCU4(x)           (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LUFSTAT_UFSLSTCU4_SHIFT)) & AON_CSTCU_LUFSTAT_UFSLSTCU4_MASK)
/*! @} */

/*! @name RDEN - Reset Domain Self-Test Enable */
/*! @{ */

#define AON_CSTCU_RDEN_SERD0_MASK                (0x1U)
#define AON_CSTCU_RDEN_SERD0_SHIFT               (0U)
/*! SERD0 - Enable Self-Test in Reset Domain 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_CSTCU_RDEN_SERD0(x)                  (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RDEN_SERD0_SHIFT)) & AON_CSTCU_RDEN_SERD0_MASK)

#define AON_CSTCU_RDEN_SERD1_MASK                (0x2U)
#define AON_CSTCU_RDEN_SERD1_SHIFT               (1U)
/*! SERD1 - Enable Self-Test in Reset Domain 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_CSTCU_RDEN_SERD1(x)                  (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RDEN_SERD1_SHIFT)) & AON_CSTCU_RDEN_SERD1_MASK)

#define AON_CSTCU_RDEN_SERD2_MASK                (0x4U)
#define AON_CSTCU_RDEN_SERD2_SHIFT               (2U)
/*! SERD2 - Enable Self-Test in Reset Domain 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_CSTCU_RDEN_SERD2(x)                  (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RDEN_SERD2_SHIFT)) & AON_CSTCU_RDEN_SERD2_MASK)
/*! @} */

/*! @name RDENSTAT - Reset Domain Enable Status */
/*! @{ */

#define AON_CSTCU_RDENSTAT_SESRD0_MASK           (0x1U)
#define AON_CSTCU_RDENSTAT_SESRD0_SHIFT          (0U)
/*! SESRD0 - Self-Test Enable Status in Reset Domain 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_CSTCU_RDENSTAT_SESRD0(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RDENSTAT_SESRD0_SHIFT)) & AON_CSTCU_RDENSTAT_SESRD0_MASK)

#define AON_CSTCU_RDENSTAT_SESRD1_MASK           (0x2U)
#define AON_CSTCU_RDENSTAT_SESRD1_SHIFT          (1U)
/*! SESRD1 - Self-Test Enable Status in Reset Domain 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_CSTCU_RDENSTAT_SESRD1(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RDENSTAT_SESRD1_SHIFT)) & AON_CSTCU_RDENSTAT_SESRD1_MASK)

#define AON_CSTCU_RDENSTAT_SESRD2_MASK           (0x4U)
#define AON_CSTCU_RDENSTAT_SESRD2_SHIFT          (2U)
/*! SESRD2 - Self-Test Enable Status in Reset Domain 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_CSTCU_RDENSTAT_SESRD2(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_RDENSTAT_SESRD2_SHIFT)) & AON_CSTCU_RDENSTAT_SESRD2_MASK)
/*! @} */

/*! @name LASTRDEN - Last Run Reset Domain Enable */
/*! @{ */

#define AON_CSTCU_LASTRDEN_LRSERD0_MASK          (0x1U)
#define AON_CSTCU_LASTRDEN_LRSERD0_SHIFT         (0U)
/*! LRSERD0 - Last Run Self-Test Enable Status in Reset Domain 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_CSTCU_LASTRDEN_LRSERD0(x)            (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LASTRDEN_LRSERD0_SHIFT)) & AON_CSTCU_LASTRDEN_LRSERD0_MASK)

#define AON_CSTCU_LASTRDEN_LRSERD1_MASK          (0x2U)
#define AON_CSTCU_LASTRDEN_LRSERD1_SHIFT         (1U)
/*! LRSERD1 - Last Run Self-Test Enable Status in Reset Domain 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_CSTCU_LASTRDEN_LRSERD1(x)            (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LASTRDEN_LRSERD1_SHIFT)) & AON_CSTCU_LASTRDEN_LRSERD1_MASK)

#define AON_CSTCU_LASTRDEN_LRSERD2_MASK          (0x4U)
#define AON_CSTCU_LASTRDEN_LRSERD2_SHIFT         (2U)
/*! LRSERD2 - Last Run Self-Test Enable Status in Reset Domain 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_CSTCU_LASTRDEN_LRSERD2(x)            (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LASTRDEN_LRSERD2_SHIFT)) & AON_CSTCU_LASTRDEN_LRSERD2_MASK)
/*! @} */

/*! @name BYPLSTCU - Bypass LSTCU */
/*! @{ */

#define AON_CSTCU_BYPLSTCU_BYP_L0_MASK           (0x1U)
#define AON_CSTCU_BYPLSTCU_BYP_L0_SHIFT          (0U)
/*! BYP_L0 - Bypass LSTCU 0
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define AON_CSTCU_BYPLSTCU_BYP_L0(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_BYPLSTCU_BYP_L0_SHIFT)) & AON_CSTCU_BYPLSTCU_BYP_L0_MASK)

#define AON_CSTCU_BYPLSTCU_BYP_L1_MASK           (0x2U)
#define AON_CSTCU_BYPLSTCU_BYP_L1_SHIFT          (1U)
/*! BYP_L1 - Bypass LSTCU 1
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define AON_CSTCU_BYPLSTCU_BYP_L1(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_BYPLSTCU_BYP_L1_SHIFT)) & AON_CSTCU_BYPLSTCU_BYP_L1_MASK)

#define AON_CSTCU_BYPLSTCU_BYP_L2_MASK           (0x4U)
#define AON_CSTCU_BYPLSTCU_BYP_L2_SHIFT          (2U)
/*! BYP_L2 - Bypass LSTCU 2
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define AON_CSTCU_BYPLSTCU_BYP_L2(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_BYPLSTCU_BYP_L2_SHIFT)) & AON_CSTCU_BYPLSTCU_BYP_L2_MASK)

#define AON_CSTCU_BYPLSTCU_BYP_L3_MASK           (0x8U)
#define AON_CSTCU_BYPLSTCU_BYP_L3_SHIFT          (3U)
/*! BYP_L3 - Bypass LSTCU 3
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define AON_CSTCU_BYPLSTCU_BYP_L3(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_BYPLSTCU_BYP_L3_SHIFT)) & AON_CSTCU_BYPLSTCU_BYP_L3_MASK)

#define AON_CSTCU_BYPLSTCU_BYP_L4_MASK           (0x10U)
#define AON_CSTCU_BYPLSTCU_BYP_L4_SHIFT          (4U)
/*! BYP_L4 - Bypass LSTCU 4
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define AON_CSTCU_BYPLSTCU_BYP_L4(x)             (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_BYPLSTCU_BYP_L4_SHIFT)) & AON_CSTCU_BYPLSTCU_BYP_L4_MASK)
/*! @} */

/*! @name STAG - Stagger */
/*! @{ */

#define AON_CSTCU_STAG_MB_DELAY_MASK             (0xFF00U)
#define AON_CSTCU_STAG_MB_DELAY_SHIFT            (8U)
/*! MB_DELAY - MBIST Delay */
#define AON_CSTCU_STAG_MB_DELAY(x)               (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_STAG_MB_DELAY_SHIFT)) & AON_CSTCU_STAG_MB_DELAY_MASK)
/*! @} */

/*! @name LMBPTR - LSTCU MBIST Run Phase Scheduler Pointer */
/*! @{ */

#define AON_CSTCU_LMBPTR_MBPTR_MASK              (0xFFU)
#define AON_CSTCU_LMBPTR_MBPTR_SHIFT             (0U)
/*! MBPTR - LSTCU Pointer Scheduled During MBIST Run Phase */
#define AON_CSTCU_LMBPTR_MBPTR(x)                (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LMBPTR_MBPTR_SHIFT)) & AON_CSTCU_LMBPTR_MBPTR_MASK)

#define AON_CSTCU_LMBPTR_MBCSM_MASK              (0x100U)
#define AON_CSTCU_LMBPTR_MBCSM_SHIFT             (8U)
/*! MBCSM - MBIST Concurrent or Sequential Mode
 *  0b0..Sequential mode
 *  0b1..Concurrent mode
 */
#define AON_CSTCU_LMBPTR_MBCSM(x)                (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LMBPTR_MBCSM_SHIFT)) & AON_CSTCU_LMBPTR_MBCSM_MASK)

#define AON_CSTCU_LMBPTR_MBEOL_MASK              (0x80000000U)
#define AON_CSTCU_LMBPTR_MBEOL_SHIFT             (31U)
/*! MBEOL - MBIST End of List
 *  0b0..Not end of list
 *  0b1..End of list
 */
#define AON_CSTCU_LMBPTR_MBEOL(x)                (((uint32_t)(((uint32_t)(x)) << AON_CSTCU_LMBPTR_MBEOL_SHIFT)) & AON_CSTCU_LMBPTR_MBEOL_MASK)
/*! @} */

/* The count of AON_CSTCU_LMBPTR */
#define AON_CSTCU_LMBPTR_COUNT                   (5U)


/*!
 * @}
 */ /* end of group AON_CSTCU_Register_Masks */


/*!
 * @}
 */ /* end of group AON_CSTCU_Peripheral_Access_Layer */


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


#endif  /* AON_CSTCU_H_ */

