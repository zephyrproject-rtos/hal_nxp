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
**         CMSIS Peripheral Access Layer for NETC_PRIV
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
 * @file NETC_PRIV.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NETC_PRIV
 *
 * CMSIS Peripheral Access Layer for NETC_PRIV
 */

#if !defined(NETC_PRIV_H_)
#define NETC_PRIV_H_                             /**< Symbol preventing repeated inclusion */

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
   -- NETC_PRIV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PRIV_Peripheral_Access_Layer NETC_PRIV Peripheral Access Layer
 * @{
 */

/** NETC_PRIV - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint32_t NETCRR;                            /**< NETC reset register, offset: 0x100 */
  __I  uint32_t NETCSR;                            /**< NETC status register, offset: 0x104 */
       uint8_t RESERVED_1[256];
  __IO uint32_t MEICR;                             /**< Memory Error Injection Config Register, offset: 0x208 */
  __IO uint32_t EICR;                              /**< Error Injection Code Register, offset: 0x20C */
       uint8_t RESERVED_2[3056];
  __IO uint32_t CMECR;                             /**< Correctable memory error configuration register, offset: 0xE00 */
  __IO uint32_t CMESR;                             /**< Correctable memory error status register, offset: 0xE04 */
       uint8_t RESERVED_3[4];
  __I  uint32_t CMECTR;                            /**< Correctable memory error count register, offset: 0xE0C */
       uint8_t RESERVED_4[32];
  __IO uint32_t UNMECR;                            /**< Uncorrectable non-fatal memory error configuration register, offset: 0xE30 */
  __IO uint32_t UNMESR0;                           /**< Uncorrectable non-fatal memory error status register 0, offset: 0xE34 */
  __I  uint32_t UNMESR1;                           /**< Uncorrectable non-fatal memory error status register 1, offset: 0xE38 */
  __I  uint32_t UNMECTR;                           /**< Uncorrectable non-fatal memory error count register, offset: 0xE3C */
  __IO uint32_t UFMECR;                            /**< Uncorrectable fatal memory error configuration register, offset: 0xE40 */
  __IO uint32_t UFMESR0;                           /**< Uncorrectable fatal memory error status register 0, offset: 0xE44 */
  __I  uint32_t UFMESR1;                           /**< Uncorrectable fatal memory error status register 1, offset: 0xE48 */
} NETC_PRIV_Type;

/* ----------------------------------------------------------------------------
   -- NETC_PRIV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PRIV_Register_Masks NETC_PRIV Register Masks
 * @{
 */

/*! @name NETCRR - NETC reset register */
/*! @{ */

#define NETC_PRIV_NETCRR_SR_MASK                 (0x1U)
#define NETC_PRIV_NETCRR_SR_SHIFT                (0U)
/*! SR - Soft reset */
#define NETC_PRIV_NETCRR_SR(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCRR_SR_SHIFT)) & NETC_PRIV_NETCRR_SR_MASK)

#define NETC_PRIV_NETCRR_LOCK_MASK               (0x2U)
#define NETC_PRIV_NETCRR_LOCK_SHIFT              (1U)
/*! LOCK - Lock */
#define NETC_PRIV_NETCRR_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCRR_LOCK_SHIFT)) & NETC_PRIV_NETCRR_LOCK_MASK)
/*! @} */

/*! @name NETCSR - NETC status register */
/*! @{ */

#define NETC_PRIV_NETCSR_ERROR_MASK              (0x1U)
#define NETC_PRIV_NETCSR_ERROR_SHIFT             (0U)
/*! ERROR - Error
 *  0b0..Configuration is valid.
 *  0b1..The current IERB configuration setting is invalid due to error in binding or resource allocation.
 *       Operating NETC in current condition could lead to undefined behavior.
 */
#define NETC_PRIV_NETCSR_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCSR_ERROR_SHIFT)) & NETC_PRIV_NETCSR_ERROR_MASK)

#define NETC_PRIV_NETCSR_STATE_MASK              (0x2U)
#define NETC_PRIV_NETCSR_STATE_SHIFT             (1U)
/*! STATE - Indicates NETC's operational state
 *  0b0..All NETC functions are ready for operation.
 *  0b1..NETC has inhibited write access to IERB registers and is in the process of initializing NETC.
 */
#define NETC_PRIV_NETCSR_STATE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCSR_STATE_SHIFT)) & NETC_PRIV_NETCSR_STATE_MASK)
/*! @} */

/*! @name MEICR - Memory Error Injection Config Register */
/*! @{ */

#define NETC_PRIV_MEICR_LINK_ID_MASK             (0x1FU)
#define NETC_PRIV_MEICR_LINK_ID_SHIFT            (0U)
/*! LINK_ID - Link ID */
#define NETC_PRIV_MEICR_LINK_ID(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_LINK_ID_SHIFT)) & NETC_PRIV_MEICR_LINK_ID_MASK)

#define NETC_PRIV_MEICR_MEM_ID_MASK              (0x1F00U)
#define NETC_PRIV_MEICR_MEM_ID_SHIFT             (8U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_MEICR_MEM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_MEM_ID_SHIFT)) & NETC_PRIV_MEICR_MEM_ID_MASK)

#define NETC_PRIV_MEICR_ARM_MASK                 (0xC0000000U)
#define NETC_PRIV_MEICR_ARM_SHIFT                (30U)
/*! ARM - Armed
 *  0b00..Disabled
 *  0b01..Single Bit ECC Error
 *  0b10..Multi Bit ECC Error
 *  0b11..Reserved (disabled)
 */
#define NETC_PRIV_MEICR_ARM(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_ARM_SHIFT)) & NETC_PRIV_MEICR_ARM_MASK)
/*! @} */

/*! @name EICR - Error Injection Code Register */
/*! @{ */

#define NETC_PRIV_EICR_EN_MASK                   (0xFFU)
#define NETC_PRIV_EICR_EN_SHIFT                  (0U)
/*! EN - Enable
 *  0b10000110..Enables error injection function
 *  *..Disables error injection function
 */
#define NETC_PRIV_EICR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_EICR_EN_SHIFT)) & NETC_PRIV_EICR_EN_MASK)
/*! @} */

/*! @name CMECR - Correctable memory error configuration register */
/*! @{ */

#define NETC_PRIV_CMECR_THRESHOLD_MASK           (0xFFU)
#define NETC_PRIV_CMECR_THRESHOLD_SHIFT          (0U)
/*! THRESHOLD - Threshold */
#define NETC_PRIV_CMECR_THRESHOLD(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMECR_THRESHOLD_SHIFT)) & NETC_PRIV_CMECR_THRESHOLD_MASK)
/*! @} */

/*! @name CMESR - Correctable memory error status register */
/*! @{ */

#define NETC_PRIV_CMESR_LINK_SLICE_ID_MASK       (0x1FU)
#define NETC_PRIV_CMESR_LINK_SLICE_ID_SHIFT      (0U)
/*! LINK_SLICE_ID - Link or Slice ID */
#define NETC_PRIV_CMESR_LINK_SLICE_ID(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_LINK_SLICE_ID_SHIFT)) & NETC_PRIV_CMESR_LINK_SLICE_ID_MASK)

#define NETC_PRIV_CMESR_MEM_ID_MASK              (0x1F00U)
#define NETC_PRIV_CMESR_MEM_ID_SHIFT             (8U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_CMESR_MEM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_MEM_ID_SHIFT)) & NETC_PRIV_CMESR_MEM_ID_MASK)

#define NETC_PRIV_CMESR_LE_MASK                  (0x20000000U)
#define NETC_PRIV_CMESR_LE_SHIFT                 (29U)
/*! LE - Locality Elevated */
#define NETC_PRIV_CMESR_LE(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_LE_SHIFT)) & NETC_PRIV_CMESR_LE_MASK)

#define NETC_PRIV_CMESR_SBEE_MASK                (0x80000000U)
#define NETC_PRIV_CMESR_SBEE_SHIFT               (31U)
/*! SBEE - Single-bit ECC error */
#define NETC_PRIV_CMESR_SBEE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_SBEE_SHIFT)) & NETC_PRIV_CMESR_SBEE_MASK)
/*! @} */

/*! @name CMECTR - Correctable memory error count register */
/*! @{ */

#define NETC_PRIV_CMECTR_COUNT_MASK              (0xFFU)
#define NETC_PRIV_CMECTR_COUNT_SHIFT             (0U)
/*! COUNT - Count */
#define NETC_PRIV_CMECTR_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMECTR_COUNT_SHIFT)) & NETC_PRIV_CMECTR_COUNT_MASK)
/*! @} */

/*! @name UNMECR - Uncorrectable non-fatal memory error configuration register */
/*! @{ */

#define NETC_PRIV_UNMECR_THRESHOLD_MASK          (0xFFU)
#define NETC_PRIV_UNMECR_THRESHOLD_SHIFT         (0U)
/*! THRESHOLD - Threshold
 *  0b00000000..Disables reporting of non-fatal memory errors.
 *  *..Determines the threshold value (1-255) of non-fatal memory errors to be reported.
 */
#define NETC_PRIV_UNMECR_THRESHOLD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECR_THRESHOLD_SHIFT)) & NETC_PRIV_UNMECR_THRESHOLD_MASK)

#define NETC_PRIV_UNMECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UNMECR_RD_SHIFT                (31U)
/*! RD - Report disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define NETC_PRIV_UNMECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECR_RD_SHIFT)) & NETC_PRIV_UNMECR_RD_MASK)
/*! @} */

/*! @name UNMESR0 - Uncorrectable non-fatal memory error status register 0 */
/*! @{ */

#define NETC_PRIV_UNMESR0_LINK_SLICE_ID_MASK     (0x1FU)
#define NETC_PRIV_UNMESR0_LINK_SLICE_ID_SHIFT    (0U)
/*! LINK_SLICE_ID - Link or Slice ID */
#define NETC_PRIV_UNMESR0_LINK_SLICE_ID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_LINK_SLICE_ID_SHIFT)) & NETC_PRIV_UNMESR0_LINK_SLICE_ID_MASK)

#define NETC_PRIV_UNMESR0_MEM_ID_MASK            (0x1F00U)
#define NETC_PRIV_UNMESR0_MEM_ID_SHIFT           (8U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_UNMESR0_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_MEM_ID_SHIFT)) & NETC_PRIV_UNMESR0_MEM_ID_MASK)

#define NETC_PRIV_UNMESR0_SYNDROME_MASK          (0x7FF0000U)
#define NETC_PRIV_UNMESR0_SYNDROME_SHIFT         (16U)
/*! SYNDROME - Syndrome */
#define NETC_PRIV_UNMESR0_SYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_SYNDROME_SHIFT)) & NETC_PRIV_UNMESR0_SYNDROME_MASK)

#define NETC_PRIV_UNMESR0_LE_MASK                (0x20000000U)
#define NETC_PRIV_UNMESR0_LE_SHIFT               (29U)
/*! LE - Locality Elevated */
#define NETC_PRIV_UNMESR0_LE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_LE_SHIFT)) & NETC_PRIV_UNMESR0_LE_MASK)

#define NETC_PRIV_UNMESR0_MBEE_MASK              (0x80000000U)
#define NETC_PRIV_UNMESR0_MBEE_SHIFT             (31U)
/*! MBEE - Multi-bit ECC error */
#define NETC_PRIV_UNMESR0_MBEE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_MBEE_SHIFT)) & NETC_PRIV_UNMESR0_MBEE_MASK)
/*! @} */

/*! @name UNMESR1 - Uncorrectable non-fatal memory error status register 1 */
/*! @{ */

#define NETC_PRIV_UNMESR1_ADDR_MASK              (0xFFFFFFFFU)
#define NETC_PRIV_UNMESR1_ADDR_SHIFT             (0U)
/*! ADDR - Address */
#define NETC_PRIV_UNMESR1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR1_ADDR_SHIFT)) & NETC_PRIV_UNMESR1_ADDR_MASK)
/*! @} */

/*! @name UNMECTR - Uncorrectable non-fatal memory error count register */
/*! @{ */

#define NETC_PRIV_UNMECTR_COUNT_MASK             (0xFFU)
#define NETC_PRIV_UNMECTR_COUNT_SHIFT            (0U)
/*! COUNT - Count */
#define NETC_PRIV_UNMECTR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECTR_COUNT_SHIFT)) & NETC_PRIV_UNMECTR_COUNT_MASK)
/*! @} */

/*! @name UFMECR - Uncorrectable fatal memory error configuration register */
/*! @{ */

#define NETC_PRIV_UFMECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UFMECR_RD_SHIFT                (31U)
/*! RD - Report disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define NETC_PRIV_UFMECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMECR_RD_SHIFT)) & NETC_PRIV_UFMECR_RD_MASK)
/*! @} */

/*! @name UFMESR0 - Uncorrectable fatal memory error status register 0 */
/*! @{ */

#define NETC_PRIV_UFMESR0_LINK_SLICE_ID_MASK     (0x1FU)
#define NETC_PRIV_UFMESR0_LINK_SLICE_ID_SHIFT    (0U)
/*! LINK_SLICE_ID - Link or Slice ID */
#define NETC_PRIV_UFMESR0_LINK_SLICE_ID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_LINK_SLICE_ID_SHIFT)) & NETC_PRIV_UFMESR0_LINK_SLICE_ID_MASK)

#define NETC_PRIV_UFMESR0_MEM_ID_MASK            (0x1F00U)
#define NETC_PRIV_UFMESR0_MEM_ID_SHIFT           (8U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_UFMESR0_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_MEM_ID_SHIFT)) & NETC_PRIV_UFMESR0_MEM_ID_MASK)

#define NETC_PRIV_UFMESR0_SYNDROME_MASK          (0x7FF0000U)
#define NETC_PRIV_UFMESR0_SYNDROME_SHIFT         (16U)
/*! SYNDROME - Syndrome */
#define NETC_PRIV_UFMESR0_SYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_SYNDROME_SHIFT)) & NETC_PRIV_UFMESR0_SYNDROME_MASK)

#define NETC_PRIV_UFMESR0_LE_MASK                (0x20000000U)
#define NETC_PRIV_UFMESR0_LE_SHIFT               (29U)
/*! LE - Locality Elevated */
#define NETC_PRIV_UFMESR0_LE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_LE_SHIFT)) & NETC_PRIV_UFMESR0_LE_MASK)

#define NETC_PRIV_UFMESR0_M_MASK                 (0x40000000U)
#define NETC_PRIV_UFMESR0_M_SHIFT                (30U)
/*! M - Multiple */
#define NETC_PRIV_UFMESR0_M(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_M_SHIFT)) & NETC_PRIV_UFMESR0_M_MASK)

#define NETC_PRIV_UFMESR0_MBEE_MASK              (0x80000000U)
#define NETC_PRIV_UFMESR0_MBEE_SHIFT             (31U)
/*! MBEE - Multi-bit ECC error */
#define NETC_PRIV_UFMESR0_MBEE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_MBEE_SHIFT)) & NETC_PRIV_UFMESR0_MBEE_MASK)
/*! @} */

/*! @name UFMESR1 - Uncorrectable fatal memory error status register 1 */
/*! @{ */

#define NETC_PRIV_UFMESR1_ADDR_MASK              (0xFFFFFFFFU)
#define NETC_PRIV_UFMESR1_ADDR_SHIFT             (0U)
/*! ADDR - Address */
#define NETC_PRIV_UFMESR1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR1_ADDR_SHIFT)) & NETC_PRIV_UFMESR1_ADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NETC_PRIV_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_PRIV_Peripheral_Access_Layer */


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


#endif  /* NETC_PRIV_H_ */

