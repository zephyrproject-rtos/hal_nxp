/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GICRlpi0
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_GICRlpi0.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for GICRlpi0
 *
 * CMSIS Peripheral Access Layer for GICRlpi0
 */

#if !defined(PERI_GICRLPI0_H_)
#define PERI_GICRLPI0_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- GICRlpi0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICRlpi0_Peripheral_Access_Layer GICRlpi0 Peripheral Access Layer
 * @{
 */

/** GICRlpi0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t GICR0_CTLR;                        /**< GICR0_CTLR, offset: 0x0 */
  __I  uint32_t GICR0_IIDR;                        /**< GICR0_IIDR, offset: 0x4 */
  __I  uint64_t GICR0_TYPER;                       /**< GICR0_TYPER, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t GICR0_WAKER;                       /**< GICR0_WAKER, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GICR0_FCTLR;                       /**< GICR0_FCTLR, offset: 0x20 */
  __IO uint32_t GICR0_PWRR;                        /**< GICR0_PWRR, offset: 0x24 */
  __IO uint32_t GICR0_CLASS;                       /**< GICR0_CLASS, offset: 0x28 */
       uint8_t RESERVED_2[65444];
  __I  uint32_t GICR0_PIDR4;                       /**< GICR0_PIDR4, offset: 0xFFD0 */
  __I  uint32_t GICR0_PIDR5;                       /**< GICR0_PIDR5, offset: 0xFFD4 */
  __I  uint32_t GICR0_PIDR6;                       /**< GICR0_PIDR6, offset: 0xFFD8 */
  __I  uint32_t GICR0_PIDR7;                       /**< GICR0_PIDR7, offset: 0xFFDC */
  __I  uint32_t GICR0_PIDR0;                       /**< GICR0_PIDR0, offset: 0xFFE0 */
  __I  uint32_t GICR0_PIDR1;                       /**< GICR0_PIDR1, offset: 0xFFE4 */
  __I  uint32_t GICR0_PIDR2;                       /**< GICR0_PIDR2, offset: 0xFFE8 */
  __I  uint32_t GICR0_PIDR3;                       /**< GICR0_PIDR3, offset: 0xFFEC */
  __I  uint32_t GICR0_CIDR0;                       /**< GICR0_CIDR0, offset: 0xFFF0 */
  __I  uint32_t GICR0_CIDR1;                       /**< GICR0_CIDR1, offset: 0xFFF4 */
  __I  uint32_t GICR0_CIDR2;                       /**< GICR0_CIDR2, offset: 0xFFF8 */
  __I  uint32_t GICR0_CIDR3;                       /**< GICR0_CIDR3, offset: 0xFFFC */
} GICRlpi0_Type;

/* ----------------------------------------------------------------------------
   -- GICRlpi0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICRlpi0_Register_Masks GICRlpi0 Register Masks
 * @{
 */

/*! @name GICR0_CTLR - GICR0_CTLR */
/*! @{ */

#define GICRlpi0_GICR0_CTLR_EnableLPIs_MASK      (0x1U)
#define GICRlpi0_GICR0_CTLR_EnableLPIs_SHIFT     (0U)
/*! EnableLPIs - EnableLPIs */
#define GICRlpi0_GICR0_CTLR_EnableLPIs(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_EnableLPIs_SHIFT)) & GICRlpi0_GICR0_CTLR_EnableLPIs_MASK)

#define GICRlpi0_GICR0_CTLR_RESERVED0_MASK       (0x6U)
#define GICRlpi0_GICR0_CTLR_RESERVED0_SHIFT      (1U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_CTLR_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_RESERVED0_SHIFT)) & GICRlpi0_GICR0_CTLR_RESERVED0_MASK)

#define GICRlpi0_GICR0_CTLR_RWP_MASK             (0x8U)
#define GICRlpi0_GICR0_CTLR_RWP_SHIFT            (3U)
/*! RWP - RWP */
#define GICRlpi0_GICR0_CTLR_RWP(x)               (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_RWP_SHIFT)) & GICRlpi0_GICR0_CTLR_RWP_MASK)

#define GICRlpi0_GICR0_CTLR_RESERVED1_MASK       (0xFFFFF0U)
#define GICRlpi0_GICR0_CTLR_RESERVED1_SHIFT      (4U)
/*! RESERVED1 - RESERVED1 */
#define GICRlpi0_GICR0_CTLR_RESERVED1(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_RESERVED1_SHIFT)) & GICRlpi0_GICR0_CTLR_RESERVED1_MASK)

#define GICRlpi0_GICR0_CTLR_DPG0_MASK            (0x1000000U)
#define GICRlpi0_GICR0_CTLR_DPG0_SHIFT           (24U)
/*! DPG0 - DPG0 */
#define GICRlpi0_GICR0_CTLR_DPG0(x)              (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_DPG0_SHIFT)) & GICRlpi0_GICR0_CTLR_DPG0_MASK)

#define GICRlpi0_GICR0_CTLR_DPG1NS_MASK          (0x2000000U)
#define GICRlpi0_GICR0_CTLR_DPG1NS_SHIFT         (25U)
/*! DPG1NS - DPG1NS */
#define GICRlpi0_GICR0_CTLR_DPG1NS(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_DPG1NS_SHIFT)) & GICRlpi0_GICR0_CTLR_DPG1NS_MASK)

#define GICRlpi0_GICR0_CTLR_DPG1S_MASK           (0x4000000U)
#define GICRlpi0_GICR0_CTLR_DPG1S_SHIFT          (26U)
/*! DPG1S - DPG1S */
#define GICRlpi0_GICR0_CTLR_DPG1S(x)             (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_DPG1S_SHIFT)) & GICRlpi0_GICR0_CTLR_DPG1S_MASK)

#define GICRlpi0_GICR0_CTLR_RESERVED2_MASK       (0x78000000U)
#define GICRlpi0_GICR0_CTLR_RESERVED2_SHIFT      (27U)
/*! RESERVED2 - RESERVED2 */
#define GICRlpi0_GICR0_CTLR_RESERVED2(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_RESERVED2_SHIFT)) & GICRlpi0_GICR0_CTLR_RESERVED2_MASK)

#define GICRlpi0_GICR0_CTLR_UWP_MASK             (0x80000000U)
#define GICRlpi0_GICR0_CTLR_UWP_SHIFT            (31U)
/*! UWP - UWP */
#define GICRlpi0_GICR0_CTLR_UWP(x)               (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CTLR_UWP_SHIFT)) & GICRlpi0_GICR0_CTLR_UWP_MASK)
/*! @} */

/*! @name GICR0_IIDR - GICR0_IIDR */
/*! @{ */

#define GICRlpi0_GICR0_IIDR_Implementer_MASK     (0xFFFU)
#define GICRlpi0_GICR0_IIDR_Implementer_SHIFT    (0U)
/*! Implementer - Implementer */
#define GICRlpi0_GICR0_IIDR_Implementer(x)       (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_IIDR_Implementer_SHIFT)) & GICRlpi0_GICR0_IIDR_Implementer_MASK)

#define GICRlpi0_GICR0_IIDR_Revision_MASK        (0xF000U)
#define GICRlpi0_GICR0_IIDR_Revision_SHIFT       (12U)
/*! Revision - Revision */
#define GICRlpi0_GICR0_IIDR_Revision(x)          (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_IIDR_Revision_SHIFT)) & GICRlpi0_GICR0_IIDR_Revision_MASK)

#define GICRlpi0_GICR0_IIDR_Variant_MASK         (0xF0000U)
#define GICRlpi0_GICR0_IIDR_Variant_SHIFT        (16U)
/*! Variant - Variant */
#define GICRlpi0_GICR0_IIDR_Variant(x)           (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_IIDR_Variant_SHIFT)) & GICRlpi0_GICR0_IIDR_Variant_MASK)

#define GICRlpi0_GICR0_IIDR_RESERVED0_MASK       (0xF00000U)
#define GICRlpi0_GICR0_IIDR_RESERVED0_SHIFT      (20U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_IIDR_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_IIDR_RESERVED0_SHIFT)) & GICRlpi0_GICR0_IIDR_RESERVED0_MASK)

#define GICRlpi0_GICR0_IIDR_ProductID_MASK       (0xFF000000U)
#define GICRlpi0_GICR0_IIDR_ProductID_SHIFT      (24U)
/*! ProductID - ProductID */
#define GICRlpi0_GICR0_IIDR_ProductID(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_IIDR_ProductID_SHIFT)) & GICRlpi0_GICR0_IIDR_ProductID_MASK)
/*! @} */

/*! @name GICR0_TYPER - GICR0_TYPER */
/*! @{ */

#define GICRlpi0_GICR0_TYPER_PLPIS_MASK          (0x1U)
#define GICRlpi0_GICR0_TYPER_PLPIS_SHIFT         (0U)
/*! PLPIS - PLPIS */
#define GICRlpi0_GICR0_TYPER_PLPIS(x)            (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_PLPIS_SHIFT)) & GICRlpi0_GICR0_TYPER_PLPIS_MASK)

#define GICRlpi0_GICR0_TYPER_VLPIS_MASK          (0x2U)
#define GICRlpi0_GICR0_TYPER_VLPIS_SHIFT         (1U)
/*! VLPIS - VLPIS */
#define GICRlpi0_GICR0_TYPER_VLPIS(x)            (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_VLPIS_SHIFT)) & GICRlpi0_GICR0_TYPER_VLPIS_MASK)

#define GICRlpi0_GICR0_TYPER_RESERVED0_MASK      (0x4U)
#define GICRlpi0_GICR0_TYPER_RESERVED0_SHIFT     (2U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_TYPER_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_RESERVED0_SHIFT)) & GICRlpi0_GICR0_TYPER_RESERVED0_MASK)

#define GICRlpi0_GICR0_TYPER_DirectLPI_MASK      (0x8U)
#define GICRlpi0_GICR0_TYPER_DirectLPI_SHIFT     (3U)
/*! DirectLPI - DirectLPI */
#define GICRlpi0_GICR0_TYPER_DirectLPI(x)        (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_DirectLPI_SHIFT)) & GICRlpi0_GICR0_TYPER_DirectLPI_MASK)

#define GICRlpi0_GICR0_TYPER_Last_MASK           (0x10U)
#define GICRlpi0_GICR0_TYPER_Last_SHIFT          (4U)
/*! Last - Last */
#define GICRlpi0_GICR0_TYPER_Last(x)             (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_Last_SHIFT)) & GICRlpi0_GICR0_TYPER_Last_MASK)

#define GICRlpi0_GICR0_TYPER_DPGS_MASK           (0x20U)
#define GICRlpi0_GICR0_TYPER_DPGS_SHIFT          (5U)
/*! DPGS - DPGS */
#define GICRlpi0_GICR0_TYPER_DPGS(x)             (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_DPGS_SHIFT)) & GICRlpi0_GICR0_TYPER_DPGS_MASK)

#define GICRlpi0_GICR0_TYPER_RESERVED1_MASK      (0xC0U)
#define GICRlpi0_GICR0_TYPER_RESERVED1_SHIFT     (6U)
/*! RESERVED1 - RESERVED1 */
#define GICRlpi0_GICR0_TYPER_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_RESERVED1_SHIFT)) & GICRlpi0_GICR0_TYPER_RESERVED1_MASK)

#define GICRlpi0_GICR0_TYPER_ProcessorNumber_MASK (0xFFFF00U)
#define GICRlpi0_GICR0_TYPER_ProcessorNumber_SHIFT (8U)
/*! ProcessorNumber - ProcessorNumber */
#define GICRlpi0_GICR0_TYPER_ProcessorNumber(x)  (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_ProcessorNumber_SHIFT)) & GICRlpi0_GICR0_TYPER_ProcessorNumber_MASK)

#define GICRlpi0_GICR0_TYPER_CommonLPIAff_MASK   (0x3000000U)
#define GICRlpi0_GICR0_TYPER_CommonLPIAff_SHIFT  (24U)
/*! CommonLPIAff - CommonLPIAff */
#define GICRlpi0_GICR0_TYPER_CommonLPIAff(x)     (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_CommonLPIAff_SHIFT)) & GICRlpi0_GICR0_TYPER_CommonLPIAff_MASK)

#define GICRlpi0_GICR0_TYPER_RESERVED2_MASK      (0xFC000000U)
#define GICRlpi0_GICR0_TYPER_RESERVED2_SHIFT     (26U)
/*! RESERVED2 - RESERVED2 */
#define GICRlpi0_GICR0_TYPER_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_RESERVED2_SHIFT)) & GICRlpi0_GICR0_TYPER_RESERVED2_MASK)

#define GICRlpi0_GICR0_TYPER_AffinityValue_MASK  (0xFFFFFFFF00000000U)
#define GICRlpi0_GICR0_TYPER_AffinityValue_SHIFT (32U)
/*! AffinityValue - AffinityValue */
#define GICRlpi0_GICR0_TYPER_AffinityValue(x)    (((uint64_t)(((uint64_t)(x)) << GICRlpi0_GICR0_TYPER_AffinityValue_SHIFT)) & GICRlpi0_GICR0_TYPER_AffinityValue_MASK)
/*! @} */

/*! @name GICR0_WAKER - GICR0_WAKER */
/*! @{ */

#define GICRlpi0_GICR0_WAKER_Sleep_MASK          (0x1U)
#define GICRlpi0_GICR0_WAKER_Sleep_SHIFT         (0U)
/*! Sleep - Sleep */
#define GICRlpi0_GICR0_WAKER_Sleep(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_WAKER_Sleep_SHIFT)) & GICRlpi0_GICR0_WAKER_Sleep_MASK)

#define GICRlpi0_GICR0_WAKER_ProcessorSleep_MASK (0x2U)
#define GICRlpi0_GICR0_WAKER_ProcessorSleep_SHIFT (1U)
/*! ProcessorSleep - ProcessorSleep */
#define GICRlpi0_GICR0_WAKER_ProcessorSleep(x)   (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_WAKER_ProcessorSleep_SHIFT)) & GICRlpi0_GICR0_WAKER_ProcessorSleep_MASK)

#define GICRlpi0_GICR0_WAKER_ChildrenAsleep_MASK (0x4U)
#define GICRlpi0_GICR0_WAKER_ChildrenAsleep_SHIFT (2U)
/*! ChildrenAsleep - ChildrenAsleep */
#define GICRlpi0_GICR0_WAKER_ChildrenAsleep(x)   (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_WAKER_ChildrenAsleep_SHIFT)) & GICRlpi0_GICR0_WAKER_ChildrenAsleep_MASK)

#define GICRlpi0_GICR0_WAKER_RESERVED0_MASK      (0x7FFFFFF8U)
#define GICRlpi0_GICR0_WAKER_RESERVED0_SHIFT     (3U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_WAKER_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_WAKER_RESERVED0_SHIFT)) & GICRlpi0_GICR0_WAKER_RESERVED0_MASK)

#define GICRlpi0_GICR0_WAKER_Quiescent_MASK      (0x80000000U)
#define GICRlpi0_GICR0_WAKER_Quiescent_SHIFT     (31U)
/*! Quiescent - Quiescent */
#define GICRlpi0_GICR0_WAKER_Quiescent(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_WAKER_Quiescent_SHIFT)) & GICRlpi0_GICR0_WAKER_Quiescent_MASK)
/*! @} */

/*! @name GICR0_FCTLR - GICR0_FCTLR */
/*! @{ */

#define GICRlpi0_GICR0_FCTLR_SIP_MASK            (0x1U)
#define GICRlpi0_GICR0_FCTLR_SIP_SHIFT           (0U)
/*! SIP - SIP */
#define GICRlpi0_GICR0_FCTLR_SIP(x)              (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_FCTLR_SIP_SHIFT)) & GICRlpi0_GICR0_FCTLR_SIP_MASK)

#define GICRlpi0_GICR0_FCTLR_RESERVED0_MASK      (0xEU)
#define GICRlpi0_GICR0_FCTLR_RESERVED0_SHIFT     (1U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_FCTLR_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_FCTLR_RESERVED0_SHIFT)) & GICRlpi0_GICR0_FCTLR_RESERVED0_MASK)

#define GICRlpi0_GICR0_FCTLR_CGO_MASK            (0x70U)
#define GICRlpi0_GICR0_FCTLR_CGO_SHIFT           (4U)
/*! CGO - CGO */
#define GICRlpi0_GICR0_FCTLR_CGO(x)              (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_FCTLR_CGO_SHIFT)) & GICRlpi0_GICR0_FCTLR_CGO_MASK)

#define GICRlpi0_GICR0_FCTLR_RESERVED1_MASK      (0x7FFFFF80U)
#define GICRlpi0_GICR0_FCTLR_RESERVED1_SHIFT     (7U)
/*! RESERVED1 - RESERVED1 */
#define GICRlpi0_GICR0_FCTLR_RESERVED1(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_FCTLR_RESERVED1_SHIFT)) & GICRlpi0_GICR0_FCTLR_RESERVED1_MASK)

#define GICRlpi0_GICR0_FCTLR_QD_MASK             (0x80000000U)
#define GICRlpi0_GICR0_FCTLR_QD_SHIFT            (31U)
/*! QD - QD */
#define GICRlpi0_GICR0_FCTLR_QD(x)               (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_FCTLR_QD_SHIFT)) & GICRlpi0_GICR0_FCTLR_QD_MASK)
/*! @} */

/*! @name GICR0_PWRR - GICR0_PWRR */
/*! @{ */

#define GICRlpi0_GICR0_PWRR_RDPD_MASK            (0x1U)
#define GICRlpi0_GICR0_PWRR_RDPD_SHIFT           (0U)
/*! RDPD - RDPD */
#define GICRlpi0_GICR0_PWRR_RDPD(x)              (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RDPD_SHIFT)) & GICRlpi0_GICR0_PWRR_RDPD_MASK)

#define GICRlpi0_GICR0_PWRR_RDAG_MASK            (0x2U)
#define GICRlpi0_GICR0_PWRR_RDAG_SHIFT           (1U)
/*! RDAG - RDAG */
#define GICRlpi0_GICR0_PWRR_RDAG(x)              (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RDAG_SHIFT)) & GICRlpi0_GICR0_PWRR_RDAG_MASK)

#define GICRlpi0_GICR0_PWRR_RDGPD_MASK           (0x4U)
#define GICRlpi0_GICR0_PWRR_RDGPD_SHIFT          (2U)
/*! RDGPD - RDGPD */
#define GICRlpi0_GICR0_PWRR_RDGPD(x)             (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RDGPD_SHIFT)) & GICRlpi0_GICR0_PWRR_RDGPD_MASK)

#define GICRlpi0_GICR0_PWRR_RDGPO_MASK           (0x8U)
#define GICRlpi0_GICR0_PWRR_RDGPO_SHIFT          (3U)
/*! RDGPO - RDGPO */
#define GICRlpi0_GICR0_PWRR_RDGPO(x)             (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RDGPO_SHIFT)) & GICRlpi0_GICR0_PWRR_RDGPO_MASK)

#define GICRlpi0_GICR0_PWRR_RESERVED0_MASK       (0xF0U)
#define GICRlpi0_GICR0_PWRR_RESERVED0_SHIFT      (4U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PWRR_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PWRR_RESERVED0_MASK)

#define GICRlpi0_GICR0_PWRR_RDGO_MASK            (0x7F00U)
#define GICRlpi0_GICR0_PWRR_RDGO_SHIFT           (8U)
/*! RDGO - RDGO */
#define GICRlpi0_GICR0_PWRR_RDGO(x)              (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RDGO_SHIFT)) & GICRlpi0_GICR0_PWRR_RDGO_MASK)

#define GICRlpi0_GICR0_PWRR_RDG_MASK             (0xFF8000U)
#define GICRlpi0_GICR0_PWRR_RDG_SHIFT            (15U)
/*! RDG - RDG */
#define GICRlpi0_GICR0_PWRR_RDG(x)               (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RDG_SHIFT)) & GICRlpi0_GICR0_PWRR_RDG_MASK)

#define GICRlpi0_GICR0_PWRR_RESERVED1_MASK       (0xFF000000U)
#define GICRlpi0_GICR0_PWRR_RESERVED1_SHIFT      (24U)
/*! RESERVED1 - RESERVED1 */
#define GICRlpi0_GICR0_PWRR_RESERVED1(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PWRR_RESERVED1_SHIFT)) & GICRlpi0_GICR0_PWRR_RESERVED1_MASK)
/*! @} */

/*! @name GICR0_CLASS - GICR0_CLASS */
/*! @{ */

#define GICRlpi0_GICR0_CLASS_Class_MASK          (0x1U)
#define GICRlpi0_GICR0_CLASS_Class_SHIFT         (0U)
/*! Class - Class */
#define GICRlpi0_GICR0_CLASS_Class(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CLASS_Class_SHIFT)) & GICRlpi0_GICR0_CLASS_Class_MASK)

#define GICRlpi0_GICR0_CLASS_RESERVED0_MASK      (0xFFFFFFFEU)
#define GICRlpi0_GICR0_CLASS_RESERVED0_SHIFT     (1U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_CLASS_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CLASS_RESERVED0_SHIFT)) & GICRlpi0_GICR0_CLASS_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR4 - GICR0_PIDR4 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR4_DES_2_MASK          (0xFU)
#define GICRlpi0_GICR0_PIDR4_DES_2_SHIFT         (0U)
/*! DES_2 - DES_2 */
#define GICRlpi0_GICR0_PIDR4_DES_2(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR4_DES_2_SHIFT)) & GICRlpi0_GICR0_PIDR4_DES_2_MASK)

#define GICRlpi0_GICR0_PIDR4_SIZE_MASK           (0xF0U)
#define GICRlpi0_GICR0_PIDR4_SIZE_SHIFT          (4U)
/*! SIZE - SIZE */
#define GICRlpi0_GICR0_PIDR4_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR4_SIZE_SHIFT)) & GICRlpi0_GICR0_PIDR4_SIZE_MASK)

#define GICRlpi0_GICR0_PIDR4_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR4_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR4_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR4_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR4_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR5 - GICR0_PIDR5 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR5_RESERVED_MASK       (0xFFU)
#define GICRlpi0_GICR0_PIDR5_RESERVED_SHIFT      (0U)
/*! RESERVED - RESERVED */
#define GICRlpi0_GICR0_PIDR5_RESERVED(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR5_RESERVED_SHIFT)) & GICRlpi0_GICR0_PIDR5_RESERVED_MASK)

#define GICRlpi0_GICR0_PIDR5_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR5_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR5_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR5_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR5_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR6 - GICR0_PIDR6 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR6_RESERVED_MASK       (0xFFU)
#define GICRlpi0_GICR0_PIDR6_RESERVED_SHIFT      (0U)
/*! RESERVED - RESERVED */
#define GICRlpi0_GICR0_PIDR6_RESERVED(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR6_RESERVED_SHIFT)) & GICRlpi0_GICR0_PIDR6_RESERVED_MASK)

#define GICRlpi0_GICR0_PIDR6_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR6_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR6_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR6_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR6_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR7 - GICR0_PIDR7 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR7_RESERVED_MASK       (0xFFU)
#define GICRlpi0_GICR0_PIDR7_RESERVED_SHIFT      (0U)
/*! RESERVED - RESERVED */
#define GICRlpi0_GICR0_PIDR7_RESERVED(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR7_RESERVED_SHIFT)) & GICRlpi0_GICR0_PIDR7_RESERVED_MASK)

#define GICRlpi0_GICR0_PIDR7_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR7_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR7_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR7_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR7_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR0 - GICR0_PIDR0 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR0_PART_0_MASK         (0xFFU)
#define GICRlpi0_GICR0_PIDR0_PART_0_SHIFT        (0U)
/*! PART_0 - PART_0 */
#define GICRlpi0_GICR0_PIDR0_PART_0(x)           (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR0_PART_0_SHIFT)) & GICRlpi0_GICR0_PIDR0_PART_0_MASK)

#define GICRlpi0_GICR0_PIDR0_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR0_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR0_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR0_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR1 - GICR0_PIDR1 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR1_PART_1_MASK         (0xFU)
#define GICRlpi0_GICR0_PIDR1_PART_1_SHIFT        (0U)
/*! PART_1 - PART_1 */
#define GICRlpi0_GICR0_PIDR1_PART_1(x)           (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR1_PART_1_SHIFT)) & GICRlpi0_GICR0_PIDR1_PART_1_MASK)

#define GICRlpi0_GICR0_PIDR1_DES_0_MASK          (0xF0U)
#define GICRlpi0_GICR0_PIDR1_DES_0_SHIFT         (4U)
/*! DES_0 - DES_0 */
#define GICRlpi0_GICR0_PIDR1_DES_0(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR1_DES_0_SHIFT)) & GICRlpi0_GICR0_PIDR1_DES_0_MASK)

#define GICRlpi0_GICR0_PIDR1_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR1_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR1_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR1_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR2 - GICR0_PIDR2 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR2_DES_1_MASK          (0x7U)
#define GICRlpi0_GICR0_PIDR2_DES_1_SHIFT         (0U)
/*! DES_1 - DES_1 */
#define GICRlpi0_GICR0_PIDR2_DES_1(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR2_DES_1_SHIFT)) & GICRlpi0_GICR0_PIDR2_DES_1_MASK)

#define GICRlpi0_GICR0_PIDR2_JEDEC_MASK          (0x8U)
#define GICRlpi0_GICR0_PIDR2_JEDEC_SHIFT         (3U)
/*! JEDEC - JEDEC */
#define GICRlpi0_GICR0_PIDR2_JEDEC(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR2_JEDEC_SHIFT)) & GICRlpi0_GICR0_PIDR2_JEDEC_MASK)

#define GICRlpi0_GICR0_PIDR2_REVISION_MASK       (0xF0U)
#define GICRlpi0_GICR0_PIDR2_REVISION_SHIFT      (4U)
/*! REVISION - REVISION */
#define GICRlpi0_GICR0_PIDR2_REVISION(x)         (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR2_REVISION_SHIFT)) & GICRlpi0_GICR0_PIDR2_REVISION_MASK)

#define GICRlpi0_GICR0_PIDR2_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR2_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR2_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR2_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_PIDR3 - GICR0_PIDR3 */
/*! @{ */

#define GICRlpi0_GICR0_PIDR3_CMOD_MASK           (0x7U)
#define GICRlpi0_GICR0_PIDR3_CMOD_SHIFT          (0U)
/*! CMOD - CMOD */
#define GICRlpi0_GICR0_PIDR3_CMOD(x)             (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR3_CMOD_SHIFT)) & GICRlpi0_GICR0_PIDR3_CMOD_MASK)

#define GICRlpi0_GICR0_PIDR3_RESERVED0_MASK      (0x8U)
#define GICRlpi0_GICR0_PIDR3_RESERVED0_SHIFT     (3U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_PIDR3_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR3_RESERVED0_SHIFT)) & GICRlpi0_GICR0_PIDR3_RESERVED0_MASK)

#define GICRlpi0_GICR0_PIDR3_REVAND_MASK         (0xF0U)
#define GICRlpi0_GICR0_PIDR3_REVAND_SHIFT        (4U)
/*! REVAND - REVAND */
#define GICRlpi0_GICR0_PIDR3_REVAND(x)           (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR3_REVAND_SHIFT)) & GICRlpi0_GICR0_PIDR3_REVAND_MASK)

#define GICRlpi0_GICR0_PIDR3_RESERVED1_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_PIDR3_RESERVED1_SHIFT     (8U)
/*! RESERVED1 - RESERVED1 */
#define GICRlpi0_GICR0_PIDR3_RESERVED1(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_PIDR3_RESERVED1_SHIFT)) & GICRlpi0_GICR0_PIDR3_RESERVED1_MASK)
/*! @} */

/*! @name GICR0_CIDR0 - GICR0_CIDR0 */
/*! @{ */

#define GICRlpi0_GICR0_CIDR0_PRMBL_0_MASK        (0xFFU)
#define GICRlpi0_GICR0_CIDR0_PRMBL_0_SHIFT       (0U)
/*! PRMBL_0 - PRMBL_0 */
#define GICRlpi0_GICR0_CIDR0_PRMBL_0(x)          (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR0_PRMBL_0_SHIFT)) & GICRlpi0_GICR0_CIDR0_PRMBL_0_MASK)

#define GICRlpi0_GICR0_CIDR0_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_CIDR0_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_CIDR0_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR0_RESERVED0_SHIFT)) & GICRlpi0_GICR0_CIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_CIDR1 - GICR0_CIDR1 */
/*! @{ */

#define GICRlpi0_GICR0_CIDR1_PRMBL_1_MASK        (0xFU)
#define GICRlpi0_GICR0_CIDR1_PRMBL_1_SHIFT       (0U)
/*! PRMBL_1 - PRMBL_1 */
#define GICRlpi0_GICR0_CIDR1_PRMBL_1(x)          (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR1_PRMBL_1_SHIFT)) & GICRlpi0_GICR0_CIDR1_PRMBL_1_MASK)

#define GICRlpi0_GICR0_CIDR1_CLASS_MASK          (0xF0U)
#define GICRlpi0_GICR0_CIDR1_CLASS_SHIFT         (4U)
/*! CLASS - CLASS */
#define GICRlpi0_GICR0_CIDR1_CLASS(x)            (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR1_CLASS_SHIFT)) & GICRlpi0_GICR0_CIDR1_CLASS_MASK)

#define GICRlpi0_GICR0_CIDR1_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_CIDR1_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_CIDR1_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR1_RESERVED0_SHIFT)) & GICRlpi0_GICR0_CIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_CIDR2 - GICR0_CIDR2 */
/*! @{ */

#define GICRlpi0_GICR0_CIDR2_PRMBL_2_MASK        (0xFFU)
#define GICRlpi0_GICR0_CIDR2_PRMBL_2_SHIFT       (0U)
/*! PRMBL_2 - PRMBL_2 */
#define GICRlpi0_GICR0_CIDR2_PRMBL_2(x)          (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR2_PRMBL_2_SHIFT)) & GICRlpi0_GICR0_CIDR2_PRMBL_2_MASK)

#define GICRlpi0_GICR0_CIDR2_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_CIDR2_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_CIDR2_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR2_RESERVED0_SHIFT)) & GICRlpi0_GICR0_CIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICR0_CIDR3 - GICR0_CIDR3 */
/*! @{ */

#define GICRlpi0_GICR0_CIDR3_PRMBL_3_MASK        (0xFFU)
#define GICRlpi0_GICR0_CIDR3_PRMBL_3_SHIFT       (0U)
/*! PRMBL_3 - PRMBL_3 */
#define GICRlpi0_GICR0_CIDR3_PRMBL_3(x)          (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR3_PRMBL_3_SHIFT)) & GICRlpi0_GICR0_CIDR3_PRMBL_3_MASK)

#define GICRlpi0_GICR0_CIDR3_RESERVED0_MASK      (0xFFFFFF00U)
#define GICRlpi0_GICR0_CIDR3_RESERVED0_SHIFT     (8U)
/*! RESERVED0 - RESERVED0 */
#define GICRlpi0_GICR0_CIDR3_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICRlpi0_GICR0_CIDR3_RESERVED0_SHIFT)) & GICRlpi0_GICR0_CIDR3_RESERVED0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GICRlpi0_Register_Masks */


/*!
 * @}
 */ /* end of group GICRlpi0_Peripheral_Access_Layer */


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


#endif  /* PERI_GICRLPI0_H_ */
