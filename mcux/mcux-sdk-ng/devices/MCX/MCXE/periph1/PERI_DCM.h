/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DCM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for DCM
 *
 * CMSIS Peripheral Access Layer for DCM
 */

#if !defined(PERI_DCM_H_)
#define PERI_DCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- DCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_Peripheral_Access_Layer DCM Peripheral Access Layer
 * @{
 */

/** DCM - Size of Registers Arrays */
#define DCM_DCMSRR_COUNT                          16u

/** DCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t DCMSTAT;                           /**< DCM Status, offset: 0x0 */
  __IO uint32_t DCMLCC;                            /**< LC and LC Control, offset: 0x4 */
  __IO uint32_t DCMLCS;                            /**< LC Scan Status, offset: 0x8 */
       uint8_t RESERVED_0[16];
  __IO uint32_t DCMMISC;                           /**< DCM Miscellaneous, offset: 0x1C */
  __I  uint32_t DCMDEB;                            /**< Debug Status and Configuration, offset: 0x20 */
       uint8_t RESERVED_1[8];
  __I  uint32_t DCMEC;                             /**< DCF Error Count, offset: 0x2C */
  __IO uint32_t DCMSRR[DCM_DCMSRR_COUNT];          /**< DCF Scan Report, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __IO uint32_t DCMLCS_2;                          /**< LC Scan Status 2, offset: 0x80 */
} DCM_Type;

/* ----------------------------------------------------------------------------
   -- DCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_Register_Masks DCM Register Masks
 * @{
 */

/*! @name DCMSTAT - DCM Status */
/*! @{ */

#define DCM_DCMSTAT_DCMDONE_MASK                 (0x1U)
#define DCM_DCMSTAT_DCMDONE_SHIFT                (0U)
/*! DCMDONE - DCM Scanning Status
 *  0b0..Running
 *  0b1..Completed
 */
#define DCM_DCMSTAT_DCMDONE(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMDONE_SHIFT)) & DCM_DCMSTAT_DCMDONE_MASK)

#define DCM_DCMSTAT_DCMERR_MASK                  (0x2U)
#define DCM_DCMSTAT_DCMERR_SHIFT                 (1U)
/*! DCMERR - DCM completion with error status (valid only if DCMDONE bit is set)
 *  0b0..DCM completed with success.
 *  0b1..DCM completed with error.
 */
#define DCM_DCMSTAT_DCMERR(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMERR_SHIFT)) & DCM_DCMSTAT_DCMERR_MASK)

#define DCM_DCMSTAT_DCMLCST_MASK                 (0x10U)
#define DCM_DCMSTAT_DCMLCST_SHIFT                (4U)
/*! DCMLCST - LC Scanning Status
 *  0b0..Completed with errors
 *  0b1..Completed successfully
 */
#define DCM_DCMSTAT_DCMLCST(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMLCST_SHIFT)) & DCM_DCMSTAT_DCMLCST_MASK)

#define DCM_DCMSTAT_DCMUTS_MASK                  (0x100U)
#define DCM_DCMSTAT_DCMUTS_SHIFT                 (8U)
/*! DCMUTS - DCM Utest DCF Scanning Status (valid only if DCMDONE bit is set)
 *  0b0..DCM Utest DCF completed with errors.
 *  0b1..DCM Utest DCF completed successfully.
 */
#define DCM_DCMSTAT_DCMUTS(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMUTS_SHIFT)) & DCM_DCMSTAT_DCMUTS_MASK)

#define DCM_DCMSTAT_DCMOTAS_MASK                 (0x200U)
#define DCM_DCMSTAT_DCMOTAS_SHIFT                (9U)
/*! DCMOTAS - DCM OTA Scanning Status (valid only when the value of the DCMDONE field is 1)
 *  0b0..Completed with errors
 *  0b1..Completed successfully
 */
#define DCM_DCMSTAT_DCMOTAS(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMOTAS_SHIFT)) & DCM_DCMSTAT_DCMOTAS_MASK)

#define DCM_DCMSTAT_DCMDBGPS_MASK                (0x400U)
#define DCM_DCMSTAT_DCMDBGPS_SHIFT               (10U)
/*! DCMDBGPS - Debug Password Scanning Status
 *  0b0..Completed with errors
 *  0b1..Completed successfully
 */
#define DCM_DCMSTAT_DCMDBGPS(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSTAT_DCMDBGPS_SHIFT)) & DCM_DCMSTAT_DCMDBGPS_MASK)
/*! @} */

/*! @name DCMLCC - LC and LC Control */
/*! @{ */

#define DCM_DCMLCC_DCMCLC_MASK                   (0x7U)
#define DCM_DCMLCC_DCMCLC_SHIFT                  (0U)
/*! DCMCLC - Current LC
 *  0b000..FA
 *  0b001..Pre-FA
 *  0b010..OEM_PROD
 *  0b011..CUST_DEL
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..MCU_PROD
 *  0b111..IN_FIELD
 */
#define DCM_DCMLCC_DCMCLC(x)                     (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMCLC_SHIFT)) & DCM_DCMLCC_DCMCLC_MASK)

#define DCM_DCMLCC_DCMLCFN_MASK                  (0x8U)
#define DCM_DCMLCC_DCMLCFN_SHIFT                 (3U)
/*! DCMLCFN - Force LC
 *  0b0..Normal
 *  0b1..Forced on current LC
 */
#define DCM_DCMLCC_DCMLCFN(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMLCFN_SHIFT)) & DCM_DCMLCC_DCMLCFN_MASK)

#define DCM_DCMLCC_DCMRLC_MASK                   (0x70U)
#define DCM_DCMLCC_DCMRLC_SHIFT                  (4U)
/*! DCMRLC - Real LC
 *  0b000..FA
 *  0b001..Pre-FA
 *  0b010..OEM_PROD
 *  0b011..CUST_DEL
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..MCU_PROD
 *  0b111..IN_FIELD
 */
#define DCM_DCMLCC_DCMRLC(x)                     (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMRLC_SHIFT)) & DCM_DCMLCC_DCMRLC_MASK)

#define DCM_DCMLCC_DCMFLC_MASK                   (0x300U)
#define DCM_DCMLCC_DCMFLC_SHIFT                  (8U)
/*! DCMFLC - Force Next LC
 *  0b00..No force
 *  0b01..Force LC to one next
 *  0b10..Force LC to two next (only possible in CD)
 *  0b11..Reserved (no effect)
 */
#define DCM_DCMLCC_DCMFLC(x)                     (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCC_DCMFLC_SHIFT)) & DCM_DCMLCC_DCMFLC_MASK)
/*! @} */

/*! @name DCMLCS - LC Scan Status */
/*! @{ */

#define DCM_DCMLCS_DCMLCSS1_MASK                 (0x1U)
#define DCM_DCMLCS_DCMLCSS1_SHIFT                (0U)
/*! DCMLCSS1 - MCU_PROD Scan Status
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCSS1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS1_SHIFT)) & DCM_DCMLCS_DCMLCSS1_MASK)

#define DCM_DCMLCS_DCMLCC1_MASK                  (0xEU)
#define DCM_DCMLCS_DCMLCC1_SHIFT                 (1U)
/*! DCMLCC1 - MCU_PROD Marking
 *  0b000..Not scanned yet
 *  0b001..Marked as active
 *  0b010..Marked as inactive
 *  0b011..Region is erased/virgin
 *  0b101..Marked as inactive by an unknown pattern
 *  0b110..Scanning timed out
 */
#define DCM_DCMLCS_DCMLCC1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC1_SHIFT)) & DCM_DCMLCS_DCMLCC1_MASK)

#define DCM_DCMLCS_DCMLCE1_MASK                  (0x10U)
#define DCM_DCMLCS_DCMLCE1_SHIFT                 (4U)
/*! DCMLCE1 - MCU_PROD ECC Errors
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCE1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE1_SHIFT)) & DCM_DCMLCS_DCMLCE1_MASK)

#define DCM_DCMLCS_DCMLCFE1_MASK                 (0x20U)
#define DCM_DCMLCS_DCMLCFE1_SHIFT                (5U)
/*! DCMLCFE1 - MCU_PROD Flash Memory Error Check
 *  0b0..Successful
 *  0b1..Failed
 */
#define DCM_DCMLCS_DCMLCFE1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE1_SHIFT)) & DCM_DCMLCS_DCMLCFE1_MASK)

#define DCM_DCMLCS_DCMLCSS2_MASK                 (0x40U)
#define DCM_DCMLCS_DCMLCSS2_SHIFT                (6U)
/*! DCMLCSS2 - CUST_DEL Scan Status
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCSS2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS2_SHIFT)) & DCM_DCMLCS_DCMLCSS2_MASK)

#define DCM_DCMLCS_DCMLCC2_MASK                  (0x380U)
#define DCM_DCMLCS_DCMLCC2_SHIFT                 (7U)
/*! DCMLCC2 - CUST_DEL Marking
 *  0b000..Not scanned yet
 *  0b001..Marked as active
 *  0b010..Marked as inactive
 *  0b011..Region is erased/virgin
 *  0b101..Marked as inactive by an unknown pattern
 *  0b110..Scanning timed out
 */
#define DCM_DCMLCS_DCMLCC2(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC2_SHIFT)) & DCM_DCMLCS_DCMLCC2_MASK)

#define DCM_DCMLCS_DCMLCE2_MASK                  (0x400U)
#define DCM_DCMLCS_DCMLCE2_SHIFT                 (10U)
/*! DCMLCE2 - ECC Errors In CUST_DEL
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCE2(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE2_SHIFT)) & DCM_DCMLCS_DCMLCE2_MASK)

#define DCM_DCMLCS_DCMLCFE2_MASK                 (0x800U)
#define DCM_DCMLCS_DCMLCFE2_SHIFT                (11U)
/*! DCMLCFE2 - CUST_DEL Flash Memory Error Check
 *  0b0..Successful
 *  0b1..Failed
 */
#define DCM_DCMLCS_DCMLCFE2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE2_SHIFT)) & DCM_DCMLCS_DCMLCFE2_MASK)

#define DCM_DCMLCS_DCMLCSS3_MASK                 (0x1000U)
#define DCM_DCMLCS_DCMLCSS3_SHIFT                (12U)
/*! DCMLCSS3 - OEM_PROD Scan Status
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCSS3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS3_SHIFT)) & DCM_DCMLCS_DCMLCSS3_MASK)

#define DCM_DCMLCS_DCMLCC3_MASK                  (0xE000U)
#define DCM_DCMLCS_DCMLCC3_SHIFT                 (13U)
/*! DCMLCC3 - OEM_PROD Marking
 *  0b000..Not scanned yet
 *  0b001..Marked as active
 *  0b010..Marked as inactive
 *  0b011..Region is erased/virgin
 *  0b101..Marked as inactive by an unknown pattern
 *  0b110..Scanning timed out
 */
#define DCM_DCMLCS_DCMLCC3(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC3_SHIFT)) & DCM_DCMLCS_DCMLCC3_MASK)

#define DCM_DCMLCS_DCMLCE3_MASK                  (0x10000U)
#define DCM_DCMLCS_DCMLCE3_SHIFT                 (16U)
/*! DCMLCE3 - OEM_PROD ECC Errors
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCE3(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE3_SHIFT)) & DCM_DCMLCS_DCMLCE3_MASK)

#define DCM_DCMLCS_DCMLCFE3_MASK                 (0x20000U)
#define DCM_DCMLCS_DCMLCFE3_SHIFT                (17U)
/*! DCMLCFE3 - OEM_PROD Flash Memory Error Check
 *  0b0..Successful
 *  0b1..Failed
 */
#define DCM_DCMLCS_DCMLCFE3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE3_SHIFT)) & DCM_DCMLCS_DCMLCFE3_MASK)

#define DCM_DCMLCS_DCMLCSS4_MASK                 (0x40000U)
#define DCM_DCMLCS_DCMLCSS4_SHIFT                (18U)
/*! DCMLCSS4 - IN_FIELD Scan Status
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCSS4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS4_SHIFT)) & DCM_DCMLCS_DCMLCSS4_MASK)

#define DCM_DCMLCS_DCMLCC4_MASK                  (0x380000U)
#define DCM_DCMLCS_DCMLCC4_SHIFT                 (19U)
/*! DCMLCC4 - IN_FIELD Marking Status
 *  0b000..Not scanned yet
 *  0b001..Marked as active
 *  0b010..Marked as inactive
 *  0b011..Region is erased/virgin
 *  0b101..Marked as inactive by an unknown pattern
 *  0b110..Scanning timed out
 */
#define DCM_DCMLCS_DCMLCC4(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC4_SHIFT)) & DCM_DCMLCS_DCMLCC4_MASK)

#define DCM_DCMLCS_DCMLCE4_MASK                  (0x400000U)
#define DCM_DCMLCS_DCMLCE4_SHIFT                 (22U)
/*! DCMLCE4 - IN_FIELD ECC Errors
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCE4(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE4_SHIFT)) & DCM_DCMLCS_DCMLCE4_MASK)

#define DCM_DCMLCS_DCMLCFE4_MASK                 (0x800000U)
#define DCM_DCMLCS_DCMLCFE4_SHIFT                (23U)
/*! DCMLCFE4 - IN_FIELD Flash Memory Error Check
 *  0b0..Successful
 *  0b1..Failed
 */
#define DCM_DCMLCS_DCMLCFE4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE4_SHIFT)) & DCM_DCMLCS_DCMLCFE4_MASK)

#define DCM_DCMLCS_DCMLCSS5_MASK                 (0x1000000U)
#define DCM_DCMLCS_DCMLCSS5_SHIFT                (24U)
/*! DCMLCSS5 - Pre-FA Scan Status
 *  0b0..Successful
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_DCMLCSS5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCSS5_SHIFT)) & DCM_DCMLCS_DCMLCSS5_MASK)

#define DCM_DCMLCS_DCMLCC5_MASK                  (0xE000000U)
#define DCM_DCMLCS_DCMLCC5_SHIFT                 (25U)
/*! DCMLCC5 - Pre-FA Marking Status
 *  0b000..Not scanned yet
 *  0b001..Marked as active
 *  0b010..Marked as inactive
 *  0b011..Region is erased/virgin
 *  0b101..Marked as inactive by an unknown pattern
 *  0b110..Scanning timed out
 */
#define DCM_DCMLCS_DCMLCC5(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCC5_SHIFT)) & DCM_DCMLCS_DCMLCC5_MASK)

#define DCM_DCMLCS_DCMLCE5_MASK                  (0x10000000U)
#define DCM_DCMLCS_DCMLCE5_SHIFT                 (28U)
/*! DCMLCE5 - Pre-FA ECC Errors
 *  0b0..No errors
 *  0b1..Marking error
 */
#define DCM_DCMLCS_DCMLCE5(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCE5_SHIFT)) & DCM_DCMLCS_DCMLCE5_MASK)

#define DCM_DCMLCS_DCMLCFE5_MASK                 (0x20000000U)
#define DCM_DCMLCS_DCMLCFE5_SHIFT                (29U)
/*! DCMLCFE5 - Pre-FA Flash Memory Error Check
 *  0b0..Successful
 *  0b1..Failed
 */
#define DCM_DCMLCS_DCMLCFE5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_DCMLCFE5_SHIFT)) & DCM_DCMLCS_DCMLCFE5_MASK)
/*! @} */

/*! @name DCMMISC - DCM Miscellaneous */
/*! @{ */

#define DCM_DCMMISC_DCMDBGT_MASK                 (0x400U)
#define DCM_DCMMISC_DCMDBGT_SHIFT                (10U)
/*! DCMDBGT - DBG Section Error
 *  0b0..No error
 *  0b1..Error exists
 */
#define DCM_DCMMISC_DCMDBGT(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMMISC_DCMDBGT_SHIFT)) & DCM_DCMMISC_DCMDBGT_MASK)

#define DCM_DCMMISC_DCMDBGE_MASK                 (0x800U)
#define DCM_DCMMISC_DCMDBGE_SHIFT                (11U)
/*! DCMDBGE - DCM ECC error on DBG sections
 *  0b0..No error on DBG section
 *  0b1..DBG section error
 */
#define DCM_DCMMISC_DCMDBGE(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMMISC_DCMDBGE_SHIFT)) & DCM_DCMMISC_DCMDBGE_MASK)

#define DCM_DCMMISC_DCMCERS_MASK                 (0x10000000U)
#define DCM_DCMMISC_DCMCERS_SHIFT                (28U)
/*! DCMCERS - DCF Client Errors
 *  0b0..No errors on any of the DCF clients
 *  0b1..Atleast one safety DCF client has an error
 */
#define DCM_DCMMISC_DCMCERS(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMMISC_DCMCERS_SHIFT)) & DCM_DCMMISC_DCMCERS_MASK)
/*! @} */

/*! @name DCMDEB - Debug Status and Configuration */
/*! @{ */

#define DCM_DCMDEB_DCM_APPDBG_STAT_MASK          (0x2U)
#define DCM_DCMDEB_DCM_APPDBG_STAT_SHIFT         (1U)
/*! DCM_APPDBG_STAT - DCM Authentication Engine Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_DCMDEB_DCM_APPDBG_STAT(x)            (((uint32_t)(((uint32_t)(x)) << DCM_DCMDEB_DCM_APPDBG_STAT_SHIFT)) & DCM_DCMDEB_DCM_APPDBG_STAT_MASK)

#define DCM_DCMDEB_APPDBG_STAT_SOC_MASK          (0x10000U)
#define DCM_DCMDEB_APPDBG_STAT_SOC_SHIFT         (16U)
/*! APPDBG_STAT_SOC - Application Debug Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_DCMDEB_APPDBG_STAT_SOC(x)            (((uint32_t)(((uint32_t)(x)) << DCM_DCMDEB_APPDBG_STAT_SOC_SHIFT)) & DCM_DCMDEB_APPDBG_STAT_SOC_MASK)
/*! @} */

/*! @name DCMEC - DCF Error Count */
/*! @{ */

#define DCM_DCMEC_DCMECT_MASK                    (0xFFFFU)
#define DCM_DCMEC_DCMECT_SHIFT                   (0U)
/*! DCMECT - Error Count */
#define DCM_DCMEC_DCMECT(x)                      (((uint32_t)(((uint32_t)(x)) << DCM_DCMEC_DCMECT_SHIFT)) & DCM_DCMEC_DCMECT_MASK)
/*! @} */

/*! @name DCMSRR - DCF Scan Report */
/*! @{ */

#define DCM_DCMSRR_DCMDCFE1_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE1_SHIFT                (0U)
/*! DCMDCFE1 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE1_SHIFT)) & DCM_DCMSRR_DCMDCFE1_MASK)

#define DCM_DCMSRR_DCMDCFF1_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF1_SHIFT                (24U)
/*! DCMDCFF1 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF1_SHIFT)) & DCM_DCMSRR_DCMDCFF1_MASK)

#define DCM_DCMSRR_DCMESF1_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF1_SHIFT                 (27U)
/*! DCMESF1 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF1_SHIFT)) & DCM_DCMSRR_DCMESF1_MASK)

#define DCM_DCMSRR_DCMESD1_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD1_SHIFT                 (28U)
/*! DCMESD1 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD1(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD1_SHIFT)) & DCM_DCMSRR_DCMESD1_MASK)

#define DCM_DCMSRR_DCMDCFT1_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT1_SHIFT                (29U)
/*! DCMDCFT1 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT1(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT1_SHIFT)) & DCM_DCMSRR_DCMDCFT1_MASK)

#define DCM_DCMSRR_DCMDCFE2_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE2_SHIFT                (0U)
/*! DCMDCFE2 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE2_SHIFT)) & DCM_DCMSRR_DCMDCFE2_MASK)

#define DCM_DCMSRR_DCMDCFF2_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF2_SHIFT                (24U)
/*! DCMDCFF2 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF2_SHIFT)) & DCM_DCMSRR_DCMDCFF2_MASK)

#define DCM_DCMSRR_DCMESF2_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF2_SHIFT                 (27U)
/*! DCMESF2 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF2(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF2_SHIFT)) & DCM_DCMSRR_DCMESF2_MASK)

#define DCM_DCMSRR_DCMESD2_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD2_SHIFT                 (28U)
/*! DCMESD2 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD2(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD2_SHIFT)) & DCM_DCMSRR_DCMESD2_MASK)

#define DCM_DCMSRR_DCMDCFT2_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT2_SHIFT                (29U)
/*! DCMDCFT2 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT2(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT2_SHIFT)) & DCM_DCMSRR_DCMDCFT2_MASK)

#define DCM_DCMSRR_DCMDCFE3_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE3_SHIFT                (0U)
/*! DCMDCFE3 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE3_SHIFT)) & DCM_DCMSRR_DCMDCFE3_MASK)

#define DCM_DCMSRR_DCMDCFF3_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF3_SHIFT                (24U)
/*! DCMDCFF3 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF3_SHIFT)) & DCM_DCMSRR_DCMDCFF3_MASK)

#define DCM_DCMSRR_DCMESF3_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF3_SHIFT                 (27U)
/*! DCMESF3 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF3(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF3_SHIFT)) & DCM_DCMSRR_DCMESF3_MASK)

#define DCM_DCMSRR_DCMESD3_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD3_SHIFT                 (28U)
/*! DCMESD3 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD3(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD3_SHIFT)) & DCM_DCMSRR_DCMESD3_MASK)

#define DCM_DCMSRR_DCMDCFT3_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT3_SHIFT                (29U)
/*! DCMDCFT3 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT3(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT3_SHIFT)) & DCM_DCMSRR_DCMDCFT3_MASK)

#define DCM_DCMSRR_DCMDCFE4_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE4_SHIFT                (0U)
/*! DCMDCFE4 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE4_SHIFT)) & DCM_DCMSRR_DCMDCFE4_MASK)

#define DCM_DCMSRR_DCMDCFF4_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF4_SHIFT                (24U)
/*! DCMDCFF4 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF4_SHIFT)) & DCM_DCMSRR_DCMDCFF4_MASK)

#define DCM_DCMSRR_DCMESF4_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF4_SHIFT                 (27U)
/*! DCMESF4 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF4(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF4_SHIFT)) & DCM_DCMSRR_DCMESF4_MASK)

#define DCM_DCMSRR_DCMESD4_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD4_SHIFT                 (28U)
/*! DCMESD4 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD4(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD4_SHIFT)) & DCM_DCMSRR_DCMESD4_MASK)

#define DCM_DCMSRR_DCMDCFT4_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT4_SHIFT                (29U)
/*! DCMDCFT4 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT4(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT4_SHIFT)) & DCM_DCMSRR_DCMDCFT4_MASK)

#define DCM_DCMSRR_DCMDCFE5_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE5_SHIFT                (0U)
/*! DCMDCFE5 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE5_SHIFT)) & DCM_DCMSRR_DCMDCFE5_MASK)

#define DCM_DCMSRR_DCMDCFF5_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF5_SHIFT                (24U)
/*! DCMDCFF5 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF5_SHIFT)) & DCM_DCMSRR_DCMDCFF5_MASK)

#define DCM_DCMSRR_DCMESF5_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF5_SHIFT                 (27U)
/*! DCMESF5 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF5(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF5_SHIFT)) & DCM_DCMSRR_DCMESF5_MASK)

#define DCM_DCMSRR_DCMESD5_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD5_SHIFT                 (28U)
/*! DCMESD5 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD5(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD5_SHIFT)) & DCM_DCMSRR_DCMESD5_MASK)

#define DCM_DCMSRR_DCMDCFT5_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT5_SHIFT                (29U)
/*! DCMDCFT5 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT5(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT5_SHIFT)) & DCM_DCMSRR_DCMDCFT5_MASK)

#define DCM_DCMSRR_DCMDCFE6_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE6_SHIFT                (0U)
/*! DCMDCFE6 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE6(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE6_SHIFT)) & DCM_DCMSRR_DCMDCFE6_MASK)

#define DCM_DCMSRR_DCMDCFF6_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF6_SHIFT                (24U)
/*! DCMDCFF6 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF6(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF6_SHIFT)) & DCM_DCMSRR_DCMDCFF6_MASK)

#define DCM_DCMSRR_DCMESF6_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF6_SHIFT                 (27U)
/*! DCMESF6 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF6(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF6_SHIFT)) & DCM_DCMSRR_DCMESF6_MASK)

#define DCM_DCMSRR_DCMESD6_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD6_SHIFT                 (28U)
/*! DCMESD6 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD6(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD6_SHIFT)) & DCM_DCMSRR_DCMESD6_MASK)

#define DCM_DCMSRR_DCMDCFT6_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT6_SHIFT                (29U)
/*! DCMDCFT6 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT6(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT6_SHIFT)) & DCM_DCMSRR_DCMDCFT6_MASK)

#define DCM_DCMSRR_DCMDCFE7_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE7_SHIFT                (0U)
/*! DCMDCFE7 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE7(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE7_SHIFT)) & DCM_DCMSRR_DCMDCFE7_MASK)

#define DCM_DCMSRR_DCMDCFF7_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF7_SHIFT                (24U)
/*! DCMDCFF7 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF7(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF7_SHIFT)) & DCM_DCMSRR_DCMDCFF7_MASK)

#define DCM_DCMSRR_DCMESF7_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF7_SHIFT                 (27U)
/*! DCMESF7 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF7(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF7_SHIFT)) & DCM_DCMSRR_DCMESF7_MASK)

#define DCM_DCMSRR_DCMESD7_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD7_SHIFT                 (28U)
/*! DCMESD7 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD7(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD7_SHIFT)) & DCM_DCMSRR_DCMESD7_MASK)

#define DCM_DCMSRR_DCMDCFT7_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT7_SHIFT                (29U)
/*! DCMDCFT7 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT7(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT7_SHIFT)) & DCM_DCMSRR_DCMDCFT7_MASK)

#define DCM_DCMSRR_DCMDCFE8_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE8_SHIFT                (0U)
/*! DCMDCFE8 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE8(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE8_SHIFT)) & DCM_DCMSRR_DCMDCFE8_MASK)

#define DCM_DCMSRR_DCMDCFF8_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF8_SHIFT                (24U)
/*! DCMDCFF8 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF8(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF8_SHIFT)) & DCM_DCMSRR_DCMDCFF8_MASK)

#define DCM_DCMSRR_DCMESF8_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF8_SHIFT                 (27U)
/*! DCMESF8 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF8(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF8_SHIFT)) & DCM_DCMSRR_DCMESF8_MASK)

#define DCM_DCMSRR_DCMESD8_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD8_SHIFT                 (28U)
/*! DCMESD8 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD8(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD8_SHIFT)) & DCM_DCMSRR_DCMESD8_MASK)

#define DCM_DCMSRR_DCMDCFT8_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT8_SHIFT                (29U)
/*! DCMDCFT8 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT8(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT8_SHIFT)) & DCM_DCMSRR_DCMDCFT8_MASK)

#define DCM_DCMSRR_DCMDCFE9_MASK                 (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE9_SHIFT                (0U)
/*! DCMDCFE9 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE9(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE9_SHIFT)) & DCM_DCMSRR_DCMDCFE9_MASK)

#define DCM_DCMSRR_DCMDCFF9_MASK                 (0x7000000U)
#define DCM_DCMSRR_DCMDCFF9_SHIFT                (24U)
/*! DCMDCFF9 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF9(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF9_SHIFT)) & DCM_DCMSRR_DCMDCFF9_MASK)

#define DCM_DCMSRR_DCMESF9_MASK                  (0x8000000U)
#define DCM_DCMSRR_DCMESF9_SHIFT                 (27U)
/*! DCMESF9 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF9(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF9_SHIFT)) & DCM_DCMSRR_DCMESF9_MASK)

#define DCM_DCMSRR_DCMESD9_MASK                  (0x10000000U)
#define DCM_DCMSRR_DCMESD9_SHIFT                 (28U)
/*! DCMESD9 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD9(x)                    (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD9_SHIFT)) & DCM_DCMSRR_DCMESD9_MASK)

#define DCM_DCMSRR_DCMDCFT9_MASK                 (0x20000000U)
#define DCM_DCMSRR_DCMDCFT9_SHIFT                (29U)
/*! DCMDCFT9 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT9(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT9_SHIFT)) & DCM_DCMSRR_DCMDCFT9_MASK)

#define DCM_DCMSRR_DCMDCFE10_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE10_SHIFT               (0U)
/*! DCMDCFE10 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE10(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE10_SHIFT)) & DCM_DCMSRR_DCMDCFE10_MASK)

#define DCM_DCMSRR_DCMDCFF10_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF10_SHIFT               (24U)
/*! DCMDCFF10 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF10(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF10_SHIFT)) & DCM_DCMSRR_DCMDCFF10_MASK)

#define DCM_DCMSRR_DCMESF10_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF10_SHIFT                (27U)
/*! DCMESF10 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF10(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF10_SHIFT)) & DCM_DCMSRR_DCMESF10_MASK)

#define DCM_DCMSRR_DCMESD10_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD10_SHIFT                (28U)
/*! DCMESD10 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD10(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD10_SHIFT)) & DCM_DCMSRR_DCMESD10_MASK)

#define DCM_DCMSRR_DCMDCFT10_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT10_SHIFT               (29U)
/*! DCMDCFT10 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT10(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT10_SHIFT)) & DCM_DCMSRR_DCMDCFT10_MASK)

#define DCM_DCMSRR_DCMDCFE11_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE11_SHIFT               (0U)
/*! DCMDCFE11 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE11(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE11_SHIFT)) & DCM_DCMSRR_DCMDCFE11_MASK)

#define DCM_DCMSRR_DCMDCFF11_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF11_SHIFT               (24U)
/*! DCMDCFF11 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF11(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF11_SHIFT)) & DCM_DCMSRR_DCMDCFF11_MASK)

#define DCM_DCMSRR_DCMESF11_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF11_SHIFT                (27U)
/*! DCMESF11 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF11(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF11_SHIFT)) & DCM_DCMSRR_DCMESF11_MASK)

#define DCM_DCMSRR_DCMESD11_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD11_SHIFT                (28U)
/*! DCMESD11 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD11(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD11_SHIFT)) & DCM_DCMSRR_DCMESD11_MASK)

#define DCM_DCMSRR_DCMDCFT11_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT11_SHIFT               (29U)
/*! DCMDCFT11 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT11(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT11_SHIFT)) & DCM_DCMSRR_DCMDCFT11_MASK)

#define DCM_DCMSRR_DCMDCFE12_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE12_SHIFT               (0U)
/*! DCMDCFE12 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE12(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE12_SHIFT)) & DCM_DCMSRR_DCMDCFE12_MASK)

#define DCM_DCMSRR_DCMDCFF12_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF12_SHIFT               (24U)
/*! DCMDCFF12 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF12(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF12_SHIFT)) & DCM_DCMSRR_DCMDCFF12_MASK)

#define DCM_DCMSRR_DCMESF12_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF12_SHIFT                (27U)
/*! DCMESF12 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF12(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF12_SHIFT)) & DCM_DCMSRR_DCMESF12_MASK)

#define DCM_DCMSRR_DCMESD12_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD12_SHIFT                (28U)
/*! DCMESD12 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD12(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD12_SHIFT)) & DCM_DCMSRR_DCMESD12_MASK)

#define DCM_DCMSRR_DCMDCFT12_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT12_SHIFT               (29U)
/*! DCMDCFT12 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT12(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT12_SHIFT)) & DCM_DCMSRR_DCMDCFT12_MASK)

#define DCM_DCMSRR_DCMDCFE13_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE13_SHIFT               (0U)
/*! DCMDCFE13 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE13(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE13_SHIFT)) & DCM_DCMSRR_DCMDCFE13_MASK)

#define DCM_DCMSRR_DCMDCFF13_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF13_SHIFT               (24U)
/*! DCMDCFF13 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF13(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF13_SHIFT)) & DCM_DCMSRR_DCMDCFF13_MASK)

#define DCM_DCMSRR_DCMESF13_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF13_SHIFT                (27U)
/*! DCMESF13 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF13(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF13_SHIFT)) & DCM_DCMSRR_DCMESF13_MASK)

#define DCM_DCMSRR_DCMESD13_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD13_SHIFT                (28U)
/*! DCMESD13 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD13(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD13_SHIFT)) & DCM_DCMSRR_DCMESD13_MASK)

#define DCM_DCMSRR_DCMDCFT13_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT13_SHIFT               (29U)
/*! DCMDCFT13 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT13(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT13_SHIFT)) & DCM_DCMSRR_DCMDCFT13_MASK)

#define DCM_DCMSRR_DCMDCFE14_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE14_SHIFT               (0U)
/*! DCMDCFE14 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE14(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE14_SHIFT)) & DCM_DCMSRR_DCMDCFE14_MASK)

#define DCM_DCMSRR_DCMDCFF14_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF14_SHIFT               (24U)
/*! DCMDCFF14 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF14(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF14_SHIFT)) & DCM_DCMSRR_DCMDCFF14_MASK)

#define DCM_DCMSRR_DCMESF14_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF14_SHIFT                (27U)
/*! DCMESF14 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF14(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF14_SHIFT)) & DCM_DCMSRR_DCMESF14_MASK)

#define DCM_DCMSRR_DCMESD14_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD14_SHIFT                (28U)
/*! DCMESD14 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD14(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD14_SHIFT)) & DCM_DCMSRR_DCMESD14_MASK)

#define DCM_DCMSRR_DCMDCFT14_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT14_SHIFT               (29U)
/*! DCMDCFT14 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT14(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT14_SHIFT)) & DCM_DCMSRR_DCMDCFT14_MASK)

#define DCM_DCMSRR_DCMDCFE15_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE15_SHIFT               (0U)
/*! DCMDCFE15 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE15(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE15_SHIFT)) & DCM_DCMSRR_DCMDCFE15_MASK)

#define DCM_DCMSRR_DCMDCFF15_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF15_SHIFT               (24U)
/*! DCMDCFF15 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF15(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF15_SHIFT)) & DCM_DCMSRR_DCMDCFF15_MASK)

#define DCM_DCMSRR_DCMESF15_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF15_SHIFT                (27U)
/*! DCMESF15 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF15(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF15_SHIFT)) & DCM_DCMSRR_DCMESF15_MASK)

#define DCM_DCMSRR_DCMESD15_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD15_SHIFT                (28U)
/*! DCMESD15 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD15(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD15_SHIFT)) & DCM_DCMSRR_DCMESD15_MASK)

#define DCM_DCMSRR_DCMDCFT15_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT15_SHIFT               (29U)
/*! DCMDCFT15 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT15(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT15_SHIFT)) & DCM_DCMSRR_DCMDCFT15_MASK)

#define DCM_DCMSRR_DCMDCFE16_MASK                (0x1FFFFFU)
#define DCM_DCMSRR_DCMDCFE16_SHIFT               (0U)
/*! DCMDCFE16 - Flash Memory Address */
#define DCM_DCMSRR_DCMDCFE16(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFE16_SHIFT)) & DCM_DCMSRR_DCMDCFE16_MASK)

#define DCM_DCMSRR_DCMDCFF16_MASK                (0x7000000U)
#define DCM_DCMSRR_DCMDCFF16_SHIFT               (24U)
/*! DCMDCFF16 - DCF Record Location
 *  0b010..Utest region
 *  0b101..Others: Reserved
 */
#define DCM_DCMSRR_DCMDCFF16(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFF16_SHIFT)) & DCM_DCMSRR_DCMDCFF16_MASK)

#define DCM_DCMSRR_DCMESF16_MASK                 (0x8000000U)
#define DCM_DCMSRR_DCMESF16_SHIFT                (27U)
/*! DCMESF16 - Flash Memory Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESF16(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESF16_SHIFT)) & DCM_DCMSRR_DCMESF16_MASK)

#define DCM_DCMSRR_DCMESD16_MASK                 (0x10000000U)
#define DCM_DCMSRR_DCMESD16_SHIFT                (28U)
/*! DCMESD16 - Chip Side Error
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMSRR_DCMESD16(x)                   (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMESD16_SHIFT)) & DCM_DCMSRR_DCMESD16_MASK)

#define DCM_DCMSRR_DCMDCFT16_MASK                (0x20000000U)
#define DCM_DCMSRR_DCMDCFT16_SHIFT               (29U)
/*! DCMDCFT16 - Scanning Timeout On Flash Memory
 *  0b0..Does not exist
 *  0b1..Exists
 */
#define DCM_DCMSRR_DCMDCFT16(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMSRR_DCMDCFT16_SHIFT)) & DCM_DCMSRR_DCMDCFT16_MASK)
/*! @} */

/*! @name DCMLCS_2 - LC Scan Status 2 */
/*! @{ */

#define DCM_DCMLCS_2_DCMLCSS6_MASK               (0x1U)
#define DCM_DCMLCS_2_DCMLCSS6_SHIFT              (0U)
/*! DCMLCSS6 - FA Scan Status
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_2_DCMLCSS6(x)                 (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCSS6_SHIFT)) & DCM_DCMLCS_2_DCMLCSS6_MASK)

#define DCM_DCMLCS_2_DCMLCC6_MASK                (0xEU)
#define DCM_DCMLCS_2_DCMLCC6_SHIFT               (1U)
/*! DCMLCC6 - FA Marking
 *  0b000..Not scanned yet
 *  0b001..Marked as active
 *  0b010..Marked as inactive
 *  0b011..Region is erased/virgin
 *  0b101..Marked as inactive by an unknown pattern
 *  0b110..Scanning timed out
 */
#define DCM_DCMLCS_2_DCMLCC6(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCC6_SHIFT)) & DCM_DCMLCS_2_DCMLCC6_MASK)

#define DCM_DCMLCS_2_DCMLCE6_MASK                (0x10U)
#define DCM_DCMLCS_2_DCMLCE6_SHIFT               (4U)
/*! DCMLCE6 - FA ECC Errors
 *  0b0..No errors
 *  0b1..Errors exist
 */
#define DCM_DCMLCS_2_DCMLCE6(x)                  (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCE6_SHIFT)) & DCM_DCMLCS_2_DCMLCE6_MASK)

#define DCM_DCMLCS_2_DCMLCFE6_MASK               (0x20U)
#define DCM_DCMLCS_2_DCMLCFE6_SHIFT              (5U)
/*! DCMLCFE6 - Flash Memory Error Check
 *  0b0..Successful
 *  0b1..Failed
 */
#define DCM_DCMLCS_2_DCMLCFE6(x)                 (((uint32_t)(((uint32_t)(x)) << DCM_DCMLCS_2_DCMLCFE6_SHIFT)) & DCM_DCMLCS_2_DCMLCFE6_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DCM_Register_Masks */


/*!
 * @}
 */ /* end of group DCM_Peripheral_Access_Layer */


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


#endif  /* PERI_DCM_H_ */

