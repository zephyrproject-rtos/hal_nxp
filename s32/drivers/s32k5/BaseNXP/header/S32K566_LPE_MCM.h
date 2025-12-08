/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LPE_MCM.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LPE_MCM
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
#if !defined(S32K566_LPE_MCM_H_)  /* Check if memory map has not been already included */
#define S32K566_LPE_MCM_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPE_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_MCM_Peripheral_Access_Layer LPE_MCM Peripheral Access Layer
 * @{
 */

/** LPE_MCM - Size of Registers Arrays */
#define LPE_MCM_LMDR_COUNT                        2u

/** LPE_MCM - Register Layout Typedef */
typedef struct LPE_MCM_Struct {
  uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t CPCR;                              /**< Core Platform Control Register, offset: 0xC */
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
  uint8_t RESERVED_1[28];
  __IO uint32_t PID;                               /**< Process ID Register, offset: 0x30 */
  uint8_t RESERVED_2[12];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
  uint8_t RESERVED_3[956];
  __IO uint32_t LMDR[LPE_MCM_LMDR_COUNT];          /**< Local Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
  __IO uint32_t LMDR2;                             /**< Local Memory Descriptor Register2, offset: 0x408 */
  uint8_t RESERVED_4[116];
  __IO uint32_t LMPECR;                            /**< LMEM Parity and ECC Control Register, offset: 0x480 */
  uint8_t RESERVED_5[4];
  __IO uint32_t LMPEIR;                            /**< LMEM Parity and ECC Interrupt Register, offset: 0x488 */
  uint8_t RESERVED_6[4];
  __I  uint32_t LMFAR;                             /**< LMEM Fault Address Register, offset: 0x490 */
  __I  uint32_t LMFATR;                            /**< LMEM Fault Attribute Register, offset: 0x494 */
  uint8_t RESERVED_7[8];
  __I  uint32_t LMFDHR;                            /**< LMEM Fault Data High Register, offset: 0x4A0 */
  __I  uint32_t LMFDLR;                            /**< LMEM Fault Data Low Register, offset: 0x4A4 */
} LPE_MCM_Type, *LPE_MCM_MemMapPtr;

/** Number of instances of the LPE_MCM module. */
#define LPE_MCM_INSTANCE_COUNT                   (1u)

/* LPE_MCM - Peripheral instance base addresses */
/** Peripheral LPE_MCM base address */
#define IP_LPE_MCM_BASE                          (0xE0080000u)
/** Peripheral LPE_MCM base pointer */
#define IP_LPE_MCM                               ((LPE_MCM_Type *)IP_LPE_MCM_BASE)
/** Array initializer of LPE_MCM peripheral base addresses */
#define IP_LPE_MCM_BASE_ADDRS                    { IP_LPE_MCM_BASE }
/** Array initializer of LPE_MCM peripheral base pointers */
#define IP_LPE_MCM_BASE_PTRS                     { IP_LPE_MCM }

/* ----------------------------------------------------------------------------
   -- LPE_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_MCM_Register_Masks LPE_MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
/*! @{ */

#define LPE_MCM_PLASC_ASC_MASK                   (0xFF00U)
#define LPE_MCM_PLASC_ASC_SHIFT                  (8U)
#define LPE_MCM_PLASC_ASC_WIDTH                  (8U)
#define LPE_MCM_PLASC_ASC(x)                     (((uint16_t)(((uint16_t)(x)) << LPE_MCM_PLASC_ASC_SHIFT)) & LPE_MCM_PLASC_ASC_MASK)
/*! @} */

/*! @name PLAMC - Crossbar Switch (AXBS) Master Configuration */
/*! @{ */

#define LPE_MCM_PLAMC_AMC_MASK                   (0xFF00U)
#define LPE_MCM_PLAMC_AMC_SHIFT                  (8U)
#define LPE_MCM_PLAMC_AMC_WIDTH                  (8U)
#define LPE_MCM_PLAMC_AMC(x)                     (((uint16_t)(((uint16_t)(x)) << LPE_MCM_PLAMC_AMC_SHIFT)) & LPE_MCM_PLAMC_AMC_MASK)
/*! @} */

/*! @name CPCR - Core Platform Control Register */
/*! @{ */

#define LPE_MCM_CPCR_SRAMLWP_MASK                (0x2U)
#define LPE_MCM_CPCR_SRAMLWP_SHIFT               (1U)
#define LPE_MCM_CPCR_SRAMLWP_WIDTH               (1U)
#define LPE_MCM_CPCR_SRAMLWP(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_SRAMLWP_SHIFT)) & LPE_MCM_CPCR_SRAMLWP_MASK)

#define LPE_MCM_CPCR_SRAMLAP_MASK                (0xCU)
#define LPE_MCM_CPCR_SRAMLAP_SHIFT               (2U)
#define LPE_MCM_CPCR_SRAMLAP_WIDTH               (2U)
#define LPE_MCM_CPCR_SRAMLAP(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_SRAMLAP_SHIFT)) & LPE_MCM_CPCR_SRAMLAP_MASK)

#define LPE_MCM_CPCR_SRAMUWP_MASK                (0x20U)
#define LPE_MCM_CPCR_SRAMUWP_SHIFT               (5U)
#define LPE_MCM_CPCR_SRAMUWP_WIDTH               (1U)
#define LPE_MCM_CPCR_SRAMUWP(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_SRAMUWP_SHIFT)) & LPE_MCM_CPCR_SRAMUWP_MASK)

#define LPE_MCM_CPCR_SRAMUAP_MASK                (0xC0U)
#define LPE_MCM_CPCR_SRAMUAP_SHIFT               (6U)
#define LPE_MCM_CPCR_SRAMUAP_WIDTH               (2U)
#define LPE_MCM_CPCR_SRAMUAP(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_SRAMUAP_SHIFT)) & LPE_MCM_CPCR_SRAMUAP_MASK)

#define LPE_MCM_CPCR_CBRR_MASK                   (0x400000U)
#define LPE_MCM_CPCR_CBRR_SHIFT                  (22U)
#define LPE_MCM_CPCR_CBRR_WIDTH                  (1U)
#define LPE_MCM_CPCR_CBRR(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_CBRR_SHIFT)) & LPE_MCM_CPCR_CBRR_MASK)

#define LPE_MCM_CPCR_PBRIDGE_IDLE_MASK           (0x2000000U)
#define LPE_MCM_CPCR_PBRIDGE_IDLE_SHIFT          (25U)
#define LPE_MCM_CPCR_PBRIDGE_IDLE_WIDTH          (1U)
#define LPE_MCM_CPCR_PBRIDGE_IDLE(x)             (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_PBRIDGE_IDLE_SHIFT)) & LPE_MCM_CPCR_PBRIDGE_IDLE_MASK)

#define LPE_MCM_CPCR_FMC_PF_IDLE_MASK            (0x8000000U)
#define LPE_MCM_CPCR_FMC_PF_IDLE_SHIFT           (27U)
#define LPE_MCM_CPCR_FMC_PF_IDLE_WIDTH           (1U)
#define LPE_MCM_CPCR_FMC_PF_IDLE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_FMC_PF_IDLE_SHIFT)) & LPE_MCM_CPCR_FMC_PF_IDLE_MASK)

#define LPE_MCM_CPCR_AXBS_HLTD_MASK              (0x10000000U)
#define LPE_MCM_CPCR_AXBS_HLTD_SHIFT             (28U)
#define LPE_MCM_CPCR_AXBS_HLTD_WIDTH             (1U)
#define LPE_MCM_CPCR_AXBS_HLTD(x)                (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_AXBS_HLTD_SHIFT)) & LPE_MCM_CPCR_AXBS_HLTD_MASK)

#define LPE_MCM_CPCR_AXBS_HLT_REQ_MASK           (0x20000000U)
#define LPE_MCM_CPCR_AXBS_HLT_REQ_SHIFT          (29U)
#define LPE_MCM_CPCR_AXBS_HLT_REQ_WIDTH          (1U)
#define LPE_MCM_CPCR_AXBS_HLT_REQ(x)             (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_AXBS_HLT_REQ_SHIFT)) & LPE_MCM_CPCR_AXBS_HLT_REQ_MASK)

#define LPE_MCM_CPCR_HLT_FSM_ST_MASK             (0xC0000000U)
#define LPE_MCM_CPCR_HLT_FSM_ST_SHIFT            (30U)
#define LPE_MCM_CPCR_HLT_FSM_ST_WIDTH            (2U)
#define LPE_MCM_CPCR_HLT_FSM_ST(x)               (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPCR_HLT_FSM_ST_SHIFT)) & LPE_MCM_CPCR_HLT_FSM_ST_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control Register */
/*! @{ */

#define LPE_MCM_ISCR_FIDCE_MASK                  (0x1U)
#define LPE_MCM_ISCR_FIDCE_SHIFT                 (0U)
#define LPE_MCM_ISCR_FIDCE_WIDTH                 (1U)
#define LPE_MCM_ISCR_FIDCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FIDCE_SHIFT)) & LPE_MCM_ISCR_FIDCE_MASK)

#define LPE_MCM_ISCR_FIXCE_MASK                  (0x8U)
#define LPE_MCM_ISCR_FIXCE_SHIFT                 (3U)
#define LPE_MCM_ISCR_FIXCE_WIDTH                 (1U)
#define LPE_MCM_ISCR_FIXCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FIXCE_SHIFT)) & LPE_MCM_ISCR_FIXCE_MASK)

#define LPE_MCM_ISCR_FUFCE_MASK                  (0x10U)
#define LPE_MCM_ISCR_FUFCE_SHIFT                 (4U)
#define LPE_MCM_ISCR_FUFCE_WIDTH                 (1U)
#define LPE_MCM_ISCR_FUFCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FUFCE_SHIFT)) & LPE_MCM_ISCR_FUFCE_MASK)

#define LPE_MCM_ISCR_FOFCE_MASK                  (0x20U)
#define LPE_MCM_ISCR_FOFCE_SHIFT                 (5U)
#define LPE_MCM_ISCR_FOFCE_WIDTH                 (1U)
#define LPE_MCM_ISCR_FOFCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FOFCE_SHIFT)) & LPE_MCM_ISCR_FOFCE_MASK)

#define LPE_MCM_ISCR_FDZCE_MASK                  (0x40U)
#define LPE_MCM_ISCR_FDZCE_SHIFT                 (6U)
#define LPE_MCM_ISCR_FDZCE_WIDTH                 (1U)
#define LPE_MCM_ISCR_FDZCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FDZCE_SHIFT)) & LPE_MCM_ISCR_FDZCE_MASK)

#define LPE_MCM_ISCR_FIOCE_MASK                  (0x80U)
#define LPE_MCM_ISCR_FIOCE_SHIFT                 (7U)
#define LPE_MCM_ISCR_FIOCE_WIDTH                 (1U)
#define LPE_MCM_ISCR_FIOCE(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FIOCE_SHIFT)) & LPE_MCM_ISCR_FIOCE_MASK)

#define LPE_MCM_ISCR_FIDC_MASK                   (0x10000U)
#define LPE_MCM_ISCR_FIDC_SHIFT                  (16U)
#define LPE_MCM_ISCR_FIDC_WIDTH                  (1U)
#define LPE_MCM_ISCR_FIDC(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FIDC_SHIFT)) & LPE_MCM_ISCR_FIDC_MASK)

#define LPE_MCM_ISCR_FIXC_MASK                   (0x80000U)
#define LPE_MCM_ISCR_FIXC_SHIFT                  (19U)
#define LPE_MCM_ISCR_FIXC_WIDTH                  (1U)
#define LPE_MCM_ISCR_FIXC(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FIXC_SHIFT)) & LPE_MCM_ISCR_FIXC_MASK)

#define LPE_MCM_ISCR_FUFC_MASK                   (0x100000U)
#define LPE_MCM_ISCR_FUFC_SHIFT                  (20U)
#define LPE_MCM_ISCR_FUFC_WIDTH                  (1U)
#define LPE_MCM_ISCR_FUFC(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FUFC_SHIFT)) & LPE_MCM_ISCR_FUFC_MASK)

#define LPE_MCM_ISCR_FOFC_MASK                   (0x200000U)
#define LPE_MCM_ISCR_FOFC_SHIFT                  (21U)
#define LPE_MCM_ISCR_FOFC_WIDTH                  (1U)
#define LPE_MCM_ISCR_FOFC(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FOFC_SHIFT)) & LPE_MCM_ISCR_FOFC_MASK)

#define LPE_MCM_ISCR_FDZC_MASK                   (0x400000U)
#define LPE_MCM_ISCR_FDZC_SHIFT                  (22U)
#define LPE_MCM_ISCR_FDZC_WIDTH                  (1U)
#define LPE_MCM_ISCR_FDZC(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FDZC_SHIFT)) & LPE_MCM_ISCR_FDZC_MASK)

#define LPE_MCM_ISCR_FIOC_MASK                   (0x800000U)
#define LPE_MCM_ISCR_FIOC_SHIFT                  (23U)
#define LPE_MCM_ISCR_FIOC_WIDTH                  (1U)
#define LPE_MCM_ISCR_FIOC(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_ISCR_FIOC_SHIFT)) & LPE_MCM_ISCR_FIOC_MASK)
/*! @} */

/*! @name PID - Process ID Register */
/*! @{ */

#define LPE_MCM_PID_PID_MASK                     (0xFF000000U)
#define LPE_MCM_PID_PID_SHIFT                    (24U)
#define LPE_MCM_PID_PID_WIDTH                    (8U)
#define LPE_MCM_PID_PID(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_MCM_PID_PID_SHIFT)) & LPE_MCM_PID_PID_MASK)
/*! @} */

/*! @name CPO - Compute Operation Control Register */
/*! @{ */

#define LPE_MCM_CPO_CPOWOI_MASK                  (0x20000000U)
#define LPE_MCM_CPO_CPOWOI_SHIFT                 (29U)
#define LPE_MCM_CPO_CPOWOI_WIDTH                 (1U)
#define LPE_MCM_CPO_CPOWOI(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPO_CPOWOI_SHIFT)) & LPE_MCM_CPO_CPOWOI_MASK)

#define LPE_MCM_CPO_CPOACK_MASK                  (0x40000000U)
#define LPE_MCM_CPO_CPOACK_SHIFT                 (30U)
#define LPE_MCM_CPO_CPOACK_WIDTH                 (1U)
#define LPE_MCM_CPO_CPOACK(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPO_CPOACK_SHIFT)) & LPE_MCM_CPO_CPOACK_MASK)

#define LPE_MCM_CPO_CPOREQ_MASK                  (0x80000000U)
#define LPE_MCM_CPO_CPOREQ_SHIFT                 (31U)
#define LPE_MCM_CPO_CPOREQ_WIDTH                 (1U)
#define LPE_MCM_CPO_CPOREQ(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_CPO_CPOREQ_SHIFT)) & LPE_MCM_CPO_CPOREQ_MASK)
/*! @} */

/*! @name LMDR - Local Memory Descriptor Register */
/*! @{ */

#define LPE_MCM_LMDR_V_MASK                      (0x1U)
#define LPE_MCM_LMDR_V_SHIFT                     (0U)
#define LPE_MCM_LMDR_V_WIDTH                     (1U)
#define LPE_MCM_LMDR_V(x)                        (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_V_SHIFT)) & LPE_MCM_LMDR_V_MASK)

#define LPE_MCM_LMDR_LMSZH_MASK                  (0x8U)
#define LPE_MCM_LMDR_LMSZH_SHIFT                 (3U)
#define LPE_MCM_LMDR_LMSZH_WIDTH                 (1U)
#define LPE_MCM_LMDR_LMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_LMSZH_SHIFT)) & LPE_MCM_LMDR_LMSZH_MASK)

#define LPE_MCM_LMDR_LMSZ_MASK                   (0xF0U)
#define LPE_MCM_LMDR_LMSZ_SHIFT                  (4U)
#define LPE_MCM_LMDR_LMSZ_WIDTH                  (4U)
#define LPE_MCM_LMDR_LMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_LMSZ_SHIFT)) & LPE_MCM_LMDR_LMSZ_MASK)

#define LPE_MCM_LMDR_WY_MASK                     (0xF00U)
#define LPE_MCM_LMDR_WY_SHIFT                    (8U)
#define LPE_MCM_LMDR_WY_WIDTH                    (4U)
#define LPE_MCM_LMDR_WY(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_WY_SHIFT)) & LPE_MCM_LMDR_WY_MASK)

#define LPE_MCM_LMDR_DPW_MASK                    (0x7000U)
#define LPE_MCM_LMDR_DPW_SHIFT                   (12U)
#define LPE_MCM_LMDR_DPW_WIDTH                   (3U)
#define LPE_MCM_LMDR_DPW(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_DPW_SHIFT)) & LPE_MCM_LMDR_DPW_MASK)

#define LPE_MCM_LMDR_LOCK_MASK                   (0x8000U)
#define LPE_MCM_LMDR_LOCK_SHIFT                  (15U)
#define LPE_MCM_LMDR_LOCK_WIDTH                  (1U)
#define LPE_MCM_LMDR_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_LOCK_SHIFT)) & LPE_MCM_LMDR_LOCK_MASK)

#define LPE_MCM_LMDR_MT_MASK                     (0x70000U)
#define LPE_MCM_LMDR_MT_SHIFT                    (16U)
#define LPE_MCM_LMDR_MT_WIDTH                    (3U)
#define LPE_MCM_LMDR_MT(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_MT_SHIFT)) & LPE_MCM_LMDR_MT_MASK)

#define LPE_MCM_LMDR_CF0_MASK                    (0xF0000000U)
#define LPE_MCM_LMDR_CF0_SHIFT                   (28U)
#define LPE_MCM_LMDR_CF0_WIDTH                   (4U)
#define LPE_MCM_LMDR_CF0(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR_CF0_SHIFT)) & LPE_MCM_LMDR_CF0_MASK)
/*! @} */

/*! @name LMDR2 - Local Memory Descriptor Register2 */
/*! @{ */

#define LPE_MCM_LMDR2_V_MASK                     (0x1U)
#define LPE_MCM_LMDR2_V_SHIFT                    (0U)
#define LPE_MCM_LMDR2_V_WIDTH                    (1U)
#define LPE_MCM_LMDR2_V(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_V_SHIFT)) & LPE_MCM_LMDR2_V_MASK)

#define LPE_MCM_LMDR2_LMSZH_MASK                 (0x8U)
#define LPE_MCM_LMDR2_LMSZH_SHIFT                (3U)
#define LPE_MCM_LMDR2_LMSZH_WIDTH                (1U)
#define LPE_MCM_LMDR2_LMSZH(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_LMSZH_SHIFT)) & LPE_MCM_LMDR2_LMSZH_MASK)

#define LPE_MCM_LMDR2_LMSZ_MASK                  (0xF0U)
#define LPE_MCM_LMDR2_LMSZ_SHIFT                 (4U)
#define LPE_MCM_LMDR2_LMSZ_WIDTH                 (4U)
#define LPE_MCM_LMDR2_LMSZ(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_LMSZ_SHIFT)) & LPE_MCM_LMDR2_LMSZ_MASK)

#define LPE_MCM_LMDR2_WY_MASK                    (0xF00U)
#define LPE_MCM_LMDR2_WY_SHIFT                   (8U)
#define LPE_MCM_LMDR2_WY_WIDTH                   (4U)
#define LPE_MCM_LMDR2_WY(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_WY_SHIFT)) & LPE_MCM_LMDR2_WY_MASK)

#define LPE_MCM_LMDR2_DPW_MASK                   (0x7000U)
#define LPE_MCM_LMDR2_DPW_SHIFT                  (12U)
#define LPE_MCM_LMDR2_DPW_WIDTH                  (3U)
#define LPE_MCM_LMDR2_DPW(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_DPW_SHIFT)) & LPE_MCM_LMDR2_DPW_MASK)

#define LPE_MCM_LMDR2_LOCK_MASK                  (0x8000U)
#define LPE_MCM_LMDR2_LOCK_SHIFT                 (15U)
#define LPE_MCM_LMDR2_LOCK_WIDTH                 (1U)
#define LPE_MCM_LMDR2_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_LOCK_SHIFT)) & LPE_MCM_LMDR2_LOCK_MASK)

#define LPE_MCM_LMDR2_MT_MASK                    (0x70000U)
#define LPE_MCM_LMDR2_MT_SHIFT                   (16U)
#define LPE_MCM_LMDR2_MT_WIDTH                   (3U)
#define LPE_MCM_LMDR2_MT(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_MT_SHIFT)) & LPE_MCM_LMDR2_MT_MASK)

#define LPE_MCM_LMDR2_CF1_MASK                   (0xF000000U)
#define LPE_MCM_LMDR2_CF1_SHIFT                  (24U)
#define LPE_MCM_LMDR2_CF1_WIDTH                  (4U)
#define LPE_MCM_LMDR2_CF1(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMDR2_CF1_SHIFT)) & LPE_MCM_LMDR2_CF1_MASK)
/*! @} */

/*! @name LMPECR - LMEM Parity and ECC Control Register */
/*! @{ */

#define LPE_MCM_LMPECR_ECPR_MASK                 (0x800U)
#define LPE_MCM_LMPECR_ECPR_SHIFT                (11U)
#define LPE_MCM_LMPECR_ECPR_WIDTH                (1U)
#define LPE_MCM_LMPECR_ECPR(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPECR_ECPR_SHIFT)) & LPE_MCM_LMPECR_ECPR_MASK)

#define LPE_MCM_LMPECR_ER1BR_MASK                (0x800000U)
#define LPE_MCM_LMPECR_ER1BR_SHIFT               (23U)
#define LPE_MCM_LMPECR_ER1BR_WIDTH               (1U)
#define LPE_MCM_LMPECR_ER1BR(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPECR_ER1BR_SHIFT)) & LPE_MCM_LMPECR_ER1BR_MASK)

#define LPE_MCM_LMPECR_ERNCR_MASK                (0x80000000U)
#define LPE_MCM_LMPECR_ERNCR_SHIFT               (31U)
#define LPE_MCM_LMPECR_ERNCR_WIDTH               (1U)
#define LPE_MCM_LMPECR_ERNCR(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPECR_ERNCR_SHIFT)) & LPE_MCM_LMPECR_ERNCR_MASK)
/*! @} */

/*! @name LMPEIR - LMEM Parity and ECC Interrupt Register */
/*! @{ */

#define LPE_MCM_LMPEIR_V_MASK                    (0x1U)
#define LPE_MCM_LMPEIR_V_SHIFT                   (0U)
#define LPE_MCM_LMPEIR_V_WIDTH                   (1U)
#define LPE_MCM_LMPEIR_V(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPEIR_V_SHIFT)) & LPE_MCM_LMPEIR_V_MASK)

#define LPE_MCM_LMPEIR_PEELOC_MASK               (0xF8U)
#define LPE_MCM_LMPEIR_PEELOC_SHIFT              (3U)
#define LPE_MCM_LMPEIR_PEELOC_WIDTH              (5U)
#define LPE_MCM_LMPEIR_PEELOC(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPEIR_PEELOC_SHIFT)) & LPE_MCM_LMPEIR_PEELOC_MASK)

#define LPE_MCM_LMPEIR_PE_MASK                   (0xFF00U)
#define LPE_MCM_LMPEIR_PE_SHIFT                  (8U)
#define LPE_MCM_LMPEIR_PE_WIDTH                  (8U)
#define LPE_MCM_LMPEIR_PE(x)                     (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPEIR_PE_SHIFT)) & LPE_MCM_LMPEIR_PE_MASK)

#define LPE_MCM_LMPEIR_E1B_MASK                  (0xFF0000U)
#define LPE_MCM_LMPEIR_E1B_SHIFT                 (16U)
#define LPE_MCM_LMPEIR_E1B_WIDTH                 (8U)
#define LPE_MCM_LMPEIR_E1B(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPEIR_E1B_SHIFT)) & LPE_MCM_LMPEIR_E1B_MASK)

#define LPE_MCM_LMPEIR_ENC_MASK                  (0xFF000000U)
#define LPE_MCM_LMPEIR_ENC_SHIFT                 (24U)
#define LPE_MCM_LMPEIR_ENC_WIDTH                 (8U)
#define LPE_MCM_LMPEIR_ENC(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMPEIR_ENC_SHIFT)) & LPE_MCM_LMPEIR_ENC_MASK)
/*! @} */

/*! @name LMFAR - LMEM Fault Address Register */
/*! @{ */

#define LPE_MCM_LMFAR_EFADD_MASK                 (0xFFFFFFFFU)
#define LPE_MCM_LMFAR_EFADD_SHIFT                (0U)
#define LPE_MCM_LMFAR_EFADD_WIDTH                (32U)
#define LPE_MCM_LMFAR_EFADD(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFAR_EFADD_SHIFT)) & LPE_MCM_LMFAR_EFADD_MASK)
/*! @} */

/*! @name LMFATR - LMEM Fault Attribute Register */
/*! @{ */

#define LPE_MCM_LMFATR_OVR_MASK                  (0x1U)
#define LPE_MCM_LMFATR_OVR_SHIFT                 (0U)
#define LPE_MCM_LMFATR_OVR_WIDTH                 (1U)
#define LPE_MCM_LMFATR_OVR(x)                    (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFATR_OVR_SHIFT)) & LPE_MCM_LMFATR_OVR_MASK)

#define LPE_MCM_LMFATR_PEFMST_MASK               (0xFF0000U)
#define LPE_MCM_LMFATR_PEFMST_SHIFT              (16U)
#define LPE_MCM_LMFATR_PEFMST_WIDTH              (8U)
#define LPE_MCM_LMFATR_PEFMST(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFATR_PEFMST_SHIFT)) & LPE_MCM_LMFATR_PEFMST_MASK)

#define LPE_MCM_LMFATR_PEFW_MASK                 (0x1000000U)
#define LPE_MCM_LMFATR_PEFW_SHIFT                (24U)
#define LPE_MCM_LMFATR_PEFW_WIDTH                (1U)
#define LPE_MCM_LMFATR_PEFW(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFATR_PEFW_SHIFT)) & LPE_MCM_LMFATR_PEFW_MASK)

#define LPE_MCM_LMFATR_PEFSIZE_MASK              (0xE000000U)
#define LPE_MCM_LMFATR_PEFSIZE_SHIFT             (25U)
#define LPE_MCM_LMFATR_PEFSIZE_WIDTH             (3U)
#define LPE_MCM_LMFATR_PEFSIZE(x)                (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFATR_PEFSIZE_SHIFT)) & LPE_MCM_LMFATR_PEFSIZE_MASK)

#define LPE_MCM_LMFATR_PEFPRT_MASK               (0xF0000000U)
#define LPE_MCM_LMFATR_PEFPRT_SHIFT              (28U)
#define LPE_MCM_LMFATR_PEFPRT_WIDTH              (4U)
#define LPE_MCM_LMFATR_PEFPRT(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFATR_PEFPRT_SHIFT)) & LPE_MCM_LMFATR_PEFPRT_MASK)
/*! @} */

/*! @name LMFDHR - LMEM Fault Data High Register */
/*! @{ */

#define LPE_MCM_LMFDHR_PEFDH_MASK                (0xFFFFFFFFU)
#define LPE_MCM_LMFDHR_PEFDH_SHIFT               (0U)
#define LPE_MCM_LMFDHR_PEFDH_WIDTH               (32U)
#define LPE_MCM_LMFDHR_PEFDH(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFDHR_PEFDH_SHIFT)) & LPE_MCM_LMFDHR_PEFDH_MASK)
/*! @} */

/*! @name LMFDLR - LMEM Fault Data Low Register */
/*! @{ */

#define LPE_MCM_LMFDLR_PEFDL_MASK                (0xFFFFFFFFU)
#define LPE_MCM_LMFDLR_PEFDL_SHIFT               (0U)
#define LPE_MCM_LMFDLR_PEFDL_WIDTH               (32U)
#define LPE_MCM_LMFDLR_PEFDL(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_MCM_LMFDLR_PEFDL_SHIFT)) & LPE_MCM_LMFDLR_PEFDL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPE_MCM_Register_Masks */

/*!
 * @}
 */ /* end of group LPE_MCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LPE_MCM_H_) */
