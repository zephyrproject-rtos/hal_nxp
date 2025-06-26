/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_LLC_CSR.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_LLC_CSR
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_LLC_CSR_H_)  /* Check if memory map has not been already included */
#define S32Z2_LLC_CSR_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LLC_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLC_CSR_Peripheral_Access_Layer LLC_CSR Peripheral Access Layer
 * @{
 */

/** LLC_CSR - Size of Registers Arrays */
#define LLC_CSR_CCUWPCR_COUNT                     8u

/** LLC_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CCUTCR;                            /**< Transaction Control, offset: 0x0 */
  __I  uint32_t CCUTAR;                            /**< Transaction Activity, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __IO uint32_t CCUCTCR;                           /**< Cache Transaction Control, offset: 0x10 */
  __I  uint32_t CCUCTAR;                           /**< Cache Transaction Activity, offset: 0x14 */
  __IO uint32_t CCUCAOR;                           /**< Allocation Override, offset: 0x18 */
  uint8_t RESERVED_1[4];
  __IO uint32_t CCUSPCR0;                          /**< Scratchpad Configuration 0, offset: 0x20 */
  __IO uint32_t CCUSPCR1;                          /**< Scratchpad Configuration 1, offset: 0x24 */
  __IO uint32_t CCUSPBR0;                          /**< Scratchpad Base Address 0, offset: 0x28 */
  uint8_t RESERVED_2[20];
  struct LLC_CSR_CCUWPCR {                         /* offset: 0x40, array step: 0x8 */
    __IO uint32_t CCUWPCRA;                          /**< Way Partitioning Control A 0..Way Partitioning Control A 7, array offset: 0x40, array step: 0x8 */
    __IO uint32_t CCUWPCRB;                          /**< Way Partitioning Control B 0..Way Partitioning Control B 7, array offset: 0x44, array step: 0x8 */
  } CCUWPCR[LLC_CSR_CCUWPCR_COUNT];
  uint8_t RESERVED_3[128];
  __IO uint32_t CCUCMCR;                           /**< Maintenance Control, offset: 0x100 */
  __I  uint32_t CCUCMAR;                           /**< Maintenance Activity, offset: 0x104 */
  __IO uint32_t CCUCMLR0;                          /**< Maintenance Location 0, offset: 0x108 */
  __IO uint32_t CCUCMLR1;                          /**< Maintenance Location 1, offset: 0x10C */
  __IO uint32_t CCUCMLR2;                          /**< Maintenance Location 2, offset: 0x110 */
  __IO uint32_t CCUCMDR;                           /**< Maintenance Data, offset: 0x114 */
  uint8_t RESERVED_4[40];
  __IO uint32_t CCUCECR;                           /**< Correctable Error Control, offset: 0x140 */
  __IO uint32_t CCUCESR;                           /**< Correctable Error Status, offset: 0x144 */
  __IO uint32_t CCUCESAR;                          /**< Correctable Error Status Alias, offset: 0x148 */
  __I  uint32_t CCUCELR0;                          /**< Correctable Error Location 0, offset: 0x14C */
  __I  uint32_t CCUCELR1;                          /**< Correctable Error Location 1, offset: 0x150 */
  __IO uint32_t CCUUEDR;                           /**< Uncorrectable Error Detect, offset: 0x154 */
  __IO uint32_t CCUUEIR;                           /**< Uncorrectable Error Interrupt, offset: 0x158 */
  __IO uint32_t CCUUESR;                           /**< Uncorrectable Error Status, offset: 0x15C */
  __IO uint32_t CCUUESAR;                          /**< Uncorrectable Error Status Alias, offset: 0x160 */
  __I  uint32_t CCUUELR0;                          /**< Uncorrectable Error Location 0, offset: 0x164 */
  __I  uint32_t CCUUELR1;                          /**< Uncorrectable Error Location 1, offset: 0x168 */
  uint8_t RESERVED_5[84];
  __I  uint32_t CCUIDR;                            /**< Identification, offset: 0x1C0 */
  __IO uint32_t CCUCRTR;                           /**< Correctable Resiliency Threshold, offset: 0x1C4 */
} LLC_CSR_Type, *LLC_CSR_MemMapPtr;

/** Number of instances of the LLC_CSR module. */
#define LLC_CSR_INSTANCE_COUNT                   (2u)

/* LLC_CSR - Peripheral instance base addresses */
/** Peripheral RTU0__LLC_CSR base address */
#define IP_RTU0__LLC_CSR_BASE                    (0x76050000u)
/** Peripheral RTU0__LLC_CSR base pointer */
#define IP_RTU0__LLC_CSR                         ((LLC_CSR_Type *)IP_RTU0__LLC_CSR_BASE)
/** Peripheral RTU1__LLC_CSR base address */
#define IP_RTU1__LLC_CSR_BASE                    (0x76850000u)
/** Peripheral RTU1__LLC_CSR base pointer */
#define IP_RTU1__LLC_CSR                         ((LLC_CSR_Type *)IP_RTU1__LLC_CSR_BASE)
/** Array initializer of LLC_CSR peripheral base addresses */
#define IP_LLC_CSR_BASE_ADDRS                    { IP_RTU0__LLC_CSR_BASE, IP_RTU1__LLC_CSR_BASE }
/** Array initializer of LLC_CSR peripheral base pointers */
#define IP_LLC_CSR_BASE_PTRS                     { IP_RTU0__LLC_CSR, IP_RTU1__LLC_CSR }

/* ----------------------------------------------------------------------------
   -- LLC_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLC_CSR_Register_Masks LLC_CSR Register Masks
 * @{
 */

/*! @name CCUTCR - Transaction Control */
/*! @{ */

#define LLC_CSR_CCUTCR_TransEn_MASK              (0x1U)
#define LLC_CSR_CCUTCR_TransEn_SHIFT             (0U)
#define LLC_CSR_CCUTCR_TransEn_WIDTH             (1U)
#define LLC_CSR_CCUTCR_TransEn(x)                (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUTCR_TransEn_SHIFT)) & LLC_CSR_CCUTCR_TransEn_MASK)
/*! @} */

/*! @name CCUTAR - Transaction Activity */
/*! @{ */

#define LLC_CSR_CCUTAR_TransActv_MASK            (0x1U)
#define LLC_CSR_CCUTAR_TransActv_SHIFT           (0U)
#define LLC_CSR_CCUTAR_TransActv_WIDTH           (1U)
#define LLC_CSR_CCUTAR_TransActv(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUTAR_TransActv_SHIFT)) & LLC_CSR_CCUTAR_TransActv_MASK)
/*! @} */

/*! @name CCUCTCR - Cache Transaction Control */
/*! @{ */

#define LLC_CSR_CCUCTCR_LookupEn_MASK            (0x1U)
#define LLC_CSR_CCUCTCR_LookupEn_SHIFT           (0U)
#define LLC_CSR_CCUCTCR_LookupEn_WIDTH           (1U)
#define LLC_CSR_CCUCTCR_LookupEn(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCTCR_LookupEn_SHIFT)) & LLC_CSR_CCUCTCR_LookupEn_MASK)

#define LLC_CSR_CCUCTCR_FillEn_MASK              (0x2U)
#define LLC_CSR_CCUCTCR_FillEn_SHIFT             (1U)
#define LLC_CSR_CCUCTCR_FillEn_WIDTH             (1U)
#define LLC_CSR_CCUCTCR_FillEn(x)                (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCTCR_FillEn_SHIFT)) & LLC_CSR_CCUCTCR_FillEn_MASK)
/*! @} */

/*! @name CCUCTAR - Cache Transaction Activity */
/*! @{ */

#define LLC_CSR_CCUCTAR_EvictActv_MASK           (0x1U)
#define LLC_CSR_CCUCTAR_EvictActv_SHIFT          (0U)
#define LLC_CSR_CCUCTAR_EvictActv_WIDTH          (1U)
#define LLC_CSR_CCUCTAR_EvictActv(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCTAR_EvictActv_SHIFT)) & LLC_CSR_CCUCTAR_EvictActv_MASK)

#define LLC_CSR_CCUCTAR_FillActv_MASK            (0x2U)
#define LLC_CSR_CCUCTAR_FillActv_SHIFT           (1U)
#define LLC_CSR_CCUCTAR_FillActv_WIDTH           (1U)
#define LLC_CSR_CCUCTAR_FillActv(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCTAR_FillActv_SHIFT)) & LLC_CSR_CCUCTAR_FillActv_MASK)

#define LLC_CSR_CCUCTAR_FlushActv_MASK           (0x4U)
#define LLC_CSR_CCUCTAR_FlushActv_SHIFT          (2U)
#define LLC_CSR_CCUCTAR_FlushActv_WIDTH          (1U)
#define LLC_CSR_CCUCTAR_FlushActv(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCTAR_FlushActv_SHIFT)) & LLC_CSR_CCUCTAR_FlushActv_MASK)
/*! @} */

/*! @name CCUCAOR - Allocation Override */
/*! @{ */

#define LLC_CSR_CCUCAOR_AwAllocEn_MASK           (0x1U)
#define LLC_CSR_CCUCAOR_AwAllocEn_SHIFT          (0U)
#define LLC_CSR_CCUCAOR_AwAllocEn_WIDTH          (1U)
#define LLC_CSR_CCUCAOR_AwAllocEn(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCAOR_AwAllocEn_SHIFT)) & LLC_CSR_CCUCAOR_AwAllocEn_MASK)

#define LLC_CSR_CCUCAOR_ArAllocEn_MASK           (0x2U)
#define LLC_CSR_CCUCAOR_ArAllocEn_SHIFT          (1U)
#define LLC_CSR_CCUCAOR_ArAllocEn_WIDTH          (1U)
#define LLC_CSR_CCUCAOR_ArAllocEn(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCAOR_ArAllocEn_SHIFT)) & LLC_CSR_CCUCAOR_ArAllocEn_MASK)

#define LLC_CSR_CCUCAOR_WrAllocPartialEn_MASK    (0x4U)
#define LLC_CSR_CCUCAOR_WrAllocPartialEn_SHIFT   (2U)
#define LLC_CSR_CCUCAOR_WrAllocPartialEn_WIDTH   (1U)
#define LLC_CSR_CCUCAOR_WrAllocPartialEn(x)      (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCAOR_WrAllocPartialEn_SHIFT)) & LLC_CSR_CCUCAOR_WrAllocPartialEn_MASK)

#define LLC_CSR_CCUCAOR_AwAllocValue_MASK        (0xF0000U)
#define LLC_CSR_CCUCAOR_AwAllocValue_SHIFT       (16U)
#define LLC_CSR_CCUCAOR_AwAllocValue_WIDTH       (4U)
#define LLC_CSR_CCUCAOR_AwAllocValue(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCAOR_AwAllocValue_SHIFT)) & LLC_CSR_CCUCAOR_AwAllocValue_MASK)

#define LLC_CSR_CCUCAOR_ArAllocValue_MASK        (0xF00000U)
#define LLC_CSR_CCUCAOR_ArAllocValue_SHIFT       (20U)
#define LLC_CSR_CCUCAOR_ArAllocValue_WIDTH       (4U)
#define LLC_CSR_CCUCAOR_ArAllocValue(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCAOR_ArAllocValue_SHIFT)) & LLC_CSR_CCUCAOR_ArAllocValue_MASK)
/*! @} */

/*! @name CCUSPCR0 - Scratchpad Configuration 0 */
/*! @{ */

#define LLC_CSR_CCUSPCR0_ScPadEn_MASK            (0x1U)
#define LLC_CSR_CCUSPCR0_ScPadEn_SHIFT           (0U)
#define LLC_CSR_CCUSPCR0_ScPadEn_WIDTH           (1U)
#define LLC_CSR_CCUSPCR0_ScPadEn(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUSPCR0_ScPadEn_SHIFT)) & LLC_CSR_CCUSPCR0_ScPadEn_MASK)

#define LLC_CSR_CCUSPCR0_NumScPadWays_MASK       (0x70000U)
#define LLC_CSR_CCUSPCR0_NumScPadWays_SHIFT      (16U)
#define LLC_CSR_CCUSPCR0_NumScPadWays_WIDTH      (3U)
#define LLC_CSR_CCUSPCR0_NumScPadWays(x)         (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUSPCR0_NumScPadWays_SHIFT)) & LLC_CSR_CCUSPCR0_NumScPadWays_MASK)
/*! @} */

/*! @name CCUSPCR1 - Scratchpad Configuration 1 */
/*! @{ */

#define LLC_CSR_CCUSPCR1_ScPadSize_MASK          (0xFFFFFFFFU)
#define LLC_CSR_CCUSPCR1_ScPadSize_SHIFT         (0U)
#define LLC_CSR_CCUSPCR1_ScPadSize_WIDTH         (32U)
#define LLC_CSR_CCUSPCR1_ScPadSize(x)            (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUSPCR1_ScPadSize_SHIFT)) & LLC_CSR_CCUSPCR1_ScPadSize_MASK)
/*! @} */

/*! @name CCUSPBR0 - Scratchpad Base Address 0 */
/*! @{ */

#define LLC_CSR_CCUSPBR0_ScPadBaseAddr_MASK      (0xFFFFFFFFU)
#define LLC_CSR_CCUSPBR0_ScPadBaseAddr_SHIFT     (0U)
#define LLC_CSR_CCUSPBR0_ScPadBaseAddr_WIDTH     (32U)
#define LLC_CSR_CCUSPBR0_ScPadBaseAddr(x)        (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUSPBR0_ScPadBaseAddr_SHIFT)) & LLC_CSR_CCUSPBR0_ScPadBaseAddr_MASK)
/*! @} */

/*! @name CCUWPCRA - Way Partitioning Control A 0..Way Partitioning Control A 7 */
/*! @{ */

#define LLC_CSR_CCUWPCRA_WpAgentId_MASK          (0xFU)
#define LLC_CSR_CCUWPCRA_WpAgentId_SHIFT         (0U)
#define LLC_CSR_CCUWPCRA_WpAgentId_WIDTH         (4U)
#define LLC_CSR_CCUWPCRA_WpAgentId(x)            (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUWPCRA_WpAgentId_SHIFT)) & LLC_CSR_CCUWPCRA_WpAgentId_MASK)

#define LLC_CSR_CCUWPCRA_WpAgentIdValid_MASK     (0x80000000U)
#define LLC_CSR_CCUWPCRA_WpAgentIdValid_SHIFT    (31U)
#define LLC_CSR_CCUWPCRA_WpAgentIdValid_WIDTH    (1U)
#define LLC_CSR_CCUWPCRA_WpAgentIdValid(x)       (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUWPCRA_WpAgentIdValid_SHIFT)) & LLC_CSR_CCUWPCRA_WpAgentIdValid_MASK)
/*! @} */

/*! @name CCUWPCRB - Way Partitioning Control B 0..Way Partitioning Control B 7 */
/*! @{ */

#define LLC_CSR_CCUWPCRB_WpWayVector_MASK        (0xFFU)
#define LLC_CSR_CCUWPCRB_WpWayVector_SHIFT       (0U)
#define LLC_CSR_CCUWPCRB_WpWayVector_WIDTH       (8U)
#define LLC_CSR_CCUWPCRB_WpWayVector(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUWPCRB_WpWayVector_SHIFT)) & LLC_CSR_CCUWPCRB_WpWayVector_MASK)
/*! @} */

/*! @name CCUCMCR - Maintenance Control */
/*! @{ */

#define LLC_CSR_CCUCMCR_MntOp_MASK               (0xFU)
#define LLC_CSR_CCUCMCR_MntOp_SHIFT              (0U)
#define LLC_CSR_CCUCMCR_MntOp_WIDTH              (4U)
#define LLC_CSR_CCUCMCR_MntOp(x)                 (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMCR_MntOp_SHIFT)) & LLC_CSR_CCUCMCR_MntOp_MASK)

#define LLC_CSR_CCUCMCR_ArrayID_MASK             (0x3F0000U)
#define LLC_CSR_CCUCMCR_ArrayID_SHIFT            (16U)
#define LLC_CSR_CCUCMCR_ArrayID_WIDTH            (6U)
#define LLC_CSR_CCUCMCR_ArrayID(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMCR_ArrayID_SHIFT)) & LLC_CSR_CCUCMCR_ArrayID_MASK)

#define LLC_CSR_CCUCMCR_SecAttr_MASK             (0x400000U)
#define LLC_CSR_CCUCMCR_SecAttr_SHIFT            (22U)
#define LLC_CSR_CCUCMCR_SecAttr_WIDTH            (1U)
#define LLC_CSR_CCUCMCR_SecAttr(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMCR_SecAttr_SHIFT)) & LLC_CSR_CCUCMCR_SecAttr_MASK)
/*! @} */

/*! @name CCUCMAR - Maintenance Activity */
/*! @{ */

#define LLC_CSR_CCUCMAR_MntOpActv_MASK           (0x1U)
#define LLC_CSR_CCUCMAR_MntOpActv_SHIFT          (0U)
#define LLC_CSR_CCUCMAR_MntOpActv_WIDTH          (1U)
#define LLC_CSR_CCUCMAR_MntOpActv(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMAR_MntOpActv_SHIFT)) & LLC_CSR_CCUCMAR_MntOpActv_MASK)
/*! @} */

/*! @name CCUCMLR0 - Maintenance Location 0 */
/*! @{ */

#define LLC_CSR_CCUCMLR0_MntSet_MASK             (0x7FFFU)
#define LLC_CSR_CCUCMLR0_MntSet_SHIFT            (0U)
#define LLC_CSR_CCUCMLR0_MntSet_WIDTH            (15U)
#define LLC_CSR_CCUCMLR0_MntSet(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMLR0_MntSet_SHIFT)) & LLC_CSR_CCUCMLR0_MntSet_MASK)

#define LLC_CSR_CCUCMLR0_MntWay_MASK             (0x1F8000U)
#define LLC_CSR_CCUCMLR0_MntWay_SHIFT            (15U)
#define LLC_CSR_CCUCMLR0_MntWay_WIDTH            (6U)
#define LLC_CSR_CCUCMLR0_MntWay(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMLR0_MntWay_SHIFT)) & LLC_CSR_CCUCMLR0_MntWay_MASK)

#define LLC_CSR_CCUCMLR0_MntWord_MASK            (0xFFE00000U)
#define LLC_CSR_CCUCMLR0_MntWord_SHIFT           (21U)
#define LLC_CSR_CCUCMLR0_MntWord_WIDTH           (11U)
#define LLC_CSR_CCUCMLR0_MntWord(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMLR0_MntWord_SHIFT)) & LLC_CSR_CCUCMLR0_MntWord_MASK)
/*! @} */

/*! @name CCUCMLR1 - Maintenance Location 1 */
/*! @{ */

#define LLC_CSR_CCUCMLR1_MntAddr_MASK            (0xFFFFU)
#define LLC_CSR_CCUCMLR1_MntAddr_SHIFT           (0U)
#define LLC_CSR_CCUCMLR1_MntAddr_WIDTH           (16U)
#define LLC_CSR_CCUCMLR1_MntAddr(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMLR1_MntAddr_SHIFT)) & LLC_CSR_CCUCMLR1_MntAddr_MASK)
/*! @} */

/*! @name CCUCMLR2 - Maintenance Location 2 */
/*! @{ */

#define LLC_CSR_CCUCMLR2_MntRange_MASK           (0xFFFFU)
#define LLC_CSR_CCUCMLR2_MntRange_SHIFT          (0U)
#define LLC_CSR_CCUCMLR2_MntRange_WIDTH          (16U)
#define LLC_CSR_CCUCMLR2_MntRange(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMLR2_MntRange_SHIFT)) & LLC_CSR_CCUCMLR2_MntRange_MASK)
/*! @} */

/*! @name CCUCMDR - Maintenance Data */
/*! @{ */

#define LLC_CSR_CCUCMDR_MntData_MASK             (0xFFFFFFFFU)
#define LLC_CSR_CCUCMDR_MntData_SHIFT            (0U)
#define LLC_CSR_CCUCMDR_MntData_WIDTH            (32U)
#define LLC_CSR_CCUCMDR_MntData(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCMDR_MntData_SHIFT)) & LLC_CSR_CCUCMDR_MntData_MASK)
/*! @} */

/*! @name CCUCECR - Correctable Error Control */
/*! @{ */

#define LLC_CSR_CCUCECR_ErrDetEn_MASK            (0x1U)
#define LLC_CSR_CCUCECR_ErrDetEn_SHIFT           (0U)
#define LLC_CSR_CCUCECR_ErrDetEn_WIDTH           (1U)
#define LLC_CSR_CCUCECR_ErrDetEn(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCECR_ErrDetEn_SHIFT)) & LLC_CSR_CCUCECR_ErrDetEn_MASK)

#define LLC_CSR_CCUCECR_ErrIntEn_MASK            (0x2U)
#define LLC_CSR_CCUCECR_ErrIntEn_SHIFT           (1U)
#define LLC_CSR_CCUCECR_ErrIntEn_WIDTH           (1U)
#define LLC_CSR_CCUCECR_ErrIntEn(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCECR_ErrIntEn_SHIFT)) & LLC_CSR_CCUCECR_ErrIntEn_MASK)

#define LLC_CSR_CCUCECR_ErrThreshold_MASK        (0xFF0U)
#define LLC_CSR_CCUCECR_ErrThreshold_SHIFT       (4U)
#define LLC_CSR_CCUCECR_ErrThreshold_WIDTH       (8U)
#define LLC_CSR_CCUCECR_ErrThreshold(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCECR_ErrThreshold_SHIFT)) & LLC_CSR_CCUCECR_ErrThreshold_MASK)
/*! @} */

/*! @name CCUCESR - Correctable Error Status */
/*! @{ */

#define LLC_CSR_CCUCESR_CErrVld_MASK             (0x1U)
#define LLC_CSR_CCUCESR_CErrVld_SHIFT            (0U)
#define LLC_CSR_CCUCESR_CErrVld_WIDTH            (1U)
#define LLC_CSR_CCUCESR_CErrVld(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESR_CErrVld_SHIFT)) & LLC_CSR_CCUCESR_CErrVld_MASK)

#define LLC_CSR_CCUCESR_CErrCountOverflow_MASK   (0x2U)
#define LLC_CSR_CCUCESR_CErrCountOverflow_SHIFT  (1U)
#define LLC_CSR_CCUCESR_CErrCountOverflow_WIDTH  (1U)
#define LLC_CSR_CCUCESR_CErrCountOverflow(x)     (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESR_CErrCountOverflow_SHIFT)) & LLC_CSR_CCUCESR_CErrCountOverflow_MASK)

#define LLC_CSR_CCUCESR_CErrCount_MASK           (0x3FCU)
#define LLC_CSR_CCUCESR_CErrCount_SHIFT          (2U)
#define LLC_CSR_CCUCESR_CErrCount_WIDTH          (8U)
#define LLC_CSR_CCUCESR_CErrCount(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESR_CErrCount_SHIFT)) & LLC_CSR_CCUCESR_CErrCount_MASK)

#define LLC_CSR_CCUCESR_CErrType_MASK            (0xF800U)
#define LLC_CSR_CCUCESR_CErrType_SHIFT           (11U)
#define LLC_CSR_CCUCESR_CErrType_WIDTH           (5U)
#define LLC_CSR_CCUCESR_CErrType(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESR_CErrType_SHIFT)) & LLC_CSR_CCUCESR_CErrType_MASK)

#define LLC_CSR_CCUCESR_CErrInfo_MASK            (0xFFFF0000U)
#define LLC_CSR_CCUCESR_CErrInfo_SHIFT           (16U)
#define LLC_CSR_CCUCESR_CErrInfo_WIDTH           (16U)
#define LLC_CSR_CCUCESR_CErrInfo(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESR_CErrInfo_SHIFT)) & LLC_CSR_CCUCESR_CErrInfo_MASK)
/*! @} */

/*! @name CCUCESAR - Correctable Error Status Alias */
/*! @{ */

#define LLC_CSR_CCUCESAR_CErrVld_MASK            (0x1U)
#define LLC_CSR_CCUCESAR_CErrVld_SHIFT           (0U)
#define LLC_CSR_CCUCESAR_CErrVld_WIDTH           (1U)
#define LLC_CSR_CCUCESAR_CErrVld(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESAR_CErrVld_SHIFT)) & LLC_CSR_CCUCESAR_CErrVld_MASK)

#define LLC_CSR_CCUCESAR_CErrCountOverflow_MASK  (0x2U)
#define LLC_CSR_CCUCESAR_CErrCountOverflow_SHIFT (1U)
#define LLC_CSR_CCUCESAR_CErrCountOverflow_WIDTH (1U)
#define LLC_CSR_CCUCESAR_CErrCountOverflow(x)    (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESAR_CErrCountOverflow_SHIFT)) & LLC_CSR_CCUCESAR_CErrCountOverflow_MASK)

#define LLC_CSR_CCUCESAR_CErrCount_MASK          (0x3FCU)
#define LLC_CSR_CCUCESAR_CErrCount_SHIFT         (2U)
#define LLC_CSR_CCUCESAR_CErrCount_WIDTH         (8U)
#define LLC_CSR_CCUCESAR_CErrCount(x)            (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESAR_CErrCount_SHIFT)) & LLC_CSR_CCUCESAR_CErrCount_MASK)

#define LLC_CSR_CCUCESAR_CErrType_MASK           (0xF800U)
#define LLC_CSR_CCUCESAR_CErrType_SHIFT          (11U)
#define LLC_CSR_CCUCESAR_CErrType_WIDTH          (5U)
#define LLC_CSR_CCUCESAR_CErrType(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESAR_CErrType_SHIFT)) & LLC_CSR_CCUCESAR_CErrType_MASK)

#define LLC_CSR_CCUCESAR_CErrInfo_MASK           (0xFFFF0000U)
#define LLC_CSR_CCUCESAR_CErrInfo_SHIFT          (16U)
#define LLC_CSR_CCUCESAR_CErrInfo_WIDTH          (16U)
#define LLC_CSR_CCUCESAR_CErrInfo(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCESAR_CErrInfo_SHIFT)) & LLC_CSR_CCUCESAR_CErrInfo_MASK)
/*! @} */

/*! @name CCUCELR0 - Correctable Error Location 0 */
/*! @{ */

#define LLC_CSR_CCUCELR0_ErrEntry_MASK           (0x7FFFU)
#define LLC_CSR_CCUCELR0_ErrEntry_SHIFT          (0U)
#define LLC_CSR_CCUCELR0_ErrEntry_WIDTH          (15U)
#define LLC_CSR_CCUCELR0_ErrEntry(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCELR0_ErrEntry_SHIFT)) & LLC_CSR_CCUCELR0_ErrEntry_MASK)

#define LLC_CSR_CCUCELR0_ErrWay_MASK             (0x1F8000U)
#define LLC_CSR_CCUCELR0_ErrWay_SHIFT            (15U)
#define LLC_CSR_CCUCELR0_ErrWay_WIDTH            (6U)
#define LLC_CSR_CCUCELR0_ErrWay(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCELR0_ErrWay_SHIFT)) & LLC_CSR_CCUCELR0_ErrWay_MASK)

#define LLC_CSR_CCUCELR0_ErrWord_MASK            (0xFFE00000U)
#define LLC_CSR_CCUCELR0_ErrWord_SHIFT           (21U)
#define LLC_CSR_CCUCELR0_ErrWord_WIDTH           (11U)
#define LLC_CSR_CCUCELR0_ErrWord(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCELR0_ErrWord_SHIFT)) & LLC_CSR_CCUCELR0_ErrWord_MASK)
/*! @} */

/*! @name CCUCELR1 - Correctable Error Location 1 */
/*! @{ */

#define LLC_CSR_CCUCELR1_ErrAddr_MASK            (0xFFFFU)
#define LLC_CSR_CCUCELR1_ErrAddr_SHIFT           (0U)
#define LLC_CSR_CCUCELR1_ErrAddr_WIDTH           (16U)
#define LLC_CSR_CCUCELR1_ErrAddr(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCELR1_ErrAddr_SHIFT)) & LLC_CSR_CCUCELR1_ErrAddr_MASK)
/*! @} */

/*! @name CCUUEDR - Uncorrectable Error Detect */
/*! @{ */

#define LLC_CSR_CCUUEDR_ProtErrDetEn_MASK        (0x1U)
#define LLC_CSR_CCUUEDR_ProtErrDetEn_SHIFT       (0U)
#define LLC_CSR_CCUUEDR_ProtErrDetEn_WIDTH       (1U)
#define LLC_CSR_CCUUEDR_ProtErrDetEn(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUEDR_ProtErrDetEn_SHIFT)) & LLC_CSR_CCUUEDR_ProtErrDetEn_MASK)

#define LLC_CSR_CCUUEDR_MemErrDetEn_MASK         (0x2U)
#define LLC_CSR_CCUUEDR_MemErrDetEn_SHIFT        (1U)
#define LLC_CSR_CCUUEDR_MemErrDetEn_WIDTH        (1U)
#define LLC_CSR_CCUUEDR_MemErrDetEn(x)           (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUEDR_MemErrDetEn_SHIFT)) & LLC_CSR_CCUUEDR_MemErrDetEn_MASK)
/*! @} */

/*! @name CCUUEIR - Uncorrectable Error Interrupt */
/*! @{ */

#define LLC_CSR_CCUUEIR_ProtErrIntEn_MASK        (0x1U)
#define LLC_CSR_CCUUEIR_ProtErrIntEn_SHIFT       (0U)
#define LLC_CSR_CCUUEIR_ProtErrIntEn_WIDTH       (1U)
#define LLC_CSR_CCUUEIR_ProtErrIntEn(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUEIR_ProtErrIntEn_SHIFT)) & LLC_CSR_CCUUEIR_ProtErrIntEn_MASK)

#define LLC_CSR_CCUUEIR_MemErrIntEn_MASK         (0x2U)
#define LLC_CSR_CCUUEIR_MemErrIntEn_SHIFT        (1U)
#define LLC_CSR_CCUUEIR_MemErrIntEn_WIDTH        (1U)
#define LLC_CSR_CCUUEIR_MemErrIntEn(x)           (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUEIR_MemErrIntEn_SHIFT)) & LLC_CSR_CCUUEIR_MemErrIntEn_MASK)
/*! @} */

/*! @name CCUUESR - Uncorrectable Error Status */
/*! @{ */

#define LLC_CSR_CCUUESR_UErrVld_MASK             (0x1U)
#define LLC_CSR_CCUUESR_UErrVld_SHIFT            (0U)
#define LLC_CSR_CCUUESR_UErrVld_WIDTH            (1U)
#define LLC_CSR_CCUUESR_UErrVld(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUESR_UErrVld_SHIFT)) & LLC_CSR_CCUUESR_UErrVld_MASK)

#define LLC_CSR_CCUUESR_UErrType_MASK            (0x1F0U)
#define LLC_CSR_CCUUESR_UErrType_SHIFT           (4U)
#define LLC_CSR_CCUUESR_UErrType_WIDTH           (5U)
#define LLC_CSR_CCUUESR_UErrType(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUESR_UErrType_SHIFT)) & LLC_CSR_CCUUESR_UErrType_MASK)

#define LLC_CSR_CCUUESR_UErrInfo_MASK            (0xFFFF0000U)
#define LLC_CSR_CCUUESR_UErrInfo_SHIFT           (16U)
#define LLC_CSR_CCUUESR_UErrInfo_WIDTH           (16U)
#define LLC_CSR_CCUUESR_UErrInfo(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUESR_UErrInfo_SHIFT)) & LLC_CSR_CCUUESR_UErrInfo_MASK)
/*! @} */

/*! @name CCUUESAR - Uncorrectable Error Status Alias */
/*! @{ */

#define LLC_CSR_CCUUESAR_UErrVld_MASK            (0x1U)
#define LLC_CSR_CCUUESAR_UErrVld_SHIFT           (0U)
#define LLC_CSR_CCUUESAR_UErrVld_WIDTH           (1U)
#define LLC_CSR_CCUUESAR_UErrVld(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUESAR_UErrVld_SHIFT)) & LLC_CSR_CCUUESAR_UErrVld_MASK)

#define LLC_CSR_CCUUESAR_UErrType_MASK           (0x1F0U)
#define LLC_CSR_CCUUESAR_UErrType_SHIFT          (4U)
#define LLC_CSR_CCUUESAR_UErrType_WIDTH          (5U)
#define LLC_CSR_CCUUESAR_UErrType(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUESAR_UErrType_SHIFT)) & LLC_CSR_CCUUESAR_UErrType_MASK)

#define LLC_CSR_CCUUESAR_UErrInfo_MASK           (0xFFFF0000U)
#define LLC_CSR_CCUUESAR_UErrInfo_SHIFT          (16U)
#define LLC_CSR_CCUUESAR_UErrInfo_WIDTH          (16U)
#define LLC_CSR_CCUUESAR_UErrInfo(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUESAR_UErrInfo_SHIFT)) & LLC_CSR_CCUUESAR_UErrInfo_MASK)
/*! @} */

/*! @name CCUUELR0 - Uncorrectable Error Location 0 */
/*! @{ */

#define LLC_CSR_CCUUELR0_ErrEntry_MASK           (0x7FFFU)
#define LLC_CSR_CCUUELR0_ErrEntry_SHIFT          (0U)
#define LLC_CSR_CCUUELR0_ErrEntry_WIDTH          (15U)
#define LLC_CSR_CCUUELR0_ErrEntry(x)             (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUELR0_ErrEntry_SHIFT)) & LLC_CSR_CCUUELR0_ErrEntry_MASK)

#define LLC_CSR_CCUUELR0_ErrWay_MASK             (0x1F8000U)
#define LLC_CSR_CCUUELR0_ErrWay_SHIFT            (15U)
#define LLC_CSR_CCUUELR0_ErrWay_WIDTH            (6U)
#define LLC_CSR_CCUUELR0_ErrWay(x)               (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUELR0_ErrWay_SHIFT)) & LLC_CSR_CCUUELR0_ErrWay_MASK)

#define LLC_CSR_CCUUELR0_ErrWord_MASK            (0xFFE00000U)
#define LLC_CSR_CCUUELR0_ErrWord_SHIFT           (21U)
#define LLC_CSR_CCUUELR0_ErrWord_WIDTH           (11U)
#define LLC_CSR_CCUUELR0_ErrWord(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUELR0_ErrWord_SHIFT)) & LLC_CSR_CCUUELR0_ErrWord_MASK)
/*! @} */

/*! @name CCUUELR1 - Uncorrectable Error Location 1 */
/*! @{ */

#define LLC_CSR_CCUUELR1_ErrAddr_MASK            (0xFFFFU)
#define LLC_CSR_CCUUELR1_ErrAddr_SHIFT           (0U)
#define LLC_CSR_CCUUELR1_ErrAddr_WIDTH           (16U)
#define LLC_CSR_CCUUELR1_ErrAddr(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUUELR1_ErrAddr_SHIFT)) & LLC_CSR_CCUUELR1_ErrAddr_MASK)
/*! @} */

/*! @name CCUIDR - Identification */
/*! @{ */

#define LLC_CSR_CCUIDR_PatchRelVer_MASK          (0xFU)
#define LLC_CSR_CCUIDR_PatchRelVer_SHIFT         (0U)
#define LLC_CSR_CCUIDR_PatchRelVer_WIDTH         (4U)
#define LLC_CSR_CCUIDR_PatchRelVer(x)            (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUIDR_PatchRelVer_SHIFT)) & LLC_CSR_CCUIDR_PatchRelVer_MASK)

#define LLC_CSR_CCUIDR_MinRelVer_MASK            (0xF0U)
#define LLC_CSR_CCUIDR_MinRelVer_SHIFT           (4U)
#define LLC_CSR_CCUIDR_MinRelVer_WIDTH           (4U)
#define LLC_CSR_CCUIDR_MinRelVer(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUIDR_MinRelVer_SHIFT)) & LLC_CSR_CCUIDR_MinRelVer_MASK)

#define LLC_CSR_CCUIDR_MajRelVer_MASK            (0xF00U)
#define LLC_CSR_CCUIDR_MajRelVer_SHIFT           (8U)
#define LLC_CSR_CCUIDR_MajRelVer_WIDTH           (4U)
#define LLC_CSR_CCUIDR_MajRelVer(x)              (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUIDR_MajRelVer_SHIFT)) & LLC_CSR_CCUIDR_MajRelVer_MASK)
/*! @} */

/*! @name CCUCRTR - Correctable Resiliency Threshold */
/*! @{ */

#define LLC_CSR_CCUCRTR_ResThreshold_MASK        (0xFFU)
#define LLC_CSR_CCUCRTR_ResThreshold_SHIFT       (0U)
#define LLC_CSR_CCUCRTR_ResThreshold_WIDTH       (8U)
#define LLC_CSR_CCUCRTR_ResThreshold(x)          (((uint32_t)(((uint32_t)(x)) << LLC_CSR_CCUCRTR_ResThreshold_SHIFT)) & LLC_CSR_CCUCRTR_ResThreshold_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LLC_CSR_Register_Masks */

/*!
 * @}
 */ /* end of group LLC_CSR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_LLC_CSR_H_) */
