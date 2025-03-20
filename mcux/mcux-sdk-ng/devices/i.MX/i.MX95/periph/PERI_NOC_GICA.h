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
**         CMSIS Peripheral Access Layer for NOC_GICA
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
 * @file NOC_GICA.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NOC_GICA
 *
 * CMSIS Peripheral Access Layer for NOC_GICA
 */

#if !defined(NOC_GICA_H_)
#define NOC_GICA_H_                              /**< Symbol preventing repeated inclusion */

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
   -- NOC_GICA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_GICA_Peripheral_Access_Layer NOC_GICA Peripheral Access Layer
 * @{
 */

/** NOC_GICA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint64_t GICA_TYPER;                        /**< GICA_TYPER, offset: 0x8 */
       uint8_t RESERVED_1[48];
  __O  uint32_t GICA_SETSPI_NSR;                   /**< GICA_SETSPI_NSR, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __O  uint32_t GICA_CLRSPI_NSR;                   /**< GICA_CLRSPI_NSR, offset: 0x48 */
       uint8_t RESERVED_3[4];
  __O  uint32_t GICA_SETSPI_SR;                    /**< GICA_SETSPI_SR, offset: 0x50 */
       uint8_t RESERVED_4[4];
  __O  uint32_t GICA_CLRSPI_SR;                    /**< GICA_CLRSPI_SR, offset: 0x58 */
       uint8_t RESERVED_5[3952];
  __I  uint32_t GICA_IIDR;                         /**< GICA_IIDR, offset: 0xFCC */
       uint8_t RESERVED_6[61440];
  __I  uint32_t GICA_PIDR4;                        /**< GICA_PIDR4, offset: 0xFFD0 */
  __I  uint32_t GICA_PIDR5;                        /**< GICA_PIDR5, offset: 0xFFD4 */
  __I  uint32_t GICA_PIDR6;                        /**< GICA_PIDR6, offset: 0xFFD8 */
  __I  uint32_t GICA_PIDR7;                        /**< GICA_PIDR7, offset: 0xFFDC */
  __I  uint32_t GICA_PIDR0;                        /**< GICA_PIDR0, offset: 0xFFE0 */
  __I  uint32_t GICA_PIDR1;                        /**< GICA_PIDR1, offset: 0xFFE4 */
  __I  uint32_t GICA_PIDR2;                        /**< GICA_PIDR2, offset: 0xFFE8 */
  __I  uint32_t GICA_PIDR3;                        /**< GICA_PIDR3, offset: 0xFFEC */
  __I  uint32_t GICA_CIDR0;                        /**< GICA_CIDR0, offset: 0xFFF0 */
  __I  uint32_t GICA_CIDR1;                        /**< GICA_CIDR1, offset: 0xFFF4 */
  __I  uint32_t GICA_CIDR2;                        /**< GICA_CIDR2, offset: 0xFFF8 */
  __I  uint32_t GICA_CIDR3;                        /**< GICA_CIDR3, offset: 0xFFFC */
} NOC_GICA_Type;

/* ----------------------------------------------------------------------------
   -- NOC_GICA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_GICA_Register_Masks NOC_GICA Register Masks
 * @{
 */

/*! @name GICA_TYPER - GICA_TYPER */
/*! @{ */

#define NOC_GICA_GICA_TYPER_NumSPIs_MASK         (0x7FFU)
#define NOC_GICA_GICA_TYPER_NumSPIs_SHIFT        (0U)
/*! NumSPIs - NumSPIs */
#define NOC_GICA_GICA_TYPER_NumSPIs(x)           (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_NumSPIs_SHIFT)) & NOC_GICA_GICA_TYPER_NumSPIs_MASK)

#define NOC_GICA_GICA_TYPER_RESERVED0_MASK       (0xF800U)
#define NOC_GICA_GICA_TYPER_RESERVED0_SHIFT      (11U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_TYPER_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_RESERVED0_SHIFT)) & NOC_GICA_GICA_TYPER_RESERVED0_MASK)

#define NOC_GICA_GICA_TYPER_INTID_MASK           (0x1FFF0000U)
#define NOC_GICA_GICA_TYPER_INTID_SHIFT          (16U)
/*! INTID - INTID */
#define NOC_GICA_GICA_TYPER_INTID(x)             (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_INTID_SHIFT)) & NOC_GICA_GICA_TYPER_INTID_MASK)

#define NOC_GICA_GICA_TYPER_SR_MASK              (0x20000000U)
#define NOC_GICA_GICA_TYPER_SR_SHIFT             (29U)
/*! SR - SR */
#define NOC_GICA_GICA_TYPER_SR(x)                (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_SR_SHIFT)) & NOC_GICA_GICA_TYPER_SR_MASK)

#define NOC_GICA_GICA_TYPER_CLR_MASK             (0x40000000U)
#define NOC_GICA_GICA_TYPER_CLR_SHIFT            (30U)
/*! CLR - CLR */
#define NOC_GICA_GICA_TYPER_CLR(x)               (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_CLR_SHIFT)) & NOC_GICA_GICA_TYPER_CLR_MASK)

#define NOC_GICA_GICA_TYPER_Valid_MASK           (0x80000000U)
#define NOC_GICA_GICA_TYPER_Valid_SHIFT          (31U)
/*! Valid - Valid */
#define NOC_GICA_GICA_TYPER_Valid(x)             (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_Valid_SHIFT)) & NOC_GICA_GICA_TYPER_Valid_MASK)

#define NOC_GICA_GICA_TYPER_RESERVED1_MASK       (0xFFFFFFFF00000000U)
#define NOC_GICA_GICA_TYPER_RESERVED1_SHIFT      (32U)
/*! RESERVED1 - RESERVED1 */
#define NOC_GICA_GICA_TYPER_RESERVED1(x)         (((uint64_t)(((uint64_t)(x)) << NOC_GICA_GICA_TYPER_RESERVED1_SHIFT)) & NOC_GICA_GICA_TYPER_RESERVED1_MASK)
/*! @} */

/*! @name GICA_SETSPI_NSR - GICA_SETSPI_NSR */
/*! @{ */

#define NOC_GICA_GICA_SETSPI_NSR_ID_MASK         (0xFFFFU)
#define NOC_GICA_GICA_SETSPI_NSR_ID_SHIFT        (0U)
/*! ID - ID */
#define NOC_GICA_GICA_SETSPI_NSR_ID(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_SETSPI_NSR_ID_SHIFT)) & NOC_GICA_GICA_SETSPI_NSR_ID_MASK)

#define NOC_GICA_GICA_SETSPI_NSR_RESERVED0_MASK  (0xFFFF0000U)
#define NOC_GICA_GICA_SETSPI_NSR_RESERVED0_SHIFT (16U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_SETSPI_NSR_RESERVED0(x)    (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_SETSPI_NSR_RESERVED0_SHIFT)) & NOC_GICA_GICA_SETSPI_NSR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CLRSPI_NSR - GICA_CLRSPI_NSR */
/*! @{ */

#define NOC_GICA_GICA_CLRSPI_NSR_ID_MASK         (0xFFFFU)
#define NOC_GICA_GICA_CLRSPI_NSR_ID_SHIFT        (0U)
/*! ID - ID */
#define NOC_GICA_GICA_CLRSPI_NSR_ID(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CLRSPI_NSR_ID_SHIFT)) & NOC_GICA_GICA_CLRSPI_NSR_ID_MASK)

#define NOC_GICA_GICA_CLRSPI_NSR_RESERVED0_MASK  (0xFFFF0000U)
#define NOC_GICA_GICA_CLRSPI_NSR_RESERVED0_SHIFT (16U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_CLRSPI_NSR_RESERVED0(x)    (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CLRSPI_NSR_RESERVED0_SHIFT)) & NOC_GICA_GICA_CLRSPI_NSR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_SETSPI_SR - GICA_SETSPI_SR */
/*! @{ */

#define NOC_GICA_GICA_SETSPI_SR_ID_MASK          (0xFFFFU)
#define NOC_GICA_GICA_SETSPI_SR_ID_SHIFT         (0U)
/*! ID - ID */
#define NOC_GICA_GICA_SETSPI_SR_ID(x)            (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_SETSPI_SR_ID_SHIFT)) & NOC_GICA_GICA_SETSPI_SR_ID_MASK)

#define NOC_GICA_GICA_SETSPI_SR_RESERVED0_MASK   (0xFFFF0000U)
#define NOC_GICA_GICA_SETSPI_SR_RESERVED0_SHIFT  (16U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_SETSPI_SR_RESERVED0(x)     (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_SETSPI_SR_RESERVED0_SHIFT)) & NOC_GICA_GICA_SETSPI_SR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CLRSPI_SR - GICA_CLRSPI_SR */
/*! @{ */

#define NOC_GICA_GICA_CLRSPI_SR_ID_MASK          (0xFFFFU)
#define NOC_GICA_GICA_CLRSPI_SR_ID_SHIFT         (0U)
/*! ID - ID */
#define NOC_GICA_GICA_CLRSPI_SR_ID(x)            (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CLRSPI_SR_ID_SHIFT)) & NOC_GICA_GICA_CLRSPI_SR_ID_MASK)

#define NOC_GICA_GICA_CLRSPI_SR_RESERVED0_MASK   (0xFFFF0000U)
#define NOC_GICA_GICA_CLRSPI_SR_RESERVED0_SHIFT  (16U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_CLRSPI_SR_RESERVED0(x)     (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CLRSPI_SR_RESERVED0_SHIFT)) & NOC_GICA_GICA_CLRSPI_SR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_IIDR - GICA_IIDR */
/*! @{ */

#define NOC_GICA_GICA_IIDR_Implementer_MASK      (0xFFFU)
#define NOC_GICA_GICA_IIDR_Implementer_SHIFT     (0U)
/*! Implementer - Implementer */
#define NOC_GICA_GICA_IIDR_Implementer(x)        (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_IIDR_Implementer_SHIFT)) & NOC_GICA_GICA_IIDR_Implementer_MASK)

#define NOC_GICA_GICA_IIDR_Revision_MASK         (0xF000U)
#define NOC_GICA_GICA_IIDR_Revision_SHIFT        (12U)
/*! Revision - Revision */
#define NOC_GICA_GICA_IIDR_Revision(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_IIDR_Revision_SHIFT)) & NOC_GICA_GICA_IIDR_Revision_MASK)

#define NOC_GICA_GICA_IIDR_Variant_MASK          (0xF0000U)
#define NOC_GICA_GICA_IIDR_Variant_SHIFT         (16U)
/*! Variant - Variant */
#define NOC_GICA_GICA_IIDR_Variant(x)            (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_IIDR_Variant_SHIFT)) & NOC_GICA_GICA_IIDR_Variant_MASK)

#define NOC_GICA_GICA_IIDR_RESERVED0_MASK        (0xF00000U)
#define NOC_GICA_GICA_IIDR_RESERVED0_SHIFT       (20U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_IIDR_RESERVED0(x)          (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_IIDR_RESERVED0_SHIFT)) & NOC_GICA_GICA_IIDR_RESERVED0_MASK)

#define NOC_GICA_GICA_IIDR_ProductID_MASK        (0xFF000000U)
#define NOC_GICA_GICA_IIDR_ProductID_SHIFT       (24U)
/*! ProductID - ProductID */
#define NOC_GICA_GICA_IIDR_ProductID(x)          (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_IIDR_ProductID_SHIFT)) & NOC_GICA_GICA_IIDR_ProductID_MASK)
/*! @} */

/*! @name GICA_PIDR4 - GICA_PIDR4 */
/*! @{ */

#define NOC_GICA_GICA_PIDR4_DES_2_MASK           (0xFU)
#define NOC_GICA_GICA_PIDR4_DES_2_SHIFT          (0U)
/*! DES_2 - DES_2 */
#define NOC_GICA_GICA_PIDR4_DES_2(x)             (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR4_DES_2_SHIFT)) & NOC_GICA_GICA_PIDR4_DES_2_MASK)

#define NOC_GICA_GICA_PIDR4_SIZE_MASK            (0xF0U)
#define NOC_GICA_GICA_PIDR4_SIZE_SHIFT           (4U)
/*! SIZE - SIZE */
#define NOC_GICA_GICA_PIDR4_SIZE(x)              (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR4_SIZE_SHIFT)) & NOC_GICA_GICA_PIDR4_SIZE_MASK)

#define NOC_GICA_GICA_PIDR4_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR4_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR4_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR4_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR4_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR5 - GICA_PIDR5 */
/*! @{ */

#define NOC_GICA_GICA_PIDR5_RESERVED_MASK        (0xFFU)
#define NOC_GICA_GICA_PIDR5_RESERVED_SHIFT       (0U)
/*! RESERVED - RESERVED */
#define NOC_GICA_GICA_PIDR5_RESERVED(x)          (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR5_RESERVED_SHIFT)) & NOC_GICA_GICA_PIDR5_RESERVED_MASK)

#define NOC_GICA_GICA_PIDR5_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR5_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR5_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR5_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR5_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR6 - GICA_PIDR6 */
/*! @{ */

#define NOC_GICA_GICA_PIDR6_RESERVED_MASK        (0xFFU)
#define NOC_GICA_GICA_PIDR6_RESERVED_SHIFT       (0U)
/*! RESERVED - RESERVED */
#define NOC_GICA_GICA_PIDR6_RESERVED(x)          (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR6_RESERVED_SHIFT)) & NOC_GICA_GICA_PIDR6_RESERVED_MASK)

#define NOC_GICA_GICA_PIDR6_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR6_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR6_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR6_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR6_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR7 - GICA_PIDR7 */
/*! @{ */

#define NOC_GICA_GICA_PIDR7_RESERVED_MASK        (0xFFU)
#define NOC_GICA_GICA_PIDR7_RESERVED_SHIFT       (0U)
/*! RESERVED - RESERVED */
#define NOC_GICA_GICA_PIDR7_RESERVED(x)          (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR7_RESERVED_SHIFT)) & NOC_GICA_GICA_PIDR7_RESERVED_MASK)

#define NOC_GICA_GICA_PIDR7_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR7_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR7_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR7_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR7_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR0 - GICA_PIDR0 */
/*! @{ */

#define NOC_GICA_GICA_PIDR0_PART_0_MASK          (0xFFU)
#define NOC_GICA_GICA_PIDR0_PART_0_SHIFT         (0U)
/*! PART_0 - PART_0 */
#define NOC_GICA_GICA_PIDR0_PART_0(x)            (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR0_PART_0_SHIFT)) & NOC_GICA_GICA_PIDR0_PART_0_MASK)

#define NOC_GICA_GICA_PIDR0_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR0_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR0_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR0_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR1 - GICA_PIDR1 */
/*! @{ */

#define NOC_GICA_GICA_PIDR1_PART_1_MASK          (0xFU)
#define NOC_GICA_GICA_PIDR1_PART_1_SHIFT         (0U)
/*! PART_1 - PART_1 */
#define NOC_GICA_GICA_PIDR1_PART_1(x)            (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR1_PART_1_SHIFT)) & NOC_GICA_GICA_PIDR1_PART_1_MASK)

#define NOC_GICA_GICA_PIDR1_DES_0_MASK           (0xF0U)
#define NOC_GICA_GICA_PIDR1_DES_0_SHIFT          (4U)
/*! DES_0 - DES_0 */
#define NOC_GICA_GICA_PIDR1_DES_0(x)             (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR1_DES_0_SHIFT)) & NOC_GICA_GICA_PIDR1_DES_0_MASK)

#define NOC_GICA_GICA_PIDR1_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR1_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR1_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR1_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR2 - GICA_PIDR2 */
/*! @{ */

#define NOC_GICA_GICA_PIDR2_DES_1_MASK           (0x7U)
#define NOC_GICA_GICA_PIDR2_DES_1_SHIFT          (0U)
/*! DES_1 - DES_1 */
#define NOC_GICA_GICA_PIDR2_DES_1(x)             (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR2_DES_1_SHIFT)) & NOC_GICA_GICA_PIDR2_DES_1_MASK)

#define NOC_GICA_GICA_PIDR2_JEDEC_MASK           (0x8U)
#define NOC_GICA_GICA_PIDR2_JEDEC_SHIFT          (3U)
/*! JEDEC - JEDEC */
#define NOC_GICA_GICA_PIDR2_JEDEC(x)             (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR2_JEDEC_SHIFT)) & NOC_GICA_GICA_PIDR2_JEDEC_MASK)

#define NOC_GICA_GICA_PIDR2_REVISION_MASK        (0xF0U)
#define NOC_GICA_GICA_PIDR2_REVISION_SHIFT       (4U)
/*! REVISION - REVISION */
#define NOC_GICA_GICA_PIDR2_REVISION(x)          (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR2_REVISION_SHIFT)) & NOC_GICA_GICA_PIDR2_REVISION_MASK)

#define NOC_GICA_GICA_PIDR2_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR2_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR2_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR2_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICA_PIDR3 - GICA_PIDR3 */
/*! @{ */

#define NOC_GICA_GICA_PIDR3_CMOD_MASK            (0x7U)
#define NOC_GICA_GICA_PIDR3_CMOD_SHIFT           (0U)
/*! CMOD - CMOD */
#define NOC_GICA_GICA_PIDR3_CMOD(x)              (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR3_CMOD_SHIFT)) & NOC_GICA_GICA_PIDR3_CMOD_MASK)

#define NOC_GICA_GICA_PIDR3_RESERVED0_MASK       (0x8U)
#define NOC_GICA_GICA_PIDR3_RESERVED0_SHIFT      (3U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_PIDR3_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR3_RESERVED0_SHIFT)) & NOC_GICA_GICA_PIDR3_RESERVED0_MASK)

#define NOC_GICA_GICA_PIDR3_REVAND_MASK          (0xF0U)
#define NOC_GICA_GICA_PIDR3_REVAND_SHIFT         (4U)
/*! REVAND - REVAND */
#define NOC_GICA_GICA_PIDR3_REVAND(x)            (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR3_REVAND_SHIFT)) & NOC_GICA_GICA_PIDR3_REVAND_MASK)

#define NOC_GICA_GICA_PIDR3_RESERVED1_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_PIDR3_RESERVED1_SHIFT      (8U)
/*! RESERVED1 - RESERVED1 */
#define NOC_GICA_GICA_PIDR3_RESERVED1(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_PIDR3_RESERVED1_SHIFT)) & NOC_GICA_GICA_PIDR3_RESERVED1_MASK)
/*! @} */

/*! @name GICA_CIDR0 - GICA_CIDR0 */
/*! @{ */

#define NOC_GICA_GICA_CIDR0_PRMBL_0_MASK         (0xFFU)
#define NOC_GICA_GICA_CIDR0_PRMBL_0_SHIFT        (0U)
/*! PRMBL_0 - PRMBL_0 */
#define NOC_GICA_GICA_CIDR0_PRMBL_0(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR0_PRMBL_0_SHIFT)) & NOC_GICA_GICA_CIDR0_PRMBL_0_MASK)

#define NOC_GICA_GICA_CIDR0_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_CIDR0_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_CIDR0_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR0_RESERVED0_SHIFT)) & NOC_GICA_GICA_CIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CIDR1 - GICA_CIDR1 */
/*! @{ */

#define NOC_GICA_GICA_CIDR1_PRMBL_1_MASK         (0xFU)
#define NOC_GICA_GICA_CIDR1_PRMBL_1_SHIFT        (0U)
/*! PRMBL_1 - PRMBL_1 */
#define NOC_GICA_GICA_CIDR1_PRMBL_1(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR1_PRMBL_1_SHIFT)) & NOC_GICA_GICA_CIDR1_PRMBL_1_MASK)

#define NOC_GICA_GICA_CIDR1_CLASS_MASK           (0xF0U)
#define NOC_GICA_GICA_CIDR1_CLASS_SHIFT          (4U)
/*! CLASS - CLASS */
#define NOC_GICA_GICA_CIDR1_CLASS(x)             (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR1_CLASS_SHIFT)) & NOC_GICA_GICA_CIDR1_CLASS_MASK)

#define NOC_GICA_GICA_CIDR1_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_CIDR1_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_CIDR1_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR1_RESERVED0_SHIFT)) & NOC_GICA_GICA_CIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CIDR2 - GICA_CIDR2 */
/*! @{ */

#define NOC_GICA_GICA_CIDR2_PRMBL_2_MASK         (0xFFU)
#define NOC_GICA_GICA_CIDR2_PRMBL_2_SHIFT        (0U)
/*! PRMBL_2 - PRMBL_2 */
#define NOC_GICA_GICA_CIDR2_PRMBL_2(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR2_PRMBL_2_SHIFT)) & NOC_GICA_GICA_CIDR2_PRMBL_2_MASK)

#define NOC_GICA_GICA_CIDR2_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_CIDR2_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_CIDR2_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR2_RESERVED0_SHIFT)) & NOC_GICA_GICA_CIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CIDR3 - GICA_CIDR3 */
/*! @{ */

#define NOC_GICA_GICA_CIDR3_PRMBL_3_MASK         (0xFFU)
#define NOC_GICA_GICA_CIDR3_PRMBL_3_SHIFT        (0U)
/*! PRMBL_3 - PRMBL_3 */
#define NOC_GICA_GICA_CIDR3_PRMBL_3(x)           (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR3_PRMBL_3_SHIFT)) & NOC_GICA_GICA_CIDR3_PRMBL_3_MASK)

#define NOC_GICA_GICA_CIDR3_RESERVED0_MASK       (0xFFFFFF00U)
#define NOC_GICA_GICA_CIDR3_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define NOC_GICA_GICA_CIDR3_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << NOC_GICA_GICA_CIDR3_RESERVED0_SHIFT)) & NOC_GICA_GICA_CIDR3_RESERVED0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NOC_GICA_Register_Masks */


/*!
 * @}
 */ /* end of group NOC_GICA_Peripheral_Access_Layer */


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


#endif  /* NOC_GICA_H_ */

