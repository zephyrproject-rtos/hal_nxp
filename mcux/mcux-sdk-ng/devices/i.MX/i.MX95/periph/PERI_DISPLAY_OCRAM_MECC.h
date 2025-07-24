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
**         CMSIS Peripheral Access Layer for DISPLAY_OCRAM_MECC
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
 * @file DISPLAY_OCRAM_MECC.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DISPLAY_OCRAM_MECC
 *
 * CMSIS Peripheral Access Layer for DISPLAY_OCRAM_MECC
 */

#if !defined(DISPLAY_OCRAM_MECC_H_)
#define DISPLAY_OCRAM_MECC_H_                    /**< Symbol preventing repeated inclusion */

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
   -- DISPLAY_OCRAM_MECC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_OCRAM_MECC_Peripheral_Access_Layer DISPLAY_OCRAM_MECC Peripheral Access Layer
 * @{
 */

/** DISPLAY_OCRAM_MECC - Register Layout Typedef */
typedef struct {
  __IO uint32_t RAMCR;                             /**< RAM Control, offset: 0x0 */
  __IO uint32_t RAMIAS;                            /**< RAM Initialization Address Start, offset: 0x4 */
  __IO uint32_t RAMIAE;                            /**< RAM Initialization Address End, offset: 0x8 */
  __IO uint32_t RAMSR;                             /**< RAM Status, offset: 0xC */
  __I  uint32_t RAMMEMA;                           /**< RAM ECC Address, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __I  uint32_t RAMSYSA;                           /**< RAM System Address, offset: 0x18 */
  __IO uint32_t RAMECCNT;                          /**< RAM Correctable Error Count, offset: 0x1C */
  __IO uint32_t RAMEID0;                           /**< RAM Error Injection Data 0, offset: 0x20 */
  __IO uint32_t RAMEID1;                           /**< RAM Error Injection Data 1, offset: 0x24 */
  __IO uint32_t RAMEIDC;                           /**< RAM Error Injection Data Control, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t RAMEIA;                            /**< RAM Error Injection Base Address, offset: 0x30 */
  __IO uint32_t RAMEIAM;                           /**< RAM Error Injection Address Mask, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t RAMMAXA;                           /**< RAM Maximum-Value Address, offset: 0x40 */
       uint8_t RESERVED_3[60];
  __IO uint32_t RAMCR2;                            /**< RAM Control 2, offset: 0x80 */
} DISPLAY_OCRAM_MECC_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_OCRAM_MECC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_OCRAM_MECC_Register_Masks DISPLAY_OCRAM_MECC Register Masks
 * @{
 */

/*! @name RAMCR - RAM Control */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMCR_INIT_MASK       (0x1U)
#define DISPLAY_OCRAM_MECC_RAMCR_INIT_SHIFT      (0U)
/*! INIT - Initialization Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define DISPLAY_OCRAM_MECC_RAMCR_INIT(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMCR_INIT_SHIFT)) & DISPLAY_OCRAM_MECC_RAMCR_INIT_MASK)

#define DISPLAY_OCRAM_MECC_RAMCR_IWS_MASK        (0x6U)
#define DISPLAY_OCRAM_MECC_RAMCR_IWS_SHIFT       (1U)
/*! IWS - Initialization Wait States
 *  0b00..Zero
 *  0b01..One
 *  0b10..Two
 *  0b11..Three
 */
#define DISPLAY_OCRAM_MECC_RAMCR_IWS(x)          (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMCR_IWS_SHIFT)) & DISPLAY_OCRAM_MECC_RAMCR_IWS_MASK)

#define DISPLAY_OCRAM_MECC_RAMCR_INIT_SYSA_MASK  (0x100U)
#define DISPLAY_OCRAM_MECC_RAMCR_INIT_SYSA_SHIFT (8U)
/*! INIT_SYSA - Initialize With System Address
 *  0b0..Local
 *  0b1..System
 */
#define DISPLAY_OCRAM_MECC_RAMCR_INIT_SYSA(x)    (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMCR_INIT_SYSA_SHIFT)) & DISPLAY_OCRAM_MECC_RAMCR_INIT_SYSA_MASK)
/*! @} */

/*! @name RAMIAS - RAM Initialization Address Start */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMIAS_IAS_MASK       (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMIAS_IAS_SHIFT      (0U)
/*! IAS - Initialization Address Start */
#define DISPLAY_OCRAM_MECC_RAMIAS_IAS(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMIAS_IAS_SHIFT)) & DISPLAY_OCRAM_MECC_RAMIAS_IAS_MASK)
/*! @} */

/*! @name RAMIAE - RAM Initialization Address End */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMIAE_IAE_MASK       (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMIAE_IAE_SHIFT      (0U)
/*! IAE - Initialization Address End */
#define DISPLAY_OCRAM_MECC_RAMIAE_IAE(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMIAE_IAE_SHIFT)) & DISPLAY_OCRAM_MECC_RAMIAE_IAE_MASK)
/*! @} */

/*! @name RAMSR - RAM Status */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMSR_IDONE_MASK      (0x1U)
#define DISPLAY_OCRAM_MECC_RAMSR_IDONE_SHIFT     (0U)
/*! IDONE - Initialization Done
 *  0b0..An initialization was not requested, is in progress, or did not complete
 *  0b1..An initialization completed successfully
 */
#define DISPLAY_OCRAM_MECC_RAMSR_IDONE(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_IDONE_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_IDONE_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_BUSERR_MASK     (0x2U)
#define DISPLAY_OCRAM_MECC_RAMSR_BUSERR_SHIFT    (1U)
/*! BUSERR - Bus Error
 *  0b0..No error occurred since the last time this field was cleared
 *  0b1..An error occurred
 */
#define DISPLAY_OCRAM_MECC_RAMSR_BUSERR(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_BUSERR_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_BUSERR_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_IPEND_MASK      (0x4U)
#define DISPLAY_OCRAM_MECC_RAMSR_IPEND_SHIFT     (2U)
/*! IPEND - Initialization Pending
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define DISPLAY_OCRAM_MECC_RAMSR_IPEND(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_IPEND_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_IPEND_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_AVALID_MASK     (0x8U)
#define DISPLAY_OCRAM_MECC_RAMSR_AVALID_SHIFT    (3U)
/*! AVALID - Addresses Valid
 *  0b0..Addresses do not correspond to an event
 *  0b1..Addresses correspond to an event
 */
#define DISPLAY_OCRAM_MECC_RAMSR_AVALID(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_AVALID_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_AVALID_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_AERR_MASK       (0x20U)
#define DISPLAY_OCRAM_MECC_RAMSR_AERR_SHIFT      (5U)
/*! AERR - ECC Address Error
 *  0b0..No error occurred
 *  0b1..An error occurred
 */
#define DISPLAY_OCRAM_MECC_RAMSR_AERR(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_AERR_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_AERR_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_MLTERR_MASK     (0x40U)
#define DISPLAY_OCRAM_MECC_RAMSR_MLTERR_SHIFT    (6U)
/*! MLTERR - ECC Multi-Bit Error
 *  0b0..No error occurred
 *  0b1..An error occurred
 */
#define DISPLAY_OCRAM_MECC_RAMSR_MLTERR(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_MLTERR_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_MLTERR_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_SGLERR_MASK     (0x80U)
#define DISPLAY_OCRAM_MECC_RAMSR_SGLERR_SHIFT    (7U)
/*! SGLERR - ECC Single-Bit Error
 *  0b0..No error occurred
 *  0b1..An error occurred
 */
#define DISPLAY_OCRAM_MECC_RAMSR_SGLERR(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_SGLERR_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_SGLERR_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_SYND_MASK       (0xFF00U)
#define DISPLAY_OCRAM_MECC_RAMSR_SYND_SHIFT      (8U)
/*! SYND - ECC Syndrome Value */
#define DISPLAY_OCRAM_MECC_RAMSR_SYND(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_SYND_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_SYND_MASK)

#define DISPLAY_OCRAM_MECC_RAMSR_EINFO_MASK      (0xFF0000U)
#define DISPLAY_OCRAM_MECC_RAMSR_EINFO_SHIFT     (16U)
/*! EINFO - Event Information */
#define DISPLAY_OCRAM_MECC_RAMSR_EINFO(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSR_EINFO_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSR_EINFO_MASK)
/*! @} */

/*! @name RAMMEMA - RAM ECC Address */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMMEMA_MEMA_MASK     (0x1FFFFU)
#define DISPLAY_OCRAM_MECC_RAMMEMA_MEMA_SHIFT    (0U)
/*! MEMA - RAM Bank Address */
#define DISPLAY_OCRAM_MECC_RAMMEMA_MEMA(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMMEMA_MEMA_SHIFT)) & DISPLAY_OCRAM_MECC_RAMMEMA_MEMA_MASK)

#define DISPLAY_OCRAM_MECC_RAMMEMA_BANK_MASK     (0x1F00000U)
#define DISPLAY_OCRAM_MECC_RAMMEMA_BANK_SHIFT    (20U)
/*! BANK - RAM Bank ID */
#define DISPLAY_OCRAM_MECC_RAMMEMA_BANK(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMMEMA_BANK_SHIFT)) & DISPLAY_OCRAM_MECC_RAMMEMA_BANK_MASK)
/*! @} */

/*! @name RAMSYSA - RAM System Address */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMSYSA_SYSA_MASK     (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMSYSA_SYSA_SHIFT    (0U)
/*! SYSA - System Address */
#define DISPLAY_OCRAM_MECC_RAMSYSA_SYSA(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMSYSA_SYSA_SHIFT)) & DISPLAY_OCRAM_MECC_RAMSYSA_SYSA_MASK)
/*! @} */

/*! @name RAMECCNT - RAM Correctable Error Count */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMECCNT_ECCNT_MASK   (0xFFU)
#define DISPLAY_OCRAM_MECC_RAMECCNT_ECCNT_SHIFT  (0U)
/*! ECCNT - ECC Correctable Error Count */
#define DISPLAY_OCRAM_MECC_RAMECCNT_ECCNT(x)     (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMECCNT_ECCNT_SHIFT)) & DISPLAY_OCRAM_MECC_RAMECCNT_ECCNT_MASK)
/*! @} */

/*! @name RAMEID0 - RAM Error Injection Data 0 */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMEID0_EID_W0_MASK   (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMEID0_EID_W0_SHIFT  (0U)
/*! EID_W0 - Error Injection Data Word 0 */
#define DISPLAY_OCRAM_MECC_RAMEID0_EID_W0(x)     (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEID0_EID_W0_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEID0_EID_W0_MASK)
/*! @} */

/*! @name RAMEID1 - RAM Error Injection Data 1 */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMEID1_EID_W1_MASK   (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMEID1_EID_W1_SHIFT  (0U)
/*! EID_W1 - Error Injection Data Word 1 */
#define DISPLAY_OCRAM_MECC_RAMEID1_EID_W1(x)     (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEID1_EID_W1_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEID1_EID_W1_MASK)
/*! @} */

/*! @name RAMEIDC - RAM Error Injection Data Control */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMEIDC_EID_CKB_MASK  (0xFFU)
#define DISPLAY_OCRAM_MECC_RAMEIDC_EID_CKB_SHIFT (0U)
/*! EID_CKB - Error Injection Data Checkbits */
#define DISPLAY_OCRAM_MECC_RAMEIDC_EID_CKB(x)    (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEIDC_EID_CKB_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEIDC_EID_CKB_MASK)

#define DISPLAY_OCRAM_MECC_RAMEIDC_EIP_EN_MASK   (0x1000000U)
#define DISPLAY_OCRAM_MECC_RAMEIDC_EIP_EN_SHIFT  (24U)
/*! EIP_EN - Error Injection Into Pipeline Enable
 *  0b0..No error injected
 *  0b1..Error injected
 */
#define DISPLAY_OCRAM_MECC_RAMEIDC_EIP_EN(x)     (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEIDC_EIP_EN_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEIDC_EIP_EN_MASK)

#define DISPLAY_OCRAM_MECC_RAMEIDC_EIA_EN_MASK   (0x40000000U)
#define DISPLAY_OCRAM_MECC_RAMEIDC_EIA_EN_SHIFT  (30U)
/*! EIA_EN - Error Injection Address Enable
 *  0b0..Ignore RAMEIA and RAMEIAM
 *  0b1..Enable RAMEIA and RAMEIAM
 */
#define DISPLAY_OCRAM_MECC_RAMEIDC_EIA_EN(x)     (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEIDC_EIA_EN_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEIDC_EIA_EN_MASK)

#define DISPLAY_OCRAM_MECC_RAMEIDC_EID_EN_MASK   (0x80000000U)
#define DISPLAY_OCRAM_MECC_RAMEIDC_EID_EN_SHIFT  (31U)
/*! EID_EN - Error Injection Data Enable
 *  0b0..No injection
 *  0b1..Local injection
 */
#define DISPLAY_OCRAM_MECC_RAMEIDC_EID_EN(x)     (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEIDC_EID_EN_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEIDC_EID_EN_MASK)
/*! @} */

/*! @name RAMEIA - RAM Error Injection Base Address */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMEIA_EIA_MASK       (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMEIA_EIA_SHIFT      (0U)
/*! EIA - Error Injection Base Address */
#define DISPLAY_OCRAM_MECC_RAMEIA_EIA(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEIA_EIA_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEIA_EIA_MASK)
/*! @} */

/*! @name RAMEIAM - RAM Error Injection Address Mask */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMEIAM_EIAM_MASK     (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMEIAM_EIAM_SHIFT    (0U)
/*! EIAM - Error Injection Address Mask */
#define DISPLAY_OCRAM_MECC_RAMEIAM_EIAM(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMEIAM_EIAM_SHIFT)) & DISPLAY_OCRAM_MECC_RAMEIAM_EIAM_MASK)
/*! @} */

/*! @name RAMMAXA - RAM Maximum-Value Address */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMMAXA_MAXA_MASK     (0xFFFFFFFFU)
#define DISPLAY_OCRAM_MECC_RAMMAXA_MAXA_SHIFT    (0U)
/*! MAXA - Maximum Address */
#define DISPLAY_OCRAM_MECC_RAMMAXA_MAXA(x)       (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMMAXA_MAXA_SHIFT)) & DISPLAY_OCRAM_MECC_RAMMAXA_MAXA_MASK)
/*! @} */

/*! @name RAMCR2 - RAM Control 2 */
/*! @{ */

#define DISPLAY_OCRAM_MECC_RAMCR2_WBUF_MASK      (0x6U)
#define DISPLAY_OCRAM_MECC_RAMCR2_WBUF_SHIFT     (1U)
/*! WBUF - Write Buffer Control
 *  0b00..Disable write buffer for all write transactions
 *  0b01..Enable write buffer for write transactions that come with a bus attribute that allows writes to be buffered and merged
 *  0b10..Enable write buffer for write transactions that are not exclusive writes
 *  0b11..Reserved
 */
#define DISPLAY_OCRAM_MECC_RAMCR2_WBUF(x)        (((uint32_t)(((uint32_t)(x)) << DISPLAY_OCRAM_MECC_RAMCR2_WBUF_SHIFT)) & DISPLAY_OCRAM_MECC_RAMCR2_WBUF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_OCRAM_MECC_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_OCRAM_MECC_Peripheral_Access_Layer */


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


#endif  /* DISPLAY_OCRAM_MECC_H_ */

