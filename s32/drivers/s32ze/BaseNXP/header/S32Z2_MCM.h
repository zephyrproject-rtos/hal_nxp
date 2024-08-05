/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_MCM.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_MCM
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
#if !defined(S32Z2_MCM_H_)  /* Check if memory map has not been already included */
#define S32Z2_MCM_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch Master Configuration, offset: 0xA */
  uint8_t RESERVED_1[4];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control, offset: 0x10 */
  uint8_t RESERVED_2[12];
  __I  uint32_t FADR;                              /**< Write Buffer Fault Address, offset: 0x20 */
  __I  uint32_t FATR;                              /**< Store Buffer Fault Attributes, offset: 0x24 */
  __I  uint32_t FDR;                               /**< Store Buffer Fault Data, offset: 0x28 */
  uint8_t RESERVED_3[8];
  __I  uint32_t CPCR2;                             /**< Core Platform Control 2, offset: 0x34 */
  uint8_t RESERVED_4[24];
  __IO uint32_t GPCR0;                             /**< General Purpose Control 0, offset: 0x50 */
  uint8_t RESERVED_5[940];
  __IO uint32_t LMDR0;                             /**< Local Memory Descriptor 0, offset: 0x400 */
  __IO uint32_t LMDR1;                             /**< Local Memory Descriptor 1, offset: 0x404 */
} MCM_Type, *MCM_MemMapPtr;

/** Number of instances of the MCM module. */
#define MCM_INSTANCE_COUNT                       (2u)

/* MCM - Peripheral instance base addresses */
/** Peripheral CE_MCM base address */
#define IP_CE_MCM_BASE                           (0xE0080000u)
/** Peripheral CE_MCM base pointer */
#define IP_CE_MCM                                ((MCM_Type *)IP_CE_MCM_BASE)
/** Peripheral SMU__MCM base address */
#define IP_SMU__MCM_BASE                         (0xE0080000u)
/** Peripheral SMU__MCM base pointer */
#define IP_SMU__MCM                              ((MCM_Type *)IP_SMU__MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define IP_MCM_BASE_ADDRS                        { IP_CE_MCM_BASE, IP_SMU__MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define IP_MCM_BASE_PTRS                         { IP_CE_MCM, IP_SMU__MCM }

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
/*! @{ */

#define MCM_PLASC_ASC0_MASK                      (0x1U)
#define MCM_PLASC_ASC0_SHIFT                     (0U)
#define MCM_PLASC_ASC0_WIDTH                     (1U)
#define MCM_PLASC_ASC0(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC0_SHIFT)) & MCM_PLASC_ASC0_MASK)

#define MCM_PLASC_ASC1_MASK                      (0x2U)
#define MCM_PLASC_ASC1_SHIFT                     (1U)
#define MCM_PLASC_ASC1_WIDTH                     (1U)
#define MCM_PLASC_ASC1(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC1_SHIFT)) & MCM_PLASC_ASC1_MASK)

#define MCM_PLASC_ASC2_MASK                      (0x4U)
#define MCM_PLASC_ASC2_SHIFT                     (2U)
#define MCM_PLASC_ASC2_WIDTH                     (1U)
#define MCM_PLASC_ASC2(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC2_SHIFT)) & MCM_PLASC_ASC2_MASK)

#define MCM_PLASC_ASC3_MASK                      (0x8U)
#define MCM_PLASC_ASC3_SHIFT                     (3U)
#define MCM_PLASC_ASC3_WIDTH                     (1U)
#define MCM_PLASC_ASC3(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC3_SHIFT)) & MCM_PLASC_ASC3_MASK)

#define MCM_PLASC_ASC4_MASK                      (0x10U)
#define MCM_PLASC_ASC4_SHIFT                     (4U)
#define MCM_PLASC_ASC4_WIDTH                     (1U)
#define MCM_PLASC_ASC4(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC4_SHIFT)) & MCM_PLASC_ASC4_MASK)

#define MCM_PLASC_ASC5_MASK                      (0x20U)
#define MCM_PLASC_ASC5_SHIFT                     (5U)
#define MCM_PLASC_ASC5_WIDTH                     (1U)
#define MCM_PLASC_ASC5(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC5_SHIFT)) & MCM_PLASC_ASC5_MASK)

#define MCM_PLASC_ASC6_MASK                      (0x40U)
#define MCM_PLASC_ASC6_SHIFT                     (6U)
#define MCM_PLASC_ASC6_WIDTH                     (1U)
#define MCM_PLASC_ASC6(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC6_SHIFT)) & MCM_PLASC_ASC6_MASK)

#define MCM_PLASC_ASC7_MASK                      (0x80U)
#define MCM_PLASC_ASC7_SHIFT                     (7U)
#define MCM_PLASC_ASC7_WIDTH                     (1U)
#define MCM_PLASC_ASC7(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC7_SHIFT)) & MCM_PLASC_ASC7_MASK)
/*! @} */

/*! @name PLAMC - Crossbar Switch Master Configuration */
/*! @{ */

#define MCM_PLAMC_AMC0_MASK                      (0x1U)
#define MCM_PLAMC_AMC0_SHIFT                     (0U)
#define MCM_PLAMC_AMC0_WIDTH                     (1U)
#define MCM_PLAMC_AMC0(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC0_SHIFT)) & MCM_PLAMC_AMC0_MASK)

#define MCM_PLAMC_AMC1_MASK                      (0x2U)
#define MCM_PLAMC_AMC1_SHIFT                     (1U)
#define MCM_PLAMC_AMC1_WIDTH                     (1U)
#define MCM_PLAMC_AMC1(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC1_SHIFT)) & MCM_PLAMC_AMC1_MASK)

#define MCM_PLAMC_AMC2_MASK                      (0x4U)
#define MCM_PLAMC_AMC2_SHIFT                     (2U)
#define MCM_PLAMC_AMC2_WIDTH                     (1U)
#define MCM_PLAMC_AMC2(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC2_SHIFT)) & MCM_PLAMC_AMC2_MASK)

#define MCM_PLAMC_AMC3_MASK                      (0x8U)
#define MCM_PLAMC_AMC3_SHIFT                     (3U)
#define MCM_PLAMC_AMC3_WIDTH                     (1U)
#define MCM_PLAMC_AMC3(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC3_SHIFT)) & MCM_PLAMC_AMC3_MASK)

#define MCM_PLAMC_AMC4_MASK                      (0x10U)
#define MCM_PLAMC_AMC4_SHIFT                     (4U)
#define MCM_PLAMC_AMC4_WIDTH                     (1U)
#define MCM_PLAMC_AMC4(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC4_SHIFT)) & MCM_PLAMC_AMC4_MASK)

#define MCM_PLAMC_AMC5_MASK                      (0x20U)
#define MCM_PLAMC_AMC5_SHIFT                     (5U)
#define MCM_PLAMC_AMC5_WIDTH                     (1U)
#define MCM_PLAMC_AMC5(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC5_SHIFT)) & MCM_PLAMC_AMC5_MASK)

#define MCM_PLAMC_AMC6_MASK                      (0x40U)
#define MCM_PLAMC_AMC6_SHIFT                     (6U)
#define MCM_PLAMC_AMC6_WIDTH                     (1U)
#define MCM_PLAMC_AMC6(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC6_SHIFT)) & MCM_PLAMC_AMC6_MASK)

#define MCM_PLAMC_AMC7_MASK                      (0x80U)
#define MCM_PLAMC_AMC7_SHIFT                     (7U)
#define MCM_PLAMC_AMC7_WIDTH                     (1U)
#define MCM_PLAMC_AMC7(x)                        (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC7_SHIFT)) & MCM_PLAMC_AMC7_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define MCM_ISCR_CWBER_MASK                      (0x10U)
#define MCM_ISCR_CWBER_SHIFT                     (4U)
#define MCM_ISCR_CWBER_WIDTH                     (1U)
#define MCM_ISCR_CWBER(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBER_SHIFT)) & MCM_ISCR_CWBER_MASK)

#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
#define MCM_ISCR_FIOC_WIDTH                      (1U)
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
#define MCM_ISCR_FDZC_WIDTH                      (1U)
#define MCM_ISCR_FDZC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)

#define MCM_ISCR_FOFC_MASK                       (0x400U)
#define MCM_ISCR_FOFC_SHIFT                      (10U)
#define MCM_ISCR_FOFC_WIDTH                      (1U)
#define MCM_ISCR_FOFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)

#define MCM_ISCR_FUFC_MASK                       (0x800U)
#define MCM_ISCR_FUFC_SHIFT                      (11U)
#define MCM_ISCR_FUFC_WIDTH                      (1U)
#define MCM_ISCR_FUFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)

#define MCM_ISCR_FIXC_MASK                       (0x1000U)
#define MCM_ISCR_FIXC_SHIFT                      (12U)
#define MCM_ISCR_FIXC_WIDTH                      (1U)
#define MCM_ISCR_FIXC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)

#define MCM_ISCR_FIDC_MASK                       (0x8000U)
#define MCM_ISCR_FIDC_SHIFT                      (15U)
#define MCM_ISCR_FIDC_WIDTH                      (1U)
#define MCM_ISCR_FIDC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)

#define MCM_ISCR_CWBEE_MASK                      (0x100000U)
#define MCM_ISCR_CWBEE_SHIFT                     (20U)
#define MCM_ISCR_CWBEE_WIDTH                     (1U)
#define MCM_ISCR_CWBEE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBEE_SHIFT)) & MCM_ISCR_CWBEE_MASK)

#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
#define MCM_ISCR_FIOCE_WIDTH                     (1U)
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
#define MCM_ISCR_FDZCE_WIDTH                     (1U)
#define MCM_ISCR_FDZCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)

#define MCM_ISCR_FOFCE_MASK                      (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT                     (26U)
#define MCM_ISCR_FOFCE_WIDTH                     (1U)
#define MCM_ISCR_FOFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)

#define MCM_ISCR_FUFCE_MASK                      (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT                     (27U)
#define MCM_ISCR_FUFCE_WIDTH                     (1U)
#define MCM_ISCR_FUFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)

#define MCM_ISCR_FIXCE_MASK                      (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT                     (28U)
#define MCM_ISCR_FIXCE_WIDTH                     (1U)
#define MCM_ISCR_FIXCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)

#define MCM_ISCR_FIDCE_MASK                      (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT                     (31U)
#define MCM_ISCR_FIDCE_WIDTH                     (1U)
#define MCM_ISCR_FIDCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name FADR - Write Buffer Fault Address */
/*! @{ */

#define MCM_FADR_ADDRESS_MASK                    (0xFFFFFFFFU)
#define MCM_FADR_ADDRESS_SHIFT                   (0U)
#define MCM_FADR_ADDRESS_WIDTH                   (32U)
#define MCM_FADR_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_FADR_ADDRESS_SHIFT)) & MCM_FADR_ADDRESS_MASK)
/*! @} */

/*! @name FATR - Store Buffer Fault Attributes */
/*! @{ */

#define MCM_FATR_BEDA_MASK                       (0x1U)
#define MCM_FATR_BEDA_SHIFT                      (0U)
#define MCM_FATR_BEDA_WIDTH                      (1U)
#define MCM_FATR_BEDA(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEDA_SHIFT)) & MCM_FATR_BEDA_MASK)

#define MCM_FATR_BEMD_MASK                       (0x2U)
#define MCM_FATR_BEMD_SHIFT                      (1U)
#define MCM_FATR_BEMD_WIDTH                      (1U)
#define MCM_FATR_BEMD(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMD_SHIFT)) & MCM_FATR_BEMD_MASK)

#define MCM_FATR_BESZ_MASK                       (0x30U)
#define MCM_FATR_BESZ_SHIFT                      (4U)
#define MCM_FATR_BESZ_WIDTH                      (2U)
#define MCM_FATR_BESZ(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BESZ_SHIFT)) & MCM_FATR_BESZ_MASK)

#define MCM_FATR_BEWT_MASK                       (0x80U)
#define MCM_FATR_BEWT_SHIFT                      (7U)
#define MCM_FATR_BEWT_WIDTH                      (1U)
#define MCM_FATR_BEWT(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEWT_SHIFT)) & MCM_FATR_BEWT_MASK)

#define MCM_FATR_BEMN_MASK                       (0xF00U)
#define MCM_FATR_BEMN_SHIFT                      (8U)
#define MCM_FATR_BEMN_WIDTH                      (4U)
#define MCM_FATR_BEMN(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMN_SHIFT)) & MCM_FATR_BEMN_MASK)

#define MCM_FATR_BEOVR_MASK                      (0x80000000U)
#define MCM_FATR_BEOVR_SHIFT                     (31U)
#define MCM_FATR_BEOVR_WIDTH                     (1U)
#define MCM_FATR_BEOVR(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEOVR_SHIFT)) & MCM_FATR_BEOVR_MASK)
/*! @} */

/*! @name FDR - Store Buffer Fault Data */
/*! @{ */

#define MCM_FDR_DATA_MASK                        (0xFFFFFFFFU)
#define MCM_FDR_DATA_SHIFT                       (0U)
#define MCM_FDR_DATA_WIDTH                       (32U)
#define MCM_FDR_DATA(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_FDR_DATA_SHIFT)) & MCM_FDR_DATA_MASK)
/*! @} */

/*! @name CPCR2 - Core Platform Control 2 */
/*! @{ */

#define MCM_CPCR2_CBCS_MASK                      (0xF0U)
#define MCM_CPCR2_CBCS_SHIFT                     (4U)
#define MCM_CPCR2_CBCS_WIDTH                     (4U)
#define MCM_CPCR2_CBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CBCS_SHIFT)) & MCM_CPCR2_CBCS_MASK)

#define MCM_CPCR2_SBCS_MASK                      (0xF000U)
#define MCM_CPCR2_SBCS_SHIFT                     (12U)
#define MCM_CPCR2_SBCS_WIDTH                     (4U)
#define MCM_CPCR2_SBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_SBCS_SHIFT)) & MCM_CPCR2_SBCS_MASK)
/*! @} */

/*! @name GPCR0 - General Purpose Control 0 */
/*! @{ */

#define MCM_GPCR0_CORE_TASKID_MASK               (0xFU)
#define MCM_GPCR0_CORE_TASKID_SHIFT              (0U)
#define MCM_GPCR0_CORE_TASKID_WIDTH              (4U)
#define MCM_GPCR0_CORE_TASKID(x)                 (((uint32_t)(((uint32_t)(x)) << MCM_GPCR0_CORE_TASKID_SHIFT)) & MCM_GPCR0_CORE_TASKID_MASK)
/*! @} */

/*! @name LMDR0 - Local Memory Descriptor 0 */
/*! @{ */

#define MCM_LMDR0_EEWG_MASK                      (0x1U)
#define MCM_LMDR0_EEWG_SHIFT                     (0U)
#define MCM_LMDR0_EEWG_WIDTH                     (1U)
#define MCM_LMDR0_EEWG(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_EEWG_SHIFT)) & MCM_LMDR0_EEWG_MASK)

#define MCM_LMDR0_EERC_MASK                      (0x2U)
#define MCM_LMDR0_EERC_SHIFT                     (1U)
#define MCM_LMDR0_EERC_WIDTH                     (1U)
#define MCM_LMDR0_EERC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_EERC_SHIFT)) & MCM_LMDR0_EERC_MASK)

#define MCM_LMDR0_MT_MASK                        (0xE000U)
#define MCM_LMDR0_MT_SHIFT                       (13U)
#define MCM_LMDR0_MT_WIDTH                       (3U)
#define MCM_LMDR0_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_MT_SHIFT)) & MCM_LMDR0_MT_MASK)

#define MCM_LMDR0_RO_MASK                        (0x10000U)
#define MCM_LMDR0_RO_SHIFT                       (16U)
#define MCM_LMDR0_RO_WIDTH                       (1U)
#define MCM_LMDR0_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_RO_SHIFT)) & MCM_LMDR0_RO_MASK)

#define MCM_LMDR0_DPW_MASK                       (0xE0000U)
#define MCM_LMDR0_DPW_SHIFT                      (17U)
#define MCM_LMDR0_DPW_WIDTH                      (3U)
#define MCM_LMDR0_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_DPW_SHIFT)) & MCM_LMDR0_DPW_MASK)

#define MCM_LMDR0_WY_MASK                        (0xF00000U)
#define MCM_LMDR0_WY_SHIFT                       (20U)
#define MCM_LMDR0_WY_WIDTH                       (4U)
#define MCM_LMDR0_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_WY_SHIFT)) & MCM_LMDR0_WY_MASK)

#define MCM_LMDR0_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR0_LMSZ_SHIFT                     (24U)
#define MCM_LMDR0_LMSZ_WIDTH                     (4U)
#define MCM_LMDR0_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_LMSZ_SHIFT)) & MCM_LMDR0_LMSZ_MASK)

#define MCM_LMDR0_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR0_LMSZH_SHIFT                    (28U)
#define MCM_LMDR0_LMSZH_WIDTH                    (1U)
#define MCM_LMDR0_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_LMSZH_SHIFT)) & MCM_LMDR0_LMSZH_MASK)

#define MCM_LMDR0_V_MASK                         (0x80000000U)
#define MCM_LMDR0_V_SHIFT                        (31U)
#define MCM_LMDR0_V_WIDTH                        (1U)
#define MCM_LMDR0_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_V_SHIFT)) & MCM_LMDR0_V_MASK)
/*! @} */

/*! @name LMDR1 - Local Memory Descriptor 1 */
/*! @{ */

#define MCM_LMDR1_EEWG_MASK                      (0x1U)
#define MCM_LMDR1_EEWG_SHIFT                     (0U)
#define MCM_LMDR1_EEWG_WIDTH                     (1U)
#define MCM_LMDR1_EEWG(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_EEWG_SHIFT)) & MCM_LMDR1_EEWG_MASK)

#define MCM_LMDR1_EERC_MASK                      (0x2U)
#define MCM_LMDR1_EERC_SHIFT                     (1U)
#define MCM_LMDR1_EERC_WIDTH                     (1U)
#define MCM_LMDR1_EERC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_EERC_SHIFT)) & MCM_LMDR1_EERC_MASK)

#define MCM_LMDR1_MT_MASK                        (0xE000U)
#define MCM_LMDR1_MT_SHIFT                       (13U)
#define MCM_LMDR1_MT_WIDTH                       (3U)
#define MCM_LMDR1_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_MT_SHIFT)) & MCM_LMDR1_MT_MASK)

#define MCM_LMDR1_RO_MASK                        (0x10000U)
#define MCM_LMDR1_RO_SHIFT                       (16U)
#define MCM_LMDR1_RO_WIDTH                       (1U)
#define MCM_LMDR1_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_RO_SHIFT)) & MCM_LMDR1_RO_MASK)

#define MCM_LMDR1_DPW_MASK                       (0xE0000U)
#define MCM_LMDR1_DPW_SHIFT                      (17U)
#define MCM_LMDR1_DPW_WIDTH                      (3U)
#define MCM_LMDR1_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_DPW_SHIFT)) & MCM_LMDR1_DPW_MASK)

#define MCM_LMDR1_WY_MASK                        (0xF00000U)
#define MCM_LMDR1_WY_SHIFT                       (20U)
#define MCM_LMDR1_WY_WIDTH                       (4U)
#define MCM_LMDR1_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_WY_SHIFT)) & MCM_LMDR1_WY_MASK)

#define MCM_LMDR1_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR1_LMSZ_SHIFT                     (24U)
#define MCM_LMDR1_LMSZ_WIDTH                     (4U)
#define MCM_LMDR1_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_LMSZ_SHIFT)) & MCM_LMDR1_LMSZ_MASK)

#define MCM_LMDR1_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR1_LMSZH_SHIFT                    (28U)
#define MCM_LMDR1_LMSZH_WIDTH                    (1U)
#define MCM_LMDR1_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_LMSZH_SHIFT)) & MCM_LMDR1_LMSZH_MASK)

#define MCM_LMDR1_V_MASK                         (0x80000000U)
#define MCM_LMDR1_V_SHIFT                        (31U)
#define MCM_LMDR1_V_WIDTH                        (1U)
#define MCM_LMDR1_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_V_SHIFT)) & MCM_LMDR1_V_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MCM_Register_Masks */

/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_MCM_H_) */
